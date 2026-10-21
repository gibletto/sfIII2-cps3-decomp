/*
 * RYU_ATTR.C  Ryu's attack attributes and random sound lists
 *
 * ryu_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * ryu_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR ryu_catt_table[93] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 72, 15,  3, 63,  0,  2, 28, 16,  6, 11,  0,  8, -8, 28, 73),  /* 1: ATTACK 2 S: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 80,  0,  3, 63,  0,  2, 20, 16,  4, 11,  0,  8, -8, 28, 73),  /* 2: ATTACK 2 S: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  6, 16,  1,  1,  0,  6, -6, 13, 72),  /* 3: S PUNCH A, follow-up of L PUNCH B, UP P GUARD P L */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 14,  3, 63,  0,  0,  4, 16,  1,  1,  0,  6, -6, 13, 72),  /* 4: S PUNCH B */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 22, 30,  7,  4,  0,  7, -7, 18, 73),  /* 5: M PUNCH A, UP P GUARD P M */
    ATTR( 32,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 20, 18,  5,  4,  0,  7, -7, 18, 73),  /* 6: M PUNCH B, UP P GUARD P S */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 14,  3, 62,  0,  0, 26, 19,  8,  7,  0, 12,-12, 23, 73),  /* 7: L PUNCH A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 14,  3, 63,  0,  0, 12, 19,  8,  7,  0, 12,-12, 23, 73),  /* 8: follow-up of UP P GUARD P M */
    ATTR( 33,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 26, 17,  7,  7,  0, 12,-12, 23, 73),  /* 9: L PUNCH B, follow-up of L PUNCH B, UP P GUARD P L, UP P GUARD P L */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 10,  3, 63,  0,  0,  8, 16,  1,  1,  0,  6, -6, 29, 72),  /* 10: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 63,  0,  0,  8, 16,  1,  1,  0,  6, -6, 29, 72),  /* 11: not used by a script */
    ATTR( 38,  0,  0,  2,  0,  1,  3,  0, 13,  3, 62,  0,  0, 22, 17,  5,  4,  0,  7, -7, 34, 73),  /* 12: M KICK A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 18, 18,  4,  4,  0,  7, -7, 34, 73),  /* 13: M KICK B, UP P GUARD K S */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0,  0, 30, 19,  6,  7,  0, 12,-12, 39, 73),  /* 14: not used by a script */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0,  0,  4, 17,  5,  7,  0,  8, -8, 39, 73),  /* 15: not used by a script */
    ATTR( 64,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  0,  4, 19,  3,  7,  0,  8, -8, 39, 73),  /* 16: not used by a script */
    ATTR( 33,  0,  0,  2,  0,  1,  3,  0, 14,  3, 62,  0,  0, 28, 19,  6,  7,  0, 12,-12, 39, 73),  /* 17: L KICK A */
    ATTR( 93,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0,  6, 32, 17,  7,  7,  0, 14,-14, 39, 73),  /* 18: UP P GUARD K L */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0,  0,  4,  0,  1,  1,  0,  6, -6, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 63,  0,  0, 18, 17,  3,  4,  0,  7, -7, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 20, 26, 17,  6,  7,  0,  8, -8, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 20, 26, 17,  6,  7,  0,  8, -8, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  3,  0, 13,  3, 45,  0,  0,  4, 16,  1,  1,  0,  6,  6, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  0,  0,  1,  0,  1,  3,  0, 12,  3, 45,  0,  0, 18, 16,  1,  4,  0,  7, -7, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  0,  0,  2,  0,  1,  3,  0, 12,  3, 45,  0,  1, 26, 17,  1,  7,  0,  8, -8, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12, 21,  3,  1,  0,  5, -5, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 20, 21,  5,  4,  0,  6, -6, 18, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0, 17, 28, 21,  7,  7,  0,  7, -7, 23, 73),  /* 28: V JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 21,  3,  1,  0,  5, -5, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 21,  4,  4,  0,  6, -6, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 14,  3, 54,  0,  0, 26, 21,  6,  7,  0,  7, -7, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  8,  3, 54,  0,  0, 10, 21,  3,  1,  0,  5, -5, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 14,  3, 54,  0,  0, 10, 21,  3,  1,  0, 12,-12, 18, 73),  /* 33: F JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0, 17, 28, 21,  7,  7,  0,  7, -7, 23, 73),  /* 34: F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 21,  2,  1,  0,  5, -5, 29, 72),  /* 35: F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 21,  4,  4,  0,  6, -6, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 24, 21,  6,  7,  0,  7, -7, 39, 73),  /* 37: F JUMP K L A, S V JP S P A */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0,  7, 30, 20,  7, 14,  0,  6, -6, 40, 73),  /* 38: ATTACK 3 M: not started by a command, ATTACK 7 S: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0,  7, 26, 20,  7, 12,  0,  7, -7, 40, 73),  /* 39: ATTACK 3 S: not started by a command, ATTACK 7 S: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0, 14, 26, 26,  7,  1,  0,  7, -7, 40, 73),  /* 40: ATTACK 3 S: not started by a command, ATTACK 7 S: not started by a command */
    ATTR( 38,  0,  0,  2,  0,  1,  7,196, 15,  3, 63,  0,  3, 20, 16,  1,  0,  0,  8,-10, 28, 73),  /* 41: not used by a script */
    ATTR( 35,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  8, 16,  1,  0,  0,  8,-10, 28, 73),  /* 42: not used by a script */
    ATTR( 38,  0,  0,  2,  0,  1,  7,196, 15,  3, 63,  0,  3,  8, 16,  1,  0,  0,  8,-14, 28, 73),  /* 43: not used by a script */
    ATTR( 35,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  8, 16,  1,  0,  0,  8,-14, 28, 73),  /* 44: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  7,200, 15,  3, 63,  0,  3,  8, 16,  1,  0,  0,  6, -6, 28, 73),  /* 45: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0,  3,  8, 16,  1,  0,  0,  6, -6, 28, 73),  /* 46: not used by a script */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0,  0,  3, 63,  0,  4, 24, 16,  4, 13,  0,  8, -8,  0, 51),  /* 47: CATCH 1, CATCH 3 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 18,  0,  0,  1, 10,-10,  0,  0),  /* 48: M PUNCH A, M PUNCH B, M PUNCH C +7 */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  5, 24, 16,  7, 13,  0,  8, -8,  0, 51),  /* 49: CATCH 5 */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  0,  8,  0,  4,  5,  0, 10,-10, 18, 73),  /* 50: M PUNCH C */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 10,  3, 54,  0,  0, 12, 18,  3,  1,  0, 12,-14, 18, 73),  /* 51: M PUNCH C */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 14,  3, 54,  0,  0, 10, 22,  3,  5,  0,  6, -6, 14, 73),  /* 52: F JUMP P M A */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 72, 15,  3, 63,  0,  2, 32, 17,  7, 11,  0, 12,-12, 28, 73),  /* 53: ATTACK 2 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  3, 72, 15,  3, 63,  0, 18, 20, 16,  8, 11,  0, 12,-12, 28, 73),  /* 54: ATTACK 2 L: not started by a command */
    ATTR( 38,  0,  0,  2, 39,  1,  7,196, 14,  3, 63,  0,  8, 12, 52,  2,  0,  0, 28,-24, 65, 73),  /* 55: not used by a script */
    ATTR( 95,  0,  0,  2,  0,  1,  0,208, 15,  3, 63,  0,  9,  8, 16,  1,  0,  0,  5, -5, 28, 73),  /* 56: ATTACK 11 SP: not started by a command */
    ATTR( 95,  0,  0,  3, 42,  1,  7,196,  0,  3,  0,  1, 15, 64, 16,  2,  0,  0, 16,-16, 65, 73),  /* 57: not used by a script */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 24, 17,  5,  4,  0,  8, -8, 18,  0),  /* 58: FUSHIN P S */
    ATTR(107,  0,  0,  3, 41,  1,  7,196,  0,  3,  0,  0, 10, 20, 19,  2,  0,  0, 28,-28, 65, 52),  /* 59: not used by a script */
    ATTR( 33,  0,  0,  2,  0,  1,  0,  0, 14,  3, 62,  0,  0, 12, 19,  1,  1,  0,  8, -8, 39, 73),  /* 60: follow-up of L PUNCH B, UP P GUARD P L */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 80,  0,  3, 63,  0,  2, 24, 16,  4, 11,  0, 10,-10, 28, 73),  /* 61: ATTACK 2 M: not started by a command */
    ATTR( 96,  0,  0,  3,  0,  1,  2, 80,  0,  3, 63,  0, 18, 16, 16,  1,  1,  0, 10,-10, 28, 73),  /* 62: ATTACK 2 L: not started by a command */
    ATTR(107,  0,  0,  2,  0,  1,  3,196,  0,  3,  0,  0, 10, 44, 19,  1,  0,  0, 32,-32, 65, 73),  /* 63: not used by a script */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0,  7, 30, 20,  7,  1,  0,  7, -7, 40, 73),  /* 64: ATTACK 3 M: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0, 14, 30, 26,  7,  1,  0,  7, -7, 40, 73),  /* 65: ATTACK 3 M: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0,  7, 34, 20,  7, 14,  0,  7, -7, 40, 73),  /* 66: ATTACK 3 L: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0,  7, 34, 20,  7,  1,  0,  7, -7, 40, 73),  /* 67: ATTACK 3 L: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 11,  3, 62,  0, 14, 34, 26,  8,  1,  0,  7, -7, 40, 73),  /* 68: ATTACK 3 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 54,  0,  0, 20, 21,  5,  4,  0,  6, -6, 18, 73),  /* 69: ATTACK 9 S: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 19, 22, 18,  1,  4,  0, 10,-10, 23, 73),  /* 70: OKIAGARI P S */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 80, 14,  3, 62,  0,  6, 24, 17,  8,  7,  0, 12,-14, 44, 73),  /* 71: ATTACK 10 S: not started by a command */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 80, 14,  3, 62,  0,  6, 28, 17,  8,  7,  0, 12,-14, 44, 73),  /* 72: ATTACK 10 M: not started by a command */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 80, 14,  3, 62,  0,  6, 32, 17,  8,  7,  0, 12,-14, 44, 73),  /* 73: ATTACK 10 L: not started by a command */
    ATTR( 96,  0,  0,  2,  0,  1,  0, 72, 15,  3, 63,  0, 18, 22, 19,  5,  0,  0, 12,-12, 28, 73),  /* 74: ATTACK 2 SP: not started by a command */
    ATTR( 96,  0,  0,  3,  0,  1,  1, 80,  0,  3, 63,  0, 18, 18, 16,  1,  0,  0, 10,-10, 28, 73),  /* 75: ATTACK 2 SP: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 80, 12,  3, 62,  0, 33, 10, 31,  1,  0,  0,  2, -2, 40, 73),  /* 76: ATTACK 3 SP: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 80, 12,  3, 62,  0, 33, 10, 31,  2,  0,  0,  2, -2, 40, 73),  /* 77: ATTACK 3 SP: not started by a command */
    ATTR( 94,  1,  0,  2,  0,  1,  1, 80, 13,  3, 62,  0, 28,  7, 47,  1,  0,  0,  4, -4, 40, 73),  /* 78: ATTACK 3 SP: not started by a command */
    ATTR(111,  0,  0,  2,  0,  1,  1, 80, 14,  3, 62,  0, 31, 24, 17,  3,  0,  0, 12,-14, 44, 73),  /* 79: ATTACK 10 SP: not started by a command */
    ATTR( 91,  0,  0,  1,  0,  1,  0, 80, 13,  3, 62,  0, 22, 12, 20,  2,  0,  0,  4, -4, 40, 73),  /* 80: ATTACK 8 SP: not started by a command */
    ATTR( 91,  0,  0,  1,  0,  1,  0, 80, 13,  3, 62,  0, 23, 12, 26,  1,  0,  0,  4, -4, 40, 73),  /* 81: ATTACK 8 SP: not started by a command */
    ATTR( 95,  1,  0,  1, 65,  0,  7,196, 14,  3, 63,  0, 24, 12, 52,  2,  0,  0,  1,-38, 65, 73),  /* 82: ATTACK 11 SP: not started by a command */
    ATTR( 96,  1,  0,  2, 66,  1,  7,196,  0,  3,  0,  1, 25, 40, 16,  2,  0,  0, 36,-36, 65, 73),  /* 83: ATTACK 12 S: not started by a command */
    ATTR( 95,  1,  0,  3, 67,  1,  7,196,  0,  3,  0,  1, 26, 40, 16,  2,  0,  0,  7, -7, 97, 73),  /* 84: ATTACK 12 S: not started by a command */
    ATTR(107,  1,  0,  3, 68,  1,  7,196,  0,  3,  0,  0, 27, 28, 19,  2,  0,  0, 30,-30, 97, 52),  /* 85: ATTACK 12 S: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 13,  3, 62,  0, 29, 20, 20,  4,  5,  0,  6, -6, 40, 73),  /* 86: ATTACK 8 S: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 13,  3, 62,  0, 30, 20, 26,  4,  1,  0,  6, -6, 40, 73),  /* 87: ATTACK 8 S: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 13,  3, 62,  0, 29, 22, 20,  4,  5,  0,  6, -6, 40, 73),  /* 88: ATTACK 8 M: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 13,  3, 62,  0, 30, 22, 26,  4,  1,  0,  6, -6, 40, 73),  /* 89: ATTACK 8 M: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 13,  3, 62,  0, 29, 24, 20,  4,  5,  0,  6, -6, 40, 73),  /* 90: ATTACK 8 L: not started by a command */
    ATTR(100,  0,  0,  1,  0,  1,  3, 80, 13,  3, 62,  0, 30, 24, 26,  4,  1,  0,  6, -6, 40, 73),  /* 91: ATTACK 8 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  1, 80, 13,  3, 62,  0, 28, 10, 31,  2,  0,  0,  3, -3, 40, 73),  /* 92: ATTACK 3 SP: not started by a command */
};

extern const u16 ryu_se_random_0[];

const u16* const ryu_se_random_table[1] = {
    ryu_se_random_0,  /* 0 */
};

const u16 ryu_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
