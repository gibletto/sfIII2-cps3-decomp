/*
 * PLPAT14_TBL.C  Gouki and Shin Gouki special attack tables
 *
 * pl14_exatt_table lists the routines of attack numbers 16 and up of character 14 (Gouki),
 * read by PLPAT14.C; pl15_exatt_table is the same list for character 15 (Shin Gouki), read by
 * PLPAT15.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl14_exatt_table[])();
extern void (*const pl15_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_KUUCHUUJINNCHUUWATARI();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_PL14_AT1();
extern void Att_PL14_AT2();
extern void Att_PL14_TOKUSHUKOUDOU();
extern void Att_PL15_AT1();
extern void Att_PL15_AT2();
extern void Att_PL15_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl14_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_SHOURYUUKEN,
    Att_SENPUUKYAKU,
    Att_KUUCHUUJINNCHUUWATARI,
    Att_SHOURYUUREPPA,
    Att_SLIDE_and_JUMP,
    Att_KUUCHUUNICHIRINSHOU,
    Att_PL14_AT1,
    Att_CHOUCHUURENGEKI,
    Att_PL14_AT2,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL14_TOKUSHUKOUDOU,
};

/* provisional name */
void (*const pl15_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_SHOURYUUKEN,
    Att_SENPUUKYAKU,
    Att_KUUCHUUJINNCHUUWATARI,
    Att_SHOURYUUREPPA,
    Att_SLIDE_and_JUMP,
    Att_KUUCHUUNICHIRINSHOU,
    Att_PL15_AT1,
    Att_CHOUCHUURENGEKI,
    Att_PL15_AT2,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL15_TOKUSHUKOUDOU,
};
