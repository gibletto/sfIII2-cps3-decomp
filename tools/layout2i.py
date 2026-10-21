#!/usr/bin/env python3
"""Write the 2nd Impact tree's link layout: sf2i/layout.tsv (every piece of every section, at its 2i address) and
sf2i/sf2i.sub (the lnk subcommands: section starts and the objects in link order).

    python tools/layout2i.py [--tree sf2i] [--map scratch/si2map] [--rom scratch/rom] [--sf3 <3s sf3 tree>]
                             [--report FILE]

Sections (2i addresses; D is given at its RAM address, its ROM copy is at 06577330):
  CVECT 06000000-06000200, P 06000400-060FC564, CTBL 060FC564-06577330, D 02000000-0200873C,
  B 0200873C-0207410A, CCDVOL 067FFFE0-06800000, CCG 06800000-06DA767C, CCDVOL2 06FFFFE0-07000000.

P is cut into modules by si2map's census: every 2i function (funcs.tsv) takes the 3s object (sf3.map unit) of the
3s routine the census places on it. 2i code the census does not place takes its module when the same module is on
both sides, and is a piece of its own (new_<address>) between two modules. A module whose routines are split by
another module's is one piece per run: the run with most routines has the module's name, the others <name>_x<k>;
a short run (two routines at most) of a module whose main run is elsewhere goes to the module around it (the
census places identical copies, the per-character AI stubs, by guesswork). A piece ends where the next begins.
sf2i/objects.tsv places objects by hand (name, start, end, evidence) where the census cut is wrong: the census
pieces inside one are dropped, those overlapping it cut back, and its functions' census addresses are not used.

A piece is C (src/<name>.c), asm (src/<name>.src), lib (lib/<name>.src) when the tree has that source, else a
blob (tools/build2i.py writes it from the ROM). The other sections of a C, asm or lib object are placed from 2i's
own bytes: the object is linked alone twice with them at two sets of placeholder addresses, and every word of its
P (and of its sections placed so far) that moves between the links refers to one of its sections, so the 2i word
there gives that section's address. A section nothing refers to is placed by its exported symbols' addresses in
the naming tables. The rest of each data section is blob pieces (<section>_<address>) between them.
"""
import argparse, csv, os, re, shutil, subprocess, sys
from collections import Counter, defaultdict
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import build2i, lnkmap, shclist

ROOT = build2i.ROOT
SECTIONS = [('CVECT', 0x06000000, 0x06000200), ('P', 0x06000400, 0x060FC564), ('CTBL', 0x060FC564, 0x06577330),
            ('D', 0x02000000, 0x0200873C), ('B', 0x0200873C, 0x0207410A), ('CCDVOL', 0x067FFFE0, 0x06800000),
            ('CCG', 0x06800000, 0x06DA767C), ('CCDVOL2', 0x06FFFFE0, 0x07000000)]
BOUNDS = {s: (lo, hi) for s, lo, hi in SECTIONS}
START = 'START CVECT(06000000),P(06000400),CTBL,D(060FC564),R,B(02000000),CCDVOL(067FFFE0),CCG(06800000),' \
        'CCDVOL2(06FFFFE0)'
IMG = 0x06000000


def partition(mapdir, sf3, tree=None):
    """P pieces: [(name, start, [(addr, unit or None, census name)])]"""
    units3 = [(a, b, u) for s, u, a, b in lnkmap.pieces((sf3 / 'sf3.map').read_text(errors='replace'))
              if s == 'P' and b > a]

    def unit3(a3):
        return next((u for a, b, u in units3 if a <= a3 < b), None)
    at = {}
    for r in csv.DictReader(open(mapdir / 'census.tsv'), delimiter='\t'):
        if r['addr2']:
            at[int(r['addr2'], 16)] = (unit3(int(r['addr3'], 16)), r['name'])
    fn = {int(r['addr'], 16) for r in csv.DictReader(open(mapdir / 'funcs.tsv'), delimiter='\t')}
    # 2i code the census leaves inside one of its blocks (3s code moved by one delta) is the 3s unit's there
    blocks = [(int(r['addr2_from'], 16), int(r['addr3_to'], 16) - int(r['addr3_from'], 16), int(r['delta']))
              for r in csv.DictReader(open(mapdir / 'layout.tsv'), delimiter='\t')]
    for a in fn - set(at):
        for a2, n, d in blocks:
            if a2 < a <= a2 + n:
                u = unit3(a - d)
                if u:
                    at[a] = (u, None)
                break
    lo, hi = BOUNDS['P']
    seq = [(a, *at.get(a, (None, None))) for a in sorted(fn | set(at)) if lo <= a < hi]
    runs = []                                          # [unit, [(addr, unit, name)]]
    for f in seq:
        if runs and runs[-1][0] == f[1]:
            runs[-1][1].append(f)
        else:
            runs.append([f[1], [f]])

    def merge(rs):
        out = []
        for r in rs:
            if out and out[-1][0] == r[0]:
                out[-1][1] += r[1]
            else:
                out.append(r)
        return out
    # unplaced 2i code between two runs of one module is that module's
    for i in range(1, len(runs) - 1):
        if runs[i][0] is None and runs[i - 1][0] is not None and runs[i - 1][0] == runs[i + 1][0]:
            runs[i][0] = runs[i - 1][0]
    runs = merge(runs)
    # short stray runs of a module whose main run is elsewhere
    while True:
        big = {}
        for r in runs:
            if r[0] and len(r[1]) > big.get(r[0], 0):
                big[r[0]] = len(r[1])
        ch = False
        for i in range(1, len(runs)):
            u, fs = runs[i]
            if u and len(fs) <= 2 and big[u] > len(fs) and runs[i - 1][0] is not None:
                runs[i][0] = runs[i - 1][0]
                ch = True
        runs = merge(runs)
        if not ch:
            break
    # objects start on 4-byte boundaries (every section is ALIGN=4): a run that starts between two is in the
    # object before it
    k = 1
    while k < len(runs):
        if runs[k][1][0][0] % 4:
            runs[k - 1][1] += runs.pop(k)[1]
        else:
            k += 1
    runs = merge(runs)
    main = {}
    for k, (u, fs) in enumerate(runs):
        if u and (u not in main or len(fs) > len(runs[main[u]][1])):
            main[u] = k
    seen, out = Counter(), []
    for k, (u, fs) in enumerate(runs):
        if u is None:
            name = f'new_{fs[0][0]:08X}'
        elif main[u] == k:
            name = u
        else:
            seen[u] += 1
            name = f'{u}_x{seen[u] + 1}'
        out.append((name, fs[0][0], fs))
    return placed_by_hand(out, objects(tree))


def objects(tree=None):
    """sf2i/objects.tsv: P objects placed by hand, [(name, start, end)]"""
    f = Path(tree or ROOT / 'sf2i') / 'objects.tsv'
    if not f.exists():
        return []
    rows = [l.rstrip('\n').split('\t') for l in open(f) if l.strip() and not l.startswith('#')]
    return [(r[0], int(r[1], 16), int(r[2], 16)) for r in rows[1:]]


def placed_by_hand(parts, hand):
    """the census cut with the hand-placed objects put in: a census piece inside one is dropped, one that
    overlaps it is cut back; a census piece with a placed object's name elsewhere is called x_<address>"""
    if not hand:
        return parts
    names = {n for n, _, _ in hand}
    nxt = [p[1] for p in parts[1:]] + [BOUNDS['P'][1]]
    out = []
    for (name, a, fs), b in zip(parts, nxt):
        cut = False     # a piece a placed object cuts in two: the part after it is x_<address>
        for _, s, e in sorted(hand, key=lambda h: h[1]):
            if s <= a < e:
                a = e
            if a < s < b:
                out.append((name if name not in names and not cut else f'x_{a:08X}', a,
                            [f for f in fs if a <= f[0] < s]))
                a = e
                cut = True
        if a < b:
            out.append((name if name not in names and not cut else f'x_{a:08X}', a, [f for f in fs if a <= f[0] < b]))
    for name, s, e in hand:
        out.append((name, s, []))
    return sorted(out, key=lambda p: p[1])


def absorb(pieces, k, lo, hi):
    """give lo..hi of P to piece k: the census can give a module's routines to identical copies elsewhere, so a
    C module whose functions say it starts earlier or whose code runs on takes the blob pieces there (cut, or
    dropped when wholly inside). False, changing nothing, when a source piece lies in the way."""
    over = [i for i, p in enumerate(pieces) if i != k and p[0] == 'P' and p[1] < hi and lo < p[2]]
    if any(pieces[i][4] != 'blob' for i in over):
        return False
    for i in over:
        sec, a, e, n, kind = pieces[i]
        if a < lo and e > hi:
            pieces[i] = (sec, a, lo, n, kind)
            pieces.append((sec, hi, e, f'new_{hi:08X}', kind))
        elif a < lo:
            pieces[i] = (sec, a, lo, n, kind)
        elif e > hi:
            pieces[i] = (sec, hi, e, n, kind)
        else:
            pieces[i] = (sec, a, a, n, kind)            # wholly inside: dropped with the empty blobs below
    return True


def cbase(T, name, work, placed):
    """the 2i address of a C module's P by its functions' census addresses (most votes), or None"""
    lst = work / f'{name}.lst'
    ok, msg = build2i.compile_one(T, build2i.source(T, name, 'c'), work / f'{name}.obj',
                                  build2i.units(T).get(name, 'speed'), build2i.TMP / f'L{name}', listing=lst)
    if not ok or not lst.exists():
        return None
    votes = Counter(placed[f] - off for f, (off, *_) in shclist.parse(lst.read_text(errors='replace')).items()
                    if f in placed)
    return votes.most_common(1)[0][0] if votes else None


def solve(T, name, kind, base, img, byname, work):
    """place the object's sections from 2i's bytes. Returns ({section: (start, size)}, [problems])"""
    src = build2i.source(T, name, kind)
    obj = work / f'{name}.obj'
    ok, msg = build2i.compile_one(T, src, obj, build2i.units(T).get(name, 'speed'), build2i.TMP / f'L{name}')
    if not ok:
        return None, [f'compile failed: {msg.strip()[:300]}'], {}, {}
    wd = work / name
    if wd.exists():
        shutil.rmtree(wd)
    wd.mkdir(parents=True)
    shutil.copy(obj, wd / 'm.obj')

    undef = set()

    def run(start, rom, defines=()):
        sub = [rom, f'START {start}', 'INPUT m.obj', *defines, 'OUTPUT m.abs', 'PRINT m.map', 'FORM A', 'EXIT']
        (wd / 'm.sub').write_text('\n'.join(l for l in sub if l) + '\n')
        for f in ('m.abs', 'm.map'):
            (wd / f).unlink(missing_ok=True)
        p = subprocess.run([str(T / 'bin' / 'lnk.exe'), '-SUBCOMMAND=m.sub'], cwd=wd, capture_output=True, text=True,
                           env=build2i.env_for(T, build2i.TMP / f'L{name}'))
        undef.update(re.findall(r'UNDEFINED EXTERNAL SYMBOL\(\w+\.(\w+)\)', p.stdout + p.stderr))
        text = (wd / 'm.map').read_text(errors='replace') if (wd / 'm.map').exists() else ''
        return {s: (a, b) for s, u, a, b in lnkmap.pieces(text)}, lnkmap.symbols(text)

    def dump(lo, hi):
        (wd / 'm.bin').unlink(missing_ok=True)
        subprocess.run([str(T / 'bin' / 'rof2bin.exe'), f'-s={lo:08X}', f'-e={hi:08X}', '-v=FF', 'm.abs'], cwd=wd,
                       capture_output=True, env=build2i.env_for(T, build2i.TMP / f'L{name}'))
        return (wd / 'm.bin').read_bytes() if (wd / 'm.bin').exists() else b''
    secs, _ = run(f'P({base:08X})', '')
    others = [s for s in secs if s != 'P' and secs[s][1] > secs[s][0]]
    sizes = {s: secs[s][1] - secs[s][0] for s in secs}
    if 'D' in others:
        others.append('R')
    rom = 'ROM (D,R)' if 'D' in others else ''
    hold = [{s: 0x06A00000 + 0x80000 * k + d * 0x1000 * (k + 1) for k, s in enumerate(others)} for d in (0, 1)]
    links = []
    for h in hold:
        start = f'P({base:08X})' + ''.join(f',{s}({h[s]:08X})' for s in others)
        sx, sy = run(start, rom)
        images = {s: dump(sx[s][0], sx[s][1]) for s in ['P'] + others if s in sx and s != 'R' and sx[s][1] > sx[s][0]}
        links.append((sx, sy, images))
    probs, place, votes = [], {}, defaultdict(Counter)

    def scan(s, at2):
        x, y = links[0][2].get(s, b''), links[1][2].get(s, b'')
        if s != 'P' and s not in ('CTBL',):
            return                                     # D's words are compared by the build, B has none
        for o in range(0, min(len(x), len(y)) - 3, 2):
            v1, v2 = int.from_bytes(x[o:o + 4], 'big'), int.from_bytes(y[o:o + 4], 'big')
            if v1 == v2:
                continue
            k = next((t for t in others if v2 - v1 == hold[1][t] - hold[0][t]), None)
            if k is None:
                continue
            w = int.from_bytes(img[at2 + o - IMG:at2 + o - IMG + 4], 'big')
            votes[k][w - (v1 - hold[0][k])] += 1
    scan('P', base)
    for _ in range(3):
        for k, c in votes.items():
            if k not in place:
                v, n = c.most_common(1)[0]
                if len(c) > 1:
                    probs.append(f'{k}: {len(c)} candidate addresses ' + ', '.join(f'{a:08X}x{m}' for a, m in c.most_common(4)))
                place[k] = v
        if 'CTBL' in place and 'CTBL' in others and not getattr(scan, 'ctbl', False):
            scan.ctbl = True
            scan('CTBL', place['CTBL'])
    # sections nothing in the object refers to: by the naming tables' addresses of the symbols they define
    sy = links[0][1]
    for k in others:
        if k in place or k == 'D':
            continue
        lo = hold[0][k]
        for sym, a in sy.items():
            if lo <= a < lo + 0x80000 and sym[1:] in byname:
                place[k] = byname[sym[1:]] - (a - lo)
                break
        else:
            if k != 'R' or 'D' in others:
                probs.append(f'{k}: no address (nothing refers to it and no named symbol)')
    out = {'P': (base, sizes.get('P', 0))}
    for k in others:
        if k == 'D':
            continue
        sec = 'D' if k == 'R' else k
        if k in place:
            out[sec] = (place[k], sizes['D' if k == 'R' else k])
    # where the object's exported symbols land in 2i
    defs = {}
    for sym, v in sy.items():
        defs[sym] = v                                   # in P, or absolute (.EQU)
        for k in others:
            if k in place and hold[0][k] <= v < hold[0][k] + 0x80000:
                defs[sym] = place[k] + v - hold[0][k]
    # the symbols it refers to and does not define: link once more with each at a value of its own; a word that
    # moves by that value refers to it, and the 2i word there (less the addend) is its 2i address
    ext = defaultdict(Counter)
    names_u = sorted(undef)
    if names_u:
        fake = {n: 0x0E000000 + 0x10000 * i for i, n in enumerate(names_u)}
        start = f'P({base:08X})' + ''.join(f',{s}({hold[0][s]:08X})' for s in others)
        sx, _ = run(start, rom, [f'DEFINE {n}({v:08X})' for n, v in fake.items()])
        who = {v: n for n, v in fake.items()}
        for s in ['P', 'CTBL', 'D']:
            if s not in links[0][2] or (s == 'CTBL' and s not in place) or (s == 'D' and 'R' not in place):
                continue
            at2 = base if s == 'P' else place[s] if s == 'CTBL' else build2i.DROM + place['R'] - build2i.RAM
            x, y = links[0][2][s], dump(sx[s][0], sx[s][1])
            for o in range(0, min(len(x), len(y)) - 3, 2):
                w0, w3 = int.from_bytes(x[o:o + 4], 'big'), int.from_bytes(y[o:o + 4], 'big')
                n = who.get((w3 - w0) & 0xFFFFFFFF)
                if n:
                    ext[n][int.from_bytes(img[at2 + o - IMG:at2 + o - IMG + 4], 'big') - w0 & 0xFFFFFFFF] += 1
        for n in names_u:
            if n not in ext:
                probs.append(f'{n}: referred to, but no word of the object moves with it')
    return out, probs, defs, ext


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=str(ROOT / 'sf2i'))
    ap.add_argument('--map', default=str(ROOT / 'scratch' / 'si2map'))
    ap.add_argument('--rom', default=str(ROOT / 'scratch' / 'rom'))
    ap.add_argument('--sf3', default=os.environ.get('SF3_TREE', ''), help='a built 3rd Strike tree (default: $SF3_TREE)')
    ap.add_argument('--report')
    args = ap.parse_args()
    T, M, S3 = Path(args.tree).resolve(), Path(args.map), Path(args.sf3)
    img = (Path(args.rom) / 'prog.bin').read_bytes()
    parts = partition(M, S3, T)
    hand = {n for n, _, _ in objects(T)}
    byname, byaddr = {}, {}
    for addr, ls in build2i.names().items():
        byaddr[addr] = [n[1:] for n in ls]
        for n in ls:
            byname[n[1:]] = addr
    missing = Counter()
    work = T / 'build' / 'layout'
    work.mkdir(parents=True, exist_ok=True)
    pieces, problems, notes, alldefs = [], [], [], {}     # pieces: (section, start, end, name, kind)
    allext = defaultdict(lambda: defaultdict(list))     # symbol -> 2i address -> [(object, words)]
    rep = []
    plo, phi = BOUNDS['P']
    for i, (name, start, fs) in enumerate(parts):
        end = parts[i + 1][1] if i + 1 < len(parts) else phi
        kind = next((k for k in ('c', 'asm', 'lib') if build2i.source(T, name, k).exists()), 'blob')
        pieces.append(('P', start, end, name, kind))
        units = Counter(u for _, u, _ in fs)
        rep.append(f'{name}\t{start:08X}\t{end:08X}\t{kind}\t{len(fs)}\t'
                   + ','.join(f'{u or "-"}:{n}' for u, n in units.most_common()))
    pieces.insert(0, ('CVECT', 0x06000000, 0x06000200, 'vectors', 'blob'))
    # source objects the census has no code for (fixed_addr: symbols only) go first, with an empty P
    have = {p[3] for p in pieces}
    for kind, d, ext in (('c', 'src', '.c'), ('asm', 'src', '.src'), ('asm', 'data', '.src'), ('lib', 'lib', '.src')):
        for f in sorted((T / d).glob('*' + ext)):
            if f.stem not in have:
                pieces.insert(1, ('P', plo, plo, f.stem, kind))
                have.add(f.stem)
    # the other sections of the source objects
    placed = {}
    for r in csv.DictReader(open(M / 'census.tsv'), delimiter='\t'):
        if r['addr2']:
            placed[r['name']] = int(r['addr2'], 16)
    for sec, start, end, name, kind in list(pieces):
        if sec != 'P' or kind == 'blob':
            continue
        if kind == 'c' and name not in hand:
            # the module starts where its functions' census addresses less their offsets in it say: the census
            # can give the first 2i routine of a module to an identical copy elsewhere (a pointer's role)
            b = cbase(T, name, work, placed)
            if b is not None and b != start:
                k = pieces.index((sec, start, end, name, kind))
                if b < start and b % 4 == 0 and absorb(pieces, k, b, start):
                    pieces[k] = (sec, b, end, name, kind)
                    notes.append(f'{name}: starts at {b:08X}, the census layout at {start:08X}')
                    start = b
                else:
                    problems.append(f'{name}: its functions put it at {b:08X}, the census layout at {start:08X}')
        out, probs, defs, ext = solve(T, name, kind, start, img, byname, work)
        for sym, c in ext.items():
            for v, n in c.items():
                allext[sym][v].append((name, n))
        for sym, v in defs.items():
            alldefs[sym] = (v, name)
            if sym[1:] in byname and byname[sym[1:]] != v:
                notes.append(f'{name}: {sym[1:]} links at {v:08X}, the naming tables put it at {byname[sym[1:]]:08X}')
        if out is None:
            problems.append(f'{name}: ' + '; '.join(probs))
            continue
        problems += [f'{name}: {p}' for p in probs]
        ps = out['P'][1]
        cut = start + (ps + 3 & ~3)
        if start + ps > end:
            # 2i code the census places no 3s routine on (new_ pieces) right after the module can be its own:
            # the object takes it when it covers only such pieces
            nxt = sorted((p for p in pieces if p[0] == 'P' and end <= p[1] < start + ps), key=lambda p: p[1])
            if nxt and all(p[3].startswith('new_') and p[4] == 'blob' for p in nxt) and nxt[0][1] == end \
                    and all(a[2] == b[1] for a, b in zip(nxt, nxt[1:])) and nxt[-1][2] >= cut:
                for p in nxt:
                    pieces.remove(p)
                pieces[pieces.index((sec, start, end, name, kind))] = (sec, start, cut, name, kind)
                last = nxt[-1]
                if last[2] > cut:
                    pieces.append(('P', cut, last[2], f'new_{cut:08X}', 'blob'))
                notes.append(f'{name}: P ends at {start + ps:08X}, past the census piece; takes '
                             + ', '.join(p[3] for p in nxt))
                end = cut
        if start + ps > end:
            # otherwise blob pieces of any name in the way (absorb)
            k = pieces.index((sec, start, end, name, kind))
            if absorb(pieces, k, end, cut):
                pieces[k] = (sec, start, cut, name, kind)
                notes.append(f'{name}: P ends at {start + ps:08X}, past the census piece (ends {end:08X})')
            else:
                problems.append(f'{name}: P is {ps:#x} bytes, its 2i piece {end - start:#x}')
        elif cut < end:
            # the census put more 2i code in the piece than the object has: the rest is another object
            pieces[pieces.index((sec, start, end, name, kind))] = (sec, start, cut, name, kind)
            pieces.append(('P', cut, end, f'new_{cut:08X}', 'blob'))
            notes.append(f'{name}: P ends at {start + ps:08X}; {cut:08X}-{end:08X} is a piece of its own')
        for s, (lo, n) in out.items():
            if s != 'P' and n:
                pieces.append((s, lo, lo + n, name, kind))
        if ps == 0 and start == end and any(s != 'P' and n for s, (lo, n) in out.items()):
            pieces.remove((sec, start, end, name, kind))    # a table-only object (data/sections.src): no P
    # the data units (sf2i/data.tsv, tools/emit2i_data.py): CTBL only, at the addresses the data layout gives
    import emit2i_data
    for u, rs in emit2i_data.units_of(emit2i_data.load_layout()).items():
        pieces.append(('CTBL', rs[0]['addr'], rs[-1]['addr'] + rs[-1]['size'], u, 'data'))
    pieces = [p for p in pieces if p[4] != 'blob' or p[2] > p[1]]
    # data sections: blobs between the placed pieces
    for sec, lo, hi in SECTIONS:
        if sec in ('P', 'CVECT'):
            continue
        fixed = sorted(p for p in pieces if p[0] == sec)
        a = lo
        for p in fixed + [(sec, hi, hi, None, None)]:
            if p[1] < a:
                problems.append(f'{p[3]}: {sec} {p[1]:08X} overlaps the piece before (ends {a:08X})')
            elif p[1] > a:
                s = (a + 3) & ~3                   # every piece is ALIGN=4; lnk fills the bytes between
                if p[1] > s:
                    pieces.append((sec, s, p[1], f'{sec}_{s:08X}', 'blob'))
            a = max(a, p[2])
            if p[3] is not None and not (lo <= p[1] and p[2] <= hi):
                problems.append(f'{p[3]}: {sec} {p[1]:08X}-{p[2]:08X} outside the section')
    order = {s: k for k, (s, _, _) in enumerate(SECTIONS)}
    pieces.sort(key=lambda p: (order[p[0]], p[1], p[2]))
    with open(T / 'layout.tsv', 'w', newline='\n') as f:
        f.write('# written by tools/layout2i.py: every piece of the 2nd Impact image, at its 2i address (D: RAM)\n')
        f.write('name\tsection\tstart\tend\tkind\n')
        for sec, s, e, name, kind in pieces:
            f.write(f'{name}\t{sec}\t{s:08X}\t{e:08X}\t{kind}\n')
    # link order: each section's pieces in address order, merged; an object without P follows the one before it
    objs = list(dict.fromkeys(p[3] for p in pieces))
    after = defaultdict(set)
    chains = defaultdict(list)
    for p in pieces:
        chains[p[0]].append(p[3])
    for ch in chains.values():
        for x, y in zip(ch, ch[1:]):
            if x != y:
                after[y].add(x)
    key = {}
    for k, o in enumerate(objs):
        key[o] = k
    done, seq = set(), []
    while len(seq) < len(objs):
        ready = [o for o in objs if o not in done and after[o] <= done]
        if not ready:
            problems.append('link order: the sections disagree on the order of ' +
                            ', '.join(o for o in objs if o not in done)[:400])
            ready = [next(o for o in objs if o not in done)]
        o = min(ready, key=lambda o: key[o])
        done.add(o)
        seq.append(o)
    kindof = {p[3]: p[4] for p in pieces}
    with open(T / 'sf2i.sub', 'w', newline='\n') as f:
        f.write('ROM (D,R)\n' + START + '\n')
        for o in seq:
            f.write(f'INPUT {build2i.objpath(kindof[o])}\\{o}.obj\n')
        f.write('OUTPUT sf2i.abs\nPRINT sf2i.map\nFORM A\nEXIT\n')
    # the symbols the source objects define: build2i.py leaves them out of the blobs' labels
    with open(work / 'defs.tsv', 'w', newline='\n') as f:
        for sym, (v, o) in sorted(alldefs.items()):
            f.write(f'{sym}\t{v:08X}\t{o}\n')
    # the symbols they refer to: defined by another source object, by a blob label (the naming tables), or missing
    with open(work / 'externs.tsv', 'w', newline='\n') as f:
        f.write('symbol\taddress\tstatus\ttable_name\trefs\n')
        for sym in sorted(allext):
            vs = allext[sym]
            for v, refs in sorted(vs.items(), key=lambda kv: -sum(n for _, n in kv[1])):
                at = byaddr.get(v, [])
                if sym in alldefs:
                    st = 'source' if alldefs[sym][0] == v else f'source at {alldefs[sym][0]:08X}'
                elif sym[1:] in byname:
                    st = 'table' if byname[sym[1:]] == v else f'table at {byname[sym[1:]]:08X}'
                else:
                    st = 'renamed' if at else 'missing'
                f.write(f'{sym}\t{v:08X}\t{st}\t{",".join(at)}\t'
                        + ' '.join(f'{o}:{n}' for o, n in refs) + '\n')
                if st not in ('source', 'table'):
                    missing[st.split()[0]] += 1
    # committed copies (sf2i/layout/): a tree without the 3rd Strike oracle builds from them (tools/build_all.py)
    (T / 'layout').mkdir(exist_ok=True)
    for n in ('defs.tsv', 'externs.tsv'):
        shutil.copyfile(work / n, T / 'layout' / n)
    if args.report:
        Path(args.report).write_text('name\tstart\tend\tkind\tfunctions\tunits\n' + '\n'.join(rep) + '\n')
    kinds = Counter(p[4] for p in pieces)
    print(f'{len(pieces)} pieces ({", ".join(f"{k} {n}" for k, n in kinds.items())}), {len(seq)} objects; '
          f'{len(problems)} problems')
    for p in problems:
        print('  ' + p)
    for p in notes:
        print('  note: ' + p)
    if missing:
        print('  externals (build/layout/externs.tsv): ' + ', '.join(f'{k} {n}' for k, n in missing.items()))
    return 1 if problems else 0


if __name__ == '__main__':
    sys.exit(main())
