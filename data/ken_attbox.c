/*
 * KEN_ATTBOX.C  Ken's attack, catch and caught boxes
 *
 * Selected per animation frame through ken_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX ken_att_box[84] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -59,  34,  36,  27 },  {    0,   0,   0,   0 } } },  /* 1: ATTACK 2 L: not started by a command, ATTACK 2 SP: not started by a command, ATTACK 2 M: not started by a command +1; attack 2, 53, 79, 84 */
    { { {  -31,  26, 101,  39 },  {  -46,  24,  48,  29 } } },  /* 2: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +3; attack 1, 2, 44, 46 ... */
    { { {  -28,  20,  88,  51 },  {  -29,  14,  53,  17 } } },  /* 3: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1; attack 2 */
    { { {  -53,  29,  75,  15 },  {  -39,  28,  57,  21 } } },  /* 4: S PUNCH A; attack 3 */
    { { {  -76,  62,  71,  15 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B; attack 4 */
    { { {  -52,  26,  39,  26 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A, UP P GUARD P M; attack 5 */
    { { {  -86,  71,  67,  12 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B, UP P GUARD P S; attack 6 */
    { { {  -63,  47,  61,  25 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, follow-up of M PUNCH A; attack 8 */
    { { {  -52,  40,  83,  32 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, follow-up of M PUNCH A; attack 8 */
    { { {  -75,  50,  70,  22 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH B, UP P GUARD P L; attack 9 */
    { { {  -76,  54,  10,  18 },  {    0,   0,   0,   0 } } },  /* 11: S KICK A; attack 10 */
    { { {  -77,  40,  49,  23 },  {    0,   0,   0,   0 } } },  /* 12: F JUMP P L A; attack 34 */
    { { {  -80,  35,  57,  15 },  {  -74,  28,  45,  10 } } },  /* 13: ATTACK 6 S: not started by a command */
    { { {  -45,  22,  68,  34 },  {    0,   0,   0,   0 } } },  /* 14: M KICK C, follow-up of M KICK A, UP P GUARD K M; attack 50 */
    { { {  -79,  59,  49,  21 },  {  -69,  30,  69,  17 } } },  /* 15: M KICK C, follow-up of M KICK A, UP P GUARD K M; attack 50 */
    { { {  -96,  25,  33,  16 },  {  -81,  47,  41,  20 } } },  /* 16: M KICK C, follow-up of M KICK A, UP P GUARD K M; attack 51 */
    { { {  -60,  23,   6,  13 },  {  -81,  40,  21,  14 } } },  /* 17: M KICK C, follow-up of M KICK A, UP P GUARD K M */
    { { {  -80,  33,  73,  17 },  {  -72,  45,  30,  29 } } },  /* 18: not used by a script */
    { { {  -89,  15,  41,  12 },  {  -83,  59,  46,  12 } } },  /* 19: L KICK A, UP P GUARD K L; attack 17 */
    { { {  -48,   1,  83,   9 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 10 M: not started by a command; attack 96 */
    { { {  -64,  45,  37,  12 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 19 */
    { { {  -69,  52,  43,  10 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 20 */
    { { {  -60,  36,  30,  35 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A; attack 21 */
    { { {  -23,  20,  89,  33 },  {  -38,  23,  61,  28 } } },  /* 24: KAGAMI P A; attack 22 */
    { { {  -78,  52,   0,   5 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 23 */
    { { {  -86,  76,   0,   5 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI K A, UP P GUARD K S; attack 24 */
    { { {  -96,  75,   0,   6 },  {  -57,  45,   2,  21 } } },  /* 27: KAGAMI K A; attack 25 */
    { { {  -47,  19,  59,  23 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -90,  60,  91,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P L A; attack 34 */
    { { {  -87,  65,  57,  18 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP K M A; attack 30 */
    { { {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 } } },  /* 31: not used by a script */
    { { {  -71,  42,  58,  20 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP P M A, F JUMP P M A; attack 27, 52 */
    { { {  -38,  18,  42,  16 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP K S A, F JUMP K S A; attack 35 */
    { { {  -76,  18,  45,  18 },  {  -58,  70,  50,  16 } } },  /* 34: F JUMP K M A; attack 36 */
    { { {  -52,  24,  18,  28 },  {  -36,  24,   4,  28 } } },  /* 35: ATTACK 2 L: not started by a command, ATTACK 2 SP: not started by a command; attack 73, 83 */
    { { {  -55,  16,  93,  19 },  {  -45,  20,  81,  14 } } },  /* 36: not used by a script */
    { { {  -66,  48,  80,  20 },  {  -81,  25,  93,  18 } } },  /* 37: V JUMP K L A; attack 31 */
    { { {  -73,  17,  63,  18 },  {  -56,  38,  63,  14 } } },  /* 38: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command; attack 39, 88 */
    { { {   18,  35,  66,  14 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1; attack 39, 40, 88 */
    { { {   -2,  33,  55,  20 },  {    0,   0,   0,   0 } } },  /* 40: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {  -61,  15,  58,  19 },  {  -55,  25,  79,   9 } } },  /* 42: not used by a script */
    { { {  -61,  13,  32,  28 },  {  -47,  13,  49,  24 } } },  /* 43: not used by a script */
    { { {  -42,  21,  58,  18 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -52,  22,  56,  18 },  {  -40,  20,  48,  16 } } },  /* 45: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1; attack 38, 75, 87 */
    { { {  -98,  26,  70,  22 },  {  -70,  26,  62,  22 } } },  /* 46: not used by a script */
    { { {  -78,  28,  70,  14 },  {    0,   0,   0,   0 } } },  /* 47: not used by a script */
    { { {  -86,  16,  52,  18 },  {  -70,  47,  54,  17 } } },  /* 48: F JUMP K L A; attack 37 */
    { { {  -85,  34,  84,  24 },  {  -67,  27,  65,  31 } } },  /* 49: not used by a script */
    { { {  -74,  61,  78,  10 },  {    0,   0,   0,   0 } } },  /* 50: FUSHIN P S; attack 69 */
    { { {  -71,  95,  50,  23 },  {  -62,  95,   0,  50 } } },  /* 51: ATTACK 5 S: not started by a command; attack 56 */
    { { {  -46,  61,  34,  96 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 5 S: not started by a command; attack 57, 58, 59 */
    { { {  -16,  27, 101,  34 },  {  -40,  28,  40,  38 } } },  /* 53: not used by a script */
    { { {   -5,  28,  99,  30 },  {   -6,  25,  35,  46 } } },  /* 54: not used by a script */
    { { {  -73,  17,  60,  18 },  {  -56,  38,  61,  14 } } },  /* 55: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1; attack 90, 94 */
    { { {   18,  35,  61,  14 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1; attack 91, 95 */
    { { {  -73,  21,  75,  17 },  {  -50,  27,  46,  31 } } },  /* 57: UP P GUARD K M; attack 13 */
    { { {  -71,  29,  76,  18 },  {  -42,  23,  58,  19 } } },  /* 58: M KICK A, UP P GUARD K M; attack 13 */
    { { {  -76,  18,  59,  11 },  {  -56,  17,  69,  11 } } },  /* 59: not used by a script */
    { { {  -94,  48,  22,  51 },  {  -60,  53,   0,  81 } } },  /* 60: ATTACK 6 S: not started by a command; attack 64, 67 */
    { { {  -89,  46,  58,  50 },  {  -59,  53,   0,  85 } } },  /* 61: ATTACK 6 S: not started by a command; attack 63, 64 */
    { { { -101, 124,  33,  70 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 6 S: not started by a command; attack 65, 68 */
    { { {  -24, 115,  27,  82 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 6 S: not started by a command; attack 66, 68 */
    { { {  -97,  53,   0,  34 },  {  -64,  64,   0,  58 } } },  /* 64: not used by a script */
    { { {  -93,  49,  45,  42 },  {  -74,  44,   0,  74 } } },  /* 65: not used by a script */
    { { { -100,  37,   0,  19 },  {  -57,  45,   2,  21 } } },  /* 66: not used by a script */
    { { {  -77, 119,   0,  64 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 5 S: not started by a command; attack 56 */
    { { {  -78,  68,  43,  17 },  {  -40,  45,  31,  19 } } },  /* 68: UP P GUARD K L; attack 17 */
    { { {  -69,  63,  19,  53 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 4 S: not started by a command; attack 41, 43, 45, 46 */
    { { {  -42,  33,  69,  69 },  {  -55,  45,  18,  60 } } },  /* 70: ATTACK 4 S: not started by a command; attack 42, 44, 46 */
    { { {  -72,  25,  39,  22 },  {  -47,  28,  49,  29 } } },  /* 71: not used by a script */
    { { {  -87,  65,  57,  18 },  {    0,   0,   0,   0 } } },  /* 72: V JUMP K M A; attack 30 */
    { { {  -92,  64,  36,  14 },  {  -66,  64,  24,  14 } } },  /* 73: ATTACK 6 S: not started by a command; attack 71 */
    { { {  -96,  30,  44,  14 },  {  -65,  38,  44,  14 } } },  /* 74: not used by a script */
    { { {  -49,  26,  29,  49 },  {    0,   0,   0,   0 } } },  /* 75: not used by a script */
    { { {  -63,  47,  48,  39 },  {    0,   0,   0,   0 } } },  /* 76: L PUNCH A; attack 7 */
    { { {  -49,  26,  29,  49 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 9 M: not started by a command; attack 74 */
    { { {  -41,  81,   0,  24 },  {    0,   0,   0,   0 } } },  /* 78: OKIAGARI P S; attack 76 */
    { { {  -42,  27,  42,  33 },  {  -30,  26, 100,  39 } } },  /* 79: OKIAGARI P S; attack 2, 76 */
    { { {  -52,  27,  42,  47 },  {  -39,  30, 102,  39 } } },  /* 80: not used by a script */
    { { {  -66,  41,  66,  13 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1; attack 40, 81, 82, 89 */
    { { {  -60,  17,  82,  18 },  {  -45,  17,  70,  18 } } },  /* 82: not used by a script */
    { { {  -71,  22,  60,  21 },  {  -48,  22,  60,  21 } } },  /* 83: not used by a script */
};

const CATCH_BOX ken_cat_box[82] = {
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
    { {  -31,    6,    0,   16 } },  /* 41: M PUNCH A, M PUNCH B, M KICK A +4 */
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
    { {    0,    0,    0,    0 } },  /* 61: no box */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
    { {    0,    0,    0,    0 } },  /* 65: no box */
    { {    0,    0,    0,    0 } },  /* 66: no box */
    { {    0,    0,    0,    0 } },  /* 67: no box */
    { {    0,    0,    0,    0 } },  /* 68: no box */
    { {    0,    0,    0,    0 } },  /* 69: no box */
    { {    0,    0,    0,    0 } },  /* 70: no box */
    { {    0,    0,    0,    0 } },  /* 71: no box */
    { {    0,    0,    0,    0 } },  /* 72: no box */
    { {    0,    0,    0,    0 } },  /* 73: no box */
    { {  -35,   10,    0,   16 } },  /* 74: L PUNCH A, L PUNCH B, L KICK A */
    { {    0,    0,    0,    0 } },  /* 75: no box */
    { {    0,    0,    0,    0 } },  /* 76: no box */
    { {    0,    0,    0,    0 } },  /* 77: no box */
    { {    0,    0,    0,    0 } },  /* 78: no box */
    { {    0,    0,    0,    0 } },  /* 79: no box */
    { {    0,    0,    0,    0 } },  /* 80: no box */
    { {    0,    0,    0,    0 } },  /* 81: no box */
};

const CAUGHT_BOX ken_cau_box[20] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +123 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +28 */
    { {  -25,   50,   48,   40 } },  /* 3: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +14 */
    { {  -25,   50,   48,   40 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +19 */
    { {   -1,   48,    0,   90 } },  /* 5: not used by a script */
    { {  -21,   36,    0,   90 } },  /* 6: not used by a script */
    { {  -36,   36,    0,   90 } },  /* 7: not used by a script */
    { {  -29,   54,    0,   16 } },  /* 8: S KICK A */
    { {  -33,   58,    0,    8 } },  /* 9: KAGAMI P A, KAGAMI K A */
    { {  -28,   48,    0,   58 } },  /* 10: not used by a script */
    { {  -28,   45,   46,   61 } },  /* 11: not used by a script */
    { {  -24,   44,   54,   52 } },  /* 12: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { {  -25,   50,   48,   40 } },  /* 13: TOUKETSU A, AIR S, AIR M +42 */
    { {  -22,   48,    0,   82 } },  /* 14: not used by a script */
    { {  -46,   80,    0,   16 } },  /* 15: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    { {  -41,   81,    0,   16 } },  /* 16: OKIAGARI P S */
    { {  -36,   73,   46,   49 } },  /* 17: OKIAGARI P S */
    { {  -38,   63,    0,   16 } },  /* 18: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -25,   50,   24,   40 } },  /* 19: PARING AIR F, PARING AIR B */
};
