#!/usr/bin/env python3
"""Build the 2nd Impact program from your ROM set in one step (what build.bat runs).

    python tools/build_all.py [rom/sfiii2n.zip]

1. tools/cps3rom2.py extract: the program SIMMs of the ROM set, as stored and decrypted (build/rom/)
2. tools/si2map.py image, seeded with sf2i/functions.tsv: the program as the CPU sees it and which halfwords are
   stored encrypted (build/si2map/prog.bin, hmap.bin). The build reads its data tables from this image.
3. tools/build2i.py --all --pack: compile, link and compare (sf2i/prog.bin), then encrypt the program into a copy
   of the ROM set (sf2i/build/rom/sfiii2n.zip) and compare its program SIMMs with yours
4. copy both to build/prog.bin and build/sfiii2n.zip and check build/prog.bin against tools/prog.sha1

Exits 0 only when the program and its SIMMs are the arcade's.
"""
import hashlib, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PY = sys.executable


def run(*args):
    print('>', ' '.join(str(a) for a in args), flush=True)
    r = subprocess.run([PY, *map(str, args)], cwd=ROOT)
    return r.returncode


def main():
    rom = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / 'rom' / 'sfiii2n.zip'
    if not rom.exists():
        sys.exit(f'{rom}: put your sfiii2n.zip there (see rom/README)')
    rom = rom.resolve()
    B = ROOT / 'build'
    # layout2i.py's lists of the names the source objects define and refer to; it needs the 3rd Strike tree, so a
    # tree without one starts from the committed copies
    work = ROOT / 'sf2i' / 'build' / 'layout'
    work.mkdir(parents=True, exist_ok=True)
    for n in ('defs.tsv', 'externs.tsv'):
        if not (work / n).exists():
            shutil.copyfile(ROOT / 'sf2i' / 'layout' / n, work / n)
    if run('tools/cps3rom2.py', 'extract', rom, B / 'rom'):
        sys.exit('ROM extract failed')
    if run('tools/si2map.py', 'image', B / 'rom', B / 'si2map', ROOT / 'sf2i' / 'functions.tsv'):
        sys.exit('si2map failed')
    rc = run('tools/build2i.py', '--all', '--rom', B / 'si2map', '--map', B / 'si2map', '--pack', rom)
    prog = ROOT / 'sf2i' / 'prog.bin'
    packed = ROOT / 'sf2i' / 'build' / 'rom' / 'sfiii2n.zip'
    if not prog.exists():
        sys.exit('the build wrote no sf2i/prog.bin')
    shutil.copyfile(prog, B / 'prog.bin')
    if packed.exists():
        shutil.copyfile(packed, B / 'sfiii2n.zip')
    want = (ROOT / 'tools' / 'prog.sha1').read_text().split()[0]
    got = hashlib.sha1(prog.read_bytes()).hexdigest()
    ok = got == want and rc == 0 and packed.exists()
    print(f'build/prog.bin sha1 {got}: ' + ('the arcade program' if got == want else f'NOT the arcade program ({want})'))
    print('build/sfiii2n.zip: ' + ('your ROM set with the program SIMMs rebuilt' if packed.exists() else 'not written'))
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
