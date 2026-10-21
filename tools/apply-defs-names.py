#!/usr/bin/env python3
"""Make the naming tables agree with the names a byte-identical build defines (sf2i/build/layout/defs.tsv).

    python tools/apply-defs-names.py <3s tree> <label> <defs.tsv>... [--modules REGEX] [--apply]

defs.tsv (written by the sf2i build): symbol, 2i address, module; every module in it is a source module (C, asm
or lib) of a byte-identical link, so its names are the ground truth at their addresses. An address with two
symbols (an _x/__x pair) is left to aliases.tsv. Only modules matching REGEX (default: all) are considered.
For each defined name (leading underscore dropped) at address A:
  match       the row at A has the name
  add         no row at A and the name is unused: a row is added (class from the bytes against the 3s routine
              of that name; else inferred)
  rename      the row at A has another name and rests on the census, pins or pointers: renamed (named by the
              build; class and 3s reference follow the bytes, the old row's if they were byte evidence)
  hand        the row at A is hand-edited or a lead decision: reported, not changed
  own-bytes   the row at A is 3s-exact/3s-reloc by our own match: reported, not changed
A row elsewhere that holds a name the build defines at A loses it when A is renamed or added (its address stays
a function through entries.tsv), unless it is hand-edited or own-bytes (then A is reported instead).
Without --apply nothing is written. Prints counts by case and writes the list to scratch/si2ghidra/defs_report.tsv.
"""
import collections, difflib, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NAMES = ROOT / 'ghidra' / 'names'
argv = sys.argv[1:]
MODRE = re.compile(argv[argv.index('--modules') + 1]) if '--modules' in argv else re.compile('')
APPLY = '--apply' in argv
pos = [a for i, a in enumerate(argv) if not a.startswith('--') and (i == 0 or argv[i - 1] != '--modules')]
TREE, LABEL, DEFS = Path(pos[0]), pos[1], pos[2:]
BASE = 0x06000000
img2 = (ROOT / 'scratch' / 'rom' / 'prog.bin').read_bytes()
img3 = (TREE / 'verify' / 'bootstrap' / 'prog.bin').read_bytes()

ms = {}
for l in open(TREE.parent.parent / 'tmp' / 'r50' / 'ms34.tsv', encoding='utf-8'):
    p = l.rstrip('\n').split('\t')
    if len(p) > 4 and re.fullmatch(r'[0-9A-Fa-f]{8}', p[1]):
        ms[p[0]] = (int(p[1], 16), int(p[2]), p[3])


s3 = {}
for l in open(TREE / 'sf3.map', encoding='latin-1'):
    m = re.match(r"_(\S+)\s+H'([0-9A-F]{8})\s+(ENT|DAT)\s*$", l)
    if m:
        s3.setdefault(m.group(1), int(m.group(2), 16))


def find_def(name, rel):
    p = TREE / rel
    if not p.is_file():
        return ''
    pat = re.compile(rf'^(?![\s#/*{{}}]).*\b{re.escape(name)}\s*\((?!.*;\s*$)')
    for n, l in enumerate(p.read_text(encoding='latin-1').splitlines(), 1):
        if pat.search(l):
            return f'{rel}:{n}'
    return rel


def word(b, o):
    return int.from_bytes(b[o:o + 4], 'big')


def isaddr(w):
    return (w >> 24) in (0x02, 0x04, 0x05, 0x06)


def norm(h):
    v = int.from_bytes(h, 'big')
    t = v >> 12
    if t in (0x9, 0xD):
        return v & 0xFF00
    if t in (0xA, 0xB):
        return v & 0xF000
    if (v & 0xFF00) in (0x8900, 0x8B00, 0x8D00, 0x8F00):
        return v & 0xFF00
    return v


def judge(name, a2):
    """(class, evidence, sf3 addr, sf3 src) against the 3s routine of that name, or None"""
    if name not in ms:
        return None
    a3, size, mod = ms[name]
    b3, b2 = img3[a3 - BASE:a3 - BASE + size], img2[a2 - BASE:a2 - BASE + size]
    if b3 == b2:
        c, e = '3s-exact', f'size {size}'
    else:
        words = [(word(b3, o), word(b2, o)) for o in range(0, size - 3, 4)]
        diff = [(x, y) for x, y in words if x != y]
        if diff and all(isaddr(x) and isaddr(y) for x, y in diff) and b3[len(words) * 4:] == b2[len(words) * 4:]:
            c, e = '3s-reloc', f'reloc {len(diff)}, size {size}'
        else:
            sim = difflib.SequenceMatcher(None, [norm(b2[i:i + 2]) for i in range(0, size, 2)],
                                          [norm(b3[i:i + 2]) for i in range(0, size, 2)], autojunk=False).ratio()
            c = '3s-near' if sim >= 0.5 else 'inferred'
            e = f'sim {round(100 * sim)}% (halfwords, PC-relative displacements masked), size {size}'
    return c, e, f'{a3:08X}', find_def(name, f'src/{mod}')


def load(t):
    text = (NAMES / t).read_text(encoding='utf-8')
    return ([l for l in text.splitlines() if l.startswith('#')],
            {l.split('\t')[0]: l.split('\t') for l in text.splitlines() if l.strip() and not l.startswith('#')})


def evidence(r):
    n = r[7]
    if 'hand edit' in n or 'lead decision' in n or 'lead-approved' in n:
        return 'hand'
    if r[3] in ('3s-exact', '3s-reloc') and 'si2map census' not in n:
        return 'own-bytes'
    return 'soft'


tabs = {t: load(t) for t in ('functions.tsv', 'globals.tsv', 'entries.tsv')}
defs = collections.defaultdict(set)
modof = {}
for f in DEFS:
    for l in open(f, encoding='utf-8'):
        p = l.rstrip('\n').split('\t')
        if len(p) >= 3 and MODRE.search(p[2]):
            defs[p[1].upper()].add(p[0][1:] if p[0].startswith('_') else p[0])
            modof[p[1].upper()] = p[2]
where = {}
for t in ('functions.tsv', 'globals.tsv'):
    for a, r in tabs[t][1].items():
        where[r[1]] = (t, a)
cases, report = collections.Counter(), []
for a in sorted(defs, key=lambda x: int(x, 16)):
    if len(defs[a]) != 1:
        cases['two names (aliases)'] += 1
        continue
    n = next(iter(defs[a]))
    t = 'functions.tsv' if a in tabs['functions.tsv'][1] or (a not in tabs['globals.tsv'][1] and 0x06000400 <= int(a, 16) < 0x060FC564) else 'globals.tsv'
    row = tabs[t][1].get(a)
    if row and row[1] == n:
        cases['match'] += 1
        continue
    held = where.get(n)
    blocker = None
    if row and evidence(row) != 'soft':
        blocker = (evidence(row), f'the row here is {row[1]} ({row[3]})')
    elif held and held[1] != a and evidence(tabs[held[0]][1][held[1]]) != 'soft':
        hr = tabs[held[0]][1][held[1]]
        blocker = (evidence(hr), f'the name is at {held[1]} ({hr[3]}, {evidence(hr)})')
    if blocker:
        cases[blocker[0]] += 1
        report.append((blocker[0], a, n, modof[a], blocker[1]))
        continue
    case = 'rename' if row else 'add'
    j = judge(n, int(a, 16)) if t == 'functions.tsv' else None
    slot = f'; the byte-identical build {LABEL} defines {n} here ({modof[a]})'
    if row and row[3] in ('3s-exact', '3s-reloc') and 'si2map census' not in row[7]:
        new = row[:1] + [n, row[2], row[3], row[4], row[5], row[6], f'{row[7]}; the name is its role here{slot}']
    elif j:
        cls, e, a3, src = j
        new = [a, n, '', cls, a3, n, src, f'{e}{slot}']
    else:
        a3 = s3.get(n)
        if a3 is not None and int(a, 16) >> 24 == 0x02:
            new = [a, n, '', '3s-exact' if a3 == int(a, 16) else '3s-reloc', f'{a3:08X}', n, '',
                   f'ram refs 1 conflicts 0 (the build){slot}']
        elif a3 is not None:
            new = [a, n, '', 'inferred', f'{a3:08X}', n, '', f'named by the build (3s has the symbol){slot}']
        else:
            new = [a, n, '', 'inferred', '', '', '', f'named by the build{slot}']
    if row:
        new[7] += f'; renamed from {row[1]} ({row[3]}, which rested on the census, pins or pointers)'
        del where[row[1]]
    if held and held[1] != a:
        old = tabs[held[0]][1].pop(held[1])
        if held[0] == 'functions.tsv':
            tabs['entries.tsv'][1].setdefault(held[1], [held[1], f'unnamed after {n} moved to {a} ({LABEL}); was {old[3]}'])
        report.append(('name moved', held[1], n, '', f'to {a}'))
    tabs[t][1][a] = new
    where[n] = (t, a)
    cases[case] += 1
    report.append((case, a, n, modof[a], f'was {row[1]}' if row else ''))
for aa in list(tabs['entries.tsv'][1]):
    if aa in tabs['functions.tsv'][1] and tabs['entries.tsv'][1][aa][1].startswith('unnamed after'):
        del tabs['entries.tsv'][1][aa]
print(dict(cases))
(ROOT / 'scratch' / 'si2ghidra' / 'defs_report.tsv').write_text(
    'case\taddress\tname\tmodule\tdetail\n' + '\n'.join('\t'.join(r) for r in report) + '\n', encoding='utf-8', newline='\n')
if APPLY:
    for t, (head, rows) in tabs.items():
        body = ['\t'.join(rows[x]) for x in sorted(rows, key=lambda x: int(x, 16))]
        (NAMES / t).write_text('\n'.join(head + body) + '\n', encoding='utf-8', newline='\n')
    print('written')
