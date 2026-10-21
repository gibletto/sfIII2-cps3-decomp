/*
 * SC_DATA.C  tables read by sc_trans.c: text (fix) layer character transfer and put routines
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const CELL_SET sc_ram_vram_tbl[];
extern const u16 sc_celllist_scr_tbl[];
extern const u16 tone_down_tbl[];
extern const u16 picture_chr_tbl[];
extern const u16 picture_set_tbl[];
extern const u16 picture_attr_tbl[];
extern const NAME_PLATE nwdata_tbl[];
extern const u16 sc_cells_1[];
extern const u16 sc_cells_50[];
extern const u16 sc_cells_6[];
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

const CELL_SET sc_ram_vram_tbl[29] = {
    { (void *)sc_cells_1, (void *)sc_cells_6, (void *)sc_cells_50 },
    { (void *)sc_vram_01_pos, (void *)sc_vram_01_code, (void *)sc_vram_01_attr },
    { (void *)sc_vram_02_pos, (void *)sc_vram_02_code, (void *)sc_vram_02_attr },
    { (void *)sc_vram_03_pos, (void *)sc_vram_03_code, (void *)sc_vram_03_attr },
    { (void *)sc_vram_04_pos, (void *)sc_vram_04_code, (void *)sc_vram_04_attr },
    { (void *)sc_vram_05_pos, (void *)sc_vram_04_code, (void *)sc_vram_04_attr },
    { (void *)sc_vram_06_pos, (void *)sc_vram_06_code, (void *)sc_vram_06_attr },
    { (void *)sc_vram_07_pos, (void *)sc_vram_06_code, (void *)sc_vram_07_attr },
    { (void *)sc_vram_06_pos, (void *)sc_vram_06_code, (void *)sc_vram_08_attr },
    { (void *)sc_vram_07_pos, (void *)sc_vram_06_code, (void *)sc_vram_09_attr },
    { (void *)sc_vram_06_pos, (void *)sc_vram_06_code, (void *)sc_vram_10_attr },
    { (void *)sc_vram_07_pos, (void *)sc_vram_06_code, (void *)sc_vram_11_attr },
    { (void *)sc_vram_12_pos, (void *)sc_vram_12_code, (void *)sc_vram_12_attr },
    { (void *)sc_vram_13_pos, (void *)sc_vram_12_code, (void *)sc_vram_12_attr },
    { (void *)sc_vram_14_pos, (void *)sc_vram_14_code, (void *)sc_vram_14_attr },
    { (void *)sc_vram_15_pos, (void *)sc_vram_15_code, (void *)sc_vram_15_attr },
    { (void *)sc_vram_16_pos, (void *)sc_vram_16_code, (void *)sc_cells_50 },
    { (void *)sc_vram_16_pos, (void *)sc_vram_16_code, (void *)sc_cells_50 },
    { (void *)sc_vram_18_pos, (void *)sc_vram_18_code, (void *)sc_cells_50 },
    { (void *)sc_vram_19_pos, (void *)sc_vram_19_code, (void *)sc_cells_50 },
    { (void *)sc_vram_20_pos, (void *)sc_vram_20_code, (void *)sc_cells_50 },
    { (void *)sc_vram_21_pos, (void *)sc_vram_21_code, (void *)sc_cells_50 },
    { (void *)sc_vram_22_pos, (void *)sc_vram_22_code, (void *)sc_cells_50 },
    { (void *)sc_vram_23_pos, (void *)sc_vram_23_code, (void *)sc_cells_50 },
    { (void *)sc_vram_24_pos, (void *)sc_vram_24_code, (void *)sc_cells_50 },
    { (void *)sc_vram_25_pos, (void *)sc_vram_25_code, (void *)sc_cells_50 },
    { (void *)sc_vram_26_pos, (void *)sc_vram_26_code, (void *)sc_cells_50 },
    { (void *)sc_vram_27_pos, (void *)sc_vram_27_code, (void *)sc_cells_50 },
    { (void *)sc_vram_28_pos, (void *)sc_vram_28_code, (void *)sc_cells_50 },
};

/* provisional name */
const u16 sc_celllist_scr_tbl[9] = {
    3, 0x303, 0xD0C, 0x303, 0x303, 0x303, 0x306, 3,
    0x3FF,
};

/* provisional name */
const u16 tone_down_tbl[48] = {
    0x80, 0x600, 0, 4, 0x1B0, 0xBA, 4, 0x1C0,
    0xCA, 0x30, 0x12A0, 0x130, 0x20, 0x13A0, 0x1E0, 0xC0,
    0x1000, 0x140, 0x10, 0x12D0, 0x160, 0x10, 0x12E0, 0x170,
    0x70, 0x1000, 0x140, 0x30, 0x10B0, 0x1B0, 0x20, 0x1000,
    0x140, 0x20, 0x1020, 0x160, 0x20, 0x1040, 0x180, 0x20,
    0x1060, 0x1A0, 0x20, 0x1080, 0x1C0, 0x20, 0x10A0, 0x1E0,
};

/* provisional name */
const u16 picture_chr_tbl[8] = {
    0xD80, 0xC80, 0xF00, 0xE80, 0xC00, 0xD00, 0xF80, 0x780,
};

/* provisional name */
const u16 picture_set_tbl[8] = {
    0x13, 0x1A, 0x1A, 0x12, 0x1A, 0x12, 0x12, 0x1C,
};

/* provisional name */
const u16 picture_attr_tbl[8] = {
    0x32, 0x2C, 0x30, 0x30, 0x2C, 0x2C, 0x2E, 0x30,
};

const NAME_PLATE nwdata_tbl[17] = {
    { 0x1100, 0xA, 4, 13, 9, 24, 9 },
    { 0x1128, 0xD, 4, 11, 9, 25, 9 },
    { 0x115C, 0xA, 4, 13, 9, 24, 9 },
    { 0x1184, 0xA, 4, 13, 9, 24, 9 },
    { 0x11AC, 0x10, 4, 10, 9, 27, 9 },
    { 0x11F4, 0x10, 4, 10, 9, 27, 9 },
    { 0x1234, 0xE, 4, 11, 9, 26, 9 },
    { 0x126C, 0xE, 4, 11, 9, 26, 9 },
    { 0x12A4, 0xF, 4, 10, 9, 26, 9 },
    { 0x12E0, 0xA, 4, 13, 9, 24, 9 },
    { 0x1308, 0xD, 4, 11, 9, 25, 9 },
    { 0x133C, 0xA, 4, 13, 9, 24, 9 },
    { 0x1364, 0xD, 4, 11, 9, 25, 9 },
    { 0x1398, 0xF, 4, 10, 9, 26, 9 },
    { 0x13D4, 0xF, 4, 10, 9, 26, 9 },
    { 0x1410, 0xF, 4, 10, 9, 26, 9 },
    { 0x15B0, 0x10, 4, 10, 9, 27, 9 },
};
