/*
 * ABOUTSPR_TBL_C.C  tables read by aboutspr.c: cell flipping, cell sizes and zoom steps
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void char_cell_flip_none();
extern void char_cell_flip_x();
extern void char_cell_flip_xy();
extern void char_cell_flip_y();
extern void char_cell_unflip_xy();
extern void char_cell_unflip_y();
extern void make_char_cells_n();
extern void make_char_cells_x();
extern void make_char_cells_xy();
extern void make_char_cells_y();
extern void (*const char_cell_flip_tbl[])();
extern void (*const make_char_cells_tbl[])();
extern const s16 cell_size_tbl[];
extern const u16 flip_attr_tbl[];
extern const s16 judge_area_code_tbl[];
extern const s16 zoom_down_tbl[];
extern const s16 zoom_up_tbl[];
extern const s16 cell_zoom_tbl[];

void (*const char_cell_flip_tbl[16])() = {
    (void (*)())char_cell_flip_none,
    (void (*)())char_cell_flip_x,
    (void (*)())char_cell_flip_y,
    (void (*)())char_cell_flip_xy,
    (void (*)())char_cell_flip_x,
    (void (*)())char_cell_flip_none,
    (void (*)())char_cell_flip_xy,
    (void (*)())char_cell_flip_y,
    (void (*)())char_cell_unflip_y,
    (void (*)())char_cell_unflip_xy,
    (void (*)())char_cell_flip_none,
    (void (*)())char_cell_flip_x,
    (void (*)())char_cell_unflip_xy,
    (void (*)())char_cell_unflip_y,
    (void (*)())char_cell_flip_x,
    (void (*)())char_cell_flip_none,
};

void (*const make_char_cells_tbl[4])() = {
    (void (*)())make_char_cells_n,
    (void (*)())make_char_cells_x,
    (void (*)())make_char_cells_y,
    (void (*)())make_char_cells_xy,
};

const s16 cell_size_tbl[16] = {
    1792, 1807, 1823, 1855, 3840, 3855, 3871, 3903,
    7936, 7951, 7967, 7999, 16128, 16143, 16159, 16191,
};

const u16 flip_attr_tbl[4] = {
    0, 0x1000, 0x800, 0x1800,
};

const s16 judge_area_code_tbl[16] = {
    0, 0, 8, 8, 16, 16, 24, 48,
    32, 32, 40, 40, 60, 56, 58, 0,
};

const s16 zoom_down_tbl[64] = {
    0, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
};

const s16 zoom_up_tbl[64] = {
    0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3,
};

const s16 cell_zoom_tbl[252] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 7,
    8, 8, 8, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 9, 9, 9, 9,
    10, 10, 10, 10, 10, 10, 10, 10,
    11, 11, 11, 11, 11, 11, 11, 11,
    12, 12, 12, 12, 12, 12, 12, 12,
    13, 13, 13, 13, 13, 13, 13, 13,
    14, 14, 14, 14, 14, 14, 14, 14,
    15, 15, 15, 15, 15, 15, 15, 15,
    0, 0, 0, 0, 1, 1, 1, 1,
    2, 2, 2, 2, 3, 3, 3, 3,
    4, 4, 4, 4, 5, 5, 5, 5,
    6, 6, 6, 6, 7, 7, 7, 7,
    8, 8, 8, 8, 9, 9, 9, 9,
    10, 10, 10, 10, 11, 11, 11, 11,
    12, 12, 12, 12, 13, 13, 13, 13,
    14, 14, 14, 14, 15, 15, 15, 15,
    16, 16, 16, 16, 17, 17, 17, 17,
    18, 18, 18, 18, 19, 19, 19, 19,
    20, 20, 20, 20, 21, 21, 21, 21,
    22, 22, 22, 22, 23, 23, 23, 23,
    24, 24, 24, 24, 25, 25, 25, 25,
    26, 26, 26, 26, 27, 27, 27, 27,
    28, 28, 28, 28, 29, 29, 29, 29,
    30, 30, 30, 30,
};
