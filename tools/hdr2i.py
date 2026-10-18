#!/usr/bin/env python3
"""2nd Impact headers against code: 3s C compiled with a header set at each routine's 2i address mod 4, compared
with 2i; and the field-offset pairs that the header changes are derived from (docs/STRUCTS.md).

    python tools/hdr2i.py list   <tree> <bin> <work> <out.pkl> [--align-dir D] [--only m.c ...]
    python tools/hdr2i.py fit    <on.pkl> <tree> <bin> <work> <out.pkl> <align in> <align out>
    python tools/hdr2i.py levels <on.pkl> <par.pkl> [<base par.pkl>] [--out levels.tsv]
    python tools/hdr2i.py pairs  <on.pkl> <par.pkl> <fields.tsv> <src dir> <out prefix>

list: every module of <tree>/build.bat compiled (bin: an SHC whose shcasm takes SHC_ALIGN_FILE, the sh5
  diagnostic build) to {module: {function: (start, words, pool, syms, lines)}}, as tools/shclist.py with the C
  line number above each halfword.
fit: list, then re-fit the SHC_ALIGN_FILE pads until every function with a 2i address has 2i's address mod 4.
  One function per module moves per round (a moved function's own pools may realign), and only the modules that
  moved are rebuilt.
levels: each near, near-moved, changed and exact/reloc routine of the census against 2i (tools/near2i.py:
  2 = exact or reloc in place, 1 = the same instructions with the pool elsewhere, 0 = neither), tallied by census
  class; with a base, the routines whose level moved. on.pkl is a 3s-header build without pads (it places the
  units).
pairs: 3s listing and 2i instructions aligned with immediates masked, each side simulated (register = base +
  offset); every memory access and relocated-symbol address gives (o3, o2), attributed to struct members named
  on the 3s source line (fields.tsv from tools/structlayout.py for the header set built). Writes <prefix>_acc.tsv
  and <prefix>_votes.tsv (struct, path, o3, size, shift:votes ...).
"""
import os, re, sys, csv, pickle, difflib, collections, subprocess, threading, queue
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import shclist, sh2
import near2i as N

ROOT = Path(__file__).resolve().parents[1]
SRCLINE = re.compile(r"^\s+(\S+\.[ch])\s+(\d+)\s")


# ---- list ------------------------------------------------------------------------------------------------------

def parse(text, cfile):
    out = shclist.parse(text)
    lines, cur_line, cur, in_p = {}, 0, None, False
    for l in text.splitlines():
        if l.startswith('******** STATISTICS'):
            break
        m = SRCLINE.match(l)
        if m:
            if m.group(1) == cfile:
                cur_line = int(m.group(2))
            continue
        mk = shclist.SECTION_MARK.match(l)
        if mk:
            in_p = mk.group(1) == 'P'
            if not in_p:
                cur = None
        m = shclist.FUNC.match(l)
        if m and in_p and m.group(2) in out:
            cur = m.group(2); lines[cur] = []
            continue
        if cur is None:
            continue
        m = shclist.LINE.match(l)
        if not m:
            continue
        v, mn = m.group(2), m.group(3)
        if mn.startswith('.RES'):
            lines[cur] += [cur_line] * (int(v, 16) // 2); continue
        if not (mn.startswith('.DATA') or mn[:1].isalpha()):
            continue
        lines[cur] += [cur_line] * (2 if (v.startswith('<') or len(v) == 8) else 1)
    return {f: v + (lines.get(f, []),) for f, v in out.items()}


def build(T, BIN, W, align=None, only=None, jobs=16):
    T, BIN, W = Path(T).resolve(), Path(BIN).resolve(), Path(W)
    mods = [m for m in shclist.modules(T) if only is None or m[0] in only]
    q = queue.Queue()
    for m in mods:
        q.put(m)
    res, lock = {}, threading.Lock()

    def worker(k):
        wd = W / f'w{k}'
        wd.mkdir(parents=True, exist_ok=True)
        for sub in ('src', 'include'):              # junctions into the tree, renewed when they point elsewhere
            j = wd / sub
            if os.path.lexists(j) and os.path.normcase(os.path.realpath(j)) != os.path.normcase(os.path.realpath(T / sub)):
                os.rmdir(j)
            if not os.path.lexists(j):
                subprocess.run(['cmd', '/c', 'mklink', '/J', str(j), os.path.realpath(T / sub)], capture_output=True)
        (wd / 'o').mkdir(exist_ok=True); (wd / 't').mkdir(exist_ok=True)
        env = {k2: v for k2, v in os.environ.items() if not re.match(r'(GEN|MDL|PEP|ASM|SWITCH|XJUMP|SLOT|JNEXT|SHCGEN)_', k2)}
        env.update(SHC_LIB=str(BIN), SHC_TMP=str(wd / 't'), TMP=str(wd / 't'), TEMP=str(wd / 't'))
        while True:
            try:
                mod, opts = q.get_nowait()
            except queue.Empty:
                return
            lst = wd / 'o' / 'm.lst'
            lst.unlink(missing_ok=True)
            al = Path(align) / (mod[:-2] + '.txt') if align else None
            if al and al.exists():
                env['SHC_ALIGN_FILE'] = str(al.resolve())
            else:
                env.pop('SHC_ALIGN_FILE', None)
            subprocess.run([str(BIN / 'shc.exe'), f'src/{mod}', *opts, '-listfile=o/m.lst', '-show=source,object',
                            '-object=o/m.obj'], cwd=wd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, env=env,
                           creationflags=0x00004000)
            r = parse(lst.read_text(errors='replace'), mod) if lst.exists() else None
            with lock:
                res[mod] = r

    ts = [threading.Thread(target=worker, args=(k,)) for k in range(jobs)]
    for t in ts: t.start()
    for t in ts: t.join()
    res['__failed__'] = sorted(m for m, r in res.items() if r is None)
    return res


# ---- fit -------------------------------------------------------------------------------------------------------

def read_pads(p):
    out = {}
    if p.exists():
        for l in p.read_text().splitlines():
            if l.strip() and not l.startswith('#'):
                n, b = l.split()
                out[n] = int(b)
    return out


def refit(par, A2, din, dout):
    """one round: per module, the first function off 2i's parity moves 2 bytes. Returns the modules changed."""
    dout.mkdir(parents=True, exist_ok=True)
    moved = set()
    for m, fs in par.items():
        if m == '__failed__' or not fs:
            continue
        pads = read_pads(din / (m[:-2] + '.txt'))
        for f, v in sorted(fs.items(), key=lambda t: t[1][0]):
            a2 = A2.get((m, f))
            if a2 is not None and (v[0] - a2) % 4:
                b = pads.get(f, 0)
                pads[f] = b - 2 if b >= 2 else b + 2
                moved.add(m)
                break
        pads = {k: b for k, b in pads.items() if b}
        q = dout / (m[:-2] + '.txt')
        if pads:
            q.write_text(''.join(f'{k} {b}\n' for k, b in pads.items()))
        elif q.exists():
            q.unlink()
    return moved


def units(on):
    return N.units({m: {f: v[:4] for f, v in fs.items()} for m, fs in on.items() if m != '__failed__'}, N.rows)


# ---- levels ----------------------------------------------------------------------------------------------------

CLASSES = ('near', 'near-moved', 'changed', 'er')


def levels(U, par):
    out = {}
    for (m, f), u in U.items():
        if u['cls'] not in CLASSES or u['parts'] != 1:
            continue
        if m not in par or f not in par[m]:
            out[(m, f)] = -1; continue
        x = N.LFn(par[m], f)
        y = N.i2(u['a2'], N.extent2(u['a2'], u['s2'], 2 * x.n))
        out[(m, f)] = N.level(x, y)
    return out


# ---- pairs -----------------------------------------------------------------------------------------------------

GLOB2 = {}          # 3s symbol -> 2i address (naming tables)
for r in csv.reader(open(ROOT / 'ghidra' / 'names' / 'globals.tsv'), delimiter='\t'):
    if r and not r[0].startswith('#') and len(r) > 5 and r[5]:
        GLOB2[r[5]] = int(r[0], 16)


def sx(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


class G3(N.LFn):
    """listing side: a relocated long gives ('G', symbol, addend)"""

    def val(self, t, size):
        k = (t - self.cbase) // 2
        if size == 4 and k in self.syms:
            m = re.fullmatch(r"(?:H'([0-9A-F]+)\+)?_?(\w+?)(?:\+H'([0-9A-F]+))?", self.syms[k])
            if m:
                return ('G', m.group(2), int(m.group(1) or m.group(3) or '0', 16))
        return super().val(t, size)


class I2(N.IFn):
    """2i side: an address in the pool gives ('G2', address)"""

    def val(self, t, size):
        k = (t - self.cbase) // 2
        if size == 4 and 0 <= k < len(self.ctx) - 1:
            a = self.ctx[k] << 16 | self.ctx[k + 1]
            if N.isaddr(a):
                return ('G2', a)
        return super().val(t, size)


class Sim:
    """registers as (base, offset): base None = a constant, ('G', sym) / ('G2',) = a global's address, else a
    fresh unknown"""

    def __init__(self):
        self.n = 0
        self.reset()

    def fresh(self):
        self.n += 1
        return (self.n, 0)

    def reset(self):
        self.r = [self.fresh() for _ in range(16)]

    def add(self, a, b):
        if a[0] is None:
            return (b[0], a[1] + b[1])
        if b[0] is None:
            return (a[0], a[1] + b[1])
        return self.fresh()

    def step(self, tok):
        """the token's accesses: [(kind, (base, offset), width)]"""
        acc, R = [], self.r
        if isinstance(tok, tuple):
            op = tok[0]
            if isinstance(op, int) and op >> 12 in (9, 0xD):
                n, v = (op >> 8) & 15, tok[1]
                if isinstance(v, int):
                    R[n] = (None, sx(v, 16) if op >> 12 == 9 else v)
                elif isinstance(v, tuple) and v[0] == 'G':
                    R[n] = (('G', v[1]), v[2]); acc.append(('addr', R[n], 0))
                elif isinstance(v, tuple) and v[0] == 'G2':
                    R[n] = (('G2',), v[1]); acc.append(('addr', R[n], 0))
                else:
                    R[n] = self.fresh()
            elif op == 0xC700:
                R[0] = self.fresh()
            return acc
        if tok == 'R':
            return acc
        w = tok
        t, n, m, d = w >> 12, (w >> 8) & 15, (w >> 4) & 15, w & 15
        W = {0: 1, 1: 2, 2: 4}
        if t == 0 and d in (4, 5, 6):
            acc.append(('st', self.add(R[0], R[n]), W[d - 4]))
        elif t == 0 and d in (0xC, 0xD, 0xE):
            acc.append(('ld', self.add(R[0], R[m]), W[d - 0xC]))
        elif t == 1:
            acc.append(('st', (R[n][0], R[n][1] + 4 * d), 4))
        elif t == 5:
            acc.append(('ld', (R[m][0], R[m][1] + 4 * d), 4))
        elif t == 8 and n in (0, 1, 4, 5):
            sz = 1 if n in (0, 4) else 2
            acc.append(('st' if n < 4 else 'ld', (R[m][0], R[m][1] + sz * d), sz))
        elif t == 2 and d in (0, 1, 2):
            acc.append(('st', R[n], W[d]))
        elif t == 2 and d in (4, 5, 6):
            R[n] = (R[n][0], R[n][1] - W[d - 4]); acc.append(('st', R[n], W[d - 4]))
            return acc
        elif t == 6 and d in (0, 1, 2):
            acc.append(('ld', R[m], W[d]))
        elif t == 6 and d in (4, 5, 6):
            acc.append(('ld', R[m], W[d - 4]))
            R[n] = self.fresh()
            if m != n:
                R[m] = (R[m][0], R[m][1] + W[d - 4])
            return acc
        if t == 0xE:
            R[n] = (None, sx(w & 0xFF, 8)); return acc
        if t == 6 and d == 3:
            R[n] = R[m]; return acc
        if t == 7:
            R[n] = (R[n][0], R[n][1] + sx(w & 0xFF, 8)); return acc
        if t == 3 and d == 0xC:
            R[n] = self.add(R[n], R[m]); return acc
        if t == 3 and d == 8 and R[m][0] is None:
            R[n] = (R[n][0], R[n][1] - R[m][1]); return acc
        if sh2.flow(w, 0)[0] in ('jsr', 'bsr', 'bsrf'):
            for i in range(8):
                R[i] = self.fresh()
        for i in sh2.dests(w):
            R[i] = self.fresh()
        return acc


def run(toks):
    """per token: its accesses. Registers are forgotten at branch targets and after an unconditional jump's slot."""
    s, out, pending = Sim(), [], False
    tg = {t[1] for t in toks if isinstance(t, tuple) and isinstance(t[0], int) and t[0] >> 12 in (8, 0xA)
          and isinstance(t[1], int)}
    for j, t in enumerate(toks):
        if j in tg:
            s.reset()
        out.append(s.step(t))
        if pending:
            s.reset(); pending = False
        if isinstance(t, int) and sh2.flow(t, 0)[0] in ('bra', 'jmp', 'rts', 'braf') or \
                isinstance(t, tuple) and isinstance(t[0], int) and t[0] >> 12 == 0xA:
            pending = True
    return out


def mask(t):
    """immediates, displacements and pool values masked"""
    if not isinstance(t, tuple):
        return N.absri(t)
    if isinstance(t[0], int) and t[0] >> 12 in (9, 0xD):
        return (t[0] & 0xF000, 'k' if isinstance(t[1], int) else 'a')
    return t


MEMBER = re.compile(r'(?:->|\.)\s*([A-Za-z_]\w*)')


def pairs(U, par, fields, srcdir, pre):
    F = collections.defaultdict(list)          # member name -> [(struct, path, offset, size)]
    for r in csv.DictReader(open(fields), delimiter='\t'):
        if r['path']:
            F[re.sub(r'\[0\]', '', r['path'].split('.')[-1])].append(
                (r['struct'], r['path'], int(r['offset']), int(r['size'])))
    srcs, votes, tally = {}, collections.defaultdict(collections.Counter), collections.Counter()
    accf = open(pre + '_acc.tsv', 'w')
    accf.write('module\tfunction\tline\tkind\twidth\to3\to2\tbase3\tcands\twidth2\n')
    for (m, f), u in sorted(U.items()):
        if u['cls'] not in ('near', 'near-moved', 'changed') or u['parts'] != 1 or m not in par or f not in par[m]:
            continue
        x = G3(par[m], f)
        y0 = N.i2(u['a2'], N.extent2(u['a2'], u['s2'], 2 * x.n))
        y = I2(y0.ctx, y0.cbase, y0.addr, y0.n, y0.code, y0.pad)
        t3, t2 = x.tokens(), y.tokens()
        lines = par[m][f][4]
        ln3 = [lines[k] if k < len(lines) else 0 for k in range(x.n) if x.code[k]]
        if m not in srcs:
            srcs[m] = (Path(srcdir) / m).read_text(errors='replace').splitlines()
        src = srcs[m]
        a3, a2 = run(t3), run(t2)
        sm = difflib.SequenceMatcher(None, [repr(mask(t)) for t in t3], [repr(mask(t)) for t in t2], autojunk=False)
        for tag, i1, i2_, j1, j2 in sm.get_opcodes():
            if tag not in ('equal', 'replace') or i2_ - i1 != j2 - j1:
                continue
            for q in range(i2_ - i1):
                A, B = a3[i1 + q], a2[j1 + q]
                if len(A) != len(B):
                    continue
                for (k3, (b3, o3), w3), (k2, (b2, o2), w2) in zip(A, B):
                    g3 = isinstance(b3, tuple) and b3[0] == 'G'
                    g2 = isinstance(b2, tuple) and b2[0] == 'G2'
                    if k3 != k2 or g3 != g2 or (b3 is None) != (b2 is None):
                        continue
                    if g3:
                        if b3[1] not in GLOB2:
                            continue
                        o2 -= GLOB2[b3[1]]
                    ln = ln3[i1 + q]
                    names = set()
                    for k in (ln - 1, ln - 2):
                        if 0 <= k < len(src):
                            names |= set(MEMBER.findall(src[k]))
                    cands = [c for nm in names for c in F.get(nm, ()) if c[2] <= o3 < c[2] + c[3]]
                    tally[bool(cands), o3 != o2] += 1
                    accf.write(f'{m}\t{f}\t{ln}\t{k3}\t{w3}\t{o3:#x}\t{o2:#x}\t{b3[1] if g3 else ""}\t'
                               f'{" ".join(f"{s}.{p}" for s, p, _, _ in cands[:6])}\t{w2}\n')
                    best = [c for c in cands if c[2] == o3] or cands
                    for c in best:
                        votes[c][o2 - o3] += 1.0 / len(best)
    accf.close()
    with open(pre + '_votes.tsv', 'w') as fo:
        fo.write('struct\tpath\to3\tsize\tshifts\n')
        for (st, path, off, size), c in sorted(votes.items(), key=lambda t: (t[0][0], t[0][2], t[0][1])):
            fo.write(f'{st}\t{path}\t{off:#x}\t{size}\t{" ".join(f"{s:+#x}:{n:.1f}" for s, n in c.most_common())}\n')
    print(f'accesses: attributed {tally[True, False] + tally[True, True]} ({tally[True, True]} moved), '
          f'unattributed {tally[False, False] + tally[False, True]} ({tally[False, True]} moved)')


# ---- main ------------------------------------------------------------------------------------------------------

def opt(args, name, rest=False):
    """remove --name and its value (all following arguments with rest) from args"""
    if name not in args:
        return None
    i = args.index(name)
    v = args[i + 1:] if rest else args[i + 1]
    del args[i:len(args) if rest else i + 2]
    return v


def main():
    cmd, args = sys.argv[1], sys.argv[2:]
    if cmd == 'list':
        only = opt(args, '--only', True); align = opt(args, '--align-dir')
        res = build(*args[:3], align=align, only=set(only) if only else None)
        pickle.dump(res, open(args[3], 'wb'))
        print(f'{args[3]}: {len(res) - 1} modules, {len(res["__failed__"])} failed')
    elif cmd == 'fit':
        on, T, BIN, W, out, din, dout = args[:7]
        A2 = {k: u['a2'] for k, u in units(pickle.load(open(on, 'rb'))).items() if u.get('a2')}
        din, dout = Path(din), Path(dout)
        par = build(T, BIN, W, align=din)
        cur, n = din, 0
        while True:
            nxt = dout.with_name(f'{dout.name}.{n}')
            moved = refit(par, A2, cur, nxt)
            if cur != din:
                for p in cur.glob('*.txt'): p.unlink()
                cur.rmdir()
            cur, n = nxt, n + 1
            if not moved:
                break
            part = build(T, BIN, W, align=cur, only=moved)
            par.update({k: v for k, v in part.items() if k != '__failed__'})
        if dout.exists():
            for p in dout.glob('*.txt'): p.unlink()
            dout.rmdir()
        cur.rename(dout)
        pickle.dump(par, open(out, 'wb'))
        print(f'{out}: {n} rounds, pads in {dout}, {len(par["__failed__"])} modules failed')
    elif cmd == 'levels':
        out = opt(args, '--out')
        U = units(pickle.load(open(args[0], 'rb')))
        L = levels(U, pickle.load(open(args[1], 'rb')))
        t = collections.Counter((U[k]['cls'], l) for k, l in L.items())
        print('class          n  lvl2  lvl1  lvl0')
        for c in CLASSES:
            n = sum(v for (cc, _), v in t.items() if cc == c)
            print(f'{c:10s} {n:5d} {t[c, 2]:5d} {t[c, 1]:5d} {t[c, 0]:5d}')
        if out:
            with open(out, 'w') as fo:
                for (m, f), l in sorted(L.items()):
                    fo.write(f'{m}\t{f}\t{U[(m, f)]["cls"]}\t{l}\n')
        if len(args) > 2:
            B = levels(U, pickle.load(open(args[2], 'rb')))
            up = sorted(k for k in L if L[k] > B.get(k, -1)); dn = sorted(k for k in L if L[k] < B.get(k, -1))
            print(f'up {len(up)} down {len(dn)}')
            for k in dn:
                print(f'  down {k[0]} {k[1]} {B[k]} -> {L[k]}')
    elif cmd == 'pairs':
        U = units(pickle.load(open(args[0], 'rb')))
        pairs(U, pickle.load(open(args[1], 'rb')), *args[2:5])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
