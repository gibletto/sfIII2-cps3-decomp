#!/usr/bin/env python3
"""Fighter data and sprite patterns, 3rd Strike vs 2nd Impact.

    python tools/fighterdiff.py <3s sf3 dir> <2i rom dir> <out dir>

Both versions keep a char_init_data row per fighter (3s 0618B148, 24 rows; 2i 06152958, 18 rows; rows 1-17 are the
same fighters in the same order), and its 24 pointers give each fighter's tables on both sides. Writes:
  fighter_tables.tsv  per fighter and box/attribute/movement table: rows on each side, rows equal / changed /
                      only in 3s / only in 2i (difflib alignment), and the fields that changed
  fighter_rows.tsv    every changed field of a changed row
  fighter_scripts.tsv every 3s animation script and the 2i script it pairs with (same kind, same index when the
                      sprite sequences agree, else the best agreeing one): lines, frames, lines whose frame count
                      (ctr), sprite, attack or hit index changed
  summary.txt         the totals, and the sprite pattern (cg number) comparison
Where the 2i layout differs (HIT_IX, ATTACK_BOX, CATCH_BOX, ATTACK_ATTR) only what both layouts hold is compared;
the 2i layouts are inferred from the data (value ranges against the box tables' row counts), not from the code.
"""
import sys, struct, bisect, collections, difflib
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from datamap import objects, refs, D2, B0

CID3, CID2, ROW = 0x0618B148, 0x06152958, 108
FIGHTERS = ['-', 'yun', 'dudley', 'alex', 'ibuki', 'ryu', 'gill', 'hugo', 'oro', 'necro', 'elena', 'ef13', 'yang', 'ken',
            'sean', 'urien', 'gouki1', 'gouki2']
FIELDS = 'nmca dmca btca caca cuca atca saca exca cbca yuca stxy mvxy sernd ovct ovix rict hiit boda hana cata caua atta hosa atit'.split()
KINDS = FIELDS[:8]


def s16s(n, pre): return [(f'{pre}{i}', 2 * i, 2, True) for i in range(n)]
XYWH = [('x', 0, 2, 1), ('w', 2, 2, 1), ('y', 4, 2, 1), ('h', 6, 2, 1)]
BOX4 = [(f'{k}{j}', 8 * j + 2 * i, 2, True) for j in range(4) for i, k in enumerate(('x', 'w', 'y', 'h'))]
REC = {        # table: (3s row bytes, [(field, offset, size, signed)])
    'hiit': (16, None), 'boda': (32, BOX4), 'hana': (32, BOX4), 'atta': (32, None), 'cata': (8, None),
    'caua': (8, XYWH), 'hosa': (8, XYWH), 'atit': (16, None), 'stxy': (4, s16s(2, 'xy')), 'mvxy': (12, s16s(6, 'v')),
    'ovct': (16, [('hos_x', 0, 2, 1), ('hos_y', 2, 2, 1), ('colmd', 4, 1, 0), ('colcd', 5, 1, 0), ('prio', 6, 1, 0),
                  ('flip', 7, 1, 0), ('timer', 8, 1, 0), ('disp', 9, 1, 0), ('mts', 10, 2, 1), ('nix', 12, 2, 0), ('char', 14, 2, 0)]),
    'ovix': (8, s16s(4, 'ix')),
    'rict': (8, [('hos_x', 0, 2, 1), ('hos_y', 2, 2, 1), ('prio', 4, 1, 0), ('flip', 5, 1, 0), ('nix', 6, 2, 1)]),
}


def words(r, ix): return tuple(int.from_bytes(r[2 * i:2 * i + 2], 'big') for i in ix)
def boxes(r): return tuple(int.from_bytes(r[i:i + 8], 'big', signed=True) for i in range(0, len(r), 8) if any(r[i:i + 8]))
ATT = [('reaction', 0), ('mkh_ix', 2), ('pow', 8), ('impact', 9), ('piyo', 10), ('hs_me', 12), ('hs_you', 13),
       ('hit_mark', 14), ('dmg_mark', 15)]
LAYOUT = {     # table: (2i row bytes, field names, 3s decoder, 2i decoder, drop all-zero rows)
    # HIT_IX: 3s boix bhix haix mf caix cuix atix hoix; 2i boix ? 0 haix cuix atix 0 hoix
    'hiit': (16, ['boix', 'haix', 'cuix', 'atix', 'hoix'], lambda r: words(r, (0, 2, 5, 6, 7)), lambda r: words(r, (0, 3, 4, 5, 7)), False),
    # ATTACK_BOX: 3s rows hold four boxes, 2i rows two; a row compares as its non-zero boxes
    'atta': (16, ['boxes'], lambda r: (boxes(r),), lambda r: (boxes(r),), False),
    # CATCH_BOX: 2i indexes it sparsely (mostly zero rows)
    'cata': (8, ['x', 'w', 'y', 'h'], lambda r: words(r, range(4)), lambda r: words(r, range(4)), True),
    # ATTACK_ATTR: level is bits 0-2 in 3s (with jump/zu/attr/nodeath flags), the high nibble in 2i; bytes 3-7 and
    # the vs_id nibble of byte 11 mean other things in 2i
    'atit': (16, ['level'] + [n for n, _ in ATT] + ['ng_type'], lambda r: (r[1] & 7,) + tuple(r[o] for _, o in ATT) + (r[11] & 15,),
             lambda r: (r[1] >> 4,) + tuple(r[o] for _, o in ATT) + (r[11] & 15,), False),
}
LF = ['ctr', 'type', 'se', 'prio', 'flip', 'olc', 'jphos', 'number', 'att', 'hit', 'meoshi', 'extdat', 'cancel', 'effect',
      'eftype', 'zoom', 'rival', 'add_xy', 'next_ix', 'status']


def ptrs(d, base, k): return struct.unpack('>24I', d[base + k * ROW - B0:base + k * ROW - B0 + 96])
def u16s(d, p, n): return struct.unpack(f'>{n}H', d[p - B0:p - B0 + 2 * n])


def index(d, p):
    """script pointers of a kind's index (ends at the first 0)"""
    out = []
    while len(out) < 400:
        v = struct.unpack('>I', d[p - B0:p - B0 + 4])[0]
        if not 0x06000000 <= v < 0x07000000: break
        out.append(v); p += 4
    return out


def parse(d, p, end):
    """script lines: ('F', ctr, type, ...) frame lines (charscr.h L2/L4/L6) or ('C', code, koc, ix, pat)"""
    wid = {2: 4, 4: 8, 6: 12}.get(u16s(d, p - 8, 1)[0], 8)        # the head's cgd_type
    lines = []; q = p
    while q + 8 <= end and len(lines) < 400:
        w = u16s(d, q, 4)
        if w[0] < 0x100:
            lines.append(('C',) + w)
            if w[0] == 1: break                                     # CM_ROA
            q += 2 * wid; continue
        if q + 2 * wid > end: break
        w = u16s(d, q, wid)
        f = [w[0] >> 8, w[0] & 0xFF, w[1] >> 4, (w[1] >> 2) & 3, w[1] & 3, w[2] >> 4, w[2] & 15, w[3]]
        if wid >= 8:
            att = w[4] >> 6
            f += [att - 1024 if att >= 512 else att, ((w[4] & 63) << 3) | (w[5] >> 13), w[5] & 0x1FFF, w[6] >> 8,
                  w[6] & 0xFF, w[7] >> 8, w[7] & 0xFF]
        if wid >= 12: f += [w[8], w[9], w[10], w[11] >> 8, w[11] & 0xFF]
        lines.append(('F',) + tuple(f)); q += 2 * wid
    return lines


def sprites(L): return [l[8] if l[0] == 'F' else ('C', l[1]) for l in L]


def tables(a, b, size3, span2, od, rep):
    summ = open(od / 'fighter_tables.tsv', 'w', encoding='utf-8')
    summ.write('fighter\ttable\tn3\tn2\trows_equal\trows_changed\trows_3s_only\trows_2i_only\tfield_changes\n')
    det = open(od / 'fighter_rows.tsv', 'w', encoding='utf-8')
    det.write('fighter\ttable\trow3\trow2\tfield\tv3\tv2\n')
    fld = collections.defaultdict(collections.Counter); tot = collections.defaultdict(collections.Counter)
    for k in range(1, 18):
        f = FIGHTERS[k]; p3 = ptrs(a, CID3, k); p2 = ptrs(b, CID2, k)
        for t, (rs, flds) in REC.items():
            fi = FIELDS.index(t)
            if not p3[fi] or not p2[fi]: continue
            if t in LAYOUT: rs2, names, d3, d2, dropzero = LAYOUT[t]
            else:
                rs2, names, dropzero = rs, [x[0] for x in flds], False
                d3 = d2 = (lambda fl: lambda r: tuple(int.from_bytes(r[o:o + s], 'big', signed=bool(g)) for _, o, s, g in fl))(flds)
            R3 = [d3(a[p3[fi] - B0 + i * rs:p3[fi] - B0 + (i + 1) * rs]) for i in range(size3[p3[fi]] // rs)]
            R2 = [d2(b[p2[fi] - B0 + i * rs2:p2[fi] - B0 + (i + 1) * rs2]) for i in range(span2(p2[fi]) // rs2)]
            if dropzero: R3 = [r for r in R3 if any(r)]; R2 = [r for r in R2 if any(r)]
            eq = ch = o3 = o2 = 0; fc = collections.Counter()
            for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, R3, R2, autojunk=False).get_opcodes():
                if op == 'equal': eq += i2 - i1; continue
                m = min(i2 - i1, j2 - j1)
                ch += m; o3 += (i2 - i1) - m; o2 += (j2 - j1) - m
                for q in range(m):
                    for nm, v3, v2 in zip(names, R3[i1 + q], R2[j1 + q]):
                        if v3 != v2:
                            fc[nm] += 1; det.write('\t'.join(map(str, (f, t, i1 + q, j1 + q, nm, v3, v2))) + '\n')
            fld[t].update(fc)
            for key, v in (('n3', len(R3)), ('n2', len(R2)), ('eq', eq), ('ch', ch), ('o3', o3), ('o2', o2)): tot[t][key] += v
            summ.write('\t'.join(map(str, (f, t, len(R3), len(R2), eq, ch, o3, o2))) + '\t' + ','.join(f'{n}:{c}' for n, c in fc.most_common()) + '\n')
    rep.append('fighter tables (17 rows of char_init_data): rows 3s, 2i, equal, changed, 3s only, 2i only | changed fields')
    for t in REC:
        c = tot[t]
        rep.append(f"  {t:5s} {c['n3']:6d} {c['n2']:6d} {c['eq']:6d} {c['ch']:6d} {c['o3']:6d} {c['o2']:6d} | " +
                   ' '.join(f'{n}:{v}' for n, v in fld[t].most_common(9)))


def scripts(a, b, od, rep):
    out = open(od / 'fighter_scripts.tsv', 'w', encoding='utf-8')
    out.write('fighter\tkind\tidx3\tidx2\tlines3\tlines2\tratio\tframes3\tframes2\tlines_ctr\tlines_sprite\tlines_att\tlines_hit\tlines_other\tlines_3s_only\tlines_2i_only\n')
    KT = collections.defaultdict(collections.Counter); FC = collections.Counter()
    for k in range(1, 18):
        f = FIGHTERS[k]; p3 = ptrs(a, CID3, k); p2 = ptrs(b, CID2, k)
        if not p3[1]: continue                                       # ef13: a single char_table
        I3 = {kd: index(a, p3[i]) for i, kd in enumerate(KINDS)}; I2 = {kd: index(b, p2[i]) for i, kd in enumerate(KINDS)}
        def ends(I, tabs):
            s = sorted(set(x for v in I.values() for x in v) | set(t for t in tabs if t))
            return lambda p: next((x - 8 for x in s if x > p), p + 0x400)          # the next script's head
        e3 = ends(I3, p3); e2 = ends(I2, p2)
        for kd in KINDS:
            S2 = {}
            for j, p in enumerate(I2[kd]):
                if p not in S2: S2[p] = (j, parse(b, p, e2(p)))
            seen = set()
            for i, p in enumerate(I3[kd]):
                if p in seen: continue
                seen.add(p)
                L3 = parse(a, p, e3(p)); s3 = sprites(L3); best = None
                def ratio(L2): return difflib.SequenceMatcher(None, s3, sprites(L2), autojunk=False).ratio()
                if i < len(I2[kd]):
                    j, L2 = S2[I2[kd][i]]; r = ratio(L2)
                    if r >= 0.5: best = (r, j, L2)
                if best is None:
                    for j, L2 in S2.values():
                        r = ratio(L2)
                        if r >= 0.5 and (best is None or r > best[0]): best = (r, j, L2)
                c = KT[kd]; c['scripts3'] += 1
                if best is None:
                    c['unpaired'] += 1; out.write(f'{f}\t{kd}\t{i}\t\t{len(L3)}' + '\t' * 11 + '\n'); continue
                r, j, L2 = best
                c['paired'] += 1; c['identical'] += L3 == L2
                fr3 = sum(l[1] for l in L3 if l[0] == 'F'); fr2 = sum(l[1] for l in L2 if l[0] == 'F')
                c['frames_changed'] += fr3 != fr2
                d = collections.Counter()
                for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, s3, sprites(L2), autojunk=False).get_opcodes():
                    m = min(i2 - i1, j2 - j1) if op in ('equal', 'replace') else 0
                    for q in range(m):
                        x, y = L3[i1 + q], L2[j1 + q]
                        if x == y: continue
                        if x[0] != 'F' or y[0] != 'F': d['other'] += 1; continue
                        diff = [LF[n] for n in range(min(len(x), len(y)) - 1) if x[n + 1] != y[n + 1]]
                        FC.update(diff)
                        for nm, key in (('ctr', 'ctr'), ('number', 'sprite'), ('att', 'att'), ('hit', 'hit')): d[key] += nm in diff
                        d['other'] += bool(set(diff) - {'ctr', 'number', 'att', 'hit'})
                    d['o3'] += (i2 - i1) - m; d['o2'] += (j2 - j1) - m
                c['ctr_changed'] += d['ctr'] > 0
                for key in ('ctr', 'sprite', 'att', 'hit', 'other', 'o3', 'o2'): c['lines_' + key] += d[key]
                c['lines3'] += len(L3)
                out.write(f"{f}\t{kd}\t{i}\t{j}\t{len(L3)}\t{len(L2)}\t{r:.2f}\t{fr3}\t{fr2}\t{d['ctr']}\t{d['sprite']}\t{d['att']}\t{d['hit']}\t{d['other']}\t{d['o3']}\t{d['o2']}\n")
    rep.append('animation scripts (16 fighters): 3s scripts, paired, identical, frame total changed, any ctr changed | '
               'lines: 3s, ctr, sprite, att, hit, other, 3s only, 2i only')
    T = collections.Counter()
    for kd in KINDS + ['all']:
        c = KT[kd] if kd != 'all' else T
        rep.append(f"  {kd:5s} {c['scripts3']:5d} {c['paired']:5d} {c['identical']:5d} {c['frames_changed']:5d} {c['ctr_changed']:5d} | "
                   f"{c['lines3']:6d} {c['lines_ctr']:5d} {c['lines_sprite']:5d} {c['lines_att']:5d} {c['lines_hit']:5d} "
                   f"{c['lines_other']:5d} {c['lines_o3']:5d} {c['lines_o2']:5d}")
        if kd != 'all': T.update(c)
    rep.append('  frame-line fields changed: ' + ' '.join(f'{n}:{v}' for n, v in FC.most_common(12)))


def cg(a, b, rep):
    """cg_data_tbl: 3s 65536 x (origin, set) at 06800000; 2i 29184 x (w0, w1, set) at 06800000-06855800, sets from
    068C0000. Sets compare with their graphics-ROM addresses (chunk src, prep) masked."""
    def cgset(d, p):
        if not 0x06800000 <= p < 0x07000000: return None
        h0, h1, prep = struct.unpack('>3I', d[p - B0:p - B0 + 12])
        cnt, cells = h1 >> 16, h1 & 0xFFFF
        if cnt > 256 or cells > 1024: return None
        q = p + 12
        ch = [struct.unpack('>2I', d[q + 8 * i - B0:q + 8 * i + 8 - B0]) for i in range(cnt)]; q += 8 * cnt
        return h0, h1, tuple(x[1] for x in ch), tuple(struct.unpack('>2I', d[q + 8 * i - B0:q + 8 * i + 8 - B0]) for i in range(cells))
    c = collections.Counter()
    for n in range(65536):
        p3 = struct.unpack('>I', a[0x800004 + 8 * n:0x800008 + 8 * n])[0]
        p2 = struct.unpack('>I', b[0x800008 + 12 * n:0x80000C + 12 * n])[0] if n < 29184 else 0
        if not p3 and not p2: continue
        if not (p3 and p2): c['3s only' if p3 else '2i only'] += 1; continue
        s3, s2 = cgset(a, p3), cgset(b, p2)
        if not s3 or not s2: c['unparsed'] += 1
        elif s3 == s2: c['same but graphics-ROM addresses'] += 1
        elif s3[3] == s2[3]: c['same cells, other chunks/header'] += 1
        else: c['different'] += 1
    rep.append('sprite patterns by cg number: ' + ', '.join(f'{k} {v}' for k, v in c.most_common()))


def main():
    if len(sys.argv) != 4: sys.exit(__doc__)
    sf3, rom, od = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3])
    od.mkdir(parents=True, exist_ok=True)
    a = (sf3 / 'verify/bootstrap/prog.bin').read_bytes()
    b = (rom / 'prog_data.bin').read_bytes(); op = (rom / 'prog_op.bin').read_bytes()
    size3 = {o[0]: o[1] for o in objects(sf3 / 'sf3.map')}
    # a 2i table ends at the next code reference or the next fighter table (box and attribute rows can look like
    # pointers, so data words are not used)
    B2 = sorted({t for t, (nc, nd) in refs(op, b, *D2).items() if nc} |
                {p for k in range(1, 18) for p in ptrs(b, CID2, k) if p})
    def span2(p):
        j = bisect.bisect_right(B2, p)
        return B2[j] - p if j < len(B2) else 0
    rep = []
    tables(a, b, size3, span2, od, rep)
    scripts(a, b, od, rep)
    cg(a, b, rep)
    (od / 'summary.txt').write_text('\n'.join(rep) + '\n', encoding='utf-8')
    print('\n'.join(rep))


if __name__ == '__main__':
    main()
