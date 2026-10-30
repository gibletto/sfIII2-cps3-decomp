/*
 * EFFF9_MES.C  effect F9's message tables
 *
 * The message of each character in the four languages (effF9_mes_pt), each character's scene lists
 * (txt_no_00 ..: the txt_no_NN_K lists in EFFF8.C) and the text number table that picks each character's first scene entry
 * (initialised work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const u16 plXXtxt0[];
extern const u16 txt_no_00_1[];
extern const u16 txt_no_00_2[];
extern const u16 txt_no_00_3[];
extern const u16 txt_no_00_4[];
extern const u16 txt_no_00_5[];
extern const u16 txt_no_00_6[];
extern const u16 txt_no_00_7[];
extern const u16 txt_no_00_8[];
extern const u16 txt_no_02_1[];
extern const u16 txt_no_02_2[];
extern const u16 txt_no_02_3[];
extern const u16 txt_no_02_4[];
extern const u16 txt_no_03_1[];
extern const u16 txt_no_03_2[];
extern const u16 txt_no_03_3[];
extern const u16 txt_no_03_4[];
extern const u16 txt_no_03_5[];
extern const u16 txt_no_03_6[];
extern const u16 txt_no_03_7[];
extern const u16 txt_no_03_8[];
extern const u16 txt_no_03_9[];
extern const u16 txt_no_04_1[];
extern const u16 txt_no_04_2[];
extern const u16 txt_no_04_3[];
extern const u16 txt_no_04_4[];
extern const u16 txt_no_04_5[];
extern const u16 txt_no_05_1[];
extern const u16 txt_no_05_2[];
extern const u16 txt_no_05_3[];
extern const u16 txt_no_05_4[];
extern const u16 txt_no_05_5[];
extern const u16 txt_no_05_6[];
extern const u16 txt_no_06_1[];
extern const u16 txt_no_06_2[];
extern const u16 txt_no_06_3[];
extern const u16 txt_no_06_4[];
extern const u16 txt_no_06_5[];
extern const u16 txt_no_06_6[];
extern const u16 txt_no_06_7[];
extern const u16 txt_no_06_8[];
extern const u16 txt_no_07_1[];
extern const u16 txt_no_07_2[];
extern const u16 txt_no_07_3[];
extern const u16 txt_no_07_4[];
extern const u16 txt_no_07_5[];
extern const u16 txt_no_07_6[];
extern const u16 txt_no_07_7[];
extern const u16 txt_no_07_8[];
extern const u16 txt_no_07_9[];
extern const u16 txt_no_07_10[];
extern const u16 txt_no_08_1[];
extern const u16 txt_no_08_2[];
extern const u16 txt_no_08_3[];
extern const u16 txt_no_08_4[];
extern const u16 txt_no_09_1[];
extern const u16 txt_no_09_2[];
extern const u16 txt_no_09_3[];
extern const u16 txt_no_09_4[];
extern const u16 txt_no_09_5[];
extern const u16 txt_no_11_1[];
extern const u16 txt_no_11_2[];
extern const u16 txt_no_11_3[];
extern const u16 txt_no_11_4[];
extern const u16 txt_no_11_5[];
extern const u16 txt_no_11_6[];
extern const u16 txt_no_12_1[];
extern const u16 txt_no_12_2[];
extern const u16 txt_no_12_3[];
extern const u16 txt_no_12_4[];
extern const u16 txt_no_12_5[];
extern const u16 txt_no_13_1[];
extern const u16 txt_no_13_2[];
extern const u16 txt_no_13_3[];
extern const u16 txt_no_13_4[];
extern const u16 txt_no_14_1[];
extern const u16 txt_no_14_2[];
extern const u16 txt_no_14_3[];
extern const u16 txt_no_14_4[];
extern const u16 txt_no_14_5[];
extern const u16 txt_no_15_1[];
extern const EFFF9_MESSAGE effF9_mes_en_0[];
extern const EFFF9_MESSAGE effF9_mes_en_10[];
extern const EFFF9_MESSAGE effF9_mes_en_11[];
extern const EFFF9_MESSAGE effF9_mes_en_12[];
extern const EFFF9_MESSAGE effF9_mes_en_13[];
extern const EFFF9_MESSAGE effF9_mes_en_14[];
extern const EFFF9_MESSAGE effF9_mes_en_15[];
extern const EFFF9_MESSAGE effF9_mes_en_16[];
extern const EFFF9_MESSAGE effF9_mes_en_2[];
extern const EFFF9_MESSAGE effF9_mes_en_3[];
extern const EFFF9_MESSAGE effF9_mes_en_4[];
extern const EFFF9_MESSAGE effF9_mes_en_5[];
extern const EFFF9_MESSAGE effF9_mes_en_6[];
extern const EFFF9_MESSAGE effF9_mes_en_7[];
extern const EFFF9_MESSAGE effF9_mes_en_8[];
extern const EFFF9_MESSAGE effF9_mes_en_9[];
extern const EFFF9_MESSAGE effF9_mes_es_0[];
extern const EFFF9_MESSAGE effF9_mes_es_10[];
extern const EFFF9_MESSAGE effF9_mes_es_11[];
extern const EFFF9_MESSAGE effF9_mes_es_12[];
extern const EFFF9_MESSAGE effF9_mes_es_13[];
extern const EFFF9_MESSAGE effF9_mes_es_14[];
extern const EFFF9_MESSAGE effF9_mes_es_2[];
extern const EFFF9_MESSAGE effF9_mes_es_3[];
extern const EFFF9_MESSAGE effF9_mes_es_4[];
extern const EFFF9_MESSAGE effF9_mes_es_5[];
extern const EFFF9_MESSAGE effF9_mes_es_6[];
extern const EFFF9_MESSAGE effF9_mes_es_7[];
extern const EFFF9_MESSAGE effF9_mes_es_8[];
extern const EFFF9_MESSAGE effF9_mes_es_9[];
extern const EFFF9_MESSAGE effF9_mes_jp_0[];
extern const EFFF9_MESSAGE effF9_mes_jp_10[];
extern const EFFF9_MESSAGE effF9_mes_jp_11[];
extern const EFFF9_MESSAGE effF9_mes_jp_12[];
extern const EFFF9_MESSAGE effF9_mes_jp_13[];
extern const EFFF9_MESSAGE effF9_mes_jp_14[];
extern const EFFF9_MESSAGE effF9_mes_jp_15[];
extern const EFFF9_MESSAGE effF9_mes_jp_16[];
extern const EFFF9_MESSAGE effF9_mes_jp_2[];
extern const EFFF9_MESSAGE effF9_mes_jp_3[];
extern const EFFF9_MESSAGE effF9_mes_jp_4[];
extern const EFFF9_MESSAGE effF9_mes_jp_5[];
extern const EFFF9_MESSAGE effF9_mes_jp_6[];
extern const EFFF9_MESSAGE effF9_mes_jp_7[];
extern const EFFF9_MESSAGE effF9_mes_jp_8[];
extern const EFFF9_MESSAGE effF9_mes_jp_9[];
extern const EFFF9_MESSAGE effF9_mes_pt_0[];
extern const EFFF9_MESSAGE effF9_mes_pt_10[];
extern const EFFF9_MESSAGE effF9_mes_pt_11[];
extern const EFFF9_MESSAGE effF9_mes_pt_12[];
extern const EFFF9_MESSAGE effF9_mes_pt_13[];
extern const EFFF9_MESSAGE effF9_mes_pt_14[];
extern const EFFF9_MESSAGE effF9_mes_pt_2[];
extern const EFFF9_MESSAGE effF9_mes_pt_3[];
extern const EFFF9_MESSAGE effF9_mes_pt_4[];
extern const EFFF9_MESSAGE effF9_mes_pt_5[];
extern const EFFF9_MESSAGE effF9_mes_pt_6[];
extern const EFFF9_MESSAGE effF9_mes_pt_7[];
extern const EFFF9_MESSAGE effF9_mes_pt_8[];
extern const EFFF9_MESSAGE effF9_mes_pt_9[];

extern const EFFF9_MESSAGE* effF9_mes_jp[];
extern const EFFF9_MESSAGE* effF9_mes_en[];
extern const EFFF9_MESSAGE* effF9_mes_es[];
extern const EFFF9_MESSAGE* effF9_mes_pt[];
extern const u16* txt_no_00[];
extern const u16* txt_no_02[];
extern const u16* txt_no_03[];
extern const u16* txt_no_10[];
extern const u16* txt_no_04[];
extern const u16* txt_no_05[];
extern const u16* txt_no_06[];
extern const u16* txt_no_07[];
extern const u16* txt_no_08[];
extern const u16* txt_no_09[];
extern const u16* txt_no_11[];
extern const u16* txt_no_12[];
extern const u16* txt_no_13[];
extern const u16* txt_no_14[];
extern const u16* txt_no_15[];
extern const u16** txt_no_tbl[];

/* 02008138 */
const EFFF9_MESSAGE* effF9_mes_jp[17] = {
    effF9_mes_jp_0,
    effF9_mes_jp_0,
    effF9_mes_jp_2,
    effF9_mes_jp_3,
    effF9_mes_jp_4,
    effF9_mes_jp_5,
    effF9_mes_jp_6,
    effF9_mes_jp_7,
    effF9_mes_jp_8,
    effF9_mes_jp_9,
    effF9_mes_jp_10,
    effF9_mes_jp_11,
    effF9_mes_jp_12,
    effF9_mes_jp_13,
    effF9_mes_jp_14,
    effF9_mes_jp_15,
    effF9_mes_jp_16,
};
/* 0200817C */
const EFFF9_MESSAGE* effF9_mes_en[17] = {
    effF9_mes_en_0,
    effF9_mes_en_0,
    effF9_mes_en_2,
    effF9_mes_en_3,
    effF9_mes_en_4,
    effF9_mes_en_5,
    effF9_mes_en_6,
    effF9_mes_en_7,
    effF9_mes_en_8,
    effF9_mes_en_9,
    effF9_mes_en_10,
    effF9_mes_en_11,
    effF9_mes_en_12,
    effF9_mes_en_13,
    effF9_mes_en_14,
    effF9_mes_en_15,
    effF9_mes_en_16,
};
/* 020081C0 */
const EFFF9_MESSAGE* effF9_mes_es[17] = {
    effF9_mes_es_0,
    effF9_mes_es_0,
    effF9_mes_es_2,
    effF9_mes_es_3,
    effF9_mes_es_4,
    effF9_mes_es_5,
    effF9_mes_es_6,
    effF9_mes_es_7,
    effF9_mes_es_8,
    effF9_mes_es_9,
    effF9_mes_es_10,
    effF9_mes_es_11,
    effF9_mes_es_12,
    effF9_mes_es_13,
    effF9_mes_es_14,
    effF9_mes_en_15,
    effF9_mes_en_16,
};
/* 02008204 */
const EFFF9_MESSAGE* effF9_mes_pt[17] = {
    effF9_mes_pt_0,
    effF9_mes_pt_0,
    effF9_mes_pt_2,
    effF9_mes_pt_3,
    effF9_mes_pt_4,
    effF9_mes_pt_5,
    effF9_mes_pt_6,
    effF9_mes_pt_7,
    effF9_mes_pt_8,
    effF9_mes_pt_9,
    effF9_mes_pt_10,
    effF9_mes_pt_11,
    effF9_mes_pt_12,
    effF9_mes_pt_13,
    effF9_mes_pt_14,
    effF9_mes_en_15,
    effF9_mes_en_16,
};
/* provisional name */
const u16* txt_no_00[9] = {
    plXXtxt0, txt_no_00_1,
    txt_no_00_2, txt_no_00_3,
    txt_no_00_4, txt_no_00_5,
    txt_no_00_6, txt_no_00_7,
    txt_no_00_8,
};
/* provisional name */
const u16* txt_no_02[5] = {
    plXXtxt0, txt_no_02_1,
    txt_no_02_2, txt_no_02_3,
    txt_no_02_4,
};
/* provisional name */
const u16* txt_no_03[10] = {
    plXXtxt0, txt_no_03_1,
    txt_no_03_2, txt_no_03_3,
    txt_no_03_4, txt_no_03_5,
    txt_no_03_6, txt_no_03_7,
    txt_no_03_8, txt_no_03_9,
};
/* provisional name */
const u16* txt_no_10[10] = {
    plXXtxt0, txt_no_03_2,
    txt_no_03_1, txt_no_03_3,
    txt_no_03_4, txt_no_03_5,
    txt_no_03_7, txt_no_03_6,
    txt_no_03_8, txt_no_03_9,
};
/* provisional name */
const u16* txt_no_04[6] = {
    plXXtxt0, txt_no_04_1,
    txt_no_04_2, txt_no_04_3,
    txt_no_04_4, txt_no_04_5,
};
/* provisional name */
const u16* txt_no_05[7] = {
    plXXtxt0, txt_no_05_1,
    txt_no_05_2, txt_no_05_3,
    txt_no_05_4, txt_no_05_5,
    txt_no_05_6,
};
/* provisional name */
const u16* txt_no_06[9] = {
    plXXtxt0, txt_no_06_1,
    txt_no_06_2, txt_no_06_3,
    txt_no_06_4, txt_no_06_5,
    txt_no_06_6, txt_no_06_7,
    txt_no_06_8,
};
/* provisional name */
const u16* txt_no_07[11] = {
    plXXtxt0, txt_no_07_1,
    txt_no_07_2, txt_no_07_3,
    txt_no_07_4, txt_no_07_5,
    txt_no_07_6, txt_no_07_7,
    txt_no_07_8, txt_no_07_9,
    txt_no_07_10,
};
/* provisional name */
const u16* txt_no_08[5] = {
    plXXtxt0, txt_no_08_1,
    txt_no_08_2, txt_no_08_3,
    txt_no_08_4,
};
/* provisional name */
const u16* txt_no_09[6] = {
    plXXtxt0, txt_no_09_1,
    txt_no_09_2, txt_no_09_3,
    txt_no_09_4, txt_no_09_5,
};
/* provisional name */
const u16* txt_no_11[7] = {
    plXXtxt0, txt_no_11_1,
    txt_no_11_2, txt_no_11_3,
    txt_no_11_4, txt_no_11_5,
    txt_no_11_6,
};
/* provisional name */
const u16* txt_no_12[6] = {
    plXXtxt0, txt_no_12_1,
    txt_no_12_2, txt_no_12_3,
    txt_no_12_4, txt_no_12_5,
};
/* provisional name */
const u16* txt_no_13[5] = {
    plXXtxt0, txt_no_13_1,
    txt_no_13_2, txt_no_13_3,
    txt_no_13_4,
};
/* provisional name */
const u16* txt_no_14[6] = {
    plXXtxt0, txt_no_14_1,
    txt_no_14_2, txt_no_14_3,
    txt_no_14_4, txt_no_14_5,
};
/* provisional name */
const u16* txt_no_15[2] = {
    plXXtxt0, txt_no_15_1,
};
/* the code declares txt_no_tbl[28]; effg0_judge_count starts after its first 17 entries */
/* 020083E8 */
const u16** txt_no_tbl[17] = {
    txt_no_00, txt_no_00, txt_no_02, txt_no_03,
    txt_no_04, txt_no_05, txt_no_06, txt_no_07,
    txt_no_08, txt_no_09, txt_no_10, txt_no_11,
    txt_no_12, txt_no_13, txt_no_14, txt_no_15,
    txt_no_15,
};
