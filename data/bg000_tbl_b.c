/*
 * BG000_TBL_B.C  stage background set-up tables
 *
 * Per stage background (bg_index), and for the special screens drawn by bg_etc_write (the etc_
 * tables, by screen type): the number of layers (bg_scno_tbl), the scroll graphics source and
 * size (bg_gfx_tbl), the layer scroll speeds (bg_speed_tbl), the cell attribute (bg_attr_tbl),
 * the cell count per layer (bg_cell_cnt_tbl) and the screen data the cells come from
 * (bg_cg_src_tbl), with etc_bg_zuubun_tbl for the special screens' layers. The layer layout
 * records passed to sprite_list_setup follow, named per stage and layer as bg_map_tbl and
 * bg_map_tbl2 in BG_WORK.C use them: bg_scr_record_NN_n (stage NN, layer n) and
 * etc_bg_scr_record_N_n (special screen N), each named after the first entry that uses it,
 * bg_scr_record_data (layer 0 of several stages and of every special screen),
 * ake_scr_record_data (the finish screen's layer 3) and the unreferenced bg_scr_record_unref_N.
 * Read by BG000.C; bg_gfx_tbl also by CMD_MAIN.C and bg_scr_record_data by EFFG0.C.
 *
 * A layer layout record (sprite_list_setup) is a run of groups, each the layer and priority followed by
 * (code, position, attribute) entries and -1, ended by -1; the comment before each record says which
 * stages' layers use it.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 bg_scno_tbl[];
extern const s16 etc_bg_scno_tbl[];
extern const s16 bg_scr_record_data[16];
extern const s16 bg_scr_record_00_1[16];
extern const s16 bg_scr_record_00_2[16];
extern const s16 etc_bg_scr_record_0_3[16];
extern const s16 bg_scr_record_unref_0[28];
extern const s16 ake_scr_record_data[28];
extern const s16 bg_scr_record_unref_1[13];
extern const s16 bg_scr_record_unref_2[7];
extern const s16 bg_scr_record_01_0[16];
extern const s16 bg_scr_record_01_1[16];
extern const s16 bg_scr_record_02_0[13];
extern const s16 bg_scr_record_02_1[16];
extern const s16 bg_scr_record_03_0[16];
extern const s16 bg_scr_record_03_1[16];
extern const s16 bg_scr_record_03_2[13];
extern const s16 bg_scr_record_11_0[13];
extern const s16 bg_scr_record_11_1[13];
extern const s16 bg_scr_record_04_0[16];
extern const s16 bg_scr_record_04_1[16];
extern const s16 bg_scr_record_05_2[7];
extern const s16 bg_scr_record_06_0[13];
extern const s16 bg_scr_record_07_0[16];
extern const s16 bg_scr_record_07_2[16];
extern const s16 bg_scr_record_08_0[22];
extern const s16 bg_scr_record_08_1[7];
extern const s16 bg_scr_record_09_1[28];
extern const s16 bg_scr_record_10_0[10];
extern const s16 bg_scr_record_10_2[10];
extern const s16 bg_scr_record_12_0[16];
extern const s16 bg_scr_record_12_1[16];
extern const s16 bg_scr_record_13_0[16];
extern const s16 bg_scr_record_14_0[16];
extern const s16 bg_scr_record_14_1[13];
extern const s16 bg_scr_record_15_0[19];
extern const s16 bg_scr_record_17_0[13];
extern const s16 bg_scr_record_unref_3[16];
extern const s16 bg_scr_record_unref_4[16];
extern const s16 bg_scr_record_unref_5[16];
extern const s16 bg_scr_record_unref_6[1];
extern const s32 bg_speed_tbl[][4][2];
extern const s32 etc_bg_speed_tbl[][4][2];
extern const s32 etc_bg_zuubun_tbl[][4];
extern const BG_GFX bg_gfx_tbl[];
extern const BG_GFX etc_bg_gfx_tbl[];
extern const s16 bg_attr_tbl[];
extern const s16 etc_bg_attr_tbl[];
extern const s16 bg_cell_cnt_tbl[][4];
extern const s16 etc_bg_cell_cnt_tbl[][4];
extern const u32 bg_cg_src_tbl[];
extern const u32 etc_bg_cg_src_tbl[];
extern const u16 bg_scrn_data_11[17][16][32];
extern const u16 bg_scrn_data_07[27][16][32];
extern const u16 bg_scrn_data_08[10][16][32];
extern const u16 bg_scrn_data_10[25][16][32];
extern const u16 bg_scrn_data_12[9][16][32];
extern const u16 bg_scrn_data_15[9][16][32];
extern const u16 etc_bg_scrn_data_0[5][16][32];
extern const u16 etc_bg_scrn_data_3[23][16][32];
extern const u16 debug_scene_scrn_data[17][16][32];
extern const u16 eff08_scrn_data[21][16][32];
extern const u16 eff23_scrn_data[3][16][32];
extern const u16 eff45_scrn_data[17][16][32];
extern const u16 effJ5_scrn_data[17][16][32];
extern const u16 effb0_scrn_data[3][16][32];
extern const u16 bg_scrn_data_01[17][16][32];
extern const u16 bg_scrn_data_02[17][16][32];
extern const u16 bg_scrn_data_03[17][16][32];
extern const u16 bg_scrn_data_04[17][16][32];
extern const u16 bg_scrn_data_05[25][16][32];

/* provisional name */
const s16 bg_scno_tbl[18] = {
    2, 2, 2, 3, 2, 3, 2, 3,
    2, 2, 3, 2, 2, 2, 2, 2,
    2, 1,
};

/* provisional name */
const s16 etc_bg_scno_tbl[5] = {
    1, 1, 1, 1, 1,
};

/* layer 0 of stages 0, 5, 9; layer 0 of special screens 0, 1, 2, 3, 4 */
const s16 bg_scr_record_data[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stages 0, 5, 6, 7, 10, 13, 15, 16; layer 1 of special screen 0; provisional name */
const s16 bg_scr_record_00_1[16] = {
    2, 84,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 2 of stages 0, 12, 13; layer 2 of special screen 0; provisional name */
const s16 bg_scr_record_00_2[16] = {
    3, 104,  0x7F, 0x7F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  -1,
    -1,
};

/* layer 3 of special screen 0; provisional name */
const s16 etc_bg_scr_record_0_3[16] = {
    4, 94,  0x7F, 0x7F00, 60,  0xFF, 0x7F00, 60,  0x17F, 0x7F00, 60,  0x1FF, 0x7F00, 60,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_0[28] = {
    0, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* provisional name */
/* layer 3 of the finish screen (bg_initialize, akebono_scr_write) */
const s16 ake_scr_record_data[28] = {
    4, 69,  0x7F, 0x7F00, 60,  0xFF, 0x7F00, 60,  0x17F, 0x7F00, 60,  0x1FF, 0x7F00, 60,  0x27F, 0x7F00, 60,
           0x2FF, 0x7F00, 60,  0x37F, 0x7F00, 60,  0x3FF, 0x7F00, 60,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_1[13] = {
    1, 94,  0xFF, 0x6F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_2[7] = {
    2, 84,  0x40, 0x4000, 28,  -1,
    -1,
};

/* layer 0 of stage 1; provisional name */
const s16 bg_scr_record_01_0[16] = {
    1, 94,  0x7F, 0x2800, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 1; provisional name */
const s16 bg_scr_record_01_1[16] = {
    2, 84,  0x7F, 0x6F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 0 of stage 2; provisional name */
const s16 bg_scr_record_02_0[13] = {
    1, 94,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 2; provisional name */
const s16 bg_scr_record_02_1[16] = {
    2, 84,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 0 of stage 3; provisional name */
const s16 bg_scr_record_03_0[16] = {
    1, 104,  0x7F, 0x1800, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 3; provisional name */
const s16 bg_scr_record_03_1[16] = {
    1, 94,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 2 of stage 3; provisional name */
const s16 bg_scr_record_03_2[13] = {
    3, 114,  0xFF, 0x1F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  -1,
    -1,
};

/* layer 0 of stage 11; provisional name */
const s16 bg_scr_record_11_0[13] = {
    1, 114,  0x7F, 0x1F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 11; provisional name */
const s16 bg_scr_record_11_1[13] = {
    2, 104,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  -1,
    -1,
};

/* layer 0 of stage 4; provisional name */
const s16 bg_scr_record_04_0[16] = {
    1, 94,  0x7F, 0xF00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 4; provisional name */
const s16 bg_scr_record_04_1[16] = {
    2, 84,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 2 of stage 5; provisional name */
const s16 bg_scr_record_05_2[7] = {
    3, 104,  0xFF, 0x7F00, 44,  -1,
    -1,
};

/* layer 0 of stages 6, 16; provisional name */
const s16 bg_scr_record_06_0[13] = {
    1, 94,  0xFF, 0x6F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 7; provisional name */
const s16 bg_scr_record_07_0[16] = {
    1, 94,  0x7F, 0x1500, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 2 of stage 7; provisional name */
const s16 bg_scr_record_07_2[16] = {
    3, 104,  0x7F, 0x1F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  -1,
    -1,
};

/* layer 0 of stage 8; provisional name */
const s16 bg_scr_record_08_0[22] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x37F, 0x7F00, 12,
           0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 8; provisional name */
const s16 bg_scr_record_08_1[7] = {
    2, 120,  0x17F, 0x100, 28,  -1,
    -1,
};

/* layer 1 of stage 9; provisional name */
const s16 bg_scr_record_09_1[28] = {
    2, 84,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  0x27F, 0x7F00, 28,
           0x2FF, 0x7F00, 28,  0x37F, 0x7F00, 28,  0x3FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 0 of stage 10; provisional name */
const s16 bg_scr_record_10_0[10] = {
    1, 94,  0x7F, 0x3F00, 12,  0xCF, 0x4F00, 12,  -1,
    -1,
};

/* layer 2 of stage 10; provisional name */
const s16 bg_scr_record_10_2[10] = {
    3, 104,  0x7F, 0x3F00, 44,  0xCF, 0x4F00, 44,  -1,
    -1,
};

/* layer 0 of stage 12; provisional name */
const s16 bg_scr_record_12_0[16] = {
    1, 94,  0x7F, 0x3F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 12; provisional name */
const s16 bg_scr_record_12_1[16] = {
    2, 84,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* layer 0 of stage 13; provisional name */
const s16 bg_scr_record_13_0[16] = {
    1, 94,  0x7F, 0x3F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 14; provisional name */
const s16 bg_scr_record_14_0[16] = {
    1, 94,  0x7F, 0x4F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 14; provisional name */
const s16 bg_scr_record_14_1[13] = {
    2, 84,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  -1,
    -1,
};

/* layer 0 of stage 15; provisional name */
const s16 bg_scr_record_15_0[19] = {
    1, 94,  0x7F, 0x4C00, 12,  0xFF, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 17; provisional name */
const s16 bg_scr_record_17_0[13] = {
    1, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_3[16] = {
    1, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_4[16] = {
    2, 94,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_5[16] = {
    3, 104,  0x7F, 0x7F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  -1,
    -1,
};

/* an empty record (the end mark alone); not referred to; provisional name */
const s16 bg_scr_record_unref_6[1] = {
    -1,
};

/* provisional name */
const s32 bg_speed_tbl[17][4][2] = {
    { { 0x4000, 0xA000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0x10000, 0x10000 } },
    { { 0xA000, 0xC000 }, { 0x10000, 0x10000 }, { 0xA000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xF000 }, { 0x10000, 0x10000 }, { 0x8000, 0xB000 }, { 0, 0 } },
    { { 0xE000, 0x11000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0xC000, 0x10000 }, { 0, 0 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { 0xA000, 0x10000 }, { 0x10000, 0x10000 }, { 0x4000, 0xA000 }, { 0, 0 } },
    { { 0x1000, 0x8000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { 0x8000, 0x8000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0x8000, 0xF000 }, { 0, 0 } },
    { { 0xE000, 0x11000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { 0xC000, 0xC000 }, { 0x10000, 0x10000 }, { 0x8000, 0xF000 }, { 0, 0 } },
    { { 0xF000, 0x10000 }, { 0x10000, 0x10000 }, { 0x8000, 0xF000 }, { 0, 0 } },
    { { 0x6000, 0xC000 }, { 0x10000, 0x10000 }, { 0x8000, 0xF000 }, { 0, 0 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { 0xE000, 0xE000 }, { 0x10000, 0x10000 }, { 0x8000, 0xF000 }, { 0, 0 } },
};

/* provisional name */
const s32 etc_bg_speed_tbl[5][4][2] = {
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xF800, 0xF000 }, { 0x10000, 0x10000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 }, { 0, 0 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 }, { 0, 0 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 }, { 0, 0 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 }, { 0, 0 } },
};

/* provisional name */
const s32 etc_bg_zuubun_tbl[5][4] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
};

/* provisional name */
const BG_GFX bg_gfx_tbl[18] = {
    { 0x116C020, 23311, 0x116C0A0, 1 },
    { 0x11A38B0, 17983, 0x11A3930, 1 },
    { 0x1016800, 20735, 0x1016880, 1 },
    { 0x1032800, 27071, 0x1032880, 1 },
    { 0x105B800, 24959, 0x105B880, 1 },
    { 0x1077000, 39327, 0x1077080, 1 },
    { 0x10A1800, 43295, 0x10A1880, 1 },
    { 0x1146800, 32303, 0x1146880, 1 },
    { 0x10DC800, 9887, 0x10DC880, 1 },
    { 0x10F2000, 24623, 0x10F2080, 1 },
    { 0x1125800, 26463, 0x1125880, 1 },
    { 0x115E020, 20767, 0x115E0A0, 1 },
    { 0x1218000, 26287, 0x1218080, 1 },
    { 0x118A8B0, 15327, 0x118A930, 1 },
    { 0x11BA8B0, 17215, 0x11BA930, 1 },
    { 0x11D28B0, 25775, 0x11D2930, 1 },
    { 0x10A1800, 43295, 0x10A1880, 1 },
    { 0x1600000, 3759, 0x1600080, 1 },
};

/* provisional name */
const BG_GFX etc_bg_gfx_tbl[5] = {
    { 0x1602000, 6511, 0x1602080, 1 },
    { 0x1602000, 6511, 0x1602080, 1 },
    { 0x1602000, 6511, 0x1602080, 1 },
    { 0x1189020, 4383, 0x11890A0, 1 },
    { 0x1189020, 4383, 0x11890A0, 1 },
};

/* provisional name */
const s16 bg_attr_tbl[19] = {
    512, 512, 512, 512, 512, 512, 512, 512,
    512, 512, 512, 512, 512, 512, 512, 512,
    512, 512, 512,
};

/* provisional name */
const s16 etc_bg_attr_tbl[5] = {
    512, 512, 512, 512, 512,
};

/* provisional name */
const s16 bg_cell_cnt_tbl[18][4] = {
    { 8, 8, 8, 0 },
    { 8, 8, 2, 0 },
    { 8, 8, 0, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 0, 0 },
    { 8, 8, 8, 0 },
    { 12, 0, 0, 0 },
    { 8, 8, 0, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 0, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 8, 0 },
    { 8, 8, 0, 0 },
    { 8, 8, 0, 0 },
    { 4, 0, 0, 0 },
};

/* provisional name */
const s16 etc_bg_cell_cnt_tbl[5][4] = {
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
};

/* provisional name */
const u32 bg_cg_src_tbl[20] = {
    (u32)debug_scene_scrn_data, (u32)bg_scrn_data_01, (u32)bg_scrn_data_02, (u32)bg_scrn_data_03,
    (u32)bg_scrn_data_04, (u32)bg_scrn_data_05, (u32)eff23_scrn_data, (u32)bg_scrn_data_07,
    (u32)bg_scrn_data_08, (u32)eff08_scrn_data, (u32)bg_scrn_data_10, (u32)bg_scrn_data_11,
    (u32)bg_scrn_data_12, (u32)effJ5_scrn_data, (u32)eff45_scrn_data, (u32)bg_scrn_data_15,
    (u32)eff23_scrn_data, (u32)effb0_scrn_data, (u32)effb0_scrn_data, (u32)effb0_scrn_data,
};

const u32 etc_bg_cg_src_tbl[5] = {
    (u32)etc_bg_scrn_data_0, (u32)etc_bg_scrn_data_0, (u32)etc_bg_scrn_data_0, (u32)etc_bg_scrn_data_3,
    (u32)etc_bg_scrn_data_3,
};
