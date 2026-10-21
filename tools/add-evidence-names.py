#!/usr/bin/env python3
"""Add (and, where the lead approved, rename) rows from an agent's names_needed list with its own evidence.

    python tools/add-evidence-names.py <names_needed.tsv> <3s tree> <label> [--rename] [--only N1,N2,..] [--dry]

<names_needed.tsv>: name, 2i address, kind ("function ...", "global ..."; "new, provisional name" makes the class
new), evidence (prose, copied into the note with <label>). A row goes to functions.tsv or globals.tsv by kind.
Class from the bytes against the 3s symbol of the same name (tmp/r50/ms34.tsv size for a routine, the 3s map
extent for data, at most 4K): 3s-exact, 3s-reloc, 3s-near (halfword similarity, PC-relative displacements masked,
at least half), else inferred; a RAM address (02xxxxxx) with a 3s symbol is 3s-exact at the 3s address, else
3s-reloc; no 3s symbol: new if the kind says provisional, else inferred.
An address that already has a row with another name, or a name already used elsewhere, is reported; with
--rename (an approved rename) the row at the address takes the new name, keeps its class and 3s reference when
they come from its bytes (named by role, classed by bytes), and a row elsewhere holding the name loses it (its
address stays a function through entries.tsv).
"""
import bisect, difflib, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NAMES = ROOT / 'ghidra' / 'names'
args = [a for a in sys.argv[1:] if not a.startswith('--')]
NEED, TREE, LABEL = args[0], Path(args[1]), args[2]
DRY, RENAME = '--dry' in sys.argv, '--rename' in sys.argv
ONLY = set(sys.argv[sys.argv.index('--only') + 1].split(',')) if '--only' in sys.argv else None
if ONLY:
    args = args[:3]
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
addrs3 = sorted(set(s3.values()))
units = []
lines = open(TREE / 'sf3.map', encoding='latin-1').read().splitlines()
for i, l in enumerate(lines[1:], 1):
    m = re.match(r"\s{10,}(\w+)\s+(\w+)\s*$", l)
    r = re.search(r"H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})", lines[i - 1])
    if m and r:
        units.append((int(r.group(1), 16), int(r.group(2), 16) + 1, m.group(1)))
units.sort()


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
        pat = (re.compile(rf'^(?![\s#/*{{}}]).*\b{re.escape(name)}\s*\((?!.*;\s*$)') if func else
               re.compile(rf'^(?![\s#/*{{}}])(?!extern\b).*\b{re.escape(name)}\b\s*(\[|=|;|,)'))
        for n, l in enumerate(p.read_text(encoding='latin-1').splitlines(), 1):
            if pat.search(l):
                return f'{rel}:{n}'
    return first


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


def judge(a3, a2, size):
    b3 = img3[a3 - BASE:a3 - BASE + size]
    b2 = img2[a2 - BASE:a2 - BASE + size]
    if b3 == b2:
        return '3s-exact', f'size {size}'
    words = [(word(b3, o), word(b2, o)) for o in range(0, size - 3, 4)]
    diff = [(x, y) for x, y in words if x != y]
    if diff and all(isaddr(x) and isaddr(y) for x, y in diff) and b3[len(words) * 4:] == b2[len(words) * 4:]:
        return '3s-reloc', f'reloc {len(diff)}, size {size}'
    sim = difflib.SequenceMatcher(None, [norm(b2[i:i + 2]) for i in range(0, size, 2)],
                                  [norm(b3[i:i + 2]) for i in range(0, size, 2)], autojunk=False).ratio()
    e = f'sim {round(100 * sim)}% (halfwords, PC-relative displacements masked), size {size}'
    return ('3s-near' if sim >= 0.5 else 'inferred'), e


def load(t):
    text = (NAMES / t).read_text(encoding='utf-8')
    return ([l for l in text.splitlines() if l.startswith('#')],
            {l.split('\t')[0]: l.split('\t') for l in text.splitlines() if l.strip() and not l.startswith('#')})


tabs = {t: load(t) for t in ('functions.tsv', 'globals.tsv', 'entries.tsv')}
log, problems = [], []
freed = {}
for l in open(NEED, encoding='utf-8').read().splitlines()[1:]:
    if not l.strip():
        continue
    p = l.split('\t')
    n, a, kind, ev = p[0], p[1].upper(), p[2], p[3] if len(p) > 3 else ''
    if ONLY and n not in ONLY:
        continue
    func = kind.startswith('function')
    t = 'functions.tsv' if func else 'globals.tsv'
    rows = tabs[t][1]
    other = tabs['globals.tsv' if func else 'functions.tsv'][1]
    here = rows.get(a) or other.get(a)
    freed_here = freed.pop(a, None)          # a row this run took a name from: its bytes still describe this address
    held = [(tt, aa) for tt in ('functions.tsv', 'globals.tsv') for aa, r in tabs[tt][1].items() if r[1] == n]
    if here and here[1] == n:
        continue                            # already there
    if (here or held) and not RENAME:
        problems.append(f'{n} {a}: ' + (f'the row here is {here[1]}' if here else f'the name is at {held[0][1]}'))
        continue
    a2 = int(a, 16)
    a3 = s3.get(n)
    if a3 is None and n in ms:
        a3 = ms[n][0]
    provisional = 'provisional' in kind
    if a3 is None:
        cls, e, sf3a, sf3n, src = ('new' if provisional else 'inferred'), '', '', '', ''
    elif (a2 >> 24) == 0x02:
        cls, e = ('3s-exact' if a2 == a3 else '3s-reloc'), 'ram refs 1 conflicts 0 (the link)'
        sf3a, sf3n, src = f'{a3:08X}', n, find_def(n, unit_of(a3), False)
    else:
        if func and n in ms:
            size, mod = ms[n][1], ms[n][2]
        else:
            k = bisect.bisect_right(addrs3, a3)
            size, mod = min((addrs3[k] if k < len(addrs3) else a3 + 4) - a3, 0x1000), unit_of(a3)
        cls, e = judge(a3, a2, size)
        sf3a, sf3n, src = f'{a3:08X}', n, find_def(n, mod, func)
    note = (e + '; ' if e else '') + f'{LABEL}: {ev}'
    if cls == 'inferred' and a3 is not None:
        note = f'the bytes differ from sf3 {n} ({e}); named by {LABEL}: {ev}'
    if not here and freed_here:
        here = freed_here
    if here:                                # approved rename: name by role, class by bytes when it has them
        if here[3] in ('3s-exact', '3s-reloc') and 'si2map census' not in here[7]:
            cls, sf3a, sf3n, src = here[3], here[4], here[5], here[6]
            note = f'{here[7].split(";")[0]}; the bytes are sf3 {here[5]}, the name is its role here: {LABEL}: {ev}'
        note += f'; renamed from {here[1]} ({here[3]})'
        log.append(f'renamed {a} {here[1]} -> {n} ({cls})')
    else:
        log.append(f'added {t[:-4]} {a} {n} ({cls})')
    for tt, aa in held:
        if aa != a:
            old = tabs[tt][1].pop(aa)
            freed[aa] = old
            if tt == 'functions.tsv':
                tabs['entries.tsv'][1].setdefault(aa, [aa, f'unnamed after {n} moved to {a} ({LABEL}); was {old[3]}'])
            log.append(f'name removed {aa} {n} (was {old[3]})')
    (other if other.get(a) else rows)[a] = [a, n, '', cls, sf3a, sf3n, src, note]

for x in problems:
    print('PROBLEM', x)
for x in log:
    print(x)
for aa in list(tabs['entries.tsv'][1]):    # a freed address that got a name again needs no entry
    if aa in tabs['functions.tsv'][1] and tabs['entries.tsv'][1][aa][1].startswith('unnamed after'):
        del tabs['entries.tsv'][1][aa]
if not DRY:
    for t, (head, rows) in tabs.items():
        body = ['\t'.join(rows[a]) for a in sorted(rows, key=lambda x: int(x, 16))]
        (NAMES / t).write_text('\n'.join(head + body) + '\n', encoding='utf-8', newline='\n')
    print('written')
