/*
 * ALEX_ATTR.C  Alex's attack attributes and random sound lists
 *
 * alex_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * alex_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR alex_catt_table[98] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  6, 45,  2,  1,  0,  6, -6, 13, 72),  /* 1: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6, 32,  2,  1,  0,  6, -6, 13, 72),  /* 2: S PUNCH B */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 22, 33,  7,  4,  0,  7, -7, 18, 73),  /* 3: M PUNCH A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 11,  3, 54,  0,  0, 24, 33,  5,  4,  0,  7, -7, 18, 73),  /* 4: UP P GUARD P S */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 10,  3, 63,  0,  0, 22, 33,  5,  4,  0,  7, -7, 18, 73),  /* 5: M PUNCH C, UP P GUARD P S */
    ATTR( 33,  0,  0,  2,  0,  1,  0,  0, 14,  3, 54,  0,  0, 36, 35,  9,  7,  0,  8, -8, 23, 73),  /* 6: not used by a script */
    ATTR( 33,  0,  0,  2,  0,  1,  0,  0, 10,  3, 54,  0,  2, 28, 35,  9,  7,  0, 16,-16, 23, 73),  /* 7: L PUNCH A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0,  9,  3, 63,  0,  0, 24, 33,  3,  4,  0,  7, -7, 18, 73),  /* 8: M PUNCH C, UP P GUARD P S */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0,  8,  3, 54,  0,  2, 28, 35,  8,  7,  0, 12,-12, 23, 73),  /* 9: L PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8, 32,  1,  1,  0,  6, -6, 29, 72),  /* 10: S KICK A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 24, 34,  6,  4,  0,  7, -7, 34, 73),  /* 11: M KICK A */
    ATTR( 38,  0,  0,  2,  0,  1,  0,  0, 14,  3, 63,  0,  0, 36, 36,  7,  7,  0,  8, -8, 39, 73),  /* 12: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 20, 36,  4,  7,  0,  9, -9, 34, 73),  /* 13: M KICK B */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 13,  3, 62,  0,  1, 30, 49, 10,  7,  0, 14,-18,121, 73),  /* 14: L KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6, 33,  2,  1,  0,  6, -6, 13, 72),  /* 15: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 18, 34,  3,  4,  0,  7, -7, 18, 73),  /* 16: KAGAMI P A */
    ATTR( 95,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  4, 16, 36,  2,  8,  0, 12,-12, 23, 73),  /* 17: KAGAMI P A */
    ATTR( 88,  0,  0,  2,  0,  1,  2,  0, 15,  3, 63,  0,  4, 12, 35,  2,  1,  0, 12,-12, 23, 73),  /* 18: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 45,  0,  0,  6, 33,  1,  1,  0,  6, -6, 29, 73),  /* 19: KAGAMI K A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 11,  3, 45,  0,  0, 16, 33,  1,  4,  0,  7, -7, 34, 73),  /* 20: KAGAMI K A, UP P GUARD K S */
    ATTR( 89,  0,  0,  2,  0,  1,  3,  0, 14,  3, 45,  0,  3, 26, 36,  1,  7,  0,  8, -8, 39, 73),  /* 21: KAGAMI K A */
    ATTR( 89,  0,  0,  2,  0,  1,  3,  0,  0,  3, 45,  0,  3, 26, 36,  1,  7,  0,  8, -8, 39, 73),  /* 22: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0,  8, 38,  4,  1,  0,  5, -5, 13, 72),  /* 23: V JUMP P S A, V JUMP P M A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0,  8, 38,  2,  1,  0,  5, -5, 13, 72),  /* 24: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0, 16, 38,  6,  4,  0,  6, -6, 18, 73),  /* 25: V JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 16, 34,  5,  4,  0,  8, -8, 18, 72),  /* 26: FUSHIN P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 28, 34,  5,  4,  0,  8, -8, 18, 73),  /* 27: OKIAGARI P S */
    ATTR( 32,  0,  0,  2, 33,  1,  0, 64, 12,  3, 56,  0,  0,  0, 34,  0,  7,  1, 10,-10, 84, 72),  /* 28: L PUNCH C */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 28, 39,  8,  7,  0,  7, -7, 23, 73),  /* 29: V JUMP P L A */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0,  9,  3, 54,  0,  0, 16, 39,  8,  7,  0,  7, -7, 23, 72),  /* 30: V JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0, 12, 38,  3,  1,  0,  5, -5, 29, 72),  /* 31: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 38,  5,  4,  0,  6, -6, 34, 73),  /* 32: V JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 24, 39,  7,  7,  0,  7, -7,121, 73),  /* 33: V JUMP K L A */
    ATTR( 36,  0,  0,  2, 25,  1,  0,  0, 10,  3, 63,  0,  0, 36, 49, 12, 13,  0, 10,-10,118, 73),  /* 34: CATCH 1 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8, 70,  0),  /* 35: M PUNCH A, M PUNCH C, L PUNCH A +2 */
    ATTR( 91,  0,  0,  2,  2,  1,  0, 64, 10,  3, 63,  0,  6, 38, 34, 10, 11,  0, 10,-10, 63,  0),  /* 36: CATCH 11 */
    ATTR( 91,  0,  0,  2,  0,  1,  0, 64, 10,  3, 63,  0, 15, 32, 34,  9, 11,  0, 10,-10, 62, 73),  /* 37: CATCH 7 */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0, 11, 24, 49,  5,  8,  0, 14,-14, 28, 73),  /* 38: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    ATTR( 34,  1,  0,  2,  0,  1,  3, 72, 11,  7, 62,  0,  0, 24, 55,  3, 10,  0, 10,-10, 23, 73),  /* 39: UP P GUARD P L, ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 97,  0,  0,  2,  0,  1,  0,  0,  6,  3, 63,  0,  5, 28, 34,  8, 13,  0, 12,-12,  0, 55),  /* 40: CATCH 3 */
    ATTR( 36,  0,  0,  2,  1,  1,  0,  0, 11,  3, 63,  0,  0, 10, 44,  2,  1,  0, 12,-12, 71,  0),  /* 41: CATCH 30, CATCH 31, CATCH 32 */
    ATTR( 37,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0,  7, 30, 36,  7,  7,  0, 14,-18, 40, 73),  /* 42: L KICK A */
    ATTR( 32,  0,  0,  1, 35,  1,  0, 64, 10,  3,  0,  0,  0,  0, 34,  0,  4,  1,  8, -8, 66,  0),  /* 43: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) */
    ATTR( 95,  0,  0,  2,  0,  1,  3, 68, 14,  3, 63,  0,  8, 16, 16,  4, 10,  0, 12,-12, 28, 73),  /* 44: ATTACK 9 S: not started by a command */
    ATTR( 32,  0,  0,  1, 36,  1,  0,192, 10,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8, 66,  0),  /* 45: ATTACK 9 S: not started by a command */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  1,  0, 34, 34,  3,  0,  0, 10,-10, 63,  0),  /* 46: CATCH 19 */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  1,  0, 34, 34,  3,  0,  0, 10,-10, 63,  0),  /* 47: CATCH 19 */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 11,  3, 63,  0, 17, 52, 34,  3,  0,  0, 10,-10, 62,  0),  /* 48: CATCH 19 */
    ATTR( 36,  0,  0,  1,  0,  1,  0, 72,  9,  3, 54,  0, 11, 24, 34,  5, 10,  0, 12,-12, 34, 73),  /* 49: not used by a script */
    ATTR( 36,  0,  0,  1,  0,  1,  0, 72,  9,  3, 54,  0, 12, 28, 35,  5, 10,  0, 12,-12, 39, 73),  /* 50: not used by a script */
    ATTR( 36,  0,  0,  1,  0,  1,  0, 72,  9,  3, 54,  0, 13, 32, 36,  5, 10,  0, 12,-12, 44, 73),  /* 51: not used by a script */
    ATTR( 34,  1,  0,  3,  0,  1,  3, 72, 11,  7, 62,  0,  0, 28, 55,  4, 10,  0, 10,-10, 23, 73),  /* 52: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  1,  0,  3,  0,  1,  3, 72, 11,  7, 62,  0,  0, 24, 55,  5, 10,  0, 12,-12, 23, 73),  /* 53: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 91,  0,  0,  2,  0,  1,  0, 64, 10,  3, 63,  0, 16, 36, 34,  9, 11,  0, 10,-10, 62, 73),  /* 54: CATCH 8, CATCH 28 */
    ATTR( 91,  0,  0,  2,  0,  1,  0, 64, 10,  3, 63,  0, 17, 40, 34,  9, 11,  0, 10,-10, 62, 73),  /* 55: CATCH 9 */
    ATTR( 36,  0,  0,  2, 25,  1,  0,192, 10,  3, 63,  1,  0,  8, 34, 10,  0,  0, 10,-10, 23, 73),  /* 56: CATCH 15 */
    ATTR( 36,  0,  0,  2, 25,  1,  0,192, 10,  3, 63,  0,  0, 18, 34, 15,  0,  0, 14,-14, 28, 73),  /* 57: CATCH 15 */
    ATTR( 32,  0,  0,  0,  0,  1,  0,192,  4,  3, 63,  0,  0,  0, 48,  0,  0,  0,  8, -8, 72, 73),  /* 58: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0,192, 12,  3,  0,  0,  0,  0, 34,  0,  0,  1, 10,-10, 66, 73),  /* 59: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    ATTR( 91,  0,  0,  2, 29,  1,  0, 64, 10,  3,  0,  0, 16, 28, 34,  9, 13,  0, 10,-10, 55, 73),  /* 60: CATCH 20 */
    ATTR( 95,  0,  0,  1, 57,  1,  0, 80, 14,  3,  6,  0, 10,  0, 16,  0,  4,  1, 10,-10, 44,  0),  /* 61: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 91,  0,  0,  2, 29,  1,  0, 64, 10,  3,  0,  0, 16, 32, 34,  9, 13,  0, 10,-10, 55, 73),  /* 62: CATCH 21 */
    ATTR( 91,  0,  0,  2, 29,  1,  0, 64, 10,  3,  0,  0, 16, 36, 34,  9, 13,  0, 10,-10, 55, 73),  /* 63: CATCH 22 */
    ATTR( 36,  0,  0,  2,  0,  1,  7,196,  9,  3, 62,  0, 18, 10, 51,  2,  0,  0,  6, -6, 23, 73),  /* 64: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 36,  0,  0,  2,  0,  1,  7,196,  9,  3, 62,  0, 18, 10, 51,  2,  0,  0,  6, -6, 23, 73),  /* 65: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  1,  0,  2,  0,  1,  7,196,  9,  3, 62,  0, 18,  8, 51,  2,  0,  0,  6, -6, 23, 73),  /* 66: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  1,  0,  2,  0,  1,  7,196,  9,  3, 62,  0, 18,  8, 51,  2,  0,  0,  6, -6, 23, 73),  /* 67: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 36,  0,  0,  2,  0,  1,  7,196,  9,  3, 62,  0, 18, 10, 51,  2,  0,  0,  6, -6, 23, 73),  /* 68: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 36,  0,  0,  2,  0,  1,  7,196,  9,  3, 62,  0, 18, 10, 51,  2,  0,  0,  6, -6, 23, 73),  /* 69: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  1,  0,  3,  0,  1,  7,196,  9,  3, 62,  0, 18,  8, 51,  2,  0,  0, 12,-12, 28, 73),  /* 70: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  1,  0,  3,  0,  1,  7,196,  9,  3, 62,  0, 18,  8, 51,  2,  0,  0, 12,-12, 28, 73),  /* 71: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  1,  0,  2,  0,  1,  0,196, 11,  3, 63,  0,  0, 24, 35,  8,  0,  0,  4,-16, 23, 73),  /* 72: not used by a script */
    ATTR( 70,  0,  0,  2,  0,  1,  0, 72,  8,  3, 54,  0, 12, 24, 34,  4, 10,  0, 14,-14, 85, 73),  /* 73: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 9 S: not started by a command */
    ATTR( 70,  0,  0,  2,  0,  1,  0, 72,  8,  3, 54,  0, 13, 28, 35,  5, 10,  0, 14,-14, 85, 73),  /* 74: ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU) */
    ATTR( 70,  0,  0,  2,  0,  1,  0, 72,  8,  3, 54,  0, 14, 32, 36,  6, 10,  0, 14,-14, 85, 73),  /* 75: ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) */
    ATTR( 91,  0,  0,  3,  2,  1,  0,192, 10,  3, 63,  0, 19, 52, 34,  2,  0,  0, 10,-10,  0, 55),  /* 76: CATCH 29 */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  0, 16, 52, 34,  6,  0,  0, 10,-10, 62, 73),  /* 77: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  0,192, 10,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8, 66,  0),  /* 78: ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  0,  0,  1, 36,  1,  0,192, 10,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8, 66,  0),  /* 79: ATTACK 4 S: SA I 360+P (plain script) */
    ATTR( 37,  1,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0,  0, 24, 55,  6, 10,  0, 10,-10, 23, 73),  /* 80: UP P GUARD P L */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  0, 20, 38,  6,  4,  0,  6, -6, 18, 73),  /* 81: ATTACK 9 S: not started by a command */
    ATTR( 91,  0,  0,  2,  2,  1,  0, 64, 10,  3, 63,  0,  6, 44, 34, 10, 11,  0, 10,-10, 63,  0),  /* 82: CATCH 12 */
    ATTR( 91,  0,  0,  2,  2,  1,  0, 64, 10,  3, 63,  0,  6, 50, 34, 10, 11,  0, 10,-10, 63,  0),  /* 83: CATCH 13 */
    ATTR( 32,  1,  0,  1,  0,  1,  1, 80, 11,  7, 62,  0,  0, 20, 55,  5,  0,  0,  6, -6, 23, 73),  /* 84: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 70,  0,  0,  2,  0,  1,  0, 72,  8,  3, 54,  0, 14, 36, 36,  7,  0,  0, 14,-14, 85, 73),  /* 85: ATTACK 8 SP: after [2](789)+K (routine Att_HOMING_JUMP) */
    ATTR( 91,  0,  0,  2, 29,  1,  0, 64, 10,  3,  0,  0, 16, 44, 34,  9,  0,  0, 10,-10, 55, 73),  /* 86: CATCH 23 */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 72, 12,  3, 62,  0,  0, 22, 36,  7, 10,  0, 10,-10, 23, 73),  /* 87: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 72, 12,  3, 62,  0,  0, 26, 36,  8, 10,  0, 12,-12, 23, 73),  /* 88: ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 72, 12,  3, 62,  0,  0, 30, 36,  9, 10,  0, 13,-13, 28, 73),  /* 89: ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 94,  1,  0,  2,  0,  1,  2, 80, 11,  7, 62,  0, 21, 20, 55,  1,  0,  0,  8, -8, 23, 73),  /* 90: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  2,  0,  1,  1, 80, 12,  3, 62,  0,  0, 17, 35,  4,  0,  0, 11,-11, 28, 73),  /* 91: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 80, 12,  3, 62,  0,  0, 17, 36,  6,  0,  0, 14,-16, 28, 73),  /* 92: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  1, 32,  0,  1,  0,  6, -6, 13, 72),  /* 93: not used by a script */
    ATTR( 95,  0,  0,  1, 57,  1,  0, 80, 14,  3, 63,  0, 10,  0, 16,  0,  0,  1, 10,-10, 44,  0),  /* 94: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  1,  0, 26, 34,  3,  0,  0, 10,-10, 63,  0),  /* 95: CATCH 33 */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  1,  0, 24, 34,  2,  0,  0,  7, -7, 63,  0),  /* 96: CATCH 33 */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  0,  0, 36, 34,  5,  0,  0,  8, -8, 63,  0),  /* 97: CATCH 33 */
};

extern const u16 alex_se_random_0[];

const u16* const alex_se_random_table[1] = {
    alex_se_random_0,  /* 0 */
};

const u16 alex_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
