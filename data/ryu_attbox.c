/*
 * RYU_ATTBOX.C  Ryu's attack, catch and caught boxes
 *
 * Selected per animation frame through ryu_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX ryu_att_box[73] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -52,  24,  38,  30 },  {    0,   0,   0,   0 } } },  /* 1: ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command, ATTACK 2 S: not started by a command +1; attack 1, 53, 54, 74 */
    { { {  -31,  26, 101,  39 },  {  -50,  26,  48,  29 } } },  /* 2: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2; attack 2, 56, 61, 62 ... */
    { { {  -28,  20,  88,  51 },  {  -29,  14,  53,  17 } } },  /* 3: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -53,  29,  75,  15 },  {  -39,  28,  57,  21 } } },  /* 4: S PUNCH A; attack 3 */
    { { {  -76,  62,  71,  15 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B; attack 4 */
    { { {  -52,  26,  39,  26 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A, UP P GUARD P M; attack 5 */
    { { {  -86,  71,  67,  12 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B, UP P GUARD P S; attack 6 */
    { { {  -63,  47,  61,  25 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, follow-up of UP P GUARD P M; attack 8 */
    { { {  -52,  40,  83,  32 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, follow-up of UP P GUARD P M; attack 8 */
    { { {  -75,  50,  70,  22 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH B, UP P GUARD P L; attack 9 */
    { { {  -76,  54,  10,  18 },  {    0,   0,   0,   0 } } },  /* 11: S KICK A; attack 10 */
    { { {  -75,  46,  65,  15 },  {  -35,  35,  59,  13 } } },  /* 12: not used by a script */
    { { {  -73,  50,  34,  41 },  {    0,   0,   0,   0 } } },  /* 13: M KICK A; attack 12 */
    { { {  -84,  79,  44,  17 },  {    0,   0,   0,   0 } } },  /* 14: M KICK B, UP P GUARD K S; attack 13 */
    { { {  -70,  17,  90,  32 },  {  -60,  19,  63,  26 } } },  /* 15: not used by a script */
    { { {  -85,  17,  90,  32 },  {  -69,  19,  68,  26 } } },  /* 16: not used by a script */
    { { { -115,  37,  72,  18 },  {  -77,  41,  64,  19 } } },  /* 17: not used by a script */
    { { {  -80,  26,  78,  36 },  {  -67,  28,  63,  36 } } },  /* 18: not used by a script */
    { { {  -91,  28,  81,  14 },  {  -62,  35,  60,  26 } } },  /* 19: L KICK A, follow-up of L PUNCH B / UP P GUARD P L; attack 17, 60 */
    { { {  -78,  42,  74,  14 },  {  -50,  39,  63,  12 } } },  /* 20: not used by a script */
    { { {  -64,  45,  37,  12 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 19 */
    { { {  -69,  52,  43,  10 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 20 */
    { { {  -60,  36,  30,  35 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A; attack 21 */
    { { {  -23,  20,  89,  33 },  {  -38,  23,  61,  28 } } },  /* 24: KAGAMI P A; attack 22 */
    { { {  -78,  52,   0,   5 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 23 */
    { { {  -86,  76,   0,   5 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI K A; attack 24 */
    { { {  -96,  75,   0,   6 },  {  -57,  45,   2,  21 } } },  /* 27: KAGAMI K A; attack 25 */
    { { {  -47,  19,  59,  23 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -90,  60,  91,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P L A; attack 28 */
    { { {  -87,  65,  57,  18 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP K M A; attack 30 */
    { { {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 } } },  /* 31: not used by a script */
    { { {  -76,  18,  59,  11 },  {  -56,  17,  69,  11 } } },  /* 32: not used by a script */
    { { {  -38,  18,  42,  16 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP K S A, F JUMP K S A; attack 29, 35 */
    { { {  -80,  18,  38,  21 },  {  -63,  77,  52,  13 } } },  /* 34: F JUMP K M A; attack 36 */
    { { {  -56,  38,  50,  32 },  {  -44,  32,  84,  44 } } },  /* 35: ATTACK 11 SP: not started by a command; attack 56 */
    { { {  -56,  18,  92,  18 },  {  -45,  27,  71,  26 } } },  /* 36: F JUMP P M A; attack 33 */
    { { {  -66,  48,  80,  20 },  {  -81,  25,  93,  18 } } },  /* 37: V JUMP K L A; attack 31 */
    { { {  -70,  14,  63,  18 },  {  -56,  38,  63,  14 } } },  /* 38: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +4; attack 38, 39, 66, 86 ... */
    { { {   18,  35,  63,  14 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +3; attack 39, 40, 64, 67 ... */
    { { { -108,  39,  52,  13 },  {  -72,  32,  55,  13 } } },  /* 40: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {  -57,  31,  53,  28 },  {    0,   0,   0,   0 } } },  /* 42: M PUNCH C; attack 50 */
    { { {  -68,  41,  18,  32 },  {    0,   0,   0,   0 } } },  /* 43: M PUNCH C; attack 51 */
    { { {  -45,  40,  58,  25 },  {    0,   0,   0,   0 } } },  /* 44: F JUMP P M A; attack 52 */
    { { {  -52,  22,  56,  18 },  {  -40,  20,  48,  16 } } },  /* 45: not used by a script */
    { { {  -80,  49,  58,  12 },  {  -31,  14,  42,  28 } } },  /* 46: UP P GUARD K L, ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command; attack 18, 73, 79 */
    { { {  -83,  57,  74,  14 },  {  -34,  10,  60,  13 } } },  /* 47: UP P GUARD K L, ATTACK 10 S: not started by a command; attack 71 */
    { { {  -86,  16,  52,  18 },  {  -70,  47,  54,  17 } } },  /* 48: F JUMP K L A, S V JP S P A; attack 37 */
    { { {  -85,  34,  84,  24 },  {  -67,  27,  65,  31 } } },  /* 49: follow-up of L PUNCH B / UP P GUARD P L; attack 60 */
    { { {  -66,  18,  72,  16 },  {  -48,  40,  75,  10 } } },  /* 50: FUSHIN P S; attack 58 */
    { { {  -71,  42,  58,  20 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P M A; attack 27 */
    { { {  -70,  54,  32,  40 },  {  -42,  30,  14,  22 } } },  /* 52: ATTACK 11 SP: not started by a command; attack 82 */
    { { {  -72,  56,  32,  56 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 12 S: not started by a command; attack 83 */
    { { {  -56,  40,  80,  60 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 12 S: not started by a command; attack 85 */
    { { {  -66,  52,  48,  52 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 12 S: not started by a command; attack 84 */
    { { { -100,  37,   0,  19 },  {  -57,  45,   2,  21 } } },  /* 56: not used by a script */
    { { {  -76,  85,  43,  18 },  {    0,   0,   0,   0 } } },  /* 57: M KICK B, UP P GUARD K S; attack 13 */
    { { {  -77,  40,  49,  23 },  {    0,   0,   0,   0 } } },  /* 58: F JUMP P L A; attack 34 */
    { { {  -90,  32,  98,  10 },  {  -56,  35,  99,  10 } } },  /* 59: not used by a script */
    { { {  -87,  70,  55,  21 },  {    0,   0,   0,   0 } } },  /* 60: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: no box */
    { { {  -49,  26,  29,  49 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 9 S: not started by a command; attack 69 */
    { { {  -63,  47,  48,  39 },  {    0,   0,   0,   0 } } },  /* 63: L PUNCH A; attack 7 */
    { { {  -41,  81,   0,  24 },  {    0,   0,   0,   0 } } },  /* 64: OKIAGARI P S; attack 70 */
    { { {  -42,  27,  42,  33 },  {  -30,  26, 100,  39 } } },  /* 65: OKIAGARI P S; attack 70 */
    { { {  -64,  39,  67,  13 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command; attack 40, 65, 68 */
    { { {  -81,  57,  72,   8 },  {  -28,   9,  45,  35 } } },  /* 67: ATTACK 10 M: not started by a command; attack 72 */
    { { {  -78,  18,  44,  31 },  {  -59,  58,  44,  24 } } },  /* 68: ATTACK 3 SP: not started by a command; attack 76 */
    { { {    1,  57,  44,  24 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 3 SP: not started by a command; attack 77, 92 */
    { { {  -64,  63,  45,  23 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 3 SP: not started by a command; attack 78 */
    { { {  -78,  18,  55,  27 },  {  -59,  48,  57,  21 } } },  /* 71: ATTACK 8 SP: not started by a command; attack 80 */
    { { {   11,  47,  57,  21 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 8 SP: not started by a command; attack 81 */
};

const CATCH_BOX ryu_cat_box[68] = {
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
    { {  -31,    6,    0,   16 } },  /* 41: M PUNCH A, M PUNCH B, M PUNCH C +4 */
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
    { {    0,    0,    0,    0 } },  /* 60: no box */
    { {  -35,   10,    0,   16 } },  /* 61: L PUNCH A, L PUNCH B, L KICK A */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
    { {    0,    0,    0,    0 } },  /* 65: no box */
    { {    0,    0,    0,    0 } },  /* 66: no box */
    { {    0,    0,    0,    0 } },  /* 67: no box */
};

const CAUGHT_BOX ryu_cau_box[21] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +114 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +26 */
    { {  -25,   50,   48,   40 } },  /* 3: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +14 */
    { {  -25,   50,   48,   40 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +19 */
    { {   -1,   48,    0,   90 } },  /* 5: not used by a script */
    { {  -21,   36,    0,   90 } },  /* 6: not used by a script */
    { {  -36,   36,    0,   90 } },  /* 7: not used by a script */
    { {  -33,   58,    0,    8 } },  /* 8: KAGAMI P A, KAGAMI K A */
    { {  -29,   54,    0,   16 } },  /* 9: S KICK A */
    { {  -28,   48,    0,   58 } },  /* 10: not used by a script */
    { {  -28,   45,   46,   61 } },  /* 11: not used by a script */
    { {  -24,   44,   54,   52 } },  /* 12: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { {  -25,   50,   48,   40 } },  /* 13: TOUKETSU A, AIR S, AIR M +36 */
    { {   -8,   40,   66,   25 } },  /* 14: FUSHIN P S */
    { {  -16,   48,    0,   82 } },  /* 15: not used by a script */
    { {  -46,   80,    0,   16 } },  /* 16: follow-up of ATTACK 4 S: not started by a command / ATTACK 4 M: not started by a command +3, ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command +9 */
    { {  -41,   81,    0,   16 } },  /* 17: not used by a script */
    { {  -36,   73,   46,   49 } },  /* 18: not used by a script */
    { {  -38,   63,    0,   16 } },  /* 19: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -25,   71,    0,   16 } },  /* 20: UP P GUARD K L, ATTACK 10 M: not started by a command, ATTACK 10 L: not started by a command +3 */
};
