/*
 * NECRO_ATTBOX.C  Necro's attack, catch and caught boxes
 *
 * Selected per animation frame through necro_hit_ix_table (atix, caix, cuix). A box is x, width,
 * y, height from the character's position, x mirrored when facing left; width 0 means no box.
 *
 * att_box  two boxes per entry: the attack boxes the hit check tests against the opponent's
 *          damage boxes; while they are out they also count as damage boxes of this character
 * cat_box  the reach of a throw: the opponent's caught box must overlap it
 * cau_box  where this character can be thrown from
 *
 * Row comments: the moves whose frames use the box (debug viewer names) and, for att_box, the
 * catt_table attacks dealt through it (rows of the fighter's _attr.c). Row 0 is no box.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const ATTACK_BOX necro_att_box[57] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -82,  21,  48,  15 },  {  -61,  36,  48,  15 } } },  /* 1: S PUNCH C; attack 1 */
    { { { -119,  24,  63,  12 },  {  -94,  65,  63,  12 } } },  /* 2: S PUNCH A; attack 2 */
    { { { -102,  26,  67,  18 },  {  -76,  54,  67,  18 } } },  /* 3: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1; attack 3, 4, 76 */
    { { {   -4,  33, 125,  46 },  {  -41,  24,  72,  59 } } },  /* 4: not used by a script */
    { { { -147,  21,  56,  17 },  { -125, 104,  56,  17 } } },  /* 5: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C; attack 5, 77 */
    { { {  -72,  41,  34,  11 },  {    0,   0,   0,   0 } } },  /* 6: S KICK C; attack 6 */
    { { {  -87,  11,  39,  24 },  {  -75,  53,  40,  15 } } },  /* 7: S KICK A; attack 7 */
    { { {  -73,  17,  70,  13 },  {  -60,  35,  40,  41 } } },  /* 8: M KICK C; attack 8 */
    { { { -124,  38,  28,  14 },  {  -84,  60,  28,  14 } } },  /* 9: M KICK A, UP P GUARD K S, D P GUARD K S; attack 9 */
    { { {  -71,  21,  86,  47 },  {  -49,  26,  42,  80 } } },  /* 10: L KICK C; attack 10 */
    { { { -128,  47,  71,  20 },  {  -80,  71,  59,  22 } } },  /* 11: L KICK A; attack 11 */
    { { { -113,  15,  32,  11 },  {  -98,  74,  32,  11 } } },  /* 12: KAGAMI P A; attack 12 */
    { { { -110,  35,  98,  27 },  {  -74,  33,  73,  25 } } },  /* 13: KAGAMI P A; attack 13 */
    { { { -117,  28,  74,  21 },  { -100,  42,  48,  31 } } },  /* 14: KAGAMI P A; attack 14 */
    { { { -105,  77,   0,  20 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A; attack 15 */
    { { {   36,  68,   8,  24 },  {    0,   0,   0,   0 } } },  /* 16: not used by a script */
    { { { -116,  22,   0,  24 },  {  -93,  78,   0,  24 } } },  /* 17: KAGAMI K A; attack 17 */
    { { {  -53,  26,  47,  24 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI P C; attack 4 */
    { { {  -86,  34,  24,  20 },  {  -73,  28,  42,  14 } } },  /* 19: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1; attack 18, 63, 64, 81 ... */
    { { { -123,  26, 113,   8 },  { -101,  67, 104,   7 } } },  /* 20: V JUMP P S A; attack 19 */
    { { { -135,  40,  55,  24 },  {  -93,  32,  57,  23 } } },  /* 21: V JUMP P L A, F JUMP P L A; attack 21 */
    { { {  -47,  15,  43,  21 },  {  -32,  16,  52,  24 } } },  /* 22: V JUMP K S A, F JUMP K S A; attack 22 */
    { { { -121,  12,  66,  27 },  { -107,  78,  66,  18 } } },  /* 23: V JUMP K L A; attack 24 */
    { { {  -68,  17,  36,  17 },  {  -59,  37,  48,  11 } } },  /* 24: F JUMP P S A; attack 25 */
    { { {  -60,  27,  33,  17 },  {  -53,  20,  48,  28 } } },  /* 25: F JUMP K M A; attack 27, 28 */
    { { {  -60,  27,  33,  17 },  {  -33,  20,  48,  28 } } },  /* 26: F JUMP K M A; attack 28 */
    { { {  -78,  21,  86,  14 },  {  -62,  49,  79,  10 } } },  /* 27: FUSHIN P S; attack 31 */
    { { {  -82,  30,  83,  18 },  {  -49,  25,  71,  26 } } },  /* 28: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +2; attack 32, 70, 71, 72 ... */
    { { {  -97,  36,   0,  48 },  {  -59,  32,  42,  17 } } },  /* 29: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +2; attack 32, 84 */
    { { {  -43,  19,  77,  47 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI P C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {  -92,  18,  52,  18 },  {  -73,  48,  52,  18 } } },  /* 32: M PUNCH C; attack 54 */
    { { { -141,  40,   0,  11 },  { -101,  71,   0,  11 } } },  /* 33: KAGAMI K A; attack 53 */
    { { { -136,  32,  62,  23 },  { -104,  72,  62,  23 } } },  /* 34: V JUMP K L A */
    { { {  -59,   9,  47,  20 },  {  -50,  29,  47,  20 } } },  /* 35: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1; attack 39, 57, 60, 65 ... */
    { { {  -84,  28,  63,  16 },  {  -55,  39,  52,  27 } } },  /* 36: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1; attack 40, 41, 58, 59 ... */
    { { {  -50, 102,  63,  27 },  {  -24,  53,  52,  46 } } },  /* 37: ATTACK 3 L: not started by a command; attack 42, 43, 67 */
    { { {  -37,  75,  63,  27 },  {  -24,  53,  48,  54 } } },  /* 38: ATTACK 3 L: not started by a command; attack 43, 67 */
    { { {  -63, 116,   7,  84 },  {  -24,  53,  52,  52 } } },  /* 39: ATTACK 4 S: not started by a command; attack 44, 45, 56, 73 ... */
    { { {  -52, 105,   7,  84 },  {  -26,  54,  53,  59 } } },  /* 40: ATTACK 4 S: not started by a command */
    { { {  -89,  42,  63,   8 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 10 SP: not started by a command; attack 31 */
    { { {  -77,  26,   0,  20 },  {  -53,  33,  13,  24 } } },  /* 42: not used by a script */
    { { {  -89,  32, 114,  32 },  {  -66,  51,  50,  73 } } },  /* 43: not used by a script */
    { { {  -97,  90,  51,  31 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { { -135,  35, 105,   9 },  { -100,  69,  98,  12 } } },  /* 45: V JUMP P M A; attack 20 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {   -1,  26, 125,  46 },  {  -19,  24,  98,  41 } } },  /* 47: KAGAMI P C */
    { { {  -57,  33,   0,  30 },  {  -77,  30,  27,  19 } } },  /* 48: ATTACK 8 L: not started by a command; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {  -39,  79,  63,  27 },  {  -24,  53,  58,  38 } } },  /* 51: ATTACK 3 S: not started by a command; attack 42, 43 */
    { { {  -44,  89,  63,  27 },  {  -24,  53,  54,  43 } } },  /* 52: ATTACK 3 M: not started by a command; attack 42, 43, 67 */
    { { { -139,  31, 102,  22 },  { -108,  79,  87,  17 } } },  /* 53: V JUMP K M A; attack 23 */
    { { {  -34,  18,  17,  25 },  {  -51,  23,  38,  20 } } },  /* 54: F JUMP K L A; attack 29, 30 */
    { { {  -79,  17,  41,  12 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP K S B; attack 79, 80 */
    { { {  -75,  26,  40,  15 },  {  -56,  33,  45,  21 } } },  /* 56: F JUMP P M A; attack 26 */
};

const CATCH_BOX necro_cat_box[53] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {    0,    0,    0,    0 } },  /* 1: no box */
    { {    0,    0,    0,    0 } },  /* 2: no box */
    { {    0,    0,    0,    0 } },  /* 3: no box */
    { {    0,    0,    0,    0 } },  /* 4: no box */
    { {    0,    0,    0,    0 } },  /* 5: no box */
    { {    0,    0,    0,    0 } },  /* 6: no box */
    { {    0,    0,    0,    0 } },  /* 7: no box */
    { {    0,    0,    0,    0 } },  /* 8: no box */
    { {    0,    0,    0,    0 } },  /* 9: no box */
    { {    0,    0,    0,    0 } },  /* 10: no box */
    { {    0,    0,    0,    0 } },  /* 11: no box */
    { {    0,    0,    0,    0 } },  /* 12: no box */
    { {    0,    0,    0,    0 } },  /* 13: no box */
    { {    0,    0,    0,    0 } },  /* 14: no box */
    { {    0,    0,    0,    0 } },  /* 15: no box */
    { {    0,    0,    0,    0 } },  /* 16: no box */
    { {    0,    0,    0,    0 } },  /* 17: no box */
    { {    0,    0,    0,    0 } },  /* 18: no box */
    { {    0,    0,    0,    0 } },  /* 19: no box */
    { {    0,    0,    0,    0 } },  /* 20: no box */
    { {    0,    0,    0,    0 } },  /* 21: no box */
    { {    0,    0,    0,    0 } },  /* 22: no box */
    { {    0,    0,    0,    0 } },  /* 23: no box */
    { {    0,    0,    0,    0 } },  /* 24: no box */
    { {    0,    0,    0,    0 } },  /* 25: no box */
    { {    0,    0,    0,    0 } },  /* 26: no box */
    { {    0,    0,    0,    0 } },  /* 27: no box */
    { {    0,    0,    0,    0 } },  /* 28: no box */
    { {    0,    0,    0,    0 } },  /* 29: no box */
    { {  -33,    6,    0,   16 } },  /* 30: M PUNCH A, M PUNCH C, M KICK A +3 */
    { { -131,   56,    4,   16 } },  /* 31: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    { {    0,    0,    0,    0 } },  /* 32: no box */
    { {    0,    0,    0,    0 } },  /* 33: no box */
    { {    0,    0,    0,    0 } },  /* 34: no box */
    { {    0,    0,    0,    0 } },  /* 35: no box */
    { {    0,    0,    0,    0 } },  /* 36: no box */
    { {    0,    0,    0,    0 } },  /* 37: no box */
    { {    0,    0,    0,    0 } },  /* 38: no box */
    { {    0,    0,    0,    0 } },  /* 39: no box */
    { {    0,    0,    0,    0 } },  /* 40: no box */
    { {  -86,   61,    0,   16 } },  /* 41: ATTACK 7 S: not started by a command */
    { {    0,    0,    0,    0 } },  /* 42: no box */
    { {    0,    0,    0,    0 } },  /* 43: no box */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {    0,    0,    0,    0 } },  /* 45: no box */
    { {  -37,   10,    0,   16 } },  /* 46: L PUNCH A, L KICK A, L KICK C */
    { {    0,    0,    0,    0 } },  /* 47: no box */
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { { -127,   40,    4,   16 } },  /* 49: not used by a script */
    { { -123,   40,    4,   16 } },  /* 50: not used by a script */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
};

const CAUGHT_BOX necro_cau_box[17] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -27,   54,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +116 */
    { {  -31,   58,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +30 */
    { {  -25,   50,   68,   48 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +29 */
    { {  -34,   48,   80,   28 } },  /* 4: not used by a script */
    { {  -24,   48,   83,   28 } },  /* 5: not used by a script */
    { {  -31,   48,   84,   28 } },  /* 6: not used by a script */
    { {   -7,   48,   84,   28 } },  /* 7: not used by a script */
    { {  -32,   48,   83,   28 } },  /* 8: not used by a script */
    { {  -55,   48,    0,    8 } },  /* 9: KAGAMI P A */
    { {  -28,   35,   56,   58 } },  /* 10: not used by a script */
    { {  -24,   48,   44,   64 } },  /* 11: not used by a script */
    { {  -22,   48,   42,   37 } },  /* 12: AIR S, AIR M, AIR L +39 */
    { {  -35,   62,    0,    8 } },  /* 13: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   -8,   24 } },  /* 14: DASH HUMIKOMI, DASH TOBINOKI, P BREAK ZUJOU +1 */
    { {  -35,   74,    0,   16 } },  /* 15: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    { {  -60,   96,   48,   27 } },  /* 16: V JUMP K S B */
};
