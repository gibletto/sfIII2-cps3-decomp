#!/usr/bin/env python3
"""Compare the 2nd Impact tree's build with the 2nd Impact image: the whole image, every layout piece's placement
in the link map, and the bytes of every piece.

    python tools/verify2i.py [--tree sf2i] [--rom scratch/rom] [--all]

Prints the image verdict (identical or the number of differing bytes and the first differences), every piece the
link put somewhere other than its layout address, and every piece whose bytes differ (--all: also the matching
C, asm and lib pieces). Exit status 0 only when the image is byte-identical and every piece is where the layout
puts it.
"""
import argparse, hashlib, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import build2i, lnkmap

IMG = 0x06000000


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=str(build2i.ROOT / 'sf2i'))
    ap.add_argument('--rom', default=str(build2i.ROOT / 'scratch' / 'rom'))
    ap.add_argument('--all', action='store_true')
    a = ap.parse_args()
    return check(Path(a.tree).resolve(), Path(a.rom), a.all)


def check(T, romdir, show_all=False):
    ref = (romdir / 'prog.bin').read_bytes()
    out = (T / 'prog.bin').read_bytes() if (T / 'prog.bin').exists() else b''
    if len(out) != len(ref):
        print(f'prog.bin: {len(out):#x} bytes, the 2i image {len(ref):#x}')
        return 1
    rows = build2i.layout(T)
    mp = lnkmap.pieces((T / 'sf2i.map').read_text(errors='replace'))
    placed = {}
    for s, u, lo, hi in mp:
        if s != 'D':                                   # D's ROM copy; R is where the layout has it
            placed[(u, 'D' if s == 'R' else s)] = (lo, hi)
    misplaced = []
    for r in rows:
        got = placed.get((r['name'], r['section']))
        if got is None:
            misplaced.append(f"{r['name']} {r['section']}: not in the link map")
        elif got[0] != r['start'] or got[1] > r['end'] or (r['kind'] == 'blob' and got[1] != r['end']):
            misplaced.append(f"{r['name']} {r['section']}: linked {got[0]:08X}-{got[1]:08X}, "
                             f"layout {r['start']:08X}-{r['end']:08X}")
    nd = sum(1 for x, y in zip(out, ref) if x != y)
    same = out == ref
    print(f'image: {"byte-identical to" if same else f"{nd} bytes differ from"} the 2nd Impact image; '
          f'sha1 {hashlib.sha1(out).hexdigest()}')
    rom = lambda r, x: build2i.DROM + x - build2i.RAM if r['section'] == 'D' else x
    bad = 0
    for r in rows:
        if r['section'] == 'B':
            continue
        lo, hi = rom(r, r['start']) - IMG, rom(r, r['end']) - IMG
        d = sum(1 for o in range(lo, hi) if out[o] != ref[o])
        if d or (show_all and r['kind'] != 'blob'):
            first = next((o for o in range(lo, hi) if out[o] != ref[o]), None)
            print(f"  {r['name']:24} {r['section']:6} {r['start']:08X}-{r['end']:08X} {r['kind']:5} "
                  + (f'{d} bytes differ, first at {first + IMG:08X}' if d else 'identical'))
            bad += d > 0
    if not same:
        first = [o for o in range(len(out)) if out[o] != ref[o]][:8]
        print('  first differences: ' + ', '.join(f'{o + IMG:08X} ours {out[o]:02X} 2i {ref[o]:02X}' for o in first))
    for m in misplaced[:30]:
        print('  misplaced: ' + m)
    if len(misplaced) > 30:
        print(f'  ... {len(misplaced)} misplaced')
    return 0 if same and not misplaced else 1


if __name__ == '__main__':
    sys.exit(main())
