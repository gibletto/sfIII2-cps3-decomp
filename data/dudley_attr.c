/*
 * DUDLEY_ATTR.C  Dudley's attack attributes and random sound lists
 *
 * dudley_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * dudley_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR dudley_catt_table[112] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0, 22,  4, 16,  1,  1,  0,  4, -4, 13, 72),  /* 1: S PUNCH A, ATTACK 13 SP: 6(123)456+P light (plain script) */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0,  9,  3, 54,  0,  0, 28, 22,  3,  1,  0,  6, -6, 23, 73),  /* 2: not used by a script */
    ATTR( 33,  0,  0,  0,  0,  1,  1,  0, 12,  3, 63,  0, 22,  8, 48,  1,  1,  0,  4, -4, 13, 72),  /* 3: S KICK A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 62,  0, 23, 12, 17,  4,  4,  0,  7, -7, 18, 73),  /* 4: M PUNCH A, UP P GUARD P S, UP P GUARD P L +1 */
    ATTR( 35,  1,  0,  2,  0,  1,  1,  0, 15,  3, 62,  0,  0, 18, 48,  5,  4,  0,  7, -7, 18, 73),  /* 5: M KICK A */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 22, 16,  3,  7,  0,  7, -7, 23, 73),  /* 6: L KICK C */
    ATTR( 32,  0,  0,  0,  0,  1,  3,  0, 12,  3, 63,  0, 22,  5, 16,  1,  1,  0,  4, -4, 13, 73),  /* 7: S PUNCH C */
    ATTR( 38,  1,  0,  1,  0,  1,  1,  0, 12,  3, 62,  0,  0, 20, 50,  4,  4,  0,  7, -7, 18, 73),  /* 8: M KICK C */
    ATTR( 35,  0,  0,  2,  0,  1,  2,  0, 15,  3, 62,  0,  0, 24, 19,  6,  7,  0,  8, -8, 23, 73),  /* 9: L KICK A */
    ATTR( 93,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  1, 36, 19,  3,  7,  0,  8, -8, 13, 73),  /* 10: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  2,  0, 12,  3, 62,  0, 10, 28, 20,  6,  7,  0,  5, -7, 23, 73),  /* 11: L PUNCH A, L PUNCH C, 6(123)456+P heavy (plain script) +1 */
    ATTR( 37,  0,  0,  0,  0,  1,  1,  0, 12,  3, 63,  0, 22,  4, 16,  1,  1,  0,  6, -6, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  1,  0, 12,  3, 63,  0,  4, 16, 17,  3,  4,  0,  7, -7, 18, 73),  /* 13: KAGAMI P A */
    ATTR( 35,  1,  0,  2,  0,  1,  1,  0, 15,  3, 63,  0, 24, 26, 19,  6,  7,  0,  8, -8, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 35,  1,  0,  2,  0,  1,  1,  0,  0,  3, 63,  0, 24, 26, 19,  6,  7,  0,  8, -8, 23, 73),  /* 15: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  1,  0, 10,  3, 45,  0, 22,  6, 16,  1,  1,  0,  6, -6, 13, 72),  /* 16: KAGAMI K A */
    ATTR( 89,  0,  0,  1,  0,  1,  1,  0, 12,  3, 45,  0,  2, 16, 19,  1,  4,  0,  7, -7, 18, 73),  /* 17: KAGAMI K A, UP P GUARD K S */
    ATTR( 95,  0,  0,  2,  0,  1,  0,  0, 12,  3, 45,  0, 26, 20, 20,  1,  7,  0, -8, -8, 23, 73),  /* 18: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0,  8, 21,  4,  1,  0,  5, -5, 13, 72),  /* 19: V JUMP P S A, F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 16, 22,  6,  4,  0,  6, -6, 18, 73),  /* 20: V JUMP P M A, F JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0, 24, 23,  7,  7,  0,  7, -7, 23, 73),  /* 21: V JUMP P L A, F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  8,  3, 54,  0,  0,  8, 21,  2,  1,  0,  5, -5, 13, 72),  /* 22: V JUMP K S A, F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0,  8,  3, 54,  0,  0, 12, 22,  3,  4,  0,  6, -6, 18, 73),  /* 23: V JUMP K M A, F JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0,  9,  3, 54,  0,  9, 16, 23,  4,  7,  0,  7, -7, 23, 73),  /* 24: V JUMP K L A, F JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 28, 18,  5,  4,  0,  8, -8, 18, 73),  /* 25: FUSHIN P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 32, 20,  5,  4,  0, 10,-10, 24, 73),  /* 26: OKIAGARI P S */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 34,  0,  0,  1, 10,-10, 70,  0),  /* 27: M PUNCH A, L PUNCH A, L PUNCH C +2 */
    ATTR( 37,  0,  0,  1,  4,  1,  3,  0, 14,  3, 63,  0,  5,  8, 34,  2,  1,  0, 12,-12, 23, 72),  /* 28: CATCH 5, CATCH 6, CATCH 7 */
    ATTR( 37,  0,  0,  2,  0,  1,  3,  0, 12,  3, 63,  0,  6, 24, 34,  6, 13,  0, 12,-12, 73, 73),  /* 29: CATCH 1 */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 72,  3,  3, 63,  0, 18, 28, 16,  8, 11,  0, 12,-12, 28, 73),  /* 30: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    ATTR( 95,  0,  0,  1,  0,  1,  2, 72,  4,  3, 63,  0,  0, 16, 16,  1, 11,  0, 10,-10, 28, 73),  /* 31: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    ATTR( 95,  0,  0,  2,  0,  1,  2, 72,  3,  3, 63,  0, 19, 32, 16,  9, 11,  0, 12,-12, 28, 73),  /* 32: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 95,  0,  0,  1,  0,  1,  2, 72,  4,  3, 63,  0,  0, 20, 16,  1, 11,  0, 10,-10, 28, 73),  /* 33: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 95,  0,  0,  2,  0,  1,  1, 72,  3,  3, 63,  0, 20, 28, 16,  8,  1,  0, 12,-12, 28, 73),  /* 34: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 95,  0,  0,  2,  0,  1,  1, 72,  4,  3, 63,  0,  0, 24, 16,  1, 11,  0, 10,-10, 28, 73),  /* 35: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 95,  0,  0,  2,  0,  1,  3,208,  1,  3, 63,  0, 17,  6, 16,  1,  0,  0,  4, -4, 28, 73),  /* 36: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  0,  0,  1,  0,  1,  1, 68, 15,  3, 63,  0, 21,  8, 16,  2, 11,  0,  6,-10, 23, 73),  /* 37: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 93,  0,  0,  2,  0,  1,  0,196, 11,  7, 62,  0,  8, 31, 16,  0,  0,  0,  2, -4, 28, 73),  /* 38: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  0,  0,  2,  0,  1,  0,200, 13,  7, 62,  0,  8, 12, 16,  0,  0,  0,  2, -4, 28, 73),  /* 39: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  0,  0,  2,  0,  1,  0,208, 12,  7, 62,  0,  8,  8, 16,  0,  0,  0,  4, -6, 28, 73),  /* 40: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  0,  0,  2,  0,  1,  0,208, 11,  7, 62,  0,  8,  8, 16,  0,  0,  0,  6, -6, 28, 73),  /* 41: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  0,  0,  2,  0,  1,  0,208, 12,  7, 62,  0,  8,  4, 19,  0,  0,  0, 10,-10, 28, 73),  /* 42: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  1,  0,  2,  0,  1,  0, 64, 12,  3, 62,  0,  0,  8, 48,  1, 12,  0,  7, -7, 23, 73),  /* 43: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 33,  1,  0,  1,  0,  1,  0, 64, 12,  3, 62,  0,  0,  4, 48,  1,  1,  0,  5, -5, 23, 73),  /* 44: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  2,  0,  1,  0, 64, 12,  3, 62,  0,  0,  4, 48,  0,  1,  0,  5, -5, 23, 73),  /* 45: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 38,  1,  0,  1,  0,  1,  0, 80, 12,  3, 62,  0,  0,  4, 48,  1,  1,  0,  5, -5, 23, 73),  /* 46: ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 37,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0,  4, 48,  0,  1,  0,  5, -5, 23, 73),  /* 47: ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 38,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  2, 12, 18,  1,  1,  0, 11,-11, 28, 73),  /* 48: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 35,  1,  0,  2,  0,  1,  0, 80, 13,  3, 62,  0,  2,  8, 18,  1,  1,  0, 11,-11, 28, 73),  /* 49: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 96,  0,  0,  3,  0,  1,  7,200, 15,  3, 63,  0, 11, 28, 16,  1,  0,  0,  8, -8, 28, 73),  /* 50: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  0,  0,  2,  0,  1,  7,200,  0,  3, 63,  0, 12, 12, 16,  1,  0,  0,  6, -6, 28, 73),  /* 51: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 37,  0,  0,  2,  0,  1,  0,200, 12,  3, 62,  0,  0, 28, 48,  1,  0,  0,  8, -8, 28, 73),  /* 52: ATTACK 3 S: SA II 23623+P (plain script) */
    ATTR( 38,  1,  0,  2,  0,  1,  0,208, 12,  3, 62,  0,  0,  8, 48,  2,  0,  0,  3, -7, 28, 73),  /* 53: ATTACK 3 S: SA II 23623+P (plain script) */
    ATTR( 34,  1,  0,  2,  0,  1,  0,208, 12,  3, 62,  0,  0,  8, 48,  2,  0,  0,  3, -7, 28, 73),  /* 54: ATTACK 3 S: SA II 23623+P (plain script) */
    ATTR( 35,  0,  0,  2,  0,  1,  0, 68, 13,  3, 63,  0,  0,  4, 48,  6,  7,  0,  4, -8, 23, 73),  /* 55: ATTACK 10 SP: not started by a command */
    ATTR( 35,  0,  0,  2,  0,  1,  0, 68, 14,  3, 63,  0,  0, 12, 48,  6,  2,  0,  6,-10, 24, 73),  /* 56: ATTACK 10 SP: not started by a command */
    ATTR( 35,  0,  0,  2,  0,  1,  0, 68, 15,  3, 63,  0,  0, 24, 18,  6,  2,  0, 10,-10, 24, 73),  /* 57: ATTACK 10 SP: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  2, 80, 12,  3, 62,  0, 10, 40, 20,  8,  7,  0, 10,-10, 28, 73),  /* 58: ATTACK 13 M: not started by a command */
    ATTR( 96,  0,  0,  3,  0,  1,  7,200, 15,  3, 63,  0, 13, 16, 16,  1,  0,  0,  6, -6, 28, 73),  /* 59: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  0,  0,  3,  0,  1,  7,200,  0,  3, 63,  0, 14, 12, 16,  1,  0,  0,  4, -4, 28, 73),  /* 60: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  0,  0,  2,  0,  1,  7,208, 15,  3, 63,  0, 15, 16, 16,  1,  0,  0,  6, -6, 28, 73),  /* 61: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  0,  0,  2,  0,  1,  0,208,  0,  3, 63,  0, 16,  6, 16,  0,  0,  0,  4, -4, 28, 73),  /* 62: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 37,  1,  0,  1,  0,  1,  1, 80, 13,  3, 62,  0, 24, 12, 17,  3,  7,  0,  6, -6, 23, 73),  /* 63: ATTACK 13 L: not started by a command */
    ATTR( 35,  1,  0,  2,  0,  1,  1, 80,  0,  3, 62,  0, 24, 28, 18,  4,  1,  0, 10,-10, 28, 73),  /* 64: ATTACK 13 L: not started by a command */
    ATTR( 95,  0,  0,  1,  0,  1,  1, 72, 15,  3, 63,  0, 21, 12, 16,  2,  0,  0,  6,-10, 23, 73),  /* 65: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU), ATTACK 10 M: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  1, 72,  3,  3, 63,  0, 20, 32, 16,  8,  0,  0, 12,-12, 28, 73),  /* 66: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU), ATTACK 10 M: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  1, 72,  4,  3, 63,  0,  0, 28, 16,  1,  0,  0, 10,-10, 28, 73),  /* 67: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU), ATTACK 10 M: not started by a command */
    ATTR( 37,  0,  0,  0,  0,  1,  0, 68, 12,  3, 63,  0,  0,  8, 48,  5,  7,  0,  6, -6, 18, 73),  /* 68: not used by a script */
    ATTR( 38,  0,  0,  1,  0,  1,  0, 68, 13,  3, 63,  0,  0, 12, 48,  2,  2,  0,  8, -8, 23, 73),  /* 69: not used by a script */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 68, 12,  3, 63,  0, 10, 24, 19,  2,  2,  0, 10,-10, 28, 73),  /* 70: not used by a script */
    ATTR( 96,  1,  0,  2,  0,  1,  0,208, 13,  3, 62,  0, 30, 38, 16,  1,  0,  0, 10,-10, 23, 73),  /* 71: ATTACK 3 S: SA II 23623+P (plain script) */
    ATTR( 96,  1,  0,  2,  0,  1,  0,208, 13,  3, 62,  0, 30, 12, 16,  1,  0,  0, 10,-10, 13, 73),  /* 72: ATTACK 3 S: SA II 23623+P (plain script) */
    ATTR( 35,  0,  0,  2,  0,  1,  0,  0, 15,  3, 62,  0,  0, 12, 18,  1,  1,  0,  8, -8, 18, 73),  /* 73: follow-up of L KICK C / KAGAMI K A +1 */
    ATTR( 35,  0,  0,  2,  0,  1,  0,  0, 15,  3, 62,  0,  0, 12, 18,  2,  5,  0,  8, -8, 18, 73),  /* 74: follow-up of M PUNCH A / M KICK C */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3, 62,  0, 10, 16, 19,  1,  1,  0, 10,-10, 23, 73),  /* 75: follow-up of follow-up of M PUNCH A / M KICK C */
    ATTR(100,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 16, 19,  9,  7,  0,  2,-10, 23, 73),  /* 76: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    ATTR(100,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 20, 19,  9,  7,  0,  2,-10, 23, 73),  /* 77: ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script) */
    ATTR(100,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 24, 19,  9,  7,  0,  2,-10, 23, 73),  /* 78: ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script) */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  0, 19,  5,  7,  0,  0, 18, 23, 73),  /* 79: ATTACK 11 M: 6(123)4+P light (plain script), ATTACK 11 L: 6(123)4+P medium (plain script), ATTACK 11 SP: 6(123)4+P heavy (plain script) +5 */
    ATTR( 32,  1,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 12, 60,  1,  1,  0,  8, -8, 18, 73),  /* 80: follow-up of follow-up of S KICK A */
    ATTR( 35,  1,  0,  2,  0,  1,  0,  0, 15,  3, 62,  0,  0, 16, 48,  1,  1,  0,  8, -8, 18, 73),  /* 81: follow-up of S KICK A */
    ATTR( 32,  1,  0,  2,  0,  1,  0,  0, 12,  3, 63,  0,  0, 16, 20,  1,  1,  0,  8, -8, 23, 73),  /* 82: atca 161 */
    ATTR( 35,  1,  0,  2,  0,  1,  0,  0, 15,  3, 63,  0,  0, 24, 20,  1,  1,  0, 10,-10, 23, 73),  /* 83: atca 162 */
    ATTR( 32,  1,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0,  8, 48,  2,  1,  0,  8, -8, 18, 73),  /* 84: follow-up of S PUNCH A */
    ATTR( 35,  1,  0,  2,  0,  1,  0,  0, 15,  3, 62,  0,  0, 20, 18,  1,  4,  0,  6, -6, 18, 73),  /* 85: follow-up of follow-up of S PUNCH A */
    ATTR( 37,  1,  0,  2,  0,  1,  0,  0, 15,  3, 62,  0,  0, 12, 60,  1,  1,  0,  8, -8, 23, 73),  /* 86: follow-up of M KICK A */
    ATTR( 37,  1,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0,  8, 19,  1,  1,  0,  8, -8, 28, 73),  /* 87: follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A */
    ATTR( 35,  1,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0,  8, 19,  1,  1,  0, 10,-10, 28, 73),  /* 88: follow-up of follow-up of M KICK A / follow-up of follow-up of S KICK A */
    ATTR( 32,  1,  0,  2,  0,  1,  0, 72, 12,  3, 62,  0,  0,  4, 19,  2,  1,  0,  8, -8, 28, 73),  /* 89: not used by a script */
    ATTR( 37,  1,  0,  2,  0,  1,  0, 72, 12,  3, 62,  0,  0,  4, 19,  1,  1,  0,  8, -8, 28, 73),  /* 90: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  8,  3, 54,  0,  0, 20, 22,  4,  4,  0,  6, -6, 18, 73),  /* 91: not started by a command */
    ATTR( 95,  0,  0,  2,  0,  1,  0,208,  0,  3, 63,  0, 25,  4, 16,  1,  0,  0,  4, -4, 28, 73),  /* 92: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 54,  0,  0, 12, 21,  4,  1,  0,  5, -5, 13, 72),  /* 93: atca 168 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 68, 12,  3, 54,  0,  0, 10, 17,  1,  1,  0,  8, -8, 28, 73),  /* 94: ATTACK 8 S: 214+K light/medium/heavy (routine Att_SLIDE_and_JUMP) */
    ATTR(100,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  0, 28, 19,  9,  0,  0,  2,-10, 23, 73),  /* 95: not used by a script */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 68, 12,  3, 54,  0,  0, 12, 16,  1,  0,  0,  5,-10, 28, 73),  /* 96: ATTACK 8 SP: EX 214+KK (routine Att_HOMING_JUMP) */
    ATTR( 95,  0,  0,  2,  0,  1,  0, 64, 15,  3, 63,  0, 27,  8, 16,  1,  0,  0,  2, -2, 23, 73),  /* 97: ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    ATTR(100,  0,  0,  2,  0,  1,  0, 64, 13,  3, 63,  0, 28, 24, 19,  8,  0,  0,  2,-10, 23, 73),  /* 98: ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) +1 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 68, 12,  3, 54,  0,  0, 10, 17,  1, 12,  0,  8, -8, 28, 73),  /* 99: ATTACK 8 S: 214+K light/medium/heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  1,  0,  2,  0,  1,  0, 64, 12,  3, 62,  0,  0,  8, 48,  1,  0,  0,  7, -7, 23, 73),  /* 100: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 33,  1,  0,  1,  0,  1,  0, 64, 12,  3, 62,  0,  0,  4, 48,  1,  0,  0,  5, -5, 23, 73),  /* 101: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  2,  0,  1,  0, 64, 12,  3, 62,  0,  0,  4, 48,  0,  0,  0,  5, -5, 23, 73),  /* 102: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 38,  1,  0,  1,  0,  1,  0, 80, 12,  3, 62,  0,  0,  4, 48,  1,  0,  0,  5, -5, 23, 73),  /* 103: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 37,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0,  4, 48,  0,  0,  0,  5, -5, 23, 73),  /* 104: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 38,  1,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  2, 12, 48,  1,  0,  0, 11,-11, 28, 73),  /* 105: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 35,  1,  0,  2,  0,  1,  0, 80, 13,  3, 62,  0,  2,  8, 48,  1,  0,  0, 11,-11, 28, 73),  /* 106: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 95,  1,  0,  2,  0,  1,  0, 80, 13,  3, 63,  0, 29,  8, 18,  1,  0,  0,  8, -8, 23, 73),  /* 107: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 35,  1,  0,  2,  0,  1,  0, 80, 13,  3, 63,  0, 29,  8, 18,  1,  0,  0,  8, -8, 23, 73),  /* 108: ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    ATTR( 37,  0,  0,  1,  0,  1,  1,  0, 12,  3, 63,  0,  4, 10, 17,  1,  1,  0,  4, -6, 18, 73),  /* 109: follow-up of JUDGMENT WAIT */
    ATTR( 35,  1,  0,  2,  0,  1,  1,  0,  0,  3, 63,  0, 24, 16, 19,  6,  7,  0,  8, -8, 23, 73),  /* 110: follow-up of follow-up of JUDGMENT WAIT */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 62,  0, 23, 10, 17,  3,  4,  0,  7, -7, 18, 73),  /* 111: follow-up of S PUNCH C */
};

extern const u16 dudley_se_random_0[];

const u16* const dudley_se_random_table[1] = {
    dudley_se_random_0,  /* 0 */
};

const u16 dudley_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
