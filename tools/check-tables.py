#!/usr/bin/env python3
"""Check the naming tables (ghidra/names/) against the provenance rules of docs/PROVENANCE.md.

    python tools/check-tables.py [<names dir>]

Checks: column counts; addresses are 8 hex digits; names are C identifiers, not C keywords and unique across
functions and globals; each address appears once per table; the class is one of the five; the evidence a class
needs (sf3_addr/sf3_name for 3s-*, "reloc N" for 3s-reloc, "sim NN%" for 3s-near, a note for inferred); every
struct/union in types.h has an @prov line; an enum's first row has a class. Prints each problem; exit 1 if any.
"""
import re, sys
from pathlib import Path

D = Path(sys.argv[1] if len(sys.argv) > 1 else Path(__file__).resolve().parent.parent / 'ghidra' / 'names')
CLASSES = {'3s-exact', '3s-reloc', '3s-near', 'inferred', 'new'}
KEYWORDS = set('auto break case char const continue default do double else enum extern float for goto if int long '
               'register return short signed sizeof static struct switch typedef union unsigned void volatile while'
               .split())
IDENT = re.compile(r'[A-Za-z_]\w*$')
problems = []


def bad(f, n, msg):
    problems.append(f'{f}:{n}: {msg}')


def rows(name, cols):
    p = D / name
    if not p.is_file():
        return []
    out = []
    for n, l in enumerate(p.read_text(encoding='utf-8').splitlines(), 1):
        if not l.strip() or l.startswith('#'):
            continue
        r = [c.strip() for c in l.split('\t')]
        if len(r) != cols:
            bad(name, n, f'{len(r)} columns, expected {cols}')
            r += [''] * (cols - len(r))
        out.append((n, r))
    return out


def evidence(f, n, cls, sf3_addr, sf3_name, note):
    if cls not in CLASSES:
        bad(f, n, f'class {cls!r} is not one of {sorted(CLASSES)}')
        return
    if cls.startswith('3s-'):
        if not re.fullmatch(r'[0-9A-Fa-f]{8}', sf3_addr) or not sf3_name:
            bad(f, n, f'{cls} needs sf3_addr and sf3_name')
    if cls == '3s-reloc' and not re.search(r'\breloc \d+|^ram refs \d+', note):
        bad(f, n, '3s-reloc note must give "reloc N" (relocated words) or, for RAM, "ram refs N"')
    if cls == '3s-near' and not re.match(r'sim \d+%', note):
        bad(f, n, '3s-near note must start "sim NN%"')
    if cls == 'inferred' and not note:
        bad(f, n, 'inferred needs a reason in the note')


names = {}
for table in ('functions.tsv', 'globals.tsv'):
    seen = {}
    for n, r in rows(table, 8):
        addr, name, _, cls, sf3_addr, sf3_name, _, note = r
        if not re.fullmatch(r'[0-9A-Fa-f]{8}', addr):
            bad(table, n, f'address {addr!r}')
        if not IDENT.match(name) or name in KEYWORDS:
            bad(table, n, f'name {name!r} is not a C identifier')
        if addr.lower() in seen:
            bad(table, n, f'address {addr} also on line {seen[addr.lower()]}')
        seen[addr.lower()] = n
        if name in names:
            bad(table, n, f'name {name} also at {names[name]}')
        names[name] = f'{table}:{n}'
        evidence(table, n, cls, sf3_addr, sf3_name, note)

for n, r in rows('entries.tsv', 2):
    if not re.fullmatch(r'[0-9A-Fa-f]{8}', r[0]):
        bad('entries.tsv', n, f'address {r[0]!r}')

first = set()
for n, r in rows('enums.tsv', 6):
    if r[0] not in first:
        first.add(r[0])
        if r[4] not in CLASSES:
            bad('enums.tsv', n, f'first row of {r[0]} needs a class, has {r[4]!r}')

for n, r in rows('locals.tsv', 8):
    if not IDENT.match(r[2]) or r[2] in KEYWORDS or r[2] in names:
        bad('locals.tsv', n, f'local {r[2]!r} is not a C identifier or is a global/function name')
    if r[6] and r[6] not in CLASSES:
        bad('locals.tsv', n, f'class {r[6]!r}')

th = D / 'types.h'
if th.is_file():
    text = th.read_text(encoding='utf-8')
    defined = set(re.findall(r'^\s*(?:typedef\s+)?(?:struct|union)\s+(\w+)\s*\{', text, re.M))
    prov = {}
    for m in re.finditer(r'^\s*// @prov (\w+) (\S+)', text, re.M):
        prov[m.group(1)] = m.group(2)
    for t in sorted(defined):
        if t not in prov:
            bad('types.h', 0, f'{t} has no // @prov line')
        elif prov[t] not in CLASSES:
            bad('types.h', 0, f'{t}: class {prov[t]!r}')

for p in problems:
    print(p)
print(f'check-tables: {len(names)} names, {len(problems)} problems')
sys.exit(1 if problems else 0)
