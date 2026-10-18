#!/usr/bin/env python3
"""Per-function match status of the 2nd Impact tree against the 2nd Impact program (the ideas of the 3rd Strike
tree's match_status.py): sf2i/build/status.tsv and a summary.

    python tools/status2i.py [--tree sf2i] [--rom scratch/rom] [--map scratch/si2map] [--out FILE] [--jobs 6]

The 2i functions are si2map's funcs.tsv entries, the naming tables' functions and the census's placements in the
code range (06000400-060FC564); each runs to the next. Their names come from functions.tsv (else the census, else
FUN_<address>). Every C module is compiled to a listing (the tree's bin/ and units.txt options, in a work dir of
its own) and each function of the listing is compared with the 2i image (<rom>/prog.bin, the logical image) at
the address the layout gives it (the module's P address plus the function's offset):

  byte_exact   every word equal, pool data and displacements included (relocated words, which the linker
               fills in, match anything)
  insn_exact   the instruction words equal with PC-relative displacements masked, pool words left out on both
               sides (2i's from si2map's hmap.bin), and every branch inside the routine landing on the same
               instruction: the function's code is right, only its literal pool may sit elsewhere
  similarity   share of both sides' normalised instruction words that align (difflib), 0..100

asm and lib functions are compared in the linked image (sf2i/prog.bin) over their 2i extent; blob functions are
listed as blob (their bytes are 2i's by construction). Columns: address, name, kind, object, size, byte_exact,
insn_exact, similarity, class (functions.tsv).
"""
import argparse, csv, difflib, os, re, subprocess, sys, threading, queue
from collections import Counter
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import build2i, shclist

IMG = 0x06000000
CODE_CLS = (1, 4)                     # tools/si2map.py: code, deadcode
FILL = -2                             # a reserved halfword in a listing: the link's fill, FFFF


def norm(w):
    """an instruction word with its PC-relative displacement masked (mov.w/mov.l @(disp,PC), bra/bsr, bt/bf/mova)"""
    top = w >> 12
    if top in (0x9, 0xD):
        return w & 0xFF00
    if top in (0xA, 0xB):
        return w & 0xF000
    if (w & 0xFF00) in (0xC700, 0x8900, 0x8B00, 0x8D00, 0x8F00):
        return w & 0xFF00
    return w


def branches(ins):
    """{index: target index} for the PC-relative branches of an instruction list [(address, word)]"""
    at = {a: i for i, (a, w) in enumerate(ins)}
    out = {}
    for i, (a, w) in enumerate(ins):
        if w >> 12 in (0xA, 0xB):
            d = w & 0xFFF
            d -= 0x1000 if d & 0x800 else 0
        elif (w & 0xFF00) in (0x8900, 0x8B00, 0x8D00, 0x8F00):
            d = w & 0xFF
            d -= 0x100 if d & 0x80 else 0
        else:
            continue
        out[i] = at.get(a + 4 + 2 * d, -1)
    return out


def listings(T, objs, jobs):
    """{object: shclist.parse result or None} for the C objects"""
    work = T / 'build' / 'status'
    fl = build2i.units(T)
    q = queue.Queue()
    for o in objs:
        q.put(o)
    res, lock = {}, threading.Lock()

    def worker(k):
        wd = work / f'w{k}'
        wd.mkdir(parents=True, exist_ok=True)
        for sub in ('src', 'include'):
            if not os.path.lexists(wd / sub):
                subprocess.run(['cmd', '/c', 'mklink', '/J', str(wd / sub), str(T / sub)], capture_output=True)
        env = build2i.env_for(T, wd / 't')
        while True:
            try:
                o = q.get_nowait()
            except queue.Empty:
                return
            lst = wd / f'{o}.lst'
            lst.unlink(missing_ok=True)
            subprocess.run([str(T / 'bin' / 'shc.exe'), f'src/{o}.c', *build2i.COMMON, *build2i.FLAGS[fl.get(o, 'speed')],
                            '-include=include', f'-listfile={o}.lst', '-show=object', f'-object={o}.obj'],
                           cwd=wd, env=env, capture_output=True, creationflags=0x00004000)
            r = shclist.parse(lst.read_text(errors='replace'), FILL) if lst.exists() else None
            with lock:
                res[o] = r

    ts = [threading.Thread(target=worker, args=(k,)) for k in range(jobs)]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=str(build2i.ROOT / 'sf2i'))
    ap.add_argument('--rom', default=str(build2i.ROOT / 'scratch' / 'rom'))
    ap.add_argument('--map', default=str(build2i.ROOT / 'scratch' / 'si2map'))
    ap.add_argument('--out')
    ap.add_argument('--jobs', type=int, default=6)
    a = ap.parse_args()
    T, M = Path(a.tree).resolve(), Path(a.map)
    ref = (Path(a.rom) / 'prog.bin').read_bytes()
    cls = (M / 'hmap.bin').read_bytes()
    ours = (T / 'prog.bin').read_bytes() if (T / 'prog.bin').exists() else b''
    rows = [r for r in build2i.layout(T) if r['section'] == 'P']
    plo, phi = 0x06000400, 0x060FC564
    names, klass = {}, {}
    for l in open(build2i.ROOT / 'ghidra' / 'names' / 'functions.tsv', encoding='utf-8'):
        if not l.startswith('#') and l.strip():
            c = l.rstrip('\n').split('\t')
            names[int(c[0], 16)], klass[int(c[0], 16)] = c[1], c[3]
    entries = {int(r['addr'], 16) for r in csv.DictReader(open(M / 'funcs.tsv'), delimiter='\t')}
    for r in csv.DictReader(open(M / 'census.tsv'), delimiter='\t'):
        if r['addr2']:
            entries.add(int(r['addr2'], 16))
            names.setdefault(int(r['addr2'], 16), r['name'])
    entries |= set(names)
    cobjs = sorted({r['name'] for r in rows if r['kind'] == 'c'})
    lst = listings(T, cobjs, a.jobs)
    # our functions by 2i address; in a C module they are the functions, a 2i entry inside one is a label in it
    ourf = {}
    for r in rows:
        if r['kind'] == 'c' and lst.get(r['name']):
            for fname, (off, words, pool, syms) in lst[r['name']].items():
                ourf[r['start'] + off] = (fname, words, pool)
    fns = sorted(e for e in entries | set(ourf) if plo <= e < phi)
    owner = {f: next((r for r in rows if r['start'] <= f < r['end']), None) for f in fns}
    ends = {}
    for i, f in enumerate(fns):
        r = owner[f]
        nxt = fns[i + 1:]
        if r and r['kind'] == 'c':
            nxt = [x for x in nxt if x in ourf]
        ends[f] = min(nxt[0] if nxt else phi, r['end'] if r else phi)

    def h(img, x):
        return img[x - IMG] << 8 | img[x - IMG + 1]

    out = []
    for f in fns:
        r = owner[f]
        kind = r['kind'] if r else 'none'
        n = ends[f] - f
        be = ie = sim = ''
        name = names.get(f, f'FUN_{f:08X}')
        if kind == 'c':
            mine = ourf.get(f)
            if mine is None:
                kind = 'c-label'                                        # an entry inside one of our functions
                n = 0
            else:
                fname, words, pool = mine
                if name.startswith('FUN_'):
                    name = fname
                be = 'yes' if all(w == -1 or (f + 2 * i < phi and (0xFFFF if w == FILL else w) == h(ref, f + 2 * i))
                                  for i, w in enumerate(words)) else 'no'
                oi = [(f + 2 * i, w) for i, w in enumerate(words) if not pool[i] and w >= 0]
                ai = [(x, h(ref, x)) for x in range(f, ends[f], 2) if cls[(x - IMG) // 2] in CODE_CLS]
                same = [norm(w) for _, w in oi] == [norm(w) for _, w in ai]
                ie = 'yes' if same and branches(oi) == branches(ai) else 'no'
                sm = difflib.SequenceMatcher(None, [norm(w) for _, w in oi], [norm(w) for _, w in ai], autojunk=False)
                sim = round(100 * 2 * sum(b.size for b in sm.get_matching_blocks()) / max(1, len(oi) + len(ai)))
                n = 2 * len(words)
        elif kind in ('asm', 'lib'):
            eq = ours[f - IMG:ends[f] - IMG] == ref[f - IMG:ends[f] - IMG] if ours else False
            be = ie = 'yes' if eq else 'no'
            sim = 100 if eq else ''
        out.append((f, name, kind, r['name'] if r else '', n, be, ie, sim, klass.get(f, '')))
    dst = Path(a.out) if a.out else T / 'build' / 'status.tsv'
    dst.parent.mkdir(parents=True, exist_ok=True)
    with open(dst, 'w', newline='\n') as fo:
        fo.write('address\tname\tkind\tobject\tsize\tbyte_exact\tinsn_exact\tsimilarity\tclass\n')
        for row in out:
            fo.write('\t'.join(f'{x:08X}' if i == 0 else str(x) for i, x in enumerate(row)) + '\n')
    c = Counter(r[2] for r in out)
    cb = sum(r[4] for r in out if r[2] in ('c', 'asm', 'lib'))
    print(f'{len(out)} 2i functions: ' + ', '.join(f'{k} {v}' for k, v in c.most_common()) + f' ({cb} bytes in source)')
    for k in ('c', 'asm', 'lib'):
        sel = [r for r in out if r[2] == k]
        if sel:
            print(f'  {k:4} byte-exact {sum(r[5] == "yes" for r in sel)}/{len(sel)}, '
                  f'insn-exact {sum(r[6] == "yes" for r in sel)}/{len(sel)}')
    bad = [r for r in out if r[2] in ('c', 'asm', 'lib') and r[5] != 'yes']
    for r in bad[:20]:
        print(f'  not byte-exact: {r[0]:08X} {r[1]} ({r[3]}) insn {r[6]} sim {r[7]}')
    failed = [o for o in cobjs if lst.get(o) is None]
    if failed:
        print('  listing failed: ' + ' '.join(failed))
    print(f'  {dst}')


if __name__ == '__main__':
    main()
