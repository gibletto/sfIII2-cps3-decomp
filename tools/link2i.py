#!/usr/bin/env python3
"""Build one 3rd Strike C module with our SHC and link it at its 2nd Impact address; compare with the 2i image.

    python tools/link2i.py <3s sf3 tree> <module.c> <si2map dir> <work dir> [NAME=VALUE ...]

The module is compiled (the tree's bin/ or $LINK2I_BIN, its build.bat options, the arcade rules unless settings
say otherwise) to an object and a listing. Its P section goes where the census puts its first routine in 2i.
Relocated words are solved from 2i's own bytes: an external symbol gets the value 2i holds at the word (minus the
addend), a word that points into one of the module's own sections places that section. A symbol or section that
gets two different values, or a routine whose address disagrees with the census, is reported. The module is then
linked (lnk DEFINE for each symbol, START for each placed section), converted with rof2bin (fill $LINK2I_FILL,
default FF: 2i's alignment fill decrypts to FFFF) and compared byte for byte with 2i's program image over P and
every other section placed in ROM.
"""
import os, re, sys, csv, subprocess, shutil
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import shclist

B = 0x06000000
FILL = os.environ.get('LINK2I_FILL', 'FF')
SECSIZE = re.compile(r'(?:PROGRAM|CONSTANT|DATA|BSS)?\s*SECTION \((\w+)\):\s+([0-9A-F]+) Byte')
RELOC = re.compile(r"^\s+([0-9A-F]{8})\s+<[0-9A-F]{8}>\s+\.DATA\.L\s+(\S+)")


def relocs(text, names):
    """[(section, offset, symbol, addend)] for every relocated long in the listing"""
    out, sec = [], None
    for l in text.splitlines():
        if l.startswith('******** STATISTICS'):
            break
        mk = shclist.SECTION_MARK.match(l)
        if mk:
            sec = next((n for n in names if n == mk.group(1)), None) or \
                next((n for n in names if n.startswith(mk.group(1))), mk.group(1))
        m = RELOC.match(l)
        if m and sec:
            for i, opd in enumerate(m.group(2).split(',')):
                r = re.fullmatch(r"(?:H'([0-9A-F]+)\+)?(\w+)(?:\+H'([0-9A-F]+))?", opd)
                o = int(m.group(1), 16) + 4 * i
                if r:
                    out.append((sec, o, r.group(2), int(r.group(1) or r.group(3) or '0', 16)))
                else:
                    out.append((sec, o, opd, None))
    return out


def main():
    T, mod, MAP, W = Path(sys.argv[1]).resolve(), sys.argv[2], Path(sys.argv[3]), Path(sys.argv[4]).resolve()
    sets = dict(a.split('=', 1) for a in sys.argv[5:])
    opts = dict(shclist.modules(T))[mod]
    stem = mod[:-2]
    if W.exists():
        shutil.rmtree(W)
    (W / 't').mkdir(parents=True)
    for sub in ('src', 'include'):
        subprocess.run(['cmd', '/c', 'mklink', '/J', str(W / sub), str(T / sub)], capture_output=True)
    BIN = Path(os.environ.get('LINK2I_BIN') or T / 'bin')
    env = {k: v for k, v in os.environ.items() if not re.match(r'(GEN|MDL|PEP|ASM|SWITCH|XJUMP|SLOT|JNEXT|SHCGEN)_', k)}
    env.update(SHC_LIB=str(BIN), SHC_TMP=str(W / 't'), TMP=str(W / 't'), TEMP=str(W / 't'), **sets)
    census = {r['name']: r for r in csv.DictReader(open(MAP / 'census.tsv'), delimiter='\t')}
    img = (MAP / 'prog.bin').read_bytes()

    def rd(a):
        return int.from_bytes(img[a - B:a - B + 4], 'big')

    try:
        subprocess.run([str(BIN / 'shc.exe'), f'src/{mod}', *opts, f'-listfile={stem}.lst', '-show=object',
                        f'-object={stem}.obj'], cwd=W, env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        text = (W / f'{stem}.lst').read_text(errors='replace')
        fns = shclist.parse(text)
        sizes = {m.group(1): int(m.group(2), 16) for m in SECSIZE.finditer(text)}
        rel = relocs(text, list(sizes))
        first = min(fns, key=lambda f: fns[f][0])
        base = int(census[first]['addr2'], 16) - fns[first][0]
        bad, clash = [], []
        for f, v in fns.items():
            r = census.get(f)
            if r and r['addr2'] and int(r['addr2'], 16) != base + v[0]:
                bad.append(f'{f}: census {r["addr2"]}, module layout {base + v[0]:08X}')

        def link(place, defs, ram):
            sec = [s for s in place if s != 'P']
            start = f'P({base:08X})' + ''.join(f',{s}({place[s]:08X})' for s in sec)
            sub = ['ROM (D,R)' if ram else '', f'START {start}', f'INPUT {stem}.obj', *defs,
                   'OUTPUT m.abs', 'PRINT m.map', 'FORM A', 'EXIT']
            (W / 'm.sub').write_text('\n'.join(l for l in sub if l) + '\n')
            p = subprocess.run([str(BIN / 'lnk.exe'), '-SUBCOMMAND=m.sub'], cwd=W, env=env, capture_output=True,
                               text=True)
            mp = (W / 'm.map').read_text(errors='replace') if (W / 'm.map').exists() else ''
            secs = {m.group(1): (int(m.group(2), 16), int(m.group(3), 16)) for m in
                    re.finditer(r"^(\w+)\s+H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})", mp, re.M)}
            syms = {m.group(1): int(m.group(2), 16) for m in
                    re.finditer(r"^(_\w+)\s+H'([0-9A-F]{8})\s+\w+", mp, re.M)}
            return [l for l in (p.stdout + p.stderr).splitlines() if '**' in l], secs, syms

        def image(lo, n):
            (W / 'm.bin').unlink(missing_ok=True)
            subprocess.run([str(BIN / 'rof2bin.exe'), f'-s={lo:08X}', f'-e={lo + n:08X}', f'-v={FILL}', 'm.abs'],
                           cwd=W, env=env, capture_output=True)
            return (W / 'm.bin').read_bytes() if (W / 'm.bin').exists() else b''

        # pass 1: the module's other sections at placeholders, nothing defined
        ram = sizes.get('D', 0) > 0
        others = [s for s in sizes if s != 'P' and sizes[s]] + (['R'] if ram else [])
        hold = {s: 0x06F00000 + 0x10000 * k for k, s in enumerate(others)}
        msgs, secs, mine = link({'P': base, **hold}, [], ram)
        ours = {s: image(secs[s][0], secs[s][1] + 1 - secs[s][0]) for s in secs if secs[s][0] >> 24 == 6}

        def our_long(s, o):
            lo = secs[s][0]
            b = ours.get(s, b'')
            return int.from_bytes(b[o:o + 4], 'big') if o + 4 <= len(b) else None

        place, sym = {'P': base}, {}

        def solve(s, o, name, add, v2):
            v1 = our_long(s, o)
            inside = next((t for t, (lo, hi) in secs.items() if v1 is not None and lo <= v1 <= hi and t != 'P'), None)
            if name in mine or inside or (name.startswith('L') and name[1:].isdigit()):
                if inside is None:
                    return
                want = v2 - (v1 - secs[inside][0])
                if inside in place and place[inside] != want:
                    clash.append(f'section {inside}: {place[inside]:08X} and {want:08X} ({name})')
                place.setdefault(inside, want)
            elif add is None:
                clash.append(f'{s}+{o:X}: operand {name}')
            else:
                if name in sym and sym[name] != v2 - add:
                    clash.append(f'{name}: {sym[name]:08X} and {v2 - add:08X}')
                sym.setdefault(name, v2 - add)

        for s, o, name, add in rel:
            if s == 'P':
                solve(s, o, name, add, rd(base + o))
        # relocations inside ROM sections placed by now (tables in C/CTBL)
        for s, o, name, add in rel:
            if s != 'P' and s in place and place[s] >> 24 == 6:
                solve(s, o, name, add, rd(place[s] + o))
        agree = disagree = 0
        for name, v in sym.items():
            r = census.get(name[1:])
            if r and r['addr2']:
                if int(r['addr2'], 16) == v: agree += 1
                elif r['class'] in ('changed', 'absent'):
                    print(f'  note: {name} solved {v:08X}; the census pins it ({r["class"]}) at {r["addr2"]}')
                else: disagree += 1; bad.append(f'{name}: solved {v:08X}, census {r["addr2"]}')
        for name, v in mine.items():
            if name[1:] in fns and name in sym and sym[name] != v:
                bad.append(f'{name}: links at {v:08X}, 2i refers to {sym[name]:08X}')
        unplaced = [s for s in others if s not in place]
        defs = [f'DEFINE {n}({v:08X})' for n, v in sorted(sym.items()) if n not in mine]
        msgs, secs, mine = link({**hold, **place}, defs, ram)
        comp = [('P', base, sizes['P'])] + [(s, place[s], sizes[s]) for s in others
                                            if s in place and place[s] >> 24 == 6 and s in sizes]
        diff = []
        for s, lo, n in comp:
            out = image(lo, n)
            ref = img[lo - B:lo + n - B]
            if len(out) < n:
                diff.append((s, lo, b'', b'')); continue
            diff += [(s, lo + o, out[o:o + 2], ref[o:o + 2]) for o in range(0, n, 2) if out[o:o + 2] != ref[o:o + 2]]
        # messages about sections that were not compared (D's ROM copy) do not count
        hard = [l for l in msgs if not re.search(r'UNDEFINED EXTERNAL SYMBOL', l)] + \
               [l for l in msgs if 'UNDEFINED' in l and not unplaced]
        print(f'{mod}: {len(fns)} functions, P {sizes["P"]} bytes at {base:08X}; '
              + ''.join(f'{s} ' + (f'{sizes[s]} bytes ' if s in sizes else '') + 'at '
                        + (f'{place[s]:08X}' if s in place else '?') + '; ' for s in others)
              + f'{len(sym)} symbols solved from 2i ({agree} routines agree with the census, {disagree} disagree), '
              f'{len(clash)} clashes; lnk {len(msgs)} messages; compared {"+".join(s for s, _, _ in comp)} '
              f'({sum(n for _, _, n in comp)} bytes): {len(diff)} halfwords differ from 2i')
        for l in bad + clash + msgs[:6]:
            print('  ' + l)
        for s, a, x, y in diff[:20]:
            print(f'  {s} {a:08X}: ours {x.hex()} 2i {y.hex()}')
        return 0 if not diff and not clash and not bad and not hard else 1
    finally:
        for sub in ('src', 'include'):
            subprocess.run(['cmd', '/c', 'rmdir', str(W / sub)], capture_output=True)


if __name__ == '__main__':
    sys.exit(main())
