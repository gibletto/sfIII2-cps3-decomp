#!/usr/bin/env python3
"""Name routines by their dispatch-table slots, proven by a byte-identical build (lead-approved renames).

    python tools/apply-build-roles.py <names_needed.tsv> <3s tree> <build label> [--dry]

<names_needed.tsv> (si2near1 format): name, 2i_addr, kind ("global (rom table, N entries)" or "function (...)"),
evidence ("ShellNN_Tbl[i]; ...", or no slot: then the name's own, XX_NNNN at XX_Tbl[NNNN]; a "(none)" name is
reported for a decision). <build label>: the byte-identical build that links the module (cited in notes).
Each function row's slot is checked: the word at ShellNN_Tbl + 4*i in the 2i image must be its address (the table
addresses come from the global rows of the same file, or from the existing tables). Then:
  - a row at the address with another name is renamed; a row elsewhere holding the name loses it (deleted, its
    address kept as a function through entries.tsv) unless the same file renames it too;
  - an address with no row gets one.
Class and 3s reference follow the bytes: the 3s routine of the same name and the old row's 3s routine are both
compared (exact, reloc, else the halfword similarity with PC-relative displacements masked); the better one wins.
Global rows (the tables) are added if missing, compared over the 3s table.
"""
import difflib, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NEED, TREE, BUILD = sys.argv[1], Path(sys.argv[2]), sys.argv[3]
DRY = '--dry' in sys.argv
BASE = 0x06000000
img2 = (ROOT / 'scratch' / 'rom' / 'prog.bin').read_bytes()
img3 = (TREE / 'verify' / 'bootstrap' / 'prog.bin').read_bytes()
NAMES = ROOT / 'ghidra' / 'names'


def word(b, o):
    return int.from_bytes(b[o:o + 4], 'big')


def isaddr(w):
    return (w >> 24) in (0x02, 0x04, 0x05, 0x06)


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


def find_def(name, rel, func):
    p = TREE / rel
    if not p.is_file():
        return ''
    pat = (re.compile(rf'^(?![\s#/*{{}}]).*\b{re.escape(name)}\s*\((?!.*;\s*$)') if func else
           re.compile(rf'^(?![\s#/*{{}}])(?!extern\b).*\b{re.escape(name)}\b\s*(\[|=|;|,)'))
    for n, l in enumerate(p.read_text(encoding='latin-1').splitlines(), 1):
        if pat.search(l):
            return f'{rel}:{n}'
    return rel


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
    """(rank, class, evidence): 3s bytes at a3 against 2i at a2 over the 3s size"""
    b3 = img3[a3 - BASE:a3 - BASE + size]
    b2 = img2[a2 - BASE:a2 - BASE + size]
    if b3 == b2:
        return 3, '3s-exact', f'size {size}'
    words = [(word(b3, o), word(b2, o)) for o in range(0, size - 3, 4)]
    diff = [(x, y) for x, y in words if x != y]
    if diff and all(isaddr(x) and isaddr(y) for x, y in diff) and b3[len(words) * 4:] == b2[len(words) * 4:]:
        return 2, '3s-reloc', f'reloc {len(diff)}, size {size}'
    x = [norm(b2[i:i + 2]) for i in range(0, size, 2)]
    y = [norm(b3[i:i + 2]) for i in range(0, size, 2)]
    sim = difflib.SequenceMatcher(None, x, y, autojunk=False).ratio()
    return sim, ('3s-near' if sim >= 0.5 else 'inferred'), f'sim {round(100 * sim)}% (halfwords, PC-relative displacements masked), size {size}'


def load(t, cols):
    text = (NAMES / t).read_text(encoding='utf-8')
    head = [l for l in text.splitlines() if l.startswith('#')]
    rows = {l.split('\t')[0]: l.split('\t') for l in text.splitlines() if l.strip() and not l.startswith('#')}
    return head, rows


fh, frows = load('functions.tsv', 8)
gh, grows = load('globals.tsv', 8)
eh, erows = load('entries.tsv', 2)
need = [l.split('\t') for l in open(NEED, encoding='utf-8').read().splitlines()[1:] if l.strip()]
tbl = {r[1]: int(r[0], 16) for r in grows.values() if r[1].endswith('_Tbl')}
for n, a, kind, ev in need:
    if kind.startswith('global'):
        tbl[n] = int(a, 16)
log, problems = [], []

# globals: the tables
for n, a, kind, ev in need:
    if not kind.startswith('global'):
        continue
    if a in grows or any(r[1] == n for r in grows.values()):
        problems.append(f'{n}: already a globals row')
        continue
    a3 = s3.get(n)
    if a3 is None:
        problems.append(f'{n}: not in sf3.map')
        continue
    k = addrs3.index(a3) + 1
    size = min(addrs3[k] - a3, 0x400) if k < len(addrs3) else 4
    _, cls, e = judge(a3, int(a, 16), size)
    note = (e.replace('size', 'rom size') + f'; the 2i dispatch table of {n[:-4]}: {ev}; the byte-identical build '
            f'{BUILD} links it here')
    grows[a] = [a, n, '', cls, f'{a3:08X}', n, find_def(n, f'data/{n[:-4].upper()}_tbl.c', False), note]
    log.append(f'global added {a} {n} {cls}')

# functions: final names by address
final = {}
for n, a, kind, ev in need:
    if kind.startswith('global'):
        continue
    if n == '(none)':
        problems.append(f'{a}: a row to unname without a new name ({ev[:80]}...): needs a decision')
        continue
    m = re.match(r'(\w+_Tbl)\[(\d+)\]', ev)
    if not m:                               # no slot given: the name's own, XX_NNNN at XX_Tbl[NNNN]
        k = re.fullmatch(r'(\w+)_(\d{4})', n)
        if k and f'{k.group(1)}_Tbl' in tbl:
            m = re.match(r'(\w+_Tbl)\[(\d+)\]', f'{k.group(1)}_Tbl[{int(k.group(2))}]')
    if not m or m.group(1) not in tbl:
        problems.append(f'{n} {a}: no table slot in the evidence')
        continue
    slot = tbl[m.group(1)] + 4 * int(m.group(2))
    if word(img2, slot - BASE) != int(a, 16):
        problems.append(f'{n} {a}: the word at {m.group(1)}[{m.group(2)}] ({slot:08X}) is {word(img2, slot - BASE):08X}')
        continue
    final[a] = (n, f'{m.group(1)}[{m.group(2)}] (the 2i word at {slot:08X} points here)')
names_final = {n for n, _ in final.values()}
for a, (n, slot) in final.items():
    old = frows.get(a)
    if old and old[1] == n:
        continue                            # already named so (an earlier batch)
    cands = [n] + ([old[5]] if old and old[5] and old[5] != n else [])
    best = None
    for c in cands:
        if c in ms:
            a3, size, mod = ms[c]
            j = judge(a3, int(a, 16), size)
            if best is None or j[0] > best[0]:
                best = (j[0], j[1], j[2], c, a3, mod)
    if best is None:
        problems.append(f'{n} {a}: no 3s routine to compare')
        continue
    _, cls, e, c, a3, mod = best
    src = find_def(c, f'src/{mod}', True)
    was = f'was {old[1]} ({old[3]}, census placement)' if old and old[1] != n else ('was unnamed' if not old else 'name kept')
    note = (f'{e}; role: {slot} and the byte-identical build {BUILD}; approved table-slot naming 2026-10-18, {was}' +
            ('' if c == n else f'; the bytes are sf3 {c}, the name is its role here'))
    frows[a] = [a, n, '', cls, f'{a3:08X}', c, src, note]
    log.append(f'{"renamed" if old and old[1] != n else "added" if not old else "updated"} {a} {n} {cls} (sf3 {c})' +
               (f' was {old[1]}' if old and old[1] != n else ''))
# rows elsewhere that held a name now given to a slot address lose it
for a, r in list(frows.items()):
    if a not in final and r[1] in names_final:
        del frows[a]
        erows.setdefault(a, [a, f'unnamed after {r[1]} moved to its table slot ({BUILD}); was {r[3]} by the census'])
        log.append(f'name removed {a} {r[1]} (kept as a function through entries.tsv)')

for p in problems:
    print('PROBLEM', p)
for l in log:
    print(l)
if not DRY:
    for t, head, rows in (('functions.tsv', fh, frows), ('globals.tsv', gh, grows), ('entries.tsv', eh, erows)):
        body = ['\t'.join(rows[a]) for a in sorted(rows, key=lambda x: int(x, 16))]
        (NAMES / t).write_text('\n'.join(head + body) + '\n', encoding='utf-8', newline='\n')
    print('written')
