/*
 * SEAN_ATTR.C  Sean's attack attributes and random sound lists
 *
 * sean_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * sean_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR sean_catt_table[99] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  3, 68, 15,  3, 63,  0,  0, 20, 16,  5,  4,  0,  8, -8, 28, 73),  /* 1: ATTACK 9 S: not started by a command */
    ATTR( 37,  0,  0,  2,  0,  1,  3, 72, 15,  3, 63,  0,  0, 16, 16,  4,  8,  0,  8, -8, 28, 73),  /* 2: OKIAGARI P S, ATTACK 9 S: not started by a command, ATTACK 9 M: not started by a command +1 */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 13,  3, 63,  0,  0,  4, 16,  2,  1,  0,  6, -6, 13, 72),  /* 3: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4, 16,  1,  1,  0,  6, -6, 13, 72),  /* 4: S PUNCH A */
    ATTR( 37,  0,  0,  1,  0,  1,  1,  0, 12,  3, 62,  0,  0, 18, 30,  6,  4,  0,  7, -7, 18, 73),  /* 5: M PUNCH A */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 18, 18,  5,  4,  0,  7, -7, 18, 73),  /* 6: M PUNCH B, UP P GUARD P S */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 15,  3, 62,  0,  0, 24, 17,  6,  7,  0,  8, -8, 23, 73),  /* 7: L PUNCH A, L PUNCH C, follow-up of L PUNCH A +1 */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 14,  3, 62,  0,  0, 10, 19,  1,  1,  0, 12,-12, 23, 73),  /* 8: UP P GUARD P L */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 14,  3, 62,  0, 24, 10, 19,  1,  1,  0, 12,-12, 23, 73),  /* 9: follow-up of M PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 10,  3, 63,  0,  0,  6, 16,  1,  1,  0,  6, -6, 29, 72),  /* 10: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 63,  0,  0,  8, 16,  1,  1,  0,  6, -6, 29, 72),  /* 11: not used by a script */
    ATTR( 38,  0,  0,  1,  0,  1,  3,  0, 13,  3, 63,  0,  0, 22, 18,  2,  4,  0,  7,-10, 34, 73),  /* 12: M KICK A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 29, 18,  5,  7,  0,  8, -8, 39, 73),  /* 13: L KICK A */
    ATTR( 35,  0,  0,  2,  0,  1,  0,  0, 14,  3, 63,  0,  0, 36, 19,  6,  7,  0,  8, -8, 39, 73),  /* 14: not used by a script */
    ATTR( 35,  0,  0,  2,  0,  1,  0,  0, 14,  3, 63,  0,  0,  4, 19,  6,  7,  0,  8, -8, 39, 73),  /* 15: not used by a script */
    ATTR( 64,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  0,  4, 19,  6,  7,  0,  8, -8, 39, 73),  /* 16: not used by a script */
    ATTR( 33,  0,  0,  2,  0,  1,  3,  0, 14,  3, 62,  0,  0, 28, 19,  8,  7,  0,  8, -8, 39, 73),  /* 17: L KICK B */
    ATTR( 93,  0,  0,  2,  0,  1,  3,  0, 12,  3, 63,  0,  0, 40, 20,  7,  7,  0, 12,-12, 39, 73),  /* 18: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 63,  0,  0, 16, 18,  3,  4,  0,  7, -7, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 22, 24, 19,  6,  7,  0,  8, -5, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 22, 24, 19,  6,  7,  0,  8, -5, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 45,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3,  9,  0,  0, 18, 16,  1,  4,  0,  7, -7, 34, 73),  /* 24: KAGAMI K A, UP P GUARD K S */
    ATTR( 89,  0,  0,  2,  0,  1,  3,  0, 12,  3,  9,  0,  1, 26, 17,  1,  7,  0, 12,-10, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0,  8, 21,  3,  1,  0,  5, -5, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 22,  5,  4,  0,  6, -6, 23, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 26, 23,  7,  7,  0,  7, -7, 23, 73),  /* 28: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 21,  3,  1,  0,  5, -5, 29, 72),  /* 29: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 22,  4,  4,  0,  6, -6, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 26, 23,  6,  7,  0,  7, -7, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  8,  3, 54,  0,  0, 10, 21,  3,  1,  0,  5, -5, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0, 18, 22,  4,  4,  0,  6, -6, 18, 73),  /* 33: F JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 26, 23,  6,  7,  0,  7, -7, 23, 73),  /* 34: V JUMP P L A, F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 21,  2,  1,  0,  5, -5, 29, 72),  /* 35: V JUMP K S A, F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 21,  4,  4,  0,  6, -6, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 22, 22,  6,  7,  0,  7, -7, 39, 73),  /* 37: F JUMP K L A */
    ATTR( 35,  1,  0,  2,  0,  1,  7,196, 14,  3, 63,  0,  0, 32, 20,  4,  4,  0,  6,-16, 44, 73),  /* 38: not used by a script */
    ATTR( 35,  1,  0,  2,  0,  1,  7,196, 13,  3, 63,  0,  0, 24, 20,  3,  5,  0,  8,-16, 44, 73),  /* 39: not used by a script */
    ATTR( 35,  1,  0,  2,  0,  1,  7,196, 14,  3, 63,  0,  0, 24, 20,  3,  5,  0,  8,-16, 44, 73),  /* 40: not used by a script */
    ATTR( 95,  0,  0,  2,  0,  1,  7,196, 15,  3, 63,  1,  3, 18, 20,  0,  0,  0,  6, -6, 28, 73),  /* 41: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 33,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3, 10, 16,  0,  0,  0,  6,-24, 28, 73),  /* 42: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 33,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  7, 16,  0,  0,  0,  4, -4, 28, 73),  /* 43: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  4, 16,  0,  0,  0,  4, -8, 28, 73),  /* 44: not used by a script */
    ATTR( 94,  0,  0,  2,  0,  1,  7,200, 15,  3, 63,  0, 14,  4, 16,  0,  0,  0,  6,-12, 28, 73),  /* 45: not used by a script */
    ATTR( 95,  0,  0,  0,  0,  1,  7,208,  0,  3, 63,  0, 23,  8, 16,  0,  0,  0,  2, -2, 28, 73),  /* 46: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  8,  0,  3, 63,  0,  4, 24, 16,  4, 13,  0,  8, -8,  0, 51),  /* 47: CATCH 1, CATCH 3 */
    ATTR( 35,  0,  0,  2,  0,  1,  0,  0, 14,  3,  0,  0,  0,  0, 34,  0,  4,  1, 10,-10,  0,  0),  /* 48: M PUNCH A, M PUNCH B, L PUNCH A +7 */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  8, 10,  3, 54,  0,  8, 24, 19,  9, 11,  0, 12,-12, 44, 73),  /* 49: ATTACK 3 S: 236+K light (routine Att_ABISEGERI), ATTACK 3 M: 236+K medium (routine Att_ABISEGERI), ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  8, 10,  3, 54,  0, 13, 24, 26,  9, 11,  0, 12,-12, 44, 73),  /* 50: ATTACK 3 L: 236+K heavy (routine Att_ABISEGERI) */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  5, 32, 16,  7, 13,  0,  8, -8,  0, 51),  /* 51: CATCH 5 */
    ATTR( 37,  0,  0,  2, 21,  1,  0, 64, 10,  3, 45,  1,  0,  0, 17,  0,  0,  1, 10,-10, 84, 60),  /* 52: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 10,  3,  9,  0,  6,  8, 16,  1,  1,  1,  8, -8, 29, 73),  /* 53: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 10,  3,  9,  0,  6,  8, 16,  1,  1,  1,  8, -8, 29, 73),  /* 54: not used by a script */
    ATTR( 37,  0,  0,  0, 20,  1,  0,  0, 10,  3,  9,  0,  6,  8, 16,  2,  1,  1,  8, -8, 39, 73),  /* 55: CATCH 9 */
    ATTR( 32,  1,  0,  2,  0,  1,  3, 68, 10,  3, 62,  0, 12, 10, 26,  3,  1,  0,  6, -8, 39, 73),  /* 56: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 33,  1,  0,  2,  0,  1,  7, 72,  9,  3, 62,  0, 12, 10, 16,  3, 12,  0,  6, -6, 44, 73),  /* 57: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 8 S: not started by a command */
    ATTR( 37,  1,  0,  2,  0,  1,  7, 80,  9,  3, 62,  0, 12, 10, 16,  3,  1,  0,  6, -4, 44, 73),  /* 58: ATTACK 8 S: not started by a command */
    ATTR( 37,  0,  0,  2, 19,  1,  0, 64, 10,  3, 36,  0,  0, 36, 20,  8, 13,  1,  8, -8, 28, 50),  /* 59: CATCH 10 */
    ATTR( 37,  1,  0,  2,  0,  1,  7,192, 14,  3, 63,  0,  0, 12, 54,  0,  0,  0,  6, -2, 44, 73),  /* 60: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  1,  0,  3,  0,  1,  7,200, 13,  3, 63,  0,  0, 12, 54,  0,  0,  0,  3, -2, 44, 73),  /* 61: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  1,  0,  3,  0,  1,  7,208, 14,  3, 63,  0, 11, 12, 54,  0,  0,  0,  3, -2, 44, 73),  /* 62: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 24, 17,  5,  0,  0,  8, -8, 18,  0),  /* 63: FUSHIN P S */
    ATTR( 32,  1,  0,  2,  0,  1,  1,208,  8,  3, 63,  0,  0,  4, 54,  0,  0,  0,  6,-12, 28, 73),  /* 64: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  1,  0,  2,  0,  1,  1,192, 14,  3, 63,  0,  0,  4, 52,  0,  0,  0,  6,-16, 28, 73),  /* 65: not used by a script */
    ATTR( 35,  1,  0,  2,  0,  1,  1,192, 14,  3, 63,  0,  0,  4, 52,  0,  0,  0,  6,-16, 28, 73),  /* 66: not used by a script */
    ATTR( 32,  1,  0,  2,  0,  1,  0,208, 10,  3, 54,  0,  8, 13, 19,  9,  0,  0,  5,-12, 44, 73),  /* 67: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 97,  0,  0,  2,  0,  1,  0,208,  8,  3, 54,  0, 13, 21, 20,  1,  0,  0, 12, -8, 44, 73),  /* 68: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 96,  0,  0,  2,  0,  1,  3, 68, 15,  3, 63,  0, 14, 28, 16,  5,  4,  0, 10,-10, 28, 73),  /* 69: ATTACK 9 M: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  3, 68, 15,  3, 63,  0, 15, 32, 16,  5,  4,  0, 12,-12, 28, 73),  /* 70: ATTACK 9 L: not started by a command */
    ATTR( 35,  0,  0,  2,  0,  1,  0,192, 15,  3, 63,  1,  0, 12, 54,  1,  0,  0,  6, -6, 28, 73),  /* 71: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  0,  0,  2,  0,  1,  0,192, 15,  3, 63,  1,  0, 12, 54,  1,  0,  0,  6, -6, 28, 73),  /* 72: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  1,  0,  2,  0,  1,  1,192,  8,  3, 63,  1,  0,  8, 54,  0,  0,  0, 12,-18,  0, 73),  /* 73: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 96,  0,  0,  3,  0,  1,  1, 68, 15,  3, 63,  0, 16, 16, 16,  5,  4,  0,  8, -8, 28, 73),  /* 74: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 68, 15,  3, 63,  0, 17, 16, 16,  5, 11,  0,  4, -4, 28, 73),  /* 75: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  8, 10,  3, 63,  0, 17, 12, 16,  3,  4,  0,  8, -8, 28, 73),  /* 76: OKIAGARI P S */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0,  8,  3, 54,  0,  0, 18, 20,  5,  4,  0,  6, -6, 23, 73),  /* 77: ATTACK 10 S: not started by a command */
    ATTR( 32,  0,  0,  3,  0,  1,  1,  8,  8,  3, 63,  0, 17, 16, 20,  4,  4,  0,  8, -8, 28, 51),  /* 78: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    ATTR( 96,  0,  0,  1,  0,  1,  1, 68, 15,  3, 63,  0, 18, 12, 16,  5,  4,  0,  8, -8, 28, 73),  /* 79: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 96,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 19, 22, 18,  1,  4,  0, 10,-10, 23, 73),  /* 80: not used by a script */
    ATTR( 37,  0,  0,  2, 21,  1,  0, 64, 10,  3, 63,  0,  0, 28, 17,  0,  4,  1, 10,-10, 28, 45),  /* 81: not used by a script */
    ATTR( 96,  0,  0,  1,  0,  1,  1, 68, 15,  3, 63,  0, 20,  8, 16,  5,  4,  0,  8, -8, 28, 73),  /* 82: not used by a script */
    ATTR( 32,  0,  0,  3,  0,  1,  1,  8,  8,  3, 63,  0, 21,  8, 20,  4,  4,  0,  8, -8, 28, 51),  /* 83: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU) */
    ATTR( 33,  1,  0,  2,  0,  1,  7, 72,  9,  3, 62,  0, 12, 10, 16,  3,  1,  0,  6, -6, 44, 73),  /* 84: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 37,  1,  0,  2,  0,  1,  7, 80,  9,  3, 62,  0, 12,  8, 16,  3, 12,  0,  6, -4, 44, 73),  /* 85: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 12, 17,  3,  8,  0,  8, -8, 23, 73),  /* 86: L PUNCH C */
    ATTR( 37,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0, 16, 17,  3,  1,  0, 10,-10, 23, 73),  /* 87: L PUNCH C */
    ATTR( 37,  0,  0,  2, 21,  1,  0, 64, 10,  3, 45,  1,  0,  0, 19,  0,  0,  1, 10,-10, 84, 60),  /* 88: ATTACK 1 SP: EX 4(123)6+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  2, 19,  1,  0, 64, 10,  3, 36,  1,  0, 18, 20,  3,  0,  1,  8, -8, 28, 50),  /* 89: CATCH 19 */
    ATTR( 37,  1,  0,  2,  0,  1,  7, 80,  9,  3, 62,  0, 12,  8, 16,  2,  0,  0,  4, -4, 44, 73),  /* 90: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    ATTR( 33,  1,  0,  2,  0,  1,  7, 72,  9,  3, 62,  0, 12, 11, 16,  4,  0,  0,  4, -6, 44, 73),  /* 91: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  1,  0,  2,  0,  1,  3, 68, 10,  3, 62,  0, 12, 11, 26,  4,  0,  0,  6, -8, 39, 73),  /* 92: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  8, 10,  3, 54,  0, 13, 24, 16,  9,  0,  0, 12,-12, 44, 73),  /* 93: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  8, 10,  3, 54,  0,  8,  8, 19,  1,  0,  0, 12,-12, 44, 73),  /* 94: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    ATTR( 37,  0,  0,  2, 19,  1,  0, 64, 10,  3, 36,  0,  0, 18, 20,  3,  0,  1,  8, -8, 28, 50),  /* 95: CATCH 19 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,192, 15,  3, 63,  1,  0, 12, 54,  1,  0,  0,  6, -6, 28, 73),  /* 96: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 10, 17,  2,  5,  0,  8, -8, 23, 73),  /* 97: follow-up of L PUNCH A */
    ATTR( 37,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0, 12, 17,  1,  1,  0, 10,-10, 23, 73),  /* 98: follow-up of L PUNCH A */
};

extern const u16 sean_se_random_0[];

const u16* const sean_se_random_table[1] = {
    sean_se_random_0,  /* 0 */
};

const u16 sean_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
