/*
 * EFFB8_MES.C  effect B8's message tables
 *
 * The message of each character in the four languages and the connection table (initialised
 * work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const u16 chr_data_06446B3E[];
extern const u16 chr_data_06446DFA[];
extern const u16 chr_data_064470FA[];
extern const u16 chr_data_0644756A[];
extern const u16 chr_data_06447DD2[];
extern const u16 chr_data_064481A2[];
extern const u16 chr_data_06470562[];
extern const u16 chr_data_064753C6[];
extern const u16 chr_data_06477A2E[];
extern const u16 chr_data_06478DEE[];
extern const u16 chr_data_06479EDA[];
extern const u16 chr_data_0647C562[];
extern const u16 chr_data_0647D962[];
extern const u16 chr_data_0647EC0E[];
extern const u16 chr_data_0647FDD2[];
extern const u16 chr_data_0648533A[];
extern const u16 chr_data_0648BD3A[];
extern const u16 chr_data_06491C7A[];
extern const u16 chr_data_06494DC2[];
extern const u16 chr_data_06497482[];
extern const u16 chr_data_06499DFA[];
extern const u16 chr_data_0649CCAA[];
extern const u16 chr_data_064A8362[];
extern const u16 chr_data_064AB112[];
extern const u16 chr_data_064ADA2E[];
extern const u16 chr_data_064B189E[];
extern const u16 chr_data_064B4E2A[];
extern const u16 chr_data_064BB67A[];
extern const u16 chr_data_064C1FF2[];
extern const u16 chr_data_064C47EE[];
extern const u16 chr_data_064CA836[];
extern const u16 chr_data_064CE10E[];
extern const u16 chr_data_064D45E2[];
extern const u16 chr_data_064DCF16[];
extern const u16 chr_data_064E78DA[];
extern const u16 chr_data_064EA7EE[];
extern const u16 chr_data_064F62FE[];
extern const u16 chr_data_064F94E2[];
extern const u16 chr_data_064FCB3A[];
extern const u16 chr_data_064FFE46[];
extern const u16 chr_data_06502E52[];
extern const u16 chr_data_065052A2[];
extern const u32 chr_data_0644693C[];
extern const u32 chr_data_06447290[];
extern const u32 chr_data_064477F4[];
extern const u32 chr_data_06447A00[];
extern const u32 chr_data_06447BC0[];
extern const u32 chr_data_06447F6C[];
extern const u32 chr_data_06471ACC[];
extern const u32 chr_data_06472EA8[];
extern const u32 chr_data_0647408C[];
extern const u32 chr_data_064767C4[];
extern const u32 chr_data_0647B23C[];
extern const u32 chr_data_064812DC[];
extern const u32 chr_data_06482234[];
extern const u32 chr_data_06488674[];
extern const u32 chr_data_0648EA30[];
extern const u32 chr_data_064A00AC[];
extern const u32 chr_data_064A3470[];
extern const u32 chr_data_064A6118[];
extern const u32 chr_data_064B8764[];
extern const u32 chr_data_064BEC40[];
extern const u32 chr_data_064C7570[];
extern const u32 chr_data_064D16B0[];
extern const u32 chr_data_064D6D44[];
extern const u32 chr_data_064D9E8C[];
extern const u32 chr_data_064E0E00[];
extern const u32 chr_data_064E410C[];
extern const u32 chr_data_064EDAB0[];
extern const u32 chr_data_064F0E7C[];
extern const u32 chr_data_064F36E4[];
extern const u32 chr_data_06508238[];

/* 02007FE4 */
const EFFB8_MESSAGE* effB8_mes_jp[16] = {
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06470562 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06471ACC + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06472EA8 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0647408C + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064753C6 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064767C4 + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06477A2E + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06478DEE + 14),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06479EDA + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0647B23C + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0647C562 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0647D962 + 14),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0647EC0E + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0647FDD2 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064812DC + 20),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064812DC + 20),
};
/* 02008024 */
const EFFB8_MESSAGE* effB8_mes_en[16] = {
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06482234 + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0648533A + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06488674 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0648BD3A + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0648EA30 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06491C7A + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06494DC2 + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06497482 + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06499DFA + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0649CCAA + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064A00AC + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064A3470 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064A6118 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064A8362 + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064AB112 + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064AB112 + 6),
};
/* 02008064 */
const EFFB8_MESSAGE* effB8_mes_es[16] = {
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064DCF16 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064E0E00 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064E410C + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064E78DA + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064EA7EE + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064EDAB0 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064F0E7C + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064F36E4 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064F62FE + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064F94E2 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064FCB3A + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064FFE46 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06502E52 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_065052A2 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06508238 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06508238 + 8),
};
/* 020080A4 */
const EFFB8_MESSAGE* effB8_mes_pt[16] = {
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064ADA2E + 6),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064B189E + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064B4E2A + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064B8764 + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064BB67A + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064BEC40 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064C1FF2 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064C47EE + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064C7570 + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064CA836 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064CE10E + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064D16B0 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064D45E2 + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064D6D44 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064D9E8C + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064D9E8C + 8),
};
/* 020080E4 */
const EFFB8_MESSAGE* effB8_conn_tbl[13] = {
    (const EFFB8_MESSAGE *)chr_data_0644693C,
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06446B3E + 14),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06446DFA + 14),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064470FA + 10),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06447290 + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_0644756A + 18),
    (const EFFB8_MESSAGE *)chr_data_0644693C,
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064477F4 + 16),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06447A00 + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06447BC0 + 12),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06447DD2 + 14),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_06447F6C + 8),
    (const EFFB8_MESSAGE *)((const u8*)chr_data_064481A2 + 14),
};
