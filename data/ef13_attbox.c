/*
 * EF13_ATTBOX.C  Effect 13's attack, catch and caught boxes
 *
 * Selected per animation frame through ef13_hit_ix_table (atix, caix, cuix). A box is x, width,
 * y, height from the character's position, x mirrored when facing left; width 0 means no box.
 *
 * att_box  two boxes per entry: the attack boxes the hit check tests against the opponent's
 *          damage boxes; while they are out they also count as damage boxes of this character
 * cat_box  the reach of a throw: the opponent's caught box must overlap it
 * cau_box  where this character can be thrown from
 *
 * Row comments: the moves whose frames use the box (debug viewer names) and, for att_box, the
 * catt_table attacks dealt through it (rows of the fighter's _attr.c). Row 0 is no box.
 *
 * Effect 13 is the projectile (shell) work the fighters fire (EFF13.c). Its scripts are ef13_char_table
 * in effect_char.c; the row comments number them (script N).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const ATTACK_BOX ef13_att_box[47] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -18,  80, -14,  26 },  {    0,   0,   0,   0 } } },  /* 1: script 0, script 5, script 6 +12; attack 1, 2, 4, 25 ... */
    { { {  -11,   8, -13,  23 },  {    0,   0,   0,   0 } } },  /* 2: script 0, script 6, script 7 +11; attack 1, 4, 5, 25 ... */
    { { {  -12,  24,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 3: script 15; attack 7 */
    { { {  -18,  36,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 4: script 16; attack 8 */
    { { {  -14,  28,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 5: script 17; attack 9 */
    { { {  -12,  24,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 6: script 18; attack 10 */
    { { {  -12,  24,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 7: script 19; attack 11 */
    { { {  -13,  69, -16,  32 },  {   -4,  31, -28,  56 } } },  /* 8: script 107, script 147; attack 42, 59 */
    { { {   -8,  18,   4,  14 },  {    0,   0,   0,   0 } } },  /* 9: script 20; attack 12 */
    { { {  -10,  20,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 10: script 21; attack 13 */
    { { {   -8,  16,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 11: script 22; attack 14 */
    { { {  -32,  64,  -8,  14 },  {    0,   0,   0,   0 } } },  /* 12: script 23; attack 15 */
    { { {  -14,  28,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 13: script 24; attack 16 */
    { { {  -20,  34, -10,  20 },  {    0,   0,   0,   0 } } },  /* 14: script 25; attack 17 */
    { { {  -22,  44,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 15: script 26; attack 18 */
    { { {   -6,  12,  -3,  11 },  {    0,   0,   0,   0 } } },  /* 16: script 40; attack 24 */
    { { {  -30,  60, -14,  28 },  {  -22,  44, -22,  44 } } },  /* 17: script 32; attack 19 */
    { { {   -8,  16,  -7,  14 },  {    0,   0,   0,   0 } } },  /* 18: script 41, script 42, script 84; attack 28, 37 */
    { { {   -9,  18,  -9,  18 },  {    0,   0,   0,   0 } } },  /* 19: script 43, script 44, script 45 +3; attack 28, 29, 30, 37 */
    { { {   -7,   8, -14,  26 },  {    0,   0,   0,   0 } } },  /* 20: script 27; attack 20 */
    { { {  -16,  32, -20,  34 },  {    0,   0,   0,   0 } } },  /* 21: script 61, script 62, script 72 +2; attack 32, 33 */
    { { {  -56,  24,   0,  16 },  {    0,   0,   0,   0 } } },  /* 22: script 10, script 71; attack 6, 34 */
    { { {   32,  28,   0,  20 },  {    0,   0,   0,   0 } } },  /* 23: script 10 */
    { { {  -36,  72,  12,  16 },  {    0,   0,   0,   0 } } },  /* 24: script 10 */
    { { {  -48,  24,   6,  16 },  {    0,   0,   0,   0 } } },  /* 25: script 10 */
    { { {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 26: script 72, script 73, script 92 +2; attack 32, 33, 39, 40 */
    { { {  -12,  24, -14,  26 },  {   12,  24, -14,  26 } } },  /* 27: script 27; attack 20 */
    { { {  -12,  24, -10,  20 },  {   12,  24, -20,  20 } } },  /* 28: script 37; attack 21 */
    { { {  -12,  24, -10,  20 },  {    2,  24, -24,  20 } } },  /* 29: script 38; attack 22 */
    { { {  -10,  20,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 30: script 37, script 38; attack 21, 22 */
    { { {  -12,  24, -20,  29 },  {    0,   0,   0,   0 } } },  /* 31: script 86; attack 38 */
    { { {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 32: script 91; attack 38 */
    { { {  -12,  22,  52,  42 },  {   -8,  12,  40,  66 } } },  /* 33: script 112, script 143; attack 44, 45 */
    { { {   -8,  12,  40,  66 },  {  -12,  22,  52,  42 } } },  /* 34: not used by a script */
    { { {   -9,  18,   2,  14 },  {    0,   0,   0,   0 } } },  /* 35: not used by a script */
    { { {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 36: script 102; attack 41, 56 */
    { { {  -12,  24, -20,  40 },  {    0,   0,   0,   0 } } },  /* 37: script 102; attack 41 */
    { { {  -12,  24, -40,  80 },  {    0,   0,   0,   0 } } },  /* 38: script 102; attack 41, 56 */
    { { {  -11,  21,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {  -10,  10, -10,  36 },  {  -10,  38, -10,  10 } } },  /* 40: script 127, script 149; attack 48, 52, 63, 66 */
    { { {   -5,  16,  -3,  14 },  {    0,   0,   0,   0 } } },  /* 41: script 122, script 148; attack 47, 62 */
    { { {   -9,  23, -16,  32 },  {    0,   0,   0,   0 } } },  /* 42: script 107, script 147; attack 42, 43, 59, 60 */
    { { {  -11,  24, -13,  23 },  {    0,   0,   0,   0 } } },  /* 43: script 74; attack 36 */
    { { {  -11,  29, -13,  23 },  {    0,   0,   0,   0 } } },  /* 44: script 5; attack 2, 3 */
    { { {  -12,  24, -11,  20 },  {    0,   0,   0,   0 } } },  /* 45: script 144; attack 38 */
    { { {   -8,  16,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 46: script 39; attack 23 */
};

const CATCH_BOX ef13_cat_box[1] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
};

const CAUGHT_BOX ef13_cau_box[1] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
};
