/*
 * PLPAT12_TBL.C  Sean's special attack table
 *
 * pl12_exatt_table is the list of Sean's special attack routines, indexed by attack routine
 * number minus 16. Read by PLPAT12.C, which dispatches through it from pl12_extra_attack.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl12_exatt_table[])();
extern void Att_ABISEGERI();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HOMING_JUMP();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_PL12_BONUS_STAGE();
extern void Att_PL12_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl12_exatt_table[16])() = {
    Att_HADOUKEN,
    Att_SHOURYUUREPPA,
    Att_SLIDE_and_JUMP,
    Att_ABISEGERI,
    Att_CHOUCHUURENGEKI,
    Att_SHOURYUUKEN,
    Att_CHOUCHUURENGEKI,
    Att_KUUCHUUNICHIRINSHOU,
    Att_SENPUUKYAKU,
    Att_HOMING_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL12_TOKUSHUKOUDOU,
    Att_PL12_BONUS_STAGE,
};
