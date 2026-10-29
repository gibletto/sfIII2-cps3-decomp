/*
 * END_MAIN_TBL2.C  ending background tables
 *
 * Indexed by the ending's character number: end_bg_index_tbl picks the ending's background,
 * whose scroll graphics source and size are in end_bg_gfx_tbl, and end_scno_tbl gives its
 * number of BG layers; read by END_MAIN_C.C. end_cg_src_tbl holds the screen data of the
 * ending backgrounds, and end_map_data_0 .. 3 are the layout records of the four ending BG
 * layers, which end_map_tbl in OP_END_WORK.C points at for sprite_list_setup.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 end_scno_tbl[];
extern const s16 end_bg_index_tbl[];
extern const END_BG_GFX end_bg_gfx_tbl[];
extern const u32 end_cg_src_tbl[];
extern const s16 end_map_data_0[];
extern const s16 end_map_data_1[];
extern const s16 end_map_data_2[];
extern const s16 end_map_data_3[];
extern const u16 end_100_scrn_data[152][32];
extern const u16 end_1100_scrn_data[20][16][32];
extern const u16 end_1200_scrn_data[3][16][32];
extern const u16 end_1300_scrn_data[9][16][32];
extern const u16 end_200_scrn_data[5][16][32];
extern const u16 end_300_scrn_data[16][16][32];
extern const u16 end_500_scrn_data[19][16][32];
extern const u16 end_600_scrn_data[11][16][32];
extern const u16 end_900_scrn_data[8][16][32];
extern const u16 end_scrn_data[95][16][32];

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

const u32 end_cg_src_tbl[11] = {
    (u32)end_100_scrn_data, (u32)end_100_scrn_data, (u32)end_200_scrn_data, (u32)end_scrn_data,
    (u32)end_500_scrn_data, (u32)end_900_scrn_data, (u32)end_1100_scrn_data, (u32)end_600_scrn_data,
    (u32)end_300_scrn_data, (u32)end_1200_scrn_data, (u32)end_1300_scrn_data,
};

/* provisional name */
const s16 end_map_data_0[28] = {
    /* [0] */
    1, 84,  0x7F, 0x3F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* provisional name */
const s16 end_map_data_1[28] = {
    /* [0] */
    2, 94,  0x7F, 0x3F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  0x27F, 0x7F00, 28,
           0x2FF, 0x7F00, 28,  0x37F, 0x7F00, 28,  0x3FF, 0x7F00, 28,  -1,
    -1,
};

/* provisional name */
const s16 end_map_data_2[28] = {
    /* [0] */
    3, 104,  0x7F, 0x3F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  0x27F, 0x7F00, 44,
           0x2FF, 0x7F00, 44,  0x37F, 0x7F00, 44,  0x3FF, 0x7F00, 44,  -1,
    -1,
};

/* provisional name */
const s16 end_map_data_3[28] = {
    /* [0] */
    4, 114,  0x7F, 0x3F00, 60,  0xFF, 0x7F00, 60,  0x17F, 0x7F00, 60,  0x1FF, 0x7F00, 60,  0x27F, 0x7F00, 60,
           0x2FF, 0x7F00, 60,  0x37F, 0x7F00, 60,  0x3FF, 0x7F00, 60,  -1,
    -1,
};
