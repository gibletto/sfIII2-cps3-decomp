/*
 * PLPAT09_TBL.C  tables read by PLPAT09.c, PLPAT11.c and plpat10.c
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
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_KUUCHUUNICHIRINSHOU,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_KUUCHUUJINNCHUUWATARI,
    (void (*)())Att_JINNCHUUWATARI,
    (void (*)())Att_JINNCHUUWATARI_EX,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL09_TOKUSHUKOUDOU,
};

void (*const pl10_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_TENSHINSENKYUUTAI,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_TENSHINSENKYUUTAI,
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL10_TOKUSHUKOUDOU,
};

void (*const pl11_exatt_table[15])() = {
    (void (*)())Att_HADOUKEN,
    (void (*)())Att_SHOURYUUKEN,
    (void (*)())Att_SENPUUKYAKU,
    (void (*)())Att_SHOURYUUREPPA,
    (void (*)())Att_SHOURYUUREPPA,
    (void (*)())Att_SLIDE_and_JUMP,
    (void (*)())Att_KUUCHUUNICHIRINSHOU,
    (void (*)())Att_CHOUCHUURENGEKI,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_DUMMY,
    (void (*)())Att_PL11_TOKUSHUKOUDOU,
};
