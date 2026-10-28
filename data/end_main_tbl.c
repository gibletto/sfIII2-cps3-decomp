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
    0, 1, 0, 0x4B, 0, 0x7F, 0x7F, 0, 0, 0xC, 0, 0xFF, 0x7F, 0, 0, 0xC,
    1, 0x7F, 0x7F, 0, 0, 0xC, 1, 0xFF, 0x7F, 0, 0, 0xC, 2, 0x7F, 0x7F, 0,
    0, 0xC, 2, 0xFF, 0x7F, 0, 0, 0xC, 3, 0x7F, 0x7F, 0, 0, 0xC, 3, 0xFF,
    0x7F, 0, 0, 0xC, 0xFF, 0xFF, 0xFF, 0xFF,
};

const u8 op_scr_record_data_1[56] = {
    0, 2, 0, 0x50, 0, 0x7F, 0x7F, 0, 0, 0x1C, 0, 0xFF, 0x7F, 0, 0, 0x1C,
    1, 0x7F, 0x7F, 0, 0, 0x1C, 1, 0xFF, 0x7F, 0, 0, 0x1C, 2, 0x7F, 0x7F, 0,
    0, 0x1C, 2, 0xFF, 0x7F, 0, 0, 0x1C, 3, 0x7F, 0x7F, 0, 0, 0x1C, 3, 0xFF,
    0x7F, 0, 0, 0x1C, 0xFF, 0xFF, 0xFF, 0xFF,
};

const u8 op_scr_record_data_2[56] = {
    0, 3, 0, 0x55, 0, 0x7F, 0x7F, 0, 0, 0x2C, 0, 0xFF, 0x7F, 0, 0, 0x2C,
    1, 0x7F, 0x7F, 0, 0, 0x2C, 1, 0xFF, 0x7F, 0, 0, 0x2C, 2, 0x7F, 0x7F, 0,
    0, 0x2C, 2, 0xFF, 0x7F, 0, 0, 0x2C, 3, 0x7F, 0x7F, 0, 0, 0x2C, 3, 0xFF,
    0x7F, 0, 0, 0x2C, 0xFF, 0xFF, 0xFF, 0xFF,
};

const u8 op_scr_record_data_3[56] = {
    0, 4, 0, 0x58, 0, 0x7F, 0x7F, 0, 0, 0x3C, 0, 0xFF, 0x7F, 0, 0, 0x3C,
    1, 0x7F, 0x7F, 0, 0, 0x3C, 1, 0xFF, 0x7F, 0, 0, 0x3C, 2, 0x7F, 0x7F, 0,
    0, 0x3C, 2, 0xFF, 0x7F, 0, 0, 0x3C, 3, 0x7F, 0x7F, 0, 0, 0x3C, 3, 0xFF,
    0x7F, 0, 0, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF,
};

/* provisional name */
const PANEL op_panel0[16] = {
    { 0, 0 },
    { 64, 0 },
    { 128, 0 },
    { 192, 0 },
    { 4096, 0 },
    { 4160, 0 },
    { 4224, 0 },
    { 4288, 0 },
    { 8192, 0 },
    { 8256, 0 },
    { 8320, 0 },
    { 8384, 0 },
    { 12288, 0 },
    { 12352, 0 },
    { 12416, 0 },
    { 12480, 0 },
};

/* provisional name */
const PANEL op_panel1[16] = {
    { 0, 0 },
    { 64, 0 },
    { 128, 0 },
    { 192, 0 },
    { 4096, 0 },
    { 4160, 0 },
    { 4224, 0 },
    { 4288, 0 },
    { 8192, 0 },
    { 8256, 0 },
    { 8320, 0 },
    { 8384, 0 },
    { 12288, 0 },
    { 12352, 4 },
    { 12416, 5 },
    { 12480, 0 },
};

/* provisional name */
const PANEL op_panel2[62] = {
    { 0, 0 },
    { 64, 0 },
    { 128, 0 },
    { 192, 0 },
    { 4096, 0 },
    { 4160, 20 },
    { 4224, 21 },
    { 4288, 0 },
    { 8192, 0 },
    { 8256, 22 },
    { 8320, 23 },
    { 8384, 0 },
    { 12288, 0 },
    { 12352, 24 },
    { 12416, 25 },
    { 12480, 0 },
    { 62, 63 },
    { 0, 1 },
    { 2, 3 },
    { 64, 65 },
    { 4, 5 },
    { 6, 7 },
    { 8, 9 },
    { 66, 67 },
    { 62, 63 },
    { 10, 11 },
    { 12, 13 },
    { 64, 65 },
    { 14, 15 },
    { 26, 27 },
    { 16, 17 },
    { 66, 67 },
    { 62, 63 },
    { 18, 19 },
    { 28, 29 },
    { 64, 65 },
    { 20, 21 },
    { 24, 25 },
    { 66, 67 },
    { 22, 23 },
    { 524546, 84017672 },
    { 100795138, 132872 },
    { 34079746, 100796168 },
    { 16909058, 84017160 },
    { 524546, 84017672 },
    { 100795138, 526082 },
    { 0, 0 },
    { 2097152, 8192 },
    { 2097152, 8192 },
    { 2097152, 8192 },
    { 4194304, 16384 },
    { 0, 0 },
    { 2097152, 8192 },
    { -2097152, -8192 },
    { 0, 0 },
    { -4194304, -8192 },
    { -2097152, -8192 },
    { -2097152, -8192 },
    { -4194304, -16384 },
    { 0, 0 },
    { -2097152, -8192 },
    { 2097152, 8192 },
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
