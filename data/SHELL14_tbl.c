/*
 * SHELL14_TBL.C  CPU anti-projectile pattern table 14
 *
 * Shell14_Tbl lists the Shell14_nnnn pattern routines the computer-controlled Gouki and Shin
 * Gouki run when the opponent fires a projectile, indexed by Pattern_Index. Read by SHELL14.C.
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
    Shell14_0000,
    Shell14_0001,
    Shell14_0002,
    Shell14_0003,
    Shell14_0004,
    Shell14_0005,
    Shell14_0006,
    Shell14_0007,
    Shell14_0008,
    Shell14_0009,
    Shell14_0010,
    Shell14_0011,
    Shell14_0012,
};
