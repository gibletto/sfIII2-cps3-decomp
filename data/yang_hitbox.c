/*
 * YANG_HITBOX.C  Yang's hit boxes
 *
 * Each of Yang's animation frames names an entry of yang_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX yang_hit_ix_table[249] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +139 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +35 */
    {    3,    3,    0,    0,    3,    0,    0,    3 },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +18 */
    {    4,    4,    0,    0,    3,    0,    0,    3 },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +13 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 5: not used by a script */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 6: GUARD AIR */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 7: not used by a script */
    {    3,    3,    0,    0,    3,    0,    0,    3 },  /* 8: GUARD AIR */
    {    9,    9,    0,    0,    1,    0,    0,    1 },  /* 9: not used by a script */
    {   14,    0,    0,    0,    1,    0,    0,    1 },  /* 10: M KICK A, follow-up of S KICK A, follow-up of follow-up of S KICK A +1 */
    {   10,   10,    0,    1,    1,    1,    0,    1 },  /* 11: not used by a script */
    {   11,   11,    0,    2,    1,    2,    0,    1 },  /* 12: M KICK A, atca 212 */
    {   11,   11,    0,   48,    1,   48,    0,    1 },  /* 13: M KICK A, follow-up of S KICK A, atca 212 */
    {   11,   11,    0,    0,    1,    0,    0,    1 },  /* 14: M KICK A, follow-up of S KICK A, atca 212 */
    {   12,    0,    0,    0,    1,    0,    0,    1 },  /* 15: M KICK A, follow-up of S KICK A, atca 212 */
    {   15,    0,    0,    0,    1,    0,    0,    1 },  /* 16: not used by a script */
    {   16,    0,    0,    0,    0,    0,    0,   21 },  /* 17: dmca 97, UP P GUARD P S, UP P GUARD P M */
    {   17,    0,    0,    3,    1,    3,    0,    1 },  /* 18: UP P GUARD P S */
    {   17,    0,    0,    4,    1,    4,    0,    1 },  /* 19: UP P GUARD P S, UP P GUARD P M */
    {   17,    0,    0,    0,    1,    0,    0,    1 },  /* 20: UP P GUARD P S, UP P GUARD P M */
    {   18,    0,    0,    0,    1,    0,    0,    1 },  /* 21: not used by a script */
    {   19,    0,    0,    0,    1,    0,    0,    1 },  /* 22: not used by a script */
    {   20,    0,    0,    0,    1,    0,    0,    1 },  /* 23: not used by a script */
    {   21,   21,    0,   60,    1,   60,    0,    1 },  /* 24: UP P GUARD P L */
    {   21,   21,    0,   61,    1,   61,    0,    1 },  /* 25: UP P GUARD P L */
    {   21,   21,    0,    0,    1,    0,    0,    1 },  /* 26: UP P GUARD P L */
    {   23,   23,    0,    0,    1,    0,    0,    1 },  /* 27: S PUNCH A, follow-up of ZANNEN 2 */
    {   24,   24,    0,    6,    1,    6,    0,    1 },  /* 28: S PUNCH A, follow-up of ZANNEN 2 */
    {   24,   24,    0,   39,    1,   39,    0,    1 },  /* 29: S PUNCH A, follow-up of ZANNEN 2 */
    {   25,   25,    0,    0,    1,    0,    0,    1 },  /* 30: M PUNCH B, atca 204 */
    {   26,   26,    0,    7,    1,    7,    0,    1 },  /* 31: M PUNCH B, atca 204 */
    {   26,   26,    0,    0,    1,    0,    0,    1 },  /* 32: not used by a script */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 33: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,   28,    0,    8,    1,    8,    0,    1 },  /* 34: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,   28,    0,   40,    1,   40,    0,    1 },  /* 35: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,   28,    0,    0,    1,    0,    0,    1 },  /* 36: M PUNCH A, follow-up of ZANNEN 4 */
    {   31,   31,    0,    0,    1,    0,    0,    1 },  /* 37: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   31,   31,    0,    9,    1,    9,    0,    1 },  /* 38: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   32,   32,    0,   42,    1,   42,    0,    1 },  /* 39: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   33,   33,    0,   43,    1,   43,    0,    1 },  /* 40: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   33,   33,    0,    0,    1,    0,    0,    1 },  /* 41: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   34,   34,    0,    0,    1,    0,    0,    1 },  /* 42: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    {   35,   35,    0,    0,    1,    0,    0,    1 },  /* 43: follow-up of M PUNCH A / M PUNCH B */
    {   36,   36,    0,   10,    1,   10,    0,    1 },  /* 44: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    {   36,   36,    0,   44,    1,   44,    0,    1 },  /* 45: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    {   36,   36,    0,    0,    1,    0,    0,    1 },  /* 46: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    {   37,   37,    0,    0,    1,    0,    0,    1 },  /* 47: L PUNCH B, follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    {   38,   38,    0,    0,    1,    0,    0,    1 },  /* 48: L PUNCH B */
    {   39,   39,    0,   11,    1,   11,    0,    1 },  /* 49: L PUNCH B */
    {   39,   39,    0,   45,    1,   45,    0,    1 },  /* 50: L PUNCH B */
    {   39,   39,    0,    0,    1,    0,    0,    1 },  /* 51: L PUNCH B */
    {   40,   40,    0,    0,    1,    0,    0,    1 },  /* 52: S KICK A, follow-up of ZANNEN 7 */
    {   41,   41,    0,   12,    1,   12,    0,    1 },  /* 53: not used by a script */
    {   41,   41,    0,   13,    1,   13,    0,    1 },  /* 54: not used by a script */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 55: not used by a script */
    {   41,   41,    0,   46,    1,   46,    0,    1 },  /* 56: S KICK A, follow-up of ZANNEN 7 */
    {   41,   41,    0,   47,    1,   47,    0,    1 },  /* 57: S KICK A, follow-up of ZANNEN 7 */
    {   24,   24,    0,    0,    1,    0,    0,    1 },  /* 58: S PUNCH A, follow-up of ZANNEN 2 */
    {   13,   13,    0,    0,    1,    0,    0,    1 },  /* 59: M KICK A, follow-up of S KICK A, atca 212 */
    {   46,   46,    0,    0,    2,    0,    0,    2 },  /* 60: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    {   47,   47,    0,   14,    2,   14,    0,    2 },  /* 61: follow-up of WIN 2 */
    {   47,   47,    0,   19,    2,   19,    0,    2 },  /* 62: follow-up of WIN 2 */
    {   47,   47,    0,    0,    2,    0,    0,    2 },  /* 63: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    {    2,   48,    0,    0,    2,   56,    0,    2 },  /* 64: KAGAMI P A, follow-up of WIN 4 */
    {    2,   49,    0,    0,    2,   56,    0,    2 },  /* 65: KAGAMI P A, follow-up of WIN 4 */
    {    2,   13,    0,    0,    2,   90,    0,    2 },  /* 66: KAGAMI P A, follow-up of WIN 4 */
    {    2,   59,    0,    0,    2,    0,    0,    2 },  /* 67: KAGAMI K A, follow-up of KAGAMI K A, follow-up of follow-up of KAGAMI K A +2 */
    {    2,   10,    0,    0,    2,   57,    0,    2 },  /* 68: KAGAMI K A, follow-up of KAGAMI K A, follow-up of WIN 5 +1 */
    {    2,   12,    0,    0,    2,   57,    0,    2 },  /* 69: KAGAMI K A, follow-up of KAGAMI K A, follow-up of WIN 5 +1 */
    {    2,   12,    0,    0,    2,    0,    0,    2 },  /* 70: KAGAMI K A, follow-up of KAGAMI K A, follow-up of follow-up of KAGAMI K A +1 */
    {   56,   56,    0,    0,    2,    0,    0,    8 },  /* 71: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    {   57,   57,    0,    0,    2,    0,    0,    8 },  /* 72: follow-up of WIN 7 */
    {   58,   58,    0,   18,    2,   18,    0,    8 },  /* 73: not used by a script */
    {   58,   58,    0,   58,    2,   58,    0,    8 },  /* 74: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    {   58,   58,    0,    0,    2,    0,    0,    8 },  /* 75: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    {   55,   55,    0,    0,    1,    0,    0,    1 },  /* 76: UP P GUARD P S, UP P GUARD P M */
    {   17,   17,    0,    5,    1,    5,    0,    1 },  /* 77: UP P GUARD P M */
    {   22,   22,    0,    0,    1,    0,    0,    1 },  /* 78: UP P GUARD P L */
    {   50,   50,    0,    0,    1,    0,    0,    1 },  /* 79: UP P GUARD P L */
    {  100,  100,    0,    0,    5,    0,    0,    1 },  /* 80: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +2 */
    {   53,   53,    0,    0,    5,    0,    0,    1 },  /* 81: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command +6 */
    {   51,   51,    0,    0,    3,    0,    0,    1 },  /* 82: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +5 */
    {   52,   52,    0,    0,    3,    0,    0,    1 },  /* 83: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +4 */
    {   61,   61,    0,    0,    1,    0,    0,    1 },  /* 84: OKIAGARI P S */
    {   62,   62,    0,    0,    1,    0,    0,    1 },  /* 85: not used by a script */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 86: GUARD HEAD */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 87: GUARD UP, P BREAK ZUJOU, TUKAMIHAZUSI */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 88: GUARD DOWN, P BREAK DOWN */
    {   72,   72,    0,    0,    1,    0,    0,    1 },  /* 89: DASH HUMIKOMI */
    {   73,   73,    0,    0,    1,    0,    0,    1 },  /* 90: DASH HUMIKOMI */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 91: TATAKI S, OKIAGARI, OKIAGARI F +16 */
    {   74,   74,    0,    0,    0,    0,    0,    0 },  /* 92: not used by a script */
    {   47,   47,    0,   54,    2,   54,    0,    2 },  /* 93: KAGAMI P A, follow-up of WIN 3 */
    {   47,   47,    0,   55,    2,   55,    0,    2 },  /* 94: KAGAMI P A, follow-up of WIN 3 */
    {    2,   14,    0,    0,    2,   84,    0,    2 },  /* 95: KAGAMI P A, follow-up of WIN 4 */
    {    2,   15,    0,    0,    2,    0,    0,    2 },  /* 96: KAGAMI P A, follow-up of WIN 4 */
    {  107,  107,    0,    0,    1,    0,    0,    1 },  /* 97: follow-up of HANASARE / APPEAR JUNBI 2, follow-up of SP APPEAR 2, follow-up of APPEAR JUNBI 5 +14 */
    {   79,   79,    0,    0,    1,    0,    0,    1 },  /* 98: M KICK C, follow-up of JUDGMENT WAIT */
    {   80,   80,    0,    0,    1,    0,    0,    1 },  /* 99: M KICK C, follow-up of JUDGMENT WAIT */
    {   81,   81,    0,    0,    4,    0,    0,    4 },  /* 100: M KICK C, follow-up of JUDGMENT WAIT */
    {   82,   82,    0,    0,    4,    0,    0,    4 },  /* 101: M KICK C, follow-up of JUDGMENT WAIT */
    {   42,   42,    0,    0,    4,    0,    0,    4 },  /* 102: M KICK C, follow-up of JUDGMENT WAIT */
    {   43,   43,    0,   20,    1,   20,    0,    1 },  /* 103: M KICK C, follow-up of JUDGMENT WAIT, exca 13 */
    {   83,   83,    0,    0,   17,    0,    0,   18 },  /* 104: not used by a script */
    {   83,   83,    0,   22,   17,   22,    0,   18 },  /* 105: not used by a script */
    {   84,   84,    0,   23,   17,   23,    0,   18 },  /* 106: not used by a script */
    {   84,   84,    0,    0,   17,    0,    0,   18 },  /* 107: not used by a script */
    {   85,   85,    0,    0,    1,    0,    0,    1 },  /* 108: ATTACK 12 M: not started by a command */
    {   86,   86,    0,    0,    1,    0,    0,    1 },  /* 109: ATTACK 12 M: not started by a command */
    {   87,   87,    0,   24,    1,   24,    0,    1 },  /* 110: ATTACK 12 M: not started by a command */
    {   88,   88,    0,   25,    1,   25,    0,    1 },  /* 111: ATTACK 12 M: not started by a command */
    {   89,   89,    0,    0,    1,    0,    0,    1 },  /* 112: ATTACK 12 M: not started by a command */
    {   90,   90,    0,   26,    1,   26,    0,    1 },  /* 113: ATTACK 2 S: not started by a command, ATTACK 11 M: not started by a command */
    {   90,   90,    0,   27,    1,   27,    0,    1 },  /* 114: ATTACK 2 S: not started by a command, ATTACK 11 M: not started by a command */
    {  138,  138,    0,   27,    1,   27,    0,    1 },  /* 115: ATTACK 2 S: not started by a command, ATTACK 11 M: not started by a command */
    {   93,   93,    0,    0,    4,    0,    0,    4 },  /* 116: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   91,   91,    0,    0,    4,    0,    0,    4 },  /* 117: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command */
    {   91,   91,    0,   29,    4,   29,    0,    4 },  /* 118: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command */
    {   92,   92,    0,    0,    4,    0,    0,    4 },  /* 119: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command */
    {   93,   93,    0,   30,    3,   30,    0,    3 },  /* 120: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   94,   94,    0,   31,    4,   31,    0,    4 },  /* 121: ATTACK 5 S: not started by a command */
    {   94,   94,    0,    0,    3,    0,    0,    3 },  /* 122: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   95,   95,    0,    0,    4,    0,    0,    4 },  /* 123: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   96,   96,    0,    0,    2,    0,    0,    2 },  /* 124: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command +2 */
    {   97,   97,    0,    0,    2,    0,    0,    2 },  /* 125: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 11 L: not started by a command */
    {   97,   97,    0,    0,    2,    0,    0,    2 },  /* 126: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 11 L: not started by a command */
    {   97,   97,    0,   32,    2,   32,    0,    2 },  /* 127: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +4 */
    {   99,   99,    0,   33,    2,   33,    0,    2 },  /* 128: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command +5 */
    {  100,    0,    0,   34,    5,   34,    0,    1 },  /* 129: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +4 */
    {  100,    0,    0,   64,    5,   64,    0,    1 },  /* 130: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command +5 */
    {  103,  103,    0,    0,    3,    0,    0,    3 },  /* 131: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    {  104,  104,    0,    0,    3,    0,    0,    3 },  /* 132: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {  105,  105,    0,   37,    3,   37,    0,    3 },  /* 133: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {  105,  105,    0,   38,    3,   38,    0,    3 },  /* 134: not used by a script */
    {  106,  106,    0,    0,    3,    0,    0,    3 },  /* 135: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    {   29,   29,    0,   41,    1,   41,    0,    1 },  /* 136: M PUNCH B, atca 204 */
    {   29,   29,    0,    0,    1,    0,    0,    1 },  /* 137: M PUNCH B, atca 204 */
    {   30,   30,    0,    0,    1,    0,    0,    1 },  /* 138: M PUNCH B, atca 204 */
    {  101,  101,    0,    0,    3,    0,    0,    3 },  /* 139: V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {  102,  102,    0,   35,    3,   35,    0,    3 },  /* 140: F JUMP P S A, follow-up of SEAN BALL HIT */
    {  102,  102,    0,   36,    3,   36,    0,    3 },  /* 141: V JUMP P S A, follow-up of JUDGMENT LOSE */
    {  105,  105,    0,   49,    3,   49,    0,    3 },  /* 142: F JUMP P L A, follow-up of BONUS WIN 1 */
    {  105,  105,    0,   50,    3,   50,    0,    3 },  /* 143: F JUMP P L A, follow-up of BONUS WIN 1 */
    {  105,  105,    0,    0,    3,    0,    0,    3 },  /* 144: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {   44,   44,    0,   21,    1,   21,    0,    1 },  /* 145: M KICK C, follow-up of JUDGMENT WAIT */
    {   45,   45,    0,    0,    1,    0,    0,    1 },  /* 146: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    {    1,    1,    0,   53,    1,   53,    0,    1 },  /* 147: M PUNCH A, M PUNCH B, L PUNCH A +5 */
    {  110,  110,    0,    0,    1,    0,    0,    1 },  /* 148: not used by a script */
    {  111,  111,    0,    0,    1,    0,    0,    1 },  /* 149: not used by a script */
    {  112,  112,    0,    0,    1,    0,    0,    1 },  /* 150: not used by a script */
    {  113,  113,    0,   62,    1,   62,    0,    1 },  /* 151: not used by a script */
    {  113,  113,    0,   63,    1,   63,    0,    1 },  /* 152: not used by a script */
    {  113,  113,    0,    0,    1,    0,    0,    1 },  /* 153: not used by a script */
    {  114,  114,    0,    0,    1,    0,    0,    1 },  /* 154: follow-up of SP APPEAR 3 / JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    {  115,  115,    0,    0,    1,    0,    0,    1 },  /* 155: follow-up of SP APPEAR 3 / JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    {   63,   63,    0,   65,    2,   65,    0,    9 },  /* 156: ATTACK 6 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   98,   98,    0,   66,    2,   66,    0,    9 },  /* 157: not used by a script */
    {   64,   64,    0,    0,    3,    0,    0,    3 },  /* 158: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   65,   65,    0,    0,    3,    0,    0,    3 },  /* 159: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   66,   66,    0,   67,    3,   67,    0,    3 },  /* 160: not used by a script */
    {   66,   66,    0,   68,    3,   68,    0,    3 },  /* 161: not used by a script */
    {   66,   66,    0,   69,    3,   69,    0,    3 },  /* 162: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   66,   66,    0,   70,    3,   70,    0,    3 },  /* 163: not used by a script */
    {   66,   66,    0,   71,    3,   71,    0,    3 },  /* 164: not used by a script */
    {   66,   66,    0,   72,    3,   72,    0,    3 },  /* 165: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   66,   66,    0,   73,    3,   73,    0,    3 },  /* 166: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   67,   67,    0,    0,    3,    0,    0,    3 },  /* 167: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    {   68,   68,    0,   74,    3,   74,    0,    3 },  /* 168: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    {   68,   68,    0,   75,    3,   75,    0,    3 },  /* 169: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    {   68,   68,    0,    0,    3,    0,    0,    3 },  /* 170: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +1 */
    {  118,  118,    0,    0,    3,    0,    0,    3 },  /* 171: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    {  116,  116,    0,    0,    3,    0,    0,    3 },  /* 172: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    {  117,  117,    0,    0,    3,    0,    0,    3 },  /* 173: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    {  118,  118,    0,   78,    3,   78,    0,    3 },  /* 174: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    {  118,  118,    0,   79,    3,   79,    0,    3 },  /* 175: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    {  118,  118,    0,   80,    3,   80,    0,    3 },  /* 176: not used by a script */
    {  118,  118,    0,   81,    3,   81,    0,    3 },  /* 177: not used by a script */
    {  119,  119,    0,    0,    3,    0,    0,    3 },  /* 178: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    {  120,  120,    0,    0,    3,    0,    0,    3 },  /* 179: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    {  121,  121,    0,   82,    3,   82,    0,    3 },  /* 180: F JUMP K S B, F JUMP K M B, F JUMP K L B +3 */
    {  121,  121,    0,   83,    3,   83,    0,    3 },  /* 181: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    {  122,  122,    0,    0,    1,    0,    0,    1 },  /* 182: follow-up of SP APPEAR 4 */
    {  123,  123,    0,    0,    1,    0,    0,    1 },  /* 183: follow-up of APPEAR 4 */
    {  124,  124,    0,    0,    1,    0,    0,    1 },  /* 184: follow-up of APPEAR 5 */
    {  125,  125,    0,    0,    1,    0,    0,    1 },  /* 185: follow-up of APPEAR 5 */
    {  126,  126,    0,   84,    1,    0,    0,    1 },  /* 186: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    {  127,  127,    0,    0,    1,    0,    0,    1 },  /* 187: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    {  128,  128,    0,    0,   17,    0,    0,   19 },  /* 188: AIR S, AIR M, AIR L +38 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 189: ATTACK 5 S: not started by a command, ATTACK 6 S: not started by a command, ATTACK 7 S: not started by a command +1 */
    {    0,    0,    0,   51,    0,   51,    0,    1 },  /* 190: not used by a script */
    {   29,   29,    0,   52,    1,   52,    0,    1 },  /* 191: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 192: AIR S, AIR M, AIR L +2 */
    {  131,  131,    0,    0,    6,    0,    0,    1 },  /* 193: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    {  132,  132,    0,    0,    1,    0,    0,    2 },  /* 194: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command +2 */
    {  133,  133,    0,   85,    1,   85,    0,    1 },  /* 195: L KICK A, follow-up of follow-up of S KICK A, atca 215 */
    {  133,  133,    0,   86,    1,   86,    0,    1 },  /* 196: L KICK A, follow-up of follow-up of S KICK A, atca 215 */
    {  134,  134,    0,    0,    1,    0,    0,    1 },  /* 197: L KICK A, follow-up of follow-up of S KICK A, atca 215 */
    {   98,   98,    0,   87,    2,   87,    0,    2 },  /* 198: ATTACK 13 SP: not started by a command */
    {   99,   99,    0,   88,    1,   88,    0,    2 },  /* 199: ATTACK 13 SP: not started by a command */
    {   17,   17,    0,   89,    1,   89,    0,    1 },  /* 200: not used by a script */
    {    1,    1,    0,   90,    1,    0,    0,    1 },  /* 201: L KICK A */
    {  136,  136,    0,    0,    1,    0,    0,    1 },  /* 202: ATTACK 2 S: not started by a command, ATTACK 2 SP: not started by a command, not started by a command */
    {  137,  137,    0,   91,    3,   91,    0,    3 },  /* 203: ATTACK 12 L: not started by a command, not started by a command */
    {    0,    0,    0,    0,    0,    0,    0,   21 },  /* 204: NEKOROBI S, dmca 96 */
    {  133,  133,    0,    0,    1,    0,    0,    1 },  /* 205: L KICK A, follow-up of follow-up of S KICK A */
    {   46,   46,    0,    0,   18,    0,    0,    2 },  /* 206: KAGAMI P A */
    {   47,   47,    0,   14,   18,   14,    0,    2 },  /* 207: KAGAMI P A */
    {   47,   47,    0,   19,   18,   19,    0,    2 },  /* 208: KAGAMI P A */
    {   47,   47,    0,    0,   18,    0,    0,    2 },  /* 209: KAGAMI P A */
    {   59,    0,    0,    0,   18,    0,    0,    2 },  /* 210: KAGAMI K A */
    {   54,   54,    0,   17,   18,   17,    0,    2 },  /* 211: KAGAMI K A */
    {   54,   54,    0,    0,   18,    0,    0,    2 },  /* 212: KAGAMI K A */
    {  100,  100,    0,   92,    5,   92,    0,    1 },  /* 213: ATTACK 13 SP: not started by a command */
    {  107,  107,    0,    0,    1,    0,    0,    1 },  /* 214: HANASARE */
    {   66,   66,    0,    0,    3,    0,    0,    3 },  /* 215: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 216: LOSE SONABA */
    {  132,  132,    0,   65,    1,   65,    0,    2 },  /* 217: ATTACK 11 SP: not started by a command, ATTACK 12 S: not started by a command */
    {  138,  138,    0,    0,    1,    0,    0,    1 },  /* 218: follow-up of follow-up of M PUNCH A / M PUNCH B, ATTACK 2 S: not started by a command */
    {  138,  138,    0,   26,    1,   26,    0,    1 },  /* 219: follow-up of follow-up of M PUNCH A / M PUNCH B */
    {   14,   14,    0,    0,    1,   28,    0,    1 },  /* 220: follow-up of S KICK A */
    {   11,   11,    0,    2,    1,   93,    0,    1 },  /* 221: follow-up of S KICK A */
    {  139,  139,    0,    0,    3,   80,    0,    3 },  /* 222: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  139,  140,    0,    0,    3,   81,    0,    3 },  /* 223: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  139,  140,    0,    0,    3,    0,    0,    3 },  /* 224: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  140,    0,    0,    0,    3,    0,    0,    3 },  /* 225: FUSHIN P S */
    {  141,    0,    0,    0,    3,    0,    0,    3 },  /* 226: FUSHIN P S */
    {  142,  141,    0,    0,    3,   94,    0,    3 },  /* 227: FUSHIN P S */
    {  143,  142,    0,    0,    3,   95,    0,    3 },  /* 228: FUSHIN P S */
    {    1,   20,    0,    0,    1,   96,    0,    1 },  /* 229: not started by a command */
    {  144,    1,    0,    0,    1,    0,    0,   22 },  /* 230: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  144,   16,    0,    0,    1,   97,    0,   22 },  /* 231: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  144,   16,    0,    0,    1,    0,    0,   22 },  /* 232: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  145,    0,    0,    0,    1,    0,    0,   22 },  /* 233: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  145,   17,    0,    0,    1,   98,    0,   22 },  /* 234: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  145,   17,    0,    0,    1,    0,    0,   22 },  /* 235: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  146,    0,    0,    0,    1,    0,    0,   22 },  /* 236: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  146,   18,    0,    0,    1,   99,    0,   22 },  /* 237: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  146,   18,    0,    0,    1,  100,    0,   22 },  /* 238: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  146,   18,    0,    0,    1,    0,    0,   22 },  /* 239: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    {  146,   18,    0,    0,    1,    0,    0,    0 },  /* 240: not started by a command */
    {    0,    0,    0,    0,    0,  101,    0,    1 },  /* 241: ATTACK 7 S: not started by a command, ATTACK 8 S: not started by a command */
    {  147,    0,    0,    0,    1,  101,    0,    1 },  /* 242: ATTACK 7 S: not started by a command, ATTACK 8 S: not started by a command */
    {  147,   19,    0,    0,    1,    0,    0,    1 },  /* 243: ATTACK 7 S: not started by a command, ATTACK 8 S: not started by a command */
    {    1,    0,    0,    0,    1,    0,    0,    0 },  /* 244: ATTACK 8 S: not started by a command */
    {    1,    0,    0,    0,    1,  102,    0,    0 },  /* 245: ATTACK 8 S: not started by a command */
    {  144,    0,    0,    0,    1,   97,    0,   22 },  /* 246: ATTACK 4 SP: not started by a command */
    {  148,    0,    0,   34,    5,   34,    0,    1 },  /* 247: ATTACK 3 SP: not started by a command */
    {  121,  121,    0,    0,    3,  103,    0,    3 },  /* 248: follow-up of F JUMP K M A */
};

const BODY_BOX yang_body_box[149] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -15,  26,  71,  19 },  {  -29,  53,  70,   7 },  {  -29,  53,  34,  35 },  {  -34,  58,   0,  32 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +139 */
    { { {  -12,  27,  46,  20 },  {  -32,  62,  41,  17 },  {    0,   0,   0,   0 },  {  -44,  82,   0,  42 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +37 */
    { { {   -7,  19,  98,  20 },  {  -21,  50,  88,  14 },  {  -16,  44,  70,  20 },  {  -24,  48,  32,  36 } } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +19 */
    { { {   -7,  19,  98,  20 },  {  -21,  50,  88,  14 },  {  -16,  44,  70,  20 },  {  -24,  48,  32,  36 } } },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +13 */
    { { {    6,  22,  74,  14 },  {   -8,  44,  60,  14 },  {   -2,  38,  36,  22 },  {  -26,  54,   0,  34 } } },  /* 5: not used by a script */
    { { {   -4,  18,  74,  14 },  {  -18,  46,  62,  14 },  {   -6,  36,  36,  26 },  {  -28,  56,   0,  34 } } },  /* 6: not used by a script */
    { { {   -4,  18,  46,  14 },  {    0,   0,   0,   0 },  {  -20,  48,  34,  18 },  {  -26,  54,   0,  32 } } },  /* 7: not used by a script */
    { { {  -18,  18,  68,  14 },  {  -30,  48,  58,  14 },  {  -24,  42,  36,  22 },  {  -24,  40,  14,  20 } } },  /* 8: not used by a script */
    { { {    0,  25,  79,  20 },  {  -16,  53,  67,  16 },  {  -32,  63,  21,  47 },  {  -21,  48,   0,  34 } } },  /* 9: not used by a script */
    { { {   18,  26,  68,  21 },  {  -11,  53,  57,  24 },  {  -36,  69,  44,  22 },  {  -20,  49,   0,  56 } } },  /* 10: not used by a script */
    { { {   13,  40,  70,  16 },  {   -2,  44,  60,  16 },  {  -46,  53,  40,  50 },  {  -40,  65,   0,  56 } } },  /* 11: M KICK A, atca 212, follow-up of S KICK A */
    { { {   16,  29,  70,  19 },  {  -19,  63,  65,  16 },  {  -64, 104,  42,  24 },  {  -32,  61,   0,  36 } } },  /* 12: M KICK A, follow-up of S KICK A, atca 212 */
    { { {    6,  28,  70,  21 },  {  -35,  72,  58,  16 },  {  -58,  94,  27,  31 },  {  -32,  58,   0,  34 } } },  /* 13: M KICK A, follow-up of S KICK A, atca 212 */
    { { {    5,  27,  74,  21 },  {  -17,  60,  64,  16 },  {  -31,  76,  38,  28 },  {  -32,  61,   0,  36 } } },  /* 14: M KICK A, follow-up of S KICK A, follow-up of follow-up of S KICK A +1 */
    { { {  -10,  16,  74,  14 },  {  -26,  46,  62,  14 },  {  -16,  34,  34,  26 },  {  -38,  60,   0,  32 } } },  /* 15: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 16: dmca 97, UP P GUARD P S, UP P GUARD P M */
    { { {  -28,  16,  68,  14 },  {  -32,  44,  58,  12 },  {  -16,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 17: UP P GUARD P S, UP P GUARD P M */
    { { {   -6,  16,  70,  14 },  {  -20,  46,  58,  12 },  {  -20,  46,  36,  22 },  {  -22,  50,   0,  34 } } },  /* 18: not used by a script */
    { { {   -6,  16,  70,  14 },  {  -20,  46,  58,  12 },  {  -20,  46,  36,  22 },  {  -22,  50,   0,  34 } } },  /* 19: not used by a script */
    { { {  -20,  16,  60,  14 },  {  -22,  40,  54,  14 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 20: not used by a script */
    { { {  -26,  16,  64,  14 },  {  -34,  46,  56,  12 },  {  -24,  30,  36,  22 },  {  -40,  74,   0,  34 } } },  /* 21: UP P GUARD P L */
    { { {  -20,  16,  68,  14 },  {  -28,  46,  58,  12 },  {  -22,  30,  36,  22 },  {  -40,  66,   0,  34 } } },  /* 22: UP P GUARD P L */
    { { {  -23,  20,  70,  16 },  {  -37,  61,  54,  18 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 23: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -23,  20,  70,  16 },  {  -37,  61,  54,  18 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 24: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -23,  37,  69,  16 },  {  -37,  66,  54,  18 },  {  -37,  64,  34,  22 },  {  -57,  87,   0,  32 } } },  /* 25: M PUNCH B, atca 204 */
    { { {  -30,  29,  67,  16 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -46,  87,   0,  32 } } },  /* 26: M PUNCH B, atca 204 */
    { { {  -18,  20,  70,  16 },  {  -31,  54,  54,  18 },  {  -26,  44,  34,  22 },  {  -42,  66,   0,  32 } } },  /* 27: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -18,  21,  70,  18 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -55,  98,   0,  32 } } },  /* 28: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -24,  16,  66,  14 },  {  -30,  60,  58,  10 },  {  -37,  66,  34,  22 },  {  -52,  87,   0,  32 } } },  /* 29: M PUNCH B, atca 204 */
    { { {  -30,  29,  67,  16 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -46,  87,   0,  32 } } },  /* 30: M PUNCH B, atca 204 */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 31: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 32: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 33: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -30,  26,  68,  21 },  {  -60,  88,  62,  17 },  {  -42,  69,  34,  35 },  {  -34,  58,   0,  32 } } },  /* 34: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -28,  16,  66,  14 },  {  -30,  46,  60,  12 },  {  -16,  36,  34,  24 },  {  -38,  68,   0,  34 } } },  /* 35: follow-up of M PUNCH A / M PUNCH B */
    { { {  -32,  30,  64,  20 },  {  -38,  67,  59,  12 },  {  -40,  65,  36,  22 },  {  -56,  95,   0,  34 } } },  /* 36: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -23,  28,  66,  21 },  {  -61,  89,  56,  14 },  {  -36,  57,  36,  20 },  {  -55,  88,   0,  34 } } },  /* 37: L PUNCH B, follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -28,  16,  66,  14 },  {  -30,  46,  60,  12 },  {  -16,  36,  34,  24 },  {  -38,  68,   0,  34 } } },  /* 38: L PUNCH B */
    { { {  -26,  16,  64,  14 },  {  -38,  56,  56,  12 },  {  -24,  36,  36,  20 },  {  -38,  68,   0,  34 } } },  /* 39: L PUNCH B */
    { { {  -14,  16,  78,  14 },  {  -28,  46,  68,  12 },  {  -16,  30,  38,  28 },  {  -30,  54,   0,  36 } } },  /* 40: S KICK A, follow-up of ZANNEN 7 */
    { { {  -12,  23,  79,  19 },  {  -30,  54,  68,  16 },  {  -40,  72,  40,  30 },  {  -37,  61,   0,  41 } } },  /* 41: S KICK A, follow-up of ZANNEN 7 */
    { { {  -20,  36,  86,  19 },  {  -51,  86,  76,  12 },  {  -43,  60,  23,  54 },  {    0,   0,   0,   0 } } },  /* 42: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -17,  26,  87,  19 },  {  -48,  89,  78,  12 },  {  -37,  66,  44,  35 },  {  -36,  60,   0,  42 } } },  /* 43: M KICK C, follow-up of JUDGMENT WAIT, exca 13 */
    { { {  -17,  26,  81,  19 },  {  -48,  80,  73,  12 },  {  -37,  66,  44,  35 },  {  -36,  60,   0,  42 } } },  /* 44: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -17,  26,  76,  19 },  {  -48,  94,  67,  12 },  {  -37,  66,  44,  25 },  {  -36,  60,   0,  42 } } },  /* 45: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    { { {  -24,  34,  47,  20 },  {  -41,  69,  36,  16 },  {    0,   0,   0,   0 },  {  -39,  78,   0,  36 } } },  /* 46: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    { { {  -31,  49,  51,  20 },  {  -41,  69,  40,  16 },  {    0,   0,   0,   0 },  {  -46,  79,   0,  40 } } },  /* 47: follow-up of WIN 2, KAGAMI P A, follow-up of WIN 3 */
    { { {  -26,  34,  55,  20 },  {  -55,  81,  36,  30 },  {    0,   0,   0,   0 },  {  -52,  83,   0,  36 } } },  /* 48: not used by a script */
    { { {  -26,  41,  55,  20 },  {  -54,  89,  36,  20 },  {    0,   0,   0,   0 },  {  -55,  89,   0,  36 } } },  /* 49: not used by a script */
    { { {  -28,  16,  68,  14 },  {  -32,  46,  58,  14 },  {  -22,  34,  34,  26 },  {  -36,  64,   0,  32 } } },  /* 50: UP P GUARD P L */
    { { {    2,  16,  80,  14 },  {  -16,  44,  70,  14 },  {  -38,  64,  54,  16 },  {  -26,  50,  34,  18 } } },  /* 51: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +5 */
    { { {  -12,  16,  82,  14 },  {  -22,  44,  72,  14 },  {  -12,  30,  46,  24 },  {  -26,  42,   8,  36 } } },  /* 52: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +4 */
    { { {  -36,  22,  64,  28 },  {  -28,  56,  52,  14 },  {  -30,  64,  40,  14 },  {   14,  16,  22,  24 } } },  /* 53: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command +6 */
    { { {    3,  30,  48,  23 },  {  -34,  69,  39,  19 },  {  -35,  69,  16,  23 },  {  -36,  70,   0,  16 } } },  /* 54: KAGAMI K A */
    { { {  -28,  16,  68,  14 },  {  -32,  44,  58,  12 },  {  -16,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 55: UP P GUARD P S, UP P GUARD P M */
    { { {   -3,  32,  52,  21 },  {  -36,  78,  39,  18 },  {  -43,  90,   0,  41 },  {    0,   0,   0,   0 } } },  /* 56: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { { {   -4,  24,  56,  14 },  {  -34,  71,  40,  18 },  {  -55,  99,   0,  41 },  {    0,   0,   0,   0 } } },  /* 57: follow-up of WIN 7 */
    { { {  -12,  35,  56,  15 },  {  -42,  69,  33,  26 },  {  -52,  87,   0,  34 },  {  -48,  80,   0,  18 } } },  /* 58: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { { {    3,  30,  48,  23 },  {  -34,  69,  39,  19 },  {  -35,  69,  16,  23 },  {  -36,  70,   0,  16 } } },  /* 59: KAGAMI K A */
    { { {  -36,  22,  64,  28 },  {  -28,  56,  52,  14 },  {  -30,  64,  40,  14 },  {   14,  16,  22,  24 } } },  /* 60: not used by a script */
    { { {    2,  16,  72,  14 },  {  -16,  44,  62,  14 },  {  -38,  64,  46,  16 },  {  -26,  50,  26,  18 } } },  /* 61: OKIAGARI P S */
    { { {   -4,  16,  68,  14 },  {  -16,  44,  56,  14 },  {  -24,  52,  38,  16 },  {  -32,  50,   8,  28 } } },  /* 62: not used by a script */
    { { {  -16,  36,  20,  10 },  {    0,   0,   0,   0 },  {  -18,  40,   0,  18 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 6 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {  -16,  16,  96,  14 },  {  -28,  44,  86,  14 },  {  -12,  32,  62,  22 },  {  -30,  46,  46,  26 } } },  /* 64: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -26,  16,  96,  14 },  {  -34,  46,  84,  14 },  {  -12,  40,  60,  22 },  {  -24,  46,  40,  22 } } },  /* 65: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -34,  16,  96,  14 },  {  -40,  52,  86,  14 },  {  -20,  56,  62,  22 },  {  -16,  32,  28,  32 } } },  /* 66: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -16,  16,  96,  14 },  {  -28,  44,  86,  18 },  {  -12,  32,  62,  22 },  {  -36,  46,  46,  26 } } },  /* 67: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -20,  16,  96,  14 },  {  -28,  42,  86,  18 },  {  -28,  46,  68,  16 },  {  -20,  36,  32,  36 } } },  /* 68: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    { { {    6,  22,  74,  14 },  {    1,  34,  60,  14 },  {   -2,  38,  36,  22 },  {  -26,  54,   0,  34 } } },  /* 69: not used by a script */
    { { {   -4,  18,  74,  14 },  {  -18,  46,  62,  14 },  {    2,  22,  36,  26 },  {  -21,  49,   0,  34 } } },  /* 70: not used by a script */
    { { {   -4,  18,  47,  14 },  {    0,   0,   0,   0 },  {  -20,  48,  35,  14 },  {  -20,  50,   0,  30 } } },  /* 71: not used by a script */
    { { {  -11,  16,  61,  14 },  {  -15,  39,  49,  14 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 72: DASH HUMIKOMI */
    { { {  -31,  26,  76,  14 },  {  -32,  57,  65,  14 },  {  -32,  57,  42,  22 },  {  -36,  64,  10,  34 } } },  /* 73: DASH HUMIKOMI */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -23,  35,   0,  47 },  {    0,   0,   0,   0 } } },  /* 74: not used by a script */
    { { {    1,  16,  77,  14 },  {  -11,  46,  62,  14 },  {   -1,  34,  36,  22 },  {  -17,  54,   0,  34 } } },  /* 75: not used by a script */
    { { {   13,  16,  83,  14 },  {    5,  35,  65,  16 },  {   11,  28,  36,  29 },  {   -4,  42,   0,  34 } } },  /* 76: not used by a script */
    { { {   13,  16,  98,  14 },  {    5,  35,  82,  16 },  {    2,  28,  44,  36 },  {  -17,  40,  69,  25 } } },  /* 77: not used by a script */
    { { {   13,  16,  98,  14 },  {    5,  35,  82,  16 },  {    2,  28,  44,  36 },  {    0,   0,   0,   0 } } },  /* 78: not used by a script */
    { { {   -8,  29,  79,  15 },  {  -24,  45,  66,  12 },  {  -32,  63,  34,  31 },  {  -25,  65,   0,  34 } } },  /* 79: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -12,  28,  79,  22 },  {  -28,  53,  71,  12 },  {  -32,  63,  34,  36 },  {  -21,  57,   0,  34 } } },  /* 80: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -19,  32,  82,  18 },  {  -29,  72,  74,  13 },  {  -28,  60,  27,  49 },  {    0,   0,   0,   0 } } },  /* 81: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -16,  29,  87,  19 },  {  -38,  93,  77,  15 },  {  -48,  74,  24,  52 },  {    0,   0,   0,   0 } } },  /* 82: M KICK C, follow-up of JUDGMENT WAIT */
    { { {   -4,  16,  85,  14 },  {  -20,  31,  66,  19 },  {  -11,  36,  28,  37 },  {    0,   0,   0,   0 } } },  /* 83: not used by a script */
    { { {   -4,  16,  85,  14 },  {  -20,  31,  66,  19 },  {  -11,  36,  28,  37 },  {  -42,  35,  55,  17 } } },  /* 84: not used by a script */
    { { {  -20,  16,  64,  14 },  {  -28,  46,  56,  12 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 85: ATTACK 12 M: not started by a command */
    { { {  -24,  16,  58,  14 },  {  -28,  46,  50,  12 },  {  -12,  34,  32,  22 },  {  -18,  50,   0,  32 } } },  /* 86: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -32,  57,  36,  22 },  {  -77, 135,   7,  29 } } },  /* 87: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -16,  34,  36,  22 },  {  -77, 135,   7,  29 } } },  /* 88: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  68,  14 },  {  -28,  46,  58,  14 },  {  -16,  34,  36,  22 },  {  -71, 124,   5,  30 } } },  /* 89: ATTACK 12 M: not started by a command */
    { { {  -24,  16,  68,  14 },  {  -22,  32,  58,  12 },  {  -10,  30,  36,  22 },  {  -30,  54,   0,  36 } } },  /* 90: ATTACK 2 S: not started by a command, ATTACK 11 M: not started by a command */
    { { {  -11,  23,  81,  18 },  {  -20,  46,  71,  15 },  {  -37,  58,  32,  39 },  {    0,   0,   0,   0 } } },  /* 91: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command */
    { { {    6,  16,  86,  14 },  {  -10,  42,  72,  14 },  {  -22,  42,  46,  20 },  {   -8,  28,  16,  36 } } },  /* 92: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command */
    { { {   -4,  16,  92,  14 },  {  -12,  40,  80,  14 },  {  -14,  30,  56,  22 },  {  -14,  22,  18,  40 } } },  /* 93: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {   -4,  16,  92,  14 },  {  -12,  40,  80,  14 },  {  -14,  30,  56,  22 },  {  -14,  22,  18,  40 } } },  /* 94: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {  -10,  16,  84,  14 },  {  -20,  40,  74,  12 },  {  -10,  30,  50,  22 },  {  -22,  32,  18,  34 } } },  /* 95: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {  -28,  16,  46,  14 },  {  -12,  36,  48,  12 },  {    0,   0,   0,   0 },  {  -18,  54,   0,  32 } } },  /* 96: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command +2 */
    { { {  -30,  53,  48,  12 },  {    0,   0,   0,   0 },  {  -50,  72,   0,  47 },  {    0,   0,   0,   0 } } },  /* 97: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 11 L: not started by a command +5 */
    { { {  -26,  50,  36,  10 },  {    0,   0,   0,   0 },  {  -43,  73,  13,  35 },  {   14,  18,   0,  16 } } },  /* 98: ATTACK 13 SP: not started by a command */
    { { {  -26,  26,  48,  22 },  {  -30,  54,  40,  14 },  {  -43,  76,  22,  37 },  {   16,  20,   0,  24 } } },  /* 99: OKIAGARI P S, ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command +6 */
    { { {  -44,  37,  36,  73 },  {  -32,  58,  52,  14 },  {  -36,  70,  34,  16 },  {   10,  16,   0,  36 } } },  /* 100: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command +6 */
    { { {  -20,  16,  96,  14 },  {  -26,  42,  88,  14 },  {  -12,  30,  74,  16 },  {  -26,  44,  52,  20 } } },  /* 101: V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -24,  16,  96,  14 },  {  -34,  46,  88,  14 },  {  -16,  48,  72,  14 },  {  -25,  54,  44,  34 } } },  /* 102: F JUMP P S A, follow-up of SEAN BALL HIT, V JUMP P S A +1 */
    { { {  -20,  16,  96,  14 },  {  -26,  42,  86,  14 },  {  -10,  28,  72,  16 },  {  -30,  48,  54,  20 } } },  /* 103: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {  -26,  16,  92,  14 },  {  -20,  36,  84,  14 },  {   -8,  28,  72,  16 },  {  -28,  56,  56,  20 } } },  /* 104: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    { { {  -26,  36,  90,  14 },  {  -34,  48,  76,  12 },  {  -42,  14,  68,  12 },  {  -24,  62,  56,  20 } } },  /* 105: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +3 */
    { { {  -22,  16,  92,  14 },  {  -20,  36,  86,  14 },  {  -12,  30,  72,  16 },  {  -28,  56,  56,  20 } } },  /* 106: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {  -10,  16,  86,  14 },  {   -4,  28,  64,  28 },  {  -20,  44,  38,  24 },  {   -4,  28,   0,  36 } } },  /* 107: follow-up of HANASARE / APPEAR JUNBI 2, follow-up of SP APPEAR 2, follow-up of APPEAR JUNBI 5 +14 */
    { { {  -33,  16,  96,  14 },  {  -20,  40,  90,  14 },  {   -4,  28,  72,  20 },  {  -20,  42,  54,  20 } } },  /* 108: not used by a script */
    { { {  -33,  16,  96,  14 },  {  -20,  40,  90,  14 },  {   -4,  28,  72,  20 },  {  -20,  42,  54,  20 } } },  /* 109: not used by a script */
    { { {  -18,  16,  74,  14 },  {  -26,  44,  68,  12 },  {   -6,  28,  38,  28 },  {  -26,  32,  16,  26 } } },  /* 110: not used by a script */
    { { {  -10,  16,  76,  14 },  {  -26,  44,  68,  12 },  {  -10,  30,  44,  22 },  {  -26,  34,  30,  26 } } },  /* 111: not used by a script */
    { { {    2,  16,  78,  14 },  {  -12,  42,  72,  12 },  {  -28,  44,  50,  20 },  {  -12,  28,  16,  32 } } },  /* 112: not used by a script */
    { { {   12,  16,  78,  14 },  {   -4,  36,  62,  22 },  {  -30,  46,  52,  20 },  {  -10,  28,  16,  34 } } },  /* 113: not used by a script */
    { { {   -2,  16,  80,  14 },  {  -12,  38,  62,  22 },  {  -30,  48,  52,  20 },  {   -8,  28,   0,  50 } } },  /* 114: follow-up of SP APPEAR 3 / JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    { { {   -8,  16,  74,  14 },  {  -20,  46,  58,  18 },  {  -22,  44,  24,  32 },  {   -6,  28,   0,  22 } } },  /* 115: follow-up of SP APPEAR 3 / JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    { { {   -2,  16,  96,  14 },  {  -18,  44,  86,  14 },  {   -8,  30,  66,  22 },  {  -26,  38,  48,  26 } } },  /* 116: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    { { {    8,  16,  94,  14 },  {   -8,  42,  86,  14 },  {  -24,  44,  68,  20 },  {   -8,  28,  36,  30 } } },  /* 117: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    { { {    9,  25,  94,  20 },  {  -50,  89,  90,  16 },  {  -18,  61,  70,  20 },  {  -32,  61,  42,  27 } } },  /* 118: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    { { {  -12,  16,  98,  14 },  {  -10,  30,  86,  16 },  {   -4,  28,  68,  20 },  {  -24,  36,  48,  28 } } },  /* 119: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    { { {  -10,  16,  98,  14 },  {   -4,  30,  90,  16 },  {  -20,  42,  62,  26 },  {  -16,  28,  38,  22 } } },  /* 120: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    { { {  -10,  44,  98,  19 },  {  -15,  54,  92,   8 },  {  -20,  58,  62,  31 },  {    0,   0,   0,   0 } } },  /* 121: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    { { {  -10,  16,  78,  14 },  {   -6,  32,  60,  24 },  {  -30,  52,  32,  26 },  {  -16,  26,   0,  32 } } },  /* 122: follow-up of SP APPEAR 4 */
    { { {  -18,  16,  84,  14 },  {  -24,  46,  70,  16 },  {  -10,  32,  32,  36 },  {  -20,  24,   0,  44 } } },  /* 123: follow-up of APPEAR 4 */
    { { {   -6,  16,  92,  14 },  {  -12,  32,  78,  18 },  {  -36,  54,  56,  20 },  {   -6,  24,   0,  54 } } },  /* 124: follow-up of APPEAR 5 */
    { { {   -6,  16,  84,  14 },  {  -12,  30,  60,  28 },  {  -38,  54,  30,  28 },  {   -4,  24,   0,  28 } } },  /* 125: follow-up of APPEAR 5 */
    { { {  -28,  34,  74,  16 },  {  -31,  52,  59,  19 },  {  -22,  51,  34,  25 },  {  -30,  76,   0,  34 } } },  /* 126: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    { { {  -19,  31,  72,  16 },  {  -24,  46,  52,  22 },  {  -21,  41,  34,  22 },  {  -30,  54,   0,  34 } } },  /* 127: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    { { {  -13,  33,  59,  14 },  {  -19,  46,  52,  15 },  {  -19,  46,  34,  16 },  {  -13,  33,  26,  14 } } },  /* 128: AIR S, AIR M, AIR L +38 */
    { { {  -68,  30,  70,  16 },  {  -82,  73,  52,  18 },  {  -59,  54,  34,  22 },  {  -65,  91,   0,  32 } } },  /* 129: not used by a script */
    { { {  -86,  36,  59,  20 },  {  -95,  73,  42,  18 },  {  -59,  54,  34,  22 },  {  -65,  91,   0,  32 } } },  /* 130: not used by a script */
    { { {  -80,  44,  63,  17 },  {  -95,  81,  39,  29 },  {  -82,  84,  34,  26 },  {  -69,  95,   0,  34 } } },  /* 131: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    { { {  -49,  81,   0,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command, ATTACK 3 SP: not started by a command +2 */
    { { {  -64,  98,  73,  22 },  {  -63,  98,  70,   7 },  {  -67, 101,  34,  35 },  {  -48,  82,   0,  32 } } },  /* 133: L KICK A, follow-up of follow-up of S KICK A, atca 215 */
    { { {  -10,  39,  71,  21 },  {  -28,  69,  70,   7 },  {  -67, 110,  34,  35 },  {  -31,  74,   0,  32 } } },  /* 134: L KICK A, follow-up of follow-up of S KICK A, atca 215 */
    { { {   -9,  26,  85,  22 },  {  -25,  48,  54,  35 },  {  -54,  74,  30,  43 },  {    0,   0,   0,   0 } } },  /* 135: not used by a script */
    { { {  -10,  22,  71,  21 },  {  -16,  39,  70,   7 },  {  -15,  38,  34,  35 },  {  -16,  41,   0,  32 } } },  /* 136: ATTACK 2 S: not started by a command, ATTACK 2 SP: not started by a command, not started by a command */
    { { {  -10,  22,  71,  21 },  {  -16,  39,  70,   7 },  {  -62,  93,  47,  57 },  {    0,   0,   0,   0 } } },  /* 137: ATTACK 12 L: not started by a command, not started by a command */
    { { {  -24,  16,  68,  14 },  {  -22,  32,  58,  12 },  {  -10,  30,  36,  22 },  {  -30,  54,   0,  36 } } },  /* 138: ATTACK 2 S: not started by a command, ATTACK 11 M: not started by a command, follow-up of follow-up of M PUNCH A / M PUNCH B */
    { { {  -28,  16,  96,  14 },  {  -34,  58,  86,  18 },  {  -73,  83,  61,  25 },  {  -26,  38,  48,  26 } } },  /* 139: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {   -4,  16,  98,  14 },  {  -23,  49,  88,  14 },  {  -13,  35,  66,  22 },  {  -30,  44,  47,  27 } } },  /* 140: FUSHIN P S */
    { { {    6,  16,  96,  14 },  {  -26,  57,  86,  16 },  {  -39,  64,  66,  20 },  {  -10,  30,  37,  29 } } },  /* 141: FUSHIN P S */
    { { {    8,  25,  95,  20 },  {  -52,  91,  90,  16 },  {  -18,  61,  69,  21 },  {  -32,  61,  43,  26 } } },  /* 142: FUSHIN P S */
    { { {    8,  25,  95,  20 },  {  -52,  91,  90,  16 },  {  -18,  61,  69,  21 },  {  -32,  61,  43,  26 } } },  /* 143: FUSHIN P S */
    { { {  -32,  22,  49,  21 },  {  -29,  53,  59,   7 },  {  -29,  53,  32,  27 },  {  -34,  87,   0,  32 } } },  /* 144: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    { { {  -49,  22,  62,  21 },  {  -61,  77,  60,  12 },  {  -51,  71,  32,  27 },  {  -63, 104,   0,  32 } } },  /* 145: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    { { {  -50,  22,  55,  21 },  {  -67,  88,  56,   8 },  {  -65,  84,  23,  31 },  {  -75,  94,   0,  32 } } },  /* 146: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +2 */
    { { {  -42,  24,  70,  17 },  {  -53,  47,  61,  10 },  {  -52,  47,  33,  26 },  {  -56,  75,   0,  33 } } },  /* 147: ATTACK 7 S: not started by a command, ATTACK 8 S: not started by a command */
    { { {  -44,  37,  44,  34 },  {  -32,  58,  52,  14 },  {  -36,  70,  34,  16 },  {   10,  16,   0,  36 } } },  /* 148: ATTACK 3 SP: not started by a command */
};

const HAND_BOX yang_hand_box[143] = {
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
    { { {  -96,  61,   0,  26 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI K A, follow-up of KAGAMI K A, follow-up of WIN 5 +1 */
    { { {  -78,  60,  56,  49 },  {    0,   0,   0,   0 } } },  /* 11: M KICK A, atca 212, follow-up of S KICK A */
    { { { -113,  78,   0,  26 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI K A, follow-up of KAGAMI K A, follow-up of WIN 5 +2 */
    { { {  -70,  52,  34,  40 },  {    0,   0,   0,   0 } } },  /* 13: M KICK A, follow-up of S KICK A, atca 212 +2 */
    { { {  -61,  40,  34,  40 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P A, follow-up of WIN 4, follow-up of S KICK A */
    { { {  -61,  58,  34,  47 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI P A, follow-up of WIN 4 */
    { { {  -63,  45,  17,  46 },  {    0,   0,   0,   0 } } },  /* 16: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
    { { {  -86,  39,  39,  36 },  {    0,   0,   0,   0 } } },  /* 17: UP P GUARD P M, ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command +2 */
    { { {  -74,  22,  33,  41 },  {    0,   0,   0,   0 } } },  /* 18: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +2 */
    { { {  -89,  52,  48,  31 },  {    0,   0,   0,   0 } } },  /* 19: ATTACK 7 S: not started by a command, ATTACK 8 S: not started by a command */
    { { {  -38,  30,  79,  29 },  {    0,   0,   0,   0 } } },  /* 20: not started by a command */
    { { {  -64,  28,  58,  12 },  {    0,   0,   0,   0 } } },  /* 21: UP P GUARD P L */
    { { {  -58,  28,  62,  10 },  {    0,   0,   0,   0 } } },  /* 22: UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: no box */
    { { {  -80,  66,  57,  23 },  {    0,   0,   0,   0 } } },  /* 24: S PUNCH A, follow-up of ZANNEN 2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {  -68,  55,  45,  31 },  {    0,   0,   0,   0 } } },  /* 26: M PUNCH B, atca 204 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: no box */
    { { {  -61,  40,  51,  34 },  {    0,   0,   0,   0 } } },  /* 28: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -63,  53,  44,  31 },  {    0,   0,   0,   0 } } },  /* 29: M PUNCH B, atca 204 */
    { { {  -43,  22,  50,  26 },  {    0,   0,   0,   0 } } },  /* 30: M PUNCH B, atca 204 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 } } },  /* 32: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 } } },  /* 33: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {  -70,  54,  43,  33 },  {    0,   0,   0,   0 } } },  /* 36: follow-up of M PUNCH A / M PUNCH B, follow-up of ZANNEN 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: no box */
    { { {  -66,  24,  60,  12 },  {    0,   0,   0,   0 } } },  /* 39: L PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { {  -66,  42,   0,  52 },  {    0,   0,   0,   0 } } },  /* 41: S KICK A, follow-up of ZANNEN 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {  -80,  62,  53,  28 },  {    0,   0,   0,   0 } } },  /* 43: M KICK C, follow-up of JUDGMENT WAIT, exca 13 */
    { { {  -80,  62,  41,  28 },  {    0,   0,   0,   0 } } },  /* 44: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -67,  62,  30,  28 },  {    0,   0,   0,   0 } } },  /* 45: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {  -82,  60,  45,  16 },  {    0,   0,   0,   0 } } },  /* 47: follow-up of WIN 2, KAGAMI P A, follow-up of WIN 3 */
    { { {  -73,  38,  23,  35 },  {    0,   0,   0,   0 } } },  /* 48: KAGAMI P A, follow-up of WIN 4 */
    { { {  -86,  58,  23,  35 },  {    0,   0,   0,   0 } } },  /* 49: KAGAMI P A, follow-up of WIN 4 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: no box */
    { { {  -82,  65,   0,  19 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {  -77,  27,   0,  25 },  {    0,   0,   0,   0 } } },  /* 58: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { { {  -73,  34,   0,  22 },  {    0,   0,   0,   0 } } },  /* 59: KAGAMI K A, follow-up of KAGAMI K A, follow-up of follow-up of KAGAMI K A +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {  -79,  60,  81,  16 },  {    0,   0,   0,   0 } } },  /* 66: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {    0,   0,   6,   0 },  {    0,   0,   0,   0 } } },  /* 67: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -61,  50,  54,  49 },  {    0,   0,   0,   0 } } },  /* 68: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
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
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {  -40,  29,  36,  48 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 12 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {  -62,  32,  64,   8 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 12 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {  -83,  62,  51,  28 },  {    0,   0,   0,   0 } } },  /* 91: follow-up of follow-up of SEAN BALL HIT, ATTACK 5 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {  -46,  24,  68,  32 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: no box */
    { { {  -46,  26,  61,  41 },  {    0,   0,   0,   0 } } },  /* 102: F JUMP P S A, follow-up of SEAN BALL HIT, V JUMP P S A +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: no box */
    { { {  -58,  36,  56,  41 },  {    0,   0,   0,   0 } } },  /* 105: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +3 */
    { { {  -52,  30,  76,  10 },  {    0,   0,   0,   0 } } },  /* 106: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: no box */
    { { {  -36,  17,  70,  23 },  {    0,   0,   0,   0 } } },  /* 108: not used by a script */
    { { {  -36,  15,  71,  22 },  {    0,   0,   0,   0 } } },  /* 109: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: no box */
    { { {  -68,  36,  58,  16 },  {    0,   0,   0,   0 } } },  /* 113: not used by a script */
    { { {  -56,  28,  48,  18 },  {    0,   0,   0,   0 } } },  /* 114: follow-up of SP APPEAR 3 / JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    { { {  -46,  22,  24,  20 },  {    0,   0,   0,   0 } } },  /* 115: follow-up of SP APPEAR 3 / JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: no box */
    { { {  -83,  65,  67,  30 },  {    0,   0,   0,   0 } } },  /* 118: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: no box */
    { { {  -20,  49,  20,  50 },  {    0,   0,   0,   0 } } },  /* 121: F JUMP K S B, F JUMP K M B, F JUMP K L B +4 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: no box */
    { { {  -54,  23,  62,  20 },  {    0,   0,   0,   0 } } },  /* 126: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    { { {  -46,  32,  56,  15 },  {    0,   0,   0,   0 } } },  /* 127: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: no box */
    { { {  -85,  21,  43,  47 },  {    0,   0,   0,   0 } } },  /* 133: L KICK A, follow-up of follow-up of S KICK A, atca 215 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: no box */
    { { {  -84,  73,  44,  25 },  {    0,   0,   0,   0 } } },  /* 135: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 136: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 137: no box */
    { { {  -56,  46,  42,  37 },  {    0,   0,   0,   0 } } },  /* 138: ATTACK 2 S: not started by a command, ATTACK 11 M: not started by a command, follow-up of follow-up of M PUNCH A / M PUNCH B */
    { { {  -75,  52,  35,  25 },  {    0,   0,   0,   0 } } },  /* 139: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -90,  62,  34,  27 },  {    0,   0,   0,   0 } } },  /* 140: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -82,  64,  69,  26 },  {    0,   0,   0,   0 } } },  /* 141: FUSHIN P S */
    { { {  -82,  64,  69,  26 },  {    0,   0,   0,   0 } } },  /* 142: FUSHIN P S */
};

const HOSEI_BOX yang_hos_box[23] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   70 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +152 */
    { {  -21,   42,    0,   54 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +64 */
    { {  -20,   40,   51,   44 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +54 */
    { {  -21,   42,   41,   37 } },  /* 4: M KICK C, follow-up of JUDGMENT WAIT, follow-up of follow-up of SEAN BALL HIT +2 */
    { {  -32,   46,   36,   36 } },  /* 5: not used by a script */
    { {  -44,   46,   36,   36 } },  /* 6: not used by a script */
    { {  -41,   46,   36,   36 } },  /* 7: not used by a script */
    { {  -21,   60,    0,   54 } },  /* 8: KAGAMI K A, follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { {  -21,   42,    0,   42 } },  /* 9: ATTACK 6 S: not started by a command, ATTACK 13 SP: not started by a command */
    { {    0,    0,    0,    0 } },  /* 10: no box */
    { {  -10,   46,   36,   36 } },  /* 11: not used by a script */
    { {    6,   36,   43,   36 } },  /* 12: not used by a script */
    { {    0,   36,   62,   36 } },  /* 13: not used by a script */
    { {    0,    0,    0,    0 } },  /* 14: no box */
    { {  -27,   32,   47,   36 } },  /* 15: not used by a script */
    { {   -4,   32,   52,   36 } },  /* 16: not used by a script */
    { {   10,   32,   52,   36 } },  /* 17: not used by a script */
    { {  -15,   38,   36,   45 } },  /* 18: not used by a script */
    { {  -17,   42,   35,   32 } },  /* 19: AIR S, AIR M, AIR L +38 */
    { {  -20,   40,   60,   24 } },  /* 20: not used by a script */
    { {  -21,   42,    0,   30 } },  /* 21: dmca 97, UP P GUARD P S, UP P GUARD P M +2 */
    { {  -28,   49,    0,   54 } },  /* 22: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command +1 */
};
