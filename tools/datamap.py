#!/usr/bin/env python3
"""Map the 3rd Strike data objects onto the 2nd Impact program data.

    python tools/datamap.py <3s sf3 dir> <3s match_status.tsv> <2i rom dir> <out dir> [<si2map dir>]

<3s sf3 dir> holds sf3.map and verify/bootstrap/prog.bin (the arcade 3s image); <2i rom dir> holds prog_data.bin and
prog_op.bin (tools/cps3rom2.py extract). With <si2map dir> (census.tsv, pins_merged.tsv or pins.tsv, prog.bin, hmap.bin of
tools/si2map.py, census3s.py and tablepins.py) the routine pairing and the 2i literal pools come from there, and
objects holding routine pointers are placed where 2i data words hold the paired 2i routines (table pins vote
directly); without it the tool pairs routines itself. Writes to <out dir>:
  objects.tsv  every 3s data object of sf3.map (a DAT symbol up to the next one or its module's end) and where it is
               in 2i: identical | reloc (equal but for pointer words) | changed (same size) | resized (other size,
               >= half equal) | relaid (placed, < half equal) | not_found | absent_fighter[(twin)]
  gaps.tsv     2i data no 3s object was placed on, named after the placed objects around it (2i keeps the 3s link
               order)
  modules.tsv  bytes per 3s module and class
  summary.txt  the tables printed at the end

Placement, strongest first: content hits (pointer words as wildcards), data addresses the paired routines load
(3s routines found in the 2i instruction view with their pools masked), char_init_data (by hand: its rows are the
fighters'), then pointer anchoring to a fixed point: a placed pair maps the objects its pointer words point at, word
by word at equal offsets (votes from a table whose size changed need the target's content to agree); script heads
before placed scripts; link-order neighbours whose content agrees; 12-byte block votes for what is left.
"""
import sys, re, bisect, collections
from pathlib import Path

B0 = 0x06000000
D3 = (0x0613BD98, 0x066166E4)          # 3s CTBL + D ROM image
D2 = (0x060FC564, 0x0657FA6C)          # 2i CTBL + D ROM image (sections words at 060FC584)
CODE2 = (0x06000400, D2[0])
SEARCH2 = ((D2[0], D2[1]), (0x06800000, 0x06BA0000))   # 06BA0000-06DA8000 is a stale copy of the data tail
SEEDS = {'char_init_data': 0x06152958}
ABSENT = ('chun_', 'makoto_', 'q_', 'no12_', 'remy_', 'bonus_')
KEEP = ('CVECT', 'CTBL', 'D', 'CSNDBANK', 'CSND', 'CCDVOL', 'CCGDIR', 'CCG')


def isptr(w): return (w >> 24) in (0x06, 0x02)
def w32(d, p): return int.from_bytes(d[p - B0:p - B0 + 4], 'big')
def h16(d, o): return (d[o] << 8) | d[o + 1]


def objects(mapfile):
    """[(addr, size, name, module, section)] from the link map"""
    L = open(mapfile, encoding='latin-1').read().split('\n')
    rx_sec = re.compile(r"^(\w+)\s+H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})\s+H'([0-9A-F]{8})")
    rx_cont = re.compile(r"^\s+H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})\s+H'([0-9A-F]{8})")
    mods = []; sec = pend = None
    for l in L:
        m = rx_sec.match(l)
        if m: sec = m.group(1); pend = (int(m.group(2), 16), int(m.group(4), 16)); continue
        m = rx_cont.match(l)
        if m and sec: pend = (int(m.group(1), 16), int(m.group(3), 16)); continue
        if pend and l.startswith('              ') and l.strip():
            if pend[1]: mods.append((sec, l.split()[0], pend[0], pend[0] + pend[1]))
            pend = None
    syms = sorted((int(m.group(2), 16), m.group(1)) for m in (re.match(r"^_?(\S+)\s+H'([0-9A-F]{8})\s+DAT\s*$", l) for l in L) if m)
    sa = [s[0] for s in syms]
    O = []
    for sec, mod, s, e in mods:
        if sec not in KEEP: continue
        inside = []; seen = set()
        for ad, n in syms[bisect.bisect_left(sa, s):bisect.bisect_left(sa, e)]:
            if ad not in seen: seen.add(ad); inside.append((ad, n))     # aliases: the first name
        if not inside or inside[0][0] > s: inside.insert(0, (s, f'{mod}+0'))
        for k, (ad, n) in enumerate(inside):
            O.append((ad, (inside[k + 1][0] if k + 1 < len(inside) else e) - ad, n, mod, sec))
    return sorted(O)


def refs(op, da, lo, hi):
    """data addresses referenced: {target: (code refs, data refs)}; code = mov.l pool loads, data = pointer words"""
    def ok(w): return lo <= w < hi or 0x06800000 <= w < 0x07000000
    nc = collections.Counter(); nd = collections.Counter(); pools = set()
    for pc in range(0x400, lo - B0, 2):
        h = h16(op, pc)
        if h >> 12 == 0xD:
            t = ((pc + 4) & ~3) + (h & 0xFF) * 4
            if t + 4 <= lo - B0: pools.add(t)
    for t in pools:
        w = int.from_bytes(da[t:t + 4], 'big')
        if ok(w): nc[w] += 1
    for o in range(lo - B0 + ((B0 - lo) & 3), hi - B0 - 3, 4):
        w = int.from_bytes(da[o:o + 4], 'big')
        if ok(w): nd[w] += 1
    return {t: (nc[t], nd[t]) for t in set(nc) | set(nd)}


def ptrmask(ad, s):
    return {o for o in range((-ad) & 3, len(s) - 3, 4) if isptr(int.from_bytes(s[o:o + 4], 'big'))}


def same_reloc(s, t, pm):
    last = 0
    for p in sorted(pm):
        if s[last:p] != t[last:p]: return False
        w = int.from_bytes(t[p:p + 4], 'big')
        if not (isptr(w) or w == 0): return False
        last = p + 4
    return s[last:] == t[last:]


def content(a, b, O):
    """{obj index: 2i addr} for objects found by content (exact, or equal but for pointer words); an ambiguous hit
    goes to the candidate nearest the module's previous hit"""
    K = 8
    idx = collections.defaultdict(list)
    for lo, hi in SEARCH2:
        for i in range(lo - B0, hi - B0 - K, 2):
            w = b[i:i + K]
            if w != b'\0' * K and w != b'\xff' * K: idx[w].append(i)
    out = {}; prev = {}
    for k, (ad, sz, nm, mod, sec) in enumerate(O):
        if sz < 24: continue
        s = a[ad - B0:ad - B0 + sz]
        if len(set(s)) < 6: continue                   # too featureless to place alone
        pm = ptrmask(ad, s); bad = {q for p in pm for q in range(p, p + 4)}
        cands = set(); tried = 0
        for anc in range(ad & 1, sz - K + 1, 2):
            if any(x in bad for x in range(anc, anc + K)): continue
            w = s[anc:anc + K]
            if w == b'\0' * K or w == b'\xff' * K: continue
            cl = idx.get(w, ())
            tried += 1
            if len(cl) <= 400:
                for c in cl:
                    st = c - anc
                    t = b[st:st + sz]
                    if t == s or (pm and same_reloc(s, t, pm)): cands.add(st + B0)
            if cands or tried >= 6: break
        if not cands: continue
        if len(cands) == 1: pick = next(iter(cands))
        elif mod in prev: pick = min(cands, key=lambda c: abs(c - (prev[mod][1] + ad - prev[mod][0])))
        else: continue
        out[k] = pick; prev[mod] = (ad, pick)
    return out


def codepairs(a, ms, op, da):
    """{3s data addr: 2i data addr} loaded by the same mov.l of paired routines (unanimous pairs only)"""
    K = 8
    idx = collections.defaultdict(list)
    for i in range(CODE2[0] - B0, CODE2[1] - B0 - K, 2): idx[op[i:i + K]].append(i)
    rows = [l.rstrip('\n').split('\t') for l in open(ms, encoding='utf-8') if not l.startswith('#')]
    votes = collections.defaultdict(collections.Counter)
    for r in (dict(zip(rows[0], r)) for r in rows[1:]):
        ad = int(r['arcade_address'], 16) - B0; sz = int(r['arcade_size'])
        if sz < 16: continue
        pool = set(); loads = []
        for k in range(0, sz, 2):
            x = h16(a, ad + k)
            if x >> 12 == 0xD:
                t = ((ad + k + 4) & ~3) + (x & 0xFF) * 4
                if ad <= t < ad + sz: pool.update((t - ad, t - ad + 2)); loads.append((k, (x >> 8) & 15, t - ad))
            elif x >> 12 == 0x9:
                t = ad + k + 4 + (x & 0xFF) * 2
                if ad <= t < ad + sz: pool.add(t - ad)
        ins = [k for k in range(0, sz, 2) if k not in pool]
        if len(ins) < 8: continue
        best = None; tried = 0
        for anc in range(0, sz - K, 2):
            if any(q in pool for q in range(anc, anc + K, 2)): continue
            cl = idx.get(a[ad + anc:ad + anc + K]); tried += 1
            if cl and len(cl) <= 50:
                for c in cl:
                    st = c - anc
                    if st < CODE2[0] - B0 or st + sz > CODE2[1] - B0: continue
                    eq = sum(1 for k in ins if a[ad + k:ad + k + 2] == op[st + k:st + k + 2])
                    if best is None or eq > best[0]: best = (eq, st)
                if best and best[0] == len(ins): break
            if tried > 8: break
        if not best or best[0] < 0.85 * len(ins): continue
        st = best[1]
        for k, n, t in loads:
            v3 = int.from_bytes(a[ad + t:ad + t + 4], 'big')
            x = h16(op, st + k)
            if not D3[0] <= v3 < 0x07000000 or x >> 12 != 0xD or (x >> 8) & 15 != n: continue
            t2 = ((st + k + 4) & ~3) + (x & 0xFF) * 4
            v2 = int.from_bytes(da[t2:t2 + 4], 'big')
            if D2[0] <= v2 < 0x07000000: votes[v3][v2] += 1
    return {v3: next(iter(c)) for v3, c in votes.items() if len(c) == 1}


def census(mapdir):
    """si2map's routine pairing: {3s addr: (2i addr, class, size3, size2)}; sure = exact/reloc with one candidate"""
    rows = [l.rstrip('\n').split('\t') for l in open(mapdir / 'census.tsv', encoding='utf-8')]
    out = {}
    for r in (dict(zip(rows[0], r)) for r in rows[1:]):
        if r['class'] in ('exact', 'reloc', 'near', 'near-moved', 'changed') and r['addr2']:
            out[int(r['addr3'], 16)] = (int(r['addr2'], 16), r['class'], int(r['size3']), int(r['size2'] or 0),
                                        r['dup'] == '1' and r['class'] in ('exact', 'reloc'))
    return out


def refs_hmap(prog, cls, da):
    """refs() with the code side read from si2map's halfword classes: every 4-aligned literal-pool word"""
    r = {t: (0, nd) for t, (nc, nd) in refs(prog, da, *D2).items() if nd}
    for h in range(0x200, len(cls) - 1, 2):
        if cls[h] == 2 and cls[h + 1] == 2:
            w = int.from_bytes(prog[2 * h:2 * h + 4], 'big')
            if D2[0] <= w < D2[1] or 0x06800000 <= w < 0x07000000:
                nc, nd = r.get(w, (0, 0)); r[w] = (nc + 1, nd)
    return r


def census_codepairs(a, cen, prog, cls):
    """codepairs() through si2map's routine pairing: the 3s mov.l and the 2i one at the same offset, same register,
    loading a word si2map classes as pool"""
    votes = collections.defaultdict(collections.Counter)
    for ad3, (ad2, k_, sz3, sz2, sure) in cen.items():
        ad, st = ad3 - B0, ad2 - B0
        for k in range(0, sz3, 2):
            x = h16(a, ad + k)
            if x >> 12 != 0xD: continue
            t = ((ad + k + 4) & ~3) + (x & 0xFF) * 4
            if not ad <= t < ad + sz3: continue
            v3 = int.from_bytes(a[t:t + 4], 'big')
            if not D3[0] <= v3 < 0x07000000 or st + k + 2 > len(prog): continue
            y = h16(prog, st + k)
            if y >> 12 != 0xD or (y >> 8) & 15 != (x >> 8) & 15: continue
            t2 = ((st + k + 4) & ~3) + (y & 0xFF) * 4
            if t2 // 2 + 1 >= len(cls) or cls[t2 // 2] != 2: continue
            v2 = int.from_bytes(prog[t2:t2 + 4], 'big')
            if D2[0] <= v2 < 0x07000000: votes[v3][v2] += 1 if sure else 0.5
    out = {}
    for v3, c in votes.items():
        (v2, n), = c.most_common(1)
        if n > 0.75 * sum(c.values()): out[v3] = v2
    return out


def routine_anchors(a, b, O, cen, pins, unplaced):
    """{obj index: 2i addr} for objects holding routine pointers: each 3s word that is a paired routine start votes
    for every 2i data word holding the 2i routine (start = that word - offset; sure pairs weigh 2, the rest 1);
    si2map's table pins vote directly (4); a start needs 4 and half of the weight"""
    loc = collections.defaultdict(list)
    for o in range(D2[0] - B0, D2[1] - B0, 4):
        w = int.from_bytes(b[o:o + 4], 'big')
        if CODE2[0] <= w < CODE2[1]: loc[w].append(o + B0)
    A3 = [o[0] for o in O]
    votes = collections.defaultdict(collections.Counter); nw = collections.Counter()
    for k in unplaced:
        ad, sz = O[k][0], O[k][1]
        for o in range((-ad) & 3, sz - 3, 4):
            v = cen.get(int.from_bytes(a[ad - B0 + o:ad - B0 + o + 4], 'big'))
            if not v: continue
            wt = 2 if v[4] else 1                         # near/changed/duplicated pairings count half
            nw[k] += wt
            for p in loc.get(v[0], ())[:20]: votes[k][p - o] += wt
    for p3, p2 in pins:
        k = bisect.bisect_right(A3, p3) - 1
        if k in unplaced and p3 < O[k][0] + O[k][1]: votes[k][p2 - (p3 - O[k][0])] += 4; nw[k] += 4
    out = {}
    for k, c in votes.items():
        best, n = c.most_common(1)[0]
        if n >= 4 and n * 2 >= nw[k] and best >= D2[0]: out[k] = best
    return out


def fuzzy(a, b, O, unplaced):
    """{obj index: 2i addr} where most of a 12-byte block sample of the object sits at one 2i start"""
    K = 12
    idx = collections.defaultdict(list)
    for i in range(D2[0] - B0, D2[1] - B0 - K, 2):
        w = b[i:i + K]
        if len(set(w)) > 2: idx[w].append(i)
    out = {}
    for k in unplaced:
        ad, sz = O[k][0], O[k][1]
        if sz < 32: continue
        s = a[ad - B0:ad - B0 + sz]
        nb = 0; votes = collections.Counter()
        for o in range(ad & 1, sz - K + 1, 4 if sz < 4096 else 8):
            w = s[o:o + K]
            if len(set(w)) <= 2: continue
            p = o - ((ad + o) & 3)
            if any(isptr(int.from_bytes(s[q:q + 4], 'big')) for q in (p, p + 4, p + 8, p + 12) if 0 <= q and q + 4 <= sz): continue
            nb += 1
            c = idx.get(w, ())
            if len(c) <= 64:
                for x in c: votes[x - o] += 1
        if votes:
            best, n = votes.most_common(1)[0]
            if n >= 3 and n * 10 >= nb * 3: out[k] = best + B0
    return out


class Mapper:
    def __init__(self, a, b, O, ref3, ref2):
        self.a, self.b, self.O, self.ref3, self.ref2 = a, b, O, ref3, ref2
        self.A3 = [o[0] for o in O]; self.R3S = sorted(ref3)
        self.m2 = {}; self.how = {}

    def place(self, d, how):
        for k, ad in d.items():
            if k not in self.m2: self.m2[k] = ad; self.how[k] = how

    def obj_at(self, p):
        i = bisect.bisect_right(self.A3, p) - 1
        return i if i >= 0 and self.O[i][0] == p else None

    def bounds(self):
        self.B2 = sorted(set(self.ref2) | set(self.m2.values()))
        self.B3 = sorted(set(self.R3S) | {self.O[i][0] for i in self.m2})

    @staticmethod
    def nxt(B, ad, cap):
        j = bisect.bisect_right(B, ad)
        return min(B[j] if j < len(B) else ad + cap, ad + cap) - ad

    def spans(self, i):
        """bytes to the next referenced or placed address, on each side; an unplaced, unreferenced 3s successor
        merges into the span as its 2i copy does"""
        O = self.O; a3 = O[i][0]; s3 = self.nxt(self.B3, a3, max(O[i][1], 1))
        j = i + 1
        while j < len(O) and j not in self.m2 and O[j][0] not in self.ref3 and O[j][3] == O[i][3]:
            s3 = O[j][0] + O[j][1] - a3; j += 1
        return s3, self.nxt(self.B2, self.m2[i], 0x40000)

    def compare(self, a3, a2, n, strict=False):
        """(equal halfwords, halfwords) over n bytes; a 3s pointer word agrees with a 2i pointer word (strict: one
        into the 2i data, and an object of pointers needs nearly all of them to)"""
        x = self.a[a3 - B0:a3 - B0 + n]; y = self.b[a2 - B0:a2 - B0 + n]
        if x == y: return n // 2, n // 2
        eq = o = np = bad = 0
        while o + 1 < n:
            if (a3 + o) & 3 == 0 and o + 4 <= n and isptr(int.from_bytes(x[o:o + 4], 'big')):
                w = int.from_bytes(y[o:o + 4], 'big'); np += 1
                if (D2[0] <= w < 0x07000000) if strict else isptr(w): eq += 2
                else: bad += 1
                o += 4; continue
            eq += x[o:o + 2] == y[o:o + 2]; o += 2
        if strict and np and bad * 5 > np: return 0, n // 2
        return eq, n // 2

    def run(self):
        O, m2, how = self.O, self.m2, self.how
        strongv = collections.defaultdict(collections.Counter); weakv = collections.defaultdict(collections.Counter)
        done = set(); self.bounds()
        while True:
            new = 0
            for i in [i for i in m2 if i not in done]:
                done.add(i)
                a3, a2 = O[i][0], m2[i]
                if (a3 - a2) & 3: continue
                s3, s2 = self.spans(i); L = min(s3, s2)
                eq, tot = self.compare(a3, a2, L)
                trusted = how[i] == 'seed' or s3 == s2 or eq == tot
                for o in range((-a3) & 3, L - 3, 4):
                    p3 = w32(self.a, a3 + o); p2 = w32(self.b, a2 + o)
                    if not (D3[0] <= p3 < 0x07000000 and D2[0] <= p2 < 0x07000000): continue
                    j = self.obj_at(p3)                 # pointers into an object's middle do not place it
                    if j is not None: (strongv if trusted else weakv)[j][p2] += 1
            for j in set(strongv) | set(weakv):
                if j in m2: continue
                c = strongv.get(j)
                if c:
                    best, n = c.most_common(1)[0]
                    if n * 2 > sum(c.values()): m2[j] = best; how[j] = 'ptr'; new += 1
                    continue
                best, n = weakv[j].most_common(1)[0]
                if n * 2 <= sum(weakv[j].values()): continue
                eq, tot = self.compare(O[j][0], best, min(O[j][1], self.nxt(self.B2, best, 0x40000)))
                if tot and eq >= 0.6 * tot: m2[j] = best; how[j] = 'ptr_weak'; new += 1
            for j in range(1, len(O)):                  # unreferenced script heads before placed scripts
                i = j - 1
                if i in m2 or j not in m2 or how[j] == 'before': continue
                if O[i][0] in self.ref3 or O[i][0] + O[i][1] != O[j][0] or O[i][3] != O[j][3]: continue
                if m2[j] - O[i][1] >= D2[0]: m2[i] = m2[j] - O[i][1]; how[i] = 'before'; new += 1
            for i in range(len(O) - 1):                 # link-order neighbours whose content agrees
                for x, y in ((i, i + 1), (i + 1, i)):
                    if x not in m2 or y in m2 or O[x][3] != O[y][3] or O[y][1] < 4: continue
                    ad = m2[x] + (O[y][0] - O[x][0])
                    if ad < D2[0] or (ad - O[y][0]) & 1: continue
                    eq, tot = self.compare(O[y][0], ad, min(O[y][1], 512), strict=True)
                    if tot and eq * 2 >= tot: m2[y] = ad; how[y] = 'chain'; new += 1
            self.bounds()
            if not new: return

    def classify(self, i):
        """(class, 2i addr, span2, similarity, bytes of 2i claimed)"""
        O = self.O; a3, sz, nm, mod, sec = O[i]
        absent = mod.startswith(ABSENT)
        if i not in self.m2: return ('absent_fighter' if absent else 'not_found'), None, None, None, 0
        a2 = self.m2[i]; s3, s2 = self.spans(i)
        eq, tot = self.compare(a3, a2, sz)
        if sz and self.a[a3 - B0:a3 - B0 + sz] == self.b[a2 - B0:a2 - B0 + sz]: k, claim, sim = 'identical', sz, 1.0
        elif sz and eq == tot: k, claim, sim = 'reloc', sz, 1.0
        else:
            eq, tot = self.compare(a3, a2, min(s3, s2)); sim = eq / tot if tot else 0.0
            k = 'changed' if s3 == s2 else ('resized' if sim >= 0.5 else 'relaid'); claim = s2
        if absent: k = 'absent_fighter(twin)' if k in ('identical', 'reloc') else 'absent_fighter'
        return k, a2, s2, sim, claim


def family(m):
    for pat, f in ((r'^(chun|makoto|q|no12|remy|bonus)_', 'absent fighters'),
                   (r'^(scene_char|stage_char|effect_char)', 'scene/stage/effect scripts'),
                   (r'_char$|_hitbox$|_attbox$|_attr$|_move$|_yuca$', 'fighters'), (r'^scrn_data', 'screen maps'),
                   (r'^chr_data', 'messages/fonts (chr_data)'), (r'^snd_|^sound_voice|^cd_volume', 'sound'),
                   (r'^(bg|BG)', 'stage tables (bg)'), (r'^cg_', 'CG patterns'), (r'^(EFF|eff|Eff)', 'effects'),
                   (r'^(end_|staff)', 'endings'), (r'^(pass|PASS|Com_|vs_shell|Getup|asstbl|BBBS|ACTIVE|active)', 'cpu AI'),
                   (r'^(sys_|Entry|DEMO|CMD_MAIN|cmd_|SYS_|test)', 'system/debug/commands')):
        if re.search(pat, m): return f
    return 'other'


def main():
    if len(sys.argv) not in (5, 6): sys.exit(__doc__)
    sf3, ms, rom, od = Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3]), Path(sys.argv[4])
    mapdir = Path(sys.argv[5]) if len(sys.argv) == 6 else None
    od.mkdir(parents=True, exist_ok=True)
    a = (sf3 / 'verify/bootstrap/prog.bin').read_bytes()
    b = (rom / 'prog_data.bin').read_bytes(); op = (rom / 'prog_op.bin').read_bytes()
    O = objects(sf3 / 'sf3.map')
    ref3 = refs(a, a, *D3)
    if mapdir:
        prog = (mapdir / 'prog.bin').read_bytes(); cls = (mapdir / 'hmap.bin').read_bytes()
        cen = census(mapdir)
        pins = [tuple(int(x, 16) for x in m.groups()) for m in
                (re.search(r'([0-9A-F]{8})->([0-9A-F]{8})', l) for l in open(next(f for f in (mapdir / 'pins_merged.tsv', mapdir / 'pins.tsv') if f.exists()), encoding='utf-8')) if m]
        ref2 = refs_hmap(prog, cls, b)
        pairs = census_codepairs(a, cen, prog, cls)
    else:
        ref2 = refs(op, b, *D2); pairs = codepairs(a, ms, op, b)
    M = Mapper(a, b, O, ref3, ref2)
    byname = {o[2]: i for i, o in enumerate(O)}
    M.place({byname[n]: ad for n, ad in SEEDS.items()}, 'seed')
    M.place(content(a, b, O), 'content')
    M.place({k: v for k, v in ((M.obj_at(v3), v2) for v3, v2 in pairs.items()) if k is not None}, 'code')
    M.run()
    if mapdir:
        M.place(routine_anchors(a, b, O, cen, pins, {i for i in range(len(O)) if i not in M.m2}), 'routines'); M.run()
    for _ in range(2):
        M.place(fuzzy(a, b, O, [i for i in range(len(O)) if i not in M.m2]), 'fuzzy'); M.run()
    # per object
    by = collections.defaultdict(collections.Counter); byn = collections.Counter()
    RANK = ['identical', 'reloc', 'changed', 'resized', 'relaid']
    lo, hi = D2; cl = bytearray(b'\xff') * (hi - lo); fam2 = bytearray(b'\xff') * (hi - lo)
    FAMS = sorted({family(o[3]) for o in O}); FI = {f: i for i, f in enumerate(FAMS)}
    claims = []
    with open(od / 'objects.tsv', 'w', encoding='utf-8') as f:
        f.write('section\tmodule\tname\taddr3\tsize3\tclass\taddr2\tspan2\tsimilarity\thow\n')
        for i, (a3, sz, nm, mod, sec) in enumerate(O):
            k, a2, s2, sim, claim = M.classify(i)
            f.write('\t'.join([sec, mod, nm, f'{a3:08X}', str(sz), k, f'{a2:08X}' if a2 else '', '' if s2 is None else str(s2),
                               '' if sim is None else f'{sim:.2f}', M.how.get(i, '')]) + '\n')
            grp = sec if sec in ('CTBL', 'D') else 'CG/SND'
            by[(grp, family(mod))][k] += sz
            if grp == 'CTBL': byn[k] += 1
            kk = 'identical' if k == 'absent_fighter(twin)' else k
            if a2 and kk in RANK and lo <= a2 < hi: claims.append((a2 - lo, claim, RANK.index(kk), FI[family(mod)]))
    with open(od / 'modules.tsv', 'w', encoding='utf-8') as f:
        cls = RANK + ['not_found', 'absent_fighter', 'absent_fighter(twin)']
        f.write('section\tmodule\tbytes\t' + '\t'.join(cls) + '\n')
        mods = collections.defaultdict(collections.Counter); msec = {}
        for l in open(od / 'objects.tsv', encoding='utf-8').readlines()[1:]:
            r = l.split('\t'); mods[r[1]][r[5]] += int(r[4]); msec[r[1]] = r[0]
        for m in sorted(mods, key=lambda m: -sum(mods[m].values())):
            f.write(f'{msec[m]}\t{m}\t{sum(mods[m].values())}\t' + '\t'.join(str(mods[m][x]) for x in cls) + '\n')
    for o, n, k, fi in sorted(claims):
        for i in range(o, min(o + n, hi - lo)):
            if k < cl[i]: cl[i] = k; fam2[i] = fi
    rep = []
    cls = RANK + ['not_found', 'absent_fighter', 'absent_fighter(twin)']
    rep.append('3s data objects by family, KB: ' + ' '.join(cls))
    for key in sorted(by, key=lambda k: -sum(by[k].values())):
        c = by[key]
        rep.append(f'{key[0]:6s} {key[1]:28s} {sum(c.values()) / 1024:7.1f} | ' + ' '.join(f'{c[x] / 1024:7.1f}' for x in cls))
    ct = collections.Counter()
    for key in by:
        if key[0] == 'CTBL': ct.update(by[key])
    tb = sum(ct.values())
    rep.append(f'3s CTBL: {sum(byn.values())} objects, {tb} bytes')
    for x in cls: rep.append(f'  {x:22s} {byn[x]:6d} objects {ct[x]:8d} bytes {ct[x] / tb:6.1%}')
    cnt = collections.Counter(cl); tot = hi - lo
    rep.append(f'2i data {lo:08X}-{hi:08X}, {tot} bytes, by the 3s object placed on it')
    for k, nm in enumerate(RANK): rep.append(f'  {nm:10s} {cnt[k]:8d} {cnt[k] / tot:6.1%}')
    rep.append(f'  {"none":10s} {cnt[255]:8d} {cnt[255] / tot:6.1%}')
    uf = collections.Counter(); ug = collections.Counter()
    with open(od / 'gaps.tsv', 'w', encoding='utf-8') as g:
        g.write('addr2\tsize\tbefore\tafter\n')
        i = 0
        while i < tot:
            if cl[i] != 255: i += 1; continue
            j = i
            while j < tot and cl[j] == 255: j += 1
            p = FAMS[fam2[i - 1]] if i and fam2[i - 1] != 255 else '-'
            q = FAMS[fam2[j]] if j < tot and fam2[j] != 255 else '-'
            g.write(f'{lo + i:08X}\t{j - i}\t{p}\t{q}\n')
            kk = p if p == q else f'{p} | {q}'; uf[kk] += j - i; ug[kk] += 1; i = j
    rep.append('2i data with no 3s object placed, by the families around it: KB, runs')
    for k, v in uf.most_common(16): rep.append(f'  {k:58s} {v / 1024:7.1f} {ug[k]:5d}')
    (od / 'summary.txt').write_text('\n'.join(rep) + '\n', encoding='utf-8')
    print('\n'.join(rep))


if __name__ == '__main__':
    main()
