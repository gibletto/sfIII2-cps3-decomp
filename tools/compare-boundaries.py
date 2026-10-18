#!/usr/bin/env python3
"""Compare Ghidra's function boundaries with si2map's entries and the 3s census.

    python tools/compare-boundaries.py <boundaries.tsv> <si2map dir> [--list]

<boundaries.tsv>: tools/ghidra-export.sh output. <si2map dir>: funcs.tsv (entries), census.tsv (2i address and
size of each placed 3s routine). Prints: entries in both, only in Ghidra, only in si2map (and whether inside a Ghidra
function); for placed exact/reloc routines, whether Ghidra's body ends where the 2i routine does (within its
trailing literal pool, at most 64 bytes before the end), runs past it or stops short. --list prints each
disagreement.
"""
import bisect, collections, sys
from pathlib import Path

B, D = sys.argv[1], Path(sys.argv[2])
LIST = '--list' in sys.argv
G = {}
for l in open(B, encoding='utf-8').read().splitlines()[1:]:
    p = l.split('\t')
    G[int(p[0], 16)] = (int(p[1], 16), p[5])
S = {}
for l in open(D / 'funcs.tsv', encoding='utf-8').read().splitlines()[1:]:
    p = l.split('\t')
    S[int(p[0], 16)] = p[1]
starts = sorted(G)


def containing(a):
    k = bisect.bisect_right(starts, a) - 1
    return starts[k] if k >= 0 and a < G[starts[k]][0] else None


print(f'entries: Ghidra {len(G)}, si2map {len(S)}, both {len(G.keys() & S.keys())}')
only_g = sorted(G.keys() - S.keys())
only_s = sorted(S.keys() - G.keys())
print(f'only in Ghidra: {len(only_g)}')
inside = [a for a in only_s if containing(a) is not None]
print(f'only in si2map: {len(only_s)} ({dict(collections.Counter(S[a] for a in only_s))}); '
      f'inside a Ghidra function: {len(inside)}')
if LIST:
    for a in only_g:
        print(f'  ghidra only {a:08X} {G[a][1]}')
    for a in inside:
        c = containing(a)
        print(f'  si2map {a:08X} ({S[a]}) inside {G[c][1]} {c:08X}-{G[c][0]:08X}')
rows = [l.rstrip('\n').split('\t') for l in open(D / 'census.tsv', encoding='utf-8')]
cnt = collections.Counter()
for c in (dict(zip(rows[0], r)) for r in rows[1:]):
    if c['class'] not in ('exact', 'reloc') or not c['addr2']:
        continue
    a, size = int(c['addr2'], 16), int(c['size2'])
    if a not in G:
        k = 'no Ghidra function at the entry'
    else:
        ext = G[a][0] - a
        k = 'ends with the routine' if size - 64 <= ext <= size else 'runs past' if ext > size else 'stops short'
    cnt[k] += 1
    if LIST and k != 'ends with the routine':
        print(f'  {k}: {c["name"]} {a:08X} size {size}' + (f', Ghidra {G[a][0] - a}' if a in G else ''))
print('census exact/reloc routines:', dict(cnt))
