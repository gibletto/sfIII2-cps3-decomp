/*
 * PLMAIN_TBL.C  player move routine tables
 *
 * plmain_lv_00 is the five routine_no[0] steps (player_mv_0000 .. 4000) of the player move,
 * read by PLMAIN.C, and plmain_b_lv_00 the same steps for the bonus stage (player_mvbs_*),
 * read by PLMAIN2.C; plmain_lv_02 the routine_no[1] states (normal, damage, catch, caught,
 * attack), used by both; sag_jmp_tbl the super art gauge process by gauge type (PLMAIN.C).
 * lvdir_conv turns the lever direction round when a jumping player changes facing, and
 * defense_cg_ix_table gives each character's guard animation by defence kind; read by PLS00.C.
 * sag_jmp_tbl_tail and sag_jmp_tbl_tail_2 follow sag_jmp_tbl and are not referred to by name.
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
extern const s16 defense_cg_ix_table[][3];
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
    player_mv_0000,
    player_mv_1000,
    player_mv_2000,
    player_mv_3000,
    player_mv_4000,
};

void (*const plmain_lv_02[5])() = {
    Player_normal,
    Player_damage,
    Player_catch,
    Player_caught,
    Player_attack,
};

void (*const sag_jmp_tbl[4])() = {
    sag_normal,
    sag_timer,
    sag_normal,
    sag_rebirth,
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
    player_mvbs_0000,
    player_mvbs_1000,
    player_mvbs_2000,
    player_mvbs_3000,
    player_mvbs_4000,
};

const s8 lvdir_conv[4] = {
    0, 2, 1, 0,
};

const s16 defense_cg_ix_table[16][3] = {
    { 1, 1, 1 },  /* Gill */
    { 1, 1, 1 },  /* Alex */
    { 1, 1, 1 },  /* Ryu */
    { 2, 2, 2 },  /* Yun */
    { 3, 3, 3 },  /* Dudley */
    { 1, 1, 1 },  /* Necro */
    { 0, 0, 0 },  /* Hugo */
    { 2, 2, 2 },  /* Ibuki */
    { 1, 1, 1 },  /* Elena */
    { 1, 1, 1 },  /* Oro */
    { 2, 2, 2 },  /* Yang */
    { 1, 1, 1 },  /* Ken */
    { 1, 1, 1 },  /* Sean */
    { 1, 1, 1 },  /* Urien */
    { 1, 1, 1 },  /* Gouki */
    { 1, 1, 1 },  /* Shin Gouki */
};
