/*
 * HUGO_HITBOX.C  Hugo's hit boxes
 *
 * Each of Hugo's animation frames names an entry of hugo_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX hugo_hit_ix_table[171] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: TUKAMIHAZUSARE, TATAKI S, TATAKI M +33 */
    {    1,    0,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +93 */
    {    2,    0,    0,    0,    2,    0,    0,    2 },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +27 */
    {    3,    0,    0,    0,    3,    0,    0,    3 },  /* 3: JUMP FRONT, JUMP VERTICAL, JUMP BACK +19 */
    {    4,    0,    0,    0,    3,    0,    0,    3 },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +25 */
    {    6,    0,    0,    0,    4,    0,    0,    5 },  /* 5: DASH HUMIKOMI */
    {    5,    0,    0,    0,    1,    0,    0,    4 },  /* 6: DASH HUMIKOMI, DASH TOBINOKI */
    {    7,    0,    0,    0,    5,    0,    0,    6 },  /* 7: DASH TOBINOKI */
    {    8,    0,    0,    0,    1,    0,    0,    1 },  /* 8: S PUNCH A */
    {    8,    1,    0,    0,    1,    1,    0,    1 },  /* 9: S PUNCH A */
    {    8,    2,    0,    0,    1,    2,    0,    1 },  /* 10: S PUNCH A */
    {    8,    3,    0,    0,    1,    0,    0,    1 },  /* 11: S PUNCH A */
    {    1,    4,    0,    0,    1,    3,    0,    1 },  /* 12: M PUNCH A */
    {    1,    5,    0,    0,    1,    4,    0,    1 },  /* 13: M PUNCH A */
    {    1,    5,    0,    0,    1,    0,    0,    1 },  /* 14: M PUNCH A */
    {    9,    0,    0,    0,    1,    0,    0,    1 },  /* 15: L PUNCH A, ATTACK 9 S: not started by a command */
    {   10,    6,    0,    0,    1,    0,    0,    1 },  /* 16: nmca 33, L PUNCH A, ATTACK 9 S: not started by a command */
    {   10,    7,    0,    0,    1,    5,    0,    1 },  /* 17: L PUNCH A */
    {   10,    8,    0,    0,    1,    6,    0,    1 },  /* 18: L PUNCH A */
    {   10,    8,    0,    0,    1,    0,    0,    1 },  /* 19: L PUNCH A, ZANNEN 3 */
    {   10,    0,    0,    0,    1,    0,    0,    1 },  /* 20: L PUNCH A, ZANNEN 3 */
    {    1,    0,    0,    1,    1,    0,    0,    1 },  /* 21: L PUNCH A */
    {    1,    9,    0,    0,    1,    0,    0,    1 },  /* 22: L PUNCH B */
    {    1,   10,    0,    0,    1,    0,    0,    1 },  /* 23: L PUNCH B */
    {    1,   11,    0,    0,    1,    0,    0,    1 },  /* 24: L PUNCH B, ATTACK 9 S: not started by a command */
    {    1,   12,    0,    0,    1,    7,    0,    1 },  /* 25: L PUNCH B */
    {    1,   13,    0,    0,    1,    8,    0,    1 },  /* 26: L PUNCH B */
    {    1,   14,    0,    0,    1,    0,    0,    1 },  /* 27: L PUNCH B, ATTACK 9 S: not started by a command */
    {   54,   15,    0,    0,    1,    9,    0,    1 },  /* 28: S KICK A */
    {   54,   15,    0,    0,    1,   10,    0,    1 },  /* 29: S KICK A */
    {   54,   15,    0,    0,    1,    0,    0,    1 },  /* 30: S KICK A */
    {   11,    0,    0,    0,    1,    0,    0,    1 },  /* 31: M KICK A */
    {   56,   16,    0,    0,    1,   11,    0,    1 },  /* 32: M KICK A */
    {   56,   17,    0,    0,    1,   12,    0,    1 },  /* 33: M KICK A */
    {   56,   18,    0,    0,    1,    0,    0,    1 },  /* 34: M KICK A */
    {   56,   19,    0,    0,    1,   43,    0,    1 },  /* 35: M KICK A */
    {   12,    0,    0,    0,    1,    0,    0,   11 },  /* 36: ATTACK 1 S: not started by a command */
    {   13,    0,    0,    0,    1,    0,    0,   11 },  /* 37: ATTACK 1 S: not started by a command */
    {   14,    0,    0,    0,    1,    0,    0,   11 },  /* 38: ATTACK 1 S: not started by a command */
    {   15,   19,    0,    0,    1,   13,    0,   11 },  /* 39: ATTACK 1 S: not started by a command */
    {   15,   20,    0,    0,    1,    0,    0,   11 },  /* 40: ATTACK 1 S: not started by a command */
    {   12,    0,    0,    0,    1,    0,    0,   11 },  /* 41: ATTACK 1 M: not started by a command */
    {   13,    0,    0,    0,    1,    0,    0,   11 },  /* 42: ATTACK 1 M: not started by a command */
    {   14,    0,    0,    0,    1,    0,    0,   11 },  /* 43: ATTACK 1 M: not started by a command */
    {   15,   19,    0,    0,    1,   13,    0,   11 },  /* 44: ATTACK 1 M: not started by a command */
    {   15,   20,    0,    0,    1,    0,    0,   11 },  /* 45: ATTACK 1 M: not started by a command */
    {   12,    0,    0,    0,    1,    0,    0,   11 },  /* 46: ATTACK 1 L: not started by a command, ATTACK 1 SP: not started by a command */
    {   13,    0,    0,    0,    1,    0,    0,   11 },  /* 47: ATTACK 1 L: not started by a command, ATTACK 1 SP: not started by a command */
    {   14,    0,    0,    0,    1,    0,    0,   11 },  /* 48: ATTACK 1 L: not started by a command, ATTACK 1 SP: not started by a command */
    {   15,   19,    0,    0,    1,   13,    0,   11 },  /* 49: ATTACK 1 L: not started by a command, ATTACK 1 SP: not started by a command */
    {   15,   20,    0,    0,    1,    0,    0,   11 },  /* 50: ATTACK 1 L: not started by a command, ATTACK 1 SP: not started by a command */
    {   24,    0,    0,    0,    3,    0,    0,    3 },  /* 51: L KICK A */
    {   24,   25,    0,    0,    3,    0,    0,    3 },  /* 52: L KICK A */
    {   24,   26,    0,    0,    3,   14,    0,    3 },  /* 53: L KICK A */
    {   24,   25,    0,    0,    3,   15,    0,    3 },  /* 54: L KICK A */
    {   25,    0,    0,    0,    3,    0,    0,    3 },  /* 55: L KICK A */
    {    2,   27,    0,    0,   10,   17,    0,    2 },  /* 56: not used by a script */
    {    2,   27,    0,    0,   10,   17,    0,    2 },  /* 57: KAGAMI P A */
    {    2,   27,    0,    0,   10,    0,    0,    2 },  /* 58: KAGAMI P A */
    {    2,   28,    0,    0,    2,   18,    0,    2 },  /* 59: KAGAMI P A */
    {    2,   28,    0,    0,    2,   19,    0,    2 },  /* 60: KAGAMI P A */
    {    2,   28,    0,    0,    2,    0,    0,    2 },  /* 61: KAGAMI P A */
    {   55,   30,    0,    0,   10,   20,    0,    2 },  /* 62: KAGAMI K A */
    {   55,   30,    0,    0,   10,   20,    0,    2 },  /* 63: KAGAMI K A */
    {   55,   30,    0,    0,   10,    0,    0,    2 },  /* 64: KAGAMI K A */
    {   55,   31,    0,    0,    2,   21,    0,    2 },  /* 65: KAGAMI K A */
    {   55,   32,    0,    0,    2,   22,    0,    2 },  /* 66: KAGAMI K A */
    {   26,    0,    0,    0,    2,    0,    0,    2 },  /* 67: L KICK A, follow-up of APPEAR JUNBI 7 */
    {   27,    0,    0,    0,    1,    0,    0,    7 },  /* 68: PIYO */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 69: CATCH 33, follow-up of ASHIBARAI A / ASHIBARAI B +2, follow-up of HUMI ASIB A +2 */
    {   28,    0,    0,    0,    2,    0,    0,    2 },  /* 70: KAGAMI P A */
    {   29,    0,    0,    0,    2,    0,    0,    2 },  /* 71: KAGAMI P A */
    {   30,    0,    0,    0,    6,   23,    0,    8 },  /* 72: KAGAMI P A */
    {   30,    0,    0,    0,    6,   24,    0,    8 },  /* 73: KAGAMI P A */
    {   31,    0,    0,    0,    6,   25,    0,    8 },  /* 74: KAGAMI P A */
    {   32,    0,    0,    0,    6,    0,    0,    8 },  /* 75: KAGAMI P A */
    {   33,    0,    0,    0,    6,    0,    0,    8 },  /* 76: not used by a script */
    {   34,    0,    0,    0,    2,    0,    0,    2 },  /* 77: KAGAMI K A */
    {   35,    0,    0,    0,    2,    0,    0,    2 },  /* 78: KAGAMI K A */
    {   36,    0,    0,    0,    6,   27,    0,    8 },  /* 79: KAGAMI K A */
    {   36,    0,    0,    0,    6,   28,    0,    8 },  /* 80: KAGAMI K A */
    {   36,    0,    0,    0,    6,   29,    0,    8 },  /* 81: KAGAMI K A */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 82: NEKOROBI S, OKIAGARI, OKIAGARI F +22 */
    {   37,    0,    0,    0,    7,    0,    0,    9 },  /* 83: AIR S, AIR M, AIR L +36 */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 84: AIR S, AIR M, AIR L +3 */
    {   55,   32,    0,    0,    2,    0,    0,    2 },  /* 85: KAGAMI K A */
    {    4,   33,    0,    0,    3,   31,    0,    3 },  /* 86: V JUMP P S A */
    {    4,   34,    0,    0,    3,   32,    0,    3 },  /* 87: V JUMP P S A */
    {    4,   35,    0,    0,    3,   33,    0,    3 },  /* 88: V JUMP P S A */
    {    4,   35,    0,    0,    3,    0,    0,    3 },  /* 89: V JUMP P S A */
    {    4,   33,    0,    0,    3,   44,    0,    3 },  /* 90: V JUMP P M A */
    {    4,   34,    0,    0,    3,   45,    0,    3 },  /* 91: V JUMP P M A */
    {    4,   35,    0,    0,    3,   46,    0,    3 },  /* 92: V JUMP P M A */
    {    4,   35,    0,    0,    3,    0,    0,    3 },  /* 93: V JUMP P M A */
    {   45,    0,    0,    0,    3,    0,    0,    3 },  /* 94: V JUMP P L A */
    {   45,   43,    0,    0,    3,    0,    0,    3 },  /* 95: V JUMP P L A */
    {   45,   36,    0,    0,    3,    0,    0,    3 },  /* 96: V JUMP P L A */
    {   45,   36,    0,    0,    3,   34,    0,    3 },  /* 97: V JUMP P L A */
    {   45,   36,    0,    0,    3,   35,    0,    3 },  /* 98: V JUMP P L A */
    {    1,    0,    0,    2,    1,    0,    0,    1 },  /* 99: ATTACK 3 S: not started by a command */
    {    1,    0,    0,    3,    1,    0,    0,    1 },  /* 100: ATTACK 3 M: not started by a command */
    {    1,    0,    0,    4,    1,    0,    0,    1 },  /* 101: ATTACK 3 L: not started by a command */
    {   38,    0,    0,    0,    3,    0,    0,    3 },  /* 102: V JUMP K S A, ATTACK 10 S: not started by a command */
    {   38,   37,    0,    0,    3,   36,    0,    3 },  /* 103: V JUMP K S A */
    {   38,   37,    0,    0,    3,   37,    0,    3 },  /* 104: V JUMP K S A */
    {   38,    0,    0,    0,    3,    0,    0,    3 },  /* 105: V JUMP K M A */
    {   38,   38,    0,    0,    3,   38,    0,    3 },  /* 106: V JUMP K M A */
    {   38,   38,    0,    0,    3,   39,    0,    3 },  /* 107: V JUMP K M A */
    {   39,    0,    0,    0,    3,    0,    0,    3 },  /* 108: V JUMP K L A */
    {   40,    0,    0,    0,    3,    0,    0,    3 },  /* 109: V JUMP K L A */
    {   41,    0,    0,    0,    3,    0,    0,    3 },  /* 110: V JUMP K L A */
    {   42,    0,    0,    0,    3,    0,    0,    3 },  /* 111: V JUMP K L A */
    {   43,   39,    0,    0,    3,   40,    0,    3 },  /* 112: V JUMP K L A */
    {   43,   40,    0,    0,    3,   41,    0,    3 },  /* 113: V JUMP K L A */
    {   43,   41,    0,    0,    3,    0,    0,    3 },  /* 114: V JUMP K L A */
    {   44,   42,    0,    0,    3,    0,    0,    3 },  /* 115: V JUMP K L A */
    {   59,    0,    0,    0,    1,   47,    0,    1 },  /* 116: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    1,    0,    0,    0,    1,   48,    0,    1 },  /* 117: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    1,   49,    0,    0,    1,   49,    0,    1 },  /* 118: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    1,    0,    0,    0,    1,   50,    0,    1 },  /* 119: not used by a script */
    {   46,    0,    0,    0,    3,    0,    0,   12 },  /* 120: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    {   47,    0,    0,    5,    3,    0,    0,   12 },  /* 121: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    {   52,    0,    0,    0,    3,    0,    0,   12 },  /* 122: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    {   53,    0,    0,    6,    3,    0,    0,   12 },  /* 123: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    {   49,    0,    0,    0,    3,    0,    0,    3 },  /* 124: V JUMP P L B */
    {   50,    0,    0,    0,    3,    0,    0,    3 },  /* 125: V JUMP P L B */
    {   51,   46,    0,    0,    9,   51,    0,   10 },  /* 126: V JUMP P L B */
    {   51,   46,    0,    0,    9,    0,    0,   10 },  /* 127: V JUMP P L B */
    {   50,   47,    0,    0,    3,    0,    0,    3 },  /* 128: V JUMP P L B */
    {   50,   47,    0,    0,    3,    0,    0,    3 },  /* 129: V JUMP P L B */
    {    0,    0,    0,    0,    0,   52,    0,    0 },  /* 130: CATCH 29 */
    {    1,    0,    0,    0,    1,   53,    0,    1 },  /* 131: ATTACK 9 S: not started by a command */
    {   59,    0,    0,    0,    1,   54,    0,    1 },  /* 132: ATTACK 8 S: not started by a command */
    {    1,    0,    0,    0,    1,   55,    0,    1 },  /* 133: ATTACK 8 S: not started by a command */
    {    1,   49,    0,    0,    1,   56,    0,    1 },  /* 134: ATTACK 8 S: not started by a command */
    {    1,   12,    0,    0,    1,   57,    0,    1 },  /* 135: ATTACK 9 S: not started by a command */
    {   10,    7,    0,    0,    1,   58,    0,    1 },  /* 136: ATTACK 9 S: not started by a command */
    {   15,   19,    0,    0,    1,   59,    0,   13 },  /* 137: ATTACK 9 S: not started by a command */
    {    1,   48,    0,    0,    1,   60,    0,    1 },  /* 138: ATTACK 9 M: not started by a command */
    {    1,   48,    0,    0,    1,    0,    0,    1 },  /* 139: not used by a script */
    {    1,   13,    0,    0,    1,    0,    0,    1 },  /* 140: L PUNCH B */
    {   54,    0,    0,    0,    1,    0,    0,    1 },  /* 141: S KICK A */
    {    0,    0,    0,    7,    1,    0,    0,    1 },  /* 142: ATTACK 6 S: not started by a command */
    {   38,   37,    0,    0,    3,    0,    0,    3 },  /* 143: V JUMP K S A, V JUMP K M A */
    {   48,    0,    0,    0,    2,    0,    0,    2 },  /* 144: follow-up of SP APPEAR 7 */
    {   57,    0,    0,    0,    2,    0,    0,    2 },  /* 145: L KICK A, follow-up of APPEAR JUNBI 7 */
    {   58,    0,    0,    0,    0,    0,    0,    2 },  /* 146: dmca 97 */
    {   59,    0,    0,    0,    1,    0,    0,    1 },  /* 147: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    {    1,   44,    0,    0,    1,    0,    0,    1 },  /* 148: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    {    1,   45,    0,    0,    1,    0,    0,    1 },  /* 149: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    {    1,    0,    0,    8,    1,    0,    0,    1 },  /* 150: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command */
    {   60,    0,    0,    0,   11,    0,    0,    1 },  /* 151: ATTACK 3 S: not started by a command, ATTACK 4 S: not started by a command, ATTACK 6 S: not started by a command */
    {   61,    0,    0,    0,   11,    0,    0,    7 },  /* 152: ATTACK 3 S: not started by a command, ATTACK 4 S: not started by a command, ATTACK 6 S: not started by a command */
    {   62,    0,    0,    0,    1,    0,    0,    1 },  /* 153: ATTACK 9 M: not started by a command */
    {   63,    0,    0,    0,   11,    0,    0,    7 },  /* 154: ATTACK 9 M: not started by a command */
    {    1,    0,    0,    9,    1,    0,    0,    1 },  /* 155: M PUNCH A */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 156: CATCH 33, ATTACK 6 S: not started by a command, ATTACK 7 S: not started by a command +3 */
    {    1,    0,    0,    0,    1,    0,    0,    0 },  /* 157: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    1,   49,    0,    0,    1,    0,    0,    0 },  /* 158: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    1,   44,    0,    0,    1,    0,    0,    0 },  /* 159: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +1 */
    {    0,    0,    0,    0,    0,   54,    0,    1 },  /* 160: ATTACK 8 S: not started by a command */
    {    1,   13,    0,    0,    1,   61,    0,    1 },  /* 161: ATTACK 9 S: not started by a command */
    {   10,    8,    0,    0,    1,   62,    0,    1 },  /* 162: ATTACK 9 S: not started by a command */
    {   12,    0,    0,    0,    1,    0,    0,   13 },  /* 163: ATTACK 9 S: not started by a command */
    {   13,    0,    0,    0,    1,    0,    0,   13 },  /* 164: ATTACK 9 S: not started by a command */
    {   14,    0,    0,    0,    1,    0,    0,   13 },  /* 165: ATTACK 9 S: not started by a command */
    {   15,   19,    0,    0,    1,   13,    0,   13 },  /* 166: ATTACK 9 S: not started by a command */
    {   15,   20,    0,    0,    1,    0,    0,   13 },  /* 167: ATTACK 9 S: not started by a command */
    {   64,    0,    0,    0,    2,    0,    0,    2 },  /* 168: follow-up of APPEAR JUNBI 7 */
    {   65,    0,    0,    0,    2,    0,    0,    2 },  /* 169: follow-up of APPEAR JUNBI 7 */
    {   66,   50,    0,    0,    3,   63,    0,    3 },  /* 170: ATTACK 10 S: not started by a command */
};

const BODY_BOX hugo_body_box[67] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -24,  41, 108,  20 },  {  -34,  70,  82,  26 },  {  -43,  79,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +93 */
    { { {  -37,  43,  67,  20 },  {  -45,  90,  42,  25 },  {  -51,  96,  24,  18 },  {  -53,  99,   0,  24 } } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +27 */
    { { {  -20,  41, 128,  20 },  {  -32,  67,  97,  31 },  {  -34,  67,  67,  30 },  {  -28,  57,  46,  30 } } },  /* 3: JUMP FRONT, JUMP VERTICAL, JUMP BACK +19 */
    { { {  -29,  41, 120,  20 },  {  -33,  63,  93,  33 },  {  -36,  65,  66,  26 },  {  -32,  60,  47,  23 } } },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +25 */
    { { {  -33,  43,  93,  22 },  {  -44,  77,  70,  23 },  {  -60,  96,  52,  18 },  {  -54,  91,   0,  52 } } },  /* 5: DASH HUMIKOMI, DASH TOBINOKI */
    { { {  -41,  41, 103,  20 },  {  -68,  94,  78,  25 },  {  -45,  76,  52,  26 },  {  -49,  87,   0,  52 } } },  /* 6: DASH HUMIKOMI */
    { { {  -29,  41, 112,  20 },  {  -50,  94,  85,  30 },  {  -49,  61,  63,  22 },  {  -62,  78,   0,  64 } } },  /* 7: DASH TOBINOKI */
    { { {  -50,  41, 108,  20 },  {  -51,  77,  82,  26 },  {  -51,  81,  52,  30 },  {  -53,  88,   0,  52 } } },  /* 8: S PUNCH A */
    { { {  -24,  41, 108,  34 },  {  -55,  81,  82,  26 },  {  -56,  86,  52,  30 },  {  -57,  89,   0,  52 } } },  /* 9: L PUNCH A, ATTACK 9 S: not started by a command */
    { { {  -50,  41,  90,  35 },  {  -55,  81,  82,  26 },  {  -56,  86,  52,  30 },  {  -57,  89,   0,  52 } } },  /* 10: nmca 33, L PUNCH A, ATTACK 9 S: not started by a command +1 */
    { { {  -12,  57, 108,  20 },  {  -31,  82,  82,  26 },  {  -46,  81,  52,  30 },  {  -48,  88,   0,  52 } } },  /* 11: M KICK A */
    { { {   -3,  41, 107,  20 },  {  -38,  85,  81,  26 },  {  -38,  93,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 12: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +2 */
    { { {  -40,  41, 107,  20 },  {  -46,  87,  81,  26 },  {  -42,  80,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 13: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +2 */
    { { {   -2,  41, 114,  20 },  {  -43, 106,  88,  26 },  {  -40,  64,  58,  30 },  {  -48,  88,   0,  52 } } },  /* 14: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +2 */
    { { {  -57,  41,  82,  22 },  {  -41,  71,  45,  49 },  {    0,   0,   0,   0 },  {  -50,  90,   0,  45 } } },  /* 15: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +2 */
    { { {   -3,  41, 107,  20 },  {  -38,  85,  81,  26 },  {  -38,  93,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 16: not used by a script */
    { { {  -40,  41, 107,  20 },  {  -46,  87,  81,  26 },  {  -42,  80,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 17: not used by a script */
    { { {   -2,  41, 114,  20 },  {  -43, 106,  88,  26 },  {  -40,  64,  58,  30 },  {  -48,  88,   0,  52 } } },  /* 18: not used by a script */
    { { {  -57,  41,  82,  22 },  {  -41,  71,  45,  49 },  {    0,   0,   0,   0 },  {  -50,  90,   0,  45 } } },  /* 19: not used by a script */
    { { {   -3,  41, 107,  20 },  {  -38,  85,  81,  26 },  {  -38,  93,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 20: not used by a script */
    { { {  -40,  41, 107,  20 },  {  -46,  87,  81,  26 },  {  -42,  80,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 21: not used by a script */
    { { {   -2,  41, 114,  20 },  {  -43, 106,  88,  26 },  {  -40,  64,  58,  30 },  {  -48,  88,   0,  52 } } },  /* 22: not used by a script */
    { { {  -57,  41,  82,  22 },  {  -41,  71,  45,  49 },  {    0,   0,   0,   0 },  {  -50,  90,   0,  45 } } },  /* 23: not used by a script */
    { { {    1,  41, 108,  22 },  {  -31,  83,  84,  37 },  {  -49,  81,  63,  40 },  {  -66,  72,  47,  38 } } },  /* 24: L KICK A */
    { { {   30,  41,  70,  22 },  {  -21,  77,  50,  26 },  {  -68,  99,  63,  40 },  {  -66,  66,  47,  27 } } },  /* 25: L KICK A */
    { { {    0,   0,   0,   0 },  {  -24,  96,   0,  54 },  {    0,   0,   0,   0 },  {  -83,  59,   0,  42 } } },  /* 26: L KICK A, follow-up of APPEAR JUNBI 7 */
    { { {  -17,  43,  78,  22 },  {  -59,  90,  53,  28 },  {  -46,  75,  35,  18 },  {  -55,  94,   0,  35 } } },  /* 27: PIYO */
    { { {  -56,  48,  54,  24 },  {    0,   0,   0,   0 },  {  -64,  95,   0,  62 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A */
    { { {  -60,  43,  27,  34 },  {    0,   0,   0,   0 },  {  -46,  93,   0,  74 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI P A */
    { { {  -68,  70,  72,  25 },  {  -56,  75,  51,  36 },  {  -48,  85,  41,  30 },  {  -15,  80,  16,  25 } } },  /* 30: KAGAMI P A */
    { { {  -70,  48,  69,  36 },  {  -63,  83,  45,  44 },  {  -40,  79,  31,  44 },  {  -16,  79,  17,  33 } } },  /* 31: KAGAMI P A */
    { { {  -76,  45,  67,  32 },  {  -61,  94,  50,  40 },  {  -43,  68,  36,  30 },  {   15,  58,  28,  46 } } },  /* 32: KAGAMI P A */
    { { {  -85,  43,  10,  26 },  {  -66,  93,  17,  42 },  {    0,   0,   0,   0 },  {    1,  49,  25,  48 } } },  /* 33: not used by a script */
    { { {  -28,  43,  71,  22 },  {  -60, 106,  51,  33 },  {  -30,  72,  33,  18 },  {  -32,  79,   0,  33 } } },  /* 34: KAGAMI K A */
    { { {  -40,  55,  71,  22 },  {  -60, 106,  47,  35 },  {  -26,  73,  27,  20 },  {   -3,  65,   0,  27 } } },  /* 35: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {  -40, 116,  46,  47 },  {    0,   0,   0,   0 },  {  -31,  63,  32,  14 } } },  /* 36: KAGAMI K A */
    { { {  -26,  41,  86,  22 },  {  -30,  67,  54,  45 },  {  -30,  68,  32,  22 },  {  -22,  51,  24,  17 } } },  /* 37: AIR S, AIR M, AIR L +36 */
    { { {   -9,  41, 128,  22 },  {  -31,  75,  95,  33 },  {  -33,  91,  69,  26 },  {  -37,  72,  46,  23 } } },  /* 38: V JUMP K S A, ATTACK 10 S: not started by a command, V JUMP K M A */
    { { {  -14,  50, 127,  22 },  {  -34,  76,  97,  38 },  {  -39,  71,  71,  26 },  {  -46,  78,  44,  27 } } },  /* 39: V JUMP K L A */
    { { {  -10,  60, 122,  24 },  {  -35,  91,  90,  33 },  {  -54,  92,  64,  26 },  {  -59,  80,  48,  16 } } },  /* 40: V JUMP K L A */
    { { {  -10,  60, 130,  22 },  {  -45, 106, 101,  36 },  {  -59, 107,  63,  41 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP K L A */
    { { {  -19,  52, 116,  22 },  {  -40, 106,  93,  33 },  {  -38, 108,  58,  35 },  {  -76,  38,  59,  51 } } },  /* 42: V JUMP K L A */
    { { {   40,  45,  97,  38 },  {  -32,  93,  54,  73 },  {  -60,  46,  56,  53 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP K L A */
    { { {   31,  46, 101,  34 },  {  -33,  92,  54,  71 },  {  -48,  46,  46,  59 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP K L A */
    { { {  -29,  41, 122,  22 },  {  -45,  85,  96,  35 },  {  -38,  72,  70,  26 },  {  -34,  65,  49,  21 } } },  /* 45: V JUMP P L A */
    { { {  -50,  41, 115,  26 },  {  -47,  79,  97,  31 },  {  -38,  67,  67,  30 },  {  -36,  74,  37,  30 } } },  /* 46: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    { { {  -50,  41, 115,  26 },  {  -55,  99,  97,  31 },  {  -49,  84,  67,  31 },  {  -26,  77,  37,  30 } } },  /* 47: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    { { {    0,   0,   0,   0 },  {  -45,  90,  42,  25 },  {  -51,  96,  24,  18 },  {  -53,  99,   0,  24 } } },  /* 48: follow-up of SP APPEAR 7 */
    { { {  -46,  41, 112,  28 },  {  -68, 109,  96,  35 },  {  -38,  72,  70,  26 },  {  -31,  74,  23,  47 } } },  /* 49: V JUMP P L B */
    { { {  -40,  41, 118,  25 },  {  -45,  85,  96,  26 },  {  -38,  72,  58,  38 },  {  -28,  93,  27,  32 } } },  /* 50: V JUMP P L B */
    { { {  -68,  59,  95,  34 },  {  -63,  81,  79,  37 },  {  -78, 140,  66,  41 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P L B */
    { { {  -50,  41, 115,  26 },  {  -47,  79,  97,  31 },  {  -38,  67,  67,  30 },  {  -36,  74,  37,  30 } } },  /* 52: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    { { {  -50,  41, 115,  26 },  {  -55,  99,  97,  31 },  {  -49,  84,  67,  31 },  {  -26,  77,  37,  30 } } },  /* 53: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    { { {  -24,  59,  95,  23 },  {  -34,  80,  73,  26 },  {  -34,  81,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 54: S KICK A */
    { { {  -27,  64,  67,  20 },  {  -45,  90,  42,  25 },  {  -51,  96,  24,  18 },  {  -53,  99,   0,  24 } } },  /* 55: KAGAMI K A */
    { { {  -12,  57, 108,  20 },  {  -31,  82,  82,  26 },  {  -46,  81,  52,  30 },  {  -35,  75,   0,  52 } } },  /* 56: M KICK A */
    { { {    0,   0,   0,   0 },  {  -80,  96,   0,  54 },  {    0,   0,   0,   0 },  {   16,  59,   0,  42 } } },  /* 57: L KICK A, follow-up of APPEAR JUNBI 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 58: dmca 97 */
    { { {  -12,  46, 108,  20 },  {  -32,  93,  82,  30 },  {  -43,  79,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 59: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    { { {  -63,  51,  90,  29 },  {  -72,  95,  75,  35 },  {  -65, 100,  52,  30 },  {  -54, 109,   0,  52 } } },  /* 60: ATTACK 3 S: not started by a command, ATTACK 4 S: not started by a command, ATTACK 6 S: not started by a command */
    { { {  -66,  51,  72,  28 },  {  -75,  96,  57,  34 },  {  -68, 106,  38,  36 },  {  -54, 109,   0,  52 } } },  /* 61: ATTACK 3 S: not started by a command, ATTACK 4 S: not started by a command, ATTACK 6 S: not started by a command */
    { { {  -49,  44,  94,  29 },  {  -60,  90,  65,  44 },  {  -43,  79,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 62: ATTACK 9 M: not started by a command */
    { { {  -59,  42,  84,  25 },  {  -65,  87,  66,  29 },  {  -68,  99,  41,  30 },  {  -52,  90,   0,  52 } } },  /* 63: ATTACK 9 M: not started by a command */
    { { {    0,   0,   0,   0 },  {  -80,  96,   0,  66 },  {    0,   0,   0,   0 },  {   16,  59,   0,  48 } } },  /* 64: follow-up of APPEAR JUNBI 7 */
    { { {    0,   0,   0,   0 },  {  -80,  96,   0,  70 },  {    0,   0,   0,   0 },  {   16,  59,   0,  56 } } },  /* 65: follow-up of APPEAR JUNBI 7 */
    { { {  -10,  44, -110,  22 },  {  -26,  80,  82,  32 },  {  -58, 116,  66,  28 },  {  -34,  76,  46,  24 } } },  /* 66: ATTACK 10 S: not started by a command */
};

const HAND_BOX hugo_hand_box[51] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { { -130,  84,  60,  30 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { { -124,  74,  60,  29 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { { -120,  74,  60,  29 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH A */
    { { { -106,  74,  64,  42 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A */
    { { { -111,  80,  64,  42 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH A */
    { { {  -68,  45,  96,  38 },  {    0,   0,   0,   0 } } },  /* 6: nmca 33, L PUNCH A, ATTACK 9 S: not started by a command */
    { { {  -77,  45,  64,  43 },  {    0,   0,   0,   0 } } },  /* 7: L PUNCH A, ATTACK 9 S: not started by a command */
    { { {  -86,  37,  59,  57 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, ZANNEN 3, ATTACK 9 S: not started by a command */
    { { {  -68, 133,  91,  29 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH B */
    { { {  -28, 133,  91,  29 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH B */
    { { {  -66,  44,  53,  44 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH B, ATTACK 9 S: not started by a command */
    { { {  -82,  57,  86,  30 },  {    0,   0,   0,   0 } } },  /* 12: L PUNCH B, ATTACK 9 S: not started by a command */
    { { {  -97,  70,  83,  41 },  {    0,   0,   0,   0 } } },  /* 13: L PUNCH B, ATTACK 9 S: not started by a command */
    { { {  -60,  45,  82,  55 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH B, ATTACK 9 S: not started by a command */
    { { { -103,  63,  23,  39 },  {    0,   0,   0,   0 } } },  /* 15: S KICK A */
    { { {  -94,  63,  69,  40 },  {    0,   0,   0,   0 } } },  /* 16: M KICK A */
    { { { -102,  72,  69,  43 },  {    0,   0,   0,   0 } } },  /* 17: M KICK A */
    { { { -102,  72,  69,  43 },  {    0,   0,   0,   0 } } },  /* 18: M KICK A */
    { { {  -81,  41,  45,  37 },  {    0,   0,   0,   0 } } },  /* 19: M KICK A, ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command +3 */
    { { {  -94,  59,  39,  42 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +2 */
    { { {  -81,  41,  45,  37 },  {    0,   0,   0,   0 } } },  /* 21: not used by a script */
    { { { -101,  61,  39,  42 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {  -81,  41,  45,  37 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { { -101,  61,  39,  42 },  {    0,   0,   0,   0 } } },  /* 24: not used by a script */
    { { { -105,  57,  50,  50 },  {    0,   0,   0,   0 } } },  /* 25: L KICK A */
    { { {  -87,  38,  73,  29 },  {    0,   0,   0,   0 } } },  /* 26: L KICK A */
    { { { -118,  81,  27,  36 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI P A */
    { { { -122,  82,  27,  36 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A */
    { { { -133,  96,  27,  36 },  {    0,   0,   0,   0 } } },  /* 29: not used by a script */
    { { { -107,  79,   0,  36 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI K A */
    { { { -116,  95,   0,  36 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI K A */
    { { { -120,  96,   0,  36 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI K A */
    { { { -116,  84,  79,  28 },  {  -90,  64, 100,  24 } } },  /* 33: V JUMP P S A, V JUMP P M A */
    { { { -108,  76,  84,  24 },  {  -90,  64, 100,  24 } } },  /* 34: V JUMP P S A, V JUMP P M A */
    { { { -101,  74,  95,  21 },  {  -78,  50, 104,  24 } } },  /* 35: V JUMP P S A, V JUMP P M A */
    { { { -108,  76,  93,  32 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P L A */
    { { {  -69,  51,  50,  42 },  {    0,   0,   0,   0 } } },  /* 37: V JUMP K S A, V JUMP K M A */
    { { {  -59,  41,  52,  35 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP K M A */
    { { {  -89,  29,  60,  47 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP K L A */
    { { { -104,  43,  52,  52 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K L A */
    { { { -104,  47,  52,  57 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP K L A */
    { { {  -96,  48,  44,  52 },  {    0,   0,   0,   0 } } },  /* 42: V JUMP K L A */
    { { {  -69,  24,  94,  34 },  {   12,  36, 121,  20 } } },  /* 43: V JUMP P L A */
    { { { -104,  79,  82,  33 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    { { {  -65,  37,  59,  52 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    { { {  -83,  53, 109,  37 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP P L B */
    { { {  -93,  54,  92,  28 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP P L B */
    { { { -104,  80,  96,  32 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 9 M: not started by a command */
    { { {  -58,  43,  82,  33 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command +2 */
    { { {  -78,  44,  48,  36 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 10 S: not started by a command */
};

const HOSEI_BOX hugo_hos_box[14] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -32,   67,    0,   98 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +98 */
    { {  -32,   67,    0,   58 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +58 */
    { {  -27,   54,   63,   58 } },  /* 3: JUMP FRONT, JUMP VERTICAL, JUMP BACK +34 */
    { {  -32,   67,    0,   72 } },  /* 4: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -41,   67,    0,   98 } },  /* 5: DASH HUMIKOMI */
    { {  -44,   67,    0,   98 } },  /* 6: DASH TOBINOKI */
    { {  -32,   67,    0,   74 } },  /* 7: PIYO, ATTACK 3 S: not started by a command, ATTACK 4 S: not started by a command +2 */
    { {  -41,   66,   34,   50 } },  /* 8: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   34,   58 } },  /* 9: AIR S, AIR M, AIR L +36 */
    { {  -51,   81,   77,   41 } },  /* 10: V JUMP P L B */
    { {  -38,   74,    0,   98 } },  /* 11: ATTACK 1 S: not started by a command, ATTACK 1 M: not started by a command, ATTACK 1 L: not started by a command +1 */
    { {  -22,   50,   63,   58 } },  /* 12: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command +3 */
    { {  -22,   68,    0,   98 } },  /* 13: ATTACK 9 S: not started by a command */
};
