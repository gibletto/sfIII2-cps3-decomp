/*
 * BG_DATA.C  tables read by bg000.c: stage background setup and stages BG000-BG030
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 bg_index_tbl[][3];
extern const s16 bg_index_tbl_tail[];
extern const u32 etc_bg_pos_tbl[];
extern const u8 ake_cell2_data[];
extern const u8 frt_tick_count[];

const s16 bg_index_tbl[18][3] = {
    { 0, 0, 0 },
    { 1, 1, 1 },
    { 2, 2, 2 },
    { 3, 3, 3 },
    { 4, 4, 4 },
    { 5, 5, 5 },
    { 6, 6, 6 },
    { 7, 7, 7 },
    { 8, 9, 9 },
    { 10, 10, 10 },
    { 11, 11, 11 },
    { 12, 12, 12 },
    { 13, 13, 13 },
    { 14, 14, 14 },
    { 15, 15, 15 },
    { 15, 15, 15 },
    { 16, 16, 16 },
    { 17, 17, 17 },
};

const s16 bg_index_tbl_tail[30] = {
    256, 256, 312, 0, 0, 0, 256, 256,
    312, 0, 0, 0, 256, 256, 312, 0,
    0, 0, 256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
};

/* provisional name */
const u32 etc_bg_pos_tbl[82] = {
    (u32)frt_tick_count, 0xFFD00000, (u32)frt_tick_count, 0,
    0, 0, 0, 0,
    0x1D80000, 0, (u32)frt_tick_count, 0,
    0, 0, 0, 0,
    (u32)frt_tick_count, 0, (u32)frt_tick_count, 0,
    0, 0, 0, 0,
    (u32)frt_tick_count, 0, (u32)frt_tick_count, 0,
    0, 0, 0, 0,
    (u32)frt_tick_count, 0, (u32)frt_tick_count, 0,
    0, 0, 0, 0,
    0x1E0014, 0xE0000, (u32)((const u8 *)ake_cell2_data + 64), 0x1E0015,
    0xE0000, (u32)((const u8 *)ake_cell2_data + 80), 0x1E0016, 0xE0000,
    (u32)((const u8 *)ake_cell2_data + 96), 0x1E0017, 0xE0000, (u32)((const u8 *)ake_cell2_data + 112),
    0x1E0018, 0xE0000, (u32)((const u8 *)ake_cell2_data + 128), 0x1E0019,
    0xE0000, (u32)((const u8 *)ake_cell2_data + 144), 0x1E001A, 0xE0000,
    (u32)((const u8 *)ake_cell2_data + 160), 0x1E001B, 0xE0000, (u32)((const u8 *)ake_cell2_data + 176),
    0x30016, 0xE0000, (u32)((const u8 *)ake_cell2_data + 192), 0x30017,
    0xE0000, (u32)((const u8 *)ake_cell2_data + 204), 0x30018, 0xE0000,
    (u32)((const u8 *)ake_cell2_data + 216), 0x30019, 0xE0000, (u32)((const u8 *)ake_cell2_data + 228),
    0x30013, 0xE0000, (u32)((const u8 *)ake_cell2_data + 236), 0x30014,
    0xE0000, (u32)((const u8 *)ake_cell2_data + 248),
};
