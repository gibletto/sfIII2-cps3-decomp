/*
 * EFFB8_MES.C  effect B8's message tables
 *
 * The message of each character in the four languages and the connection table (initialised
 * work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const EFFB8_MESSAGE effB8_conn_0[];
extern const EFFB8_MESSAGE effB8_conn_10[];
extern const EFFB8_MESSAGE effB8_conn_11[];
extern const EFFB8_MESSAGE effB8_conn_12[];
extern const EFFB8_MESSAGE effB8_conn_1[];
extern const EFFB8_MESSAGE effB8_conn_2[];
extern const EFFB8_MESSAGE effB8_conn_3[];
extern const EFFB8_MESSAGE effB8_conn_4[];
extern const EFFB8_MESSAGE effB8_conn_5[];
extern const EFFB8_MESSAGE effB8_conn_7[];
extern const EFFB8_MESSAGE effB8_conn_8[];
extern const EFFB8_MESSAGE effB8_conn_9[];
extern const EFFB8_MESSAGE effB8_mes_en_0[];
extern const EFFB8_MESSAGE effB8_mes_en_10[];
extern const EFFB8_MESSAGE effB8_mes_en_11[];
extern const EFFB8_MESSAGE effB8_mes_en_12[];
extern const EFFB8_MESSAGE effB8_mes_en_13[];
extern const EFFB8_MESSAGE effB8_mes_en_14[];
extern const EFFB8_MESSAGE effB8_mes_en_1[];
extern const EFFB8_MESSAGE effB8_mes_en_2[];
extern const EFFB8_MESSAGE effB8_mes_en_3[];
extern const EFFB8_MESSAGE effB8_mes_en_4[];
extern const EFFB8_MESSAGE effB8_mes_en_5[];
extern const EFFB8_MESSAGE effB8_mes_en_6[];
extern const EFFB8_MESSAGE effB8_mes_en_7[];
extern const EFFB8_MESSAGE effB8_mes_en_8[];
extern const EFFB8_MESSAGE effB8_mes_en_9[];
extern const EFFB8_MESSAGE effB8_mes_es_0[];
extern const EFFB8_MESSAGE effB8_mes_es_10[];
extern const EFFB8_MESSAGE effB8_mes_es_11[];
extern const EFFB8_MESSAGE effB8_mes_es_12[];
extern const EFFB8_MESSAGE effB8_mes_es_13[];
extern const EFFB8_MESSAGE effB8_mes_es_14[];
extern const EFFB8_MESSAGE effB8_mes_es_1[];
extern const EFFB8_MESSAGE effB8_mes_es_2[];
extern const EFFB8_MESSAGE effB8_mes_es_3[];
extern const EFFB8_MESSAGE effB8_mes_es_4[];
extern const EFFB8_MESSAGE effB8_mes_es_5[];
extern const EFFB8_MESSAGE effB8_mes_es_6[];
extern const EFFB8_MESSAGE effB8_mes_es_7[];
extern const EFFB8_MESSAGE effB8_mes_es_8[];
extern const EFFB8_MESSAGE effB8_mes_es_9[];
extern const EFFB8_MESSAGE effB8_mes_jp_0[];
extern const EFFB8_MESSAGE effB8_mes_jp_10[];
extern const EFFB8_MESSAGE effB8_mes_jp_11[];
extern const EFFB8_MESSAGE effB8_mes_jp_12[];
extern const EFFB8_MESSAGE effB8_mes_jp_13[];
extern const EFFB8_MESSAGE effB8_mes_jp_14[];
extern const EFFB8_MESSAGE effB8_mes_jp_1[];
extern const EFFB8_MESSAGE effB8_mes_jp_2[];
extern const EFFB8_MESSAGE effB8_mes_jp_3[];
extern const EFFB8_MESSAGE effB8_mes_jp_4[];
extern const EFFB8_MESSAGE effB8_mes_jp_5[];
extern const EFFB8_MESSAGE effB8_mes_jp_6[];
extern const EFFB8_MESSAGE effB8_mes_jp_7[];
extern const EFFB8_MESSAGE effB8_mes_jp_8[];
extern const EFFB8_MESSAGE effB8_mes_jp_9[];
extern const EFFB8_MESSAGE effB8_mes_pt_0[];
extern const EFFB8_MESSAGE effB8_mes_pt_10[];
extern const EFFB8_MESSAGE effB8_mes_pt_11[];
extern const EFFB8_MESSAGE effB8_mes_pt_12[];
extern const EFFB8_MESSAGE effB8_mes_pt_13[];
extern const EFFB8_MESSAGE effB8_mes_pt_14[];
extern const EFFB8_MESSAGE effB8_mes_pt_1[];
extern const EFFB8_MESSAGE effB8_mes_pt_2[];
extern const EFFB8_MESSAGE effB8_mes_pt_3[];
extern const EFFB8_MESSAGE effB8_mes_pt_4[];
extern const EFFB8_MESSAGE effB8_mes_pt_5[];
extern const EFFB8_MESSAGE effB8_mes_pt_6[];
extern const EFFB8_MESSAGE effB8_mes_pt_7[];
extern const EFFB8_MESSAGE effB8_mes_pt_8[];
extern const EFFB8_MESSAGE effB8_mes_pt_9[];

/* 02007FE4 */
const EFFB8_MESSAGE* effB8_mes_jp[16] = {
    effB8_mes_jp_0,
    effB8_mes_jp_1,
    effB8_mes_jp_2,
    effB8_mes_jp_3,
    effB8_mes_jp_4,
    effB8_mes_jp_5,
    effB8_mes_jp_6,
    effB8_mes_jp_7,
    effB8_mes_jp_8,
    effB8_mes_jp_9,
    effB8_mes_jp_10,
    effB8_mes_jp_11,
    effB8_mes_jp_12,
    effB8_mes_jp_13,
    effB8_mes_jp_14,
    effB8_mes_jp_14,
};
/* 02008024 */
const EFFB8_MESSAGE* effB8_mes_en[16] = {
    effB8_mes_en_0,
    effB8_mes_en_1,
    effB8_mes_en_2,
    effB8_mes_en_3,
    effB8_mes_en_4,
    effB8_mes_en_5,
    effB8_mes_en_6,
    effB8_mes_en_7,
    effB8_mes_en_8,
    effB8_mes_en_9,
    effB8_mes_en_10,
    effB8_mes_en_11,
    effB8_mes_en_12,
    effB8_mes_en_13,
    effB8_mes_en_14,
    effB8_mes_en_14,
};
/* 02008064 */
const EFFB8_MESSAGE* effB8_mes_es[16] = {
    effB8_mes_es_0,
    effB8_mes_es_1,
    effB8_mes_es_2,
    effB8_mes_es_3,
    effB8_mes_es_4,
    effB8_mes_es_5,
    effB8_mes_es_6,
    effB8_mes_es_7,
    effB8_mes_es_8,
    effB8_mes_es_9,
    effB8_mes_es_10,
    effB8_mes_es_11,
    effB8_mes_es_12,
    effB8_mes_es_13,
    effB8_mes_es_14,
    effB8_mes_es_14,
};
/* 020080A4 */
const EFFB8_MESSAGE* effB8_mes_pt[16] = {
    effB8_mes_pt_0,
    effB8_mes_pt_1,
    effB8_mes_pt_2,
    effB8_mes_pt_3,
    effB8_mes_pt_4,
    effB8_mes_pt_5,
    effB8_mes_pt_6,
    effB8_mes_pt_7,
    effB8_mes_pt_8,
    effB8_mes_pt_9,
    effB8_mes_pt_10,
    effB8_mes_pt_11,
    effB8_mes_pt_12,
    effB8_mes_pt_13,
    effB8_mes_pt_14,
    effB8_mes_pt_14,
};
/* 020080E4 */
const EFFB8_MESSAGE* effB8_conn_tbl[13] = {
    effB8_conn_0,
    effB8_conn_1,
    effB8_conn_2,
    effB8_conn_3,
    effB8_conn_4,
    effB8_conn_5,
    effB8_conn_0,
    effB8_conn_7,
    effB8_conn_8,
    effB8_conn_9,
    effB8_conn_10,
    effB8_conn_11,
    effB8_conn_12,
};
