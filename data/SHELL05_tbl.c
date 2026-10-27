/*
 * SHELL05_TBL.C  CPU anti-projectile pattern table 05 (Necro)
 *
 * Shell05_Tbl lists the Shell05_nnnn pattern routines the computer-controlled Necro runs when
 * the opponent fires a projectile, indexed by Pattern_Index. Read by SHELL05.C.
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
    Shell05_0000,
    Shell05_0001,
    Shell05_0002,
    Shell05_0003,
    Shell05_0004,
    Shell05_0005,
    Shell05_0006,
    Shell05_0007,
    Shell05_0008,
    Shell05_0009,
    Shell05_0010,
};
