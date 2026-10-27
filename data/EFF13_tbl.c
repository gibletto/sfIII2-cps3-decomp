/*
 * EFF13_TBL.C  projectile (shell) process tables
 *
 * kind_of_tama_process is the jump table of the shell processes kotp_00000 .. kotp_09000,
 * kage_tbl the shadow offset, priority and pattern by shadow index, and homing_empos_hos the
 * point on the opponent that a homing shell turns toward. Read by EFF13.C, the projectiles.
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
    kotp_00000,
    kotp_01000,
    kotp_02000,
    kotp_03000,
    kotp_04000,
    kotp_05000,
    kotp_06000,
    kotp_07000,
    kotp_08000,
    kotp_09000,
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
