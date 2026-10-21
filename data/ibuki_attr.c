/*
 * IBUKI_ATTR.C  Ibuki's attack attributes and random sound lists
 *
 * ibuki_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * ibuki_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR ibuki_catt_table[178] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6,  0,  2,  1,  0,  6, -6, 13, 72),  /* 1: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  5,  5,  2,  1,  0,  6, -6, 13, 72),  /* 2: S PUNCH B */
    ATTR( 36,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  1, 18,  3,  6,  4,  0,  7, -7, 39, 73),  /* 3: M KICK C */
    ATTR( 36,  0,  0,  1,  0,  1,  0,  0,  8,  3, 54,  0,  2, 16,  3,  6,  4,  0,  7, -7, 39, 73),  /* 4: M KICK C */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 13,  3, 45,  0,  3, 22,  2,  1,  8,  0,  6, -8, 39, 73),  /* 5: KAGAMI K A, UP P GUARD K S */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  4, 24,  4,  6,  8,  0,  7, -7, 39, 73),  /* 6: V JUMP K L A, F JUMP K L A */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0,  9,  3, 54,  0,  5, 20,  2,  6,  8,  0,  7, -7, 39, 73),  /* 7: V JUMP K L A, F JUMP K L A */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0,  7,  3, 54,  0,  6, 18,  1,  5,  8,  0,  7, -7, 39, 73),  /* 8: FUSHIN P S */
    ATTR( 34,  0,  0,  2,  0,  1,  0,  0, 11,  3, 62,  0,  0, 30,  7, 10,  7,  0,  8,-10, 39, 73),  /* 9: L KICK C */
    ATTR( 36,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0,  8,  0,  2,  1,  0,  5, -5, 29, 72),  /* 10: F JUMP K S A */
    ATTR( 36,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 14,  6,  4,  4,  0,  6, -6, 34, 73),  /* 11: F JUMP K M A, FUSHIN P S */
    ATTR( 36,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12,  6,  3,  4,  0,  6, -6, 34, 73),  /* 12: F JUMP K M A, FUSHIN P S */
    ATTR( 35,  0,  0,  1,  0,  1,  0,  0, 14,  3, 62,  0,  0,  6, 54,  2,  4,  0,  7, -9, 18, 73),  /* 13: M PUNCH C, follow-up of S PUNCH A */
    ATTR( 35,  0,  0,  1,  0,  1,  0,  0, 14,  3, 62,  0,  0, 12,  1,  5,  1,  0,  7, -7, 18, 73),  /* 14: M PUNCH C, follow-up of S PUNCH A */
    ATTR( 35,  0,  0,  1,  0,  1,  0,  0, 14,  3, 62,  0,  0, 10,  1,  3,  1,  0,  7, -7, 18, 73),  /* 15: M PUNCH C, follow-up of S PUNCH A */
    ATTR( 33,  0,  0,  1,  0,  1,  0,  0, 11,  3, 62,  0,  0, 16,  2,  6,  4,  0,  7, -7, 18, 73),  /* 16: M PUNCH A, FUSHIN P S */
    ATTR( 33,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 16,  2,  5,  4,  0,  7, -7, 18, 73),  /* 17: M PUNCH A */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0, 13,  3, 62,  0,  0, 12,  1,  4,  7,  0,  8, -8, 23, 73),  /* 18: L PUNCH A */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0, 11,  3, 62,  0,  0, 14,  2,  3,  1,  0,  8, -8, 24, 73),  /* 19: L PUNCH A */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0,  9,  3, 62,  0,  0, 12,  2,  1,  1,  0,  8, -8, 24, 73),  /* 20: L PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 21: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 22: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 23: S KICK B */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 24: S KICK B */
    ATTR( 38,  0,  0,  1,  0,  1,  0,  0, 15,  3, 62,  0,  0, 20,  1,  5,  4,  0,  8,-10, 34, 73),  /* 25: M KICK A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 14,  2,  3,  4,  0,  7, -7, 34, 73),  /* 26: M KICK B */
    ATTR( 95,  0,  0,  2,  0,  1,  1,  0,  0,  3, 62,  0,  8, 14,  2,  4,  1,  0,  8, -8, 39, 73),  /* 27: L KICK A */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 15,  3, 62,  0,  9, 12,  2,  1,  1,  0,  8, -8, 39, 73),  /* 28: L KICK A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 11,  3, 62,  0, 10, 18,  1,  2,  8,  0,  8, -8, 23, 73),  /* 29: L PUNCH B */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 12,  3, 62,  0,  0, 16,  1,  1,  5,  0,  8, -8, 23, 73),  /* 30: L PUNCH B */
    ATTR( 38,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 20,  2,  6,  4,  0,  7, -7, 18, 73),  /* 31: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 73),  /* 32: KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0, 11, 24,  2,  7,  7,  0, 10,-10, 23, 73),  /* 33: KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 14,  3, 63,  0,  0, 22,  1,  7,  7,  0, 10,-10, 23, 73),  /* 34: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 13,  3, 45,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 72),  /* 35: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10,  5,  3,  1,  0,  5, -5, 13, 72),  /* 36: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 16,  5,  5,  4,  0,  6, -6, 18, 73),  /* 37: V JUMP P M A, F JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 14,  6,  4,  4,  0,  6, -6, 18, 73),  /* 38: V JUMP P M A, F JUMP P M A */
    ATTR( 34,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0, 26,  8,  6,  7,  0,  7, -7, 23, 73),  /* 39: V JUMP P L A */
    ATTR( 36,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0, 12,  5,  2,  1,  0,  5, -5, 13, 73),  /* 40: F JUMP P S A */
    ATTR( 36,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0, 12,  5,  3,  1,  0,  5, -5, 13, 72),  /* 41: not used by a script */
    ATTR( 36,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0, 12,  5,  2,  1,  0,  5, -5, 13, 72),  /* 42: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0, 10,  5,  2,  1,  0,  5, -5, 29, 72),  /* 43: V JUMP K S A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12,  5,  2,  1,  0,  5, -5, 29, 72),  /* 44: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12,  5,  2,  1,  0,  5, -5, 29, 72),  /* 45: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 20,  2,  1,  4,  0,  7, -7, 18, 73),  /* 46: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 13,  3, 45,  0,  0, 16,  2,  1,  4,  0,  7, -7, 34, 73),  /* 47: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0, 28, 14,  0,  3,  1,  0, 10,-11, 23, 73),  /* 48: follow-up of M PUNCH C, UP P GUARD P S */
    ATTR( 96,  1,  0,  2,  0,  1,  0,  0, 14,  3, 62,  0,  8, 10,  2,  1,  8,  0,  4, -4, 23, 73),  /* 49: L KICK A */
    ATTR( 37,  0,  0,  2, 34,  1,  0, 64, 10,  3, 56,  0,  0,  0,  1,  0,  0,  1, 10, -6, 66,  0),  /* 50: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  0,  0,  2,  0,  1,  0, 64, 12,  3,  0,  0, 12, 36, 34,  4, 10,  0, 14,-14,  0, 78),  /* 51: CATCH 8 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,192, 10,  3, 63,  0,  0,  0,  1,  0,  0,  2,  0, -2, 66,  0),  /* 52: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 94,  0,  0,  2,  0,  1,  0,192, 12,  3,  0,  0, 18, 88, 35,  6,  0,  0, 18,-18,  0, 79),  /* 53: CATCH 11 */
    ATTR( 94,  0,  0,  2, 18,  1,  0, 64,  0,  3,  0,  0, 13, 32, 34,  8, 13,  0, 10, -4,  0, 73),  /* 54: CATCH 5 */
    ATTR( 36,  0,  0,  2,  0,  1,  7,196, 10,  3, 54,  0,  0, 12,  1,  1,  0,  0,  8,-12, 44, 73),  /* 55: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  7,196, 12,  3, 63,  0,  0, 12,  0,  1,  0,  0,  6, -8, 44, 73),  /* 56: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  7,196,  4,  3, 63,  0, 17, 12,  2,  1,  0,  0,  4,-16, 44, 73),  /* 57: not used by a script */
    ATTR( 37,  1,  0,  1, 14,  1,  2, 72, 14,  3, 63,  0, 16,  8,  0,  1, 11,  0,  2, -4, 32, 73),  /* 58: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    ATTR( 38,  1,  0,  2, 15,  1,  2, 72, 14,  3, 63,  0, 16,  4,  1,  1,  1,  0,  2, -4, 36, 73),  /* 59: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 35,  0,  0,  2, 16,  1,  2, 72, 15,  3, 63,  0, 16,  4,  3,  2,  1,  0,  3, -3, 40, 73),  /* 60: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 72,  0,  3, 63,  0, 16, 16,  6,  2,  1,  0,  4, -6, 64, 73),  /* 61: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  3, 72,  0,  3, 63,  0, 14, 12,  6,  1,  1,  0,  4, -8, 64, 73),  /* 62: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    ATTR( 38,  1,  0,  2, 12,  1,  2, 72, 14,  3, 63,  0, 16, 10,  1,  1, 11,  0,  2, -4, 32, 73),  /* 63: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2, 13,  1,  3, 72,  0,  3, 63,  0, 16, 18,  8,  3,  1,  0,  4, -8, 64, 73),  /* 64: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  3, 72,  0,  3, 63,  0, 14, 16,  8,  2,  1,  0,  5, -9, 64, 73),  /* 65: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 38,  1,  0,  2, 10,  1,  2, 72, 13,  3, 63,  0, 14, 12,  2,  1, 11,  0,  2, -4, 32, 73),  /* 66: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2, 11,  1,  3, 72, 15,  3, 63,  0, 14, 20,  8,  4,  1,  0,  4, -8, 64, 73),  /* 67: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  3, 72,  0,  3, 63,  0, 14, 20,  8,  2,  1,  0,  5, -9, 64, 73),  /* 68: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0,  6,  3, 63,  0, 15, 24, 16,  6, 13,  1, 10,-10,  0, 77),  /* 69: CATCH 1 */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3,  0,  0,  0,  0, 16,  0,  0,  1, 10,-10,  0,  0),  /* 70: M PUNCH A, M PUNCH C, L PUNCH A +5 */
    ATTR( 95,  0,  0,  2,  0,  1,  7,196,  0,  3, 63,  0, 21, 12,  2,  1,  0,  0,  6,-12, 44, 73),  /* 71: not used by a script */
    ATTR( 34,  0,  0,  2,  0,  1,  1,  0, 14,  3, 63,  0,  0, 22,  3,  6,  7,  0,  8,-12, 44, 73),  /* 72: L KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A, OKIAGARI P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 64, 10,  3,  0,  0,  0,  0, 34,  0,  0,  2, 10,-10,  0,  0),  /* 73: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 12,  3, 62,  0,  0, 12,  4,  6,  5,  0,  8,-12, 23, 73),  /* 74: not used by a script */
    ATTR( 33,  0,  0,  2,  0,  1,  0,  0, 12,  3, 62,  0,  0, 12,  2,  6,  5,  0,  6,-20, 23, 73),  /* 75: L PUNCH B */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  4, 12,  3, 62,  0,  0,  4,  4,  2,  5,  0,  2, -8, 23, 73),  /* 76: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0,  8,  0,  1, 12,  0,  1, -4, 39, 73),  /* 77: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 10,  0,  1,  1,  0,  1, -4, 39, 73),  /* 78: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 12,  0,  1,  1,  0,  1, -4, 39, 73),  /* 79: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0,  8,  0,  1, 12,  0,  2, -8, 39, 73),  /* 80: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 68,  9,  3, 54,  0,  5,  8,  0,  3, 12,  0,  6,-12, 39, 73),  /* 81: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  5, 16,  6,  3,  1,  0, 10,-14, 44, 73),  /* 82: ATTACK 2 S: 421+K light (routine Att_PL07_AT2) */
    ATTR( 37,  0,  0,  2, 45,  1,  7, 16, 12,  7, 63,  0, 22,  4, 54,  0,  0,  0,  0, -2, 23, 73),  /* 83: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 32,  0,  0,  2, 46,  1,  7, 16, 12,  7, 63,  0, 22,  4,  1,  0,  0,  0,  0, -2, 23, 73),  /* 84: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 38,  0,  0,  2, 50,  1,  7, 16, 12,  7, 63,  0, 22,  6,  0,  0,  0,  0,  0, -2, 23, 73),  /* 85: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 33,  0,  0,  2, 48,  1,  7, 16, 12,  7, 63,  0, 22,  6,  0,  0,  0,  0,  0, -2, 23, 73),  /* 86: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 35,  0,  0,  2, 47,  1,  7, 16, 12,  7, 63,  0, 22,  8,  0,  0,  0,  0,  0, -2, 23, 73),  /* 87: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 93,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 18, 12,  0,  0,  0,  0,  6, -5, 28, 73),  /* 88: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  5, 20,  7,  3,  1,  0, 12,-12, 44, 73),  /* 89: ATTACK 2 M: 421+K medium (routine Att_PL07_AT2) */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  5, 26,  8,  4,  1,  0, 14,-14, 44, 73),  /* 90: ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) */
    ATTR( 93,  0,  0,  2,  0,  1,  0, 64, 12,  3,  0,  0, 12, 40, 34,  5, 10,  0, 15,-15,  0, 78),  /* 91: CATCH 9 */
    ATTR( 93,  0,  0,  2,  0,  1,  0, 64, 12,  3,  0,  0, 12, 44, 34,  6, 10,  0, 16,-16,  0, 78),  /* 92: CATCH 10 */
    ATTR( 38,  1,  0,  2,  6,  1,  7,196, 13,  3, 63,  0, 14,  8,  3,  1,  0,  0,  4, -6, 64, 73),  /* 93: ATTACK 6 S: not started by a command */
    ATTR( 38,  1,  0,  2,  7,  1,  7,196, 14,  3, 63,  0, 16,  8,  4,  1,  0,  0,  4, -6, 64, 73),  /* 94: ATTACK 6 S: not started by a command */
    ATTR( 35,  0,  0,  2,  8,  1,  7,196, 15,  3, 63,  0, 16,  8,  4,  1,  0,  0,  4, -6, 64, 73),  /* 95: ATTACK 6 S: not started by a command */
    ATTR( 95,  0,  0,  2,  9,  1,  7,196, 15,  3, 63,  0, 14, 20,  4,  2,  0,  0,  8, -8, 64, 73),  /* 96: ATTACK 6 S: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  7,196,  0,  3, 63,  0, 14, 20,  5,  2,  0,  0,  8, -8, 64, 73),  /* 97: ATTACK 6 S: not started by a command */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 68, 12,  3, 45,  0,  0, 12, 54,  1,  4,  2,  2, -2, 39, 73),  /* 98: ATTACK 4 S: 236+K light (routine Att_PL07_AT1) */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 68, 12,  3, 45,  0,  0, 12, 54,  1,  4,  2,  4, -2, 39, 73),  /* 99: ATTACK 4 M: 236+K medium (routine Att_PL07_AT1) */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 68, 12,  3, 45,  0,  0, 16,  2,  1,  4,  0,  8, -8, 39, 73),  /* 100: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 68, 12,  3, 45,  0,  0, 12, 54,  1,  4,  2,  4, -2, 39, 73),  /* 101: ATTACK 4 L: 236+K heavy (routine Att_PL07_AT1), ATTACK 4 SP: EX 236+KK (routine Att_PL07_AT1) */
    ATTR( 89,  0,  0,  2,  0,  1,  1, 68, 13,  3, 45,  0,  3, 24,  3,  1,  4,  0, 10,-10, 44, 73),  /* 102: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 45,  0,  0, 14,  0,  1, 14,  0,  6, -6, 39, 73),  /* 103: KAGAMI K A */
    ATTR( 39,  0,  0,  2,  0,  1,  7,196,  9,  3, 54,  0, 19, 12, 54,  2,  0,  0,  6, -8, 28, 73),  /* 104: ATTACK 11 M: after SA I air 23623+P (routine Att_PL07_SA3), ATTACK 11 L: after SA I air 23623+P (routine Att_PL07_SA3), ATTACK 11 SP: after SA I air 23623+P (routine Att_PL07_SA3) +6 */
    ATTR( 96,  0,  0,  2, 43,  1,  1,  0,  9,  3, 63,  0, 20, 16,  0,  4, 13,  0,  6, -6, 44, 51),  /* 105: CATCH 16 */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 54,  0,  0, 14,  6,  4,  4,  0,  6, -6, 34, 72),  /* 106: V JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 54,  0,  0, 12,  6,  4,  4,  0,  6, -6, 34, 72),  /* 107: V JUMP K M A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 16,  0,  3,  5,  0,  7, -7, 18, 73),  /* 108: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8,  0,  0,  0,  0,  6, -6, 13, 72),  /* 109: APPEAR 1 */
    ATTR( 38,  0,  0,  1,  0,  1,  0,  0, 15,  3, 63,  0,  0, 20,  1,  0,  0,  0,  7, -7, 34, 73),  /* 110: APPEAR 1 */
    ATTR( 35,  0,  0,  2,  0,  1,  0,208, 12,  3, 63,  0,  0,  8, 54,  1,  0,  0,  2, -2, 23, 73),  /* 111: not used by a script */
    ATTR( 89,  0,  0,  2,  0,  1,  0, 80, 13,  3, 45,  0,  3, 14,  3,  1,  1,  0,  6,-10, 39, 73),  /* 112: ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 10,  1,  1,  1,  0,  7, -7, 34, 72),  /* 113: S KICK B */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 10,  1,  1,  1,  0,  7, -7, 34, 72),  /* 114: S KICK B */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 54,  0,  0, 20,  6,  5,  4,  0,  6, -6, 18, 73),  /* 115: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 54,  0,  0, 20,  6,  4,  4,  0,  6, -6, 18, 73),  /* 116: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 11,  3, 54,  0,  4, 22,  4,  6,  5,  0,  7, -7, 39, 73),  /* 117: not started by a command */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0,  9,  3, 54,  0,  5, 20,  2,  6,  5,  0,  7, -7, 39, 73),  /* 118: not started by a command */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0,  7,  3, 54,  0,  6, 20,  1,  5,  5,  0,  7, -7, 39, 73),  /* 119: not started by a command */
    ATTR( 37,  0,  0,  2,  0,  1,  0,200, 11,  3, 62,  0, 10, 24, 54,  1,  0,  0,  8,-20, 28, 73),  /* 120: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  0,  0,  2,  0,  1,  0,200, 14,  3, 62,  0,  0, 12, 54,  3,  0,  0,  8,-18, 44, 73),  /* 121: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 38,  0,  0,  2,  0,  1,  0,200, 15,  3, 62,  0,  0,  6, 54,  2,  0,  0,  6, -8, 44, 73),  /* 122: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 38,  1,  0,  2,  0,  1,  7,200, 14,  3, 62,  0,  8, 12, 54,  1,  0,  0,  5, -5, 23, 73),  /* 123: not used by a script */
    ATTR( 95,  0,  0,  3,  0,  1,  0,200,  0,  3, 62,  0, 21, 20,  0,  2,  0,  0,  9, -9, 44, 73),  /* 124: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 35,  0,  0,  2,  0,  1,  0,200,  0,  3, 62,  0,  9, 20,  0,  4,  0,  0,  9, -9, 44, 73),  /* 125: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 13,  3, 45,  0,  3,  8,  3,  1,  1,  0,  6, -8, 39, 73),  /* 126: follow-up of M PUNCH C, L PUNCH A */
    ATTR( 36,  0,  0,  1,  0,  1,  0,  0, 13,  3, 54,  0,  0, 10,  6,  4,  1,  0,  6, -6, 34, 73),  /* 127: follow-up of V JUMP P L A, F JUMP K S A */
    ATTR( 36,  0,  0,  1,  0,  1,  0,  0, 12,  3, 54,  0,  0,  8,  6,  3,  1,  0,  6, -6, 34, 73),  /* 128: follow-up of V JUMP P L A, F JUMP K S A */
    ATTR( 96,  0,  0,  2, 44,  1,  1,  0,  9,  3, 63,  0, 20, 16,  0,  4, 13,  0,  6, -6, 44, 51),  /* 129: CATCH 16 */
    ATTR( 37,  0,  0,  2, 49,  1,  7, 16, 12,  7, 63,  0, 22,  4, 54,  0,  0,  0,  0, -2, 28, 73),  /* 130: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 33,  0,  0,  2, 52,  1,  7, 16, 12,  7, 63,  0, 22,  6,  0,  0,  0,  0,  0, -2, 23, 73),  /* 131: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 35,  0,  0,  2, 51,  1,  7, 16, 12,  7, 63,  0, 22,  8,  0,  0,  0,  0,  0, -2, 23, 73),  /* 132: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 34,  0,  0,  2,  0,  1,  0,  0, 11,  3, 54,  0,  0, 20,  8,  6,  6,  0,  7, -7, 23, 73),  /* 133: follow-up of F JUMP P S A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,196, 13,  3, 62,  0,  0,  6, 54,  2,  0,  0,  6, -8, 40, 73),  /* 134: after SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 22,  4, 54,  0,  0,  0,  0, -2, 23, 73),  /* 135: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 32,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 22,  4,  1,  0,  0,  0,  0, -2, 23, 73),  /* 136: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 38,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 22,  6,  0,  0,  0,  0,  0, -2, 23, 73),  /* 137: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 33,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 22,  6,  1,  0,  0,  0,  0, -2, 23, 73),  /* 138: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 35,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 22,  8,  0,  0,  0,  0,  0, -2, 23, 73),  /* 139: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 38,  0,  0,  1,  0,  1,  0,  0, 15,  3, 62,  0,  0, 10,  1,  3,  1,  0,  8,-10, 34, 73),  /* 140: follow-up of S KICK A */
    ATTR( 34,  0,  0,  2,  0,  1,  0,  0, 14,  3, 62,  0,  0, 16,  3,  3,  4,  0,  7,-10, 44, 73),  /* 141: follow-up of M KICK A */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 68, 12,  3, 62,  0,  0, 12,  0,  1,  1,  0,  2, -8, 39, 73),  /* 142: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 14,  0,  2,  1,  0,  2, -8, 39, 73),  /* 143: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 10,  0,  1, 12,  0,  2, -9, 44, 73),  /* 144: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 14,  0,  1,  1,  0,  2, -9, 44, 73),  /* 145: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 14,  0,  2,  1,  0,  2, -9, 44, 73),  /* 146: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 68,  9,  3, 54,  0,  5,  8,  0,  3,  0,  0,  6,-12, 39, 73),  /* 147: ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  5, 30,  8,  4,  0,  0, 15,-15, 44, 73),  /* 148: ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    ATTR( 38,  1,  0,  2, 10,  1,  2, 72, 13,  3, 63,  0,  0, 12,  2,  1,  0,  0,  2, -5, 32, 73),  /* 149: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 38,  1,  0,  2, 15,  1,  2, 72, 14,  3, 63,  0,  0,  4,  5,  1,  0,  0,  2, -5, 36, 73),  /* 150: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 35,  0,  0,  2, 16,  1,  1, 72, 15,  3, 63,  0,  0,  4,  5,  2,  0,  0,  3, -7, 40, 73),  /* 151: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2, 11,  1,  1, 72, 15,  3, 63,  0,  0, 20,  5,  3,  0,  0,  4, -8, 64, 73),  /* 152: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 72,  0,  3, 63,  0,  0, 20,  5,  3,  0,  0,  5, -9, 64, 73),  /* 153: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 10,  1,  1,  0,  0,  1, -3, 39, 73),  /* 154: EX 214+KK (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0, 72, 12,  3, 62,  0,  0, 10,  1,  1,  0,  0,  1, -3, 39, 73),  /* 155: after 214+K (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  1,  0,  2,  0,  1,  0, 72, 12,  3, 62,  0, 24, 20,  4,  1,  0,  0,  1, -3, 39, 73),  /* 156: after 214+K (routine Att_CHOUCHUURENGEKI) */
    ATTR( 36,  0,  0,  0, 71,  1,  0,  0, 13,  1, 63,  1,  0,  0,  1,  0,  0,  2, 10,-10, 66,  0),  /* 157: not started by a command */
    ATTR( 36,  0,  0,  0,  0,  1,  0, 64, 13,  1, 63,  0, 23,  1, 52,  4,  4,  0,  1, -1,  0, 80),  /* 158: not used by a script */
    ATTR( 36,  0,  0,  3,  0,  1,  0, 64, 13,  1, 63,  0,  0,  1, 52,  4,  4,  0,  1,-20,  0, 80),  /* 159: CATCH 20 */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 72, 12,  3, 45,  0,  0, 10,  1,  1,  0,  0,  1, -3, 39, 73),  /* 160: after 214+K (routine Att_CHOUCHUURENGEKI) */
    ATTR( 89,  0,  0,  2,  0,  1,  0, 72, 13,  3, 45,  0, 25, 18,  3,  1,  0,  0,  8, -8, 39, 73),  /* 161: after 214+K (routine Att_CHOUCHUURENGEKI) */
    ATTR( 94,  0,  0,  3, 18,  1,  7, 64,  0,  3,  0,  1, 26, 10, 34,  3,  0,  0,  2, -8,  0, 73),  /* 162: CATCH 22 */
    ATTR( 32,  0,  0,  1,  0,  1,  7, 64, 10,  3,  0,  1,  0,  0, 34,  0,  0,  2, 10,-10,  0,  0),  /* 163: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  7, 64, 10,  3,  0,  1,  0,  0, 34,  0,  0,  1, 10,-10,  0,  0),  /* 164: CATCH 22, CATCH 23 */
    ATTR( 94,  0,  0,  3, 18,  1,  7, 64,  0,  3,  0,  1, 26, 12, 34,  3,  0,  0,  2, -8,  0, 73),  /* 165: CATCH 23 */
    ATTR( 94,  0,  0,  1, 18,  1,  7, 64,  0,  3,  0,  0, 27, 18, 34,  3,  0,  0,  8,-14,  0, 73),  /* 166: CATCH 24 */
    ATTR( 93,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 18, 12,  0,  0,  0,  0,  8, -7, 28, 73),  /* 167: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 93,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 18, 12,  0,  0,  0,  0, 10, -9, 28, 73),  /* 168: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 93,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 18, 12,  0,  0,  0,  0, 16,-15, 28, 73),  /* 169: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 93,  0,  0,  2,  0,  1,  7, 16, 12,  7, 63,  0, 18, 12,  0,  0,  0,  0, 20,-19, 28, 73),  /* 170: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 12,  0,  1,  1,  0,  7, -9, 18, 73),  /* 171: follow-up of KAGAMI K A */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0, 11, 20,  2,  6,  4,  0, 10,-10, 23, 73),  /* 172: follow-up of follow-up of KAGAMI K A */
    ATTR( 38,  1,  0,  2, 15,  1,  2, 72, 14,  3, 63,  0, 16,  4,  2,  1,  1,  0,  2, -4, 36, 73),  /* 173: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 36,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  1, 14,  3,  6,  1,  0,  7, -7, 39, 73),  /* 174: follow-up of M KICK B */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0, 11, 20,  2,  6,  1,  0, 10,-10, 23, 73),  /* 175: follow-up of KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 14,  3, 63,  0,  0, 20,  1,  6,  1,  0, 10,-10, 23, 73),  /* 176: follow-up of KAGAMI P A */
    ATTR( 34,  0,  0,  2,  0,  1,  1,  0, 14,  3, 62,  0,  0, 16,  3,  6,  1,  0,  8,-12, 44, 73),  /* 177: follow-up of follow-up of M PUNCH C, L PUNCH A */
};

extern const u16 ibuki_se_random_0[];

const u16* const ibuki_se_random_table[1] = {
    ibuki_se_random_0,  /* 0 */
};

const u16 ibuki_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
