/*
 * SHELL01_TBL.C  CPU anti-projectile pattern table 01 (Alex)
 *
 * Shell01_Tbl lists the Shell01_nnnn pattern routines the computer-controlled Alex runs when
 * the opponent fires a projectile, indexed by Pattern_Index. Read by SHELL01.C.
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
    Shell01_0000,
    Shell01_0001,
    Shell01_0002,
    Shell01_0003,
    Shell01_0004,
    Shell01_0005,
    Shell01_0006,
    Shell01_0007,
    Shell01_0008,
    Shell01_0009,
};
