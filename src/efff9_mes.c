/*
 * EFFF9_MES.C  effect F9's message tables
 *
 * The message of each character in the four languages, the characters' scene lists (efff9_scene_tbl)
 * and the text number table that picks each character's first scene (initialised work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const u16 efff9_scene_data[];
extern const u16 chr_data_06449C6E[];
extern const u16 chr_data_0644B946[];
extern const u16 chr_data_0644C07E[];
extern const u16 chr_data_0644C5FA[];
extern const u16 chr_data_0644C9C6[];
extern const u16 chr_data_0644D332[];
extern const u16 chr_data_0644D806[];
extern const u16 chr_data_0644E096[];
extern const u16 chr_data_0644E446[];
extern const u16 chr_data_06451ECA[];
extern const u16 chr_data_0645568A[];
extern const u16 chr_data_06455FCA[];
extern const u16 chr_data_0645677E[];
extern const u16 chr_data_064576DE[];
extern const u16 chr_data_06457DFA[];
extern const u16 chr_data_0645C41A[];
extern const u16 chr_data_0645DA7A[];
extern const u16 chr_data_0645FD42[];
extern const u16 chr_data_06460AD6[];
extern const u16 chr_data_0646142E[];
extern const u16 chr_data_06461BE6[];
extern const u16 chr_data_064627D2[];
extern const u16 chr_data_0646326A[];
extern const u16 chr_data_06464C52[];
extern const u16 chr_data_06466312[];
extern const u16 chr_data_06466F9E[];
extern const u16 chr_data_06469272[];
extern const u16 chr_data_0646C232[];
extern const u16 chr_data_0646D30E[];
extern const u16 chr_data_0646E996[];
extern const u16 chr_data_0652699E[];
extern const u32 chr_data_06448370[];
extern const u32 chr_data_06448EF4[];
extern const u32 chr_data_06449604[];
extern const u32 chr_data_0644A160[];
extern const u32 chr_data_0644A888[];
extern const u32 chr_data_0644D0A8[];
extern const u32 chr_data_0644FA5C[];
extern const u32 chr_data_06450640[];
extern const u32 chr_data_06451250[];
extern const u32 chr_data_06452908[];
extern const u32 chr_data_06454988[];
extern const u32 chr_data_0645738C[];
extern const u32 chr_data_06458FD4[];
extern const u32 chr_data_06459718[];
extern const u32 chr_data_0645ABE8[];
extern const u32 chr_data_0645B830[];
extern const u32 chr_data_0645D05C[];
extern const u32 chr_data_06462B08[];
extern const u32 chr_data_06464520[];
extern const u32 chr_data_06467BDC[];
extern const u32 chr_data_064687F4[];
extern const u32 chr_data_0646B4D4[];
extern const u32 chr_data_0646CBAC[];
extern const u32 chr_data_0646DF50[];
extern const u32 chr_data_0646E280[];
extern const u32 chr_data_0646FDC4[];
extern const u32 chr_data_06526170[];
extern const u32 chr_data_065263F0[];
extern const u32 chr_data_06526C04[];

extern const EFFF9_MESSAGE* effF9_mes_jp[];
extern const EFFF9_MESSAGE* effF9_mes_en[];
extern const EFFF9_MESSAGE* effF9_mes_es[];
extern const EFFF9_MESSAGE* effF9_mes_pt[];
extern s32* txt_no_tbl[];

/* 02008138 */
const EFFF9_MESSAGE* effF9_mes_jp[17] = {
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06448370 + 12),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06448370 + 12),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06448EF4 + 12),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06449604 + 16),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06449C6E + 14),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644A160 + 12),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644A888 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644B946 + 14),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644C07E + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644C5FA + 18),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644C9C6 + 14),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644D0A8 + 12),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644D332 + 14),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644D806 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644E096 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06526170 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0652699E + 6),
};
/* 0200817C */
const EFFF9_MESSAGE* effF9_mes_en[17] = {
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644E446 + 18),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644E446 + 18),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0644FA5C + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06450640 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06451250 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06451ECA + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06452908 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06454988 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645568A + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06455FCA + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645677E + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645738C + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_064576DE + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06457DFA + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06458FD4 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_065263F0 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06526C04 + 8),
};
/* 020081C0 */
const EFFF9_MESSAGE* effF9_mes_es[17] = {
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06459718 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06459718 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645ABE8 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645B830 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645C41A + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645D05C + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645DA7A + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0645FD42 + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06460AD6 + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646142E + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06461BE6 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_064627D2 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06462B08 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646326A + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06464520 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_065263F0 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06526C04 + 8),
};
/* 02008204 */
const EFFF9_MESSAGE* effF9_mes_pt[17] = {
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06464C52 + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06464C52 + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06466312 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06466F9E + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06467BDC + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_064687F4 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06469272 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646B4D4 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646C232 + 6),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646CBAC + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646D30E + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646DF50 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646E280 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646E996 + 10),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_0646FDC4 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_065263F0 + 8),
    (const EFFF9_MESSAGE *)((const u8*)chr_data_06526C04 + 8),
};
/* 02008248: each character's scenes, as lists of (message number, time) pairs in efff9_scene_data
   (txt_no_tbl gives each character's first; provisional name) */
const u16* efff9_scene_tbl[104] = {
    efff9_scene_data,
    efff9_scene_data + 2,
    efff9_scene_data + 16,
    efff9_scene_data + 20,
    efff9_scene_data + 26,
    efff9_scene_data + 30,
    efff9_scene_data + 38,
    efff9_scene_data + 44,
    efff9_scene_data + 46,
    efff9_scene_data,
    efff9_scene_data + 52,
    efff9_scene_data + 58,
    efff9_scene_data + 64,
    efff9_scene_data + 68,
    efff9_scene_data,
    efff9_scene_data + 72,
    efff9_scene_data + 76,
    efff9_scene_data + 80,
    efff9_scene_data + 88,
    efff9_scene_data + 96,
    efff9_scene_data + 102,
    efff9_scene_data + 106,
    efff9_scene_data + 110,
    efff9_scene_data + 114,
    efff9_scene_data,
    efff9_scene_data + 76,
    efff9_scene_data + 72,
    efff9_scene_data + 80,
    efff9_scene_data + 88,
    efff9_scene_data + 96,
    efff9_scene_data + 106,
    efff9_scene_data + 102,
    efff9_scene_data + 110,
    efff9_scene_data + 114,
    efff9_scene_data,
    efff9_scene_data + 120,
    efff9_scene_data + 128,
    efff9_scene_data + 132,
    efff9_scene_data + 136,
    efff9_scene_data + 144,
    efff9_scene_data,
    efff9_scene_data + 150,
    efff9_scene_data + 154,
    efff9_scene_data + 160,
    efff9_scene_data + 164,
    efff9_scene_data + 178,
    efff9_scene_data + 180,
    efff9_scene_data,
    efff9_scene_data + 186,
    efff9_scene_data + 192,
    efff9_scene_data + 204,
    efff9_scene_data + 212,
    efff9_scene_data + 220,
    efff9_scene_data + 228,
    efff9_scene_data + 236,
    efff9_scene_data + 244,
    efff9_scene_data,
    efff9_scene_data + 252,
    efff9_scene_data + 254,
    efff9_scene_data + 270,
    efff9_scene_data + 272,
    efff9_scene_data + 274,
    efff9_scene_data + 276,
    efff9_scene_data + 280,
    efff9_scene_data + 284,
    efff9_scene_data + 286,
    efff9_scene_data + 290,
    efff9_scene_data,
    efff9_scene_data + 300,
    efff9_scene_data + 308,
    efff9_scene_data + 312,
    efff9_scene_data + 318,
    efff9_scene_data,
    efff9_scene_data + 320,
    efff9_scene_data + 324,
    efff9_scene_data + 328,
    efff9_scene_data + 330,
    efff9_scene_data + 334,
    efff9_scene_data,
    efff9_scene_data + 340,
    efff9_scene_data + 346,
    efff9_scene_data + 350,
    efff9_scene_data + 354,
    efff9_scene_data + 356,
    efff9_scene_data + 360,
    efff9_scene_data,
    efff9_scene_data + 364,
    efff9_scene_data + 368,
    efff9_scene_data + 378,
    efff9_scene_data + 382,
    efff9_scene_data + 386,
    efff9_scene_data,
    efff9_scene_data + 390,
    efff9_scene_data + 396,
    efff9_scene_data + 402,
    efff9_scene_data + 412,
    efff9_scene_data,
    efff9_scene_data + 424,
    efff9_scene_data + 428,
    efff9_scene_data + 434,
    efff9_scene_data + 438,
    efff9_scene_data + 444,
    efff9_scene_data,
    efff9_scene_data + 450,
};
/* the code declares txt_no_tbl[28]; effg0_judge_count starts after its first 17 entries */
/* 020083E8 */
s32* txt_no_tbl[17] = {
    (s32 *)&efff9_scene_tbl[0],
    (s32 *)&efff9_scene_tbl[0],
    (s32 *)&efff9_scene_tbl[9],
    (s32 *)&efff9_scene_tbl[14],
    (s32 *)&efff9_scene_tbl[34],
    (s32 *)&efff9_scene_tbl[40],
    (s32 *)&efff9_scene_tbl[47],
    (s32 *)&efff9_scene_tbl[56],
    (s32 *)&efff9_scene_tbl[67],
    (s32 *)&efff9_scene_tbl[72],
    (s32 *)&efff9_scene_tbl[24],
    (s32 *)&efff9_scene_tbl[78],
    (s32 *)&efff9_scene_tbl[85],
    (s32 *)&efff9_scene_tbl[91],
    (s32 *)&efff9_scene_tbl[96],
    (s32 *)&efff9_scene_tbl[102],
    (s32 *)&efff9_scene_tbl[102],
};
