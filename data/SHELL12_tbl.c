/*
 * SHELL12_TBL.C  tables read by SHELL12.c: CPU anti-projectile patterns, table 12
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell12_Tbl[])();
extern void Shell12_0000();
extern void Shell12_0001();
extern void Shell12_0002();
extern void Shell12_0003();
extern void Shell12_0004();
extern void Shell12_0005();
extern void Shell12_0006();
extern void Shell12_0007();
extern void Shell12_0008();
extern void Shell12_0009();
extern void Shell12_0010();

void (*const Shell12_Tbl[11])() = {
    (void (*)())Shell12_0000,
    (void (*)())Shell12_0001,
    (void (*)())Shell12_0002,
    (void (*)())Shell12_0003,
    (void (*)())Shell12_0004,
    (void (*)())Shell12_0005,
    (void (*)())Shell12_0006,
    (void (*)())Shell12_0007,
    (void (*)())Shell12_0008,
    (void (*)())Shell12_0009,
    (void (*)())Shell12_0010,
};
