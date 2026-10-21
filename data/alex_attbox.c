/*
 * ALEX_ATTBOX.C  Alex's attack, catch and caught boxes
 *
 * Selected per animation frame through alex_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX alex_att_box[70] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -76,  20,  47,  26 },  {  -56,  23,  43,  30 } } },  /* 1: S PUNCH A; attack 1 */
    { { {  -86,  19,  74,  15 },  {  -67,  38,  72,  17 } } },  /* 2: S PUNCH B; attack 2 */
    { { {  -82,  21,  72,  26 },  {  -62,  25,  68,  28 } } },  /* 3: nmca 33, M PUNCH A; attack 3 */
    { { {  -80,  18,  76,  18 },  {  -62,  18,  72,  18 } } },  /* 4: not used by a script */
    { { {  -81,  52,  60,  22 },  {  -60,  31,  82,  14 } } },  /* 5: L PUNCH A; attack 7 */
    { { {  -46,  27, 101,  25 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH C; attack 5 */
    { { {  -91,  26,  69,  24 },  {  -66,  33,  62,  23 } } },  /* 7: M PUNCH C, UP P GUARD P S; attack 5 */
    { { {  -87,  30,   0,  23 },  {  -69,  25,  19,  15 } } },  /* 8: S KICK A; attack 10 */
    { { {  -62,  38,  49,  25 },  {  -41,  42,  19,  28 } } },  /* 9: M KICK A; attack 11 */
    { { { -123,  41,  50,  17 },  {  -82,  64,  46,  17 } } },  /* 10: M KICK B; attack 13 */
    { { {  -58,  44,  33,  15 },  {  -64,  25,  48,  20 } } },  /* 11: L PUNCH A; attack 9 */
    { { {  -73,  22,  33,  19 },  {  -50,  31,  40,  22 } } },  /* 12: M PUNCH C, UP P GUARD P S; attack 8 */
    { { {  -62,  45,  43,  31 },  {  -37,  37,  25,  27 } } },  /* 13: not used by a script */
    { { { -108,  32,  70,  20 },  {  -72,  42,  66,  20 } } },  /* 14: not used by a script */
    { { {  -92,  25,  42,   9 },  {  -67,  44,  41,  11 } } },  /* 15: KAGAMI P A; attack 15 */
    { { { -110,  29,  43,  16 },  {  -81,  51,  41,  13 } } },  /* 16: KAGAMI P A; attack 16 */
    { { {  -43,  31,  80,  15 },  {  -50,  28,  39,  41 } } },  /* 17: KAGAMI P A; attack 17 */
    { { {  -47,  22,  99,  17 },  {  -38,  53, 110,  17 } } },  /* 18: KAGAMI P A; attack 18 */
    { { {  -90,  34,   0,  21 },  {  -56,  40,  15,  19 } } },  /* 19: KAGAMI K A; attack 19 */
    { { { -105,  39,   0,  21 },  {  -66,  36,  13,  19 } } },  /* 20: KAGAMI K A, UP P GUARD K S; attack 20 */
    { { { -108,  40,   0,  20 },  {  -68,  52,   0,  24 } } },  /* 21: KAGAMI K A; attack 21 */
    { { { -116,  35,  30,  18 },  {  -81,  50,  23,  19 } } },  /* 22: not used by a script */
    { { {  -77,  21,  46,  15 },  {  -55,  22,  57,  18 } } },  /* 23: V JUMP P S A; attack 23, 24 */
    { { {  -92,  26,  53,  17 },  {  -66,  32,  62,  18 } } },  /* 24: V JUMP P M A; attack 23, 25 */
    { { {  -71,  26,  34,  19 },  {  -45,  25,  44,  19 } } },  /* 25: ATTACK 9 S: not started by a command; attack 81 */
    { { {  -98,  40,  82,  12 },  {  -72,  40,  72,  12 } } },  /* 26: FUSHIN P S */
    { { {  -92,  56,  98,  27 },  {  -76,  46,  76,  22 } } },  /* 27: OKIAGARI P S; attack 27 */
    { { {  -46,  59, 111,  20 },  {  -79,  58,  96,  21 } } },  /* 28: OKIAGARI P S */
    { { {  -35,  58, 106,  23 },  {    0,   0,   0,   0 } } },  /* 29: not used by a script */
    { { {  -89,  29,  66,  49 },  {  -79,  31,  50,  16 } } },  /* 30: V JUMP P L A; attack 29 */
    { { {  -51,  24,  63,  18 },  {  -58,  31,  40,  23 } } },  /* 31: V JUMP P L A; attack 30 */
    { { {  -46,  15,  42,  20 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP K S A; attack 31 */
    { { {  -97,  52,  58,  18 },  {  -44,  32,  56,  20 } } },  /* 33: V JUMP K M A; attack 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {  -67,  32,  60,  24 },  {  -35,  26,  60,  15 } } },  /* 36: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command; attack 38 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -95,  21,  63,  25 },  {  -74,  69,  63,  22 } } },  /* 38: L KICK A; attack 14, 42 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {  -48,  50,  83,  28 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -48,  54,  -2, 103 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {  -34,  44,   0,  88 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) +2; attack 73, 74, 75, 85 */
    { { { -106,  58,  69,  17 },  {  -48,  33,  63,  23 } } },  /* 48: V JUMP K L A; attack 33 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {  -97,  35,  63,  30 },  {  -75,  62,  76,  26 } } },  /* 50: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 64 */
    { { {  -89,  75,  49,  23 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 65 */
    { { { -102,  32,  58,  34 },  {  -70,  39,  44,  53 } } },  /* 52: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 66 */
    { { {  -76,  61,  83,  19 },  {  -99,  85,  70,  22 } } },  /* 53: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 67 */
    { { {  -97,  35,  63,  30 },  {  -75,  62,  76,  26 } } },  /* 54: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 68 */
    { { {  -89,  75,  49,  23 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 69 */
    { { { -102,  35,  63,  30 },  {  -70,  39,  44,  53 } } },  /* 56: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 70 */
    { { {  -76,  61,  83,  19 },  {  -99,  85,  70,  22 } } },  /* 57: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 71 */
    { { {  -60,  30,  48,  18 },  {  -91,  61,  66,  18 } } },  /* 58: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI); attack 39, 80 */
    { { {  -91,  60,  73,  17 },  {    0,   0,   0,   0 } } },  /* 59: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI); attack 39 */
    { { {  -63,  33,  48,  18 },  {  -93,  63,  66,  18 } } },  /* 60: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI); attack 52 */
    { { {  -95,  65,  73,  17 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -67,  37,  48,  18 },  {  -97,  67,  66,  18 } } },  /* 62: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI); attack 53, 84 */
    { { {  -99,  69,  73,  17 },  {  -64,  44,  86,  13 } } },  /* 63: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI); attack 90 */
    { { {  -59,  28,  62,  23 },  {  -31,  22,  62,  15 } } },  /* 64: F JUMP P L B, SP F JP L P B, FUSHIN P S; attack 26 */
    { { {  -51,  20,  64,  19 },  {  -31,  20,  64,  15 } } },  /* 65: F JUMP P L B, SP F JP L P B */
    { { {  -82,  29,  46,  51 },  {  -53,  26,  59,  33 } } },  /* 66: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP); attack 87, 88, 89 */
    { { {  -73,  41,  36,  31 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP); attack 91 */
    { { {  -93,  60,  95,  23 },  {  -70,  38,  78,  17 } } },  /* 68: not used by a script */
    { { {  -92,  39,  46,  51 },  {  -53,  26,  59,  33 } } },  /* 69: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP); attack 92 */
};

const CATCH_BOX alex_cat_box[66] = {
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
    { { -103,   72,    8,    8 } },  /* 29: L PUNCH C */
    { {    0,    0,    0,    0 } },  /* 30: no box */
    { {    0,    0,    0,    0 } },  /* 31: no box */
    { {    0,    0,    0,    0 } },  /* 32: no box */
    { {    0,    0,    0,    0 } },  /* 33: no box */
    { {  -36,    6,    0,   16 } },  /* 34: M PUNCH A, M PUNCH C, TUKAMIKAKARI A */
    { {  -76,   46,    0,   16 } },  /* 35: ATTACK 3 S: 6(123)4+P light (plain script) */
    { {    0,    0,    0,    0 } },  /* 36: no box */
    { {  -72,   42,    0,   16 } },  /* 37: ATTACK 3 M: 6(123)4+P medium (plain script) */
    { {    0,    0,    0,    0 } },  /* 38: no box */
    { {  -40,   10,    0,   16 } },  /* 39: L PUNCH A, L PUNCH C */
    { {  -68,   38,    0,   16 } },  /* 40: ATTACK 3 L: 6(123)4+P heavy/EX (plain script) */
    { {    0,    0,    0,    0 } },  /* 41: no box */
    { {  -44,   32,   -8,  100 } },  /* 42: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 9 S: not started by a command */
    { {  -51,   43,   52,   40 } },  /* 43: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {    0,    0,    0,    0 } },  /* 45: no box */
    { {  -98,   45,   -8,   78 } },  /* 46: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    { {    0,    0,    0,    0 } },  /* 47: no box */
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { {  -96,   68,    0,   16 } },  /* 49: ATTACK 4 S: SA I 360+P (plain script), ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { {    0,    0,    0,    0 } },  /* 50: no box */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
    { {    0,    0,    0,    0 } },  /* 53: no box */
    { {    0,    0,    0,    0 } },  /* 54: no box */
    { {    0,    0,    0,    0 } },  /* 55: no box */
    { {    0,    0,    0,    0 } },  /* 56: no box */
    { {    0,    0,    0,    0 } },  /* 57: no box */
    { {    0,    0,    0,    0 } },  /* 58: no box */
    { {    0,    0,    0,    0 } },  /* 59: no box */
    { {    0,    0,    0,    0 } },  /* 60: no box */
    { {    0,    0,    0,    0 } },  /* 61: no box */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
    { {    0,    0,    0,    0 } },  /* 65: no box */
};

const CAUGHT_BOX alex_cau_box[18] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -30,   61,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +116 */
    { {  -34,   65,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +34 */
    { {  -30,   61,   45,   58 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +34 */
    { {  -46,   61,    0,   16 } },  /* 4: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { {   -7,   41,   54,   21 } },  /* 5: V JUMP K L A, P BREAK ZUJOU, P BREAK DOWN +1 */
    { {  -46,   93,    0,    8 } },  /* 6: not used by a script */
    { {  -23,   47,   92,   50 } },  /* 7: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 8: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 9: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -27,   53,  103,   43 } },  /* 10: not used by a script */
    { {  -36,   56,   63,   32 } },  /* 11: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command +1 */
    { {  -21,   45,   45,   44 } },  /* 12: AIR S, AIR M, AIR L +43 */
    { {  -35,   70,    0,   16 } },  /* 13: PIYO */
    { {  -24,   55,   45,   40 } },  /* 14: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 9 S: not started by a command, ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +2 */
    { {  -36,   67,    0,   16 } },  /* 15: S KICK A */
    { {  -38,   69,    0,    8 } },  /* 16: KAGAMI P A, KAGAMI K A, UP P GUARD K S */
    { {  -48,   88,    0,   16 } },  /* 17: L KICK A */
};
