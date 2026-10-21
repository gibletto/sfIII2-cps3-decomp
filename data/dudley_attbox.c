/*
 * DUDLEY_ATTBOX.C  Dudley's attack, catch and caught boxes
 *
 * Selected per animation frame through dudley_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX dudley_att_box[72] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -87,  16,  80,  13 },  {  -72,  47,  80,  13 } } },  /* 1: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1; attack 1, 65 */
    { { { -102,  18,  76,  16 },  {  -84,  56,  76,  16 } } },  /* 2: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +5; attack 4, 66, 80, 84 ... */
    { { {  -70,  47,  72,  19 },  {  -52,  29,  56,  16 } } },  /* 3: S KICK A; attack 3 */
    { { {  -65,  27,  71,  21 },  {  -54,  30,  53,  18 } } },  /* 4: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4; attack 5, 55, 67, 73 ... */
    { { {  -56,  16, 106,  22 },  {  -65,  22,  88,  18 } } },  /* 5: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4; attack 55, 67 */
    { { {  -88,  19,  60,  16 },  {  -69,  47,  60,  16 } } },  /* 6: S PUNCH C; attack 7 */
    { { {  -84,  60,  63,  16 },  {  -65,  41,  48,  15 } } },  /* 7: M KICK C; attack 8 */
    { { {  -59,  33,  39,  20 },  {    0,   0,   0,   0 } } },  /* 8: L KICK A, atca 162, follow-up of M KICK A; attack 9, 83, 86 */
    { { {  -87,  61,  65,  21 },  {  -69,  43,  47,  18 } } },  /* 9: L KICK A, atca 162, follow-up of M KICK A +1; attack 56 */
    { { {  -70,  22,  66,  36 },  {  -46,  20,  66,  17 } } },  /* 10: L KICK A, atca 162, follow-up of M KICK A +5; attack 49, 106 */
    { { { -108,  28,  64,  21 },  {  -80,  54,  55,  30 } } },  /* 11: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A / M KICK C +3; attack 11, 75, 82 */
    { { {  -74,  22,  45,  15 },  {  -52,  28,  45,  12 } } },  /* 12: KAGAMI P A; attack 12 */
    { { {  -87,  19,  51,  22 },  {  -68,  48,  52,  10 } } },  /* 13: KAGAMI P A, follow-up of JUDGMENT WAIT; attack 13, 109 */
    { { {  -76,  34,  49,  24 },  {  -60,  32,  33,  25 } } },  /* 14: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3; attack 14, 57, 71, 87 ... */
    { { {  -69,  29,  94,  25 },  {  -74,  19,  84,  17 } } },  /* 15: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3; attack 15, 57, 72, 88 ... */
    { { {  -73,  23,  24,  18 },  {  -58,  32,  33,  16 } } },  /* 16: KAGAMI K A; attack 16 */
    { { {  -70,  23,   0,  23 },  {  -52,  22,  19,  17 } } },  /* 17: KAGAMI K A, UP P GUARD K S; attack 17 */
    { { {  -70,  22,   0,  21 },  {  -52,  18,  16,  14 } } },  /* 18: KAGAMI K A; attack 18 */
    { { {  -69,  43,  93,  11 },  {    0,   0,   0,   0 } } },  /* 19: V JUMP P S A, F JUMP P S A, atca 168; attack 19, 93 */
    { { {  -80,  53,  90,  21 },  {    0,   0,   0,   0 } } },  /* 20: V JUMP P M A, F JUMP P M A; attack 20 */
    { { {  -79,  24,  67,  19 },  {  -55,  27,  80,  17 } } },  /* 21: V JUMP P L A, F JUMP P L A; attack 21 */
    { { {  -47,  27,  78,  32 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K S A, F JUMP K S A; attack 22 */
    { { {  -63,  31,  43,  19 },  {    0,   0,   0,   0 } } },  /* 23: F JUMP K L A; attack 24 */
    { { {  -52,  26,  73,  12 },  {  -26,  13,  74,  17 } } },  /* 24: FUSHIN P S; attack 25 */
    { { {  -60,  19,  52,  20 },  {  -51,  18,  37,  16 } } },  /* 25: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: no box */
    { { {  -36,  32,  95,  58 },  {    0,   0,   0,   0 } } },  /* 27: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +1; attack 31, 33, 35, 67 */
    { { {  -48,  32,  65,  31 },  {  -34,  16,  48,  17 } } },  /* 28: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU); attack 30 */
    { { {  -54,  37,  48,  23 },  {  -46,  37,  31,  17 } } },  /* 29: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU); attack 32 */
    { { {  -54,  30,  60,  28 },  {  -46,  28,  31,  28 } } },  /* 30: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {  -54,  33,  33,  31 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU); attack 37 */
    { { {  -58,  33,  67,  30 },  {  -53,  30,  46,  21 } } },  /* 32: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU); attack 34 */
    { { {  -96,  88,  72,  18 },  {  -52, 120,  64,  32 } } },  /* 33: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script), ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script) +1; attack 76, 77 */
    { { {  -29,  24, 104,  42 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +1; attack 31, 33, 35, 67 */
    { { {  -42,  16,  64,  21 },  {    0,   0,   0,   0 } } },  /* 35: L KICK C; attack 6 */
    { { {  -82,  29,  19,  20 },  {  -70,  31,  39,  18 } } },  /* 36: L KICK C; attack 6 */
    { { {  -96,  21,  61,  23 },  {  -75,  48,  61,  29 } } },  /* 37: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1; attack 43, 100 */
    { { {  -87,  22,  69,  18 },  {  -83,  57,  88,  11 } } },  /* 38: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1; attack 44, 101 */
    { { {  -99,  32,  86,  19 },  {  -65,  39,  86,  14 } } },  /* 39: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU); attack 45, 102 */
    { { {  -92,  33,  54,  22 },  {  -58,  28,  69,  18 } } },  /* 40: ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU); attack 46, 47, 103, 104 */
    { { {  -78,  20,  61,  25 },  {  -58,  18,  50,  21 } } },  /* 41: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1; attack 48, 105 */
    { { {  -67,  21,  83,  25 },  {  -83,  16,  70,  19 } } },  /* 42: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1; attack 49, 106 */
    { { {  -80,  36,  56,  22 },  {  -56,  28,  48,  38 } } },  /* 43: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI); attack 38 */
    { { {  -88,  40,  58,  18 },  {  -60,  30,  52,  30 } } },  /* 44: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI); attack 39 */
    { { {  -92,  42,  60,  14 },  {  -64,  32,  54,  26 } } },  /* 45: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI); attack 40 */
    { { {  -96,  44,  62,  10 },  {  -68,  34,  56,  22 } } },  /* 46: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI); attack 41 */
    { { {  -96,  48,  62,  10 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI); attack 42 */
    { { {  -56,  34,  37,  16 },  {  -43,  43,  29,  13 } } },  /* 48: ATTACK 3 S: SA II 23623+P (plain script); attack 52 */
    { { {  -64,  19,  43,  24 },  {  -48,  17,  31,  23 } } },  /* 49: ATTACK 3 S: SA II 23623+P (plain script); attack 53 */
    { { {  -50,  79,  70,  14 },  {  -63,  25,  54,  14 } } },  /* 50: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {   -6,  37,  79,  14 },  {  -39,  31,  70,  14 } } },  /* 51: not used by a script */
    { { {  -82,  19,  32,  38 },  {  -62,  29,  23,  19 } } },  /* 52: ATTACK 3 S: SA II 23623+P (plain script); attack 54 */
    { { {  -69,  29,  54,  25 },  {  -89,  18,  35,  35 } } },  /* 53: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -39,  39,  65,  16 },  {  -59,  19,  57,  16 } } },  /* 54: not used by a script */
    { { {  -70,  63,  33,  51 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 61 */
    { { {  -27,  38, 110,  42 },  {  -53,  26,  68,  53 } } },  /* 56: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 51, 60 */
    { { {  -65,  37,  42,  24 },  {    0,   0,   0,   0 } } },  /* 57: V JUMP K L A; attack 24 */
    { { {  -42,  73, 116,  38 },  {  -53,  26,  68,  48 } } },  /* 58: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 36, 62 */
    { { {  -53,  31,  68,  27 },  {    0,   0,   0,   0 } } },  /* 59: V JUMP K M A, F JUMP K M A; attack 23 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -98,  20,  75,  11 },  {  -78,  51,  74,  12 } } },  /* 61: ATTACK 13 M: not started by a command; attack 58 */
    { { {  -68,  40,  42,  36 },  {  -57,  43,  21,  28 } } },  /* 62: ATTACK 13 L: not started by a command; attack 63 */
    { { {  -60,  32,  98,  22 },  {  -68,  21,  79,  19 } } },  /* 63: ATTACK 13 L: not started by a command; attack 64 */
    { { {  -50,  35,  49,  36 },  {    0,   0,   0,   0 } } },  /* 64: not started by a command; attack 91 */
    { { {  -25,  57, 115,  29 },  {   19,  31,  75,  40 } } },  /* 65: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 92 */
    { { {  -29,  34,   0,  15 },  {  -29,  34,  15,  31 } } },  /* 66: ATTACK 8 S: 214+K light/medium/heavy (routine Att_SLIDE_and_JUMP), ATTACK 8 SP: EX 214+KK (routine Att_HOMING_JUMP); attack 94, 96, 99 */
    { { { -112,  88,  72,  18 },  {  -58,  80,  64,  32 } } },  /* 67: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    { { {  -96, 200,  72,  18 },  {  -50, 124,  64,  32 } } },  /* 68: ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1; attack 78, 97, 98 */
    { { {  -68,  60,  49,  32 },  {  -50,  42,  31,  18 } } },  /* 69: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 50, 59 */
    { { {  -54,  33,  33,  31 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU); attack 65 */
    { { {  -58,  33,  67,  30 },  {  -53,  30,  46,  21 } } },  /* 71: OKIAGARI P S, ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU); attack 26, 66 */
};

const CATCH_BOX dudley_cat_box[66] = {
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
    { {  -34,    6,    0,   16 } },  /* 26: M PUNCH A, TUKAMIKAKARI A, TUKAMIKAKARI C */
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
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { {    0,    0,    0,    0 } },  /* 49: no box */
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
    { {  -38,   10,    0,   16 } },  /* 60: L PUNCH A, L PUNCH C */
    { {    0,    0,    0,    0 } },  /* 61: no box */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
    { {    0,    0,    0,    0 } },  /* 65: no box */
};

const CAUGHT_BOX dudley_cau_box[23] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -28,   57,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +127 */
    { {  -52,  104,    0,   16 } },  /* 2: ATTACK 11 M: 6(123)4+P light (plain script), ATTACK 11 L: 6(123)4+P medium (plain script), ATTACK 11 SP: 6(123)4+P heavy (plain script) +2 */
    { {  -32,   64,    0,   16 } },  /* 3: DASH HUMIKOMI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    { {  -24,   40,    0,   16 } },  /* 4: not used by a script */
    { {  -24,   48,    0,   16 } },  /* 5: not used by a script */
    { {  -32,   61,    0,    8 } },  /* 6: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +45 */
    { {  -36,   65,    0,    8 } },  /* 7: KAGAMI P A, KAGAMI K A */
    { {  -26,   52,   44,   61 } },  /* 8: V JUMP K L A, JUMP JUNBI, SP JUMP JUNBI +34 */
    { {  -42,   71,    0,   16 } },  /* 9: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -34,   63,    0,   16 } },  /* 10: S PUNCH C */
    { {  -24,   48,    0,   16 } },  /* 11: not used by a script */
    { {  -18,   40,    0,   16 } },  /* 12: not used by a script */
    { {  -48,   77,    0,    8 } },  /* 13: KAGAMI K A */
    { {  -16,   43,   86,   21 } },  /* 14: not used by a script */
    { {  -42,   28,   56,   35 } },  /* 15: not used by a script */
    { {  -11,   40,    8,   96 } },  /* 16: FUSHIN P S */
    { {  -15,   40,    0,   16 } },  /* 17: TOUKETSU A, OKIAGARI P S */
    { {  -29,   40,    0,   16 } },  /* 18: not used by a script */
    { {  -55,  102,    0,    8 } },  /* 19: ATTACK 3 S: SA II 23623+P (plain script) */
    { {  -55,  102,    0,    8 } },  /* 20: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    { {  -20,   51,   40,   44 } },  /* 21: AIR S, AIR M, AIR L +41 */
    { {  -32,   61,    0,   16 } },  /* 22: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), OKIAGARI P S, ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) +3 */
};
