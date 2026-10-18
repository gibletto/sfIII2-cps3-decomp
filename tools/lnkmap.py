#!/usr/bin/env python3
"""Read a Hitachi lnk 6.0 map (FORM A, PRINT): the pieces each unit puts in each section, and the symbols.

    pieces(text) -> [(section, unit, start, end)]     end exclusive; empty pieces included
    symbols(text) -> {name: address}                  the externally defined symbols list (names with their _)
"""
import re

PIECE = re.compile(r"^(\w*)\s+H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})\s+H'([0-9A-F]{8})\s*$")
UNIT = re.compile(r"^\s+(\S+)\s+(\S+)\s*$")
SYM = re.compile(r"^(\S+)\s+H'([0-9A-F]{8})\s+(?:DAT|ENT|EQU)\s*$")


def pieces(text):
    out, sec, pend = [], None, None
    for l in text.splitlines():
        if l.startswith('* TOTAL ADDRESS'):
            pend = None
            continue
        m = PIECE.match(l)
        if m:
            if m.group(1):
                sec = m.group(1)
            pend = (sec, int(m.group(2), 16), int(m.group(4), 16))
            continue
        m = UNIT.match(l)
        if m and pend:
            s, a, n = pend
            out.append((s, m.group(1), a, a + n))
            pend = None
    return out


def symbols(text):
    out = {}
    on = False
    for l in text.splitlines():
        if 'EXTERNALLY DEFINED SYMBOLS LIST' in l:
            on = True
            continue
        if on:
            m = SYM.match(l)
            if m:
                out[m.group(1)] = int(m.group(2), 16)
    return out


if __name__ == '__main__':
    import sys
    t = open(sys.argv[1], errors='replace').read()
    for s, u, a, b in pieces(t):
        print(f'{s}\t{u}\t{a:08X}\t{b:08X}')
