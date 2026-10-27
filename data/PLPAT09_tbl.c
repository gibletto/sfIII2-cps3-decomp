/*
 * PLPAT09_TBL.C  Oro, Yang and Ken special attack tables
 *
 * pl09_exatt_table is the list of Oro's special attack routines, indexed by attack routine
 * number minus 16. homing_hos (per opponent character) and homing_kop hold the target-relative
 * jump data stepped by mvxy_table_reader; pl09_tk_table is the stun timer cut rate per
 * personal-action repeat count. Read by PLPAT09.C. pl10_exatt_table and pl11_exatt_table are
 * the special attack routines of characters 10 (Yang) and 11 (Ken), read by PLPAT10.C and
 * PLPAT11.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 pl09_tk_table[];
extern const s16 homing_hos[][16][2];
extern const s16 homing_kop[][4];
extern void (*const pl09_exatt_table[])();
extern void (*const pl10_exatt_table[])();
extern void (*const pl11_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_JINNCHUUWATARI();
extern void Att_JINNCHUUWATARI_EX();
extern void Att_KUUCHUUJINNCHUUWATARI();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_PL09_TOKUSHUKOUDOU();
extern void Att_PL10_TOKUSHUKOUDOU();
extern void Att_PL11_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();
extern void Att_TENSHINSENKYUUTAI();

const s16 pl09_tk_table[14] = {
    0, 500, 600, 700, 800, 900, 1000, 1100,
    1200, 1300, 1400, 1500, 1600, 1700,
};

const s16 homing_hos[2][16][2] = {
    { { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 } },
    { { 24, 86 }, { 28, 68 }, { 16, 62 }, { 16, 52 }, { 20, 72 }, { 20, 58 }, { 18, 82 }, { 18, 52 }, { 28, 45 }, { 25, 42 }, { 16, 52 }, { 16, 62 }, { 16, 62 }, { 24, 86 }, { 16, 62 }, { 16, 62 } },
};

const s16 homing_kop[2][4] = {
    { 1, 14, 0, 2 },
    { 0, 14, 0, 2 },
};

void (*const pl09_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_SHOURYUUKEN,
    Att_KUUCHUUNICHIRINSHOU,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_HADOUKEN,
    Att_KUUCHUUJINNCHUUWATARI,
    Att_JINNCHUUWATARI,
    Att_JINNCHUUWATARI_EX,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL09_TOKUSHUKOUDOU,
};

void (*const pl10_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_TENSHINSENKYUUTAI,
    Att_SLIDE_and_JUMP,
    Att_HADOUKEN,
    Att_SLIDE_and_JUMP,
    Att_TENSHINSENKYUUTAI,
    Att_HADOUKEN,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL10_TOKUSHUKOUDOU,
};

void (*const pl11_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_SHOURYUUKEN,
    Att_SENPUUKYAKU,
    Att_SHOURYUUREPPA,
    Att_SHOURYUUREPPA,
    Att_SLIDE_and_JUMP,
    Att_KUUCHUUNICHIRINSHOU,
    Att_CHOUCHUURENGEKI,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL11_TOKUSHUKOUDOU,
};
