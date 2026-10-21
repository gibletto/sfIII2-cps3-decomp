/*
 * IBUKI_HITBOX.C  Ibuki's hit boxes
 *
 * Each of Ibuki's animation frames names an entry of ibuki_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX ibuki_hit_ix_table[263] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +23 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +120 */
    {    2,    2,    0,    0,    2,    0,    0,    2 },  /* 2: DASH TOBINOKI, KAGAMU, KAGAMI KAMAE +47 */
    {    3,    3,    0,    0,    1,    0,    0,    1 },  /* 3: S PUNCH A, ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) +1 */
    {    9,    9,    0,    1,    1,    1,    0,    1 },  /* 4: S PUNCH A */
    {    4,    4,    0,    0,    1,    0,    0,    1 },  /* 5: S PUNCH B */
    {    5,    5,    0,    2,    1,    2,    0,    1 },  /* 6: S PUNCH B */
    {    5,    5,    0,    0,    1,    0,    0,    1 },  /* 7: S PUNCH B */
    {    6,    6,    0,    0,    3,    0,    0,    3 },  /* 8: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +12 */
    {    7,    7,    0,    0,    3,    0,    0,    3 },  /* 9: JUMP FRONT, JUMP BACK, SP JUMP FRONT +21 */
    {    8,    8,    0,    0,    3,    0,    0,    3 },  /* 10: JUMP FRONT, JUMP VERTICAL, JUMP BACK +29 */
    {    9,    9,    0,    0,    1,    0,    0,    1 },  /* 11: S PUNCH A */
    {   10,   10,    0,    0,    1,    0,    0,    1 },  /* 12: GUARD HEAD, GUARD UP */
    {   11,   11,    0,    0,    2,    0,    0,    2 },  /* 13: GUARD DOWN */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 14: not used by a script */
    {   13,   13,    0,    0,    4,    0,    0,    4 },  /* 15: DASH HUMIKOMI */
    {   14,   14,    0,    0,    4,    0,    0,    4 },  /* 16: DASH HUMIKOMI, nmca 33 */
    {   15,   15,    0,    0,    4,    0,    0,    4 },  /* 17: DASH HUMIKOMI, CATCH 5, CATCH 24 */
    {   16,   16,    0,    0,    4,    0,    0,    4 },  /* 18: DASH TOBINOKI, not started by a command */
    {   17,   17,    0,    0,    9,    0,    0,   11 },  /* 19: DASH TOBINOKI, ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2) +2 */
    {   18,   18,    0,    0,    1,    0,    0,    1 },  /* 20: M KICK C, follow-up of M KICK B */
    {   19,   19,    0,    0,    4,    0,    0,    4 },  /* 21: M KICK C, follow-up of M KICK B */
    {   20,   20,    0,    0,    3,    0,    0,    3 },  /* 22: M KICK C, follow-up of M KICK B */
    {   21,   21,    0,    3,    3,    3,    0,    3 },  /* 23: M KICK C, follow-up of M KICK B */
    {   22,   22,    0,    4,    3,    4,    0,    3 },  /* 24: M KICK C, follow-up of M KICK B */
    {   22,   22,    0,    0,    4,    0,    0,    4 },  /* 25: M KICK C, follow-up of M KICK B */
    {   23,   23,    0,    5,    2,    5,    0,    2 },  /* 26: KAGAMI K A, follow-up of M PUNCH C / L PUNCH A, UP P GUARD K S */
    {   24,   24,    0,    0,    3,    0,    0,    3 },  /* 27: V JUMP K L A, F JUMP K L A, not started by a command */
    {   25,   25,    0,    0,    3,    0,    0,    3 },  /* 28: V JUMP K L A, F JUMP K L A, not started by a command */
    {   70,   70,    0,    6,    3,    6,    0,    3 },  /* 29: V JUMP K L A, F JUMP K L A */
    {   71,   71,    0,    7,    3,    7,    0,    3 },  /* 30: V JUMP K L A, F JUMP K L A */
    {   72,   72,    0,    8,    3,    8,    0,    3 },  /* 31: not used by a script */
    {   26,   26,    0,    0,    3,    0,    0,    3 },  /* 32: L KICK C */
    {   27,   27,    0,    0,    3,    0,    0,    3 },  /* 33: L KICK C */
    {   28,   28,    0,    9,    3,    9,    0,    3 },  /* 34: L KICK C */
    {  101,  101,    0,    0,    3,    0,    0,    3 },  /* 35: L KICK C */
    {   29,   29,    0,    0,    3,    0,    0,    3 },  /* 36: F JUMP K S A */
    {   73,   73,    0,   10,    3,   10,    0,    3 },  /* 37: F JUMP K S A */
    {   73,   73,    0,   11,    3,   11,    0,    3 },  /* 38: F JUMP K S A */
    {   30,   30,    0,    0,    3,    0,    0,    3 },  /* 39: F JUMP K M A, follow-up of V JUMP P L A / F JUMP K S A, FUSHIN P S */
    {   31,   31,    0,   12,    3,   12,    0,    3 },  /* 40: F JUMP K M A, follow-up of V JUMP P L A / F JUMP K S A, FUSHIN P S */
    {   31,   31,    0,   13,    3,   13,    0,    3 },  /* 41: F JUMP K M A, follow-up of V JUMP P L A / F JUMP K S A, FUSHIN P S */
    {  111,  111,    0,    0,    2,    0,    0,    2 },  /* 42: KAGAMI K A, follow-up of M PUNCH C / L PUNCH A, UP P GUARD K S +2 */
    {   32,   32,    0,    0,    1,    0,    0,    1 },  /* 43: M PUNCH C, follow-up of S PUNCH A */
    {   32,   32,    0,   14,    1,   14,    0,    1 },  /* 44: M PUNCH C, follow-up of S PUNCH A */
    {  124,  124,    0,   15,    1,   15,    0,    1 },  /* 45: M PUNCH C, follow-up of S PUNCH A */
    {   33,   33,    0,   16,    1,   16,    0,    1 },  /* 46: M PUNCH C, follow-up of S PUNCH A */
    {   33,   33,    0,    0,    1,    0,    0,    1 },  /* 47: M PUNCH C, follow-up of S PUNCH A */
    {   34,   34,    0,    0,    1,    0,    0,    1 },  /* 48: M PUNCH A */
    {   35,   35,    0,   17,    1,   17,    0,    1 },  /* 49: M PUNCH A */
    {  105,  105,    0,   18,    1,   18,    0,    1 },  /* 50: M PUNCH A */
    {  105,  105,    0,    0,    1,    0,    0,    1 },  /* 51: M PUNCH A */
    {    1,    1,    0,   19,    1,   19,    0,    1 },  /* 52: L PUNCH A */
    {   36,   36,    0,   20,    1,   20,    0,    1 },  /* 53: L PUNCH A */
    {   36,   36,    0,   21,    1,   21,    0,    1 },  /* 54: L PUNCH A */
    {  106,  106,    0,    0,    1,    0,    0,    1 },  /* 55: L PUNCH A */
    {   37,   37,    0,    0,    1,    0,    0,    1 },  /* 56: S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   38,   38,    0,   22,    1,   22,    0,    1 },  /* 57: not used by a script */
    {   38,   38,    0,   23,    1,   23,    0,    1 },  /* 58: S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   38,   38,    0,    0,    1,    0,    0,    1 },  /* 59: S KICK A */
    {   39,   39,    0,   24,    1,   24,    0,    1 },  /* 60: S KICK B */
    {   39,   39,    0,   25,    1,   25,    0,    1 },  /* 61: S KICK B */
    {  102,  102,    0,    0,    1,    0,    0,    1 },  /* 62: S KICK B */
    {   40,   40,    0,    0,    1,    0,    0,    1 },  /* 63: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   50,   50,    0,   26,    1,   26,    0,    1 },  /* 64: M KICK A, follow-up of S KICK A */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 65: M KICK B, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    {   42,   42,    0,    0,    1,    0,    0,    1 },  /* 66: M KICK B */
    {  100,  100,    0,   27,    1,   27,    0,    1 },  /* 67: M KICK B */
    {   43,   43,    0,    0,    1,    0,    0,    1 },  /* 68: M KICK B, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +9 */
    {   45,   45,    0,   28,    1,   28,    0,    1 },  /* 69: L KICK A */
    {   45,   45,    0,   29,    1,   29,    0,    1 },  /* 70: L KICK A */
    {   45,   45,    0,    0,    1,    0,    0,    1 },  /* 71: L KICK A, ATTACK 6 S: not started by a command, not started by a command +1 */
    {   44,   44,    0,    0,    1,    0,    0,    1 },  /* 72: L KICK A, ATTACK 6 S: not started by a command, not started by a command +1 */
    {   47,   47,    0,    0,    1,    0,    0,    1 },  /* 73: L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   48,   48,    0,    0,    1,    0,    0,    1 },  /* 74: TOUKETSU A, L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   49,   49,    0,   30,    1,   30,    0,    1 },  /* 75: L PUNCH B */
    {   49,   49,    0,   31,    1,   31,    0,    1 },  /* 76: L PUNCH B */
    {  107,  107,    0,    0,    1,    0,    0,    1 },  /* 77: L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   50,   50,    0,   32,    1,   32,    0,    1 },  /* 78: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  103,  103,    0,    0,    1,    0,    0,    1 },  /* 79: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   51,   51,    0,   33,   11,   33,    0,    2 },  /* 80: KAGAMI P A */
    {   51,   51,    0,   34,    2,   34,    0,    2 },  /* 81: KAGAMI P A, follow-up of KAGAMI K A */
    {   51,   51,    0,    0,    2,    0,    0,    2 },  /* 82: KAGAMI P A, follow-up of KAGAMI K A */
    {   52,   52,    0,    0,    2,    0,    0,    2 },  /* 83: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    {   53,   53,    0,   35,    2,   35,    0,    2 },  /* 84: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    {   53,   53,    0,   36,    2,   36,    0,    2 },  /* 85: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    {  104,  104,    0,    0,    2,    0,    0,    2 },  /* 86: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    {   54,   54,    0,   37,   11,   37,    0,    2 },  /* 87: KAGAMI K A */
    {   54,   54,    0,   38,   11,   38,    0,    2 },  /* 88: KAGAMI K A */
    {   54,   54,    0,    0,   11,    0,    0,    2 },  /* 89: KAGAMI K A */
    {   55,   55,    0,    0,    3,    0,    0,    3 },  /* 90: V JUMP P S A, V JUMP P M A */
    {  117,  117,    0,   39,    3,   39,    0,    3 },  /* 91: V JUMP P S A */
    {  117,  117,    0,    0,    3,    0,    0,    3 },  /* 92: V JUMP P S A, V JUMP P M A */
    {   56,   56,    0,   40,    3,   40,    0,    3 },  /* 93: V JUMP P S A */
    {   57,   57,    0,    0,    3,    0,    0,    3 },  /* 94: V JUMP P L A */
    {   58,   58,    0,    0,    3,    0,    0,    3 },  /* 95: V JUMP P L A, follow-up of F JUMP P S A */
    {   59,   59,    0,   41,    3,   41,    0,    3 },  /* 96: V JUMP P L A, follow-up of F JUMP P S A */
    {   59,   59,    0,   76,    3,   76,    0,    3 },  /* 97: V JUMP P L A, follow-up of F JUMP P S A */
    {   60,   60,    0,    0,    3,    0,    0,    3 },  /* 98: V JUMP K S A, V JUMP K M A */
    {   61,   61,    0,   42,    3,   42,    0,    3 },  /* 99: V JUMP K S A */
    {   61,   61,    0,   43,    3,   43,    0,    3 },  /* 100: V JUMP K S A, V JUMP K M A */
    {   61,   61,    0,    0,    3,    0,    0,    3 },  /* 101: V JUMP K M A */
    {   62,   62,    0,    0,    3,    0,    0,    3 },  /* 102: V JUMP K M A */
    {   63,   63,    0,    0,    3,    0,    0,    3 },  /* 103: F JUMP P S A, F JUMP P M A, not started by a command */
    {   64,   64,    0,   44,    3,   44,    0,    3 },  /* 104: F JUMP P S A */
    {   64,   64,    0,   45,    3,   45,    0,    3 },  /* 105: F JUMP P S A, F JUMP P M A */
    {   65,   65,    0,    0,    2,    0,    0,    2 },  /* 106: not used by a script */
    {   66,   66,    0,    0,    2,    0,    0,    2 },  /* 107: not used by a script */
    {   67,   67,    0,   46,    2,   46,    0,    2 },  /* 108: not used by a script */
    {   67,   67,    0,    0,    2,    0,    0,    2 },  /* 109: not used by a script */
    {  116,  116,    0,   47,    1,   47,    0,    1 },  /* 110: follow-up of M PUNCH C, UP P GUARD P S */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 111: TATAKI S, KGM TATAKI S, OKIAGARI +18 */
    {   68,   68,    0,    0,    1,    0,    0,    1 },  /* 112: not used by a script */
    {   69,   69,    0,   48,    1,   48,    0,    1 },  /* 113: L KICK A */
    {   69,   69,    0,    0,    1,    0,    0,    1 },  /* 114: L KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {    1,    1,    0,   49,    1,   49,    0,    1 },  /* 115: not used by a script */
    {   74,   74,    0,   50,    3,   50,    0,    3 },  /* 116: not used by a script */
    {  134,  134,    0,    0,    1,    0,    0,    1 },  /* 117: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  134,  134,    0,   48,    1,   48,    0,    1 },  /* 118: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  134,  134,    0,   51,    3,   51,    0,    1 },  /* 119: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  135,  135,    0,   52,    3,   52,    0,    1 },  /* 120: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  135,  135,    0,   53,    3,   53,    0,    1 },  /* 121: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {    1,    1,    0,   55,    1,   55,    0,    1 },  /* 122: M PUNCH A, M PUNCH C, L PUNCH A +2 */
    {   76,   76,    0,    0,    2,    0,    0,    2 },  /* 123: not used by a script */
    {   77,   77,    0,    0,    2,    0,    0,    2 },  /* 124: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    {   78,   78,    0,   56,    2,   56,    0,    2 },  /* 125: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +1 */
    {  122,  122,    0,   57,    2,   57,    0,    2 },  /* 126: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +1 */
    {   79,   79,    0,   58,    3,   58,    0,    3 },  /* 127: not used by a script */
    {   80,   80,    0,    0,    1,    0,    0,    5 },  /* 128: L PUNCH B */
    {   81,   81,    0,   59,    1,   59,    0,    5 },  /* 129: L PUNCH B */
    {   82,   82,    0,    0,    5,    0,    0,    6 },  /* 130: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    {   82,   82,    0,   49,    5,   49,    0,    6 },  /* 131: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI) */
    {   83,   83,    0,   60,    3,   60,    0,    3 },  /* 132: not used by a script */
    {   84,   84,    0,   61,    3,   61,    0,    3 },  /* 133: not used by a script */
    {   85,   85,    0,   62,    3,   62,    0,    3 },  /* 134: not used by a script */
    {   86,   86,    0,   63,    1,   63,    0,    1 },  /* 135: not used by a script */
    {   86,   86,    0,   64,    1,   64,    0,    1 },  /* 136: not used by a script */
    {   87,   87,    0,    0,    6,    0,    0,    7 },  /* 137: AIR S, AIR M, AIR L +49 */
    {   88,   88,    0,    0,    7,    0,    0,    8 },  /* 138: not used by a script */
    {   93,   93,    0,    0,    3,    0,    0,    9 },  /* 139: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   89,   89,    0,   65,    3,   65,    0,    9 },  /* 140: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   90,   90,    0,    0,    3,    0,    0,    3 },  /* 141: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   90,   90,    0,   66,    3,   66,    0,    3 },  /* 142: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   92,   92,    0,   67,    5,   67,    0,    6 },  /* 143: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   91,   91,    0,    0,    5,    0,    0,    6 },  /* 144: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,   92,    0,    0,    5,    0,    0,    6 },  /* 145: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,   92,    0,   68,    5,   68,    0,    6 },  /* 146: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,   92,    0,   69,    5,   69,    0,    6 },  /* 147: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,   92,    0,   70,    5,   70,    0,    6 },  /* 148: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,   92,    0,   71,    5,   71,    0,    6 },  /* 149: not used by a script */
    {   92,   92,    0,   72,    5,   72,    0,    6 },  /* 150: not used by a script */
    {   94,   94,    0,    0,    2,    0,    0,    2 },  /* 151: KAGAMI K A, ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1) +2 */
    {   94,   94,    0,   73,    2,   73,    0,    2 },  /* 152: not used by a script */
    {   95,   95,    0,   74,    2,   74,    0,    2 },  /* 153: ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1), ATTACK 4 L: 236+K heavy (routine Att_PL07_AT1) +1 */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 154: AIR S, AIR M, AIR L +2 */
    {  110,  110,    0,   75,    2,   75,    0,    2 },  /* 155: KAGAMI K A */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 156: not used by a script */
    {   97,   97,    0,    0,    8,    0,    0,   10 },  /* 157: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    {   98,   98,    0,    0,    8,    0,    0,   10 },  /* 158: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    {   99,   99,    0,    0,    8,    0,    0,   10 },  /* 159: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    {  135,  135,    0,   54,    3,   54,    0,    1 },  /* 160: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,  135,    0,   89,    3,   89,    0,    1 },  /* 161: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {    0,    0,    0,    0,    0,    0,    0,    8 },  /* 162: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    6 },  /* 163: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {    0,    0,    0,    0,    0,    0,    0,   10 },  /* 164: ATTACK 10 S: SA I air 23623+P light (routine Att_PL07_SA3), ATTACK 10 M: SA I air 23623+P medium (routine Att_PL07_SA3), ATTACK 10 L: SA I air 23623+P heavy/EX (routine Att_PL07_SA3) */
    {   57,   57,    0,   78,    3,   78,    0,    3 },  /* 165: V JUMP P L A */
    {  108,  108,    0,    0,    3,    0,    0,    3 },  /* 166: L KICK C */
    {  109,  109,    0,   79,    2,   79,    0,    2 },  /* 167: KAGAMI P A, follow-up of KAGAMI K A */
    {  140,  140,    0,   80,    1,   80,    0,    1 },  /* 168: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    {   23,   23,    0,   81,    2,   81,    0,    2 },  /* 169: ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    {  112,  112,    0,    0,    8,    0,    0,   10 },  /* 170: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    {  113,  113,    0,    0,    8,    0,    0,   10 },  /* 171: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    {  114,  114,    0,    0,    8,    0,    0,   10 },  /* 172: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +3 */
    {    0,    0,    0,   49,    0,   49,    0,    6 },  /* 173: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {  115,  115,    0,   82,    3,   82,    0,    3 },  /* 174: V JUMP K M A */
    {  118,  118,    0,   83,    3,   83,    0,    3 },  /* 175: V JUMP P M A */
    {  119,  119,    0,   84,    3,   84,    0,    3 },  /* 176: V JUMP P M A */
    {  120,  120,    0,    0,    1,    0,    0,    1 },  /* 177: not used by a script */
    {  121,  121,    0,    0,    1,    0,    0,    1 },  /* 178: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +1 */
    {  123,  123,    0,    0,    3,    0,    0,    9 },  /* 179: ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2), ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    {   38,   38,    0,   85,    1,   85,    0,    1 },  /* 180: not used by a script */
    {  125,  125,    0,    0,    3,    0,    0,    3 },  /* 181: M KICK C */
    {   23,   23,    0,    0,    2,    0,    0,    2 },  /* 182: KAGAMI K A, follow-up of M PUNCH C / L PUNCH A */
    {  126,  126,    0,   86,    3,   86,    0,    3 },  /* 183: F JUMP P M A */
    {   38,   38,    0,   87,    1,   87,    0,    1 },  /* 184: S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {    1,    1,    0,   88,    1,   88,    0,    1 },  /* 185: not used by a script */
    {  135,  135,    0,   90,    3,   90,    0,    1 },  /* 186: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,  135,    0,   91,    3,   91,    0,    1 },  /* 187: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,  135,    0,   92,    3,   92,    0,    1 },  /* 188: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,  135,    0,   93,    3,   93,    0,    1 },  /* 189: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,  135,    0,    0,    3,    0,    0,    1 },  /* 190: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {   44,   44,    0,    0,    3,    0,    0,    1 },  /* 191: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  132,  132,    0,    0,    1,    0,    0,    1 },  /* 192: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  132,  132,    0,   48,    1,   48,    0,    1 },  /* 193: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  132,  132,    0,   51,    1,   51,    0,    1 },  /* 194: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,  137,    0,   52,    3,   52,    0,    1 },  /* 195: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,  137,    0,   53,    3,   53,    0,    1 },  /* 196: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,  137,    0,   54,    3,   54,    0,    1 },  /* 197: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,  137,    0,   94,    3,   94,    0,    1 },  /* 198: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   55,   55,    0,   78,    3,   78,    0,    3 },  /* 199: V JUMP P M A */
    {   63,   63,    0,   99,    3,   99,    0,    3 },  /* 200: F JUMP P M A */
    {  127,  127,    0,    0,   10,    0,    0,   12 },  /* 201: PIYO */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 202: CATCH 5, CATCH 22, CATCH 23 +1 */
    {  126,  126,    0,  100,    3,  100,    0,    3 },  /* 203: not started by a command */
    {   64,   64,    0,  101,    3,  101,    0,    3 },  /* 204: not started by a command */
    {   70,   70,    0,  102,    3,  102,    0,    3 },  /* 205: not started by a command */
    {   71,   71,    0,  103,    3,  103,    0,    3 },  /* 206: not started by a command */
    {   72,   72,    0,  104,    3,  104,    0,    3 },  /* 207: not started by a command */
    {  128,  128,    0,    0,    2,    0,    0,    2 },  /* 208: ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1), ATTACK 4 L: 236+K heavy (routine Att_PL07_AT1) */
    {  129,  129,    0,    0,   10,    0,    0,   12 },  /* 209: PIYO */
    {    0,    0,    0,    0,    0,    0,    0,   13 },  /* 210: NEKOROBI S, dmca 96 */
    {  130,  130,    0,  105,    1,  105,    0,    1 },  /* 211: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  131,  131,    0,  106,    1,  106,    0,    1 },  /* 212: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   45,   45,    0,   95,    3,   95,    0,    1 },  /* 213: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   45,   45,    0,   96,    3,   96,    0,    1 },  /* 214: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   78,   78,    0,  107,    2,  107,    0,    2 },  /* 215: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  122,  122,    0,  108,    2,  108,    0,    2 },  /* 216: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   50,   50,    0,  109,    1,  109,    0,    1 },  /* 217: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   45,   45,    0,  110,    1,  110,    0,    1 },  /* 218: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   45,   45,    0,  111,   12,  111,    0,    1 },  /* 219: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  137,  137,    0,   97,    3,   97,    0,    1 },  /* 220: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,  137,    0,   98,    3,   98,    0,    1 },  /* 221: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,  137,    0,    0,    3,    0,    0,    1 },  /* 222: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   44,   44,    0,    0,    3,    0,    0,    1 },  /* 223: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  133,  133,    0,    0,    1,    0,    0,    1 },  /* 224: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  133,  133,    0,   48,    1,   48,    0,    1 },  /* 225: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  133,  133,    0,   51,    1,   51,    0,    1 },  /* 226: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,  112,    3,  112,    0,    1 },  /* 227: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,  113,    3,  113,    0,    1 },  /* 228: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,   54,    3,   54,    0,    1 },  /* 229: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,   94,    3,  117,    0,    1 },  /* 230: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,   95,    3,  118,    0,    1 },  /* 231: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,   96,    3,  119,    0,    1 },  /* 232: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,   97,    3,  120,    0,    1 },  /* 233: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,   98,    3,  121,    0,    1 },  /* 234: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,  138,    0,    0,    3,    0,    0,    1 },  /* 235: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {   44,   44,    0,    0,    3,    0,    0,    1 },  /* 236: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 237: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  139,  139,    0,    0,    5,    0,    0,    6 },  /* 238: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   51,   51,    0,   34,   11,   34,    0,    2 },  /* 239: KAGAMI P A */
    {   51,   51,    0,    0,   11,    0,    0,    2 },  /* 240: KAGAMI P A */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 241: follow-up of SP WIN 2 */
    {    2,    2,    0,    0,    0,    0,    0,    2 },  /* 242: follow-up of SP WIN 2 */
    {   82,   82,    0,  114,    5,  114,    0,    6 },  /* 243: ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) */
    {   82,   82,    0,  115,    5,  115,    0,    6 },  /* 244: ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 245: LOSE SONABA */
    {   45,   45,    0,    0,   12,    0,    0,    1 },  /* 246: not started by a command, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   44,   44,    0,    0,   12,    0,    0,    1 },  /* 247: not started by a command, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  141,    0,    0,  116,    3,    0,    0,    3 },  /* 248: not started by a command */
    {    6,    0,    0,    0,    3,    0,    0,    0 },  /* 249: CATCH 20, CATCH 21 */
    {   12,    0,    0,    0,    0,    0,    0,   13 },  /* 250: dmca 97 */
    {    0,    0,    0,   48,    0,   48,    0,    1 },  /* 251: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  142,    0,    0,    0,    3,    0,    0,    3 },  /* 252: not started by a command */
    {   14,   14,    0,    0,    4,    0,    0,    0 },  /* 253: DASH HUMIKOMI */
    {  140,  144,    0,    0,    1,  116,    0,    1 },  /* 254: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0,  117,    0,    0,    0,    0 },  /* 255: CATCH 22, CATCH 23 */
    {  143,    0,    0,    0,    2,    0,    0,    2 },  /* 256: ATTACK 4 SP: EX 236+KK (routine Att_PL07_AT1) */
    {   42,  141,    0,    0,    1,    0,    0,    1 },  /* 257: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    {   42,  142,    0,    0,    1,    0,    0,    1 },  /* 258: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    {   42,  143,    0,    0,    1,    0,    0,    1 },  /* 259: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    {   42,  144,    0,    0,    1,    0,    0,    1 },  /* 260: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    {  140,  145,    0,    0,    1,   80,    0,    1 },  /* 261: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    {  140,  146,    0,    0,    1,   80,    0,    1 },  /* 262: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
};

const BODY_BOX ibuki_body_box[144] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -19,  23,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +120 */
    { { {  -19,  20,  45,  18 },  {    0,   0,   0,   0 },  {  -36,  58,   0,  58 },  {  -48,  80,   0,  27 } } },  /* 2: DASH TOBINOKI, KAGAMU, KAGAMI KAMAE +47 */
    { { {  -28,  20,  74,  18 },  {  -44,  56,  66,  15 },  {  -30,  36,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 3: S PUNCH A, ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -28,  20,  74,  18 },  {  -36,  48,  66,  15 },  {  -24,  34,  37,  29 },  {  -36,  68,   0,  37 } } },  /* 4: S PUNCH B */
    { { {  -28,  20,  74,  18 },  {  -36,  48,  66,  15 },  {  -24,  34,  37,  29 },  {  -36,  68,   0,  37 } } },  /* 5: S PUNCH B */
    { { {  -14,  20,  92,  18 },  {  -28,  46,  86,  12 },  {  -19,  38,  70,  19 },  {  -38,  60,  45,  25 } } },  /* 6: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  64,  44,  50 },  {    0,   0,   0,   0 } } },  /* 7: JUMP FRONT, JUMP BACK, SP JUMP FRONT +21 */
    { { {  -14,  20,  92,  18 },  {  -29,  48,  86,  12 },  {  -23,  43,  67,  19 },  {  -29,  54,  38,  29 } } },  /* 8: JUMP FRONT, JUMP VERTICAL, JUMP BACK +29 */
    { { {  -28,  20,  74,  18 },  {  -35,  44,  62,  16 },  {  -30,  36,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 9: S PUNCH A */
    { { {   -3,  20,  72,  18 },  {  -22,  54,  66,  15 },  {  -11,  39,  34,  32 },  {  -30,  68,   0,  37 } } },  /* 10: GUARD HEAD, GUARD UP */
    { { {  -15,  20,  45,  18 },  {    0,   0,   0,   0 },  {  -34,  58,   0,  56 },  {  -44,  78,   0,  27 } } },  /* 11: GUARD DOWN */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 12: dmca 97 */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -40,  72,   0,  37 } } },  /* 13: DASH HUMIKOMI */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -40,  72,   0,  37 } } },  /* 14: DASH HUMIKOMI, nmca 33 */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -40,  72,   0,  37 } } },  /* 15: DASH HUMIKOMI, CATCH 5, CATCH 24 */
    { { {  -22,  20,  63,  18 },  {    0,   0,   0,   0 },  {  -30,  48,  27,  44 },  {  -40,  72,   0,  37 } } },  /* 16: DASH TOBINOKI, not started by a command */
    { { {  -22,  20,  88,  18 },  {  -45,  59,  80,  14 },  {  -39,  48,  17,  63 },  {  -34,  44,  34,  20 } } },  /* 17: DASH TOBINOKI, ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2) +2 */
    { { {  -20,  20,  62,  18 },  {  -29,  48,  54,  15 },  {  -43,  70,  38,  20 },  {  -36,  68,   0,  37 } } },  /* 18: M KICK C, follow-up of M KICK B */
    { { {  -16,  20,  82,  18 },  {  -23,  52,  76,  15 },  {  -16,  43,  36,  40 },  {    0,   0,   0,   0 } } },  /* 19: M KICK C, follow-up of M KICK B */
    { { {  -16,  20,  92,  18 },  {  -43,  61,  81,  15 },  {  -28,  51,  59,  22 },  {  -11,  34,  44,  16 } } },  /* 20: M KICK C, follow-up of M KICK B */
    { { {   -8,  20,  88,  18 },  {  -30,  48,  78,  15 },  {  -45,  62,  54,  25 },  {  -27,  44,  36,  19 } } },  /* 21: M KICK C, follow-up of M KICK B */
    { { {    2,  20,  84,  18 },  {  -26,  48,  69,  15 },  {  -38,  48,  18,  51 },  {  -64,  46,  29,  31 } } },  /* 22: M KICK C, follow-up of M KICK B */
    { { {  -18,  20,  48,  18 },  {  -36,  54,  40,  19 },  {    0,   0,   0,   0 },  {  -48,  75,   0,  40 } } },  /* 23: KAGAMI K A, follow-up of M PUNCH C / L PUNCH A, UP P GUARD K S +2 */
    { { {  -14,  20,  84,  18 },  {  -28,  46,  75,  15 },  {  -30,  52,  53,  22 },  {  -27,  45,  21,  32 } } },  /* 24: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -14,  20,  84,  18 },  {  -28,  46,  75,  15 },  {  -34,  64,  56,  19 },  {  -18,  45,  21,  36 } } },  /* 25: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -16,  20,  86,  18 },  {  -24,  54,  78,  15 },  {  -26,  55,  34,  44 },  {    0,   0,   0,   0 } } },  /* 26: L KICK C */
    { { {  -16,  20,  90,  18 },  {  -30,  48,  83,  15 },  {  -18,  40,  62,  26 },  {  -10,  39,  27,  44 } } },  /* 27: L KICK C */
    { { {  -16,  20,  98,  18 },  {  -27,  48,  88,  15 },  {  -39,  74,  63,  26 },  {    0,   0,   0,   0 } } },  /* 28: L KICK C */
    { { {  -20,  20,  84,  18 },  {  -25,  48,  73,  15 },  {  -32,  43,  64,   9 },  {  -19,  44,  33,  15 } } },  /* 29: F JUMP K S A */
    { { {   -8,  20,  87,  18 },  {  -16,  49,  82,  15 },  {  -39,  65,  58,  24 },  {  -44,  70,  38,  26 } } },  /* 30: F JUMP K M A, follow-up of V JUMP P L A / F JUMP K S A, FUSHIN P S */
    { { {   -8,  20,  87,  18 },  {  -16,  49,  82,  15 },  {  -39,  65,  58,  24 },  {  -41,  80,  41,  18 } } },  /* 31: F JUMP K M A, follow-up of V JUMP P L A / F JUMP K S A, FUSHIN P S */
    { { {  -26,  20,  67,  18 },  {  -36,  56,  58,  15 },  {  -26,  42,  30,  32 },  {  -36,  68,   0,  37 } } },  /* 32: M PUNCH C, follow-up of S PUNCH A */
    { { {  -26,  20,  67,  18 },  {  -36,  56,  58,  15 },  {  -26,  42,  30,  32 },  {  -36,  68,   0,  37 } } },  /* 33: M PUNCH C, follow-up of S PUNCH A */
    { { {  -16,  20,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 34: M PUNCH A */
    { { {  -16,  20,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 35: M PUNCH A */
    { { {  -20,  20,  72,  18 },  {  -36,  56,  63,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 36: L PUNCH A */
    { { {   -2,  20,  74,  18 },  {  -28,  56,  66,  15 },  {  -26,  42,  34,  32 },  {   -7,  40,   0,  44 } } },  /* 37: S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {   -2,  20,  74,  18 },  {  -28,  56,  66,  15 },  {  -26,  42,  34,  32 },  {   -7,  40,   0,  44 } } },  /* 38: S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -16,  20,  70,  18 },  {  -36,  56,  62,  15 },  {  -26,  42,  34,  32 },  {  -38,  46,   0,  38 } } },  /* 39: S KICK B */
    { { {  -16,  20,  78,  18 },  {  -36,  56,  70,  15 },  {  -26,  42,  38,  32 },  {  -30,  56,   0,  44 } } },  /* 40: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    4,  20,  76,  18 },  {  -28,  54,  67,  15 },  {  -20,  40,  39,  28 },  {  -20,  51,   0,  39 } } },  /* 41: M KICK B, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    { { {    4,  20,  74,  18 },  {  -27,  52,  63,  19 },  {  -26,  40,  40,  24 },  {  -34,  57,   0,  45 } } },  /* 42: M KICK B, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    { { {    4,  20,  72,  18 },  {  -13,  40,  62,  20 },  {  -36,  47,  39,  23 },  {  -20,  51,   0,  39 } } },  /* 43: M KICK B, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +9 */
    { { {  -16,  20,  78,  18 },  {  -43,  50,  72,  15 },  {  -39,  51,  46,  24 },  {  -34,  47,   0,  34 } } },  /* 44: L KICK A, ATTACK 6 S: not started by a command, not started by a command +5 */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,   0,  34 } } },  /* 45: L KICK A, ATTACK 6 S: not started by a command, not started by a command +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {  -16,  20,  74,  18 },  {  -30,  46,  65,  15 },  {  -27,  40,  36,  29 },  {  -24,  55,   0,  37 } } },  /* 47: L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -16,  20,  74,  18 },  {  -30,  46,  65,  15 },  {  -27,  40,  36,  29 },  {  -48,  76,   0,  34 } } },  /* 48: TOUKETSU A, L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -21,  20,  66,  18 },  {  -27,  46,  54,  15 },  {  -26,  40,  29,  29 },  {  -40,  76,   0,  34 } } },  /* 49: L PUNCH B */
    { { {  -16,  20,  78,  18 },  {  -36,  56,  70,  15 },  {  -26,  42,  38,  32 },  {  -30,  56,   0,  44 } } },  /* 50: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -19,  20,  50,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  80,   0,  38 } } },  /* 51: KAGAMI P A, follow-up of KAGAMI K A */
    { { {  -25,  20,  62,  18 },  {  -39,  46,  53,  15 },  {  -39,  55,  33,  20 },  {  -40,  78,   0,  33 } } },  /* 52: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    { { {  -19,  20,  66,  18 },  {  -39,  56,  53,  23 },  {  -39,  55,  33,  20 },  {  -40,  78,   0,  34 } } },  /* 53: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    { { {   -4,  20,  50,  18 },  {  -18,  50,  38,  19 },  {  -26,  63,   0,  38 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI K A */
    { { {  -10,  20,  86,  18 },  {  -26,  56,  78,  15 },  {  -19,  46,  60,  18 },  {  -36,  69,  41,  19 } } },  /* 55: V JUMP P S A, V JUMP P M A */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 56: V JUMP P S A */
    { { {  -16,  20,  87,  18 },  {  -34,  44,  76,  15 },  {  -24,  30,  62,  14 },  {  -36,  52,  29,  33 } } },  /* 57: V JUMP P L A */
    { { {  -10,  20,  87,  18 },  {  -22,  44,  77,  15 },  {  -18,  31,  63,  14 },  {  -16,  50,  31,  32 } } },  /* 58: V JUMP P L A, follow-up of F JUMP P S A */
    { { {  -20,  20,  82,  18 },  {  -30,  42,  72,  15 },  {    0,   0,   0,   0 },  {  -18,  48,  33,  39 } } },  /* 59: V JUMP P L A, follow-up of F JUMP P S A */
    { { {  -18,  20,  87,  18 },  {  -26,  42,  77,  15 },  {    0,   0,   0,   0 },  {  -33,  56,  33,  44 } } },  /* 60: V JUMP K S A, V JUMP K M A */
    { { {  -18,  20,  87,  18 },  {  -32,  47,  74,  19 },  {  -23,  42,  52,  22 },  {  -16,  33,  16,  36 } } },  /* 61: V JUMP K S A, V JUMP K M A */
    { { {  -18,  20,  87,  18 },  {  -26,  44,  78,  15 },  {  -21,  43,  18,  60 },  {  -63,  43,  43,  22 } } },  /* 62: V JUMP K M A */
    { { {  -43,  20,  76,  18 },  {  -46,  50,  70,  15 },  {  -43,  51,  50,  20 },  {  -35,  67,  29,  21 } } },  /* 63: F JUMP P S A, F JUMP P M A, not started by a command */
    { { {  -43,  20,  76,  18 },  {  -47,  58,  73,  15 },  {  -42,  51,  53,  20 },  {  -23,  51,  28,  25 } } },  /* 64: F JUMP P S A, F JUMP P M A, not started by a command */
    { { {   -8,  16,  51,  14 },  {  -19,  40,  42,  12 },  {  -16,  32,  26,  12 },  {  -32,  62,   0,  26 } } },  /* 65: not used by a script */
    { { {  -25,  16,  51,  14 },  {  -19,  40,  42,  12 },  {  -16,  32,  26,  12 },  {  -32,  62,   0,  26 } } },  /* 66: not used by a script */
    { { {  -25,  16,  51,  14 },  {  -19,  40,  42,  12 },  {  -16,  32,  26,  12 },  {  -32,  62,   0,  26 } } },  /* 67: not used by a script */
    { { {    0,   0,   0,   0 },  {  -22,  38,  66,  12 },  {  -16,  28,  40,  24 },  {  -30,  54,   0,  38 } } },  /* 68: not used by a script */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,   0,  34 } } },  /* 69: L KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -14,  20,  84,  18 },  {  -26,  48,  66,  24 },  {  -38,  58,  48,  28 },  {  -10,  37,  17,  43 } } },  /* 70: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -14,  20,  84,  18 },  {  -25,  43,  66,  27 },  {  -42,  62,  45,  21 },  {  -10,  40,  14,  43 } } },  /* 71: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -14,  20,  84,  18 },  {  -25,  43,  66,  24 },  {  -37,  56,  43,  23 },  {  -10,  40,  14,  43 } } },  /* 72: not started by a command */
    { { {  -18,  20,  84,  18 },  {  -23,  48,  76,  15 },  {  -28,  54,  45,  31 },  {    0,   0,   0,   0 } } },  /* 73: F JUMP K S A */
    { { {   -7,  20,  86,  18 },  {  -19,  44,  80,  15 },  {  -19,  42,  46,  32 },  {    0,   0,   0,   0 } } },  /* 74: not used by a script */
    { { {  -27,  16,  73,  14 },  {  -32,  38,  64,  13 },  {  -27,  32,  42,  20 },  {  -32,  54,   0,  40 } } },  /* 75: not used by a script */
    { { {    0,   0,   0,   0 },  {  -22,  44,  33,  18 },  {  -26,  48,  15,  22 },  {    0,   0,   0,   0 } } },  /* 76: not used by a script */
    { { {   20,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -24,  50,   0,  84 },  {    0,   0,   0,   0 } } },  /* 77: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    { { {   20,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -28,  56,   0,  68 },  {  -73,  63,  80,  22 } } },  /* 78: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    { { {  -19,  16,  85,  14 },  {  -37,  48,  71,  13 },  {  -23,  30,  51,  22 },  {   -2,  47,   0,  48 } } },  /* 79: not used by a script */
    { { {  -39,  20,  63,  18 },  {  -58,  46,  55,  15 },  {  -45,  28,  34,  21 },  {  -51,  71,   0,  34 } } },  /* 80: L PUNCH B */
    { { {  -41,  20,  63,  18 },  {  -51,  46,  55,  15 },  {  -42,  42,  34,  21 },  {  -51,  71,   0,  34 } } },  /* 81: L PUNCH B */
    { { {  -47,  41,  70,  18 },  {  -69,  81,  59,  17 },  {  -54,  68,  36,  24 },  {  -62,  86,   0,  37 } } },  /* 82: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -11,  20,  90,  18 },  {  -22,  43,  83,  15 },  {  -27,  42,  64,  24 },  {  -18,  30,  21,  47 } } },  /* 83: not used by a script */
    { { {   -6,  20,  87,  18 },  {  -23,  46,  80,  15 },  {  -37,  55,  54,  26 },  {  -21,  33,  16,  38 } } },  /* 84: not used by a script */
    { { {   -3,  20,  84,  18 },  {  -23,  48,  75,  15 },  {  -18,  34,  50,  25 },  {  -44,  45,  23,  37 } } },  /* 85: not used by a script */
    { { {   -5,  20,  79,  18 },  {  -19,  56,  70,  15 },  {  -34,  62,  38,  32 },  {  -11,  40,   0,  38 } } },  /* 86: not used by a script */
    { { {  -18,  45,  68,  16 },  {  -24,  56,  55,  17 },  {  -23,  52,  41,  14 },  {  -20,  45,  28,  13 } } },  /* 87: AIR S, AIR M, AIR L +49 */
    { { {  -21,  20,  43,  18 },  {  -24,  39,  37,  15 },  {  -19,  52,  13,  24 },  {  -30,  68,   0,  15 } } },  /* 88: not used by a script */
    { { {  -24,  20,  78,  18 },  {  -33,  48,  73,  15 },  {  -19,  50,  48,  25 },  {  -86, 116,  19,  29 } } },  /* 89: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {  -18,  20,  84,  18 },  {  -36,  48,  76,  15 },  {  -39,  68,  53,  23 },  {  -66,  60,  28,  25 } } },  /* 90: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {  -41,  20,  74,  18 },  {  -53,  65,  60,  21 },  {  -53,  63,  37,  24 },  {  -62,  81,   0,  37 } } },  /* 91: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {  -51,  20,  70,  18 },  {  -49,  62,  57,  19 },  {  -55,  48,  37,  19 },  {  -62,  81,   0,  37 } } },  /* 92: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {  -18,  20,  84,  18 },  {  -36,  48,  76,  15 },  {  -39,  54,  51,  25 },  {  -42,  66,   1,  50 } } },  /* 93: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {   -2,  20,  30,  18 },  {  -16,  44,  26,  18 },  {  -16,  49,   0,  26 },  {  -45,  29,  26,  16 } } },  /* 94: KAGAMI K A, ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1) +2 */
    { { {   -2,  20,  30,  18 },  {  -16,  44,  26,  18 },  {  -16,  46,   0,  37 },  {  -37,  21,  26,  21 } } },  /* 95: ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1), ATTACK 4 L: 236+K heavy (routine Att_PL07_AT1) +1 */
    { { {  -21,  16,  78,  14 },  {  -29,  41,  75,  12 },  {  -30,  47,  33,  48 },  {    0,   0,   0,   0 } } },  /* 96: not used by a script */
    { { {  -23,  20,  60,  18 },  {  -53, 106,  67,  27 },  {    0,   0,   0,   0 },  {  -38,  70,  90,  66 } } },  /* 97: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    { { {  -30,  20,  63,  18 },  {  -55, 100,  76,  23 },  {  -24,  53,  94,  22 },  {  -21,  75, 116,  31 } } },  /* 98: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    { { {  -19,  20,  58,  18 },  {  -34,  59,  63,  16 },  {  -29,  48,  79,  16 },  {  -43,  69,  95,  38 } } },  /* 99: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    { { {    4,  20,  74,  18 },  {  -27,  52,  63,  19 },  {  -26,  40,  40,  24 },  {  -34,  57,   0,  45 } } },  /* 100: M KICK B */
    { { {  -16,  20,  98,  18 },  {  -27,  48,  88,  15 },  {  -39,  74,  63,  26 },  {    0,   0,   0,   0 } } },  /* 101: L KICK C */
    { { {  -16,  20,  70,  18 },  {  -36,  56,  62,  15 },  {  -26,  42,  34,  32 },  {  -38,  46,   0,  38 } } },  /* 102: S KICK B */
    { { {  -16,  20,  78,  18 },  {  -36,  56,  70,  15 },  {  -26,  42,  38,  32 },  {  -30,  56,   0,  44 } } },  /* 103: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -23,  20,  68,  18 },  {  -39,  47,  53,  22 },  {  -39,  55,  33,  20 },  {  -40,  78,   0,  34 } } },  /* 104: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    { { {  -16,  20,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 105: M PUNCH A */
    { { {  -20,  20,  72,  18 },  {  -36,  56,  63,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 106: L PUNCH A */
    { { {  -21,  20,  66,  18 },  {  -27,  46,  54,  15 },  {  -26,  40,  29,  29 },  {  -40,  76,   0,  34 } } },  /* 107: L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -16,  20,  98,  18 },  {  -44,  82,  94,  13 },  {  -29,  53,  63,  32 },  {  -52,  95,  34,  28 } } },  /* 108: L KICK C */
    { { {  -19,  20,  50,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  80,   0,  38 } } },  /* 109: KAGAMI P A, follow-up of KAGAMI K A */
    { { {   -2,  20,  30,  18 },  {  -16,  44,  26,  18 },  {  -16,  49,   0,  26 },  {    0,   0,   0,   0 } } },  /* 110: KAGAMI K A */
    { { {  -18,  20,  47,  18 },  {    0,   0,   0,   0 },  {  -36,  59,   0,  59 },  {  -68,  97,   0,  27 } } },  /* 111: KAGAMI K A, follow-up of M PUNCH C / L PUNCH A, UP P GUARD K S +2 */
    { { {  -39,  20,  59,  18 },  {  -55,  96,  72,  25 },  {    0,   0,   0,   0 },  {  -25,  84,  96,  33 } } },  /* 112: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    { { {  -41,  20,  64,  18 },  {  -21,  72,  62,  29 },  {    0,   0,   0,   0 },  {   -9,  55,  91,  22 } } },  /* 113: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    { { {  -41,  20,  64,  18 },  {  -21,  68,  62,  29 },  {    0,   0,   0,   0 },  {  -41,  34,  62,  40 } } },  /* 114: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +3 */
    { { {  -18,  20,  87,  18 },  {  -32,  47,  74,  19 },  {  -23,  42,  52,  22 },  {  -16,  33,  16,  36 } } },  /* 115: V JUMP K M A */
    { { {  -15,  20,  75,  18 },  {  -34,  58,  66,  18 },  {  -26,  42,  34,  32 },  {  -44,  76,   0,  37 } } },  /* 116: follow-up of M PUNCH C, UP P GUARD P S */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 117: V JUMP P S A, V JUMP P M A */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 118: V JUMP P M A */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 119: V JUMP P M A */
    { { {   -8,  20,  78,  18 },  {  -22,  46,  70,  15 },  {  -20,  49,  46,  24 },  {  -28,  60,   0,  46 } } },  /* 120: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  63,  28,  52 },  {  -26,  63,   0,  28 } } },  /* 121: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +1 */
    { { {   20,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -28,  56,   0,  68 },  {  -60,  50,  78,  20 } } },  /* 122: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    { { {  -18,  20,  84,  18 },  {  -36,  48,  76,  15 },  {  -39,  54,  51,  25 },  {  -33,  51,  39,  12 } } },  /* 123: ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2), ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    { { {  -26,  20,  67,  18 },  {  -36,  56,  58,  15 },  {  -26,  42,  30,  32 },  {  -36,  68,   0,  37 } } },  /* 124: M PUNCH C, follow-up of S PUNCH A */
    { { {  -16,  20,  92,  18 },  {  -43,  61,  81,  15 },  {  -28,  51,  59,  22 },  {  -11,  34,  44,  16 } } },  /* 125: M KICK C */
    { { {  -43,  20,  76,  18 },  {  -47,  58,  73,  15 },  {  -42,  51,  53,  20 },  {  -23,  51,  28,  25 } } },  /* 126: F JUMP P M A, not started by a command */
    { { {  -52,  20,  49,  18 },  {  -44,  62,  58,  19 },  {  -46,  70,  28,  29 },  {  -41,  79,   0,  27 } } },  /* 127: PIYO */
    { { {  -19,  20,  51,  18 },  {    0,   0,   0,   0 },  {  -36,  58,   0,  64 },  {  -48,  80,   0,  27 } } },  /* 128: ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1), ATTACK 4 L: 236+K heavy (routine Att_PL07_AT1) */
    { { {  -36,  28,  49,  18 },  {  -32,  62,  59,  19 },  {  -33,  68,  31,  28 },  {  -37,  77,   0,  30 } } },  /* 129: PIYO */
    { { {  -21,  20,  68,  18 },  {  -27,  52,  54,  15 },  {  -26,  42,  29,  29 },  {  -38,  78,   0,  34 } } },  /* 130: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -21,  20,  68,  18 },  {  -27,  52,  54,  15 },  {  -26,  42,  29,  29 },  {  -38,  78,   0,  34 } } },  /* 131: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  45,  37,  39 },  {  -30,  44,   0,  37 } } },  /* 132: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -30,  53,  23,  38 },  {  -38,  70,   0,  23 } } },  /* 133: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -15,  20,  73,  18 },  {  -26,  46,  66,  15 },  {  -18,  34,  34,  32 },  {  -24,  56,   0,  37 } } },  /* 134: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    { { {  -15,  20,  80,  18 },  {  -32,  50,  68,  16 },  {  -26,  36,  34,  34 },  {  -24,  31,  22,  12 } } },  /* 135: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    { { {  -15,  20,  73,  18 },  {  -26,  46,  66,  15 },  {  -18,  34,  34,  32 },  {  -24,  56,   0,  37 } } },  /* 136: not used by a script */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,  18,  16 } } },  /* 137: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,  18,  16 } } },  /* 138: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -49,  20,  70,  18 },  {  -75,  84,  57,  25 },  {  -56,  39,  36,  24 },  {  -62,  81,   0,  37 } } },  /* 139: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {    4,  20,  74,  18 },  {  -27,  52,  63,  19 },  {  -26,  40,  40,  24 },  {  -34,  57,   0,  45 } } },  /* 140: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -10,  20,  84,  16 },  {  -32,  46,  76,  12 },  {  -30,  38,  54,  20 },  {  -26,  48,  16,  36 } } },  /* 141: not started by a command */
    { { {  -14,  20,  83,  18 },  {  -29,  48,  79,  12 },  {  -24,  41,  60,  19 },  {  -29,  54,  21,  39 } } },  /* 142: not started by a command */
    { { {  -19,  20,  43,  18 },  {    0,   0,   0,   0 },  {  -36,  58,   0,  56 },  {  -48,  80,   0,  27 } } },  /* 143: ATTACK 4 SP: EX 236+KK (routine Att_PL07_AT1) */
};

const HAND_BOX ibuki_hand_box[147] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: no box */
    { { {  -63,  35,  61,  25 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -78,  50,  61,  25 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {  -58,  30,  63,  21 },  {    0,   0,   0,   0 } } },  /* 9: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: no box */
    { { {  -91,  61,  50,  26 },  {    0,   0,   0,   0 } } },  /* 21: M KICK C, follow-up of M KICK B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: no box */
    { { {  -86,  38,   0,  19 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI K A, follow-up of M PUNCH C / L PUNCH A, UP P GUARD K S +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: no box */
    { { {  -54,  36,  62,  36 },  {    0,   0,   0,   0 } } },  /* 27: L KICK C */
    { { {  -93,  69,  62,  23 },  {    0,   0,   0,   0 } } },  /* 28: L KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -73,  46,  36,  35 },  {    0,   0,   0,   0 } } },  /* 31: F JUMP K M A, follow-up of V JUMP P L A / F JUMP K S A, FUSHIN P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {  -63,  37,  75,  33 },  {    0,   0,   0,   0 } } },  /* 33: M PUNCH C, follow-up of S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { {  -75,  39,  62,  21 },  {    0,   0,   0,   0 } } },  /* 35: M PUNCH A */
    { { {  -57,  37,  61,  24 },  {    0,   0,   0,   0 } } },  /* 36: L PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -66,  60,  45,  28 },  {    0,   0,   0,   0 } } },  /* 38: S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -91,  65,  25,  25 },  {    0,   0,   0,   0 } } },  /* 39: S KICK B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {  -75,  48,  58,  22 },  {    0,   0,   0,   0 } } },  /* 42: M KICK B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {  -52,  42,  58,  68 },  {    0,   0,   0,   0 } } },  /* 45: L KICK A, ATTACK 6 S: not started by a command, not started by a command +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {  -56,  35,  49,  30 },  {    0,   0,   0,   0 } } },  /* 49: L PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {  -78, 106,  38,  19 },  {    0,   0,   0,   0 } } },  /* 51: KAGAMI P A, follow-up of KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {  -67,  52,  65,  41 },  {    0,   0,   0,   0 } } },  /* 53: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    { { {  -90,  64,   6,  27 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {  -87,  68,  65,  25 },  {    0,   0,   0,   0 } } },  /* 56: V JUMP P S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {  -67,  49,  57,  26 },  {    0,   0,   0,   0 } } },  /* 59: V JUMP P L A, follow-up of F JUMP P S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -92,  69,  39,  31 },  {    0,   0,   0,   0 } } },  /* 61: V JUMP K S A, V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {  -76,  43,  36,  34 },  {    0,   0,   0,   0 } } },  /* 64: F JUMP P S A, F JUMP P M A, not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {  -53,  35,  48,   8 },  {    0,   0,   0,   0 } } },  /* 67: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: no box */
    { { {  -50,  36,  59,  59 },  {    0,   0,   0,   0 } } },  /* 70: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -73,  49,  38,  34 },  {    0,   0,   0,   0 } } },  /* 71: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -65,  37,  12,  33 },  {    0,   0,   0,   0 } } },  /* 72: not started by a command */
    { { {  -47,  38,  28,  32 },  {    0,   0,   0,   0 } } },  /* 73: F JUMP K S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {  -44,  11,  53,  25 },  {    0,   0,   0,   0 } } },  /* 75: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {  -78,  54,  48,  29 },  {    0,   0,   0,   0 } } },  /* 77: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    { { { -106, 116,  60,  30 },  {    0,   0,   0,   0 } } },  /* 78: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no box */
    { { {  -73,  34,  49,  30 },  {    0,   0,   0,   0 } } },  /* 80: L PUNCH B */
    { { {  -77,  36,  46,  30 },  {    0,   0,   0,   0 } } },  /* 81: L PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {  -49,  38,  81,  22 },  {    0,   0,   0,   0 } } },  /* 83: not used by a script */
    { { {  -41,  35,  74,  24 },  {    0,   0,   0,   0 } } },  /* 84: not used by a script */
    { { {  -36,  33,  71,  23 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {  -85,  44,  44,  50 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { { -104, 124,  49,  45 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {  -75,  60,   0,  30 },  {    0,   0,   0,   0 } } },  /* 94: KAGAMI K A, ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1) +2 */
    { { {  -52,  49,   0,  26 },  {    0,   0,   0,   0 } } },  /* 95: ATTACK 4 S: 236+K light (routine Att_PL07_AT1), ATTACK 4 M: 236+K medium (routine Att_PL07_AT1), ATTACK 4 L: 236+K heavy (routine Att_PL07_AT1) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { { -104,  77,  60,  26 },  {    0,   0,   0,   0 } } },  /* 100: M KICK B */
    { { {  -87,  48,  53,  32 },  {    0,   0,   0,   0 } } },  /* 101: L KICK C */
    { { {  -79,  56,  16,  32 },  {    0,   0,   0,   0 } } },  /* 102: S KICK B */
    { { {  -54,  38,  34,  56 },  {    0,   0,   0,   0 } } },  /* 103: M KICK A, follow-up of S KICK A, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -59,  34,  61,  42 },  {    0,   0,   0,   0 } } },  /* 104: KAGAMI P A, follow-up of follow-up of KAGAMI K A, follow-up of KAGAMI P A */
    { { {  -75,  39,  62,  21 },  {    0,   0,   0,   0 } } },  /* 105: M PUNCH A */
    { { {  -50,  29,  32,  39 },  {    0,   0,   0,   0 } } },  /* 106: L PUNCH A */
    { { {  -56,  35,  49,  30 },  {    0,   0,   0,   0 } } },  /* 107: L PUNCH B, after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: no box */
    { { {  -68,  96,  38,  19 },  {    0,   0,   0,   0 } } },  /* 109: KAGAMI P A, follow-up of KAGAMI K A */
    { { {  -98,  82,   0,  30 },  {    0,   0,   0,   0 } } },  /* 110: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: no box */
    { { {  -78,  55,  40,  30 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: no box */
    { { {  -68,  49,  69,  23 },  {    0,   0,   0,   0 } } },  /* 117: V JUMP P S A, V JUMP P M A */
    { { {  -78,  59,  72,  24 },  {    0,   0,   0,   0 } } },  /* 118: V JUMP P M A */
    { { {  -70,  51,  72,  24 },  {    0,   0,   0,   0 } } },  /* 119: V JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: no box */
    { { {  -88,  98,  60,  28 },  {    0,   0,   0,   0 } } },  /* 122: L KICK B, follow-up of M KICK A, follow-up of follow-up of M PUNCH C / L PUNCH A +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: no box */
    { { {  -67,  41,  71,  33 },  {    0,   0,   0,   0 } } },  /* 124: M PUNCH C, follow-up of S PUNCH A */
    { { {  -78,  62,  71,  31 },  {    0,   0,   0,   0 } } },  /* 125: M KICK C */
    { { {  -72,  41,  40,  30 },  {    0,   0,   0,   0 } } },  /* 126: F JUMP P M A, not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 127: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: no box */
    { { {  -40,  50,  55,  25 },  {    0,   0,   0,   0 } } },  /* 130: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -48,  52,  48,  31 },  {    0,   0,   0,   0 } } },  /* 131: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 133: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: no box */
    { { {  -42,  40,  58,  78 },  {    0,   0,   0,   0 } } },  /* 135: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 136: no box */
    { { {  -49,  39,  58,  63 },  {    0,   0,   0,   0 } } },  /* 137: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -52,  36,  51,  52 },  {    0,   0,   0,   0 } } },  /* 138: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 139: no box */
    { { { -122,  95,  60,  26 },  {    0,   0,   0,   0 } } },  /* 140: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    { { {  -82,  55,  54,  26 },  {    0,   0,   0,   0 } } },  /* 141: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    { { {  -66,  39,  56,  22 },  {    0,   0,   0,   0 } } },  /* 142: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -46,  19,  57,  20 },  {    0,   0,   0,   0 } } },  /* 143: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    { { {  -50,  23,  54,  29 },  {    0,   0,   0,   0 } } },  /* 144: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    { { { -110,  83,  60,  26 },  {    0,   0,   0,   0 } } },  /* 145: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -92,  65,  54,  29 },  {    0,   0,   0,   0 } } },  /* 146: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
};

const HOSEI_BOX ibuki_hos_box[14] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -28,   56,    0,   77 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +130 */
    { {  -28,   56,    0,   53 } },  /* 2: DASH TOBINOKI, KAGAMU, KAGAMI KAMAE +69 */
    { {  -24,   48,   44,   48 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +53 */
    { {  -30,   60,    0,   72 } },  /* 4: DASH HUMIKOMI, nmca 33, CATCH 5 +5 */
    { {  -22,   44,   28,   36 } },  /* 5: L PUNCH B */
    { {  -32,   64,    0,   77 } },  /* 6: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    { {  -15,   40,   44,   38 } },  /* 7: AIR S, AIR M, AIR L +49 */
    { {  -28,   56,    0,   56 } },  /* 8: not used by a script */
    { {  -32,   61,   21,   58 } },  /* 9: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { {  -25,   48,   64,   53 } },  /* 10: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +16 */
    { {  -32,   64,   14,   78 } },  /* 11: DASH TOBINOKI, ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2) +2 */
    { {  -30,   60,    0,   62 } },  /* 12: PIYO */
    { {  -28,   56,    0,   30 } },  /* 13: NEKOROBI S, dmca 96, dmca 97 */
};
