/*
 * EFFC0_TBL.C  damage state 25 effect and landing stage object tables
 *
 * plhos_data gives, for each character, the offset from the player and the pattern of the
 * effect, and hok_table_ef the extra animation steps per frame by how hard the player mashes;
 * read by EFFC0.C, the animation attached to a player in damage state 25. effc2_data_tbl gives
 * the x, y, priority and pattern of the four stage objects that drop on the landing; read by
 * EFFC2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 hok_table_ef[];
extern const s16 plhos_data[][3];
extern const s16 effc2_data_tbl[][4];

const s16 hok_table_ef[8] = {
    1, 1, 2, 2, 3, 3, 3, 3,
};

/*
 * One row per character (player_number): x offset in front of the player (mirrored by
 * rl_flag), y offset and animation number.
 */
const s16 plhos_data[16][3] = {
    { 2, 136, 4 },  /* Gill */
    { 40, 92, 3 },  /* Alex */
    { -4, 104, 2 },  /* Ryu */
    { 2, 92, 5 },  /* Yun */
    { 40, 88, 5 },  /* Dudley */
    { 8, 94, 2 },  /* Necro */
    { 8, 106, 2 },  /* Hugo */
    { 20, 78, 2 },  /* Ibuki */
    { 30, 96, 2 },  /* Elena */
    { 10, 88, 3 },  /* Oro */
    { 2, 92, 5 },  /* Yang */
    { -4, 104, 2 },  /* Ken */
    { -4, 104, 5 },  /* Sean */
    { 2, 136, 4 },  /* Urien */
    { -4, 104, 2 },  /* Gouki */
    { -4, 104, 2 },  /* Shin Gouki */
};

/* provisional name */
const s16 effc2_data_tbl[4][4] = {
    { 784, 32, 20, 8 },
    { 720, 64, 77, 9 },
    { 240, 32, 20, 10 },
    { 304, 64, 77, 11 },
};
