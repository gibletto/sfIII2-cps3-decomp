/*
 * EFF13_TBL.C  tables read by effect 13
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const kind_of_tama_process[])();
extern const s16 kage_tbl[][4];
extern const s16 homing_empos_hos[][4];
extern void kotp_00000();
extern void kotp_01000();
extern void kotp_02000();
extern void kotp_03000();
extern void kotp_04000();
extern void kotp_05000();
extern void kotp_06000();
extern void kotp_07000();
extern void kotp_08000();
extern void kotp_09000();

void (*const kind_of_tama_process[10])() = {
    (void (*)())kotp_00000,
    (void (*)())kotp_01000,
    (void (*)())kotp_02000,
    (void (*)())kotp_03000,
    (void (*)())kotp_04000,
    (void (*)())kotp_05000,
    (void (*)())kotp_06000,
    (void (*)())kotp_07000,
    (void (*)())kotp_08000,
    (void (*)())kotp_09000,
};

const s16 kage_tbl[6][4] = {
    { 0, 0, 71, 0 },
    { 0, 0, 71, 3 },
    { 0, 0, 71, 4 },
    { 0, 0, 71, 9 },
    { 0, 0, 71, 1 },
    { 0, 0, 71, 0 },
};

const s16 homing_empos_hos[8][4] = {
    { 12, 76, 0, 72 },
    { 6, 66, 2, 52 },
    { 2, 74, 2, 66 },
    { 4, 82, 6, 60 },
    { 6, 58, 6, 48 },
    { 2, 52, 6, 66 },
    { 6, 66, 12, 76 },
    { 6, 66, 6, 66 },
};
