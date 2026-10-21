/*
 * SHELL14_TBL.C  tables read by SHELL14.c: CPU anti-projectile patterns, table 14
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell14_Tbl[])();
extern void Shell14_0000();
extern void Shell14_0001();
extern void Shell14_0002();
extern void Shell14_0003();
extern void Shell14_0004();
extern void Shell14_0005();
extern void Shell14_0006();
extern void Shell14_0007();
extern void Shell14_0008();
extern void Shell14_0009();
extern void Shell14_0010();
extern void Shell14_0011();
extern void Shell14_0012();

void (*const Shell14_Tbl[13])() = {
    (void (*)())Shell14_0000,
    (void (*)())Shell14_0001,
    (void (*)())Shell14_0002,
    (void (*)())Shell14_0003,
    (void (*)())Shell14_0004,
    (void (*)())Shell14_0005,
    (void (*)())Shell14_0006,
    (void (*)())Shell14_0007,
    (void (*)())Shell14_0008,
    (void (*)())Shell14_0009,
    (void (*)())Shell14_0010,
    (void (*)())Shell14_0011,
    (void (*)())Shell14_0012,
};
