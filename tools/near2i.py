#!/usr/bin/env python3
"""2nd Impact routines against 3s listings: the census, routine extents and the comparison levels.

Folded from si2cc's round-1 scratch tools (py, near.py), which are not kept; module-level state is the
si2map output in $SI2MAP (default scratch/si2map): census.tsv, funcs.tsv, prog.bin, hmap.bin.

  census() / units(on, rows)   3s listing functions placed in 2i (cls er, near, near-moved, changed, ...)
  Fn, LFn, IFn, i2(a, size)    a routine as words in a context; tokens() normalizes it (pool values, branches)
  layout_eq / level            2 = same words in place (relocations and outward branches free), 1 = same
                               tokens (pool placed elsewhere), 0 = neither
  classify(t3, t2)             hunks and a verdict: same, codegen, const, const+reg, source
"""
import os, sys, csv, difflib, collections
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import sh2

ROOT = Path(__file__).resolve().parents[1]
MAP = Path(os.environ.get('SI2MAP') or ROOT / 'scratch' / 'si2map')
BASE = 0x06000000
IMG2 = (MAP / 'prog.bin').read_bytes()
W2 = [IMG2[i] << 8 | IMG2[i + 1] for i in range(0, len(IMG2) - 1, 2)]
CLS2 = (MAP / 'hmap.bin').read_bytes()
CODE2 = (1, 4)


def isaddr(v):
    return v >> 24 in (0x02, 0x06)


class Fn:
    """A routine inside a context: ctx is the word array (module listing or the 2i image), addr the address of
    ctx word 0, a/n the routine's address and length in words, code the routine's code flags."""

    def __init__(self, ctx, cbase, a, n, code, pad=None):
        self.ctx, self.cbase, self.addr, self.n, self.code = ctx, cbase, a, n, code
        k = (a - cbase) // 2
        self.k0 = k
        self.words = ctx[k:k + n]
        self.pad = pad or [False] * n

    @staticmethod
    def from_module(mod, f):
        """mod: {function: (start, words, pool, syms)} complete and contiguous"""
        ctx = place_words(mod)
        s, w, pool, syms = mod[f]
        return Fn(ctx, 0, s, len(w), [not p for p in pool])

    @staticmethod
    def from_2i(a, size):
        o = (a - BASE) // 2
        n = size // 2
        c = [CLS2[o + i] in CODE2 if o + i < len(CLS2) else False for i in range(n)]
        pad = [CLS2[o + i] == 5 if o + i < len(CLS2) else False for i in range(n)]
        return Fn(W2, BASE, a, n, c, pad)

    def inside(self, t):
        return self.addr <= t < self.addr + 2 * self.n

    def val(self, t, size):
        k = (t - self.cbase) // 2
        if not 0 <= k < len(self.ctx) - (size == 4):
            return 'X'
        if size == 4:
            if self.ctx[k] < 0 or self.ctx[k + 1] < 0:
                return 'A'
            v = self.ctx[k] << 16 | self.ctx[k + 1]
            return 'A' if isaddr(v) else v
        return 'A' if self.ctx[k] < 0 else self.ctx[k]

    def tokens(self):
        """normalized code tokens (shape level)"""
        idx = {}
        pcs = [self.addr + 2 * k for k in range(self.n) if self.code[k]]
        for j, pc in enumerate(pcs):
            idx[pc] = j
        out = []
        for pc in pcs:
            w = self.words[(pc - self.addr) // 2]
            if w < 0:
                out.append('R'); continue
            k, t = sh2.flow(w, pc)
            if k in ('bra', 'bsr', 'cbr', 'cbrs'):
                op = w & (0xF000 if k in ('bra', 'bsr') else 0xFF00)
                out.append((op, idx.get(t, 'X') if self.inside(t) else 'X'))
                continue
            p = sh2.pcrel(w, pc)
            if p:
                if p[2] == 'a':
                    out.append((0xC700,)); continue
                out.append((w & 0xFF00, self.val(p[0], p[1])))
                continue
            out.append(w)
        return out


def place_words(mod):
    """the module's P words at their listing offsets (gaps, from alignment fill, as nop)"""
    end = max(v[0] + 2 * len(v[1]) for v in mod.values())
    ctx = [9] * (end // 2)
    for v in mod.values():
        ctx[v[0] // 2:v[0] // 2 + len(v[1])] = v[1]
    return ctx


def layout_eq(x, y):
    """x from a listing, y from 2i: level-2 test"""
    n = x.n
    if y.n != n:
        if y.n == n + 1 and (y.words[-1] in (0, 9) or y.pad[-1]):     # unit alignment pad after the routine
            pass
        elif y.n == n - 1 and not x.code[-1]:
            n = y.n
        else:
            return False
    for k in range(n):
        u, v = x.words[k], y.words[k]
        if u < 0 or u == v:
            continue
        if not x.code[k] and y.pad[k]:
            continue
        if x.code[k]:
            f1, t1 = sh2.flow(u, x.addr + 2 * k)
            f2, t2 = sh2.flow(v, y.addr + 2 * k)
            if f1 in ('bra', 'bsr') and f1 == f2 and not x.inside(t1) and not y.inside(t2):
                continue
            p1, p2 = sh2.pcrel(u, x.addr + 2 * k), sh2.pcrel(v, y.addr + 2 * k)
            if p1 and p2 and u & 0xFF00 == v & 0xFF00 and p1[2] != 'a' and not x.inside(p1[0])                     and not y.inside(p2[0]) and x.val(p1[0], p1[1]) == y.val(p2[0], p2[1]) != 'X':
                continue
        return False
    return True


def level(x, y, tx=None, ty=None):
    if layout_eq(x, y):
        return 2
    tx = tx if tx is not None else x.tokens()
    ty = ty if ty is not None else y.tokens()
    return 1 if tx == ty else 0


_BOUNDS = None


def extent2(a2, s2, want):
    """2i extent for a comparison: the census size, grown up to want bytes over code nothing calls (a dead exit
    the census leaves out as an 'unreached' piece), never past a called entry or another census routine"""
    global _BOUNDS
    import bisect
    if _BOUNDS is None:
        b = {int(l.split()[0], 16) for l in open(MAP / 'funcs.tsv') if not l.startswith('addr')
             and l.split()[1] != 'unreached'}
        b |= {r['a2'] for r in census() if r['a2'] is not None}
        _BOUNDS = sorted(b)
    if want <= s2:
        return s2
    i = bisect.bisect_right(_BOUNDS, a2)
    lim = _BOUNDS[i] if i < len(_BOUNDS) else a2 + want
    return max(s2, min(want, lim - a2))


def census():
    rows = list(csv.DictReader(open(MAP / 'census.tsv'), delimiter='\t'))
    for r in rows:
        r['a3'] = int(r['addr3'], 16)
        r['a2'] = int(r['addr2'], 16) if r['addr2'] else None
        r['s2'] = int(r['size2']) if r['size2'] else None
    return rows


def units(on, rows):
    """{(module, function): dict(cls, a2, s2, a3, n3)} for every listing function"""
    bym = collections.defaultdict(list)
    for r in rows:
        if r['kind'] == 'c':
            bym[r['module']].append(r)
    out = {}
    for m, fs in on.items():
        if m.startswith('__') or not fs:
            continue
        rs = sorted(bym.get(m, []), key=lambda r: r['a3'])
        base = None
        for r in rs:
            if r['name'] in fs:
                base = r['a3'] - fs[r['name']][0]; break
        if base is None:
            continue
        for f, v in fs.items():
            a3 = base + v[0]; e3 = a3 + 2 * len(v[1])
            inr = [r for r in rs if a3 <= r['a3'] < e3]
            u = dict(a3=a3, n3=len(v[1]), parts=len(inr), cls='absent', a2=None, s2=None)
            if inr and inr[0]['a3'] == a3:
                cl = {r['class'] for r in inr}
                if all(r['a2'] is not None for r in inr):
                    ds = {r['a2'] - r['a3'] for r in inr}
                    last = inr[-1]
                    if cl <= {'exact', 'reloc'} and len(ds) == 1:
                        u.update(cls='er', a2=inr[0]['a2'], s2=last['a2'] + last['s2'] - inr[0]['a2'])
                    elif len(inr) == 1 and inr[0]['class'] in ('near', 'near-moved', 'changed'):
                        u.update(cls=inr[0]['class'], a2=inr[0]['a2'], s2=inr[0]['s2'], sim=float(inr[0]['sim'] or 0))
                    elif len(ds) == 1 and cl & {'near', 'near-moved'}:
                        u.update(cls='near', a2=inr[0]['a2'], s2=last['a2'] + last['s2'] - inr[0]['a2'], sim=0.0)
                    else:
                        u.update(cls='mixed')
                else:
                    u.update(cls='part-absent' if cl - {'absent'} else 'absent')
            out[(m, f)] = u
    return out



rows = census()
ADDR2 = {r['a2']: r['name'] for r in rows if r['a2'] is not None and r['class'] != 'absent'}
NAME2 = {r['name']: r['a2'] for r in rows if r['a2'] is not None and r['class'] != 'absent'}


class LFn(Fn):
    """listing side: relocated longs carry the symbol; a routine symbol becomes its 2i address"""

    def __init__(self, mod, f):
        mod = {g: v[:4] for g, v in mod.items()}      # lsrc entries carry source lines as a fifth element
        ctx, syms = place_words(mod), {}
        for g, v in mod.items():
            for k, s in v[3].items():
                syms[(v[0] + 2 * k) // 2] = s
        s, w, pool, sy = mod[f]
        super().__init__(ctx, 0, s, len(w), [not p for p in pool])
        self.syms = syms

    def val(self, t, size):
        k = (t - self.cbase) // 2
        if size == 4 and k in self.syms:
            s = self.syms[k]
            for c in (s[1:] if s.startswith('_') else s, s.lstrip('_')):    # _divws is __divws in a listing
                if c in NAME2:
                    return ('A', NAME2[c])
            return 'A'
        return super().val(t, size)


class IFn(Fn):
    def val(self, t, size):
        v = super().val(t, size)
        if v == 'A' and size == 4:
            k = (t - self.cbase) // 2
            a = self.ctx[k] << 16 | self.ctx[k + 1]
            return ('A', a) if a in ADDR2 else 'A'
        return v


def i2(a, size):
    f = Fn.from_2i(a, size)
    g = IFn(f.ctx, f.cbase, f.addr, f.n, f.code, f.pad)
    return g


def fields(w):
    """(register mask, immediate mask) of an instruction word"""
    t = w >> 12
    if t in (0, 2, 3, 6):
        return 0x0FF0, 0
    if t in (1, 5):
        return 0x0FF0, 0x000F
    if t == 4:
        return 0x0F00, 0
    if t == 7 or t == 0xE:
        return 0x0F00, 0x00FF
    if t == 8:
        n = (w >> 8) & 15
        if n in (0, 1, 4, 5):
            return 0x00F0, 0x000F
        if n == 8:
            return 0, 0x00FF
        return 0, 0x00FF
    if t in (9, 0xD):
        return 0x0F00, 0
    if t == 0xC:
        return 0, 0x00FF
    return 0, 0


def absr(tok):
    """registers masked"""
    if isinstance(tok, tuple):
        if tok[0] in (0x9000, 0xD000) or (isinstance(tok[0], int) and tok[0] >> 12 in (9, 0xD)):
            return (tok[0] & 0xF000,) + tok[1:]
        return tok
    if tok == 'R':
        return tok
    r, i = fields(tok)
    return tok & ~r & 0xFFFF


def absi(tok):
    """immediates, displacements and pool values masked"""
    if isinstance(tok, tuple):
        if isinstance(tok[0], int) and tok[0] >> 12 in (9, 0xD):
            v = tok[1] if len(tok) > 1 else None
            return (tok[0], 'addr' if (v == 'A' or isinstance(v, tuple)) else 'k')
        return tok
    if tok == 'R':
        return tok
    r, i = fields(tok)
    return tok & ~i & 0xFFFF


def absri(tok):
    return absi(absr(tok)) if not isinstance(tok, tuple) else absi(absr(tok))


def is_call_tok(a, b):
    return isinstance(a, tuple) and isinstance(b, tuple) and len(a) > 1 and len(b) > 1 and a[0] == b[0] \
        and (a[1] == 'A' or isinstance(a[1], tuple)) and (b[1] == 'A' or isinstance(b[1], tuple))


def classify(t3, t2):
    sm = difflib.SequenceMatcher(None, t3, t2, autojunk=False)
    hunks = []
    for tag, i1, i2_, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            continue
        a, b = t3[i1:i2_], t2[j1:j2]
        if tag == 'delete':
            k = 'del'
        elif tag == 'insert':
            k = 'ins'
        elif len(a) == len(b):
            if all(is_call_tok(x, y) for x, y in zip(a, b) if x != y):
                k = 'call'
            elif all(absr(x) == absr(y) for x, y in zip(a, b)):
                k = 'reg'
            elif all(absi(x) == absi(y) for x, y in zip(a, b)):
                k = 'const'
            elif all(absri(x) == absri(y) for x, y in zip(a, b)):
                k = 'reg+const'
            elif sorted(map(repr, map(absr, a))) == sorted(map(repr, map(absr, b))):
                k = 'sched'
            else:
                k = 'other'
        else:
            k = 'other'
        hunks.append((k, i1, i2_, j1, j2))
    kinds = collections.Counter(h[0] for h in hunks)
    same_ms = sorted(map(repr, map(absr, t3))) == sorted(map(repr, map(absr, t2)))
    if not hunks:
        verdict = 'same'                          # identical tokens (at 2i's parity)
    elif same_ms and set(kinds) <= {'reg', 'sched', 'ins', 'del', 'other'}:
        verdict = 'codegen'                       # the same instructions, registers aside, placed/assigned otherwise
    elif set(kinds) <= {'const', 'reg', 'reg+const', 'call'} and set(kinds) & {'const', 'reg+const', 'call'}:
        verdict = 'const' if not set(kinds) & {'reg', 'reg+const'} else 'const+reg'
    else:
        verdict = 'source'
    return hunks, kinds, same_ms, verdict


def dis(tok, pc=0):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_SH, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_SH2)
    if isinstance(tok, tuple):
        op = tok[0]
        if op >> 12 in (9, 0xD):
            v = tok[1]
            vs = (f'&{ADDR2.get(v[1], hex(v[1]))}' if isinstance(v, tuple) else str(v) if v in ('A', 'X')
                  else hex(v))
            return f"{'mov.w' if op >> 12 == 9 else 'mov.l'} ={vs},r{(op >> 8) & 15}"
        if op == 0xC700:
            return 'mova'
        name = {0xA000: 'bra', 0xB000: 'bsr', 0x8900: 'bt', 0x8B00: 'bf', 0x8D00: 'bt/s', 0x8F00: 'bf/s'}.get(op, hex(op))
        return f'{name} ->{tok[1]}'
    if tok == 'R':
        return '(reloc)'
    i = next(md.disasm(tok.to_bytes(2, 'big'), pc), None)
    return f'{i.mnemonic} {i.op_str}'.strip() if i else f'.word {tok:04x}'
