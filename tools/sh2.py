#!/usr/bin/env python3
"""Minimal SH-2 (SH7604) instruction decoder: validity, control flow, PC-relative loads, written register.

Every function takes the 16-bit instruction word `w` and, where it matters, its address `pc`.
"""


def s8(x):
    return x - 0x100 if x & 0x80 else x


def s12(x):
    return x - 0x1000 if x & 0x800 else x


_OP4 = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0E,
        0x10, 0x11, 0x12, 0x13, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1E,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2E}


def valid(w):
    t, n, m, d = w >> 12, (w >> 8) & 15, (w >> 4) & 15, w & 15
    if t == 0:
        if d in (0, 1): return False
        if d == 2: return m <= 2
        if d == 3: return m in (0, 2)
        if d == 8: return n == 0 and m <= 2
        if d == 9: return (n == 0 and m <= 1) or m == 2
        if d == 0xA: return m <= 2
        if d == 0xB: return n == 0 and m <= 2
        return True
    if t == 2: return d != 3
    if t == 3: return d not in (1, 9)
    if t == 4: return d == 0xF or (w & 0xFF) in _OP4
    if t == 8: return n in (0, 1, 4, 5, 8, 9, 0xB, 0xD, 0xF)
    if t == 0xF: return False
    return True


def is_branch(w):
    """Instructions not allowed in a delay slot (anything that changes PC)."""
    return flow(w, 0)[0] is not None or w >> 8 == 0xC3


def flow(w, pc):
    """Control flow of an instruction: (kind, target).
    kind: None (falls through), 'cbr' (bt/bf), 'cbrs' (bt/s, bf/s), 'bra', 'bsr', 'bsrf', 'braf',
    'jsr', 'jmp', 'rts', 'rte'. target is the PC-relative destination when there is one."""
    t = w >> 12
    if t == 8:
        k = (w >> 8) & 15
        if k in (9, 0xB): return 'cbr', pc + 4 + s8(w & 0xFF) * 2
        if k in (0xD, 0xF): return 'cbrs', pc + 4 + s8(w & 0xFF) * 2
        return None, None
    if t == 0xA: return 'bra', pc + 4 + s12(w & 0xFFF) * 2
    if t == 0xB: return 'bsr', pc + 4 + s12(w & 0xFFF) * 2
    if t == 0:
        lo = w & 0xFF
        if lo == 0x03: return 'bsrf', None
        if lo == 0x23: return 'braf', None
        if w == 0x000B: return 'rts', None
        if w == 0x002B: return 'rte', None
        return None, None
    if t == 4:
        lo = w & 0xFF
        if lo == 0x0B: return 'jsr', None
        if lo == 0x2B: return 'jmp', None
    return None, None


DELAYED = {'cbrs', 'bra', 'bsr', 'bsrf', 'braf', 'jsr', 'jmp', 'rts', 'rte'}


def pcrel(w, pc):
    """PC-relative data reference: (address, size, kind) for mov.w/mov.l @(disp,PC) and mova, else None."""
    t = w >> 12
    if t == 9: return pc + 4 + (w & 0xFF) * 2, 2, 'w'
    if t == 0xD: return ((pc + 4) & ~3) + (w & 0xFF) * 4, 4, 'l'
    if w >> 8 == 0xC7: return ((pc + 4) & ~3) + (w & 0xFF) * 4, 0, 'a'
    return None


def dests(w):
    """Registers an instruction writes (roughly; enough to end a constant's life)."""
    t, n, m, d = w >> 12, (w >> 8) & 15, (w >> 4) & 15, w & 15
    if t == 0:
        if d in (2, 9, 0xA, 0xC, 0xD, 0xE) and not (d == 9 and m < 2): return (n,)
        if d == 0xF: return (n, m)
        return ()
    if t == 2:
        if d in (4, 5, 6, 9, 0xA, 0xB, 0xD): return (n,)
        return ()
    if t == 3:
        return (n,) if d in (4, 8, 0xA, 0xB, 0xC, 0xE, 0xF) else ()
    if t == 4:
        lo = w & 0xFF
        if d == 0xF: return (n, m)
        if lo in (0x0A, 0x0B, 0x0E, 0x1A, 0x1B, 0x1E, 0x2A, 0x2B, 0x2E, 0x11, 0x15): return ()
        return (n,)
    if t in (5, 7, 9, 0xD, 0xE): return (n,)
    if t == 6: return (n, m) if d in (4, 5, 6) else (n,)
    if t == 8: return (0,) if n in (4, 5) else ()
    if t == 0xC: return (0,) if n in (4, 5, 6, 7, 9, 0xA, 0xB) else ()
    return ()
