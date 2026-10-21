/*
 * SHELL00.C  CPU anti-projectile patterns, table 00
 *
 * Behaviour patterns used by the computer-controlled player when the opponent fires a
 * projectile (VS Shell mode). Com_VS_Shell in Com_Pl calls Shell00 for player 0 (Gill);
 * it runs the pattern in Pattern_Index through Shell00_Tbl. Each Shell00_nnnn routine is
 * a script stepped by CP_Index: SHELL_Term waits for the projectile, then the player jumps or
 * jump-attacks over it, follows up with normal or command attacks and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "SHELL00.h"



/* 2i 06077264, 3s-reloc: sf3 src/SHELL00.c:20 Shell00 */
void Shell00(PLW* wk) {
    Shell00_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0607727C, 3s-reloc: sf3 src/SHELL00.c:26 Shell00_0000 */
void Shell00_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
    }
}



/* 2i 06077290, 3s-reloc: sf3 src/SHELL00.c:35 Shell00_0001 */
void Shell00_0001(PLW* wk) {
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



/* 2i 060772D0, 3s-reloc: sf3 src/SHELL00.c:51 Shell00_0002 */
void Shell00_0002(PLW* wk) {
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



/* 2i 06077310, 3s-reloc: sf3 src/SHELL13.c:68 Shell13_0003 */
void Shell00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8088, 0x8030, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060773A0, 3s-exact: sf3 src/SHELL13.c:90 Shell13_0004 */
void Shell00_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8088, 0x8030, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607740E, 3s-near: sf3 src/SHELL13.c:109 Shell13_0005 */
void Shell00_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8088, 0x8040, 0xB, (0x100), 0, 0x8050, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060774A2, 3s-exact: sf3 src/SHELL13.c:128 Shell13_0006 */
void Shell00_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 1, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x200, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060774FA, 3s-exact: sf3 src/SHELL13.c:144 Shell13_0007 */
void Shell00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607752C, 3s-reloc: sf3 src/SHELL13.c:157 Shell13_0008 */
void Shell00_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8088, 0x8030, 0xB, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060775C0, 3s-near: sf3 src/SHELL13.c:176 Shell13_0009 */
void Shell00_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 2, 2, 1, -1, -1);
        break;
    case 1:
        Next_Be_Flip(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077600, 3s-near: sf3 src/SHELL13.c:195 Shell13_0010 */
void Shell00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}
