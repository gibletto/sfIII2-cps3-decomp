#!/usr/bin/env python3
"""Build the 2nd Impact tree (sf2i/): write the blobs, compile, link, convert, compare (and pack).

    python tools/build2i.py [--tree sf2i] [--rom scratch/rom] [--jobs 6] [--all] [--only NAME ...] [--no-link]
                            [--pack sfiii2n.zip [--map scratch/si2map]]

Every piece of sf2i/layout.tsv is an object in the link (sf2i/sf2i.sub; both are written by tools/layout2i.py,
which is run again whenever a module comes in as source):
  c     src/<name>.c, compiled with SHC (units.txt gives the options, as in the 3rd Strike tree) to obj/
  asm   src/<name>.src, assembled to obj/
  lib   lib/<name>.src, assembled to obj/
  blob  build/blob/<name>.src, written here from the 2nd Impact image (<rom>/prog.bin, the logical image of
        tools/si2map.py) and assembled beside it: the piece's bytes as .DATA, with a label for every name of
        ghidra/names/functions.tsv and globals.tsv inside it, and for the names the source modules refer to that
        the tables do not have yet (layout2i.py's build/layout/externs.tsv). Blobs hold ROM bytes, so they are
        generated, never committed.
  data  a data unit of sf2i/data.tsv: data/<name>.c when the tree has one, else build/data/<name>.c, written here
        from the 2nd Impact image by tools/emit2i_data.py (typed tables, ROM content: generated, never committed)
Only out-of-date objects are rebuilt (--all: every one). The link goes to sf2i/sf2i.abs and sf2i.map, the image to
sf2i/prog.bin (06000000-06FFFFFF, fill FF: rof2bin -v=FF), which is then compared with the 2nd Impact image
(tools/verify2i.py). --pack also encrypts it into the ROM set, sf2i/build/rom/sfiii2n.zip (tools/cps3rom2.py
pack, with si2map's hmap.bin), and compares the program SIMMs with the given set's. The rebuilt compiler stages'
rule switches (GEN_*, MDL_*, PEP_*, ...) in the environment are passed on; none set means the arcade rules.
"""
import argparse, csv, os, re, shutil, subprocess, sys, zlib
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
# SHC wants a short path without '-'; one directory per tree, so builds in several worktrees at once don't share it
TMP = Path(os.environ.get('SF2I_TMP') or Path(os.environ.get('SystemDrive', 'C:') + os.sep) / 'shct_2i'
           / format(zlib.crc32(str(ROOT).lower().encode()), '08x'))
KNOBS = re.compile(r'(PEP|SWITCH|GEN|MDL|XJUMP|ASM|SLOT|JNEXT|SHCGEN)_')     # rebuilt stages' rule switches
FLAGS = {'speed': ['-optimize=1', '-speed'], 'nospeed': ['-optimize=1', '-nospeed'],
         'opt0': ['-optimize=0', '-nospeed'], 'speed_noinline': ['-optimize=1', '-speed', '-noinline'],
         'speed_consttbl': ['-optimize=1', '-speed', '-section=const=CTBL'],
         'speed_noinline_consttbl': ['-optimize=1', '-speed', '-noinline', '-section=const=CTBL']}
COMMON = ['-cpu=sh2', '-division=cpu', '-endian=big', '-pic=0', '-extra=m=8,a=8', '-nortnext']
RAM, DROM = 0x02000000, 0x06577330          # the D section's RAM address (R) and its ROM copy
# 2nd Impact was built by a slightly different revision of the arcade compiler: settings of the rebuilt stages
# that are off for 3rd Strike and on here (sf2i/README.TXT)
# (GEN_OR_LEFT_KEEP and GEN_STORE_ADDR_AVOID were retired 2026-10-20: they emulated 3s's `s8 Suicide[8]`; 2i's
# Suicide is a scalar, and with `extern s8 Suicide;` the build is byte-identical with both off)
REVISION = {'MDL_MUL_CONST': '15', 'XJUMP_2I': '62', 'MDL_IV_AUTOINC': '1', 'MDL_MOD_CONST': '3', 'MDL_IMM_REG': '127', 'MDL_EQ_CONST': '3', 'MDL_TEMP_EXPR': '1', 'MDL_GCSE': '26', 'GEN_STORE_RHS_INDEX': '1', 'GEN_LAST_IDX': '4', 'ASM_CALL_SLACK': '6', 'MDL_IV_START0': '6', 'MDL_IV_ADDR': '1', 'PEP_SWITCH_END': '1', 'MDL_IV': '31', 'MDL_IV_WEB_ORDER': '1'}
# ... and per unit option: at -optimize=0 the 2nd Impact compiler does not reuse a constant a register already holds
# for an add (GEN_NARROW_CONST off; sys_config_2 config_top_select `add #8,r4`; no other opt0 unit changes)
REVISION_BY_FLAGS = {'opt0': {'GEN_NARROW_CONST': '0'}}


def env_for(T, tmp, sets=None):
    """the compiler's environment: the tree's bin/, a private work dir, the arcade rules at their defaults plus
    2nd Impact's compiler revision (REVISION; switches in the caller's environment are passed on; sets
    overrides them)"""
    tmp.mkdir(parents=True, exist_ok=True)
    b = str(T / 'bin')
    env = {'SHC_LIB': b, 'SHC_TMP': str(tmp), 'TMP': str(tmp), 'TEMP': str(tmp),
           'SystemRoot': os.environ.get('SystemRoot', ''), 'PATH': f"{b};{os.environ.get('PATH', '')}"}
    env.update(REVISION)
    env.update({k: v for k, v in os.environ.items() if KNOBS.match(k)})
    env.update(sets or {})
    return env


def units(T):
    out = {}
    for l in (T / 'units.txt').read_text().splitlines():
        if l.strip() and not l.startswith(';'):
            n, fl = l.split()[:2]
            out[n] = fl
    return out


def layout(T):
    """[{name, section, start, end, kind}] in file order (start/end ints; D pieces in RAM addresses)"""
    rows = []
    for r in csv.DictReader((l for l in open(T / 'layout.tsv') if not l.startswith('#')), delimiter='\t'):
        r['start'], r['end'] = int(r['start'], 16), int(r['end'], 16)
        rows.append(r)
    return rows


def source(T, name, kind):
    if kind == 'data':                          # a data unit: hand-maintained in data/, else generated
        hand = T / 'data' / f'{name}.c'
        return hand if hand.exists() else T / 'build' / 'data' / f'{name}.c'
    if kind == 'asm' and (T / 'data' / f'{name}.src').exists():
        return T / 'data' / f'{name}.src'       # an assembler table (data/sections.src)
    return {'c': T / 'src' / f'{name}.c', 'asm': T / 'src' / f'{name}.src', 'lib': T / 'lib' / f'{name}.src',
            'blob': T / 'build' / 'blob' / f'{name}.src'}[kind]


def objpath(kind):
    """where an object goes, relative to the tree: a blob's next to its generated source, a data unit's in
    build/data"""
    return {'blob': 'build\\blob', 'data': 'build\\data'}.get(kind, 'obj')


def compile_one(T, src, obj, fl, tmp, listing=None, sets=None):
    """compile or assemble src (a path under T) to obj; returns (ok, messages)"""
    rs, ro = str(src.relative_to(T)), str(obj.relative_to(T))
    if src.suffix == '.c':
        cmd = [str(T / 'bin' / 'shc.exe'), rs, *COMMON, *FLAGS[fl], '-include=include', f'-object={ro}']
        if listing:
            cmd += [f'-listfile={listing.relative_to(T)}', '-show=object']
    else:
        cmd = [str(T / 'bin' / 'asmsh.exe'), rs, f'-object={ro}']
    obj.unlink(missing_ok=True)
    env = env_for(T, tmp, sets)
    for k, v in REVISION_BY_FLAGS.get(fl, {}).items():
        if k not in os.environ and not (sets and k in sets):
            env[k] = v
    p = subprocess.run(cmd, capture_output=True, text=True, env=env, cwd=str(T),
                       creationflags=0x00004000)            # BELOW_NORMAL_PRIORITY_CLASS
    out = p.stdout + p.stderr
    bad = p.returncode != 0 or not obj.exists() or '(E)' in out or '(F)' in out
    return not bad, out


def names(root=ROOT):
    """{address: [label, ...]} from the naming tables (functions, globals and their aliases)"""
    out = {}
    for f in ('functions.tsv', 'globals.tsv', 'aliases.tsv'):
        for l in open(root / 'ghidra' / 'names' / f, encoding='utf-8'):
            if l.startswith('#') or not l.strip():
                continue
            c = l.rstrip('\n').split('\t')
            out.setdefault(int(c[0], 16), []).append('_' + c[1])
    return out


def blob_source(piece, img, labels):
    """assembler text for one blob piece: its bytes from the 2i image (D: the ROM copy), labels at named addresses"""
    sec, lo, hi = piece['section'], piece['start'], piece['end']
    rom = (lambda a: DROM + a - RAM) if sec == 'D' else (lambda a: a)
    align = 4 if lo % 4 == 0 else 2
    out = [f'; {piece["name"]}: 2nd Impact {sec} {lo:08X}-{hi:08X}, generated by tools/build2i.py from the ROM',
           '          .CPU        SH2',
           f'          .SECTION    {sec},{"CODE" if sec == "P" else "DATA"},ALIGN={align}']
    marks = sorted(a for a in labels if lo <= a < hi)
    for a in marks:
        for n in labels[a]:
            out.append(f'          .EXPORT     {n}')
    cuts = marks + [hi]
    a = lo
    for nxt in cuts:
        if nxt > a:
            if sec == 'B':
                out.append(f'          .RES.B      {nxt - a}')
            else:
                b = img[rom(a) - 0x06000000:rom(nxt) - 0x06000000]
                i = 0
                while i < len(b):
                    x = a + i
                    if align == 4 and x % 4 == 0 and len(b) - i >= 4:
                        k = min((len(b) - i) // 4, 8) * 4
                        out.append('          .DATA.L     ' + ','.join(
                            f"H'{int.from_bytes(b[i + j:i + j + 4], 'big'):08X}" for j in range(0, k, 4)))
                    elif x % 2 == 0 and len(b) - i >= 2:
                        k = 2 if align == 4 else min((len(b) - i) // 2, 8) * 2
                        out.append('          .DATA.W     ' + ','.join(
                            f"H'{int.from_bytes(b[i + j:i + j + 2], 'big'):04X}" for j in range(0, k, 2)))
                    else:
                        k = 1
                        out.append(f"          .DATA.B     H'{b[i]:02X}")
                    i += k
        if nxt < hi:
            out += [f'{n}:' for n in labels[nxt]]
        a = nxt
    out.append('          .END')
    return '\n'.join(out) + '\n'


def write_blobs(T, rows, img):
    labels = names()
    # names the source objects define (tools/layout2i.py lists them) are theirs, not a blob's
    defs = T / 'build' / 'layout' / 'defs.tsv'
    mine = {l.split('\t')[0] for l in open(defs)} if defs.exists() else set()
    # and so are the data units' objects (tools/emit2i_data.py)
    ddefs = T / 'build' / 'data' / 'defs.tsv'
    if ddefs.exists():
        mine |= {l.split('\t')[0] for l in open(ddefs)}
    labels = {a: [n for n in ls if n not in mine] for a, ls in labels.items()}
    # names the source objects refer to that the tables do not have yet: at the address 2i's code has for them
    # (tools/layout2i.py solves them from the relocated words and lists them for the tables)
    ext = T / 'build' / 'layout' / 'externs.tsv'
    if ext.exists():
        for l in list(open(ext))[1:]:
            sym, addr, st = l.split('\t')[:3]
            if st == 'missing' and sym not in mine:     # a data unit's object defines it
                a = int(addr, 16)
                if any(r['start'] <= a < r['end'] for r in rows if r['kind'] == 'blob'):
                    labels.setdefault(a, []).append(sym)
                else:
                    print(f'  {sym} ({a:08X}): no blob holds it, so no label')
    # the provisional labels the data units point at (tools/emit2i_data.py): in the blob that holds the address
    dl = T / 'build' / 'data' / 'labels.tsv'
    if dl.exists():
        for l in open(dl):
            sym, addr = l.split()[:2]
            a = int(addr, 16)
            if any(r['start'] <= a < r['end'] for r in rows if r['kind'] == 'blob'):
                labels.setdefault(a, []).append(sym)
            else:
                print(f'  {sym} ({a:08X}): a data unit points at it, but no blob holds it')
    labels = {a: ls for a, ls in labels.items() if ls}
    d = T / 'build' / 'blob'
    d.mkdir(parents=True, exist_ok=True)
    pieces = {}
    for r in rows:
        if r['kind'] == 'blob':
            pieces.setdefault(r['name'], []).append(r)
    n = 0
    for name, ps in pieces.items():
        text = ''.join(blob_source(p, img, labels) for p in ps)
        # one object may hold pieces in several sections: one .END at the end
        text = text.replace('          .END\n', '') + '          .END\n'
        f = d / f'{name}.src'
        if not f.exists() or f.read_text() != text:
            f.write_text(text)
            n += 1
    for f in list(d.glob('*.src')) + list(d.glob('*.obj')):
        if f.stem not in pieces:
            f.unlink()                          # a piece the layout no longer has (now source, or cut differently)
    return pieces, n


def link(T):
    p = subprocess.run([str(T / 'bin' / 'lnk.exe'), '-SUBCOMMAND=sf2i.sub'], capture_output=True, text=True,
                       env=env_for(T, TMP / 'lnk'), cwd=str(T))
    (T / 'link.log').write_text(p.stdout + p.stderr)
    return [l for l in (p.stdout + p.stderr).splitlines() if '**' in l]


def image(T):
    (T / 'prog.bin').unlink(missing_ok=True)
    p = subprocess.run([str(T / 'bin' / 'rof2bin.exe'), '-s=06000000', '-e=07000000', '-v=FF', 'sf2i.abs'],
                       capture_output=True, text=True, env=env_for(T, TMP / 'lnk'), cwd=str(T))
    (T / 'rof2bin.log').write_text(p.stdout + p.stderr)
    if (T / 'sf2i.bin').exists():
        shutil.move(T / 'sf2i.bin', T / 'prog.bin')
        return True
    return False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=str(ROOT / 'sf2i'))
    ap.add_argument('--rom', default=str(ROOT / 'scratch' / 'rom'), help='dir with prog.bin, the 2i logical image')
    ap.add_argument('--jobs', type=int, default=6)
    ap.add_argument('--only', nargs='*')
    ap.add_argument('--no-link', action='store_true')
    ap.add_argument('--all', action='store_true', help='compile every object, not only the out-of-date ones')
    ap.add_argument('--pack', metavar='sfiii2n.zip', help='also write the ROM set (tools/cps3rom2.py pack) to '
                    'sf2i/build/rom and compare its program SIMMs with this one')
    ap.add_argument('--map', default=str(ROOT / 'scratch' / 'si2map'), help="dir with si2map's hmap.bin (--pack)")
    a = ap.parse_args()
    T = Path(a.tree).resolve()
    img = (Path(a.rom) / 'prog.bin').read_bytes()
    rows = layout(T)
    fl = units(T)
    (T / 'obj').mkdir(exist_ok=True)
    if not a.no_link and not a.only:
        for f in ('prog.bin', 'sf2i.abs', 'sf2i.map'):
            (T / f).unlink(missing_ok=True)       # a failed build must not leave the last image to compare
    if any(r['kind'] == 'data' for r in rows):
        import emit2i_data
        emit2i_data.emit(argparse.Namespace(rom=a.rom))
    blobs, nb = write_blobs(T, rows, img)
    newest_header = max(h.stat().st_mtime for h in (T / 'include').iterdir())
    units_time = (T / 'units.txt').stat().st_mtime
    kinds = {}
    for r in rows:
        kinds.setdefault(r['name'], r['kind'])
    jobs = []
    for k, (name, kind) in enumerate(kinds.items()):
        if a.only and name not in a.only:
            continue
        src, obj = source(T, name, kind), T / objpath(kind) / f'{name}.obj'
        newer = src.stat().st_mtime if kind not in ('c', 'data') else max(src.stat().st_mtime, newest_header, units_time)
        if obj.exists() and obj.stat().st_mtime > newer and not a.all:
            continue
        jobs.append((src, obj, fl.get(name, 'speed')))
    fails = []
    with ThreadPoolExecutor(a.jobs) as ex:
        res = ex.map(lambda j: (j[0].name, *compile_one(T, j[0], j[1], j[2], TMP / f'w{j[0].stem}')), jobs)
        for name, ok, out in res:
            if not ok:
                fails.append((name, out))
    with open(T / 'compile_errors.txt', 'w') as f:
        for name, out in fails:
            f.write(f'==== {name}\n{out}\n')
    print(f'{nb} blob sources written; compiled {len(jobs)}, failed {len(fails)} (compile_errors.txt)')
    if fails or a.no_link or a.only:
        for name, out in fails[:5]:
            print(f'  {name}: ' + ' | '.join(l for l in out.splitlines() if '(E)' in l or '(F)' in l)[:300])
        return 1 if fails else 0
    errs = link(T)
    print(f'lnk: {len(errs)} messages (link.log)')
    for l in errs[:10]:
        print('  ' + l)
    if not (T / 'sf2i.abs').exists() or not image(T):
        print('BUILD FAILED')
        return 1
    print(f"prog.bin {(T / 'prog.bin').stat().st_size:#x} bytes")
    import verify2i
    bad = verify2i.check(T, Path(a.rom))
    if a.pack:
        import cps3rom2
        if not cps3rom2.pack(T / 'prog.bin', Path(a.map) / 'hmap.bin', a.pack, T / 'build' / 'rom'):
            bad = 1
    return 1 if errs or bad else 0


if __name__ == '__main__':
    sys.exit(main())
