/*
 * END_MAIN_TBL2.C  ending background tables
 *
 * Indexed by the ending's character number: end_bg_index_tbl picks the ending's background,
 * whose scroll graphics source and size are in end_bg_gfx_tbl, and end_scno_tbl gives its
 * number of BG layers; read by END_MAIN_C.C. end_cg_src_tbl holds the screen data of the
 * ending backgrounds, followed by the four layer layout records that end_map_tbl in
 * OP_END_WORK.C points at for sprite_list_setup.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 end_scno_tbl[];
extern const s16 end_bg_index_tbl[];
extern const END_BG_GFX end_bg_gfx_tbl[];
extern const u32 end_cg_src_tbl[];
extern const u32 end_100_scrn_data[];
extern const u32 end_1100_scrn_data[];
extern const u32 end_1200_scrn_data[];
extern const u32 end_1300_scrn_data[];
extern const u32 end_200_scrn_data[];
extern const u32 end_300_scrn_data[];
extern const u32 end_500_scrn_data[];
extern const u32 end_600_scrn_data[];
extern const u32 end_900_scrn_data[];
extern const u32 end_scrn_data[];

const s16 end_scno_tbl[16] = {
    0, 2, 2, 2, 2, 2, 2, 2,
    3, 1, 2, 2, 3, 2, 2, 2,
};

const s16 end_bg_index_tbl[16] = {
    0, 1, 2, 8, 3, 4, 7, 3,
    3, 5, 8, 3, 6, 9, 10, 10,
};

const END_BG_GFX end_bg_gfx_tbl[11] = {
    { 0, 0, 0 },
    { 0x128F500, 10831, 0x128F580 },
    { 0x1299500, 9215, 0x1299580 },
    { 0x12AFD00, 92143, 0x12AFD80 },
    { 0x12A0D00, 14159, 0x12A0D80 },
    { 0x12AB500, 7903, 0x12AB580 },
    { 0x1240000, 19679, 0x1240080 },
    { 0x1373D00, 13215, 0x1373D80 },
    { 0x133FD00, 22319, 0x133FD80 },
    { 0x135BD00, 14175, 0x135BD80 },
    { 0x1327D00, 13279, 0x1327D80 },
};

const u32 end_cg_src_tbl[67] = {
    (u32)end_100_scrn_data, (u32)end_100_scrn_data, (u32)end_200_scrn_data, (u32)end_scrn_data,
    (u32)end_500_scrn_data, (u32)end_900_scrn_data, (u32)end_1100_scrn_data, (u32)end_600_scrn_data,
    (u32)end_300_scrn_data, (u32)end_1200_scrn_data, (u32)end_1300_scrn_data, 0x10054,
    0x7F3F00, 0xC00FF, 0x7F00000C, 0x17F7F00,
    0xC01FF, 0x7F00000C, 0x27F7F00, 0xC02FF,
    0x7F00000C, 0x37F7F00, 0xC03FF, 0x7F00000C,
    0xFFFFFFFF, 0x2005E, 0x7F3F00, 0x1C00FF,
    0x7F00001C, 0x17F7F00, 0x1C01FF, 0x7F00001C,
    0x27F7F00, 0x1C02FF, 0x7F00001C, 0x37F7F00,
    0x1C03FF, 0x7F00001C, 0xFFFFFFFF, 0x30068,
    0x7F3F00, 0x2C00FF, 0x7F00002C, 0x17F7F00,
    0x2C01FF, 0x7F00002C, 0x27F7F00, 0x2C02FF,
    0x7F00002C, 0x37F7F00, 0x2C03FF, 0x7F00002C,
    0xFFFFFFFF, 0x40072, 0x7F3F00, 0x3C00FF,
    0x7F00003C, 0x17F7F00, 0x3C01FF, 0x7F00003C,
    0x27F7F00, 0x3C02FF, 0x7F00003C, 0x37F7F00,
    0x3C03FF, 0x7F00003C, 0xFFFFFFFF,
};
