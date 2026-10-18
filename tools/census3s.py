#!/usr/bin/env python3
"""Census of the 3rd Strike routines in the 2nd Impact program.

    python tools/census3s.py <3s prog.bin> <3s routine tsv> <si2map dir> <out dir> [pins tsv ...]

<3s routine tsv> has name, arcade_address, arcade_size, module, kind (c/asm/lib) per routine; the routines tile the
3s code range. <si2map dir> is the output of tools/si2map.py image (prog.bin, hmap.bin, funcs.tsv). Each 3s routine
gets one class:
  exact   the same bytes, pools and padding included
  reloc   the same instructions; only addresses differ (pool words that are program or RAM addresses, branch and
          call displacements to places outside the routine) and pools may sit at another offset
  near    the same routine with code changes: best 2i function by instruction alignment, sim = matched share of
          instructions (difflib ratio over normalized instructions), at least NEAR_MIN, found between the 2i
          places of its exact/reloc neighbours; near-moved: found elsewhere, sim at least MOVED_MIN
  changed the 2i routine that matched callers call (via xref) or a pin names in its place, below NEAR_MIN
          similarity
  absent  nothing similar enough
Writes <out dir>/census.tsv (per 3s routine), new2i.tsv (2i functions no 3s routine maps to), layout.tsv (runs of
matched routines with one address delta) and prints a summary. Pins tsvs (name, addr2[, source]) place routines
first, overriding the search: placements known from elsewhere, such as dispatch tables (via = pin). A pin scoring
below NEAR_MIN at its address is placed only after the search, if the place is still free; pins that did not
take are listed in <out dir>/pins_unplaced.tsv.
"""
import sys, collections, difflib
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import sh2, si2map
from si2map import BASE, CODE, POOL, TABLE, DEAD, PAD

NEAR_MIN = 0.5        # similarity for a near match where the neighbours say it should be
MOVED_MIN = 0.8       # and anywhere else
LOCAL_MAX = 0x8000    # a neighbour window wider than this says nothing
ENC = (CODE, DEAD)


def isaddr(v):
    return v >> 24 in (0x02, 0x06)


class Side:
    """One program: image, halfword classes, code instruction positions."""

    def __init__(self, img, cls):
        self.img, self.cls = img, cls
        self.code = [BASE + 2 * h for h in range(len(cls)) if cls[h] in ENC]
        self.ci = {a: i for i, a in enumerate(self.code)}

    def w(self, a):
        o = a - BASE
        return self.img[o] << 8 | self.img[o + 1]

    def l(self, a):
        o = a - BASE
        return int.from_bytes(self.img[o:o + 4], 'big')

    def c(self, a):
        h = (a - BASE) // 2
        return self.cls[h] if 0 <= h < len(self.cls) else 0

    def insns(self, a, end):
        """Code instruction addresses in [a, end)."""
        import bisect
        i = bisect.bisect_left(self.code, a); j = bisect.bisect_left(self.code, end)
        return self.code[i:j]

    def tok(self, a, fine=True):
        """Normalized instruction at a: displacements masked; with fine, PC-relative loads carry the loaded
        value (addresses as 'A')."""
        w = self.w(a)
        k, t = sh2.flow(w, a)
        if k in ('bra', 'bsr'): return w & 0xF000
        if k in ('cbr', 'cbrs'): return w & 0xFF00
        p = sh2.pcrel(w, a)
        if p:
            if not fine or p[2] == 'a': return w & 0xFF00
            v = self.l(p[0]) if p[1] == 4 else self.w(p[0])
            return (w & 0xFF00, 'A' if p[1] == 4 and isaddr(v) else v)
        return w


def compare(S3, a, L, S2, b, entries):
    """3s routine [a, a+L) against 2i code from b. Returns (class, diffs, relocs, 2i extent end), or None when
    the 2i side runs into another function (an entry after b) before it has as many instructions."""
    import bisect
    i3 = S3.insns(a, a + L)
    if not i3: return None
    if S2.c(b) not in ENC: return None
    j = S2.ci[b]
    i2 = S2.code[j:j + len(i3)]
    if len(i2) < len(i3): return None
    k = bisect.bisect_right(entries, b)
    if k < len(entries) and entries[k] <= i2[-1]: return None
    # the 2i extent: through its last instruction, then the data and padding that follow it
    e2 = i2[-1] + 2
    while S2.c(e2) in (POOL, TABLE, PAD) or (S2.c(e2) == 0 and e2 - b < L): e2 += 2
    if e2 - b == L and S3.img[a - BASE:a - BASE + L] == S2.img[b - BASE:b - BASE + L]:
        return 'exact', 0, 0, b + L
    idx3 = {x: k for k, x in enumerate(i3)}; idx2 = {x: k for k, x in enumerate(i2)}
    diffs = relocs = 0
    for x, y in zip(i3, i2):
        u, v = S3.w(x), S2.w(y)
        k3, t3 = sh2.flow(u, x); k2, t2 = sh2.flow(v, y)
        if k3 in ('bra', 'bsr', 'cbr', 'cbrs'):
            if k2 != k3 or (u & 0xFF00 if k3 in ('cbr', 'cbrs') else u & 0xF000) != (v & 0xFF00 if k3 in ('cbr', 'cbrs') else v & 0xF000):
                diffs += 1; continue
            in3, in2 = t3 in idx3, t2 in idx2
            if in3 and in2 and idx3[t3] == idx2[t2]: continue
            if not in3 and not in2 and not (a <= t3 < a + L) and not (b <= t2 < e2):
                if t3 - x != t2 - y: relocs += 1
                continue
            diffs += 1; continue
        p3 = sh2.pcrel(u, x)
        if p3:
            p2 = sh2.pcrel(v, y)
            if not p2 or u & 0xFF00 != v & 0xFF00: diffs += 1; continue
            if p3[2] == 'a': continue
            v3 = S3.l(p3[0]) if p3[1] == 4 else S3.w(p3[0])
            v2 = S2.l(p2[0]) if p2[1] == 4 else S2.w(p2[0])
            if v3 == v2: continue
            if p3[1] == 4 and isaddr(v3) and isaddr(v2): relocs += 1; continue
            diffs += 1; continue
        if u != v: diffs += 1
    if diffs == 0 and abs(e2 - b - L) <= 2:
        for o in range(0, min(L, e2 - b), 2):                         # switch tables are part of the routine
            if S3.c(a + o) == TABLE and S3.w(a + o) != S2.w(b + o): diffs += 1
    return ('reloc' if diffs == 0 else 'same-shape'), diffs, relocs, e2


def main():
    if len(sys.argv) < 5: sys.exit(__doc__)
    p3, tsv, mapdir, out = sys.argv[1:5]
    pins = collections.defaultdict(set)                                 # name -> 2i addresses
    for pf in sys.argv[5:]:
        for l in open(pf, encoding='utf-8'):
            f = l.rstrip('\n').split('\t')
            if len(f) >= 2 and f[0] != 'name': pins[f[0]].add(int(f[1], 16))
    mapdir, out = Path(mapdir), Path(out); out.mkdir(parents=True, exist_ok=True)
    img3 = open(p3, 'rb').read()
    rows = [l.rstrip('\n').split('\t') for l in open(tsv, encoding='utf-8') if not l.startswith('#')]
    hdr = rows[0]; R = [dict(zip(hdr, r)) for r in rows[1:]]
    for r in R: r['a'] = int(r['arcade_address'], 16); r['L'] = int(r['arcade_size'])
    R.sort(key=lambda r: r['a'])

    # 3s classes: follow the 3s program from every routine entry (one image is both views there)
    P3 = si2map.Prog(img3, img3)
    P3.run([(r['a'], 'routine') for r in R], trial_kinds=())
    P3.learn(); P3.sweep()
    S3 = Side(img3, P3.cls)
    img2 = (mapdir / 'prog.bin').read_bytes(); cls2 = (mapdir / 'hmap.bin').read_bytes()
    S2 = Side(img2, cls2)
    fl = [l.rstrip('\n').split('\t') for l in open(mapdir / 'funcs.tsv') if not l.startswith('addr')]
    ent2 = sorted(int(a, 16) for a, how in fl)
    strong = sorted(int(a, 16) for a, how in fl if how in ('bsr', 'jsr', 'vector'))   # called: a real start (asm jmps to labels)

    # candidate index: 4 normalized instructions in a row (coarse tokens)
    K = 4
    t2 = [S2.tok(x, False) for x in S2.code]
    index = collections.defaultdict(list)
    for j in range(len(t2) - K):
        index[tuple(t2[j:j + K])].append(j)

    rank = {'exact': 0, 'reloc': 1, 'same-shape': 2}

    def try_at(r, cands):
        a, L = r['a'], r['L']
        found = []
        for b in cands:
            c = compare(S3, a, L, S2, b, strong)
            if c and (c[0] != 'same-shape' or c[1] <= max(2, r['n3'] // 10) and 1 - c[1] / r['n3'] >= NEAR_MIN):
                found.append((c, b))
        found.sort(key=lambda f: (rank[f[0][0]], f[0][1]))
        return found

    for r in R:
        a, L = r['a'], r['L']
        i3 = S3.insns(a, a + L)
        r['n3'] = len(i3)
        if len(i3) < K: continue
        t3 = [S3.tok(x, False) for x in i3]
        best = None
        for an in range(0, len(t3) - K + 1):
            js = index.get(tuple(t3[an:an + K]), [])
            if js and (best is None or len(js) < len(best[1])): best = (an, js)
            if best and len(best[1]) <= 8: break
        if not best: continue
        an, js = best
        r['found'] = try_at(r, {S2.code[j - an] for j in js[:400] if j - an >= 0})

    # pick among equally good candidates by the address delta of the nearest uniquely matched neighbours
    def uniq(r):
        f = r.get('found') or []
        return len(f) == 1 or (len(f) > 1 and (f[0][0][0], f[0][0][1]) != (f[1][0][0], f[1][0][1]))
    anchors = [(r['a'], r['found'][0][1] - r['a']) for r in R if r.get('found') and uniq(r)
               and r['found'][0][0][0] in ('exact', 'reloc')]
    import bisect
    aa = [x for x, _ in anchors]

    def predict(a):
        i = bisect.bisect_left(aa, a)
        ds = [anchors[k][1] for k in (i - 1, i) if 0 <= k < len(anchors)]
        return [a + d for d in ds]

    # routines too short for the index, or not found through it: look where the neighbours say they are
    for r in R:
        if r.get('found') or not r['n3']: continue
        c = set()
        for p in predict(r['a']):
            for b in range(p - 0x40, p + 0x42, 2):
                if S2.c(b) in ENC: c.add(b)
        r['found'] = try_at(r, c)

    # one 2i place per routine and one routine per 2i place. Candidates near where the neighbours predict go
    # first (best class, then nearest); then near matches inside the neighbours' window; only then exact/reloc
    # copies elsewhere (identical code in another module, often a changed routine's twin); then near-moved.
    by_a = {r['a']: r for r in R}
    taken = []                                                          # claimed 2i ranges

    def claim(r, b, e2, **kw):
        i = bisect.bisect_right(taken, (b, 1 << 40)) - 1
        if i >= 0 and taken[i][1] > b: return False
        if i + 1 < len(taken) and taken[i + 1][0] < e2: return False
        bisect.insort(taken, (b, e2)); r.update(b=b, e2=e2, **kw)
        return True

    allc = []
    for r in R:
        pr = predict(r['a'])
        for (cl, diffs, relocs, e2), b in r.get('found') or []:
            dist = min(abs(b - p) for p in pr) if pr else 0
            allc.append((dist > LOCAL_MAX // 2, rank[cl], diffs, dist, r['a'], cl, relocs, e2, b, len(r['found'])))
    allc.sort()

    def place(far_ok, same_only=False):
        for far, rk, diffs, dist, a, cl, relocs, e2, b, nf in allc:
            r = by_a[a]
            if 'b' in r or far and not far_ok or same_only and cl == 'same-shape': continue
            claim(r, b, e2, cls=cl if cl != 'same-shape' else 'near', diffs=diffs, relocs=relocs,
                  sim=1.0 if cl != 'same-shape' else round(1 - diffs / max(1, r['n3']), 3), dup=nf)

    N = 3

    def near_pass(local):
        """The rest against unclaimed 2i functions by instruction alignment."""
        tk = [b for b, _ in taken]
        free = []
        for k, e in enumerate(ent2):
            i = bisect.bisect_right(tk, e) - 1
            if i >= 0 and taken[i][0] <= e < taken[i][1]: continue
            nx = ent2[k + 1] if k + 1 < len(ent2) else S2.code[-1] + 2
            j = bisect.bisect_left(tk, e)
            if j < len(tk): nx = min(nx, tk[j])
            ins = S2.insns(e, nx)
            if ins: free.append((e, nx, ins))
        ftok = [[S2.tok(x) for x in ins] for _, _, ins in free]
        gidx = collections.defaultdict(set)
        for fi, tt in enumerate(ftok):
            for j in range(len(tt) - N + 1): gidx[tuple(tt[j:j + N])].add(fi)
        # the neighbours' window: between the 2i ends of the nearest exact/reloc routines before and after
        mt = [(r['a'], r['b'], r['e2']) for r in R if r.get('cls') in ('exact', 'reloc')]
        ma = [x[0] for x in mt]
        fstart = [e for e, _, _ in free]

        def window(a):
            i = bisect.bisect_left(ma, a)
            if i == 0 or i == len(mt): return None
            lo, hi = mt[i - 1][2], mt[i][1]
            return (lo, hi) if lo <= hi and hi - lo <= LOCAL_MAX else None

        props = []
        for r in R:
            if 'b' in r or not r['n3']: continue
            w = window(r['a'])
            if local and not w: continue
            tt = [S3.tok(x) for x in S3.insns(r['a'], r['a'] + r['L'])]
            votes = collections.Counter()
            for g in set(tuple(tt[j:j + N]) for j in range(len(tt) - N + 1)):
                s = gidx.get(g)
                if s and len(s) < 50:
                    for fi in s: votes[fi] += 1
            if local:
                loc = range(bisect.bisect_left(fstart, w[0]), bisect.bisect_left(fstart, w[1]))
                cand = set(loc) if len(loc) <= 12 else {fi for fi in loc if votes[fi]}
            else:
                cand = {fi for fi, _ in votes.most_common(4)}
            for fi in cand:
                sim = round(difflib.SequenceMatcher(None, tt, ftok[fi], autojunk=False).ratio(), 3)
                if sim >= (NEAR_MIN if local else MOVED_MIN): props.append((sim, r['name'], fi, r))
        props.sort(key=lambda p: -p[0])
        used = set()
        for sim, _, fi, r in props:
            if 'b' in r or fi in used: continue
            e, nx, ins = free[fi]
            if claim(r, e, nx, cls='near' if local else 'near-moved', sim=sim, diffs='', relocs='', dup=1):
                used.add(fi)

    def xref_pass():
        """A routine the matched code calls or points to sits where the 2i twin of that code calls or points:
        3s targets (bsr, pool words) of exact/reloc routines vote for 2i places."""
        votes = collections.defaultdict(collections.Counter)
        for r in R:
            if r.get('cls') not in ('exact', 'reloc'): continue
            i3 = S3.insns(r['a'], r['a'] + r['L']); j = S2.ci[r['b']]
            for x, y in zip(i3, S2.code[j:j + len(i3)]):
                u, v = S3.w(x), S2.w(y)
                k, t3 = sh2.flow(u, x)
                if k == 'bsr':
                    t2 = sh2.flow(v, y)[1]
                else:
                    p = sh2.pcrel(u, x); q = sh2.pcrel(v, y)
                    if not p or not q or p[1] != 4 or q[1] != 4: continue
                    t3, t2 = S3.l(p[0]), S2.l(q[0])
                if t3 in by_a and t3 != r['a']: votes[t3][t2] += 1
        n = 0
        ents = sorted(set(ent2) | {b for b, _ in taken})
        for t3, vs in votes.items():
            r = by_a[t3]
            if 'b' in r or not r['n3']: continue
            t2, c = vs.most_common(1)[0]
            if c < 0.6 * sum(vs.values()) or S2.c(t2) not in ENC: continue
            cmpd = compare(S3, r['a'], r['L'], S2, t2, strong)
            if cmpd and cmpd[0] == 'reloc':
                if claim(r, t2, cmpd[3], cls='reloc', diffs=0, relocs=cmpd[2], sim=1.0, dup=1, how='xref'): n += 1
                continue
            k = bisect.bisect_right(ents, t2)
            e2 = ents[k] if k < len(ents) else S2.code[-1] + 2
            tt = [S3.tok(x) for x in S3.insns(r['a'], r['a'] + r['L'])]
            sim = round(difflib.SequenceMatcher(None, tt, [S2.tok(x) for x in S2.insns(t2, e2)],
                                                autojunk=False).ratio(), 3)
            if claim(r, t2, e2, cls='near' if sim >= NEAR_MIN else 'changed', sim=sim, diffs='', relocs='',
                     dup=1, how='xref'): n += 1
        return n

    # pinned exact/reloc placements first, then in-place exact/reloc from the search, then pinned near ones; a pin
    # whose routine scores below NEAR_MIN there (a table slot whose 2i routine was rewritten, or a role
    # placement) waits for the in-place search and takes its place only if still free; copies found out of place
    # come after it. Pins that disagree (two addresses for a routine, two routines for an
    # address) are settled by how well the routine scores at the address: exact, reloc, then similarity.
    late, unplaced, scored = [], [], []
    for r in R:
        if r['name'] not in pins or not r['n3']: continue
        tt = [S3.tok(x) for x in S3.insns(r['a'], r['a'] + r['L'])]
        for b in pins[r['name']]:
            c = compare(S3, r['a'], r['L'], S2, b, [])
            if c and c[0] in ('exact', 'reloc'):
                scored.append((3 if c[0] == 'exact' else 2, b, r, c)); continue
            k = bisect.bisect_right(ent2, b)
            e2 = ent2[k] if k < len(ent2) else S2.code[-1] + 2
            sim = round(difflib.SequenceMatcher(None, tt, [S2.tok(x) for x in S2.insns(b, e2)],
                                                autojunk=False).ratio(), 3)
            scored.append((sim, b, r, (None, '', '', e2)))
    scored.sort(key=lambda s: (-s[0], s[1]))
    near_pins = []
    for score, b, r, c in scored:
        if score < NEAR_MIN: late.append((r, b, c[3], score)); continue
        if not c[0]: near_pins.append((score, b, r, c)); continue
        if 'b' in r:
            if r['b'] != b: unplaced.append((r['name'], b, 'a better pin placed it at %08X' % r['b']))
            continue
        if not claim(r, b, c[3], cls=c[0], diffs=c[1], relocs=c[2], sim=1.0, dup=1, how='pin'):
            unplaced.append((r['name'], b, 'taken'))
    place(False, same_only=True)                                         # in-place exact/reloc beat near pins
    for score, b, r, c in near_pins:
        if 'b' in r:
            if r['b'] != b: unplaced.append((r['name'], b, 'search placed it at %08X (%s)' % (r['b'], r['cls'])))
            continue
        if not claim(r, b, c[3], cls='near', sim=score, diffs='', relocs='', dup=1, how='pin'):
            unplaced.append((r['name'], b, 'taken'))
    place(False)
    for it in range(4):
        if not xref_pass(): break
    near_pass(True)
    for r, b, e2, sim in late:
        if 'b' in r:
            if r['b'] != b: unplaced.append((r['name'], b, 'search placed it at %08X (%s)' % (r['b'], r['cls'])))
            continue
        if not claim(r, b, e2, cls='changed', sim=sim, diffs='', relocs='', dup=1, how='pin'):
            unplaced.append((r['name'], b, 'taken'))
    place(True)
    near_pass(False)
    # dead exits (unreached code left after a tail call) right after a placed routine's last instruction belong
    # to it when the 3s routine has dead code of its own, at least as much
    starts2 = sorted(r['b'] for r in R if 'b' in r)
    grown = 0
    for r in R:
        if 'b' not in r or S2.c(r['e2']) != DEAD: continue
        dead3 = sum(1 for x in range(r['a'], r['a'] + r['L'], 2) if S3.c(x) == DEAD)
        nxt = starts2[bisect.bisect_right(starts2, r['b'])] if bisect.bisect_right(starts2, r['b']) < len(starts2) else 1 << 40
        x, dead2 = r['e2'], 0
        while x < nxt and S2.c(x) == DEAD: x += 2; dead2 += 1
        while x < nxt and S2.c(x) in (POOL, TABLE, PAD): x += 2
        if 0 < dead2 <= dead3: r['e2'] = x; grown += 1
    print(f'{grown} routines took their dead exits')
    with open(out / 'pins_unplaced.tsv', 'w', encoding='utf-8') as f:
        f.write('name\taddr2\twhy\n')
        held = sorted((r['b'], r['e2'], r['name'], r['cls']) for r in R if 'b' in r)
        for n, b, why in unplaced:
            if why == 'taken':
                h = held[bisect.bisect_right(held, (b, 1 << 40)) - 1]
                why = 'taken by %s (%s)' % (h[2], h[3]) if h[0] <= b < h[1] else 'overlaps a placed routine'
            f.write('%s\t%08X\t%s\n' % (n, b, why))
    for r in R:
        if 'cls' not in r: r['cls'] = 'absent' if r['n3'] else 'nocode'
    # in link order or not: between the 2i places of the nearest exact/reloc routines before and after it
    mt = [(r['a'], r['b'], r['e2']) for r in R if r.get('cls') in ('exact', 'reloc')]
    ma = [x[0] for x in mt]
    for r in R:
        if 'b' not in r: continue
        i = bisect.bisect_left(ma, r['a'])
        p = mt[i - 1] if i > 0 else None
        if i < len(mt) and mt[i][0] == r['a']: i += 1
        n = mt[i] if i < len(mt) else None
        r['order'] = 'in' if (not p or p[1] < r['b']) and (not n or r['b'] < n[1]) else 'out'

    end2 = S2.code[-1] + 2
    write(R, S2, ent2, end2, out)


def write(R, S2, ent2, end2, out):
    import bisect
    with open(out / 'census.tsv', 'w', encoding='utf-8') as f:
        f.write('name\tmodule\tkind\taddr3\tsize3\tinsns3\tclass\torder\taddr2\tsize2\tdelta\tsim\tdiffs\trelocs\tdup\tvia\n')
        for r in R:
            b = r.get('b')
            f.write(f"{r['name']}\t{r['module']}\t{r['kind']}\t{r['a']:08X}\t{r['L']}\t{r['n3']}\t{r['cls']}\t"
                    f"{r.get('order', '')}\t{format(b, '08X') if b else ''}\t{r['e2'] - b if b else ''}\t"
                    f"{b - r['a'] if b else ''}\t{r.get('sim', '')}\t{r.get('diffs', '')}\t{r.get('relocs', '')}\t"
                    f"{r.get('dup', '')}\t{r.get('how', '')}\n")
    # 2i code no 3s routine maps to, cut at function entries, with the modules of the matched neighbours
    m = sorted((r['b'], r['e2'], r['module']) for r in R if r.get('b'))
    mb = [x[0] for x in m]
    gaps, pos = [], BASE + 0x400
    for b, e2, _ in m + [(end2, end2, '')]:
        if b > pos: gaps.append((pos, b))
        pos = max(pos, e2)
    with open(out / 'new2i.tsv', 'w') as f:
        f.write('addr2\tsize\tinsns\tprev_module\tnext_module\n')
        for g0, g1 in gaps:
            cuts = [g0] + [e for e in ent2[bisect.bisect_right(ent2, g0):bisect.bisect_left(ent2, g1)]] + [g1]
            for x, y in zip(cuts, cuts[1:]):
                ins = S2.insns(x, y)
                if not ins: continue
                i = bisect.bisect_left(mb, x)
                pm = m[i - 1][2] if i > 0 else ''; nm = m[i][2] if i < len(m) else ''
                f.write(f'{x:08X}\t{y - x}\t{len(ins)}\t{pm}\t{nm}\n')
    # layout: runs of consecutive (3s order) matched routines with the same delta
    with open(out / 'layout.tsv', 'w') as f:
        f.write('addr3_from\taddr3_to\taddr2_from\tdelta\troutines\tfirst\tlast\tmodules\n')
        run = []
        def flush():
            if not run: return
            mods = list(dict.fromkeys(x['module'] for x in run))
            f.write(f"{run[0]['a']:08X}\t{run[-1]['a'] + run[-1]['L']:08X}\t{run[0]['b']:08X}\t{run[0]['b'] - run[0]['a']}\t"
                    f"{len(run)}\t{run[0]['name']}\t{run[-1]['name']}\t{','.join(mods[:6])}{'...' if len(mods) > 6 else ''}\n")
        for r in R:
            if r['cls'] not in ('exact', 'reloc'): continue
            if run and r['b'] - r['a'] != run[-1]['b'] - run[-1]['a']: flush(); run = []
            run.append(r)
        flush()
    classes = ('exact', 'reloc', 'near', 'near-moved', 'changed', 'absent', 'nocode')
    with open(out / 'modules.tsv', 'w', encoding='utf-8') as f:
        f.write('module\troutines\t' + '\t'.join(classes) + '\tbytes3\tbytes3_exact_reloc\n')
        mods = collections.OrderedDict()
        for r in R: mods.setdefault(r['module'], []).append(r)
        for m, rs in mods.items():
            c = collections.Counter(r['cls'] for r in rs)
            f.write(f"{m}\t{len(rs)}\t" + '\t'.join(str(c[k]) for k in classes) +
                    f"\t{sum(r['L'] for r in rs)}\t{sum(r['L'] for r in rs if r['cls'] in ('exact', 'reloc'))}\n")
    # summary: 3s routines by kind and class; 2i code range by what covers it
    lines = []
    c = collections.Counter((r['kind'], r['cls']) for r in R)
    for kind in ('c', 'asm', 'lib'):
        lines.append(f"3s {kind:3s} " + '  '.join(f'{k} {c[kind, k]}' for k in classes if c[kind, k]))
    total = end2 - (BASE + 0x400)
    cov = collections.Counter(); ins = collections.Counter(); fn = collections.Counter()
    for r in R:
        if r.get('b'):
            k = r['cls'] if r.get('order') == 'in' or r['cls'] not in ('exact', 'reloc') else r['cls'] + '-out'
            cov[k] += r['e2'] - r['b']; ins[k] += len(S2.insns(r['b'], r['e2'])); fn[k] += 1
    new = [l.rstrip('\n').split('\t') for l in open(out / 'new2i.tsv')][1:]
    cov['unmatched'] = sum(int(x[1]) for x in new); ins['unmatched'] = sum(int(x[2]) for x in new)
    fn['unmatched'] = len(new)
    lines.append(f'2i code range {BASE + 0x400:08X}-{end2:08X}: {total} bytes, {len(S2.code)} instructions')
    for k in ('exact', 'exact-out', 'reloc', 'reloc-out', 'near', 'near-moved', 'changed', 'unmatched'):
        lines.append(f'  {k:10s} {fn[k]:5d} functions {cov[k]:8d} bytes ({100 * cov[k] / total:5.1f}%) '
                     f'{ins[k]:7d} instructions ({100 * ins[k] / len(S2.code):5.1f}%)')
    (out / 'summary.txt').write_text('\n'.join(lines) + '\n')
    print('\n'.join(lines))


if __name__ == '__main__':
    main()
