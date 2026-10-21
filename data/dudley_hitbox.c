/*
 * DUDLEY_HITBOX.C  Dudley's hit boxes
 *
 * Each of Dudley's animation frames names an entry of dudley_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX dudley_hit_ix_table[149] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +20 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, FRONT WALK +125 */
    {    2,    2,    0,    0,    2,    0,    0,    1 },  /* 2: ATTACK 11 M: 6(123)4+P light (plain script), ATTACK 11 L: 6(123)4+P medium (plain script), ATTACK 11 SP: 6(123)4+P heavy (plain script) +2 */
    {    7,    7,    0,    0,    0,   67,    0,    0 },  /* 3: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    {    3,    3,    0,    0,    3,    0,    0,   20 },  /* 4: DASH HUMIKOMI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    {    5,    5,    0,    0,    1,    0,    0,    1 },  /* 5: L KICK C */
    {   12,   12,    0,   35,    1,   35,    0,    1 },  /* 6: L KICK C */
    {    4,    4,    0,   36,    1,   36,    0,    1 },  /* 7: L KICK C */
    {   77,   77,    0,   57,    8,   57,    0,    5 },  /* 8: V JUMP K L A */
    {    8,    8,    0,    0,    6,    0,    0,    3 },  /* 9: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +43 */
    {    0,    0,    0,    0,    0,    0,    0,    5 },  /* 10: AIR S, AIR M, AIR L +10 */
    {   10,   10,    0,    0,    8,    0,    0,    5 },  /* 11: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +29 */
    {    7,    7,    0,    0,    0,   33,    0,    0 },  /* 12: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script), ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script) +1 */
    {    6,    6,    0,    0,    1,    0,    0,   11 },  /* 13: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    {    9,    9,    0,    0,    1,    0,    0,   11 },  /* 14: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    {   14,   14,    0,    1,    1,    1,    0,    1 },  /* 15: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1 */
    {   15,   15,    0,    2,    1,    2,    0,    1 },  /* 16: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +5 */
    {   16,   16,    0,    3,    1,    3,    0,    1 },  /* 17: S KICK A */
    {   16,   16,    0,    0,    1,    0,    0,    1 },  /* 18: S KICK A */
    {   17,   17,    0,    0,    1,    0,    0,    1 },  /* 19: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    {   18,   18,    0,    4,    1,    4,    0,    1 },  /* 20: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    {   68,   68,    0,    5,    1,    5,    0,    1 },  /* 21: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    {   68,   68,    0,    0,    1,    0,    0,    1 },  /* 22: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    {   19,   19,    0,    0,   10,    0,    0,    1 },  /* 23: S PUNCH C */
    {   20,   20,    0,    6,   10,    6,    0,    1 },  /* 24: S PUNCH C */
    {   15,   15,    0,    0,    1,    0,    0,    1 },  /* 25: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +3 */
    {   22,   22,    0,    0,    1,    0,    0,    1 },  /* 26: L PUNCH A, L PUNCH C, M KICK C +10 */
    {   23,   23,    0,    7,    1,    7,    0,    4 },  /* 27: M KICK C */
    {   23,   23,    0,    0,    1,    0,    0,    4 },  /* 28: M KICK C */
    {   24,   24,    0,    8,    1,    8,    0,    1 },  /* 29: L KICK A, atca 162, follow-up of M KICK A */
    {   25,   25,    0,    9,    1,    9,    0,    1 },  /* 30: L KICK A, atca 162, follow-up of M KICK A +1 */
    {   26,   26,    0,   10,    1,   10,    0,    1 },  /* 31: L KICK A, atca 162, follow-up of M KICK A +5 */
    {   26,   26,    0,    0,    1,    0,    0,    1 },  /* 32: L KICK A, atca 162, follow-up of M KICK A +5 */
    {   27,   27,    0,   11,    1,   11,    0,    1 },  /* 33: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A / M KICK C +3 */
    {   27,   27,    0,    0,    1,    0,    0,    1 },  /* 34: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A / M KICK C +5 */
    {   28,   28,    0,   12,    7,   12,    0,    3 },  /* 35: KAGAMI P A */
    {   29,   29,    0,    0,    6,    0,    0,    3 },  /* 36: KAGAMI P A, follow-up of JUDGMENT WAIT */
    {   30,   30,    0,   13,    6,   13,    0,    3 },  /* 37: KAGAMI P A, follow-up of JUDGMENT WAIT */
    {   30,   30,    0,    0,    6,    0,    0,    3 },  /* 38: KAGAMI P A, follow-up of JUDGMENT WAIT, follow-up of follow-up of JUDGMENT WAIT */
    {   31,   31,    0,    0,    6,    0,    0,    1 },  /* 39: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    {   32,   32,    0,   14,    6,   14,    0,    1 },  /* 40: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    {   33,   33,    0,   15,    6,   15,    0,    1 },  /* 41: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    {   34,   34,    0,    0,    6,    0,    0,    1 },  /* 42: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    {   35,   35,    0,    0,    6,    0,    0,    1 },  /* 43: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    {   36,   36,    0,   16,    7,   16,    0,    3 },  /* 44: KAGAMI K A */
    {   36,   36,    0,    0,    7,    0,    0,    3 },  /* 45: KAGAMI K A */
    {   37,   37,    0,    0,    6,    0,    0,    3 },  /* 46: KAGAMI K A, UP P GUARD K S */
    {   38,   38,    0,   17,    6,   17,    0,    3 },  /* 47: KAGAMI K A, UP P GUARD K S */
    {   38,   38,    0,    0,    6,    0,    0,    3 },  /* 48: KAGAMI K A, UP P GUARD K S */
    {   44,   44,    0,    0,    6,    0,    0,    3 },  /* 49: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {   40,   40,    0,    0,    6,    0,    0,    3 },  /* 50: KAGAMI K A */
    {   41,   41,    0,    0,   13,    0,    0,    3 },  /* 51: KAGAMI K A */
    {    4,    4,    0,    0,    1,    0,    0,    1 },  /* 52: L KICK C */
    {   43,   43,    0,   18,   13,   18,    0,    3 },  /* 53: KAGAMI K A */
    {   43,   43,    0,    0,   13,    0,    0,    3 },  /* 54: KAGAMI K A */
    {   83,   83,    0,   64,    8,   64,    0,    5 },  /* 55: not started by a command */
    {   45,   45,    0,   19,    8,   19,    0,    5 },  /* 56: V JUMP P S A, F JUMP P S A, atca 168 */
    {   45,   45,    0,    0,    8,    0,    0,    5 },  /* 57: V JUMP P S A, F JUMP P S A, atca 168 */
    {   46,   46,    0,   20,    8,   20,    0,    5 },  /* 58: V JUMP P M A, F JUMP P M A */
    {   46,   46,    0,    0,    8,    0,    0,    5 },  /* 59: V JUMP P M A, F JUMP P M A */
    {   47,   47,    0,    0,    8,    0,    0,    5 },  /* 60: V JUMP P L A, F JUMP P L A */
    {   48,   48,    0,   21,    8,   21,    0,    5 },  /* 61: V JUMP P L A, F JUMP P L A */
    {   48,   48,    0,    0,    8,    0,    0,    5 },  /* 62: V JUMP P L A, F JUMP P L A */
    {   75,   75,    0,   22,    8,   22,    0,    5 },  /* 63: V JUMP K S A, F JUMP K S A */
    {   49,   49,    0,    0,    8,    0,    0,    5 },  /* 64: V JUMP K L A, F JUMP K L A */
    {   50,   50,    0,   23,    8,   23,    0,    5 },  /* 65: F JUMP K L A */
    {   50,   50,    0,    0,    8,    0,    0,    5 },  /* 66: V JUMP K L A, F JUMP K L A */
    {   51,   51,    0,    0,    6,    0,    0,    3 },  /* 67: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {    8,    8,    0,    0,   22,   28,    0,    3 },  /* 68: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 69: TATAKI S, OKIAGARI, OKIAGARI F +19 */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 70: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   54,    0,    0,    0,    0,    0,    0,   26 },  /* 71: dmca 97 */
    {   55,   55,    0,    0,   16,    0,    0,   15 },  /* 72: FUSHIN P S */
    {   55,   55,    0,   24,   16,   24,    0,   15 },  /* 73: FUSHIN P S */
    {   56,   56,    0,    0,   17,    0,    0,   16 },  /* 74: TOUKETSU A, OKIAGARI P S */
    {    0,    0,    0,    0,    0,   70,    0,    3 },  /* 75: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   57,    0,    0,    0,   22,   71,    0,    3 },  /* 76: OKIAGARI P S, ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {    1,    1,    0,   26,    1,   26,    0,    1 },  /* 77: M PUNCH A, TUKAMIKAKARI A, TUKAMIKAKARI C */
    {   21,   21,    0,   28,   22,   28,    0,    3 },  /* 78: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    {   13,   13,    0,   27,    8,   27,    0,    5 },  /* 79: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   39,   39,    0,   29,   22,   29,    0,    3 },  /* 80: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {   88,    0,    0,   30,   22,   30,    0,    3 },  /* 81: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {   51,   51,    0,   31,    6,   31,    0,    3 },  /* 82: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {   52,   52,    0,   32,   22,   32,    0,    3 },  /* 83: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {   13,   13,    0,    0,    8,    0,    0,    5 },  /* 84: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +2 */
    {   13,   13,    0,   34,    8,   34,    0,    5 },  /* 85: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   59,   59,    0,    0,    1,    0,    0,   25 },  /* 86: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    {   60,   60,    0,    0,    1,    0,    0,   27 },  /* 87: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,   61,    0,   37,    1,   37,    0,    1 },  /* 88: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,   61,    0,   38,    1,   38,    0,    1 },  /* 89: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,   61,    0,   39,    1,   39,    0,    1 },  /* 90: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    {   61,   61,    0,   40,    1,   40,    0,    1 },  /* 91: ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    {   61,   61,    0,   41,    1,   41,    0,    1 },  /* 92: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,   61,    0,   42,    1,   42,    0,    1 },  /* 93: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   62,   62,    0,    0,    1,    0,    0,    1 },  /* 94: not used by a script */
    {   63,   63,    0,    0,    1,    0,    0,    1 },  /* 95: not used by a script */
    {   64,   64,    0,    0,    1,    0,    0,    1 },  /* 96: not used by a script */
    {    0,    0,    0,   43,    1,   43,    0,    3 },  /* 97: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,   66,    0,   44,    1,   44,    0,    3 },  /* 98: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,   66,    0,   45,    1,   45,    0,    3 },  /* 99: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,   66,    0,   46,    1,   46,    0,    3 },  /* 100: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   85,   85,    0,   47,    1,   47,    0,    3 },  /* 101: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   85,   85,    0,    0,    1,    0,    0,    3 },  /* 102: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   67,   67,    0,    0,   20,    0,    0,   19 },  /* 103: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    {   89,    0,    0,    0,   19,    0,    0,   28 },  /* 104: ATTACK 3 S: SA II 23623+P (plain script) */
    {   89,    0,    0,   48,   19,   48,    0,   28 },  /* 105: ATTACK 3 S: SA II 23623+P (plain script) */
    {   69,   69,    0,   49,    1,   49,    0,   13 },  /* 106: ATTACK 3 S: SA II 23623+P (plain script) */
    {   70,   70,    0,   50,    1,   50,    0,   13 },  /* 107: ATTACK 3 S: SA II 23623+P (plain script) */
    {   70,   70,    0,   51,    1,   51,    0,   13 },  /* 108: not used by a script */
    {   70,   70,    0,    0,    1,    0,    0,   13 },  /* 109: ATTACK 3 S: SA II 23623+P (plain script) */
    {   71,   71,    0,    0,   19,    0,    0,   13 },  /* 110: ATTACK 3 S: SA II 23623+P (plain script) */
    {   72,   72,    0,    0,   19,    0,    0,   13 },  /* 111: ATTACK 3 S: SA II 23623+P (plain script) */
    {   72,   72,    0,   52,   19,   52,    0,   13 },  /* 112: ATTACK 3 S: SA II 23623+P (plain script) */
    {   73,   73,    0,   53,    1,   53,    0,   13 },  /* 113: ATTACK 3 S: SA II 23623+P (plain script) */
    {   73,   73,    0,   54,    1,   54,    0,   13 },  /* 114: not used by a script */
    {   73,   73,    0,    0,    1,    0,    0,   13 },  /* 115: ATTACK 3 S: SA II 23623+P (plain script) */
    {   52,   52,    0,   55,   22,   55,    0,   12 },  /* 116: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   13,   13,    0,   56,    8,   56,    0,    5 },  /* 117: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   52,   52,    0,    0,   22,   69,    0,    3 },  /* 118: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   13,   13,    0,   58,    8,   58,    0,    5 },  /* 119: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   74,   74,    0,    0,   21,    0,    0,   24 },  /* 120: AIR S, AIR M, AIR L +41 */
    {   76,   76,    0,   59,    8,   59,    0,    5 },  /* 121: V JUMP K M A, F JUMP K M A */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 122: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI), ATTACK 3 S: SA II 23623+P (plain script) */
    {    0,    0,    0,    0,    0,    0,    0,    5 },  /* 123: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 124: not used by a script */
    {    0,    0,    0,   56,    8,   56,    0,    5 },  /* 125: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0,    0,    0,   69,    0,    3 },  /* 126: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    1,    1,    0,   60,    1,   60,    0,    1 },  /* 127: L PUNCH A, L PUNCH C */
    {   78,   78,    0,   61,    1,   61,    0,    1 },  /* 128: ATTACK 13 M: not started by a command */
    {   78,   78,    0,    0,    1,    0,    0,    1 },  /* 129: ATTACK 13 M: not started by a command */
    {   79,   79,    0,   62,    1,   62,    0,    1 },  /* 130: ATTACK 13 L: not started by a command */
    {   80,   80,    0,   63,    1,   63,    0,    1 },  /* 131: ATTACK 13 L: not started by a command */
    {   80,   80,    0,    0,    1,    0,    0,    1 },  /* 132: ATTACK 13 L: not started by a command */
    {   81,   81,    0,    0,    1,    0,    0,   10 },  /* 133: PIYO */
    {   82,   82,    0,    0,    1,    0,    0,   10 },  /* 134: PIYO */
    {   13,   13,    0,   65,    8,   65,    0,    5 },  /* 135: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0,    0,    0,    0,    0,   26 },  /* 136: NEKOROBI S, dmca 96 */
    {   84,   84,    0,    0,    9,    0,    0,   14 },  /* 137: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   28,   28,    0,    0,    7,    0,    0,    3 },  /* 138: KAGAMI P A */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 139: follow-up of SP WIN 1 */
    {    8,    8,    0,    0,    0,    0,    0,    3 },  /* 140: follow-up of SP WIN 1 */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 141: LOSE SONABA */
    {   86,   10,    0,    0,    8,    0,    0,    5 },  /* 142: not used by a script */
    {   86,   86,    0,    0,    8,   66,    0,    5 },  /* 143: not used by a script */
    {   86,   87,    0,    0,    8,   66,    0,    5 },  /* 144: ATTACK 8 S: 214+K light/medium/heavy (routine Att_SLIDE_and_JUMP), ATTACK 8 SP: EX 214+KK (routine Att_HOMING_JUMP) */
    {    7,    7,    0,    0,    0,   68,    0,    0 },  /* 145: ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    {   87,    0,    0,    0,    1,    0,    0,    1 },  /* 146: KAGAMI K A */
    {   14,   14,    0,    0,    1,    0,    0,    1 },  /* 147: S PUNCH A, follow-up of S PUNCH A */
    {   20,   20,    0,    0,   10,    0,    0,    1 },  /* 148: S PUNCH C */
};

const BODY_BOX dudley_body_box[90] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -21,  31,  88,  17 },  {  -29,  60,  85,  12 },  {  -29,  60,  40,  45 },  {  -33,  68,   0,  40 } } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +125 */
    { { {  -32,  61,  67,  39 },  {  -26,  55,  57,  10 },  {  -26,  55,  38,  19 },  {  -32,  70,   0,  38 } } },  /* 2: ATTACK 11 M: 6(123)4+P light (plain script), ATTACK 11 L: 6(123)4+P medium (plain script), ATTACK 11 SP: 6(123)4+P heavy (plain script) +2 */
    { { {  -52,  19,  56,  26 },  {  -31,  54,  56,  26 },  {  -33,  69,  33,  21 },  {  -33,  68,   0,  32 } } },  /* 3: DASH HUMIKOMI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -33,  51,  80,  15 },  {  -52,  74,  59,  19 },  {  -40,  62,  36,  21 },  {  -40,  85,   0,  34 } } },  /* 4: L KICK C */
    { { {  -24,  53,  81,  18 },  {  -34,  67,  59,  23 },  {  -34,  60,  34,  25 },  {  -40,  81,   0,  34 } } },  /* 5: L KICK C */
    { { {  -30,  30,  82,  18 },  {  -52,  66,  62,  28 },  {  -38,  60,  40,  30 },  {  -50,  90,   0,  38 } } },  /* 6: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -38,  60,  40,  34 },  {  -50,  90,   0,  38 } } },  /* 7: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script) +1 */
    { { {  -21,  31,  59,  17 },  {  -39,  75,  49,  20 },  {  -38,  71,  29,  20 },  {  -43,  84,   0,  29 } } },  /* 8: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +43 */
    { { {  -28,  30,  84,  18 },  {  -44,  70,  62,  26 },  {  -32,  64,  36,  24 },  {  -48,  92,   0,  36 } } },  /* 9: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    { { {  -23,  42,  96,  16 },  {  -32,  64,  84,  23 },  {  -30,  59,  64,  18 },  {  -30,  60,  41,  21 } } },  /* 10: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +29 */
    { { {  -21,  33, 107,  41 },  {  -32,  61,  84,  24 },  {  -31,  59,  64,  20 },  {  -31,  59,  41,  23 } } },  /* 11: not used by a script */
    { { {  -35,  49,  81,  19 },  {  -45,  70,  59,  32 },  {  -40,  65,  34,  25 },  {  -40,  81,   0,  34 } } },  /* 12: L KICK C */
    { { {  -18,  30,  97,  44 },  {  -30,  56,  84,  22 },  {  -31,  57,  64,  20 },  {  -29,  52,  26,  38 } } },  /* 13: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +2 */
    { { {  -24,  26,  91,  16 },  {  -24,  52,  76,  23 },  {  -27,  54,  45,  29 },  {  -33,  68,   0,  43 } } },  /* 14: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1 */
    { { {  -24,  26,  91,  16 },  {  -29,  45,  73,  21 },  {  -33,  49,  41,  30 },  {  -39,  74,   0,  40 } } },  /* 15: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +6 */
    { { {  -18,  34,  92,  17 },  {  -23,  48,  73,  18 },  {  -55,  80,  53,  20 },  {  -35,  71,   0,  53 } } },  /* 16: S KICK A */
    { { {  -40,  29,  80,  18 },  {  -43,  59,  72,  17 },  {  -43,  69,  40,  32 },  {  -36,  82,   0,  40 } } },  /* 17: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    { { {  -33,  34,  93,  16 },  {  -48,  70,  83,  17 },  {  -46,  74,  48,  35 },  {  -40,  80,   0,  48 } } },  /* 18: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    { { {  -34,  37,  79,  13 },  {  -34,  52,  61,  19 },  {  -34,  61,  37,  22 },  {  -34,  81,   0,  35 } } },  /* 19: S PUNCH C */
    { { {  -28,  40,  83,  13 },  {  -27,  56,  62,  22 },  {  -28,  69,  38,  22 },  {  -33,  86,   0,  37 } } },  /* 20: S PUNCH C */
    { { {  -18,  31,  72,  17 },  {  -45,  77,  62,  17 },  {  -45,  77,  28,  33 },  {  -45,  89,   0,  28 } } },  /* 21: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    { { {  -17,  35,  76,  16 },  {  -32,  68,  61,  22 },  {  -32,  68,  38,  21 },  {  -42,  88,   0,  37 } } },  /* 22: L PUNCH A, L PUNCH C, M KICK C +10 */
    { { {  -35,  39,  81,  16 },  {  -24,  45,  65,  15 },  {  -53,  74,  46,  19 },  {  -40,  75,   0,  47 } } },  /* 23: M KICK C */
    { { {  -31,  39,  77,  22 },  {  -37,  67,  61,  21 },  {  -43,  73,  39,  22 },  {  -37,  77,   0,  39 } } },  /* 24: L KICK A, atca 162, follow-up of M KICK A */
    { { {  -31,  43,  81,  18 },  {  -25,  51,  64,  15 },  {  -53,  83,  46,  18 },  {  -37,  72,   0,  46 } } },  /* 25: L KICK A, atca 162, follow-up of M KICK A +1 */
    { { {  -24,  34,  84,  18 },  {  -73, 103,  64,  20 },  {  -36,  67,  41,  23 },  {  -36,  72,   0,  40 } } },  /* 26: L KICK A, atca 162, follow-up of M KICK A +5 */
    { { {  -30,  42,  83,  16 },  {  -80, 106,  52,  39 },  {  -36,  63,  38,  14 },  {  -42,  88,   0,  38 } } },  /* 27: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A / M KICK C +5 */
    { { {  -22,  34,  59,  19 },  {  -41,  78,  47,  25 },  {  -39,  73,  29,  18 },  {  -43,  87,   0,  29 } } },  /* 28: KAGAMI P A */
    { { {  -29,  31,  69,  17 },  {  -40,  68,  53,  23 },  {  -37,  61,  33,  20 },  {  -42,  87,   0,  33 } } },  /* 29: KAGAMI P A, follow-up of JUDGMENT WAIT */
    { { {  -29,  31,  69,  17 },  {  -40,  68,  53,  23 },  {  -37,  61,  33,  20 },  {  -42,  87,   0,  33 } } },  /* 30: KAGAMI P A, follow-up of JUDGMENT WAIT, follow-up of follow-up of JUDGMENT WAIT */
    { { {  -46,  31,  72,  17 },  {  -54,  68,  53,  23 },  {  -37,  61,  33,  20 },  {  -42,  87,   0,  33 } } },  /* 31: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {  -35,  31,  82,  17 },  {  -49,  67,  60,  26 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 32: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {  -30,  31,  89,  17 },  {  -45,  63,  60,  30 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 33: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {  -30,  31,  89,  17 },  {  -45,  63,  60,  30 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 34: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {  -30,  31,  89,  17 },  {  -45,  63,  60,  30 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 35: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -21,  31,  61,  17 },  {  -39,  75,  46,  27 },  {  -38,  71,  29,  20 },  {  -43,  84,   0,  29 } } },  /* 36: KAGAMI K A */
    { { {  -29,  36,  56,  19 },  {  -47,  71,  50,  15 },  {  -48,  78,  29,  21 },  {  -48,  95,   0,  29 } } },  /* 37: KAGAMI K A, UP P GUARD K S */
    { { {  -46,  33,  51,  18 },  {  -54,  76,  39,  26 },  {  -66, 106,  25,  27 },  {  -55, 112,   0,  33 } } },  /* 38: KAGAMI K A, UP P GUARD K S */
    { { {  -41,  51,  82,  19 },  {  -51,  77,  61,  26 },  {  -26,  65,  42,  27 },  {  -14,  62,   0,  42 } } },  /* 39: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {  -32,  31,  67,  17 },  {  -39,  76,  49,  28 },  {  -39,  68,  29,  20 },  {  -40,  87,   0,  29 } } },  /* 40: KAGAMI K A */
    { { {  -55,  31,  67,  17 },  {  -50,  66,  53,  24 },  {  -48,  80,  29,  24 },  {  -45,  87,   0,  29 } } },  /* 41: KAGAMI K A */
    { { {  -24,  43,  99,  16 },  {  -32,  58,  84,  25 },  {  -30,  56,  64,  20 },  {  -29,  55,  41,  23 } } },  /* 42: not used by a script */
    { { {  -61,  33,  30,  29 },  {  -40,  48,  35,  31 },  {  -75, 109,  23,  24 },  {  -48, 104,   0,  28 } } },  /* 43: KAGAMI K A */
    { { {  -41,  50,  71,  20 },  {  -35,  63,  62,  20 },  {  -22,  57,  40,  22 },  {  -14,  60,   0,  40 } } },  /* 44: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {  -19,  28, 107,  16 },  {    0,   0,   0,   0 },  {  -29,  58,  79,  32 },  {  -26,  52,  50,  29 } } },  /* 45: V JUMP P S A, F JUMP P S A, atca 168 */
    { { {  -35,  43, 104,  16 },  {    0,   0,   0,   0 },  {  -31,  61,  79,  34 },  {  -28,  56,  42,  37 } } },  /* 46: V JUMP P M A, F JUMP P M A */
    { { {    4,  31,  99,  18 },  {    0,   0,   0,   0 },  {  -21,  63,  71,  41 },  {  -21,  53,  43,  28 } } },  /* 47: V JUMP P L A, F JUMP P L A */
    { { {  -18,  37, 105,  15 },  {  -72, 102,  66,  44 },  {  -34,  74,  40,  37 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP P L A, F JUMP P L A */
    { { {  -45,  42,  96,  16 },  {  -37,  71,  84,  23 },  {  -35,  79,  64,  18 },  {  -26,  78,  48,  16 } } },  /* 49: V JUMP K L A, F JUMP K L A */
    { { {  -76,  50,  78,  15 },  {  -76,  72,  47,  31 },  {  -26,  79,  78,  27 },  {   -4,  57,  47,  31 } } },  /* 50: F JUMP K L A, V JUMP K L A */
    { { {  -33,  39,  71,  20 },  {  -35,  63,  62,  20 },  {  -35,  71,  40,  22 },  {  -35,  81,   0,  40 } } },  /* 51: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    { { {  -29,  37,  82,  20 },  {  -43,  69,  62,  26 },  {  -35,  71,  40,  22 },  {  -35,  81,   0,  40 } } },  /* 52: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    { { {  -48,  16,  55,  16 },  {  -39,  45,  50,  22 },  {  -28,  56,  32,  15 },  {  -32,  68,   0,  28 } } },  /* 53: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 54: dmca 97 */
    { { {   -1,  16,  99,  16 },  {  -19,  61,  82,  20 },  {  -12,  47,  56,  24 },  {  -17,  53,  12,  42 } } },  /* 55: FUSHIN P S */
    { { {  -11,  16,  71,  16 },  {  -22,  56,  60,  16 },  {  -20,  50,  38,  20 },  {  -20,  53,   0,  36 } } },  /* 56: TOUKETSU A, OKIAGARI P S */
    { { {  -29,  37,  82,  20 },  {  -43,  69,  62,  26 },  {  -35,  71,  40,  22 },  {  -35,  81,   0,  40 } } },  /* 57: OKIAGARI P S, ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    { { {  -43,  16,  57,  16 },  {  -55,  56,  59,  12 },  {  -37,  53,  33,  22 },  {  -23,  53,   0,  40 } } },  /* 58: not used by a script */
    { { {  -33,  33,  71,  22 },  {  -42,  73,  65,  17 },  {  -42,  62,  50,  15 },  {  -42,  70,  35,  15 } } },  /* 59: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    { { {  -38,  34,  86,  17 },  {  -42,  62,  78,  14 },  {  -42,  74,  58,  20 },  {  -42,  78,   0,  58 } } },  /* 60: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -22,  16,  90,  16 },  {  -28,  50,  71,  20 },  {  -27,  46,  47,  24 },  {  -29,  52,   0,  47 } } },  /* 61: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    4,  16,  88,  14 },  {  -20,  46,  74,  16 },  {  -22,  36,  40,  32 },  {  -32,  60,   0,  38 } } },  /* 62: not used by a script */
    { { {   -4,  16,  90,  14 },  {  -22,  48,  74,  16 },  {  -24,  36,  40,  32 },  {  -36,  62,   0,  38 } } },  /* 63: not used by a script */
    { { {  -10,  16,  76,  14 },  {  -30,  50,  68,  16 },  {  -26,  36,  40,  26 },  {  -36,  62,   0,  38 } } },  /* 64: not used by a script */
    { { {  -26,  16,  74,  14 },  {  -42,  56,  60,  14 },  {  -20,  34,  38,  20 },  {  -36,  72,   0,  36 } } },  /* 65: not used by a script */
    { { {  -33,  36,  74,  17 },  {  -42,  74,  60,  14 },  {  -40,  75,  38,  22 },  {  -40,  79,   0,  38 } } },  /* 66: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -61,  26,  22,  20 },  {  -35,  19,  22,  20 },  {  -16,  36,  22,  20 },  {  -55, 102,   0,  22 } } },  /* 67: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    { { {  -50,  50,  96,  16 },  {  -72,  96,  83,  16 },  {  -45,  74,  48,  35 },  {  -45,  85,   0,  48 } } },  /* 68: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    { { {   -9,  16,  71,  16 },  {  -30,  64,  62,  16 },  {  -19,  49,  41,  20 },  {  -25,  53,   0,  39 } } },  /* 69: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {    8,  16,  79,  16 },  {  -20,  53,  69,  16 },  {  -17,  39,  36,  31 },  {  -30,  56,   0,  34 } } },  /* 70: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {   12,  16,  59,  16 },  {  -18,  53,  55,  15 },  {  -17,  41,  38,  15 },  {  -35,  53,   0,  36 } } },  /* 71: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -42,  16,  44,  16 },  {  -36,  54,  47,  19 },  {  -30,  48,  32,  13 },  {  -31,  57,   0,  30 } } },  /* 72: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -30,  16,  74,  16 },  {  -37,  51,  65,  19 },  {  -24,  39,  41,  22 },  {  -32,  50,   0,  40 } } },  /* 73: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -18,  47,  72,  17 },  {  -22,  55,  62,  18 },  {  -22,  55,  43,  17 },  {  -19,  49,  34,  14 } } },  /* 74: AIR S, AIR M, AIR L +41 */
    { { {  -34,  42, 104,  16 },  {  -28,  57,  80,  32 },  {  -29,  58,  41,  39 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K S A, F JUMP K S A */
    { { {  -34,  42, 104,  16 },  {  -28,  57,  80,  32 },  {  -29,  58,  41,  39 },  {    0,   0,   0,   0 } } },  /* 76: V JUMP K M A, F JUMP K M A */
    { { {  -60,  34,  78,  15 },  {  -62,  58,  32,  46 },  {  -26,  79,  78,  27 },  {   -4,  57,  47,  31 } } },  /* 77: V JUMP K L A */
    { { {  -22,  32,  83,  16 },  {  -45,  71,  52,  36 },  {  -49,  75,  38,  14 },  {  -65, 110,   0,  38 } } },  /* 78: ATTACK 13 M: not started by a command */
    { { {  -34,  33,  82,  17 },  {  -47,  67,  60,  29 },  {  -28,  61,  33,  27 },  {  -12,  68,   0,  33 } } },  /* 79: ATTACK 13 L: not started by a command */
    { { {  -30,  35,  89,  17 },  {  -50,  68,  60,  30 },  {  -50,  74,  33,  27 },  {  -50,  95,   0,  33 } } },  /* 80: ATTACK 13 L: not started by a command */
    { { {  -55,  31,  42,  18 },  {  -50,  64,  49,  31 },  {  -40,  67,  29,  24 },  {  -40,  85,   0,  29 } } },  /* 81: PIYO */
    { { {  -55,  31,  50,  18 },  {  -50,  64,  57,  30 },  {  -40,  65,  29,  37 },  {  -40,  83,   0,  29 } } },  /* 82: PIYO */
    { { {  -34,  42, 104,  16 },  {  -70,  96,  85,  27 },  {  -68,  94,  60,  25 },  {    0,   0,   0,   0 } } },  /* 83: not started by a command */
    { { {  -21,  31,  94,  17 },  {  -43,  74,  85,  14 },  {  -43,  74,  40,  45 },  {  -43,  74,   0,  40 } } },  /* 84: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -33,  36,  74,  17 },  {  -42,  74,  60,  14 },  {  -40,  75,  38,  22 },  {  -40,  79,   0,  38 } } },  /* 85: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -23,  42,  32,  16 },  {  -32,  64,  48,  23 },  {  -30,  59,  71,  18 },  {  -30,  60,  70,  59 } } },  /* 86: ATTACK 8 S: 214+K light/medium/heavy (routine Att_SLIDE_and_JUMP), ATTACK 8 SP: EX 214+KK (routine Att_HOMING_JUMP) */
    { { {   11,  45, 105,  18 },  {   -2,  63,  88,  28 },  {  -15,  70,  45,  43 },  {  -33,  83,   0,  45 } } },  /* 87: KAGAMI K A */
    { { {  -41,  51,  82,  19 },  {  -51,  77,  61,  26 },  {  -41,  78,  42,  27 },  {  -33,  84,   0,  42 } } },  /* 88: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {    0,   0,   0,   0 },  {  -35,  19,  22,  20 },  {  -16,  36,  22,  20 },  {  -51, 102,   0,  22 } } },  /* 89: ATTACK 3 S: SA II 23623+P (plain script) */
};

const HAND_BOX dudley_hand_box[88] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: no box */
    { { {  -74,  33,  20,  41 },  {    0,   0,   0,   0 } } },  /* 4: L KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {  -88,  63,  78,  21 },  {    0,   0,   0,   0 } } },  /* 14: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1 */
    { { {  -94,  66,  74,  24 },  {    0,   0,   0,   0 } } },  /* 15: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +6 */
    { { {  -65,  43,  69,  27 },  {    0,   0,   0,   0 } } },  /* 16: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: no box */
    { { {  -90,  63,  62,  22 },  {    0,   0,   0,   0 } } },  /* 20: S PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: no box */
    { { {  -72,  46,  63,  20 },  {    0,   0,   0,   0 } } },  /* 23: M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: no box */
    { { {  -72,  46,  65,  13 },  {    0,   0,   0,   0 } } },  /* 25: L KICK A, atca 162, follow-up of M KICK A +1 */
    { { {  -74,  50,  84,  21 },  {    0,   0,   0,   0 } } },  /* 26: L KICK A, atca 162, follow-up of M KICK A +5 */
    { { {  -91,  11,  61,  30 },  {    0,   0,   0,   0 } } },  /* 27: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A / M KICK C +5 */
    { { {  -81,  44,  39,  31 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {  -83,  44,  52,  27 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI P A, follow-up of JUDGMENT WAIT, follow-up of follow-up of JUDGMENT WAIT */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {  -83,  46,  57,  29 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {  -79,  48,  76,  38 },  {    0,   0,   0,   0 } } },  /* 33: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {  -79,  48,  76,  38 },  {    0,   0,   0,   0 } } },  /* 34: KAGAMI P A, follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A, follow-up of follow-up of JUDGMENT WAIT +3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {  -80,  52,  17,  42 },  {    0,   0,   0,   0 } } },  /* 36: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -80,  37,  19,  25 },  {    0,   0,   0,   0 } } },  /* 38: KAGAMI K A, UP P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {  -87,  39,  16,  19 },  {    0,   0,   0,   0 } } },  /* 43: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {  -75,  47,  82,  27 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP P S A, F JUMP P S A, atca 168 */
    { { {  -75,  47,  83,  24 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -43,  14,  70,  23 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: no box */
    { { {  -73,  41,  99,  27 },  {    0,   0,   0,   0 } } },  /* 68: M KICK A, follow-up of L KICK C / KAGAMI K A +1, follow-up of M PUNCH A / M KICK C +4 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {  -56,  44,  75,  41 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K S A, F JUMP K S A */
    { { {  -49,  36,  65,  46 },  {    0,   0,   0,   0 } } },  /* 76: V JUMP K M A, F JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: no box */
    { { {  -88,  66,  62,  33 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 13 M: not started by a command */
    { { {  -87,  55,  51,  32 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 13 L: not started by a command */
    { { {  -81,  50,  72,  40 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 13 L: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {  -72,  28,  60,  14 },  {    0,   0,   0,   0 } } },  /* 85: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -37,  35,  21,  28 },  {    0,   0,   0,   0 } } },  /* 86: not used by a script */
    { { {  -37,  35,   7,  42 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 8 S: 214+K light/medium/heavy (routine Att_SLIDE_and_JUMP), ATTACK 8 SP: EX 214+KK (routine Att_HOMING_JUMP) */
};

const HOSEI_BOX dudley_hos_box[29] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -28,   57,    0,   91 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +129 */
    { {  -24,   48,    0,   85 } },  /* 2: not used by a script */
    { {  -28,   57,    0,   61 } },  /* 3: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +69 */
    { {  -20,   57,    0,   91 } },  /* 4: M KICK C */
    { {  -26,   52,   44,   61 } },  /* 5: V JUMP K L A, AIR S, AIR M +47 */
    { {  -12,   57,    0,   91 } },  /* 6: not used by a script */
    { {   -4,   57,    0,   91 } },  /* 7: not used by a script */
    { {  -24,   57,    0,   91 } },  /* 8: not used by a script */
    { {    4,   57,    0,   91 } },  /* 9: not used by a script */
    { {  -28,   57,    0,   73 } },  /* 10: PIYO */
    { {  -28,   57,    0,   40 } },  /* 11: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1, ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    { {  -28,   57,    0,   50 } },  /* 12: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    { {  -12,   57,    0,   58 } },  /* 13: ATTACK 3 S: SA II 23623+P (plain script) */
    { {  -42,   71,    0,   91 } },  /* 14: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -17,   47,    6,   91 } },  /* 15: FUSHIN P S */
    { {  -18,   48,   27,   48 } },  /* 16: TOUKETSU A, OKIAGARI P S */
    { {  -32,   48,   27,   48 } },  /* 17: not used by a script */
    { {  -29,   48,   19,   44 } },  /* 18: not used by a script */
    { {  -55,   93,   19,   44 } },  /* 19: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    { {  -32,   64,    0,   80 } },  /* 20: DASH HUMIKOMI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    { {  -33,   57,    0,   91 } },  /* 21: not used by a script */
    { {  -53,   81,   41,   37 } },  /* 22: not used by a script */
    { {  -49,   94,   19,   44 } },  /* 23: not used by a script */
    { {  -20,   51,   40,   44 } },  /* 24: AIR S, AIR M, AIR L +41 */
    { {  -39,   74,    0,   79 } },  /* 25: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    { {  -28,   57,    0,   30 } },  /* 26: dmca 97, NEKOROBI S, dmca 96 */
    { {  -38,   67,    0,   91 } },  /* 27: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -28,   84,    0,   74 } },  /* 28: ATTACK 3 S: SA II 23623+P (plain script) */
};
