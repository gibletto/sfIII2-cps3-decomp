#!/usr/bin/env python3
"""Struct layouts of a tree's include/structs.h: every member path of every typedef'd struct or union, with its
offset and size, as SHC lays them out (SH-2: char 1, short 2, int/long/pointer/float 4, double 8; a member is
aligned to its type, a struct to its widest member, its size rounded up to that).

    python tools/structlayout.py <include dir> <out.tsv> [--check <shc bin dir> <work dir>]

out.tsv: struct, path, offset, size, type (paths like `wu.xyz[1].disp.pos`; an array gives one row for the whole
array and rows for its first element's members, `name[0]...`). --check compiles a C file with every top-level
member's `(int)&((T *)0)->m` and each struct's sizeof with SHC and compares them with the computed layout.
"""
import re, sys, subprocess, shutil, os
from pathlib import Path
from pycparser import c_parser, c_ast

PRIM = {'char': 1, 'short': 2, 'int': 4, 'long': 4, 'float': 4, 'double': 8, 'void': 1}


class Layout:
    def __init__(self, ast):
        self.typedefs, self.tags = {}, {}
        for e in ast.ext:
            if isinstance(e, c_ast.Typedef):
                self.typedefs[e.name] = e.type
            elif isinstance(e, c_ast.Decl) and isinstance(e.type, (c_ast.Struct, c_ast.Union)) and e.type.name:
                self.tags[e.type.name] = e.type
            if isinstance(e, c_ast.Typedef) and isinstance(e.type.type, (c_ast.Struct, c_ast.Union)) \
                    and e.type.type.name and e.type.type.decls is not None:
                self.tags[e.type.type.name] = e.type.type

    def resolve(self, t):
        """(kind, node): kind prim name, 'ptr', 'array', 'struct'"""
        if isinstance(t, c_ast.TypeDecl):
            return self.resolve(t.type)
        if isinstance(t, c_ast.PtrDecl):
            return 'ptr', t
        if isinstance(t, c_ast.ArrayDecl):
            return 'array', t
        if isinstance(t, (c_ast.Struct, c_ast.Union)):
            if t.decls is None:
                t = self.tags[t.name]
            return 'struct', t
        if isinstance(t, c_ast.IdentifierType):
            n = t.names
            if n[-1] in self.typedefs and len(n) == 1:
                return self.resolve(self.typedefs[n[0]])
            base = [x for x in n if x in PRIM]
            return base[-1] if base else 'int', t
        if isinstance(t, c_ast.Enum):
            return 'int', t
        if isinstance(t, c_ast.FuncDecl):
            return 'func', t
        raise TypeError(type(t))

    def size_align(self, t):
        k, n = self.resolve(t)
        if k in PRIM:
            s = PRIM[k]
            return s, min(s, 4)
        if k == 'ptr':
            return 4, 4
        if k == 'array':
            s, a = self.size_align(n.type)
            return s * int(n.dim.value, 0), a
        if k == 'struct':
            return self.struct_layout(n)[1:]
        return 4, 4

    def struct_layout(self, st):
        """([(name, offset, type node)], size, align)"""
        out, off, al, union = [], 0, 1, isinstance(st, c_ast.Union)
        bits = None                                         # (unit offset, unit size, bits used) of open bitfield
        for d in st.decls or []:
            s, a = self.size_align(d.type)
            if d.bitsize is not None:
                w = int(d.bitsize.value, 0)
                if bits and bits[1] == s and bits[2] + w <= 8 * s:
                    out.append((d.name, bits[0], d.type)); bits = (bits[0], s, bits[2] + w)
                    continue
                off = (off + a - 1) // a * a
                out.append((d.name, off, d.type)); bits = (off, s, w)
                off += s; al = max(al, a)
                continue
            bits = None
            if union:
                out.append((d.name, 0, d.type)); off = max(off, s)
            else:
                off = (off + a - 1) // a * a
                out.append((d.name, off, d.type)); off += s
            al = max(al, a)
        return out, (off + al - 1) // al * al, al

    def tname(self, t):
        k, n = self.resolve(t)
        if k == 'struct':
            return 'struct'
        if k == 'array':
            return self.tname(n.type) + f'[{n.dim.value}]'
        if k == 'ptr':
            return 'ptr'
        if isinstance(t, c_ast.TypeDecl) and isinstance(t.type, c_ast.IdentifierType):
            return ' '.join(t.type.names)
        return k

    def flatten(self, st, base=0, prefix=''):
        mem, _, _ = self.struct_layout(st)
        for name, o, t in mem:
            if name is None:
                continue
            p = prefix + name
            s, _ = self.size_align(t)
            yield p, base + o, s, self.tname(t)
            k, n = self.resolve(t)
            while k == 'array':
                p += '[0]'
                k, n = self.resolve(n.type)
                t = n
            if k == 'struct':
                yield from self.flatten(n, base + o, p + '.')


def parse(inc):
    cpp = shutil.which('cpp')
    src = subprocess.run([cpp, '-P', '-I', str(inc), str(Path(inc) / 'structs.h')], capture_output=True,
                         text=True, check=True).stdout
    return Layout(c_parser.CParser().parse(src))


def structs(L):
    """typedef name -> struct node, for typedef'd structs and unions"""
    out = {}
    for name, t in L.typedefs.items():
        if isinstance(t, c_ast.TypeDecl) and isinstance(t.type, (c_ast.Struct, c_ast.Union)):
            out[name] = L.resolve(t)[1]
    for tag, st in L.tags.items():
        out.setdefault('struct ' + tag, st)
    return out


def check(L, ss, inc, BIN, W):
    W = Path(W).resolve(); W.mkdir(parents=True, exist_ok=True)
    (W / 'inc').mkdir(exist_ok=True)                 # SHC takes no drive letter in -include
    for h in ('structs.h', 'types.h'):
        shutil.copy(Path(inc) / h, W / 'inc' / h)
    exprs = []
    for name, st in ss.items():
        exprs.append((name, '', f'sizeof({name})', L.struct_layout(st)[1]))
        for m, o, t in L.struct_layout(st)[0]:
            if m and not isinstance(st, c_ast.Union):
                exprs.append((name, m, f'(int)&(({name} *)0)->{m}', o))
    c = ['#include "structs.h"', 'const int chk[] = {'] + [f'    {e},' for _, _, e, _ in exprs] + ['};']
    (W / 'chk.c').write_text('\n'.join(c) + '\n')
    env = dict(os.environ, SHC_LIB=str(BIN), SHC_TMP=str(W), TMP=str(W), TEMP=str(W))
    subprocess.run([str(Path(BIN) / 'shc.exe'), 'chk.c', '-cpu=sh2', '-endian=big', '-include=inc',
                    '-listfile=chk.lst', '-show=object', '-object=chk.obj'], cwd=W, env=env,
                   capture_output=True)
    lst = (W / 'chk.lst').read_text(errors='replace')
    vals = [int(v, 16) for v in re.findall(r"H'([0-9A-F]{8})", lst[lst.index('_chk:'):lst.index('STATISTICS')])]
    if len(vals) != len(exprs):
        sys.exit(f'check: {len(vals)} values for {len(exprs)} expressions (see {W / "chk.lst"})')
    bad = [(n, m, v, want) for (n, m, _, want), v in zip(exprs, vals) if v != want]
    for n, m, v, want in bad:
        print(f'MISMATCH {n} {m or "sizeof"}: shc {v:#x}, computed {want:#x}')
    print(f'check: {len(exprs)} offsets and sizes, {len(bad)} mismatches')
    return not bad


def main():
    inc, out = Path(sys.argv[1]), Path(sys.argv[2])
    L = parse(inc)
    ss = structs(L)
    with open(out, 'w') as f:
        f.write('struct\tpath\toffset\tsize\ttype\n')
        for name, st in ss.items():
            f.write(f'{name}\t\t0\t{L.struct_layout(st)[1]}\t{"union" if isinstance(st, c_ast.Union) else "struct"}\n')
            for p, o, s, t in L.flatten(st):
                f.write(f'{name}\t{p}\t{o}\t{s}\t{t}\n')
    if '--check' in sys.argv:
        i = sys.argv.index('--check')
        sys.exit(0 if check(L, ss, inc.resolve(), Path(sys.argv[i + 1]).resolve(), sys.argv[i + 2]) else 1)


if __name__ == '__main__':
    main()
