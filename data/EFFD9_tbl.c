/*
 * EFFD9_TBL.C  palette change, opponent select plate and flame position tables
 *
 * color_table_index has seven entries { end-condition flags, timer, 1P table, 2P table }; the
 * entry number is given when effect D9 is started. coltbl_000_1P and coltbl_000_2P (and slices
 * of it, the last running on into coltbl_008_2P) are the colour steps, { frames, colour }
 * pairs ending with 0, that the effect cycles through the player's extra colour. Read by
 * EFFD9.C, the palette change controller. effE0_x_tbl and effE0_delay_tbl give the x position
 * and slide-in delay of the eight stage plates on the opponent select screen (EFFE0.C);
 * effE0_delay_tbl_tail is not referred to by name. flames_stand is the flame pieces of a
 * standing player, read by EFFE2.C with the tables of EFFE2_TBL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 coltbl_000_1P[];
extern const s16 coltbl_000_2P[];
extern const s16 coltbl_008_2P[];
extern const ColorTableIndex color_table_index[];
extern const s16 effE0_x_tbl[];
extern const s16 effE0_delay_tbl[];
extern const u16 effE0_delay_tbl_tail[];
extern const u16 flames_stand[];

const s16 coltbl_000_1P[10] = {
    1, 8192, 2, 8193, 1, 8195, 2, 8193,
    0, 0,
};

const s16 coltbl_000_2P[78] = {
    1, 8208, 2, 8209, 1, 8211, 2, 8209,
    0, 0, 2, 8192, 2, 8194, 0, 0,
    2, 8208, 2, 8210, 0, 0, 999, 8195,
    0, 0, 999, 8211, 0, 0, 2, 8192,
    2, 8193, 0, 0, 2, 8208, 2, 8209,
    0, 0, 2, 8192, 2, 8196, 0, 0,
    2, 8208, 2, 8212, 0, 0, 1, 8318,
    2, 8192, 0, 0, 1, 8319, 2, 8208,
    0, 0, 2, 8192, 2, 8371, 2, 8192,
    2, 8374, 0, 0, 2, 8208,
};

const s16 coltbl_008_2P[8] = {
    2, 8379, 2, 8208, 2, 8382, 0, 0,
};

const ColorTableIndex color_table_index[7] = {
    { 8, 0, (void *)coltbl_000_1P, (void *)coltbl_000_2P },
    { 7, 24, (void *)&coltbl_000_2P[30], (void *)&coltbl_000_2P[36] },
    { 7, 30, (void *)&coltbl_000_2P[10], (void *)&coltbl_000_2P[16] },
    { 5, 0, (void *)&coltbl_000_2P[22], (void *)&coltbl_000_2P[26] },
    { 7, 18, (void *)&coltbl_000_2P[42], (void *)&coltbl_000_2P[48] },
    { 18, 24, (void *)&coltbl_000_2P[54], (void *)&coltbl_000_2P[60] },
    { 17, 24, (void *)&coltbl_000_2P[66], (void *)&coltbl_000_2P[76] },
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
/* Stored after effE0_delay_tbl. Nothing in the program refers to it by name or address. */
const u16 effE0_delay_tbl_tail[8] = {
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
