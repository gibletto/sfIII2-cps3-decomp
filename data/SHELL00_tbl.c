/*
 * SHELL00_TBL.C  tables read by SHELL00.c: CPU anti-projectile patterns, table 00
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell00_Tbl[])();
extern void Shell00_0000();
extern void Shell00_0001();
extern void Shell00_0002();
extern void Shell00_0003();
extern void Shell00_0004();
extern void Shell00_0005();
extern void Shell00_0006();
extern void Shell00_0007();
extern void Shell00_0008();
extern void Shell00_0009();
extern void Shell00_0010();

void (*const Shell00_Tbl[11])() = {
    (void (*)())Shell00_0000,
    (void (*)())Shell00_0001,
    (void (*)())Shell00_0002,
    (void (*)())Shell00_0003,
    (void (*)())Shell00_0004,
    (void (*)())Shell00_0005,
    (void (*)())Shell00_0006,
    (void (*)())Shell00_0007,
    (void (*)())Shell00_0008,
    (void (*)())Shell00_0009,
    (void (*)())Shell00_0010,
};
