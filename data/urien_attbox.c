/*
 * URIEN_ATTBOX.C  Urien's attack, catch and caught boxes
 *
 * Selected per animation frame through urien_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX urien_att_box[51] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -84,  26,  74,  16 },  {  -66,  26,  82,  12 } } },  /* 1: S PUNCH A, UP P GUARD P S; attack 1 */
    { { {  -56,  36,  92,  24 },  {  -76,  32, 104,  24 } } },  /* 2: not used by a script */
    { { {  -76,  32, 104,  24 },  {  -56,  36,  92,  24 } } },  /* 3: M PUNCH C, UP P GUARD P M; attack 2, 3 */
    { { {  -56,  22, 104,  18 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -68,  36,  56,  38 },  {  -84,  40,  36,  40 } } },  /* 5: L PUNCH A; attack 5 */
    { { {  -90,  24,  44,  16 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A */
    { { {  -72,  32,  10,  14 },  {  -62,  30,  22,  12 } } },  /* 7: S KICK A, UP P GUARD P L; attack 6 */
    { { { -118,  28,  70,  12 },  {  -89,  54,  66,  16 } } },  /* 8: not used by a script */
    { { { -112,  24,  70,  12 },  {  -89,  54,  66,  16 } } },  /* 9: M KICK A; attack 8 */
    { { {  -66,  20,  38,  16 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -45,  21, 106,  15 },  {  -49,  22,  87,  19 } } },  /* 11: KAGAMI P A, atca 157; attack 14, 50 */
    { { { -104,  54,  50,  18 },  {  -80,  80,  68,  16 } } },  /* 12: not used by a script */
    { { {  -82,  20,  46,  16 },  {  -66,  20,  38,  16 } } },  /* 13: KAGAMI P A, UP P GUARD P L; attack 12, 13 */
    { { {  -52,  28,  60,  20 },  {  -44,  24,  42,  18 } } },  /* 14: KAGAMI P A, atca 157; attack 28, 49 */
    { { {  -97,  66,   0,  12 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A, UP P GUARD P L; attack 15 */
    { { {  -78,  22,  61,  18 },  {  -62,  22,  53,  18 } } },  /* 16: V JUMP P L A */
    { { {  -56,  22,  68,  12 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P S A; attack 18 */
    { { {  -92,  24,  86,  14 },  {  -74,  24,  80,  14 } } },  /* 18: V JUMP P M A */
    { { {  -48,  20,  58,  16 },  {    0,   0,   0,   0 } } },  /* 19: V JUMP K S A; attack 19, 29 */
    { { {  -50,  24,  71,  17 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { { -104,  86,  80,  12 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP K M A, FUSHIN P S; attack 30 */
    { { {  -94,  56,  80,  12 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K M A, FUSHIN P S, ATTACK 4 M: not started by a command; attack 20 */
    { { { -107,  32,  50,  16 },  {  -81,  52,  58,  16 } } },  /* 23: V JUMP K L A; attack 31 */
    { { { -108,  40,  52,  16 },  {  -74,  44,  60,  16 } } },  /* 24: not used by a script */
    { { {  -89,  56,  55,  24 },  {    0,   0,   0,   0 } } },  /* 25: follow-up of APPEAR JUNBI 6 */
    { { {  -30,  56,  54,  16 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -36,  56,  40,  16 },  {    0,   0,   0,   0 } } },  /* 27: not used by a script */
    { { { -120,  56,  42,  22 },  {  -84,  84,  64,  18 } } },  /* 28: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -38,  44,  46,  20 },  {  -18,  30,  60,  14 } } },  /* 31: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 24, 47 */
    { { {  -54,  28,  62,  22 },  {  -38,  22,  54,  16 } } },  /* 32: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 25, 48 */
    { { {  -33,  12,  56,  42 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI); attack 32, 41 */
    { { {  -78,  50,  56,  29 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI); attack 33, 42 */
    { { {  -74,  26,  68,  20 },  {  -69,  24,  77,  20 } } },  /* 35: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU); attack 26, 52, 53 */
    { { { -104,  40,  66,  22 },  {  -70,  42,  78,  20 } } },  /* 36: not used by a script */
    { { {  -94,  30,  72,  16 },  {  -70,  30,  78,  16 } } },  /* 37: M PUNCH A, follow-up of S PUNCH A; attack 3, 51 */
    { { {  -66,  34, 102,  36 },  {    0,   0,   0,   0 } } },  /* 38: L KICK A; attack 9 */
    { { { -113,  68,  64,  26 },  {  -91,  52,  88,  12 } } },  /* 39: L KICK A; attack 10 */
    { { {  -87,  36,  12,  28 },  {  -92,  32,  32,  26 } } },  /* 40: L KICK A */
    { { { -107,  76,   0,  16 },  {    0,   0,   0,   0 } } },  /* 41: KAGAMI K A, UP P GUARD P L; attack 16 */
    { { { -116,  84,   0,  16 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI K A; attack 17 */
    { { { -110,  22,  76,  16 },  {  -88,  48,  80,  14 } } },  /* 43: V JUMP P M A; attack 19 */
    { { {  -88,  28,  70,  24 },  {  -76,  24,  88,  24 } } },  /* 44: V JUMP P L A; attack 20 */
    { { {  -48,  34,  58,  18 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command; attack 34 */
    { { {  -45,  17,  52,  34 },  {  -38,  11,  32,  48 } } },  /* 46: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI); attack 39, 40 */
    { { { -112,  22,  61,  15 },  {  -90,  53,  58,  18 } } },  /* 47: M KICK C; attack 38 */
    { { {  -64, 128,   0,   8 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 8 SP: not started by a command; attack 46 */
    { { {  -28,  14,  50,  28 },  {  -23,  10,  32,  51 } } },  /* 49: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1; attack 35, 36, 37, 43 ... */
    { { {  -76,  28,  66,  20 },  {  -69,  24,  78,  20 } } },  /* 50: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU); attack 45 */
};

const CATCH_BOX urien_cat_box[46] = {
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
    { {  -30,    6,    0,   16 } },  /* 29: M PUNCH A, M PUNCH C, M KICK A +2 */
    { {  -34,   10,    0,   16 } },  /* 30: L PUNCH A, L KICK A, TUKAMIKAKARI A */
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
};

const CAUGHT_BOX urien_cau_box[9] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +105 */
    { {  -28,   52,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +36 */
    { {  -24,   48,   56,   56 } },  /* 3: S JUMP FRONT, GUARD AIR, V JUMP P M A +41 */
    { {  -24,   48,    0,   16 } },  /* 4: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { {  -28,   52,    0,    8 } },  /* 5: not used by a script */
    { {  -32,   64,    0,   16 } },  /* 6: DASH HUMIKOMI */
    { {  -23,   48,   34,   58 } },  /* 7: AIR S, AIR M, AIR L +39 */
    { {  -43,   52,   52,   59 } },  /* 8: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
};
