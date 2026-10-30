/*
 * PLCNT_TBL.C  player control phases and per-character base data
 *
 * player_main_process (init, move, die), appear_initalize (start-of-round set-ups) and
 * settle_process (the KO, double KO and time-over finishes) are the routine tables of player
 * control, with quake_table, the shake offsets by quake value; read by PLCNTSET_2.C. By
 * character: plid_data (character set), weight_lv_table, spmv_ng_table, kage_base (shadow
 * offset and pattern) and super_arts_data (16 bytes per super art); read by PLCNTDAT.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const player_main_process[])();
extern void (*const appear_initalize[])();
extern void (*const settle_process[])();
extern const s8 plid_data[];
extern const s8 weight_lv_table[];
extern const s16 quake_table[];
extern const u32 spmv_ng_table[];
extern const s16 kage_base[][2];
extern const SA_DATA super_arts_data[][4];
extern void init_app_10000();
extern void init_app_20000();
extern void init_app_30000();
extern void plcnt_die();
extern void plcnt_init();
extern void plcnt_move();
extern void settle_type_00000();
extern void settle_type_10000();
extern void settle_type_20000();
extern void settle_type_30000();
extern void settle_type_40000();
extern void settle_type_50000();
extern void settle_type_60000();

void (*const player_main_process[3])() = {
    plcnt_init,
    plcnt_move,
    plcnt_die,
};

void (*const appear_initalize[4])() = {
    init_app_10000,
    init_app_10000,
    init_app_20000,
    init_app_30000,
};

void (*const settle_process[7])() = {
    settle_type_00000,
    settle_type_10000,
    settle_type_20000,
    settle_type_30000,
    settle_type_40000,
    settle_type_50000,
    settle_type_60000,
};

const s8 plid_data[16] = {
    6, 3, 5, 1, 2, 9, 7, 4, 10, 8, 12, 13, 14, 15, 16, 17,
};

const s8 weight_lv_table[16] = {
    2, 2, 1, 0, 1, 2, 3, 0, 1, 0, 0, 1, 1, 2, 1, 1,
};

const s16 quake_table[42] = {
    1, -1, 1, -1, 1, -1, 1, -2,
    1, -2, 1, -2, 1, -2, 1, -2,
    1, -2, 2, -2, 2, -2, 2, -2,
    2, -2, 2, -2, 2, -2, 2, -2,
    2, -2, 2, -2, 2, -2, 2, -2,
    2, -2,
};

const u32 spmv_ng_table[16] = {
    0x10023, 0x10023, 0x10023, 0x10023,
    0x10023, 0x10023, 0x10023, 0x10023,
    0x10023, 0x10023, 0x10023, 0x10023,
    0x10023, 0x10023, 0x10023, 0x10023,
};

const s16 kage_base[16][2] = {
    { 0, 21 },  /* Gill */
    { 0, 30 },  /* Alex */
    { 0, 21 },  /* Ryu */
    { -4, 16 },  /* Yun */
    { 4, 21 },  /* Dudley */
    { 6, 20 },  /* Necro */
    { -4, 26 },  /* Hugo */
    { -4, 20 },  /* Ibuki */
    { 0, 25 },  /* Elena */
    { -3, 22 },  /* Oro */
    { -4, 15 },  /* Yang */
    { 0, 21 },  /* Ken */
    { 0, 21 },  /* Sean */
    { 0, 21 },  /* Urien */
    { 0, 21 },  /* Gouki */
    { 0, 21 },  /* Shin Gouki */
};

const SA_DATA super_arts_data[16][4] = {
    {  /* Gill */
        { 20, 24, 0, 0, 0, SA_GAUGE_REBIRTH, 128, 1, 0, 0x10000 },
        { 21, 24, 0, 0, 0, SA_GAUGE_REBIRTH, 128, 1, 0, 0x10000 },
        { 22, 24, 0, 0, 0, SA_GAUGE_REBIRTH, 128, 1, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_REBIRTH, 64, 1, 0, 0x10000 },
    },
    {  /* Alex */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 128, 1, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 80, 1, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 0, 0, 0, 0x10000 },
    },
    {  /* Ryu */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 104, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 120, 1, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 80, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 0, 0, 0, 0x10000 },
    },
    {  /* Yun */
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 1, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 3, 0, 0x10000 },
        { 20, 0, 0, 0, 0, SA_GAUGE_TIMER, 72, 1, 0, 0x4000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Dudley */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 2, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 1, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 80, 3, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Necro */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 1, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 104, 1, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Hugo */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 128, 1, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_REBIRTH, 64, 1, 0, 0x10000 },
    },
    {  /* Ibuki */
        { 0, 0, 38, 0, 0, SA_GAUGE_STOCK, 72, 3, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 1, 0, 0x10000 },
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 80, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Elena */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 72, 3, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 104, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 1, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Oro */
        { 22, 0, 0, 0, 0, SA_GAUGE_TIMER, 96, 1, 0, 0x4000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 3, 0, 0x10000 },
        { 20, 0, 0, 0, 0, SA_GAUGE_TIMER, 112, 1, 0, 0x3333 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 0, 0, 0x10000 },
    },
    {  /* Yang */
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 120, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 104, 2, 0, 0x10000 },
        { 20, 0, 0, 0, 0, SA_GAUGE_TIMER, 104, 1, 0, 0x5555 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Ken */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 104, 1, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 80, 3, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Sean */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 72, 3, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_STOCK, 64, 1, 0, 0x10000 },
    },
    {  /* Urien */
        { 20, 0, 0, 0, 0, SA_GAUGE_STOCK, 104, 2, 0, 0x10000 },
        { 21, 0, 0, 0, 0, SA_GAUGE_STOCK, 88, 2, 0, 0x10000 },
        { 22, 0, 0, 0, 0, SA_GAUGE_STOCK, 80, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_REBIRTH, 64, 1, 0, 0x10000 },
    },
    {  /* Gouki */
        { 20, 24, 38, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 21, 24, 0, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 22, 24, 39, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_REBIRTH, 64, 1, 0, 0x10000 },
    },
    {  /* Shin Gouki */
        { 20, 24, 38, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 21, 24, 0, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 22, 24, 39, 0, 0, SA_GAUGE_STOCK, 112, 2, 0, 0x10000 },
        { 0, 0, 0, 0, 0, SA_GAUGE_REBIRTH, 64, 1, 0, 0x10000 },
    },
};
