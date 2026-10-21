/*
 * ALEX_HITBOX.C  Alex's hit boxes
 *
 * Each of Alex's animation frames names an entry of alex_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX alex_hit_ix_table[175] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: TATAKI S, TATAKI M, TATAKI L +42 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +110 */
    {    3,    3,    0,    0,    1,    0,    0,    1 },  /* 2: DASH HUMIKOMI */
    {    0,    0,    0,    0,    0,    0,    0,    7 },  /* 3: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {    4,    4,    0,    0,    2,    0,    0,    7 },  /* 4: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +33 */
    {    5,    5,    0,    0,    1,    0,    0,    2 },  /* 5: not used by a script */
    {    0,    0,    0,    0,    1,    0,    0,    3 },  /* 6: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    8 },  /* 7: AIR S, AIR M, AIR L +2 */
    {    8,    8,    0,    1,    1,    1,    0,    1 },  /* 8: S PUNCH A */
    {    9,    9,    0,    0,    1,    0,    0,    1 },  /* 9: S PUNCH A */
    {    9,    9,    0,    0,    1,    0,    0,    1 },  /* 10: not used by a script */
    {   10,   10,    0,    2,    1,    2,    0,    1 },  /* 11: S PUNCH B */
    {   11,   11,    0,    0,    1,    0,    0,    1 },  /* 12: S PUNCH B */
    {   12,   12,    0,    0,    3,    0,    0,    8 },  /* 13: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +28 */
    {    0,    0,    0,    0,    0,    0,    0,    8 },  /* 14: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    {   13,   13,    0,    0,    3,    0,    0,    8 },  /* 15: ATTACK 9 S: not started by a command */
    {   14,   14,    0,    3,    1,    3,    0,    1 },  /* 16: nmca 33, M PUNCH A */
    {   15,   15,    0,    0,    1,    0,    0,    1 },  /* 17: not used by a script */
    {    5,    5,    0,    6,    1,    6,    0,    1 },  /* 18: M PUNCH C */
    {   15,   15,    0,    5,    1,    5,    0,    1 },  /* 19: L PUNCH A */
    {   16,   16,    0,   11,    1,   11,    0,    4 },  /* 20: L PUNCH A */
    {   17,    0,    0,    0,    1,    0,    0,    2 },  /* 21: L PUNCH A */
    {   18,    0,    0,    0,    1,    0,    0,    1 },  /* 22: M PUNCH C */
    {   19,   19,    0,    7,    1,    7,    0,    4 },  /* 23: M PUNCH C, UP P GUARD P S */
    {   20,   20,    0,   12,    1,   12,    0,    5 },  /* 24: M PUNCH C, UP P GUARD P S */
    {   21,   21,    0,    0,    1,    0,    0,    3 },  /* 25: M PUNCH C, UP P GUARD P S */
    {   22,   22,    0,    8,   15,    8,    0,    3 },  /* 26: S KICK A */
    {   23,   23,    0,    0,   15,    0,    0,    2 },  /* 27: S KICK A */
    {    2,    2,    0,    0,    1,    0,    0,    4 },  /* 28: M KICK A */
    {   24,   24,    0,    9,    1,    9,    0,    4 },  /* 29: M KICK A */
    {   13,   13,    0,    0,    1,    0,    0,    2 },  /* 30: M KICK A */
    {   25,   25,    0,    0,    1,    0,    0,    2 },  /* 31: M KICK B */
    {   26,   26,    0,   10,    1,   10,    0,    2 },  /* 32: M KICK B */
    {   26,   26,    0,    0,    1,    0,    0,    2 },  /* 33: M KICK B */
    {    0,    0,    0,    0,    0,    0,    0,    7 },  /* 34: not used by a script */
    {   18,    0,    0,    0,    1,    0,    0,    3 },  /* 35: M PUNCH C, UP P GUARD P S */
    {   24,   24,    0,   13,    1,   13,    0,    1 },  /* 36: not used by a script */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 37: not used by a script */
    {   69,   69,    0,   38,    1,   38,    0,    4 },  /* 38: L KICK A */
    {   69,   69,    0,    0,    1,    0,    0,    4 },  /* 39: L KICK A */
    {  108,  108,    0,    0,   17,    0,    0,   19 },  /* 40: L KICK A */
    {   30,   30,    0,   15,   16,   15,    0,    7 },  /* 41: KAGAMI P A */
    {   30,   30,    0,    0,    2,    0,    0,    7 },  /* 42: KAGAMI P A */
    {   29,   29,    0,   16,    2,   16,    0,    7 },  /* 43: KAGAMI P A */
    {   31,   31,    0,   17,    2,   17,    0,    7 },  /* 44: KAGAMI P A */
    {   32,   32,    0,   18,    3,   18,    0,    8 },  /* 45: KAGAMI P A */
    {   33,   33,    0,    0,    3,    0,    0,    8 },  /* 46: KAGAMI P A */
    {   34,   34,    0,    0,    1,    0,    0,    1 },  /* 47: follow-up of APPEAR JUNBI 7 */
    {   35,   35,    0,   19,   16,   19,    0,    7 },  /* 48: KAGAMI K A */
    {   35,   35,    0,    0,   16,    0,    0,    7 },  /* 49: KAGAMI K A, UP P GUARD K S */
    {   36,   36,    0,   20,    2,   20,    0,    7 },  /* 50: KAGAMI K A, UP P GUARD K S */
    {   37,   37,    0,   21,    2,   21,    0,    7 },  /* 51: KAGAMI K A */
    {   38,   38,    0,   22,    2,   22,    0,    7 },  /* 52: not used by a script */
    {   38,   38,    0,    0,    2,    0,    0,    7 },  /* 53: KAGAMI K A */
    {   36,   36,    0,    0,    2,    0,    0,    7 },  /* 54: KAGAMI K A */
    {   37,   37,    0,    0,    2,    0,    0,    7 },  /* 55: KAGAMI K A */
    {   39,   39,    0,   23,    3,   23,    0,    8 },  /* 56: V JUMP P S A */
    {   40,   40,    0,   24,    3,   24,    0,    8 },  /* 57: V JUMP P M A */
    {   65,   65,    0,    0,    2,    0,    0,   23 },  /* 58: SP F JP L P B */
    {    6,    6,    0,   25,    3,   25,    0,    8 },  /* 59: ATTACK 9 S: not started by a command */
    {    0,    0,    0,    0,    0,    0,    0,    7 },  /* 60: OKIAGARI, OKIAGARI F, OKIAGARI B +21 */
    {   41,   41,    0,    0,    3,    0,    0,    8 },  /* 61: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,   22 },  /* 62: NEKOROBI S, dmca 96 */
    {   43,   43,    0,    0,    3,    0,    0,    8 },  /* 63: not used by a script */
    {   44,   44,    0,    0,    3,    0,    0,    8 },  /* 64: FUSHIN P S */
    {   45,   45,    0,   26,    3,   26,    0,    8 },  /* 65: FUSHIN P S */
    {   45,   45,    0,    0,    3,    0,    0,    8 },  /* 66: not used by a script */
    {   46,   46,    0,    0,    3,    0,    0,    8 },  /* 67: not used by a script */
    {   47,   47,    0,    0,    3,    0,    0,    8 },  /* 68: not used by a script */
    {   48,   48,    0,    0,    1,    0,    0,    1 },  /* 69: OKIAGARI P S */
    {   48,   48,    0,    0,    1,    0,    0,    1 },  /* 70: OKIAGARI P S */
    {   50,   50,    0,   27,    1,   27,    0,    1 },  /* 71: OKIAGARI P S */
    {   51,   51,    0,   28,    1,   28,    0,    1 },  /* 72: OKIAGARI P S */
    {   49,   49,    0,    0,    1,    0,    0,    1 },  /* 73: OKIAGARI P S */
    {   52,   52,    0,    0,   12,    0,    0,   18 },  /* 74: AIR S, AIR M, AIR L +43 */
    {   53,   53,    0,   29,    1,    0,    0,    3 },  /* 75: L PUNCH C */
    {   54,   54,    0,    0,    1,    0,    0,    3 },  /* 76: L PUNCH C */
    {   54,   54,    0,    0,    1,    0,    0,    1 },  /* 77: not used by a script */
    {   55,   55,    0,    0,    3,    0,    0,    8 },  /* 78: V JUMP P L A */
    {   56,   56,    0,    0,    3,    0,    0,    8 },  /* 79: V JUMP P L A */
    {   57,   57,    0,   30,    3,   30,    0,    8 },  /* 80: V JUMP P L A */
    {   58,   58,    0,   31,    3,   31,    0,    8 },  /* 81: V JUMP P L A */
    {   59,   59,    0,    0,    3,    0,    0,    8 },  /* 82: V JUMP P L A */
    {   60,   60,    0,   32,    3,   32,    0,    8 },  /* 83: V JUMP K S A */
    {   61,   61,    0,    0,    3,    0,    0,    8 },  /* 84: V JUMP K M A */
    {   62,   62,    0,    0,    3,    0,    0,    8 },  /* 85: V JUMP K M A */
    {   63,   63,    0,   33,    3,   33,    0,    8 },  /* 86: V JUMP K M A */
    {   63,   63,    0,    0,    3,    0,    0,    8 },  /* 87: V JUMP K M A */
    {   64,   64,    0,    0,    0,    0,    0,    0 },  /* 88: ATTACK 9 S: not started by a command */
    {    1,    1,    0,   34,    1,   34,    0,    1 },  /* 89: M PUNCH A, M PUNCH C, TUKAMIKAKARI A */
    {    1,    1,    0,   39,    1,   39,    0,    1 },  /* 90: L PUNCH A, L PUNCH C */
    {    7,    7,    0,    0,    3,    0,    0,    8 },  /* 91: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   66,   66,    0,    0,    3,    0,    0,    8 },  /* 92: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    {   67,   67,    0,   36,   11,   36,    0,   16 },  /* 93: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    {   80,   80,    0,    0,   11,    0,    0,   16 },  /* 94: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    {   71,   71,    0,   35,    1,   35,    0,    1 },  /* 95: ATTACK 3 S: 6(123)4+P light (plain script) */
    {   71,   71,    0,   37,    1,   37,    0,    1 },  /* 96: ATTACK 3 M: 6(123)4+P medium (plain script) */
    {   70,   70,    0,    0,    1,    0,    0,    1 },  /* 97: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +1 */
    {   71,   71,    0,   40,    1,   40,    0,    1 },  /* 98: ATTACK 3 L: 6(123)4+P heavy/EX (plain script) */
    {   71,   71,    0,    0,    4,    0,    0,    9 },  /* 99: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    {    0,    0,    0,   49,    1,   49,    0,    1 },  /* 100: ATTACK 4 S: SA I 360+P (plain script) */
    {   72,   72,    0,    0,    2,    0,    0,    7 },  /* 101: KAGAMI P A */
    {   68,   68,    0,    0,    2,    0,    0,    7 },  /* 102: not used by a script */
    {   73,   73,    0,   42,   14,    0,    0,   21 },  /* 103: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 9 S: not started by a command */
    {   73,   73,    0,   43,   14,    0,    0,   21 },  /* 104: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {   74,   74,    0,    0,    7,    0,    0,   12 },  /* 105: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   75,   75,    0,    0,    8,    0,    0,   13 },  /* 106: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   76,   76,    0,    0,    9,    0,    0,   14 },  /* 107: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   76,   76,    0,   44,    9,   44,    0,   14 },  /* 108: not used by a script */
    {   77,   77,    0,   45,   10,   45,    0,   15 },  /* 109: not used by a script */
    {   77,   77,    0,    0,   10,    0,    0,   15 },  /* 110: not used by a script */
    {   78,   78,    0,    0,    1,    0,    0,    1 },  /* 111: ATTACK 9 S: not started by a command */
    {   40,   40,    0,   46,    3,   46,    0,    8 },  /* 112: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    {   79,   79,    0,    0,    2,    0,    0,    7 },  /* 113: not used by a script */
    {    0,    0,    0,    0,    1,    0,    0,    1 },  /* 114: not used by a script */
    {    0,    0,    0,    0,    1,    0,    0,   10 },  /* 115: not used by a script */
    {   81,   81,    0,    0,    1,    0,    0,   10 },  /* 116: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 117: ATTACK 4 S: SA I 360+P (plain script), ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI), ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    {   82,   82,    0,    0,    1,   47,    0,    0 },  /* 118: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) +2 */
    {   82,   82,    0,    0,    1,    0,    0,    8 },  /* 119: ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) */
    {   78,   78,    0,    0,    1,    0,    0,    8 },  /* 120: ATTACK 9 S: not started by a command */
    {   83,   83,    0,    0,    3,    0,    0,    8 },  /* 121: V JUMP K L A */
    {   84,   84,    0,    0,    5,    0,    0,    8 },  /* 122: V JUMP K L A */
    {   85,   85,    0,   48,    5,   48,    0,    8 },  /* 123: V JUMP K L A */
    {   85,   85,    0,    0,    5,    0,    0,    8 },  /* 124: P BREAK ZUJOU, P BREAK DOWN, TUKAMIHAZUSI +1 */
    {    0,    0,    0,   50,    0,   50,    0,    3 },  /* 125: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0,   51,    0,   51,    0,    3 },  /* 126: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   87,   87,    0,   52,    1,   52,    0,    3 },  /* 127: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   87,   87,    0,   53,    1,   53,    0,    3 },  /* 128: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   88,   88,    0,   54,    1,   54,    0,    3 },  /* 129: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   88,   88,    0,   55,    1,   55,    0,    3 },  /* 130: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   89,   89,    0,   56,    1,   56,    0,    3 },  /* 131: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   89,   89,    0,   57,    1,   57,    0,    3 },  /* 132: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   90,   90,    0,    0,    1,    0,    0,    3 },  /* 133: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   91,   91,    0,    0,    1,    0,    0,    1 },  /* 134: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   92,   92,    0,   58,    1,   58,    0,    1 },  /* 135: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   93,   93,    0,   59,    1,   59,    0,    1 },  /* 136: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   94,   94,    0,    0,    1,    0,    0,    1 },  /* 137: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   95,   95,    0,    0,    1,    0,    0,    1 },  /* 138: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   96,   96,    0,   60,    1,   60,    0,    1 },  /* 139: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   97,   97,    0,   61,    1,   61,    0,    1 },  /* 140: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   98,   98,    0,    0,    1,    0,    0,    1 },  /* 141: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   99,   99,    0,    0,    1,    0,    0,    1 },  /* 142: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {  100,  100,    0,   62,    1,   62,    0,    1 },  /* 143: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    {  101,  101,    0,   63,    1,   63,    0,    1 },  /* 144: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    {  102,  102,    0,    0,    1,    0,    0,    1 },  /* 145: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {  103,  103,    0,    0,   13,    0,    0,   20 },  /* 146: PIYO */
    {  104,  104,    0,    0,   13,    0,    0,   20 },  /* 147: PIYO */
    {  105,  105,    0,    0,    1,    0,    0,    1 },  /* 148: not used by a script */
    {   86,   86,    0,    0,    1,    0,    0,    1 },  /* 149: FUSHIN P S, ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  106,  106,    0,   64,   11,   64,    0,   16 },  /* 150: F JUMP P L B, SP F JP L P B, FUSHIN P S */
    {  107,  107,    0,   65,   11,   65,    0,   16 },  /* 151: F JUMP P L B, SP F JP L P B */
    {   30,   30,    0,    0,   16,    0,    0,    7 },  /* 152: KAGAMI P A */
    {   72,   72,    0,    0,   16,    0,    0,    7 },  /* 153: KAGAMI P A */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 154: follow-up of APPEAR 8 */
    {    4,    4,    0,    0,    0,    0,    0,    7 },  /* 155: follow-up of APPEAR 8 */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 156: LOSE SONABA */
    {   71,   71,    0,   49,    1,   49,    0,    1 },  /* 157: ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  109,    0,    0,    0,    1,    0,    0,    1 },  /* 158: ATTACK 10 S: not started by a command */
    {  110,    0,    0,    0,    1,    0,    0,   26 },  /* 159: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  111,    0,    0,    0,    1,    0,    0,   24 },  /* 160: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  112,    0,    0,    0,    1,    0,    0,   25 },  /* 161: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  113,    0,    0,    0,    1,    0,    0,   25 },  /* 162: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  114,    0,    0,    0,    1,    0,    0,    1 },  /* 163: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   14,  111,    0,    0,    1,   66,    0,    1 },  /* 164: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    {  113,    0,    0,    0,    1,   67,    0,   25 },  /* 165: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    {  109,    0,    0,    0,    1,   29,    0,    1 },  /* 166: not used by a script */
    {  115,  110,    0,    0,    1,   68,    0,    1 },  /* 167: not used by a script */
    {  115,  110,    0,    0,    1,    0,    0,    1 },  /* 168: not used by a script */
    {  115,    0,    0,    0,    1,    0,    0,    1 },  /* 169: not used by a script */
    {   28,    0,    0,    0,    0,    0,    0,   22 },  /* 170: dmca 97 */
    {  100,   17,    0,   62,    1,   62,    0,    1 },  /* 171: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {  101,   18,    0,   63,    1,   63,    0,    1 },  /* 172: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {   14,  109,    0,    0,    1,   69,    0,    1 },  /* 173: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    {   40,   40,    0,    0,    3,    0,    0,    8 },  /* 174: V JUMP P M A */
};

const BODY_BOX alex_body_box[116] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -25,  34,  85,  18 },  {  -38,  76,  78,  13 },  {  -38,  76,  34,  44 },  {  -44,  88,   0,  34 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +111 */
    { { {  -25,  34, 102,  18 },  {  -38,  76,  74,  26 },  {  -29,  66,  42,  30 },  {  -30,  89,   0,  40 } } },  /* 2: M KICK A */
    { { {  -36,  37,  74,  13 },  {  -36,  70,  58,  16 },  {  -36,  70,  33,  25 },  {  -36,  93,   0,  33 } } },  /* 3: DASH HUMIKOMI */
    { { {  -33,  50,  53,  18 },  {  -46,  92,  41,  22 },  {  -49,  98,  24,  15 },  {  -52, 100,   0,  22 } } },  /* 4: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +33 */
    { { {  -50,  43, 102,  26 },  {  -50,  78,  74,  28 },  {  -41,  78,  39,  35 },  {  -43, 103,   0,  39 } } },  /* 5: M PUNCH C */
    { { {  -26,  37,  96,  23 },  {  -58,  89,  85,  14 },  {  -82, 113,  66,  18 },  {  -90, 123,  49,  17 } } },  /* 6: ATTACK 9 S: not started by a command */
    { { {  -37,  37,  93,  20 },  {  -43,  77,  84,  22 },  {  -48,  86,  76,  18 },  {  -48,  86,  55,  21 } } },  /* 7: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  30 },  {  -51,  95,   0,  32 } } },  /* 8: S PUNCH A */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  30 },  {  -44,  88,   0,  32 } } },  /* 9: S PUNCH A */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  32 },  {  -53, 104,   0,  34 } } },  /* 10: S PUNCH B */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  32 },  {  -44,  88,   0,  34 } } },  /* 11: S PUNCH B */
    { { {  -30,  37, 101,  20 },  {  -44,  75,  81,  31 },  {  -36,  67,  58,  30 },  {  -41,  72,  38,  26 } } },  /* 12: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +28 */
    { { {  -55,  87,  92,  18 },  {  -47,  79,  76,  15 },  {  -58,  90,  52,  22 },  {  -14,  45,   0,  50 } } },  /* 13: ATTACK 9 S: not started by a command, M KICK A */
    { { {  -42,  46,  89,  16 },  {  -42,  81,  66,  30 },  {  -45,  84,  34,  32 },  {  -50, 102,   0,  34 } } },  /* 14: nmca 33, M PUNCH A, ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -34,  52,  68,  38 },  {  -34,  68,  60,  32 },  {  -30,  78,  34,  26 },  {  -30,  88,   0,  32 } } },  /* 15: L PUNCH A */
    { { {  -45,  79,  78,  22 },  {  -29,  63,  51,  27 },  {  -29,  77,  40,  21 },  {  -30,  88,   0,  40 } } },  /* 16: L PUNCH A */
    { { {  -38,  43,  88,  14 },  {  -38,  76,  56,  36 },  {  -30,  76,  34,  20 },  {  -30,  88,   0,  32 } } },  /* 17: L PUNCH A */
    { { {  -12,  34, 102,  18 },  {  -38,  83,  73,  28 },  {  -30,  76,  41,  31 },  {  -37,  92,   0,  39 } } },  /* 18: M PUNCH C, UP P GUARD P S */
    { { {  -43,  49,  81,  20 },  {  -34,  74,  58,  23 },  {  -42,  90,  32,  26 },  {  -41, 110,   0,  32 } } },  /* 19: M PUNCH C, UP P GUARD P S */
    { { {  -50,  88,  71,  19 },  {  -68, 114,  56,  15 },  {  -30,  76,  29,  27 },  {  -30, 118,   0,  29 } } },  /* 20: M PUNCH C, UP P GUARD P S */
    { { {  -50,  88,  71,  19 },  {  -50,  98,  56,  15 },  {  -29,  77,  29,  27 },  {  -30, 118,   0,  29 } } },  /* 21: M PUNCH C, UP P GUARD P S */
    { { {  -36,  54,  92,  19 },  {  -46,  79,  66,  26 },  {  -66,  99,  34,  32 },  {  -14,  47,   0,  34 } } },  /* 22: S KICK A */
    { { {  -36,  54,  92,  19 },  {  -46,  79,  66,  26 },  {  -66,  99,  34,  32 },  {  -14,  47,   0,  34 } } },  /* 23: S KICK A */
    { { {  -55,  87,  92,  18 },  {  -62,  94,  76,  16 },  {  -22,  54,  52,  22 },  {  -14,  46,   0,  52 } } },  /* 24: M KICK A */
    { { {  -37,  44,  94,  21 },  {  -55,  86,  66,  35 },  {  -35,  66,  34,  30 },  {  -30,  61,   0,  32 } } },  /* 25: M KICK B */
    { { {   40,  46,  66,  26 },  {  -38,  78,  66,  26 },  {  -52,  34,  49,  36 },  {  -30,  61,   0,  64 } } },  /* 26: M KICK B */
    { { {   -2,  22,  94,  14 },  {  -16,  64,  80,  14 },  {  -16,  60,  46,  30 },  {   -8,  36,   0,  44 } } },  /* 27: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 28: dmca 97 */
    { { {  -33,  67,  53,  18 },  {  -58,  96,  35,  27 },  {  -37,  74,  22,  20 },  {  -52, 100,   0,  22 } } },  /* 29: KAGAMI P A */
    { { {  -33,  50,  53,  18 },  {  -58,  96,  38,  27 },  {  -37,  74,  22,  20 },  {  -52, 100,   0,  22 } } },  /* 30: KAGAMI P A */
    { { {  -72,  73,  67,  33 },  {  -72,  84,  45,  22 },  {  -62,  97,  30,  15 },  {  -39, 103,   0,  30 } } },  /* 31: KAGAMI P A */
    { { {  -63,  82, 105,  29 },  {  -63,  97,  71,  34 },  {  -48,  89,  41,  30 },  {  -21,  82,  23,  25 } } },  /* 32: KAGAMI P A */
    { { {  -63,  82, 105,  29 },  {  -63,  97,  71,  34 },  {  -48,  89,  41,  30 },  {  -21,  82,  23,  25 } } },  /* 33: KAGAMI P A */
    { { {  -63,  82, 105,  29 },  {  -63,  97,  71,  34 },  {  -48,  89,  41,  30 },  {  -21,  82,  23,  25 } } },  /* 34: follow-up of APPEAR JUNBI 7 */
    { { {  -32,  54,  63,  18 },  {  -61, 100,  42,  30 },  {    0,   0,   0,   0 },  {  -30,  78,   0,  42 } } },  /* 35: KAGAMI K A, UP P GUARD K S */
    { { {  -32,  54,  63,  18 },  {  -61, 100,  42,  30 },  {    0,   0,   0,   0 },  {  -30,  70,   0,  42 } } },  /* 36: KAGAMI K A, UP P GUARD K S */
    { { {  -42,  76,  47,  18 },  {  -74, 113,  30,  26 },  {    0,   0,   0,   0 },  {  -30,  78,   0,  40 } } },  /* 37: KAGAMI K A */
    { { {  -38,  71,  50,  18 },  {  -85, 124,  27,  30 },  {    0,   0,   0,   0 },  {  -92, 140,   0,  40 } } },  /* 38: KAGAMI K A */
    { { {  -30,  37, 101,  20 },  {  -44,  75,  81,  31 },  {  -64,  97,  58,  36 },  {  -45,  84,  33,  28 } } },  /* 39: V JUMP P S A */
    { { {  -30,  37, 101,  20 },  {  -44,  75,  81,  31 },  {  -63,  96,  63,  28 },  {  -44,  81,  36,  29 } } },  /* 40: V JUMP P M A, ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    { { {  -46,  22,  84,  18 },  {  -50,  32,  64,  24 },  {  -24,  40,  64,  34 },  {  -32,  44,  46,  16 } } },  /* 41: not used by a script */
    { { {  -10,  22,  82,  16 },  {  -12,  52,  80,  14 },  {   -2,  40,  42,  36 },  {  -34,  76,   0,  40 } } },  /* 42: not used by a script */
    { { {   -6,  22,  88,  16 },  {    2,  38,  84,  18 },  {    4,  40,  48,  34 },  {  -18,  52,  16,  30 } } },  /* 43: not used by a script */
    { { {  -18,  22,  94,  16 },  {  -22,  52,  88,  12 },  {  -12,  38,  48,  38 },  {  -30,  56,  16,  30 } } },  /* 44: FUSHIN P S */
    { { {  -18,  22,  94,  16 },  {  -22,  52,  88,  12 },  {  -12,  38,  48,  38 },  {  -30,  56,  16,  30 } } },  /* 45: FUSHIN P S */
    { { {   -8,  22,  98,  16 },  {  -12,  48,  88,  16 },  {   -8,  40,  48,  38 },  {  -22,  44,  16,  30 } } },  /* 46: not used by a script */
    { { {  -26,  22,  98,  16 },  {  -32,  50,  88,  16 },  {  -22,  40,  48,  38 },  {  -28,  50,  16,  30 } } },  /* 47: not used by a script */
    { { {   -7,  32,  84,  16 },  {  -26,  59,  66,  18 },  {  -41,  76,  44,  22 },  {  -56,  93,   0,  44 } } },  /* 48: OKIAGARI P S */
    { { {  -30,  51,  87,  16 },  {  -39,  70,  73,  14 },  {  -47,  81,  52,  20 },  {  -59,  96,   0,  52 } } },  /* 49: OKIAGARI P S */
    { { {  -46,  53,  98,  16 },  {  -45,  65,  84,  15 },  {  -48,  63,  52,  32 },  {  -59,  96,   0,  52 } } },  /* 50: OKIAGARI P S */
    { { {  -12,  22, 102,  16 },  {  -34,  54,  84,  18 },  {  -30,  36,  52,  30 },  {  -30,  48,   0,  50 } } },  /* 51: OKIAGARI P S */
    { { {  -26,  53,  95,  17 },  {  -33,  67,  75,  30 },  {  -33,  67,  43,  32 },  {  -26,  53,  36,  16 } } },  /* 52: AIR S, AIR M, AIR L +43 */
    { { {  -38,  76,  82,  16 },  {  -38,  76,  66,  16 },  {  -38,  76,  34,  30 },  {  -44,  88,   0,  32 } } },  /* 53: L PUNCH C */
    { { {  -38,  76,  82,  16 },  {  -38,  76,  66,  16 },  {  -38,  76,  34,  30 },  {  -44,  88,   0,  32 } } },  /* 54: L PUNCH C */
    { { {  -35,  52, 109,  17 },  {  -65,  97,  73,  36 },  {  -43,  75,  42,  31 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP P L A */
    { { {  -35,  52, 109,  17 },  {  -65,  97,  73,  36 },  {  -43,  75,  42,  31 },  {    0,   0,   0,   0 } } },  /* 56: V JUMP P L A */
    { { {  -44,  42,  95,  17 },  {  -28,  48,  83,  22 },  {  -41,  77,  38,  45 },  {    0,   0,   0,   0 } } },  /* 57: V JUMP P L A */
    { { {  -51,  48,  95,  17 },  {  -51,  71,  83,  22 },  {  -27,  63,  38,  45 },  {    0,   0,   0,   0 } } },  /* 58: V JUMP P L A */
    { { {  -53,  88,  87,  24 },  {  -44,  78,  57,  30 },  {  -34,  67,  38,  19 },  {    0,   0,   0,   0 } } },  /* 59: V JUMP P L A */
    { { {  -31,  71,  86,  37 },  {  -60, 116,  56,  30 },  {  -49,  80,  44,  12 },  {    0,   0,   0,   0 } } },  /* 60: V JUMP K S A */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 61: V JUMP K M A */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 62: V JUMP K M A */
    { { {   42,  27,  61,  30 },  {    2,  40,  45,  46 },  { -120, 122,  52,  35 },  {    0,   0,   0,   0 } } },  /* 63: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  89,   0,  49 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 9 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -57, 104,   0,  66 },  {    0,   0,   0,   0 } } },  /* 65: SP F JP L P B */
    { { {  -60,  33,  43,  50 },  {  -44,  61,  62,  43 },  {  -39,  72,  32,  30 },  {    0,   0,   0,   0 } } },  /* 66: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { { -100,  60,  81,  17 },  {  -40,  30,  48,  50 },  {  -10,  77,  62,  39 },  {    0,   0,   0,   0 } } },  /* 67: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { {  -33,  50,  53,  18 },  {  -46,  92,  41,  22 },  {  -91, 140,  24,  15 },  {  -91, 143,   0,  22 } } },  /* 68: not used by a script */
    { { {  -15,  56, 101,  23 },  {  -35,  80,  82,  27 },  {  -20,  54,  48,  53 },  {   -3,  56,   0,  59 } } },  /* 69: L KICK A */
    { { {  -20,  22,  80,  16 },  {  -32,  66,  69,  13 },  {  -33,  50,  43,  28 },  {  -49,  79,   0,  40 } } },  /* 70: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +1 */
    { { {  -61,  42,  69,  22 },  {  -61,  72,  50,  29 },  {  -51,  83,  30,  28 },  {  -51, 108,   0,  29 } } },  /* 71: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { { {  -33,  50,  59,  18 },  {  -48,  90,  42,  27 },  {    0,   0,   0,   0 },  {  -52, 100,   0,  42 } } },  /* 72: KAGAMI P A */
    { { {  -27,  61,  78,  25 },  {  -27,  62,  55,  23 },  {  -41,  86,  35,  20 },  {  -15,  68,  12,  23 } } },  /* 73: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 9 S: not started by a command, ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +2 */
    { { {  -30,  34, 143,  20 },  {  -52,  89, 139,  21 },  {  -46,  78, 115,  24 },  {  -34,  60,  82,  33 } } },  /* 74: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -30,  34, 143,  20 },  {  -52,  89, 139,  21 },  {  -46,  78, 115,  24 },  {  -34,  60,  82,  33 } } },  /* 75: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -35,  38, 146,  19 },  {  -54,  87, 137,  22 },  {  -47,  76, 116,  21 },  {  -44,  68,  93,  23 } } },  /* 76: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -6,  19, 113,  17 },  {  -24,  57,  98,  23 },  {  -32,  44,  72,  24 },  {  -38,  45,   4,  66 } } },  /* 77: not used by a script */
    { { {  -29,  19,  97,  18 },  {  -33,  50,  84,  20 },  {  -23,  45,  55,  28 },  {  -27,  49,  -2,  56 } } },  /* 78: ATTACK 9 S: not started by a command */
    { { {  -42,  22,  60,  16 },  {  -36,  50,  50,  20 },  {  -26,  46,  32,  20 },  {  -42,  68,   0,  36 } } },  /* 79: not used by a script */
    { { {  -90,  53,  38,  41 },  {  -59,  68,  59,  37 },  {   -9,  48,  41,  55 },  {    0,   0,   0,   0 } } },  /* 80: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  76,   0,  33 } } },  /* 81: not used by a script */
    { { {   -8,  20, 110,  20 },  {  -24,  56,  94,  24 },  {  -26,  44,  68,  28 },  {  -30,  44,   4,  62 } } },  /* 82: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) +2 */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 83: V JUMP K L A */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP K L A */
    { { {   45,  24,  59,  27 },  {   -1,  44,  43,  43 },  {  -52,  51,  45,  47 },  { -114,  62,  51,  41 } } },  /* 85: V JUMP K L A, P BREAK ZUJOU, P BREAK DOWN +1 */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  78,  14 },  {  -61, 100,  34,  44 },  {  -66, 124,   0,  34 } } },  /* 86: FUSHIN P S, ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -45,  83,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 87: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -50, 103,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 88: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -50, 103,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 89: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -38,  43,  83,  18 },  {  -38,  76,  66,  26 },  {  -46,  84,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 90: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    9,  50,  75,  19 },  {    2,  45,  53,  22 },  {  -10,  52,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 91: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  27 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 92: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 93: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  31,  85,  17 },  {  -34,  55,  78,  15 },  {  -31,  65,  40,  38 },  {  -34,  89,   0,  40 } } },  /* 94: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {    9,  50,  75,  19 },  {    2,  45,  53,  22 },  {  -10,  52,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 95: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 96: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 97: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -73, 100,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 98: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {    9,  50,  75,  19 },  {    2,  45,  53,  22 },  {  -10,  52,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 99: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 100: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 101: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -73, 100,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 102: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -57,  34,  49,  18 },  {  -49,  57,  46,  37 },  {  -53,  76,  25,  21 },  {  -53, 100,   0,  25 } } },  /* 103: PIYO */
    { { {  -45,  34,  49,  18 },  {  -37,  59,  46,  43 },  {  -45,  76,  25,  21 },  {  -45, 100,   0,  25 } } },  /* 104: PIYO */
    { { {  -37,  42,  75,  19 },  {  -46,  41,  53,  22 },  {  -54,  36,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 105: not used by a script */
    { { { -100,  60,  81,  17 },  {  -40,  30,  48,  50 },  {  -10,  77,  62,  39 },  {    0,   0,   0,   0 } } },  /* 106: F JUMP P L B, SP F JP L P B, FUSHIN P S */
    { { { -100,  60,  81,  17 },  {  -40,  30,  48,  50 },  {  -10,  77,  62,  39 },  {    0,   0,   0,   0 } } },  /* 107: F JUMP P L B, SP F JP L P B */
    { { {  -32,  61,  89,  18 },  {  -52,  94,  78,  14 },  {  -52,  94,  34,  44 },  {  -59, 107,   0,  34 } } },  /* 108: L KICK A */
    { { {  -25,  34, 104,  18 },  {  -42,  76,  91,  13 },  {  -37,  68,  47,  44 },  {  -36,  66,   0,  47 } } },  /* 109: ATTACK 10 S: not started by a command */
    { { {  -22,  34,  74,  18 },  {  -38,  76,  67,  13 },  {  -42,  76,  23,  44 },  {  -52,  95,   0,  29 } } },  /* 110: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -22,  34,  65,  18 },  {  -38,  69,  60,  13 },  {  -47,  76,  23,  37 },  {  -59,  99,   0,  28 } } },  /* 111: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -46,  34,  63,  18 },  {  -58,  69,  57,  13 },  {  -63,  91,  26,  33 },  {  -50, 100,   0,  28 } } },  /* 112: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -46,  34,  58,  18 },  {  -56,  69,  52,  13 },  {  -63,  91,  24,  33 },  {  -49, 100,   0,  28 } } },  /* 113: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -48,  34,  74,  18 },  {  -61,  75,  67,  16 },  {  -45,  64,  23,  44 },  {  -52,  95,   0,  29 } } },  /* 114: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -27,  41, 105,  18 },  {  -44,  78,  85,  24 },  {  -45,  82,  34,  51 },  {  -44,  81,   0,  34 } } },  /* 115: not used by a script */
};

const HAND_BOX alex_hand_box[112] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {  -85,  47,  43,  35 },  {    0,   0,   0,   0 } } },  /* 8: S PUNCH A */
    { { {  -80,  41,  45,  39 },  {    0,   0,   0,   0 } } },  /* 9: S PUNCH A */
    { { {  -90,  66,  67,  29 },  {    0,   0,   0,   0 } } },  /* 10: S PUNCH B */
    { { {  -90,  66,  67,  29 },  {    0,   0,   0,   0 } } },  /* 11: S PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {  -68,  25,  65,  41 },  {    0,   0,   0,   0 } } },  /* 14: nmca 33, M PUNCH A */
    { { {  -96,  62,  68,  38 },  {    0,   0,   0,   0 } } },  /* 15: L PUNCH A */
    { { {  -79,  50,  40,  38 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH A */
    { { {  -51,  19,  68,  31 },  {    0,   0,   0,   0 } } },  /* 17: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -62,  36,  66,  41 },  {    0,   0,   0,   0 } } },  /* 18: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -81,  47,  60,  44 },  {    0,   0,   0,   0 } } },  /* 19: M PUNCH C, UP P GUARD P S */
    { { {  -85,  57,  29,  30 },  {    0,   0,   0,   0 } } },  /* 20: M PUNCH C, UP P GUARD P S */
    { { {  -71,  42,  25,  31 },  {    0,   0,   0,   0 } } },  /* 21: M PUNCH C, UP P GUARD P S */
    { { {  -94,  80,   0,  34 },  {    0,   0,   0,   0 } } },  /* 22: S KICK A */
    { { {  -94,  80,   0,  34 },  {    0,   0,   0,   0 } } },  /* 23: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { { -116,  64,  54,  31 },  {    0,   0,   0,   0 } } },  /* 26: M KICK B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: no box */
    { { { -114,  56,  36,  21 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI P A */
    { { { -110,  52,  39,  24 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { { -118,  88,   0,  42 },  {    0,   0,   0,   0 } } },  /* 35: KAGAMI K A, UP P GUARD K S */
    { { { -126,  96,   0,  42 },  {    0,   0,   0,   0 } } },  /* 36: KAGAMI K A, UP P GUARD K S */
    { { { -114,  84,   0,  40 },  {    0,   0,   0,   0 } } },  /* 37: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: no box */
    { { {  -93,  51,  39,  42 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP P S A */
    { { {  -85,  51,  39,  43 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP P M A, ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {  -64,  40,  78,  14 },  {    0,   0,   0,   0 } } },  /* 45: FUSHIN P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {  -72,  50,  98,  18 },  {    0,   0,   0,   0 } } },  /* 51: OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {  -99,  61,  66,  23 },  {    0,   0,   0,   0 } } },  /* 53: L PUNCH C */
    { { {  -99,  61,  66,  23 },  {    0,   0,   0,   0 } } },  /* 54: L PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {  -81,  51,  40,  62 },  {    0,   0,   0,   0 } } },  /* 57: V JUMP P L A */
    { { {  -71,  44,  29,  52 },  {    0,   0,   0,   0 } } },  /* 58: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { { -118,  78,  44,  37 },  {    0,   0,   0,   0 } } },  /* 67: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: no box */
    { { {  -99,  79,  48,  53 },  {    0,   0,   0,   0 } } },  /* 69: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: no box */
    { { {  -84,  31,  44,  30 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { { {  -82,  34,  33,  22 },  {    0,   0,   0,   0 } } },  /* 72: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { { -102,  68,  68,  31 },  {    0,   0,   0,   0 } } },  /* 92: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  66,  41 },  {    0,   0,   0,   0 } } },  /* 93: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -87,  69,  79,  28 },  {    0,   0,   0,   0 } } },  /* 94: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { { -102,  68,  68,  31 },  {    0,   0,   0,   0 } } },  /* 96: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  66,  41 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  71,  36 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { { -102,  68,  68,  31 },  {    0,   0,   0,   0 } } },  /* 100: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  66,  41 },  {    0,   0,   0,   0 } } },  /* 101: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  71,  36 },  {    0,   0,   0,   0 } } },  /* 102: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: no box */
    { { { -118,  78,  44,  37 },  {    0,   0,   0,   0 } } },  /* 106: F JUMP P L B, SP F JP L P B, FUSHIN P S */
    { { { -118,  78,  44,  37 },  {    0,   0,   0,   0 } } },  /* 107: F JUMP P L B, SP F JP L P B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: no box */
    { { {  -69,  39,  75,  33 },  {    0,   0,   0,   0 } } },  /* 109: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    { { {  -77,  51,  99,  23 },  {    0,   0,   0,   0 } } },  /* 110: not used by a script */
    { { {  -69,  39,  44,  63 },  {    0,   0,   0,   0 } } },  /* 111: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
};

const HOSEI_BOX alex_hos_box[27] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -30,   61,    0,   86 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +114 */
    { {  -22,   61,    0,   86 } },  /* 2: L PUNCH A, S KICK A, M KICK A +1 */
    { {  -14,   61,    0,   86 } },  /* 3: M PUNCH C, UP P GUARD P S, S KICK A +2 */
    { {   -6,   61,    0,   86 } },  /* 4: L PUNCH A, M PUNCH C, UP P GUARD P S +2 */
    { {    2,   61,    0,   86 } },  /* 5: M PUNCH C, UP P GUARD P S */
    { {   10,   61,    0,   86 } },  /* 6: not used by a script */
    { {  -30,   61,    0,   59 } },  /* 7: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), KAGAMU, KAGAMI KAMAE +58 */
    { {  -30,   61,   45,   58 } },  /* 8: AIR S, AIR M, AIR L +42 */
    { {  -46,   61,    0,   86 } },  /* 9: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { {  -38,   73,    0,   83 } },  /* 10: not used by a script */
    { {  -12,   48,   60,   39 } },  /* 11: not used by a script */
    { {  -23,   47,   92,   50 } },  /* 12: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 13: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 14: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -26,   42,   60,   58 } },  /* 15: not used by a script */
    { {  -36,   56,   63,   32 } },  /* 16: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command +1 */
    { {  -42,   62,   45,   58 } },  /* 17: not used by a script */
    { {  -21,   45,   45,   44 } },  /* 18: AIR S, AIR M, AIR L +43 */
    { {  -48,   88,    0,   86 } },  /* 19: L KICK A */
    { {  -35,   70,    0,   62 } },  /* 20: PIYO */
    { {  -24,   55,   45,   40 } },  /* 21: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 9 S: not started by a command, ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +2 */
    { {  -30,   61,    0,   30 } },  /* 22: NEKOROBI S, dmca 96, dmca 97 */
    { {  -30,   61,    0,   56 } },  /* 23: SP F JP L P B */
    { {  -37,   95,    0,   74 } },  /* 24: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { {  -56,   98,    0,   74 } },  /* 25: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { {  -37,   95,    0,   74 } },  /* 26: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
};
