/*
 * EF13_HITBOX.C  Effect 13's hit boxes
 *
 * Each of Effect 13's animation frames names an entry of ef13_hit_ix_table (cg_hit_ix in the frame
 * record). The entry picks the boxes that frame uses; set_char_base_data (CHARID) points the work
 * at these tables through char_init_data. A box is x, width, y, height from the character's
 * position, x mirrored when facing left; width 0 means no box.
 *
 * hit_ix_table  one row per animation frame pose (a script line's hit field picks it); each column
 *               picks a row of one box table (0 = none):
 *     boix  body box: where this character can be hit (body_box)
 *     haix  hand box: extra damage boxes on an extended arm or leg (hand_box)
 *     free  unused (0 in every row)
 *     caix  catch box: this frame's throw reach (cat_box in _attbox.c)
 *     cuix  caught box: where this character can be thrown (cau_box in _attbox.c)
 *     atix  attack box: where this frame hits (att_box in _attbox.c)
 *     eaix  attack boxes the hit check tests before atix's, which cannot themselves be hit (h_eat);
 *           0 in every row
 *     hoix  push box: keeps the two fighters apart (hos_box)
 * body_box      four damage boxes (head down to legs)
 * hand_box      two damage boxes for an extended arm or leg, hit only from the front
 * hos_box       the push box: where two fighters' push boxes overlap they are moved apart; attacks
 *               whose attribute has free4 bit 7 also hit it
 *
 * Row comments: the moves whose frames use the row or box (debug viewer names). Row 0 of a
 * box table is no box; a projectile has no hand or push boxes (hand_box and hos_box are row 0 only) and
 * no throw boxes (caix and cuix are 0).
 *
 * Effect 13 is the projectile (shell) work the fighters fire (EFF13.c). Its scripts are ef13_char_table
 * in effect_char.c; the row comments number them (script N).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const HIT_IX ef13_hit_ix_table[53] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: script 58, script 59, script 102 +6 */
    {    1,    0,    0,    0,    0,    1,    0,    0 },  /* 1: script 0, script 5, script 6 +12 */
    {    2,    0,    0,    0,    0,    2,    0,    0 },  /* 2: script 0, script 6, script 7 +11 */
    {    3,    0,    0,    0,    0,    3,    0,    0 },  /* 3: script 15 */
    {    4,    0,    0,    0,    0,    4,    0,    0 },  /* 4: script 16 */
    {    5,    0,    0,    0,    0,    5,    0,    0 },  /* 5: script 17 */
    {    6,    0,    0,    0,    0,    6,    0,    0 },  /* 6: script 18 */
    {    7,    0,    0,    0,    0,    7,    0,    0 },  /* 7: script 19 */
    {    8,    0,    0,    0,    0,    0,    0,    0 },  /* 8: script 132, script 134 */
    {    9,    0,    0,    0,    0,    9,    0,    0 },  /* 9: script 20 */
    {   10,    0,    0,    0,    0,   10,    0,    0 },  /* 10: script 21 */
    {   11,    0,    0,    0,    0,   11,    0,    0 },  /* 11: script 22 */
    {   12,    0,    0,    0,    0,   12,    0,    0 },  /* 12: script 23 */
    {   13,    0,    0,    0,    0,   13,    0,    0 },  /* 13: script 24 */
    {   14,    0,    0,    0,    0,   14,    0,    0 },  /* 14: script 25 */
    {   15,    0,    0,    0,    0,   15,    0,    0 },  /* 15: script 26 */
    {   16,    0,    0,    0,    0,   16,    0,    0 },  /* 16: script 40 */
    {   17,    0,    0,    0,    0,   17,    0,    0 },  /* 17: script 32 */
    {   18,    0,    0,    0,    0,   18,    0,    0 },  /* 18: script 41, script 42, script 84 */
    {   20,    0,    0,    0,    0,   19,    0,    0 },  /* 19: script 43, script 44, script 45 +3 */
    {   19,    0,    0,    0,    0,   20,    0,    0 },  /* 20: script 27 */
    {   21,    0,    0,    0,    0,   21,    0,    0 },  /* 21: script 61, script 62, script 72 +2 */
    {   22,    0,    0,    0,    0,   22,    0,    0 },  /* 22: script 10, script 71 */
    {   23,    0,    0,    0,    0,   23,    0,    0 },  /* 23: script 10 */
    {   24,    0,    0,    0,    0,   24,    0,    0 },  /* 24: script 10 */
    {   25,    0,    0,    0,    0,   25,    0,    0 },  /* 25: script 10 */
    {   26,    0,    0,    0,    0,   26,    0,    0 },  /* 26: script 72, script 73, script 92 +2 */
    {   27,    0,    0,    0,    0,   27,    0,    0 },  /* 27: script 27 */
    {   28,    0,    0,    0,    0,   28,    0,    0 },  /* 28: script 37 */
    {   29,    0,    0,    0,    0,   29,    0,    0 },  /* 29: script 38 */
    {   30,    0,    0,    0,    0,   30,    0,    0 },  /* 30: script 37, script 38 */
    {   31,    0,    0,    0,    0,   31,    0,    0 },  /* 31: script 86 */
    {   32,    0,    0,    0,    0,   32,    0,    0 },  /* 32: script 91 */
    {   33,    0,    0,    0,    0,   33,    0,    0 },  /* 33: script 112, script 143 */
    {   33,    0,    0,    0,    0,   34,    0,    0 },  /* 34: not used by a script */
    {   34,    0,    0,    0,    0,   35,    0,    0 },  /* 35: not used by a script */
    {   34,    0,    0,    0,    0,    0,    0,    0 },  /* 36: not used by a script */
    {   35,    0,    0,    0,    0,   36,    0,    0 },  /* 37: script 102 */
    {   36,    0,    0,    0,    0,   37,    0,    0 },  /* 38: script 102 */
    {   37,    0,    0,    0,    0,   38,    0,    0 },  /* 39: script 102 */
    {   35,    0,    0,    0,    0,    0,    0,    0 },  /* 40: script 102 */
    {   38,    0,    0,    0,    0,   39,    0,    0 },  /* 41: not used by a script */
    {   38,    0,    0,    0,    0,    0,    0,    0 },  /* 42: not used by a script */
    {   39,    0,    0,    0,    0,   40,    0,    0 },  /* 43: script 127, script 149 */
    {   40,    0,    0,    0,    0,   41,    0,    0 },  /* 44: script 122, script 148 */
    {   41,    0,    0,    0,    0,    8,    0,    0 },  /* 45: script 107, script 147 */
    {   42,    0,    0,    0,    0,   43,    0,    0 },  /* 46: script 74 */
    {   43,    0,    0,    0,    0,   44,    0,    0 },  /* 47: script 5 */
    {   44,    0,    0,    0,    0,   45,    0,    0 },  /* 48: script 144 */
    {   45,    0,    0,    0,    0,   42,    0,    0 },  /* 49: script 107, script 147 */
    {   46,    0,    0,    0,    0,   46,    0,    0 },  /* 50: script 39 */
    {   47,    0,    0,    0,    0,   39,    0,    0 },  /* 51: not used by a script */
    {   47,    0,    0,    0,    0,    0,    0,    0 },  /* 52: not used by a script */
};

const BODY_BOX ef13_body_box[48] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {  -18,  80, -14,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: script 0, script 5, script 6 +12 */
    { { {    0,   0,   0,   0 },  {  -11,   8, -13,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: script 0, script 6, script 7 +11 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 3: script 15 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -18,  36,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 4: script 16 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -14,  28,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 5: script 17 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 6: script 18 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 7: script 19 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  36,  46,  32 },  {    0,   0,   0,   0 } } },  /* 8: script 132, script 134 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -8,  18,   4,  14 },  {    0,   0,   0,   0 } } },  /* 9: script 20 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -10,  20,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 10: script 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -8,  16,  -6,  12 },  {    0,   0,   0,   0 } } },  /* 11: script 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  64,  -8,  14 },  {    0,   0,   0,   0 } } },  /* 12: script 23 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -14,  28,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 13: script 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -20,  34, -10,  20 },  {    0,   0,   0,   0 } } },  /* 14: script 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -22,  44,  -8,  16 },  {    0,   0,   0,   0 } } },  /* 15: script 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -6,  12,  -3,  11 },  {    0,   0,   0,   0 } } },  /* 16: script 40 */
    { { {    0,   0,   0,   0 },  {  -30,  60, -14,  28 },  {  -22,  44, -22,  44 },  {    0,   0,   0,   0 } } },  /* 17: script 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 18: script 41, script 42, script 84 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -7,   8, -14,  26 },  {    0,   0,   0,   0 } } },  /* 19: script 27 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -10,  20, -11,  22 },  {    0,   0,   0,   0 } } },  /* 20: script 43, script 44, script 45 +3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  32, -20,  34 },  {    0,   0,   0,   0 } } },  /* 21: script 61, script 62, script 72 +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -56,  24,   0,  16 },  {    0,   0,   0,   0 } } },  /* 22: script 10, script 71 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   32,  28,   0,  20 },  {    0,   0,   0,   0 } } },  /* 23: script 10 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -36,  72,  12,  16 },  {    0,   0,   0,   0 } } },  /* 24: script 10 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  24,   6,  16 },  {    0,   0,   0,   0 } } },  /* 25: script 10 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 26: script 72, script 73, script 92 +2 */
    { { {    0,   0,   0,   0 },  {  -12,  30, -14,  26 },  {   18,  30, -14,  26 },  {    0,   0,   0,   0 } } },  /* 27: script 27 */
    { { {    0,   0,   0,   0 },  {  -12,  24, -10,  20 },  {   12,  24, -20,  20 },  {    0,   0,   0,   0 } } },  /* 28: script 37 */
    { { {    0,   0,   0,   0 },  {  -12,  24, -10,  20 },  {    2,  24, -24,  20 },  {    0,   0,   0,   0 } } },  /* 29: script 38 */
    { { {    0,   0,   0,   0 },  {  -10,  20,  -8,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: script 37, script 38 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -20,  29 },  {    0,   0,   0,   0 } } },  /* 31: script 86 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 32: script 91 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -6,  10,  18, 108 },  {    0,   0,   0,   0 } } },  /* 33: script 112, script 143 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -19,  38,  -5,  28 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -10,  20 },  {    0,   0,   0,   0 } } },  /* 35: script 102 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -20,  40 },  {    0,   0,   0,   0 } } },  /* 36: script 102 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -40,  80 },  {    0,   0,   0,   0 } } },  /* 37: script 102 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -18,  35, -14,  28 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {    0,   0,   0,   0 },  {  -10,  10, -10,  36 },  {  -10,  38, -10,  10 },  {    0,   0,   0,   0 } } },  /* 39: script 127, script 149 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -5,  16,  -3,  14 },  {    0,   0,   0,   0 } } },  /* 40: script 122, script 148 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -13,  69, -16,  32 },  {    0,   0,   0,   0 } } },  /* 41: script 107, script 147 */
    { { {    0,   0,   0,   0 },  {  -11,  24, -13,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: script 74 */
    { { {    0,   0,   0,   0 },  {  -11,   8, -13,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: script 5 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  24, -11,  20 },  {    0,   0,   0,   0 } } },  /* 44: script 144 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -9,  23, -16,  32 },  {    0,   0,   0,   0 } } },  /* 45: script 107, script 147 */
    { { {    0,   0,   0,   0 },  {   -8,  16,  -6,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: script 39 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -26,  51, -19,  38 },  {    0,   0,   0,   0 } } },  /* 47: not used by a script */
};

const HAND_BOX ef13_hand_box[1] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
};

const HOSEI_BOX ef13_hos_box[1] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
};
