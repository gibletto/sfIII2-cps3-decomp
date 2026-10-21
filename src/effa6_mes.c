/*
 * EFFA6_MES.C  effect A6's message tables
 *
 * The message of each character in the four languages (initialised work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const EFFA6_MESSAGE effA6_mes_en_0[];
extern const EFFA6_MESSAGE effA6_mes_en_10[];
extern const EFFA6_MESSAGE effA6_mes_en_11[];
extern const EFFA6_MESSAGE effA6_mes_en_12[];
extern const EFFA6_MESSAGE effA6_mes_en_13[];
extern const EFFA6_MESSAGE effA6_mes_en_14[];
extern const EFFA6_MESSAGE effA6_mes_en_2[];
extern const EFFA6_MESSAGE effA6_mes_en_3[];
extern const EFFA6_MESSAGE effA6_mes_en_4[];
extern const EFFA6_MESSAGE effA6_mes_en_5[];
extern const EFFA6_MESSAGE effA6_mes_en_6[];
extern const EFFA6_MESSAGE effA6_mes_en_7[];
extern const EFFA6_MESSAGE effA6_mes_en_8[];
extern const EFFA6_MESSAGE effA6_mes_en_9[];
extern const EFFA6_MESSAGE effA6_mes_es_0[];
extern const EFFA6_MESSAGE effA6_mes_es_10[];
extern const EFFA6_MESSAGE effA6_mes_es_11[];
extern const EFFA6_MESSAGE effA6_mes_es_12[];
extern const EFFA6_MESSAGE effA6_mes_es_13[];
extern const EFFA6_MESSAGE effA6_mes_es_14[];
extern const EFFA6_MESSAGE effA6_mes_es_2[];
extern const EFFA6_MESSAGE effA6_mes_es_3[];
extern const EFFA6_MESSAGE effA6_mes_es_4[];
extern const EFFA6_MESSAGE effA6_mes_es_5[];
extern const EFFA6_MESSAGE effA6_mes_es_6[];
extern const EFFA6_MESSAGE effA6_mes_es_7[];
extern const EFFA6_MESSAGE effA6_mes_es_8[];
extern const EFFA6_MESSAGE effA6_mes_es_9[];
extern const EFFA6_MESSAGE effA6_mes_jp_0[];
extern const EFFA6_MESSAGE effA6_mes_jp_10[];
extern const EFFA6_MESSAGE effA6_mes_jp_11[];
extern const EFFA6_MESSAGE effA6_mes_jp_12[];
extern const EFFA6_MESSAGE effA6_mes_jp_13[];
extern const EFFA6_MESSAGE effA6_mes_jp_14[];
extern const EFFA6_MESSAGE effA6_mes_jp_2[];
extern const EFFA6_MESSAGE effA6_mes_jp_3[];
extern const EFFA6_MESSAGE effA6_mes_jp_4[];
extern const EFFA6_MESSAGE effA6_mes_jp_5[];
extern const EFFA6_MESSAGE effA6_mes_jp_6[];
extern const EFFA6_MESSAGE effA6_mes_jp_7[];
extern const EFFA6_MESSAGE effA6_mes_jp_8[];
extern const EFFA6_MESSAGE effA6_mes_jp_9[];
extern const EFFA6_MESSAGE effA6_mes_pt_0[];
extern const EFFA6_MESSAGE effA6_mes_pt_10[];
extern const EFFA6_MESSAGE effA6_mes_pt_11[];
extern const EFFA6_MESSAGE effA6_mes_pt_12[];
extern const EFFA6_MESSAGE effA6_mes_pt_13[];
extern const EFFA6_MESSAGE effA6_mes_pt_14[];
extern const EFFA6_MESSAGE effA6_mes_pt_2[];
extern const EFFA6_MESSAGE effA6_mes_pt_3[];
extern const EFFA6_MESSAGE effA6_mes_pt_4[];
extern const EFFA6_MESSAGE effA6_mes_pt_5[];
extern const EFFA6_MESSAGE effA6_mes_pt_6[];
extern const EFFA6_MESSAGE effA6_mes_pt_7[];
extern const EFFA6_MESSAGE effA6_mes_pt_8[];
extern const EFFA6_MESSAGE effA6_mes_pt_9[];

/* 02007EF4 */
const EFFA6_MESSAGE* effA6_mes_jp[15] = {
    effA6_mes_jp_0,
    effA6_mes_jp_0,
    effA6_mes_jp_2,
    effA6_mes_jp_3,
    effA6_mes_jp_4,
    effA6_mes_jp_5,
    effA6_mes_jp_6,
    effA6_mes_jp_7,
    effA6_mes_jp_8,
    effA6_mes_jp_9,
    effA6_mes_jp_10,
    effA6_mes_jp_11,
    effA6_mes_jp_12,
    effA6_mes_jp_13,
    effA6_mes_jp_14,
};
/* 02007F30 */
const EFFA6_MESSAGE* effA6_mes_en[15] = {
    effA6_mes_en_0,
    effA6_mes_en_0,
    effA6_mes_en_2,
    effA6_mes_en_3,
    effA6_mes_en_4,
    effA6_mes_en_5,
    effA6_mes_en_6,
    effA6_mes_en_7,
    effA6_mes_en_8,
    effA6_mes_en_9,
    effA6_mes_en_10,
    effA6_mes_en_11,
    effA6_mes_en_12,
    effA6_mes_en_13,
    effA6_mes_en_14,
};
/* 02007F6C */
const EFFA6_MESSAGE* effA6_mes_es[15] = {
    effA6_mes_es_0,
    effA6_mes_es_0,
    effA6_mes_es_2,
    effA6_mes_es_3,
    effA6_mes_es_4,
    effA6_mes_es_5,
    effA6_mes_es_6,
    effA6_mes_es_7,
    effA6_mes_es_8,
    effA6_mes_es_9,
    effA6_mes_es_10,
    effA6_mes_es_11,
    effA6_mes_es_12,
    effA6_mes_es_13,
    effA6_mes_es_14,
};
/* 02007FA8 */
const EFFA6_MESSAGE* effA6_mes_pt[15] = {
    effA6_mes_pt_0,
    effA6_mes_pt_0,
    effA6_mes_pt_2,
    effA6_mes_pt_3,
    effA6_mes_pt_4,
    effA6_mes_pt_5,
    effA6_mes_pt_6,
    effA6_mes_pt_7,
    effA6_mes_pt_8,
    effA6_mes_pt_9,
    effA6_mes_pt_10,
    effA6_mes_pt_11,
    effA6_mes_pt_12,
    effA6_mes_pt_13,
    effA6_mes_pt_14,
};
