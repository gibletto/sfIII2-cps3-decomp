#!/usr/bin/env python3
"""Seed ghidra/names/functions.tsv and globals.tsv from the 3rd Strike routine matches (docs/PROVENANCE.md).

    python tools/seed-tables.py <matches.tsv> <3s tree> <3s prog.bin> <prog_op.bin> <prog_data.bin>
        [--census <si2map census.tsv>] [--pins <si2map pins.tsv>] [--why <3s symbol>] [--dry]

<matches.tsv>: tools/match3s_dual.py output. <3s tree>: the 3s source tree (src/, data/, sf3.map).
Routines: every exact or reloc match becomes a 3s-exact / 3s-reloc row. A 3s routine with several hits (a short
routine repeated, or the per-character modules' copies) is placed by its module: the hit whose delta (2i - 3s
address) a placed routine of the same 3s module has; then 3s routines with the same set of hits and as many
routines as hits (the same bytes in several modules) are placed in address order; then by its neighbours: the hit
whose delta the nearest placed routine before or after it has, else the only hit between those two; otherwise it
is left out. Also left out: two routines placed at one 2i address, and a routine placed 32K or more (in delta) from
every other placed routine of its module.
Pointers: the literal-pool words of the placed routines that are addresses (02/04/05/06xxxxxx on both sides) pair a
3s address with a 2i one, and each pair votes for the 3s map symbol containing the 3s address (a routine only by a
pointer to its entry), at the 2i address minus the same offset. A ROM table found that way votes too, word for word
against the 3s table, when it is aligned (3s-exact or 3s-reloc, or nine in ten of its words that point at symbols
already placed agree), and only between agreeing words (one 3s extent can hold several static tables whose 2i
lengths differ). A symbol takes its majority address when that has at least two thirds of the votes. Copies
placed by address order move to the hits the pointers give them, and the placement is redone.
  a 3s routine     a function row, inferred (by its role); when the address is the hit of matched 3s routines the
                   placement left out, the class and 3s reference follow those bytes (the named routine itself if
                   it is one of them)
  RAM (02xxxxxx)   3s-exact when the address is unchanged, else 3s-reloc; note "ram refs N conflicts M"
  ROM data         compared over the 3s extent (to the next 3s symbol, at most 64K): 3s-exact, 3s-reloc (only
                   address words differ; "reloc N"), 3s-near (at least half the words equal; "sim NN%"), else
                   inferred
--census: also seed si2map's census (tools/census3s.py) rows at 2i addresses with no row yet: near (3s-near, its
sim and instruction differences), exact and reloc for routines with one 2i copy (dup 1) or placed by a pin (via
pin; then near-moved too, and changed = a pinned table slot whose routine is rewritten, as inferred).
Rows are only added: an address or a name already in a table is left as it is, and a disagreement is reported.
--pins: si2map's table pins (name, 2i address: a 3s routine pointer and its 2i counterpart in matching data
tables) vote like pointers. --why: print a 3s symbol's votes and table alignment checks. --dry: report only.
"""
import bisect, collections, re, sys
from pathlib import Path

argv = sys.argv[1:]
CENSUS = argv[argv.index('--census') + 1] if '--census' in argv else None
WHY = argv[argv.index('--why') + 1] if '--why' in argv else None
PINS = argv[argv.index('--pins') + 1] if '--pins' in argv else None
args = [a for a in argv if not a.startswith('--') and a not in (CENSUS, WHY, PINS)]
DRY = '--dry' in sys.argv
MATCHES, TREE, P3, OP, DATA = args[:5]
TREE = Path(TREE)
NAMES = Path(__file__).resolve().parent.parent / 'ghidra' / 'names'
BASE = 0x06000000
a3 = open(P3, 'rb').read()
op = open(OP, 'rb').read()
dv = open(DATA, 'rb').read()


def isaddr(w):
    return (w >> 24) in (0x02, 0x04, 0x05, 0x06)


def word(b, off):
    return int.from_bytes(b[off:off + 4], 'big')


# ---- the 3s side: map symbols, link units, source lines

syms = {}                                   # 3s address -> (name, ENT/DAT)
for l in open(TREE / 'sf3.map', encoding='latin-1'):
    m = re.match(r"(\S+)\s+H'([0-9A-F]{8})\s+(ENT|DAT)\s*$", l)
    if m:
        syms.setdefault(int(m.group(2), 16), (m.group(1)[1:] if m.group(1).startswith('_') else m.group(1), m.group(3)))
sym_addrs = sorted(syms)

units = []                                  # (start, end, unit) from the link map
lines = open(TREE / 'sf3.map', encoding='latin-1').read().splitlines()
for i, l in enumerate(lines[1:], 1):        # a unit's line follows its range (on the section line for the first)
    m = re.match(r"\s{10,}(\w+)\s+(\w+)\s*$", l)
    r = re.search(r"H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})", lines[i - 1])
    if m and r:
        units.append((int(r.group(1), 16), int(r.group(2), 16) + 1, m.group(1)))
units.sort()


def unit_of(addr):
    i = bisect.bisect_right(units, (addr, 1 << 40, '')) - 1
    return units[i][2] if i >= 0 and units[i][0] <= addr < units[i][1] else None


_src = {}


def src_lines(rel):
    if rel not in _src:
        p = TREE / rel
        _src[rel] = p.read_text(encoding='latin-1').splitlines() if p.is_file() else None
    return _src[rel]


def find_def(name, module, func):
    """'<dir>/<file>:<line>' of the definition of name in the module's file under src/ or data/, or the file alone
    when no line is found; module: a file name (ms34) or a link unit"""
    if not module:
        return ''
    names = [module] if '.' in module else [f'{module}.c', f'{module}.src']
    first = ''
    for rel in [f'{d}/{x}' for d in ('src', 'data') for x in names]:
        ls = src_lines(rel)
        if ls is None:
            continue
        first = first or rel
        if rel.endswith('.src'):
            pat = re.compile(rf'^_?{re.escape(name)}:')
        elif func:
            pat = re.compile(rf'^(?![\s#/*{{}}]).*\b{re.escape(name)}\s*\((?!.*;\s*$)')
        else:
            pat = re.compile(rf'^(?![\s#/*{{}}])(?!extern\b)(?!.*\(\s*\*?\s*\w*\s*\)\s*\().*\b{re.escape(name)}\b\s*(\[|=|;|,)')
        for n, l in enumerate(ls, 1):
            if pat.search(l):
                return f'{rel}:{n}'
    return first


# ---- matches: placement

rows = [l.rstrip('\n').split('\t') for l in open(MATCHES, encoding='utf-8')]
M = [dict(zip(rows[0], r)) for r in rows[1:]]
module_of = {m['name']: m['module'] for m in M}
for m in M:                                 # a routine's label is code even when the map types it DAT (asm)
    syms[int(m['addr3'], 16)] = (m['name'], 'ENT')
sym_addrs = sorted(syms)
M = [m for m in M if m['result'] in ('exact', 'reloc')]
M.sort(key=lambda m: int(m['addr3'], 16))
for m in M:
    m['hits'] = [(int(x.split(':')[0], 16), x.split(':')[1]) for x in m['alts'].split(',')]
placed = {i: m['hits'][0][0] for i, m in enumerate(M) if len(m['hits']) == 1}   # index -> 2i address
firm = set(placed)                          # placed by their only hit
index_of = {int(m['addr3'], 16): i for i, m in enumerate(M)}
report = collections.Counter()


def place(i, a, why):
    placed[i] = a
    report[why] += 1


# by module: the hit whose delta some placed routine of the same 3s module has (repeated until nothing moves);
# the per-character modules repeat routines byte for byte, so a lone neighbour is not enough
changed = True
while changed:
    changed = False
    taken = set(placed.values())
    deltas = collections.defaultdict(set)
    for i, a in placed.items():
        deltas[M[i]['module']].add(a - int(M[i]['addr3'], 16))
    for i, m in enumerate(M):
        if i in placed:
            continue
        a3m = int(m['addr3'], 16)
        pick = [h for h, _ in m['hits'] if h not in taken and h - a3m in deltas[m['module']]]
        if len(pick) == 1:
            place(i, pick[0], 'placed by module')
            taken.add(pick[0])
            changed = True
# by module neighbours: the only hit between the nearest placed routines of the same module before and after it,
# or within 4K of where the one on one side puts it (repeated until nothing moves)
changed = True
while changed:
    changed = False
    taken = set(placed.values())
    bymod = collections.defaultdict(list)
    for i in sorted(placed):
        bymod[M[i]['module']].append(i)
    for i, m in enumerate(M):
        if i in placed:
            continue
        same = bymod[m['module']]
        if not same:
            continue
        k = bisect.bisect_left(same, i)
        prev = same[k - 1] if k > 0 else None
        nxt = same[k] if k < len(same) else None
        a3m = int(m['addr3'], 16)
        hits = [h for h, _ in m['hits'] if h not in taken]
        if prev is not None and nxt is not None:
            pick = [h for h in hits if placed[prev] < h < placed[nxt]]
        else:
            n = prev if prev is not None else nxt
            pred = a3m + placed[n] - int(M[n]['addr3'], 16)
            pick = [h for h in hits if abs(h - pred) < 0x1000]
        if len(pick) == 1:
            place(i, pick[0], 'placed by module neighbours')
            taken.add(pick[0])
            bisect.insort(same, i)
            changed = True
# copies: 3s routines with the same set of hits (the same bytes in several modules, as Yun's and Yang's) and as
# many routines as hits are placed in address order, 3s to 2i; the note says so
copies = {}                                 # index -> (the group's indexes, its hits); placed by address order
groups = collections.defaultdict(list)
for i, m in enumerate(M):
    if i not in placed:
        groups[tuple(h for h, _ in m['hits'])].append(i)
taken = set(placed.values())
for hits, idxs in groups.items():
    if len(idxs) == len(hits) > 1 and not taken & set(hits):
        idxs = sorted(idxs, key=lambda i: int(M[i]['addr3'], 16))
        for i, h in zip(idxs, sorted(hits)):
            place(i, h, 'placed as one of identical copies')
            copies[i] = (idxs, sorted(hits))
        taken |= set(hits)
# by neighbours: the hit whose delta the nearest placed routine before or after has, else the only hit between them
order = sorted(placed)
taken = set(placed.values())
for i, m in enumerate(M):
    if i in placed:
        continue
    k = bisect.bisect_left(order, i)
    prev = order[k - 1] if k > 0 else None
    nxt = order[k] if k < len(order) else None
    a3m = int(m['addr3'], 16)
    want = {placed[n] - int(M[n]['addr3'], 16) for n in (prev, nxt) if n is not None}
    hits = [h for h, _ in m['hits'] if h not in taken]
    pick = [h for h in hits if h - a3m in want]
    if len(pick) != 1:
        lo = placed[prev] if prev is not None else 0
        hi = placed[nxt] if nxt is not None else 1 << 40
        pick = [h for h in hits if lo < h < hi]
    if len(pick) == 1:
        place(i, pick[0], 'placed by neighbours')
        taken.add(pick[0])
    else:
        report['ambiguous, left out'] += 1
# a routine placed 32K or more away (in delta) from every other placed routine of its module, when there are at
# least four others, is another module's copy of the same bytes: left out
bymod = collections.defaultdict(list)
for i, a in placed.items():
    bymod[M[i]['module']].append(a - int(M[i]['addr3'], 16))
for i in list(placed):
    d = placed[i] - int(M[i]['addr3'], 16)
    others = list(bymod[M[i]['module']])
    others.remove(d)
    if len(others) >= 4 and min(abs(d - o) for o in others) >= 0x8000:
        del placed[i]
        report['outside its module, left out'] += 1
claims = collections.Counter(placed.values())
for i in [i for i, a in placed.items() if claims[a] > 1]:
    del placed[i]
    report['two routines at one address, left out'] += 1


def compare(s, st):
    """-> (result, pool word offsets, relocation pairs): s 3s bytes, st 2i offset (the matcher's comparison)"""
    n = len(s)
    datah, bad = [], []
    for i in range(0, n, 2):
        x = s[i:i + 2]
        if x == op[st + i:st + i + 2]:
            continue
        if x == dv[st + i:st + i + 2]:
            datah.append(i)
        else:
            bad.append(i)
    rel, done = [], set()
    for i in bad:
        j = i - ((st + i) & 2)
        if j in done:
            continue
        if j < 0 or j + 4 > n:
            return None
        w3, w2 = word(s, j), word(dv, st + j)
        if not (isaddr(w3) and isaddr(w2)):
            return None
        done.add(j)
        rel.append((j, w3, w2))
    pool = {j for j, _, _ in rel} | {i for i in datah if (st + i) % 4 == 0 and i + 2 in datah}
    return ('reloc' if rel else 'exact'), sorted(pool), rel


def vote(pairs, w3, w2, how):
    """a 3s address w3 seen as the 2i address w2: a vote for the 3s symbol containing w3"""
    if not (isaddr(w3) and isaddr(w2)) or (w3 >> 24) != (w2 >> 24):
        return
    k = bisect.bisect_right(sym_addrs, w3) - 1
    if k < 0:
        return
    base3 = sym_addrs[k]
    if syms[base3][1] == 'ENT' and (w3 != base3 or w2 & 1):
        return                              # a function is named only from a pointer to its entry
    pairs[base3][w2 - (w3 - base3)][how] += 1


pins = []                                   # (3s routine, 2i address) from si2map's table pins
if PINS:
    addr_of = {n: b for b, (n, t) in syms.items() if t == 'ENT'}
    for l in open(PINS, encoding='utf-8').read().splitlines()[1:]:
        n, a = l.split('\t')[:2]
        if n in addr_of:
            pins.append((addr_of[n], int(a, 16)))


def routine_rows():
    """placed routines -> (rows by 2i address, votes from their literal pools)"""
    rows, pairs = {}, collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    for i, a2 in sorted(placed.items(), key=lambda t: t[1]):
        m = M[i]
        ad3, sz = int(m['addr3'], 16), int(m['size'])
        s = a3[ad3 - BASE:ad3 - BASE + sz]
        c = compare(s, a2 - BASE)
        if c is None:
            report['placed hit failed to compare'] += 1
            continue
        res, pool, rel = c
        note = f'size {sz}' if res == 'exact' else f'reloc {len(rel)}, size {sz}'
        src = find_def(m['name'], m['module'], True) if m['kind'] != 'lib' else ''
        if m['kind'] == 'lib':
            note += '; SHC runtime library routine'
        if i in role_how:
            note += f'; placed by the pointers to it ({how_text(role_how[i])})'
        elif i in copies:
            note += '; the same bytes as ' + ', '.join(M[j]['name'] for j in copies[i][0] if j != i) + \
                    ': placed among the copies by address order'
        rows[a2] = [f'{a2:08X}', m['name'], '', '3s-' + res, m['addr3'], m['name'], src, note]
        for j in pool:
            vote(pairs, word(s, j), word(dv, a2 - BASE + j), 'pool')
    for base3, a2 in pins:
        pairs[base3][a2]['pin'] += 1
    return rows, pairs


def rom_object(base3, a2):
    """a 3s ROM data symbol at the 2i address a2 -> (class, note, size)"""
    k = bisect.bisect_right(sym_addrs, base3)
    size = min((sym_addrs[k] if k < len(sym_addrs) else base3 + 4) - base3, 0x10000)
    s3 = a3[base3 - BASE:base3 - BASE + size]
    o2 = a2 - BASE                          # each halfword from the view that matches it (code labels typed DAT)
    s2 = b''.join(op[o2 + i:o2 + i + 2] if s3[i:i + 2] == op[o2 + i:o2 + i + 2] else dv[o2 + i:o2 + i + 2]
                  for i in range(0, size, 2))
    words = [(word(s3, o), word(s2, o)) for o in range(0, size - 3, 4)]
    diff = [(x, y) for x, y in words if x != y]
    if s3 == s2:
        return '3s-exact', f'rom size {size}', size
    if all(isaddr(x) and isaddr(y) for x, y in diff) and s3[len(words) * 4:] == s2[len(words) * 4:]:
        return '3s-reloc', f'reloc {len(diff)}, rom size {size}', size
    if len(words) and 2 * len(diff) <= len(words):
        sim = 100 * (len(words) - len(diff)) // len(words)
        return '3s-near', f'sim {sim}% of {len(words)} words equal, rom size {size}; contents changed', size
    # under half the words equal: the name rests on the references alone
    return 'inferred', (f'the 2i words that match the references to sf3 {base3:08X} point here; contents differ '
                        f'({len(words) - len(diff)} of {len(words)} words equal, rom size {size})'), size


def tally(pairs):
    out = {}
    for base3, by in pairs.items():
        votes = collections.Counter({a: sum(h.values()) for a, h in by.items()})
        total = sum(votes.values())
        a2, n = votes.most_common(1)[0]
        if 3 * n >= 2 * total:
            out[base3] = (a2, total, total - n, by[a2])
    return out


table_stats = {}                            # (3s table, 2i address) -> (class, checked words, agreeing words)


def resolve(pairs):
    """votes -> {3s symbol address: (2i address, total, conflicts, how)}, the ROM tables' elements voting too: a
    table found by a vote pairs its words with the 3s table's, word for word, when it is aligned: 3s-exact or
    3s-reloc, or its words that point at symbols already placed (firm routines, or symbols placed by literal pools) agree
    with those placements, at least two and nine in ten of them. Repeated until no new table."""
    known = {int(M[i]['addr3'], 16): a2 for i, a2 in placed.items() if i in firm}
    for b, r in tally(pairs).items():
        known.setdefault(b, r[0])
    tables = set()
    while True:
        out = tally(pairs)
        new = [(b, out[b][0]) for b in out if (b >> 24) == 0x06 and syms[b][1] == 'DAT' and (b, out[b][0]) not in tables]
        if not new:
            return out
        for base3, a2 in new:
            tables.add((base3, a2))
            cls, _, size = rom_object(base3, a2)
            words = [(word(a3, base3 - BASE + o), word(dv, a2 - BASE + o)) for o in range(0, size - 3, 4)]
            checks = agree = 0
            state = []                      # per word: True agrees, False disagrees, None not checkable
            for w3, w2 in words:
                k = bisect.bisect_right(sym_addrs, w3) - 1
                if isaddr(w3) and k >= 0 and sym_addrs[k] in known:
                    checks += 1
                    ok = known[sym_addrs[k]] + w3 - sym_addrs[k] == w2
                    agree += ok
                    state.append(ok)
                else:
                    state.append(None)
            table_stats[base3, a2] = (cls, checks, agree)
            if cls not in ('3s-exact', '3s-reloc') and (checks < 2 or 10 * agree < 9 * checks):
                report['table not aligned, its words do not vote'] += 1
                continue
            # a 3s symbol's extent can hold several static tables whose 2i lengths differ: a word votes only when
            # the nearest checked words on both sides of it (or itself) agree, so votes stop at a table edge
            before, last = [], None
            for s_ in state:
                last = s_ if s_ is not None else last
                before.append(last)
            after, last = [], None
            for s_ in reversed(state):
                last = s_ if s_ is not None else last
                after.append(last)
            after.reverse()
            for (w3, w2), s_, b_, a_ in zip(words, state, before, after):
                if s_ is True or (s_ is None and b_ is True and a_ is True) or cls in ('3s-exact', '3s-reloc'):
                    vote(pairs, w3, w2, 'table')
                else:
                    report['table word past an edge, no vote'] += 1


def how_text(how):
    words = {'pool': 'literal-pool slot', 'table': 'table word', 'pin': 'si2map table pin'}
    return ' and '.join(f'{n} {words[h]}{"s" if n > 1 else ""}' for h, n in sorted(how.items()))


# roles: where pointers (literal pools, aligned tables) put a 3s routine, it goes, over placements by bytes alone
# that are not firm (a routine with one hit is firm; one placed by module, copies or neighbours is not). Its own
# placement elsewhere and another routine's placement there are dropped; when the address is not one of its hits
# it gets a row by role below. Redone until nothing moves, since moved routines bring other literal pools.
role_how = {}
for _ in range(4):
    func_rows, pairs = routine_rows()
    res = resolve(pairs)
    at = {a: i for i, a in placed.items()}
    moved = False
    for base3, (a2, total, conflicts, how) in res.items():
        i = index_of.get(base3)
        if syms[base3][1] != 'ENT' or (i is not None and i in firm and i in placed):
            continue
        j = at.get(a2)
        if j is not None and (j in firm or j == i):
            if j == i:
                role_how[i] = how
            continue
        if j is not None:                   # another routine's copy of the bytes, placed by bytes alone
            del placed[j]
            del at[a2]
            moved = True
        if i is not None and i in placed:
            del at[placed[i]]
            del placed[i]
            moved = True
        if i is not None and a2 in {h for h, _ in M[i]['hits']}:
            placed[i] = a2
            at[a2] = i
            role_how[i] = how
            moved = True
    if not moved:
        break
    report['placements moved by pointers'] += 1
func_rows, pairs = routine_rows()
res = resolve(pairs)

# ---- globals and pointer-only functions

glob_rows = {}
extents = sorted((a, int(re.search(r'size (\d+)', r[7]).group(1))) for a, r in func_rows.items())
ext_starts = [a for a, _ in extents]


def inside(a2):
    """a2 lies within a placed routine (its entry included)"""
    k = bisect.bisect_right(ext_starts, a2) - 1
    return k >= 0 and a2 < extents[k][0] + extents[k][1]


placed_names = {r[1]: a for a, r in func_rows.items()}
report['global with conflicting references, left out'] = len(pairs) - len(res)
for base3, (a2, total, conflicts, how) in sorted(res.items()):
    name, typ = syms[base3]
    refs = f'refs {total} conflicts {conflicts}'
    if typ == 'ENT':
        if name in placed_names:
            if placed_names[name] != a2:
                report['pointer disagrees with a placed routine'] += 1
            continue
        if inside(a2):
            report['pointer target inside a placed routine, left out'] += 1
            continue
        mod = module_of.get(name)
        func_rows[a2] = [f'{a2:08X}', name, '', 'inferred', f'{base3:08X}', name,
                         find_def(name, mod, True) if mod else '',
                         f'pointed to as sf3 {name} by {how_text(how)} of matched routines and tables: {refs}']
        report['function from pointers (inferred)'] += 1
        continue
    unit = unit_of(base3)
    src = find_def(name, unit, False) if unit else ''
    if (base3 >> 24) == 0x02:
        cls = '3s-exact' if a2 == base3 else '3s-reloc'
        note = f'ram {refs} ({how_text(how)})'
    else:
        cls, note, _ = rom_object(base3, a2)
        note += f'; {refs} ({how_text(how)})'
    if inside(a2):
        report['global inside a placed routine, left out'] += 1
        continue
    glob_rows[a2] = [f'{a2:08X}', name, '', cls, f'{base3:08X}', name, src, note]

# a function named by pointers (its role: say the character-4 entry of a per-character table) at a hit of 3s
# routines not placed there (copies of the same bytes): the named routine itself when it is one of them, else the
# only one; the class and the 3s reference follow the bytes, the name the role
by_hit = collections.defaultdict(list)
for i, m in enumerate(M):
    for h, _ in m['hits']:
        if placed.get(i) != h:
            by_hit[h].append(i)
for a2, r in func_rows.items():
    cand = by_hit.get(a2, [])
    own = [i for i in cand if M[i]['name'] == r[1]]
    if r[3] != 'inferred' or not (own or len(cand) == 1):
        continue
    m = M[(own or cand)[0]]
    others = [M[i]['name'] for i in cand if M[i] is not m]
    ad3, sz = int(m['addr3'], 16), int(m['size'])
    c = compare(a3[ad3 - BASE:ad3 - BASE + sz], a2 - BASE)
    if c is None:
        continue
    res, _, rel = c
    r[3:8] = ['3s-' + res, m['addr3'], m['name'], find_def(m['name'], m['module'], True),
              (f'size {sz}' if res == 'exact' else f'reloc {len(rel)}, size {sz}') +
              (f'; the same bytes as {", ".join(others)}; placed by the pointers to it: ' if m['name'] == r[1] else
               f'; the bytes are sf3 {m["name"]}, the name is its role here: ') + r[7]]
    report['copy placed by pointers' if m['name'] == r[1] else 'function named by role, bytes another 3s routine'] += 1

# si2map's census: near matches, and the exact/reloc placements of routines with one 2i copy, where nothing here
# has a row
def census_note(c):
    if c['class'] in ('near', 'near-moved'):
        return (f'sim {round(100 * float(c["sim"]))}%: {c["diffs"] or 0} instructions differ, 2i size '
                f'{c["size2"]} vs 3s {c["size3"]} (si2map census)')
    if c['class'] == 'exact':
        return f'size {c["size3"]} (si2map census)'
    return f'reloc {c["relocs"] or 0}, size {c["size3"]} (si2map census: addresses, displacements or pool offsets differ)'


if CENSUS:
    rows = [l.rstrip('\n').split('\t') for l in open(CENSUS, encoding='utf-8')]
    # a routine named here by pointers alone that the census places at the same address by its instructions: the
    # two agree, and the class follows the census comparison
    by_name = {c['name']: c for c in (dict(zip(rows[0], r)) for r in rows[1:])}
    # a routine named here by pointers alone, at an address where the census finds another 3s routine's bytes
    # (exact or reloc): the bytes win, since a table word past the edge of a shorter 2i table names the wrong slot
    by_addr2 = {c['addr2']: c for c in by_name.values() if c['addr2'] and c['class'] in ('exact', 'reloc')}
    names_now = {r[1] for r in func_rows.values()}
    for a2, r in list(func_rows.items()):
        c = by_addr2.get(r[0])
        if r[3] != 'inferred' or not c or c['name'] == r[1] or c['name'] in names_now:
            continue
        func_rows[a2] = [r[0], c['name'], '', '3s-' + c['class'], c['addr3'], c['name'],
                         find_def(c['name'], c['module'], True) if c['kind'] != 'lib' else '',
                         census_note(c) + f'; replaces sf3 {r[1]}, which only pointers put here ({r[7]})']
        names_now.add(c['name'])
        report['pointer-only name replaced by census bytes'] += 1
    for a2, r in func_rows.items():
        c = by_name.get(r[1])
        if r[3] != 'inferred' or not c or c['addr2'] != r[0] or r[5] != r[1]:
            continue
        if c['class'] in ('exact', 'reloc', 'near', 'near-moved'):
            r[3] = '3s-near' if c['class'].startswith('near') else '3s-' + c['class']
            r[7] = census_note(c) + '; ' + r[7]
            report['pointer-named routine confirmed by the census'] += 1
        elif c['class'] == 'changed':
            r[7] += f'; si2map census: the routine matched callers call in its place (sim {round(100 * float(c["sim"]))}%)'
    names_here = {r[1] for r in func_rows.values()}
    for c in (dict(zip(rows[0], r)) for r in rows[1:]):
        pinned = c.get('via') == 'pin'
        if not pinned and c['class'] not in ('near', 'exact', 'reloc') or \
                pinned and c['class'] not in ('near', 'near-moved', 'exact', 'reloc', 'changed') or \
                not c['addr2'] or c['name'] in names_here:
            continue
        if c['dup'] != '1' and not pinned:  # a routine with several 2i copies: its placement is not settled
            report[f'census {c["class"]}: several copies, left out'] += 1
            continue
        a2 = int(c['addr2'], 16)
        if a2 in func_rows or inside(a2):
            report[f'census {c["class"]}: address already named here'] += 1
            continue
        if c['class'] == 'changed':         # a table slot whose 2i routine is rewritten: named by its role
            cls = 'inferred'
            note = (f'si2map census: the {c["name"]} slot of a routine-pointer table matched with the 3s one '
                    f'(pinned); the routine is rewritten (sim {round(100 * float(c["sim"]))}%)')
        else:
            cls = '3s-near' if c['class'].startswith('near') else '3s-' + c['class']
            note = census_note(c) + ('; placed by si2map table pins' if pinned else '')
        func_rows[a2] = [f'{a2:08X}', c['name'], '', cls, c['addr3'], c['name'],
                         find_def(c['name'], c['module'], True) if c['kind'] != 'lib' else '', note]
        names_here.add(c['name'])
        report[f'census {c["class"]} added'] += 1

if WHY:                                     # --why <3s symbol>: its votes and, for a table, its alignment check
    for b, (n, t) in syms.items():
        if n == WHY:
            print(f'{WHY} 3s {b:08X} {t}: votes', {f'{a:08X}': dict(h) for a, h in pairs.get(b, {}).items()},
                  'tables', {f'{a:08X}': v for (bb, a), v in table_stats.items() if bb == b})
# ---- merge into the tables (add only)

HEAD = {'functions.tsv': '# address\tname\tsignature\tclass\tsf3_addr\tsf3_name\tsf3_src\tnote   (docs/PROVENANCE.md)\n',
        'globals.tsv': '# address\tname\ttype\tclass\tsf3_addr\tsf3_name\tsf3_src\tnote   (docs/PROVENANCE.md)\n'}
names_all = {}
tables = {}
for t in HEAD:
    p = NAMES / t
    text = p.read_text(encoding='utf-8') if p.is_file() else HEAD[t]
    have = {}
    for l in text.splitlines():
        if l.strip() and not l.startswith('#'):
            r = l.split('\t')
            have[int(r[0], 16)] = r
            names_all[r[1]] = int(r[0], 16)
    tables[t] = (p, text, have)
for t, new in (('functions.tsv', func_rows), ('globals.tsv', glob_rows)):
    p, text, have = tables[t]
    add = []
    for a2, r in sorted(new.items()):
        if a2 in have:
            if have[a2][1] != r[1]:
                report[f'{t}: address already named differently'] += 1
            continue
        if r[1] in names_all:
            if names_all[r[1]] != a2:
                report[f'{t}: name already used at another address'] += 1
            continue
        names_all[r[1]] = a2
        add.append('\t'.join(r))
    rows_all = sorted([l for l in text.splitlines() if l.strip() and not l.startswith('#')] + add,
                      key=lambda l: int(l.split('\t')[0], 16))
    head = [l for l in text.splitlines() if l.startswith('#')] or [HEAD[t].rstrip('\n')]
    if not DRY:
        NAMES.mkdir(parents=True, exist_ok=True)
        p.write_text('\n'.join(head + rows_all) + '\n', encoding='utf-8', newline='\n')
    report[f'{t}: rows added'] = len(add)
    cls = collections.Counter(l.split('\t')[3] for l in rows_all)
    print(f'{t}: {len(rows_all)} rows ({len(add)} added): ' + ', '.join(f'{k} {v}' for k, v in sorted(cls.items())))
for k, v in sorted(report.items()):
    print(f'  {k}: {v}')
