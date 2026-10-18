#!/usr/bin/env python3
"""Find 3rd Strike routines in 2nd Impact, reading 2nd Impact through both of its views.

    python tools/match3s_dual.py <3s prog.bin> <3s ms34.tsv> <prog_op.bin> <prog_data.bin> <out.tsv>

2nd Impact stores instructions encrypted and data plain, so before the merged image exists neither view alone is
the program. Here each 2i halfword may match the 3s halfword in either view: the instruction view (prog_op.bin) or
the stored bytes (prog_data.bin). Results per 3s routine (address and size from ms34.tsv):
  exact  the same bytes
  reloc  the same bytes except aligned 32-bit words that are addresses on both sides (02/04/05/06xxxxxx), which are
         listed as relocation pairs (3s value -> 2i value) in the reloc column
The chosen hit is an exact one first, then the nearest to the 3s address; alts lists every hit (address:result).
Candidates come from an index of 8-byte windows of the instruction view (06000000-063FFFFF) at even offsets. The
data column lists the 2i word offsets (from the routine start) that matched only in the data view: literal pools.
"""
import sys, collections

P3, MS, OP, DATA, OUT = sys.argv[1:6]
a = open(P3, 'rb').read()
op = open(OP, 'rb').read()
dv = open(DATA, 'rb').read()
BASE = 0x06000000
K = 8
SPAN = 0x400000
idx = collections.defaultdict(list)
for i in range(0, SPAN - K, 2):
    idx[op[i:i + K]].append(i)


def isaddr(w):
    return (w >> 24) in (0x02, 0x04, 0x05, 0x06)


def compare(s, st):
    """-> (result, data word offsets, relocation pairs) or None; s: 3s bytes, st: 2i offset"""
    n = len(s)
    if st < 0 or st + n > len(op):
        return None
    datah = []
    i = 0
    bad = []
    while i < n:
        x = s[i:i + 2]
        if x == op[st + i:st + i + 2]:
            pass
        elif x == dv[st + i:st + i + 2]:
            datah.append(i)
        else:
            bad.append(i)
        i += 2
    if not bad:
        return 'exact', datah, []
    # relocation: every mismatching halfword lies in a word, aligned in 2i, that is an address on both sides
    rel = []
    done = set()
    for i in bad:
        j = i - ((st + i) & 2)              # the 2i-aligned word holding halfword i
        if j in done:
            continue
        if j < 0 or j + 4 > n:
            return None
        w3 = int.from_bytes(s[j:j + 4], 'big')
        w2 = int.from_bytes(dv[st + j:st + j + 4], 'big')
        if not (isaddr(w3) and isaddr(w2)):
            return None
        done.add(j)
        rel.append((w3, w2))
        datah.extend(h for h in (j, j + 2) if h not in datah)
    return 'reloc', sorted(set(datah)), rel


rows = [l.rstrip('\n').split('\t') for l in open(MS, encoding='utf-8') if not l.startswith('#')]
h = rows[0]
R = [dict(zip(h, r)) for r in rows[1:]]
out = open(OUT, 'w', encoding='utf-8')
out.write('name\tmodule\tkind\taddr3\tsize\tresult\taddr2\tdelta\tdata\treloc\tcands\talts\n')
cnt = collections.Counter()
for r in R:
    ad = int(r['arcade_address'], 16)
    sz = int(r['arcade_size'])
    s = a[ad - BASE:ad - BASE + sz]
    res, a2, data, rel, ncand, alts = 'none', None, [], [], 0, ''
    if sz < K:
        res = 'tiny'
    else:
        hits = {}
        for anchor in range(0, sz - K + 1, 2):
            cands = idx.get(s[anchor:anchor + K], [])
            if not cands or len(cands) > 400:
                continue
            for c in cands:
                st = c - anchor
                if st in hits:
                    continue
                m = compare(s, st)
                if m:
                    hits[st] = m
            if hits:
                break
        if hits:
            ncand = len(hits)
            # an exact hit first, then the nearest to the 3s address
            st = min(hits, key=lambda t: (hits[t][0] != 'exact', abs(t + BASE - ad)))
            res, data, rel = hits[st]
            a2 = st + BASE
            alts = ','.join(f'{t + BASE:08X}:{hits[t][0]}' for t in sorted(hits))
    cnt[(r['kind'], res)] += 1
    out.write(f"{r['name']}\t{r['module']}\t{r['kind']}\t{ad:08X}\t{sz}\t{res}\t{a2 and format(a2, '08X') or ''}\t"
              f"{'' if a2 is None else a2 - ad}\t{','.join(map(str, data))}\t"
              f"{','.join(f'{x:08X}>{y:08X}' for x, y in rel)}\t{ncand or ''}\t{alts}\n")
for k, v in sorted(cnt.items()):
    print(*k, v)
