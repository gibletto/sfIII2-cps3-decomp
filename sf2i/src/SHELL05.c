/*
 * SHELL05.C  CPU anti-projectile patterns, table 05
 *
 * Behaviour patterns used by the computer-controlled player when the opponent fires a
 * projectile (VS Shell mode). Com_VS_Shell in Com_Pl calls Shell05 for player 5 (Necro);
 * it runs the pattern in Pattern_Index through Shell05_Tbl. Each Shell05_nnnn routine is
 * a script stepped by CP_Index: SHELL_Term waits for the projectile, then the player jumps or
 * jump-attacks over it, follows up with normal or command attacks and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "SHELL05.h"



/* 2i 060781E0, 3s-exact: sf3 src/SHELL05.c:20 Shell05 */
void Shell05(PLW* wk) {
    Shell05_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 060781F8, 3s-exact: sf3 src/SHELL05.c:26 Shell05_0000 */
void Shell05_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607820C, 3s-exact: sf3 src/SHELL05.c:36 Shell05_0001 */
void Shell05_0001(PLW* wk) {
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



/* 2i 0607824C, 3s-exact: sf3 src/SHELL05.c:52 Shell05_0002 */
void Shell05_0002(PLW* wk) {
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



/* 2i 0607828C, 3s-reloc: sf3 src/SHELL05.c:68 Shell05_0003 */
void Shell05_0003(PLW* wk) {
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



/* 2i 06078326, 3s-exact: sf3 src/SHELL05.c:90 Shell05_0004 */
void Shell05_0004(PLW* wk) {
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



/* 2i 06078394, 3s-reloc: sf3 src/SHELL05.c:109 Shell05_0005 */
void Shell05_0005(PLW* wk) {
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



/* 2i 0607842C, 3s-exact: sf3 src/SHELL05.c:128 Shell05_0006 */
void Shell05_0006(PLW* wk) {
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



/* 2i 06078484, 3s-exact: sf3 src/SHELL05.c:144 Shell05_0007 */
void Shell05_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x50, 8, 0x102, 2, 0x8080, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060784C6, 3s-near: sf3 src/SHELL05.c:157 Shell05_0008 */
void Shell05_0008(PLW* wk) {
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



/* 2i 0607855C, 3s-near: sf3 src/SHELL05.c:176 Shell05_0009 */
void Shell05_0009(PLW* wk) {
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



/* 2i 0607859C, 3s-near: sf3 src/SHELL05.c:195 Shell05_0010 */
void Shell05_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}
