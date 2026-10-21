/*
 * SHELL07.C  CPU anti-projectile patterns, table 07
 *
 * Behaviour patterns used by the computer-controlled player when the opponent fires a
 * projectile (VS Shell mode). Com_VS_Shell in Com_Pl calls Shell07 for player 7 (Ibuki);
 * it runs the pattern in Pattern_Index through Shell07_Tbl. Each Shell07_nnnn routine is
 * a script stepped by CP_Index: SHELL_Term waits for the projectile, then the player jumps or
 * jump-attacks over it, follows up with normal or command attacks and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "SHELL07.h"



/* 2i 060785D4, 3s-exact: sf3 src/SHELL07.c:20 Shell07 */
void Shell07(PLW* wk) {
    Shell07_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 060785EC, 3s-exact: sf3 src/SHELL07.c:26 Shell07_0000 */
void Shell07_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06078600, 3s-exact: sf3 src/SHELL07.c:36 Shell07_0001 */
void Shell07_0001(PLW* wk) {
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



/* 2i 06078640, 3s-exact: sf3 src/SHELL07.c:52 Shell07_0002 */
void Shell07_0002(PLW* wk) {
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



/* 2i 06078680, 3s-reloc: sf3 src/SHELL07.c:68 Shell07_0003 */
void Shell07_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607871A, 3s-exact: sf3 src/SHELL07.c:90 Shell07_0004 */
void Shell07_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06078788, 3s-reloc: sf3 src/SHELL07.c:109 Shell07_0005 */
void Shell07_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607881C, 3s-exact: sf3 src/SHELL07.c:128 Shell07_0006 */
void Shell07_0006(PLW* wk) {
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



/* 2i 06078874, 3s-exact: sf3 src/SHELL07.c:144 Shell07_0007 */
void Shell07_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060788A6, 3s-near: sf3 src/SHELL07.c:157 Shell07_0008 */
void Shell07_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 0xB, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06078938, 3s-near: sf3 src/SHELL07.c:176 Shell07_0009 */
void Shell07_0009(PLW* wk) {
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



/* 2i 06078978, 3s-near: sf3 src/SHELL07.c:195 Shell07_0010 */
void Shell07_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607898C, 3s-near: sf3 src/SHELL07.c:205 Shell07_0011 */
void Shell07_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
