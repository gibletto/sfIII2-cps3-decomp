/*
 * ELENA_ATTR.C  Elena's attack attributes and random sound lists
 *
 * elena_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * elena_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR elena_catt_table[103] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0, 20, 33,  6,  4,  0,  7, -7, 34, 73),  /* 1: M PUNCH C */
    ATTR( 34,  0,  0,  1,  0,  1,  1,  0, 14,  3, 62,  0,  0, 10, 33,  3,  1,  0,  4, -8, 34, 73),  /* 2: M PUNCH A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 13,  3, 62,  0,  0, 28, 35,  9,  7,  0,  7,-10, 39, 73),  /* 3: L PUNCH A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 62,  0,  0, 24, 36,  8,  7,  0,  4,-10, 39, 73),  /* 4: L KICK A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  8, 32,  2,  1,  0,  6, -6, 29, 72),  /* 5: S PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0, 10, 32,  3,  1,  0,  6, -6, 29, 72),  /* 6: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 10,  3, 63,  0,  0,  8, 32,  2,  1,  0,  6, -6, 29, 72),  /* 7: S KICK A, FUSHIN P S */
    ATTR( 89,  0,  0,  2,  0,  1,  1,  0, 11,  3, 45,  0,  5, 20, 35,  1,  7,  0,  8, -8, 34, 73),  /* 8: L KICK C, KAGAMI K C */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 63,  0,  0, 18, 34,  5,  4,  0,  4, -8, 34, 73),  /* 9: M KICK A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 18,  0,  0,  1, 10,-10,  0,  0),  /* 10: M PUNCH A, M PUNCH C, L PUNCH A */
    ATTR( 96,  0,  0,  2,  0,  1,  1,  0, 10,  3, 63,  0,  4, 24, 16,  6, 13,  0,  8, -8,  0, 78),  /* 11: CATCH 2 */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  0,  3, 63,  0,  0, 16, 36,  5,  4,  0,  8, -8, 34, 73),  /* 12: OKIAGARI P S */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  8, 32,  2,  1,  0,  6, -6, 29, 72),  /* 13: KAGAMI P A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 18, 33,  3,  4,  0,  7, -7, 34, 73),  /* 14: KAGAMI P A */
    ATTR( 35,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0,  0, 22, 35,  8,  7,  0,  8, -8, 39, 73),  /* 15: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 45,  0,  0,  8, 32,  1,  1,  0,  6, -6, 29, 72),  /* 16: KAGAMI K A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 12,  3, 45,  0,  0, 16, 34,  1,  4,  0,  7, -7, 34, 73),  /* 17: KAGAMI K A */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 12,  3, 45,  0,  2, 24, 36,  1,  7,  0,  8, -8, 39, 73),  /* 18: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0, 10, 37,  3,  1,  0,  5, -5, 29, 72),  /* 19: V JUMP P S A, F JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 20, 38,  6,  4,  0,  6, -6, 34, 73),  /* 20: V JUMP P M A, F JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 24, 39,  5,  7,  0,  7, -7, 39, 73),  /* 21: V JUMP P L A, F JUMP P L A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0, 10, 37,  3,  1,  0,  5, -5, 29, 72),  /* 22: V JUMP K S A, F JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 18, 38,  4,  4,  0,  6, -6, 34, 73),  /* 23: V JUMP K M A, F JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0,  8, 32,  1,  1,  0,  7, -7, 44, 73),  /* 24: V JUMP K L A, F JUMP K L A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0,  9,  3, 54,  0,  0, 22, 39,  6,  8,  0,  7, -7, 39, 73),  /* 25: V JUMP K L A, F JUMP K L A */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72, 11,  3, 63,  0,  0, 16, 32,  1,  1,  0,  8, -8, 44, 73),  /* 26: not used by a script */
    ATTR( 96,  1,  0,  2,  0,  1,  0, 72, 14,  3, 63,  0, 18, 26, 37,  6,  7,  0,  8, -8, 44, 73),  /* 27: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    ATTR( 38,  1,  0,  2,  0,  1,  0, 72, 14,  3, 63,  0, 19, 18, 32,  6,  1,  0,  7, -7, 44, 73),  /* 28: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 95,  0,  0,  2,  0,  1,  0, 72, 15,  3, 63,  0, 19, 12, 32,  1,  7,  0,  7, -7, 44, 73),  /* 29: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 91,  1,  0,  2,  0,  1,  0, 72, 15,  3, 63,  0, 20,  8, 32,  1,  1,  0,  6, -6, 44, 73),  /* 30: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  2,  0,  1,  0, 72,  0,  3, 63,  0, 20,  8, 32,  1,  1,  0,  6, -6, 44, 73),  /* 31: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72, 12,  3, 63,  0,  0,  8, 49,  1,  1,  0,  8, -8, 44, 73),  /* 32: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72, 10,  3, 63,  0,  0,  8, 49,  1,  1,  0,  8, -8, 44, 73),  /* 33: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72,  9,  3, 63,  0,  0,  8, 49,  1,  1,  0,  8, -8, 44, 73),  /* 34: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72,  0,  3, 63,  0,  0,  8, 39,  1,  1,  0,  8, -8, 44, 73),  /* 35: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 93,  0,  0,  2,  0,  1,  0, 72, 12,  3, 63,  0,  7, 28, 39,  9,  7,  0,  8, -8, 44, 73),  /* 36: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
    ATTR( 93,  0,  0,  2,  0,  1,  0, 72, 12,  3, 63,  0,  7, 30, 39,  9,  7,  0,  8, -8, 44, 73),  /* 37: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) */
    ATTR( 93,  0,  0,  2,  0,  1,  0, 72, 12,  3, 63,  0,  7, 32, 39,  9,  7,  0,  8, -8, 44, 73),  /* 38: ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  2,  0,  5,  0,208, 10,  3, 63,  1,  0, 22, 54,  0,  0,  0,  4, -8, 42, 73),  /* 39: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 37,  1,  0,  0,  0,  1,  0,208, 13,  3, 63,  1,  0, 17, 54,  0,  0,  0,  4, -8, 42, 73),  /* 40: CATCH 3, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  1,  0,  1,  0,  1,  0,192, 13,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 42, 73),  /* 41: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 34,  1,  0,  1,  0,  1,  0,208, 14,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 42, 73),  /* 42: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 37,  1,  0,  1,  0,  1,  0,208, 12,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 44, 73),  /* 43: not used by a script */
    ATTR( 36,  1,  0,  1,  0,  1,  0,192, 11,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 44, 73),  /* 44: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  1,  0,  2,  0,  1,  0,208, 12,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 42, 73),  /* 45: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  1,  0,  2,  0,  1,  0,192, 13,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 42, 73),  /* 46: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  1,  0,  2,  0,  1,  0,208, 12,  3, 63,  1,  0,  8, 54,  0,  0,  0,  4, -8, 42, 73),  /* 47: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  0,  0,  2,  0,  1,  0,200, 11,  3, 63,  1,  0,  8, 32,  0,  0,  0,  4, -4, 44, 73),  /* 48: not used by a script */
    ATTR( 94,  0,  0,  1,  0,  1,  0,200, 15,  3, 63,  0,  8, 24, 39,  0,  0,  0,  4, -8, 44, 73),  /* 49: not used by a script */
    ATTR( 37,  1,  0,  1,  0,  1,  0,200,  9,  3, 63,  0,  9, 10, 54,  1,  0,  0,  4,-12, 44, 73),  /* 50: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 38,  1,  0,  2,  0,  1,  7,208, 11,  3, 63,  0,  0, 18, 54,  1,  0,  0,  4, -8, 44, 73),  /* 51: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  1,  0,  2,  0,  1,  0,208, 13,  3, 63,  0, 10, 16, 48,  1,  0,  0,  8, -8, 44, 73),  /* 52: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 36,  0,  0,  1,  0,  1,  0, 72,  8,  3, 54,  0,  0, 24, 48,  6,  8,  0,  8, -8, 44, 73),  /* 53: follow-up of APPEAR 1 */
    ATTR( 36,  0,  0,  1,  0,  1,  0, 72,  8,  3, 54,  0,  0, 26, 48,  6,  8,  0,  8, -8, 44, 73),  /* 54: follow-up of SP WIN 3 */
    ATTR( 36,  0,  0,  1,  0,  1,  0, 72,  8,  3, 54,  0,  0, 28, 48,  6,  8,  0,  8, -8, 44, 73),  /* 55: follow-up of SP WIN 4 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  0, 16, 48,  6,  8,  0, 10,-10, 44, 73),  /* 56: follow-up of APPEAR 1 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  0, 18, 48,  6,  8,  0, 10,-10, 44, 73),  /* 57: follow-up of SP WIN 3 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  0, 20, 48,  6,  8,  0, 10,-10, 44, 73),  /* 58: follow-up of SP WIN 4 */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  8, 32,  3,  1,  0,  6, -6, 29, 73),  /* 59: UP P GUARD P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 16, 34,  5,  4,  0,  8, -8, 34, 73),  /* 60: UP P GUARD P M */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 12,  3, 63,  0,  0, 20, 35,  5,  4,  0, 10,-10, 39, 73),  /* 61: UP P GUARD P L */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0,  9,  3, 63,  0,  0,  8, 32,  2,  1,  0,  8, -8, 38, 73),  /* 62: UP P GUARD P L */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 10,  3, 63,  0,  0,  8, 32,  2,  1,  0,  6, -6, 29, 73),  /* 63: D P GUARD P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 11,  3, 63,  0,  0, 20, 35,  5,  4,  0,  8, -8, 34, 73),  /* 64: D P GUARD P M */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  8,  3, 63,  0,  0,  8, 32,  2,  1,  0,  8, -8, 44, 73),  /* 65: follow-up of APPEAR 1, follow-up of SP WIN 3, follow-up of SP WIN 4 */
    ATTR( 95,  0,  0,  2,  0,  1,  0,192, 15,  3, 63,  0,  8, 16, 33,  1,  0,  0,  4, -4, 44, 73),  /* 66: not used by a script */
    ATTR( 94,  1,  0,  2,  0,  1,  0,192,  0,  3, 63,  0,  8,  8, 37,  0,  0,  0,  4, -8, 44, 73),  /* 67: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 34,  0,  0,  1,  0,  1,  0,  0, 14,  3, 62,  0,  0,  8, 33,  4,  4,  0,  4, -4, 34, 73),  /* 68: M PUNCH A */
    ATTR( 37,  0,  0,  2,  0,  1,  0, 72, 14,  3, 63,  0, 20, 18, 32,  6, 11,  0,  6, -6, 44, 73),  /* 69: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 37,  1,  0,  1,  0,  1,  7,200,  9,  3, 63,  0,  9, 10, 54,  1,  0,  0,  4,-12, 42, 73),  /* 70: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  9,  3, 54,  0,  0, 16, 37,  3,  4,  0,  6, -6, 34, 73),  /* 71: ATTACK 7 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 38,  1,  1,  0,  6, -6, 34, 73),  /* 72: follow-up of V JUMP P S A, F JUMP P S A */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 11,  3, 62,  0,  0, 12, 32,  1, 12,  0,  4,-12, 44, 73),  /* 73: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 12, 32,  1,  1,  0,  6, -8, 44, 73),  /* 74: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 12, 32,  3,  1,  0,  2, -4, 44, 73),  /* 75: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  1,  0,  2,  0,  1,  0, 80, 13,  3, 62,  0,  7, 12, 35,  3,  1,  0,  8, -8, 44, 73),  /* 76: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 12, 32,  1, 12,  0,  2,-12, 44, 73),  /* 77: ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 13, 34,  1,  1,  0,  6, -8, 44, 73),  /* 78: ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 12, 32,  2,  1,  0,  2, -4, 44, 73),  /* 79: ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  1,  0,  2,  0,  1,  0, 80, 13,  3, 62,  0,  7, 13, 35,  3,  1,  0,  8, -8, 44, 73),  /* 80: ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 13, 32,  1, 12,  0,  2,-12, 44, 73),  /* 81: ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP), ATTACK 11 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 13, 34,  1,  1,  0,  6, -8, 44, 73),  /* 82: ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP), ATTACK 11 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0,  9, 32,  2,  1,  0,  2, -4, 44, 73),  /* 83: ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP), ATTACK 11 M: not started by a command */
    ATTR( 95,  1,  0,  2,  0,  1,  0, 80, 13,  3, 62,  0,  7,  9, 35,  2,  1,  0,  8, -8, 44, 73),  /* 84: ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP), ATTACK 11 M: not started by a command */
    ATTR( 91,  0,  0,  2,  0,  1,  0,  0, 12,  3, 45,  0, 11,  2, 32,  0, 15,  0,  6, -6, 29, 72),  /* 85: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    ATTR( 91,  0,  0,  2,  0,  1,  0,  0, 15,  3, 54,  0, 12,  2, 32,  0, 15,  0,  6, -6, 29, 72),  /* 86: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    ATTR( 37,  1,  0,  2,  0,  1,  0, 80, 14,  3, 63,  0, 13, 20, 32,  6,  0,  0,  4, -4, 44, 73),  /* 87: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 35,  1,  0,  2,  0,  1,  0, 80, 15,  3, 63,  0, 14,  8, 32,  1,  0,  0,  4, -4, 44, 73),  /* 88: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 96,  1,  0,  2,  0,  1,  0, 80,  0,  3, 63,  0, 15,  8, 32,  1,  0,  0,  4, -4, 44, 73),  /* 89: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  3,  0,  1,  0, 80,  1,  3, 63,  0, 16,  8, 32,  1,  0,  0, 12,-12, 44, 73),  /* 90: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  9,  3, 54,  0,  0, 24, 48,  6,  0,  0,  6, -6, 44, 73),  /* 91: follow-up of SP WIN 1 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 80,  8,  3, 54,  0,  0, 12, 32,  2,  0,  0,  6, -6, 44, 73),  /* 92: follow-up of SP WIN 1 */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 68, 12,  3, 63,  0,  0, 20, 32,  8,  0,  0,  8, -8, 44, 73),  /* 93: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    ATTR( 93,  1,  0,  2,  0,  1,  0, 68, 12,  3, 63,  0,  7, 16, 37,  1,  0,  0,  8, -8, 44, 73),  /* 94: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 12, 32,  1,  0,  0,  2,-12, 44, 73),  /* 95: ATTACK 10 S: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  1,  0,  2,  0,  1,  0, 80,  0,  3, 62,  0, 17,  8, 34,  1,  0,  0,  2, -2, 44, 73),  /* 96: ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  1,  0,  0,  0,  1,  0,208, 13,  3, 63,  1,  0, 17, 54,  0,  0,  0,  4, -8, 44, 73),  /* 97: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12, 39,  1,  1,  0,  7, -7, 39, 73),  /* 98: follow-up of V JUMP P M A, F JUMP P M A */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72, 12,  3, 63,  0,  0,  8, 49,  1,  0,  0,  8, -8, 44, 73),  /* 99: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72, 10,  3, 63,  0,  0,  8, 49,  1,  0,  0,  8, -8, 44, 73),  /* 100: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72,  9,  3, 63,  0,  0,  8, 49,  1,  0,  0,  8, -8, 44, 73),  /* 101: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 72,  0,  3, 63,  0,  0,  8, 39,  1,  0,  0,  8, -8, 44, 73),  /* 102: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
};

extern const u16 elena_se_random_0[];
extern const u16 elena_se_random_1[];

const u16* const elena_se_random_table[2] = {
    elena_se_random_0,  /* 0 */
    elena_se_random_1,  /* 1 */
};

const u16 elena_se_random_0[16] = {
    0x0175, 0x0175, 0x0175, 0x0248, 0x0175, 0x0249, 0x0175, 0x0248,
    0x0175, 0x0175, 0x0175, 0x0248, 0x0175, 0x0249, 0x0249, 0x0175,
};

const u16 elena_se_random_1[16] = {
    0x0209, 0x0175, 0x024A, 0x024B, 0x0209, 0x0175, 0x0175, 0x0209,
    0x0209, 0x0175, 0x024A, 0x024B, 0x0175, 0x0175, 0x0175, 0x0209,
};
