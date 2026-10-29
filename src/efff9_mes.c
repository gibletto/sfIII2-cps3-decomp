/*
 * EFFF9_MES.C  effect F9's message tables
 *
 * The message of each character in the four languages (effF9_mes_pt), each character's scene lists
 * (txt_no_00 ..: pl<NN>txt<M> in EFFF8.C) and the text number table that picks each character's first scene entry
 * (initialised work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const u16 efff9_no_scene[];
extern const u16 pl01txt1[];
extern const u16 pl02txt1[];
extern const u16 pl03txt1[];
extern const u16 pl04txt1[];
extern const u16 pl05txt1[];
extern const u16 pl06txt1[];
extern const u16 pl07txt1[];
extern const u16 pl08txt1[];
extern const u16 pl09txt1[];
extern const u16 pl11txt1[];
extern const u16 pl12txt1[];
extern const u16 pl13txt1[];
extern const u16 pl14txt1[];
extern const u16 pl16txt1[];
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
    efff9_no_scene, pl01txt1,
    &pl01txt1[14], &pl01txt1[18],
    &pl01txt1[24], &pl01txt1[28],
    &pl01txt1[36], &pl01txt1[42],
    &pl01txt1[44],
};
/* provisional name */
const u16* txt_no_02[5] = {
    efff9_no_scene, pl02txt1,
    &pl02txt1[6], &pl02txt1[12],
    &pl02txt1[16],
};
/* provisional name */
const u16* txt_no_03[10] = {
    efff9_no_scene, pl03txt1,
    &pl03txt1[4], &pl03txt1[8],
    &pl03txt1[16], &pl03txt1[24],
    &pl03txt1[30], &pl03txt1[34],
    &pl03txt1[38], &pl03txt1[42],
};
/* provisional name */
const u16* txt_no_10[10] = {
    efff9_no_scene, &pl03txt1[4],
    pl03txt1, &pl03txt1[8],
    &pl03txt1[16], &pl03txt1[24],
    &pl03txt1[34], &pl03txt1[30],
    &pl03txt1[38], &pl03txt1[42],
};
/* provisional name */
const u16* txt_no_04[6] = {
    efff9_no_scene, pl04txt1,
    &pl04txt1[8], &pl04txt1[12],
    &pl04txt1[16], &pl04txt1[24],
};
/* provisional name */
const u16* txt_no_05[7] = {
    efff9_no_scene, pl05txt1,
    &pl05txt1[4], &pl05txt1[10],
    &pl05txt1[14], &pl05txt1[28],
    &pl05txt1[30],
};
/* provisional name */
const u16* txt_no_06[9] = {
    efff9_no_scene, pl06txt1,
    &pl06txt1[6], &pl06txt1[18],
    &pl06txt1[26], &pl06txt1[34],
    &pl06txt1[42], &pl06txt1[50],
    &pl06txt1[58],
};
/* provisional name */
const u16* txt_no_07[11] = {
    efff9_no_scene, pl07txt1,
    &pl07txt1[2], &pl07txt1[18],
    &pl07txt1[20], &pl07txt1[22],
    &pl07txt1[24], &pl07txt1[28],
    &pl07txt1[32], &pl07txt1[34],
    &pl07txt1[38],
};
/* provisional name */
const u16* txt_no_08[5] = {
    efff9_no_scene, pl08txt1,
    &pl08txt1[8], &pl08txt1[12],
    &pl08txt1[18],
};
/* provisional name */
const u16* txt_no_09[6] = {
    efff9_no_scene, pl09txt1,
    &pl09txt1[4], &pl09txt1[8],
    &pl09txt1[10], &pl09txt1[14],
};
/* provisional name */
const u16* txt_no_11[7] = {
    efff9_no_scene, pl11txt1,
    &pl11txt1[6], &pl11txt1[10],
    &pl11txt1[14], &pl11txt1[16],
    &pl11txt1[20],
};
/* provisional name */
const u16* txt_no_12[6] = {
    efff9_no_scene, pl12txt1,
    &pl12txt1[4], &pl12txt1[14],
    &pl12txt1[18], &pl12txt1[22],
};
/* provisional name */
const u16* txt_no_13[5] = {
    efff9_no_scene, pl13txt1,
    &pl13txt1[6], &pl13txt1[12],
    &pl13txt1[22],
};
/* provisional name */
const u16* txt_no_14[6] = {
    efff9_no_scene, pl14txt1,
    &pl14txt1[4], &pl14txt1[10],
    &pl14txt1[14], &pl14txt1[20],
};
/* provisional name */
const u16* txt_no_15[2] = {
    efff9_no_scene, pl16txt1,
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
