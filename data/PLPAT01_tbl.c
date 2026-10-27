/*
 * PLPAT01_TBL.C  Alex, Ryu and Yun special attack tables
 *
 * pl01_exatt_table, pl02_exatt_table and pl03_exatt_table are the special attack routines of
 * characters 1 (Alex), 2 (Ryu) and 3 (Yun), indexed by attack routine number minus 16; read by
 * PLPAT01.C, PLPAT02.C and PLPAT03.C. lgix_table gives the extra animation frames skipped by
 * charge count in Ryu's charged fireball super (PLPAT02.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const pl01_exatt_table[])();
extern const s16 lgix_table[];
extern void (*const pl02_exatt_table[])();
extern void (*const pl03_exatt_table[])();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DENJINHADOUKEN();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_HOMING_JUMP();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_NM_OKIAGARI();
extern void Att_PL01_TOKUSHUKOUDOU();
extern void Att_PL02_TOKUSHUKOUDOU();
extern void Att_PL03_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SENPUUKYAKU2();
extern void Att_SHINSHOURYUUKEN();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();
extern void Att_TENSHINSENKYUUTAI();

void (*const pl01_exatt_table[15])() = {
    Att_CHOUCHUURENGEKI,
    Att_SHOURYUUKEN,
    Att_HADOUKEN,
    Att_HADOUKEN2,
    Att_CHOUCHUURENGEKI,
    Att_SENPUUKYAKU2,
    Att_SENPUUKYAKU,
    Att_NM_OKIAGARI,
    Att_DUMMY,
    Att_HOMING_JUMP,
    Att_SLIDE_and_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL01_TOKUSHUKOUDOU,
};

const s16 lgix_table[8] = {
    0, 1, 2, 3, 3, 4, 4, 5,
};

void (*const pl02_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_SHOURYUUKEN,
    Att_SENPUUKYAKU,
    Att_HADOUKEN,
    Att_SHINSHOURYUUKEN,
    Att_DENJINHADOUKEN,
    Att_KUUCHUUNICHIRINSHOU,
    Att_SLIDE_and_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL02_TOKUSHUKOUDOU,
};

void (*const pl03_exatt_table[15])() = {
    Att_HADOUKEN,
    Att_TENSHINSENKYUUTAI,
    Att_SENPUUKYAKU,
    Att_HADOUKEN,
    Att_SLIDE_and_JUMP,
    Att_SLIDE_and_JUMP,
    Att_HADOUKEN,
    Att_DUMMY,
    Att_SLIDE_and_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL03_TOKUSHUKOUDOU,
};
