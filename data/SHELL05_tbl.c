/*
 * SHELL05_TBL.C  tables read by SHELL05.c: CPU anti-projectile patterns, table 05
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell05_Tbl[])();
extern void Shell05_0000();
extern void Shell05_0001();
extern void Shell05_0002();
extern void Shell05_0003();
extern void Shell05_0004();
extern void Shell05_0005();
extern void Shell05_0006();
extern void Shell05_0007();
extern void Shell05_0008();
extern void Shell05_0009();
extern void Shell05_0010();

void (*const Shell05_Tbl[11])() = {
    (void (*)())Shell05_0000,
    (void (*)())Shell05_0001,
    (void (*)())Shell05_0002,
    (void (*)())Shell05_0003,
    (void (*)())Shell05_0004,
    (void (*)())Shell05_0005,
    (void (*)())Shell05_0006,
    (void (*)())Shell05_0007,
    (void (*)())Shell05_0008,
    (void (*)())Shell05_0009,
    (void (*)())Shell05_0010,
};
