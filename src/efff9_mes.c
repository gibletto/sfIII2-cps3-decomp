/*
 * EFFF9_MES.C  effect F9's message tables
 *
 * The message of each character in the four languages (effF9_mes_pt continues with each character's scene
 * lists, pl<NN>txt<M> in EFFF8.C) and the text number table that picks each character's first scene entry
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
extern s32* txt_no_tbl[];

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
const EFFF9_MESSAGE* effF9_mes_pt[121] = {
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
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl01txt1,
    (const EFFF9_MESSAGE*)&pl01txt1[14],
    (const EFFF9_MESSAGE*)&pl01txt1[18],
    (const EFFF9_MESSAGE*)&pl01txt1[24],
    (const EFFF9_MESSAGE*)&pl01txt1[28],
    (const EFFF9_MESSAGE*)&pl01txt1[36],
    (const EFFF9_MESSAGE*)&pl01txt1[42],
    (const EFFF9_MESSAGE*)&pl01txt1[44],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl02txt1,
    (const EFFF9_MESSAGE*)&pl02txt1[6],
    (const EFFF9_MESSAGE*)&pl02txt1[12],
    (const EFFF9_MESSAGE*)&pl02txt1[16],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl03txt1,
    (const EFFF9_MESSAGE*)&pl03txt1[4],
    (const EFFF9_MESSAGE*)&pl03txt1[8],
    (const EFFF9_MESSAGE*)&pl03txt1[16],
    (const EFFF9_MESSAGE*)&pl03txt1[24],
    (const EFFF9_MESSAGE*)&pl03txt1[30],
    (const EFFF9_MESSAGE*)&pl03txt1[34],
    (const EFFF9_MESSAGE*)&pl03txt1[38],
    (const EFFF9_MESSAGE*)&pl03txt1[42],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)&pl03txt1[4],
    (const EFFF9_MESSAGE*)pl03txt1,
    (const EFFF9_MESSAGE*)&pl03txt1[8],
    (const EFFF9_MESSAGE*)&pl03txt1[16],
    (const EFFF9_MESSAGE*)&pl03txt1[24],
    (const EFFF9_MESSAGE*)&pl03txt1[34],
    (const EFFF9_MESSAGE*)&pl03txt1[30],
    (const EFFF9_MESSAGE*)&pl03txt1[38],
    (const EFFF9_MESSAGE*)&pl03txt1[42],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl04txt1,
    (const EFFF9_MESSAGE*)&pl04txt1[8],
    (const EFFF9_MESSAGE*)&pl04txt1[12],
    (const EFFF9_MESSAGE*)&pl04txt1[16],
    (const EFFF9_MESSAGE*)&pl04txt1[24],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl05txt1,
    (const EFFF9_MESSAGE*)&pl05txt1[4],
    (const EFFF9_MESSAGE*)&pl05txt1[10],
    (const EFFF9_MESSAGE*)&pl05txt1[14],
    (const EFFF9_MESSAGE*)&pl05txt1[28],
    (const EFFF9_MESSAGE*)&pl05txt1[30],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl06txt1,
    (const EFFF9_MESSAGE*)&pl06txt1[6],
    (const EFFF9_MESSAGE*)&pl06txt1[18],
    (const EFFF9_MESSAGE*)&pl06txt1[26],
    (const EFFF9_MESSAGE*)&pl06txt1[34],
    (const EFFF9_MESSAGE*)&pl06txt1[42],
    (const EFFF9_MESSAGE*)&pl06txt1[50],
    (const EFFF9_MESSAGE*)&pl06txt1[58],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl07txt1,
    (const EFFF9_MESSAGE*)&pl07txt1[2],
    (const EFFF9_MESSAGE*)&pl07txt1[18],
    (const EFFF9_MESSAGE*)&pl07txt1[20],
    (const EFFF9_MESSAGE*)&pl07txt1[22],
    (const EFFF9_MESSAGE*)&pl07txt1[24],
    (const EFFF9_MESSAGE*)&pl07txt1[28],
    (const EFFF9_MESSAGE*)&pl07txt1[32],
    (const EFFF9_MESSAGE*)&pl07txt1[34],
    (const EFFF9_MESSAGE*)&pl07txt1[38],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl08txt1,
    (const EFFF9_MESSAGE*)&pl08txt1[8],
    (const EFFF9_MESSAGE*)&pl08txt1[12],
    (const EFFF9_MESSAGE*)&pl08txt1[18],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl09txt1,
    (const EFFF9_MESSAGE*)&pl09txt1[4],
    (const EFFF9_MESSAGE*)&pl09txt1[8],
    (const EFFF9_MESSAGE*)&pl09txt1[10],
    (const EFFF9_MESSAGE*)&pl09txt1[14],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl11txt1,
    (const EFFF9_MESSAGE*)&pl11txt1[6],
    (const EFFF9_MESSAGE*)&pl11txt1[10],
    (const EFFF9_MESSAGE*)&pl11txt1[14],
    (const EFFF9_MESSAGE*)&pl11txt1[16],
    (const EFFF9_MESSAGE*)&pl11txt1[20],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl12txt1,
    (const EFFF9_MESSAGE*)&pl12txt1[4],
    (const EFFF9_MESSAGE*)&pl12txt1[14],
    (const EFFF9_MESSAGE*)&pl12txt1[18],
    (const EFFF9_MESSAGE*)&pl12txt1[22],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl13txt1,
    (const EFFF9_MESSAGE*)&pl13txt1[6],
    (const EFFF9_MESSAGE*)&pl13txt1[12],
    (const EFFF9_MESSAGE*)&pl13txt1[22],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl14txt1,
    (const EFFF9_MESSAGE*)&pl14txt1[4],
    (const EFFF9_MESSAGE*)&pl14txt1[10],
    (const EFFF9_MESSAGE*)&pl14txt1[14],
    (const EFFF9_MESSAGE*)&pl14txt1[20],
    (const EFFF9_MESSAGE*)efff9_no_scene,
    (const EFFF9_MESSAGE*)pl16txt1,
};
/* the code declares txt_no_tbl[28]; effg0_judge_count starts after its first 17 entries */
/* 020083E8 */
s32* txt_no_tbl[17] = {
    (s32*)&effF9_mes_pt[17],
    (s32*)&effF9_mes_pt[17],
    (s32*)&effF9_mes_pt[26],
    (s32*)&effF9_mes_pt[31],
    (s32*)&effF9_mes_pt[51],
    (s32*)&effF9_mes_pt[57],
    (s32*)&effF9_mes_pt[64],
    (s32*)&effF9_mes_pt[73],
    (s32*)&effF9_mes_pt[84],
    (s32*)&effF9_mes_pt[89],
    (s32*)&effF9_mes_pt[41],
    (s32*)&effF9_mes_pt[95],
    (s32*)&effF9_mes_pt[102],
    (s32*)&effF9_mes_pt[108],
    (s32*)&effF9_mes_pt[113],
    (s32*)&effF9_mes_pt[119],
    (s32*)&effF9_mes_pt[119],
};
