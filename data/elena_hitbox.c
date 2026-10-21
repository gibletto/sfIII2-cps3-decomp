/*
 * ELENA_HITBOX.C  Elena's hit boxes
 *
 * Each of Elena's animation frames names an entry of elena_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX elena_hit_ix_table[313] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +9 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, STAND UP, WALK END +75 */
    {    2,    2,    0,    0,    1,    0,    0,    1 },  /* 2: FRONT WALK, BACK WALK, ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {    3,    3,    0,    0,    2,    0,    0,    2 },  /* 3: KAGAMU, KAGAMI KAMAE, PARING DOWN +34 */
    {   11,   11,    0,    0,    1,    0,    0,    1 },  /* 4: follow-up of S PUNCH A, S PUNCH C +8, PIYO, WAIT */
    {    4,    4,    0,    0,    3,    0,    0,    3 },  /* 5: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +2 */
    {    5,    5,    0,    0,    3,    0,    0,    3 },  /* 6: JUMP FRONT, S JUMP FRONT, PARING AIR F +19 */
    {    6,    6,    0,    0,    5,    0,    0,    6 },  /* 7: AIR S, AIR M, AIR L +23 */
    {    7,    7,    0,    0,    6,    0,    0,    5 },  /* 8: DASH HUMIKOMI */
    {    8,    8,    0,    0,    6,    0,    0,    5 },  /* 9: DASH HUMIKOMI */
    {    9,    9,    0,    0,    1,    0,    0,    1 },  /* 10: DASH HUMIKOMI, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   10,   10,    0,    0,    1,    0,    0,    1 },  /* 11: DASH HUMIKOMI */
    {   12,   12,    0,    0,    3,    0,    0,    3 },  /* 12: GUARD AIR */
    {  185,  185,    0,    0,    0,    0,    0,    0 },  /* 13: ATTACK 7 M: not started by a command, SP APPEAR 1 */
    {   13,   13,    0,    0,    2,    0,    0,    2 },  /* 14: KAGAMI TURN */
    {   14,   14,    0,    0,    2,    0,    0,    2 },  /* 15: KAGAMI TURN */
    {   15,   15,    0,    0,    1,    0,    0,    1 },  /* 16: HURIMUKI */
    {   16,   16,    0,    0,    1,    0,    0,    1 },  /* 17: HURIMUKI */
    {   17,   17,    0,    0,    1,    0,    0,    1 },  /* 18: HURIMUKI */
    {   18,   18,    0,    0,    1,    0,    0,    1 },  /* 19: HURIMUKI */
    {   19,   19,    0,    0,    2,    0,    0,    2 },  /* 20: KAGAMI P A */
    {   21,   21,    0,    0,    7,    0,    0,    2 },  /* 21: KAGAMI P A */
    {   22,   22,    0,    0,    7,    0,    0,    2 },  /* 22: KAGAMI P A */
    {   21,   21,    0,    0,    2,    0,    0,    2 },  /* 23: KAGAMI P A */
    {   22,   22,    0,    0,    2,    0,    0,    2 },  /* 24: KAGAMI P A */
    {   23,   23,    0,    0,    7,    0,    0,    2 },  /* 25: KAGAMI K A */
    {   24,   24,    0,    2,    7,    2,    0,    2 },  /* 26: KAGAMI K A */
    {   24,   24,    0,    0,    7,    0,    0,    2 },  /* 27: KAGAMI K A */
    {   25,   25,    0,    0,    7,    0,    0,    2 },  /* 28: KAGAMI K A */
    {   26,   26,    0,    0,    7,    0,    0,    2 },  /* 29: KAGAMI K A */
    {   27,   27,    0,    3,    2,    3,    0,    2 },  /* 30: not used by a script */
    {   27,   27,    0,    0,    2,    0,    0,    2 },  /* 31: KAGAMI P A */
    {   28,   28,    0,    0,    2,    0,    0,    2 },  /* 32: KAGAMI P A, KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   29,   29,    0,    0,    2,    0,    0,    2 },  /* 33: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   30,   30,    0,    0,    2,    0,    0,    2 },  /* 34: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   31,   31,    0,    0,    2,    0,    0,    2 },  /* 35: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   32,   32,    0,    4,    2,    4,    0,    2 },  /* 36: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   32,   32,    0,    0,    2,    0,    0,    2 },  /* 37: KAGAMI P A, ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   33,   33,    0,    0,    2,    0,    0,    2 },  /* 38: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   34,   34,    0,    0,    2,    0,    0,    2 },  /* 39: KAGAMI K A */
    {   35,   35,    0,    0,    2,    0,    0,    2 },  /* 40: KAGAMI K A */
    {   36,   36,    0,    0,    2,    0,    0,    2 },  /* 41: KAGAMI K A */
    {   37,   37,    0,    5,    2,    5,    0,    2 },  /* 42: not used by a script */
    {   37,   37,    0,    0,    2,    0,    0,    2 },  /* 43: KAGAMI K A */
    {   38,   38,    0,    0,    3,    0,    0,    3 },  /* 44: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   39,   39,    0,    0,    3,    0,    0,    3 },  /* 45: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   40,   40,    0,    6,    3,    6,    0,    3 },  /* 46: V JUMP P S A, F JUMP P S A */
    {  107,  107,    0,    0,    3,    0,    0,    3 },  /* 47: V JUMP P S A, V JUMP P M A, V JUMP P L A +10 */
    {  108,  108,    0,    0,    3,    0,    0,    3 },  /* 48: V JUMP P M A, V JUMP P L A, V JUMP K S A +7 */
    {  109,  109,    0,    7,    3,    7,    0,    3 },  /* 49: V JUMP P M A, F JUMP P M A */
    {  109,  109,    0,    0,    3,    0,    0,    3 },  /* 50: V JUMP P M A, F JUMP P M A */
    {  110,  110,    0,    0,    3,    0,    0,    3 },  /* 51: V JUMP P L A, F JUMP P L A */
    {  111,  111,    0,    0,    3,    0,    0,    3 },  /* 52: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    {  112,  112,    0,    8,    3,    8,    0,    3 },  /* 53: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    {  112,  112,    0,    0,    3,    0,    0,    3 },  /* 54: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    {  114,  114,    0,    0,    3,    0,    0,    3 },  /* 55: V JUMP K S A, F JUMP K S A */
    {  114,  114,    0,    9,    3,    9,    0,    3 },  /* 56: V JUMP K S A, F JUMP K S A */
    {  115,  115,    0,   10,    3,   10,    0,    3 },  /* 57: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    {  115,  115,    0,    0,    3,    0,    0,    3 },  /* 58: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    {    0,    0,    0,    0,    3,    0,    0,    3 },  /* 59: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0,    0,    0,    0,    0,    6 },  /* 60: AIR S, AIR M, AIR L +2 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 61: GUARD HEAD, GUARD UP, APPEAR 1 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 62: GUARD UP, GUARD AIR, HUSHIN HEAD +2 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 63: FUSHIN P S, ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {    0,    0,    0,    0,    0,    0,    0,    6 },  /* 64: not used by a script */
    {   46,   46,    0,    0,    1,    0,    0,    1 },  /* 65: not used by a script */
    {   47,   47,    0,    0,    1,    0,    0,    1 },  /* 66: not used by a script */
    {   48,   48,    0,    0,    1,    0,    0,    1 },  /* 67: follow-up of SP WIN 2 */
    {   49,   49,    0,    0,    1,    0,    0,    1 },  /* 68: HUSHIN HEAD, HUSHIN DOWN, follow-up of SP WIN 2 +1 */
    {   50,   50,    0,    0,    5,    0,    0,    6 },  /* 69: PARING AIR F, PARING AIR B, P BREAK AIR F +1 */
    {   51,   51,    0,    0,    5,    0,    0,    6 },  /* 70: not used by a script */
    {   52,   52,    0,    0,    1,    0,    0,    2 },  /* 71: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   53,   53,    0,    0,    1,    0,    0,    1 },  /* 72: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   54,   54,    0,   26,    1,   26,    0,    1 },  /* 73: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   54,   54,    0,    0,    1,    0,    0,    1 },  /* 74: M PUNCH C, OKIAGARI P S */
    {   55,   55,    0,    0,    1,    0,    0,    1 },  /* 75: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   56,   56,    0,    0,    1,    0,    0,    2 },  /* 76: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   57,   57,    0,    0,    1,    0,    0,    2 },  /* 77: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   58,   58,    0,   49,    1,   49,    0,    2 },  /* 78: M PUNCH A */
    {   59,   59,    0,   27,    1,   27,    0,    2 },  /* 79: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   59,   59,    0,    0,    1,    0,    0,    2 },  /* 80: M PUNCH A */
    {   60,   60,    0,    0,    1,    0,    0,    2 },  /* 81: M PUNCH A */
    {   61,   61,    0,    0,    1,    0,    0,    2 },  /* 82: M PUNCH A */
    {   62,   62,    0,    0,    1,    0,    0,    1 },  /* 83: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   63,   63,    0,    0,    1,    0,    0,    1 },  /* 84: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   64,   64,    0,    0,    1,    0,    0,    1 },  /* 85: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   65,   65,    0,   28,    1,   28,    0,    1 },  /* 86: not used by a script */
    {   65,   65,    0,   41,    1,   41,    0,    1 },  /* 87: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   66,   66,    0,    0,    1,    0,    0,    1 },  /* 88: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   67,   67,    0,    0,    1,    0,    0,    1 },  /* 89: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   68,   68,    0,    0,    1,    0,    0,    1 },  /* 90: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   69,   69,    0,    0,    8,    0,    0,    8 },  /* 91: L KICK A, UP P GUARD P L, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   70,   70,    0,   29,    8,   29,    0,    8 },  /* 92: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   71,   71,    0,   29,    8,   29,    0,    8 },  /* 93: L KICK A, UP P GUARD P L */
    {   71,   71,    0,    0,    8,    0,    0,    8 },  /* 94: L KICK A, UP P GUARD P L */
    {   72,   72,    0,    0,    8,    0,    0,    8 },  /* 95: L KICK A, UP P GUARD P L */
    {   73,   73,    0,    0,    1,    0,    0,    1 },  /* 96: L KICK A, UP P GUARD P L */
    {   74,   74,    0,    0,    1,    0,    0,    1 },  /* 97: S PUNCH A, UP P GUARD P S, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   75,   75,    0,   30,    1,   30,    0,    1 },  /* 98: S PUNCH A, UP P GUARD P S */
    {   75,   75,    0,    0,    1,    0,    0,    1 },  /* 99: S PUNCH A */
    {   75,   75,    0,    0,    1,    0,    0,    1 },  /* 100: UP P GUARD P S */
    {   76,   76,    0,    0,    1,    0,    0,    1 },  /* 101: S PUNCH A, UP P GUARD P S */
    {   77,   77,    0,    0,    1,    0,    0,    1 },  /* 102: S PUNCH A, UP P GUARD P S */
    {   78,   78,    0,    0,    1,    0,    0,    1 },  /* 103: S KICK A, D P GUARD P S, FUSHIN P S +1 */
    {   79,   79,    0,   32,    1,   32,    0,    1 },  /* 104: S KICK A, D P GUARD P S, FUSHIN P S +1 */
    {   79,   79,    0,    0,    1,    0,    0,    1 },  /* 105: S KICK A, D P GUARD P S */
    {   81,   81,    0,    0,    1,    0,    0,    1 },  /* 106: S KICK A, D P GUARD P S */
    {   82,   82,    0,    0,    2,    0,    0,    2 },  /* 107: L KICK C, KAGAMI K C, D P GUARD P M */
    {   83,   83,    0,    0,    2,    0,    0,    2 },  /* 108: L KICK C, KAGAMI K C, D P GUARD P M */
    {  206,  206,    0,   33,    2,   33,    0,    2 },  /* 109: D P GUARD P M */
    {   84,   84,    0,   33,    2,   33,    0,    2 },  /* 110: L KICK C, KAGAMI K C, D P GUARD P M */
    {   84,   84,    0,    0,    2,    0,    0,    2 },  /* 111: L KICK C, KAGAMI K C, D P GUARD P M */
    {   86,   86,    0,    0,    2,    0,    0,    2 },  /* 112: L KICK C, KAGAMI K C, D P GUARD P M */
    {   87,   87,    0,    0,    2,    0,    0,    2 },  /* 113: L KICK C, KAGAMI K C, D P GUARD P M */
    {   88,   88,    0,    0,    2,    0,    0,    2 },  /* 114: L KICK C, KAGAMI K C, D P GUARD P M */
    {   89,   89,    0,    0,    1,    0,    0,    1 },  /* 115: L KICK C, KAGAMI K C, D P GUARD P M */
    {   90,   90,    0,    0,    1,    0,    0,    1 },  /* 116: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) */
    {   91,   91,    0,    0,    1,    0,    0,    1 },  /* 117: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   92,   92,    0,    0,    3,    0,    0,    3 },  /* 118: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   93,   93,    0,    0,    3,    0,    0,    3 },  /* 119: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   94,   94,    0,    0,    3,    0,    0,    3 },  /* 120: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   95,   95,    0,    0,    3,    0,    0,    3 },  /* 121: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +5 */
    {   96,   96,    0,   35,    1,   35,    0,    1 },  /* 122: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    {   97,   97,    0,   36,    1,   36,    0,    1 },  /* 123: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    {   98,   98,    0,    0,    1,    0,    0,    1 },  /* 124: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    {   99,   99,    0,    0,    1,    0,    0,    1 },  /* 125: not used by a script */
    {  100,  100,    0,    0,    1,    0,    0,    2 },  /* 126: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  101,  101,    0,    0,    1,    0,    0,    2 },  /* 127: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  102,  102,    0,    0,    1,    0,    0,    2 },  /* 128: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  103,  103,    0,   37,    1,   37,    0,    2 },  /* 129: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  104,  104,    0,    0,    1,    0,    0,    2 },  /* 130: M KICK A */
    {  105,  105,    0,    0,    1,    0,    0,    2 },  /* 131: M KICK A, UP P GUARD P M */
    {  106,  106,    0,    0,    1,    0,    0,    1 },  /* 132: M KICK A, UP P GUARD P M */
    {   97,   97,    0,    0,    1,    0,    0,    1 },  /* 133: not used by a script */
    {  116,  116,    0,    0,    3,    0,    0,    3 },  /* 134: V JUMP K L A, F JUMP K L A */
    {  117,  117,    0,    0,    3,    0,    0,    3 },  /* 135: V JUMP K L A, F JUMP K L A */
    {  118,  118,    0,    0,    3,    0,    0,    3 },  /* 136: V JUMP K L A, F JUMP K L A */
    {  119,  119,    0,   11,    3,   11,    0,    3 },  /* 137: V JUMP K L A, F JUMP K L A */
    {  120,  120,    0,    0,    3,    0,    0,    3 },  /* 138: V JUMP K L A, F JUMP K L A */
    {  121,  121,    0,    0,    3,    0,    0,    3 },  /* 139: V JUMP K L A, F JUMP K L A */
    {  122,  122,    0,    0,    3,    0,    0,    3 },  /* 140: V JUMP K L A, F JUMP K L A */
    {  123,  123,    0,    0,    2,    0,    0,    2 },  /* 141: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  124,  124,    0,    0,    2,    0,    0,    2 },  /* 142: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  125,  125,    0,   12,    2,   12,    0,    2 },  /* 143: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  126,  126,    0,    0,    2,    0,    0,    2 },  /* 144: KAGAMI K A */
    {  127,  127,    0,    0,    2,    0,    0,    2 },  /* 145: KAGAMI K A */
    {  128,  128,    0,    0,    2,    0,    0,    2 },  /* 146: KAGAMI K A */
    {  129,  129,    0,    0,    2,    0,    0,    2 },  /* 147: KAGAMI K A */
    {  130,  130,    0,    0,    2,    0,    0,    2 },  /* 148: KAGAMI K A */
    {    0,    0,    0,    0,    0,    0,    0,    4 },  /* 149: TATAKI S, TATAKI V. S, KGM TATAKI S +21 */
    {  131,  131,    0,    0,    2,    0,    0,    4 },  /* 150: OKIAGARI P S */
    {  132,  132,    0,   13,    2,   13,    0,    4 },  /* 151: OKIAGARI P S */
    {  132,  132,    0,    0,    2,    0,    0,    4 },  /* 152: OKIAGARI P S */
    {  133,  133,    0,    0,    2,    0,    0,    4 },  /* 153: OKIAGARI P S */
    {  134,  134,    0,    0,    2,    0,    0,    4 },  /* 154: OKIAGARI P S */
    {  135,  135,    0,    0,    2,    0,    0,    4 },  /* 155: OKIAGARI P S */
    {  136,  136,    0,    0,    2,    0,    0,    4 },  /* 156: OKIAGARI P S */
    {  137,  137,    0,   14,    3,   14,    0,    3 },  /* 157: UP P GUARD P L */
    {  138,  138,    0,   15,    3,   15,    0,    3 },  /* 158: UP P GUARD P L */
    {   80,   80,    0,   48,    1,   48,    0,    1 },  /* 159: not used by a script */
    {  140,  140,    0,    0,    1,    0,    0,    1 },  /* 160: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  141,  141,    0,    0,    1,    0,    0,    1 },  /* 161: UP P GUARD P L */
    {  142,  142,    0,    0,    1,    0,    0,    1 },  /* 162: UP P GUARD P L */
    {  143,  143,    0,    0,    1,    0,    0,    2 },  /* 163: DASH TOBINOKI */
    {  144,  144,    0,    0,    1,    0,    0,    2 },  /* 164: DASH TOBINOKI */
    {  145,  145,    0,    0,    1,    0,    0,    2 },  /* 165: DASH TOBINOKI */
    {  146,  146,    0,    0,    1,    0,    0,    2 },  /* 166: DASH TOBINOKI */
    {  147,  147,    0,    0,    1,    0,    0,    2 },  /* 167: DASH TOBINOKI */
    {  148,  148,    0,    0,    1,    0,    0,    2 },  /* 168: DASH TOBINOKI */
    {  149,  149,    0,    0,    1,    0,    0,    2 },  /* 169: DASH TOBINOKI */
    {  150,  150,    0,    0,    1,    0,    0,    1 },  /* 170: DASH TOBINOKI */
    {    1,    1,    0,   16,    1,   16,    0,    1 },  /* 171: M PUNCH A, M PUNCH C */
    {  181,  181,    0,   54,    5,   54,    0,    6 },  /* 172: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  182,  182,    0,   38,    5,   38,    0,    6 },  /* 173: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {   98,   98,    0,   25,    1,   25,    0,    1 },  /* 174: follow-up of APPEAR 1, follow-up of SP WIN 3, follow-up of SP WIN 4 */
    {  183,  183,    0,   39,    9,   39,    0,    9 },  /* 175: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  184,  184,    0,   40,    9,   40,    0,    9 },  /* 176: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  118,  118,    0,   42,    3,   42,    0,    3 },  /* 177: V JUMP K L A, F JUMP K L A */
    {  156,  156,    0,    0,    0,    0,    0,    6 },  /* 178: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  157,  157,    0,   17,    5,   17,    0,    6 },  /* 179: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  158,  158,    0,   18,    9,   18,    0,    9 },  /* 180: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  159,  159,    0,    0,    9,    0,    0,    9 },  /* 181: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  160,  160,    0,    0,    9,    0,    0,    9 },  /* 182: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  161,  161,    0,    0,    9,    0,    0,    9 },  /* 183: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  162,  162,    0,    0,    9,    0,    0,    9 },  /* 184: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  163,  163,    0,    0,    1,    0,    0,    1 },  /* 185: follow-up of APPEAR JUNBI 7, follow-up of SP WIN 6, follow-up of SP WIN 7 */
    {  164,  164,    0,    0,    1,    0,    0,    1 },  /* 186: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  165,  165,    0,    0,    1,    0,    0,    1 },  /* 187: S PUNCH C, ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  166,  166,    0,    0,    1,    0,    0,    1 },  /* 188: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  167,  167,    0,    0,    1,    0,    0,    1 },  /* 189: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  168,  168,    0,    0,    1,    0,    0,    1 },  /* 190: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  169,  169,    0,    0,    1,    0,    0,    1 },  /* 191: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  170,  170,    0,    0,    1,    0,    0,    1 },  /* 192: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  171,  171,    0,    0,    1,    0,    0,    1 },  /* 193: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  172,  172,    0,   20,    3,   20,    0,    3 },  /* 194: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  173,  173,    0,   21,    3,   21,    0,    3 },  /* 195: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  174,  174,    0,   22,    3,   22,    0,    3 },  /* 196: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  175,  175,    0,    0,    3,    0,    0,    3 },  /* 197: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  176,  176,    0,   23,    3,   23,    0,    3 },  /* 198: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  176,  176,    0,    0,    3,    0,    0,    3 },  /* 199: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  177,  177,    0,    0,    3,    0,    0,    3 },  /* 200: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  178,  178,    0,    0,    9,    0,    0,    9 },  /* 201: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  179,  179,    0,   24,    5,   24,    0,    6 },  /* 202: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  179,  179,    0,    0,    5,    0,    0,    6 },  /* 203: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  180,  180,    0,    0,    1,    0,    0,    1 },  /* 204: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  186,  186,    0,    0,    1,    0,    0,    1 },  /* 205: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  187,  187,    0,   43,    1,   43,    0,    1 },  /* 206: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  188,  188,    0,   44,    1,   44,    0,    1 },  /* 207: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  189,  189,    0,   45,    1,   45,    0,    1 },  /* 208: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  190,  190,    0,   46,    1,   46,    0,    1 },  /* 209: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  191,  191,    0,   47,    1,   47,    0,    1 },  /* 210: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  192,  192,    0,    0,    1,    0,    0,    1 },  /* 211: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  193,  193,    0,    0,    1,    0,    0,    1 },  /* 212: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  194,  194,    0,    0,    1,    0,    0,    1 },  /* 213: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  195,  195,    0,    0,    1,    0,    0,    1 },  /* 214: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  196,  196,    0,    0,    1,    0,    0,    1 },  /* 215: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  197,  197,    0,    0,    1,    0,    0,    1 },  /* 216: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  198,  198,    0,    0,    1,    0,    0,    1 },  /* 217: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  199,  199,    0,    0,    1,    0,    0,    1 },  /* 218: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  200,  200,    0,    0,    1,    0,    0,    1 },  /* 219: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  201,  201,    0,    0,    1,    0,    0,    1 },  /* 220: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  202,  202,    0,    0,    1,    0,    0,    1 },  /* 221: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  203,  203,    0,    0,    1,    0,    0,    1 },  /* 222: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  204,  204,    0,    0,    1,    0,    0,    1 },  /* 223: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0,   44,    1,   44,    0,    1 },  /* 224: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  223,  223,    0,   31,    1,   31,    0,    1 },  /* 225: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  119,  119,    0,    0,    3,    0,    0,    3 },  /* 226: V JUMP K L A, F JUMP K L A */
    {  260,    0,    0,   62,    3,   62,    0,    3 },  /* 227: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  103,  103,    0,    0,    1,    0,    0,    2 },  /* 228: M KICK A */
    {  205,  205,    0,    0,    1,    0,    0,    2 },  /* 229: not used by a script */
    {  209,  209,    0,    1,    7,    1,    0,    2 },  /* 230: KAGAMI P A */
    {   27,   27,    0,    3,    2,    3,    0,    2 },  /* 231: KAGAMI P A */
    {   55,   55,    0,    0,    1,    0,    0,    2 },  /* 232: M PUNCH C */
    {  211,  211,    0,    0,    2,    0,    0,    2 },  /* 233: KAGAMI K A */
    {  211,  211,    0,    5,    2,    5,    0,    2 },  /* 234: KAGAMI K A */
    {  125,  125,    0,    0,    2,    0,    0,    2 },  /* 235: KAGAMI K A */
    {  174,  174,    0,    0,    3,    0,    0,    3 },  /* 236: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
    {  224,  224,    0,    0,    2,    0,    0,    2 },  /* 237: ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
    {  207,  207,    0,   28,    1,   28,    0,    1 },  /* 238: L PUNCH A */
    {   65,   65,    0,    0,    1,    0,    0,    1 },  /* 239: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  208,  208,    0,    0,    1,    0,    0,    1 },  /* 240: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  210,  210,    0,    0,    2,    0,    0,    2 },  /* 241: KAGAMI P A */
    {  212,  212,    0,    0,    1,    0,    0,    2 },  /* 242: M PUNCH A */
    {  213,  213,    0,   50,    8,   50,    0,    8 },  /* 243: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  214,  214,    0,   51,    8,   51,    0,    8 },  /* 244: L KICK A */
    {  215,  215,    0,    0,    1,    0,    0,    2 },  /* 245: M KICK A */
    {  216,  216,    0,    0,    0,    0,    0,    6 },  /* 246: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  217,  217,    0,    0,    5,    0,    0,    6 },  /* 247: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  218,  218,    0,   19,    9,   19,    0,    9 },  /* 248: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  219,  219,    0,    0,    0,    0,    0,    6 },  /* 249: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  219,  219,    0,   54,    5,   54,    0,    6 },  /* 250: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  220,  220,    0,   52,    5,   52,    0,    6 },  /* 251: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  221,  221,    0,   53,    9,   53,    0,    9 },  /* 252: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {    1,    1,    0,   58,    1,   58,    0,    1 },  /* 253: L PUNCH A */
    {   40,   40,    0,   59,    3,   59,    0,    3 },  /* 254: not used by a script */
    {  222,  222,    0,   11,    3,   11,    0,    3 },  /* 255: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,    7 },  /* 256: NEKOROBI S, dmca 96 */
    {  210,  210,    0,    0,    7,    0,    0,    2 },  /* 257: KAGAMI P A */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 258: follow-up of JUDGMENT WIN */
    {    3,    3,    0,    0,    0,    0,    0,    2 },  /* 259: follow-up of JUDGMENT WIN */
    {   40,   40,    0,   63,    3,   63,    0,    3 },  /* 260: ATTACK 7 L: not started by a command */
    {  207,  207,    0,   64,    1,   64,    0,    1 },  /* 261: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 262: LOSE SONABA */
    {  225,  225,    0,    0,    1,    0,    0,    1 },  /* 263: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  226,  226,    0,    0,    1,    0,    0,    2 },  /* 264: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  227,  227,    0,    0,    1,    0,    0,    2 },  /* 265: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  228,  228,    0,    0,    1,    0,    0,    2 },  /* 266: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  229,  229,    0,    0,    1,    0,    0,    2 },  /* 267: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  230,  230,    0,    0,    1,    0,    0,    2 },  /* 268: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  231,  231,    0,    0,    1,   65,    0,    2 },  /* 269: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  232,  232,    0,    0,    1,    0,    0,    2 },  /* 270: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  232,    0,    0,    0,    1,    0,    0,    2 },  /* 271: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  233,  233,    0,    0,    1,    0,    0,    2 },  /* 272: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  234,  234,    0,    0,    1,    0,    0,    2 },  /* 273: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  235,  235,    0,    0,    1,    0,    0,    2 },  /* 274: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +5 */
    {  236,  236,    0,    0,    1,    0,    0,    2 },  /* 275: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  237,  237,    0,    0,    1,    0,    0,    1 },  /* 276: not used by a script */
    {  238,  238,    0,    0,    1,    0,    0,    1 },  /* 277: not used by a script */
    {  239,  239,    0,    0,    1,    0,    0,    2 },  /* 278: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  240,  240,    0,    0,    1,    0,    0,    2 },  /* 279: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  241,  241,    0,    0,    1,    0,    0,    2 },  /* 280: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  242,  242,    0,    0,    1,   67,    0,    2 },  /* 281: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  243,  243,    0,    0,    1,   68,    0,    2 },  /* 282: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  244,  244,    0,    0,    1,    0,    0,    2 },  /* 283: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  245,  245,    0,    0,    1,    0,    0,    2 },  /* 284: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  246,  246,    0,    0,    1,   70,    0,    2 },  /* 285: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  247,  247,    0,    0,    1,    0,    0,    2 },  /* 286: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  248,  248,    0,    0,    1,    0,    0,    2 },  /* 287: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  249,  249,    0,    0,    1,    0,    0,    1 },  /* 288: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  250,  250,    0,    0,    1,    0,    0,    1 },  /* 289: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  251,  251,    0,    0,    1,    0,    0,    1 },  /* 290: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  252,  252,    0,    0,    1,    0,    0,    1 },  /* 291: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  253,  253,    0,    0,    1,    0,    0,    1 },  /* 292: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  254,  254,    0,    0,    1,    0,    0,    1 },  /* 293: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {    1,   41,    0,    0,    1,   72,    0,    1 },  /* 294: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    {    1,   42,    0,    0,    1,   73,    0,    1 },  /* 295: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    {    0,    0,    0,    0,    0,    0,    0,    2 },  /* 296: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {    0,    0,    0,    0,    0,   74,    0,    6 },  /* 297: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  256,    0,    0,    0,    5,   75,    0,    6 },  /* 298: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  257,   43,    0,    0,    9,   76,    0,    9 },  /* 299: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  258,   44,    0,    0,    9,   77,    0,    9 },  /* 300: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  258,   44,    0,    0,    9,    0,    0,    9 },  /* 301: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  180,  180,    0,    0,    1,   78,    0,    1 },  /* 302: not used by a script */
    {  259,    0,    0,    0,    1,    0,    0,    1 },  /* 303: ATTACK 3 SP: EX 6(123)4+PP (routine Att_SENPUUKYAKU) */
    {  151,    0,    0,    0,    0,    0,    0,    7 },  /* 304: dmca 97 */
    {    0,    0,    0,   45,    1,   45,    0,    1 },  /* 305: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  190,    0,    0,   46,    1,   46,    0,    1 },  /* 306: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  191,    0,    0,   47,    1,   47,    0,    1 },  /* 307: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  172,    0,    0,   20,    3,   20,    0,    3 },  /* 308: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  173,  255,    0,   21,    3,   21,    0,    3 },  /* 309: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  174,  256,    0,   22,    3,   22,    0,    3 },  /* 310: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  176,  257,    0,   23,    3,   23,    0,    3 },  /* 311: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  179,  258,    0,   24,    5,   24,    0,    6 },  /* 312: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
};

const BODY_BOX elena_body_box[261] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -32,  22,  72,  19 },  {  -33,  57,  71,  10 },  {  -33,  57,  37,  33 },  {  -33,  64,   0,  36 } } },  /* 1: KAMAE, STAND UP, WALK END +81 */
    { { {  -23,  21,  84,  18 },  {  -28,  52,  72,  18 },  {  -29,  55,  40,  32 },  {  -31,  61,   0,  40 } } },  /* 2: FRONT WALK, BACK WALK, ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -32,  31,  41,  19 },  {  -16,  44,  41,  13 },  {  -36,  68,  23,  20 },  {  -42,  82,   0,  22 } } },  /* 3: KAGAMU, KAGAMI KAMAE, PARING DOWN +34 */
    { { {  -29,  51,  56,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +2 */
    { { {  -33,  55,  56,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: JUMP FRONT, S JUMP FRONT, PARING AIR F +19 */
    { { {  -17,  36,  61,  16 },  {  -21,  45,  51,  19 },  {  -23,  47,  34,  17 },  {  -19,  39,  25,  16 } } },  /* 6: AIR S, AIR M, AIR L +23 */
    { { {  -36,  30,  52,  18 },  {  -20,  45,  41,  23 },  {  -13,  46,  30,  23 },  {  -19,  54,   0,  32 } } },  /* 7: DASH HUMIKOMI */
    { { {  -49,  24,  62,  19 },  {  -32,  41,  53,  24 },  {  -26,  53,  32,  35 },  {  -22,  68,   0,  37 } } },  /* 8: DASH HUMIKOMI */
    { { {  -41,  26,  66,  17 },  {  -28,  39,  56,  21 },  {  -21,  42,  36,  33 },  {  -31,  69,   0,  36 } } },  /* 9: DASH HUMIKOMI, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -35,  28,  70,  17 },  {  -26,  44,  60,  19 },  {  -22,  49,  36,  30 },  {  -32,  70,   0,  36 } } },  /* 10: DASH HUMIKOMI */
    { { {  -54,  22,  64,  19 },  {  -36,  48,  68,  10 },  {  -38,  56,  37,  30 },  {  -36,  68,   0,  36 } } },  /* 11: follow-up of S PUNCH A, S PUNCH C +8, PIYO, WAIT */
    { { {  -32,  16,  80,  16 },  {  -16,  32,  72,  22 },  {  -28,  50,  46,  26 },  {    0,   0,   0,   0 } } },  /* 12: GUARD AIR */
    { { {    9,  28,  41,  19 },  {  -16,  33,  30,  22 },  {  -22,  48,  14,  27 },  {  -29,  67,   0,  27 } } },  /* 13: KAGAMI TURN */
    { { {  -19,  25,  48,  16 },  {  -27,  46,  36,  18 },  {  -30,  59,  22,  16 },  {  -32,  67,   0,  22 } } },  /* 14: KAGAMI TURN */
    { { {   14,  22,  53,  20 },  {  -10,  33,  48,  18 },  {  -27,  51,  35,  24 },  {  -29,  58,   0,  35 } } },  /* 15: HURIMUKI */
    { { {  -28,  23,  86,  15 },  {  -28,  45,  73,  17 },  {  -25,  51,  43,  30 },  {  -19,  48,   0,  43 } } },  /* 16: HURIMUKI */
    { { {  -37,  26,  73,  18 },  {  -25,  38,  64,  20 },  {  -23,  45,  40,  28 },  {  -26,  53,   0,  40 } } },  /* 17: HURIMUKI */
    { { {  -40,  27,  60,  23 },  {  -24,  38,  54,  23 },  {  -21,  42,  33,  27 },  {  -28,  53,   0,  40 } } },  /* 18: HURIMUKI */
    { { {  -37,  28,  41,  19 },  {  -28,  45,  31,  24 },  {  -20,  44,  18,  27 },  {  -40,  68,   0,  31 } } },  /* 19: KAGAMI P A */
    { { {  -38,  16,  40,  16 },  {  -28,  44,  28,  32 },  {  -68,  48,   0,  34 },  {  -20,  40,   0,  28 } } },  /* 20: not used by a script */
    { { {  -43,  24,  42,  17 },  {  -19,  31,  40,  17 },  {  -44,  58,  18,  24 },  {  -48,  67,   0,  24 } } },  /* 21: KAGAMI P A */
    { { {  -45,  28,  41,  19 },  {  -17,  36,  41,  15 },  {  -44,  66,  22,  19 },  {  -42,  67,   0,  24 } } },  /* 22: KAGAMI P A */
    { { {   30,  16,  44,  16 },  {    4,  48,  24,  32 },  {  -28,  32,  24,  22 },  {  -36,  88,   0,  24 } } },  /* 23: KAGAMI K A */
    { { {   44,  17,  32,  20 },  {  -13,  57,  24,  29 },  {  -45,  33,  25,  13 },  {  -36,  91,   0,  24 } } },  /* 24: KAGAMI K A */
    { { {   44,  17,  32,  20 },  {   14,  34,  24,  32 },  {  -28,  42,  24,  26 },  {  -40,  92,   0,  24 } } },  /* 25: KAGAMI K A */
    { { {   -6,  41,  42,  18 },  {    4,  44,  24,  28 },  {  -28,  32,  24,  24 },  {  -36,  88,   0,  24 } } },  /* 26: KAGAMI K A */
    { { {  -43,  20,  40,  18 },  {  -22,  37,  25,  36 },  {  -64,  44,   0,  32 },  {  -20,  40,   0,  24 } } },  /* 27: KAGAMI P A */
    { { {   -4,  16,  44,  16 },  {  -24,  48,  36,  20 },  {  -32,  66,  24,  12 },  {  -36,  80,   0,  24 } } },  /* 28: KAGAMI P A, KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    0,   0,   0,   0 },  {  -20,  48,  38,  20 },  {  -32,  72,  24,  16 },  {  -36,  88,   0,  24 } } },  /* 29: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {  -24,  60,  44,  20 },  {  -32,  72,  24,  20 },  {  -36,  88,   0,  24 } } },  /* 30: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {  -48,  83,  44,  24 },  {  -44,  90,  24,  20 },  {  -45,  97,   0,  24 } } },  /* 31: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {  -34,  71,  28,  34 },  {  -51,  57,  52,  39 },  {  -50,  99,   0,  33 } } },  /* 32: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {  -36,  64,  44,  26 },  {  -24,  68,  24,  20 },  {  -36,  88,   0,  24 } } },  /* 33: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {    8,  16,  40,  16 },  {   -2,  44,  24,  26 },  {  -30,  32,  24,  24 },  {  -40,  88,   0,  24 } } },  /* 34: KAGAMI K A */
    { { {   22,  16,  38,  16 },  {   -2,  40,  24,  28 },  {  -30,  32,  24,  24 },  {  -40,  88,   0,  24 } } },  /* 35: KAGAMI K A */
    { { {   40,  16,  32,  16 },  {    8,  36,  24,  30 },  {  -32,  40,  24,  24 },  {  -40,  88,   0,  24 } } },  /* 36: KAGAMI K A */
    { { {   44,  16,  32,  16 },  {    8,  40,  24,  34 },  {  -40,  48,  24,  28 },  {  -40,  88,   0,  24 } } },  /* 37: KAGAMI K A */
    { { {  -30,  23,  87,  18 },  {  -24,  48,  72,  27 },  {  -36,  64,  50,  27 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {   -6,  28,  92,  16 },  {  -36,  70,  72,  24 },  {  -49,  82,  43,  29 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {   -7,  28,  92,  16 },  {  -36,  70,  72,  24 },  {  -49,  82,  43,  29 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP P S A, F JUMP P S A, ATTACK 7 L: not started by a command */
    { { {   -2,  16,  79,  15 },  {    0,  32,  64,  17 },  {   -6,  36,  42,  22 },  {  -28,  54,   0,  42 } } },  /* 41: not used by a script */
    { { {  -11,  16,  79,  15 },  {  -14,  34,  66,  18 },  {   -6,  34,  38,  28 },  {  -12,  40,   0,  38 } } },  /* 42: not used by a script */
    { { {  -28,  16, 100,  16 },  {  -16,  28,  76,  32 },  {  -36,  44,  58,  26 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
    { { {  -30,  16, 100,  16 },  {  -26,  40,  84,  22 },  {  -26,  36,  44,  40 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -28,  16,  98,  16 },  {  -36,  48,  76,  24 },  {  -36,  44,  36,  40 },  {  -36,  54,   0,  36 } } },  /* 45: not used by a script */
    { { {  -28,  16,  80,  16 },  {  -18,  32,  68,  18 },  {  -16,  34,  36,  32 },  {  -30,  54,   0,  36 } } },  /* 46: not used by a script */
    { { {  -38,  16,  64,  16 },  {  -20,  32,  62,  18 },  {  -20,  32,  36,  26 },  {  -32,  54,   0,  36 } } },  /* 47: not used by a script */
    { { {  -38,  16,  46,  16 },  {  -22,  40,  46,  18 },  {  -24,  52,  24,  22 },  {  -36,  68,   0,  24 } } },  /* 48: follow-up of SP WIN 2 */
    { { {  -34,  16,  66,  16 },  {  -26,  40,  62,  18 },  {  -22,  44,  36,  24 },  {  -28,  52,   0,  36 } } },  /* 49: HUSHIN HEAD, HUSHIN DOWN, follow-up of SP WIN 2 +1 */
    { { {  -38,  16,  64,  16 },  {  -22,  36,  64,  18 },  {  -24,  40,  32,  32 },  {    0,   0,   0,   0 } } },  /* 50: PARING AIR F, PARING AIR B, P BREAK AIR F +1 */
    { { {  -30,  16,  72,  16 },  {  -18,  36,  66,  18 },  {  -28,  50,  29,  36 },  {    0,   0,   0,   0 } } },  /* 51: not used by a script */
    { { {    0,   0,   0,   0 },  {  -44,  72,  24,  22 },  {  -16,  66,  46,  24 },  {  -48,  80,   0,  24 } } },  /* 52: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -32,  54,  24,  22 },  {  -16,  48,  46,  43 },  {  -36,  72,   0,  24 } } },  /* 53: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -12,  52,  24,  22 },  {  -24,  64,  46,  43 },  {  -18,  72,   0,  24 } } },  /* 54: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), OKIAGARI P S */
    { { {  -46,  16,  60,  16 },  {  -36,  56,  50,  22 },  {  -32,  60,  30,  24 },  {  -32,  68,   0,  30 } } },  /* 55: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -16,  16,  56,  16 },  {  -30,  52,  44,  18 },  {  -30,  52,  28,  16 },  {  -36,  64,   0,  28 } } },  /* 56: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   24,  16,  52,  16 },  {  -20,  44,  52,  18 },  {  -28,  60,  32,  20 },  {  -28,  74,   0,  32 } } },  /* 57: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   32,  23,  36,  18 },  {    8,  28,  32,  32 },  {  -29,  50,  32,  40 },  {  -31,  75,   0,  36 } } },  /* 58: M PUNCH A */
    { { {   32,  21,  36,  17 },  {  -39,  71,  32,  31 },  {  -51,  41,  52,  37 },  {  -41,  83,   0,  32 } } },  /* 59: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   23,  16,  37,  23 },  {  -28,  52,  42,  22 },  {  -30,  60,  24,  18 },  {  -40,  80,   0,  24 } } },  /* 60: M PUNCH A */
    { { {  -17,  25,  60,  15 },  {  -28,  52,  42,  22 },  {  -30,  56,  24,  18 },  {  -40,  80,   0,  24 } } },  /* 61: M PUNCH A */
    { { {   -4,  25,  88,  16 },  {  -18,  48,  66,  22 },  {  -18,  50,  40,  26 },  {  -20,  52,   0,  40 } } },  /* 62: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -2,  27,  94,  14 },  {  -20,  52,  74,  20 },  {  -24,  48,  40,  34 },  {  -28,  52,   0,  40 } } },  /* 63: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -2,  24,  96,  16 },  {  -16,  44,  76,  20 },  {  -34,  54,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 64: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -5,  26,  96,  16 },  {  -63,  94,  70,  28 },  {  -24,  44,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 65: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    6,  24,  84,  18 },  {  -16,  48,  68,  22 },  {  -20,  48,  40,  28 },  {  -26,  64,   0,  40 } } },  /* 66: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -24,  24,  80,  16 },  {  -28,  55,  60,  20 },  {  -14,  50,  36,  26 },  {   -8,  48,   0,  36 } } },  /* 67: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -14,  24,  94,  16 },  {  -20,  48,  80,  20 },  {  -14,  46,  44,  36 },  {   -8,  48,   0,  44 } } },  /* 68: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -11,  24,  94,  16 },  {  -21,  49,  84,  18 },  {  -21,  43,  51,  34 },  {   -5,  28,   3,  48 } } },  /* 69: L KICK A, UP P GUARD P L, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -13,  25,  85,  16 },  {  -22,  51,  76,  20 },  {  -16,  40,  38,  38 },  {    0,   0,   0,   0 } } },  /* 70: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -13,  25,  85,  16 },  {  -22,  51,  76,  20 },  {  -16,  40,  38,  38 },  {    0,   0,   0,   0 } } },  /* 71: L KICK A, UP P GUARD P L */
    { { {  -31,  24,  84,  17 },  {  -26,  50,  70,  26 },  {  -28,  53,  34,  36 },  {    0,   0,   0,   0 } } },  /* 72: L KICK A, UP P GUARD P L */
    { { {  -44,  24,  80,  16 },  {  -34,  48,  70,  18 },  {  -36,  60,  40,  30 },  {  -36,  80,   0,  40 } } },  /* 73: L KICK A, UP P GUARD P L */
    { { {    4,  23,  82,  16 },  {  -12,  47,  60,  22 },  {  -14,  48,  36,  24 },  {  -22,  68,   0,  36 } } },  /* 74: S PUNCH A, UP P GUARD P S, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -5,  26,  86,  15 },  {  -49,  82,  61,  29 },  {  -23,  57,  36,  40 },  {  -21,  56,   0,  36 } } },  /* 75: S PUNCH A, UP P GUARD P S */
    { { {   -3,  25,  83,  16 },  {  -14,  50,  64,  18 },  {  -14,  48,  36,  28 },  {  -22,  60,   0,  36 } } },  /* 76: S PUNCH A, UP P GUARD P S */
    { { {   -9,  26,  80,  16 },  {  -14,  48,  60,  22 },  {  -14,  48,  32,  28 },  {  -22,  60,   0,  32 } } },  /* 77: S PUNCH A, UP P GUARD P S */
    { { {  -24,  22,  90,  16 },  {  -20,  40,  72,  22 },  {  -16,  40,  44,  32 },  {  -32,  64,   0,  44 } } },  /* 78: S KICK A, D P GUARD P S, FUSHIN P S +1 */
    { { {  -28,  24,  86,  16 },  {  -22,  42,  68,  24 },  {  -28,  56,  40,  32 },  {  -32,  60,   0,  40 } } },  /* 79: S KICK A, D P GUARD P S, FUSHIN P S +1 */
    { { {  -28,  16,  88,  16 },  {  -22,  44,  70,  22 },  {  -24,  52,  40,  32 },  {  -36,  64,   0,  40 } } },  /* 80: not used by a script */
    { { {  -38,  24,  80,  16 },  {  -22,  40,  64,  24 },  {  -26,  52,  40,  28 },  {  -30,  60,   0,  40 } } },  /* 81: S KICK A, D P GUARD P S */
    { { {   -8,  22,  57,  16 },  {  -18,  48,  46,  14 },  {  -26,  68,  30,  16 },  {  -44,  88,   0,  30 } } },  /* 82: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {    4,  16,  50,  16 },  {  -18,  52,  38,  18 },  {  -28,  72,  26,  12 },  {  -44,  96,   0,  26 } } },  /* 83: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {    8,  16,  42,  16 },  {   -2,  40,  24,  28 },  {  -28,  26,  24,  24 },  {  -50,  21,  25,  13 } } },  /* 84: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {   32,  16,  30,  16 },  {    6,  26,  28,  34 },  {  -32,  38,  28,  26 },  {  -24,  72,   0,  28 } } },  /* 85: not used by a script */
    { { {   36,  16,  28,  16 },  {   12,  24,  28,  32 },  {  -20,  32,  28,  30 },  {  -40,  88,   0,  28 } } },  /* 86: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {    0,   0,   0,   0 },  {   12,  40,  28,  26 },  {  -24,  36,  28,  32 },  {  -36,  88,   0,  28 } } },  /* 87: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  64,  32,  28 },  {  -40,  88,   0,  32 } } },  /* 88: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {  -50,  23,  56,  18 },  {  -34,  47,  50,  18 },  {  -32,  53,  28,  22 },  {  -36,  71,   0,  28 } } },  /* 89: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {  -58,  16,  46,  16 },  {  -42,  30,  40,  36 },  {  -12,  30,  40,  32 },  {  -38,  84,   0,  40 } } },  /* 90: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) */
    { { {    0,   0,   0,   0 },  {  -54,  32,  42,  40 },  {  -22,  40,  42,  46 },  {  -26,  40,   0,  42 } } },  /* 91: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -40,  56,  56,  14 },  {  -32,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -30,  46,  58,  14 },  {  -36,  56,  70,  24 },  {    0,   0,   0,   0 } } },  /* 93: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -16,  40,  58,  24 },  {  -36,  20,  58,  24 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -32,  40,  50,  32 },  {   -8,  24,  50,  32 },  {    0,   0,   0,   0 } } },  /* 95: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +5 */
    { { {  -39,  19,  49,  25 },  {  -20,  28,  42,  40 },  {    8,  32,  42,  44 },  {   -8,  40,   0,  42 } } },  /* 96: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -39,  18,  48,  22 },  {  -20,  28,  42,  40 },  {    8,  32,  42,  44 },  {   -8,  40,   0,  42 } } },  /* 97: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -38,  16,  54,  22 },  {  -20,  52,  60,  18 },  {  -18,  56,  36,  24 },  {  -16,  60,   0,  36 } } },  /* 98: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -26,  30,  71,  16 },  {  -20,  55,  60,  18 },  {  -18,  60,  36,  24 },  {  -16,  80,   0,  36 } } },  /* 99: not used by a script */
    { { {  -36,  16,  52,  16 },  {  -20,  40,  46,  18 },  {  -24,  52,  28,  18 },  {  -28,  68,   0,  28 } } },  /* 100: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  56,  32,  28 },  {  -40,  80,   0,  32 } } },  /* 101: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    2,  34,  28,  30 },  {  -34,  36,  28,  32 },  {  -66, 110,   0,  28 } } },  /* 102: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   20,  16,  28,  16 },  {   -8,  28,  28,  36 },  {  -54,  45,  28,  38 },  {  -66, 110,   0,  28 } } },  /* 103: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    4,  21,  40,  16 },  {  -14,  39,  28,  24 },  {  -58,  43,  28,  31 },  {  -66, 110,   0,  28 } } },  /* 104: M KICK A */
    { { {  -11,  27,  54,  17 },  {  -24,  50,  38,  22 },  {  -50,  78,  26,  18 },  {  -66, 110,   0,  26 } } },  /* 105: M KICK A, UP P GUARD P M */
    { { {  -14,  23,  70,  16 },  {  -24,  56,  50,  21 },  {  -33,  73,  26,  24 },  {  -53,  97,   0,  26 } } },  /* 106: M KICK A, UP P GUARD P M */
    { { {  -26,  25,  97,  16 },  {  -33,  53,  80,  22 },  {  -44,  63,  48,  31 },  {    0,   0,   0,   0 } } },  /* 107: V JUMP P S A, V JUMP P M A, V JUMP P L A +10 */
    { { {  -15,  26,  94,  16 },  {  -40,  70,  76,  22 },  {  -47,  70,  48,  29 },  {    0,   0,   0,   0 } } },  /* 108: V JUMP P M A, V JUMP P L A, V JUMP K S A +7 */
    { { {    2,  26,  94,  16 },  {  -24,  63,  78,  21 },  {  -40,  76,  46,  32 },  {    0,   0,   0,   0 } } },  /* 109: V JUMP P M A, F JUMP P M A */
    { { {  -14,  24,  96,  16 },  {  -28,  57,  76,  24 },  {  -40,  72,  48,  28 },  {    0,   0,   0,   0 } } },  /* 110: V JUMP P L A, F JUMP P L A */
    { { {   -8,  25,  94,  16 },  {  -20,  60,  76,  22 },  {  -24,  72,  46,  30 },  {    0,   0,   0,   0 } } },  /* 111: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    { { {  -11,  25,  96,  16 },  {  -28,  56,  76,  24 },  {  -28,  72,  48,  28 },  {    0,   0,   0,   0 } } },  /* 112: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    { { {   -4,  16,  94,  16 },  {  -28,  64,  76,  22 },  {  -40,  72,  48,  28 },  {    0,   0,   0,   0 } } },  /* 113: not used by a script */
    { { {   -6,  25,  94,  16 },  {  -28,  64,  76,  22 },  {  -75, 111,  45,  32 },  {    0,   0,   0,   0 } } },  /* 114: V JUMP K S A, F JUMP K S A */
    { { {    8,  24,  94,  16 },  {  -34,  77,  76,  22 },  {  -61,  92,  49,  32 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    { { {  -54,  16,  64,  16 },  {  -38,  32,  50,  44 },  {   -8,  56,  46,  40 },  {    0,   0,   0,   0 } } },  /* 116: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -34,  32,  34,  56 },  {   -2,  56,  52,  44 },  {    0,   0,   0,   0 } } },  /* 117: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -24,  56,  34,  32 },  {  -37,  72,  66,  39 },  {    0,   0,   0,   0 } } },  /* 118: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -27,  65,  34,  40 },  {  -33,  47,  69,  52 },  {    0,   0,   0,   0 } } },  /* 119: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -51,  85,  34,  40 },  {  -22,  48,  72,  33 },  {    0,   0,   0,   0 } } },  /* 120: V JUMP K L A, F JUMP K L A */
    { { {   32,  16,  52,  16 },  {    8,  24,  44,  42 },  {  -45,  52,  30,  56 },  {    0,   0,   0,   0 } } },  /* 121: V JUMP K L A, F JUMP K L A */
    { { {   -8,  25,  74,  16 },  {  -28,  60,  62,  21 },  {  -32,  72,  38,  24 },  {    0,   0,   0,   0 } } },  /* 122: V JUMP K L A, F JUMP K L A */
    { { {   14,  16,  40,  16 },  {  -24,  48,  38,  14 },  {  -32,  72,  24,  14 },  {  -40,  88,   0,  24 } } },  /* 123: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   40,  16,  30,  16 },  {    8,  32,  28,  28 },  {  -28,  36,  28,  28 },  {  -40,  88,   0,  28 } } },  /* 124: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   44,  16,  18,  16 },  {   12,  32,   0,  36 },  {   -8,  20,   0,  40 },  {    0,   0,   0,   0 } } },  /* 125: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   44,  16,  10,  16 },  {   12,  32,   0,  32 },  {   -8,  20,   0,  36 },  {  -92,  83,   0,  33 } } },  /* 126: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    4,  32,  24,  26 },  {  -36,  38,  24,  30 },  {  -85, 138,   0,  24 } } },  /* 127: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    8,  36,  24,  28 },  {  -32,  40,  24,  32 },  {  -69, 123,   0,  29 } } },  /* 128: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    8,  36,  24,  24 },  {  -32,  40,  24,  28 },  {  -36,  88,   0,  24 } } },  /* 129: KAGAMI K A */
    { { {   26,  16,  40,  16 },  {    8,  36,  24,  24 },  {  -24,  32,  24,  28 },  {  -32,  84,   0,  24 } } },  /* 130: KAGAMI K A */
    { { {   52,  16,   0,  16 },  {   24,  28,   0,  30 },  {  -24,  48,   0,  36 },  {    0,   0,   0,   0 } } },  /* 131: OKIAGARI P S */
    { { {   52,  16,   0,  16 },  {   24,  28,   0,  30 },  {  -24,  48,   0,  36 },  {    0,   0,   0,   0 } } },  /* 132: OKIAGARI P S */
    { { {   48,  16,   8,  16 },  {   24,  24,   0,  36 },  {  -24,  48,  24,  32 },  {  -24,  48,   0,  24 } } },  /* 133: OKIAGARI P S */
    { { {   36,  16,  16,  16 },  {    8,  28,  28,  22 },  {  -24,  32,  28,  22 },  {  -32,  56,   0,  24 } } },  /* 134: OKIAGARI P S */
    { { {   44,  16,  34,  16 },  {   16,  28,  28,  32 },  {  -16,  32,  28,  32 },  {  -32,  56,   0,  28 } } },  /* 135: OKIAGARI P S */
    { { {   30,  16,  40,  16 },  {   -2,  32,  28,  36 },  {  -30,  28,  28,  32 },  {  -32,  56,   0,  28 } } },  /* 136: OKIAGARI P S */
    { { {  -12,  16, 104,  16 },  {  -26,  40,  92,  18 },  {  -20,  34,  54,  38 },  {    0,   0,   0,   0 } } },  /* 137: UP P GUARD P L */
    { { {  -12,  16, 104,  16 },  {  -22,  40,  92,  18 },  {  -16,  34,  54,  38 },  {    0,   0,   0,   0 } } },  /* 138: UP P GUARD P L */
    { { {  -22,  16,  42,  16 },  {  -16,  40,  34,  20 },  {   -8,  40,  12,  24 },  {  -30,  56,   0,  22 } } },  /* 139: not used by a script */
    { { {  -22,  25,  86,  16 },  {  -24,  42,  66,  24 },  {  -26,  48,  40,  26 },  {  -30,  64,   0,  40 } } },  /* 140: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -26,  16,  80,  16 },  {  -22,  40,  62,  18 },  {  -18,  44,  36,  26 },  {  -18,  52,   0,  36 } } },  /* 141: UP P GUARD P L */
    { { {  -12,  16,  94,  16 },  {  -18,  40,  80,  16 },  {  -14,  44,  44,  36 },  {   -8,  52,   0,  44 } } },  /* 142: UP P GUARD P L */
    { { {  -22,  16,  52,  16 },  {  -24,  32,  40,  18 },  {  -24,  44,  24,  16 },  {  -32,  56,   0,  24 } } },  /* 143: DASH TOBINOKI */
    { { {    6,  16,  48,  16 },  {  -14,  32,  36,  18 },  {  -20,  44,  24,  16 },  {  -40,  56,   0,  24 } } },  /* 144: DASH TOBINOKI */
    { { {   28,  16,  22,  16 },  {    4,  24,  24,  24 },  {  -40,  44,  24,  20 },  {  -44,  64,   0,  24 } } },  /* 145: DASH TOBINOKI */
    { { {    0,   0,   0,   0 },  {  -22,  64,  24,  20 },  {  -52,  71,  27,  37 },  {  -22,  56,   0,  24 } } },  /* 146: DASH TOBINOKI */
    { { {    0,   0,   0,   0 },  {  -22,  48,  24,  20 },  {  -33,  52,  44,  30 },  {  -22,  56,   0,  24 } } },  /* 147: DASH TOBINOKI */
    { { {    0,   0,   0,   0 },  {  -26,  52,  24,  20 },  {  -16,  47,  44,  33 },  {  -30,  60,   0,  24 } } },  /* 148: DASH TOBINOKI */
    { { {    0,   0,   0,   0 },  {  -30,  24,  24,  28 },  {   -6,  34,  24,  38 },  {  -40,  72,   0,  24 } } },  /* 149: DASH TOBINOKI */
    { { {  -48,  16,  56,  16 },  {  -32,  40,  50,  16 },  {  -22,  42,  28,  26 },  {  -26,  58,   0,  28 } } },  /* 150: DASH TOBINOKI */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 151: dmca 97 */
    { { {   20,  16,  68,  16 },  {  -12,  40,  60,  18 },  {  -20,  44,  36,  24 },  {  -24,  52,   0,  36 } } },  /* 152: not used by a script */
    { { {   28,  16,  54,  16 },  {  -12,  40,  60,  18 },  {  -20,  44,  36,  24 },  {  -28,  56,   0,  36 } } },  /* 153: not used by a script */
    { { {   28,  16,  54,  16 },  {    2,  26,  36,  36 },  {  -24,  26,  36,  36 },  {  -36,  56,   0,  36 } } },  /* 154: not used by a script */
    { { {   28,  16,  54,  16 },  {    2,  26,  36,  36 },  {  -36,  38,  36,  36 },  {  -36,  56,   0,  36 } } },  /* 155: not used by a script */
    { { {    2,  16,  72,  16 },  {   -8,  36,  56,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 156: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  25 },  {  -22,  40,  30,  26 },  {    0,   0,   0,   0 } } },  /* 157: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    0,  30,  86,  16 },  {  -66,  95,  41,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 158: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {   28,  16,  82,  16 },  {  -14,  48,  68,  22 },  {  -28,  54,  32,  36 },  {    0,   0,   0,   0 } } },  /* 159: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {   36,  16,  50,  16 },  {    8,  31,  52,  36 },  {  -22,  30,  42,  44 },  {    0,   0,   0,   0 } } },  /* 160: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {    0,   0,   0,   0 },  {  -26,  50,  40,  24 },  {  -26,  50,  64,  24 },  {    0,   0,   0,   0 } } },  /* 161: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -48,  23,  46,  16 },  {  -40,  30,  52,  29 },  {  -13,  35,  38,  47 },  {    0,   0,   0,   0 } } },  /* 162: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -64,  16,  50,  16 },  {  -48,  32,  40,  40 },  {  -16,  32,  40,  48 },  {  -28,  40,   0,  40 } } },  /* 163: follow-up of APPEAR JUNBI 7, follow-up of SP WIN 6, follow-up of SP WIN 7 */
    { { {    4,  16,  82,  16 },  {  -12,  40,  68,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 164: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {    6,  16,  82,  16 },  {   -4,  36,  66,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 165: S PUNCH C, ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    { { {   12,  16,  78,  16 },  {    2,  32,  64,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 166: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   16,  16,  74,  16 },  {    2,  32,  60,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 167: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -10,  16,  82,  16 },  {  -18,  40,  68,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 168: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {  -20,  16,  84,  16 },  {  -22,  36,  68,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 169: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {  -16,  16,  88,  16 },  {  -22,  36,  72,  18 },  {  -18,  38,  36,  36 },  {  -24,  52,   0,  36 } } },  /* 170: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {   -8,  16,  86,  16 },  {  -18,  34,  72,  18 },  {  -18,  38,  36,  36 },  {  -24,  52,   0,  36 } } },  /* 171: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -2,  16,  92,  16 },  {  -14,  40,  80,  18 },  {  -14,  36,  52,  28 },  {    0,   0,   0,   0 } } },  /* 172: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -2,  16,  92,  16 },  {  -14,  40,  80,  18 },  {  -14,  36,  52,  28 },  {    0,   0,   0,   0 } } },  /* 173: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -2,  16,  92,  16 },  {  -18,  40,  84,  18 },  {  -48,  64,  68,  16 },  {    0,   0,   0,   0 } } },  /* 174: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU), ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) +1 */
    { { {   10,  16,  88,  16 },  {  -18,  40,  84,  18 },  {  -83, 103,  70,  21 },  {    0,   0,   0,   0 } } },  /* 175: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   18,  16,  84,  16 },  {   -2,  24,  66,  28 },  {  -85, 106,  62,  20 },  {    0,   0,   0,   0 } } },  /* 176: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   28,  16,  70,  16 },  {    2,  26,  64,  28 },  {  -51,  50,  50,  53 },  {    0,   0,   0,   0 } } },  /* 177: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   32,  16,  56,  16 },  {    4,  28,  40,  40 },  {  -35,  38,  41,  47 },  {    0,   0,   0,   0 } } },  /* 178: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   32,  16,  56,  16 },  {  -34,  67,  25,  58 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 179: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   24,  23,  46,  22 },  {  -10,  34,  18,  50 },  {  -71,  60,  31,  37 },  {    0,   0,   0,   0 } } },  /* 180: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -11,  36,  72,  16 },  {  -23,  47,  56,  18 },  {  -34,  59,  11,  44 },  {    0,   0,   0,   0 } } },  /* 181: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  18 },  {  -22,  40,  30,  26 },  {    0,   0,   0,   0 } } },  /* 182: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   14,  16,  86,  16 },  {  -22,  50,  68,  22 },  {  -18,  40,  32,  36 },  {    0,   0,   0,   0 } } },  /* 183: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   28,  16,  82,  16 },  {  -14,  48,  68,  22 },  {  -28,  54,  32,  36 },  {    0,   0,   0,   0 } } },  /* 184: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  50,   0,  28 },  {    0,   0,   0,   0 } } },  /* 185: ATTACK 7 M: not started by a command, SP APPEAR 1 */
    { { {   38,  16,  46,  16 },  {    8,  30,  40,  36 },  {  -22,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 186: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   38,  16,  46,  16 },  {    8,  30,  40,  36 },  {  -22,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 187: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   38,  16,  46,  16 },  {   24,  30,  40,  36 },  {  -14,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 188: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   38,  16,  46,  16 },  {   24,  30,  40,  36 },  {  -14,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 189: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   20,  32,  40,  40 },  {  -12,  32,  40,  46 },  {    0,   0,   0,   0 } } },  /* 190: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 191: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 192: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 193: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 194: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 195: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -28,  40,  48,  35 },  {   12,  20,  44,  35 },  {    0,   0,   0,   0 } } },  /* 196: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -28,  40,  48,  35 },  {   12,  20,  44,  35 },  {    0,   0,   0,   0 } } },  /* 197: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 198: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 199: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 200: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 201: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -30,  16,  66,  16 },  {  -20,  40,  54,  18 },  {  -16,  48,  36,  24 },  {  -16,  56,   0,  36 } } },  /* 202: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -30,  16,  66,  16 },  {  -20,  40,  54,  18 },  {  -16,  48,  36,  24 },  {  -16,  56,   0,  36 } } },  /* 203: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    6,  16,  80,  16 },  {  -14,  40,  62,  18 },  {  -18,  48,  36,  26 },  {  -28,  56,   0,  36 } } },  /* 204: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   32,  21,  36,  17 },  {   -8,  40,  32,  31 },  {  -39,  31,  32,  57 },  {  -41,  83,   0,  32 } } },  /* 205: not used by a script */
    { { {   44,  16,  18,  16 },  {   12,  32,   0,  36 },  {   -8,  20,   0,  40 },  {  -32,  24,   0,  24 } } },  /* 206: D P GUARD P M */
    { { {   -7,  25,  96,  16 },  {  -16,  45,  76,  22 },  {  -24,  44,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 207: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -6,  26,  94,  16 },  {  -25,  56,  76,  21 },  {  -24,  44,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 208: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -43,  20,  42,  16 },  {  -22,  34,  40,  20 },  {  -45,  59,  21,  19 },  {  -48,  64,   0,  26 } } },  /* 209: KAGAMI P A */
    { { {  -43,  20,  39,  17 },  {  -22,  34,  35,  23 },  {  -79,  56,   0,  39 },  {  -23,  41,   0,  35 } } },  /* 210: KAGAMI P A */
    { { {   44,  16,  32,  16 },  {    8,  40,  24,  36 },  {  -40,  48,  24,  28 },  {  -40,  88,   0,  24 } } },  /* 211: KAGAMI K A */
    { { {   32,  21,  36,  17 },  {  -39,  71,  32,  31 },  {  -51,  42,  52,  26 },  {  -41,  83,   0,  32 } } },  /* 212: M PUNCH A */
    { { {  -22,  24,  84,  16 },  {  -28,  54,  72,  24 },  {  -57,  83,  50,  24 },  {    0,   0,   0,   0 } } },  /* 213: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -28,  24,  84,  16 },  {  -33,  58,  78,  20 },  {  -41,  65,  50,  28 },  {    0,   0,   0,   0 } } },  /* 214: L KICK A */
    { { {   -5,  22,  41,  16 },  {  -14,  36,  28,  24 },  {  -56,  42,  28,  26 },  {  -66, 110,   0,  28 } } },  /* 215: M KICK A */
    { { {   -2,  16,  72,  16 },  {   -8,  36,  56,  18 },  {  -44,  68,  14,  41 },  {    0,   0,   0,   0 } } },  /* 216: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  18 },  {  -36,  49,   0,  56 },  {    0,   0,   0,   0 } } },  /* 217: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {   13,  16,  85,  11 },  {  -34,  63,  68,  17 },  {  -34,  58,  32,  36 },  {    0,   0,   0,   0 } } },  /* 218: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {  -11,  36,  72,  16 },  {  -23,  47,  56,  18 },  {  -36,  61,  11,  50 },  {    0,   0,   0,   0 } } },  /* 219: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  18 },  {  -22,  40,  30,  26 },  {    0,   0,   0,   0 } } },  /* 220: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {   14,  16,  86,  16 },  {  -22,  50,  68,  22 },  {  -18,  40,  32,  36 },  {    0,   0,   0,   0 } } },  /* 221: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -27,  65,  34,  40 },  {  -32,  44,  68,  56 },  {    0,   0,   0,   0 } } },  /* 222: not used by a script */
    { { {   -2,  16,  88,  16 },  {  -25,  58,  72,  21 },  {  -43,  74,  53,  26 },  {  -21,  49,   0,  54 } } },  /* 223: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  84,   0,  59 },  {    0,   0,   0,   0 } } },  /* 224: ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
    { { {  -26,  29,  67,  17 },  {  -41,  58,  64,  12 },  {  -46,  72,  38,  26 },  {  -53, 106,   0,  38 } } },  /* 225: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -38,  26,  43,  20 },  {  -44,  61,  41,  19 },  {  -44,  77,  35,  17 },  {  -50, 100,   0,  35 } } },  /* 226: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -20,  22,  31,  19 },  {  -24,  57,  39,  10 },  {  -34,  72,  31,  26 },  {  -47,  97,   0,  31 } } },  /* 227: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {    3,  22,  27,  19 },  {  -12,  57,  37,  10 },  {  -22,  64,  37,  23 },  {  -47,  97,   0,  37 } } },  /* 228: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   16,  22,  32,  19 },  {   -9,  55,  44,  15 },  {  -25,  64,  44,  25 },  {  -47,  95,   0,  44 } } },  /* 229: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   10,  22,  34,  19 },  {  -10,  44,  42,  17 },  {  -43,  74,  43,  31 },  {  -50,  90,   0,  43 } } },  /* 230: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   -5,  23,  43,  21 },  {  -15,  26,  40,  32 },  {  -50,  35,  43,  37 },  {  -50,  76,   0,  43 } } },  /* 231: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -11,  22,  42,  29 },  {  -27,  27,  42,  35 },  {  -65,  38,  41,  42 },  {  -50,  76,   0,  41 } } },  /* 232: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -34,  27,  62,  19 },  {  -34,  36,  46,  29 },  {  -54,  20,  46,  32 },  {  -53,  79,   0,  46 } } },  /* 233: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -50,  36,  64,  17 },  {  -53,  55,  57,  18 },  {  -54,  74,  44,  19 },  {  -55,  90,   0,  44 } } },  /* 234: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -56,  34,  62,  15 },  {  -53,  50,  56,  16 },  {  -55,  77,  42,  20 },  {  -55,  99,   0,  42 } } },  /* 235: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +5 */
    { { {  -48,  20,  45,  20 },  {  -28,  47,  45,  17 },  {  -49,  81,  32,  13 },  {  -50,  93,   0,  33 } } },  /* 236: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -54,  22,  42,  19 },  {  -41,  38,  40,  22 },  {  -21,  36,  37,  19 },  {  -55, 109,   0,  42 } } },  /* 237: not used by a script */
    { { {  -23,  22,  33,  19 },  {  -24,  38,  37,  22 },  {   -3,  27,  40,  19 },  {  -45,  93,   0,  38 } } },  /* 238: not used by a script */
    { { {  -52,  22,  53,  20 },  {  -33,  42,  41,  31 },  {   -3,  34,  41,  25 },  {  -49, 107,   0,  41 } } },  /* 239: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -32,  66,  39,  28 },  {    0,   0,   0,   0 },  {  -48, 104,   0,  39 } } },  /* 240: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -49,  74,  37,  24 },  {  -47,  93,   0,  37 } } },  /* 241: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -59,  45,  60,  19 },  {  -57,  67,  37,  23 },  {  -49,  74,   0,  37 } } },  /* 242: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -86,  58,  46,  35 },  {  -67,  74,  26,  33 },  {  -52,  77,   0,  37 } } },  /* 243: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  74,  26,  33 },  {  -52,  77,   0,  37 } } },  /* 244: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  74,  26,  33 },  {  -52,  77,   0,  37 } } },  /* 245: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  74,  29,  37 },  {  -52,  77,   0,  37 } } },  /* 246: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -65,  73,  32,  35 },  {  -50,  75,   0,  37 } } },  /* 247: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  76,  37,  36 },  {  -42,  75,   0,  37 } } },  /* 248: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -50,  58,  51,  31 },  {  -40,  64,  37,  25 },  {  -34,  74,   0,  37 } } },  /* 249: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -41,  66,  59,  24 },  {  -32,  68,  37,  25 },  {  -25,  72,   0,  37 } } },  /* 250: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -17,  30,  68,  21 },  {  -14,  51,  60,  24 },  {   -8,  57,  37,  31 },  {   -5,  67,   0,  37 } } },  /* 251: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -24,  25,  57,  23 },  {    1,  32,  52,  23 },  {  -10,  53,  37,  20 },  {  -11,  63,   0,  37 } } },  /* 252: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -29,  24,  54,  24 },  {   -5,  39,  47,  27 },  {  -23,  67,  38,  17 },  {  -28,  80,   0,  38 } } },  /* 253: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -37,  19,  59,  23 },  {  -19,  47,  51,  26 },  {  -31,  65,  38,  21 },  {  -33,  78,   0,  38 } } },  /* 254: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    2,  18,  70,  16 },  {  -12,  50,  58,  18 },  {  -36,  48,  32,  28 },  {    0,   0,   0,   0 } } },  /* 255: not used by a script */
    { { {    6,  18,  74,  16 },  {  -10,  50,  54,  24 },  {  -50,  54,  40,  30 },  {  -32,  36,  10,  28 } } },  /* 256: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {   14,  18,  86,  16 },  {   -8,  36,  74,  18 },  {  -22,  40,  56,  24 },  {  -30,  36,  16,  38 } } },  /* 257: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {   26,  18,  82,  16 },  {   -6,  40,  74,  18 },  {  -16,  42,  58,  22 },  {  -38,  34,  16,  40 } } },  /* 258: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -58,  16,  46,  16 },  {  -42,  30,  40,  36 },  {  -12,  30,  40,  32 },  {    0,   0,   0,   0 } } },  /* 259: ATTACK 3 SP: EX 6(123)4+PP (routine Att_SENPUUKYAKU) */
    { { {   -7,  28,  92,  16 },  {  -36,  70,  72,  24 },  {  -36,  70,  46,  26 },  {    0,   0,   0,   0 } } },  /* 260: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
};

const HAND_BOX elena_hand_box[259] = {
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
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: no box */
    { { { -108,  84,  32,  18 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: no box */
    { { {  -92,  56,   0,  24 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: no box */
    { { { -100,  82,  32,  22 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {  -79,  49,  76,  30 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {  -68,  35,  58,  21 },  {    0,   0,   0,   0 } } },  /* 33: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: no box */
    { { {  -89,  49,  24,  29 },  {    0,   0,   0,   0 } } },  /* 37: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { { -104,  72,   0,  40 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    { { {  -16,  18, 112,  32 },  {    0,   0,   0,   0 } } },  /* 42: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    { { {  -72,  42,  56,  40 },  {    0,   0,   0,   0 } } },  /* 43: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -56,  48,  68,  52 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: no box */
    { { {  -84,  72,  51,  30 },  {    0,   0,   0,   0 } } },  /* 54: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {  -38,  37,  59,  29 },  {    0,   0,   0,   0 } } },  /* 58: M PUNCH A */
    { { {  -77,  42,  78,  29 },  {    0,   0,   0,   0 } } },  /* 59: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {  -79,  30,  86,  22 },  {    0,   0,   0,   0 } } },  /* 65: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: no box */
    { { {  -63,  62,  57,  24 },  {    0,   0,   0,   0 } } },  /* 70: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -73,  65,  54,  28 },  {    0,   0,   0,   0 } } },  /* 71: L KICK A, UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {  -69,  41,  77,  23 },  {    0,   0,   0,   0 } } },  /* 75: S PUNCH A, UP P GUARD P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {  -62,  30,   0,  40 },  {    0,   0,   0,   0 } } },  /* 79: S KICK A, D P GUARD P S, FUSHIN P S +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {  -88, 142,   0,  29 },  {    0,   0,   0,   0 } } },  /* 84: L KICK C, KAGAMI K C, D P GUARD P M */
    { { {  -48,  24,   0,  36 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {  -20,  20,  80,  24 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {   40,  40,  86,  12 },  {    0,   0,   0,   0 } } },  /* 96: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {   40,  48,  56,  16 },  {    0,   0,   0,   0 } } },  /* 97: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {   36,  49,  46,  21 },  {    0,   0,   0,   0 } } },  /* 98: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: no box */
    { { {  -97,  41,  49,  24 },  {    0,   0,   0,   0 } } },  /* 103: M KICK A, UP P GUARD P M, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -95,  43,  48,  21 },  {    0,   0,   0,   0 } } },  /* 104: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: no box */
    { { {  -94,  68,  65,  21 },  {    0,   0,   0,   0 } } },  /* 109: V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: no box */
    { { {  -84,  55,  47,  25 },  {    0,   0,   0,   0 } } },  /* 112: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: no box */
    { { { -101,  60,  41,  26 },  {    0,   0,   0,   0 } } },  /* 114: V JUMP K S A, F JUMP K S A */
    { { {  -87,  42,  45,  26 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: no box */
    { { {  -80,  62,  45,  34 },  {    0,   0,   0,   0 } } },  /* 119: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: no box */
    { { {  -90,  82,   0,  41 },  {    0,   0,   0,   0 } } },  /* 125: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 126: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 127: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: no box */
    { { {  -24,  24,  36,  48 },  {    0,   0,   0,   0 } } },  /* 132: OKIAGARI P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 133: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 135: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 136: no box */
    { { {  -48,  22,  94,  40 },  {    0,   0,   0,   0 } } },  /* 137: UP P GUARD P L */
    { { {  -82,  58,  72,  40 },  {    0,   0,   0,   0 } } },  /* 138: UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 139: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 140: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 141: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 142: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 143: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 144: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 145: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 146: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 147: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 148: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 149: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 150: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 151: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 152: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 153: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 154: no box */
    { { {  -72,  36,  36,  28 },  {    0,   0,   0,   0 } } },  /* 155: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 156: no box */
    { { {  -51,  27,  30,  51 },  {    0,   0,   0,   0 } } },  /* 157: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -80,  63,  76,  19 },  {    0,   0,   0,   0 } } },  /* 158: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -24,  48,  84,  16 },  {    0,   0,   0,   0 } } },  /* 159: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 160: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 161: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 162: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 163: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 164: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 165: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 166: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 167: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 168: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 169: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 170: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 171: no box */
    { { {  -28,  14,  80,  48 },  {    0,   0,   0,   0 } } },  /* 172: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -67,  53,  73,  39 },  {    0,   0,   0,   0 } } },  /* 173: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -84,  63,  74,  30 },  {    0,   0,   0,   0 } } },  /* 174: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU), ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 175: no box */
    { { {  -30,  26,  85,  57 },  {    0,   0,   0,   0 } } },  /* 176: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 177: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 178: no box */
    { { {  -96,  76,  58,  31 },  {    0,   0,   0,   0 } } },  /* 179: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 180: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 181: no box */
    { { {  -34,  12,  30,  32 },  {    0,   0,   0,   0 } } },  /* 182: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -66,  44,  64,  20 },  {    0,   0,   0,   0 } } },  /* 183: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -42,  67,  85,  22 },  {    0,   0,   0,   0 } } },  /* 184: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 185: no box */
    { { {  -38,  33,   0,  46 },  {    0,   0,   0,   0 } } },  /* 186: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -38,  33,   0,  46 },  {    0,   0,   0,   0 } } },  /* 187: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -50,  37,  49,  13 },  {    0,   0,   0,   0 } } },  /* 188: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -53,  39,  59,  12 },  {    0,   0,   0,   0 } } },  /* 189: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -63,  52,  77,  13 },  {    0,   0,   0,   0 } } },  /* 190: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -44,  39,  89,  21 },  {    0,   0,   0,   0 } } },  /* 191: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 192: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 193: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 194: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 195: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 196: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 197: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 198: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 199: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 200: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 201: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 202: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 203: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 204: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 205: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 206: no box */
    { { {  -81,  71,  63,  26 },  {    0,   0,   0,   0 } } },  /* 207: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -61,  36,  88,  24 },  {    0,   0,   0,   0 } } },  /* 208: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { { -101,  64,  27,  24 },  {    0,   0,   0,   0 } } },  /* 209: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 210: no box */
    { { { -108,  68,  23,  30 },  {    0,   0,   0,   0 } } },  /* 211: KAGAMI K A */
    { { {  -82,  40,  66,  21 },  {    0,   0,   0,   0 } } },  /* 212: M PUNCH A */
    { { {  -76,  48,  40,  23 },  {    0,   0,   0,   0 } } },  /* 213: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -55,  30,  31,  31 },  {    0,   0,   0,   0 } } },  /* 214: L KICK A */
    { { {  -85,  42,  41,  17 },  {    0,   0,   0,   0 } } },  /* 215: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 216: no box */
    { { {  -41,  18,  29,  38 },  {    0,   0,   0,   0 } } },  /* 217: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {  -74,  55,  49,  32 },  {    0,   0,   0,   0 } } },  /* 218: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 219: no box */
    { { {  -52,  31,  32,  40 },  {    0,   0,   0,   0 } } },  /* 220: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {  -77,  53,  55,  36 },  {    0,   0,   0,   0 } } },  /* 221: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {  -92,  68,  48,  36 },  {    0,   0,   0,   0 } } },  /* 222: not used by a script */
    { { {  -67,  41,  74,  24 },  {    0,   0,   0,   0 } } },  /* 223: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 224: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 225: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 226: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 227: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 228: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 229: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 230: no box */
    { { { -106,  56,  48,  41 },  {    0,   0,   0,   0 } } },  /* 231: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { { -118,  52,  52,  38 },  {    0,   0,   0,   0 } } },  /* 232: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 233: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 234: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 235: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 236: no box */
    { { {  -46,  24,  62,  23 },  {    0,   0,   0,   0 } } },  /* 237: not used by a script */
    { { {  -69,  45,  58,  26 },  {    0,   0,   0,   0 } } },  /* 238: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 239: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 240: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 241: no box */
    { { { -103,  44,  53,  35 },  {    0,   0,   0,   0 } } },  /* 242: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -148,  61,  50,  40 },  {    0,   0,   0,   0 } } },  /* 243: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -138,  61,  50,  35 },  {  -76,  49,  42,  36 } } },  /* 244: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -134,  62,  41,  35 },  {  -72,  51,  36,  36 } } },  /* 245: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -134,  66,  41,  35 },  {    0,   0,   0,   0 } } },  /* 246: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -128,  85,  41,  35 },  {    0,   0,   0,   0 } } },  /* 247: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 248: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 249: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 250: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 251: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 252: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 253: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 254: no box */
    { { {  -55,  42,  73,  37 },  {    0,   0,   0,   0 } } },  /* 255: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -63,  44,  74,  30 },  {    0,   0,   0,   0 } } },  /* 256: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -12,   9,  85,  51 },  {    0,   0,   0,   0 } } },  /* 257: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -81,  62,  58,  31 },  {    0,   0,   0,   0 } } },  /* 258: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
};

const HOSEI_BOX elena_hos_box[10] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   77 } },  /* 1: KAMAE, STAND UP, WALK END +113 */
    { {  -25,   50,    0,   49 } },  /* 2: KAGAMU, KAGAMI KAMAE, PARING DOWN +55 */
    { {  -23,   46,   56,   44 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +36 */
    { {  -25,   50,    0,   36 } },  /* 4: TATAKI S, TATAKI V. S, KGM TATAKI S +21 */
    { {  -31,   62,    0,   67 } },  /* 5: DASH HUMIKOMI */
    { {  -23,   46,   28,   44 } },  /* 6: AIR S, AIR M, AIR L +37 */
    { {  -25,   50,    0,   30 } },  /* 7: NEKOROBI S, dmca 96, dmca 97 */
    { {  -25,   50,   56,   41 } },  /* 8: L KICK A, UP P GUARD P L, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { {  -23,   46,   38,   44 } },  /* 9: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +6 */
};
