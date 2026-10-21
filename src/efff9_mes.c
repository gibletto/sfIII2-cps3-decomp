/*
 * EFFF9_MES.C  effect F9's message tables
 *
 * The message of each character in the four languages and the text number table (initialised
 * work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const u16 EFFF8_0617CDC0[];
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
const EFFF9_MESSAGE* effF9_mes_pt[121] = {
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
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 4),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 32),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 40),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 52),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 60),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 76),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 88),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 92),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 104),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 116),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 128),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 136),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 144),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 152),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 160),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 176),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 192),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 204),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 212),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 220),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 228),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 152),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 144),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 160),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 176),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 192),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 212),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 204),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 220),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 228),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 240),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 256),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 264),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 272),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 288),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 300),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 308),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 320),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 328),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 356),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 360),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 372),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 384),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 408),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 424),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 440),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 456),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 472),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 488),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 504),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 508),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 540),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 544),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 548),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 552),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 560),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 568),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 572),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 580),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 600),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 616),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 624),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 636),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 640),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 648),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 656),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 660),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 668),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 680),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 692),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 700),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 708),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 712),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 720),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 728),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 736),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 756),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 764),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 772),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 780),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 792),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 804),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 824),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 848),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 856),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 868),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 876),
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 888),
    (const EFFF9_MESSAGE *)EFFF8_0617CDC0,
    (const EFFF9_MESSAGE *)((const u8*)EFFF8_0617CDC0 + 900),
};
/* the code declares txt_no_tbl[28]; effg0_judge_count starts after its first 17 entries */
/* 020083E8 */
s32* txt_no_tbl[17] = {
    (s32 *)((u8*)effF9_mes_pt + 68),
    (s32 *)((u8*)effF9_mes_pt + 68),
    (s32 *)((u8*)effF9_mes_pt + 104),
    (s32 *)((u8*)effF9_mes_pt + 124),
    (s32 *)((u8*)effF9_mes_pt + 204),
    (s32 *)((u8*)effF9_mes_pt + 228),
    (s32 *)((u8*)effF9_mes_pt + 256),
    (s32 *)((u8*)effF9_mes_pt + 292),
    (s32 *)((u8*)effF9_mes_pt + 336),
    (s32 *)((u8*)effF9_mes_pt + 356),
    (s32 *)((u8*)effF9_mes_pt + 164),
    (s32 *)((u8*)effF9_mes_pt + 380),
    (s32 *)((u8*)effF9_mes_pt + 408),
    (s32 *)((u8*)effF9_mes_pt + 432),
    (s32 *)((u8*)effF9_mes_pt + 452),
    (s32 *)((u8*)effF9_mes_pt + 476),
    (s32 *)((u8*)effF9_mes_pt + 476),
};
