/*
 * ORO_ATTR.C  Oro's attack attributes and random sound lists
 *
 * oro_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * oro_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR oro_catt_table[87] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  6,  0,  2,  1,  0,  6, -6, 13, 72),  /* 1: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  5,  1,  2,  1,  0,  6, -6, 13, 72),  /* 2: S PUNCH B */
    ATTR( 95,  1,  0,  2,  0,  1,  0,  0, 12,  3, 62,  0, 15,  8,  2,  2,  4,  0,  9, -9, 18, 73),  /* 3: M PUNCH A */
    ATTR( 34,  0,  0,  1,  0,  1,  3,  0, 12,  3, 62,  0,  0, 20,  2,  6,  4,  0, 10,-10, 18, 73),  /* 4: M PUNCH B */
    ATTR( 96,  0,  0,  2,  0,  1,  1,  0, 14,  3, 27,  0,  1, 16,  3,  4,  8,  0,  8, -8, 23, 73),  /* 5: not used by a script */
    ATTR( 95,  0,  0,  2,  0,  1,  1,  0, 15,  3, 62,  0, 15,  8,  3,  2,  1,  0, 12,-12, 23, 73),  /* 6: M PUNCH A */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0, 10,  3, 54,  0,  5, 12,  3,  3,  8,  0,  8, -8, 23, 73),  /* 7: L PUNCH A, UP P GUARD P L */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0, 11,  3, 54,  0,  5, 16,  4,  3,  1,  0,  8, -8, 23, 73),  /* 8: L PUNCH A, UP P GUARD P L */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 14,  3, 63,  0,  0,  8,  0,  1,  1,  0,  6, -6, 29, 72),  /* 9: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6,  0,  1,  1,  0,  6, -6, 29, 72),  /* 10: S KICK B */
    ATTR( 38,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 22,  2,  5,  4,  0,  7, -7, 34, 73),  /* 11: M KICK A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 20,  2,  6,  4,  0,  7, -7, 34, 73),  /* 12: M KICK B, UP P GUARD K S */
    ATTR( 38,  0,  0,  2,  0,  1,  0,  0, 13,  3, 62,  0,  0, 24,  4,  9,  7,  0,  8, -8, 39, 73),  /* 13: L KICK A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 13,  3, 62,  0,  0, 24,  4,  7,  7,  0,  8, -8, 39, 73),  /* 14: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  8,  1,  2,  1,  0,  6, -6, 13, 72),  /* 15: KAGAMI P A */
    ATTR( 34,  1,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 26, 10,  5,  7,  0, 10,-14, 23, 73),  /* 16: KAGAMI P A */
    ATTR( 94,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  3, 24,  4,  5,  7,  0,  8, -8, 23, 73),  /* 17: not used by a script */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 24,  4,  5,  7,  0,  8, -8, 23, 73),  /* 18: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 45,  0,  0,  4,  0,  1,  1,  0,  6, -6, 29, 72),  /* 19: KAGAMI K A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 45,  0,  0, 18,  2,  1,  4,  0,  7, -7, 34, 73),  /* 20: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12,  5,  2,  1,  0,  5, -5, 13, 72),  /* 21: V JUMP P S A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12,  5,  3,  1,  0,  5, -5, 29, 72),  /* 22: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 22,  6,  5,  4,  0,  6, -6, 34, 73),  /* 23: V JUMP K M A */
    ATTR( 36,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 28,  7,  7,  7,  0,  7, -7, 39, 73),  /* 24: V JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  9,  3, 54,  0,  0, 12,  5,  3,  1,  0,  5, -5, 13, 72),  /* 25: F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0,  9,  3, 54,  0,  0, 20,  6,  5,  4,  0,  6, -6, 18, 73),  /* 26: F JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0,  9,  3, 54,  0,  0, 20,  7,  4,  7,  0,  7, -7, 23, 73),  /* 27: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 15,  3, 54,  0,  0,  8,  7,  4,  1,  0,  7, -7, 23, 73),  /* 28: F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0, 12,  5,  2,  1,  0,  5, -5, 29, 72),  /* 29: F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0, 20,  6,  4,  4,  0,  6, -6, 34, 73),  /* 30: F JUMP K M A */
    ATTR( 91,  0,  0,  1,  0,  1,  0, 80, 15,  3, 54,  0, 13,  8,  6,  2, 10,  0,  4, -4, 34, 73),  /* 31: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 36,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 24,  7,  6,  7,  0,  7, -7, 39, 73),  /* 32: F JUMP K L A */
    ATTR( 34,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 20,  2,  5,  4,  0, 10,-10, 18, 73),  /* 33: UP P GUARD P S, D P GUARD P S, FUSHIN P S */
    ATTR( 89,  0,  0,  1,  0,  1,  0,  0, 12,  3,  9,  0,  2, 20,  2,  5,  4,  0, 10,-10, 34, 73),  /* 34: D P GUARD K S */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 80, 15,  3, 63,  0,  4, 28,  2,  7, 11,  0, 10,-10, 28, 73),  /* 35: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 80,  0,  3, 63,  0,  4, 16,  2,  1,  1,  0,  8, -8, 28, 73),  /* 36: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN) */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 80, 15,  3, 63,  0,  4, 32,  2,  7, 11,  0, 10,-10, 28, 73),  /* 37: ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 80, 15,  3, 63,  0,  4, 20,  2,  1,  1,  0, 10,-10, 28, 73),  /* 38: ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 80, 15,  3, 63,  0,  4, 24,  2,  9, 11,  0,  4, -4, 28, 73),  /* 39: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    ATTR( 96,  0,  0,  2,  0,  1,  2, 80,  0,  3, 63,  0,  4, 12,  2,  1,  1,  0,  6, -6, 28, 73),  /* 40: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 80,  1,  3, 63,  0,  4,  8,  2,  1,  1,  0, 12,-12, 28, 73),  /* 41: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 63,  0,  0,  8,  2,  4,  0,  0,  8, -8, 23, 73),  /* 42: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 13,  3, 63,  0,  0,  8,  2,  5,  0,  0,  8, -8, 23, 73),  /* 43: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 14,  3, 63,  0,  0,  8,  2,  6,  0,  0,  8, -8, 23, 73),  /* 44: not used by a script */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80, 11,  3, 54,  0,  0,  8,  2,  4,  0,  0,  8, -8, 23, 73),  /* 45: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 18,  0,  0,  2, 10,-10, 70,  0),  /* 46: M PUNCH A, M PUNCH B, L PUNCH A +1 */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0,  1,  3, 63,  0,  6, 24, 16,  7, 13,  1,  8, -8, 73, 74),  /* 47: CATCH 2 */
    ATTR( 37,  0,  0,  2,  5,  1,  0,  0,  2,  3, 63,  0,  7,  8, 16,  2,  1,  2,  8, -8, 71, 73),  /* 48: CATCH 11, CATCH 12, CATCH 13 */
    ATTR( 37,  0,  0,  2, 27,  1,  0, 64,  8,  3, 63,  0,  8,  8, 16,  2, 13,  1,  8, -8, 74, 75),  /* 49: CATCH 5 */
    ATTR( 37,  0,  0,  2, 32,  1,  0,  0, 10,  3, 56,  0,  0,  0, 16,  0,  4,  1, 10,-10, 84,  0),  /* 50: TUKAMIKAKARI A, ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script) +1 */
    ATTR( 37,  0,  0,  2, 26,  1,  0,  0,  8,  3, 63,  0,  8,  8, 16,  2,  1,  1,  8, -8, 74, 75),  /* 51: CATCH 5 */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 16,  2,  1,  4,  0,  7, -7, 18, 73),  /* 52: KAGAMI P A */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 12,  3, 45,  0,  2, 24,  4,  1,  7,  0,  8, -8, 39, 73),  /* 53: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 22,  6,  4,  4,  0,  6, -6, 18, 73),  /* 54: V JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 28,  7,  6,  7,  0,  7, -7, 23, 73),  /* 55: V JUMP P L A */
    ATTR( 37,  0,  0,  2, 27,  1,  0,192,  8,  3, 63,  0,  0,  8, 16,  0,  0,  1,  8, -8,125, 73),  /* 56: CATCH 6 */
    ATTR( 96,  0,  0,  0,  0,  1,  0,192,  1,  3, 63,  0,  9, 36, 16,  0,  0,  1,  8, -8,125, 60),  /* 57: CATCH 6 */
    ATTR( 37,  0,  0,  2,  0,  1,  0,192, 13,  3,  0,  0,  0,  0, 18,  0,  0,  1, 10,-10, 70, 73),  /* 58: follow-up of WIN 8, follow-up of SP WIN 1, follow-up of ZANNEN 2 +1 */
    ATTR( 37,  0,  0,  2, 26,  1,  0,192,  8,  3, 63,  0,  0,  8, 16,  0,  0,  1,  8, -8,125, 73),  /* 59: CATCH 6 */
    ATTR( 96,  0,  0,  2,  0,  1,  0,  0,  1,  3, 63,  0, 12, 36, 16,  7, 13,  0,  8, -8, 39, 74),  /* 60: CATCH 4 */
    ATTR( 91,  0,  0,  1,  0,  1,  0, 64, 15,  3, 54,  0, 13,  4,  6,  0,  1,  0, -6, -6, 34, 73),  /* 61: ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 37,  0,  0,  1,  0,  1,  0,192, 11,  3,  0,  0,  0,  0, 18,  0,  0,  1, 10,-10, 70, 73),  /* 62: follow-up of ZANNEN 7 */
    ATTR( 96,  0,  0,  2,  0,  1,  0,192,  1,  3, 63,  1,  0, 12, 16,  0,  0,  0,  8, -8, 39, 55),  /* 63: CATCH 7 */
    ATTR( 96,  0,  0,  2,  0,  1,  0,192,  1,  3, 63,  0, 12, 34, 16,  0,  0,  0,  8, -8, 40, 56),  /* 64: CATCH 7 */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 10,  3,  0,  1,  0,  0, 18,  0,  0,  1, 10,-10, 70,  0),  /* 65: V JUMP P L A, F JUMP P L A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 18,  0,  0,  1, 10,-10, 70,  0),  /* 66: M KICK A, M KICK B, L KICK A */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 10, 62,  2, 11,  0,  6, -8, 39, 73),  /* 67: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) */
    ATTR( 97,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 10,  6,  2,  1,  0,  6, -8, 39, 73),  /* 68: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  9,  3, 54,  0,  0, 16,  7,  6,  4,  0,  6, -6, 18, 73),  /* 69: ATTACK 11 L: not started by a command */
    ATTR( 37,  0,  0,  2, 27,  1,  0, 64,  8,  3, 63,  0,  8, 14, 16,  4,  1,  0,  8, -8, 74,  0),  /* 70: CATCH 5, CATCH 9, CATCH 10 */
    ATTR( 96,  0,  0,  2,  0,  1,  3,  0, 15,  3, 63,  0, 16, 20,  2,  1,  4,  0, 10,-10, 23, 73),  /* 71: OKIAGARI P S */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 12, 62,  2, 11,  0,  6, -8, 39, 73),  /* 72: ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI) */
    ATTR( 97,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 12,  6,  2,  1,  0,  6, -8, 39, 73),  /* 73: ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI) */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 14, 62,  2, 11,  0,  6, -8, 39, 73),  /* 74: ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) */
    ATTR( 97,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 12,  6,  2,  1,  0,  6, -8, 39, 73),  /* 75: ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) */
    ATTR( 37,  0,  0,  2, 27,  1,  0, 64,  8,  3, 63,  0,  8, 10, 16,  2, 13,  1,  8, -8, 74, 75),  /* 76: CATCH 9 */
    ATTR( 37,  0,  0,  2, 26,  1,  0, 64,  8,  3, 63,  0,  8, 10, 16,  2,  1,  1,  8, -8, 74, 75),  /* 77: CATCH 9 */
    ATTR( 37,  0,  0,  2, 27,  1,  0, 64,  8,  3, 63,  0,  8, 12, 16,  2, 13,  1,  8, -8, 74, 75),  /* 78: CATCH 10 */
    ATTR( 37,  0,  0,  2, 26,  1,  0, 64,  8,  3, 63,  0,  8, 12, 16,  2,  1,  1,  8, -8, 74, 75),  /* 79: CATCH 10 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 13, 62,  2,  0,  0,  6, -8, 39, 73),  /* 80: ATTACK 11 M: EX 236+KK (routine Att_JINNCHUUWATARI_EX) */
    ATTR( 97,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0, 14, 15,  6,  2,  0,  0,  6, -8, 39, 73),  /* 81: ATTACK 11 M: EX 236+KK (routine Att_JINNCHUUWATARI_EX) */
    ATTR( 91,  1,  0,  1,  0,  1,  0, 80,  9,  3, 54,  0, 17,  9,  6,  2,  0,  0,  4, -4, 34, 73),  /* 82: ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 91,  0,  0,  1,  0,  1,  0, 64,  9,  3, 54,  0, 17,  5,  6,  0,  0,  0, -6, -6, 34, 73),  /* 83: ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 96,  0,  0,  2,  0,  1,  0, 80, 15,  3, 63,  0, 18, 14,  2,  7,  0,  0,  4, -4, 28, 73),  /* 84: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    ATTR( 96,  0,  0,  2,  0,  1,  1, 80,  0,  3, 63,  0, 18, 12,  2,  1,  0,  0,  6, -6, 28, 73),  /* 85: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2,  0,  1,  1, 80,  1,  3, 63,  0, 19,  6,  2,  1,  0,  0, 12,-12, 28, 73),  /* 86: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
};

extern const u16 oro_se_random_0[];

const u16* const oro_se_random_table[1] = {
    oro_se_random_0,  /* 0 */
};

const u16 oro_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
