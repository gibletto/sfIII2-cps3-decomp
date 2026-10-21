/*
 * EFFD9_TBL.C  tables read by effects D9, E0 and E2
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 coltbl_000_1P[];
extern const s16 coltbl_000_2P[];
extern const s16 EFFD9_tbl_0617AF20[];
extern const s16 coltbl_008_2P[];
extern const ColorTableIndex color_table_index[];
extern const s16 effE0_x_tbl[];
extern const s16 effE0_delay_tbl[];
extern const u16 EFFD9_tbl_0617B02C[];
extern const u16 flames_stand[];

const s16 coltbl_000_1P[10] = {
    1, 8192, 2, 8193, 1, 8195, 2, 8193,
    0, 0,
};

const s16 coltbl_000_2P[10] = {
    1, 8208, 2, 8209, 1, 8211, 2, 8209,
    0, 0,
};

/* provisional name */
const s16 EFFD9_tbl_0617AF20[68] = {
    2, 8192, 2, 8194, 0, 0, 2, 8208,
    2, 8210, 0, 0, 999, 8195, 0, 0,
    999, 8211, 0, 0, 2, 8192, 2, 8193,
    0, 0, 2, 8208, 2, 8209, 0, 0,
    2, 8192, 2, 8196, 0, 0, 2, 8208,
    2, 8212, 0, 0, 1, 8318, 2, 8192,
    0, 0, 1, 8319, 2, 8208, 0, 0,
    2, 8192, 2, 8371, 2, 8192, 2, 8374,
    0, 0, 2, 8208,
};

const s16 coltbl_008_2P[8] = {
    2, 8379, 2, 8208, 2, 8382, 0, 0,
};

const ColorTableIndex color_table_index[7] = {
    { 8, 0, (void *)coltbl_000_1P, (void *)coltbl_000_2P },
    { 7, 24, (void *)((const u8 *)EFFD9_tbl_0617AF20 + 40), (void *)((const u8 *)EFFD9_tbl_0617AF20 + 52) },
    { 7, 30, (void *)EFFD9_tbl_0617AF20, (void *)((const u8 *)EFFD9_tbl_0617AF20 + 12) },
    { 5, 0, (void *)((const u8 *)EFFD9_tbl_0617AF20 + 24), (void *)((const u8 *)EFFD9_tbl_0617AF20 + 32) },
    { 7, 18, (void *)((const u8 *)EFFD9_tbl_0617AF20 + 64), (void *)((const u8 *)EFFD9_tbl_0617AF20 + 76) },
    { 18, 24, (void *)((const u8 *)EFFD9_tbl_0617AF20 + 88), (void *)((const u8 *)EFFD9_tbl_0617AF20 + 100) },
    { 17, 24, (void *)((const u8 *)EFFD9_tbl_0617AF20 + 112), (void *)((const u8 *)EFFD9_tbl_0617AF20 + 132) },
};

/* provisional name */
const s16 effE0_x_tbl[8] = {
    -138, -98, -58, -18, 18, 58, 98, 138,
};

/* provisional name */
const s16 effE0_delay_tbl[8] = {
    1, 3, 5, 7, 7, 5, 3, 1,
};

/* provisional name */
const u16 EFFD9_tbl_0617B02C[8] = {
    1, 1, 1, 1, 1, 1, 1, 1,
};

const u16 flames_stand[256] = {
    1, 0xFFE0, 0xFFF0, 0x12, 1, 0x10, 0x10, 0x39,
    3, 0x10, 0x18, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x20, 0xFFF0, 0x39, 2, 0, 0, 0x12,
    3, 0x20, 8, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 0xC, 0x12, 3, 0xFFF0, 8, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x10, 8, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x20, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 8, 0x12, 3, 0xFFF0, 0x14, 0x12,
    1, 0, 0xFFF0, 0x39, 3, 0xFFE0, 0x18, 0x12,
    3, 0xFFF0, 0x10, 0x12, 3, 0x10, 8, 0x12,
    1, 0x20, 0xFFF0, 0x39, 2, 0, 0, 0x12,
    3, 0x20, 8, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 0xC, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0xFFEC, 0x10, 0x12, 3, 0x10, 8, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0xFFF0, 8, 0x12, 3, 0x18, 0xC, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x10, 8, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 0xC, 0x12, 3, 0xFFF0, 8, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 0xC, 0x12, 3, 0xFFF0, 8, 0x12,
    1, 0xFFE0, 0xFFF0, 0x12, 1, 0x10, 0x10, 0x39,
    3, 0x10, 0x18, 0x12, 3, 0xFFF0, 0x10, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 0xC, 0x12, 3, 0xFFF0, 8, 0x12,
    1, 0x10, 0xFFF0, 0x39, 0, 0, 0, 0,
    3, 0x18, 0xC, 0x12, 3, 0xFFF0, 8, 0x12,
};
