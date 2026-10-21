/*
 * NECRO_HITBOX.C  Necro's hit boxes
 *
 * Each of Necro's animation frames names an entry of necro_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX necro_hit_ix_table[195] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +20 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +112 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +24 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +1 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 4: JUMP FRONT, SP JUMP FRONT */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 5: SP JUMP FRONT */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 6: JUMP FRONT, JUMP VERTICAL, S JUMP FRONT +9 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 7: JUMP FRONT, JUMP VERTICAL, JUMP BACK +5 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 8: JUMP BACK, SP JUMP BACK, PARING AIR F +3 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 9: JUMP BACK, SP JUMP BACK, TUKAMIHAZUSI */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 10: SP JUMP BACK */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 11: JUMP BACK, SP JUMP BACK, TUKAMIHAZUSI */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 12: S PUNCH C */
    {   13,   13,    0,    1,    1,    1,    0,    9 },  /* 13: S PUNCH C */
    {   13,   13,    0,    0,    1,    0,    0,    9 },  /* 14: S PUNCH C */
    {   91,   91,    0,    0,    1,    0,    0,    9 },  /* 15: S PUNCH C */
    {   14,   14,    0,    0,    1,    0,    0,    9 },  /* 16: nmca 33, S PUNCH C */
    {   15,   15,    0,    2,    1,    2,    0,    1 },  /* 17: S PUNCH A */
    {   15,   15,    0,    0,    1,    0,    0,    1 },  /* 18: S PUNCH A */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 19: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    {   17,   17,    0,    3,    1,    3,    0,    1 },  /* 20: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    {   97,   97,    0,    0,    1,    0,    0,    1 },  /* 21: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 22: KAGAMI P C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 23: KAGAMI P C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 24: KAGAMI P C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 25: KAGAMI P C */
    {  124,   12,    0,    0,    1,    0,    0,    1 },  /* 26: ATTACK 10 SP: not started by a command */
    {   22,   22,    0,    0,    1,    0,    0,    1 },  /* 27: KAGAMI P C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 28: KAGAMI P C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 29: KAGAMI P C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 30: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 31: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    {   27,    0,    0,    0,    1,    0,    0,    1 },  /* 32: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    {   28,   28,    0,    0,    1,    0,    0,    1 },  /* 33: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    {   29,   29,    0,    5,    1,    5,    0,    1 },  /* 34: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    {   29,   29,    0,    0,    1,    0,    0,    1 },  /* 35: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    {    1,   30,    0,    0,    1,    6,    0,    1 },  /* 36: S KICK C */
    {    1,   30,    0,    0,    1,    0,    0,    1 },  /* 37: S KICK C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 38: S KICK A */
    {   32,   32,    0,    7,    1,    7,    0,    1 },  /* 39: S KICK A */
    {   32,   32,    0,    0,    1,    0,    0,    1 },  /* 40: S KICK A */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 41: M KICK C */
    {   34,   34,    0,    8,    1,    8,    0,    1 },  /* 42: M KICK C */
    {   34,   34,    0,    0,    1,    0,    0,    1 },  /* 43: M KICK C */
    {   35,   35,    0,    9,    1,    9,    0,    1 },  /* 44: M KICK A, UP P GUARD K S, D P GUARD K S */
    {   35,   35,    0,    0,    1,    0,    0,    1 },  /* 45: M KICK A, UP P GUARD K S, D P GUARD K S */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 46: L KICK C */
    {   37,   37,    0,    0,    1,    0,    0,    1 },  /* 47: L KICK C */
    {   38,   38,    0,   10,    1,   10,    0,    1 },  /* 48: L KICK C */
    {   38,   38,    0,    0,    1,    0,    0,    1 },  /* 49: L KICK C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 50: L KICK A */
    {   40,   40,    0,    0,    1,    0,    0,    1 },  /* 51: L KICK A */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 52: L KICK A */
    {   42,   42,    0,   11,    1,   11,    0,    1 },  /* 53: L KICK A */
    {   42,   42,    0,    0,    1,    0,    0,    1 },  /* 54: L KICK A */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 55: L KICK A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 56: KAGAMI P A */
    {   46,   46,    0,   12,   13,   12,    0,    2 },  /* 57: KAGAMI P A */
    {   46,   46,    0,    0,   13,    0,    0,    2 },  /* 58: KAGAMI P A */
    {   47,   47,    0,   13,    2,   13,    0,    2 },  /* 59: KAGAMI P A */
    {   47,   47,    0,    0,    2,    0,    0,    2 },  /* 60: KAGAMI P A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 61: KAGAMI P A */
    {   49,   49,    0,    0,    2,    0,    0,    2 },  /* 62: KAGAMI P A */
    {   50,   50,    0,    0,    2,    0,    0,    2 },  /* 63: KAGAMI P A */
    {   51,   51,    0,    0,    2,    0,    0,    2 },  /* 64: KAGAMI P A */
    {   52,   52,    0,    0,    2,    0,    0,    2 },  /* 65: KAGAMI P A */
    {   53,   53,    0,   14,    9,   14,    0,   18 },  /* 66: KAGAMI P A */
    {   53,   53,    0,    0,    9,    0,    0,   18 },  /* 67: KAGAMI P A */
    {   52,   52,    0,    0,    9,    0,    0,   18 },  /* 68: KAGAMI P A */
    {   54,   54,    0,   15,   13,   15,    0,    2 },  /* 69: KAGAMI K A */
    {   54,   54,    0,    0,   13,    0,    0,    2 },  /* 70: KAGAMI K A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 71: KAGAMI K A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 72: KAGAMI K A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 73: KAGAMI K A */
    {   58,   58,    0,    0,    2,    0,    0,    2 },  /* 74: KAGAMI K A */
    {   58,   58,    0,    0,    2,    0,    0,    2 },  /* 75: KAGAMI K A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 76: KAGAMI K A */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 77: KAGAMI K A */
    {   61,   61,    0,    0,    2,    0,    0,    2 },  /* 78: not used by a script */
    {   62,   62,    0,   17,    2,   17,    0,    2 },  /* 79: KAGAMI K A */
    {  102,  102,    0,    0,    2,    0,    0,    2 },  /* 80: KAGAMI K A */
    {   63,   63,    0,    0,    2,    0,    0,    2 },  /* 81: KAGAMI K A */
    {   64,   64,    0,    0,    2,    0,    0,    2 },  /* 82: KAGAMI K A */
    {    1,    1,    0,   18,    1,   18,    0,    1 },  /* 83: KAGAMI P C */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 84: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 85: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1 */
    {   67,   67,    0,   19,    3,   19,    0,    3 },  /* 86: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1 */
    {   67,   67,    0,    0,    3,    0,    0,    3 },  /* 87: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 88: V JUMP P S A, V JUMP P M A, V JUMP P L A +3 */
    {   69,   69,    0,   20,    3,   20,    0,    3 },  /* 89: V JUMP P S A */
    {   69,   69,    0,    0,    3,    0,    0,    3 },  /* 90: V JUMP P S A */
    {   70,   70,    0,   45,    3,   45,    0,    3 },  /* 91: V JUMP P M A */
    {   70,   70,    0,    0,    3,    0,    0,    3 },  /* 92: V JUMP P M A */
    {   71,   71,    0,   21,    3,   21,    0,    3 },  /* 93: V JUMP P L A, F JUMP P L A */
    {   71,   71,    0,    0,    3,    0,    0,    3 },  /* 94: V JUMP P L A, F JUMP P L A */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 95: V JUMP K S A, V JUMP K L A, F JUMP P S A +3 */
    {  115,  115,    0,   22,    3,   22,    0,    3 },  /* 96: V JUMP K S A, F JUMP K S A */
    {   73,   73,    0,    0,    3,    0,    0,    3 },  /* 97: V JUMP K L A */
    {   74,   74,    0,   23,    3,   23,    0,    6 },  /* 98: V JUMP K L A */
    {   75,   75,    0,   34,    3,   34,    0,    6 },  /* 99: V JUMP K L A */
    {   76,   76,    0,    0,    3,    0,    0,    3 },  /* 100: V JUMP P L A, F JUMP P L A */
    {   77,   77,    0,   24,    3,   24,    0,    3 },  /* 101: F JUMP P S A */
    {   77,   77,    0,    0,    3,    0,    0,    3 },  /* 102: F JUMP P S A */
    {   78,   78,    0,    0,    3,   56,    0,    3 },  /* 103: F JUMP P M A */
    {   78,   78,    0,    0,    3,    0,    0,    3 },  /* 104: F JUMP P M A */
    {   79,   79,    0,    0,    3,    0,    0,    3 },  /* 105: V JUMP K S B, F JUMP K M A, F JUMP K L A */
    {   80,   80,    0,    0,    3,   25,    0,    3 },  /* 106: F JUMP K M A */
    {   80,   80,    0,    0,    3,   26,    0,    3 },  /* 107: F JUMP K M A */
    {   80,   80,    0,    0,    3,    0,    0,    3 },  /* 108: F JUMP K M A */
    {    1,    1,    0,    0,    3,    0,    0,    3 },  /* 109: not used by a script */
    {   82,    0,    0,    0,    3,   54,    0,    3 },  /* 110: F JUMP K L A */
    {   82,   82,    0,    0,    3,   54,    0,    3 },  /* 111: F JUMP K L A */
    {   82,   82,    0,    0,    3,    0,    0,    3 },  /* 112: F JUMP K L A */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 113: GUARD HEAD, GUARD UP, P BREAK ZUJOU +1 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 114: PARING DOWN, GUARD DOWN, P BREAK DOWN */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 115: TATAKI S, KGM TATAKI S, OKIAGARI +18 */
    {   85,   85,    0,    0,    0,    0,    0,    2 },  /* 116: not used by a script */
    {  121,  121,    0,    0,    1,    0,    0,    1 },  /* 117: FUSHIN P S, OKIAGARI P S, ATTACK 7 S: not started by a command +4 */
    {    1,    1,    0,   27,    1,   27,    0,    1 },  /* 118: FUSHIN P S */
    {  108,  108,    0,   28,    1,   28,    0,    1 },  /* 119: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +1 */
    {  109,  109,    0,   29,    1,   29,    0,    1 },  /* 120: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +1 */
    {    1,    1,    0,   30,    1,    0,    0,    1 },  /* 121: M PUNCH A, M PUNCH C, M KICK A +3 */
    {   87,    1,    0,    0,    2,    0,    0,    2 },  /* 122: CATCH 5, ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command +1 */
    {   88,    1,    0,    0,    2,    0,    0,    2 },  /* 123: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    {   89,    1,    0,    0,    2,    0,    0,    2 },  /* 124: CATCH 5, ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command +1 */
    {   90,   90,    0,   31,    2,   31,    0,    2 },  /* 125: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 126: M PUNCH C */
    {   92,   92,    0,   32,    1,   32,    0,    1 },  /* 127: M PUNCH C */
    {   93,   93,    0,    0,    1,    0,    0,    1 },  /* 128: M PUNCH C */
    {   95,   95,    0,    0,    1,    0,    0,    1 },  /* 129: M PUNCH C */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 130: M PUNCH C */
    {   96,   96,    0,    0,    1,    0,    0,    1 },  /* 131: S PUNCH A, ATTACK 7 S: not started by a command */
    {   98,   98,    0,    0,   13,    0,    0,    2 },  /* 132: KAGAMI P A */
    {   99,   99,    0,    0,   13,    0,    0,    2 },  /* 133: KAGAMI K A */
    {  103,    0,    0,    0,    2,    0,    0,    2 },  /* 134: KAGAMI K A */
    {  103,  103,    0,    0,    2,    0,    0,    2 },  /* 135: KAGAMI K A */
    {  103,  103,    0,    0,    2,   33,    0,    2 },  /* 136: KAGAMI K A */
    {    3,    3,    0,    0,    3,    0,    0,    3 },  /* 137: V JUMP K M A, V JUMP K L A */
    {  100,  100,    0,    0,    3,    0,    0,    3 },  /* 138: V JUMP K L A */
    {  101,  101,    0,    0,    9,    0,    0,   18 },  /* 139: KAGAMI P A */
    {  104,  104,    0,   35,   15,   35,    0,    1 },  /* 140: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {  105,  105,    0,   36,   15,   36,    0,    1 },  /* 141: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {  106,  106,    0,   37,    1,   37,    0,    1 },  /* 142: ATTACK 3 L: not started by a command */
    {  106,  106,    0,   38,    1,   38,    0,    1 },  /* 143: ATTACK 3 L: not started by a command */
    {  111,  111,    0,   39,    1,   39,    0,    1 },  /* 144: ATTACK 4 S: not started by a command */
    {  111,  111,    0,   40,    1,   40,    0,    1 },  /* 145: ATTACK 4 S: not started by a command */
    {   68,   68,    0,    0,   14,    0,    0,   22 },  /* 146: DASH HUMIKOMI, DASH TOBINOKI, P BREAK ZUJOU +1 */
    {  107,  107,    0,    0,   12,    0,    0,   23 },  /* 147: AIR S, AIR M, AIR L +39 */
    {    1,    1,    0,   41,    1,    0,    0,    1 },  /* 148: ATTACK 7 S: not started by a command */
    {  108,  108,    0,    0,    1,    0,    0,    1 },  /* 149: not used by a script */
    {  109,  109,    0,   42,    1,   42,    0,    1 },  /* 150: not used by a script */
    {  113,  113,    0,   43,    1,   43,    0,    1 },  /* 151: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,   24 },  /* 152: OKIAGARI P S */
    {  110,  110,    0,    0,    2,    0,    0,   24 },  /* 153: OKIAGARI P S, ATTACK 7 S: not started by a command, ATTACK 9 L: not started by a command +3 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 154: ATTACK 1 S: not started by a command, ATTACK 4 S: not started by a command, ATTACK 7 S: not started by a command */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 155: not used by a script */
    {  112,  112,    0,    0,    1,    0,    0,    1 },  /* 156: KAGAMI P C */
    {    1,    1,    0,   46,    1,   46,    0,    1 },  /* 157: L PUNCH A, L KICK A, L KICK C */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 158: AIR S, AIR M, AIR L +2 */
    {   62,   62,    0,    0,    2,    0,    0,    2 },  /* 159: KAGAMI K A */
    {  114,  114,    0,   47,    1,   47,    0,    1 },  /* 160: KAGAMI P C */
    {  116,  116,    0,    0,    1,    0,    0,    1 },  /* 161: ATTACK 1 S: not started by a command */
    {  117,  117,    0,   48,    3,   48,    0,    3 },  /* 162: ATTACK 8 L: not started by a command */
    {  118,  118,    0,    0,   15,    0,    0,    1 },  /* 163: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    {  119,  119,    0,    0,    1,    0,    0,    2 },  /* 164: PIYO */
    {   17,   17,    0,    0,    1,    0,    0,    1 },  /* 165: M PUNCH A, follow-up of S KICK A, S KICK C */
    {   90,   90,    0,   49,    2,   49,    0,    2 },  /* 166: not used by a script */
    {   90,   90,    0,   50,    2,   50,    0,    2 },  /* 167: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,   24 },  /* 168: NEKOROBI S, dmca 96 */
    {  106,  106,    0,   51,    1,   51,    0,    1 },  /* 169: ATTACK 3 S: not started by a command */
    {  106,  106,    0,   51,    1,   51,    0,    1 },  /* 170: not used by a script */
    {  106,  106,    0,   52,    1,   52,    0,    1 },  /* 171: ATTACK 3 M: not started by a command */
    {  106,  106,    0,   52,    1,   52,    0,    1 },  /* 172: not used by a script */
    {  120,  120,    0,    0,    2,    0,    0,    2 },  /* 173: OKIAGARI P S, ATTACK 7 S: not started by a command, ATTACK 9 L: not started by a command +3 */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 174: follow-up of SP APPEAR 6 */
    {    2,    2,    0,    0,    0,    0,    0,    2 },  /* 175: follow-up of SP APPEAR 6 */
    {  106,  106,    0,    0,    1,    0,    0,    1 },  /* 176: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 177: LOSE SONABA */
    {   90,   90,    0,    0,    2,    0,    0,    2 },  /* 178: CATCH 5, ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command +1 */
    {   25,    4,    0,    0,    3,    0,    0,    3 },  /* 179: V JUMP K M A */
    {   25,    5,    0,    0,    3,   53,    0,    3 },  /* 180: V JUMP K M A */
    {   25,    6,    0,    0,    3,   53,    0,    3 },  /* 181: V JUMP K M A */
    {   25,    6,    0,    0,    3,    0,    0,    3 },  /* 182: V JUMP K M A */
    {   25,    0,    0,    0,    3,    0,    0,    3 },  /* 183: not used by a script */
    {   26,    0,    0,    0,   16,   55,    0,   25 },  /* 184: V JUMP K S B */
    {   26,    0,    0,    0,   16,    0,    0,   25 },  /* 185: V JUMP K S B */
    {  122,  112,    0,    0,    1,   30,    0,    1 },  /* 186: KAGAMI P C */
    {  123,    0,    0,    0,    1,    0,    0,    1 },  /* 187: M KICK A */
    {  124,   12,    0,    0,    1,   41,    0,    1 },  /* 188: ATTACK 10 SP: not started by a command */
    {  125,    0,    0,    0,    0,    0,    0,   24 },  /* 189: dmca 97 */
    {  126,    0,    0,    0,    1,    0,    0,    1 },  /* 190: ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command, ATTACK 10 S: not started by a command +1 */
    {   67,    0,    0,   19,    3,   19,    0,    3 },  /* 191: ATTACK 6 SP: not started by a command */
    {  108,    0,    0,   28,    1,   28,    0,    1 },  /* 192: ATTACK 10 M: not started by a command */
    {  109,    9,    0,   29,    1,   29,    0,    1 },  /* 193: ATTACK 10 M: not started by a command */
    {  127,    0,    0,   35,   15,   35,    0,    1 },  /* 194: ATTACK 2 SP: not started by a command */
};

const BODY_BOX necro_body_box[128] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +115 */
    { { {  -33,  21,  47,  18 },  {  -14,  52,  50,  16 },  {  -33,  71,  25,  26 },  {  -39,  78,   0,  28 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +27 */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +26 */
    { { {  -47,  25,  79,  17 },  {  -40,  48,  83,  18 },  {  -32,  46,  73,  41 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {    0,   0,   0,   0 },  {  -40,  48,  83,  18 },  {  -32,  46,  55,  41 },  {    0,   0,   0,   0 } } },  /* 5: not used by a script */
    { { {  -15,  25,  95,  17 },  {  -23,  48,  89,  18 },  {  -23,  46,  48,  41 },  {    0,   0,   0,   0 } } },  /* 6: not used by a script */
    { { {  -16,  21,  99,  14 },  {  -29,  47,  91,  18 },  {  -26,  41,  71,  23 },  {    0,   0,   0,   0 } } },  /* 7: not used by a script */
    { { {    4,  25, 100,  17 },  {   -7,  48,  95,  18 },  {  -15,  33,  69,  41 },  {    0,   0,   0,   0 } } },  /* 8: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -33,  44,  73,  52 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -29,  46,  59,  41 },  {    0,   0,   0,   0 } } },  /* 10: not used by a script */
    { { {  -19,  25, 100,  17 },  {  -28,  48,  88,  18 },  {  -27,  46,  50,  41 },  {    0,   0,   0,   0 } } },  /* 11: not used by a script */
    { { {  -16,  24,  76,  18 },  {  -30,  58,  60,  26 },  {  -20,  44,  40,  24 },  {  -20,  54,   0,  38 } } },  /* 12: not used by a script */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 13: S PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -30,  58,  60,  26 },  {  -20,  44,  40,  24 },  {  -20,  54,   0,  38 } } },  /* 14: nmca 33, S PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 15: S PUNCH A */
    { { {  -31,  25,  71,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 16: not used by a script */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 17: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    { { {    2,  25,  76,  17 },  {   -2,  48,  67,  18 },  {    6,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 18: not used by a script */
    { { {   16,  25,  48,  17 },  {  -20,  48,  43,  18 },  {  -39,  46,  24,  24 },  {  -38,  44,   0,  23 } } },  /* 19: not used by a script */
    { { {   -6,  25,  60,  17 },  {  -20,  48,  43,  18 },  {  -39,  46,  24,  24 },  {  -38,  44,   0,  23 } } },  /* 20: not used by a script */
    { { {  -11,  25,  66,  17 },  {  -27,  48,  53,  18 },  {  -38,  46,  29,  24 },  {  -38,  44,   0,  29 } } },  /* 21: not used by a script */
    { { {  -36,  26,  96,  31 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 22: KAGAMI P C */
    { { {    0,  25,  81,  17 },  {   -9,  48,  70,  18 },  {   -9,  46,  33,  38 },  {  -10,  44,   0,  45 } } },  /* 23: not used by a script */
    { { {  -21,  25,  81,  17 },  {  -24,  48,  70,  18 },  {  -22,  46,  33,  38 },  {  -24,  44,   0,  45 } } },  /* 24: not used by a script */
    { { {  -29,  61,  93,  25 },  { -121, 155,  77,  24 },  {  -47,  79,  60,  22 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP K M A */
    { { {   25,  41,  66,  38 },  {  -18,  69,  55,  41 },  {  -61,  60,  40,  49 },  {  -85,  46,  33,  42 } } },  /* 26: V JUMP K S B */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -43,  82,   0,  40 } } },  /* 27: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -45,  84,   0,  40 } } },  /* 28: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -45,  84,   0,  40 } } },  /* 29: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    { { {  -31,  25,  71,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -51,  75,   0,  39 } } },  /* 30: not used by a script */
    { { {    1,  25,  71,  17 },  {   10,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 31: not used by a script */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 32: S KICK A */
    { { {  -19,  25,  89,  17 },  {  -21,  48,  79,  18 },  {  -19,  46,  41,  36 },  {  -19,  44,   0,  39 } } },  /* 33: not used by a script */
    { { {  -19,  25,  89,  17 },  {  -21,  48,  79,  18 },  {  -66,  92,  37,  39 },  {  -30,  65,   0,  38 } } },  /* 34: M KICK C */
    { { {  -31,  25,  71,  17 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 35: M KICK A, UP P GUARD K S, D P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 36: not used by a script */
    { { {   10,  25,  95,  17 },  {  -22,  74,  73,  29 },  {  -19,  46,  41,  45 },  {  -19,  44,   0,  39 } } },  /* 37: L KICK C */
    { { {   10,  25,  95,  17 },  {  -44,  91,  73,  29 },  {  -19,  46,  41,  45 },  {  -19,  44,   0,  39 } } },  /* 38: L KICK C */
    { { {  -11,  25,  83,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 39: not used by a script */
    { { {    9,  25,  88,  21 },  {   -4,  75,  79,  18 },  {  -19,  46,  55,  24 },  {  -19,  44,   0,  53 } } },  /* 40: L KICK A */
    { { {    9,  25,  88,  21 },  {  -18,  75,  79,  20 },  {  -91, 118,  52,  33 },  {  -19,  44,   0,  53 } } },  /* 41: L KICK A */
    { { {    9,  25,  88,  21 },  {  -18,  75,  79,  18 },  {  -23,  49,  55,  24 },  {  -19,  44,   0,  53 } } },  /* 42: L KICK A */
    { { {    1,  25,  87,  17 },  {  -18,  75,  79,  18 },  {  -23,  49,  55,  24 },  {  -19,  44,   0,  53 } } },  /* 43: not used by a script */
    { { {  -31,  25,  87,  17 },  {  -21,  48,  79,  18 },  {  -19,  45,  55,  24 },  {  -18,  44,   0,  53 } } },  /* 44: not used by a script */
    { { {  -16,  25,  55,  17 },  {  -21,  48,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 45: not used by a script */
    { { {  -28,  40,  60,  18 },  {  -47,  88,  44,  27 },  {  -24,  60,  24,  20 },  {  -49,  90,   0,  28 } } },  /* 46: KAGAMI P A */
    { { {  -61,  45,  49,  36 },  {  -31,  67,  44,  36 },  {  -41,  80,  24,  22 },  {  -49,  92,   0,  28 } } },  /* 47: KAGAMI P A */
    { { {  -16,  25,  55,  17 },  {  -38,  68,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 48: not used by a script */
    { { {   -9,  37,  64,  19 },  {  -27,  79,  45,  25 },  {  -40,  71,  26,  24 },  {  -50,  87,   0,  26 } } },  /* 49: KAGAMI P A */
    { { {   -9,  37,  64,  19 },  {  -27,  79,  45,  25 },  {  -40,  71,  26,  24 },  {  -50,  87,   0,  26 } } },  /* 50: KAGAMI P A */
    { { {  -25,  37,  61,  19 },  {  -52,  77,  45,  28 },  {  -56,  69,  26,  24 },  {  -55,  77,   0,  26 } } },  /* 51: KAGAMI P A */
    { { {  -25,  37,  61,  19 },  {  -52,  77,  45,  28 },  {  -56,  69,  26,  24 },  {  -55,  77,   0,  26 } } },  /* 52: KAGAMI P A */
    { { {  -54,  25,  68,  18 },  {  -84,  74,  52,  29 },  {  -84,  74,  26,  24 },  {  -84, 112,   0,  26 } } },  /* 53: KAGAMI P A */
    { { {  -41,  28,  42,  24 },  {  -13,  52,  44,  27 },  {  -67, 106,  24,  26 },  {  -28,  67,   0,  28 } } },  /* 54: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {  -21,  48,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 55: not used by a script */
    { { {   26,  25,  35,  17 },  {  -21,  48,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 56: not used by a script */
    { { {  -63,  25,  33,  17 },  {  -60,  48,  45,  18 },  {  -36,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 57: not used by a script */
    { { {  -81,  65,  33,  19 },  {  -60,  52,  42,  28 },  {  -36,  71,  26,  34 },  {  -39, 138,   0,  34 } } },  /* 58: KAGAMI K A */
    { { {  -51,  25,  24,  17 },  {  -45,  48,  34,  18 },  {  -23,  46,  24,  24 },  {  -19,  44,   0,  26 } } },  /* 59: not used by a script */
    { { {    0,   0,   0,   0 },  {  -17,  48,  34,  18 },  {  -23,  46,  24,  24 },  {  -19,  44,   0,  26 } } },  /* 60: not used by a script */
    { { {    6,  25,  34,  17 },  {    2,  48,  25,  18 },  {  -24,  46,  17,  24 },  {  -19,  44,   0,  26 } } },  /* 61: not used by a script */
    { { {   26,  25,  51,  22 },  {   20,  75,  44,  22 },  {  -16,  80,   0,  42 },  {  -16,  43,   0,  42 } } },  /* 62: KAGAMI K A */
    { { {    6,  25,  64,  20 },  {  -20,  75,  57,  22 },  {  -17,  70,  38,  24 },  {  -59, 116,   0,  42 } } },  /* 63: KAGAMI K A */
    { { {  -29,  39,  64,  20 },  {  -30,  65,  54,  24 },  {  -30,  73,  38,  24 },  {  -34,  86,   0,  42 } } },  /* 64: KAGAMI K A */
    { { {  -31,  25, 104,  17 },  {  -35,  41,  90,  18 },  {  -17,  28,  55,  34 },  {    0,   0,   0,   0 } } },  /* 65: not used by a script */
    { { {  -48,  25,  91,  17 },  {  -35,  41,  90,  18 },  {  -17,  28,  55,  34 },  {    0,   0,   0,   0 } } },  /* 66: not used by a script */
    { { {  -48,  25,  91,  17 },  {  -35,  41,  90,  18 },  {  -80,  87,  55,  34 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1 */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -30,  65,  -8,  49 } } },  /* 68: DASH HUMIKOMI, DASH TOBINOKI, P BREAK ZUJOU +1 */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 69: V JUMP P S A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 70: V JUMP P M A */
    { { { -108,  80,  70,  27 },  {  -60,  65,  69,  34 },  {  -24,  49,  64,  47 },  {    0,   0,   0,   0 } } },  /* 71: V JUMP P L A, F JUMP P L A */
    { { {  -13,  25,  94,  17 },  {  -21,  48,  83,  18 },  {  -19,  46,  62,  29 },  {    0,   0,   0,   0 } } },  /* 72: not used by a script */
    { { {  -49,  50,  87,  34 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP K L A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K L A */
    { { {  -54,  85,  90,  29 },  {  -70, 100,  72,  27 },  {  -47,  78,  53,  36 },  {    0,   0,   0,   0 } } },  /* 76: V JUMP P L A, F JUMP P L A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 77: F JUMP P S A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 78: F JUMP P M A */
    { { {   16,  29,  94,  25 },  {  -25,  61,  56,  51 },  {  -55,  54,  37,  51 },  {    0,   0,   0,   0 } } },  /* 79: V JUMP K S B, F JUMP K M A, F JUMP K L A */
    { { {   15,  25,  94,  17 },  {  -37,  79,  82,  33 },  {  -57,  55,  63,  25 },  {  -68,  46,  27,  42 } } },  /* 80: F JUMP K M A */
    { { {  -10,  25,  94,  17 },  {  -37,  79,  82,  33 },  {  -57,  55,  63,  25 },  {    0,   0,   0,   0 } } },  /* 81: not used by a script */
    { { {   15,  25,  94,  17 },  {  -37,  79,  82,  33 },  {  -45,  62,  63,  25 },  {  -64,  73,  36,  30 } } },  /* 82: F JUMP K L A */
    { { {  -14,  25,  77,  17 },  {  -21,  48,  65,  18 },  {   -9,  27,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 83: not used by a script */
    { { {  -18,  25,  59,  17 },  {  -29,  48,  48,  18 },  {  -22,  36,  26,  24 },  {  -28,  44,   0,  26 } } },  /* 84: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -17,  39,   0,  35 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { {  -13,  25,  83,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 86: not used by a script */
    { { {  -20,  34,  64,  17 },  {  -29,  67,  58,  17 },  {  -29,  64,  38,  20 },  {  -37,  73,   0,  38 } } },  /* 87: CATCH 5, ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command +1 */
    { { {   -8,  45,  64,  17 },  {  -28,  79,  58,  17 },  {  -34,  72,  38,  20 },  {  -53,  90,   0,  38 } } },  /* 88: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    { { {  -32,  45,  64,  17 },  {  -40,  72,  57,  19 },  {  -42,  73,  38,  20 },  {  -50,  88,   0,  38 } } },  /* 89: CATCH 5, ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command +1 */
    { { {  -52,  33,  45,  18 },  {  -34,  74,  44,  28 },  {  -60,  89,  20,  27 },  {  -40,  83,   0,  28 } } },  /* 90: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command +1 */
    { { {  -64,  44,  58,  20 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 91: S PUNCH C */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 92: M PUNCH C */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 93: M PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 94: not used by a script */
    { { {  -64,  44,  58,  20 },  {  -30,  58,  60,  26 },  {  -20,  44,  40,  24 },  {  -20,  54,   0,  38 } } },  /* 95: M PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 96: S PUNCH A, ATTACK 7 S: not started by a command */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 97: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    { { {  -16,  25,  55,  17 },  {  -14,  52,  44,  22 },  {  -24,  60,  24,  20 },  {  -28,  67,   0,  28 } } },  /* 98: KAGAMI P A */
    { { {  -41,  28,  42,  24 },  {  -13,  52,  44,  27 },  {  -67, 106,  24,  26 },  {  -84, 112,   0,  28 } } },  /* 99: KAGAMI K A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 100: V JUMP K L A */
    { { {  -54,  25,  68,  18 },  {  -84,  74,  52,  29 },  {  -84,  74,  26,  24 },  {  -84, 112,   0,  26 } } },  /* 101: KAGAMI P A */
    { { {   26,  25,  51,  22 },  {   20,  75,  44,  22 },  {  -16,  80,   0,  42 },  {  -16,  43,   0,  42 } } },  /* 102: KAGAMI K A */
    { { {  -41,  28,  42,  24 },  {  -13,  52,  44,  27 },  {  -67, 106,  24,  26 },  {  -54,  93,   0,  28 } } },  /* 103: KAGAMI K A */
    { { {  -31,  25,  71,  17 },  {  -61,  86,  65,  18 },  {  -19,  46,  41,  24 },  {  -65,  91,   0,  39 } } },  /* 104: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -74,  64,  57,  20 },  {  -21,  48,  65,  18 },  {  -54,  83,  41,  24 },  {  -55,  84,   0,  39 } } },  /* 105: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -36,  25,  62,  28 },  {  -21,  48,  65,  18 },  {  -33,  60,  41,  24 },  {  -50, 104,   0,  44 } } },  /* 106: ATTACK 3 L: not started by a command, ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command */
    { { {  -24,  47,  72,  17 },  {  -27,  55,  62,  18 },  {  -27,  55,  34,  27 },  {    0,   0,   0,   0 } } },  /* 107: AIR S, AIR M, AIR L +39 */
    { { {  -47,  44,  82,  23 },  {  -29,  64,  72,  28 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 108: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +2 */
    { { {  -32,  33,  76,  19 },  {  -39,  75,  71,  19 },  {  -85, 121,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 109: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,  79,   0,  60 },  {    0,   0,   0,   0 } } },  /* 110: OKIAGARI P S, ATTACK 7 S: not started by a command, ATTACK 9 L: not started by a command +3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -19,  46,  41,  24 },  {  -42,  86,   0,  39 } } },  /* 111: ATTACK 4 S: not started by a command */
    { { {  -13,  25,  96,  17 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 112: KAGAMI P C */
    { { {   10,  25,  95,  17 },  {  -44,  91,  73,  29 },  {  -19,  46,  41,  45 },  {  -19,  44,   0,  39 } } },  /* 113: not used by a script */
    { { {  -26,  30,  96,  38 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 114: KAGAMI P C */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K S A, F JUMP K S A */
    { { {  -28,  24,  40,  30 },  {    4,  33,  71,  16 },  {  -10,  64,  40,  31 },  {  -24,  79,   0,  38 } } },  /* 116: ATTACK 1 S: not started by a command */
    { { {  -17,  21, 103,  16 },  {  -69,  94,  91,  27 },  {  -70,  96,  53,  36 },  {    0,   0,   0,   0 } } },  /* 117: ATTACK 8 L: not started by a command */
    { { {  -16,  24,  76,  18 },  {  -42,  89,  72,  16 },  {  -42,  88,  40,  31 },  {  -43,  89,   0,  38 } } },  /* 118: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    { { {  -33,  24,  48,  23 },  {  -29,  62,  60,  18 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 119: PIYO */
    { { {    0,   0,   0,   0 },  {   32,  44,  63,  30 },  {  -13,  81,  37,  29 },  {  -13,  96,   0,  37 } } },  /* 120: OKIAGARI P S, ATTACK 7 S: not started by a command, ATTACK 9 L: not started by a command +3 */
    { { {   -4,  39,  71,  36 },  {  -25,  37,  72,  56 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 121: FUSHIN P S, OKIAGARI P S, ATTACK 7 S: not started by a command +4 */
    { { {  -34,  30,  96,  39 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 122: KAGAMI P C */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -45,  81,   0,  38 } } },  /* 123: M KICK A */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -50,  85,   0,  38 } } },  /* 124: ATTACK 10 SP: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 125: dmca 97 */
    { { {    0,   0,   0,   0 },  {   -2,  44,  74,  35 },  {  -20,  84,  37,  37 },  {  -27, 107,   0,  37 } } },  /* 126: ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command, ATTACK 10 S: not started by a command +1 */
    { { {  -31,  25,  71,  17 },  {  -33,  62,  65,  18 },  {  -19,  46,  41,  24 },  {  -65,  91,   0,  39 } } },  /* 127: ATTACK 2 SP: not started by a command */
};

const HAND_BOX necro_hand_box[122] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {  -64,  38,  53,  37 },  {    0,   0,   0,   0 } } },  /* 3: V JUMP K M A, V JUMP K L A */
    { { { -167,  47,  98,  33 },  {    0,   0,   0,   0 } } },  /* 4: V JUMP K M A */
    { { { -130,  41,  92,  23 },  {    0,   0,   0,   0 } } },  /* 5: V JUMP K M A */
    { { { -140,  51,  92,  35 },  {    0,   0,   0,   0 } } },  /* 6: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: no box */
    { { {  -90,  67,  49,  41 },  {    0,   0,   0,   0 } } },  /* 12: ATTACK 10 SP: not started by a command */
    { { {  -92,  72,  42,  37 },  {    0,   0,   0,   0 } } },  /* 13: S PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: no box */
    { { { -128, 102,  57,  29 },  {    0,   0,   0,   0 } } },  /* 15: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: no box */
    { { { -102,  79,  73,  23 },  {    0,   0,   0,   0 } } },  /* 17: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { {   -3,  29,  97,  47 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: no box */
    { { {  -99,  72,  50,  34 },  {    0,   0,   0,   0 } } },  /* 28: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    { { { -148, 128,  50,  31 },  {    0,   0,   0,   0 } } },  /* 29: L PUNCH A, follow-up of follow-up of S KICK A, S KICK C */
    { { {  -63,  31,  20,  38 },  {    0,   0,   0,   0 } } },  /* 30: S KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {  -92,  71,  33,  35 },  {    0,   0,   0,   0 } } },  /* 32: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { { -132, 106,  23,  25 },  {    0,   0,   0,   0 } } },  /* 35: M KICK A, UP P GUARD K S, D P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -63,  39,  67,  59 },  {    0,   0,   0,   0 } } },  /* 38: L KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { { -126, 122,  58,  28 },  {    0,   0,   0,   0 } } },  /* 42: L KICK A */
    { { { -116, 102,  64,  19 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { { -121,  96,  29,  22 },  {    0,   0,   0,   0 } } },  /* 46: KAGAMI P A */
    { { { -103,  41,  85,  35 },  {    0,   0,   0,   0 } } },  /* 47: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { { -110,  48,  64,  25 },  {    0,   0,   0,   0 } } },  /* 53: KAGAMI P A */
    { { { -115,  91,   0,  33 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: no box */
    { { { -108,  95,   0,  51 },  {    0,   0,   0,   0 } } },  /* 62: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {  -96,  65,  20,  36 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 6 S: not started by a command, ATTACK 6 M: not started by a command, ATTACK 6 L: not started by a command +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: no box */
    { { { -119,  92,  95,  21 },  {    0,   0,   0,   0 } } },  /* 69: V JUMP P S A */
    { { { -127,  98,  97,  24 },  {    0,   0,   0,   0 } } },  /* 70: V JUMP P M A */
    { { { -140,  82,  46,  37 },  {    0,   0,   0,   0 } } },  /* 71: V JUMP P L A, F JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { { -118,  93,  56,  33 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A */
    { { { -130, 103,  54,  39 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {  -75,  58,  30,  45 },  {    0,   0,   0,   0 } } },  /* 77: F JUMP P S A */
    { { {  -71,  49,  29,  33 },  {    0,   0,   0,   0 } } },  /* 78: F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {  -52,  53,   0,  33 },  {    0,   0,   0,   0 } } },  /* 82: F JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {  -99,  39,  20,  25 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {  -88,  62,  56,  18 },  {    0,   0,   0,   0 } } },  /* 92: M PUNCH C */
    { { {  -92,  66,  56,  19 },  {    0,   0,   0,   0 } } },  /* 93: M PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {  -86,  64,  60,  24 },  {    0,   0,   0,   0 } } },  /* 96: S PUNCH A, ATTACK 7 S: not started by a command */
    { { {  -68,  48,  73,  16 },  {    0,   0,   0,   0 } } },  /* 97: M PUNCH A, follow-up of S KICK A, S KICK C, UP P GUARD P S +1 */
    { { {  -72,  48,  28,  16 },  {    0,   0,   0,   0 } } },  /* 98: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { { -118,  93,  56,  33 },  {    0,   0,   0,   0 } } },  /* 100: V JUMP K L A */
    { { {  -88,  29,  54,  32 },  {    0,   0,   0,   0 } } },  /* 101: KAGAMI P A */
    { { { -104, 105,   0,  41 },  {    0,   0,   0,   0 } } },  /* 102: KAGAMI K A */
    { { { -154, 134,   0,  34 },  {    0,   0,   0,   0 } } },  /* 103: KAGAMI K A */
    { { {  -66,  51,  43,  29 },  {    0,   0,   0,   0 } } },  /* 104: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -95,  85,  73,  20 },  {    0,   0,   0,   0 } } },  /* 105: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: no box */
    { { {  -84,  37,  96,  32 },  {    0,   0,   0,   0 } } },  /* 108: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +1 */
    { { { -106,  44,  21,  30 },  {    0,   0,   0,   0 } } },  /* 109: OKIAGARI P S, ATTACK 9 L: not started by a command, ATTACK 9 SP: not started by a command +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: no box */
    { { {  -16,  29,  93,  68 },  {    0,   0,   0,   0 } } },  /* 112: KAGAMI P C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: no box */
    { { {    5,  20,  96,  64 },  {    0,   0,   0,   0 } } },  /* 114: KAGAMI P C */
    { { {  -54,  45,  37,  43 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K S A, F JUMP K S A */
    { { {  -68,  39,   0,  41 },  {    0,   0,   0,   0 } } },  /* 116: ATTACK 1 S: not started by a command */
    { { {  -88,  67,  36,  31 },  {    0,   0,   0,   0 } } },  /* 117: ATTACK 8 L: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: no box */
};

const HOSEI_BOX necro_hos_box[26] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -27,   54,    0,   82 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +115 */
    { {  -27,   54,    0,   61 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +51 */
    { {  -25,   50,   68,   48 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +34 */
    { {  -35,   48,   72,   40 } },  /* 4: not used by a script */
    { {  -24,   48,   67,   40 } },  /* 5: not used by a script */
    { {  -31,   48,   70,   40 } },  /* 6: V JUMP K L A */
    { {  -22,   48,   70,   40 } },  /* 7: not used by a script */
    { {  -32,   48,   73,   40 } },  /* 8: not used by a script */
    { {  -21,   48,   30,   40 } },  /* 9: S PUNCH C, nmca 33 */
    { {   -1,   48,   37,   40 } },  /* 10: not used by a script */
    { {  -19,   48,   27,   40 } },  /* 11: not used by a script */
    { {  -32,   48,   31,   40 } },  /* 12: not used by a script */
    { {  -28,   48,   46,   56 } },  /* 13: not used by a script */
    { {  -11,   48,   32,   56 } },  /* 14: not used by a script */
    { {  -25,   48,   32,   56 } },  /* 15: not used by a script */
    { {   -4,   48,   58,   40 } },  /* 16: not used by a script */
    { {  -21,   48,   58,   40 } },  /* 17: not used by a script */
    { {  -55,   48,    0,   54 } },  /* 18: KAGAMI P A */
    { {  -72,   97,   22,   40 } },  /* 19: not used by a script */
    { {  -21,   27,   59,   43 } },  /* 20: not used by a script */
    { {  -43,   63,   61,   39 } },  /* 21: not used by a script */
    { {  -37,   64,    0,   79 } },  /* 22: DASH HUMIKOMI, DASH TOBINOKI, P BREAK ZUJOU +1 */
    { {  -22,   48,   42,   37 } },  /* 23: AIR S, AIR M, AIR L +39 */
    { {  -27,   54,    0,   30 } },  /* 24: OKIAGARI P S, ATTACK 7 S: not started by a command, ATTACK 9 L: not started by a command +6 */
    { {  -60,   96,   48,   27 } },  /* 25: V JUMP K S B */
};
