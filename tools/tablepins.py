#!/usr/bin/env python3
"""Routine placements from data tables of routine pointers (dispatch tables, task tables, state tables).

    python tools/tablepins.py <3s prog.bin> <3s routine tsv> <si2map dir> <out pins.tsv>

A 3s table is a run of 4-aligned data words (past the 3s code, below 06800000) that are all 3s routine starts.
Its entries already placed with confidence by <si2map dir>/census.tsv (exact or reloc, one candidate, in link
order) anchor it in 2i: from each 2i data word holding such an entry's 2i address the table is read both ways
until the first entry that disagrees (see main), so table edges and inserted entries end it. Each entry votes
for the 2i word beside it. A routine is pinned when one 2i address, a code halfword in hmap.bin, has at least
two thirds of its votes. Two routines pinned to one address are left for census3s.py, which keeps the one that
matches there best. Output columns: name, addr2, source. Feed it to census3s.py as a pins argument.
"""
import sys, collections
from pathlib import Path

BASE = 0x06000000
TOP = 0x06800000                       # graphics past this (2i also keeps a stale data copy up there)


def main():
    if len(sys.argv) < 5: sys.exit(__doc__)
    p3, tsv, mapdir, out = sys.argv[1:5]
    mapdir = Path(mapdir)
    img3 = open(p3, 'rb').read()
    img2 = (mapdir / 'prog.bin').read_bytes(); cls2 = (mapdir / 'hmap.bin').read_bytes()
    rows = [l.rstrip('\n').split('\t') for l in open(tsv, encoding='utf-8') if not l.startswith('#')]
    hdr = rows[0]
    starts = {int(r[hdr.index('arcade_address')], 16): r[0] for r in rows[1:]}
    cen = [l.rstrip('\n').split('\t') for l in open(mapdir / 'census.tsv', encoding='utf-8')]
    ch = cen[0]; C = [dict(zip(ch, r)) for r in cen[1:]]
    sure = {int(r['addr3'], 16): int(r['addr2'], 16) for r in C
            if r['class'] in ('exact', 'reloc') and r['dup'] == '1' and r['order'] == 'in'}
    end3 = int.from_bytes(img3[0x1008:0x100C], 'big'); end2 = BASE + 2 * len(cls2)

    def words(img, lo):
        for o in range(lo - BASE, TOP - BASE, 4):
            yield BASE + o, int.from_bytes(img[o:o + 4], 'big')

    def code2(v):
        return BASE <= v < end2 and not v & 1 and cls2[(v - BASE) // 2] in (1, 4)

    at2 = collections.defaultdict(list)                          # 2i address -> data words holding it
    for a, v in words(img2, (end2 + 3) & ~3):
        if code2(v): at2[v].append(a)
    tables, run = [], []
    for a, v in words(img3, (end3 + 3) & ~3):
        if v in starts: run.append((a, v)); continue
        if len(run) >= 2: tables.append(run)
        run = []
    def w2at(b, i):
        o = b - BASE + 4 * i
        return int.from_bytes(img2[o:o + 4], 'big')

    # Every placed entry anchors a 2i base at each 2i word holding its address. From the anchor the table runs
    # both ways until the first entry that disagrees: a 2i word that is not code, a placed entry whose 2i address
    # is not there, or a 2i word holding another routine census placed unambiguously (one candidate, in link
    # order). That can still run past a table edge (3s runs often hold several tables back to back, and the 2i
    # ones are shorter) where the next 2i table starts with copies placed ambiguously; then two routines are
    # pinned to one 2i address and census3s keeps the one that matches there best.
    owner = {int(r['addr2'], 16): int(r['addr3'], 16) for r in C
             if r['addr2'] and r['order'] == 'in' and r['dup'] == '1'}
    segs = {}
    for ti, t in enumerate(tables):
        for j, (_, vj) in enumerate(t):
            if vj not in sure or len(at2[sure[vj]]) >= 64: continue
            for p in at2[sure[vj]]:
                b = p - 4 * j
                if (ti, b) in segs and j in segs[ti, b][1]: continue
                lo = hi = j; anchors = [j]
                for step in (1, -1):
                    i = j + step
                    while 0 <= i < len(t):
                        w, v = w2at(b, i), t[i][1]
                        if not code2(w) or v in sure and sure[v] != w or v not in sure and owner.get(w, v) != v:
                            break
                        if v in sure: anchors.append(i)
                        lo, hi = min(lo, i), max(hi, i); i += step
                if len(anchors) >= 2 and len(anchors) > len(segs.get((ti, b), (None, ()))[1]):
                    segs[ti, b] = (range(lo, hi + 1), sorted(anchors))
    votes = collections.defaultdict(collections.Counter); src = {}
    for (ti, b), (span, anchors) in segs.items():
        for i in span:
            a, v = tables[ti][i]; w = w2at(b, i)
            votes[v][w] += 1; src.setdefault((v, w), f'{a:08X}->{b + 4 * i:08X}')
    aligned = len({ti for ti, _ in segs})
    pick = {}
    for v, vs in votes.items():
        w2, c = vs.most_common(1)[0]
        if 3 * c >= 2 * sum(vs.values()): pick[v] = (w2, c, sum(vs.values()))
    with open(out, 'w', encoding='utf-8') as f:
        f.write('name\taddr2\tsource\n')
        for v, (w2, c, t) in sorted(pick.items()):
            f.write(f'{starts[v]}\t{w2:08X}\ttable {c}/{t} {src[v, w2]}\n')
    print(f'{len(tables)} 3s tables, {aligned} aligned to 2i; {len(votes)} routines voted, {len(pick)} clear, '
          f'{len(pick)} pinned')


if __name__ == '__main__':
    main()
