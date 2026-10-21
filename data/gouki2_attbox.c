/*
 * GOUKI2_ATTBOX.C  Shin Akuma's attack, catch and caught boxes
 *
 * Selected per animation frame through gouki2_hit_ix_table (atix, caix, cuix). A box is x, width,
 * y, height from the character's position, x mirrored when facing left; width 0 means no box.
 *
 * att_box  two boxes per entry: the attack boxes the hit check tests against the opponent's
 *          damage boxes; while they are out they also count as damage boxes of this character
 * cat_box  the reach of a throw: the opponent's caught box must overlap it
 * cau_box  where this character can be thrown from
 *
 * Row comments: the moves whose frames use the box (debug viewer names) and, for att_box, the
 * catt_table attacks dealt through it (rows of the fighter's _attr.c). Row 0 is no box.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const ATTACK_BOX gouki2_att_box[70] = {
    /*   x    w    y    h         x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -56,  24,  38,  30 },  {    0,   0,   0,   0 } } },  /* 1: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN), ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN); attack 1, 53, 55 */
    { { {  -31,  26, 101,  39 },  {  -46,  24,  48,  29 } } },  /* 2: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) +1; attack 2, 61, 62 */
    { { {  -28,  20,  88,  51 },  {  -29,  14,  53,  17 } } },  /* 3: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    { { {  -53,  29,  75,  15 },  {  -39,  28,  57,  21 } } },  /* 4: S PUNCH A; attack 3 */
    { { {  -76,  62,  71,  15 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B; attack 4 */
    { { {  -52,  26,  39,  26 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A, UP P GUARD P M; attack 5 */
    { { {  -86,  71,  67,  12 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B, UP P GUARD P S; attack 6 */
    { { {  -63,  47,  61,  25 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, follow-up of UP P GUARD P M; attack 8 */
    { { {  -52,  40,  83,  32 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, follow-up of UP P GUARD P M; attack 8 */
    { { {  -98,  63,  61,   7 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH B, follow-up of M PUNCH A, UP P GUARD P L; attack 8, 9 */
    { { {  -76,  54,  10,  18 },  {    0,   0,   0,   0 } } },  /* 11: S KICK A; attack 10 */
    { { {  -84,  52,  63,   7 },  {    0,   0,   0,   0 } } },  /* 12: L PUNCH B, follow-up of M PUNCH A, UP P GUARD P L */
    { { {  -73,  50,  34,  41 },  {    0,   0,   0,   0 } } },  /* 13: M KICK A; attack 12 */
    { { {  -84,  79,  44,  17 },  {    0,   0,   0,   0 } } },  /* 14: M KICK B, UP P GUARD K S; attack 13 */
    { { {  -69,  22, -18,  11 },  {    0,   0,   0,   0 } } },  /* 15: F JUMP K M B */
    { { {  -78,  18,  63,  20 },  {  -56,  38,  63,  14 } } },  /* 16: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU); attack 39, 64 */
    { { { -103, 115,  16,  70 },  {    0,   0,   0,   0 } } },  /* 17: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN); attack 77 */
    { { {  -89,  60,  43,  54 },  {    0,   0,   0,   0 } } },  /* 18: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI); attack 67, 73, 77, 79 */
    { { {  -91,  28,  81,  14 },  {  -62,  35,  60,  26 } } },  /* 19: L KICK A, follow-up of UP P GUARD P L; attack 17, 60 */
    { { {   33,  55,  53,  37 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI); attack 68, 72, 80 */
    { { {  -64,  45,  37,  12 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 19 */
    { { {  -69,  52,  43,  10 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 20 */
    { { {  -60,  36,  30,  35 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A; attack 21 */
    { { {  -23,  20,  89,  33 },  {  -38,  23,  61,  28 } } },  /* 24: KAGAMI P A; attack 22 */
    { { {  -80,  54,   0,   5 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 23 */
    { { {  -86,  76,   0,   5 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI K A; attack 24 */
    { { {  -96,  75,   0,   6 },  {  -57,  45,   2,  21 } } },  /* 27: KAGAMI K A; attack 25 */
    { { {  -47,  19,  59,  23 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P S A, F JUMP P S A, S V JP S P A; attack 26, 32 */
    { { {  -90,  60,  91,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P L A, S V JP L P A; attack 28 */
    { { {  -87,  65,  57,  18 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP K M A, S V JP M K A; attack 30 */
    { { {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 } } },  /* 31: not used by a script */
    { { {  -76,  18,  59,  11 },  {  -56,  17,  69,  11 } } },  /* 32: not used by a script */
    { { {  -38,  18,  42,  16 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP K S A, F JUMP K S A, S V JP S K A; attack 29, 35 */
    { { {  -80,  18,  38,  21 },  {  -63,  77,  52,  13 } } },  /* 34: F JUMP K M A; attack 36 */
    { { {  -56,  38,  50,  32 },  {  -44,  32,  84,  44 } } },  /* 35: not used by a script */
    { { {  -58,  19,  95,  20 },  {  -45,  27,  66,  28 } } },  /* 36: S V JP M P A; attack 33 */
    { { {  -66,  48,  80,  20 },  {  -81,  25,  93,  18 } } },  /* 37: V JUMP K L A; attack 31 */
    { { {  -52,  22,  56,  18 },  {  -40,  20,  48,  16 } } },  /* 38: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU); attack 38, 39 */
    { { {   18,  35,  66,  16 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU); attack 39, 64, 65, 66 */
    { { {  -97,  71,  67,  54 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI); attack 81 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {  -83,  45,  34,  39 },  {    0,   0,   0,   0 } } },  /* 42: M PUNCH C; attack 50 */
    { { {  -87,  49,  22,  27 },  {    0,   0,   0,   0 } } },  /* 43: M PUNCH C; attack 51 */
    { { {  -45,  40,  54,  29 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -52,  22,  56,  18 },  {  -40,  20,  48,  16 } } },  /* 45: not used by a script */
    { { {  -80,  49,  58,  12 },  {  -31,  14,  42,  28 } } },  /* 46: not used by a script */
    { { {  -83,  57,  74,  14 },  {  -34,  10,  60,  13 } } },  /* 47: not used by a script */
    { { {  -86,  16,  52,  18 },  {  -70,  47,  54,  17 } } },  /* 48: F JUMP K L A, S V JP L K A; attack 37 */
    { { {  -85,  34,  84,  24 },  {  -67,  27,  65,  31 } } },  /* 49: follow-up of UP P GUARD P L; attack 60 */
    { { {  -66,  18,  72,  16 },  {  -48,  40,  75,  10 } } },  /* 50: FUSHIN P S; attack 58 */
    { { {  -71,  42,  58,  20 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P M A; attack 27 */
    { { {  -50,  28,  24,  26 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN); attack 54 */
    { { {  -69,  63,  19,  53 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA), OKIAGARI P S; attack 41, 45, 46 */
    { { {  -42,  33,  69,  69 },  {  -55,  45,  18,  60 } } },  /* 54: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA), OKIAGARI P S; attack 42, 44, 46, 52 ... */
    { { {  -66,  52,  48,  52 },  {    0,   0,   0,   0 } } },  /* 55: not used by a script */
    { { {  -44,  40,  50,  13 },  {  -20,  20,  36,  14 } } },  /* 56: F JUMP K M B; attack 11 */
    { { {  -76,  85,  43,  18 },  {    0,   0,   0,   0 } } },  /* 57: M KICK B, UP P GUARD K S; attack 13 */
    { { {  -77,  40,  49,  23 },  {    0,   0,   0,   0 } } },  /* 58: F JUMP P L A; attack 34 */
    { { {  -90,  32,  98,  10 },  {  -56,  35,  99,  10 } } },  /* 59: not used by a script */
    { { {  -87,  70,  55,  21 },  {    0,   0,   0,   0 } } },  /* 60: V JUMP K M A, S V JP M K A; attack 30 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: no box */
    { { {  -49,  26,  29,  49 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 9 S: not started by a command; attack 69 */
    { { {  -63,  47,  48,  39 },  {    0,   0,   0,   0 } } },  /* 63: L PUNCH A; attack 7 */
    { { {  -69,  63,  19,  53 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 43 */
    { { {  -31,  26, 101,  39 },  {  -46,  24,  48,  29 } } },  /* 65: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 44 */
    { { {  -64,  39,  70,  12 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU); attack 65, 66 */
    { { {  -81,  57,  72,   8 },  {  -28,   9,  45,  35 } } },  /* 67: not used by a script */
    { { {  -78,  18,  63,  20 },  {  -56,  38,  63,  14 } } },  /* 68: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU); attack 82 */
    { { {   18,  35,  66,  16 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU); attack 83 */
};

const CATCH_BOX gouki2_cat_box[68] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {    0,    0,    0,    0 } },  /* 1: no box */
    { {    0,    0,    0,    0 } },  /* 2: no box */
    { {    0,    0,    0,    0 } },  /* 3: no box */
    { {    0,    0,    0,    0 } },  /* 4: no box */
    { {    0,    0,    0,    0 } },  /* 5: no box */
    { {    0,    0,    0,    0 } },  /* 6: no box */
    { {    0,    0,    0,    0 } },  /* 7: no box */
    { {    0,    0,    0,    0 } },  /* 8: no box */
    { {    0,    0,    0,    0 } },  /* 9: no box */
    { {    0,    0,    0,    0 } },  /* 10: no box */
    { {    0,    0,    0,    0 } },  /* 11: no box */
    { {    0,    0,    0,    0 } },  /* 12: no box */
    { {    0,    0,    0,    0 } },  /* 13: no box */
    { {    0,    0,    0,    0 } },  /* 14: no box */
    { {    0,    0,    0,    0 } },  /* 15: no box */
    { {    0,    0,    0,    0 } },  /* 16: no box */
    { {    0,    0,    0,    0 } },  /* 17: no box */
    { {    0,    0,    0,    0 } },  /* 18: no box */
    { {    0,    0,    0,    0 } },  /* 19: no box */
    { {    0,    0,    0,    0 } },  /* 20: no box */
    { {    0,    0,    0,    0 } },  /* 21: no box */
    { {    0,    0,    0,    0 } },  /* 22: no box */
    { {    0,    0,    0,    0 } },  /* 23: no box */
    { {    0,    0,    0,    0 } },  /* 24: no box */
    { {    0,    0,    0,    0 } },  /* 25: no box */
    { {    0,    0,    0,    0 } },  /* 26: no box */
    { {    0,    0,    0,    0 } },  /* 27: no box */
    { {    0,    0,    0,    0 } },  /* 28: no box */
    { {    0,    0,    0,    0 } },  /* 29: no box */
    { {    0,    0,    0,    0 } },  /* 30: no box */
    { {    0,    0,    0,    0 } },  /* 31: no box */
    { {    0,    0,    0,    0 } },  /* 32: no box */
    { {    0,    0,    0,    0 } },  /* 33: no box */
    { {    0,    0,    0,    0 } },  /* 34: no box */
    { {  -33,    8,    0,   16 } },  /* 35: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    { {    0,    0,    0,    0 } },  /* 36: no box */
    { {    0,    0,    0,    0 } },  /* 37: no box */
    { {    0,    0,    0,    0 } },  /* 38: no box */
    { {    0,    0,    0,    0 } },  /* 39: no box */
    { {    0,    0,    0,    0 } },  /* 40: no box */
    { {  -31,    6,    0,   16 } },  /* 41: M PUNCH A, M PUNCH B, M PUNCH C +4 */
    { {    0,    0,    0,    0 } },  /* 42: no box */
    { {    0,    0,    0,    0 } },  /* 43: no box */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {    0,    0,    0,    0 } },  /* 45: no box */
    { {    0,    0,    0,    0 } },  /* 46: no box */
    { {    0,    0,    0,    0 } },  /* 47: no box */
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { {    0,    0,    0,    0 } },  /* 49: no box */
    { {    0,    0,    0,    0 } },  /* 50: no box */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
    { {    0,    0,    0,    0 } },  /* 53: no box */
    { {    0,    0,    0,    0 } },  /* 54: no box */
    { {    0,    0,    0,    0 } },  /* 55: no box */
    { {    0,    0,    0,    0 } },  /* 56: no box */
    { {    0,    0,    0,    0 } },  /* 57: no box */
    { {    0,    0,    0,    0 } },  /* 58: no box */
    { {    0,    0,    0,    0 } },  /* 59: no box */
    { {    0,    0,    0,    0 } },  /* 60: no box */
    { {  -35,   10,    0,   16 } },  /* 61: L PUNCH A, L PUNCH B, L KICK A */
    { {    0,    0,    0,    0 } },  /* 62: no box */
    { {    0,    0,    0,    0 } },  /* 63: no box */
    { {    0,    0,    0,    0 } },  /* 64: no box */
    { {    0,    0,    0,    0 } },  /* 65: no box */
    { {    0,    0,    0,    0 } },  /* 66: no box */
    { {    0,    0,    0,    0 } },  /* 67: no box */
};

const CAUGHT_BOX gouki2_cau_box[21] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: KAMAE, HURIMUKI, FRONT WALK +130 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +30 */
    { {  -25,   50,   48,   40 } },  /* 3: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) +15 */
    { {  -25,   50,   48,   40 } },  /* 4: JUMP FRONT, JUMP BACK, SP JUMP FRONT +31 */
    { {  -35,   50,   30,   40 } },  /* 5: F JUMP K M B */
    { {  -21,   36,    0,   90 } },  /* 6: not used by a script */
    { {  -36,   36,    0,   90 } },  /* 7: not used by a script */
    { {  -33,   58,    0,    8 } },  /* 8: KAGAMI P A, KAGAMI K A */
    { {  -29,   54,    0,   16 } },  /* 9: S KICK A */
    { {  -28,   48,    0,   58 } },  /* 10: not used by a script */
    { {  -28,   45,   46,   61 } },  /* 11: not used by a script */
    { {  -24,   44,   54,   52 } },  /* 12: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) +5 */
    { {  -25,   50,   48,   40 } },  /* 13: TOUKETSU A, AIR S, AIR M +36 */
    { {   -8,   40,   66,   25 } },  /* 14: FUSHIN P S */
    { {  -16,   48,    0,   82 } },  /* 15: not used by a script */
    { {  -46,   80,    0,   16 } },  /* 16: follow-up of ATTACK 4 S: SA I 23623+P light (plain script), ATTACK 4 M: SA I 23623+P medium (plain script) +1, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +7 */
    { {  -41,   81,    0,   16 } },  /* 17: not used by a script */
    { {  -36,   73,   46,   49 } },  /* 18: not used by a script */
    { {  -38,   63,    0,   16 } },  /* 19: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -25,   71,    0,   16 } },  /* 20: UP P GUARD K L */
};
