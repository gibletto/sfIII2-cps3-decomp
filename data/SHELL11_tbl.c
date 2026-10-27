/*
 * SHELL11_TBL.C  CPU anti-projectile pattern table 11
 *
 * Shell11_Tbl lists the Shell11_nnnn pattern routines the computer-controlled Ryu and Ken run
 * when the opponent fires a projectile, indexed by Pattern_Index. Read by SHELL11.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void (*const Shell11_Tbl[])();
extern void Shell11_0000();
extern void Shell11_0001();
extern void Shell11_0002();
extern void Shell11_0003();
extern void Shell11_0004();
extern void Shell11_0005();
extern void Shell11_0006();
extern void Shell11_0007();
extern void Shell11_0008();
extern void Shell11_0009();
extern void Shell11_0010();
extern void Shell11_0011();
extern void Shell11_0012();
extern void Shell11_0013();

void (*const Shell11_Tbl[14])() = {
    Shell11_0000,
    Shell11_0001,
    Shell11_0002,
    Shell11_0003,
    Shell11_0004,
    Shell11_0005,
    Shell11_0006,
    Shell11_0007,
    Shell11_0008,
    Shell11_0009,
    Shell11_0010,
    Shell11_0011,
    Shell11_0012,
    Shell11_0013,
};
