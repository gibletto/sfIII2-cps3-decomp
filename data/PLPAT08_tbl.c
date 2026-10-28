/*
 * PLPAT08_TBL.C  Elena's special attack tables and Oro's rock-summon tables
 *
 * pl08_exatt_table is the list of Elena's special attack routines, indexed by attack routine
 * number minus 16. pl08_hcs_tbl marks, for each of the three punch and three kick button bits,
 * whether pressing it cuts the healing super art's pose short. Read by PLPAT08.C. For Oro's
 * rock-summon move, tenguiwa_stage_data picks by stage and round a row of tenguiwa_stand_by
 * (eight rock shell types chosen from at random), tenguiwa_type_flag marks the shell types
 * that are rocks, and tenguiwa_pos_hosei gives each rock's start position, scroll speed and
 * direction; read by PLPAT09.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 pl08_hcs_tbl[];
extern void (*const pl08_exatt_table[])();
extern const u8 tenguiwa_stage_data[][4];
extern const u8 tenguiwa_stand_by[][8];
extern const s16 tenguiwa_pos_hosei[][6];
extern const u8 tenguiwa_type_flag[];
extern void Att_DUMMY();
extern void Att_PL08_HEALING();
extern void Att_PL08_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

const u8 pl08_hcs_tbl[8] = {
    0, 0, 0, 1, 0, 1, 1, 1,
};

void (*const pl08_exatt_table[15])() = {
    Att_SHOURYUUKEN,
    Att_SENPUUKYAKU,
    Att_SENPUUKYAKU,
    Att_SHOURYUUREPPA,
    Att_SHOURYUUREPPA,
    Att_PL08_HEALING,
    Att_DUMMY,
    Att_SLIDE_and_JUMP,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_DUMMY,
    Att_PL08_TOKUSHUKOUDOU,
};

const u8 tenguiwa_stage_data[17][4] = {
    { 0, 1, 0, 0 }, { 4, 5, 4, 5 },
    { 0, 1, 0, 1 }, { 0, 1, 0, 1 },
    { 4, 5, 4, 5 }, { 0, 1, 0, 1 },
    { 0, 1, 0, 1 }, { 0, 1, 0, 1 },
    { 2, 3, 2, 3 }, { 2, 3, 2, 3 },
    { 0, 1, 0, 1 }, { 4, 4, 5, 5 },
    { 4, 5, 4, 5 }, { 0, 1, 3, 0 },
    { 3, 1, 2, 0 }, { 2, 1, 3, 0 },
    { 6, 6, 6, 6 },
};

const u8 tenguiwa_stand_by[7][8] = {
    { 24, 25, 26, 27, 28, 29, 30, 31 },
    { 32, 33, 34, 35, 24, 25, 26, 27 },
    { 24, 25, 26, 27, 28, 29, 30, 31 },
    { 29, 31, 34, 35, 24, 25, 26, 27 },
    { 24, 31, 26, 32, 33, 29, 30, 31 },
    { 32, 33, 29, 30, 24, 31, 26, 27 },
    { 30, 31, 29, 31, 27, 31, 28, 30 },
};

const s16 tenguiwa_pos_hosei[4][6] = {
    { 8, 112, 2, 16, 56, 48 },
    { 48, 104, -2, 48, 48, 96 },
    { -48, 100, 2, -32, 48, 144 },
    { -8, 96, -2, 0, 24, 192 },
};

const u8 tenguiwa_type_flag[32] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
