/*
 * SHELL04.C  CPU anti-projectile patterns, table 04
 *
 * Behaviour patterns used by the computer-controlled player when the opponent fires a
 * projectile (VS Shell mode). Com_VS_Shell in Com_Pl calls Shell04 for player 4 (Dudley);
 * it runs the pattern in Pattern_Index through Shell04_Tbl. Each Shell04_nnnn routine is
 * a script stepped by CP_Index: SHELL_Term waits for the projectile, then the player jumps or
 * jump-attacks over it, follows up with normal or command attacks and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "SHELL04.h"



/* 2i 06077D90, 3s-exact: sf3 src/SHELL04.c:20 Shell04 */
void Shell04(PLW* wk) {
    Shell04_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06077DA8, 3s-exact: sf3 src/SHELL04.c:26 Shell04_0000 */
void Shell04_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077DBC, 3s-exact: sf3 src/SHELL04.c:36 Shell04_0001 */
void Shell04_0001(PLW* wk) {
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



/* 2i 06077DFC, 3s-exact: sf3 src/SHELL04.c:52 Shell04_0002 */
void Shell04_0002(PLW* wk) {
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



/* 2i 06077E3C, 3s-reloc: sf3 src/SHELL04.c:68 Shell04_0003 */
void Shell04_0003(PLW* wk) {
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
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077ED6, 3s-exact: sf3 src/SHELL04.c:90 Shell04_0004 */
void Shell04_0004(PLW* wk) {
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



/* 2i 06077F44, 3s-reloc: sf3 src/SHELL04.c:109 Shell04_0005 */
void Shell04_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077FDC, 3s-exact: sf3 src/SHELL04.c:128 Shell04_0006 */
void Shell04_0006(PLW* wk) {
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



/* 2i 06078034, 3s-exact: sf3 src/SHELL04.c:144 Shell04_0007 */
void Shell04_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 3, 2, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06078080, 3s-reloc: sf3 src/SHELL04.c:160 Shell04_0008 */
void Shell04_0008(PLW* wk) {
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



/* 2i 06078116, 3s-near: sf3 src/SHELL04.c:179 Shell04_0009 */
void Shell04_0009(PLW* wk) {
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



/* 2i 06078156, 3s-reloc: sf3 src/SHELL04.c:198 Shell04_0010 */
void Shell04_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607816A, 3s-near: sf3 src/SHELL04.c:208 Shell04_0011 */
void Shell04_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 3, 2, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
