/*
 * SHELL13_TBL.C  tables read by SHELL13.c: CPU anti-projectile patterns, table 13
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell13_Tbl[])();
extern void Shell13_0000();
extern void Shell13_0001();
extern void Shell13_0002();
extern void Shell13_0003();
extern void Shell13_0004();
extern void Shell13_0005();
extern void Shell13_0006();
extern void Shell13_0007();
extern void Shell13_0008();
extern void Shell13_0009();
extern void Shell13_0010();
extern void Shell13_0011();

void (*const Shell13_Tbl[12])() = {
    (void (*)())Shell13_0000,
    (void (*)())Shell13_0001,
    (void (*)())Shell13_0002,
    (void (*)())Shell13_0003,
    (void (*)())Shell13_0004,
    (void (*)())Shell13_0005,
    (void (*)())Shell13_0006,
    (void (*)())Shell13_0007,
    (void (*)())Shell13_0008,
    (void (*)())Shell13_0009,
    (void (*)())Shell13_0010,
    (void (*)())Shell13_0011,
};
