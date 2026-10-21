#!/usr/bin/env python3
"""Which halfwords of a CPS3 SH-2 program are instructions: a code walk over the program image.

    import codemap; cls = codemap.classify(image, entries)

The program is followed from the vector table, the program header at 06001000 and the given entry points, then from
every data word that points at an unexplored place in the code range and decodes there as clean code. Pools
(mov.w/mov.l @(disp,PC)), switch tables (mova + braf/jmp) and pool-based address tables are data. What is still
unreached is then swept: 0xFFFF fill (or one 0000/0009 before a 4-byte boundary) is padding, and a gap that explores
cleanly and scores as code is code nothing reaches. classify returns one class per halfword of the code range
(CLS); 2nd Impact stores the classes in ENCRYPTED (instructions, unreached instructions, padding) encrypted and the
rest plain. The image may be the arcade's or a new build's: with a build's link map as the entry points the walk
gives the arcade's classes exactly.
"""
import collections
import sh2

BASE = 0x06000000
UNK, CODE, POOL, TABLE, DEAD, PAD = range(6)
CLS = {UNK: 'unreached', CODE: 'code', POOL: 'pool', TABLE: 'table', DEAD: 'deadcode', PAD: 'pad'}
ENCRYPTED = (CODE, DEAD, PAD)


class Prog:
    def __init__(self, data, op):
        self.data, self.op = data, op
        self.end = int.from_bytes(data[0x1008:0x100C], 'big')          # code end from the program header
        self.n = (self.end - BASE) // 2
        self.cls = bytearray(self.n)
        self.entries = {}                                                 # address -> how found
        self.notes = []

    def inr(self, a):
        return BASE + 0x400 <= a < self.end and not a & 1

    def opw(self, a):
        o = a - BASE
        return self.op[o] << 8 | self.op[o + 1]

    def d32(self, a):
        o = a - BASE
        return int.from_bytes(self.data[o:o + 4], 'big')

    def d16(self, a):
        o = a - BASE
        return self.data[o] << 8 | self.data[o + 1]

    def explore(self, entry):
        """Follow one function from entry (branches, not calls) without committing. Returns
        (code, data, calls, problems): code = set of halfword addresses, data = {address: class},
        calls = {target: how}."""
        code, data, calls, probs = set(), {}, {}, []
        work = [entry]

        def mark_data(a, size, k):
            for x in range(a, a + size, 2):
                if not self.inr(x): probs.append(('pcrel out of range', x)); return
                if x in code or self.cls[(x - BASE) // 2] in (CODE, DEAD): probs.append(('data on code', x)); return
                if data.get(x) != TABLE: data[x] = k

        def back(run, i, reg, depth=16):
            """Last writer of reg before run[i] in this straight run: (address, word) or None."""
            for j in range(i - 1, max(-1, i - 1 - depth), -1):
                a = run[j]; w = self.opw(a)
                if reg in sh2.dests(w): return a, w
            return None

        def const(run, i, reg):
            r = back(run, i, reg)
            if r and r[1] >> 12 == 0xD:
                return self.d32(sh2.pcrel(r[1], r[0])[0])
            if r and r[1] >> 12 == 6 and r[1] & 15 == 3:              # mov rm,rn: one step back
                j = run.index(r[0]); r2 = back(run, j, (r[1] >> 4) & 15)
                if r2 and r2[1] >> 12 == 0xD: return self.d32(sh2.pcrel(r2[1], r2[0])[0])
            return None

        def switch(run, i, a, kind):
            """braf/jmp through a mova table, or jmp through a table of addresses whose base comes from the
            pool (mov.l @(r0,rm),rn; jmp @rn): returns list of targets or None."""
            mv = None
            for j in range(i - 1, max(-1, i - 10), -1):
                w = self.opw(run[j])
                if w >> 8 == 0xC7: mv = j; break
            if mv is None:
                r = back(run, i, (self.opw(a) >> 8) & 15)
                if kind != 'jmp' or not r or r[1] >> 12 != 0 or r[1] & 15 != 0xE: return None
                j = run.index(r[0]); tab = const(run, j, (r[1] >> 4) & 15)
                if tab is None or not self.inr(tab): return None
                tg = []
                for k in range(256):
                    ea = tab + 4 * k
                    if not self.inr(ea) or self.cls[(ea - BASE) // 2] in (CODE, DEAD) or ea in code: break
                    t = self.d32(ea)
                    if not self.inr(t): break
                    tg.append(t); data[ea] = data[ea + 2] = TABLE
                probs.append(('address table without bound', a))
                return tg
            tab = sh2.pcrel(self.opw(run[mv]), run[mv])[0]
            ld = None
            for j in range(mv + 1, i):
                w = self.opw(run[j])
                if w >> 12 == 0 and w & 15 in (0xC, 0xD, 0xE): ld = w & 15
            if ld is None: return None
            size = {0xC: 1, 0xD: 2, 0xE: 4}[ld]
            count = None
            for j in range(mv - 1, max(-1, mv - 12), -1):
                w = self.opw(run[j])
                if w >> 12 == 3 and (w >> 8) & 15 == 0 and w & 15 in (2, 6):    # cmp/hs or cmp/hi rm,r0
                    m = (w >> 4) & 15; r = back(run, j, m)
                    if r and r[1] >> 12 == 0xE:
                        imm = r[1] & 0xFF
                        count = imm + (1 if w & 15 == 6 else 0)
                    elif r and r[1] >> 12 == 9:
                        count = self.d16(sh2.pcrel(r[1], r[0])[0]) + (1 if w & 15 == 6 else 0)
                    break
            tg = []; lim = count if count is not None else 256
            for k in range(lim):
                ea = tab + k * size
                if count is None and tg and ea >= min(tg): break
                if size == 1:
                    v = self.data[ea - BASE]; v = v - 256 if v & 0x80 else v
                elif size == 2:
                    v = self.d16(ea); v = v - 0x10000 if v & 0x8000 else v
                else:
                    v = self.d32(ea)
                t = v if size == 4 else (a + 4 + v if kind == 'braf' else tab + v)
                if not self.inr(t):
                    if count is None: break
                    probs.append(('switch target out of range', ea)); continue
                tg.append(t)
                for x in range(ea & ~1, ea + size, 2): data[x] = TABLE
            if count is None: probs.append(('switch without bound', a))
            return tg

        while work:
            a = work.pop()
            run = []
            while True:
                if not self.inr(a): probs.append(('flow out of range', a)); break
                if a in code: break
                h = (a - BASE) // 2
                if self.cls[h] in (CODE, DEAD): break
                if self.cls[h] in (POOL, TABLE) or data.get(a) in (POOL, TABLE):
                    probs.append(('code on data', a)); break
                w = self.opw(a)
                if not sh2.valid(w): probs.append(('invalid', a)); break
                code.add(a); run.append(a)
                pr = sh2.pcrel(w, a)
                if pr and pr[2] != 'a': mark_data(pr[0], pr[1], POOL)
                k, t = sh2.flow(w, a)
                if k is None:
                    a += 2; continue
                if k in sh2.DELAYED:
                    s = a + 2; sw = self.opw(s) if self.inr(s) else 0xFFFF
                    if not self.inr(s) or not sh2.valid(sw) or sh2.is_branch(sw):
                        probs.append(('bad delay slot', s)); break
                    if self.cls[(s - BASE) // 2] in (POOL, TABLE) or data.get(s) in (POOL, TABLE):
                        probs.append(('code on data', s)); break
                    code.add(s); run.append(s)
                    sp = sh2.pcrel(sw, s)
                    if sp: probs.append(('pcrel in delay slot', s))
                    if sp and sp[2] != 'a': mark_data(sp[0], sp[1], POOL)
                i = len(run) - (2 if k in sh2.DELAYED else 1)
                if k == 'cbr':
                    work.append(t); a += 2; continue
                if k == 'cbrs':
                    work.append(t); a += 4; continue
                if k == 'bra':
                    work.append(t); break
                if k == 'bsr':
                    calls[t] = 'bsr'; a += 4; continue
                if k in ('jsr', 'jmp'):
                    v = const(run, i, (w >> 8) & 15)
                    if v is not None and self.inr(v):
                        calls[v] = k
                    elif k == 'jmp':
                        tg = switch(run, i, a, 'jmp')
                        if tg: work.extend(tg)
                        else: probs.append(('unresolved jmp', a))
                    if k == 'jsr': a += 4; continue
                    break
                if k == 'bsrf':
                    probs.append(('bsrf', a)); a += 4; continue
                if k == 'braf':
                    tg = switch(run, i, a, 'braf')
                    if tg: work.extend(tg)
                    else: probs.append(('unresolved braf', a))
                    break
                break                                                  # rts / rte
        return code, data, calls, probs

    def commit(self, code, data, k=CODE):
        for x in code: self.cls[(x - BASE) // 2] = k
        for x, k in data.items():
            h = (x - BASE) // 2
            if self.cls[h] == UNK or (self.cls[h] == POOL and k == TABLE): self.cls[h] = k

    def run(self, seeds, trial_kinds=('ptr',)):
        """seeds: list of (address, how). Seeds whose how is in trial_kinds must explore cleanly to be taken."""
        work = list(seeds); done = set(); fail = collections.Counter()
        while work:
            a, how = work.pop()
            if a in done or not self.inr(a): continue
            if self.cls[(a - BASE) // 2] == CODE:
                # already followed: a call target is a function start, a stray data word is not
                if how != 'ptr': self.entries.setdefault(a, how)
                done.add(a); continue
            code, data, calls, probs = self.explore(a)
            if how in trial_kinds and not self.plausible(code, probs):
                fail[how] += 1; continue
            done.add(a); self.entries.setdefault(a, how)
            for p in probs: self.notes.append((p[0], p[1], a))
            self.commit(code, data)
            for t, k in calls.items():
                if t not in done: work.append((t, k))
        return fail

    BAD = ('invalid', 'code on data', 'data on code', 'bad delay slot', 'flow out of range')

    def dataish(self, code):
        """Share of explored instruction halfwords whose stored (plain) value looks like data: plain data read
        through the opcode mask still decodes as instructions now and then, but its stored form gives it away."""
        n = 0
        for x in code:
            v = self.d16(x)
            if v >> 8 in (0x00, 0xFF, 0x02, 0x06, 0x04, 0x05, 0x0C): n += 1
        return n / len(code)

    def learn(self):
        """Value statistics of what the flow has classified so far: instruction words (opcode view) and data
        words (stored view). llr(a) > 0 says the halfword at a is more likely an encrypted instruction than
        plain data."""
        import math
        hc = [1] * 65536; hd = [1] * 65536
        for h in range(0x200, self.n):
            if self.cls[h] == CODE: hc[self.opw(BASE + 2 * h)] += 1
            elif self.cls[h] in (POOL, TABLE): hd[self.d16(BASE + 2 * h)] += 1
        tc, td = sum(hc), sum(hd)
        self.lc = [math.log(x / tc) for x in hc]; self.ld = [math.log(x / td) for x in hd]

    def llr(self, a):
        return self.lc[self.opw(a)] - self.ld[self.d16(a)]

    def plausible(self, code, probs):
        if not code or [p for p in probs if p[0] in self.BAD]: return False
        if getattr(self, 'lc', None): return sum(self.llr(x) for x in code) > 0
        return self.dataish(code) <= 0.4

    def sweep(self):
        """Unreached runs: 0xFFFF fill (op view), or one nop or zero before a 4-byte boundary, is alignment padding; a run whose op view explores cleanly from
        its start is code nothing reaches (dead, or called through a computed pointer)."""
        new = 0; h = 0
        while h < self.n:
            if self.cls[h] != UNK: h += 1; continue
            s = h
            while h < self.n and self.cls[h] == UNK and (self.opw(BASE + 2 * h) == 0xFFFF or
                                                         self.opw(BASE + 2 * h) in (0, 9) and h & 1):
                self.cls[h] = PAD; h += 1                              # fill, or a nop aligning what follows
            if h >= self.n or self.cls[h] != UNK: continue
            s = h
            while h < self.n and self.cls[h] == UNK: h += 1
            a = BASE + 2 * s
            if a < BASE + 0x400: continue
            code, data, calls, probs = self.explore(a)
            if not self.plausible(code, probs): continue
            self.entries.setdefault(a, 'unreached'); self.commit(code, data, DEAD); new += 1
            for p in probs: self.notes.append((p[0], p[1], a))
            h = s                                                      # the rest of this run next
        return new

    def pointer_seeds(self):
        """Data words (4-aligned, data view) in the first program SIMM pointing at unexplored code-range
        halfwords. Function tables lie well past the code (0657xxxx), so the whole SIMM is read."""
        top = 0x800000
        out = []
        for o in range(0x400, top, 4):
            if o < self.end - BASE and self.cls[o // 2] in ENCRYPTED: continue      # an instruction, not data
            v = int.from_bytes(self.data[o:o + 4], 'big')
            if self.inr(v) and self.cls[(v - BASE) // 2] == UNK: out.append((v, 'ptr'))
        return sorted(set(out), reverse=True)


def classify(data, entries, op=None, log=None):
    """the class of every halfword of the code range (a bytes object, values of CLS). data: the image as data reads
    see it; op: as instruction fetches see it (default data, for an image that is already decrypted); entries:
    addresses of routines (a link map's code symbols, or a functions table)."""
    P = Prog(data, op if op is not None else data)
    seeds = []
    for o in range(0, 0x200, 4):                                           # vector table
        v = P.d32(BASE + o)
        if P.inr(v):
            seeds.append((v, 'vector'))
    for o in range(0x1000, 0x1100, 4):                                     # program header
        v = P.d32(BASE + o)
        if P.inr(v):
            seeds.append((v, 'header'))
    seeds += [(a, 'match3s') for a in entries]
    say = log or (lambda s: None)
    say(f'seeds {dict(collections.Counter(h for _, h in seeds))}')
    fail = P.run(seeds[::-1], trial_kinds=('ptr', 'header', 'match3s'))
    say(f'after seeds: entries {len(P.entries)} failed {dict(fail)}')
    P.learn()
    for it in range(8):
        ps = P.pointer_seeds()
        n0 = len(P.entries)
        fail = P.run(ps)
        say(f'pointer pass {it}: candidates {len(ps)} new entries {len(P.entries) - n0} failed {dict(fail)}')
        if len(P.entries) == n0:
            break
    say(f'sweep: unreached code runs {P.sweep()}')
    say(str({CLS[k]: v * 2 for k, v in sorted(collections.Counter(P.cls).items())}))
    return P, bytes(P.cls)
