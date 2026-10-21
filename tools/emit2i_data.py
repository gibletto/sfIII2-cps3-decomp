#!/usr/bin/env python3
"""The 2nd Impact program data as typed C: plan the data layout, and write the C for it from the ROM.

    python tools/emit2i_data.py plan [--select refs|fighters|all|MODULE...] [--add] [--objects <si2data objects.tsv>]
    python tools/emit2i_data.py emit [--rom scratch/rom]

The data layout, sf2i/data.tsv (committed), lists the data units: each a C file of typed tables that covers one
stretch of CTBL, with its objects (name, 2i address, size, type, provenance). It holds addresses, names and types,
never ROM bytes. `plan` writes it from si2data's map of the 3rd Strike data objects onto 2i (objects.tsv: which 3s
object sits where in 2i, and how it compares), the 3s tree's declarations (the type of each 3s object: $SF3_TREE
data/*.c and src/*.c) and the naming tables; a unit is a run of 3s objects of one 3s module that lie back to back
in 2i inside a stretch the layout still has as blob. --add keeps the units already there and adds new ones.

`emit` writes each unit's C from the 2i image (<rom>/prog.bin) to sf2i/build/data/<unit>.c (generated at build
time, like the blobs: the files are ROM content and are never committed), unless sf2i/data/<unit>.c exists (a
hand-maintained unit, committed). Every pointer word becomes a symbol reference: a name of the naming tables, a
symbol of the last link (sf2i/sf2i.map), an object of the data layout, or, for an address none of them names, a
provisional label (dat_/fun_<address>) that tools/build2i.py puts in the blob there; those are listed in
sf2i/build/data/labels.tsv (and in scratch/si2dat/names_needed.tsv for the naming tables). Before writing,
`emit` gives every name the source modules refer to inside a data unit (layout2i's externs.tsv, no table row) an
object of its own there, by renaming, splitting or a gap object, and records it in data.tsv (adopt_externs).

Types (data.tsv `type`): u8 s8 u16 s16 u32 s32 char, optionally with inner dimensions (u16[4]); `u32p` (u32 words,
the ones in the program's address ranges written as (u32)symbol); `ptr:<pointee>` (an array of pointers,
`const u16 *const x[]`); `fptr` (routine pointers); or a struct typedef of sf2i/include (HIT_IX, ATTACK_BOX, ...).
"""
import argparse, csv, os, re, shutil, subprocess, sys
from collections import Counter, defaultdict
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import build2i, lnkmap

ROOT = build2i.ROOT
T = ROOT / 'sf2i'
DATA_TSV = T / 'data.tsv'
GEN = T / 'build' / 'data'
HAND = T / 'data'
IMG = 0x06000000
CTBL = (0x060FC564, 0x06577330)
P = (0x06000400, 0x060FC564)
RAM = (0x02000000, 0x0207410A)
SIMPLE = {'u8': (1, False), 's8': (1, True), 'char': (1, False), 'u16': (2, False), 's16': (2, True),
          'u32': (4, False), 's32': (4, True), 'u32p': (4, False)}
COLS = ['unit', 'name', 'addr', 'size', 'type', 'class', 'sf3_name', 'sf3_src', 'note']


# ---------------------------------------------------------------------------------------------- 3s declarations
DEF = re.compile(r'^(?:static\s+)?(?:const\s+)?(?P<type>[A-Za-z_]\w*)\s*(?P<ptr>(?:\*\s*(?:const\s*)?)*)'
                 r'(?P<name>[A-Za-z_]\w*)\s*(?P<dims>(?:\[[^\]]*\])*)\s*=')
FDEF = re.compile(r'^(?:static\s+)?(?:const\s+)?(?P<ret>\w+)\s*\(\s*\*\s*(?:const\s+)?(?P<name>\w+)\s*'
                  r'(?P<dims>(?:\[[^\]]*\])*)\s*\)\s*\([^)]*\)\s*=')


def decls3s(sf3):
    """{name: {'type': spec, 'dims': [inner dims], 'file': rel, 'line': n}} for the 3s tree's tables"""
    out = {}
    for d in ('data', 'src'):
        for f in sorted((sf3 / d).glob('*.c')):
            lines = f.read_text(errors='replace').splitlines()
            for i, l in enumerate(lines):
                m = FDEF.match(l)
                if m:
                    out.setdefault(m.group('name'), {'type': 'fptr', 'dims': [], 'file': f'{d}/{f.name}',
                                                     'line': i + 1})
                    continue
                m = DEF.match(l)
                if not m or m.group('type') in ('return', 'typedef', 'struct', 'union', 'enum'):
                    continue
                t, ptr, name = m.group('type'), m.group('ptr').replace(' ', ''), m.group('name')
                dims = re.findall(r'\[([^\]]*)\]', m.group('dims'))
                if ptr:
                    spec = f'ptr:const {t}' if not ptr.startswith('**') else 'ptr:const void'
                else:
                    spec = t
                    if t == 'u32' and l.rstrip().endswith('{'):
                        body = []
                        for l2 in lines[i + 1:i + 4000]:
                            if l2.startswith('};'):
                                break
                            body.append(l2)
                        if any('(u32)' in b for b in body):
                            spec = 'u32p'
                inner = [x for x in dims[1:]]
                out.setdefault(name, {'type': spec, 'dims': inner, 'file': f'{d}/{f.name}', 'line': i + 1})
    return out


# ---------------------------------------------------------------------------------------------- struct types
class Types:
    """the struct typedefs of sf2i/include (structs.h and the headers that define table types), laid out by
    tools/structlayout.py's rules"""

    def __init__(self, inc):
        import structlayout
        from pycparser import c_parser
        cpp = shutil.which('cpp')
        src = subprocess.run([cpp, '-P', '-I', str(inc), str(Path(inc) / 'structs.h')], capture_output=True,
                             text=True, check=True).stdout
        self.L = structlayout.Layout(c_parser.CParser().parse(src))
        self.ss = structlayout.structs(self.L)

    def known(self, name):
        return name in self.ss

    def size(self, name):
        return self.L.struct_layout(self.ss[name])[1]


def elem_size(spec, types):
    base, dims = split_spec(spec)
    n = 1
    for d in dims:
        n *= d
    if base in SIMPLE:
        return SIMPLE[base][0] * n
    if base.startswith('ptr:') or base == 'fptr':
        return 4 * n
    if types and types.known(base):
        return types.size(base) * n
    return None


def align(spec, types):
    base, _ = split_spec(spec)
    if base in SIMPLE:
        return SIMPLE[base][0]
    if base.startswith('ptr:') or base == 'fptr':
        return 4
    return types.L.struct_layout(types.ss[base])[2]


def split_spec(spec):
    m = re.match(r'^([^\[]+)((?:\[\d+\])*)$', spec)
    return m.group(1), [int(x) for x in re.findall(r'\[(\d+)\]', m.group(2))]


# ---------------------------------------------------------------------------------------------- names
def load_layout():
    rows = []
    if DATA_TSV.exists():
        for r in csv.DictReader((l for l in open(DATA_TSV, encoding='utf-8') if not l.startswith('#')),
                                delimiter='\t'):
            r['addr'], r['size'] = int(r['addr'], 16), int(r['size'])
            rows.append(r)
    return rows


def write_layout(rows):
    with open(DATA_TSV, 'w', newline='\n', encoding='utf-8') as f:
        f.write('# written by tools/emit2i_data.py plan, then kept by hand: the data units (C files of typed tables) '
                'and their objects, at their 2i addresses; no ROM bytes\n')
        f.write('\t'.join(COLS) + '\n')
        for r in sorted(rows, key=lambda r: r['addr']):
            f.write('\t'.join(f'{r[c]:08X}' if c == 'addr' else str(r[c]) for c in COLS) + '\n')


class Names:
    """address -> name, for pointer words: the naming tables, the last link's symbols, the data layout's objects"""

    def __init__(self, rows, pieces):
        self.at = {}                                      # address -> name
        self.kind = {}                                    # name -> 'fun' | 'data'
        self.src = {}                                     # name -> where the name comes from
        for f, kind in (('functions.tsv', 'fun'), ('globals.tsv', 'data'), ('aliases.tsv', None)):
            for l in open(ROOT / 'ghidra' / 'names' / f, encoding='utf-8'):
                if l.startswith('#') or not l.strip():
                    continue
                c = l.rstrip('\n').split('\t')
                a = int(c[0], 16)
                k = kind or self.kind.get(self.at.get(a), 'data')
                self.at.setdefault(a, c[1])
                self.kind.setdefault(c[1], k)
                self.src.setdefault(c[1], 'tables')
        mp = T / 'sf2i.map'
        if mp.exists():
            for s, a in lnkmap.symbols(mp.read_text(errors='replace')).items():
                n = s[1:]
                if not s.startswith('_') or n.startswith(('dat_', 'fun_')):
                    continue                              # our own provisional labels come back each time
                if a not in self.at:
                    self.at[a] = n
                    self.kind.setdefault(n, 'fun' if P[0] <= a < P[1] else 'data')
                    self.src.setdefault(n, 'link')
        # what the source objects define in this build (layout2i's defs.tsv): current even when the last link is older,
        # and the ground truth where it disagrees with a table row (a row naming another address the source defines
        # elsewhere would link a pointer to the wrong place, so that row's name is dropped at its address)
        dfs = T / 'build' / 'layout' / 'defs.tsv'
        if dfs.exists():
            defs = {}
            for l in open(dfs, encoding='utf-8'):
                c = l.rstrip('\n').split('\t')
                if len(c) >= 2 and c[0].startswith('_'):
                    defs[c[0][1:]] = int(c[1], 16)
            for a, n in list(self.at.items()):
                if n in defs and defs[n] != a:
                    del self.at[a]
            for n, a in defs.items():
                self.at[a] = n
                self.kind[n] = 'fun' if P[0] <= a < P[1] else 'data'
                self.src[n] = 'source'
        self.obj = []                                     # (addr, end, name) of the data layout
        for r in rows:
            self.at[r['addr']] = r['name']
            self.kind[r['name']] = 'data'
            self.src[r['name']] = 'layout'
            self.obj.append((r['addr'], r['addr'] + max(r['size'], 1), r['name']))
        self.obj.sort()
        self.defd = {r['name'] for r in rows}             # names a data row defines
        self.pieces = pieces                              # [(start, end, kind)] of sf2i/layout.tsv
        self.new = {}                                     # provisional labels: address -> name
        self.refby = defaultdict(set)                     # provisional label address -> the objects using it
        self.cur = None                                   # the object being written
        fm = ROOT / 'scratch' / 'si2map' / 'funcs.tsv'      # si2map's routine entries (named or not)
        self.funcs = {int(r['addr'], 16) for r in csv.DictReader(open(fm), delimiter='\t')} if fm.exists() else set()

    def known(self, v):
        return v in self.at or v in self.funcs

    def resolve(self, v):
        """(name, offset) for an address"""
        import bisect
        k = bisect.bisect_right(self.obj, (v, 0xFFFFFFFF, '')) - 1
        if v in self.at:
            # a naming-table name inside a data row that does not start there names nothing the link defines:
            # the row and an offset
            if not (k >= 0 and self.obj[k][0] < v < self.obj[k][1] and self.at[v] not in self.defd):
                return self.at[v], 0
            return self.obj[k][2], v - self.obj[k][0]
        if k >= 0 and self.obj[k][0] <= v < self.obj[k][1]:
            return self.obj[k][2], v - self.obj[k][0]
        if v in self.new:
            self.refby[v].add(self.cur)
            return self.new[v], 0
        # a provisional label, which the blob holding the address gets; else the nearest name below in its piece
        pc = next((p for p in self.pieces if p[0] <= v < p[1]), None)
        if pc is None or pc[2] == 'blob':
            n = ('fun_' if P[0] <= v < P[1] else 'dat_') + f'{v:08X}'
            self.new[v] = n
            self.refby[v].add(self.cur)
            self.kind[n] = 'fun' if P[0] <= v < P[1] else 'data'
            return n, 0
        below = max((a for a in self.at if pc[0] <= a <= v), default=None)
        if below is None:
            raise ValueError(f'{v:08X}: inside source piece {pc}, no name at or below it')
        return self.at[below], v - below


def isaddr(v):
    """an address something can be at: the program and its tables, the D image, the SIMM headers, the graphics,
    work RAM"""
    return (IMG <= v < 0x0657FA6C) or (0x067FFFE0 <= v < 0x06DA767C) or (0x06FFFFE0 <= v < 0x07000000) \
        or (RAM[0] <= v < RAM[1])


class Check:
    """a stand-in for Names that only checks that pointer words are addresses (plan's trial emission)"""
    kind = {}

    def resolve(self, v):
        if not isaddr(v):
            raise ValueError(f'pointer word {v:08X} is no address')
        return 'x', 0

    def known(self, v):
        return True


# ---------------------------------------------------------------------------------------------- emit
def fmt(v, signed, size):
    if signed and v >= 1 << (8 * size - 1):
        v -= 1 << (8 * size)
    if signed:
        return str(v)
    return str(v) if v < 10 else f'0x{v:X}'


def cstring(b):
    """a C string literal for bytes that are text then NULs, else None"""
    if 0 not in b:
        return None
    k = b.index(0)
    if any(b[k:]) or k == 0:
        return None
    s = b[:k]
    if not all(32 <= c < 127 or c in (10,) for c in s):
        return None
    return '"' + s.decode('ascii').replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n') + '"'


class Unit:
    def __init__(self, name, rows, img, names, types):
        self.name, self.rows, self.img, self.names, self.types = name, rows, img, names, types
        self.ext = {}                                     # referenced name -> declaration
        self.defined = {r['name'] for r in rows}
        self.decl = {r['name']: self.cdecl(r, '[]') for r in rows}

    def byte(self, a, n):
        return self.img[a - IMG:a - IMG + n]

    def word(self, a, n):
        return int.from_bytes(self.byte(a, n), 'big')

    def cdecl(self, r, dim):
        base, dims = split_spec(r['type'])
        inner = ''.join(f'[{d}]' for d in dims)
        if base == 'fptr':
            return f'void (*const {r["name"]}{dim}{inner})()'
        if base.startswith('ptr:'):
            return f'{base[4:]} *const {r["name"]}{dim}{inner}'
        return f'const {"u32" if base == "u32p" else base} {r["name"]}{dim}{inner}'

    def ref(self, v, cast):
        """C for the address v as `cast` (None: as it is)"""
        if v == 0:
            return '0'
        if not isaddr(v):
            raise ValueError(f'pointer word {v:08X} is no address')
        n, off = self.names.resolve(v)
        if n not in self.defined:
            self.ext[n] = (f'extern void {n}();' if self.names.kind.get(n) == 'fun'
                           else self.extern_decl(n))
        if off:
            e = f'(const u8 *){n} + {off}'
            return f'({cast})({e})' if cast else f'({e})'
        return f'({cast}){n}' if cast else n

    def extern_decl(self, n):
        return f'extern const u8 {n}[];'

    def scalar(self, a, base):
        size, signed = SIMPLE[base]
        v = self.word(a, size)
        # a u32 table mixes numbers and addresses: a word is an address in the tables, the D image or the
        # graphics; in code or work RAM only where something starts (a name, a routine entry)
        if base == 'u32p' and isaddr(v) and (CTBL[0] <= v < 0x06800000 + 0x5A767C or self.names.known(v)):
            return self.ref(v, 'u32')
        return fmt(v, signed, size)

    def value(self, a, spec, depth=0):
        """initializer text for one element of type spec at a"""
        base, dims = split_spec(spec)
        if dims:
            sub = base + ''.join(f'[{d}]' for d in dims[1:])
            es = elem_size(sub, self.types)
            return '{ ' + ', '.join(self.value(a + k * es, sub, depth + 1) for k in range(dims[0])) + ' }'
        if base in SIMPLE:
            return self.scalar(a, base)
        if base == 'fptr':
            return self.ref(self.word(a, 4), 'void (*)()')
        if base.startswith('ptr:'):
            return self.ref(self.word(a, 4), base[4:] + ' *')
        return self.struct(a, self.types.ss[base])

    def struct(self, a, st):
        from pycparser import c_ast
        L = self.types.L
        mem, size, _ = L.struct_layout(st)
        if isinstance(st, c_ast.Union):
            mem = mem[:1]
            if L.size_align(mem[0][2])[0] != size:
                raise ValueError('union whose first member is not its whole size')
        parts = []
        for name, o, t in mem:
            parts.append(self.tvalue(a + o, t))
        return '{ ' + ', '.join(parts) + ' }'

    def tvalue(self, a, t):
        L = self.types.L
        k, n = L.resolve(t)
        if k == 'array':
            cnt = int(n.dim.value, 0)
            es = L.size_align(n.type)[0]
            return '{ ' + ', '.join(self.tvalue(a + i * es, n.type) for i in range(cnt)) + ' }'
        if k == 'struct':
            return self.struct(a, n)
        if k == 'ptr':
            return self.ref(self.word(a, 4), 'void *')
        tn = L.tname(t)
        base = {'u8': 'u8', 's8': 's8', 'u16': 'u16', 's16': 's16', 'u32': 'u32', 's32': 's32', 'char': 'char',
                'unsigned char': 'u8', 'signed char': 's8', 'short': 's16', 'unsigned short': 'u16', 'int': 's32',
                'long': 's32', 'unsigned int': 'u32', 'unsigned long': 'u32'}.get(tn)
        if base is None:
            raise ValueError(f'member type {tn}')
        return self.scalar(a, base)

    def object(self, r):
        self.names.cur = f'{self.name}:{r["name"]}'
        base, dims = split_spec(r['type'])
        es = elem_size(r['type'], self.types)
        n = r['size'] // es
        prov = r['class'] + (f': 3s {r["sf3_name"]}' if r['sf3_name'] else '') + \
            (f' ({r["sf3_src"]})' if r['sf3_src'] else '') + (f'; {r["note"]}' if r['note'] else '')
        head = f'/* {r["addr"]:08X}  {prov} */'
        if base == 'char' and not dims:
            s = cstring(self.byte(r['addr'], n))
            if s is not None:
                return f'{head}\n{self.cdecl(r, f"[{n}]")} = {s};\n'
        if r.get('scalar'):
            return f'{head}\n{self.cdecl(r, "")} = {self.value(r["addr"], r["type"])};\n'
        per = {1: 16, 2: 8, 4: 4}.get(es, 1) if base in SIMPLE and not dims else 1
        items = [self.value(r['addr'] + k * es, r['type']) for k in range(n)]
        lines = []
        for k in range(0, n, per):
            lines.append('    ' + ', '.join(items[k:k + per]) + ',')
        return f'{head}\n{self.cdecl(r, f"[{n}]")} = {{\n' + '\n'.join(lines) + '\n};\n'

    def text(self):
        body = [self.object(r) for r in self.rows]
        lo, hi = self.rows[0]['addr'], self.rows[-1]['addr'] + self.rows[-1]['size']
        out = [f'/*\n * {self.name.upper()}.C  2nd Impact tables, CTBL {lo:08X}-{hi:08X}',
               ' *', ' * Generated by tools/emit2i_data.py from the 2nd Impact program image and sf2i/data.tsv.',
               ' */', '', '#include "types.h"', '#include "structs.h"', '', '#pragma section TBL', '']
        # the unit's own objects first (in address order: SHC keeps definition order), then what it refers to
        out += [f'extern {self.decl[r["name"]]};' for r in self.rows]
        out += sorted(self.ext.values())
        out.append('')
        out += body
        return '\n'.join(out)


def units_of(rows):
    us = defaultdict(list)
    for r in rows:
        us[r['unit']].append(r)
    for u in us.values():
        u.sort(key=lambda r: r['addr'])
    return us


SRC_NOTE = 'named by the source that refers to it'


def adopt_externs(rows, types):
    """the names the source modules refer to at addresses inside the data units (tools/layout2i.py's
    build/layout/externs.tsv, `missing`: no naming-table row) name the data there: an object starting there is
    renamed when its name is provisional, one containing it is split at the element boundary, a gap gets an
    object of its own up to the next one; a data.tsv object holding the name at another address takes a
    provisional name. data.tsv is rewritten when anything changed. Returns the changes, for the report"""
    ext = T / 'build' / 'layout' / 'externs.tsv'
    if not ext.exists():
        return []
    want = {}
    for l in list(open(ext))[1:]:
        c = l.rstrip('\n').split('\t')
        if c[2] == 'missing':
            want.setdefault(c[0][1:], int(c[1], 16))
    span = {}
    for u, rs in units_of(rows).items():
        span[u] = (rs[0]['addr'], rs[-1]['addr'] + rs[-1]['size'])
    log = []
    for name, a in sorted(want.items(), key=lambda kv: kv[1]):
        if any(r['name'] == name and r['addr'] == a for r in rows):
            continue
        for r in rows:
            if r['name'] == name:                       # the source puts the name elsewhere
                r['name'] = f'{name}_{r["addr"]:08X}'
                r['note'] += ('; ' if r['note'] else '') + f'provisional name (the source puts {name} at {a:08X})'
                log.append(f'{name}: the object at {r["addr"]:08X} renamed {r["name"]}')
        unit = next((u for u, (lo, hi) in span.items() if lo <= a < hi), None)
        if unit is None:
            continue                                    # in a blob: tools/build2i.py labels it
        o = next((r for r in rows if r['unit'] == unit and r['addr'] <= a < r['addr'] + r['size']), None)
        add = {'unit': unit, 'name': name, 'addr': a, 'type': None, 'class': 'inferred', 'sf3_name': '',
               'sf3_src': '', 'note': SRC_NOTE}
        if o is not None and o['addr'] == a:
            if o['class'] != 'new' and 'provisional' not in o['note']:
                log.append(f'{name}: {a:08X} is {o["name"]} (not provisional): a second name, left alone')
                continue
            log.append(f'{name}: {o["name"]} renamed')
            o['name'], o['class'] = name, 'inferred'
            o['note'] = SRC_NOTE + (f'; was {o["note"]}' if o['note'] else '')
            continue
        if o is not None:
            es = elem_size(o['type'], types)
            off = a - o['addr']
            if off % es:
                log.append(f'{name}: {a:08X} is inside an element of {o["name"]} ({o["type"]}): left alone')
                continue
            add.update(type=o['type'], size=o['size'] - off)
            o['size'] = off
            log.append(f'{name}: split from {o["name"]} at +{off}')
        else:
            nxt = min([r['addr'] for r in rows if r['unit'] == unit and r['addr'] > a] + [span[unit][1]])
            n = nxt - a
            t = next(t for t in ('u32', 'u16', 'u8') if a % SIMPLE[t][0] == 0 and n % SIMPLE[t][0] == 0)
            add.update(type=t, size=n)
            log.append(f'{name}: a gap object of {n} bytes ({t})')
        rows.append(add)
    if log:
        rows.sort(key=lambda r: r['addr'])
        write_layout(rows)
    return log


def emit(args):
    img = (Path(args.rom) / 'prog.bin').read_bytes()
    rows = load_layout()
    types = Types(T / 'include')
    for m in adopt_externs(rows, types):
        print('  data.tsv: ' + m)
    pieces = [(p['start'], p['end'], p['kind']) for p in build2i.layout(T) if p['section'] != 'D']
    names = Names(rows, pieces)
    GEN.mkdir(parents=True, exist_ok=True)
    n = 0
    us = units_of(rows)
    for u, rs in us.items():
        if (HAND / f'{u}.c').exists():
            continue
        text = Unit(u, rs, img, names, types).text()
        f = GEN / f'{u}.c'
        if not f.exists() or f.read_text() != text:
            f.write_text(text, newline='\n')
            n += 1
    for f in GEN.glob('*.c'):
        if f.stem not in us or (HAND / f.name).exists():
            f.unlink()
    with open(GEN / 'labels.tsv', 'w', newline='\n') as f:
        for a, nm in sorted(names.new.items()):
            f.write(f'_{nm}\t{a:08X}\t' + ' '.join(sorted(names.refby[a])) + '\n')
    with open(GEN / 'defs.tsv', 'w', newline='\n') as f:
        for r in rows:
            f.write(f'_{r["name"]}\t{r["addr"]:08X}\t{r["unit"]}\n')
    print(f'{len(us)} data units, {len(rows)} objects, {sum(r["size"] for r in rows)} bytes; {n} files written; '
          f'{len(names.new)} provisional labels')
    return names


def needs(args):
    """the names the data units need from the naming tables: the provisional labels their pointers use (after
    `emit`) and the objects with provisional names"""
    fm = Path(args.map) / 'funcs.tsv'
    funcs = {int(r['addr'], 16): r['how'] for r in csv.DictReader(open(fm), delimiter='\t')} if fm.exists() else {}
    out = []
    for l in open(GEN / 'labels.tsv'):
        n, a, refs = (l.rstrip('\n').split('\t') + [''])[:3]
        v = int(a, 16)
        kind = 'function' if n.startswith('_fun_') else 'data'
        ev = 'pointed at by ' + ', '.join(refs.split())
        if v in funcs:
            ev += f'; si2map funcs.tsv entry ({funcs[v]})'
        elif kind == 'function':
            kind = 'code label'
            ev += '; not a function entry in si2map funcs.tsv'
        out.append((n[1:], a, kind, ev))
    # the names the source modules refer to that the naming tables lack (layout2i's externs.tsv, `missing`) and a
    # data unit defines
    srcref = {}
    ext = T / 'build' / 'layout' / 'externs.tsv'
    if ext.exists():
        for l in list(open(ext))[1:]:
            c = l.rstrip('\n').split('\t')
            if c[2] == 'missing':
                srcref[(c[0][1:], int(c[1], 16))] = c[4]
    for r in load_layout():
        ref = srcref.get((r['name'], r['addr']))
        if ref is not None or r['note'].startswith(SRC_NOTE):
            ev = f'data unit {r["unit"]} ({r["type"]}, {r["size"]} bytes); referred to by ' + \
                (', '.join(ref.split()) if ref else 'the source modules') + ' (sf2i/build/layout/externs.tsv)'
            if r['sf3_name']:
                ev += f'; si2data placed 3s {r["sf3_name"]} ({r["class"]}, {r["sf3_src"]})'
            out.append((r['name'], f'{r["addr"]:08X}', 'data object (source)', ev))
        elif 'provisional' in r['note']:
            ev = f'data unit {r["unit"]} ({r["type"]}, {r["size"]} bytes)'
            if r['sf3_name']:
                ev += f'; si2data placed 3s {r["sf3_name"]} ({r["sf3_src"]}) here, the naming tables put that ' \
                      f'name elsewhere'
            else:
                ev += '; no 3s object placed here'
            out.append((r['name'], f'{r["addr"]:08X}', 'data object', ev))
    with open(args.out, 'w', newline='\n') as f:
        f.write('name\taddr2\tkind\tevidence\n')
        for row in sorted(out, key=lambda r: r[1]):
            f.write('\t'.join(row) + '\n')
    print(f'{len(out)} names needed -> {args.out}: '
          + ', '.join(f'{k} {n}' for k, n in Counter(r[2] for r in out).items()))


# ---------------------------------------------------------------------------------------------- plan
RANK = {'identical': 0, 'reloc': 1, 'changed': 2, 'resized': 3, 'relaid': 4,
        'absent_fighter': 9, 'absent_fighter(twin)': 9}
PROV = {'identical': '3s-exact', 'reloc': '3s-reloc', 'changed': '3s-near', 'resized': '3s-near',
        'relaid': 'inferred'}


def plan(args):
    sf3 = Path(args.sf3)
    img = (Path(args.rom) / 'prog.bin').read_bytes()
    types = Types(T / 'include')
    d3 = decls3s(sf3)
    keep = load_layout() if args.add else []
    taken = [(r['addr'], r['addr'] + r['size']) for r in keep]
    have_units = {r['unit'] for r in keep}
    # 2i stretches the layout still has as blob
    blobs = []
    for p in build2i.layout(T):
        if p['section'] == 'CTBL' and p['kind'] in ('blob', 'data'):
            if blobs and p['start'] - blobs[-1][1] <= 3:
                blobs[-1] = (blobs[-1][0], p['end'])
            else:
                blobs.append((p['start'], p['end']))
    tabname = {}
    for l in open(ROOT / 'ghidra' / 'names' / 'globals.tsv', encoding='utf-8'):
        if not l.startswith('#') and l.strip():
            c = l.split('\t')
            tabname[int(c[0], 16)] = c[1]
    # an address with a second name (aliases.tsv) stays in a blob: a C object has one name
    alias = set()
    for l in open(ROOT / 'ghidra' / 'names' / 'aliases.tsv', encoding='utf-8'):
        if not l.startswith('#') and l.strip():
            alias.add(int(l.split('\t')[0], 16))
    objs, size3 = [], {}
    for r in csv.DictReader(open(args.objects), delimiter='\t'):
        size3[r['name']] = int(r['size3'])
        if not r['addr2'] or r['class'] not in PROV:
            continue
        a = int(r['addr2'], 16)
        if not CTBL[0] <= a < CTBL[1]:
            continue
        objs.append(dict(r, a=a, n=int(r['span2'])))
    # one object per 2i address: the naming tables' name, else the best class
    by = defaultdict(list)
    for o in objs:
        by[o['a']].append(o)
    pick = []
    for a, os_ in by.items():
        os_.sort(key=lambda o: (o['name'] != tabname.get(a), RANK[o['class']], -o['n']))
        pick.append(os_[0])
    pick.sort(key=lambda o: o['a'])
    # drop objects that overlap the one before (keep the earlier)
    clean, end = [], 0
    for o in pick:
        if o['a'] < end:
            continue
        clean.append(o)
        end = o['a'] + o['n']
    # type each from its 3s declaration
    typed, why = [], Counter()

    def fits(a, n, spec):
        """a trial emission: every pointer the type has must hold an address"""
        es = elem_size(spec, types)
        try:
            tu = Unit('trial', [], img, Check(), types)
            for k in range(n // es):
                tu.value(a + k * es, spec)
        except (ValueError, KeyError):
            return False
        return True
    for o in clean:
        d = d3.get(o['name'])
        if d is None:
            why['no 3s declaration'] += 1
            continue
        base = d['type']
        if base not in SIMPLE and not base.startswith('ptr:') and base != 'fptr' and not types.known(base):
            why[f'type {base} unknown'] += 1
            continue
        try:
            dims = [int(x, 0) for x in d['dims']]
        except ValueError:
            why['inner dimension not a number'] += 1
            continue
        spec = base + ''.join(f'[{x}]' for x in dims)
        o['type'], o['decl'] = spec, d
        if not fits(o['a'], o['n'], spec):
            why['the 3s type does not fit (a pointer that is no address)'] += 1
            continue
        typed.append(o)
    # runs: same module, back to back, inside one blob stretch. An object's size is its 2i extent up to the next
    # object when that is whole elements (padding the 3s extent also counts), else its whole elements; what is
    # left before the next object must be zero bytes the compiler pads for the next one's alignment
    runs, cur = [], []

    def close():
        nonlocal cur
        if cur:
            runs.append(cur)
        cur = []
    for k, o in enumerate(typed):
        es = elem_size(o['type'], types)
        bl = next((b for b in blobs if b[0] <= o['a'] < b[1]), None)
        if bl is None or o['a'] + o['n'] > bl[1] or any(s < o['a'] + o['n'] and o['a'] < e for s, e in taken)                 or any(o['a'] <= x < o['a'] + o['n'] for x in alias):
            why['not in a blob stretch / already in a unit'] += 1
            close()
            continue
        o['bl'] = bl
        nxt = typed[k + 1]['a'] if k + 1 < len(typed) else o['a'] + o['n']
        ext = min(nxt - o['a'], o['n'] + 3)
        o['size'] = ext if ext % es == 0 else o['n'] - o['n'] % es
        if not o['size'] or any(img[o['a'] + o['size'] - IMG:o['a'] + o['n'] - IMG]):
            why['smaller than one element, or tail bytes not a whole element'] += 1
            close()
            continue
        if cur:
            p = cur[-1]
            pend = p['a'] + p['size']
            gap = o['a'] - pend
            # an alignment pad inside an object file is .RES, which the image has as FF: the object before
            # takes the pad bytes as elements of its own, or the run ends
            if p['module'] != o['module'] or p['bl'] != bl or gap < 0 or gap > 3 \
                    or gap % elem_size(p['type'], types) or not fits(pend, gap, p['type']):
                close()
            elif gap:
                p['size'] += gap
        cur.append(o)
    close()
    # a run starts on a 4-byte boundary and ends on one (the pieces around it are ALIGN=4)
    good = []
    for run in runs:
        while run and run[0]['a'] % 4:
            run.pop(0)
        while run and (run[-1]['a'] + run[-1]['size']) % 4:
            o = run[-1]
            e = o['a'] + o['size']
            pad = (4 - e % 4) % 4
            es = elem_size(o['type'], types)
            if pad % es == 0 and not any(img[e - IMG:e + pad - IMG]) and e + pad <= o['a'] + o['n'] + 3:
                nxt = e + pad
                if not any(s < nxt and e < s2 for s, s2 in taken):
                    o['size'] += pad
                    continue
            run.pop()
        if run:
            good.append(run)
    sel = args.select or ['refs']
    refs = set()
    ext = T / 'build' / 'layout' / 'externs.tsv'
    if ext.exists():
        for l in list(open(ext))[1:]:
            c = l.split('\t')
            refs.add(c[0][1:])
            refs.update(c[3].split(','))
    refs.discard('')

    def chosen(run):
        mods = {o['module'] for o in run}
        if 'all' in sel:
            return True
        if 'refs' in sel and any(o['name'] in refs for o in run):
            return True
        if 'fighters' in sel and any(re.match(r'^[a-z0-9]+_(hitbox|attbox|attr|move|char|yuca)$', m) for m in mods):
            return True
        return bool(mods & set(sel))
    # 2i data between two runs of one module (no 3s object placed there, or one that could not be typed) joins
    # them as objects of its own: cut at the naming tables' names, typed like the object before it (else the one
    # after it, u16, u8) when whole elements fit; never across a word that points at a known address unless the
    # neighbours hold pointers
    known = set(tabname) | {o['a'] for o in objs}
    for l in open(ROOT / 'ghidra' / 'names' / 'functions.tsv', encoding='utf-8'):
        if not l.startswith('#') and l.strip():
            known.add(int(l.split('\t')[0], 16))
    fm = Path(args.map) / 'funcs.tsv'
    if fm.exists():
        known |= {int(r['addr'], 16) for r in csv.DictReader(open(fm), delimiter='\t')}

    def has_ptr(a, b):
        """a word that may be an address: a known one, or anywhere in the code and the tables (2i data with no 3s
        type stays blob rather than hide an address as a number)"""
        for x in range(a + (-a) % 4, b - 3, 4):
            w = int.from_bytes(img[x - IMG:x + 4 - IMG], 'big')
            if w in known or P[0] <= w < 0x0657FA6C:
                return True
        return False

    def fillers(a, b, before, after, mod):
        if any(a <= x < b for x in alias):
            return None
        cuts = {a, b} | {x for x in tabname if a < x < b}
        # a named object ends where its 3s namesake does (the rest is 2i data of its own)
        cuts |= {x + size3[tabname[x]] for x in list(cuts) if x in tabname and tabname[x] in size3
                 and a < x + size3[tabname[x]] < b}
        cuts = sorted(cuts)
        out = []
        for s, e in zip(cuts, cuts[1:]):
            for t in dict.fromkeys((before, after, 'u16', 'u8')):
                es = elem_size(t, types)
                if (e - s) % es or s % align(t, types):
                    continue
                if t == 'u32p' or t == 'fptr' or t.startswith('ptr:'):
                    # a pointer type only where every word is an address (or 0)
                    if fits(s, e - s, 'ptr:const void' if t == 'u32p' else t):
                        break
                elif not has_ptr(s, e) and fits(s, e - s, t):
                    break
            else:
                return None
            out.append({'a': s, 'n': e - s, 'size': e - s, 'type': t, 'module': mod, 'name': tabname.get(s, ''),
                        'class': 'new', 'similarity': '', 'decl': None, 'bl': None})
        return out
    merged = []
    for run in good:
        if merged and merged[-1][-1]['module'] == run[0]['module'] and merged[-1][-1]['bl'] == run[0]['bl']:
            prev = merged[-1]
            pend = prev[-1]['a'] + prev[-1]['size']
            gap = run[0]['a'] - pend
            if 0 < gap <= args.max_gap:
                fill = fillers(pend, run[0]['a'], prev[-1]['type'], run[0]['type'], run[0]['module'])
                if fill:
                    prev.extend(fill + run)
                    why['gap filled'] += len(fill)
                    continue
                x = next((x for x in sorted(alias) if pend <= x < run[0]['a']), None)
                if x is not None:
                    # the aliased object stays blob; what is before it joins the run before, the rest this run
                    xe = min([t for t in tabname if x < t <= run[0]['a']] + [run[0]['a']])
                    f1 = fillers(pend, x, prev[-1]['type'], prev[-1]['type'], run[0]['module']) if x > pend else []
                    f2 = fillers(xe, run[0]['a'], run[0]['type'], run[0]['type'], run[0]['module']) \
                        if run[0]['a'] > xe else []
                    if f1 is not None and x % 4 == 0:
                        prev.extend(f1)
                        why['gap filled'] += len(f1)
                    if f2 is not None and xe % 4 == 0:
                        run[:0] = f2
                        why['gap filled'] += len(f2)
        if merged and merged[-1][-1]['bl'] == run[0]['bl'] and args.fill_between:
            # 2i data between two modules' runs (fonts, screen maps, sound data no 3s object was placed on):
            # objects of the run before, cut at the naming tables' names
            prev = merged[-1]
            pend = prev[-1]['a'] + prev[-1]['size']
            if 0 < run[0]['a'] - pend <= args.fill_between:
                fill = fillers(pend, run[0]['a'], prev[-1]['type'], prev[-1]['type'], prev[-1]['module'])
                if fill:
                    for f in fill:
                        f['between'] = True
                    prev.extend(fill)
                    why['filled between modules'] += len(fill)
        merged.append(run)
    good = merged
    # names: the naming tables' name at the address; a 3s name the tables give another address (or that the
    # layout already has) is provisional, with the address
    tabat = {}
    for a, n in tabname.items():
        tabat[n] = a
    used = {r['name'] for r in keep}
    for run in good:
        for o in run:
            n = tabname.get(o['a'], o['name'] or f'{o["module"]}_{o["a"]:08X}')
            if n in used or tabat.get(n, o['a']) != o['a']:
                n = f'{o["name"]}_{o["a"]:08X}'
            o['cname'] = n
            used.add(n)
    rows = list(keep)
    # a unit is named after its 3s module (data/<module>.c); the module's biggest run has the plain name
    picked = [run for run in good if chosen(run)]
    big = {}
    for run in picked:
        m = run[0]['module']
        sz = sum(o['size'] for o in run)
        if m not in have_units and sz > big.get(m, (0,))[0]:
            big[m] = (sz, run[0]['a'])
    code = {f.stem for f in (sf3 / 'src').glob('*.c')} | {p['name'] for p in build2i.layout(T) if p['section'] == 'P'}
    for run in picked:
        mod = run[0]['module']
        if mod in code:
            mod += '_ctbl'                              # the tables of a code module (its -section=const=CTBL)
        unit = mod if big.get(run[0]['module'], (0, None))[1] == run[0]['a'] else f'{mod}_2i_{run[0]["a"]:08X}'
        for o in run:
            d = o['decl']
            if o['class'] == 'new':
                note = 'no 3s object placed here; ' + ("between two modules' tables; " if o.get('between') else '') \
                    + ('named by the naming tables; ' if o['name'] else '') + 'type of the object before it' \
                    + ('' if o.get('between') else ' or after it')
                if not o['name']:
                    note += '; provisional name'
            else:
                note = '' if o['class'] in ('identical', 'reloc') else f'{o["class"]}, sim {o["similarity"]}'
                if o['cname'] != o['name'] and o['cname'] == tabname.get(o['a']):
                    note += ('; ' if note else '') + 'named by the naming tables'
                elif o['cname'] != o['name']:
                    note += ('; ' if note else '') + 'provisional name (the naming tables put the 3s name elsewhere)'
            if o['size'] != o['n']:
                note += ('; ' if note else '') + f'2i extent {o["n"]}'
            rows.append({'unit': unit, 'name': o['cname'], 'addr': o['a'], 'size': o['size'], 'type': o['type'],
                         'class': PROV.get(o['class'], 'new'), 'sf3_name': o['name'] if d else '',
                         'sf3_src': f'{d["file"]}:{d["line"]}' if d else '', 'note': note})
    write_layout(rows)
    us = units_of(rows)
    print(f'{len(us)} units, {len(rows)} objects, {sum(r["size"] for r in rows)} bytes '
          f'(new: {len(rows) - len(keep)} objects)')
    for k, v in why.most_common():
        print(f'  skipped: {k}: {v}')


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('plan')
    p.add_argument('--select', nargs='*')
    p.add_argument('--add', action='store_true')
    p.add_argument('--objects', default=str(ROOT / 'scratch' / 'si2dat' / 'objects.tsv'))
    p.add_argument('--sf3', default=os.environ.get('SF3_TREE', ''))
    p.add_argument('--rom', default=str(ROOT / 'scratch' / 'rom'))
    p.add_argument('--map', default=str(ROOT / 'scratch' / 'si2map'), help="si2map's funcs.tsv (pointer targets)")
    p.add_argument('--max-gap', type=int, default=0x10000, help='largest stretch filled between two runs')
    p.add_argument('--fill-between', type=int, default=0x200000,
                   help="largest stretch filled between two modules' runs (0: none)")
    nd = sub.add_parser('needs')
    nd.add_argument('--out', default=str(ROOT / 'scratch' / 'si2dat' / 'names_needed.tsv'))
    nd.add_argument('--map', default=str(ROOT / 'scratch' / 'si2map'))
    e = sub.add_parser('emit')
    e.add_argument('--rom', default=str(ROOT / 'scratch' / 'rom'))
    a = ap.parse_args()
    if a.cmd == 'needs':
        needs(a)
    elif a.cmd == 'plan':
        plan(a)
    else:
        emit(a)


if __name__ == '__main__':
    main()
