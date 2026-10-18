#!/usr/bin/env python3
"""Seed ghidra/names/entries.tsv from the si2map function entries that Ghidra's analysis does not find.

    python tools/seed-entries.py <si2map funcs.tsv> <boundaries.tsv>

<si2map funcs.tsv>: addr, how (tools/si2map.py: vector, jsr, bsr, jmp, ptr = a data word pointing at clean code,
match3s, unreached = code nothing reaches). <boundaries.tsv>: tools/ghidra-export.sh output of the current project.
An entry is added when Ghidra has no function there and the address is not inside a Ghidra function (those are
boundary disagreements, printed instead). Rows are only added; the note says how si2map found the entry.
"""
import bisect, collections, sys
from pathlib import Path

FUNCS, BOUNDS = sys.argv[1:3]
P = Path(__file__).resolve().parent.parent / 'ghidra' / 'names' / 'entries.tsv'
G = {}
for l in open(BOUNDS, encoding='utf-8').read().splitlines()[1:]:
    p = l.split('\t')
    G[int(p[0], 16)] = (int(p[1], 16), p[5])
starts = sorted(G)
text = P.read_text(encoding='utf-8') if P.is_file() else '# address\tnote   (docs/PROVENANCE.md)\n'
have = {int(l.split('\t')[0], 16) for l in text.splitlines() if l.strip() and not l.startswith('#')}
add, inside = [], collections.Counter()
for l in open(FUNCS, encoding='utf-8').read().splitlines()[1:]:
    a, how = l.split('\t')[:2]
    a = int(a, 16)
    if a in G or a in have:
        continue
    k = bisect.bisect_right(starts, a) - 1
    if k >= 0 and a < G[starts[k]][0]:
        inside[how] += 1
        print(f'inside: {a:08X} ({how}) is inside {G[starts[k]][1]} {starts[k]:08X}-{G[starts[k]][0]:08X}')
        continue
    add.append((a, f'si2map entry ({how})'))
rows = sorted([l for l in text.splitlines() if l.strip() and not l.startswith('#')] +
              [f'{a:08X}\t{n}' for a, n in add], key=lambda l: int(l.split('\t')[0], 16))
head = [l for l in text.splitlines() if l.startswith('#')]
P.write_text('\n'.join(head + rows) + '\n', encoding='utf-8', newline='\n')
print(f'entries.tsv: {len(rows)} rows ({len(add)} added: {dict(collections.Counter(n for _, n in add))}); '
      f'inside a Ghidra function, not added: {dict(inside)}')
