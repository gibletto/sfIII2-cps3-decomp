#!/usr/bin/env python3
"""Street Fighter III 2nd Impact (CPS3) program ROM reader.

    python tools/cps3rom2.py extract <sfiii2n.zip> <out dir>
        Read the two program SIMMs (sfiii2-simm1.*, sfiii2-simm2.*) and write two views of 06000000-06FFFFFF:
          <out dir>/prog_data.bin    the bytes as stored: what a data read sees
          <out dir>/prog_op.bin      every word decrypted with the CPS3 address mask (keys 0, 0): what an
                                     instruction fetch sees
        2nd Impact stores its instructions encrypted and its data (tables, literal pools, the program header)
        plain, so neither view alone is the program: code words come from prog_op.bin, data words from
        prog_data.bin. (3rd Strike encrypts both; there one decrypted image is the program.)

    python tools/cps3rom2.py pack <prog.bin> <hmap.bin> <sfiii2n.zip> <out dir>
        The reverse, for a built program: encrypt the instruction halfwords (hmap.bin, tools/si2map.py: classes
        code, deadcode and pad, 06000000 up to the code end; everything else is stored plain), split the image
        into the two program SIMMs' chips, compare each chip with the ROM set's and write <out dir>/sfiii2n.zip:
        the ROM set with the program SIMMs replaced. Exit status 0 when every chip equals the original.

A program SIMM is four 2 MB chips, one byte lane each (the same layout as 3rd Strike's).
"""
import hashlib, sys, zipfile
from pathlib import Path

CHIP = 0x200000
SIMM = 4 * CHIP


def rol16(v, n):
    v &= 0xFFFF
    return ((v << n) | (v >> (16 - n))) & 0xFFFF


def rotxor(val, x):
    res = (val + rol16(val, 2)) & 0xFFFF
    return (rol16(res, 4) ^ (res & (val ^ x))) & 0xFFFF


def mask(addr, key1, key2):
    addr ^= key1
    v = (addr & 0xFFFF) ^ 0xFFFF
    v = rotxor(v, key2 & 0xFFFF)
    v ^= ((addr >> 16) & 0xFFFF) ^ 0xFFFF
    v = rotxor(v, key2 >> 16)
    v ^= (addr & 0xFFFF) ^ (key2 & 0xFFFF)
    return (v | (v << 16)) & 0xFFFFFFFF


def read_simm(z, n, base, keys):
    chips = [z.read(f"sfiii2-simm{n}.{i}") for i in range(4)]
    out = bytearray(SIMM)
    for i in range(CHIP):
        w = chips[0][i] << 24 | chips[1][i] << 16 | chips[2][i] << 8 | chips[3][i]
        if keys is not None:
            w ^= mask(base + i * 4, *keys)
        out[i * 4:i * 4 + 4] = w.to_bytes(4, "big")
    return out


ENCRYPTED = (1, 4, 5)        # tools/si2map.py CLS: code, deadcode, pad


def pack(image, hmap, rom, outdir):
    prog = Path(image).read_bytes()
    cls = Path(hmap).read_bytes()
    if len(prog) != 2 * SIMM:
        sys.exit(f"{image}: expected {2 * SIMM:#x} bytes")
    stored = bytearray(prog)
    for h, c in enumerate(cls):
        if c in ENCRYPTED:
            o = 2 * h
            m = mask(0x06000000 + (o & ~3), 0, 0) & 0xFFFF
            v = (prog[o] << 8 | prog[o + 1]) ^ m
            stored[o], stored[o + 1] = v >> 8, v & 0xFF
    new = {}
    for n in (1, 2):
        flat = stored[(n - 1) * SIMM:n * SIMM]
        for c in range(4):
            new[f"sfiii2-simm{n}.{c}"] = bytes(flat[c::4])
    out = Path(outdir); out.mkdir(parents=True, exist_ok=True)
    same = True
    with zipfile.ZipFile(rom) as src, zipfile.ZipFile(out / "sfiii2n.zip", "w", zipfile.ZIP_DEFLATED) as dst:
        for info in src.infolist():
            old = src.read(info.filename)
            data = new.get(info.filename, old)
            if info.filename in new:
                eq = data == old
                same &= eq
                print(f"{info.filename}: {'identical' if eq else 'DIFFERS'} sha1 {hashlib.sha1(data).hexdigest()}")
            dst.writestr(info, data)
    print(f"{out / 'sfiii2n.zip'} written; program SIMMs " + ("identical to" if same else "differ from")
          + f" {rom}")
    return same


def main():
    a = sys.argv[1:]
    if len(a) == 5 and a[0] == "pack":
        sys.exit(0 if pack(*a[1:]) else 1)
    if len(a) < 3 or a[0] != "extract":
        sys.exit(__doc__)
    out = Path(a[2]); out.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(a[1]) as z:
        for name, keys in (("prog_data.bin", None), ("prog_op.bin", (0, 0))):
            prog = read_simm(z, 1, 0x06000000, keys) + read_simm(z, 2, 0x06800000, keys)
            (out / name).write_bytes(prog)
            print(f"{out / name}: {len(prog):#x} bytes")


if __name__ == "__main__":
    main()
