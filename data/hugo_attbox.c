/*
 * HUGO_ATTBOX.C  Hugo's attack, catch and caught boxes
 *
 * Selected per animation frame through hugo_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX hugo_att_box[64] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { { -121,  34,  61,  17 },  {  -85,  51,  61,  17 } } },  /* 1: S PUNCH A; attack 1 */
    { { { -111,  24,  62,  10 },  {  -86,  53,  62,  10 } } },  /* 2: S PUNCH A; attack 1 */
    { { { -117,  60,  58,  27 },  {  -89,  58,  78,  12 } } },  /* 3: M PUNCH A; attack 2 */
    { { { -108,  49,  58,  29 },  {  -89,  58,  78,  12 } } },  /* 4: M PUNCH A; attack 2 */
    { { {  -87,  36,  51,  23 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A; attack 3 */
    { { {  -78,  21,  64,  23 },  {  -57,  13,  67,  22 } } },  /* 6: L PUNCH A */
    { { {  -99,  35,  82,  30 },  {  -64,  40,  86,  26 } } },  /* 7: L PUNCH B; attack 6 */
    { { {  -92,  28,  92,  27 },  {  -64,  39,  88,  22 } } },  /* 8: L PUNCH B */
    { { { -106,  13,  24,  22 },  {  -93,  60,  33,  13 } } },  /* 9: S KICK A; attack 7 */
    { { {  -96,  23,  26,  16 },  {  -73,  32,  34,  12 } } },  /* 10: S KICK A */
    { { { -103,  29,  88,  28 },  {  -79,  33,  70,  26 } } },  /* 11: M KICK A; attack 8 */
    { { {  -98,  24,  88,  19 },  {  -74,  29,  70,  21 } } },  /* 12: M KICK A */
    { { { -112,  64,  24,  56 },  {    0,   0,   0,   0 } } },  /* 13: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +2; attack 9, 10, 11, 33 ... */
    { { {  -98,  29,  56,  27 },  {  -68,  37,  67,  17 } } },  /* 14: L KICK A; attack 12 */
    { { {  -88,  22,  63,  21 },  {  -66,  32,  63,  21 } } },  /* 15: L KICK A */
    { { { -120,  28,  32,  17 },  {  -92,  48,  32,  17 } } },  /* 16: not used by a script */
    { { { -114,  19,  32,  17 },  {  -96,  54,  33,  15 } } },  /* 17: KAGAMI P A; attack 14 */
    { { { -123,  32,  32,  17 },  {  -92,  50,  32,  17 } } },  /* 18: KAGAMI P A; attack 15 */
    { { { -120,  29,  32,  17 },  {  -92,  47,  33,  15 } } },  /* 19: KAGAMI P A */
    { { { -104,  19,   0,  16 },  {  -85,  50,   0,  16 } } },  /* 20: KAGAMI K A; attack 16 */
    { { { -123,  25,   0,  25 },  {  -98,  67,   0,  21 } } },  /* 21: KAGAMI K A; attack 24 */
    { { { -117,  21,   0,  24 },  {  -96,  65,   0,  18 } } },  /* 22: KAGAMI K A */
    { { {  -50,  24,  91,  16 },  {  -44,  27,  72,  23 } } },  /* 23: KAGAMI P A; attack 17 */
    { { {  -52,  26,  88,  15 },  {  -42,  27,  73,  19 } } },  /* 24: KAGAMI P A; attack 18 */
    { { {  -56,  27,  77,  14 },  {  -46,  24,  57,  20 } } },  /* 25: KAGAMI P A; attack 18 */
    { { {  -63,  23,  75,  12 },  {  -50,  25,  60,  19 } } },  /* 26: not used by a script */
    { { {  -52,  37,  44,  24 },  {  -39,  24,  37,   7 } } },  /* 27: KAGAMI K A; attack 19 */
    { { {  -46,  37,  42,  21 },  {  -33,  24,  35,   7 } } },  /* 28: KAGAMI K A; attack 19 */
    { { {  -44,  37,  38,  17 },  {  -31,  24,  31,   7 } } },  /* 29: KAGAMI K A; attack 20 */
    { { {  -99,  26,   0,  16 },  {  -73,  47,   0,  16 } } },  /* 30: not used by a script */
    { { { -106,  29,  76,  20 },  {  -81,  37,  91,  16 } } },  /* 31: V JUMP P S A; attack 25 */
    { { {  -95,  30,  84,  19 },  {  -75,  38,  98,  15 } } },  /* 32: V JUMP P S A; attack 25 */
    { { {  -87,  31,  95,  15 },  {  -67,  33, 102,  16 } } },  /* 33: V JUMP P S A; attack 25 */
    { { { -121,  37,  89,  32 },  {  -84,  52,  93,  26 } } },  /* 34: V JUMP P L A; attack 28 */
    { { { -105,  27,  89,  31 },  {  -79,  46,  93,  25 } } },  /* 35: V JUMP P L A; attack 28 */
    { { {  -63,  19,  60,  24 },  {  -58,  30,  73,  16 } } },  /* 36: V JUMP K S A; attack 29 */
    { { {  -58,  16,  60,  22 },  {  -51,  27,  73,  14 } } },  /* 37: V JUMP K S A; attack 29 */
    { { {  -60,  19,  53,  27 },  {  -50,  30,  70,  16 } } },  /* 38: V JUMP K M A; attack 30 */
    { { {  -56,  18,  53,  25 },  {  -48,  28,  70,  15 } } },  /* 39: V JUMP K M A */
    { { {  -96,  25,  60,  33 },  {  -71,  43,  67,  27 } } },  /* 40: V JUMP K L A; attack 31 */
    { { {  -92,  20,  62,  29 },  {  -72,  36,  69,  24 } } },  /* 41: V JUMP K L A; attack 31 */
    { { {  -89,  25,  58,  36 },  {  -70,  64,  66,  27 } } },  /* 42: not used by a script */
    { { {  -81,  35,  34,  30 },  {    0,   0,   0,   0 } } },  /* 43: M KICK A; attack 32 */
    { { { -120,  41,  84,  17 },  {  -85,  41,  95,  19 } } },  /* 44: V JUMP P M A; attack 27 */
    { { { -109,  45,  87,  18 },  {  -79,  39,  98,  19 } } },  /* 45: V JUMP P M A; attack 27 */
    { { {  -99,  37,  95,  17 },  {  -67,  33, 103,  18 } } },  /* 46: V JUMP P M A; attack 27 */
    { { {  -38,  18,  68,  38 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1; attack 43, 66 */
    { { {  -35,  18,  68,  37 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -61,  38,  82,  23 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -63,  62,  86,  29 },  {    0,   0,   0,   0 } } },  /* 50: not used by a script */
    { { {  -44,  72,  71,  21 },  {  -69,  43,  79,  31 } } },  /* 51: V JUMP P L B; attack 53 */
    { { {  -90, 200,   0,  16 },  {    0,   0,   0,   0 } } },  /* 52: CATCH 29; attack 58 */
    { { {  -74,  59,  49,  66 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 9 S: not started by a command; attack 62 */
    { { {  -63,  49,  36,  64 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 8 S: not started by a command; attack 59 */
    { { {  -57,  43,  36,  68 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 8 S: not started by a command */
    { { {  -72,  66,  56,  50 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 8 S: not started by a command */
    { { { -103,  44,  60,  42 },  {  -59,  45,  68,  36 } } },  /* 57: ATTACK 9 S: not started by a command; attack 60 */
    { { {  -98,  58,  47,  36 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 9 S: not started by a command; attack 61 */
    { { { -116,  71,  34,  49 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 9 S: not started by a command; attack 63 */
    { { { -100,  32, 108,  16 },  {  -68,  32, 100,  16 } } },  /* 60: ATTACK 9 M: not started by a command; attack 64 */
    { { {  -93,  36,  74,  38 },  {  -64,  52,  76,  30 } } },  /* 61: ATTACK 9 S: not started by a command; attack 60 */
    { { {  -83,  29,  60,  31 },  {  -57,  26,  62,  24 } } },  /* 62: ATTACK 9 S: not started by a command; attack 61 */
    { { {  -58,  40,  34,  32 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 10 S: not started by a command; attack 65 */
};

const CATCH_BOX hugo_cat_box[10] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -44,   10,    0,   16 } },  /* 1: L PUNCH A */
    { {  -76,   44,    0,   16 } },  /* 2: ATTACK 3 S: not started by a command */
    { {  -70,   38,    0,   16 } },  /* 3: ATTACK 3 M: not started by a command */
    { {  -64,   32,    0,   16 } },  /* 4: ATTACK 3 L: not started by a command */
    { {  -51,   26,   79,   35 } },  /* 5: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    { {  -68,   47,   64,   57 } },  /* 6: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    { {  -87,   55,    0,   16 } },  /* 7: ATTACK 6 S: not started by a command */
    { {  -55,   23,    0,   16 } },  /* 8: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command */
    { {  -40,    6,    0,   16 } },  /* 9: M PUNCH A */
};

const CAUGHT_BOX hugo_cau_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -32,   67,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +95 */
    { {  -36,   71,    0,   16 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +27 */
    { {  -27,   54,   63,   58 } },  /* 3: JUMP FRONT, JUMP VERTICAL, JUMP BACK +28 */
    { {  -41,   67,    0,   16 } },  /* 4: DASH HUMIKOMI */
    { {  -44,   67,    0,   16 } },  /* 5: DASH TOBINOKI */
    { {  -41,   65,   34,   58 } },  /* 6: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   34,   58 } },  /* 7: AIR S, AIR M, AIR L +36 */
    { {  -57,   62,   23,   58 } },  /* 8: not used by a script */
    { {  -51,   81,   77,   41 } },  /* 9: V JUMP P L B */
    { {  -40,   75,    0,   16 } },  /* 10: KAGAMI P A, KAGAMI K A */
    { {  -40,   75,    0,   16 } },  /* 11: ATTACK 3 S: not started by a command, ATTACK 4 S: not started by a command, ATTACK 6 S: not started by a command +1 */
};
