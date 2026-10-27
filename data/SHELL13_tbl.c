/*
 * SHELL13_TBL.C  CPU anti-projectile pattern table 13 (Urien)
 *
 * Shell13_Tbl lists the Shell13_nnnn pattern routines the computer-controlled Urien runs when
 * the opponent fires a projectile, indexed by Pattern_Index. Read by SHELL13.C.
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
    Shell13_0000,
    Shell13_0001,
    Shell13_0002,
    Shell13_0003,
    Shell13_0004,
    Shell13_0005,
    Shell13_0006,
    Shell13_0007,
    Shell13_0008,
    Shell13_0009,
    Shell13_0010,
    Shell13_0011,
};
