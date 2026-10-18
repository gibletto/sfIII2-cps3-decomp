#!/usr/bin/env python3
"""Compile every C module of a 3rd Strike tree to an SHC listing under a set of rule settings and keep the
per-function words: the compiler side of rule-witness and 2nd Impact comparisons.

    python tools/shclist.py <tree sf3 dir> <bin dir> <work dir> <out.pkl> [NAME=VALUE ...] [--jobs N]
                            [--only m.c ...] [--base on.pkl] [--align-dir DIR]

NAME=VALUE are compiler settings (the rebuilt stages' rule switches); any such setting in the environment is
dropped first, so no setting means the arcade rules at their defaults. --align-dir: DIR/<module stem>.txt, when
present, is that module's SHC_ALIGN_FILE (a diagnostic shcasm build moves the named functions, as if the code
before them were longer: the way to compile a function at another address mod 4).

Writes {module: {function: (start, words, pool, syms)}}: words are halfwords (-1 for a relocated half), pool the
data flags, syms {halfword index: symbol} for relocated longs. With --base, only functions that differ from the
base build are kept (and modules whose listing failed are recorded under '__failed__').
"""
import os, re, sys, pickle, shutil, subprocess, threading, queue
from pathlib import Path

FUNC = re.compile(r"^\S*\s+([0-9A-F]{8})\s+_(\w+):\s")
SECTION_MARK = re.compile(r"^(\S+)\s+(?:[0-9A-F]{8}(?:\s|$)|; File\b)")
LINE = re.compile(r"^\s+([0-9A-F]{8})\s+([0-9A-F]{4}|<[0-9A-F]{8}>|[0-9A-F]{8})\s+(\S+)\s*(\S*)")


def parse(text):
    out, cur, in_p = {}, None, False
    for l in text.splitlines():
        if l.startswith('******** STATISTICS'):
            break
        mk = SECTION_MARK.match(l)
        if mk:
            in_p = mk.group(1) == 'P'
            if not in_p:
                cur = None
        m = FUNC.match(l)
        if m and in_p:
            cur = [int(m.group(1), 16), [], [], {}]
            out[m.group(2)] = cur
            continue
        if cur is None:
            continue
        m = LINE.match(l)
        if not m:
            continue
        v, mn, opd = m.group(2), m.group(3), m.group(4)
        words, pool, syms = cur[1], cur[2], cur[3]
        if mn.startswith('.RES'):
            n = int(v, 16) // 2
            words += [0] * n; pool += [True] * n
            continue
        isp = mn.startswith('.DATA')
        if not (isp or mn[:1].isalpha()):
            continue
        if v.startswith('<'):
            syms[len(words)] = opd
            words += [-1, -1]; pool += [True, True]
        elif len(v) == 8:
            words += [int(v[:4], 16), int(v[4:], 16)]; pool += [isp, isp]
        else:
            words.append(int(v, 16)); pool.append(isp)
    return {k: (v[0], v[1], v[2], v[3]) for k, v in out.items()}


ALIGN = None      # --align-dir: <module stem>.txt there is the module's SHC_ALIGN_FILE (diagnostic shcasm)


def modules(T):
    out = []
    for l in (T / 'build.bat').read_text().splitlines():
        if l.startswith('shc src\\'):
            p = l.split()
            out.append((p[1].split('\\')[-1], [o for o in p[2:] if not o.startswith('-object=')]))
    return out


def main():
    args = sys.argv[1:]
    jobs, only, base = 16, None, None
    if '--jobs' in args:
        i = args.index('--jobs'); jobs = int(args[i + 1]); del args[i:i + 2]
    if '--base' in args:
        i = args.index('--base'); base = pickle.load(open(args[i + 1], 'rb')); del args[i:i + 2]
    global ALIGN
    if '--align-dir' in args:
        i = args.index('--align-dir'); ALIGN = Path(args[i + 1]); del args[i:i + 2]
    if '--only' in args:
        i = args.index('--only'); only = set(args[i + 1:]); del args[i:]
    T, BIN, W, OUT = Path(args[0]).resolve(), Path(args[1]).resolve(), Path(args[2]), Path(args[3])
    env_set = dict(a.split('=', 1) for a in args[4:])
    mods = [m for m in modules(T) if only is None or m[0] in only]
    q = queue.Queue()
    for m in mods:
        q.put(m)
    res, lock = {}, threading.Lock()

    def worker(k):
        wd = W / f'w{k}'
        wd.mkdir(parents=True, exist_ok=True)
        for sub in ('src', 'include'):              # junctions into the tree; a work dir reused for another tree
            j = wd / sub                            # must not keep pointing at the old one
            if os.path.lexists(j) and os.path.normcase(os.path.realpath(j)) != os.path.normcase(str(T / sub)):
                os.rmdir(j)
            if not os.path.lexists(j):
                subprocess.run(['cmd', '/c', 'mklink', '/J', str(j), str(T / sub)], capture_output=True)
        (wd / 'o').mkdir(exist_ok=True); (wd / 't').mkdir(exist_ok=True)
        env = {k2: v for k2, v in os.environ.items() if not re.match(r'(GEN|MDL|PEP|ASM|SWITCH|XJUMP|SLOT|JNEXT|SHCGEN)_', k2)}
        env.update(SHC_LIB=str(BIN), SHC_TMP=str(wd / 't'), TMP=str(wd / 't'), TEMP=str(wd / 't'))
        env.update(env_set)
        env.pop('SHC_ALIGN_FILE', None)
        while True:
            try:
                mod, opts = q.get_nowait()
            except queue.Empty:
                return
            lst = wd / 'o' / 'm.lst'
            lst.unlink(missing_ok=True)
            al = ALIGN / (mod[:-2] + '.txt') if ALIGN else None
            if al and al.exists():
                env['SHC_ALIGN_FILE'] = str(al.resolve())
            else:
                env.pop('SHC_ALIGN_FILE', None)
            subprocess.run([str(BIN / 'shc.exe'), f'src/{mod}', *opts, '-listfile=o/m.lst', '-show=object',
                            '-object=o/m.obj'], cwd=wd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, env=env,
                           creationflags=0x00004000)
            r = parse(lst.read_text(errors='replace')) if lst.exists() else None
            with lock:
                res[mod] = r

    ts = [threading.Thread(target=worker, args=(k,)) for k in range(jobs)]
    for t in ts: t.start()
    for t in ts: t.join()
    failed = sorted(m for m, r in res.items() if r is None)
    if base is not None:
        out = {}
        for m, r in res.items():
            if r is None:
                continue
            b = base.get(m) or {}
            d = {f: v for f, v in r.items() if b.get(f) is None or b[f][1:3] != v[1:3]}
            if d:
                out[m] = d
        res = out
    res['__failed__'] = failed
    pickle.dump(res, open(OUT, 'wb'))
    print(f'{OUT.name}: {len(mods)} modules, {len(failed)} failed, {sum(len(v) for k, v in res.items() if k != "__failed__")} functions kept')


if __name__ == '__main__':
    main()
