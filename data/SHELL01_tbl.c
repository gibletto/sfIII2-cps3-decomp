/*
 * SHELL01_TBL.C  tables read by SHELL01.c: CPU anti-projectile patterns, table 01
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell01_Tbl[])();
extern void Shell01_0000();
extern void Shell01_0001();
extern void Shell01_0002();
extern void Shell01_0003();
extern void Shell01_0004();
extern void Shell01_0005();
extern void Shell01_0006();
extern void Shell01_0007();
extern void Shell01_0008();
extern void Shell01_0009();

void (*const Shell01_Tbl[10])() = {
    (void (*)())Shell01_0000,
    (void (*)())Shell01_0001,
    (void (*)())Shell01_0002,
    (void (*)())Shell01_0003,
    (void (*)())Shell01_0004,
    (void (*)())Shell01_0005,
    (void (*)())Shell01_0006,
    (void (*)())Shell01_0007,
    (void (*)())Shell01_0008,
    (void (*)())Shell01_0009,
};
