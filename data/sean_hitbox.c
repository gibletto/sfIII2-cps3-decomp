/*
 * SEAN_HITBOX.C  Sean's hit boxes
 *
 * Each of Sean's animation frames names an entry of sean_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX sean_hit_ix_table[209] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +16 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +116 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +33 */
    {   30,    0,    0,    0,    0,    0,    0,   26 },  /* 3: dmca 97, OKIAGARI P S */
    {    0,    0,    0,    1,    0,    1,    0,    2 },  /* 4: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +1 */
    {    0,    0,    0,    2,    0,    2,    0,    1 },  /* 5: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +1 */
    {    3,    3,    0,    3,   10,    3,    0,   17 },  /* 6: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command */
    {    3,    3,    0,    0,   10,    0,    0,   17 },  /* 7: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +5 */
    {    4,    4,    0,    0,   10,    0,    0,   17 },  /* 8: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +3 */
    {    5,    5,    0,    0,   18,    0,    0,   19 },  /* 9: DASH HUMIKOMI, DASH TOBINOKI */
    {    6,    6,    0,    0,    1,    0,    0,    1 },  /* 10: DASH TOBINOKI */
    {    7,    7,    0,    0,    3,    0,    0,    3 },  /* 11: GUARD AIR, V JUMP P M A, V JUMP K S A +7 */
    {    8,    8,    0,    0,    3,    0,    0,    3 },  /* 12: not used by a script */
    {    9,    9,    0,    0,    3,    0,    0,    3 },  /* 13: not used by a script */
    {   10,   10,    0,    0,    4,    0,    0,    4 },  /* 14: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    {   11,   11,    0,    0,    4,    0,    0,    4 },  /* 15: JUMP JUNBI, SP JUMP JUNBI, JUMP VERTICAL +7 */
    {   12,   12,    0,    0,    4,    0,    0,    4 },  /* 16: JUMP VERTICAL, S JUMP FRONT, SP JUMP V +2 */
    {   13,   13,    0,    0,    3,    0,    0,    3 },  /* 17: not used by a script */
    {   14,   14,    0,    0,    3,    0,    0,    3 },  /* 18: not used by a script */
    {   15,   15,    0,    0,    3,    0,    0,    3 },  /* 19: not used by a script */
    {  109,  109,    0,    4,    1,    4,    0,    1 },  /* 20: not used by a script */
    {   16,   16,    0,    0,    1,    0,    0,    1 },  /* 21: not used by a script */
    {   17,   17,    0,    5,    1,    5,    0,    1 },  /* 22: S PUNCH A */
    {   17,   17,    0,    0,    1,    0,    0,    1 },  /* 23: S PUNCH A */
    {  110,  110,    0,    6,    1,    6,    0,    1 },  /* 24: M PUNCH A */
    {   18,   18,    0,    0,    1,    0,    0,    1 },  /* 25: M PUNCH B, L PUNCH A, L PUNCH C +3 */
    {   19,   19,    0,    7,    1,    7,    0,    1 },  /* 26: M PUNCH B, UP P GUARD P S */
    {   19,  147,    0,    0,    1,    0,    0,    1 },  /* 27: M PUNCH B, UP P GUARD P S */
    {   20,   20,    0,    0,    1,    0,    0,    1 },  /* 28: M PUNCH B, UP P GUARD P S */
    {   21,   21,    0,    0,    1,    0,    0,    1 },  /* 29: L PUNCH A, UP P GUARD P L */
    {   22,   22,    0,    8,    1,    8,    0,    1 },  /* 30: L PUNCH A, UP P GUARD P L */
    {   23,   23,    0,    9,    1,    9,    0,    1 },  /* 31: L PUNCH A, UP P GUARD P L */
    {   24,   24,    0,    0,    1,    0,    0,    1 },  /* 32: L PUNCH A, UP P GUARD P L */
    {   25,   25,    0,    0,    1,    0,    0,    1 },  /* 33: not used by a script */
    {   26,   26,    0,   10,    1,   10,    0,    1 },  /* 34: not used by a script */
    {   27,   27,    0,   10,    1,   10,    0,    1 },  /* 35: not used by a script */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 36: not used by a script */
    {   28,   28,    0,    0,    1,    0,    0,    1 },  /* 37: not used by a script */
    {   29,   29,    0,    0,    1,    0,    0,    1 },  /* 38: not used by a script */
    {   31,   31,    0,    0,    8,    0,    0,    1 },  /* 39: S KICK A, M KICK A */
    {   31,   31,    0,   11,    8,   11,    0,    1 },  /* 40: S KICK A */
    {   31,    0,    0,    0,    8,    0,    0,    1 },  /* 41: S KICK A */
    {   32,   32,    0,    0,    1,    0,    0,    1 },  /* 42: not used by a script */
    {   33,   33,    0,    0,    1,    0,    0,    1 },  /* 43: not used by a script */
    {   34,   34,    0,   12,    1,   12,    0,    1 },  /* 44: not used by a script */
    {   34,   34,    0,    0,    1,    0,    0,    1 },  /* 45: not used by a script */
    {   35,   35,    0,    0,    1,    0,    0,    1 },  /* 46: not used by a script */
    {   36,   36,    0,    0,    1,    0,    0,    1 },  /* 47: M KICK A */
    {   31,   31,    0,   13,    1,   13,    0,    1 },  /* 48: M KICK A */
    {   37,   37,    0,   13,    1,   13,    0,    1 },  /* 49: M KICK A */
    {   38,   38,    0,    0,    1,    0,    0,    1 },  /* 50: not used by a script */
    {   39,   39,    0,    0,    1,    0,    0,    1 },  /* 51: not used by a script */
    {   40,   40,    0,   14,    1,   14,    0,    1 },  /* 52: not used by a script */
    {   40,   40,    0,    0,    1,    0,    0,    1 },  /* 53: not used by a script */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 54: not used by a script */
    {   42,   42,    0,    0,    1,    0,    0,    1 },  /* 55: not used by a script */
    {   43,   43,    0,    0,    1,    0,    0,    1 },  /* 56: not used by a script */
    {   44,   44,    0,    0,    1,    0,    0,    1 },  /* 57: not used by a script */
    {   45,   45,    0,    0,    1,    0,    0,    1 },  /* 58: L KICK A */
    {   46,   46,    0,   15,    1,   15,    0,    1 },  /* 59: L KICK A */
    {   47,   47,    0,   15,    1,   15,    0,    1 },  /* 60: L KICK A */
    {   48,   48,    0,    0,    1,    0,    0,    1 },  /* 61: L KICK A */
    {   49,   49,    0,    0,    1,    0,    0,    1 },  /* 62: not used by a script */
    {   50,   50,    0,    0,    1,    0,    0,    1 },  /* 63: not used by a script */
    {   51,   51,    0,    0,    1,    0,    0,    1 },  /* 64: not used by a script */
    {   52,   52,    0,    0,    1,    0,    0,    1 },  /* 65: L KICK B, follow-up of M PUNCH A */
    {   53,   53,    0,   19,    1,   19,    0,    1 },  /* 66: L KICK B */
    {   54,   54,    0,   19,    1,   19,    0,    1 },  /* 67: L KICK B */
    {   55,   55,    0,    0,    1,    0,    0,    1 },  /* 68: L KICK B, follow-up of M PUNCH A */
    {   54,   54,    0,    0,    1,    0,    0,    1 },  /* 69: L KICK B, follow-up of M PUNCH A */
    {   56,   56,    0,    0,    1,    0,    0,    1 },  /* 70: L KICK B, follow-up of M PUNCH A */
    {   57,   57,    0,    0,    1,    0,    0,    1 },  /* 71: L KICK B, follow-up of M PUNCH A */
    {   58,   58,    0,    0,    1,    0,    0,    1 },  /* 72: not used by a script */
    {   59,   59,    0,    0,    1,    0,    0,    1 },  /* 73: not used by a script */
    {   60,   60,    0,    0,   13,    0,    0,   10 },  /* 74: TOUKETSU A */
    {   61,   61,    0,   20,    1,   20,    0,    1 },  /* 75: not used by a script */
    {   61,   61,    0,    0,    1,    0,    0,    1 },  /* 76: not used by a script */
    {   62,   62,    0,    0,    1,    0,    0,    1 },  /* 77: not used by a script */
    {   63,   63,    0,    0,    1,    0,    0,    1 },  /* 78: not used by a script */
    {   64,   64,    0,   21,    9,   21,    0,    2 },  /* 79: KAGAMI P A */
    {   64,   64,    0,    0,    9,    0,    0,    2 },  /* 80: KAGAMI P A */
    {   65,   65,    0,   22,    2,   22,    0,    2 },  /* 81: KAGAMI P A */
    {   65,   65,    0,    0,    2,    0,    0,    2 },  /* 82: KAGAMI P A */
    {   66,   66,    0,    0,    2,    0,    0,    2 },  /* 83: KAGAMI P A */
    {   67,   67,    0,   23,    2,   23,    0,    2 },  /* 84: KAGAMI P A */
    {   68,   68,    0,   24,    2,   24,    0,    2 },  /* 85: KAGAMI P A */
    {   69,   69,    0,    0,    2,    0,    0,    2 },  /* 86: not used by a script */
    {   68,   68,    0,    0,    2,    0,    0,    2 },  /* 87: KAGAMI P A */
    {   70,   70,    0,    0,    2,    0,    0,    2 },  /* 88: KAGAMI P A */
    {   71,   71,    0,    0,    9,    0,    0,    2 },  /* 89: KAGAMI K A */
    {   72,   72,    0,   25,    9,   25,    0,    2 },  /* 90: KAGAMI K A */
    {   72,   72,    0,    0,    9,    0,    0,    2 },  /* 91: KAGAMI K A */
    {   73,   73,    0,    0,    2,    0,    0,    2 },  /* 92: KAGAMI K A, UP P GUARD K S */
    {   74,   74,    0,   26,    2,   26,    0,    2 },  /* 93: KAGAMI K A, UP P GUARD K S */
    {   74,   74,    0,    0,    2,    0,    0,    2 },  /* 94: KAGAMI K A, UP P GUARD K S */
    {   75,   75,    0,    0,    2,    0,    0,    2 },  /* 95: UP P GUARD K S */
    {   76,   76,    0,    0,    2,    0,    0,    2 },  /* 96: KAGAMI K A */
    {   77,   77,    0,   27,    2,   27,    0,    2 },  /* 97: KAGAMI K A */
    {   77,   77,    0,    0,    2,    0,    0,    2 },  /* 98: KAGAMI K A */
    {   78,   78,    0,    0,    4,    0,    0,    4 },  /* 99: V JUMP P S A, F JUMP P S A */
    {   78,   78,    0,   28,    4,   28,    0,    4 },  /* 100: V JUMP P S A, F JUMP P S A */
    {   79,   79,    0,    0,    4,    0,    0,    4 },  /* 101: V JUMP P L A */
    {   80,   80,    0,   29,    4,   29,    0,    4 },  /* 102: V JUMP P L A */
    {   80,   80,    0,    0,    4,    0,    0,    4 },  /* 103: V JUMP P L A */
    {   81,   81,    0,   30,    4,   30,    0,    4 },  /* 104: V JUMP K M A */
    {   81,   81,    0,    0,    4,    0,    0,    4 },  /* 105: V JUMP K M A */
    {   95,   95,    0,   31,    3,   31,    0,    3 },  /* 106: not used by a script */
    {   96,   96,    0,   32,    3,   32,    0,    3 },  /* 107: F JUMP P L A */
    {   82,   82,    0,   33,    3,   33,    0,    3 },  /* 108: V JUMP K S A, F JUMP K S A */
    {   82,   82,    0,    0,    3,    0,    0,    3 },  /* 109: V JUMP K S A, F JUMP K S A */
    {   83,   83,    0,   34,    3,   34,    0,    3 },  /* 110: F JUMP K M A */
    {   83,   83,    0,    0,    3,    0,    0,    3 },  /* 111: F JUMP K M A, F JUMP K L A */
    {   96,  154,    0,    0,    4,   35,    0,    4 },  /* 112: V JUMP P M A, F JUMP P M A */
    {   96,  155,    0,    0,    4,    0,    0,    4 },  /* 113: V JUMP P M A, F JUMP P M A */
    {   84,   84,    0,   37,    3,   37,    0,    3 },  /* 114: V JUMP K L A */
    {   84,   84,    0,    0,    3,    0,    0,    3 },  /* 115: V JUMP K L A */
    {   85,   85,    0,    0,   15,    0,    0,   23 },  /* 116: not used by a script */
    {   86,   86,    0,    0,   15,    0,    0,   23 },  /* 117: ATTACK 4 S: SA I 23623+P (plain script) */
    {   87,   87,    0,   38,    0,   38,    0,    1 },  /* 118: exca 17, ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   88,   88,    0,    0,   12,    0,    0,   18 },  /* 119: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +3 */
    {   89,   89,    0,   39,   12,   39,    0,   18 },  /* 120: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +2 */
    {   89,   89,    0,    0,   12,    0,    0,   18 },  /* 121: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +3 */
    {   90,   90,    0,    0,    0,    0,    0,   18 },  /* 122: not used by a script */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 123: GUARD HEAD */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 124: GUARD UP, P BREAK ZUJOU, P BREAK DOWN +1 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 125: GUARD DOWN */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 126: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 127: not used by a script */
    {    1,    1,    0,   41,    1,   41,    0,    1 },  /* 128: M PUNCH A, M PUNCH B, M KICK A +3 */
    {  115,  115,    0,    0,    1,    0,    0,    1 },  /* 129: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI) */
    {  116,  116,    0,    0,    3,    0,    0,    3 },  /* 130: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +1 */
    {  117,  117,    0,   46,    3,   46,    0,    3 },  /* 131: not used by a script */
    {  118,  118,    0,   42,    3,   42,    0,    3 },  /* 132: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  119,  119,    0,   43,    3,   43,    0,    3 },  /* 133: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +2 */
    {  120,  120,    0,    0,    3,    0,    0,    3 },  /* 134: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  118,  118,    0,    0,    0,    0,    0,    1 },  /* 135: not used by a script */
    {  119,  119,    0,    0,    0,    0,    0,    1 },  /* 136: not used by a script */
    {  126,  126,    0,    0,    0,    0,    0,    0 },  /* 137: ATTACK 7 S: 214+P light (routine Att_CHOUCHUURENGEKI), ATTACK 7 M: 214+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 7 L: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  121,  121,    0,    0,   13,    0,    0,   20 },  /* 138: AIR S, AIR M, AIR L +41 */
    {  119,  119,    0,   44,    3,   44,    0,    3 },  /* 139: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  122,  122,    0,    0,    2,    0,    0,    2 },  /* 140: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 1 SP: EX 4(123)6+PP (routine Att_CHOUCHUURENGEKI) */
    {  123,  123,    0,    0,    5,    0,    0,   21 },  /* 141: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {  124,  124,    0,    0,    5,    0,    0,   21 },  /* 142: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {  125,  125,    0,   45,    5,   45,    0,   21 },  /* 143: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 144: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {    0,    0,    0,    0,   19,    0,    0,    0 },  /* 145: not used by a script */
    {  128,  128,    0,    0,   14,    0,    0,   22 },  /* 146: not used by a script */
    {  129,  129,    0,   47,   14,   47,    0,   22 },  /* 147: not used by a script */
    {    5,    5,    0,   48,    1,   48,    0,    1 },  /* 148: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  108,  108,    0,    0,    1,    0,    0,    1 },  /* 149: M PUNCH A, FUSHIN P S */
    {    0,    0,    0,    0,    0,    0,    0,   23 },  /* 150: FUSHIN P S, ATTACK 4 S: SA I 23623+P (plain script) */
    {  130,  130,    0,    0,    0,    0,    0,    2 },  /* 151: not used by a script */
    {  131,  131,    0,    0,    0,    0,    0,    2 },  /* 152: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command */
    {   83,   83,    0,   49,    3,   49,    0,    3 },  /* 153: F JUMP K L A */
    {   77,   77,    0,    0,    2,    0,    0,    2 },  /* 154: not used by a script */
    {    1,    1,    0,   51,    1,   51,    0,    1 },  /* 155: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  132,  132,    0,   46,    0,   46,    0,    1 },  /* 156: not used by a script */
    {    0,    0,    0,   48,    0,   48,    0,    1 },  /* 157: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   89,   89,    0,   52,    0,   52,    0,   18 },  /* 158: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   74,   74,    0,    0,    2,    0,    0,    2 },  /* 159: not used by a script */
    {  133,  133,    0,   48,   15,   48,    0,   23 },  /* 160: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  133,  133,    0,    0,   15,    0,    0,   23 },  /* 161: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {  118,  118,    0,   53,    0,   53,    0,   20 },  /* 162: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    1,    0,   55,    1,   55,    0,    1 },  /* 163: L PUNCH A, L PUNCH C, L KICK A +1 */
    {    0,    0,    0,    0,    0,    0,    0,   18 },  /* 164: AIR S, AIR M, AIR L +2 */
    {  134,  134,    0,    0,   11,    0,    0,   25 },  /* 165: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {  134,  134,    0,   56,    0,   56,    0,   25 },  /* 166: not used by a script */
    {  134,  134,    0,   57,    0,   57,    0,   25 },  /* 167: not used by a script */
    {  134,  134,    0,   58,   11,   58,    0,   25 },  /* 168: ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {  134,  134,    0,   59,    0,   59,    0,   18 },  /* 169: not used by a script */
    {  135,  135,    0,   60,    3,   60,    0,    3 },  /* 170: ATTACK 10 S: not started by a command */
    {  137,  137,    0,    0,    1,    0,    0,    1 },  /* 171: PIYO */
    {  138,  138,    0,    0,    1,    0,    0,    1 },  /* 172: PIYO */
    {  139,  139,    0,    0,   15,    0,    0,    5 },  /* 173: ATTACK 4 S: SA I 23623+P (plain script) */
    {   84,   84,    0,   61,    3,   61,    0,    3 },  /* 174: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    {    0,    0,    0,    0,    0,    0,    0,   26 },  /* 175: NEKOROBI S, dmca 96 */
    {  140,  140,    0,    0,   16,    0,    0,    2 },  /* 176: OKIAGARI P S */
    {  140,  140,    0,   62,   16,   62,    0,    1 },  /* 177: OKIAGARI P S */
    {  141,  141,    0,   63,   17,   63,    0,    4 },  /* 178: OKIAGARI P S */
    {  142,  142,    0,    0,   17,    0,    0,    4 },  /* 179: OKIAGARI P S */
    {   96,   96,    0,   64,    3,   64,    0,    3 },  /* 180: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {    2,    2,    0,    1,    1,    1,    0,    2 },  /* 181: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) +2 */
    {  143,  143,    0,    2,    3,    2,    0,    1 },  /* 182: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) +2 */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 183: follow-up of SP APPEAR 8 */
    {    2,    2,    0,    0,    0,    0,    0,    2 },  /* 184: follow-up of SP APPEAR 8 */
    {  144,  144,    0,    0,    1,    0,    0,    1 },  /* 185: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +1 */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 186: LOSE SONABA */
    {  145,  145,    0,    0,   20,    0,    0,   27 },  /* 187: PARING AIR F, PARING AIR B */
    {  125,  125,    0,    0,    5,    0,    0,   21 },  /* 188: not used by a script */
    {  146,  146,    0,    0,    5,    0,    0,   21 },  /* 189: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   19,  147,    0,    7,    1,    7,    0,    1 },  /* 190: M PUNCH B */
    {  147,  148,    0,    0,    1,    0,    0,    1 },  /* 191: L PUNCH C, follow-up of L PUNCH A */
    {  148,  148,    0,    0,    1,    0,    0,    1 },  /* 192: L PUNCH C, follow-up of L PUNCH A */
    {  149,  148,    0,    0,    1,    0,    0,    1 },  /* 193: L PUNCH C, follow-up of L PUNCH A */
    {  150,  149,    0,    0,    1,   16,    0,    2 },  /* 194: L PUNCH C, follow-up of L PUNCH A */
    {  151,  150,    0,    0,    1,   17,    0,    2 },  /* 195: L PUNCH C, follow-up of L PUNCH A */
    {  151,  151,    0,    0,    1,   18,    0,    2 },  /* 196: L PUNCH C, follow-up of L PUNCH A */
    {  151,  151,    0,    0,    1,    0,    0,    2 },  /* 197: L PUNCH C, follow-up of L PUNCH A */
    {  152,  152,    0,    0,    1,    0,    0,    1 },  /* 198: L PUNCH C, follow-up of L PUNCH A */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 199: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {  153,    0,    0,    0,    4,    0,    0,    4 },  /* 200: ATTACK 12 S: not started by a command, ATTACK 12 M: not started by a command, ATTACK 12 SP: not started by a command */
    {    7,    0,    0,    0,    4,    0,    0,    4 },  /* 201: V JUMP K M A */
    {  154,  153,    0,   30,    4,   30,    0,    4 },  /* 202: V JUMP K M A */
    {   84,    0,    0,   61,    3,   61,    0,    3 },  /* 203: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    {    0,    0,    0,    0,    1,    1,    0,    2 },  /* 204: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {  155,  156,    0,    0,    3,   65,    0,    3 },  /* 205: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +1 */
    {  155,  156,    0,    0,    3,    0,    0,    3 },  /* 206: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   53,   53,    0,    0,    1,   66,    0,    1 },  /* 207: follow-up of M PUNCH A */
    {   54,   54,    0,    0,    1,   67,    0,    1 },  /* 208: follow-up of M PUNCH A */
};

const BODY_BOX sean_body_box[156] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -16,  23,  84,  18 },  {  -29,  59,  81,   7 },  {  -29,  59,  32,  49 },  {  -35,  72,   0,  31 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +119 */
    { { {  -16,  26,  50,  18 },  {  -30,  58,  43,  13 },  {  -29,  58,  26,  20 },  {  -38,  72,   0,  30 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +35 */
    { { {   -1,  18,  96,  16 },  {  -20,  44,  81,  14 },  {  -16,  32,  63,  18 },  {  -26,  42,   0,  64 } } },  /* 3: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command +5 */
    { { {   -4,  18, 102,  16 },  {  -24,  44,  90,  14 },  {  -24,  46,  61,  31 },  {  -18,  42,  -3,  73 } } },  /* 4: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +3 */
    { { {  -16,  23,  78,  16 },  {  -25,  53,  62,  20 },  {  -24,  40,  37,  29 },  {  -38,  66,   0,  35 } } },  /* 5: DASH HUMIKOMI, DASH TOBINOKI, ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {   -5,  23,  78,  16 },  {  -25,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -33,  55,   0,  35 } } },  /* 6: DASH TOBINOKI */
    { { {  -19,  39,  92,  16 },  {  -32,  64,  78,  15 },  {  -30,  59,  42,  37 },  {    0,   0,   0,   0 } } },  /* 7: GUARD AIR, V JUMP P M A, V JUMP K S A +8 */
    { { {  -28,  54,  39,  40 },  {  -23,  53,  75,  20 },  {  -28,  54,  39,  40 },  {    0,   0,   0,   0 } } },  /* 8: not used by a script */
    { { {  -42,  31,  52,  21 },  {  -33,  60,  75,  20 },  {  -25,  52,  36,  37 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {    0,   0,   0,   0 },  {  -34,  69,  42,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    { { {  -11,  23, 106,  16 },  {  -23,  53,  90,  20 },  {  -19,  43,  45,  49 },  {    0,   0,   0,   0 } } },  /* 11: JUMP JUNBI, SP JUMP JUNBI, JUMP VERTICAL +7 */
    { { {  -18,  23,  99,  16 },  {  -23,  53,  90,  20 },  {  -31,  63,  44,  44 },  {    0,   0,   0,   0 } } },  /* 12: JUMP VERTICAL, S JUMP FRONT, SP JUMP V +2 */
    { { {  -13,  27,  93,  17 },  {  -22,  57,  76,  20 },  {  -29,  57,  40,  38 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {  -11,  49,  81,  19 },  {  -39,  79,  42,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: not used by a script */
    { { {  -22,  57,  76,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: not used by a script */
    { { {  -23,  23,  78,  16 },  {  -31,  53,  63,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 16: not used by a script */
    { { {  -14,  21,  84,  18 },  {  -28,  58,  69,  22 },  {  -21,  49,  38,  31 },  {  -28,  63,   0,  38 } } },  /* 17: S PUNCH A */
    { { {  -29,  34,  82,  16 },  {  -36,  65,  66,  20 },  {  -32,  58,  36,  29 },  {  -32,  67,   0,  35 } } },  /* 18: M PUNCH B, L PUNCH A, L PUNCH C +3 */
    { { {  -27,  23,  79,  16 },  {  -45,  69,  63,  21 },  {  -32,  52,  36,  29 },  {  -42,  74,   0,  41 } } },  /* 19: M PUNCH B, UP P GUARD P S */
    { { {  -20,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 20: M PUNCH B, UP P GUARD P S */
    { { {  -20,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 21: L PUNCH A, UP P GUARD P L */
    { { {  -29,  34,  83,  16 },  {  -32,  54,  67,  20 },  {  -26,  43,  36,  29 },  {  -33,  62,   0,  35 } } },  /* 22: L PUNCH A, UP P GUARD P L */
    { { {  -29,  34,  83,  16 },  {  -32,  54,  67,  20 },  {  -26,  43,  36,  29 },  {  -33,  62,   0,  35 } } },  /* 23: L PUNCH A, UP P GUARD P L */
    { { {  -29,  34,  83,  16 },  {  -32,  54,  67,  20 },  {  -26,  43,  36,  29 },  {  -33,  62,   0,  35 } } },  /* 24: L PUNCH A, UP P GUARD P L */
    { { {  -21,  38,  83,  16 },  {  -29,  55,  67,  20 },  {  -21,  44,  47,  22 },  {  -35,  61,   0,  47 } } },  /* 25: not used by a script */
    { { {  -20,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -35,  61,   0,  35 } } },  /* 26: not used by a script */
    { { {   -6,  26,  82,  16 },  {  -25,  49,  67,  20 },  {  -20,  43,  36,  29 },  {  -36,  80,   0,  35 } } },  /* 27: not used by a script */
    { { {    0,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -35,  61,   0,  35 } } },  /* 28: not used by a script */
    { { {  -14,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -35,  61,   0,  35 } } },  /* 29: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 30: dmca 97, OKIAGARI P S */
    { { {  -24,  31,  84,  16 },  {  -32,  51,  67,  20 },  {  -35,  56,  36,  29 },  {  -44,  56,   0,  35 } } },  /* 31: S KICK A, M KICK A */
    { { {    7,  23,  83,  16 },  {   -5,  53,  67,  20 },  {   -6,  43,  36,  29 },  {   10,  26,   0,  35 } } },  /* 32: not used by a script */
    { { {   21,  23,  83,  16 },  {    6,  53,  67,  20 },  {   -6,  43,  36,  29 },  {   10,  26,   0,  35 } } },  /* 33: not used by a script */
    { { {   21,  23,  83,  16 },  {    6,  53,  67,  20 },  {   -6,  43,  36,  29 },  {   10,  26,   0,  35 } } },  /* 34: not used by a script */
    { { {  -33,  23,  86,  15 },  {  -41,  52,  72,  14 },  {  -56,  63,  41,  30 },  {  -47,  55,   0,  42 } } },  /* 35: not used by a script */
    { { {  -19,  31,  84,  16 },  {  -32,  56,  67,  20 },  {  -35,  60,  36,  31 },  {  -39,  80,   0,  35 } } },  /* 36: M KICK A */
    { { {  -24,  31,  84,  16 },  {  -32,  51,  67,  20 },  {  -35,  56,  36,  29 },  {  -44,  56,   0,  35 } } },  /* 37: M KICK A */
    { { {  -26,  23,  83,  16 },  {  -33,  43,  68,  20 },  {  -25,  29,  35,  30 },  {  -33,  28,   0,  35 } } },  /* 38: not used by a script */
    { { {   -2,  23,  87,  16 },  {  -12,  53,  67,  20 },  {  -13,  43,  36,  29 },  {   -9,  33,   0,  37 } } },  /* 39: not used by a script */
    { { {    7,  31,  82,  16 },  {  -16,  77,  59,  25 },  {  -39,  67,  46,  18 },  {  -28,  63,   0,  38 } } },  /* 40: not used by a script */
    { { {   16,  24,  82,  19 },  {    3,  53,  67,  20 },  {  -16,  48,  32,  32 },  {  -28,  63,   0,  38 } } },  /* 41: not used by a script */
    { { {   14,  23,  82,  16 },  {    3,  53,  67,  20 },  {   -8,  43,  36,  29 },  {    8,  33,   0,  37 } } },  /* 42: not used by a script */
    { { {  -32,  23,  82,  16 },  {  -46,  53,  67,  20 },  {  -39,  43,  36,  29 },  {  -43,  55,   0,  35 } } },  /* 43: not used by a script */
    { { {  -35,  23,  88,  16 },  {  -46,  46,  67,  20 },  {  -52,  43,  36,  29 },  {  -43,  34,   0,  35 } } },  /* 44: not used by a script */
    { { {  -33,  23,  86,  15 },  {  -41,  52,  72,  14 },  {  -47,  56,  41,  30 },  {  -47,  55,   0,  42 } } },  /* 45: L KICK A */
    { { {  -35,  23,  88,  16 },  {  -46,  46,  67,  20 },  {  -52,  43,  36,  29 },  {  -43,  34,   0,  35 } } },  /* 46: L KICK A */
    { { {  -35,  23,  88,  16 },  {  -46,  46,  67,  20 },  {  -52,  43,  36,  29 },  {  -43,  34,   0,  35 } } },  /* 47: L KICK A */
    { { {  -39,  31,  89,  16 },  {  -48,  53,  73,  20 },  {  -33,  38,  43,  31 },  {  -47,  55,   0,  42 } } },  /* 48: L KICK A */
    { { {  -26,  23,  83,  16 },  {  -33,  43,  68,  20 },  {  -25,  29,  35,  30 },  {  -33,  28,   0,  35 } } },  /* 49: not used by a script */
    { { {  -20,  23,  88,  16 },  {  -46,  46,  67,  20 },  {  -52,  43,  36,  29 },  {  -43,  34,   0,  35 } } },  /* 50: not used by a script */
    { { {  -31,  23,  88,  16 },  {  -44,  46,  67,  20 },  {  -39,  43,  36,  29 },  {  -43,  50,   0,  35 } } },  /* 51: not used by a script */
    { { {  -14,  31,  86,  16 },  {  -25,  53,  67,  20 },  {  -29,  45,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 52: L KICK B, follow-up of M PUNCH A */
    { { {    2,  23,  86,  16 },  {  -27,  60,  74,  20 },  {  -35,  60,  39,  42 },  {  -26,  55,   0,  39 } } },  /* 53: L KICK B, follow-up of M PUNCH A */
    { { {    2,  23,  86,  16 },  {  -27,  60,  74,  20 },  {  -35,  60,  39,  42 },  {  -26,  55,   0,  39 } } },  /* 54: L KICK B, follow-up of M PUNCH A */
    { { {    2,  23,  86,  16 },  {  -27,  60,  74,  20 },  {  -35,  60,  39,  42 },  {  -26,  55,   0,  39 } } },  /* 55: L KICK B, follow-up of M PUNCH A */
    { { {    2,  23,  86,  16 },  {  -27,  60,  74,  20 },  {  -35,  60,  39,  42 },  {  -26,  55,   0,  39 } } },  /* 56: L KICK B, follow-up of M PUNCH A */
    { { {    2,  23,  86,  16 },  {  -27,  60,  74,  20 },  {  -35,  60,  39,  42 },  {  -26,  55,   0,  39 } } },  /* 57: L KICK B, follow-up of M PUNCH A */
    { { {   -4,  23,  90,  16 },  {  -25,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 58: not used by a script */
    { { {    6,  23,  86,  16 },  {  -14,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 59: not used by a script */
    { { {   20,  23,  77,  16 },  {  -14,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 60: TOUKETSU A */
    { { {   37,  23,  65,  16 },  {    4,  53,  54,  20 },  {  -14,  43,  36,  29 },  {  -15,  36,   0,  35 } } },  /* 61: not used by a script */
    { { {   37,  23,  65,  16 },  {    4,  53,  54,  20 },  {  -14,  43,  36,  29 },  {  -15,  36,   0,  35 } } },  /* 62: not used by a script */
    { { {   32,  23,  78,  16 },  {    4,  53,  64,  20 },  {  -14,  43,  36,  29 },  {  -15,  36,   0,  35 } } },  /* 63: not used by a script */
    { { {  -23,  26,  48,  18 },  {  -30,  58,  43,  18 },  {  -18,  43,  20,  26 },  {  -42,  70,   0,  58 } } },  /* 64: KAGAMI P A */
    { { {  -14,  23,  50,  16 },  {  -21,  43,  37,  18 },  {  -18,  43,  20,  26 },  {  -42,  70,   0,  58 } } },  /* 65: KAGAMI P A */
    { { {  -14,  23,  50,  16 },  {  -21,  43,  37,  18 },  {  -18,  43,  20,  26 },  {  -42,  70,   0,  58 } } },  /* 66: KAGAMI P A */
    { { {  -24,  25,  70,  19 },  {  -37,  63,  61,  18 },  {    0,   0,   0,   0 },  {  -47,  74,   0,  60 } } },  /* 67: KAGAMI P A */
    { { {   -5,  23,  80,  16 },  {  -26,  62,  66,  18 },  {  -18,  43,  37,  29 },  {  -48,  78,   0,  52 } } },  /* 68: KAGAMI P A */
    { { {   -7,  23,  75,  16 },  {  -18,  44,  60,  18 },  {  -19,  43,  37,  29 },  {  -42,  70,   0,  58 } } },  /* 69: not used by a script */
    { { {   -8,  23,  69,  16 },  {  -17,  36,  53,  18 },  {  -21,  43,  31,  29 },  {  -42,  70,   0,  58 } } },  /* 70: KAGAMI P A */
    { { {  -16,  40,  46,  18 },  {  -30,  58,  43,  13 },  {  -29,  58,  26,  20 },  {  -38,  72,   0,  30 } } },  /* 71: KAGAMI K A */
    { { {   -4,  34,  43,  18 },  {  -35,  63,  34,  18 },  {  -54,  93,  13,  28 },  {  -85, 128,   0,  23 } } },  /* 72: KAGAMI K A */
    { { {   -4,  25,  44,  17 },  {  -44,  77,  28,  23 },  {  -23,  65,  20,  26 },  {  -59, 103,   0,  28 } } },  /* 73: KAGAMI K A, UP P GUARD K S */
    { { {   -4,  25,  44,  17 },  {  -35,  74,  28,  23 },  {  -59, 109,  17,  26 },  {  -65, 122,   0,  28 } } },  /* 74: KAGAMI K A, UP P GUARD K S */
    { { {   -6,  24,  58,  19 },  {  -36,  80,  43,  21 },  {  -31,  84,  20,  26 },  {  -64, 122,   0,  32 } } },  /* 75: UP P GUARD K S */
    { { {  -30,  48,  51,  17 },  {  -43,  73,  44,  14 },  {  -47,  78,  32,  16 },  {  -55,  92,   0,  33 } } },  /* 76: KAGAMI K A */
    { { {  -30,  48,  51,  18 },  {  -43,  73,  44,  14 },  {  -63,  97,  25,  19 },  {  -72, 111,   0,  32 } } },  /* 77: KAGAMI K A */
    { { {  -39,  49,  89,  20 },  {  -41,  72,  73,  28 },  {  -41,  77,  42,  45 },  {    0,   0,   0,   0 } } },  /* 78: V JUMP P S A, F JUMP P S A */
    { { {  -17,  28, 108,  16 },  {  -29,  54,  95,  15 },  {  -31,  69,  47,  49 },  {    0,   0,   0,   0 } } },  /* 79: V JUMP P L A */
    { { {  -17,  28, 108,  16 },  {  -29,  54,  95,  15 },  {  -31,  69,  47,  49 },  {    0,   0,   0,   0 } } },  /* 80: V JUMP P L A */
    { { {   -6,  23, 100,  16 },  {  -25,  53,  86,  20 },  {  -33,  69,  37,  52 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP K M A */
    { { {  -23,  39,  89,  16 },  {  -32,  63,  67,  24 },  {  -49,  76,  35,  33 },  {    0,   0,   0,   0 } } },  /* 82: V JUMP K S A, F JUMP K S A */
    { { {  -28,  48,  92,  14 },  {  -39,  68,  81,  14 },  {  -44,  74,  46,  41 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K M A, F JUMP K L A */
    { { {  -11,  23, 106,  16 },  {  -23,  53,  90,  20 },  {  -29,  57,  43,  40 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP K L A, ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    { { {  -28,  38,  74,  16 },  {  -37,  65,  56,  20 },  {  -19,  43,  36,  29 },  {  -46,  80,   0,  35 } } },  /* 85: not used by a script */
    { { {  -31,  29,  70,  16 },  {  -42,  77,  55,  23 },  {  -19,  43,  36,  29 },  {  -46,  80,   0,  35 } } },  /* 86: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {  -12,  18,  86,  14 },  {  -24,  52,  76,  14 },  {  -26,  53,  57,  22 },  {  -24,  56,   0,  62 } } },  /* 87: exca 17, ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  20, 102,  15 },  {  -29,  50,  88,  14 },  {  -26,  45,  53,  44 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +3 */
    { { {  -12,  20, 102,  15 },  {  -29,  50,  88,  14 },  {  -26,  45,  41,  59 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +3 */
    { { {  -10,  18,  98,  14 },  {  -24,  48,  88,  14 },  {  -31,  60,  30,  62 },  {    0,   0,   0,   0 } } },  /* 90: not used by a script */
    { { {   -3,  23,  83,  16 },  {  -17,  43,  72,  20 },  {   -8,  37,  40,  29 },  {  -20,  55,   0,  35 } } },  /* 91: not used by a script */
    { { {   -6,  23,  83,  16 },  {  -20,  53,  67,  20 },  {  -12,  38,  36,  29 },  {  -22,  55,   0,  35 } } },  /* 92: not used by a script */
    { { {   -6,  23,  49,  16 },  {  -16,  42,  37,  18 },  {  -18,  44,  20,  26 },  {  -28,  55,   0,  31 } } },  /* 93: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -27,  36,   0,  53 },  {    0,   0,   0,   0 } } },  /* 94: not used by a script */
    { { {  -20,  23,  89,  16 },  {  -25,  53,  74,  20 },  {  -17,  43,  47,  35 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -32,  27,  89,  24 },  {  -34,  66,  79,  27 },  {  -38,  82,  43,  46 },  {    0,   0,   0,   0 } } },  /* 96: F JUMP P L A, V JUMP P M A, F JUMP P M A +2 */
    { { {  -13,  22, 100,  17 },  {  -34,  65,  88,  14 },  {  -29,  60,  38,  53 },  {    0,   0,   0,   0 } } },  /* 97: not used by a script */
    { { {  -13,  22, 100,  17 },  {  -34,  65,  88,  14 },  {  -29,  60,  38,  53 },  {    0,   0,   0,   0 } } },  /* 98: not used by a script */
    { { {  -12,  18,  90,  14 },  {  -26,  50,  80,  14 },  {  -20,  34,  50,  28 },  {  -30,  54,  10,  38 } } },  /* 99: not used by a script */
    { { {  -10,  18,  84,  14 },  {  -24,  52,  74,  14 },  {  -24,  40,  40,  30 },  {  -10,  36,   0,  38 } } },  /* 100: not used by a script */
    { { {   -2,  18,  84,  14 },  {  -24,  52,  76,  14 },  {  -18,  36,  38,  34 },  {  -28,  50,   0,  36 } } },  /* 101: not used by a script */
    { { {   14,  18,  78,  14 },  {  -18,  52,  70,  14 },  {  -28,  48,  38,  30 },  {  -24,  26,   0,  36 } } },  /* 102: not used by a script */
    { { {   36,  18,  66,  14 },  {   12,  24,  50,  28 },  {  -30,  40,  44,  30 },  {  -20,  28,   0,  42 } } },  /* 103: not used by a script */
    { { {   34,  18,  68,  14 },  {   12,  24,  48,  30 },  {  -30,  40,  44,  28 },  {  -18,  28,   0,  42 } } },  /* 104: not used by a script */
    { { {   20,  18,  78,  14 },  {  -12,  52,  64,  20 },  {  -24,  48,  30,  32 },  {   -8,  30,   0,  30 } } },  /* 105: not used by a script */
    { { {  -23,  18,  86,  14 },  {  -30,  52,  73,  14 },  {  -19,  37,  41,  30 },  {  -38,  72,   2,  36 } } },  /* 106: not used by a script */
    { { {  -31,  23,  79,  16 },  {  -34,  53,  63,  20 },  {  -28,  43,  36,  29 },  {  -33,  55,   0,  35 } } },  /* 107: not used by a script */
    { { {  -14,  21,  84,  18 },  {  -28,  58,  69,  22 },  {  -21,  49,  38,  31 },  {  -28,  63,   0,  38 } } },  /* 108: M PUNCH A, FUSHIN P S */
    { { {  -23,  18,  81,  14 },  {  -34,  52,  67,  14 },  {  -25,  40,  38,  30 },  {  -28,  56,   0,  36 } } },  /* 109: not used by a script */
    { { {  -18,  23,  81,  16 },  {  -30,  61,  70,  15 },  {  -46,  72,  38,  30 },  {  -33,  65,   0,  36 } } },  /* 110: M PUNCH A */
    { { {  -28,  46,  89,  16 },  {  -35,  60,  69,  26 },  {  -72, 100,  49,  22 },  {  -85, 102,  46,  16 } } },  /* 111: not used by a script */
    { { {  -24,  23,  79,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 112: not used by a script */
    { { {  -24,  18,  90,  14 },  {  -17,  52,  79,  14 },  {   -9,  40,  47,  30 },  {  -24,  56,   0,  36 } } },  /* 113: not used by a script */
    { { {  -24,  18,  90,  14 },  {  -17,  52,  79,  14 },  {   -9,  40,  47,  30 },  {  -24,  56,   0,  36 } } },  /* 114: not used by a script */
    { { {    2,  23,  64,  16 },  {  -15,  33,  53,  20 },  {  -18,  43,  36,  29 },  {  -25,  61,   0,  35 } } },  /* 115: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI) */
    { { {    2,  23,  64,  16 },  {  -20,  39,  52,  19 },  {  -36,  83,  46,  54 },  {    0,   0,   0,   0 } } },  /* 116: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +1 */
    { { {    4,  23,  64,  16 },  {  -38, 113,  56,  31 },  {  -37,  98,  52,  47 },  {  -22,  65,  68,  21 } } },  /* 117: not used by a script */
    { { {    6,  38,  72,  16 },  {  -22,  72,  50,  20 },  {  -45,  96,  49,  47 },  {    0,   0,   0,   0 } } },  /* 118: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -28,  55,  71,  26 },  {  -47,  84,  36,  48 },  {  -28,  84,  48,  28 },  {    0,   0,   0,   0 } } },  /* 119: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +2 */
    { { {   -8,  36,  65,  28 },  {  -35,  91,  55,  20 },  {  -73, 115,  18,  40 },  {    0,   0,   0,   0 } } },  /* 120: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -17,  37,  77,  14 },  {  -24,  52,  66,  17 },  {  -24,  53,  47,  17 },  {  -17,  40,  37,  15 } } },  /* 121: AIR S, AIR M, AIR L +41 */
    { { {  -20,  23,  68,  16 },  {  -23,  50,  55,  14 },  {  -20,  43,  38,  15 },  {  -25,  55,   0,  35 } } },  /* 122: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 1 SP: EX 4(123)6+PP (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  66,  33,  16 },  {  -59,  94,   0,  34 } } },  /* 123: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -54,  22,  36,  16 },  {  -49,  53,  36,  17 },  {  -39,  43,  31,  11 },  {  -56,  94,   0,  32 } } },  /* 124: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -75,  23,  30,  16 },  {  -67,  53,  37,  13 },  {  -54,  43,  25,  16 },  {  -60, 101,   0,  25 } } },  /* 125: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {    0,   0,   0,   0 },  {  -23,  50,  22,  18 },  {  -18,  43,   9,  26 },  {  -28,  55,   0,  23 } } },  /* 126: ATTACK 7 S: 214+P light (routine Att_CHOUCHUURENGEKI), ATTACK 7 M: 214+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 7 L: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  55,   0,  23 } } },  /* 127: not used by a script */
    { { {    0,  16,  85,  16 },  {   -8,  48,  72,  16 },  {   -4,  40,  48,  24 },  {   -8,  40,  48,  24 } } },  /* 128: not used by a script */
    { { {    0,  16,  85,  16 },  {   -8,  48,  72,  16 },  {   -4,  40,  48,  24 },  {  -48,  40,  72,  16 } } },  /* 129: not used by a script */
    { { {  -34,  26,  73,  16 },  {  -27,  48,  61,  14 },  {  -25,  46,  38,  24 },  {  -38,  67,   0,  36 } } },  /* 130: not used by a script */
    { { {  -34,  26,  49,  16 },  {  -27,  48,  46,  14 },  {  -27,  46,  30,  24 },  {  -38,  67,   0,  36 } } },  /* 131: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command */
    { { {  -28,  57,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  99,  30,  50 },  {  -86,  98,   0,  36 } } },  /* 133: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -23,  21,  96,  18 },  {    0,   0,   0,   0 },  {  -50,  69,  40,  65 },  {    0,   0,   0,   0 } } },  /* 134: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -32,  27,  89,  24 },  {  -65,  96,  79,  27 },  {  -72, 104,  49,  33 },  {    0,   0,   0,   0 } } },  /* 135: ATTACK 10 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  56,  28,  78 },  {    0,   0,   0,   0 } } },  /* 136: not used by a script */
    { { {   -9,  21,  84,  18 },  {  -11,  54,  81,   7 },  {  -11,  52,  41,  40 },  {  -28,  63,   0,  38 } } },  /* 137: PIYO */
    { { {  -34,  21,  80,  18 },  {  -43,  68,  69,  17 },  {  -28,  52,  38,  30 },  {  -29,  63,   0,  38 } } },  /* 138: PIYO */
    { { {  -19,  23,  70,  16 },  {  -68,  95,  55,  23 },  {  -19,  43,  36,  29 },  {  -26,  58,   0,  35 } } },  /* 139: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -41,  81,   0,  24 } } },  /* 140: OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -41,  82,   0,  61 } } },  /* 141: OKIAGARI P S */
    { { {  -20,  41,  96,  27 },  {  -29,  58,  82,  14 },  {  -29,  58,  64,  18 },  {  -33,  66,   0,  64 } } },  /* 142: OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -25,  51,  34,  61 },  {    0,   0,   0,   0 } } },  /* 143: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA), ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) +2 */
    { { {  -29,  30,  84,  18 },  {  -40,  66,  78,   8 },  {  -39,  68,  38,  40 },  {  -30,  61,   0,  38 } } },  /* 144: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +1 */
    { { {    0,   0,   0,   0 },  {  -31,  63,  22,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 145: PARING AIR F, PARING AIR B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  66,  33,  32 },  {  -59,  94,   0,  34 } } },  /* 146: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -30,  23,  82,  16 },  {  -36,  53,  66,  20 },  {  -32,  49,  36,  29 },  {  -32,  69,   0,  35 } } },  /* 147: L PUNCH C, follow-up of L PUNCH A */
    { { {  -30,  23,  82,  16 },  {  -36,  53,  66,  20 },  {  -32,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 148: L PUNCH C, follow-up of L PUNCH A */
    { { {  -30,  49,  82,  16 },  {  -36,  67,  66,  20 },  {  -32,  56,  36,  29 },  {  -32,  92,   0,  35 } } },  /* 149: L PUNCH C, follow-up of L PUNCH A */
    { { {  -30,  29,  67,  16 },  {  -36,  62,  59,  13 },  {  -32,  56,  36,  23 },  {  -32,  92,   0,  35 } } },  /* 150: L PUNCH C, follow-up of L PUNCH A */
    { { {  -52,  21,  41,  30 },  {  -47,  49,  53,  13 },  {  -33,  47,  36,  23 },  {  -35,  92,   0,  35 } } },  /* 151: L PUNCH C, follow-up of L PUNCH A */
    { { {  -35,  21,  56,  20 },  {  -32,  49,  53,  13 },  {  -33,  47,  36,  23 },  {  -35,  92,   0,  35 } } },  /* 152: L PUNCH C, follow-up of L PUNCH A */
    { { {  -14,  20,  98,  18 },  {  -32,  54,  92,  12 },  {  -28,  46,  58,  32 },  {  -30,  48,  20,  36 } } },  /* 153: ATTACK 12 S: not started by a command, ATTACK 12 M: not started by a command, ATTACK 12 SP: not started by a command */
    { { {   -6,  23, 100,  16 },  {  -25,  53,  86,  20 },  {  -33,  69,  37,  52 },  {    0,   0,   0,   0 } } },  /* 154: V JUMP K M A */
    { { {  -28,  55,  71,  26 },  {  -47,  84,  36,  48 },  {  -28,  84,  48,  28 },  {    0,   0,   0,   0 } } },  /* 155: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +2 */
};

const HAND_BOX sean_hand_box[157] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {   -6,  17, 106,  26 },  {    0,   0,   0,   0 } } },  /* 3: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command +5 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: no box */
    { { {  -42,  12,  70,  20 },  {    0,   0,   0,   0 } } },  /* 16: not used by a script */
    { { {  -64,  51,  67,  22 },  {    0,   0,   0,   0 } } },  /* 17: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {  -70,  59,  64,  18 },  {    0,   0,   0,   0 } } },  /* 19: M PUNCH B, UP P GUARD P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { {  -55,  30,  38,  35 },  {    0,   0,   0,   0 } } },  /* 22: L PUNCH A, UP P GUARD P L */
    { { {  -58,  33,  41,  56 },  {    0,   0,   0,   0 } } },  /* 23: L PUNCH A, UP P GUARD P L */
    { { {  -49,  46,  57,  54 },  {    0,   0,   0,   0 } } },  /* 24: L PUNCH A, UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {  -57,  33,  74,  14 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -42,  62,  63,  33 },  {    0,   0,   0,   0 } } },  /* 27: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -71,  47,  11,  44 },  {    0,   0,   0,   0 } } },  /* 31: S KICK A, M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: no box */
    { { {  -49,  50,  60,  12 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: no box */
    { { {  -78,  52,  11,  44 },  {    0,   0,   0,   0 } } },  /* 37: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {  -82,  82,  55,  19 },  {    0,   0,   0,   0 } } },  /* 40: not used by a script */
    { { {  -51,  45,  42,  22 },  {    0,   0,   0,   0 } } },  /* 41: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { {  -55,  19,  57,  27 },  {    0,   0,   0,   0 } } },  /* 46: L KICK A */
    { { {  -72,  31,  46,  38 },  {    0,   0,   0,   0 } } },  /* 47: L KICK A */
    { { {  -72,  38,  31,  50 },  {    0,   0,   0,   0 } } },  /* 48: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {  -57,  45,  42,  35 },  {    0,   0,   0,   0 } } },  /* 53: L KICK B, follow-up of M PUNCH A */
    { { {  -75,  49,  42,  35 },  {    0,   0,   0,   0 } } },  /* 54: L KICK B, follow-up of M PUNCH A */
    { { {  -79,  51,  42,  46 },  {    0,   0,   0,   0 } } },  /* 55: L KICK B, follow-up of M PUNCH A */
    { { {  -53,  44,  26,  47 },  {    0,   0,   0,   0 } } },  /* 56: L KICK B, follow-up of M PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -32,  38,  65,  11 },  {    0,   0,   0,   0 } } },  /* 61: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {  -61,  52,  43,   9 },  {    0,   0,   0,   0 } } },  /* 64: KAGAMI P A */
    { { {  -57,  45,  38,  17 },  {    0,   0,   0,   0 } } },  /* 65: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {  -52,  24,  27,  33 },  {    0,   0,   0,   0 } } },  /* 67: KAGAMI P A */
    { { {  -43,  43,  40,  76 },  {    0,   0,   0,   0 } } },  /* 68: KAGAMI P A */
    { { {  -35,  33,  51,  59 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {  -88,  62,   0,  28 },  {    0,   0,   0,   0 } } },  /* 74: KAGAMI K A, UP P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {  -97,  42,   0,  32 },  {    0,   0,   0,   0 } } },  /* 77: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no box */
    { { {  -71,  53,  82,  32 },  {    0,   0,   0,   0 } } },  /* 80: V JUMP P L A */
    { { {  -90,  64,  47,  33 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {  -72,  47,  44,  37 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K M A, F JUMP K L A */
    { { {  -74,  68,  70,  24 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP K L A, ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {  -64,  22,  55,  23 },  {    0,   0,   0,   0 } } },  /* 86: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {  -72, 101,  48,  38 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: no box */
    { { {  -40,  25,  69,  19 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -72,  48,  59,  27 },  {    0,   0,   0,   0 } } },  /* 96: F JUMP P L A, ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {  -57,  56,  56,  16 },  {    0,   0,   0,   0 } } },  /* 97: not used by a script */
    { { {  -13,  56,  55,  16 },  {    0,   0,   0,   0 } } },  /* 98: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: no box */
    { { {  -64,  32,  64,  16 },  {    0,   0,   0,   0 } } },  /* 103: not used by a script */
    { { {  -60,  28,  46,  16 },  {    0,   0,   0,   0 } } },  /* 104: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: no box */
    { { {  -50,  26,  63,  26 },  {    0,   0,   0,   0 } } },  /* 107: not used by a script */
    { { {  -43,  25,  51,  23 },  {    0,   0,   0,   0 } } },  /* 108: M PUNCH A, FUSHIN P S */
    { { {  -46,  16,  74,  18 },  {    0,   0,   0,   0 } } },  /* 109: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {  -72,  41,  71,  15 },  {    0,   0,   0,   0 } } },  /* 111: not used by a script */
    { { {  -52,  18,  51,  26 },  {    0,   0,   0,   0 } } },  /* 112: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: no box */
    { { {  -59,  41,  78,  10 },  {    0,   0,   0,   0 } } },  /* 114: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: no box */
    { { {  -45,  51,  71,  53 },  {    0,   0,   0,   0 } } },  /* 118: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -89,  71,  35,  43 },  {    0,   0,   0,   0 } } },  /* 119: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 126: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 127: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {  -48,  40,  72,  16 },  {    0,   0,   0,   0 } } },  /* 129: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 133: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 135: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 136: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 137: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 138: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 139: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 140: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 141: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 142: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 143: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 144: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 145: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 146: no box */
    { { {  -79,  59,  64,  18 },  {    0,   0,   0,   0 } } },  /* 147: M PUNCH B, UP P GUARD P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 148: no box */
    { { {  -36,  17,  56,  28 },  {    0,   0,   0,   0 } } },  /* 149: L PUNCH C, follow-up of L PUNCH A */
    { { {  -55,  17,  36,  28 },  {    0,   0,   0,   0 } } },  /* 150: L PUNCH C, follow-up of L PUNCH A */
    { { {  -60,  25,  29,  28 },  {    0,   0,   0,   0 } } },  /* 151: L PUNCH C, follow-up of L PUNCH A */
    { { {  -46,  25,  36,  28 },  {    0,   0,   0,   0 } } },  /* 152: L PUNCH C, follow-up of L PUNCH A */
    { { {  -76,  69,  47,  33 },  {    0,   0,   0,   0 } } },  /* 153: V JUMP K M A */
    { { {  -62,  43,  53,  30 },  {    0,   0,   0,   0 } } },  /* 154: V JUMP P M A, F JUMP P M A */
    { { {  -72,  48,  54,  32 },  {    0,   0,   0,   0 } } },  /* 155: V JUMP P M A, F JUMP P M A */
    { { {  -84,  71,  47,  43 },  {    0,   0,   0,   0 } } },  /* 156: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) +2 */
};

const HOSEI_BOX sean_hos_box[28] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   84 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +129 */
    { {  -25,   50,    0,   53 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +60 */
    { {  -25,   50,   48,   40 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP K S A +17 */
    { {  -25,   50,   48,   40 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +21 */
    { {  -46,   80,    0,   70 } },  /* 5: ATTACK 4 S: SA I 23623+P (plain script) */
    { {  -20,   37,   35,   54 } },  /* 6: not used by a script */
    { {  -37,   37,   35,   54 } },  /* 7: not used by a script */
    { {    6,   47,   35,   54 } },  /* 8: not used by a script */
    { {  -14,   62,   49,   33 } },  /* 9: not used by a script */
    { {  -28,   53,   36,   44 } },  /* 10: TOUKETSU A */
    { {   -4,   56,   35,   48 } },  /* 11: not used by a script */
    { {   -4,   56,   35,   48 } },  /* 12: not used by a script */
    { {  -16,   47,   23,   37 } },  /* 13: not used by a script */
    { {  -16,   47,   13,   37 } },  /* 14: not used by a script */
    { {  -24,   47,   23,   37 } },  /* 15: not used by a script */
    { {  -20,   51,   45,   49 } },  /* 16: not used by a script */
    { {  -18,   45,   48,   45 } },  /* 17: ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command, ATTACK 9 L: not started by a command +5 */
    { {  -27,   47,   52,   45 } },  /* 18: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +8 */
    { {  -38,   63,    0,   80 } },  /* 19: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -25,   50,   48,   40 } },  /* 20: AIR S, AIR M, AIR L +42 */
    { {  -43,   42,    9,   48 } },  /* 21: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { {   -8,   48,   48,   32 } },  /* 22: not used by a script */
    { {  -46,   80,    0,   70 } },  /* 23: ATTACK 4 S: SA I 23623+P (plain script), FUSHIN P S, ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { {  -20,   71,    0,   56 } },  /* 24: not used by a script */
    { {  -28,   44,   48,   47 } },  /* 25: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,    0,   30 } },  /* 26: dmca 97, OKIAGARI P S, NEKOROBI S +1 */
    { {  -25,   50,   24,   40 } },  /* 27: PARING AIR F, PARING AIR B */
};
