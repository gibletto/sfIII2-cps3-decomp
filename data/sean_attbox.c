/*
 * SEAN_ATTBOX.C  Sean's attack, catch and caught boxes
 *
 * Selected per animation frame through sean_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX sean_att_box[68] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -54,  26,  28,  30 },  {    0,   0,   0,   0 } } },  /* 1: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +5; attack 1, 41, 43, 69 ... */
    { { {  -29,  29,  34,  77 },  {  -46,  24,  48,  29 } } },  /* 2: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +5; attack 2, 42, 46, 74 ... */
    { { {  -40,  18,  58,  16 },  {  -26,  14, 122,  20 } } },  /* 3: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command */
    { { {  -52,  11,  78,  18 },  {  -38,  12,  68,  20 } } },  /* 4: not used by a script */
    { { {  -70,  52,  74,  12 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH A; attack 4 */
    { { {  -60,  38,  44,  27 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A; attack 5 */
    { { {  -86,  65,  64,  18 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B, UP P GUARD P S; attack 6 */
    { { {  -69,  44,  49,  33 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, UP P GUARD P L; attack 7 */
    { { {  -51,  31,  80,  33 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, UP P GUARD P L; attack 7, 8 */
    { { {  -74,  28,  78,  16 },  {  -47,  25,  77,  13 } } },  /* 10: not used by a script */
    { { {  -62,  38,  11,  36 },  {    0,   0,   0,   0 } } },  /* 11: S KICK A; attack 10 */
    { { {  -75,  46,  65,  15 },  {  -35,  35,  59,  13 } } },  /* 12: not used by a script */
    { { {  -87,  32,  12,  20 },  {  -64,  42,  34,  18 } } },  /* 13: M KICK A; attack 12 */
    { { {  -88,  63,   7,  14 },  {    0,   0,   0,   0 } } },  /* 14: not used by a script */
    { { {  -78,  44,  48,  24 },  {    0,   0,   0,   0 } } },  /* 15: L KICK A; attack 13 */
    { { {  -44,  28,  50,  35 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH C, follow-up of L PUNCH A; attack 86, 97 */
    { { {  -66,  28,  25,  31 },  {    0,   0,   0,   0 } } },  /* 17: L PUNCH C, follow-up of L PUNCH A; attack 87, 98 */
    { { {  -59,  19,  32,  20 },  {    0,   0,   0,   0 } } },  /* 18: L PUNCH C, follow-up of L PUNCH A; attack 7 */
    { { {  -85,  33,  74,  10 },  {  -52,  37,  63,  15 } } },  /* 19: L KICK B; attack 17 */
    { { {  -78,  42,  74,  14 },  {  -50,  39,  63,  12 } } },  /* 20: not used by a script */
    { { {  -62,  54,  41,  13 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 19 */
    { { {  -72,  52,  40,  14 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 20 */
    { { {  -60,  36,  30,  35 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A; attack 21 */
    { { {  -23,  20,  89,  33 },  {  -38,  23,  61,  28 } } },  /* 24: KAGAMI P A; attack 22 */
    { { {  -80,  54,   0,   5 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 23 */
    { { {  -86,  76,   0,   5 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI K A, UP P GUARD K S; attack 24 */
    { { {  -96,  75,   0,   6 },  {  -57,  45,   2,  21 } } },  /* 27: KAGAMI K A; attack 25 */
    { { {  -47,  19,  59,  23 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -90,  60,  91,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P L A; attack 34 */
    { { {  -87,  65,  57,  18 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP K M A; attack 30 */
    { { {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 } } },  /* 31: not used by a script */
    { { {  -77,  40,  49,  23 },  {    0,   0,   0,   0 } } },  /* 32: F JUMP P L A; attack 34 */
    { { {  -38,  18,  42,  16 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP K S A, F JUMP K S A; attack 35 */
    { { {  -80,  18,  38,  21 },  {  -63,  77,  52,  13 } } },  /* 34: F JUMP K M A; attack 36 */
    { { {  -71,  42,  58,  20 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P M A, F JUMP P M A; attack 27, 33 */
    { { {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 } } },  /* 36: not used by a script */
    { { {  -66,  48,  80,  20 },  {  -81,  25,  93,  18 } } },  /* 37: V JUMP K L A; attack 31 */
    { { {  -47,  40,  25,  48 },  {    0,   0,   0,   0 } } },  /* 38: exca 17, ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 60 */
    { { {  -75,  55,  56,  14 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +2; attack 56, 57, 58, 84 ... */
    { { { -108,  39,  52,  13 },  {  -72,  32,  55,  13 } } },  /* 40: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {  -26,  30,  90,  29 },  {    0,   0,   0,   0 } } },  /* 42: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -68,  47,  50,  11 },  {    0,   0,   0,   0 } } },  /* 43: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +2; attack 49, 50, 94 */
    { { {  -85,  64,  36,  40 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 68 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { {   23,  31,  85,  10 },  {    9,  27,  75,  15 } } },  /* 46: not used by a script */
    { { {  -66,  18,  72,  16 },  {  -48,  40,  75,  10 } } },  /* 47: not used by a script */
    { { {  -79,  21,  31,  30 },  {  -58,  30,   0,  64 } } },  /* 48: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 64, 73 */
    { { {  -86,  16,  52,  18 },  {  -70,  47,  54,  17 } } },  /* 49: F JUMP K L A; attack 37 */
    { { { -100,  37,   0,  19 },  {  -57,  45,   2,  21 } } },  /* 50: not used by a script */
    { { {  -79,  58,  24,  72 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 71, 72, 96 */
    { { {  -96, 109,  30,  51 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 61, 62 */
    { { {  -51,  55,  41,  85 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 67 */
    { { {  -92,  83,  34,  73 },  {    0,   0,   0,   0 } } },  /* 54: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    2,  34,  80,  41 },  {    0,   0,   0,   0 } } },  /* 56: not used by a script */
    { { {  -44,  42, 106,  24 },  {    0,   0,   0,   0 } } },  /* 57: not used by a script */
    { { {  -66,  58,  91,  29 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU); attack 78 */
    { { {  -65,  90,  88,  29 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -49,  26,  29,  49 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 10 S: not started by a command; attack 77 */
    { { {  -71,  35,  87,  16 },  {  -34,  15,  66,  31 } } },  /* 61: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN); attack 85, 90 */
    { { {  -41,  81,   0,  24 },  {    0,   0,   0,   0 } } },  /* 62: OKIAGARI P S; attack 76 */
    { { {  -42,  27,  42,  33 },  {  -30,  26, 100,  39 } } },  /* 63: OKIAGARI P S; attack 2, 76 */
    { { {  -66,  47,  74,  17 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU); attack 78, 83 */
    { { {  -70,  47,  62,  11 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +1; attack 49, 93 */
    { { {  -85,  33,  76,  30 },  {  -57,  37,  64,  15 } } },  /* 66: follow-up of M PUNCH A; attack 9 */
    { { {  -83,  31,  74,  20 },  {  -57,  35,  64,  11 } } },  /* 67: follow-up of M PUNCH A */
};

const CATCH_BOX sean_cat_box[65] = {
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
    { {  -31,    6,    0,   16 } },  /* 41: M PUNCH A, M PUNCH B, M KICK A +3 */
    { {    0,    0,    0,    0 } },  /* 42: no box */
    { {    0,    0,    0,    0 } },  /* 43: no box */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {  -77,   33,    0,   16 } },  /* 45: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { {    0,    0,    0,    0 } },  /* 46: no box */
    { {    0,    0,    0,    0 } },  /* 47: no box */
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { {    0,    0,    0,    0 } },  /* 49: no box */
    { {    0,    0,    0,    0 } },  /* 50: no box */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
    { {    0,    0,    0,    0 } },  /* 53: no box */
    { {    0,    0,    0,    0 } },  /* 54: no box */
    { {  -35,   10,    0,   16 } },  /* 55: L PUNCH A, L PUNCH C, L KICK A +1 */
    { {    0,    0,    0,    0 } },  /* 56: no box */
    { {    0,    0,    0,    0 } },  /* 57: no box */
    { {    0,    0,    0,    0 } },  /* 58: no box */
    { {    0,    0,    0,    0 } },  /* 59: no box */
    { {    0,    0,    0,    0 } },  /* 60: no box */
    { {    0,    0,    0,    0 } },  /* 61: no box */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
};

const CAUGHT_BOX sean_cau_box[21] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +125 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +34 */
    { {  -25,   50,   48,   40 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP K S A +20 */
    { {  -25,   50,   48,   40 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +20 */
    { {  -42,   42,    0,   16 } },  /* 5: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { {  -21,   36,    0,   90 } },  /* 6: not used by a script */
    { {  -36,   36,    0,   90 } },  /* 7: not used by a script */
    { {  -29,   54,    0,   16 } },  /* 8: S KICK A, M KICK A */
    { {  -33,   58,    0,    8 } },  /* 9: KAGAMI P A, KAGAMI K A */
    { {  -18,   45,   48,   45 } },  /* 10: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command +5 */
    { {  -28,   44,   48,   47 } },  /* 11: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -27,   47,   52,   45 } },  /* 12: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +3 */
    { {  -25,   50,   48,   40 } },  /* 13: TOUKETSU A, AIR S, AIR M +42 */
    { {   -8,   40,   66,   25 } },  /* 14: not used by a script */
    { {  -46,   80,    0,   16 } },  /* 15: ATTACK 4 S: SA I 23623+P (plain script), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { {  -41,   81,    0,   16 } },  /* 16: OKIAGARI P S */
    { {  -36,   73,   46,   49 } },  /* 17: OKIAGARI P S */
    { {  -38,   63,    0,   16 } },  /* 18: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -35,   70,    0,   16 } },  /* 19: not used by a script */
    { {  -25,   50,   24,   40 } },  /* 20: PARING AIR F, PARING AIR B */
};
