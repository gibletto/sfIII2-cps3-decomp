/*
 * PLMAIN_TBL.C  tables read by PLMAIN.c, PLMAIN2.c and PLS00.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const plmain_lv_00[])();
extern void (*const plmain_lv_02[])();
extern void (*const sag_jmp_tbl[])();
extern const s16 sag_jmp_tbl_tail[];
extern const s16 sag_jmp_tbl_tail_2[][4];
extern void (*const plmain_b_lv_00[])();
extern const s8 lvdir_conv[];
extern const u16 defense_cg_ix_table[];
extern void Player_attack();
extern void Player_catch();
extern void Player_caught();
extern void Player_damage();
extern void Player_normal();
extern void player_mv_0000();
extern void player_mv_1000();
extern void player_mv_2000();
extern void player_mv_3000();
extern void player_mv_4000();
extern void player_mvbs_0000();
extern void player_mvbs_1000();
extern void player_mvbs_2000();
extern void player_mvbs_3000();
extern void player_mvbs_4000();
extern void sag_normal();
extern void sag_rebirth();
extern void sag_timer();

void (*const plmain_lv_00[5])() = {
    (void (*)())player_mv_0000,
    (void (*)())player_mv_1000,
    (void (*)())player_mv_2000,
    (void (*)())player_mv_3000,
    (void (*)())player_mv_4000,
};

void (*const plmain_lv_02[5])() = {
    (void (*)())Player_normal,
    (void (*)())Player_damage,
    (void (*)())Player_catch,
    (void (*)())Player_caught,
    (void (*)())Player_attack,
};

void (*const sag_jmp_tbl[4])() = {
    (void (*)())sag_normal,
    (void (*)())sag_timer,
    (void (*)())sag_normal,
    (void (*)())sag_rebirth,
};

/* provisional name */
/* Stored after sag_jmp_tbl: 16 words of 15 and two 32-entry ramps (24..40, 28..36), then 16 bytes. Nothing in the
   program refers to it by name or address. */
const s16 sag_jmp_tbl_tail[96] = {
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    24, 25, 25, 26, 26, 27, 27, 28,
    28, 29, 29, 30, 30, 31, 31, 32,
    32, 33, 33, 34, 34, 35, 35, 36,
    36, 37, 37, 38, 38, 39, 39, 40,
    28, 28, 29, 29, 29, 29, 30, 30,
    30, 30, 31, 31, 31, 31, 32, 32,
    32, 32, 33, 33, 33, 33, 34, 34,
    34, 34, 35, 35, 35, 35, 36, 36,
    0, 256, 512, 768, 1024, 1280, 1536, 1792,
    2048, 2304, 256, 513, 512, 0, 0, 0,
};

/* provisional name */
/* 128 records of (-96, 0, 256, 0) after sag_jmp_tbl_tail. Nothing in the program refers to it by name or address. */
const s16 sag_jmp_tbl_tail_2[128][4] = {
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
    { -96, 0, 256, 0 },
};

void (*const plmain_b_lv_00[5])() = {
    (void (*)())player_mvbs_0000,
    (void (*)())player_mvbs_1000,
    (void (*)())player_mvbs_2000,
    (void (*)())player_mvbs_3000,
    (void (*)())player_mvbs_4000,
};

const s8 lvdir_conv[4] = {
    0, 2, 1, 0,
};

const u16 defense_cg_ix_table[48] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 3, 3, 3, 1,
    1, 1, 0, 0, 0, 2, 2, 2,
    1, 1, 1, 1, 1, 1, 2, 2,
    2, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
};
