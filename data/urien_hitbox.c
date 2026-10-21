/*
 * URIEN_HITBOX.C  Urien's hit boxes
 *
 * Each of Urien's animation frames names an entry of urien_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX urien_hit_ix_table[143] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: TATAKI M, TATAKI L, TATAKI SP +22 */
    {    1,    0,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +88 */
    {    2,    0,    0,    0,    2,    0,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +35 */
    {    3,    3,    0,    0,    6,    0,    0,    9 },  /* 3: DASH HUMIKOMI */
    {    4,    4,    0,    0,    6,    0,    0,    9 },  /* 4: DASH HUMIKOMI */
    {   19,    0,    0,    0,    1,    0,    0,    1 },  /* 5: S KICK A */
    {    6,    6,    0,    0,    1,    0,    0,    1 },  /* 6: DASH TOBINOKI */
    {    7,    7,    0,    0,    1,    0,    0,    1 },  /* 7: DASH HUMIKOMI, DASH TOBINOKI */
    {    8,    8,    0,    0,    3,    0,    0,    3 },  /* 8: S JUMP FRONT, GUARD AIR, V JUMP P M A +15 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 9: ATTACK 8 M: not started by a command */
    {   10,   10,    0,    0,    3,    0,    0,    3 },  /* 10: not used by a script */
    {   11,   11,    0,    1,    1,    1,    0,    1 },  /* 11: S PUNCH A, UP P GUARD P S */
    {   11,   11,    0,    0,    1,    0,    0,    1 },  /* 12: S PUNCH A, UP P GUARD P S */
    {   13,    0,    0,    0,    1,    0,    0,    1 },  /* 13: M PUNCH C, L PUNCH A */
    {   12,   12,    0,    0,    1,    0,    0,    1 },  /* 14: M PUNCH C */
    {   96,   96,    0,    3,    1,    3,    0,    1 },  /* 15: M PUNCH C, UP P GUARD P M */
    {   13,    0,    0,    0,    1,    0,    0,    1 },  /* 16: M PUNCH C, UP P GUARD P M */
    {   19,   19,    0,    0,    1,    0,    0,    1 },  /* 17: S KICK A */
    {   19,   19,    0,    7,    1,    7,    0,    1 },  /* 18: S KICK A, UP P GUARD P L */
    {   21,   21,    0,    0,    1,    0,    0,    1 },  /* 19: M KICK A */
    {   22,   22,    0,    8,    1,    8,    0,    1 },  /* 20: not used by a script */
    {   22,   22,    0,    9,    1,    9,    0,    1 },  /* 21: M KICK A */
    {   22,   22,    0,    0,    1,    0,    0,    1 },  /* 22: M KICK A */
    {   23,   23,    0,    0,    1,    0,    0,    1 },  /* 23: L KICK A */
    {   24,   24,    0,    0,    1,    0,    0,    1 },  /* 24: L KICK A */
    {   88,   88,    0,   38,    1,   38,    0,    1 },  /* 25: L KICK A */
    {   25,   25,    0,   39,    1,   39,    0,    1 },  /* 26: L KICK A */
    {   26,   26,    0,   40,    1,   40,    0,    1 },  /* 27: L KICK A */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 28: L KICK A, UP P GUARD P L */
    {   31,   31,    0,   13,    2,   13,    0,    2 },  /* 29: KAGAMI P A, UP P GUARD P L */
    {   31,   31,    0,    0,    2,    0,    0,    2 },  /* 30: KAGAMI P A, UP P GUARD P L */
    {   33,   33,    0,    0,    1,    0,    0,    1 },  /* 31: KAGAMI P A, atca 157, UP P GUARD P L */
    {   34,   34,    0,   15,    2,   15,    0,    2 },  /* 32: KAGAMI K A, UP P GUARD P L */
    {   34,   34,    0,   41,    2,   41,    0,    2 },  /* 33: KAGAMI K A, UP P GUARD P L */
    {   29,   29,    0,    0,    1,    0,    0,    5 },  /* 34: not used by a script */
    {   30,   30,    0,   12,    1,   12,    0,    5 },  /* 35: not used by a script */
    {   30,   30,    0,    0,    1,    0,    0,    5 },  /* 36: not used by a script */
    {    2,   31,    0,   10,    2,   10,    0,    2 },  /* 37: KAGAMI P A */
    {   32,   32,    0,    0,    2,    0,    0,    2 },  /* 38: KAGAMI P A, atca 157 */
    {   32,   32,    0,   14,    2,   14,    0,    2 },  /* 39: KAGAMI P A, atca 157 */
    {   33,   33,    0,   11,    1,   11,    0,    1 },  /* 40: KAGAMI P A, atca 157 */
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
    {   92,   92,    0,    0,    3,    0,    0,    3 },  /* 56: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
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
    {    1,    0,    0,   29,    1,   29,    0,    1 },  /* 73: M PUNCH A, M PUNCH C, M KICK A +2 */
    {    1,    0,    0,   30,    1,   30,    0,    1 },  /* 74: L PUNCH A, L KICK A, TUKAMIKAKARI A */
    {   62,   62,    0,    0,    1,    0,    0,    1 },  /* 75: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +1 */
    {   63,   63,    0,    0,    1,    0,    0,    1 },  /* 76: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +2 */
    {   64,   64,    0,    0,    4,    0,    0,    1 },  /* 77: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   65,   65,    0,    0,    4,    0,    0,    1 },  /* 78: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,   66,    0,    0,    4,    0,    0,    1 },  /* 79: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   67,   67,    0,    0,    4,    0,    0,    1 },  /* 80: not used by a script */
    {   68,   68,    0,    0,    4,    0,    0,    1 },  /* 81: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 82: TATAKI S, NEKOROBI S, OKIAGARI +12 */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 83: AIR S, AIR M, AIR L +2 */
    {   69,   69,    0,    0,    1,    0,    0,    5 },  /* 84: not used by a script */
    {   70,   70,    0,    0,    1,    0,    0,    1 },  /* 85: PIYO */
    {   71,   71,    0,    0,    1,    0,    0,    1 },  /* 86: PIYO */
    {   72,   72,    0,    0,    1,    0,    0,    8 },  /* 87: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    {   73,   73,    0,    0,    3,    0,    0,    3 },  /* 88: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   74,   74,    0,    0,    3,    0,    0,    3 },  /* 89: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   75,   75,    0,    0,    3,    0,    0,    3 },  /* 90: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   75,   75,    0,   31,    3,   31,    0,    3 },  /* 91: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   76,   76,    0,   32,    3,   32,    0,    3 },  /* 92: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   76,   76,    0,    0,    3,    0,    0,    3 },  /* 93: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   77,   77,    0,    0,    3,    0,    0,    3 },  /* 94: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   78,   78,    0,   33,    0,   33,    0,    0 },  /* 95: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   79,   79,    0,    0,    1,    0,    0,    1 },  /* 96: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   80,   80,    0,   34,    1,   34,    0,    1 },  /* 97: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   81,   81,    0,    0,    1,    0,    0,    1 },  /* 98: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   82,   82,    0,    0,    3,    0,    0,    3 },  /* 99: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   83,   83,    0,   35,    8,   35,    0,   12 },  /* 100: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) */
    {   83,   83,    0,    0,    8,    0,    0,   12 },  /* 101: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   84,   84,    0,    0,    3,    0,    0,    3 },  /* 102: not used by a script */
    {   85,   85,    0,    0,    3,    0,    0,    3 },  /* 103: not used by a script */
    {    1,    0,    0,    0,    0,    0,    0,    1 },  /* 104: follow-up of APPEAR 2 */
    {    2,    2,    0,    0,    0,    0,    0,    2 },  /* 105: follow-up of APPEAR 2 */
    {   14,   14,    0,    0,    1,    0,    0,    1 },  /* 106: M PUNCH A, follow-up of S PUNCH A */
    {   14,   14,    0,   37,    1,   37,    0,    1 },  /* 107: M PUNCH A, follow-up of S PUNCH A */
    {   14,   14,    0,   37,    1,   37,    0,    1 },  /* 108: M PUNCH A, follow-up of S PUNCH A */
    {   15,   15,    0,    0,    1,    0,    0,    1 },  /* 109: L PUNCH A */
    {   16,   15,    0,    0,    1,    0,    0,    1 },  /* 110: L PUNCH A */
    {   17,   17,    0,    5,    1,    5,    0,    1 },  /* 111: L PUNCH A */
    {   17,   16,    0,    6,    1,    6,    0,    1 },  /* 112: L PUNCH A */
    {   17,   16,    0,    0,    1,    0,    0,    1 },  /* 113: L PUNCH A */
    {   41,   41,    0,    0,    3,    0,    0,    3 },  /* 114: V JUMP K L A */
    {   42,   42,    0,    0,    3,    0,    0,    3 },  /* 115: V JUMP K L A */
    {   40,   40,    0,   21,    3,    0,    0,    3 },  /* 116: V JUMP K M A */
    {   43,   43,    0,   21,    3,   23,    0,    3 },  /* 117: V JUMP K L A */
    {   43,   43,    0,    0,    3,    0,    0,    3 },  /* 118: V JUMP K L A */
    {   44,   44,    0,    0,    3,    0,    0,    3 },  /* 119: V JUMP K L A */
    {    1,    0,    0,    0,    1,    0,    0,    0 },  /* 120: not used by a script */
    {   78,   78,    0,   33,    0,   33,    0,    1 },  /* 121: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   95,   95,    0,    0,    3,    0,    0,    3 },  /* 122: PARING AIR F, PARING AIR B, P BREAK AIR F +1 */
    {    2,    0,    0,    0,    2,    0,    0,   10 },  /* 123: KAGAMI P A */
    {   97,    0,    0,    0,    1,    0,    0,    1 },  /* 124: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {   97,    0,    0,    0,    1,   49,    0,    1 },  /* 125: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   97,   97,    0,    0,    1,   49,    0,    1 },  /* 126: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   98,   98,    0,    0,    1,    0,    0,    1 },  /* 127: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    5,    5,    0,    0,    1,   47,    0,    1 },  /* 128: M KICK C */
    {    5,    5,    0,    0,    1,    0,    0,    1 },  /* 129: M KICK C */
    {    5,  100,    0,    0,    1,    0,    0,    1 },  /* 130: M KICK C */
    {    9,    9,    0,    0,    1,    0,    0,    1 },  /* 131: M KICK C */
    {  100,    0,    0,    0,    7,    0,    0,   11 },  /* 132: AIR S, AIR M, AIR L +39 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 133: ATTACK 10 L: SA III 23623+P light (plain script), ATTACK 10 SP: SA III 23623+P medium (plain script), ATTACK 11 S: SA III 23623+P heavy (plain script) +3 */
    {    2,    0,    0,    0,    2,   48,    0,    2 },  /* 134: ATTACK 8 SP: not started by a command */
    {  101,    0,    0,    0,    0,    0,    0,    2 },  /* 135: dmca 97 */
    {    0,    0,    0,    0,    1,    0,    0,    1 },  /* 136: ATTACK 10 M: EX [4]6+KK (routine Att_CHOUCHUURENGEKI) */
    {   97,    0,    0,    0,    1,   46,    0,    1 },  /* 137: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  102,    0,    0,    0,    8,   50,    0,   12 },  /* 138: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    {   24,  101,    0,    0,    1,    0,    0,    1 },  /* 139: L KICK A */
    {  103,    0,    0,    0,    3,    0,    0,    3 },  /* 140: V JUMP K L A */
    {   92,   92,    0,    0,    3,    0,    0,   13 },  /* 141: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +5 */
    {    8,    8,    0,    0,    3,    0,    0,   13 },  /* 142: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
};

const BODY_BOX urien_body_box[104] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -21,  27, 102,  18 },  {  -39,  71,  92,  14 },  {  -31,  56,  50,  42 },  {  -31,  65,   0,  50 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +89 */
    { { {  -12,  32,  54,  18 },  {  -32,  70,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +35 */
    { { {  -50,  22,  92,  18 },  {  -38,  60,  94,  12 },  {  -32,  60,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 3: DASH HUMIKOMI */
    { { {  -34,  22,  86,  18 },  {  -28,  52,  81,  16 },  {  -28,  52,  41,  39 },  {  -32,  72,   0,  40 } } },  /* 4: DASH HUMIKOMI */
    { { {  -10,  34,  96,  18 },  {  -58,  92,  70,  26 },  {  -41,  64,  48,  26 },  {  -36,  64,   0,  48 } } },  /* 5: M KICK C */
    { { {   -2,  22, 114,  18 },  {  -20,  68, 104,  12 },  {  -20,  61,  51,  52 },  {  -32,  72,   0,  50 } } },  /* 6: DASH TOBINOKI */
    { { {  -22,  22,  90,  18 },  {  -26,  64,  85,  12 },  {  -26,  66,  41,  42 },  {  -32,  72,   0,  40 } } },  /* 7: DASH HUMIKOMI, DASH TOBINOKI */
    { { {  -11,  24, 125,  18 },  {  -29,  68, 106,  30 },  {  -29,  54,  64,  42 },  {  -24,  54,  28,  36 } } },  /* 8: S JUMP FRONT, GUARD AIR, V JUMP P M A +24 */
    { { {  -34,  40, 105,  18 },  {  -45,  75,  92,  16 },  {  -50,  75,  50,  42 },  {  -36,  64,   0,  50 } } },  /* 9: M KICK C */
    { { {  -48,  22,  92,  18 },  {  -28,  56,  88,  28 },  {  -32,  60,  50,  38 },  {    0,   0,   0,   0 } } },  /* 10: not used by a script */
    { { {  -18,  24, 102,  18 },  {  -39,  71,  92,  14 },  {  -31,  56,  50,  42 },  {  -31,  65,   0,  50 } } },  /* 11: S PUNCH A, UP P GUARD P S */
    { { {  -22,  24,  94,  18 },  {  -36,  71,  82,  19 },  {  -28,  56,  46,  36 },  {  -34,  82,   0,  46 } } },  /* 12: M PUNCH C */
    { { {  -22,  42,  92,  20 },  {  -36,  76,  79,  18 },  {  -29,  58,  46,  42 },  {  -36,  80,   0,  46 } } },  /* 13: M PUNCH C, L PUNCH A, UP P GUARD P M */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 14: M PUNCH A, follow-up of S PUNCH A */
    { { {   -3,  24, 100,  18 },  {  -32,  76,  90,  17 },  {  -24,  58,  52,  38 },  {  -34,  70,   0,  52 } } },  /* 15: L PUNCH A */
    { { {  -48,  48, 100,  22 },  {  -44,  71,  88,  15 },  {  -38,  57,  48,  41 },  {  -43,  84,   0,  48 } } },  /* 16: L PUNCH A */
    { { {  -34,  60,  80,  28 },  {  -50,  72,  54,  27 },  {  -34,  62,  40,  24 },  {  -46,  96,   0,  40 } } },  /* 17: L PUNCH A */
    { { {  -10,  22, 102,  18 },  {  -32,  64,  94,  12 },  {  -32,  64,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 18: not used by a script */
    { { {  -35,  24,  99,  18 },  {  -50,  74,  88,  16 },  {  -44,  56,  48,  40 },  {  -60,  68,   0,  48 } } },  /* 19: S KICK A, UP P GUARD P L */
    { { {  -15,  19, 103,  16 },  {  -27,  51,  94,  12 },  {  -20,  30,  41,  52 },  {  -22,  41,   0,  40 } } },  /* 20: not used by a script */
    { { {  -16,  40,  94,  21 },  {  -42,  73,  86,  19 },  {  -36,  63,  52,  38 },  {  -27,  40,   0,  52 } } },  /* 21: M KICK A */
    { { {  -32,  58,  94,  21 },  {  -58,  93,  70,  24 },  {  -36,  43,  50,  26 },  {  -27,  40,   0,  50 } } },  /* 22: M KICK A */
    { { {  -12,  24, 106,  18 },  {  -24,  68,  92,  15 },  {  -22,  50,  52,  40 },  {  -34,  62,   0,  52 } } },  /* 23: L KICK A */
    { { {   -3,  24, 108,  18 },  {  -26,  72,  94,  16 },  {  -32,  70,  58,  36 },  {  -14,  38,   0,  58 } } },  /* 24: L KICK A */
    { { {    3,  24, 103,  18 },  {  -20,  69,  90,  17 },  {  -44,  76,  56,  34 },  {  -14,  38,   0,  56 } } },  /* 25: L KICK A */
    { { {   12,  24,  96,  18 },  {  -16,  70,  84,  16 },  {  -30,  78,  60,  24 },  {  -24,  48,   0,  60 } } },  /* 26: L KICK A */
    { { {    1,  41,  94,  18 },  {  -26,  85,  66,  30 },  {  -50,  73,  36,  32 },  {  -26,  50,   0,  40 } } },  /* 27: L KICK A, UP P GUARD P L */
    { { {   20,  22,  96,  18 },  {  -12,  72,  78,  24 },  {  -36,  80,  41,  36 },  {  -16,  48,   0,  40 } } },  /* 28: not used by a script */
    { { {   -8,  22, 106,  18 },  {  -24,  60,  94,  12 },  {  -24,  60,  41,  52 },  {  -12,  48,   0,  40 } } },  /* 29: not used by a script */
    { { {  -30,  22, 108,  18 },  {  -16,  56, 100,  28 },  {  -24,  64,  48,  52 },  {    0,   0,   0,   0 } } },  /* 30: not used by a script */
    { { {  -24,  32,  54,  18 },  {  -44,  70,  44,  14 },  {  -40,  84,  22,  24 },  {  -40,  80,   0,  22 } } },  /* 31: KAGAMI P A, UP P GUARD P L */
    { { {  -22,  26,  74,  18 },  {  -40,  66,  58,  20 },  {  -48,  78,  34,  24 },  {  -48,  92,   0,  34 } } },  /* 32: KAGAMI P A, atca 157 */
    { { {  -15,  24, 103,  18 },  {  -28,  60,  88,  18 },  {  -30,  58,  34,  54 },  {  -38,  82,   0,  34 } } },  /* 33: KAGAMI P A, atca 157, UP P GUARD P L */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 34: KAGAMI K A, UP P GUARD P L */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 35: KAGAMI K A */
    { { {  -18,  19, 107,  16 },  {  -24,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {   -3,  40, 110,  16 },  {  -24,  68,  88,  27 },  {  -36,  82,  62,  34 },  {  -14,  48,  48,  22 } } },  /* 40: V JUMP K M A, FUSHIN P S, ATTACK 4 M: not started by a command */
    { { {   -7,  24, 116,  18 },  {  -35,  69, 102,  21 },  {  -31,  62,  76,  26 },  {  -28,  57,  42,  34 } } },  /* 41: V JUMP K L A */
    { { {  -17,  24, 113,  18 },  {  -29,  62, 102,  20 },  {  -47,  76,  81,  26 },  {  -41,  77,  54,  27 } } },  /* 42: V JUMP K L A */
    { { {  -39,  24, 111,  18 },  {  -26,  58, 102,  23 },  {  -51,  86,  78,  27 },  {  -58,  96,  60,  28 } } },  /* 43: V JUMP K L A */
    { { {  -38,  28, 115,  18 },  {  -34,  63, 104,  18 },  {  -48,  77,  75,  29 },  {  -61,  85,  52,  40 } } },  /* 44: V JUMP K L A */
    { { {   -8,  19, 115,  16 },  {  -17,  46,  98,  21 },  {  -13,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -32,  16, 106,  16 },  {  -23,  46,  96,  21 },  {  -16,  30,  57,  46 },  {    0,   0,   0,   0 } } },  /* 46: not used by a script */
    { { {  -25,  24, 118,  18 },  {  -39,  71, 106,  20 },  {  -35,  62,  78,  28 },  {  -38,  63,  48,  30 } } },  /* 47: V JUMP P S A, V JUMP P M A, V JUMP P L A +6 */
    { { {  -40,  24, 108,  18 },  {  -48,  72,  98,  14 },  {  -52,  86,  72,  24 },  {  -32,  60,  48,  26 } } },  /* 48: V JUMP P S A */
    { { {   -4,  40, 109,  16 },  {  -28,  67,  88,  25 },  {  -40,  86,  62,  26 },  {  -24,  57,  50,  18 } } },  /* 49: V JUMP K S A, V JUMP K M A, FUSHIN P S */
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
    { { {   -8,  24,  94,  18 },  {  -35,  71,  90,  15 },  {  -32,  60,  50,  40 },  {  -67, 108,   0,  50 } } },  /* 62: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +1 */
    { { {  -28,  62,  82,  18 },  {  -55,  93,  62,  18 },  {  -34,  71,  42,  28 },  {  -71, 116,   0,  44 } } },  /* 63: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +2 */
    { { {   -9,  57,  82,  18 },  {  -19,  68,  69,  14 },  {  -23,  67,  40,  28 },  {  -71, 116,   0,  44 } } },  /* 64: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -44,  75,  82,  18 },  {  -39,  78,  68,  17 },  {  -30,  65,  40,  28 },  {  -69, 114,   0,  44 } } },  /* 65: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -26,  24,  98,  18 },  {  -44,  72,  88,  16 },  {  -32,  52,  52,  38 },  {  -54,  94,   0,  50 } } },  /* 66: ATTACK 3 M: 236+P light (plain script), ATTACK 11 L: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -28,  62,  85,  18 },  {  -50,  87,  75,  20 },  {  -34,  71,  44,  34 },  {  -71, 116,   0,  44 } } },  /* 67: not used by a script */
    { { {  -28,  62,  82,  20 },  {  -42,  33,  92,  17 },  {  -34,  71,  44,  38 },  {  -71, 116,   0,  44 } } },  /* 68: not used by a script */
    { { {  -36,  22, 104,  18 },  {  -28,  56,  82,  28 },  {  -48,  64,  48,  34 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { {  -11,  30, 102,  18 },  {  -30,  68,  94,  12 },  {  -30,  65,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 70: PIYO */
    { { {  -29,  33, 102,  18 },  {  -37,  63,  94,  12 },  {  -37,  65,  41,  52 },  {  -36,  74,   0,  40 } } },  /* 71: PIYO */
    { { {  -26,  22,  84,  18 },  {  -32,  58,  82,  12 },  {  -24,  50,  40,  40 },  {  -36,  72,   0,  40 } } },  /* 72: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    { { {   14,  22, 126,  18 },  {  -18,  58, 120,  15 },  {  -22,  50,  80,  40 },  {  -13,  53,  50,  29 } } },  /* 73: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -36,  64,  92,  32 },  {  -36,  64,  58,  34 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -14,  22, 110,  18 },  {  -32,  56, 104,  16 },  {  -20,  42,  72,  30 },  {  -31,  63,  54,  32 } } },  /* 75: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -50,  64,  94,  20 },  {  -36,  51,  72,  21 },  {  -46,  60,  56,  24 } } },  /* 76: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -38,  22, 106,  18 },  {  -34,  58,  94,  20 },  {  -18,  36,  72,  24 },  {  -38,  50,  50,  28 } } },  /* 77: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -105,  22,  92,  18 },  { -109,  88,  82,  22 },  {  -99,  64,  40,  40 },  {  -79,  88,   0,  40 } } },  /* 78: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  22 },  {  -31,  52,  46,  36 },  {  -36,  78,   0,  46 } } },  /* 79: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  22 },  {  -31,  52,  46,  36 },  {  -36,  78,   0,  46 } } },  /* 80: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -40,  23,  70,  26 },  {  -16,  56,  80,  22 },  {  -31,  65,  36,  44 },  {  -34,  82,   0,  36 } } },  /* 81: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    8,  22, 104,  18 },  {  -24,  70,  92,  14 },  {  -16,  48,  60,  32 },  {   -4,  50,  32,  26 } } },  /* 82: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -44,  58,  92,  26 },  {  -62,  30,  70,  34 },  {  -42,  61,  68,  24 },  {  -46,  65,  32,  38 } } },  /* 83: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -28,  22, 108,  18 },  {  -34,  60,  98,  20 },  {  -14,  38,  72,  24 },  {  -28,  48,  42,  28 } } },  /* 84: not used by a script */
    { { {   -8,  22, 118,  18 },  {  -24,  56,  98,  20 },  {  -22,  42,  70,  26 },  {  -14,  38,  28,  40 } } },  /* 85: not used by a script */
    { { {  -54,  78, 103,  24 },  {  -62,  80,  86,  21 },  {  -40,  64,  50,  37 },  {  -32,  68,  41,  16 } } },  /* 86: V JUMP P M A, V JUMP P L A */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  51,  37 },  {   -4,  50,  48,  20 } } },  /* 87: V JUMP P M A */
    { { {   -2,  24, 109,  18 },  {  -26,  68,  94,  16 },  {  -22,  60,  58,  36 },  {  -14,  38,   0,  58 } } },  /* 88: L KICK A */
    { { {  -52,  60, 103,  18 },  {  -60,  84,  88,  18 },  {  -36,  71,  56,  32 },  {  -14,  60,  43,  20 } } },  /* 89: V JUMP P L A */
    { { {  -20,  24, 104,  18 },  {  -36,  68,  92,  14 },  {  -30,  52,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 90: FRONT WALK, BACK WALK */
    { { {   -8,  24, 118,  18 },  {  -24,  60, 108,  14 },  {  -22,  46,  70,  36 },  {  -16,  48,  42,  26 } } },  /* 91: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +6 */
    { { {  -24,  24, 110,  18 },  {  -32,  60, 106,  14 },  {  -16,  44,  70,  36 },  {  -30,  52,  44,  24 } } },  /* 92: JUMP FRONT, JUMP VERTICAL, JUMP BACK +12 */
    { { {  -46,  24,  94,  18 },  {  -28,  56, 100,  14 },  {  -10,  40,  72,  26 },  {  -36,  60,  50,  26 } } },  /* 93: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -44,  42, 108,  18 },  {  -60,  92,  98,  14 },  {  -70, 108,  72,  24 },  {  -44,  72,  48,  26 } } },  /* 94: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {  -20,  24, 116,  18 },  {  -44,  72, 108,  14 },  {  -40,  72,  80,  30 },  {  -46,  80,  62,  24 } } },  /* 95: PARING AIR F, PARING AIR B, P BREAK AIR F +1 */
    { { {  -22,  24,  96,  18 },  {  -34,  70,  82,  20 },  {  -28,  56,  46,  36 },  {  -38,  86,   0,  46 } } },  /* 96: M PUNCH C, UP P GUARD P M */
    { { {  -38,  24,  52,  45 },  {  -32,  64,  68,  35 },  {  -32,  55,  50,  35 },  {  -32,  78,   0,  50 } } },  /* 97: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -40,  24,  69,  21 },  {  -32,  60,  67,  28 },  {  -44,  67,  50,  35 },  {  -48,  91,   0,  50 } } },  /* 98: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 99: not used by a script */
    { { {  -26,  53,  95,  17 },  {  -33,  67,  75,  30 },  {  -33,  67,  43,  32 },  {  -26,  53,  36,  16 } } },  /* 100: AIR S, AIR M, AIR L +39 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 101: dmca 97 */
    { { {  -52,  62,  94,  20 },  {    0,   0,   0,   0 },  {  -48,  58,  68,  26 },  {  -48,  59,  38,  30 } } },  /* 102: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    { { {  -22,  24, 118,  18 },  {  -27,  62, 106,  16 },  {  -34,  58,  62,  44 },  {  -27,  50,  28,  36 } } },  /* 103: V JUMP K L A */
};

const HAND_BOX urien_hand_box[102] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: no box */
    { { { -124,  82,  53,  33 },  {    0,   0,   0,   0 } } },  /* 5: M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {  -88,  48,  70,  28 },  {    0,   0,   0,   0 } } },  /* 11: S PUNCH A, UP P GUARD P S */
    { { {  -60,  40,  68,  48 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH C */
    { { {  -40,  26,  98,  40 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {  -82,  60,  76,  28 },  {    0,   0,   0,   0 } } },  /* 14: M PUNCH A, follow-up of S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: no box */
    { { {  -84,  54,  42,  32 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH A */
    { { {  -72,  38,  40,  62 },  {    0,   0,   0,   0 } } },  /* 17: L PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {  -80,  48,   0,  34 },  {    0,   0,   0,   0 } } },  /* 19: S KICK A, UP P GUARD P L */
    { { {  -78,  58,  74,   9 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { { -118,  60,  68,  26 },  {    0,   0,   0,   0 } } },  /* 22: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: no box */
    { { {  -98,  78,  64,  45 },  {    0,   0,   0,   0 } } },  /* 25: L KICK A */
    { { {  -88,  58,  20,  54 },  {    0,   0,   0,   0 } } },  /* 26: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -84,  38,  42,  22 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI P A, UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {  -56,  41,  76,  48 },  {    0,   0,   0,   0 } } },  /* 33: KAGAMI P A, atca 157, UP P GUARD P L */
    { { { -114,  74,   0,  34 },  {    0,   0,   0,   0 } } },  /* 34: KAGAMI K A, UP P GUARD P L */
    { { { -120,  81,   0,  34 },  {    0,   0,   0,   0 } } },  /* 35: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -68,  57,  83,   7 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -38,  18,  64,  26 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { { -110,  74,  70,  27 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K M A, FUSHIN P S, ATTACK 4 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { { -108,  87,  49,  35 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP K L A */
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
    { { {  -60,  38,  66,  26 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {  -90,  53,  70,  36 },  {    0,   0,   0,   0 } } },  /* 87: V JUMP P M A */
    { { {  -58,  40,  84,  66 },  {    0,   0,   0,   0 } } },  /* 88: L KICK A */
    { { {  -86,  50,  60,  32 },  {    0,   0,   0,   0 } } },  /* 89: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {  -66,  32,  54,  22 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {  -68,  48,  78,  54 },  {    0,   0,   0,   0 } } },  /* 96: M PUNCH C, UP P GUARD P M */
    { { {  -44,  19,  31,  70 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { {  -99,  69,  25,  44 },  {    0,   0,   0,   0 } } },  /* 100: M KICK C */
    { { {  -30,  38,  93,  57 },  {    0,   0,   0,   0 } } },  /* 101: L KICK A */
};

const HOSEI_BOX urien_hos_box[14] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   94 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +98 */
    { {  -24,   48,    0,   54 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +52 */
    { {  -24,   48,   54,   58 } },  /* 3: S JUMP FRONT, GUARD AIR, V JUMP P M A +45 */
    { {   -4,   48,    0,  100 } },  /* 4: not used by a script */
    { {  -11,   48,    0,  100 } },  /* 5: not used by a script */
    { {    7,   48,    0,   54 } },  /* 6: not used by a script */
    { {  -24,   48,    0,  100 } },  /* 7: not used by a script */
    { {  -24,   48,    0,   84 } },  /* 8: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    { {  -32,   64,    0,   94 } },  /* 9: DASH HUMIKOMI */
    { {  -32,   56,    0,   56 } },  /* 10: KAGAMI P A */
    { {  -23,   48,   34,   58 } },  /* 11: AIR S, AIR M, AIR L +39 */
    { {  -44,   54,   48,   63 } },  /* 12: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -24,   48,   50,   62 } },  /* 13: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
};
