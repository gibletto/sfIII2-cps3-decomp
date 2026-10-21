/*
 * SPGAUGE_TBL_B.C  tables read by sc_sub_2.c: HUD win marks, palette fade control and stun gauge
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 fade_adrs_tbl_17[];
extern const u16 fade_adrs_tbl_15_061742FC[];
extern const u16 fade_adrs_tbl_5_06174300[];
extern const u16 fade_adrs_tbl_18[];
extern const u16 fade_adrs_tbl_27_06174308[];
extern const u16 fade_adrs_tbl_19[];
extern const u16 fade_adrs_tbl_20[];
extern const u16 fade_adrs_tbl_21[];
extern const u16 fade_adrs_tbl_22[];
extern const u16 fade_adrs_tbl_25[];
extern const u16 fade_adrs_tbl_26[];
extern const u16 fade_adrs_tbl_28[];
extern const u16 fade_adrs_tbl_29[];
extern const u16 fade_adrs_tbl_27[];
extern const u16 fade_adrs_tbl_23[];
extern const u16 fade_adrs_tbl_30[];
extern const u16 fade_adrs_tbl_0[];
extern const u16 spgauge_tbl_0617433C[];
extern const u16 fade_adrs_tbl_1[];
extern const u16 spgauge_tbl_06174344[];
extern const u16 fade_adrs_tbl_2[];
extern const u16 spgauge_tbl_0617434C[];
extern const u16 fade_adrs_tbl_3[];
extern const u16 spgauge_tbl_06174358[];
extern const u16 fade_adrs_tbl_4[];
extern const u16 spgauge_tbl_06174364[];
extern const u16 fade_adrs_tbl_5[];
extern const u16 spgauge_tbl_06174370[];
extern const u16 fade_adrs_tbl_6[];
extern const u16 spgauge_tbl_0617437C[];
extern const u16 fade_adrs_tbl_7[];
extern const u16 spgauge_tbl_06174388[];
extern const u16 fade_adrs_tbl_8[];
extern const u16 spgauge_tbl_06174390[];
extern const u16 fade_adrs_tbl_9[];
extern const u16 spgauge_tbl_0617439C[];
extern const u16 fade_adrs_tbl_10[];
extern const u16 spgauge_tbl_061743A8[];
extern const u16 fade_adrs_tbl_11[];
extern const u16 spgauge_tbl_061743B4[];
extern const u16 fade_adrs_tbl_12[];
extern const u16 spgauge_tbl_061743C0[];
extern const u16 fade_adrs_tbl_13[];
extern const u16 spgauge_tbl_061743C8[];
extern const u16 fade_adrs_tbl_14[];
extern const u16 spgauge_tbl_061743D0[];
extern const u16 fade_adrs_tbl_15[];
extern const u16 spgauge_tbl_061743D8[];

const u16 fade_adrs_tbl_17[2] = {
    0, 5,
};

/* provisional name */
const u16 fade_adrs_tbl_15_061742FC[2] = {
    0, 7,
};

/* provisional name */
const u16 fade_adrs_tbl_5_06174300[2] = {
    0, 8,
};

const u16 fade_adrs_tbl_18[2] = {
    0, 4,
};

/* provisional name */
const u16 fade_adrs_tbl_27_06174308[2] = {
    0, 2,
};

const u16 fade_adrs_tbl_19[2] = {
    0, 4,
};

const u16 fade_adrs_tbl_20[2] = {
    0, 2,
};

const u16 fade_adrs_tbl_21[2] = {
    0, 0xA,
};

const u16 fade_adrs_tbl_22[2] = {
    0, 9,
};

const u16 fade_adrs_tbl_25[2] = {
    0, 0x82,
};

const u16 fade_adrs_tbl_26[2] = {
    0, 0x92,
};

const u16 fade_adrs_tbl_28[2] = {
    0, 0x85,
};

const u16 fade_adrs_tbl_29[2] = {
    0, 0x84,
};

const u16 fade_adrs_tbl_27[2] = {
    0, 0x91,
};

const u16 fade_adrs_tbl_23[2] = {
    0, 0x86,
};

const u16 fade_adrs_tbl_30[2] = {
    0, 0xB4,
};

const u16 fade_adrs_tbl_0[2] = {
    0, 0x34,
};

/* provisional name */
const u16 spgauge_tbl_0617433C[2] = {
    0, 0x45,
};

const u16 fade_adrs_tbl_1[2] = {
    0, 0x35,
};

/* provisional name */
const u16 spgauge_tbl_06174344[2] = {
    0, 0x46,
};

const u16 fade_adrs_tbl_2[2] = {
    0, 0x38,
};

/* provisional name */
const u16 spgauge_tbl_0617434C[4] = {
    0, 0x49, 0, 0x67,
};

const u16 fade_adrs_tbl_3[2] = {
    0, 0x39,
};

/* provisional name */
const u16 spgauge_tbl_06174358[4] = {
    0, 0x4A, 0, 0x6A,
};

const u16 fade_adrs_tbl_4[2] = {
    0, 0x3B,
};

/* provisional name */
const u16 spgauge_tbl_06174364[4] = {
    0, 0x4C, 0, 0x65,
};

const u16 fade_adrs_tbl_5[2] = {
    0, 0x3D,
};

/* provisional name */
const u16 spgauge_tbl_06174370[4] = {
    0, 0x4E, 0, 0x61,
};

const u16 fade_adrs_tbl_6[2] = {
    0, 0x3E,
};

/* provisional name */
const u16 spgauge_tbl_0617437C[4] = {
    0, 0x4F, 0, 0x60,
};

const u16 fade_adrs_tbl_7[2] = {
    0, 0x3F,
};

/* provisional name */
const u16 spgauge_tbl_06174388[2] = {
    0, 0x50,
};

const u16 fade_adrs_tbl_8[2] = {
    0, 0x42,
};

/* provisional name */
const u16 spgauge_tbl_06174390[4] = {
    0, 0x53, 0, 0x62,
};

const u16 fade_adrs_tbl_9[2] = {
    0, 0x43,
};

/* provisional name */
const u16 spgauge_tbl_0617439C[4] = {
    0, 0x54, 0, 0x63,
};

const u16 fade_adrs_tbl_10[2] = {
    0, 0x44,
};

/* provisional name */
const u16 spgauge_tbl_061743A8[4] = {
    0, 0x55, 0, 0x6C,
};

const u16 fade_adrs_tbl_11[2] = {
    0, 0x3A,
};

/* provisional name */
const u16 spgauge_tbl_061743B4[4] = {
    0, 0x4B, 0, 0x6B,
};

const u16 fade_adrs_tbl_12[2] = {
    0, 0x99,
};

/* provisional name */
const u16 spgauge_tbl_061743C0[2] = {
    0, 0x9A,
};

const u16 fade_adrs_tbl_13[2] = {
    0, 0x9D,
};

/* provisional name */
const u16 spgauge_tbl_061743C8[2] = {
    0, 0x9E,
};

const u16 fade_adrs_tbl_14[2] = {
    0, 0x97,
};

/* provisional name */
const u16 spgauge_tbl_061743D0[2] = {
    0, 0x98,
};

const u16 fade_adrs_tbl_15[2] = {
    0, 0x95,
};

/* provisional name */
const u16 spgauge_tbl_061743D8[2] = {
    0, 0x96,
};
