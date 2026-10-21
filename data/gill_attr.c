/*
 * GILL_ATTR.C  Gill's attack attributes and random sound lists
 *
 * gill_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * gill_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR gill_catt_table[35] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 63,  0,  0,  6, 32,  2,  1,  0,  6, -6, 13, 72),  /* 1: S PUNCH A, UP P GUARD P S */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 15,  3, 62,  0,  0, 24, 33,  6,  4,  0,  7, -7, 18, 72),  /* 2: M PUNCH C */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 22, 34,  6,  4,  0,  7, -7, 18, 72),  /* 3: M PUNCH A, UP P GUARD P M */
    ATTR( 32,  0,  1,  1,  0,  1,  0,  0, 12,  3, 63,  0,  0, 16, 35,  8,  7,  0,  8, -8, 23, 73),  /* 4: not used by a script */
    ATTR( 36,  0,  1,  2,  0,  1,  0, 16, 10,  3, 63,  0,  9, 32, 35,  8,  7,  0,  8, -8, 23, 73),  /* 5: L PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 63,  0,  0,  8, 32,  3,  1,  0,  6, -6, 29, 72),  /* 6: S KICK A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0, 16, 32,  4,  1,  0,  6, -6, 29,  0),  /* 7: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 13,  3, 62,  0,  0, 20, 34,  6,  4,  0,  7, -7, 34, 72),  /* 8: M KICK A, M KICK C, follow-up of APPEAR 7 */
    ATTR( 32,  0,  1,  2,  0,  1,  0, 16, 11,  3, 54,  0,  9, 14, 35,  2,  8,  0,  8, -8, 39, 73),  /* 9: L KICK A, UP P GUARD P L */
    ATTR( 36,  0,  1,  2,  0,  1,  0, 16,  9,  3, 54,  0,  9, 22, 35,  8,  1,  0,  8, -8, 39, 73),  /* 10: L KICK A, UP P GUARD P L */
    ATTR( 32,  0,  0,  2,  0,  1,  0,  0, 11,  3, 63,  0,  0, 36, 36,  8,  7,  0,  8, -8, 39,  0),  /* 11: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 13,  3, 63,  0,  0,  4, 32,  2,  1,  0,  6, -6, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 14,  3, 63,  0,  0, 16, 34,  6,  4,  0,  7, -7, 18, 72),  /* 13: KAGAMI P A, atca 156 */
    ATTR( 95,  0,  3,  3,  0,  1,  0, 16, 15,  3, 63,  0,  8, 14, 35,  4,  1,  0,  8, -8, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 45,  0,  0,  4, 32,  1,  1,  0,  6, -6, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 12,  3, 45,  0,  0, 18, 34,  3,  4,  0,  7, -7, 34, 72),  /* 16: KAGAMI K A */
    ATTR( 89,  0,  1,  0,  0,  1,  0, 16, 13,  3, 45,  0,  1, 26, 36,  4,  7,  0,  8, -8, 39, 73),  /* 17: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0,  9,  3, 54,  0,  0, 12, 37,  4,  1,  0,  5, -5, 13, 72),  /* 18: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 11,  3, 54,  0,  0, 20, 38,  6,  4,  0,  6, -6, 18, 72),  /* 19: V JUMP P M A, V JUMP K S A */
    ATTR( 32,  0,  3,  2,  0,  1,  1, 16, 10,  3, 54,  0,  0, 28, 39,  8,  7,  0,  7, -7, 23, 73),  /* 20: V JUMP P L A, ATTACK 4 M: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0, 11,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8,  0, 73),  /* 21: M PUNCH A, M PUNCH C, L PUNCH A +4 */
    ATTR( 32,  0,  0,  1, 54,  1,  0,  0, 10,  3, 63,  0,  2, 40, 38,  9, 13,  0, 10,-10, 55, 73),  /* 22: CATCH 1 */
    ATTR( 32,  0,  0,  2, 38,  1,  0,  0,  6,  3, 63,  0,  4, 10, 36,  2,  1,  0, 12,-12, 71, 72),  /* 23: CATCH 2 */
    ATTR( 36,  0,  0,  2,  0,  1,  0, 72, 10,  3, 54,  0,  5, 12, 36,  4,  4,  0,  8, -8, 44, 73),  /* 24: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    ATTR( 35,  0,  0,  2,  0,  1,  0, 72, 13,  3, 54,  0,  6, 28, 36,  6,  1,  0, 16,-16, 44, 73),  /* 25: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    ATTR( 32,  0,  0,  2,  0,  1,  1, 72, 13,  3, 54,  0, 12, 26, 36,  9,  4,  0, 12,-12, 96, 73),  /* 26: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 16, 12,  3, 63,  0,  6,  6, 36,  2,  1,  0, 12,-12, 28, 73),  /* 27: not used by a script */
    ATTR( 38,  0,  3,  2,  0,  1,  0, 16, 13,  3, 63,  0,  7, 20, 35,  4,  8,  0,  8, -8, 23, 73),  /* 28: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 12,  3, 54,  0,  0, 12, 37,  4,  1,  0,  5, -5, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 13,  3, 54,  0,  0, 20, 38,  6,  4,  0,  6, -6, 34, 72),  /* 30: V JUMP K M A, FUSHIN P S */
    ATTR( 32,  0,  3,  2,  0,  1,  1, 16, 11,  3, 54,  0,  0, 28, 39,  8,  7,  0,  7, -7, 39, 73),  /* 31: V JUMP K L A */
    ATTR(110,  1,  0,  1, 53,  1,  0,  8,  2,  3, 62,  0, 10, 40, 39,  2,  7,  0, 16,-16, 28, 60),  /* 32: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  0,  1,  2,  0,  1,  0,  8, 11,  3, 62,  0, 11, 16, 39,  8,  1,  0, 12,-12, 28, 72),  /* 33: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  1,  0,  1,  0,  0,  9,  3, 54,  0,  0, 16, 37,  4,  4,  0,  6, -6, 13, 72),  /* 34: ATTACK 7 M: not started by a command */
};

extern const u16 gill_se_random_0[];

const u16* const gill_se_random_table[1] = {
    gill_se_random_0,  /* 0 */
};

const u16 gill_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
