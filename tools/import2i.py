#!/usr/bin/env python3
"""Bring 3rd Strike modules into the 2nd Impact tree as source (the blob of each is then no longer written).

    python tools/import2i.py <module> ... [--tree sf2i] [--sf3 <3s sf3 tree>] [--drop NAME ...]

<module> is the 3s object name (Entry, intr, slow_mvn). The source comes from the 3s tree: src/<module>.c (and
its units.txt line), src/<module>.src or lib/<module>.src. A C module gets one comment line above every function
the naming tables place in 2i, from its own functions.tsv row (docs/PROVENANCE.md: "2i <address>, <class>: sf3
<source> <3s name>"); a function whose own row has another name is renamed in the module and reported, so the
callers in other source modules can follow. A function's own row is the one that lies in the module (own_rows):
the row of an identical copy elsewhere, named by its role there, neither renames it nor comments it. --drop NAME removes a function definition that 2i does not
have (the census calls it absent), from its line to the closing brace at column 0 together with the comment
lines straight above it. Run tools/layout2i.py afterwards: it places the module's sections and writes the link.
"""
import argparse, os, re, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import build2i

S3 = os.environ.get('SF3_TREE', '')   # a built 3rd Strike development tree (its sf3/ directory)
if not S3:
    sys.exit('set SF3_TREE to a built 3rd Strike tree (the sf3/ directory with src/, include/ and sf3.map)')


def rows_for(src):
    """functions.tsv rows whose 3s source is this file: [(line, row)]"""
    out = []
    for l in open(build2i.ROOT / 'ghidra' / 'names' / 'functions.tsv', encoding='utf-8'):
        if l.startswith('#') or not l.strip():
            continue
        c = l.rstrip('\n').split('\t')
        m = re.fullmatch(r'(src|lib)/(.+):(\d+)', c[6])
        if m and f'{m.group(1)}/{m.group(2)}' == src:
            out.append((int(m.group(3)), c))
    return out


REACH = 0x4000      # how far past the module's outermost anchors a first or last routine's row may lie


def own_rows(rows):
    """each 3s function's own row: [(line, row)], at most one per line. Several rows can carry one 3s source line
    (identical copies elsewhere, named by their roles), so a row counts only where it lies in the module: its
    address must fall between those of the anchors (lines with exactly one row of the 3s name itself) before and
    after it, the anchors kept in source order with rising addresses (longest such run). Among the rows in range
    the 3s name itself wins; a line with no row in range gets none (the function keeps its 3s name)."""
    by = {}
    for line, c in rows:
        by.setdefault(line, []).append(c)
    anchors = []
    for line in sorted(by):
        own = [c for c in by[line] if c[1] == c[5]]
        if len(own) == 1:
            anchors.append((line, int(own[0][0], 16)))
    # longest run of anchors with rising addresses (patience sort with back links)
    tails, prev, idx = [], [None] * len(anchors), []
    for k, (_, a) in enumerate(anchors):
        lo, hi = 0, len(tails)
        while lo < hi:
            mid = (lo + hi) // 2
            if anchors[tails[mid]][1] < a:
                lo = mid + 1
            else:
                hi = mid
        prev[k] = tails[lo - 1] if lo else None
        if lo == len(tails):
            tails.append(k)
        else:
            tails[lo] = k
    k = tails[-1] if tails else None
    while k is not None:
        idx.append(k)
        k = prev[k]
    kept = sorted(anchors[k] for k in idx)
    out = []
    for line in sorted(by):
        before = [a for l, a in kept if l <= line]
        after = [a for l, a in kept if l >= line]
        lo = before[-1] if before else (after[0] - REACH if after else None)
        hi = after[0] if after else (before[-1] + REACH if before else None)
        cands = [c for c in by[line] if lo is None or lo <= int(c[0], 16) <= hi]
        if cands:
            out.append((line, min(cands, key=lambda c: (c[1] != c[5], int(c[0], 16)))))
    return out


def drop(lines, name):
    """remove the definition of function name (a line naming it with '(' and no ';', through the next '}' line
    at column 0) and the comment block above it"""
    pat = re.compile(r'^[A-Za-z_].*\b' + re.escape(name) + r'\s*\(')
    for i, l in enumerate(lines):
        if pat.match(l) and not l.rstrip().endswith(';'):
            j = i
            while j < len(lines) and not lines[j].startswith('}'):
                j += 1
            k = i
            while k > 0 and (lines[k - 1].lstrip().startswith(('/*', '*', '//')) or lines[k - 1].rstrip().endswith('*/')):
                k -= 1
            while k > 0 and not lines[k - 1].strip() and k > 1 and not lines[k - 2].strip():
                k -= 1
            return lines[:k] + lines[j + 1:], True
    return lines, False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('modules', nargs='+')
    ap.add_argument('--tree', default=str(build2i.ROOT / 'sf2i'))
    ap.add_argument('--sf3', default=S3)
    ap.add_argument('--drop', nargs='*', default=[])
    a = ap.parse_args()
    T, S = Path(a.tree).resolve(), Path(a.sf3)
    u3 = {}
    for l in (S / 'units.txt').read_text().splitlines():
        if l.strip() and not l.startswith(';'):
            u3[l.split()[0]] = l
    for mod in a.modules:
        cands = [('src', f'{mod}.c'), ('src', f'{mod}.src'), ('lib', f'{mod}.src')]
        sub, fname = next(((d, f) for d, f in cands if (S / d / f).exists()), (None, None))
        if sub is None:
            print(f'{mod}: no source in {S}')
            continue
        text = open(S / sub / fname, encoding='latin-1', newline='').read()
        out = T / sub / fname
        if fname.endswith('.c'):
            nl = '\r\n' if '\r\n' in text else '\n'
            lines = text.split(nl)
            rows = own_rows(rows_for(f'{sub}/{fname}'))
            renames = {}
            for line, c in sorted(rows, reverse=True):
                addr, name, cls, s3name = c[0], c[1], c[3], c[5]
                if name != s3name and s3name:
                    renames[s3name] = name
                lines.insert(line - 1, f'/* 2i {addr}, {cls}: sf3 {c[6]} {s3name or name} */')
            for n in a.drop:
                lines, ok = drop(lines, n)
                print(f'{mod}: {"dropped" if ok else "no definition of"} {n}')
            text = nl.join(lines)
            for old, new in renames.items():
                text = re.sub(r'\b' + re.escape(old) + r'\b', new, text)
                print(f'{mod}: {old} is {new} in 2i (renamed in the module; other modules calling it must follow)')
            ul = u3.get(mod, f'{mod} speed')
            ut = open(T / 'units.txt', newline='').read() if (T / 'units.txt').exists() else ''
            if not any(l.split()[:1] == [mod] for l in ut.splitlines()):
                (T / 'units.txt').write_text(ut + ul + '\r\n', newline='')
            print(f'{mod}: {sub}/{fname}, {len(rows)} functions with a 2i row, options {ul.split()[1]}')
        else:
            print(f'{mod}: {sub}/{fname}')
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text, encoding='latin-1', newline='')


if __name__ == '__main__':
    main()
