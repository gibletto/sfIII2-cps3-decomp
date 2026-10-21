/*
 * GILL_HITBOX.C  Gill's hit boxes
 *
 * Each of Gill's animation frames names an entry of gill_hit_ix_table (cg_hit_ix in the frame
 * record). The entry picks the boxes that frame uses; set_char_base_data (CHARID) points the work
 * at these tables through char_init_data. A box is x, width, y, height from the character's
 * position, x mirrored when facing left; width 0 means no box.
 *
 * hit_ix_table  one row per animation frame pose (a script line's hit field picks it); each column
 *               picks a row of one box table (0 = none):
 *     boix  body box: where this character can be hit (body_box)
 *     haix  hand box: extra damage boxes on an extended arm or leg (hand_box)
 *     free  unused (0 in every row)
 *     caix  catch box: this frame's throw reach (cat_box in _attbox.c)
 *     cuix  caught box: where this character can be thrown (cau_box in _attbox.c)
 *     atix  attack box: where this frame hits (att_box in _attbox.c)
 *     eaix  attack boxes the hit check tests before atix's, which cannot themselves be hit (h_eat);
 *           0 in every row
 *     hoix  push box: keeps the two fighters apart (hos_box)
 * body_box      four damage boxes (head down to legs)
 * hand_box      two damage boxes for an extended arm or leg, hit only from the front
 * hos_box       the push box: where two fighters' push boxes overlap they are moved apart; attacks
 *               whose attribute has free4 bit 7 also hit it
 *
 * Row comments: the moves whose frames use the row or box (debug viewer names). Row 0 of a
 * box table is no box.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const HIT_IX gill_hit_ix_table[128] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: TATAKI M, TATAKI L, TATAKI SP +23 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +77 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +29 */
    {    3,    3,    0,    0,    6,    0,    0,    9 },  /* 3: DASH HUMIKOMI */
    {    4,    4,    0,    0,    6,    0,    0,    9 },  /* 4: DASH HUMIKOMI */
    {    5,    5,    0,    0,    2,    0,    0,    2 },  /* 5: DASH TOBINOKI */
    {    6,    6,    0,    0,    1,    0,    0,    1 },  /* 6: DASH TOBINOKI */
    {    7,    7,    0,    0,    1,    0,    0,    1 },  /* 7: DASH HUMIKOMI, DASH TOBINOKI */
    {    8,    8,    0,    0,    3,    0,    0,    3 },  /* 8: S JUMP FRONT, GUARD AIR, V JUMP P M A +19 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 9: ATTACK 8 M: SA I (never)+P (routine Att_RESURRECTION); SA II (never)+P (routine Att_RESURRECTION); SA III (never)+P (routine Att_RESURRECTION) */
    {   10,   10,    0,    0,    3,    0,    0,    3 },  /* 10: not used by a script */
    {   11,   11,    0,    1,    1,    1,    0,    1 },  /* 11: S PUNCH A, UP P GUARD P S */
    {   11,   11,    0,    0,    1,    0,    0,    1 },  /* 12: S PUNCH A, UP P GUARD P S */
    {   12,   12,    0,    0,    1,    0,    0,    1 },  /* 13: M PUNCH C, L PUNCH A */
    {   12,   12,    0,    2,    1,    2,    0,    1 },  /* 14: P BREAK AIR F, TUKAMIHAZUSI, M PUNCH C */
    {   96,   96,    0,    3,    1,    3,    0,    1 },  /* 15: M PUNCH C, UP P GUARD P M */
    {   13,   13,    0,    0,    1,    0,    0,    1 },  /* 16: M PUNCH C, UP P GUARD P M */
    {   19,   19,    0,    0,    1,    0,    0,    1 },  /* 17: S KICK A */
    {   19,   19,    0,    7,    1,    7,    0,    1 },  /* 18: S KICK A, UP P GUARD P L */
    {   21,   21,    0,    0,    1,    0,    0,    1 },  /* 19: M KICK A, M KICK C */
    {   22,   22,    0,    8,    1,    8,    0,    1 },  /* 20: M KICK A, M KICK C */
    {   22,   22,    0,    9,    1,    9,    0,    1 },  /* 21: M KICK A, M KICK C */
    {   22,   22,    0,    0,    1,    0,    0,    1 },  /* 22: M KICK A, M KICK C */
    {   23,   23,    0,    0,    1,    0,    0,    1 },  /* 23: L KICK A */
    {   24,   24,    0,    0,    1,    0,    0,    1 },  /* 24: L KICK A */
    {   88,   88,    0,   38,    1,   38,    0,    1 },  /* 25: L KICK A */
    {   25,   25,    0,   39,    1,   39,    0,    1 },  /* 26: L KICK A */
    {   26,   26,    0,   40,    1,   40,    0,    1 },  /* 27: L KICK A */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 28: L KICK A, UP P GUARD P L */
    {   31,   31,    0,   13,    2,   13,    0,    2 },  /* 29: KAGAMI P A, atca 156, UP P GUARD P L */
    {   31,   31,    0,    0,    2,    0,    0,    2 },  /* 30: KAGAMI P A, atca 156, UP P GUARD P L */
    {   33,   33,    0,    0,    1,    0,    0,    1 },  /* 31: KAGAMI P A, UP P GUARD P L */
    {   34,   34,    0,   15,    2,   15,    0,    2 },  /* 32: KAGAMI K A, UP P GUARD P L */
    {   34,   34,    0,   41,    2,   41,    0,    2 },  /* 33: UP P GUARD P L */
    {   29,   29,    0,    0,    1,    0,    0,    5 },  /* 34: not used by a script */
    {   30,   30,    0,   12,    1,   12,    0,    5 },  /* 35: not used by a script */
    {   30,   30,    0,    0,    1,    0,    0,    5 },  /* 36: not used by a script */
    {   31,   31,    0,   10,    2,   10,    0,    2 },  /* 37: KAGAMI P A, atca 156 */
    {   32,   32,    0,    0,    2,    0,    0,    2 },  /* 38: KAGAMI P A */
    {   32,   32,    0,   14,    2,   14,    0,    2 },  /* 39: KAGAMI P A */
    {   33,   33,    0,   11,    1,   11,    0,    1 },  /* 40: KAGAMI P A */
    {   34,   34,    0,    0,    2,    0,    0,    2 },  /* 41: KAGAMI K A */
    {   35,   35,    0,   42,    2,   42,    0,    2 },  /* 42: KAGAMI K A */
    {   35,   35,    0,    0,    2,    0,    0,    2 },  /* 43: KAGAMI K A */
    {   89,   89,    0,   44,    3,   44,    0,    3 },  /* 44: V JUMP P L A */
    {   89,   89,    0,    0,    3,    0,    0,    3 },  /* 45: V JUMP P L A */
    {   89,   89,    0,   16,    3,   16,    0,    3 },  /* 46: V JUMP P L A */
    {   87,   87,    0,   18,    3,   18,    0,    3 },  /* 47: V JUMP P M A */
    {   86,   86,    0,    0,    3,    0,    0,    3 },  /* 48: V JUMP P M A, V JUMP P L A */
    {   87,   87,    0,   43,    3,   43,    0,    3 },  /* 49: V JUMP P M A */
    {   87,   87,    0,    0,    3,    0,    0,    3 },  /* 50: V JUMP P M A */
    {   49,   49,    0,    0,    3,    0,    0,    3 },  /* 51: V JUMP K S A, V JUMP K M A, FUSHIN P S */
    {   49,   49,    0,   19,    3,   19,    0,    3 },  /* 52: V JUMP K S A */
    {   40,   40,    0,   21,    3,   21,    0,    3 },  /* 53: V JUMP K M A, FUSHIN P S */
    {   40,   40,    0,   22,    3,   22,    0,    3 },  /* 54: V JUMP K M A, FUSHIN P S, ATTACK 4 M: not started by a command */
    {   91,   91,    0,    0,    3,    0,    0,    3 },  /* 55: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +6 */
    {   92,   92,    0,    0,    3,    0,    0,    3 },  /* 56: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    {   93,   93,    0,    0,    3,    0,    0,    3 },  /* 57: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {   94,   94,    0,   45,    3,   45,    0,    3 },  /* 58: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    {   90,   90,    0,    0,    1,    0,    0,    1 },  /* 59: FRONT WALK, BACK WALK */
    {   47,   47,    0,    0,    3,    0,    0,    3 },  /* 60: V JUMP P S A, V JUMP P M A, V JUMP P L A +6 */
    {   48,   48,    0,   17,    3,   17,    0,    3 },  /* 61: V JUMP P S A */
    {   52,   52,    0,    0,    1,    0,    0,    1 },  /* 62: follow-up of APPEAR JUNBI 6 */
    {   53,   53,    0,   25,    1,   25,    0,    1 },  /* 63: follow-up of APPEAR JUNBI 6 */
    {   53,   53,    0,    0,    1,    0,    0,    1 },  /* 64: not used by a script */
    {   54,   54,    0,    0,    3,    0,    0,    3 },  /* 65: not used by a script */
    {   55,   55,    0,    0,    3,    0,    0,    3 },  /* 66: not used by a script */
    {   56,   56,    0,    0,    3,    0,    0,    3 },  /* 67: follow-up of APPEAR JUNBI 6 */
    {   57,   57,    0,    0,    3,    0,    0,    3 },  /* 68: not used by a script */
    {   58,   58,    0,    0,    3,    0,    0,    3 },  /* 69: not used by a script */
    {   59,   59,    0,   26,    3,   26,    0,    3 },  /* 70: not used by a script */
    {    8,    8,    0,   27,    3,   27,    0,    3 },  /* 71: not used by a script */
    {   30,   30,    0,   28,    1,   28,    0,    5 },  /* 72: not used by a script */
    {    1,    1,    0,   29,    1,   29,    0,    1 },  /* 73: M PUNCH A, M PUNCH C, L PUNCH A +4 */
    {    1,    1,    0,   30,    1,   30,    0,    1 },  /* 74: TUKAMIKAKARI A */
    {   62,   62,    0,    0,    1,    0,    0,    1 },  /* 75: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    {   63,   63,    0,    0,    1,    0,    0,    1 },  /* 76: ATTACK 3 M: 236+P light (plain script) */
    {   64,   64,    0,    0,    4,    0,    0,    7 },  /* 77: ATTACK 3 M: 236+P light (plain script) */
    {   65,   65,    0,    0,    4,    0,    0,    7 },  /* 78: ATTACK 3 M: 236+P light (plain script) */
    {   66,   66,    0,    0,    4,    0,    0,    7 },  /* 79: ATTACK 3 M: 236+P light (plain script) */
    {   67,   67,    0,    0,    4,    0,    0,    7 },  /* 80: ATTACK 3 L: 236+P medium (plain script) */
    {   68,   68,    0,    0,    4,    0,    0,    7 },  /* 81: ATTACK 3 SP: 236+P heavy/EX (plain script) */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 82: TATAKI S, NEKOROBI S, OKIAGARI +12 */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 83: AIR S, AIR M, AIR L +2 */
    {   69,   69,    0,    0,    1,    0,    0,    5 },  /* 84: not used by a script */
    {   70,   70,    0,    0,    1,    0,    0,    1 },  /* 85: PIYO */
    {   71,   71,    0,    0,    1,    0,    0,    1 },  /* 86: PIYO */
    {   72,   72,    0,    0,    1,    0,    0,    8 },  /* 87: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   73,   73,    0,    0,    3,    0,    0,    3 },  /* 88: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   74,   74,    0,    0,    3,    0,    0,    3 },  /* 89: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   75,   75,    0,    0,    3,    0,    0,    3 },  /* 90: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   75,   75,    0,   31,    3,   31,    0,    3 },  /* 91: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   76,   76,    0,   32,    3,   32,    0,    3 },  /* 92: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   76,   76,    0,    0,    3,    0,    0,    3 },  /* 93: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   77,   77,    0,    0,    3,    0,    0,    3 },  /* 94: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   78,   78,    0,   33,    0,   33,    0,    0 },  /* 95: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   79,   79,    0,    0,    1,    0,    0,    1 },  /* 96: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   80,   80,    0,   34,    1,   34,    0,    1 },  /* 97: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   81,   81,    0,    0,    1,    0,    0,    1 },  /* 98: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   82,   82,    0,    0,    3,    0,    0,    3 },  /* 99: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   83,   83,    0,   35,    3,   35,    0,    3 },  /* 100: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   83,   83,    0,    0,    3,    0,    0,    3 },  /* 101: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   84,   84,    0,    0,    3,    0,    0,    3 },  /* 102: not used by a script */
    {   85,   85,    0,    0,    3,    0,    0,    3 },  /* 103: not used by a script */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 104: follow-up of APPEAR 2 */
    {    2,    2,    0,    0,    0,    0,    0,    2 },  /* 105: follow-up of APPEAR 2 */
    {   14,   14,    0,    0,    1,    0,    0,    1 },  /* 106: M PUNCH A */
    {   14,   14,    0,   37,    1,   37,    0,    1 },  /* 107: M PUNCH A */
    {   14,   14,    0,   37,    1,   37,    0,    1 },  /* 108: M PUNCH A */
    {   15,   15,    0,    0,    1,    0,    0,    1 },  /* 109: L PUNCH A */
    {   16,   16,    0,    0,    1,    0,    0,    1 },  /* 110: L PUNCH A */
    {   17,   17,    0,    5,    1,    5,    0,    1 },  /* 111: L PUNCH A */
    {   17,   17,    0,    6,    1,    6,    0,    1 },  /* 112: L PUNCH A */
    {   17,   17,    0,    0,    1,    0,    0,    1 },  /* 113: L PUNCH A */
    {   41,   41,    0,    0,    3,    0,    0,    3 },  /* 114: V JUMP K L A */
    {   42,   42,    0,    0,    3,    0,    0,    3 },  /* 115: V JUMP K L A */
    {   43,   43,    0,   24,    3,   24,    0,    3 },  /* 116: V JUMP K L A */
    {   43,   43,    0,   24,    3,   24,    0,    3 },  /* 117: V JUMP K L A */
    {   43,   43,    0,    0,    3,    0,    0,    3 },  /* 118: V JUMP K L A */
    {   44,   44,    0,    0,    3,    0,    0,    3 },  /* 119: V JUMP K L A */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 120: not used by a script */
    {   78,   78,    0,   33,    0,   33,    0,    1 },  /* 121: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   95,   95,    0,    0,    3,    0,    0,    3 },  /* 122: PARING AIR F, PARING AIR B */
    {    2,    2,    0,    0,    2,    0,    0,   10 },  /* 123: KAGAMI P A, atca 156 */
    {   97,    0,    0,    0,    7,    0,    0,   11 },  /* 124: TUKAMIHAZUSI, AIR S, AIR M +40 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 125: ATTACK 9 L: SA (all arts) 23623+P (plain script) */
    {    0,    0,    0,    0,    0,    0,    0,   10 },  /* 126: ATTACK 9 L: SA (all arts) 23623+P (plain script) */
    {   98,    0,    0,    0,    0,    0,    0,    2 },  /* 127: dmca 97 */
};

const BODY_BOX gill_body_box[99] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -21,  27, 102,  18 },  {  -40,  68,  92,  14 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +78 */
    { { {  -12,  32,  54,  18 },  {  -32,  70,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +29 */
    { { {  -50,  22,  92,  18 },  {  -38,  60,  94,  12 },  {  -32,  60,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 3: DASH HUMIKOMI */
    { { {  -34,  22,  86,  18 },  {  -28,  52,  81,  16 },  {  -28,  52,  41,  39 },  {  -32,  72,   0,  40 } } },  /* 4: DASH HUMIKOMI */
    { { {  -16,  22,  74,  18 },  {  -28,  52,  33,  16 },  {  -24,  48,  44,  20 },  {  -32,  72,   0,  44 } } },  /* 5: DASH TOBINOKI */
    { { {   -2,  22, 114,  18 },  {  -20,  68, 104,  12 },  {  -20,  61,  51,  52 },  {  -32,  72,   0,  50 } } },  /* 6: DASH TOBINOKI */
    { { {  -22,  22,  90,  18 },  {  -26,  64,  85,  12 },  {  -26,  66,  41,  42 },  {  -32,  72,   0,  40 } } },  /* 7: DASH HUMIKOMI, DASH TOBINOKI */
    { { {   -8,  24, 118,  18 },  {  -26,  62, 106,  16 },  {  -22,  46,  62,  42 },  {  -12,  44,  28,  36 } } },  /* 8: S JUMP FRONT, GUARD AIR, V JUMP P M A +19 */
    { { {  -32,  22, 106,  18 },  {  -28,  56,  92,  24 },  {  -20,  44,  50,  44 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {  -48,  22,  92,  18 },  {  -28,  56,  88,  28 },  {  -32,  60,  50,  38 },  {    0,   0,   0,   0 } } },  /* 10: not used by a script */
    { { {  -18,  24, 102,  18 },  {  -40,  68,  92,  14 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 11: S PUNCH A, UP P GUARD P S */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 12: M PUNCH C, L PUNCH A, P BREAK AIR F +1 */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 13: M PUNCH C, UP P GUARD P M */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 14: M PUNCH A */
    { { {   -2,  24, 100,  18 },  {  -32,  76,  92,  14 },  {  -20,  52,  52,  38 },  {  -34,  70,   0,  50 } } },  /* 15: L PUNCH A */
    { { {  -44,  40, 100,  16 },  {  -40,  68,  88,  14 },  {  -32,  52,  48,  38 },  {  -36,  78,   0,  46 } } },  /* 16: L PUNCH A */
    { { {  -34,  50,  80,  22 },  {  -50,  70,  54,  24 },  {  -30,  56,  40,  24 },  {  -40,  92,   0,  40 } } },  /* 17: L PUNCH A */
    { { {  -10,  22, 102,  18 },  {  -32,  64,  94,  12 },  {  -32,  64,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 18: not used by a script */
    { { {  -34,  24,  98,  18 },  {  -44,  66,  88,  14 },  {  -30,  46,  50,  36 },  {  -52,  60,   0,  48 } } },  /* 19: S KICK A, UP P GUARD P L */
    { { {  -15,  19, 103,  16 },  {  -27,  51,  94,  12 },  {  -20,  30,  41,  52 },  {  -22,  41,   0,  40 } } },  /* 20: not used by a script */
    { { {   -2,  24,  98,  18 },  {  -40,  68,  88,  14 },  {  -26,  52,  52,  38 },  {  -14,  36,   0,  50 } } },  /* 21: M KICK A, M KICK C */
    { { {   -8,  32,  96,  18 },  {  -58,  92,  70,  24 },  {  -34,  38,  50,  26 },  {  -16,  34,   0,  48 } } },  /* 22: M KICK A, M KICK C */
    { { {  -12,  24, 104,  18 },  {  -24,  68,  92,  14 },  {  -22,  50,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 23: L KICK A */
    { { {   -2,  24, 106,  18 },  {  -26,  68,  94,  14 },  {  -22,  60,  58,  34 },  {   -8,  34,   0,  56 } } },  /* 24: L KICK A */
    { { {   10,  24,  96,  18 },  {  -20,  68,  86,  14 },  {  -44,  76,  56,  30 },  {  -10,  34,   0,  54 } } },  /* 25: L KICK A */
    { { {   16,  24,  94,  18 },  {   -8,  68,  84,  14 },  {  -28,  78,  60,  24 },  {  -14,  34,   0,  58 } } },  /* 26: L KICK A */
    { { {   20,  28,  94,  18 },  {  -16,  78,  66,  30 },  {  -44,  58,  36,  32 },  {  -12,  34,   0,  40 } } },  /* 27: L KICK A, UP P GUARD P L */
    { { {   20,  22,  96,  18 },  {  -12,  72,  78,  24 },  {  -36,  80,  41,  36 },  {  -16,  48,   0,  40 } } },  /* 28: not used by a script */
    { { {   -8,  22, 106,  18 },  {  -24,  60,  94,  12 },  {  -24,  60,  41,  52 },  {  -12,  48,   0,  40 } } },  /* 29: not used by a script */
    { { {  -30,  22, 108,  18 },  {  -16,  56, 100,  28 },  {  -24,  64,  48,  52 },  {    0,   0,   0,   0 } } },  /* 30: not used by a script */
    { { {  -24,  32,  54,  18 },  {  -44,  70,  44,  14 },  {  -32,  76,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 31: KAGAMI P A, atca 156, UP P GUARD P L */
    { { {  -20,  26,  70,  18 },  {  -34,  56,  60,  14 },  {  -46,  76,  36,  22 },  {  -44,  88,   0,  34 } } },  /* 32: KAGAMI P A */
    { { {  -16,  24, 100,  18 },  {  -26,  54,  88,  14 },  {  -22,  48,  36,  50 },  {  -38,  82,   0,  34 } } },  /* 33: KAGAMI P A, UP P GUARD P L */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 34: KAGAMI K A, UP P GUARD P L */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 35: KAGAMI K A */
    { { {  -18,  19, 107,  16 },  {  -24,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {   -2,  40, 106,  16 },  {  -18,  60,  88,  22 },  {  -36,  82,  66,  30 },  {   -6,  40,  48,  22 } } },  /* 40: V JUMP K M A, FUSHIN P S, ATTACK 4 M: not started by a command */
    { { {   -2,  24, 110,  18 },  {  -32,  66, 102,  14 },  {  -28,  56,  76,  26 },  {  -24,  56,  42,  32 } } },  /* 41: V JUMP K L A */
    { { {  -12,  24, 110,  18 },  {  -20,  54, 102,  20 },  {  -32,  66,  78,  24 },  {  -40,  76,  58,  24 } } },  /* 42: V JUMP K L A */
    { { {  -34,  24, 108,  18 },  {  -24,  54, 102,  20 },  {  -40,  68,  78,  24 },  {  -52,  90,  60,  26 } } },  /* 43: V JUMP K L A */
    { { {  -30,  28, 112,  18 },  {  -32,  60, 106,  14 },  {  -32,  56,  78,  26 },  {  -50,  62,  58,  28 } } },  /* 44: V JUMP K L A */
    { { {   -8,  19, 115,  16 },  {  -17,  46,  98,  21 },  {  -13,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -32,  16, 106,  16 },  {  -23,  46,  96,  21 },  {  -16,  30,  57,  46 },  {    0,   0,   0,   0 } } },  /* 46: not used by a script */
    { { {  -20,  24, 118,  18 },  {  -34,  66, 106,  14 },  {  -28,  56,  78,  26 },  {  -32,  64,  50,  26 } } },  /* 47: V JUMP P S A, V JUMP P M A, V JUMP P L A +6 */
    { { {  -40,  24, 108,  18 },  {  -48,  72,  98,  14 },  {  -52,  86,  72,  24 },  {  -32,  60,  48,  26 } } },  /* 48: V JUMP P S A */
    { { {   -2,  40, 106,  16 },  {  -18,  60,  88,  22 },  {  -40,  86,  62,  24 },  {  -18,  50,  50,  18 } } },  /* 49: V JUMP K S A, V JUMP K M A, FUSHIN P S */
    { { {   -8,  19, 115,  16 },  {  -17,  46,  98,  21 },  {  -13,  30,  49,  46 },  {  -45,  29,  72,  12 } } },  /* 50: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {  -50,  28,  66,  24 } } },  /* 51: not used by a script */
    { { {  -32,  19,  86,  16 },  {  -26,  51,  68,  21 },  {  -20,  30,  44,  39 },  {  -22,  41,   0,  44 } } },  /* 52: follow-up of APPEAR JUNBI 6 */
    { { {  -39,  19,  71,  16 },  {  -18,  46,  65,  32 },  {  -20,  30,  44,  39 },  {  -22,  41,   0,  44 } } },  /* 53: follow-up of APPEAR JUNBI 6 */
    { { {   13,  11, 129,  16 },  {  -17,  46, 113,  21 },  {  -13,  30,  69,  46 },  {    0,   0,   0,   0 } } },  /* 54: not used by a script */
    { { {   40,  19,  97,  16 },  {    4,  35,  84,  44 },  {  -21,  30,  69,  46 },  {    0,   0,   0,   0 } } },  /* 55: not used by a script */
    { { {   11,  19,  55,  16 },  {   -6,  46,  70,  21 },  {  -32,  58,  85,  25 },  {    0,   0,   0,   0 } } },  /* 56: follow-up of APPEAR JUNBI 6 */
    { { {   -7,  19,  51,  16 },  {  -24,  46,  66,  21 },  {  -19,  41,  88,  34 },  {    0,   0,   0,   0 } } },  /* 57: not used by a script */
    { { {  -34,  19, 106,  16 },  {  -23,  28,  75,  36 },  {    6,  41,  85,  20 },  {    0,   0,   0,   0 } } },  /* 58: not used by a script */
    { { {  -18,  19, 117,  16 },  {  -24,  46,  98,  21 },  {  -20,  30,  59,  46 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -22,  19,  88,  16 },  {  -27,  51,  68,  21 },  {  -22,  32,  40,  39 },  {  -32,  64,   0,  44 } } },  /* 60: not used by a script */
    { { {  -64,  19,  72,  16 },  {  -45,  51,  68,  21 },  {  -32,  32,  40,  39 },  {  -48,  64,   0,  44 } } },  /* 61: not used by a script */
    { { {   -8,  24,  94,  18 },  {  -32,  68,  90,  14 },  {  -28,  52,  52,  36 },  {  -54,  94,   0,  50 } } },  /* 62: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { { {  -28,  62,  82,  18 },  {  -48,  86,  70,  14 },  {  -24,  60,  42,  28 },  {  -62, 102,   0,  44 } } },  /* 63: ATTACK 3 M: 236+P light (plain script) */
    { { {   -4,  52,  82,  18 },  {  -12,  58,  70,  14 },  {  -18,  58,  40,  28 },  {  -62, 102,   0,  44 } } },  /* 64: ATTACK 3 M: 236+P light (plain script) */
    { { {  -42,  68,  82,  18 },  {  -34,  66,  70,  14 },  {  -22,  58,  40,  28 },  {  -62, 102,   0,  44 } } },  /* 65: ATTACK 3 M: 236+P light (plain script) */
    { { {  -26,  24,  98,  18 },  {  -44,  68,  88,  14 },  {  -32,  52,  52,  38 },  {  -54,  94,   0,  50 } } },  /* 66: ATTACK 3 M: 236+P light (plain script) */
    { { {  -28,  62,  82,  18 },  {  -44,  82,  78,  14 },  {  -24,  60,  44,  32 },  {  -62, 102,   0,  44 } } },  /* 67: ATTACK 3 L: 236+P medium (plain script) */
    { { {  -28,  62,  82,  18 },  {  -38,  18,  94,  12 },  {  -22,  58,  44,  36 },  {  -62, 102,   0,  44 } } },  /* 68: ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { { {  -36,  22, 104,  18 },  {  -28,  56,  82,  28 },  {  -48,  64,  48,  34 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { {  -11,  30, 102,  18 },  {  -30,  68,  94,  12 },  {  -30,  65,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 70: PIYO */
    { { {  -29,  33, 102,  18 },  {  -37,  63,  94,  12 },  {  -37,  65,  41,  52 },  {  -36,  74,   0,  40 } } },  /* 71: PIYO */
    { { {  -26,  22,  84,  18 },  {  -32,  58,  82,  12 },  {  -24,  50,  40,  40 },  {  -36,  72,   0,  40 } } },  /* 72: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { { {   14,  22, 126,  18 },  {  -18,  58, 122,  12 },  {  -22,  50,  80,  40 },  {   -4,  44,  50,  20 } } },  /* 73: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {    0,   0,   0,   0 },  {  -36,  64,  96,  28 },  {  -36,  64,  64,  28 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {  -14,  22, 110,  18 },  {  -32,  56, 104,  16 },  {  -20,  42,  72,  30 },  {  -28,  46,  56,  24 } } },  /* 75: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {    0,   0,   0,   0 },  {  -50,  64,  94,  20 },  {  -26,  42,  72,  14 },  {  -46,  60,  56,  24 } } },  /* 76: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {  -38,  22, 106,  18 },  {  -34,  58,  94,  20 },  {  -18,  36,  72,  24 },  {  -38,  50,  50,  28 } } },  /* 77: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { { -105,  22,  92,  18 },  { -109,  88,  82,  16 },  {  -99,  64,  40,  40 },  {  -53,  56,   0,  40 } } },  /* 78: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  18 },  {  -20,  44,  46,  34 },  {  -36,  78,   0,  46 } } },  /* 79: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  18 },  {  -20,  44,  46,  34 },  {  -36,  78,   0,  46 } } },  /* 80: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -40,  22,  70,  18 },  {  -16,  56,  80,  18 },  {  -26,  54,  38,  40 },  {  -34,  82,   0,  36 } } },  /* 81: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {    8,  22, 104,  18 },  {  -24,  70,  92,  14 },  {  -16,  48,  60,  32 },  {   -4,  50,  32,  26 } } },  /* 82: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { { {  -44,  50,  94,  18 },  {  -64,  28,  70,  22 },  {  -38,  54,  68,  24 },  {  -40,  54,  40,  26 } } },  /* 83: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { { {  -28,  22, 108,  18 },  {  -34,  60,  98,  20 },  {  -14,  38,  72,  24 },  {  -28,  48,  42,  28 } } },  /* 84: not used by a script */
    { { {   -8,  22, 118,  18 },  {  -24,  56,  98,  20 },  {  -22,  42,  70,  26 },  {  -14,  38,  28,  40 } } },  /* 85: not used by a script */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  56,  30 },  {   -4,  50,  48,  20 } } },  /* 86: V JUMP P M A, V JUMP P L A */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  56,  30 },  {   -4,  50,  48,  20 } } },  /* 87: V JUMP P M A */
    { { {   -2,  24, 106,  18 },  {  -26,  68,  94,  14 },  {  -22,  60,  58,  34 },  {   -8,  34,   0,  56 } } },  /* 88: L KICK A */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  56,  30 },  {   -4,  50,  48,  20 } } },  /* 89: V JUMP P L A */
    { { {  -20,  24, 104,  18 },  {  -36,  68,  92,  14 },  {  -30,  52,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 90: FRONT WALK, BACK WALK */
    { { {   -8,  24, 118,  18 },  {  -24,  60, 108,  14 },  {  -22,  46,  70,  36 },  {  -16,  48,  42,  26 } } },  /* 91: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +6 */
    { { {  -24,  24, 110,  18 },  {  -32,  60, 106,  14 },  {  -16,  44,  70,  36 },  {  -30,  52,  44,  24 } } },  /* 92: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    { { {  -46,  24,  94,  18 },  {  -28,  56, 100,  14 },  {  -10,  40,  72,  26 },  {  -36,  60,  50,  26 } } },  /* 93: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -44,  42, 108,  18 },  {  -60,  92,  98,  14 },  {  -70, 108,  72,  24 },  {  -44,  72,  48,  26 } } },  /* 94: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {  -20,  24, 116,  18 },  {  -44,  72, 108,  14 },  {  -40,  72,  80,  30 },  {  -46,  80,  62,  24 } } },  /* 95: PARING AIR F, PARING AIR B */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 96: M PUNCH C, UP P GUARD P M */
    { { {  -26,  53,  95,  17 },  {  -33,  67,  75,  30 },  {  -33,  67,  43,  32 },  {  -26,  53,  36,  16 } } },  /* 97: TUKAMIHAZUSI, AIR S, AIR M +40 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 98: dmca 97 */
};

const HAND_BOX gill_hand_box[97] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {  -88,  48,  70,  28 },  {    0,   0,   0,   0 } } },  /* 11: S PUNCH A, UP P GUARD P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {  -40,  26,  98,  40 },  {    0,   0,   0,   0 } } },  /* 13: M PUNCH C, UP P GUARD P M */
    { { {  -82,  52,  76,  28 },  {    0,   0,   0,   0 } } },  /* 14: M PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: no box */
    { { {  -68,  34,  42,  40 },  {    0,   0,   0,   0 } } },  /* 17: L PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: no box */
    { { {  -78,  58,  74,   9 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { { -112,  52,  70,  22 },  {    0,   0,   0,   0 } } },  /* 22: M KICK A, M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: no box */
    { { {  -78,  44,  64,  50 },  {    0,   0,   0,   0 } } },  /* 25: L KICK A */
    { { {  -72,  42,  26,  46 },  {    0,   0,   0,   0 } } },  /* 26: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -84,  38,  42,  22 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI P A, atca 156, UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {  -40,  24,  76,  48 },  {    0,   0,   0,   0 } } },  /* 33: KAGAMI P A, UP P GUARD P L */
    { { {  -92,  50,   0,  30 },  {    0,   0,   0,   0 } } },  /* 34: KAGAMI K A, UP P GUARD P L */
    { { {  -98,  56,   0,  32 },  {    0,   0,   0,   0 } } },  /* 35: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -68,  57,  83,   7 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -38,  18,  64,  26 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { { -100,  62,  70,  16 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K M A, FUSHIN P S, ATTACK 4 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { { -100,  46,  58,  24 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: no box */
    { { {  -50,  28,  72,  12 },  {    0,   0,   0,   0 } } },  /* 52: follow-up of APPEAR JUNBI 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -64,  16,  32,  40 },  {    0,   0,   0,   0 } } },  /* 61: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no box */
    { { {  -60,  38,  66,  16 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {  -90,  44,  80,  28 },  {    0,   0,   0,   0 } } },  /* 87: V JUMP P M A */
    { { {  -50,  24,  88,  36 },  {    0,   0,   0,   0 } } },  /* 88: L KICK A */
    { { {  -68,  30,  66,  18 },  {    0,   0,   0,   0 } } },  /* 89: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {  -66,  32,  54,  22 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {  -60,  40,  80,  52 },  {    0,   0,   0,   0 } } },  /* 96: M PUNCH C, UP P GUARD P M */
};

const HOSEI_BOX gill_hos_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   94 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +83 */
    { {  -24,   48,    0,   54 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +47 */
    { {  -24,   48,   62,   50 } },  /* 3: S JUMP FRONT, GUARD AIR, V JUMP P M A +40 */
    { {   -4,   48,    0,  100 } },  /* 4: not used by a script */
    { {  -11,   48,    0,  100 } },  /* 5: not used by a script */
    { {    7,   48,    0,   54 } },  /* 6: not used by a script */
    { {  -24,   48,    0,  100 } },  /* 7: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { {  -24,   48,    0,   84 } },  /* 8: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { {  -32,   64,    0,   94 } },  /* 9: DASH HUMIKOMI */
    { {  -74,   96,    0,   54 } },  /* 10: KAGAMI P A, atca 156, ATTACK 9 L: SA (all arts) 23623+P (plain script) */
    { {  -23,   48,   34,   58 } },  /* 11: TUKAMIHAZUSI, AIR S, AIR M +40 */
};
