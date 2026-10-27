/*
 * PLCNT_TBL_C.C  stun recovery, stun times and bonus-stage scroll limits
 *
 * pl_nr_piyo_tbl gives each character's stun recovery rate, read by PLCNTDAT.C. The
 * tsuujyou_*, hissatsu_* and super_arts_nage_* tables are the stun times, 16 random draws
 * each, after normal strikes, special moves, throws and super art throws by attack strength
 * (the later rows of tsuujyou_nage_02 serve two further attack kinds), reached through the
 * kizetsu_timer_table lists of PLPDM.C, the player damage process. bsmr_range_table gives the
 * players' scroll limits in the bonus stage by screen mode and by which players are human;
 * read by PLCNT2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 pl_nr_piyo_tbl[];
extern const s16 tsuujyou_dageki_00[];
extern const s16 tsuujyou_dageki_01[];
extern const s16 tsuujyou_dageki_02[];
extern const s16 hissatsu_dageki_00[];
extern const s16 hissatsu_dageki_01[];
extern const s16 hissatsu_dageki_02[];
extern const s16 tsuujyou_nage_00[];
extern const s16 tsuujyou_nage_01[];
extern const s16 tsuujyou_nage_02[];
extern const s16 super_arts_nage_00[];
extern const s16 super_arts_nage_01[];
extern const s16 super_arts_nage_02[];
extern const s16 bsmr_range_table[][2][2][2];

const s32 pl_nr_piyo_tbl[16] = {
    2978, 2978, 2978, 2978,
    2978, 2978, 2978, 2978,
    2978, 2978, 2978, 2978,
    2978, 2978, 2978, 2978,
};

const s16 tsuujyou_dageki_00[16] = {
    150, 150, 130, 130, 130, 110, 110, 110,
    110, 110, 90, 90, 90, 90, 90, 90,
};

const s16 tsuujyou_dageki_01[16] = {
    150, 150, 150, 150, 130, 130, 130, 130,
    110, 110, 110, 110, 90, 90, 90, 90,
};

const s16 tsuujyou_dageki_02[16] = {
    150, 150, 150, 150, 150, 150, 130, 130,
    130, 130, 130, 110, 110, 110, 90, 90,
};

const s16 hissatsu_dageki_00[16] = {
    210, 210, 190, 190, 190, 170, 170, 170,
    170, 170, 150, 150, 150, 150, 150, 150,
};

const s16 hissatsu_dageki_01[16] = {
    210, 210, 210, 210, 190, 190, 190, 190,
    170, 170, 170, 170, 150, 150, 150, 150,
};

const s16 hissatsu_dageki_02[16] = {
    210, 210, 210, 210, 210, 210, 190, 190,
    190, 190, 190, 170, 170, 170, 150, 150,
};

const s16 tsuujyou_nage_00[16] = {
    180, 180, 160, 160, 160, 140, 140, 140,
    140, 140, 120, 120, 120, 120, 120, 120,
};

const s16 tsuujyou_nage_01[16] = {
    180, 180, 180, 180, 160, 160, 160, 160,
    140, 140, 140, 140, 120, 120, 120, 120,
};

const s16 tsuujyou_nage_02[112] = {
    180, 180, 180, 180, 180, 180, 160, 160,
    160, 160, 160, 140, 140, 140, 120, 120,
    240, 240, 200, 200, 200, 160, 160, 160,
    160, 160, 120, 120, 120, 120, 120, 120,
    240, 240, 240, 240, 200, 200, 200, 200,
    160, 160, 160, 160, 120, 120, 120, 120,
    240, 240, 240, 240, 240, 240, 200, 200,
    200, 200, 200, 160, 160, 160, 120, 120,
    240, 240, 200, 200, 200, 160, 160, 160,
    160, 160, 120, 120, 120, 120, 120, 120,
    240, 240, 240, 240, 200, 200, 200, 200,
    160, 160, 160, 160, 120, 120, 120, 120,
    240, 240, 240, 240, 240, 240, 200, 200,
    200, 200, 200, 160, 160, 160, 120, 120,
};

const s16 super_arts_nage_00[16] = {
    270, 270, 230, 230, 230, 190, 190, 190,
    190, 190, 150, 150, 150, 150, 150, 150,
};

const s16 super_arts_nage_01[16] = {
    270, 270, 270, 270, 230, 230, 230, 230,
    190, 190, 190, 190, 150, 150, 150, 150,
};

const s16 super_arts_nage_02[16] = {
    270, 270, 270, 270, 270, 270, 230, 230,
    230, 230, 230, 190, 190, 190, 150, 150,
};

const s16 bsmr_range_table[4][2][2][2] = {
    { { { 192, 192 }, { 192, 192 } }, { { 248, 248 }, { 248, 248 } } },
    { { { 32, 192 }, { 192, -88 } }, { { 48, 248 }, { 248, -128 } } },
    { { { -88, 192 }, { 192, 32 } }, { { -128, 248 }, { 248, 48 } } },
    { { { 192, 192 }, { 192, 192 } }, { { 248, 248 }, { 248, 248 } } },
};
