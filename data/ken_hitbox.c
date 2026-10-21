/*
 * KEN_HITBOX.C  Ken's hit boxes
 *
 * Each of Ken's animation frames names an entry of ken_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX ken_hit_ix_table[233] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +111 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +27 */
    {  123,  123,    0,    0,    0,    0,    0,    2 },  /* 3: OKIAGARI P S, ATTACK 2 S: not started by a command */
    {  123,  123,    0,    1,    0,    1,    0,    1 },  /* 4: not used by a script */
    {  134,  134,    0,    0,    0,   52,    0,    4 },  /* 5: ATTACK 5 S: not started by a command */
    {    3,    3,    0,    2,    3,    2,    0,    4 },  /* 6: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +3 */
    {    3,    3,    0,    0,    3,    0,    0,    4 },  /* 7: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +3 */
    {    4,    4,    0,    0,    3,    0,    0,    4 },  /* 8: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +4 */
    {    5,    5,    0,    0,   18,    0,    0,   21 },  /* 9: DASH HUMIKOMI, DASH TOBINOKI */
    {    6,    6,    0,    0,    1,    0,    0,    1 },  /* 10: DASH TOBINOKI */
    {    7,    0,    0,    0,    3,    0,    0,    3 },  /* 11: GUARD AIR, V JUMP P M A, V JUMP K S A +7 */
    {   96,   96,    0,    0,    3,   12,    0,    3 },  /* 12: F JUMP P L A */
    {    9,    9,    0,    0,    3,    0,    0,    3 },  /* 13: not used by a script */
    {   10,   10,    0,    0,    4,    0,    0,    4 },  /* 14: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    {   11,    0,    0,    0,    4,    0,    0,    4 },  /* 15: JUMP JUNBI, SP JUMP JUNBI, JUMP VERTICAL +8 */
    {   12,   12,    0,    0,    4,    0,    0,    4 },  /* 16: JUMP VERTICAL, S JUMP FRONT, SP JUMP V +3 */
    {   13,    0,    0,    0,    0,    0,    0,   27 },  /* 17: dmca 97 */
    {    1,   14,    0,    0,    1,   20,    0,    1 },  /* 18: ATTACK 10 M: not started by a command */
    {    1,   14,    0,    0,    1,    0,    0,    1 },  /* 19: ATTACK 10 M: not started by a command */
    {  109,  109,    0,    4,    1,    4,    0,    1 },  /* 20: S PUNCH A */
    {   16,   16,    0,    0,    1,    0,    0,    1 },  /* 21: S PUNCH A */
    {   17,   17,    0,    5,    1,    5,    0,    1 },  /* 22: S PUNCH B */
    {   17,   17,    0,    0,    1,    0,    0,    1 },  /* 23: S PUNCH B */
    {  110,  110,    0,    6,    1,    6,    0,    1 },  /* 24: M PUNCH A, UP P GUARD P M */
    {   18,    0,    0,    0,    1,    0,    0,    1 },  /* 25: L PUNCH A, follow-up of M PUNCH A, UP P GUARD P S */
    {   19,   19,    0,    7,    1,    7,    0,    1 },  /* 26: M PUNCH B, UP P GUARD P S */
    {   19,  135,    0,    0,    1,    0,    0,    1 },  /* 27: M PUNCH B, UP P GUARD P S */
    {   20,    0,    0,    0,    1,    0,    0,    1 },  /* 28: M PUNCH B, UP P GUARD P S */
    {   21,   21,    0,    0,    1,    0,    0,    1 },  /* 29: not used by a script */
    {   22,   22,    0,    8,    1,    8,    0,    1 },  /* 30: L PUNCH A, follow-up of M PUNCH A */
    {   23,   23,    0,    9,    1,    9,    0,    1 },  /* 31: L PUNCH A, follow-up of M PUNCH A */
    {   24,   24,    0,    0,    1,    0,    0,    1 },  /* 32: L PUNCH A, follow-up of M PUNCH A */
    {   25,   25,    0,    0,    1,    0,    0,    1 },  /* 33: L PUNCH B, UP P GUARD P L */
    {   26,   26,    0,   10,    1,   10,    0,    1 },  /* 34: L PUNCH B, UP P GUARD P L */
    {   27,   27,    0,   10,    1,   10,    0,    1 },  /* 35: L PUNCH B, UP P GUARD P L */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 36: not used by a script */
    {   28,   28,    0,    0,    1,    0,    0,    1 },  /* 37: L PUNCH B, UP P GUARD P L */
    {   29,   29,    0,    0,    1,    0,    0,    1 },  /* 38: L PUNCH B, UP P GUARD P L */
    {   30,   30,    0,    0,    8,    0,    0,    1 },  /* 39: S KICK A */
    {   31,   31,    0,   11,    8,   11,    0,    1 },  /* 40: S KICK A */
    {   31,   31,    0,    0,    8,    0,    0,    1 },  /* 41: S KICK A */
    {   32,   32,    0,    0,    1,    0,    0,    5 },  /* 42: not used by a script */
    {   33,   33,    0,    0,    1,    0,    0,    5 },  /* 43: not used by a script */
    {   34,   34,    0,    0,    1,    0,    0,    5 },  /* 44: not used by a script */
    {   34,   34,    0,    0,    1,    0,    0,    5 },  /* 45: not used by a script */
    {   35,   35,    0,    0,    1,    0,    0,    1 },  /* 46: ATTACK 6 S: not started by a command */
    {   36,   36,    0,    0,    1,    0,    0,    1 },  /* 47: not used by a script */
    {   37,   37,    0,   13,    1,   13,    0,    1 },  /* 48: ATTACK 6 S: not started by a command */
    {   37,   37,    0,    0,    1,    0,    0,    1 },  /* 49: ATTACK 6 S: not started by a command */
    {   38,   38,    0,    0,    1,    0,    0,    1 },  /* 50: not used by a script */
    {   39,   39,    0,    0,    1,    0,    0,    1 },  /* 51: UP P GUARD K M, ATTACK 6 S: not started by a command */
    {   40,   40,    0,   57,    1,   57,    0,    1 },  /* 52: UP P GUARD K M */
    {   40,   40,    0,   58,    1,   58,    0,    1 },  /* 53: M KICK A, UP P GUARD K M */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 54: M KICK A, UP P GUARD K M, ATTACK 6 S: not started by a command */
    {   42,   42,    0,    0,    1,    0,    0,    1 },  /* 55: not used by a script */
    {   43,   43,    0,    0,    1,    0,    0,    1 },  /* 56: M KICK C */
    {   44,   44,    0,    0,    1,    0,    0,    1 },  /* 57: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    {   45,   45,    0,    0,    1,    0,    0,    1 },  /* 58: not used by a script */
    {   45,   45,    0,   14,    1,   14,    0,    1 },  /* 59: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    {   46,   46,    0,   15,    1,   15,    0,    1 },  /* 60: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    {   47,   47,    0,   16,    1,   16,    0,    1 },  /* 61: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    {   49,   49,    0,   17,    1,   17,    0,    1 },  /* 62: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    {   49,   49,    0,   18,    1,   18,    0,    1 },  /* 63: not used by a script */
    {   50,   50,    0,    0,    1,    0,    0,    1 },  /* 64: not used by a script */
    {   52,   52,    0,    0,    1,    0,    0,    1 },  /* 65: L KICK A, UP P GUARD K L */
    {   53,   53,    0,   68,    1,   68,    0,    1 },  /* 66: UP P GUARD K L */
    {   54,   54,    0,   19,    1,   19,    0,    1 },  /* 67: L KICK A, UP P GUARD K L */
    {   54,   54,    0,   19,    1,   19,    0,    1 },  /* 68: UP P GUARD K L */
    {   55,   55,    0,    0,    1,    0,    0,    1 },  /* 69: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    {   56,   56,    0,    0,    1,    0,    0,    1 },  /* 70: not used by a script */
    {   57,   57,    0,    0,    1,    0,    0,    1 },  /* 71: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    {   58,   58,    0,    0,    1,    0,    0,    1 },  /* 72: not used by a script */
    {   59,   59,    0,    0,    1,    0,    0,   19 },  /* 73: not used by a script */
    {   60,   60,    0,    0,   13,    0,    0,   10 },  /* 74: TOUKETSU A */
    {   61,   61,    0,   20,    1,    0,    0,   11 },  /* 75: not used by a script */
    {   61,   61,    0,    0,    1,    0,    0,   11 },  /* 76: not used by a script */
    {   62,   62,    0,    0,    1,    0,    0,   11 },  /* 77: not used by a script */
    {   63,   63,    0,    0,    1,    0,    0,   11 },  /* 78: not used by a script */
    {   64,   64,    0,   21,    9,   21,    0,    2 },  /* 79: KAGAMI P A */
    {   64,   64,    0,    0,    9,    0,    0,    2 },  /* 80: KAGAMI P A */
    {   65,   65,    0,   22,    2,   22,    0,    2 },  /* 81: KAGAMI P A */
    {   65,   65,    0,    0,    2,    0,    0,    2 },  /* 82: KAGAMI P A */
    {   66,   66,    0,    0,    2,    0,    0,    2 },  /* 83: KAGAMI P A */
    {   67,   67,    0,   23,    2,   23,    0,    2 },  /* 84: KAGAMI P A */
    {   68,   68,    0,   24,    2,   24,    0,    2 },  /* 85: KAGAMI P A */
    {   69,   69,    0,    0,    2,    0,    0,    2 },  /* 86: KAGAMI P A */
    {   68,   68,    0,    0,    2,    0,    0,    2 },  /* 87: not used by a script */
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
    {   78,   78,    0,    0,    4,   28,    0,   16 },  /* 100: V JUMP P S A, F JUMP P S A */
    {    7,    0,    0,    0,    4,    0,    0,    4 },  /* 101: V JUMP K M A */
    {   80,   80,    0,    0,    4,   29,    0,    4 },  /* 102: not used by a script */
    {   96,   11,    0,    0,    4,    0,    0,    4 },  /* 103: V JUMP P M A, F JUMP P M A */
    {   81,   81,    0,    0,    4,   30,    0,    4 },  /* 104: V JUMP K M A */
    {   81,   81,    0,    0,    4,    0,    0,    4 },  /* 105: V JUMP K M A */
    {   77,   77,    0,   66,    2,   66,    0,    2 },  /* 106: not used by a script */
    {   96,    7,    0,    0,    4,   32,    0,    4 },  /* 107: V JUMP P M A, F JUMP P M A */
    {   82,    0,    0,    0,    3,   33,    0,    3 },  /* 108: V JUMP K S A, F JUMP K S A */
    {   82,    0,    0,    0,    3,    0,    0,    3 },  /* 109: V JUMP K S A, F JUMP K S A */
    {   83,   83,    0,    0,    3,   34,    0,    3 },  /* 110: F JUMP K M A */
    {   83,   83,    0,    0,    3,    0,    0,    3 },  /* 111: F JUMP K M A, F JUMP K L A */
    {  123,  123,    0,   35,    0,   35,    0,    2 },  /* 112: not used by a script */
    {    7,    0,    0,   36,    4,   36,    0,    3 },  /* 113: not used by a script */
    {   84,   84,    0,    0,    4,   37,    0,    4 },  /* 114: V JUMP K L A */
    {   84,   84,    0,    0,    4,    0,    0,    4 },  /* 115: V JUMP K L A */
    {   85,   85,    0,    0,   15,    0,    0,   19 },  /* 116: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    {   86,   86,    0,    0,   15,    0,    0,   19 },  /* 117: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    {   87,   87,    0,    0,    1,    0,    0,    1 },  /* 118: follow-up of APPEAR JUNBI 1, follow-up of APPEAR 8, follow-up of ZANNEN 5 +4 */
    {   88,   88,    0,    0,    1,    0,    0,    1 },  /* 119: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {   89,   89,    0,   45,    1,   45,    0,    1 },  /* 120: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {   90,   90,    0,    0,   12,    0,    0,   18 },  /* 121: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +2 */
    {   97,   97,    0,   38,   12,   38,    0,   18 },  /* 122: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 123: GUARD HEAD */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 124: GUARD UP, P BREAK ZUJOU, P BREAK DOWN +1 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 125: GUARD DOWN */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 126: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 127: not used by a script */
    {    1,    1,    0,   41,    1,   41,    0,    1 },  /* 128: M PUNCH A, M PUNCH B, M KICK A +4 */
    {  107,  107,    0,   42,    1,   42,    0,    1 },  /* 129: not used by a script */
    {  112,  112,    0,   43,    1,   43,    0,    1 },  /* 130: not used by a script */
    {    7,    0,    0,   44,    4,   44,    0,    3 },  /* 131: not used by a script */
    {   97,   97,    0,    0,   12,    0,    0,   18 },  /* 132: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {   98,   98,    0,   39,   12,   39,    0,   18 },  /* 133: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {   98,   98,    0,    0,   12,    0,    0,   18 },  /* 134: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {   99,   99,    0,    0,    1,    0,    0,    1 },  /* 135: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {  100,  100,    0,    0,    1,    0,    0,   10 },  /* 136: not used by a script */
    {  101,  101,    0,    0,    1,    0,    0,   10 },  /* 137: not used by a script */
    {  102,  102,    0,    0,    1,    0,    0,   10 },  /* 138: not used by a script */
    {  103,  103,    0,   46,    1,   46,    0,   11 },  /* 139: not used by a script */
    {  103,  103,    0,   47,    1,   47,    0,   11 },  /* 140: not used by a script */
    {  103,  103,    0,    0,    1,    0,    0,   11 },  /* 141: not used by a script */
    {  104,  104,    0,    0,    1,    0,    0,   11 },  /* 142: not used by a script */
    {  105,  105,    0,    0,    1,    0,    0,    1 },  /* 143: not used by a script */
    {    1,    1,    0,    0,    1,    0,    0,   10 },  /* 144: not used by a script */
    {   83,   83,    0,    0,    3,   48,    0,    3 },  /* 145: F JUMP K L A */
    {  108,  108,    0,    0,    1,    0,    0,    1 },  /* 146: M PUNCH A, UP P GUARD P M */
    {  106,  106,    0,    0,    1,    0,    0,    1 },  /* 147: not used by a script */
    {   54,   54,    0,   49,    1,   49,    0,    9 },  /* 148: not used by a script */
    {  113,  113,    0,    0,    1,    0,    0,    1 },  /* 149: FUSHIN P S */
    {  114,  114,    0,   50,    1,   50,    0,    1 },  /* 150: FUSHIN P S */
    {    0,    0,    0,   51,    0,   51,    0,    1 },  /* 151: ATTACK 5 S: not started by a command */
    {  135,    0,    0,   52,    3,   52,    0,    0 },  /* 152: ATTACK 5 S: not started by a command */
    {  135,    0,    0,   52,    3,   52,    0,    0 },  /* 153: ATTACK 5 S: not started by a command */
    {  135,    0,    0,   52,    3,   52,    0,    0 },  /* 154: ATTACK 5 S: not started by a command */
    {  135,    0,    0,   52,    3,   52,    0,    0 },  /* 155: ATTACK 5 S: not started by a command */
    {  135,    0,    0,   52,    3,   52,    0,    0 },  /* 156: ATTACK 5 S: not started by a command */
    {  117,  117,    0,    0,    1,    0,    0,    0 },  /* 157: ATTACK 8 S: not started by a command, ATTACK 8 M: not started by a command, ATTACK 8 L: not started by a command +1 */
    {   90,   90,    0,    0,   12,    0,    0,    4 },  /* 158: ATTACK 6 S: not started by a command */
    {   97,   97,    0,   38,   12,   38,    0,    0 },  /* 159: not used by a script */
    {   97,   97,    0,    0,   12,    0,    0,    4 },  /* 160: ATTACK 6 S: not started by a command */
    {   98,   98,    0,   39,   12,   39,    0,    0 },  /* 161: not used by a script */
    {  115,  115,    0,    0,   13,    0,    0,   22 },  /* 162: AIR S, AIR M, AIR L +41 */
    {  116,  116,    0,   59,    3,   59,    0,    3 },  /* 163: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 164: ATTACK 4 S: not started by a command, ATTACK 6 S: not started by a command */
    {    0,    0,    0,   60,    0,   60,    0,    1 },  /* 165: ATTACK 6 S: not started by a command */
    {   54,   54,    0,   60,    1,   60,    0,    1 },  /* 166: ATTACK 6 S: not started by a command */
    {   40,   40,    0,   61,    1,   61,    0,    1 },  /* 167: ATTACK 6 S: not started by a command */
    {   97,   97,    0,   62,    1,   62,    0,    4 },  /* 168: ATTACK 6 S: not started by a command */
    {   98,   98,    0,   63,    1,   63,    0,    4 },  /* 169: ATTACK 6 S: not started by a command */
    {   31,   31,    0,   60,    1,   60,    0,    1 },  /* 170: not used by a script */
    {   37,   37,    0,   60,    1,   60,    0,    1 },  /* 171: ATTACK 6 S: not started by a command */
    {    0,    0,    0,   67,    0,   67,    0,    2 },  /* 172: ATTACK 5 S: not started by a command */
    {   52,   52,    0,   68,    1,   68,    0,    1 },  /* 173: not used by a script */
    {  118,  118,    0,    1,    0,    1,    0,   25 },  /* 174: not used by a script */
    {    0,    0,    0,   69,    0,   69,    0,   25 },  /* 175: ATTACK 4 S: not started by a command */
    {    0,    0,    0,   70,    0,   70,    0,   25 },  /* 176: ATTACK 4 S: not started by a command */
    {    0,    0,    0,    2,    0,    2,    0,   25 },  /* 177: not used by a script */
    {    3,    3,    0,    0,    0,    0,    0,   25 },  /* 178: not used by a script */
    {   51,   51,    0,    0,    4,    0,    0,    4 },  /* 179: V JUMP P L A */
    {  119,    0,    0,    0,    4,    0,    0,    4 },  /* 180: V JUMP P L A */
    {  120,  120,    0,    0,    4,   29,    0,    4 },  /* 181: V JUMP P L A */
    {  121,  121,    0,    0,    4,   72,    0,    4 },  /* 182: V JUMP K M A */
    {    0,    0,    0,    0,    0,    0,    0,    4 },  /* 183: AIR S, AIR M, AIR L +2 */
    {    1,    1,    0,    1,    1,   69,    0,   25 },  /* 184: ATTACK 4 S: not started by a command */
    {    1,    1,    0,    2,    3,    2,    0,   25 },  /* 185: ATTACK 4 S: not started by a command */
    {    0,    0,    0,    0,    0,    0,    0,   25 },  /* 186: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 187: not used by a script */
    {    0,    0,    0,   73,    0,   73,    0,    1 },  /* 188: ATTACK 6 S: not started by a command */
    {   74,   74,    0,    0,    2,    0,    0,    2 },  /* 189: not used by a script */
    {   72,   72,    0,    0,    9,    0,    0,    2 },  /* 190: not used by a script */
    {    1,    1,    0,   74,    1,    0,    0,    1 },  /* 191: L PUNCH A, L PUNCH B, L KICK A */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 192: ATTACK 5 S: not started by a command */
    {  124,  124,    0,   75,    3,   75,    0,    3 },  /* 193: not used by a script */
    {  125,  125,    0,    0,    1,    0,    0,    1 },  /* 194: PIYO */
    {  126,  126,    0,    0,    1,    0,    0,    1 },  /* 195: PIYO */
    {   22,   22,    0,   76,    1,   76,    0,    1 },  /* 196: L PUNCH A */
    {  127,  127,    0,   77,    3,   77,    0,    3 },  /* 197: ATTACK 9 M: not started by a command */
    {    0,    0,    0,    0,    0,    0,    0,   27 },  /* 198: NEKOROBI S, dmca 96 */
    {  128,  128,    0,    0,   16,    0,    0,    2 },  /* 199: OKIAGARI P S */
    {  128,  128,    0,   78,   16,   78,    0,    1 },  /* 200: OKIAGARI P S */
    {  129,  129,    0,   79,   17,   79,    0,    4 },  /* 201: OKIAGARI P S */
    {  130,  130,    0,    0,    4,    0,    0,    4 },  /* 202: OKIAGARI P S */
    {    0,    0,    0,    0,    1,    0,    0,    2 },  /* 203: not used by a script */
    {    2,    2,    0,   69,    1,   69,    0,   25 },  /* 204: ATTACK 4 S: not started by a command */
    {    1,    1,    0,   70,    3,   70,    0,   25 },  /* 205: ATTACK 4 S: not started by a command */
    {  123,  123,    0,    0,    0,    0,    0,    2 },  /* 206: ATTACK 2 L: not started by a command */
    {  123,  123,    0,   35,    0,   35,    0,    2 },  /* 207: ATTACK 2 L: not started by a command */
    {  123,  123,    0,    1,    0,    1,    0,    2 },  /* 208: ATTACK 2 L: not started by a command, ATTACK 2 SP: not started by a command */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 209: follow-up of SP APPEAR 8 */
    {    2,    2,    0,    0,    0,    0,    0,    2 },  /* 210: follow-up of SP APPEAR 8 */
    {  131,  131,    0,    0,    0,    0,    0,    2 },  /* 211: ATTACK 2 M: not started by a command */
    {  131,  131,    0,    1,    0,    1,    0,    2 },  /* 212: ATTACK 2 M: not started by a command */
    {    1,    1,    0,    2,    1,    2,    0,    1 },  /* 213: not used by a script */
    {   97,   97,    0,   81,   12,   81,    0,   18 },  /* 214: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 215: LOSE SONABA */
    {  132,  132,    0,    0,   19,    0,    0,   28 },  /* 216: PARING AIR F, PARING AIR B */
    {  134,  134,    0,    1,    0,    1,    0,    2 },  /* 217: ATTACK 2 S: not started by a command */
    {   19,  135,    0,    7,    1,    7,    0,    1 },  /* 218: M PUNCH B */
    {    3,    3,    0,    3,    3,    3,    0,    4 },  /* 219: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 220: ATTACK 2 SP: not started by a command */
    {    0,    0,    0,    0,    0,   35,    0,    2 },  /* 221: ATTACK 2 SP: not started by a command */
    {    1,   18,    0,    0,    1,   74,    0,    1 },  /* 222: not used by a script */
    {    1,   20,    0,    0,    1,   74,    0,    1 },  /* 223: not used by a script */
    {    1,   20,    0,    0,    1,    0,    0,    1 },  /* 224: not used by a script */
    {    1,  135,    0,    0,    1,   82,    0,    1 },  /* 225: not used by a script */
    {    1,  136,    0,    0,    1,   83,    0,    1 },  /* 226: not used by a script */
    {    1,  137,    0,    0,    1,    0,    0,    1 },  /* 227: not used by a script */
    {   90,   90,    0,    0,   12,    0,    0,   18 },  /* 228: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1 */
    {   97,   97,    0,    0,   12,   55,    0,   18 },  /* 229: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1 */
    {   97,   97,    0,    0,   12,    0,    0,   18 },  /* 230: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1 */
    {   98,   98,    0,    0,   12,   56,    0,   18 },  /* 231: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1 */
    {   98,   98,    0,    0,   12,    0,    0,   18 },  /* 232: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command +1 */
};

const BODY_BOX ken_body_box[136] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -16,  23,  84,  18 },  {  -29,  59,  81,   7 },  {  -29,  59,  32,  49 },  {  -35,  72,   0,  31 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +115 */
    { { {  -16,  26,  50,  18 },  {  -30,  58,  43,  13 },  {  -29,  58,  26,  20 },  {  -42,  82,   0,  31 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +28 */
    { { {   -1,  18,  96,  16 },  {  -20,  44,  81,  14 },  {  -16,  32,  63,  18 },  {  -22,  42,  37,  27 } } },  /* 3: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +3 */
    { { {   -4,  18, 102,  16 },  {  -24,  44,  90,  14 },  {  -24,  46,  61,  31 },  {  -18,  42,  -3,  73 } } },  /* 4: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +4 */
    { { {  -16,  23,  78,  16 },  {  -25,  53,  62,  20 },  {  -24,  40,  37,  29 },  {  -38,  66,   0,  35 } } },  /* 5: DASH HUMIKOMI, DASH TOBINOKI */
    { { {   -5,  23,  78,  16 },  {  -25,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -33,  55,   0,  35 } } },  /* 6: DASH TOBINOKI */
    { { {  -19,  39,  92,  16 },  {  -32,  64,  78,  15 },  {  -30,  59,  42,  37 },  {    0,   0,   0,   0 } } },  /* 7: GUARD AIR, V JUMP P M A, V JUMP K S A +8 */
    { { {  -28,  54,  39,  40 },  {  -23,  53,  75,  20 },  {  -28,  54,  39,  40 },  {    0,   0,   0,   0 } } },  /* 8: not used by a script */
    { { {  -42,  31,  52,  21 },  {  -33,  60,  75,  20 },  {  -25,  52,  36,  37 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {    0,   0,   0,   0 },  {  -34,  69,  42,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    { { {  -11,  23, 106,  16 },  {  -23,  53,  90,  20 },  {  -19,  43,  45,  49 },  {    0,   0,   0,   0 } } },  /* 11: JUMP JUNBI, SP JUMP JUNBI, JUMP VERTICAL +8 */
    { { {  -18,  23,  99,  16 },  {  -23,  53,  90,  20 },  {  -31,  63,  44,  44 },  {    0,   0,   0,   0 } } },  /* 12: JUMP VERTICAL, S JUMP FRONT, SP JUMP V +3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 13: dmca 97 */
    { { {  -11,  49,  81,  19 },  {  -39,  79,  42,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: not used by a script */
    { { {  -22,  57,  76,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: not used by a script */
    { { {  -23,  23,  78,  16 },  {  -31,  53,  63,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 16: S PUNCH A */
    { { {  -14,  21,  84,  18 },  {  -28,  58,  69,  22 },  {  -21,  49,  38,  31 },  {  -28,  63,   0,  38 } } },  /* 17: S PUNCH B */
    { { {  -29,  34,  82,  16 },  {  -36,  65,  66,  20 },  {  -32,  58,  36,  29 },  {  -32,  67,   0,  35 } } },  /* 18: L PUNCH A, follow-up of M PUNCH A, UP P GUARD P S */
    { { {  -27,  23,  79,  16 },  {  -45,  69,  63,  21 },  {  -32,  52,  36,  29 },  {  -42,  74,   0,  41 } } },  /* 19: M PUNCH B, UP P GUARD P S */
    { { {  -20,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 20: M PUNCH B, UP P GUARD P S */
    { { {  -20,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 21: not used by a script */
    { { {  -29,  34,  83,  16 },  {  -32,  54,  67,  20 },  {  -26,  43,  36,  29 },  {  -33,  62,   0,  35 } } },  /* 22: L PUNCH A, follow-up of M PUNCH A */
    { { {  -29,  34,  83,  16 },  {  -32,  54,  67,  20 },  {  -26,  43,  36,  29 },  {  -33,  62,   0,  35 } } },  /* 23: L PUNCH A, follow-up of M PUNCH A */
    { { {  -29,  34,  83,  16 },  {  -32,  54,  67,  20 },  {  -26,  43,  36,  29 },  {  -33,  62,   0,  35 } } },  /* 24: L PUNCH A, follow-up of M PUNCH A */
    { { {  -21,  38,  83,  16 },  {  -29,  55,  67,  20 },  {  -21,  44,  47,  22 },  {  -35,  61,   0,  47 } } },  /* 25: L PUNCH B, UP P GUARD P L */
    { { {  -20,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -35,  61,   0,  35 } } },  /* 26: L PUNCH B, UP P GUARD P L */
    { { {   -6,  26,  82,  16 },  {  -25,  49,  67,  20 },  {  -20,  43,  36,  29 },  {  -36,  80,   0,  35 } } },  /* 27: L PUNCH B, UP P GUARD P L */
    { { {    0,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -35,  61,   0,  35 } } },  /* 28: L PUNCH B, UP P GUARD P L */
    { { {  -14,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -35,  61,   0,  35 } } },  /* 29: L PUNCH B, UP P GUARD P L */
    { { {  -14,  23,  83,  16 },  {  -25,  44,  67,  20 },  {  -35,  51,  36,  31 },  {  -33,  36,   0,  35 } } },  /* 30: S KICK A */
    { { {  -24,  31,  84,  16 },  {  -32,  51,  67,  20 },  {  -35,  56,  36,  29 },  {  -44,  56,   0,  35 } } },  /* 31: S KICK A */
    { { {    7,  23,  83,  16 },  {   -5,  53,  67,  20 },  {   -6,  43,  36,  29 },  {   10,  26,   0,  35 } } },  /* 32: not used by a script */
    { { {   21,  23,  83,  16 },  {    6,  53,  67,  20 },  {   -6,  43,  36,  29 },  {   10,  26,   0,  35 } } },  /* 33: not used by a script */
    { { {   21,  23,  83,  16 },  {    6,  53,  67,  20 },  {   -6,  43,  36,  29 },  {   10,  26,   0,  35 } } },  /* 34: not used by a script */
    { { {  -33,  23,  86,  15 },  {  -41,  52,  72,  14 },  {  -56,  63,  41,  30 },  {  -47,  55,   0,  42 } } },  /* 35: ATTACK 6 S: not started by a command */
    { { {  -33,  23,  83,  16 },  {  -31,  43,  67,  20 },  {  -19,  29,  36,  30 },  {  -47,  55,   0,  42 } } },  /* 36: not used by a script */
    { { {  -39,  31,  89,  16 },  {  -48,  53,  73,  20 },  {  -33,  38,  43,  31 },  {  -47,  55,   0,  42 } } },  /* 37: ATTACK 6 S: not started by a command */
    { { {  -26,  23,  83,  16 },  {  -33,  43,  68,  20 },  {  -25,  29,  35,  30 },  {  -33,  28,   0,  35 } } },  /* 38: not used by a script */
    { { {   -2,  23,  87,  16 },  {  -12,  53,  67,  20 },  {  -13,  43,  36,  29 },  {   -9,  33,   0,  37 } } },  /* 39: UP P GUARD K M, ATTACK 6 S: not started by a command */
    { { {    3,  23,  82,  16 },  {  -11,  47,  67,  20 },  {  -35,  61,  48,  24 },  {  -33,  54,   0,  48 } } },  /* 40: UP P GUARD K M, M KICK A, ATTACK 6 S: not started by a command */
    { { {   -5,  23,  82,  16 },  {  -16,  47,  67,  20 },  {  -25,  43,  37,  29 },  {  -20,  33,   0,  37 } } },  /* 41: M KICK A, UP P GUARD K M, ATTACK 6 S: not started by a command */
    { { {   -5,  23,  82,  16 },  {  -16,  47,  67,  20 },  {  -25,  43,  37,  29 },  {  -20,  33,   0,  37 } } },  /* 42: not used by a script */
    { { {  -20,  23,  88,  16 },  {  -34,  51,  70,  20 },  {  -31,  43,  42,  29 },  {  -36,  49,   0,  43 } } },  /* 43: M KICK C */
    { { {  -16,  24,  84,  16 },  {  -28,  52,  69,  16 },  {  -32,  48,  36,  32 },  {  -32,  40,   0,  36 } } },  /* 44: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { {  -16,  24,  84,  16 },  {  -28,  52,  69,  16 },  {  -32,  48,  36,  32 },  {  -32,  40,   0,  36 } } },  /* 45: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { {  -16,  24,  84,  16 },  {  -28,  52,  69,  16 },  {  -32,  48,  36,  32 },  {  -32,  40,   0,  36 } } },  /* 46: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { {  -16,  24,  84,  16 },  {  -28,  52,  69,  16 },  {  -32,  48,  36,  32 },  {  -32,  40,   0,  36 } } },  /* 47: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { {  -24,  24,  84,  16 },  {  -36,  52,  69,  16 },  {  -40,  48,  36,  32 },  {  -40,  40,   0,  36 } } },  /* 48: not used by a script */
    { { {  -31,  23,  78,  16 },  {  -39,  46,  59,  20 },  {  -47,  39,  39,  23 },  {  -65,  43,   0,  48 } } },  /* 49: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { {  -25,  21,  80,  17 },  {  -28,  52,  59,  23 },  {  -33,  40,  35,  30 },  {  -37,  40,   1,  36 } } },  /* 50: not used by a script */
    { { {  -17,  28, 108,  16 },  {  -29,  54,  95,  15 },  {  -31,  69,  47,  49 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P L A */
    { { {   -5,  23,  77,  16 },  {  -25,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 52: L KICK A, UP P GUARD K L */
    { { {   -5,  23,  77,  16 },  {  -25,  53,  67,  20 },  {  -33,  61,  41,  24 },  {  -17,  39,   1,  39 } } },  /* 53: UP P GUARD K L */
    { { {   -5,  23,  81,  16 },  {  -25,  53,  67,  20 },  {  -33,  61,  41,  24 },  {  -17,  39,   0,  39 } } },  /* 54: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    { { {    0,  23,  78,  16 },  {  -17,  52,  64,  16 },  {  -26,  43,  39,  29 },  {  -17,  33,   0,  35 } } },  /* 55: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    { { {    7,  23,  77,  16 },  {  -30,  63,  61,  20 },  {  -30,  43,  36,  29 },  {  -31,  53,   0,  35 } } },  /* 56: not used by a script */
    { { {   -8,  23,  83,  16 },  {  -21,  51,  68,  18 },  {  -24,  43,  39,  29 },  {  -15,  33,   0,  35 } } },  /* 57: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    { { {   -2,  23,  81,  16 },  {  -19,  44,  70,  18 },  {  -24,  43,  38,  29 },  {  -15,  36,   0,  35 } } },  /* 58: not used by a script */
    { { {   -4,  23,  90,  16 },  {  -25,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 59: not used by a script */
    { { {   20,  23,  77,  16 },  {  -14,  53,  67,  20 },  {  -18,  43,  36,  29 },  {  -25,  55,   0,  35 } } },  /* 60: TOUKETSU A */
    { { {   37,  23,  65,  16 },  {    4,  53,  54,  20 },  {  -14,  43,  36,  29 },  {  -15,  36,   0,  35 } } },  /* 61: not used by a script */
    { { {   37,  23,  65,  16 },  {    4,  53,  54,  20 },  {  -14,  43,  36,  29 },  {  -15,  36,   0,  35 } } },  /* 62: not used by a script */
    { { {   32,  23,  78,  16 },  {    4,  53,  64,  20 },  {  -14,  43,  36,  29 },  {  -15,  36,   0,  35 } } },  /* 63: not used by a script */
    { { {  -23,  26,  48,  18 },  {  -30,  58,  43,  18 },  {  -18,  43,  20,  26 },  {  -42,  70,   0,  58 } } },  /* 64: KAGAMI P A */
    { { {  -14,  23,  50,  16 },  {  -21,  43,  37,  18 },  {  -18,  43,  20,  26 },  {  -42,  70,   0,  58 } } },  /* 65: KAGAMI P A */
    { { {  -14,  23,  50,  16 },  {  -21,  43,  37,  18 },  {  -18,  43,  20,  26 },  {  -42,  70,   0,  58 } } },  /* 66: KAGAMI P A */
    { { {  -24,  25,  70,  19 },  {  -37,  63,  61,  18 },  {    0,   0,   0,   0 },  {  -47,  74,   0,  60 } } },  /* 67: KAGAMI P A */
    { { {   -5,  23,  80,  16 },  {  -26,  62,  66,  18 },  {  -18,  43,  37,  29 },  {  -48,  78,   0,  52 } } },  /* 68: KAGAMI P A */
    { { {   -7,  23,  75,  16 },  {  -18,  44,  60,  18 },  {  -19,  43,  37,  29 },  {  -42,  70,   0,  58 } } },  /* 69: KAGAMI P A */
    { { {   -8,  23,  69,  16 },  {  -17,  36,  53,  18 },  {  -21,  43,  31,  29 },  {  -42,  70,   0,  58 } } },  /* 70: KAGAMI P A */
    { { {  -16,  40,  46,  18 },  {  -30,  58,  43,  13 },  {  -29,  58,  26,  20 },  {  -38,  72,   0,  30 } } },  /* 71: KAGAMI K A */
    { { {   -4,  34,  43,  18 },  {  -35,  63,  34,  18 },  {  -54,  93,  13,  28 },  {  -85, 128,   0,  23 } } },  /* 72: KAGAMI K A */
    { { {   -4,  25,  44,  17 },  {  -44,  77,  28,  23 },  {  -23,  65,  20,  26 },  {  -59, 103,   0,  28 } } },  /* 73: KAGAMI K A, UP P GUARD K S */
    { { {   -4,  25,  44,  17 },  {  -35,  74,  28,  23 },  {  -59, 109,  17,  26 },  {  -65, 122,   0,  28 } } },  /* 74: KAGAMI K A, UP P GUARD K S */
    { { {   -6,  24,  58,  19 },  {  -36,  80,  43,  21 },  {  -31,  84,  20,  26 },  {  -64, 122,   0,  32 } } },  /* 75: UP P GUARD K S */
    { { {  -30,  48,  51,  17 },  {  -43,  73,  44,  14 },  {  -47,  78,  32,  16 },  {  -55,  92,   0,  33 } } },  /* 76: KAGAMI K A */
    { { {  -30,  48,  51,  18 },  {  -43,  73,  44,  14 },  {  -63,  97,  25,  19 },  {  -72, 111,   0,  32 } } },  /* 77: KAGAMI K A */
    { { {  -39,  49,  89,  20 },  {  -41,  72,  73,  28 },  {  -41,  77,  42,  45 },  {    0,   0,   0,   0 } } },  /* 78: V JUMP P S A, F JUMP P S A */
    { { {  -18,  23, 107,  16 },  {  -25,  53,  74,  20 },  {  -17,  43,  47,  35 },  {    0,   0,   0,   0 } } },  /* 79: not used by a script */
    { { {  -18,  23, 107,  16 },  {  -25,  53,  74,  20 },  {  -17,  43,  47,  35 },  {    0,   0,   0,   0 } } },  /* 80: not used by a script */
    { { {   -6,  23, 100,  16 },  {  -25,  53,  86,  20 },  {  -33,  69,  37,  52 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP K M A */
    { { {  -23,  39,  89,  16 },  {  -32,  63,  67,  24 },  {  -49,  76,  35,  33 },  {    0,   0,   0,   0 } } },  /* 82: V JUMP K S A, F JUMP K S A */
    { { {  -28,  48,  92,  14 },  {  -39,  68,  81,  14 },  {  -44,  74,  46,  41 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K M A, F JUMP K L A */
    { { {  -11,  23, 106,  16 },  {  -23,  53,  90,  20 },  {  -29,  57,  43,  40 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP K L A */
    { { {  -28,  38,  74,  16 },  {  -37,  65,  56,  20 },  {  -19,  43,  36,  29 },  {  -46,  80,   0,  35 } } },  /* 85: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    { { {  -31,  29,  70,  16 },  {  -42,  77,  55,  23 },  {  -19,  43,  36,  29 },  {  -46,  80,   0,  35 } } },  /* 86: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    { { {  -14,  24,  73,  18 },  {  -24,  52,  58,  24 },  {  -17,  45,  36,  22 },  {  -24,  56,   0,  36 } } },  /* 87: follow-up of APPEAR JUNBI 1, follow-up of APPEAR 8, follow-up of ZANNEN 5 +4 */
    { { {  -11,  20,  85,  16 },  {  -18,  47,  74,  16 },  {  -16,  40,  40,  34 },  {  -16,  56,   0,  40 } } },  /* 88: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    { { {   -8,  18,  84,  14 },  {  -24,  46,  72,  14 },  {  -23,  38,  44,  28 },  {  -16,  24,   0,  44 } } },  /* 89: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    { { {  -10,  18,  98,  14 },  {  -24,  48,  88,  14 },  {  -29,  60,  49,  43 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { { {   -3,  23,  83,  16 },  {  -17,  43,  72,  20 },  {   -8,  37,  40,  29 },  {  -20,  55,   0,  35 } } },  /* 91: not used by a script */
    { { {   -6,  23,  83,  16 },  {  -20,  53,  67,  20 },  {  -12,  38,  36,  29 },  {  -22,  55,   0,  35 } } },  /* 92: not used by a script */
    { { {   -6,  23,  49,  16 },  {  -16,  42,  37,  18 },  {  -18,  44,  20,  26 },  {  -28,  55,   0,  31 } } },  /* 93: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -27,  36,   0,  53 },  {    0,   0,   0,   0 } } },  /* 94: not used by a script */
    { { {  -20,  23,  89,  16 },  {  -25,  53,  74,  20 },  {  -17,  43,  47,  35 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -32,  27,  89,  24 },  {  -34,  66,  79,  27 },  {  -38,  82,  43,  46 },  {    0,   0,   0,   0 } } },  /* 96: F JUMP P L A, V JUMP P M A, F JUMP P M A */
    { { {  -13,  22, 100,  17 },  {  -34,  65,  88,  14 },  {  -29,  60,  49,  43 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command +6 */
    { { {  -13,  22, 100,  17 },  {  -34,  65,  88,  14 },  {  -29,  60,  49,  43 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { { {  -12,  18,  90,  14 },  {  -26,  50,  80,  14 },  {  -20,  34,  50,  28 },  {  -30,  54,  10,  38 } } },  /* 99: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    { { {  -10,  18,  84,  14 },  {  -24,  52,  74,  14 },  {  -24,  40,  40,  30 },  {  -10,  36,   0,  38 } } },  /* 100: not used by a script */
    { { {   -2,  18,  84,  14 },  {  -24,  52,  76,  14 },  {  -18,  36,  38,  34 },  {  -28,  50,   0,  36 } } },  /* 101: not used by a script */
    { { {   14,  18,  78,  14 },  {  -18,  52,  70,  14 },  {  -28,  48,  38,  30 },  {  -24,  26,   0,  36 } } },  /* 102: not used by a script */
    { { {   36,  18,  66,  14 },  {   12,  24,  50,  28 },  {  -30,  40,  44,  30 },  {  -20,  28,   0,  42 } } },  /* 103: not used by a script */
    { { {   34,  18,  68,  14 },  {   12,  24,  48,  30 },  {  -30,  40,  44,  28 },  {  -18,  28,   0,  42 } } },  /* 104: not used by a script */
    { { {   20,  18,  78,  14 },  {  -12,  52,  64,  20 },  {  -24,  48,  30,  32 },  {   -8,  30,   0,  30 } } },  /* 105: not used by a script */
    { { {  -23,  18,  86,  14 },  {  -30,  52,  73,  14 },  {  -19,  37,  41,  30 },  {  -38,  72,   2,  36 } } },  /* 106: not used by a script */
    { { {  -31,  23,  79,  16 },  {  -34,  53,  63,  20 },  {  -28,  43,  36,  29 },  {  -33,  55,   0,  35 } } },  /* 107: not used by a script */
    { { {  -14,  21,  84,  18 },  {  -28,  58,  69,  22 },  {  -21,  49,  38,  31 },  {  -28,  63,   0,  38 } } },  /* 108: M PUNCH A, UP P GUARD P M */
    { { {  -23,  18,  81,  14 },  {  -34,  52,  67,  14 },  {  -25,  40,  38,  30 },  {  -28,  56,   0,  36 } } },  /* 109: S PUNCH A */
    { { {  -18,  23,  81,  16 },  {  -30,  61,  70,  15 },  {  -46,  72,  38,  30 },  {  -33,  65,   0,  36 } } },  /* 110: M PUNCH A, UP P GUARD P M */
    { { {  -28,  46,  89,  16 },  {  -35,  60,  69,  26 },  {  -72, 100,  49,  22 },  {  -85, 102,  46,  16 } } },  /* 111: not used by a script */
    { { {  -24,  23,  79,  16 },  {  -25,  44,  67,  20 },  {  -18,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 112: not used by a script */
    { { {  -24,  18,  90,  14 },  {  -17,  52,  79,  14 },  {   -9,  40,  47,  30 },  {  -24,  56,   0,  36 } } },  /* 113: FUSHIN P S */
    { { {  -24,  18,  90,  14 },  {  -17,  52,  79,  14 },  {   -9,  40,  47,  30 },  {  -24,  56,   0,  36 } } },  /* 114: FUSHIN P S */
    { { {  -17,  37,  77,  14 },  {  -24,  52,  66,  17 },  {  -24,  53,  47,  17 },  {  -17,  40,  37,  15 } } },  /* 115: AIR S, AIR M, AIR L +41 */
    { { {  -20,  23,  89,  16 },  {  -25,  53,  74,  20 },  {  -17,  43,  47,  35 },  {    0,   0,   0,   0 } } },  /* 116: not used by a script */
    { { {    0,   0,   0,   0 },  {  -23,  50,  22,  18 },  {  -18,  43,   9,  26 },  {  -28,  55,   0,  23 } } },  /* 117: ATTACK 8 S: not started by a command, ATTACK 8 M: not started by a command, ATTACK 8 L: not started by a command +1 */
    { { {  -37,  30,  68,  21 },  {  -33,  51,  62,  14 },  {  -34,  52,  46,  20 },  {  -30,  58,   0,  46 } } },  /* 118: not used by a script */
    { { {  -17,  28, 108,  16 },  {  -29,  54,  95,  15 },  {  -31,  69,  47,  49 },  {    0,   0,   0,   0 } } },  /* 119: V JUMP P L A */
    { { {  -17,  28, 108,  16 },  {  -29,  54,  95,  15 },  {  -31,  69,  47,  49 },  {    0,   0,   0,   0 } } },  /* 120: V JUMP P L A */
    { { {   -6,  23, 100,  16 },  {  -25,  53,  86,  20 },  {  -33,  69,  37,  52 },  {    0,   0,   0,   0 } } },  /* 121: V JUMP K M A */
    { { {  -19,  39,  92,  16 },  {  -32,  64,  78,  15 },  {  -30,  59,  42,  37 },  {    0,   0,   0,   0 } } },  /* 122: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -35,  59,   0,  48 } } },  /* 123: OKIAGARI P S, ATTACK 2 S: not started by a command, ATTACK 2 L: not started by a command +1 */
    { { {  -32,  27,  89,  24 },  {  -65,  96,  79,  27 },  {  -72, 104,  49,  33 },  {    0,   0,   0,   0 } } },  /* 124: not used by a script */
    { { {   -9,  21,  84,  18 },  {  -11,  54,  81,   7 },  {  -11,  52,  41,  40 },  {  -28,  63,   0,  38 } } },  /* 125: PIYO */
    { { {  -34,  21,  80,  18 },  {  -43,  68,  69,  17 },  {  -28,  52,  38,  30 },  {  -29,  63,   0,  38 } } },  /* 126: PIYO */
    { { {  -32,  27,  89,  24 },  {  -65,  96,  79,  27 },  {  -72, 104,  49,  33 },  {    0,   0,   0,   0 } } },  /* 127: ATTACK 9 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -41,  81,   0,  24 } } },  /* 128: OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -41,  82,   0,  61 } } },  /* 129: OKIAGARI P S */
    { { {  -20,  41,  96,  27 },  {  -29,  58,  82,  14 },  {  -29,  58,  64,  18 },  {  -33,  66,   0,  64 } } },  /* 130: OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  59,   0,  32 } } },  /* 131: ATTACK 2 M: not started by a command */
    { { {    0,   0,   0,   0 },  {  -31,  63,  22,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: PARING AIR F, PARING AIR B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -35,  59,   0,  48 } } },  /* 133: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -35,  59,   0,  60 } } },  /* 134: ATTACK 5 S: not started by a command, ATTACK 2 S: not started by a command */
    { { {  -16,  34,  80,  22 },  {    0,   0,   0,   0 },  {  -19,  42,  24,  54 },  {    0,   0,   0,   0 } } },  /* 135: ATTACK 5 S: not started by a command */
};

const HAND_BOX ken_hand_box[138] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {  -21,  17,  97,  26 },  {    0,   0,   0,   0 } } },  /* 3: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {  -62,  43,  53,  30 },  {    0,   0,   0,   0 } } },  /* 7: V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {  -72,  48,  54,  32 },  {    0,   0,   0,   0 } } },  /* 11: V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {  -54,  40,  79,  22 },  {    0,   0,   0,   0 } } },  /* 14: ATTACK 10 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: no box */
    { { {  -46,  22,  74,  22 },  {    0,   0,   0,   0 } } },  /* 16: S PUNCH A */
    { { {  -73,  51,  66,  30 },  {    0,   0,   0,   0 } } },  /* 17: S PUNCH B */
    { { {  -82,  60,  46,  20 },  {  -65,  38,  44,  14 } } },  /* 18: not used by a script */
    { { {  -70,  59,  64,  18 },  {    0,   0,   0,   0 } } },  /* 19: M PUNCH B, UP P GUARD P S */
    { { {  -94,  66,  46,  20 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { {  -50,  32,  46,  29 },  {    0,   0,   0,   0 } } },  /* 22: L PUNCH A, follow-up of M PUNCH A */
    { { {  -50,  32,  46,  51 },  {    0,   0,   0,   0 } } },  /* 23: L PUNCH A, follow-up of M PUNCH A */
    { { {  -49,  46,  57,  54 },  {    0,   0,   0,   0 } } },  /* 24: L PUNCH A, follow-up of M PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {  -52,  29,  60,  40 },  {    0,   0,   0,   0 } } },  /* 26: L PUNCH B, UP P GUARD P L */
    { { {  -68,  45,  60,  40 },  {    0,   0,   0,   0 } } },  /* 27: L PUNCH B, UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -71,  47,  11,  44 },  {    0,   0,   0,   0 } } },  /* 31: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: no box */
    { { {  -49,  50,  60,  12 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: no box */
    { { {  -68,  38,  14,  53 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 6 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {  -78,  53,  55,  33 },  {    0,   0,   0,   0 } } },  /* 40: UP P GUARD K M, M KICK A, ATTACK 6 S: not started by a command */
    { { {  -59,  42,  45,  22 },  {    0,   0,   0,   0 } } },  /* 41: M KICK A, UP P GUARD K M, ATTACK 6 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {  -70,  51,  61,  60 },  {    0,   0,   0,   0 } } },  /* 45: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { { -107,  74,  41,  61 },  {    0,   0,   0,   0 } } },  /* 46: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { { -107,  74,  41,  61 },  {    0,   0,   0,   0 } } },  /* 47: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    { { {  -61,  21,   9,  36 },  {    0,   0,   0,   0 } } },  /* 48: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {  -71,  53,  82,  32 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {  -57,  33,  44,  17 },  {    0,   0,   0,   0 } } },  /* 53: UP P GUARD K L */
    { { {  -90,  63,  35,  38 },  {    0,   0,   0,   0 } } },  /* 54: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    { { {  -81,  55,  40,  18 },  {    0,   0,   0,   0 } } },  /* 55: L KICK A, UP P GUARD K L, ATTACK 6 S: not started by a command */
    { { {  -68,  27,  72,  23 },  {    0,   0,   0,   0 } } },  /* 56: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -32,  38,  65,  11 },  {    0,   0,   0,   0 } } },  /* 61: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {  -72,  52,  34,  24 },  {    0,   0,   0,   0 } } },  /* 64: KAGAMI P A */
    { { {  -63,  41,  37,  19 },  {    0,   0,   0,   0 } } },  /* 65: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {  -52,  24,  27,  33 },  {    0,   0,   0,   0 } } },  /* 67: KAGAMI P A */
    { { {  -43,  43,  40,  76 },  {    0,   0,   0,   0 } } },  /* 68: KAGAMI P A */
    { { {  -35,  33,  51,  59 },  {    0,   0,   0,   0 } } },  /* 69: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {  -88,  62,   0,  28 },  {    0,   0,   0,   0 } } },  /* 74: KAGAMI K A, UP P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {  -97,  42,   0,  32 },  {    0,   0,   0,   0 } } },  /* 77: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {  -74,  54,  68,  49 },  {    0,   0,   0,   0 } } },  /* 79: not used by a script */
    { { {  -80,  64,  95,  15 },  {    0,   0,   0,   0 } } },  /* 80: not used by a script */
    { { {  -90,  64,  47,  33 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {  -72,  47,  44,  37 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K M A, F JUMP K L A */
    { { {  -74,  68,  70,  24 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {  -39,  17,  46,  23 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: no box */
    { { {  -40,  25,  69,  19 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -72,  48,  59,  27 },  {    0,   0,   0,   0 } } },  /* 96: F JUMP P L A */
    { { {  -60,  50,  53,  20 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command +6 */
    { { {    4,  56,  53,  20 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: no box */
    { { {  -64,  32,  64,  16 },  {    0,   0,   0,   0 } } },  /* 103: not used by a script */
    { { {  -60,  28,  46,  16 },  {    0,   0,   0,   0 } } },  /* 104: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: no box */
    { { {  -50,  26,  63,  26 },  {    0,   0,   0,   0 } } },  /* 107: not used by a script */
    { { {  -33,  21,  54,  19 },  {    0,   0,   0,   0 } } },  /* 108: M PUNCH A, UP P GUARD P M */
    { { {  -46,  22,  74,  22 },  {    0,   0,   0,   0 } } },  /* 109: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {  -72,  41,  71,  15 },  {    0,   0,   0,   0 } } },  /* 111: not used by a script */
    { { {  -52,  18,  51,  26 },  {    0,   0,   0,   0 } } },  /* 112: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: no box */
    { { {  -59,  41,  78,  10 },  {    0,   0,   0,   0 } } },  /* 114: FUSHIN P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: no box */
    { { {  -52,  39,  71,  17 },  {    0,   0,   0,   0 } } },  /* 116: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: no box */
    { { {  -71,  53,  82,  32 },  {    0,   0,   0,   0 } } },  /* 120: V JUMP P L A */
    { { {  -76,  69,  47,  33 },  {    0,   0,   0,   0 } } },  /* 121: V JUMP K M A */
    { { {  -58,  38,  59,  24 },  {    0,   0,   0,   0 } } },  /* 122: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 126: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 127: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 133: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: no box */
    { { {  -81,  50,  64,  19 },  {    0,   0,   0,   0 } } },  /* 135: M PUNCH B, UP P GUARD P S */
    { { {  -76,  49,  67,  20 },  {    0,   0,   0,   0 } } },  /* 136: not used by a script */
    { { {  -57,  45,  28,  46 },  {    0,   0,   0,   0 } } },  /* 137: not used by a script */
};

const HOSEI_BOX ken_hos_box[29] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   84 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +121 */
    { {  -25,   50,    0,   53 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +53 */
    { {  -25,   50,   48,   40 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP K S A +7 */
    { {  -25,   50,   48,   40 } },  /* 4: ATTACK 5 S: not started by a command, ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command +31 */
    { {    1,   47,   35,   54 } },  /* 5: not used by a script */
    { {  -20,   37,   35,   54 } },  /* 6: not used by a script */
    { {  -37,   37,   35,   54 } },  /* 7: not used by a script */
    { {    6,   47,   35,   54 } },  /* 8: not used by a script */
    { {  -14,   62,   49,   33 } },  /* 9: not used by a script */
    { {  -28,   53,   36,   44 } },  /* 10: TOUKETSU A */
    { {  -20,   49,   36,   36 } },  /* 11: not used by a script */
    { {   -4,   56,   35,   48 } },  /* 12: not used by a script */
    { {  -16,   47,   23,   37 } },  /* 13: not used by a script */
    { {  -16,   47,   13,   37 } },  /* 14: not used by a script */
    { {  -24,   47,   23,   37 } },  /* 15: not used by a script */
    { {  -25,   50,   48,   40 } },  /* 16: V JUMP P S A, F JUMP P S A */
    { {  -22,   69,   40,   61 } },  /* 17: not used by a script */
    { {  -24,   44,   54,   52 } },  /* 18: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { {  -46,   80,    0,   70 } },  /* 19: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    { {  -24,   57,   27,   63 } },  /* 20: not used by a script */
    { {  -38,   63,    0,   80 } },  /* 21: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -25,   50,   48,   40 } },  /* 22: AIR S, AIR M, AIR L +41 */
    { {  -20,   47,   36,   44 } },  /* 23: not used by a script */
    { {  -20,   71,    0,   56 } },  /* 24: not used by a script */
    { {  -18,   44,  -20,   87 } },  /* 25: ATTACK 4 S: not started by a command */
    { {  -22,   49,   12,   82 } },  /* 26: not used by a script */
    { {  -25,   50,    0,   30 } },  /* 27: dmca 97, NEKOROBI S, dmca 96 */
    { {  -25,   50,   24,   40 } },  /* 28: PARING AIR F, PARING AIR B */
};
