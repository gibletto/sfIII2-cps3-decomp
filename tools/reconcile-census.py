#!/usr/bin/env python3
"""Reconcile ghidra/names/functions.tsv with a newer si2map census, changing only rows the new evidence plainly beats.

    python tools/reconcile-census.py <new census.tsv> <old census.tsv> <new pins.tsv> <label> [--dry]

Only census rows that changed between the two runs are considered, and rows resting on si2map pins the new pins
no longer give (tools/census-diff.py lists them all). A row of
ours is replaceable when its only evidence was the old census, or si2map pins the new pins no longer give: no
literal pool or table word of our own (a hand-edited row never is). A row whose name the new pins still put at its
address keeps the name: that is its role. Changes, each noted with <label>:
  moved   a replaceable row whose routine the new census places elsewhere with exact/reloc bytes, or as near with
          at least the old similarity, moves there when that address is free or replaceable
  taken   a replaceable 3s-near or inferred row at an address where the new census places another routine with exact or reloc
          bytes becomes that routine (when its name is not used elsewhere); when the new pins still name the row
          there, or the routine is the same slot of another character's module (Passive16_0132 for our
          Passive01_0132), it keeps its name and takes that routine's class and 3s reference (named by role,
          classed by bytes)
  class   a 3s-near row the new census finds exact or reloc at the same address takes that class
Everything else is listed, not changed. Prints the changes and the remaining contradictions by kind.
"""
import collections, re, sys
from pathlib import Path

NEW, OLD, PINS, LABEL = sys.argv[1:5]
DRY = '--dry' in sys.argv
T = Path(__file__).resolve().parent.parent / 'ghidra' / 'names' / 'functions.tsv'


def load(p):
    rows = [l.rstrip('\n').split('\t') for l in open(p, encoding='utf-8')]
    return {r[0]: dict(zip(rows[0], r)) for r in rows[1:]}


new, old = load(NEW), load(OLD)
changed = {n for n, c in new.items() if old.get(n) != c}
pinned = {(l.split('\t')[0], l.split('\t')[1].upper()) for l in open(PINS, encoding='utf-8').read().splitlines()[1:]}
lines = T.read_text(encoding='utf-8').splitlines()
head = [l for l in lines if l.startswith('#')]
rows = {l.split('\t')[0]: l.split('\t') for l in lines if l.strip() and not l.startswith('#')}
at_name = {r[1]: a for a, r in rows.items()}
src = {}                                    # 3s name -> our sf3_src (to reuse for a routine we already cite)
for r in rows.values():
    src.setdefault(r[5], r[6])


def replaceable(r):
    n = r[7]
    if 'table word' in n or 'literal-pool slot' in n or 'hand edit' in n:
        return False
    # evidence from the old census, or from si2map pins the new pins no longer give
    return 'si2map census' in n or ('si2map table pin' in n and (r[1], r[0]) not in pinned)


def withdrawn(r):
    """the row rests on si2map pins alone and the new pins no longer give it"""
    n = r[7]
    return ('si2map table pin' in n and 'si2map census' not in n and 'table word' not in n
            and 'literal-pool slot' not in n and (r[1], r[0]) not in pinned)


def sim(c):
    return float(c['sim'] or 0)


def cls_of(c):
    return '3s-near' if c['class'].startswith('near') else '3s-' + c['class']


def note_of(c):
    if c['class'].startswith('near'):
        return (f'sim {round(100 * sim(c))}%: {c["diffs"] or 0} instructions differ, 2i size {c["size2"]} vs 3s '
                f'{c["size3"]} (si2map census)')
    if c['class'] == 'exact':
        return f'size {c["size3"]} (si2map census)'
    return f'reloc {c["relocs"] or 0}, size {c["size3"]} (si2map census: addresses, displacements or pool offsets differ)'


def row_for(c, why):
    return [c['addr2'], c['name'], '', cls_of(c), c['addr3'], c['name'], src.get(c['name'], ''),
            note_of(c) + f'; {LABEL}: {why}']


log = collections.Counter()
done = []
by_addr = {}
for c in new.values():
    if c['addr2'] and c['class'] in ('exact', 'reloc', 'near', 'near-moved'):
        by_addr.setdefault(c['addr2'], c)

# class: near -> exact/reloc at the same address
for a, r in rows.items():
    c = new.get(r[5])
    if c and c['name'] in changed and r[3] == '3s-near' and c['addr2'] == a and c['class'] in ('exact', 'reloc') \
            and r[1] == r[5]:
        rows[a] = row_for(c, f'the new census finds {c["class"]} bytes here (was {r[7][:40]})')
        log['class'] += 1
        done.append(('class', a, r[1], rows[a][3]))

# moved
for a, r in list(rows.items()):
    if a not in rows or rows[a] is not r:
        continue
    c = new.get(r[5])
    if not c or not (c['name'] in changed or withdrawn(r)) or not replaceable(r) or r[1] != r[5] or not c['addr2']             or c['addr2'] == a:
        continue
    oldsim = 0.0 if r[3] == 'inferred' else float(m.group(1)) / 100 if (m := re.match(r'sim (\d+)%', r[7])) else 1.0
    if not (c['class'] in ('exact', 'reloc') or (c['class'].startswith('near') and sim(c) >= oldsim)):
        continue
    if (r[1], a) in pinned:
        log['moved, but the new pins keep it here'] += 1
        continue
    t = rows.get(c['addr2'])
    if t is not None and not (replaceable(t) and t[3] in ('3s-near', 'inferred')):
        log['moved, target held by a stronger row'] += 1
        continue
    if t is not None:
        del at_name[t[1]]
    del rows[a]
    rows[c['addr2']] = row_for(c, f'moved from {a} by the new census ({c["class"]}, sim {sim(c):.2f}, via {c.get("via", "")})')
    at_name[r[1]] = c['addr2']
    log['moved'] += 1
    done.append(('moved', a, r[1], c['addr2']))

# taken
for a, r in list(rows.items()):
    c = by_addr.get(a)
    if not c or not (c['name'] in changed or withdrawn(r)) or c['name'] == r[5] or c['class'] not in ('exact', 'reloc'):
        continue
    if r[3] not in ('3s-near', 'inferred') or not replaceable(r):
        continue
    slot = re.sub(r'\d\d_', '_', r[1]) == re.sub(r'\d\d_', '_', c['name'])
    if (r[1], a) in pinned or slot:         # the role stands: the name stays, the class follows the bytes
        rows[a] = [a, r[1], r[2], cls_of(c), c['addr3'], c['name'], src.get(c['name'], ''),
                   note_of(c) + f'; {LABEL}: the bytes are sf3 {c["name"]}, the name is its role here (' +
                   ('si2map pin' if (r[1], a) in pinned else "the same slot of another character's copy") + ')']
        log['taken, kept by role'] += 1
        done.append(('role', a, r[1], c['name']))
        continue
    if c['name'] in at_name:
        log['taken, census routine named elsewhere here'] += 1
        continue
    del at_name[r[1]]
    rows[a] = row_for(c, f'replaces {r[1]} ({r[7][:40]}): the new census finds {c["name"]} {c["class"]} here')
    at_name[c['name']] = a
    log['taken'] += 1
    done.append(('taken', a, r[1], c['name']))

for d in done:
    print(*d, sep='\t')
print(dict(log))
if not DRY:
    out = head + ['\t'.join(rows[a]) for a in sorted(rows, key=lambda x: int(x, 16))]
    T.write_text('\n'.join(out) + '\n', encoding='utf-8', newline='\n')
