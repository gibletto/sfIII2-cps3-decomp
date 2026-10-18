#!/usr/bin/env python3
"""List the rows of ghidra/names/functions.tsv that si2map's census contradicts, with both sides' evidence.

    python tools/census-diff.py <census.tsv> [<old census.tsv>]

For each row with a 3s reference: the census row of its sf3_name. Reported:
  moved     the census places the routine at another 2i address
  absent    the census does not place it (ours does)
  class     the census class differs from ours (3s-exact/3s-reloc/3s-near against exact/reloc/near)
  taken     the census places another 3s routine at our address
  extent    the census 2i size differs from what our row says (our "size N" is the 3s size for exact/reloc)
With <old census.tsv>: only the census rows that changed since then are considered (a reconcile after a fix
pass). Output: kind, address, name, our class, our note (shortened), census name/class/addr2/size2/sim/via.
Nothing is changed; rows are edited by hand, each with a note.
"""
import re, sys

def load(p):
    rows = [l.rstrip('\n').split('\t') for l in open(p, encoding='utf-8')]
    return [dict(zip(rows[0], r)) for r in rows[1:]]

new = load(sys.argv[1])
old = {c['name']: c for c in load(sys.argv[2])} if len(sys.argv) > 2 else None
by_name = {c['name']: c for c in new}
by_addr = {}
for c in new:
    if c['addr2'] and c['class'] not in ('absent',):
        by_addr.setdefault(c['addr2'], c)
changed = None if old is None else {n for n, c in by_name.items() if old.get(n) != c}
CLS = {'exact': '3s-exact', 'reloc': '3s-reloc', 'near': '3s-near', 'near-moved': '3s-near'}
T = __import__('pathlib').Path(__file__).resolve().parent.parent / 'ghidra' / 'names' / 'functions.tsv'
out = []
for l in T.read_text(encoding='utf-8').splitlines():
    if not l.strip() or l.startswith('#'):
        continue
    r = l.split('\t')
    addr, name, cls, sf3, note = r[0], r[1], r[3], r[5], r[7]
    c = by_name.get(sf3)
    t = by_addr.get(addr)
    def ev(c):
        return '' if not c else f'{c["name"]} {c["class"]} {c["addr2"]} size2 {c["size2"]} sim {c["sim"]} via {c.get("via", "")}'
    def add(kind, c):
        if changed is None or (c and c['name'] in changed):
            out.append(f'{kind}\t{addr}\t{name}\t{cls}\t{note[:120]}\t{ev(c)}')
    if c:
        if not c['addr2']:
            add('absent', c)
        elif c['addr2'] != addr:
            add('moved', c)
        else:
            if CLS.get(c['class'], cls) != cls and cls != 'inferred':
                add('class', c)
            m = re.match(r'(?:reloc \d+, )?size (\d+)', note)
            if m and cls in ('3s-exact', '3s-reloc') and c['size2'] and int(c['size2']) != int(m.group(1)):
                add('extent', c)
    if t and t['name'] != sf3 and t['class'] in ('exact', 'reloc'):
        add('taken', t)
print('kind\taddress\tname\tour class\tour note\tcensus')
print('\n'.join(out))
import collections
print(dict(collections.Counter(o.split('\t')[0] for o in out)), file=sys.stderr)
