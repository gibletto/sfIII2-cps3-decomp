/*
 * PLPCA_TBL.C  tables read by PLPCA.c: player catch (throwing) process
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const plpca_lv_00[])();
extern void Catch_00000();
extern void Catch_01000();
extern void Catch_02000();
extern void Catch_03000();
extern void Catch_04000();
extern void Catch_05000();
extern void Catch_06000();

void (*const plpca_lv_00[7])() = {
    (void (*)())Catch_00000,
    (void (*)())Catch_01000,
    (void (*)())Catch_02000,
    (void (*)())Catch_03000,
    (void (*)())Catch_04000,
    (void (*)())Catch_05000,
    (void (*)())Catch_06000,
};
