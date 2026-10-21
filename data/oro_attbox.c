/*
 * ORO_ATTBOX.C  Oro's attack, catch and caught boxes
 *
 * Selected per animation frame through oro_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX oro_att_box[61] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -61,  22,  82,  14 },  {  -49,  28,  48,  33 } } },  /* 1: nmca 33, S PUNCH A; attack 1 */
    { { {  -97,  16,  51,  13 },  {  -80,  50,  54,   9 } } },  /* 2: S PUNCH B; attack 2 */
    { { { -103,  48,  48,  12 },  {  -53,  18,  53,  14 } } },  /* 3: not used by a script */
    { { {  -91,  34,  71,  15 },  {  -56,  39,  72,  15 } } },  /* 4: M PUNCH B; attack 4 */
    { { {  -53,  21,  50,  14 },  {  -36,  21,  43,   8 } } },  /* 5: M PUNCH A; attack 3 */
    { { {  -30,  17,  99,  33 },  {  -24,  14,  70,  28 } } },  /* 6: M PUNCH A; attack 6 */
    { { {  -50,  15,  59,  22 },  {  -40,  14,  56,  12 } } },  /* 7: L PUNCH A, UP P GUARD P L; attack 7 */
    { { {  -74,  40,  12,  27 },  {  -33,  12,  29,  18 } } },  /* 8: L PUNCH A, UP P GUARD P L; attack 8 */
    { { {  -46,  14,  42,  34 },  {  -35,  19,  57,  36 } } },  /* 9: S KICK A; attack 9 */
    { { {  -78,  10,  44,  18 },  {  -74,  57,  44,  12 } } },  /* 10: S KICK B; attack 10 */
    { { {  -42,  26,  37,  49 },  {    0,   0,   0,   0 } } },  /* 11: M KICK A; attack 11 */
    { { {  -90,  71,  57,  22 },  {    0,   0,   0,   0 } } },  /* 12: UP P GUARD K S; attack 12 */
    { { {  -79,  19,  62,  20 },  {  -60,  41,  62,  19 } } },  /* 13: L KICK A; attack 13 */
    { { {  -96,  10,  29,  13 },  {  -85,  60,  29,  13 } } },  /* 14: KAGAMI P A; attack 15 */
    { { {  -88,  29,  47,  19 },  {  -67,  37,  37,  21 } } },  /* 15: KAGAMI P A; attack 16 */
    { { {  -76,  33,  56,  16 },  {  -43,  35,  45,  19 } } },  /* 16: KAGAMI P A */
    { { {  -47,  18,  74,  14 },  {  -30,  19,  62,  15 } } },  /* 17: not used by a script */
    { { {  -80,  28,   0,  10 },  {  -54,  37,   8,   9 } } },  /* 18: KAGAMI K A; attack 19 */
    { { {  -98,  67,   0,  26 },  {    0,   0,   0,   0 } } },  /* 19: D P GUARD K S, KAGAMI K A; attack 34, 53 */
    { { {  -84,  20,  54,  14 },  {  -65,  28,  65,  13 } } },  /* 20: V JUMP P S A; attack 21 */
    { { {  -54,  16,  55,  16 },  {  -38,  14,  49,  20 } } },  /* 21: V JUMP K S A, ATTACK 11 L: not started by a command; attack 22, 69 */
    { { {  -65,  25,  56,  23 },  {  -44,  20,  45,  26 } } },  /* 22: V JUMP K M A; attack 23 */
    { { {  -91,  14,  49,  17 },  {  -75,  54,  49,  17 } } },  /* 23: V JUMP K L A; attack 24 */
    { { {  -69,  14,  42,  13 },  {  -54,  31,  47,  14 } } },  /* 24: F JUMP P S A; attack 25 */
    { { {  -69,  13,  35,  26 },  {  -56,  28,  42,  15 } } },  /* 25: F JUMP P M A; attack 26 */
    { { {  -44,  18,  14,  45 },  {    0,   0,   0,   0 } } },  /* 26: F JUMP P L A; attack 27 */
    { { {  -45,  19,  85,  45 },  {    0,   0,   0,   0 } } },  /* 27: F JUMP P L A; attack 28 */
    { { {  -42,  13,  24,  15 },  {    0,   0,   0,   0 } } },  /* 28: F JUMP K S A; attack 29 */
    { { {  -39,  24,  15,  19 },  {  -23,  28,  23,  24 } } },  /* 29: F JUMP K M A; attack 30 */
    { { {  -20,  14,   0,  15 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI); attack 31, 61 */
    { { {  -92,  24,  44,  12 },  {  -71,  47,  44,  12 } } },  /* 31: not used by a script */
    { { { -107,  42,  50,  12 },  {  -67,  43,  52,   7 } } },  /* 32: UP P GUARD P S, D P GUARD P S; attack 33 */
    { { {  -89,  42,  61,  12 },  {  -60,  43,  63,   7 } } },  /* 33: FUSHIN P S; attack 33 */
    { { {  -62,  50,  26,  37 },  {  -54,  42,  12,  14 } } },  /* 34: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN); attack 39, 84 */
    { { {  -61,  60,  58,  35 },  {  -54,  28,  38,  22 } } },  /* 35: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2; attack 35, 37, 40, 71 ... */
    { { {  -29,  23, 108,  28 },  {  -44,  31,  82,  30 } } },  /* 36: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2; attack 36, 38, 40, 71 ... */
    { { {  -76,  32,  60,   8 },  {  -65,  36,  60,   8 } } },  /* 37: not used by a script */
    { { {  -60,  12,  70,   8 },  {  -48,  11,  62,   9 } } },  /* 38: not used by a script */
    { { {  -56,  10,  88,   8 },  {  -46,  10,  71,  16 } } },  /* 39: not used by a script */
    { { {  -88,  13,  66,   7 },  {  -77,  14,  70,   8 } } },  /* 40: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { { -102,  20,  27,  18 },  {  -82,  61,  27,  18 } } },  /* 42: KAGAMI P A; attack 52 */
    { { {  -90,  43,   0,  10 },  {  -54,  45,   8,  15 } } },  /* 43: KAGAMI K A; attack 20 */
    { { {  -96,  27,  48,  19 },  {  -79,  31,  58,  17 } } },  /* 44: V JUMP P M A; attack 54 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {  -29,  46,  99,  31 },  {    0,   0,   0,   0 } } },  /* 48: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2; attack 41, 71, 86 */
    { { {  -51,  33,  31,  57 },  {    0,   0,   0,   0 } } },  /* 49: not used by a script */
    { { {  -41,  40,   0,   9 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1; attack 67, 68, 72, 73 ... */
    { { {  -89,  73,  59,  13 },  {    0,   0,   0,   0 } } },  /* 51: M KICK B, UP P GUARD K S; attack 12 */
    { { {  -83,  21,  65,  20 },  {  -60,  47,  68,  15 } } },  /* 52: not used by a script */
    { { { -100,  38,  70,  15 },  {  -60,  35,  77,   8 } } },  /* 53: V JUMP P L A; attack 55 */
    { { {  -88,  14,  40,  14 },  {  -73,  49,  39,  17 } } },  /* 54: F JUMP K L A; attack 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {  -50,  27,   0,  29 },  {  -55,  27,  27,  15 } } },  /* 59: not used by a script */
    { { {  -28,  22,  -3,  15 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI); attack 82, 83 */
};

const CATCH_BOX oro_cat_box[61] = {
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
    { {  -89,   62,    0,   16 } },  /* 41: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    { {    0,    0,    0,    0 } },  /* 42: no box */
    { {    0,    0,    0,    0 } },  /* 43: no box */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {  -35,    6,    0,   16 } },  /* 45: M PUNCH A, M PUNCH B, M KICK A +3 */
    { {  -83,   56,    0,   16 } },  /* 46: follow-up of ZANNEN 2 */
    { {  -29,   24,   60,   38 } },  /* 47: V JUMP P L A, F JUMP P L A */
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { {    0,    0,    0,    0 } },  /* 49: no box */
    { {    0,    0,    0,    0 } },  /* 50: no box */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
    { {    0,    0,    0,    0 } },  /* 53: no box */
    { {    0,    0,    0,    0 } },  /* 54: no box */
    { {  -39,   10,    0,   16 } },  /* 55: L PUNCH A, L KICK A */
    { {  -65,   42,   72,   22 } },  /* 56: follow-up of ZANNEN 7 */
    { {  -57,   28,    0,   16 } },  /* 57: follow-up of WIN 8 */
    { {  -69,   40,    0,   16 } },  /* 58: follow-up of SP WIN 1 */
    { {    0,    0,    0,    0 } },  /* 59: no box */
    { {  -93,   64,    0,   16 } },  /* 60: ATTACK 9 S: after 6(123)4+P (plain script) */
};

const CAUGHT_BOX oro_cau_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -29,   59,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +112 */
    { {  -43,   50,    0,   16 } },  /* 2: DASH HUMIKOMI, P BREAK ZUJOU, TUKAMIHAZUSI */
    { {  -33,   63,    0,    8 } },  /* 3: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +28 */
    { {  -23,   46,   39,   47 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +38 */
    { {  -25,   50,   31,   58 } },  /* 5: not used by a script */
    { {  -29,   59,    0,   16 } },  /* 6: M KICK B, UP P GUARD K S */
    { {  -23,   46,   39,   47 } },  /* 7: not used by a script */
    { {  -25,   50,   31,   58 } },  /* 8: not used by a script */
    { {  -21,   49,   22,   45 } },  /* 9: AIR S, AIR M, AIR L +40 */
    { {  -24,   48,   28,   51 } },  /* 10: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { {  -37,   67,    0,    8 } },  /* 11: KAGAMI P A, KAGAMI K A */
};
