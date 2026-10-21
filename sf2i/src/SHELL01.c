/*
 * SHELL01.C  CPU anti-projectile patterns, table 01
 *
 * Behaviour patterns used by the computer-controlled player when the opponent fires a
 * projectile (VS Shell mode). Com_VS_Shell in Com_Pl calls Shell01 for player 1 (Alex);
 * it runs the pattern in Pattern_Index through Shell01_Tbl. Each Shell01_nnnn routine is
 * a script stepped by CP_Index: SHELL_Term waits for the projectile, then the player jumps or
 * jump-attacks over it, follows up with normal or command attacks and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "SHELL01.h"



/* 2i 06077624, 3s-exact: sf3 src/SHELL01.c:20 Shell01 */
void Shell01(PLW* wk) {
    Shell01_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0607763C, 3s-exact: sf3 src/SHELL01.c:26 Shell01_0000 */
void Shell01_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077650, 3s-exact: sf3 src/SHELL01.c:36 Shell01_0001 */
void Shell01_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 1, 2, 1, -1, -1);
        break;
    case 1:
        Jump(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077690, 3s-exact: sf3 src/SHELL01.c:52 Shell01_0002 */
void Shell01_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060776D0, 3s-reloc: sf3 src/SHELL01.c:68 Shell01_0003 */
void Shell01_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x30, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607774C, 3s-exact: sf3 src/SHELL01.c:84 Shell01_0004 */
void Shell01_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060777A4, 3s-exact: sf3 src/SHELL01.c:100 Shell01_0005 */
void Shell01_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x200, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060777FC, 3s-reloc: sf3 src/SHELL01.c:116 Shell01_0006 */
void Shell01_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x30, 8, 0x100, 0, -1, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077882, 3s-reloc: sf3 src/SHELL01.c:135 Shell01_0007 */
void Shell01_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060778EA, 3s-reloc: sf3 src/SHELL01.c:154 Shell01_0008 */
void Shell01_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 0xB, 0x100, 0, -1, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077952, 3s-near: sf3 src/SHELL01.c:173 Shell01_0009 */
void Shell01_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 2, 2, 1, -1, -1);
        break;
    case 1:
        Next_Be_Flip(wk, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
