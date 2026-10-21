/*
 * URIEN_ATTR.C  Urien's attack attributes and random sound lists
 *
 * urien_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * urien_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR urien_catt_table[54] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 63,  0,  0,  4, 32,  1,  1,  0,  6, -6, 13, 72),  /* 1: S PUNCH A, UP P GUARD P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 14,  3, 62,  0,  0, 16, 33,  4,  4,  0,  7, -7, 18, 72),  /* 2: M PUNCH C */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 16, 34,  4,  4,  0,  7, -7, 18, 72),  /* 3: M PUNCH A, follow-up of S PUNCH A, UP P GUARD P M */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 10, 35,  5,  7,  0,  8, -8, 23, 73),  /* 4: not used by a script */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0, 10,  3, 62,  0,  9, 26, 35,  5,  7,  0,  8, -8, 23, 73),  /* 5: L PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 63,  0,  0,  6, 32,  1,  1,  0,  6, -6, 29, 72),  /* 6: S KICK A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0, 10, 32,  3,  1,  0,  6, -6, 29,  0),  /* 7: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 16, 34,  4,  4,  0,  7, -7, 34, 72),  /* 8: M KICK A */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 11,  3, 54,  0,  9, 10, 35,  1,  1,  0,  8, -8, 39, 73),  /* 9: L KICK A, UP P GUARD P L */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0,  9,  3, 54,  0,  9, 18, 35,  4,  8,  0,  8, -8, 39, 73),  /* 10: L KICK A, UP P GUARD P L */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 11,  3, 63,  0,  0, 30, 36,  7,  7,  0,  8, -8, 39,  0),  /* 11: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  4, 32,  1,  1,  0,  6, -6, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 14,  3, 63,  0,  0, 12, 34,  4,  4,  0,  7, -7, 18, 72),  /* 13: KAGAMI P A */
    ATTR( 95,  0,  0,  2,  0,  1,  0,  0, 15,  3, 63,  0,  8, 10, 35,  2,  1,  0,  8, -8, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 45,  0,  0,  4, 32,  1,  1,  0,  6, -6, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 45,  0,  0, 14, 34,  1,  4,  0,  7, -7, 34, 72),  /* 16: KAGAMI K A */
    ATTR( 89,  0,  0,  0,  0,  1,  0,  0, 13,  3, 45,  0,  1, 22, 36,  1,  7,  0,  8, -8, 39, 73),  /* 17: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  9,  3, 54,  0,  0, 10, 37,  1,  1,  0,  5, -5, 13, 72),  /* 18: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 18, 38,  4,  4,  0,  6, -6, 18, 72),  /* 19: V JUMP P M A, V JUMP K S A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 10,  3, 54,  0,  0, 26, 39,  5,  7,  0,  7, -7, 23, 73),  /* 20: V JUMP P L A, ATTACK 4 M: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 11,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8,  0, 73),  /* 21: M PUNCH A, M PUNCH C, L PUNCH A +4 */
    ATTR( 32,  0,  0,  1, 54,  1,  0,  0, 10,  3, 63,  0,  2, 28, 38,  6, 13,  0, 10,-10, 55, 73),  /* 22: CATCH 1 */
    ATTR( 32,  0,  0,  2, 38,  1,  0,  0,  6,  3, 63,  0,  4,  4, 36,  2,  1,  0, 12,-12, 71, 72),  /* 23: CATCH 2 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 72, 10,  3, 54,  0,  5, 22, 36,  5, 12,  0,  8, -8, 44, 73),  /* 24: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 35,  0,  0,  2,  0,  1,  0, 72, 13,  3, 54,  0,  6,  6, 36,  5, 12,  0, 12,-16, 44, 73),  /* 25: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 72, 13,  3, 54,  0, 12, 24, 36,  6, 10,  0, 12,-12, 28, 73),  /* 26: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 16, 12,  3, 62,  0,  6,  6, 36,  1,  1,  0, 12,-12, 28, 73),  /* 27: not used by a script */
    ATTR( 38,  0,  0,  2,  0,  1,  0,  0, 13,  3, 63,  0,  7, 14, 35,  2,  8,  0,  8, -8, 23, 73),  /* 28: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 10, 37,  1,  1,  0,  5, -5, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 18, 38,  4,  4,  0,  6, -6, 34, 72),  /* 30: V JUMP K M A, FUSHIN P S */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 11,  3, 54,  0,  0, 26, 39,  5,  7,  0,  7, -7, 39, 73),  /* 31: V JUMP K L A */
    ATTR(110,  1,  0,  1, 53,  1,  0,  8,  2,  3, 62,  0, 10, 24, 39,  2,  7,  0, 16,-16, 28, 60),  /* 32: ATTACK 2 M: not started by a command */
    ATTR( 33,  0,  0,  2,  0,  1,  0,  8, 11,  3, 62,  0, 11, 16, 39,  5,  1,  0, 12,-12, 28, 72),  /* 33: ATTACK 2 M: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  9,  3, 54,  0,  0, 10, 37,  3,  4,  0,  6, -6, 13, 72),  /* 34: ATTACK 7 M: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 22, 34,  2,  7,  0, 12,-12, 28, 73),  /* 35: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 28, 35,  3,  7,  0, 12,-12, 28, 73),  /* 36: ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 32, 36,  4,  7,  0, 12,-12, 28, 73),  /* 37: ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 18, 34,  4,  4,  0,  7, -7, 34, 72),  /* 38: M KICK C */
    ATTR( 33,  0,  0,  2,  0,  1,  0,208, 12,  3, 62,  0,  0, 12, 35,  0,  0,  0,  4,-12, 28, 73),  /* 39: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  0,  0,  2,  0,  1,  0,208, 12,  3, 62,  0,  0, 16, 35,  0,  0,  0,  4,-12, 28, 73),  /* 40: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR(110,  1,  0,  1, 53,  1,  2,208,  2,  3, 62,  0, 10, 32, 39,  0,  0,  0, 16,-16, 28, 60),  /* 41: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 33,  0,  0,  2,  0,  1,  2,208, 11,  3, 62,  0, 11, 12, 39,  5,  0,  0, 12,-12, 28, 72),  /* 42: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 33,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 18, 34,  4,  0,  0,  4,-12, 28, 73),  /* 43: ATTACK 10 M: EX [4]6+KK (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  0,  0,  2,  0,  1,  0, 80, 12,  3, 62,  0,  0, 18, 35,  1,  0,  0,  4,-12, 28, 73),  /* 44: ATTACK 10 M: EX [4]6+KK (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  0,  2,  2,  0,  1,  0, 72, 13,  3, 54,  0, 17, 16, 36,  5,  0,  0, 12,-12, 28, 73),  /* 45: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    ATTR( 89,  0,  0,  3,  0,  1,  1,  0,  8,  3,  9,  1, 16,  1, 36,  0,  1,  0, -1, -1,  0, 80),  /* 46: ATTACK 8 SP: not started by a command */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 72, 10,  3, 54,  0,  5,  6, 34,  2,  0,  0,  8, -8, 44, 73),  /* 47: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2) */
    ATTR( 35,  0,  0,  2,  0,  1,  0, 72, 13,  3, 54,  0,  6, 22, 36,  6,  0,  0, 16,-16, 44, 73),  /* 48: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2) */
    ATTR( 38,  0,  0,  2,  0,  1,  1,  0, 13,  3, 63,  0,  7,  6, 35,  1,  8,  0,  8, -8, 23, 73),  /* 49: atca 157 */
    ATTR( 95,  0,  0,  2,  0,  1,  1,  0, 15,  3, 63,  0,  8,  6, 35,  1,  1,  0,  8, -8, 23, 73),  /* 50: atca 157 */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0,  8, 34,  2,  4,  0,  7, -7, 18, 72),  /* 51: follow-up of S PUNCH A */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 72, 13,  3, 54,  0, 12, 24, 36,  7, 10,  0, 12,-12, 28, 73),  /* 52: ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 93,  0,  0,  2,  0,  1,  1, 72, 13,  3, 54,  0, 12, 28, 36,  8, 10,  0, 12,-12, 28, 73),  /* 53: ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) */
};

extern const u16 urien_se_random_0[];

const u16* const urien_se_random_table[1] = {
    urien_se_random_0,  /* 0 */
};

const u16 urien_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
