/*
 * ELENA_ATTBOX.C  Elena's attack, catch and caught boxes
 *
 * Selected per animation frame through elena_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX elena_att_box[79] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -96,  71,  30,  11 },  {    0,   0,   0,   0 } } },  /* 1: KAGAMI P A; attack 13 */
    { { {  -88,  34,   0,  14 },  {  -54,  34,  11,  12 } } },  /* 2: KAGAMI K A; attack 16 */
    { { { -104,  89,  34,  16 },  {    0,   0,   0,   0 } } },  /* 3: KAGAMI P A; attack 14 */
    { { {  -64,  23,  81,  22 },  {  -42,  27,  52,  31 } } },  /* 4: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP); attack 15, 46, 96 */
    { { {  -98,  78,  28,  14 },  {    0,   0,   0,   0 } } },  /* 5: KAGAMI K A; attack 17 */
    { { {  -41,  22,  53,  14 },  {    0,   0,   0,   0 } } },  /* 6: V JUMP P S A, F JUMP P S A; attack 19 */
    { { {  -75,  56,  74,  16 },  {  -97,  22,  78,  16 } } },  /* 7: V JUMP P M A, F JUMP P M A; attack 20 */
    { { {  -88,  23,  45,  16 },  {  -80,  57,  54,  12 } } },  /* 8: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A / F JUMP P M A; attack 21, 98 */
    { { {  -56,  26,  55,  11 },  {  -87,  35,  50,  10 } } },  /* 9: V JUMP K S A, F JUMP K S A; attack 22 */
    { { {  -91,  32,  51,  11 },  {  -59,  72,  54,  13 } } },  /* 10: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A / F JUMP P S A; attack 23, 72 */
    { { {  -83,  15,  42,  22 },  {  -72,  54,  53,  18 } } },  /* 11: V JUMP K L A, F JUMP K L A; attack 25 */
    { { {  -88,  67,  12,  19 },  {  -94,  30,   0,  30 } } },  /* 12: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA); attack 18, 45 */
    { { {  -32,  18,  64,  28 },  {  -20,  20,  40,  48 } } },  /* 13: OKIAGARI P S; attack 12 */
    { { {  -62,  20, 112,  26 },  {    0,   0,   0,   0 } } },  /* 14: UP P GUARD P L; attack 61 */
    { { {  -92,  28,  68,  40 },  {  -68,  48,  76,  44 } } },  /* 15: UP P GUARD P L; attack 62 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: no box */
    { { {  -61,  20,  20,  56 },  {  -60,  30,  60,  16 } } },  /* 17: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 28 */
    { { {  -63,  46,  60,  24 },  {  -80,  24,  31,  51 } } },  /* 18: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 29 */
    { { {  -83,  64,  73,  17 },  {  -57,  38,  52,  20 } } },  /* 19: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN); attack 27 */
    { { {    0,   0,   0,   0 },  {  -32,  18,  68,  56 } } },  /* 20: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1; attack 32, 99 */
    { { {  -74,  26, 101,  19 },  {  -53,  40,  72,  36 } } },  /* 21: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1; attack 33, 100 */
    { { {  -82,  28,  96,  14 },  {  -70,  52,  76,  24 } } },  /* 22: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU), ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU); attack 34, 101 */
    { { {  -22,  16,  92,  56 },  {    0,   0,   0,   0 } } },  /* 23: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1; attack 35, 102 */
    { { { -108,  44,  62,  27 },  {  -64,  45,  56,  24 } } },  /* 24: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1; attack 36, 37, 38, 93 ... */
    { { {   39,  56,  40,  22 },  {    0,   0,   0,   0 } } },  /* 25: follow-up of APPEAR 1, follow-up of SP WIN 3, follow-up of SP WIN 4; attack 65 */
    { { {  -88,  74,  52,  16 },  {    0,   0,   0,   0 } } },  /* 26: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA); attack 1, 44 */
    { { {  -71,  30,  81,  14 },  {  -48,  28,  54,  31 } } },  /* 27: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA); attack 2, 42 */
    { { {  -97,  37,  78,  16 },  {  -60,  43,  64,  23 } } },  /* 28: L PUNCH A; attack 3 */
    { { {  -75,  63,  49,  23 },  {    0,   0,   0,   0 } } },  /* 29: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), UP P GUARD P L; attack 4, 47 */
    { { {  -68,  27,  79,  13 },  {  -46,  37,  64,  18 } } },  /* 30: S PUNCH A, UP P GUARD P S; attack 5, 59 */
    { { {  -71,  32,  73,  19 },  {  -49,  42,  50,  33 } } },  /* 31: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 97 */
    { { {  -59,  16,   0,  24 },  {  -51,  23,  12,  21 } } },  /* 32: S KICK A, D P GUARD P S, FUSHIN P S +1; attack 7, 40, 63 */
    { { {  -56,  35,   0,  19 },  {  -76,  19,   0,  13 } } },  /* 33: D P GUARD P M, L KICK C, KAGAMI K C; attack 8, 64 */
    { { {   -8,  18,  84,  48 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {   42,  60,  90,  18 },  {   22,  48,  80,  12 } } },  /* 35: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1; attack 53, 54, 55, 91 */
    { { {   84,  18,  62,  22 },  {   44,  40,  54,  12 } } },  /* 36: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1; attack 56, 57, 58, 92 */
    { { { -100,  38,  56,  16 },  {  -62,  44,  46,  16 } } },  /* 37: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA); attack 9, 41, 60 */
    { { {  -64,  24,  12,  64 },  {  -52,  32,  56,  26 } } },  /* 38: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -90,  26,  48,  48 },  {  -76,  64,  70,  32 } } },  /* 39: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA); attack 52 */
    { { {  -72,  88,  82,  45 },  {    8,  56, 102,  32 } } },  /* 40: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA); attack 52 */
    { { {  -82,  26,  88,  23 },  {  -60,  44,  72,  16 } } },  /* 41: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -46,  18,  74,  40 },  {    0,   0,   0,   0 } } },  /* 42: V JUMP K L A, F JUMP K L A; attack 24 */
    { { {  -76,  24,   0,  36 },  {  -56,  48,  32,  28 } } },  /* 43: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA); attack 70 */
    { { {  -80,  20,  24,  32 },  {  -64,  59,  48,  28 } } },  /* 44: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA); attack 70 */
    { { {  -80,  20,  64,  24 },  {  -60,  57,  62,  20 } } },  /* 45: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -87,  55,  70,  36 },  {  -55,  50,  65,  30 } } },  /* 46: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA); attack 50 */
    { { {  -76,  52,  97,  28 },  {  -54,  49,  82,  29 } } },  /* 47: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {  -44,  27,  65,  12 },  {  -26,  20,  40,  29 } } },  /* 49: M PUNCH A; attack 68 */
    { { {  -66,  28,  32,  22 },  {  -52,  28,  53,  12 } } },  /* 50: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA); attack 4 */
    { { {  -47,  29,  21,  31 },  {    0,   0,   0,   0 } } },  /* 51: L KICK A; attack 4 */
    { { {  -59,  24,  20,  49 },  {  -52,  32,  61,  14 } } },  /* 52: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN); attack 30 */
    { { {  -76,  54,  73,  24 },  {  -85,  24,  48,  43 } } },  /* 53: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN); attack 31 */
    { { {  -52,  38,  12,  42 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN); attack 51, 69 */
    { { {  -64,  24,  20,  56 },  {  -52,  32,  64,  18 } } },  /* 55: not used by a script */
    { { {  -76,  54,  78,  24 },  {  -90,  24,  48,  48 } } },  /* 56: not used by a script */
    { { {  -72,  72,  92,  20 },  {    8,  56, 102,  32 } } },  /* 57: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {  -48,  48,  42,  20 },  {  -24,  48,  24,  20 } } },  /* 59: not used by a script */
    { { {  -48,  48,  42,  20 },  {  -24,  48,  24,  20 } } },  /* 60: not used by a script */
    { { {  -84,  36,  24,  36 },  {  -72,  48,   8,  22 } } },  /* 61: not used by a script */
    { { {  -54,  26,  40,  28 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 39 */
    { { {  -44,  21,  33,  31 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 7 L: not started by a command; attack 71 */
    { { {  -65,  56,  57,  31 },  { -100,  48,  70,  24 } } },  /* 64: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA); attack 67 */
    { { { -121,  43,  62,  16 },  {  -90,  53,  51,  20 } } },  /* 65: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2; attack 73, 74, 77, 78 ... */
    { { { -124,  43,  63,  25 },  {  -80,  48,  42,  36 } } },  /* 66: not used by a script */
    { { { -115,  28,  63,  15 },  {  -87,  35,  56,  17 } } },  /* 67: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 75, 79, 83 */
    { { { -143,  36,  61,  17 },  { -106,  46,  52,  17 } } },  /* 68: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -132,  47,  67,  19 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { { -140,  50,  50,  17 },  {  -90,  42,  42,  17 } } },  /* 70: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 76, 80, 84 */
    { { {  -95,  45,  61,  22 },  {    0,   0,   0,   0 } } },  /* 71: not used by a script */
    { { {  -96,  64,  20,  12 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 8 L: not started by a command, WIN 1, WIN 6; attack 85 */
    { { {  -12,  10, 116,  24 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 8 L: not started by a command, WIN 1, WIN 6; attack 86 */
    { { {  -60,  38,  32,  32 },  {  -40,  28,  18,  22 } } },  /* 74: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 87 */
    { { {  -64,  38,  48,  32 },  {  -52,  28,  32,  22 } } },  /* 75: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 88 */
    { { {  -70,  30,  64,  34 },  {  -62,  26,  46,  22 } } },  /* 76: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 89 */
    { { {  -58,  24,  88,  36 },  {  -68,  22,  60,  36 } } },  /* 77: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 90 */
    { { {  -64,  40,  32,  20 },  {  -68,  20,  48,  16 } } },  /* 78: not used by a script */
};

const CATCH_BOX elena_cat_box[65] = {
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
    { {  -31,    6,    0,   16 } },  /* 16: M PUNCH A, M PUNCH C */
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
    { {    0,    0,    0,    0 } },  /* 30: no box */
    { {    0,    0,    0,    0 } },  /* 31: no box */
    { {    0,    0,    0,    0 } },  /* 32: no box */
    { {    0,    0,    0,    0 } },  /* 33: no box */
    { {    0,    0,    0,    0 } },  /* 34: no box */
    { {    0,    0,    0,    0 } },  /* 35: no box */
    { {    0,    0,    0,    0 } },  /* 36: no box */
    { {    0,    0,    0,    0 } },  /* 37: no box */
    { {    0,    0,    0,    0 } },  /* 38: no box */
    { {    0,    0,    0,    0 } },  /* 39: no box */
    { {    0,    0,    0,    0 } },  /* 40: no box */
    { {    0,    0,    0,    0 } },  /* 41: no box */
    { {    0,    0,    0,    0 } },  /* 42: no box */
    { {    0,    0,    0,    0 } },  /* 43: no box */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {    0,    0,    0,    0 } },  /* 45: no box */
    { {    0,    0,    0,    0 } },  /* 46: no box */
    { {    0,    0,    0,    0 } },  /* 47: no box */
    { {  -68,   68,    0,   32 } },  /* 48: not used by a script */
    { {    0,    0,    0,    0 } },  /* 49: no box */
    { {    0,    0,    0,    0 } },  /* 50: no box */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
    { {    0,    0,    0,    0 } },  /* 53: no box */
    { {    0,    0,    0,    0 } },  /* 54: no box */
    { {    0,    0,    0,    0 } },  /* 55: no box */
    { {    0,    0,    0,    0 } },  /* 56: no box */
    { {    0,    0,    0,    0 } },  /* 57: no box */
    { {  -35,   10,    0,   16 } },  /* 58: L PUNCH A */
    { {    0,    0,    0,   16 } },  /* 59: not used by a script */
    { {    0,    0,    0,   16 } },  /* 60: not used by a script */
    { {    0,    0,    0,   16 } },  /* 61: not used by a script */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
};

const CAUGHT_BOX elena_cau_box[10] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: KAMAE, STAND UP, WALK END +116 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, PARING DOWN +42 */
    { {  -23,   46,   56,   44 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +36 */
    { {  -25,   50,    0,    8 } },  /* 4: not used by a script */
    { {  -23,   46,   28,   44 } },  /* 5: AIR S, AIR M, AIR L +36 */
    { {  -31,   62,    0,   16 } },  /* 6: DASH HUMIKOMI */
    { {  -33,   58,    0,    8 } },  /* 7: KAGAMI P A, KAGAMI K A */
    { {  -25,   50,   56,   41 } },  /* 8: L KICK A, UP P GUARD P L, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { {  -23,   46,   38,   44 } },  /* 9: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +6 */
};
