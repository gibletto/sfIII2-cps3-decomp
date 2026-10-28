/*
 * END_MAIN_TBL.C  opening demo BG tables
 *
 * op_scr_record_data_0 .. op_scr_record_data_3 are the layout records of the four opening BG
 * layers, passed to sprite_list_setup; op_scrn_pos_tbl is the BG positions set by
 * opening_scrn_pos_set and op_ctr_set the counter start of an opening scene. These are read by
 * END_MAIN.C. op_panel0 - op_panel2 are the cell lists (map offset, cell number) written into
 * the opening BG layers, reached through op_panel_p in OP_END_WORK.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 op_scr_record_data_0[];
extern const u8 op_scr_record_data_1[];
extern const u8 op_scr_record_data_2[];
extern const u8 op_scr_record_data_3[];
extern const PANEL op_panel0[];
extern const PANEL op_panel1[];
extern const PANEL op_panel2[];
extern const OP_SCRN_POS op_scrn_pos_tbl[];
extern const OP_CTR_SET op_ctr_set[];

const u8 op_scr_record_data_0[56] = {
    0, 1, 0, 75, 0, 127, 127, 0, 0, 12, 0, 255, 127, 0, 0, 12,
    1, 127, 127, 0, 0, 12, 1, 255, 127, 0, 0, 12, 2, 127, 127, 0,
    0, 12, 2, 255, 127, 0, 0, 12, 3, 127, 127, 0, 0, 12, 3, 255,
    127, 0, 0, 12, 255, 255, 255, 255,
};

const u8 op_scr_record_data_1[56] = {
    0, 2, 0, 80, 0, 127, 127, 0, 0, 28, 0, 255, 127, 0, 0, 28,
    1, 127, 127, 0, 0, 28, 1, 255, 127, 0, 0, 28, 2, 127, 127, 0,
    0, 28, 2, 255, 127, 0, 0, 28, 3, 127, 127, 0, 0, 28, 3, 255,
    127, 0, 0, 28, 255, 255, 255, 255,
};

const u8 op_scr_record_data_2[56] = {
    0, 3, 0, 85, 0, 127, 127, 0, 0, 44, 0, 255, 127, 0, 0, 44,
    1, 127, 127, 0, 0, 44, 1, 255, 127, 0, 0, 44, 2, 127, 127, 0,
    0, 44, 2, 255, 127, 0, 0, 44, 3, 127, 127, 0, 0, 44, 3, 255,
    127, 0, 0, 44, 255, 255, 255, 255,
};

const u8 op_scr_record_data_3[56] = {
    0, 4, 0, 88, 0, 127, 127, 0, 0, 60, 0, 255, 127, 0, 0, 60,
    1, 127, 127, 0, 0, 60, 1, 255, 127, 0, 0, 60, 2, 127, 127, 0,
    0, 60, 2, 255, 127, 0, 0, 60, 3, 127, 127, 0, 0, 60, 3, 255,
    127, 0, 0, 60, 255, 255, 255, 255,
};

/* provisional name */
const PANEL op_panel0[16] = {
    { 0, 0 },
    { 0x40, 0 },
    { 0x80, 0 },
    { 0xC0, 0 },
    { 0x1000, 0 },
    { 0x1040, 0 },
    { 0x1080, 0 },
    { 0x10C0, 0 },
    { 0x2000, 0 },
    { 0x2040, 0 },
    { 0x2080, 0 },
    { 0x20C0, 0 },
    { 0x3000, 0 },
    { 0x3040, 0 },
    { 0x3080, 0 },
    { 0x30C0, 0 },
};

/* provisional name */
const PANEL op_panel1[16] = {
    { 0, 0 },
    { 0x40, 0 },
    { 0x80, 0 },
    { 0xC0, 0 },
    { 0x1000, 0 },
    { 0x1040, 0 },
    { 0x1080, 0 },
    { 0x10C0, 0 },
    { 0x2000, 0 },
    { 0x2040, 0 },
    { 0x2080, 0 },
    { 0x20C0, 0 },
    { 0x3000, 0 },
    { 0x3040, 4 },
    { 0x3080, 5 },
    { 0x30C0, 0 },
};

/* provisional name */
const PANEL op_panel2[62] = {
    { 0, 0 },
    { 0x40, 0 },
    { 0x80, 0 },
    { 0xC0, 0 },
    { 0x1000, 0 },
    { 0x1040, 20 },
    { 0x1080, 21 },
    { 0x10C0, 0 },
    { 0x2000, 0 },
    { 0x2040, 22 },
    { 0x2080, 23 },
    { 0x20C0, 0 },
    { 0x3000, 0 },
    { 0x3040, 24 },
    { 0x3080, 25 },
    { 0x30C0, 0 },
    { 0x3E, 63 },
    { 0, 1 },
    { 2, 3 },
    { 0x40, 65 },
    { 4, 5 },
    { 6, 7 },
    { 8, 9 },
    { 0x42, 67 },
    { 0x3E, 63 },
    { 0xA, 11 },
    { 0xC, 13 },
    { 0x40, 65 },
    { 0xE, 15 },
    { 0x1A, 27 },
    { 0x10, 17 },
    { 0x42, 67 },
    { 0x3E, 63 },
    { 0x12, 19 },
    { 0x1C, 29 },
    { 0x40, 65 },
    { 0x14, 21 },
    { 0x18, 25 },
    { 0x42, 67 },
    { 0x16, 23 },
    { 0x80102, 84017672 },
    { 0x6020302, 132872 },
    { 0x2080402, 100796168 },
    { 0x1020302, 84017160 },
    { 0x80102, 84017672 },
    { 0x6020302, 526082 },
    { 0, 0 },
    { 0x200000, 8192 },
    { 0x200000, 8192 },
    { 0x200000, 8192 },
    { 0x400000, 16384 },
    { 0, 0 },
    { 0x200000, 8192 },
    { -0x200000, -8192 },
    { 0, 0 },
    { -0x400000, -8192 },
    { -0x200000, -8192 },
    { -0x200000, -8192 },
    { -0x400000, -16384 },
    { 0, 0 },
    { -0x200000, -8192 },
    { 0x200000, 8192 },
};

/* provisional name */
const OP_SCRN_POS op_scrn_pos_tbl[4] = {
    { 0, 256, 512, 85, 0 },
    { 1, 768, 512, 34, 0 },
    { 3, 256, 0, 35, 0 },
    { 4, 768, 0, 125, 0 },
};

/* provisional name */
const OP_CTR_SET op_ctr_set[2] = {
    { { 0, 4, 3, 0, 3, 0 }, 10, 0 },
    { { 0, 4, 2, 0, 0, 0 }, 30, 0 },
};
