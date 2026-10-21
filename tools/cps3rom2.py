#!/usr/bin/env python3
"""Street Fighter III 2nd Impact (CPS3) program ROM tool.

    python tools/cps3rom2.py extract <sfiii2n.zip> <cg.bin>
        Read the two program SIMMs (sfiii2-simm1.*, sfiii2-simm2.*) from the ROM set and write the graphics
        pattern directory and patterns (06800000 up to 06DA767C), which the build does not compile.

    python tools/cps3rom2.py pack <sf2i.bin> <cg.bin> <sfiii2n.zip> <out dir> [sf2i.map]
        Put the patterns into the linked image, write <out dir>/prog.bin (06000000-06FFFFFF), compare it with the
        expected image (tools/prog.sha1), and write <out dir>/sfiii2n.zip: the ROM set with the two program SIMMs
        replaced by the new program. Exit status 0 when the image and every program chip are the original's.

A program SIMM is four 2 MB chips, one byte lane each. 2nd Impact stores its instructions encrypted with the CPS3
address mask (MAME's cps3_state::cps3_mask, keys 0, 0) and its data (tables, literal pools, the program header)
plain, chosen per halfword. pack works out which halfwords are instructions from the image itself: tools/codemap.py
follows the code from the vector table, the program header and every routine the link map names (sf2i.map), so a
changed program is packed correctly too; for the original program it gives the arcade's choice exactly.
"""
import hashlib, re, sys, zipfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import codemap

CHIP = 0x200000
SIMM = 4 * CHIP
BASE = 0x06000000
CG_START, CG_END = 0x06800000, 0x06DA767C
HERE = Path(__file__).resolve().parent


def rol16(v, n):
    v &= 0xFFFF
    return ((v << n) | (v >> (16 - n))) & 0xFFFF


def rotxor(val, x):
    res = (val + rol16(val, 2)) & 0xFFFF
    return (rol16(res, 4) ^ (res & (val ^ x))) & 0xFFFF


def mask(addr, key1=0, key2=0):
    addr ^= key1
    v = (addr & 0xFFFF) ^ 0xFFFF
    v = rotxor(v, key2 & 0xFFFF)
    v ^= ((addr >> 16) & 0xFFFF) ^ 0xFFFF
    v = rotxor(v, key2 >> 16)
    v ^= (addr & 0xFFFF) ^ (key2 & 0xFFFF)
    return (v | (v << 16)) & 0xFFFFFFFF


def stored(z):
    """06000000-06FFFFFF as stored on the two program SIMMs"""
    out = bytearray(2 * SIMM)
    for n in (1, 2):
        chips = [z.read(f"sfiii2-simm{n}.{i}") for i in range(4)]
        for c in range(4):
            out[(n - 1) * SIMM + c:n * SIMM:4] = chips[c]
    return out


def extract(rom, cg):
    with zipfile.ZipFile(rom) as z:
        img = stored(z)                          # the patterns are stored plain
    Path(cg).parent.mkdir(parents=True, exist_ok=True)
    Path(cg).write_bytes(img[CG_START - BASE:CG_END - BASE])
    print(f"{cg}: {CG_END - CG_START:#x} bytes of patterns")


def routines(mapfile):
    """the code addresses the link map names (entry symbols in the program's code range)"""
    out = set()
    for l in Path(mapfile).read_text(errors="replace").splitlines():
        m = re.match(r"\s*_\w+\s+H'(06[0-9A-F]{6})\s+ENT", l)
        if m:
            out.add(int(m.group(1), 16))
    return sorted(out)


def pack(linked, cg, rom, outdir, mapfile="sf2i.map"):
    prog = bytearray(Path(linked).read_bytes())
    if len(prog) != 2 * SIMM:
        sys.exit(f"{linked}: expected {2 * SIMM:#x} bytes")
    prog[CG_START - BASE:CG_END - BASE] = Path(cg).read_bytes()
    out = Path(outdir)
    out.mkdir(parents=True, exist_ok=True)
    (out / "prog.bin").write_bytes(prog)
    want = (HERE / "prog.sha1").read_text().split()[0]
    sha1 = hashlib.sha1(prog).hexdigest()
    ok = sha1 == want
    print(f"prog.bin sha1 {sha1}: " + ("matches" if ok else f"DIFFERS from expected {want}"))
    _, cls = codemap.classify(bytes(prog), routines(mapfile))
    st = bytearray(prog)
    n = 0
    for h, c in enumerate(cls):
        if c in codemap.ENCRYPTED:
            o = 2 * h
            m = mask(BASE + (o & ~3)) & 0xFFFF
            v = (prog[o] << 8 | prog[o + 1]) ^ m
            st[o], st[o + 1] = v >> 8, v & 0xFF
            n += 1
    print(f"{n} instruction halfwords encrypted")
    new = {}
    for k in (1, 2):
        flat = st[(k - 1) * SIMM:k * SIMM]
        for c in range(4):
            new[f"sfiii2-simm{k}.{c}"] = bytes(flat[c::4])
    with zipfile.ZipFile(rom) as src, zipfile.ZipFile(out / "sfiii2n.zip", "w", zipfile.ZIP_DEFLATED) as dst:
        for info in src.infolist():
            old = src.read(info.filename)
            data = new.get(info.filename, old)
            if info.filename in new:
                eq = data == old
                ok &= eq
                print(f"{info.filename}: {'identical' if eq else 'DIFFERS'} sha1 {hashlib.sha1(data).hexdigest()}")
            dst.writestr(info, data)
    print(f"{out / 'sfiii2n.zip'} written; program SIMMs " + ("identical to the original" if ok else "NOT the original"))
    return ok


def main():
    a = sys.argv[1:]
    if len(a) == 3 and a[0] == "extract":
        extract(a[1], a[2])
    elif len(a) in (5, 6) and a[0] == "pack":
        sys.exit(0 if pack(*a[1:]) else 1)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
