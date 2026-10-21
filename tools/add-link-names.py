#!/usr/bin/env python3
"""Add the names the sf2i build needs to the naming tables, with the link as evidence (add-only).

    python tools/add-link-names.py <names_needed.tsv> <3s tree> [--dry]

<names_needed.tsv> (si2build): name, addr2, sf3_addr, what (ROM data / RAM / code / defined by <module>), refs.
The build (sf2i/sf2i.map) is byte-identical to 2nd Impact, so its map proves each address. Each name is checked
against sf2i.map (the C name is the map symbol without its leading underscore) and gets a row:
  code / defined by   functions.tsv; class from the bytes: the 3s routine (tmp/r50/ms34.tsv size) against the
                      2i image: 3s-exact, 3s-reloc (only address words differ), else the census class at that
                      address (3s-near), else inferred
  ROM data            globals.tsv; compared over the 3s extent (to the next 3s map symbol): 3s-exact, 3s-reloc,
                      3s-near (half the words or more equal), else inferred
  RAM                 globals.tsv; 3s-exact at the 3s address, else 3s-reloc
Every note cites the link and the referencing modules. A name or address that already has a row is reported, not
changed: a second label at an address (the run-time library's _x / __x pairs) needs a decision first.
"""
import bisect, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NEED, TREE = sys.argv[1], Path(sys.argv[2])
DRY = '--dry' in sys.argv
BASE = 0x06000000
img2 = (ROOT / 'scratch' / 'rom' / 'prog.bin').read_bytes()
img3 = (TREE / 'verify' / 'bootstrap' / 'prog.bin').read_bytes()


def word(b, o):
    return int.from_bytes(b[o:o + 4], 'big')


def isaddr(w):
    return (w >> 24) in (0x02, 0x04, 0x05, 0x06)


def mapsyms(path):
    out = {}
    for l in open(path, encoding='latin-1'):
        m = re.match(r"(\S+)\s+H'([0-9A-F]{8})\s+(ENT|DAT)\s*$", l)
        if m:
            out.setdefault(m.group(1), int(m.group(2), 16))
    return out


link = mapsyms(ROOT / 'sf2i' / 'sf2i.map')
link_at = {}
for n, a in link.items():
    link_at.setdefault(a, []).append(n[1:] if n.startswith('_') else n)
s3 = mapsyms(TREE / 'sf3.map')
addrs3 = sorted(set(s3.values()))
units = []
lines = open(TREE / 'sf3.map', encoding='latin-1').read().splitlines()
for i, l in enumerate(lines[1:], 1):
    m = re.match(r"\s{10,}(\w+)\s+(\w+)\s*$", l)
    r = re.search(r"H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})", lines[i - 1])
    if m and r:
        units.append((int(r.group(1), 16), int(r.group(2), 16) + 1, m.group(1)))
units.sort()
ms = {}
for l in open(TREE.parent.parent / 'tmp' / 'r50' / 'ms34.tsv', encoding='utf-8'):
    p = l.rstrip('\n').split('\t')
    if len(p) > 4 and re.fullmatch(r'[0-9A-Fa-f]{8}', p[1]):
        ms[int(p[1], 16)] = (p[0], int(p[2]), p[3], p[4])
census = {}
rows = [l.rstrip('\n').split('\t') for l in open(ROOT / 'scratch' / 'si2map' / 'census.tsv', encoding='utf-8')]
for r in rows[1:]:
    c = dict(zip(rows[0], r))
    if c['addr2']:
        census.setdefault(int(c['addr2'], 16), c)


def unit_of(a):
    i = bisect.bisect_right(units, (a, 1 << 40, '')) - 1
    return units[i][2] if i >= 0 and units[i][0] <= a < units[i][1] else None


def find_def(name, module, func):
    if not module:
        return ''
    files = [module] if '.' in module else [f'{module}.c', f'{module}.src']
    first = ''
    for rel in [f'{d}/{f}' for d in ('src', 'data') for f in files]:
        p = TREE / rel
        if not p.is_file():
            continue
        first = first or rel
        if rel.endswith('.src'):
            pat = re.compile(rf'^_?_?{re.escape(name.lstrip("_"))}:')
        elif func:
            pat = re.compile(rf'^(?![\s#/*{{}}]).*\b{re.escape(name)}\s*\((?!.*;\s*$)')
        else:
            pat = re.compile(rf'^(?![\s#/*{{}}])(?!extern\b)(?!.*\(\s*\*?\s*\w*\s*\)\s*\().*\b{re.escape(name)}\b\s*(\[|=|;|,)')
        for n, l in enumerate(p.read_text(encoding='latin-1').splitlines(), 1):
            if pat.search(l):
                return f'{rel}:{n}'
    return first


def compare(a3, a2, size):
    """3s bytes at a3 against 2i bytes at a2 -> (class, evidence) or None when under half the words agree"""
    b3 = img3[a3 - BASE:a3 - BASE + size]
    b2 = img2[a2 - BASE:a2 - BASE + size]
    if b3 == b2:
        return '3s-exact', f'size {size}'
    words = [(word(b3, o), word(b2, o)) for o in range(0, size - 3, 4)]
    diff = [(x, y) for x, y in words if x != y]
    tail = b3[len(words) * 4:] == b2[len(words) * 4:]
    if tail and diff and all(isaddr(x) and isaddr(y) for x, y in diff):
        return '3s-reloc', f'reloc {len(diff)}, size {size}'
    if words and 2 * len(diff) <= len(words):
        return '3s-near', f'sim {100 * (len(words) - len(diff)) // len(words)}% of {len(words)} words equal, size {size}'
    return None


tables = {}
for t in ('functions.tsv', 'globals.tsv'):
    p = ROOT / 'ghidra' / 'names' / t
    text = p.read_text(encoding='utf-8')
    tables[t] = (p, text, {l.split('\t')[0]: l.split('\t')[1] for l in text.splitlines() if l.strip() and not l.startswith('#')})
names = {n for _, _, h in tables.values() for n in h.values()}
add = {'functions.tsv': [], 'globals.tsv': []}
report = []
pending = {}                                # 2i address -> name added in this run
for l in open(NEED, encoding='utf-8').read().splitlines()[1:]:
    name, addr2, sf3, what, refs = (l.split('\t') + [''] * 5)[:5]
    a2, a3 = int(addr2, 16), int(sf3, 16)
    cand = link_at.get(a2, [])
    if name not in cand:                    # a name cut short in the list: the link's symbol ending in it
        fix = [c for c in cand if c.endswith(name)]
        if len(fix) != 1:
            report.append(f'not in the link at {addr2}: {name} (link has {cand})')
            continue
        report.append(f'name corrected from the link: {name} -> {fix[0]}')
        name = fix[0]
    code = what in ('code',) or what.startswith('defined by')
    t = 'functions.tsv' if code else 'globals.tsv'
    held = tables[t][2].get(f'{a2:08X}') or tables['functions.tsv' if t == 'globals.tsv' else 'globals.tsv'][2].get(f'{a2:08X}')
    held = held or pending.get(a2)
    if name in names:
        report.append(f'already a row: {name}')
        continue
    if held:
        report.append(f'second label at {addr2}: {name} (the row there is {held}); needs a decision')
        continue
    module = what[len('defined by '):] if what.startswith('defined by') else unit_of(a3)
    link_note = (f'sf2i link: {name} at {addr2} in the byte-identical build (sf2i/sf2i.map)' +
                 (f', defined by module {module}' if what.startswith('defined by') else '') +
                 (f'; referenced by {refs}' if refs else ''))
    if what == 'RAM':
        cls = '3s-exact' if a2 == a3 else '3s-reloc'
        n_refs = sum(int(x.split(':')[1]) for x in refs.split() if ':' in x) or 1
        note = f'ram refs {n_refs} conflicts 0 (the link); ' + link_note
    else:
        if code:
            size = ms[a3][1] if a3 in ms else 4
        else:
            k = bisect.bisect_right(addrs3, a3)
            size = min((addrs3[k] if k < len(addrs3) else a3 + 4) - a3, 0x10000)
        c = compare(a3, a2, size)
        cen = census.get(a2)
        if c is None and code and cen and cen['name'] == name and cen['class'].startswith('near'):
            c = ('3s-near', f'sim {round(100 * float(cen["sim"]))}% (si2map census)')
        if c is None:
            cls, note = 'inferred', f'the bytes differ from sf3 {name} (under half the words equal); named by ' + link_note
        else:
            cls, note = c[0], c[1] + '; ' + link_note
    src = find_def(name, module + ('.src' if what.startswith('defined by') and not (TREE / 'src' / f'{module}.c').is_file()
                                    and (TREE / 'src' / f'{module}.src').is_file() else ''), code) if module else ''
    pending[a2] = name
    add[t].append([f'{a2:08X}', name, '', cls, f'{a3:08X}', name, src, note])
    names.add(name)

for t, rows_ in add.items():
    p, text, _ = tables[t]
    lines_ = [l for l in text.splitlines() if l.strip()]
    head = [l for l in lines_ if l.startswith('#')]
    body = [l for l in lines_ if not l.startswith('#')] + ['\t'.join(r) for r in rows_]
    body.sort(key=lambda l: int(l.split('\t')[0], 16))
    if not DRY:
        p.write_text('\n'.join(head + body) + '\n', encoding='utf-8', newline='\n')
    from collections import Counter
    print(f'{t}: {len(rows_)} added: {dict(Counter(r[3] for r in rows_))}')
for r in report:
    print(' ', r)
