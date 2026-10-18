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

A program SIMM is four 2 MB chips, one byte lane each (the same layout as 3rd Strike's).
"""
import sys, zipfile
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


def main():
    a = sys.argv[1:]
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
