#!/usr/bin/env python3
"""Find 3rd Strike routines in the 2nd Impact program.

    python tools/match3s.py <3s prog.bin> <3s match_status.tsv> <2i prog.bin> <out.tsv>

For each 3s routine (address and size from match_status.tsv) look for its bytes in the 2i image:
  exact   - the same bytes
  reloc   - the same bytes except 32-bit words that are program/RAM addresses on both sides (06xxxxxx / 02xxxxxx)
Candidates come from an index of 8-byte windows of the 2i image at even offsets.
"""
import sys, collections
P3, MS, P2, OUT = sys.argv[1:5]
a = open(P3, 'rb').read(); b = open(P2, 'rb').read()
rows = [l.rstrip('\n').split('\t') for l in open(MS, encoding='utf-8') if not l.startswith('#')]
h = rows[0]; R = [dict(zip(h, r)) for r in rows[1:]]
K = 8
idx = collections.defaultdict(list)
for i in range(0, 0x800000 - K, 2):          # code lives in the first SIMM
    idx[b[i:i + K]].append(i)

def isaddr(w):
    return (w >> 24) in (0x06, 0x02)

def same_reloc(x, y):
    if len(x) != len(y): return False
    i = 0
    while i < len(x):
        if x[i:i + 2] == y[i:i + 2]: i += 2; continue
        ok = False
        for j in (i, i - 2):
            if j >= 0 and j + 4 <= len(x) and isaddr(int.from_bytes(x[j:j+4], 'big')) and isaddr(int.from_bytes(y[j:j+4], 'big')):
                ok = True; i = j + 4; break
        if not ok: return False
    return True

out = open(OUT, 'w', encoding='utf-8')
out.write('name\tmodule\tkind\taddr3\tsize\tresult\taddr2\tdelta\n')
cnt = collections.Counter(); deltas = collections.Counter()
for r in R:
    ad = int(r['arcade_address'], 16); sz = int(r['arcade_size'])
    o = ad - 0x06000000; s = a[o:o + sz]
    res, a2 = 'none', ''
    if sz >= K:
        for anchor in range(0, max(1, sz - K), 2):
            cands = idx.get(s[anchor:anchor + K], [])
            if not cands or len(cands) > 200: continue
            hit = None
            for c in cands:
                st = c - anchor
                if st < 0: continue
                t = b[st:st + sz]
                if t == s: hit = ('exact', st); break
                if hit is None and same_reloc(s, t): hit = ('reloc', st)
            if hit: res, a2 = hit[0], hit[1] + 0x06000000; break
    else:
        res = 'tiny'
    cnt[(r['kind'], res)] += 1
    if a2: deltas[(a2 - ad) // 0x1000 * 0x1000] += 1
    out.write(f"{r['name']}\t{r['module']}\t{r['kind']}\t{ad:08X}\t{sz}\t{res}\t{a2 and format(a2, '08X')}\t{a2 and a2 - ad}\n")
for k, v in sorted(cnt.items()): print(k, v)
print('deltas (4K buckets, top):', deltas.most_common(12))
