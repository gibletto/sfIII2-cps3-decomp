/*
 * HUGO_ATTR.C  Hugo's attack attributes and random sound lists
 *
 * hugo_catt_table has one attack attribute per row, written with ATTR (charscr.h): reaction,
 *   attribute and chip damage class, guard type, knock-back, blow-away type, damage (pow), stun
 *   (piyo), super art gain, hit stop and marks. A frame line's att picks the row (negative: a new
 *   hit). Each row names the moves using it.
 *
 * hugo_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code has bit 11 set names an entry here and plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR hugo_catt_table[67] = {
    /*   rea zu  att kez mkh dip zur fr4 dir vs  grd nd  but pow imp piy art ng  hsm hsy hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6, 34,  2,  1,  0,  7, -9, 18, 72),  /* 1: S PUNCH A */
    ATTR( 34,  0,  0,  1,  0,  1,  0,  0, 12,  3, 62,  0,  0, 24, 34,  7,  4,  0, 10,-11, 27, 73),  /* 2: M PUNCH A */
    ATTR( 36,  0,  0,  2,  0,  1,  0,  0, 11,  3, 54,  0,  0, 34, 35, 10,  7,  0, 11,-13,117, 73),  /* 3: L PUNCH A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3,  0,  0,  0,  0, 34,  0,  0,  1,  8, -8, 70,  0),  /* 4: M PUNCH A, L PUNCH A */
    ATTR( 97,  0,  0,  2, 55,  1,  0,  0,  7,  3, 63,  0,  1, 32, 34,  8, 13,  0, 12,-12,  0, 60),  /* 5: CATCH 1 */
    ATTR( 33,  0,  0,  2,  0,  1,  0,  0, 14,  3, 62,  0,  0, 32, 49, 10,  7,  0, 14,-18,117, 73),  /* 6: L PUNCH B */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0, 10, 33,  1,  1,  0,  8, -8, 34, 72),  /* 7: S KICK A */
    ATTR( 35,  0,  0,  2,  0,  1,  0,  0, 13,  3, 62,  0,  0, 14, 34,  4,  5,  0, 12,-16, 43, 73),  /* 8: M KICK A */
    ATTR( 37,  0,  0,  2, 62,  1,  0, 72, 11,  7, 62,  0,  0, 24, 33,  8, 10,  0, 11,-15,118, 73),  /* 9: ATTACK 1 S: not started by a command, ATTACK 9 S: not started by a command */
    ATTR( 37,  0,  0,  2, 62,  1,  0, 72, 11,  7, 62,  0,  0, 28, 33,  9, 10,  0, 11,-18,118, 73),  /* 10: ATTACK 1 M: not started by a command */
    ATTR( 37,  0,  0,  2, 62,  1,  0, 72, 11,  7, 62,  0,  0, 32, 33, 10, 10,  0, 11,-20,118, 73),  /* 11: ATTACK 1 L: not started by a command */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 13,  3, 54,  0, 11, 30, 49,  9,  7,  0, 14,-18,121, 73),  /* 12: L KICK A */
    ATTR( 32,  0,  0,  0, 56,  1,  0,  0, 14,  3,  9,  0,  2, 10, 32,  2,  1,  1,  9, -9, 71, 53),  /* 13: CATCH 6, CATCH 7, CATCH 8 */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 63,  0,  0,  6, 33,  1,  1,  0,  7, -9, 18, 72),  /* 14: KAGAMI P A */
    ATTR( 37,  0,  0,  1,  0,  1,  0,  0, 13,  3, 63,  0,  0, 20, 34,  2,  4,  0, 10,-11, 27, 73),  /* 15: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  1,  0,  0, 12,  3, 45,  0,  0,  8, 34,  1,  1,  0,  7, -9, 34, 73),  /* 16: KAGAMI K A */
    ATTR( 88,  0,  0,  3,  0,  1,  2,  0, 15,  3, 63,  0,  3, 22, 35,  6,  7,  0, 13,-15,117, 73),  /* 17: KAGAMI P A */
    ATTR( 32,  0,  0,  2,  0,  1,  2,  0, 12,  3, 63,  0,  0, 20, 49,  5,  7,  0, 12,-14,117, 73),  /* 18: KAGAMI P A */
    ATTR( 93,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  4, 22, 49,  6,  7,  0,  8,-10,121, 73),  /* 19: KAGAMI K A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 10,  3, 63,  0,  0, 24, 36,  3,  7,  0, 12,-16,121, 73),  /* 20: KAGAMI K A */
    ATTR(108,  0,  0,  0, 73,  1,  0, 64, 12,  3, 63,  0, 19, 48, 34,  9, 11,  0, 10,-10,127, 73),  /* 21: CATCH 9 */
    ATTR(108,  0,  0,  0, 73,  1,  0, 64, 12,  3, 63,  0, 19, 52, 34,  9, 11,  0, 10,-10,128, 73),  /* 22: CATCH 10 */
    ATTR(108,  0,  0,  0, 73,  1,  0, 64, 12,  3, 63,  0, 19, 58, 34,  9, 11,  0, 10,-10,129, 73),  /* 23: CATCH 11 */
    ATTR( 89,  0,  0,  2,  0,  1,  0,  0, 12,  3, 45,  0, 18, 20, 36,  1,  4,  0, 10,-11, 43, 73),  /* 24: KAGAMI K A */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 10,  3, 54,  0,  0,  8, 38,  4,  1,  0,  6, -6, 18, 72),  /* 25: V JUMP P S A */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 64, 10,  3,  0,  1,  0,  0, 34,  0,  4,  1,  8, -8, 66,  0),  /* 26: ATTACK 3 S: not started by a command, ATTACK 3 M: not started by a command, ATTACK 3 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 10,  3, 54,  0,  0, 18, 38,  6,  4,  0,  7, -7, 43, 73),  /* 27: V JUMP P M A */
    ATTR( 36,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 30, 39,  8,  7,  0,  8, -8,117, 73),  /* 28: V JUMP P L A, V JUMP P L B */
    ATTR( 32,  0,  0,  0,  0,  1,  1,  0, 11,  3, 54,  0,  0, 12, 38,  3,  1,  0,  6, -6, 34, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  0,  0,  1,  0,  1,  1,  0, 12,  3, 54,  0,  0, 20, 38,  5,  4,  0,  7, -7, 43, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 12,  3, 54,  0,  0, 26, 39,  7,  7,  0,  8, -8,121, 73),  /* 31: V JUMP K L A */
    ATTR( 37,  0,  0,  2,  0,  1,  0,  0, 11,  3, 54,  0,  0, 10, 34,  2,  1,  0, 12,-16, 43, 73),  /* 32: M KICK A */
    ATTR( 36,  0,  0,  2, 58,  1,  7, 80, 12,  7, 62,  0,  0,  4, 34,  1,  0,  0,  0, -2,118, 73),  /* 33: ATTACK 1 SP: not started by a command */
    ATTR( 32,  0,  0,  2, 59,  1,  7, 80, 12,  7, 62,  0,  0, 12, 34,  1,  0,  0,  0, -2,118, 73),  /* 34: ATTACK 1 SP: not started by a command */
    ATTR( 37,  0,  0,  2, 60,  1,  7, 80, 12,  7, 62,  0,  0, 12, 35,  1,  0,  0,  0, -2,117, 73),  /* 35: not used by a script */
    ATTR( 36,  0,  0,  2, 61,  1,  7, 80, 12,  7, 62,  0,  0,  4, 34,  1,  0,  0,  0, -2,118, 73),  /* 36: not used by a script */
    ATTR( 35,  0,  0,  2, 62,  1,  7, 80, 12,  7, 62,  0,  0,  4, 34,  1,  0,  0,  0, -2,118, 73),  /* 37: not used by a script */
    ATTR( 34,  0,  0,  2, 63,  1,  7, 80, 12,  7, 62,  0,  0,  4, 34,  1,  0,  0,  0, -2,118, 73),  /* 38: not used by a script */
    ATTR( 36,  0,  0,  2, 64,  1,  7, 80, 12,  7, 62,  0,  0,  4, 34,  1,  0,  0,  0, -2,118, 73),  /* 39: not used by a script */
    ATTR(106,  0,  0,  3, 64,  1,  1, 72, 11,  7, 62,  0,  7, 28, 39,  4,  0,  0, 10,-12,118, 73),  /* 40: ATTACK 1 SP: not started by a command */
    ATTR(110,  0,  0,  2,  0,  1,  3, 72,  2,  3, 62,  0,  8, 30, 39,  5, 12,  0, 16,-16,118, 73),  /* 41: not used by a script */
    ATTR(110,  0,  0,  2,  0,  1,  3, 72,  2,  3, 62,  0,  8, 32, 39,  6, 12,  0, 17,-17,118, 73),  /* 42: not used by a script */
    ATTR(110,  0,  0,  2,  0,  1,  3, 72,  2,  3, 62,  0,  8, 34, 39,  7, 12,  0, 18,-18,118, 73),  /* 43: ATTACK 2 S: not started by a command, ATTACK 2 M: not started by a command, ATTACK 2 L: not started by a command */
    ATTR(111,  1,  0,  3,  0,  1,  0, 72, 14,  3, 63,  0,  9, 14, 39,  3, 12,  1,  6, -6,  0, 73),  /* 44: CATCH 21 */
    ATTR(111,  1,  0,  3,  0,  1,  0, 72, 14,  3, 63,  0, 14, 14, 39,  3, 12,  1,  6, -6,  0, 73),  /* 45: CATCH 22 */
    ATTR(111,  1,  0,  3,  0,  1,  0, 72, 14,  3, 63,  0, 16, 14, 39,  3, 12,  1,  6, -6,  0, 73),  /* 46: CATCH 23 */
    ATTR( 91,  0,  0,  0, 70,  1,  0, 64,  8,  3, 63,  0, 12, 36, 34,  7, 11,  0, 10,-10,115,101),  /* 47: CATCH 17 */
    ATTR( 91,  0,  0,  0, 70,  1,  0, 64,  8,  3, 63,  0, 12, 40, 34,  7, 11,  0, 10,-10,116,101),  /* 48: not used by a script */
    ATTR( 91,  0,  0,  0, 70,  1,  0, 64,  8,  3, 63,  0, 12, 44, 34,  7, 11,  0, 10,-10,116,101),  /* 49: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0, 64, 12,  3, 63,  1,  0,  0, 34,  0,  4,  1,  8, -8, 84,  0),  /* 50: ATTACK 5 S: not started by a command, ATTACK 5 M: not started by a command, ATTACK 5 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0, 64, 10,  3,  0,  1,  0,  0, 34,  0,  4,  1,  8, -8, 66,  0),  /* 51: ATTACK 4 S: not started by a command, ATTACK 4 M: not started by a command, ATTACK 4 L: not started by a command */
    ATTR( 32,  0,  0,  1,  0,  1,  0,192, 10,  3,  0,  1,  0,  0, 34,  0,  0,  1,  8, -8, 66,  0),  /* 52: ATTACK 6 S: not started by a command */
    ATTR( 32,  0,  0,  2,  0,  1,  1,  0, 10,  3, 54,  0,  0, 20, 39,  8,  7,  0,  8, -8,117,  0),  /* 53: V JUMP P L B */
    ATTR( 91,  0,  0,  2, 70,  1,  0,192,  8,  3, 63,  1,  0, 38, 34,  3,  0,  0, 10,-10,115, 73),  /* 54: CATCH 25 */
    ATTR(108,  0,  0,  0, 72,  1,  0,192,  8,  3, 63,  0, 20, 58, 34,  3,  0,  0, 10,-10,129, 73),  /* 55: CATCH 25 */
    ATTR( 32,  0,  0,  0,  0,  1,  0,192, 12,  3,  0,  1,  0,  0, 34,  0,  0,  1,  8, -8, 84,  0),  /* 56: ATTACK 7 S: not started by a command, ATTACK 7 M: not started by a command, ATTACK 7 L: not started by a command */
    ATTR( 91,  0,  0,  2,  0,  1,  0,192,  8,  3,  0,  1, 13, 14, 34,  5,  0,  0, 10,-10,  0,106),  /* 57: CATCH 29 */
    ATTR(112,  0,  0,  0,  0,  1,  0,192,  8,  3,  0,  0, 21, 76, 34,  9,  0,  0, 10,-10,130,  0),  /* 58: CATCH 29 */
    ATTR( 35,  1,  0,  2,  0,  1,  0,208,  2,  3, 63,  0,  0, 16, 32,  3,  0,  0, 10,-16,118, 73),  /* 59: ATTACK 8 S: not started by a command */
    ATTR( 33,  1,  0,  2,  0,  1,  0,208, 14,  3, 63,  0,  0, 18, 32,  2,  0,  0, 12,-16,118, 73),  /* 60: ATTACK 9 S: not started by a command */
    ATTR( 36,  1,  0,  1,  0,  1,  0,208,  8,  3, 54,  0,  0, 16, 32,  2,  0,  0, 10,-14,118, 73),  /* 61: ATTACK 9 S: not started by a command */
    ATTR( 33,  1,  0,  1,  0,  1,  0,208,  2,  3, 54,  0,  0, 12,  0,  2,  0,  0,  9,-19,118, 73),  /* 62: ATTACK 9 S: not started by a command */
    ATTR(106,  1,  0,  3,  0,  1,  2,208, 11,  3, 63,  0,  6, 24, 32,  3,  0,  0, 14,-15,118, 73),  /* 63: ATTACK 9 S: not started by a command */
    ATTR( 32,  1,  0,  0,  0,  1,  0,208, 13,  7, 63,  0,  0,  1, 32,  1,  1,  0,  7, -7, 18, 73),  /* 64: ATTACK 9 M: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  1,  0,  0, 11,  3, 54,  0,  0, 14, 38,  3,  4,  0,  6, -6, 34, 72),  /* 65: ATTACK 10 S: not started by a command */
    ATTR(109,  0,  0,  1,  0,  1,  3, 72,  2,  3, 62,  0,  8, 36, 39, 12,  0,  0, 22,-22,118, 73),  /* 66: ATTACK 2 SP: not started by a command */
};

extern const u16 hugo_se_random_0[];

const u16* const hugo_se_random_table[1] = {
    hugo_se_random_0,  /* 0 */
};

const u16 hugo_se_random_0[16] = {
    0x0236, 0x0237, 0x0236, 0x0239, 0x0236, 0x0239, 0x0236, 0x0236,
    0x0239, 0x0226, 0x0239, 0x0236, 0x0239, 0x0236, 0x0239, 0x0239,
};
