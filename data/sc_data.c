/*
 * SC_DATA.C  text layer transfer, picture and name plate tables
 *
 * sc_ram_vram_tbl has 29 entries, each pointing at a position list, a character code list and
 * an attribute list in SC_TRANS_TBL.C, for putting prepared screen parts on the text layer.
 * sc_celllist_scr_tbl gives each cell list its screen column base, tone_down_tbl the character
 * transfers of ToneDown, picture_chr_tbl, picture_set_tbl and picture_attr_tbl the characters,
 * screen part and attribute of each text-layer picture (sc_picture_put), and nwdata_tbl the
 * winner name plate of each character (cells, size and two positions). Read by SC_TRANS.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const CELL_SET sc_ram_vram_tbl[];
extern const s8 sc_celllist_scr_tbl[];
extern const TONE_ENTRY tone_down_tbl[];
extern const u16 picture_chr_tbl[];
extern const s16 picture_set_tbl[];
extern const u16 picture_attr_tbl[];
extern const NAME_PLATE nwdata_tbl[];
extern const u16 sc_vram_01_attr[];
extern const u16 sc_vram_01_pos[];
extern const u16 sc_vram_02_attr[];
extern const u16 sc_vram_02_code[];
extern const u16 sc_vram_02_pos[];
extern const u16 sc_vram_03_attr[];
extern const u16 sc_vram_03_code[];
extern const u16 sc_vram_03_pos[];
extern const u16 sc_vram_04_attr[];
extern const u16 sc_vram_04_code[];
extern const u16 sc_vram_04_pos[];
extern const u16 sc_vram_05_pos[];
extern const u16 sc_vram_06_attr[];
extern const u16 sc_vram_06_code[];
extern const u16 sc_vram_06_pos[];
extern const u16 sc_vram_07_attr[];
extern const u16 sc_vram_07_pos[];
extern const u16 sc_vram_08_attr[];
extern const u16 sc_vram_09_attr[];
extern const u16 sc_vram_10_attr[];
extern const u16 sc_vram_16_code[];
extern const u16 sc_vram_16_pos[];
extern const u16 sc_vram_18_code[];
extern const u16 sc_vram_18_pos[];
extern const u16 sc_vram_19_code[];
extern const u16 sc_vram_19_pos[];
extern const u16 sc_vram_20_code[];
extern const u16 sc_vram_21_code[];
extern const u16 sc_vram_24_code[];
extern const u16 sc_vram_24_pos[];
extern const u16 sc_vram_25_code[];
extern const u16 sc_vram_25_pos[];
extern const u16 sc_vram_26_code[];
extern const u16 sc_vram_26_pos[];
extern const u16 sc_vram_28_code[];
extern const u16 sc_vram_28_pos[];
extern const u16 sc_vram_01_code[];
extern const u16 sc_vram_11_attr[];
extern const u16 sc_vram_12_attr[];
extern const u16 sc_vram_12_code[];
extern const u16 sc_vram_12_pos[];
extern const u16 sc_vram_13_pos[];
extern const u16 sc_vram_14_attr[];
extern const u16 sc_vram_14_code[];
extern const u16 sc_vram_14_pos[];
extern const u16 sc_vram_15_attr[];
extern const u16 sc_vram_15_code[];
extern const u16 sc_vram_15_pos[];
extern const u16 sc_vram_20_pos[];
extern const u16 sc_vram_21_pos[];
extern const u16 sc_vram_22_code[];
extern const u16 sc_vram_22_pos[];
extern const u16 sc_vram_23_code[];
extern const u16 sc_vram_23_pos[];
extern const u16 sc_vram_27_code[];
extern const u16 sc_vram_27_pos[];
extern const u16 sc_vram_00_attr[];
extern const u16 sc_vram_00_code[];
extern const u16 sc_vram_00_pos[];

const CELL_SET sc_ram_vram_tbl[29] = {
    { sc_vram_00_pos, sc_vram_00_code, sc_vram_00_attr },
    { sc_vram_01_pos, sc_vram_01_code, sc_vram_01_attr },
    { sc_vram_02_pos, sc_vram_02_code, sc_vram_02_attr },
    { sc_vram_03_pos, sc_vram_03_code, sc_vram_03_attr },
    { sc_vram_04_pos, sc_vram_04_code, sc_vram_04_attr },
    { sc_vram_05_pos, sc_vram_04_code, sc_vram_04_attr },
    { sc_vram_06_pos, sc_vram_06_code, sc_vram_06_attr },
    { sc_vram_07_pos, sc_vram_06_code, sc_vram_07_attr },
    { sc_vram_06_pos, sc_vram_06_code, sc_vram_08_attr },
    { sc_vram_07_pos, sc_vram_06_code, sc_vram_09_attr },
    { sc_vram_06_pos, sc_vram_06_code, sc_vram_10_attr },
    { sc_vram_07_pos, sc_vram_06_code, sc_vram_11_attr },
    { sc_vram_12_pos, sc_vram_12_code, sc_vram_12_attr },
    { sc_vram_13_pos, sc_vram_12_code, sc_vram_12_attr },
    { sc_vram_14_pos, sc_vram_14_code, sc_vram_14_attr },
    { sc_vram_15_pos, sc_vram_15_code, sc_vram_15_attr },
    { sc_vram_16_pos, sc_vram_16_code, sc_vram_00_attr },
    { sc_vram_16_pos, sc_vram_16_code, sc_vram_00_attr },
    { sc_vram_18_pos, sc_vram_18_code, sc_vram_00_attr },
    { sc_vram_19_pos, sc_vram_19_code, sc_vram_00_attr },
    { sc_vram_20_pos, sc_vram_20_code, sc_vram_00_attr },
    { sc_vram_21_pos, sc_vram_21_code, sc_vram_00_attr },
    { sc_vram_22_pos, sc_vram_22_code, sc_vram_00_attr },
    { sc_vram_23_pos, sc_vram_23_code, sc_vram_00_attr },
    { sc_vram_24_pos, sc_vram_24_code, sc_vram_00_attr },
    { sc_vram_25_pos, sc_vram_25_code, sc_vram_00_attr },
    { sc_vram_26_pos, sc_vram_26_code, sc_vram_00_attr },
    { sc_vram_27_pos, sc_vram_27_code, sc_vram_00_attr },
    { sc_vram_28_pos, sc_vram_28_code, sc_vram_00_attr },
};

/* provisional name */
const s8 sc_celllist_scr_tbl[18] = {
    0, 3, 3, 3, 13, 12, 3, 3, 3, 3, 3, 3, 3, 6, 0, 3,
    3, -1,
};

/* provisional name */
const TONE_ENTRY tone_down_tbl[16] = {
    { 0x80, 0x600, 0 }, { 4, 0x1B0, 0xBA },
    { 4, 0x1C0, 0xCA }, { 0x30, 0x12A0, 0x130 },
    { 0x20, 0x13A0, 0x1E0 }, { 0xC0, 0x1000, 0x140 },
    { 0x10, 0x12D0, 0x160 }, { 0x10, 0x12E0, 0x170 },
    { 0x70, 0x1000, 0x140 }, { 0x30, 0x10B0, 0x1B0 },
    { 0x20, 0x1000, 0x140 }, { 0x20, 0x1020, 0x160 },
    { 0x20, 0x1040, 0x180 }, { 0x20, 0x1060, 0x1A0 },
    { 0x20, 0x1080, 0x1C0 }, { 0x20, 0x10A0, 0x1E0 },
};

/* provisional name */
const u16 picture_chr_tbl[8] = {
    0xD80, 0xC80, 0xF00, 0xE80, 0xC00, 0xD00, 0xF80, 0x780,
};

/* provisional name */
const s16 picture_set_tbl[8] = {
    0x13, 0x1A, 0x1A, 0x12, 0x1A, 0x12, 0x12, 0x1C,
};

/* provisional name */
const u16 picture_attr_tbl[8] = {
    0x32, 0x2C, 0x30, 0x30, 0x2C, 0x2C, 0x2E, 0x30,
};

const NAME_PLATE nwdata_tbl[17] = {
    { 0x1100, 10, 4, 13, 9, 24, 9 },
    { 0x1128, 13, 4, 11, 9, 25, 9 },
    { 0x115C, 10, 4, 13, 9, 24, 9 },
    { 0x1184, 10, 4, 13, 9, 24, 9 },
    { 0x11AC, 16, 4, 10, 9, 27, 9 },
    { 0x11F4, 16, 4, 10, 9, 27, 9 },
    { 0x1234, 14, 4, 11, 9, 26, 9 },
    { 0x126C, 14, 4, 11, 9, 26, 9 },
    { 0x12A4, 15, 4, 10, 9, 26, 9 },
    { 0x12E0, 10, 4, 13, 9, 24, 9 },
    { 0x1308, 13, 4, 11, 9, 25, 9 },
    { 0x133C, 10, 4, 13, 9, 24, 9 },
    { 0x1364, 13, 4, 11, 9, 25, 9 },
    { 0x1398, 15, 4, 10, 9, 26, 9 },
    { 0x13D4, 15, 4, 10, 9, 26, 9 },
    { 0x1410, 15, 4, 10, 9, 26, 9 },
    { 0x15B0, 16, 4, 10, 9, 27, 9 },
};
