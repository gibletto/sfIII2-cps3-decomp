#!/usr/bin/env python3
"""Write the pointer placements of ghidra/names/functions.tsv as pins for si2map's census3s.py.

    python tools/export-pins.py <out.tsv>

A row is a pin when tools/seed-tables.py placed it by pointers of its own (literal pools, aligned ROM tables); rows
resting only on si2map's table pins are left out, since si2map has them. Columns: name, addr2, source.
"""
import re, sys
from pathlib import Path

T = Path(__file__).resolve().parent.parent / 'ghidra' / 'names' / 'functions.tsv'
out = ['name\taddr2\tsource']
for l in T.read_text(encoding='utf-8').splitlines():
    if not l.strip() or l.startswith('#'):
        continue
    r = l.split('\t')
    m = re.search(r'(?:pointed to as sf3 \S+ by |placed by the pointers to it \()(.*?)(?: of matched|\)|:|$)', r[7])
    if not m:
        continue
    how = re.sub(r' and \d+ si2map table pins?|\d+ si2map table pins? and ', '', m.group(1).strip())
    if re.fullmatch(r'\d+ si2map table pins?', how):
        continue
    out.append(f'{r[1]}\t{r[0]}\tsi2ghidra: {how}')
Path(sys.argv[1]).write_text('\n'.join(out) + '\n', encoding='utf-8', newline='\n')
print(f'{len(out) - 1} pins -> {sys.argv[1]}')
