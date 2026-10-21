/*
 * SHELL03_TBL.C  tables read by SHELL03.c: CPU anti-projectile patterns, table 03
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell03_Tbl[])();
extern void Shell03_0000();
extern void Shell03_0001();
extern void Shell03_0002();
extern void Shell03_0003();
extern void Shell03_0004();
extern void Shell03_0005();
extern void Shell03_0006();
extern void Shell03_0007();
extern void Shell03_0008();
extern void Shell03_0009();
extern void Shell03_0010();

void (*const Shell03_Tbl[11])() = {
    (void (*)())Shell03_0000,
    (void (*)())Shell03_0001,
    (void (*)())Shell03_0002,
    (void (*)())Shell03_0003,
    (void (*)())Shell03_0004,
    (void (*)())Shell03_0005,
    (void (*)())Shell03_0006,
    (void (*)())Shell03_0007,
    (void (*)())Shell03_0008,
    (void (*)())Shell03_0009,
    (void (*)())Shell03_0010,
};
