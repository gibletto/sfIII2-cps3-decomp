/*
 * EFFA6_MES.C  effect A6's message tables
 *
 * The message of each character in the four languages (initialised work RAM, section D).
 */

#include "types.h"
#include "structs.h"

extern const u32 eff67_mes_0650AF20[];
extern const u32 eff67_mes_0650B484[];
extern const u32 eff67_mes_0650B960[];
extern const u32 eff67_mes_0650BE5C[];
extern const u32 eff67_mes_0650C3C4[];
extern const u32 eff67_mes_0650C930[];
extern const u32 eff67_mes_0650D200[];
extern const u32 eff67_mes_0650D698[];
extern const u32 eff67_mes_0650DB54[];
extern const u32 eff67_mes_0650E098[];
extern const u32 eff67_mes_0650E51C[];
extern const u32 eff67_mes_0650EA04[];
extern const u32 eff67_mes_0650EEA8[];
extern const u32 eff67_mes_0650F350[];
extern const u32 eff67_mes_0650F6CC[];
extern const u32 eff67_mes_0650FF70[];
extern const u32 eff67_mes_06510774[];
extern const u32 eff67_mes_06510F88[];
extern const u32 eff67_mes_065117EC[];
extern const u32 eff67_mes_06512038[];
extern const u32 eff67_mes_06512FE0[];
extern const u32 eff67_mes_06513804[];
extern const u32 eff67_mes_06513FD8[];
extern const u32 eff67_mes_06514834[];
extern const u32 eff67_mes_065150A0[];
extern const u32 eff67_mes_06515874[];
extern const u32 eff67_mes_06516118[];
extern const u32 eff67_mes_06516894[];
extern const u32 eff67_mes_06516FE0[];
extern const u32 eff67_mes_065178D0[];
extern const u32 eff67_mes_065180DC[];
extern const u32 eff67_mes_06518910[];
extern const u32 eff67_mes_065191A8[];
extern const u32 eff67_mes_065199E0[];
extern const u32 eff67_mes_0651AA40[];
extern const u32 eff67_mes_0651B230[];
extern const u32 eff67_mes_0651B9FC[];
extern const u32 eff67_mes_0651C28C[];
extern const u32 eff67_mes_0651CAF4[];
extern const u32 eff67_mes_0651D2DC[];
extern const u32 eff67_mes_0651DBA4[];
extern const u32 eff67_mes_0651E318[];
extern const u32 eff67_mes_0651EA9C[];
extern const u32 eff67_mes_0651F2D4[];
extern const u32 eff67_mes_0651FAE8[];
extern const u32 eff67_mes_06520280[];
extern const u32 eff67_mes_06520A3C[];
extern const u32 eff67_mes_06521284[];
extern const u32 eff67_mes_065222B8[];
extern const u32 eff67_mes_06522A70[];
extern const u32 eff67_mes_06523240[];
extern const u32 eff67_mes_06523A18[];
extern const u32 eff67_mes_06524248[];
extern const u32 eff67_mes_06524A00[];
extern const u32 eff67_mes_06525288[];
extern const u32 eff67_mes_06525A40[];

/* 02007EF4 */
const EFFA6_MESSAGE* effA6_mes_jp[15] = {
    (const EFFA6_MESSAGE *)eff67_mes_0650AF20,
    (const EFFA6_MESSAGE *)eff67_mes_0650AF20,
    (const EFFA6_MESSAGE *)eff67_mes_0650B484,
    (const EFFA6_MESSAGE *)eff67_mes_0650B960,
    (const EFFA6_MESSAGE *)eff67_mes_0650BE5C,
    (const EFFA6_MESSAGE *)eff67_mes_0650C3C4,
    (const EFFA6_MESSAGE *)eff67_mes_0650C930,
    (const EFFA6_MESSAGE *)eff67_mes_0650D200,
    (const EFFA6_MESSAGE *)eff67_mes_0650D698,
    (const EFFA6_MESSAGE *)eff67_mes_0650DB54,
    (const EFFA6_MESSAGE *)eff67_mes_0650E098,
    (const EFFA6_MESSAGE *)eff67_mes_0650E51C,
    (const EFFA6_MESSAGE *)eff67_mes_0650EA04,
    (const EFFA6_MESSAGE *)eff67_mes_0650EEA8,
    (const EFFA6_MESSAGE *)eff67_mes_0650F350,
};
/* 02007F30 */
const EFFA6_MESSAGE* effA6_mes_en[15] = {
    (const EFFA6_MESSAGE *)eff67_mes_0650F6CC,
    (const EFFA6_MESSAGE *)eff67_mes_0650F6CC,
    (const EFFA6_MESSAGE *)eff67_mes_0650FF70,
    (const EFFA6_MESSAGE *)eff67_mes_06510774,
    (const EFFA6_MESSAGE *)eff67_mes_06510F88,
    (const EFFA6_MESSAGE *)eff67_mes_065117EC,
    (const EFFA6_MESSAGE *)eff67_mes_06512038,
    (const EFFA6_MESSAGE *)eff67_mes_06512FE0,
    (const EFFA6_MESSAGE *)eff67_mes_06513804,
    (const EFFA6_MESSAGE *)eff67_mes_06513FD8,
    (const EFFA6_MESSAGE *)eff67_mes_06514834,
    (const EFFA6_MESSAGE *)eff67_mes_065150A0,
    (const EFFA6_MESSAGE *)eff67_mes_06515874,
    (const EFFA6_MESSAGE *)eff67_mes_06516118,
    (const EFFA6_MESSAGE *)eff67_mes_06516894,
};
/* 02007F6C */
const EFFA6_MESSAGE* effA6_mes_es[15] = {
    (const EFFA6_MESSAGE *)eff67_mes_06516FE0,
    (const EFFA6_MESSAGE *)eff67_mes_06516FE0,
    (const EFFA6_MESSAGE *)eff67_mes_065178D0,
    (const EFFA6_MESSAGE *)eff67_mes_065180DC,
    (const EFFA6_MESSAGE *)eff67_mes_06518910,
    (const EFFA6_MESSAGE *)eff67_mes_065191A8,
    (const EFFA6_MESSAGE *)eff67_mes_065199E0,
    (const EFFA6_MESSAGE *)eff67_mes_0651AA40,
    (const EFFA6_MESSAGE *)eff67_mes_0651B230,
    (const EFFA6_MESSAGE *)eff67_mes_0651B9FC,
    (const EFFA6_MESSAGE *)eff67_mes_0651C28C,
    (const EFFA6_MESSAGE *)eff67_mes_0651CAF4,
    (const EFFA6_MESSAGE *)eff67_mes_0651D2DC,
    (const EFFA6_MESSAGE *)eff67_mes_0651DBA4,
    (const EFFA6_MESSAGE *)eff67_mes_0651E318,
};
/* 02007FA8 */
const EFFA6_MESSAGE* effA6_mes_pt[15] = {
    (const EFFA6_MESSAGE *)eff67_mes_0651EA9C,
    (const EFFA6_MESSAGE *)eff67_mes_0651EA9C,
    (const EFFA6_MESSAGE *)eff67_mes_0651F2D4,
    (const EFFA6_MESSAGE *)eff67_mes_0651FAE8,
    (const EFFA6_MESSAGE *)eff67_mes_06520280,
    (const EFFA6_MESSAGE *)eff67_mes_06520A3C,
    (const EFFA6_MESSAGE *)eff67_mes_06521284,
    (const EFFA6_MESSAGE *)eff67_mes_065222B8,
    (const EFFA6_MESSAGE *)eff67_mes_06522A70,
    (const EFFA6_MESSAGE *)eff67_mes_06523240,
    (const EFFA6_MESSAGE *)eff67_mes_06523A18,
    (const EFFA6_MESSAGE *)eff67_mes_06524248,
    (const EFFA6_MESSAGE *)eff67_mes_06524A00,
    (const EFFA6_MESSAGE *)eff67_mes_06525288,
    (const EFFA6_MESSAGE *)eff67_mes_06525A40,
};
