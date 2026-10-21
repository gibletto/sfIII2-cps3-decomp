/*
 * NECRO_ATTR.C  Necro's attack attributes and random sound lists
 *
 * necro_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * necro_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR necro_catt_table[90] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0, 10, 24,  2,  1,  0,  6, -6, 13, 72),  /* 1: S PUNCH C */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6, 24,  1,  1,  0,  6, -6, 13, 72),  /* 2: S PUNCH A */
    ATTR( 33,  0,  0,  1,  0,  1,  1,  0, 12,  3, 62,  0,  0, 14, 25,  5,  4,  0,  7, -7, 18, 73),  /* 3: M PUNCH A, M PUNCH C, UP P GUARD P S +1 */
    ATTR( 95,  0,  0,  2,  0,  1,  1,  0, 15,  3, 63,  0,  2, 26, 26,  7,  7,  0,  8, -8, 23, 73),  /* 4: KAGAMI P C, UP P GUARD P S, D P GUARD P S */
    ATTR( 32,  0,  0,  2,  0,  1,  3,  0, 12,  3, 62,  0,  0, 22, 26,  6,  7,  0,  8, -8, 23, 73),  /* 5: L PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  9, 24,  3,  1,  0,  6, -6, 29, 72),  /* 6: S KICK C */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8, 24,  2,  1,  0,  6, -6, 29, 72),  /* 7: S KICK A */
    ATTR( 37,  0,  0,  1,  0,  1,  1,  0, 13,  3, 62,  0,  0, 16, 25,  6,  4,  0,  7, -7, 34, 73),  /* 8: M KICK C, ATTACK 7 S: not started by a command */
    ATTR( 37,  0,  0,  1,  0,  1,  1,  0, 13,  3, 63,  0,  0, 14, 25,  2,  4,  0,  7, -7, 34, 73),  /* 9: M KICK A, UP P GUARD K S, D P GUARD K S */
    ATTR( 38,  0,  0,  2,  0,  1,  2,  0, 14,  3, 62,  0,  0, 28, 25,  8,  7,  0, -8, -8, 39, 73),  /* 10: L KICK C */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 13,  3, 62,  0,  0, 26, 26,  7,  7,  0,  8, -8, 39, 73),  /* 11: L KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8, 24,  1,  1,  0,  6, -6, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  2,  0, 14,  3, 63,  0,  0, 14, 25,  3,  4,  0,  7, -7, 18, 73),  /* 13: KAGAMI P A */
    ATTR( 93,  0,  0,  2,  0,  1,  0,  0, 14,  3, 63,  0,  3, 28, 49,  5,  7,  0,  8, -8, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3,  9,  0,  0,  8, 24,  1,  1,  0,  6, -6, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 12,  3,  9,  0,  0, 24, 26,  1,  7,  0,  8, -8, 39, 73),  /* 16: not used by a script */
    ATTR( 89,  0,  0,  2,  0,  1,  1,  0, 12,  3,  9,  0,  1, 24, 26,  1,  7,  0,  8, -8, 39, 73),  /* 17: KAGAMI K A */
    ATTR( 98,  0,  0,  2,  0,  1,  0, 80, 11,  3, 54,  0,  4, 24, 26,  6,  7,  0,-10,-10, 28, 73),  /* 18: ATTACK 6 S: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 13,  3, 54,  0,  0,  6, 16,  3,  1,  0,  5, -5, 13, 72),  /* 19: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 14, 18,  5,  4,  0,  6, -6, 18, 73),  /* 20: V JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 20, 19,  7,  7,  0,  7, -7, 23, 73),  /* 21: V JUMP P L A, F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0,  6, 16,  2,  1,  0,  5, -5, 29, 72),  /* 22: V JUMP K S A, F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 14, 18,  4,  4,  0,  6, -6, 34, 73),  /* 23: V JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 24, 19,  6,  7,  0,  7, -7, 39, 73),  /* 24: V JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0,  8, 16,  3,  1,  0,  5, -5, 13, 72),  /* 25: F JUMP P S A, ATTACK 8 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0, 16, 18,  5,  4,  0,  6, -6, 18, 73),  /* 26: F JUMP P M A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 63,  0,  0, 12, 18,  1,  5,  0,  6, -6, 36, 73),  /* 27: F JUMP K M A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 63,  0,  0,  4, 18,  1,  1,  0,  6, -6, 36, 73),  /* 28: F JUMP K M A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 63,  0,  0, 16, 19,  2,  8,  0,  6, -6, 40, 73),  /* 29: F JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 63,  0,  0,  4, 19,  2,  1,  0,  6, -8, 40, 73),  /* 30: F JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 14,  3, 63,  0,  0,  1, 16,  0,  1,  0,  6, -6,108,  0),  /* 31: FUSHIN P S, ATTACK 10 SP: not started by a command */
    ATTR( 40,  0,  0,  1,  0,  1,  0, 64, 10,  3, 54,  0, 10, 24, 25,  5,  4,  0,  8, -8, 34, 73),  /* 32: OKIAGARI P S */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3,  0,  0,  0,  0, 25,  0,  0,  2, 10,-10, 70,  0),  /* 33: M PUNCH A, M PUNCH C, L PUNCH A +1 */
    ATTR( 32,  0,  0,  2,  3,  1,  0,  0, 12,  3, 63,  0,  5, 24, 26,  6, 13,  2, 10,-10, 23, 73),  /* 34: CATCH 1 */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 64, 12,  3, 63,  0,  0, 40, 26,  5, 13,  1, 10,-10, 63,  0),  /* 35: CATCH 2 */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 64, 12,  3,  0,  0,  0,  0, 25,  0,  0,  1, 10,-10, 70,  0),  /* 36: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 64, 11,  3, 45,  0,  0,  0, 25,  0,  4,  1, 10,-10, 84,  0),  /* 37: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 64,  2,  3,  0,  0,  6, 28, 26,  5, 13,  1, 10,-10, 73, 55),  /* 38: CATCH 4 */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 12, 24,  3, 10,  0, 12,-12, 28, 73),  /* 39: ATTACK 2 S: not started by a command */
    ATTR( 94,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  3, 16, 26,  2,  1,  0, 12,-12, 28, 73),  /* 40: ATTACK 2 S: not started by a command */
    ATTR( 94,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 16, 24,  3,  1,  0, 12,-12, 28, 73),  /* 41: ATTACK 2 S: not started by a command */
    ATTR( 37,  0,  2,  1,  0,  1,  1, 68,  0,  3, 62,  0,  8, 12, 16,  4,  5,  0, 16,-16, 23, 73),  /* 42: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command */
    ATTR( 37,  0,  2,  1,  0,  1,  1, 68,  0,  3, 62,  0,  8, 12, 17,  2,  1,  0, 16,-16, 23, 73),  /* 43: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command */
    ATTR( 92,  0,  2,  2,  0,  1,  0,208,  0,  7, 63,  0,  9,  8, 53,  0,  0,  0,  4, -6, 28, 73),  /* 44: ATTACK 4 S: not started by a command */
    ATTR( 37,  0,  2,  2,  0,  1,  0,208,  0,  7, 63,  0,  0,  8, 53,  0,  0,  0,  4, -6, 28, 73),  /* 45: ATTACK 4 S: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0,  2,  3,  0,  0,  7, 24, 26,  9, 13,  2, 10,-10, 73, 55),  /* 46: CATCH 3 */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 11,  3,  0,  0,  0,  0, 25,  0,  0,  2, 10,-10, 70,  0),  /* 47: M KICK A, M KICK C, L KICK A +2 */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0,  0,  3, 63,  0, 11,  0, 26,  0,  0,  1, 10,-10, 73, 73),  /* 48: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0,  0,  3, 63,  0, 11,  0, 26,  0,  0,  1, 10,-10, 73,  0),  /* 49: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0,192,  2,  3, 63,  0, 12, 54, 26,  3,  0,  2, 10,-10, 73,131),  /* 50: CATCH 6 */
    ATTR( 32,  0,  0,  2, 30,  1,  0,192, 12,  3, 63,  1,  0, 26, 26,  3,  0,  1, 10,-10, 55, 73),  /* 51: CATCH 6 */
    ATTR( 32,  0,  0,  2, 37,  1,  0,192, 12,  3,  0,  0,  0,  0, 25,  0,  0,  1, 10,-10, 70,  0),  /* 52: ATTACK 7 S: not started by a command */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3,  9,  0,  0, 14, 25,  1,  4,  0,  7, -7, 34, 73),  /* 53: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 16, 25,  5,  4,  0,  7, -7, 18, 73),  /* 54: M PUNCH C */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 64, 11,  3, 54,  0,  0, 14, 16,  5,  7,  0,  8, -8, 28, 73),  /* 55: not used by a script */
    ATTR( 37,  0,  2,  2,  0,  1,  7,208,  0,  7, 63,  0,  0, 20, 53,  0,  0,  0,  4, -6, 28, 73),  /* 56: ATTACK 4 S: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 16, 24,  3, 10,  0,  8, -8, 28, 73),  /* 57: ATTACK 2 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 16, 26,  2,  1,  0, 12,-12, 28, 73),  /* 58: ATTACK 2 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 16, 24,  3,  1,  0, 12,-12, 28, 73),  /* 59: ATTACK 2 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 10, 26,  2, 10,  0,  8, -8, 28, 73),  /* 60: ATTACK 2 L: not started by a command */
    ATTR( 34,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  3, 20, 24,  2,  1,  0, 12,-12, 28, 73),  /* 61: ATTACK 2 L: not started by a command */
    ATTR( 34,  1,  0,  3,  0,  1,  0, 80, 12,  3, 62,  0,  0, 10, 24,  2,  1,  0, 12,-12, 28, 73),  /* 62: ATTACK 2 L: not started by a command */
    ATTR( 98,  0,  0,  2,  0,  1,  0, 80, 11,  3, 54,  0,  4, 28, 26,  6,  7,  0,-10,-10, 28, 73),  /* 63: ATTACK 6 M: not started by a command */
    ATTR( 98,  0,  0,  2,  0,  1,  0, 80, 11,  3, 54,  0,  4, 32, 26,  6,  7,  0,-10,-10, 28, 73),  /* 64: ATTACK 6 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 80, 12,  3, 62,  0,  0, 10, 26,  2,  1,  0,  8, -8, 28, 73),  /* 65: ATTACK 2 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 10,  3, 54,  0,  0, 16, 16,  3,  4,  0,  6, -6, 18, 72),  /* 66: not used by a script */
    ATTR( 91,  0,  2,  2,  0,  1,  1, 68,  0,  3, 63,  0,  8, 12, 17,  2,  1,  0, 16,-16, 23, 73),  /* 67: ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 64,  2,  3, 63,  0,  6, 30, 26,  6, 13,  1, 10,-10, 73, 55),  /* 68: CATCH 9 */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 64,  2,  3, 63,  0,  6, 32, 26,  7, 13,  1, 10,-10, 73, 55),  /* 69: CATCH 10 */
    ATTR( 40,  0,  0,  2,  0,  1,  0, 80, 10,  3, 54,  0, 10, 26, 25,  3, 10,  0, 10,-10, 44, 73),  /* 70: ATTACK 9 L: not started by a command */
    ATTR( 40,  0,  0,  2,  0,  1,  0, 80, 10,  3, 54,  0, 10, 30, 25,  4, 10,  0, 10,-10, 44, 73),  /* 71: ATTACK 9 SP: not started by a command */
    ATTR( 40,  0,  0,  2,  0,  1,  0, 80, 10,  3, 54,  0, 10, 34, 25,  5, 10,  0, 10,-10, 44, 73),  /* 72: ATTACK 10 S: not started by a command */
    ATTR( 37,  0,  2,  2,  0,  1,  0,192,  0,  7, 63,  0,  0,  6, 53,  0,  0,  0,  4, -6, 28, 73),  /* 73: ATTACK 4 S: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3, 63,  0,  0, 48, 26,  6, 13,  1, 10,-10, 63,  0),  /* 74: CATCH 11 */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3, 63,  0,  0, 56, 26,  7, 13,  1, 10,-10, 63,  0),  /* 75: CATCH 12 */
    ATTR( 33,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 10, 25,  2,  4,  0,  7, -7, 18, 73),  /* 76: follow-up of S KICK A / S KICK C */
    ATTR( 32,  0,  0,  2,  0,  1,  3,  0, 12,  3, 63,  0,  0, 16, 26,  3,  4,  0,  8, -8, 23, 73),  /* 77: follow-up of follow-up of S KICK A / S KICK C */
    ATTR( 92,  0,  2,  2,  0,  1,  0,208,  0,  7, 63,  0,  9,  4, 53,  0,  0,  0,  4, -6, 28, 73),  /* 78: ATTACK 4 S: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 63,  0,  0, 10, 18,  1,  5,  0,  5, -5, 36, 73),  /* 79: V JUMP K S B */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 63,  0,  0,  3, 18,  1,  1,  0,  5, -5, 36, 73),  /* 80: V JUMP K S B */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80, 11,  3, 54,  0,  4, 16, 16,  6,  0,  0,  2, -2, 28, 73),  /* 81: ATTACK 6 SP: not started by a command */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80, 11,  3, 54,  0,  4, 24, 26,  1,  0,  0,  7, -7, 28, 73),  /* 82: ATTACK 6 SP: not started by a command */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80, 10,  3, 54,  0, 10, 20, 25,  5,  0,  0,  6, -6, 44, 73),  /* 83: ATTACK 10 M: not started by a command */
    ATTR( 40,  0,  0,  2,  0,  1,  0, 80, 10,  3, 54,  0, 10, 22, 25,  1,  0,  0, 10,-10, 44, 73),  /* 84: ATTACK 10 M: not started by a command */
    ATTR( 94,  0,  0,  1,  0,  1,  0, 80, 12,  3, 62,  0, 15, 10, 26,  1,  0,  0,  8, -8, 28, 73),  /* 85: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 10, 26,  1,  0,  0,  4, -4, 28, 73),  /* 86: ATTACK 2 SP: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 10, 25,  1,  0,  0,  2, -2, 28, 73),  /* 87: ATTACK 2 SP: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 10, 25,  1,  0,  0,  3, -3, 28, 73),  /* 88: ATTACK 2 SP: not started by a command */
    ATTR( 94,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0, 15, 10, 26,  1,  0,  0,  4, -4, 28, 73),  /* 89: ATTACK 2 SP: not started by a command */
};

extern const u16 necro_se_random_0[];

const u16* const necro_se_random_table[1] = {
    necro_se_random_0,  /* 0 */
};

const u16 necro_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
