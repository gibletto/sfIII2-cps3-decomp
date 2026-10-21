/*
 * KEN_ATTR.C  Ken's attack attributes and random sound lists
 *
 * ken_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * ken_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR ken_catt_table[97] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 95,  0,  0,  2,  0,  1,  1, 80, 15,  3, 63,  0,  2, 12, 16,  2,  1,  0, 10,-10, 28, 73),  /* 1: ATTACK 2 M: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  1, 72,  0,  3, 63,  0,  2, 30, 16,  5, 11,  0, 10,-10, 28, 73),  /* 2: OKIAGARI P S, ATTACK 2 S: not started by a command, ATTACK 2 L: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 13,  3, 63,  0,  0,  4, 16,  1,  1,  0,  6, -6, 13, 72),  /* 3: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4, 16,  1,  1,  0,  6, -6, 13, 72),  /* 4: S PUNCH B */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 20, 30,  7,  4,  0,  7, -7, 18, 73),  /* 5: M PUNCH A, UP P GUARD P M */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 18, 18,  5,  4,  0,  7, -7, 18, 73),  /* 6: M PUNCH B, UP P GUARD P S */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 15,  3, 62,  0,  0, 26, 17,  7,  7,  0, 12,-12, 23, 73),  /* 7: L PUNCH A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 14,  3, 62,  0,  0, 12, 19,  2,  1,  0, 12,-12, 23, 73),  /* 8: follow-up of M PUNCH A */
    ATTR( 33,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 26, 17,  6,  7,  0, 12,-12, 23, 73),  /* 9: L PUNCH B, UP P GUARD P L */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 10,  3, 63,  0,  0,  8, 16,  1,  1,  0,  6, -6, 29, 72),  /* 10: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 63,  0,  0,  8, 16,  1,  1,  0,  6, -6, 29, 72),  /* 11: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 13,  3, 62,  0,  0, 22, 18,  5,  4,  0,  7, -7, 34, 73),  /* 12: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 22, 17,  7,  4,  0,  7,-11, 34, 73),  /* 13: M KICK A, UP P GUARD K M */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 14,  3, 63,  0,  0, 24, 19,  6,  7,  0,  6, -6, 39, 73),  /* 14: not used by a script */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 14,  3, 63,  0,  0,  4, 19,  6,  7,  0,  8, -8, 39, 73),  /* 15: not used by a script */
    ATTR( 64,  0,  0,  2,  0,  1,  3,  0, 10,  3, 63,  0,  0,  4, 19,  6,  7,  0, 12,-12, 39, 73),  /* 16: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 30, 26,  5,  7,  0, 10,-16, 39, 73),  /* 17: L KICK A, UP P GUARD K L */
    ATTR( 93,  0,  0,  2,  0,  1,  3,  0, 12,  3, 63,  0,  6, 40, 20,  8,  7,  0, 10,-14, 44, 73),  /* 18: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 63,  0,  0, 18, 17,  3,  4,  0,  7, -7, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 21, 26, 17,  6,  7,  0, 10,-13, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 21, 26, 17,  6,  7,  0, 10,-13, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 45,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 45,  0,  0, 18, 16,  1,  4,  0,  7, -7, 34, 73),  /* 24: KAGAMI K A, UP P GUARD K S */
    ATTR( 89,  0,  0,  2,  0,  1,  3,  0, 12,  3, 45,  0,  1, 26, 17,  1,  7,  0, 12,-10, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12, 21,  3,  1,  0,  5, -5, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 20, 21,  5,  4,  0,  6, -6, 18, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 28, 21,  7,  7,  0,  7, -7, 23, 73),  /* 28: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 21,  3,  1,  0,  5, -5, 29, 72),  /* 29: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 21,  4,  4,  0,  6, -6, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 26, 21,  6,  7,  0,  7, -7, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  8,  3, 54,  0,  0, 10, 21,  3,  1,  0,  5, -5, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0, 20, 21,  5,  4,  0,  6, -6, 18, 73),  /* 33: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 28, 21,  7,  7,  0,  7, -7, 23, 73),  /* 34: V JUMP P L A, F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 21,  2,  1,  0,  7, -5, 29, 72),  /* 35: V JUMP K S A, F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 21,  4,  4,  0,  6, -6, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 24, 21,  6,  7,  0,  7, -7, 39, 73),  /* 37: F JUMP K L A */
    ATTR( 38,  1,  0,  1,  0,  1,  1, 80, 11,  3, 62,  0,  6, 12, 17,  3, 12,  0,  5, -5, 44, 73),  /* 38: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command */
    ATTR( 34,  1,  0,  2,  0,  1,  1, 80, 11,  3, 62,  0,  0,  6, 17,  1,  1,  0,  5, -3, 44, 73),  /* 39: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command */
    ATTR( 34,  1,  0,  2,  0,  1,  3, 80, 11,  3, 62,  0,  0,  6, 26,  1,  1,  0,  5, -5, 44, 73),  /* 40: ATTACK 3 S: not started by a command */
    ATTR( 37,  1,  0,  2,  0,  1,  7,200, 15,  3, 63,  0,  3, 26, 19,  0,  0,  0,  4,-14, 28, 73),  /* 41: ATTACK 4 S: not started by a command */
    ATTR( 35,  1,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  6, 17,  0,  0,  0,  3,-14, 28, 73),  /* 42: ATTACK 4 S: not started by a command */
    ATTR( 37,  1,  0,  2,  0,  1,  7,200, 15,  3, 63,  0,  3, 14, 19,  0,  0,  0,  4, -8, 28, 73),  /* 43: ATTACK 4 S: not started by a command */
    ATTR( 35,  1,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  8, 19,  0,  0,  0,  3,-10, 28, 73),  /* 44: ATTACK 4 S: not started by a command */
    ATTR( 37,  1,  1,  2,  0,  1,  7,200, 14,  3, 63,  0,  3,  8, 16,  0,  0,  0,  4, -6, 28, 73),  /* 45: ATTACK 4 S: not started by a command */
    ATTR( 96,  1,  1,  3,  0,  1,  7,200,  0,  3, 63,  0, 11,  8, 16,  0,  0,  0,  2, -6, 28, 73),  /* 46: ATTACK 4 S: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0,  0,  3, 63,  0,  4, 24, 16,  5, 13,  0,  8, -8,  0, 51),  /* 47: CATCH 1, CATCH 3 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  6,  0, 18,  0,  0,  1, 10,-10,  0,  0),  /* 48: M PUNCH A, M PUNCH B, L PUNCH A +7 */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  5, 24, 16,  7, 13,  0,  8, -8,  0, 51),  /* 49: CATCH 5 */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  0, 12, 16,  4,  5,  0,  6, -6, 39, 73),  /* 50: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  0, 20, 18,  4,  1,  0, 12,-12, 39, 73),  /* 51: M KICK C, follow-up of M KICK A / UP P GUARD K M */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 14,  3, 54,  0,  0, 20, 22,  5,  4,  0,  6, -6, 18, 73),  /* 52: F JUMP P M A */
    ATTR( 37,  0,  0,  1,  0,  1,  1, 72, 15,  3, 63,  0,  2, 22, 16,  5, 11,  0, 10,-10, 28, 73),  /* 53: ATTACK 2 M: not started by a command */
    ATTR( 96,  0,  1,  2,  0,  1,  1, 72, 15,  3, 63,  0,  2, 14, 19,  1,  1,  0, 10,-10, 28, 73),  /* 54: ATTACK 2 L: not started by a command */
    ATTR( 37,  0,  0,  0, 22,  1,  0,  0, 14,  3,  9,  0,  6,  8, 16,  2,  1,  1,  8, -8, 34, 73),  /* 55: CATCH 19, CATCH 20, CATCH 21 */
    ATTR( 96,  1,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  7, 17, 52,  0,  0,  0,  4, -4, 28, 73),  /* 56: ATTACK 5 S: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  7,200,  0,  3, 63,  0,  7, 13, 16,  0,  0,  0,  4, -4, 28, 73),  /* 57: ATTACK 5 S: not started by a command */
    ATTR( 96,  1,  0,  1,  0,  1,  7,200,  0,  3, 63,  0,  8,  5, 16,  0,  0,  0,  4, -4, 28, 73),  /* 58: ATTACK 5 S: not started by a command */
    ATTR( 95,  1,  0,  1,  0,  1,  7,200,  0,  3, 63,  0,  9, 13, 16,  0,  0,  0,  4, -4, 28, 73),  /* 59: ATTACK 5 S: not started by a command */
    ATTR( 33,  1,  0,  2,  0,  1,  7,196, 12,  3, 63,  0, 13, 36, 54,  3,  0,  0, 10,-10, 44, 73),  /* 60: not used by a script */
    ATTR( 95,  1,  0,  2,  0,  1,  7,200, 12,  3, 63,  0, 10,  8, 16,  0,  0,  0,  8, -8, 28, 73),  /* 61: not used by a script */
    ATTR( 95,  1,  1,  3,  0,  1,  3,200,  0,  3, 63,  0, 11,  8, 16,  0,  0,  0,  2, -6, 28, 73),  /* 62: ATTACK 4 S: not started by a command */
    ATTR( 32,  1,  0,  2,  0,  1,  7,208,  0,  3, 62,  0,  0, 10,  0,  1,  0,  0,  4,-10, 44, 73),  /* 63: ATTACK 6 S: not started by a command */
    ATTR( 33,  1,  0,  1,  0,  1,  7,208,  0,  3, 62,  0,  0,  4, 54,  1,  0,  0,  4,-12, 44, 73),  /* 64: ATTACK 6 S: not started by a command */
    ATTR( 95,  1,  0,  0,  0,  1,  7,208,  8,  3, 62,  0, 15,  6, 54,  0,  0,  0,  2, -4, 44, 73),  /* 65: ATTACK 6 S: not started by a command */
    ATTR( 96,  1,  0,  0,  0,  1,  7,208,  8,  3, 62,  0, 15,  6, 54,  1,  0,  0,  2, -4, 44, 73),  /* 66: ATTACK 6 S: not started by a command */
    ATTR( 37,  1,  0,  1,  0,  1,  7,208,  0,  3, 62,  0,  0,  8, 54,  1,  0,  0,  2, -4, 44, 73),  /* 67: ATTACK 6 S: not started by a command */
    ATTR( 95,  1,  0,  2,  0,  1,  3,208,  0,  3, 62,  0, 14, 10, 54,  1,  0,  0,  4,-14, 44, 73),  /* 68: ATTACK 6 S: not started by a command */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 24, 17,  5,  4,  0,  8, -8, 18,  0),  /* 69: FUSHIN P S */
    ATTR( 96,  0,  1,  2,  0,  1,  0, 72, 15,  3, 63,  0, 19,  4, 19,  1,  1,  0,  6, -6, 28, 73),  /* 70: not used by a script */
    ATTR( 33,  1,  0,  2,  0,  1,  7,208,  0,  3, 62,  0,  0, 18, 53,  3,  0,  0,  6, -6, 44, 73),  /* 71: ATTACK 6 S: not started by a command */
    ATTR( 37,  1,  0,  2,  0,  1,  7,208, 13,  3, 62,  1,  0,  8, 53,  1,  0,  0,  0, -2,  0, 73),  /* 72: not used by a script */
    ATTR( 37,  0,  1,  2,  0,  1,  1, 72, 15,  3, 63,  0,  2, 12, 19,  5, 11,  0,  6,-10, 28, 73),  /* 73: ATTACK 2 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  8,  3, 54,  0,  0, 20, 21,  5,  4,  0,  6, -6, 18, 73),  /* 74: ATTACK 9 M: not started by a command */
    ATTR( 38,  1,  0,  1,  0,  1,  1, 80, 11,  3, 62,  0,  0, 16, 17,  3, 12,  0,  4, -4, 44, 73),  /* 75: ATTACK 3 S: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 20, 22, 18,  1,  4,  0, 10,-10, 23, 73),  /* 76: OKIAGARI P S */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0,  6, 21,  6,  7,  0,  7, -7, 39, 73),  /* 77: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 10,  3, 54,  0,  0,  6, 21,  6,  7,  0,  7, -7, 39, 73),  /* 78: not used by a script */
    ATTR( 37,  0,  1,  2,  0,  1,  1, 72, 15,  3, 63,  0,  2, 12, 19,  1,  1,  0,  6,-10, 28, 73),  /* 79: ATTACK 2 L: not started by a command */
    ATTR( 32,  1,  0,  1,  0,  1,  3,  0, 12,  3, 63,  0,  0, 12, 18,  1,  1,  0,  7, -7, 18, 73),  /* 80: not used by a script */
    ATTR( 33,  1,  0,  2,  0,  1,  3, 80, 11,  3, 62,  0,  0,  6, 26,  1,  1,  0,  5, -5, 44, 73),  /* 81: ATTACK 3 M: not started by a command */
    ATTR( 33,  1,  0,  2,  0,  1,  3, 80, 11,  3, 62,  0,  0,  6, 27,  1,  1,  0,  5, -5, 44, 73),  /* 82: ATTACK 3 L: not started by a command */
    ATTR( 37,  0,  1,  1,  0,  1,  0, 80, 12,  3, 63,  0,  2, 12, 19,  5,  0,  0,  4, -6, 28, 73),  /* 83: ATTACK 2 SP: not started by a command */
    ATTR( 37,  0,  1,  1,  0,  1,  0, 80, 13,  3, 63,  0,  2, 12, 19,  1,  0,  0,  4, -6, 28, 73),  /* 84: ATTACK 2 SP: not started by a command */
    ATTR( 96,  0,  1,  2,  0,  1,  1, 80, 14,  3, 63,  0,  2,  8, 19,  1,  0,  0,  4, -6, 28, 73),  /* 85: ATTACK 2 SP: not started by a command */
    ATTR( 96,  0,  1,  2,  0,  1,  1, 80, 15,  3, 63,  0,  2,  8, 19,  1,  0,  0,  8, -8, 28, 73),  /* 86: ATTACK 2 SP: not started by a command */
    ATTR( 38,  1,  0,  1,  0,  1,  1, 80, 15,  3, 62,  0,  6, 12, 17,  3,  0,  0,  3, -3, 44, 73),  /* 87: ATTACK 3 SP: not started by a command */
    ATTR( 34,  1,  0,  2,  0,  1,  1, 80, 13,  3, 62,  0,  0,  7, 16,  1,  0,  0,  3, -2, 44, 73),  /* 88: ATTACK 3 SP: not started by a command */
    ATTR( 33,  1,  0,  2,  0,  1,  3, 80, 12,  3, 62,  0,  0,  6, 26,  1,  0,  0,  3, -3, 44, 73),  /* 89: ATTACK 3 SP: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  0, 80, 13,  3, 62,  0, 22,  6, 16,  2,  0,  0,  4, -6, 44, 73),  /* 90: ATTACK 7 SP: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  0, 80, 13,  3, 62,  0, 23,  6, 26,  2,  0,  0,  4, -6, 44, 73),  /* 91: ATTACK 7 SP: not started by a command */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 13,  3, 54,  0,  0, 14, 18,  5,  4,  0,  7, -7, 34, 73),  /* 92: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 13,  3, 54,  0,  0, 10, 18,  1,  1,  0,  7, -7, 34, 73),  /* 93: not used by a script */
    ATTR( 34,  1,  0,  2,  0,  1,  1, 80, 11,  3, 62,  0,  0, 16, 16,  2, 14,  0,  5, -3, 44, 73),  /* 94: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    ATTR( 34,  1,  0,  2,  0,  1,  3, 80, 11,  3, 62,  0,  0, 16, 26,  2,  1,  0,  5, -5, 44, 73),  /* 95: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    ATTR( 35,  0,  0,  0,  0,  1,  2,  0,  0,  3, 63,  0,  0,  1, 48,  1,  1,  0,  6, -6, 13, 73),  /* 96: ATTACK 10 M: not started by a command */
};

extern const u16 ken_se_random_0[];

const u16* const ken_se_random_table[1] = {
    ken_se_random_0,  /* 0 */
};

const u16 ken_se_random_0[16] = {
    0x0261, 0x0261, 0x0261, 0x0262, 0x0262, 0x0263, 0x0263, 0x0263,
    0x0261, 0x0261, 0x0261, 0x0262, 0x0262, 0x0263, 0x0263, 0x0263,
};
