/*
 * NEXT_CPU_TBL.C  Japanese game configuration page scripts
 *
 * The gcfg_*_scr_jp_* tables are the text-layer scripts of the Japanese GAME CONFIGURATION
 * page of test mode: the guide and exit guide lines, the value labels of the screen mode,
 * round, event and bonus items, the cursor and its eraser, and the eight steps of the star
 * gauges with their eraser. They are reached through the TMSCRIPT tables of GAME_CONFIG_JP.C.
 * gcfg_title_old_scr_jp_0, a shorter title script, is only pointed at by
 * gcfg_title_old_scr_jp, which nothing reads.
 *
 * A script is a list of blocks, each the glyph count, column, row and attribute followed by the
 * glyphs (tilemap_print_script_seq); a count of 0 ends it.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 gcfg_guide_scr_jp_0[];
extern const u16 gcfg_exit_guide_scr_jp_0[];
extern const u16 gcfg_screen_scr_jp_1[];
extern const u16 gcfg_screen_scr_jp_0[];
extern const u16 gcfg_round_scr_jp_0[];
extern const u16 gcfg_round_scr_jp_1[];
extern const u16 gcfg_round_scr_jp_2[];
extern const u16 gcfg_round_scr_jp_3[];
extern const u16 gcfg_event_scr_jp_0[];
extern const u16 gcfg_event_scr_jp_1[];
extern const u16 gcfg_bonus_scr_jp_0[];
extern const u16 gcfg_bonus_scr_jp_1[];
extern const u16 gcfg_cursor_scr_jp_0[];
extern const u16 gcfg_cursor_clr_scr_jp_0[];
extern const u16 gcfg_gauge_scr_jp_0[];
extern const u16 gcfg_gauge_scr_jp_1[];
extern const u16 gcfg_gauge_scr_jp_2[];
extern const u16 gcfg_gauge_scr_jp_3[];
extern const u16 gcfg_gauge_scr_jp_4[];
extern const u16 gcfg_gauge_scr_jp_5[];
extern const u16 gcfg_gauge_scr_jp_6[];
extern const u16 gcfg_gauge_scr_jp_7[];
extern const u16 gcfg_gauge_clr_scr_jp_0[];
extern const u16 gcfg_title_old_scr_jp_0[];

const u16 gcfg_guide_scr_jp_0[24] = {
    19, 5, 24, 2,   0x1354, 0x1350, 0x1274, 0x1278, 0x127C, 0x12A8, 0x1324, 0x12C0, 0x12CC, 0x1218,
                    0x1284, 0x12A8, 0x1324, 0x12C0, 0x12CC, 0x121C, 0x1254, 0x1378, 0x137C,
    0,
};

const u16 gcfg_exit_guide_scr_jp_0[26] = {
    21, 5, 24, 2,   0x1200, 0x1218, 0x13C4, 0x12A8, 0x1324, 0x12C0, 0x12CC, 0x1218, 0x1254, 0x133C,
                    0x1340, 0x1300, 0x12D4, 0x1308, 0x13C8, 0x125C, 0x1344, 0x1264, 0x1200, 0x1200,
                    0x1200,
    0,
};

const u16 gcfg_screen_scr_jp_1[9] = {
    4, 0, 0, 2,     0x13D0, 0x1288, 0x12D0, 0x1200,
    0,
};

const u16 gcfg_screen_scr_jp_0[9] = {
    4, 0, 0, 2,     0x12D8, 0x13C8, 0x12F8, 0x1314,
    0,
};

const u16 gcfg_round_scr_jp_0[9] = {
    4, 0, 0, 2,     0x1218, 0x13B4, 0x1388, 0x138C,
    0,
};

const u16 gcfg_round_scr_jp_1[9] = {
    4, 0, 0, 2,     0x1220, 0x13B4, 0x1388, 0x138C,
    0,
};

const u16 gcfg_round_scr_jp_2[9] = {
    4, 0, 0, 2,     0x1228, 0x13B4, 0x1388, 0x138C,
    0,
};

const u16 gcfg_round_scr_jp_3[9] = {
    4, 0, 0, 2,     0x1230, 0x13B4, 0x1388, 0x138C,
    0,
};

const u16 gcfg_event_scr_jp_0[9] = {
    4, 0, 0, 2,     0x12D8, 0x13C8, 0x12F8, 0x1314,
    0,
};

const u16 gcfg_event_scr_jp_1[9] = {
    4, 0, 0, 2,     0x1218, 0x12F8, 0x12C0, 0x12BC,
    0,
};

const u16 gcfg_bonus_scr_jp_0[7] = {
    2, 0, 0, 2,     0x1258, 0x1248,
    0,
};

const u16 gcfg_bonus_scr_jp_1[7] = {
    2, 0, 0, 2,     0x123C, 0x1268,
    0,
};

const u16 gcfg_cursor_scr_jp_0[6] = {
    1, 1, 0, 2,     0x1204,
    0,
};

const u16 gcfg_cursor_clr_scr_jp_0[6] = {
    1, 1, 0, 2,     0x1200,
    0,
};

const u16 gcfg_gauge_scr_jp_0[6] = {
    1, 1, 0, 2,     0x1218,
    0,
};

const u16 gcfg_gauge_scr_jp_1[6] = {
    1, 1, 0, 2,     0x121C,
    0,
};

const u16 gcfg_gauge_scr_jp_2[6] = {
    1, 1, 0, 2,     0x1220,
    0,
};

const u16 gcfg_gauge_scr_jp_3[6] = {
    1, 1, 0, 2,     0x1224,
    0,
};

const u16 gcfg_gauge_scr_jp_4[6] = {
    1, 1, 0, 2,     0x1228,
    0,
};

const u16 gcfg_gauge_scr_jp_5[6] = {
    1, 1, 0, 2,     0x122C,
    0,
};

const u16 gcfg_gauge_scr_jp_6[6] = {
    1, 1, 0, 2,     0x1230,
    0,
};

const u16 gcfg_gauge_scr_jp_7[6] = {
    1, 1, 0, 2,     0x1234,
    0,
};

const u16 gcfg_gauge_clr_scr_jp_0[6] = {
    1, 1, 0, 2,     0x13CC,
    0,
};

/* provisional name */
/* A shorter title screen script; only gcfg_title_old_scr_jp (game_config_jp.c), which nothing reads, points at
   it. */
const u16 gcfg_title_old_scr_jp_0[110] = {
    5, 19, 0, 2,    0x129C, 0x13C8, 0x12FC, 0x133C, 0x1340,
    2, 4, 2, 2,     0x1398, 0x13A0,
    10, 24, 2, 2,   0x139C, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x1398,
    3, 4, 4, 2,     0x1390, 0x1394, 0x1330,
    6, 24, 4, 2,    0x13A4, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x13A8,
    4, 4, 6, 2,     0x12B8, 0x1288, 0x12F8, 0x13C8,
    6, 24, 6, 2,    0x13AC, 0x13CC, 0x13CC, 0x13CC, 0x13CC, 0x13B0,
    5, 4, 8, 2,     0x1388, 0x138C, 0x1304, 0x13C8, 0x12D0,
    4, 4, 10, 2,    0x1288, 0x12F0, 0x131C, 0x12CC,
    9, 4, 12, 2,    0x133C, 0x1340, 0x1300, 0x12D4, 0x1308, 0x13C8, 0x125C, 0x1344, 0x1264,
    10, 14, 22, 2,  0x1218, 0x13C4, 0x1318, 0x12DC, 0x13C8, 0x1348, 0x134C, 0x1254, 0x1358, 0x135C,
    0, 0xFFFF,
};
