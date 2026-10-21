/*
 * ORO_HITBOX.C  Oro's hit boxes
 *
 * Each of Oro's animation frames names an entry of oro_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX oro_hit_ix_table[179] = {
    /* boix  haix  free  caix  cuix  atix  eaix  hoix */
    {    0,    0,    0,    0,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +21 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +103 */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 2: FRONT WALK, BACK WALK */
    {    3,    3,    0,    0,    1,    0,    0,    1 },  /* 3: DASH HUMIKOMI */
    {   10,   10,    0,    0,    2,    0,    0,    2 },  /* 4: DASH HUMIKOMI */
    {    5,    5,    0,    0,    2,    0,    0,   19 },  /* 5: DASH HUMIKOMI, P BREAK ZUJOU, TUKAMIHAZUSI */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 6: DASH HUMIKOMI, P BREAK ZUJOU, TUKAMIHAZUSI */
    {    7,    7,    0,    0,    1,    0,    0,    1 },  /* 7: DASH TOBINOKI */
    {    8,    8,    0,    0,    1,    0,    0,   13 },  /* 8: DASH TOBINOKI */
    {   10,   10,    0,    0,    1,    0,    0,    3 },  /* 9: DASH TOBINOKI */
    {   10,   10,    0,    0,    3,    0,    0,    3 },  /* 10: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +24 */
    {   10,   10,    0,    0,    3,    0,    0,    3 },  /* 11: KAGAMI TURN */
    {   12,   12,    0,    0,    4,    0,    0,    4 },  /* 12: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    {   13,   13,    0,    0,    4,    0,    0,    4 },  /* 13: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    {   14,   14,    0,    0,    4,    0,    0,    4 },  /* 14: JUMP FRONT, JUMP BACK, S JUMP FRONT +11 */
    {   15,   15,    0,    0,    4,    0,    0,    4 },  /* 15: JUMP JUNBI, SP JUMP JUNBI, JUMP VERTICAL +12 */
    {   16,   16,    0,    1,    1,    1,    0,    1 },  /* 16: nmca 33, S PUNCH A */
    {   16,   16,    0,    0,    1,    0,    0,    1 },  /* 17: S PUNCH A */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 18: S PUNCH A */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 19: S PUNCH B */
    {   19,   19,    0,    2,    1,    2,    0,    1 },  /* 20: S PUNCH B */
    {   19,   19,    0,    0,    1,    0,    0,    1 },  /* 21: S PUNCH B */
    {   20,   20,    0,    0,    1,    0,    0,    1 },  /* 22: not used by a script */
    {   21,   21,    0,    3,    1,    3,    0,    1 },  /* 23: not used by a script */
    {   21,   21,    0,    0,    1,    0,    0,    1 },  /* 24: not used by a script */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 25: M PUNCH B */
    {   23,   23,    0,    4,    1,    4,    0,    1 },  /* 26: not used by a script */
    {   24,   24,    0,    4,    1,    4,    0,    1 },  /* 27: M PUNCH B */
    {   24,   24,    0,    0,    1,    0,    0,    1 },  /* 28: M PUNCH B */
    {   25,   25,    0,    0,    1,    0,    0,    1 },  /* 29: CATCH 6, M PUNCH B */
    {    1,    1,    0,    6,    1,    6,    0,    1 },  /* 30: not used by a script */
    {   27,   27,    0,    5,    1,    5,    0,    1 },  /* 31: M PUNCH A */
    {   28,   28,    0,    6,    1,    6,    0,    1 },  /* 32: M PUNCH A */
    {   29,   29,    0,    0,    1,    0,    0,    1 },  /* 33: M PUNCH A */
    {   30,   30,    0,    0,    1,    0,    0,    1 },  /* 34: M PUNCH A */
    {    1,    1,    0,    0,    1,    0,    0,    1 },  /* 35: M PUNCH A */
    {   32,   32,    0,    0,    1,    0,    0,    1 },  /* 36: L PUNCH A, UP P GUARD P L */
    {   33,   33,    0,    0,    1,    0,    0,    1 },  /* 37: L PUNCH A, UP P GUARD P L */
    {   34,   34,    0,    0,    1,    0,    0,    1 },  /* 38: L PUNCH A, UP P GUARD P L */
    {   35,   35,    0,    7,    1,    7,    0,    1 },  /* 39: L PUNCH A, UP P GUARD P L */
    {   36,   36,    0,    8,    1,    8,    0,    1 },  /* 40: L PUNCH A, UP P GUARD P L */
    {   36,   36,    0,    0,    1,    0,    0,    1 },  /* 41: L PUNCH A, UP P GUARD P L */
    {   37,   37,    0,    0,    1,    0,    0,    1 },  /* 42: L PUNCH A, UP P GUARD P L */
    {   38,   38,    0,    0,    1,    0,    0,    1 },  /* 43: S KICK A */
    {   40,   40,    0,    9,    1,    9,    0,    1 },  /* 44: S KICK A */
    {   40,   40,    0,    0,    1,    0,    0,    1 },  /* 45: S KICK A */
    {   39,   39,    0,    0,    1,    0,    0,    1 },  /* 46: S KICK A */
    {   41,   41,    0,    0,    1,    0,    0,    1 },  /* 47: S KICK B */
    {   42,   42,    0,   10,    1,   10,    0,    1 },  /* 48: S KICK B */
    {   42,   42,    0,    0,    1,    0,    0,    1 },  /* 49: S KICK B */
    {   43,   43,    0,    0,    1,    0,    0,    1 },  /* 50: S KICK B */
    {   44,   44,    0,    0,    1,    0,    0,    1 },  /* 51: M KICK A */
    {   46,   46,    0,   11,    1,   11,    0,    1 },  /* 52: M KICK A */
    {   46,   46,    0,    0,    1,    0,    0,    1 },  /* 53: M KICK A */
    {   47,   47,    0,    0,    1,    0,    0,    1 },  /* 54: M KICK A */
    {   48,   48,    0,    0,    6,    0,    0,    1 },  /* 55: M KICK B, UP P GUARD K S */
    {   49,   49,    0,   12,    6,   12,    0,    1 },  /* 56: UP P GUARD K S */
    {   50,   50,    0,   51,    6,   51,    0,    1 },  /* 57: M KICK B, UP P GUARD K S */
    {   50,   50,    0,    0,    6,    0,    0,    1 },  /* 58: M KICK B, UP P GUARD K S */
    {   51,   51,    0,    0,    6,    0,    0,    1 },  /* 59: M KICK B, UP P GUARD K S */
    {   52,   52,    0,    0,    1,    0,    0,    1 },  /* 60: M KICK B, UP P GUARD K S */
    {   53,   53,    0,    0,    1,    0,    0,    1 },  /* 61: L KICK A */
    {   54,   54,    0,   13,    1,   13,    0,    1 },  /* 62: L KICK A */
    {   55,   55,    0,   52,    1,   52,    0,    1 },  /* 63: not used by a script */
    {   55,   55,    0,    0,    1,    0,    0,    1 },  /* 64: L KICK A */
    {   57,   57,    0,    0,    1,    0,    0,    1 },  /* 65: L KICK A */
    {   58,   58,    0,    0,   11,    0,    0,    3 },  /* 66: KAGAMI P A */
    {   59,   59,    0,   14,   11,   14,    0,    3 },  /* 67: KAGAMI P A */
    {   59,   59,    0,    0,   11,    0,    0,    3 },  /* 68: KAGAMI P A */
    {   60,   60,    0,    0,    3,    0,    0,    3 },  /* 69: KAGAMI P A */
    {   61,   61,    0,   15,    3,   15,    0,    3 },  /* 70: KAGAMI P A */
    {   62,   62,    0,   16,    3,   16,    0,    3 },  /* 71: KAGAMI P A */
    {   60,   60,    0,    0,    3,    0,    0,    3 },  /* 72: KAGAMI P A */
    {   63,   63,    0,    0,    3,    0,    0,    3 },  /* 73: KAGAMI P A */
    {   64,   64,    0,    0,    3,    0,    0,    3 },  /* 74: TOUKETSU A, KAGAMI P A */
    {   65,   65,    0,    0,    3,    0,    0,    3 },  /* 75: KAGAMI K A */
    {   66,   66,    0,   18,   11,   18,    0,    3 },  /* 76: KAGAMI K A */
    {   66,   66,    0,    0,   11,    0,    0,    3 },  /* 77: KAGAMI K A */
    {   65,   65,    0,    0,   11,    0,    0,    3 },  /* 78: KAGAMI K A */
    {   68,   68,    0,   19,    3,   19,    0,    3 },  /* 79: D P GUARD K S */
    {   68,   68,    0,    0,    3,    0,    0,    3 },  /* 80: KAGAMI K A, D P GUARD K S */
    {   69,   69,    0,   19,    3,   19,    0,    3 },  /* 81: KAGAMI K A, D P GUARD K S */
    {   69,   69,    0,    0,    3,    0,    0,    3 },  /* 82: KAGAMI K A, D P GUARD K S */
    {   70,   70,    0,    0,    3,    0,    0,    3 },  /* 83: KAGAMI K A, D P GUARD K S */
    {   71,   71,    0,    0,    3,    0,    0,    3 },  /* 84: KAGAMI K A, D P GUARD K S */
    {   72,   72,    0,    0,    3,    0,    0,    3 },  /* 85: KAGAMI K A, D P GUARD K S */
    {   73,   73,    0,   20,    4,   20,    0,    4 },  /* 86: V JUMP P S A */
    {   73,   73,    0,    0,    4,    0,    0,    4 },  /* 87: V JUMP P S A */
    {  104,  104,    0,   21,    4,   21,    0,    4 },  /* 88: V JUMP K S A, ATTACK 11 L: not started by a command */
    {  104,  104,    0,   22,    4,   22,    0,    4 },  /* 89: V JUMP K M A */
    {   74,   74,    0,   23,    4,   23,    0,    4 },  /* 90: V JUMP K L A */
    {   74,   74,    0,    0,    4,    0,    0,    4 },  /* 91: V JUMP K L A */
    {   75,   75,    0,    0,    4,    0,    0,    4 },  /* 92: F JUMP P S A, F JUMP P M A, F JUMP P L A */
    {   76,   76,    0,    0,    4,    0,    0,    4 },  /* 93: F JUMP P S A, F JUMP P M A */
    {  118,  118,    0,   24,    4,   24,    0,    4 },  /* 94: F JUMP P S A */
    {  105,  105,    0,   25,    4,   25,    0,    4 },  /* 95: F JUMP P M A */
    {   77,   77,    0,    0,    4,    0,    0,    4 },  /* 96: F JUMP P S A, F JUMP P M A */
    {  106,  106,    0,   26,    4,   26,    0,    4 },  /* 97: F JUMP P L A */
    {  107,  107,    0,   27,    4,   27,    0,    4 },  /* 98: F JUMP P L A */
    {   78,   78,    0,    0,    4,    0,    0,    4 },  /* 99: F JUMP K S A, F JUMP K M A */
    {   79,   79,    0,    0,    4,    0,    0,    4 },  /* 100: GUARD AIR, F JUMP K S A, F JUMP K M A */
    {   79,   79,    0,   28,    4,   28,    0,    4 },  /* 101: F JUMP K S A */
    {   79,   79,    0,   29,    4,   29,    0,    4 },  /* 102: F JUMP K M A */
    {   80,   80,    0,    0,    4,    0,    0,    4 },  /* 103: GUARD AIR, F JUMP K S A, F JUMP K M A */
    {   81,   81,    0,   30,    4,   30,    0,    4 },  /* 104: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    {   81,   81,    0,   50,    4,   50,    0,    4 },  /* 105: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    {   82,   82,    0,    0,    4,    0,    0,    4 },  /* 106: F JUMP K M B, F JUMP K L A */
    {   17,    0,    0,    0,    0,    0,    0,   20 },  /* 107: dmca 97 */
    {   83,   83,    0,    0,    4,    0,    0,    4 },  /* 108: F JUMP K L A */
    {   10,   10,    0,    0,    3,    0,    0,    3 },  /* 109: PARING DOWN, GUARD DOWN, P BREAK DOWN */
    {   85,   85,    0,   32,    1,   32,    0,    1 },  /* 110: UP P GUARD P S, D P GUARD P S */
    {   85,   85,    0,    0,    1,    0,    0,    1 },  /* 111: UP P GUARD P S, D P GUARD P S */
    {   86,   86,    0,   33,    1,   33,    0,    1 },  /* 112: FUSHIN P S */
    {   86,   86,    0,    0,    1,    0,    0,    1 },  /* 113: FUSHIN P S */
    {    0,    0,    0,    0,    0,    0,    0,    3 },  /* 114: OKIAGARI, UKEMI MOVE F, UKEMI MOVE R +13 */
    {   87,   87,    0,    0,    0,    0,    0,   15 },  /* 115: ATTACK 10 M: not started by a command */
    {    0,    0,    0,    0,    0,    0,    0,   12 },  /* 116: not used by a script */
    {   88,   88,    0,    0,    0,    0,    0,   12 },  /* 117: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +1 */
    {   89,   89,    0,    0,    0,    0,    0,   12 },  /* 118: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +1 */
    {   90,   90,    0,   34,    1,   34,    0,   12 },  /* 119: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    {   91,   91,    0,   35,    1,   35,    0,   13 },  /* 120: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    {   92,   92,    0,   36,   10,   36,    0,   14 },  /* 121: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    {   93,   93,    0,    0,   10,    0,    0,   14 },  /* 122: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    {   94,   94,    0,    0,    1,    0,    0,    1 },  /* 123: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    {   95,   95,    0,    0,    1,    0,    0,    1 },  /* 124: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    {   96,   96,    0,    0,    1,    0,    0,    1 },  /* 125: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    {   97,   97,    0,   37,    1,   37,    0,    1 },  /* 126: not used by a script */
    {   97,   97,    0,    0,    1,    0,    0,    1 },  /* 127: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 SP: EX [4]6+PP (plain script) */
    {   98,   98,    0,   38,    1,   38,    0,    1 },  /* 128: not used by a script */
    {   98,   98,    0,    0,    1,    0,    0,    1 },  /* 129: ATTACK 4 M: [4]6+P medium (plain script) */
    {   99,   99,    0,   39,    1,   39,    0,    1 },  /* 130: not used by a script */
    {   99,   99,    0,    0,    1,    0,    0,    1 },  /* 131: ATTACK 4 L: [4]6+P heavy (plain script), ATTACK 13 M: not started by a command */
    {  100,  100,    0,    0,    4,    0,    0,    4 },  /* 132: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    {  101,  101,    0,    0,    4,    0,    0,    4 },  /* 133: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    {  101,  101,    0,    0,    4,    0,    0,    4 },  /* 134: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    {  109,  109,    0,   41,    1,   41,    0,    1 },  /* 135: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    {  102,  102,    0,   42,    3,   42,    0,    3 },  /* 136: KAGAMI P A */
    {  111,  111,    0,   43,    3,   43,    0,    3 },  /* 137: KAGAMI K A */
    {  103,  103,    0,   44,    4,   44,    0,    4 },  /* 138: V JUMP P M A */
    {  103,  103,    0,    0,    4,    0,    0,    4 },  /* 139: V JUMP P M A, follow-up of ZANNEN 7 */
    {  108,  108,    0,    0,    4,    0,    0,    4 },  /* 140: F JUMP P L A */
    {    1,    1,    0,   45,    1,   45,    0,    1 },  /* 141: M PUNCH A, M PUNCH B, M KICK A +3 */
    {  110,  110,    0,    0,    9,    0,    0,   18 },  /* 142: AIR S, AIR M, AIR L +40 */
    {    0,    0,    0,    0,    0,    0,    0,    1 },  /* 143: ATTACK 6 S: SA III 23623+P (plain script), ATTACK 7 S: SA II 23623+P light (plain script), ATTACK 7 M: SA II 23623+P medium (plain script) +3 */
    {  113,  113,    0,   57,    1,   57,    0,    1 },  /* 144: follow-up of WIN 8 */
    {  113,  113,    0,   46,    1,   46,    0,    1 },  /* 145: follow-up of ZANNEN 2 */
    {  113,  113,    0,    0,    1,    0,    0,    1 },  /* 146: follow-up of WIN 8, follow-up of SP WIN 1, follow-up of ZANNEN 2 +1 */
    {  113,  113,    0,   58,    1,   58,    0,    1 },  /* 147: follow-up of SP WIN 1 */
    {   15,   15,    0,   47,    4,   47,    0,    4 },  /* 148: V JUMP P L A, F JUMP P L A */
    {   93,   93,    0,   48,   10,   48,    0,   14 },  /* 149: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    {   46,   46,    0,   49,    1,   49,    0,    1 },  /* 150: not used by a script */
    {   81,   81,    0,    0,    4,    0,    0,    4 },  /* 151: ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) +3 */
    {  115,  115,    0,    0,    4,    0,    0,    4 },  /* 152: V JUMP P L A */
    {   65,   65,    0,   43,    3,   43,    0,    3 },  /* 153: not used by a script */
    {    0,    0,    0,    0,    0,    0,    0,   15 },  /* 154: OKIAGARI F, OKIAGARI B, OKIAGARI FRONT +1 */
    {  115,  115,    0,   53,    4,   53,    0,    4 },  /* 155: V JUMP P L A */
    {  116,  116,    0,   22,    4,   22,    0,    4 },  /* 156: not used by a script */
    {   15,   15,    0,   23,    4,   23,    0,    4 },  /* 157: not used by a script */
    {   83,   83,    0,   54,    4,   54,    0,    4 },  /* 158: F JUMP K L A */
    {    1,    1,    0,   55,    1,   55,    0,    1 },  /* 159: L PUNCH A, L KICK A */
    {    0,    0,    0,    0,    0,    0,    0,    4 },  /* 160: AIR S, AIR M, AIR L +2 */
    {  122,  122,    0,   56,    4,   56,    0,    4 },  /* 161: follow-up of ZANNEN 7 */
    {  119,  119,    0,    0,    4,    0,    0,    4 },  /* 162: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    {  120,  120,    0,    0,    1,    0,    0,   19 },  /* 163: PIYO */
    {  121,  121,    0,   59,    4,   59,    0,    4 },  /* 164: not used by a script */
    {  111,  111,    0,    0,    3,    0,    0,    3 },  /* 165: KAGAMI K A */
    {    0,    0,    0,    0,    0,    0,    0,   20 },  /* 166: NEKOROBI S, dmca 96 */
    {  123,  123,    0,    0,    1,    0,    0,    1 },  /* 167: ATTACK 6 S: SA III 23623+P (plain script) */
    {   59,   59,    0,    0,    3,    0,    0,    3 },  /* 168: KAGAMI P A */
    {   58,   58,    0,    0,    3,    0,    0,    3 },  /* 169: KAGAMI P A */
    {    1,    1,    0,    0,    0,    0,    0,    1 },  /* 170: follow-up of SP WIN 2 */
    {   10,   10,    0,    0,    0,    0,    0,    3 },  /* 171: follow-up of SP WIN 2 */
    {    1,    1,    0,    0,    1,    0,    0,    0 },  /* 172: LOSE SONABA */
    {  106,  106,    0,    0,    4,    0,    0,    4 },  /* 173: F JUMP P L A */
    {  107,  107,    0,    0,    4,    0,    0,    4 },  /* 174: F JUMP P L A */
    {    0,    0,    0,    0,    0,    0,    0,   12 },  /* 175: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    {    0,    0,    0,    0,    0,   34,    0,   12 },  /* 176: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    {   81,   81,    0,   30,    4,   60,    0,    4 },  /* 177: ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    {  113,  113,    0,   60,    1,    0,    0,    1 },  /* 178: ATTACK 9 S: after 6(123)4+P (plain script) */
};

const BODY_BOX oro_body_box[124] = {
    /*   x    w    y    h         x    w    y    h         x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -20,  29,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +105 */
    { { {  -19,  21,  67,  21 },  {  -28,  49,  52,  16 },  {  -28,  50,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 2: not used by a script */
    { { {   -5,  21,  53,  23 },  {  -26,  47,  42,  15 },  {  -25,  44,  24,  17 },  {  -37,  64,   0,  27 } } },  /* 3: DASH HUMIKOMI */
    { { {  -24,  21,  33,  23 },  {  -42,  47,  30,  15 },  {  -46,  55,  21,  13 },  {  -50,  64,   0,  27 } } },  /* 4: not used by a script */
    { { {  -50,  21,  36,  23 },  {  -42,  47,  34,  15 },  {  -38,  55,  23,  13 },  {  -53,  90,   0,  27 } } },  /* 5: DASH HUMIKOMI, P BREAK ZUJOU, TUKAMIHAZUSI */
    { { {  -39,  21,  57,  23 },  {  -42,  47,  34,  15 },  {  -38,  55,  23,  13 },  {  -53,  90,   0,  27 } } },  /* 6: not used by a script */
    { { {  -22,  21,  53,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 7: DASH TOBINOKI */
    { { {  -33,  21,  46,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 8: DASH TOBINOKI */
    { { {  -30,  21,  34,  23 },  {  -25,  49,  40,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 9: not used by a script */
    { { {  -29,  31,  41,  23 },  {  -29,  58,  30,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 10: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +29 */
    { { {   -6,  21,  39,  23 },  {  -22,  49,  32,  12 },  {  -20,  46,  18,  16 },  {  -34,  64,   0,  14 } } },  /* 11: not used by a script */
    { { {  -45,  21,  81,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 12: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    { { {  -51,  21,  70,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 13: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    { { {  -51,  21,  63,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 14: JUMP FRONT, JUMP BACK, S JUMP FRONT +11 */
    { { {  -10,  21,  95,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 15: JUMP JUNBI, SP JUMP JUNBI, JUMP VERTICAL +13 */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 16: nmca 33, S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 17: dmca 97 */
    { { {  -22,  21,  64,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 18: not used by a script */
    { { {  -22,  21,  62,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 19: S PUNCH B */
    { { {  -22,  21,  69,  23 },  {  -33,  49,  54,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 20: not used by a script */
    { { {  -22,  21,  69,  23 },  {  -33,  49,  54,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 21: not used by a script */
    { { {  -10,  21,  74,  23 },  {  -22,  49,  61,  12 },  {  -19,  42,  32,  27 },  {  -30,  64,   0,  30 } } },  /* 22: not used by a script */
    { { {  -18,  21,  85,  23 },  {  -27,  44,  70,  15 },  {  -25,  42,  42,  26 },  {  -30,  64,   0,  39 } } },  /* 23: not used by a script */
    { { {  -18,  21,  85,  23 },  {  -27,  52,  70,  15 },  {  -25,  49,  39,  32 },  {  -30,  64,   0,  39 } } },  /* 24: M PUNCH B */
    { { {  -18,  21,  85,  23 },  {  -27,  44,  70,  15 },  {  -25,  42,  42,  26 },  {  -30,  64,   0,  39 } } },  /* 25: CATCH 6, M PUNCH B */
    { { {  -13,  21,  62,  23 },  {  -28,  49,  52,  12 },  {  -15,  42,  27,  22 },  {  -35,  64,   0,  27 } } },  /* 26: not used by a script */
    { { {  -20,  29,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 27: M PUNCH A */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 28: M PUNCH A */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 29: M PUNCH A */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 30: M PUNCH A */
    { { {   -4,  21,  66,  23 },  {  -28,  49,  52,  12 },  {  -15,  42,  27,  22 },  {  -24,  64,   0,  27 } } },  /* 31: not used by a script */
    { { {  -11,  27,  72,  23 },  {  -20,  52,  59,  12 },  {  -35,  68,  34,  25 },  {  -15,  52,   0,  34 } } },  /* 32: L PUNCH A, UP P GUARD P L */
    { { {  -11,  27,  72,  23 },  {  -17,  49,  59,  16 },  {  -26,  63,  33,  26 },  {  -31,  73,   0,  33 } } },  /* 33: L PUNCH A, UP P GUARD P L */
    { { {  -18,  26,  62,  24 },  {  -22,  50,  52,  17 },  {  -24,  57,  28,  24 },  {  -33,  74,   0,  33 } } },  /* 34: L PUNCH A, UP P GUARD P L */
    { { {  -21,  28,  56,  23 },  {  -24,  51,  47,  22 },  {  -23,  57,  27,  22 },  {  -30,  74,   0,  27 } } },  /* 35: L PUNCH A, UP P GUARD P L */
    { { {  -23,  30,  56,  23 },  {  -34,  62,  47,  19 },  {  -17,  56,  28,  22 },  {  -29,  77,   0,  27 } } },  /* 36: L PUNCH A, UP P GUARD P L */
    { { {   -5,  28,  69,  23 },  {  -25,  57,  56,  18 },  {  -28,  60,  33,  23 },  {  -38,  76,   0,  33 } } },  /* 37: L PUNCH A, UP P GUARD P L */
    { { {   12,  24,  77,  23 },  {   -6,  55,  59,  20 },  {  -25,  62,  38,  26 },  {  -31,  67,   0,  40 } } },  /* 38: S KICK A */
    { { {    9,  25,  77,  23 },  {  -13,  55,  59,  22 },  {  -30,  57,  37,  29 },  {   -2,  36,   0,  40 } } },  /* 39: S KICK A */
    { { {   14,  26,  77,  23 },  {   -3,  50,  59,  22 },  {  -18,  44,  37,  22 },  {   -2,  34,   0,  40 } } },  /* 40: S KICK A */
    { { {   16,  21,  79,  23 },  {  -18,  60,  67,  12 },  {  -31,  69,  42,  26 },  {   -2,  34,   0,  42 } } },  /* 41: S KICK B */
    { { {   27,  21,  78,  23 },  {  -18,  60,  67,  12 },  {  -15,  42,  42,  26 },  {   -2,  34,   0,  42 } } },  /* 42: S KICK B */
    { { {   27,  21,  78,  23 },  {  -18,  60,  67,  12 },  {  -31,  69,  42,  26 },  {   -2,  34,   0,  42 } } },  /* 43: S KICK B */
    { { {    1,  21,  75,  23 },  {  -14,  49,  62,  12 },  {  -16,  42,  35,  25 },  {  -17,  64,   0,  33 } } },  /* 44: M KICK A */
    { { {  -30,  21,  45,  23 },  {  -29,  58,  28,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 45: not used by a script */
    { { {    1,  21,  75,  23 },  {  -14,  49,  62,  12 },  {  -16,  42,  35,  25 },  {  -17,  39,   0,  33 } } },  /* 46: M KICK A */
    { { {  -16,  21,  75,  23 },  {  -14,  49,  62,  12 },  {  -16,  42,  35,  25 },  {  -17,  39,   0,  33 } } },  /* 47: M KICK A */
    { { {    2,  21,  93,  23 },  {   -9,  49,  74,  18 },  {  -15,  42,  45,  29 },  {  -10,  34,   0,  44 } } },  /* 48: M KICK B, UP P GUARD K S */
    { { {    2,  21,  93,  23 },  {   -9,  49,  75,  17 },  {  -15,  42,  45,  29 },  {  -10,  34,   0,  44 } } },  /* 49: UP P GUARD K S */
    { { {   -5,  30,  87,  24 },  {  -13,  57,  75,  22 },  {  -15,  42,  45,  29 },  {  -10,  34,   0,  44 } } },  /* 50: M KICK B, UP P GUARD K S */
    { { {   -7,  26,  79,  24 },  {  -15,  55,  65,  24 },  {  -15,  42,  39,  29 },  {  -10,  34,   0,  37 } } },  /* 51: M KICK B, UP P GUARD K S */
    { { {  -18,  27,  78,  25 },  {  -28,  56,  62,  27 },  {  -29,  55,  37,  25 },  {  -35,  67,   0,  37 } } },  /* 52: M KICK B, UP P GUARD K S */
    { { {  -11,  25,  82,  23 },  {  -16,  51,  61,  25 },  {  -26,  50,  38,  28 },  {  -29,  34,   0,  36 } } },  /* 53: L KICK A */
    { { {   -2,  30,  82,  23 },  {  -36,  72,  66,  26 },  {  -18,  42,  38,  28 },  {  -29,  42,   0,  37 } } },  /* 54: L KICK A */
    { { {   -2,  30,  82,  23 },  {  -36,  72,  66,  26 },  {  -18,  42,  38,  28 },  {  -29,  42,   0,  37 } } },  /* 55: L KICK A */
    { { {   -8,  21,  81,  23 },  {  -16,  49,  66,  20 },  {  -18,  42,  38,  28 },  {  -29,  34,   0,  36 } } },  /* 56: not used by a script */
    { { {  -16,  33,  81,  23 },  {  -28,  59,  64,  20 },  {  -25,  50,  38,  28 },  {  -25,  42,   0,  37 } } },  /* 57: L KICK A */
    { { {  -30,  29,  45,  23 },  {  -29,  58,  28,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 58: KAGAMI P A */
    { { {  -22,  24,  48,  23 },  {  -30,  58,  36,  20 },  {  -43,  72,  16,  20 },  {  -59,  90,   0,  14 } } },  /* 59: KAGAMI P A */
    { { {   -8,  26,  50,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 60: KAGAMI P A */
    { { {   -8,  26,  50,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 61: KAGAMI P A */
    { { {   -8,  29,  50,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 62: KAGAMI P A */
    { { {  -10,  31,  52,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 63: KAGAMI P A */
    { { {  -22,  30,  50,  25 },  {  -29,  58,  28,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 64: TOUKETSU A, KAGAMI P A */
    { { {    2,  24,  49,  23 },  {  -14,  55,  43,  15 },  {  -27,  67,  19,  23 },  {  -46,  85,   0,  19 } } },  /* 65: KAGAMI K A */
    { { {    2,  24,  49,  23 },  {  -14,  55,  43,  15 },  {  -27,  67,  19,  23 },  {  -57,  93,   0,  32 } } },  /* 66: KAGAMI K A */
    { { {   30,  21,  39,  23 },  {  -15,  49,  41,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 67: not used by a script */
    { { {  -11,  35,  46,  17 },  {  -27,  61,  38,  17 },  {  -46,  78,  28,  19 },  {  -58,  91,   0,  27 } } },  /* 68: D P GUARD K S, KAGAMI K A */
    { { {  -11,  35,  46,  17 },  {  -27,  61,  38,  17 },  {  -46,  78,  28,  19 },  {  -58,  91,   0,  27 } } },  /* 69: KAGAMI K A, D P GUARD K S */
    { { {  -19,  38,  46,  23 },  {  -27,  61,  38,  17 },  {  -46,  78,  28,  22 },  {  -58,  91,   0,  27 } } },  /* 70: KAGAMI K A, D P GUARD K S */
    { { {  -24,  38,  46,  17 },  {  -31,  61,  38,  17 },  {  -46,  78,  28,  22 },  {  -58,  91,   0,  27 } } },  /* 71: KAGAMI K A, D P GUARD K S */
    { { {  -28,  27,  46,  22 },  {  -31,  62,  40,  15 },  {  -29,  59,  28,  18 },  {  -35,  77,   0,  27 } } },  /* 72: KAGAMI K A, D P GUARD K S */
    { { {  -33,  26,  92,  23 },  {  -73,  98,  61,  30 },  {  -32,  58,  26,  51 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP P S A */
    { { {  -10,  21,  95,  23 },  {  -24,  49,  74,  20 },  {  -17,  39,  27,  48 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A */
    { { {  -46,  21,  66,  23 },  {  -28,  49,  72,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 75: F JUMP P S A, F JUMP P M A, F JUMP P L A */
    { { {  -46,  21,  66,  23 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 76: F JUMP P S A, F JUMP P M A */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  78,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 77: F JUMP P S A, F JUMP P M A */
    { { {  -28,  21,  81,  23 },  {  -28,  49,  72,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 78: F JUMP K S A, F JUMP K M A */
    { { {    5,  21,  81,  23 },  {  -28,  49,  72,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 79: GUARD AIR, F JUMP K S A, F JUMP K M A */
    { { {  -45,  21,  81,  23 },  {  -28,  49,  72,  12 },  {  -33,  57,  36,  39 },  {    0,   0,   0,   0 } } },  /* 80: GUARD AIR, F JUMP K S A, F JUMP K M A */
    { { {  -47,  21,  62,  23 },  {  -30,  49,  78,  12 },  {  -26,  42,  32,  44 },  {  -35,  47,   5,  27 } } },  /* 81: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) +4 */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  72,  12 },  {  -57,  36,  38,  30 },  {    0,   0,   0,   0 } } },  /* 82: F JUMP K M B, F JUMP K L A */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  72,  12 },  {  -50,  71,  26,  48 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K L A */
    { { {   -5,  21,  39,  23 },  {  -16,  49,  28,  12 },  {  -12,  46,  12,  16 },  {  -29,  64,   0,  14 } } },  /* 84: not used by a script */
    { { {  -13,  21,  62,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 85: UP P GUARD P S, D P GUARD P S */
    { { {  -13,  21,  62,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 86: FUSHIN P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -29,  53,   0,  21 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 10 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  42,  28,  18 },  {  -30,  64,   0,  26 } } },  /* 88: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  42,  26,  18 },  {  -36,  64,   0,  26 } } },  /* 89: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +1 */
    { { {  -33,  42,  52,  18 },  {    0,   0,   0,   0 },  {  -28,  42,  30,  18 },  {  -24,  62,   0,  30 } } },  /* 90: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -28,  38,  66,  16 },  {  -27,  40,  38,  27 },  {  -14,  50,   0,  38 } } },  /* 91: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { { {  -10,  16,  96,  16 },  {  -20,  26,  78,  16 },  {  -26,  38,  52,  24 },  {  -20,  34,  26,  24 } } },  /* 92: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { { {  -10,  18, 100,  16 },  {  -20,  38,  80,  16 },  {  -24,  48,  52,  24 },  {  -18,  36,   0,  51 } } },  /* 93: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { { {  -30,  18,  50,  20 },  {  -30,  42,  44,  18 },  {  -24,  40,  28,  20 },  {  -40,  68,   0,  26 } } },  /* 94: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    { { {  -16,  18,  76,  20 },  {  -24,  34,  58,  16 },  {  -26,  32,  34,  22 },  {  -46,  66,   0,  32 } } },  /* 95: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -52,  82,   0,  33 } } },  /* 96: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -52,  82,   0,  33 } } },  /* 97: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 SP: EX [4]6+PP (plain script) */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -47,  81,   0,  34 } } },  /* 98: ATTACK 4 M: [4]6+P medium (plain script) */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -52,  82,   0,  34 } } },  /* 99: ATTACK 4 L: [4]6+P heavy (plain script), ATTACK 13 M: not started by a command */
    { { {   -6,  18,  98,  22 },  {  -12,  48,  84,  12 },  {  -18,  46,  62,  20 },  {  -24,  42,  36,  24 } } },  /* 100: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    { { {  -28,  18,  96,  22 },  {  -32,  48,  84,  12 },  {  -22,  46,  62,  20 },  {  -24,  42,  36,  24 } } },  /* 101: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    { { {  -22,  24,  49,  23 },  {  -30,  58,  36,  20 },  {  -43,  72,  16,  20 },  {  -59,  90,   0,  14 } } },  /* 102: KAGAMI P A */
    { { {  -33,  26,  92,  23 },  {  -64,  94,  61,  30 },  {  -36,  63,  36,  34 },  {    0,   0,   0,   0 } } },  /* 103: V JUMP P M A, follow-up of ZANNEN 7 */
    { { {  -25,  21,  81,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 104: V JUMP K S A, ATTACK 11 L: not started by a command, V JUMP K M A */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  78,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 105: F JUMP P M A */
    { { {  -72,  44,  50,  37 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 106: F JUMP P L A */
    { { {  -72,  44,  50,  37 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 107: F JUMP P L A */
    { { {  -72,  44,  50,  37 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 108: F JUMP P L A */
    { { {  -23,  21,  71,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -54,  86,   0,  33 } } },  /* 109: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    { { {  -21,  43,  56,  14 },  {  -27,  54,  50,  18 },  {  -27,  55,  35,  15 },  {  -27,  55,  21,  14 } } },  /* 110: AIR S, AIR M, AIR L +40 */
    { { {    2,  24,  49,  23 },  {  -14,  55,  43,  15 },  {  -27,  67,  19,  23 },  {  -46,  85,   0,  19 } } },  /* 111: KAGAMI K A */
    { { {  -18,  18,  74,  18 },  {  -24,  34,  56,  16 },  {  -26,  38,  32,  22 },  {  -34,  60,   0,  30 } } },  /* 112: not used by a script */
    { { {  -20,  18,  72,  18 },  {  -48,  58,  58,  14 },  {  -26,  38,  32,  24 },  {  -34,  60,   0,  30 } } },  /* 113: follow-up of WIN 8, follow-up of ZANNEN 2, follow-up of SP WIN 1 +1 */
    { { {  -20,  18,  72,  18 },  {  -48,  58,  58,  14 },  {  -26,  38,  32,  24 },  {  -34,  60,   0,  30 } } },  /* 114: not used by a script */
    { { {  -10,  21,  95,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  51 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP P L A */
    { { {  -25,  21,  81,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 116: not used by a script */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  72,  12 },  {  -50,  71,  26,  48 },  {    0,   0,   0,   0 } } },  /* 117: not used by a script */
    { { {  -46,  21,  66,  23 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 118: F JUMP P S A */
    { { {  -10,  21,  79,  13 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 119: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    { { {  -20,  29,  57,  23 },  {  -29,  59,  45,  25 },  {  -32,  64,  28,  29 },  {  -35,  68,   0,  27 } } },  /* 120: PIYO */
    { { {  -68,  42,  66,  25 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 121: not used by a script */
    { { {  -10,  21,  95,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  51 },  {    0,   0,   0,   0 } } },  /* 122: follow-up of ZANNEN 7 */
    { { {  -11,  23,  84,  27 },  {  -34,  70,  70,  19 },  {  -32,  66,  42,  28 },  {  -29,  59,   0,  42 } } },  /* 123: ATTACK 6 S: SA III 23623+P (plain script) */
};

const HAND_BOX oro_hand_box[124] = {
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
    { { {  -62,  39,  64,  36 },  {    0,   0,   0,   0 } } },  /* 16: nmca 33, S PUNCH A */
    { { {  -38,  17,  57,  15 },  {    0,   0,   0,   0 } } },  /* 17: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: no box */
    { { { -100,  67,  49,  20 },  {    0,   0,   0,   0 } } },  /* 19: S PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: no box */
    { { {  -72,  40,  48,  12 },  {    0,   0,   0,   0 } } },  /* 21: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: no box */
    { { {  -81,  60,  62,  29 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { {  -86,  68,  68,  24 },  {    0,   0,   0,   0 } } },  /* 24: M PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: no box */
    { { {  -54,  36,  38,  23 },  {    0,   0,   0,   0 } } },  /* 27: M PUNCH A */
    { { {  -39,  28,  73,  56 },  {    0,   0,   0,   0 } } },  /* 28: M PUNCH A */
    { { {  -37,  25,  78,  48 },  {    0,   0,   0,   0 } } },  /* 29: M PUNCH A */
    { { {  -45,  27,  67,  39 },  {    0,   0,   0,   0 } } },  /* 30: M PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { {  -56,  29,  54,  36 },  {    0,   0,   0,   0 } } },  /* 35: L PUNCH A, UP P GUARD P L */
    { { {  -71,  54,  25,  22 },  {    0,   0,   0,   0 } } },  /* 36: L PUNCH A, UP P GUARD P L */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {  -48,  44,  42,  48 },  {    0,   0,   0,   0 } } },  /* 40: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {  -82,  69,  40,  26 },  {    0,   0,   0,   0 } } },  /* 42: S KICK B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: no box */
    { { {  -71,  54,  28,  27 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -44,  29,  34,  53 },  {    0,   0,   0,   0 } } },  /* 46: M KICK A */
    { { {  -36,  21,  49,  22 },  {    0,   0,   0,   0 } } },  /* 47: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: no box */
    { { {  -68,  43,  55,  25 },  {    0,   0,   0,   0 } } },  /* 49: UP P GUARD K S */
    { { {  -83,  74,  53,  27 },  {    0,   0,   0,   0 } } },  /* 50: M KICK B, UP P GUARD K S */
    { { {  -83,  74,  38,  25 },  {    0,   0,   0,   0 } } },  /* 51: M KICK B, UP P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: no box */
    { { {  -86,  68,  55,  32 },  {    0,   0,   0,   0 } } },  /* 54: L KICK A */
    { { {  -82,  65,  55,  27 },  {    0,   0,   0,   0 } } },  /* 55: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { { -108,  85,  29,  23 },  {    0,   0,   0,   0 } } },  /* 59: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: no box */
    { { {  -79,  51,  36,  25 },  {    0,   0,   0,   0 } } },  /* 61: KAGAMI P A */
    { { {  -69,  59,  44,  25 },  {    0,   0,   0,   0 } } },  /* 62: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {  -91,  49,   0,  22 },  {    0,   0,   0,   0 } } },  /* 66: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: no box */
    { { {  -72,  41,   0,  36 },  {    0,   0,   0,   0 } } },  /* 68: D P GUARD K S, KAGAMI K A */
    { { {  -98,  66,   0,  36 },  {    0,   0,   0,   0 } } },  /* 69: KAGAMI K A, D P GUARD K S */
    { { {  -80,  49,   0,  36 },  {    0,   0,   0,   0 } } },  /* 70: KAGAMI K A, D P GUARD K S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: no box */
    { { {  -93,  60,  48,  29 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP P S A */
    { { {  -84,  62,  43,  30 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { {  -53,  26,  43,  20 },  {    0,   0,   0,   0 } } },  /* 76: F JUMP P S A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {  -46,  46,  12,  30 },  {    0,   0,   0,   0 } } },  /* 79: GUARD AIR, F JUMP K S A, F JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {  -92,  70,  32,  27 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {  -69,  43,  52,   7 },  {    0,   0,   0,   0 } } },  /* 85: UP P GUARD P S, D P GUARD P S */
    { { {  -36,  49,  60,  10 },  {    0,   0,   0,   0 } } },  /* 86: FUSHIN P S */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {  -40,  18,  25,  31 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    { { {  -46,  17,  47,  33 },  {    0,   0,   0,   0 } } },  /* 91: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: no box */
    { { { -108,  68,  60,  12 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 SP: EX [4]6+PP (plain script) */
    { { {  -85,  55,  59,  35 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 4 M: [4]6+P medium (plain script) */
    { { {  -65,  28,  63,  49 },  {    0,   0,   0,   0 } } },  /* 99: ATTACK 4 L: [4]6+P heavy (plain script), ATTACK 13 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: no box */
    { { {  -98,  40,  64,  18 },  {    0,   0,   0,   0 } } },  /* 101: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    { { {  -99,  68,  31,  19 },  {    0,   0,   0,   0 } } },  /* 102: KAGAMI P A */
    { { {  -96,  64,  54,  23 },  {    0,   0,   0,   0 } } },  /* 103: V JUMP P M A, follow-up of ZANNEN 7 */
    { { {  -62,  41,  48,  29 },  {    0,   0,   0,   0 } } },  /* 104: V JUMP K S A, ATTACK 11 L: not started by a command, V JUMP K M A */
    { { {  -80,  54,  40,  28 },  {    0,   0,   0,   0 } } },  /* 105: F JUMP P M A */
    { { {  -58,  35,   9,  68 },  {    0,   0,   0,   0 } } },  /* 106: F JUMP P L A */
    { { {  -53,  34,  69,  57 },  {    0,   0,   0,   0 } } },  /* 107: F JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: no box */
    { { {  -82,  48,  59,  15 },  {    0,   0,   0,   0 } } },  /* 109: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {  -83,  56,   0,  32 },  {    0,   0,   0,   0 } } },  /* 111: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: no box */
    { { {  -80,  34,  60,  10 },  {    0,   0,   0,   0 } } },  /* 113: follow-up of WIN 8, follow-up of ZANNEN 2, follow-up of SP WIN 1 +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: no box */
    { { { -104,  78,  74,  19 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: no box */
    { { { -102,  83,  32,  27 },  {    0,   0,   0,   0 } } },  /* 117: not used by a script */
    { { {  -77,  53,  37,  25 },  {    0,   0,   0,   0 } } },  /* 118: F JUMP P S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: no box */
    { { {  -68,  40,  31,  37 },  {    0,   0,   0,   0 } } },  /* 121: not used by a script */
    { { {  -98,  75,  62,  37 },  {    0,   0,   0,   0 } } },  /* 122: follow-up of ZANNEN 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: no box */
};

const HOSEI_BOX oro_hos_box[21] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -29,   59,    0,   76 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +109 */
    { {  -43,   50,    0,   64 } },  /* 2: DASH HUMIKOMI */
    { {  -29,   59,    0,   44 } },  /* 3: DASH TOBINOKI, KAGAMU, KAGAMI KAMAE +44 */
    { {  -23,   46,   39,   47 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +43 */
    { {  -25,   50,   31,   58 } },  /* 5: not used by a script */
    { {  -14,   50,   28,   40 } },  /* 6: not used by a script */
    { {  -16,   50,   28,   60 } },  /* 7: not used by a script */
    { {  -28,   50,   28,   60 } },  /* 8: not used by a script */
    { {  -16,   50,   22,   34 } },  /* 9: not used by a script */
    { {  -28,   50,   31,   47 } },  /* 10: not used by a script */
    { {  -28,   50,   51,   47 } },  /* 11: not used by a script */
    { {  -24,   48,    0,   57 } },  /* 12: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { {  -28,   56,    0,   65 } },  /* 13: DASH TOBINOKI, OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN) +3 */
    { {  -24,   48,   28,   51 } },  /* 14: OKIAGARI P S, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { {  -26,   44,    0,   25 } },  /* 15: ATTACK 10 M: not started by a command, OKIAGARI F, OKIAGARI B +2 */
    { {  -43,   64,    0,   55 } },  /* 16: not used by a script */
    { {  -43,   79,   20,   34 } },  /* 17: not used by a script */
    { {  -21,   49,   22,   45 } },  /* 18: AIR S, AIR M, AIR L +40 */
    { {  -29,   59,    0,   60 } },  /* 19: DASH HUMIKOMI, P BREAK ZUJOU, TUKAMIHAZUSI +1 */
    { {  -29,   59,    0,   30 } },  /* 20: dmca 97, NEKOROBI S, dmca 96 */
};
