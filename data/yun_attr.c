/*
 * YUN_ATTR.C  Yun's attack attributes and random sound lists
 *
 * yun_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * yun_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR yun_catt_table[157] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  1,  0, 14,  3, 63,  0, 15, 10,  2,  4,  4,  0,  4, -4, 34, 73),  /* 1: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  1,  0, 15,  3, 62,  0, 18, 16,  2,  4,  4,  0,  6, -6, 34, 73),  /* 2: M KICK A, follow-up of S KICK A, atca 212 */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8,  0,  3,  1,  0,  8, -8, 13, 72),  /* 3: UP P GUARD P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 16,  0,  5,  4,  0, 10,-10, 18, 73),  /* 4: UP P GUARD P M */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 24,  0,  4,  7,  0, 10,-10, 23, 73),  /* 5: UP P GUARD P L */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 72),  /* 6: S PUNCH A */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 14,  3, 62,  0,  0, 10,  3,  2,  4,  0,  7, -7, 18, 73),  /* 7: M PUNCH B */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 12,  1,  2,  4,  0,  7, -7, 18, 73),  /* 8: M PUNCH A */
    ATTR( 38,  0,  0,  1,  0,  1,  3,  0, 14,  3, 62,  0,  0,  8,  3,  3,  8,  0,  8, -8, 23, 73),  /* 9: L PUNCH A */
    ATTR( 32,  0,  0,  2,  0,  1,  2,  0, 13,  3, 62,  0, 13, 26,  4,  7,  7,  0,  8, -8, 23, 73),  /* 10: L PUNCH B */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3, 62,  0, 14, 10, 62,  2,  1,  0, 12,-12, 23, 73),  /* 11: follow-up of M PUNCH A, M PUNCH B */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  8,  0,  2,  1,  0,  6, -6, 29, 72),  /* 12: S KICK A, follow-up of S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  1,  0,  0, 15,  0,  6, -6, 13, 72),  /* 13: not started by a command */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 72),  /* 14: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 11,  3, 45,  0,  0,  6,  0,  1,  1,  0,  6, -6, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 16,  0,  5,  4,  0,  8, -8, 23, 73),  /* 16: FUSHIN P S */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 14,  3, 63,  0,  0, 32,  3,  4,  7,  0, 10,-10, 39, 73),  /* 17: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 11,  3, 54,  0,  0, 16,  3,  5,  4,  0, 10,-10, 39, 73),  /* 18: M KICK C */
    ATTR( 40,  0,  0,  2,  0,  1,  3,  0, 10,  3, 54,  0,  3, 36,  3,  4,  7,  0,  8, -8, 39, 73),  /* 19: not used by a script */
    ATTR( 93,  1,  0,  2,  0,  1,  2, 72, 13,  3, 62,  0,  4, 20,  4,  4, 12,  0,  6, -6, 28, 73),  /* 20: ATTACK 4 S: not started by a command */
    ATTR( 93,  1,  0,  2,  0,  1,  2, 72, 12,  3, 62,  0,  4, 20,  4,  2, 12,  0,  6, -6, 28, 73),  /* 21: ATTACK 4 S: not started by a command */
    ATTR(106,  0,  0,  0, 31,  1,  0, 72, 11,  7, 62,  0,  5, 36,  3, 11, 10,  0, 10,-12, 87, 73),  /* 22: ATTACK 2 S: not started by a command */
    ATTR(106,  0,  0,  0,  0,  1,  0, 72, 12,  7, 62,  0,  5, 28,  3,  8, 10,  0,  6, -8, 23, 73),  /* 23: ATTACK 2 S: not started by a command */
    ATTR( 34,  0,  0,  2,  0,  1,  7,196, 13,  3, 63,  0,  6, 16,  3,  1,  0,  0,  6, -6, 39, 73),  /* 24: ATTACK 5 S: not started by a command */
    ATTR( 34,  0,  0,  2,  0,  1,  7,196, 14,  3, 63,  0,  6, 16,  3,  1,  0,  0,  6, -6, 39, 73),  /* 25: ATTACK 5 S: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  7,196, 15,  3, 63,  0,  7, 20,  3,  1,  0,  0, 12,-12, 44, 73),  /* 26: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  3,196, 14,  3, 63,  0,  7, 20,  3,  1,  0,  0, 10,-10, 44, 73),  /* 27: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    ATTR( 96,  1,  0,  1,  0,  1,  0, 68, 15,  3, 63,  0,  8, 16,  3,  3, 11,  0,  8, -8, 44, 73),  /* 28: ATTACK 3 S: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 68,  0,  3, 63,  0,  8, 12,  3,  2,  1,  0, 10,-10, 44, 73),  /* 29: ATTACK 3 S: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 68,  0,  3, 63,  0,  9, 10,  3,  2,  1,  0, 10,-10, 40, 73),  /* 30: ATTACK 3 S: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0,  8,  5,  3,  1,  0,  5, -5, 13, 72),  /* 31: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 16,  6,  5,  4,  0,  6, -6, 18, 73),  /* 32: V JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 24,  7,  7,  7,  0,  7, -7, 23, 73),  /* 33: V JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 13,  3, 54,  0,  0,  8,  5,  2,  1,  0,  5, -5, 29, 72),  /* 34: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 14,  6,  4,  4,  0,  6, -6, 34, 73),  /* 35: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 22,  7,  6,  7,  0,  7, -7, 39, 73),  /* 36: V JUMP K L A, F JUMP K L A */
    ATTR( 32,  1,  0,  1,  0,  1,  0,200, 13,  3, 62,  0, 10, 14,  0,  1,  0,  0,  1, -8, 23, 73),  /* 37: ATTACK 7 S: not started by a command, not started by a command */
    ATTR( 32,  1,  0,  0,  0,  1,  0,200, 14,  3, 62,  0, 10, 14,  0,  0,  0,  0,  1, -8, 23, 73),  /* 38: ATTACK 7 S: not started by a command, not started by a command */
    ATTR( 37,  1,  0,  1,  0,  1,  0,200, 12,  3, 62,  0, 10, 12,  0,  2,  0,  0,  1, -8, 23, 73),  /* 39: ATTACK 8 S: not started by a command, not started by a command */
    ATTR( 32,  1,  0,  2,  0,  1,  0,200, 13,  3, 62,  0, 31, 12,  5,  0,  0,  0,  1, -8, 24, 73),  /* 40: ATTACK 8 S: not started by a command, not started by a command */
    ATTR( 35,  0,  0,  1,  0,  1,  1,  0,  0,  3, 62,  0,  0, 12,  3,  3,  1,  0,  8, -8, 23, 73),  /* 41: L PUNCH A */
    ATTR( 93,  0,  0,  2,  0,  1,  0,  0, 10,  3, 62,  0, 21, 20,  2,  8,  7,  0,  8, -8, 39, 73),  /* 42: L KICK A */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 64, 12,  3,  0,  0,  0,  0, 18,  0,  0,  2, 10,-14,  0,  0),  /* 43: ATTACK 9 S: not started by a command, ATTACK 13 L: not started by a command */
    ATTR( 96,  0,  0,  0, 28,  1,  3,  0, 14,  3, 63,  0, 17,  8, 16,  2,  1,  0,  8, -8, 39, 73),  /* 44: CATCH 4, CATCH 7, CATCH 8 +1 */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 14,  0,  2,  4,  0,  7, -7, 18, 73),  /* 45: KAGAMI P A */
    ATTR( 38,  0,  0,  1,  0,  1,  3,  0, 13,  3, 63,  0,  0,  6,  0,  1,  8,  0, -6, -6, 18, 73),  /* 46: KAGAMI P A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 13,  3, 63,  0,  0, 16,  0,  2,  1,  0,  9, -9, 23, 73),  /* 47: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 45,  0,  0, 10,  0,  1,  4,  0,  7, -7, 34, 73),  /* 48: KAGAMI K A */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0,  0,  3, 45,  0,  2, 18,  2,  1,  7,  0,  4, -4, 35, 73),  /* 49: not used by a script */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 13,  3, 45,  0,  1, 18,  2,  1,  7,  0,  4, -4, 39, 73),  /* 50: KAGAMI K A */
    ATTR( 89,  0,  0,  1,  0,  1,  0,  0, 11,  3, 45,  0,  2, 18,  2,  1,  7,  0,  4, -4, 35, 73),  /* 51: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0,  3,  3, 63,  0,  0,  0, 48,  0,  0,  0,  8, -8,  0,  0),  /* 52: CATCH 1, CATCH 5 */
    ATTR( 37,  0,  0,  1,  0,  1,  0,196, 12,  3, 63,  0,  0, 16, 53,  2,  0,  0,  8,-10, 39, 73),  /* 53: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  7,208, 14,  3, 63,  0,  8,  4, 48,  1,  0,  0,  2, -2, 44, 73),  /* 54: ATTACK 13 SP: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  7,208, 15,  3, 63,  0,  8,  6,  3,  0,  0,  0,  2, -2, 44, 73),  /* 55: ATTACK 13 SP: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  7,208, 15,  3, 63,  0,  9,  6,  3,  0,  0,  0, 16,-16, 44, 73),  /* 56: ATTACK 13 SP: not started by a command */
    ATTR( 96,  1,  0,  1,  0,  1,  0, 68, 15,  3, 63,  0,  8, 16,  3,  4, 11,  0,  8, -8, 44, 73),  /* 57: ATTACK 3 M: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 68,  0,  3, 63,  0,  8, 14,  3,  5,  1,  0, 10,-10, 44, 73),  /* 58: ATTACK 3 M: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 68,  0,  3, 63,  0,  9, 12,  3,  4,  1,  0, 10,-10, 44, 73),  /* 59: ATTACK 3 M: not started by a command */
    ATTR( 96,  1,  0,  1,  0,  1,  0, 68, 15,  3, 63,  0,  8, 16,  3,  5, 11,  0,  8, -8, 44, 73),  /* 60: ATTACK 3 L: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 68,  0,  3, 63,  0,  8, 16,  3,  2,  1,  0, 10,-10, 44, 73),  /* 61: ATTACK 3 L: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 68,  0,  3, 63,  0,  9, 14,  3,  1,  1,  0, 10,-10, 44, 73),  /* 62: ATTACK 3 L: not started by a command */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0,  2,  0,  0,  1, 10,-10, 70, 73),  /* 63: M KICK A, M KICK C, L KICK A +1 */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0,  2,  3,  0,  0,  0,  0,  2,  0,  0,  2, 10,-10, 70, 51),  /* 64: M PUNCH A, M PUNCH B, L PUNCH A +2 */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0,  8,  5,  3,  1,  0,  7, -7, 13, 72),  /* 65: F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 16,  6,  4,  4,  0,  6, -6, 18, 73),  /* 66: F JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 20,  7,  6,  7,  0,  7, -7, 23, 73),  /* 67: F JUMP P L A, ATTACK 12 L: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 13,  3, 54,  0,  0,  8,  5,  2,  1,  0,  5, -5, 29, 72),  /* 68: F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 14,  6,  4,  4,  0,  6, -6, 34, 73),  /* 69: V JUMP K M A, F JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 18,  7,  6,  7,  0,  7, -7, 39, 73),  /* 70: not used by a script */
    ATTR( 36,  0,  0,  1,  0,  1,  3,  0,  9,  3, 54,  0,  0, 16,  3,  5,  4,  0,  6, -6, 34, 73),  /* 71: F JUMP K S B, F JUMP K M B, F JUMP K L B */
    ATTR( 32,  0,  0,  1,  0,  1,  0,208, 13,  3, 54,  0,  0, 24,  7,  1,  0,  0, 12,-12, 39, 73),  /* 72: ATTACK 5 S: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 18,  7,  3,  3,  0, 11,-11, 23, 73),  /* 73: follow-up of V JUMP P S A, F JUMP P S A */
    ATTR( 95,  0,  0,  2,  0,  1,  0,  0, 13,  3, 54,  0,  7,  8,  5,  1,  0,  0,  8, -8, 40, 73),  /* 74: not used by a script */
    ATTR( 95,  0,  0,  2,  0,  1,  0,  0, 13,  3, 54,  0,  7, 12,  6,  1,  0,  0,  8, -8, 40, 73),  /* 75: ATTACK 13 SP: not started by a command */
    ATTR( 93,  0,  0,  2, 31,  1,  0,  0, 11,  7, 62,  0,  5, 12,  3,  3,  1,  0, 12,-14, 87, 73),  /* 76: follow-up of follow-up of M PUNCH A, M PUNCH B */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0,  0,  3, 62,  0,  0, 10,  2,  2,  1,  0,  6, -6, 34, 73),  /* 77: follow-up of S KICK A */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 10,  3, 62,  0,  0, 12, 20,  4,  8,  0,  8, -8, 39, 73),  /* 78: follow-up of follow-up of S KICK A */
    ATTR( 96,  0,  0,  3,  0,  1,  7,192, 14,  3, 63,  0, 15,  8,  2,  0,  0,  0,  4, -8, 39, 73),  /* 79: not used by a script */
    ATTR( 93,  0,  0,  2, 31,  1,  0,200, 11,  7, 62,  0,  5, 24,  3,  0,  0,  0, 12,-14, 87, 73),  /* 80: ATTACK 11 M: not started by a command */
    ATTR( 96,  0,  0,  3,  0,  1,  7,196, 15,  3, 63,  0,  8,  8,  3,  0,  0,  0,  4, -5, 44, 73),  /* 81: ATTACK 12 S: not started by a command, ATTACK 11 SP: not started by a command, ATTACK 11 L: not started by a command */
    ATTR(100,  1,  0,  2,  0,  1,  0,200, 13,  3, 62,  0, 29,  8,  3,  1,  0,  0,  4, -4, 40, 73),  /* 82: ATTACK 8 S: not started by a command, not started by a command */
    ATTR( 94,  1,  0,  2,  0,  1,  0,200, 12,  3, 62,  0, 30, 22,  3,  1,  0,  0, 14,-14, 40, 73),  /* 83: ATTACK 8 S: not started by a command, not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8,  0,  1,  5,  0,  8, -8, 29, 72),  /* 84: not used by a script */
    ATTR( 89,  0,  0,  2,  0,  1,  0,192, 13,  3, 45,  0,  1, 12,  3,  0,  0,  0,  4, -4, 44, 73),  /* 85: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0,192, 12,  3, 45,  0,  0,  8,  1,  0,  0,  0,  4, -8, 39, 73),  /* 86: not used by a script */
    ATTR( 93,  1,  0,  2,  0,  1,  2, 72, 13,  3, 62,  0, 19, 22,  4,  4, 12,  0,  6, -6, 28, 73),  /* 87: ATTACK 4 M: not started by a command */
    ATTR( 93,  1,  0,  2,  0,  1,  2, 72, 12,  3, 62,  0, 19, 22,  4,  2, 12,  0,  6, -6, 28, 73),  /* 88: ATTACK 4 M: not started by a command */
    ATTR( 93,  1,  0,  2,  0,  1,  2, 72, 13,  3, 62,  0, 20, 24,  4,  4, 12,  0,  6, -6, 28, 73),  /* 89: ATTACK 4 L: not started by a command */
    ATTR( 93,  1,  0,  2,  0,  1,  2, 72, 12,  3, 62,  0, 20, 24,  4,  2, 12,  0,  6, -6, 28, 73),  /* 90: ATTACK 4 L: not started by a command */
    ATTR( 93,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  0, 24,  4,  0,  0,  0,  8, -8, 39, 73),  /* 91: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0,  2,  3, 63,  0, 16, 24,  0,  7, 13,  0,  8, -8,  0, 51),  /* 92: CATCH 2, CATCH 3, CATCH 6 */
    ATTR( 37,  1,  0,  1,  0,  1,  0, 80, 12,  3, 63,  0,  0, 16, 54,  1, 11,  0,  8,-12, 44, 73),  /* 93: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 11,  3, 54,  0,  0, 16,  6,  5,  4,  0,  6, -6, 18, 73),  /* 94: not used by a script */
    ATTR( 95,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 21, 20,  2,  4,  1,  0, 10,-10, 39, 73),  /* 95: OKIAGARI P S */
    ATTR( 32,  0,  0,  2,  0,  1,  7,192, 14,  3, 63,  0,  0,  8,  2,  0,  0,  0,  1, -2, 18, 73),  /* 96: ATTACK 11 SP: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  7,192, 15,  3, 62,  0,  0,  6,  1,  0,  0,  0, -6, -6, 28, 73),  /* 97: ATTACK 12 M: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  7,196, 15,  3, 62,  0,  0,  8,  1,  0,  0,  0, -6, -6, 28, 73),  /* 98: ATTACK 12 M: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  7,192, 14,  3, 63,  0,  0,  4,  0,  0,  0,  0,  4, -6, 28, 73),  /* 99: follow-up of ZANNEN 2 */
    ATTR( 32,  0,  0,  0,  0,  1,  7,192, 14,  3, 62,  0,  0,  8,  5,  0,  0,  0,  4, -4, 28, 73),  /* 100: follow-up of ZANNEN 4 */
    ATTR( 32,  0,  0,  1,  0,  1,  7,192, 15,  3, 62,  0,  0,  8,  1,  0,  0,  0, -6, -6, 28, 73),  /* 101: atca 204 */
    ATTR( 38,  0,  0,  1,  0,  1,  7,192, 15,  3, 62,  0,  0,  8,  1,  0,  0,  0, -8, -8, 28, 73),  /* 102: follow-up of JUDGMENT WAIT */
    ATTR( 35,  0,  0,  1,  0,  1,  7,192, 15,  3, 62,  0,  0,  8,  1,  0,  0,  0, -8, -8, 28, 73),  /* 103: follow-up of JUDGMENT WAIT */
    ATTR( 32,  0,  0,  1,  0,  1,  7,192, 15,  3, 62,  0,  0, 10,  1,  0,  0,  0, -6, -8, 28, 73),  /* 104: follow-up of ZANNEN 6 */
    ATTR( 32,  0,  0,  0,  0,  1,  7,192, 14,  3, 63,  0,  0,  6,  0,  0,  0,  0,  4, -6, 44, 73),  /* 105: follow-up of ZANNEN 7 */
    ATTR( 96,  0,  0,  3,  0,  1,  7,192, 14,  3, 62,  0, 15,  6,  2,  0,  0,  0,  4, -8, 44, 73),  /* 106: atca 212 */
    ATTR( 32,  0,  0,  1,  0,  1,  7,192, 11,  3, 54,  0,  0, 16,  3,  0,  0,  0,  8, -8, 44, 73),  /* 107: follow-up of JUDGMENT WAIT */
    ATTR( 93,  0,  0,  2,  0,  1,  7,192, 10,  3, 62,  0,  0, 12,  4,  0,  0,  0,  6, -8, 44, 73),  /* 108: atca 215 */
    ATTR( 37,  0,  0,  1,  0,  1,  7,192, 12,  3, 63,  0,  0,  4,  0,  0,  0,  0,  4, -7, 28, 73),  /* 109: follow-up of WIN 2 */
    ATTR( 37,  0,  0,  1,  0,  1,  7,192, 12,  3, 63,  0,  0,  8,  5,  0,  0,  0,  6, -8, 28, 73),  /* 110: follow-up of WIN 3 */
    ATTR( 38,  0,  0,  1,  0,  1,  7,192, 12,  3, 63,  0,  0, 10,  5,  0,  0,  0,  6, -8, 28, 73),  /* 111: follow-up of WIN 4 */
    ATTR( 37,  0,  0,  1,  0,  1,  7,192, 12,  3, 63,  0,  0,  8,  5,  0,  0,  0,  6, -8, 28, 73),  /* 112: follow-up of WIN 4 */
    ATTR( 37,  0,  0,  1,  0,  1,  7,192, 12,  3, 45,  0,  0,  4,  0,  0,  0,  0,  4, -7, 44, 73),  /* 113: follow-up of WIN 5 */
    ATTR( 37,  0,  0,  1,  0,  1,  7,192, 12,  3, 45,  0,  0,  6,  6,  0,  0,  0,  6, -6, 44, 73),  /* 114: follow-up of WIN 6 */
    ATTR( 89,  0,  0,  2,  0,  1,  7,192, 13,  3, 45,  0,  1, 10,  2,  0,  0,  0,  6, -6, 44, 73),  /* 115: follow-up of WIN 7 */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0,  8,  5,  0,  0,  0,  5, -5, 28, 72),  /* 116: follow-up of JUDGMENT LOSE */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 16,  6,  0,  0,  0,  6, -6, 28, 73),  /* 117: follow-up of JUDGMENT LOSE */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 24,  7,  0,  0,  0,  7, -7, 28, 73),  /* 118: follow-up of JUDGMENT LOSE */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 13,  3, 54,  0,  0,  8,  5,  0,  0,  0,  5, -5, 44, 72),  /* 119: follow-up of WAIT */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 14,  6,  0,  0,  0,  6, -6, 44, 73),  /* 120: follow-up of AFRICA JUMP */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 22,  7,  0,  0,  0,  7, -7, 44, 73),  /* 121: follow-up of AFRICA LAND */
    ATTR( 32,  0,  0,  0,  0,  1,  2,  0, 11,  3, 54,  0,  0,  8,  5,  0,  0,  0,  7, -7, 28, 72),  /* 122: follow-up of SEAN BALL HIT */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 16,  6,  0,  0,  0,  6, -6, 28, 73),  /* 123: follow-up of follow-up of F JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 20,  7,  0,  0,  0,  7, -7, 28, 73),  /* 124: follow-up of BONUS WIN 1 */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 13,  3, 54,  0,  0,  8,  5,  0,  0,  0,  5, -5, 44, 72),  /* 125: follow-up of BONUS WIN 2 */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 14,  6,  0,  0,  0,  6, -6, 44, 73),  /* 126: follow-up of follow-up of V JUMP K M A, F JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 18,  7,  0,  0,  0,  7, -7, 44, 73),  /* 127: follow-up of follow-up of F JUMP K L A */
    ATTR( 36,  0,  0,  1,  0,  1,  2,  0,  9,  3, 54,  0,  0, 16,  3,  0,  0,  0,  6, -6, 44, 73),  /* 128: follow-up of BONUS WIN 3, follow-up of follow-up of F JUMP K M B, follow-up of follow-up of F JUMP K L B */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  5,  3, 54,  0,  0,  8,  7,  0,  0,  0, 12,-16, 44, 73),  /* 129: follow-up of follow-up of SEAN BALL HIT */
    ATTR( 32,  0,  0,  0,  0,  1,  2,  0,  5,  3, 54,  0,  0,  8,  7,  0,  0,  0, 12,-16, 44, 73),  /* 130: follow-up of follow-up of SEAN BALL HIT */
    ATTR( 32,  0,  0,  1,  0,  1,  7,  0, 11,  3, 54,  0,  0, 16,  6,  0,  0,  0,  6, -6, 28, 73),  /* 131: not started by a command */
    ATTR( 96,  1,  0,  1,  0,  1,  0, 72, 15,  3, 63,  0,  8, 16,  3,  5,  0,  0,  1, -1, 44, 73),  /* 132: ATTACK 3 SP: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  0, 72,  0,  3, 63,  0,  8,  4,  3,  2,  0,  0,  1, -1, 44, 73),  /* 133: ATTACK 3 SP: not started by a command */
    ATTR( 95,  1,  0,  3,  0,  1,  0, 72,  0,  3, 63,  0,  9, 16,  3,  1,  0,  0, 10,-10, 44, 73),  /* 134: ATTACK 3 SP: not started by a command */
    ATTR( 32,  1,  0,  2,  0,  1,  3, 72, 13,  3, 62,  0, 32, 12,  4,  3,  0,  0,  1, -1, 28, 73),  /* 135: ATTACK 4 SP: not started by a command */
    ATTR( 93,  1,  0,  2,  0,  1,  3, 72, 12,  3, 62,  0, 32, 20,  4,  2,  0,  0,  6, -6, 28, 73),  /* 136: ATTACK 4 SP: not started by a command */
    ATTR(106,  0,  0,  0, 31,  1,  0, 72, 11,  7, 62,  0, 22, 44,  3, 11,  0,  0, 10,-12, 87, 73),  /* 137: not used by a script */
    ATTR(106,  0,  0,  0,  0,  1,  0, 72, 12,  7, 62,  0, 22, 36,  3,  8,  0,  0,  6, -8, 23, 73),  /* 138: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 80, 13,  3, 63,  1,  0, 20, 48,  4,  0,  0,  8,-16, 28, 73),  /* 139: not started by a command */
    ATTR( 91,  0,  0,  2,  0,  1,  0, 80, 12,  3, 63,  0, 22, 20,  1,  2,  0,  0,  4, -4, 28, 73),  /* 140: not started by a command */
    ATTR( 37,  0,  0,  2,  0,  1,  1, 80, 12,  3, 63,  0,  0, 24,  1,  4, 12,  0,  4, -4, 28, 73),  /* 141: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  1, 80, 12,  3, 63,  0, 23, 28,  1,  4, 12,  0,  5, -5, 28, 73),  /* 142: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  1, 80, 12,  3, 63,  0, 24, 32,  1,  4, 12,  0,  6, -6, 28, 73),  /* 143: not started by a command */
    ATTR(107,  1,  0,  1,  0,  0,  0,208, 15,  3, 62,  0, 25, 52,  1,  4,  0,  0,  8, -8, 98, 73),  /* 144: ATTACK 6 S: not started by a command, not started by a command */
    ATTR( 96,  1,  0,  1,  0,  0,  7,208, 14,  3, 62,  0, 26, 16, 52,  3,  0,  0,  4,-12, 98, 73),  /* 145: ATTACK 6 S: not started by a command, not started by a command */
    ATTR( 96,  1,  0,  3,  0,  0,  7,208, 12,  3, 62,  0, 27, 32, 16,  4,  0,  0,  4,-10, 98, 73),  /* 146: ATTACK 6 S: not started by a command, not started by a command */
    ATTR(106,  0,  0,  0, 31,  1,  0, 80, 11,  3, 62,  0,  5, 40,  3, 11, 10,  0, 10,-12, 87, 73),  /* 147: not used by a script */
    ATTR(106,  0,  0,  0,  0,  1,  0, 80, 12,  3, 62,  0,  5, 32,  3,  8, 10,  0,  6, -8, 23, 73),  /* 148: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  7,196, 12,  3, 63,  0,  0,  8,  1,  0,  0,  0,  4, -4, 28, 73),  /* 149: not started by a command */
    ATTR( 95,  0,  0,  3,  0,  1,  7,192, 12,  3, 63,  0, 28, 12,  1,  0,  0,  0,  4, -4, 28, 73),  /* 150: not started by a command */
    ATTR( 93,  0,  0,  2,  0,  1,  0,  0, 10,  3, 62,  0, 21, 12,  2,  4,  1,  0,  8, -8, 39, 73),  /* 151: follow-up of KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 12,  7,  1,  4,  0,  7, -7, 23, 73),  /* 152: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -9, 29, 72),  /* 153: follow-up of S PUNCH A */
    ATTR( 32,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 10,  1,  4,  4,  0, 12,-12, 18, 73),  /* 154: follow-up of follow-up of S PUNCH A */
    ATTR( 38,  0,  0,  1,  0,  1,  3,  0, 15,  3, 63,  0,  0,  4,  0,  1,  1,  0, -9, -9, 18, 73),  /* 155: follow-up of KAGAMI P A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 13,  3, 63,  0,  0, 14,  0,  1,  1,  0,  9, -9, 23, 73),  /* 156: follow-up of KAGAMI P A */
};

extern const u16 yun_se_random_0[];
extern const u16 yun_se_random_1[];
extern const u16 yun_se_random_2[];
extern const u16 yun_se_random_3[];

const u16* const yun_se_random_table[4] = {
    yun_se_random_0,  /* 0 */
    yun_se_random_1,  /* 1 */
    yun_se_random_2,  /* 2 */
    yun_se_random_3,  /* 3 */
};

const u16 yun_se_random_0[16] = {
    0x02D6, 0x02E0, 0x02D6, 0x02E0, 0x02D6, 0x02E0, 0x02D6, 0x02E0,
    0x02E0, 0x02D6, 0x02E0, 0x02D6, 0x02E0, 0x02D6, 0x02E0, 0x02D6,
};

const u16 yun_se_random_1[16] = {
    0x019A, 0x019B, 0x02D1, 0x019A, 0x02D1, 0x019A, 0x019A, 0x02D1,
    0x019A, 0x02D6, 0x02D1, 0x019B, 0x02DC, 0x02D1, 0x019A, 0x019A,
};

const u16 yun_se_random_2[16] = {
    0x0199, 0x02D0, 0x0199, 0x02D0, 0x02D0, 0x0199, 0x02D0, 0x0199,
    0x02D0, 0x02DD, 0x02D0, 0x0199, 0x02DD, 0x02D0, 0x0199, 0x02D0,
};

const u16 yun_se_random_3[16] = {
    0x02D4, 0x02D5, 0x02D4, 0x02D5, 0x02D4, 0x02D5, 0x02D4, 0x02D5,
    0x02D4, 0x02D5, 0x02D4, 0x02D5, 0x02D4, 0x02D5, 0x0000, 0x0000,
};
