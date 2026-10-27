/*
 * EXCHANGE.C  combo damage scaling tables
 *
 * exchange_pow points, for each attack kind, at a row of exchange_pow_data_0 - 2: the damage
 * scale (out of 32) by how much combo has built up; exchange_pow_pl03_sa3 replaces it for Yun
 * and Yang while their third super art is active. exchange_koa points at the
 * exchange_koa_data_0 - 10 rows, the weight each kind of earlier hit adds to that count. Read
 * by HITCHECK.C. bonus_level_rate_tbl is the bonus stage rating factor by the rounds setting,
 * read by BBBSCOM.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const POWER *const exchange_pow_pl03_sa3[];
extern const POWER *const exchange_pow[];
extern const POWER exchange_pow_data_0[];
extern const POWER exchange_pow_data_1[];
extern const POWER exchange_pow_data_2[];
extern const KOATT *const exchange_koa[];
extern const KOATT exchange_koa_data_0[];
extern const KOATT exchange_koa_data_1[];
extern const KOATT exchange_koa_data_2[];
extern const KOATT exchange_koa_data_3[];
extern const KOATT exchange_koa_data_4[];
extern const KOATT exchange_koa_data_5[];
extern const KOATT exchange_koa_data_6[];
extern const KOATT exchange_koa_data_7[];
extern const KOATT exchange_koa_data_8[];
extern const KOATT exchange_koa_data_9[];
extern const KOATT exchange_koa_data_10[];
extern const u16 bonus_level_rate_tbl[];

const POWER *const exchange_pow_pl03_sa3[33] = {
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
    exchange_pow_data_2,
};

const POWER *const exchange_pow[33] = {
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_0,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
    exchange_pow_data_1,
};

const POWER exchange_pow_data_0[2] = {
    { { 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8 } },
    { { 32, 31, 30, 28, 26, 23, 20, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13, 13, 12, 12, 12, 11, 11, 11, 10, 10, 10, 9, 9, 9, 8 } },
};

const POWER exchange_pow_data_1[1] = {
    { { 32, 30, 28, 26, 24, 23, 22, 21, 20, 19, 18, 17, 16, 16, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8, 7, 7 } },
};

const POWER exchange_pow_data_2[1] = {
    { { 32, 31, 30, 28, 26, 24, 21, 18, 15, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
};

const KOATT *const exchange_koa[33] = {
    (const KOATT *)exchange_koa_data_0,
    (const KOATT *)exchange_koa_data_1,
    (const KOATT *)exchange_koa_data_2,
    (const KOATT *)exchange_koa_data_2,
    (const KOATT *)exchange_koa_data_3,
    (const KOATT *)exchange_koa_data_3,
    (const KOATT *)exchange_koa_data_3,
    (const KOATT *)exchange_koa_data_3,
    (const KOATT *)exchange_koa_data_4,
    (const KOATT *)exchange_koa_data_4,
    (const KOATT *)exchange_koa_data_4,
    (const KOATT *)exchange_koa_data_4,
    (const KOATT *)exchange_koa_data_5,
    (const KOATT *)exchange_koa_data_5,
    (const KOATT *)exchange_koa_data_5,
    (const KOATT *)exchange_koa_data_5,
    (const KOATT *)exchange_koa_data_6,
    (const KOATT *)exchange_koa_data_6,
    (const KOATT *)exchange_koa_data_6,
    (const KOATT *)exchange_koa_data_6,
    (const KOATT *)exchange_koa_data_7,
    (const KOATT *)exchange_koa_data_7,
    (const KOATT *)exchange_koa_data_7,
    (const KOATT *)exchange_koa_data_7,
    (const KOATT *)exchange_koa_data_8,
    (const KOATT *)exchange_koa_data_8,
    (const KOATT *)exchange_koa_data_8,
    (const KOATT *)exchange_koa_data_8,
    (const KOATT *)exchange_koa_data_9,
    (const KOATT *)exchange_koa_data_9,
    (const KOATT *)exchange_koa_data_9,
    (const KOATT *)exchange_koa_data_9,
    (const KOATT *)exchange_koa_data_10,
};

const KOATT exchange_koa_data_0[1] = {
    { { { 1536, 256, 256, 256 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_1[1] = {
    { { { 256, 1280, 256, 256 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_2[1] = {
    { { { 256, 256, 1024, 1536 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_3[1] = {
    { { { 256, 512, 768, 768 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_4[1] = {
    { { { 256, 512, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_5[1] = {
    { { { 256, 512, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 512, 512, 512, 512 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_6[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_7[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 256, 256, 256, 256 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_8[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 256, 256, 256, 256 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_9[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 256, 0, 0, 0 } } },
};

const KOATT exchange_koa_data_10[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};

/* provisional name */
const u16 bonus_level_rate_tbl[4] = {
    0xA, 5, 3, 2,
};
