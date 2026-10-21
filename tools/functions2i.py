#!/usr/bin/env python3
"""Write sf2i/functions.tsv: every routine of the 2nd Impact program, from a build's status (sf2i/build/status.tsv).

    python tools/functions2i.py [--tree sf2i]

Columns: the 2nd Impact address, the size in bytes, the name (the C spelling: the link symbol without its leading _),
the file that holds it, and the kind (c, c-label: a second entry inside a C routine, asm, lib). tools/si2map.py takes
the file as its seeds (the entries the code walk starts from besides the vector table and the program header).
"""
import argparse
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FILE = {'c': 'src/{}.c', 'c-label': 'src/{}.c', 'asm': 'src/{}.src', 'lib': 'lib/{}.src'}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=str(ROOT / 'sf2i'))
    a = ap.parse_args()
    T = Path(a.tree)
    rows = [l.rstrip('\n').split('\t') for l in open(T / 'build' / 'status.tsv', encoding='utf-8')]
    head, rows = rows[0], rows[1:]
    col = {k: i for i, k in enumerate(head)}
    out = ['# 2nd Impact address\tsize\tname (C spelling: the link symbol without its leading _)\tfile\tkind']
    left = []
    for r in rows:
        kind = r[col['kind']]
        if kind not in FILE:
            left.append(r[col['name']])
            continue
        f = FILE[kind].format(r[col['object']])
        if not (T / f).exists():
            raise SystemExit(f'{r[col["name"]]}: {f} is not in the tree')
        out.append('\t'.join((r[col['address']], r[col['size']], r[col['name']], f, kind)))
    if left:
        raise SystemExit(f'{len(left)} routines are not source yet (first {left[0]})')
    (T / 'functions.tsv').write_text('\n'.join(out) + '\n', encoding='utf-8', newline='\n')
    print(f"{T / 'functions.tsv'}: {len(out) - 1} routines")


if __name__ == '__main__':
    main()
