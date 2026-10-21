/*
 * SHELL07_TBL.C  tables read by SHELL07.c: CPU anti-projectile patterns, table 07
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell07_Tbl[])();
extern void Shell07_0000();
extern void Shell07_0001();
extern void Shell07_0002();
extern void Shell07_0003();
extern void Shell07_0004();
extern void Shell07_0005();
extern void Shell07_0006();
extern void Shell07_0007();
extern void Shell07_0008();
extern void Shell07_0009();
extern void Shell07_0010();
extern void Shell07_0011();

void (*const Shell07_Tbl[12])() = {
    (void (*)())Shell07_0000,
    (void (*)())Shell07_0001,
    (void (*)())Shell07_0002,
    (void (*)())Shell07_0003,
    (void (*)())Shell07_0004,
    (void (*)())Shell07_0005,
    (void (*)())Shell07_0006,
    (void (*)())Shell07_0007,
    (void (*)())Shell07_0008,
    (void (*)())Shell07_0009,
    (void (*)())Shell07_0010,
    (void (*)())Shell07_0011,
};
