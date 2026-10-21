/*
 * SHELL04_TBL.C  tables read by SHELL04.c: CPU anti-projectile patterns, table 04
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell04_Tbl[])();
extern void Shell04_0000();
extern void Shell04_0001();
extern void Shell04_0002();
extern void Shell04_0003();
extern void Shell04_0004();
extern void Shell04_0005();
extern void Shell04_0006();
extern void Shell04_0007();
extern void Shell04_0008();
extern void Shell04_0009();
extern void Shell04_0010();
extern void Shell04_0011();

void (*const Shell04_Tbl[12])() = {
    (void (*)())Shell04_0000,
    (void (*)())Shell04_0001,
    (void (*)())Shell04_0002,
    (void (*)())Shell04_0003,
    (void (*)())Shell04_0004,
    (void (*)())Shell04_0005,
    (void (*)())Shell04_0006,
    (void (*)())Shell04_0007,
    (void (*)())Shell04_0008,
    (void (*)())Shell04_0009,
    (void (*)())Shell04_0010,
    (void (*)())Shell04_0011,
};
