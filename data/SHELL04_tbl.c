/*
 * SHELL04_TBL.C  CPU anti-projectile pattern table 04 (Dudley)
 *
 * Shell04_Tbl lists the Shell04_nnnn pattern routines the computer-controlled Dudley runs when
 * the opponent fires a projectile, indexed by Pattern_Index. Read by SHELL04.C.
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
    Shell04_0000,
    Shell04_0001,
    Shell04_0002,
    Shell04_0003,
    Shell04_0004,
    Shell04_0005,
    Shell04_0006,
    Shell04_0007,
    Shell04_0008,
    Shell04_0009,
    Shell04_0010,
    Shell04_0011,
};
