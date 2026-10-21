/*
 * ACTIVE06.C  CPU active patterns for player 06 (Hugo)
 *
 * Behaviour patterns for the computer-controlled player 06 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer06, which runs the pattern chosen in Pattern_Index
 * through Pattern06_Tbl. Each Pattern06_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active06.h"



/* 2i 0602818C, 3s-reloc: sf3 src/active06.c:20 Computer06 */
void Computer06(PLW* wk) {
    Pattern06_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 060281A4, 3s-reloc: sf3 src/active06.c:26 Pattern06_0000 */
void Pattern06_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Off(wk);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060281CC, 3s-reloc: sf3 src/active06.c:42 Pattern06_0001 */
void Pattern06_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060281FE, 3s-reloc: sf3 src/active06.c:55 Pattern06_0002 */
void Pattern06_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 4, 5, 6, 6);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028232, 3s-reloc: sf3 src/active06.c:68 Pattern06_0003 */
void Pattern06_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028264, 3s-reloc: sf3 src/active06.c:81 Pattern06_0004 */
void Pattern06_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8215, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028296, 3s-reloc: sf3 src/active06.c:94 Pattern06_0005 */
void Pattern06_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8215, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060282C8, 3s-reloc: sf3 src/active06.c:107 Pattern06_0006 */
void Pattern06_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8215, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060282FA, 3s-near: sf3 src/active06.c:120 Pattern06_0007 */
void Pattern06_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8004, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602834E, 3s-near: sf3 src/active06.c:139 Pattern06_0008 */
void Pattern06_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8004, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060283E0, 3s-near: sf3 src/active06.c:158 Pattern06_0009 */
void Pattern06_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028422, 3s-near: sf3 src/active06.c:174 Pattern06_0010 */
void Pattern06_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028464, 3s-near: sf3 src/active06.c:190 Pattern06_0011 */
void Pattern06_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060284A6, 3s-near: sf3 src/active06.c:206 Pattern06_0012 */
void Pattern06_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060284FC, 3s-reloc: sf3 src/active06.c:222 Pattern06_0013 */
void Pattern06_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602851C, 3s-reloc: sf3 src/active06.c:235 Pattern06_0014 */
void Pattern06_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602853C, 3s-near: sf3 src/active06.c:248 Pattern06_0015 */
void Pattern06_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602855C, 3s-reloc: sf3 src/active06.c:261 Pattern06_0016 */
void Pattern06_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602857C, 3s-reloc: sf3 src/active06.c:274 Pattern06_0017 */
void Pattern06_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602859C, 3s-reloc: sf3 src/active06.c:287 Pattern06_0018 */
void Pattern06_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060285E0, 3s-near: sf3 src/active06.c:303 Pattern06_0019 */
void Pattern06_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028616, 3s-near: sf3 src/active06.c:316 Pattern06_0020 */
void Pattern06_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028636, 3s-near: sf3 src/active06.c:329 Pattern06_0021 */
void Pattern06_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028656, 3s-near: sf3 src/active06.c:342 Pattern06_0022 */
void Pattern06_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028676, 3s-near: sf3 src/active06.c:355 Pattern06_0023 */
void Pattern06_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028696, 3s-near: sf3 src/active06.c:368 Pattern06_0024 */
void Pattern06_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060286B6, 3s-near: sf3 src/active06.c:381 Pattern06_0025 */
void Pattern06_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x70, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028718, 3s-reloc: sf3 src/active06.c:397 Pattern06_0026 */
void Pattern06_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x68, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028758, 3s-reloc: sf3 src/active06.c:413 Pattern06_0027 */
void Pattern06_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028798, 3s-near: sf3 src/active06.c:429 Pattern06_0028 */
void Pattern06_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060287CA, 3s-near: sf3 src/active06.c:442 Pattern06_0029 */
void Pattern06_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060287FC, 3s-near: sf3 src/active06.c:455 Pattern06_0030 */
void Pattern06_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602882E, 3s-near: sf3 src/active06.c:468 Pattern06_0031 */
void Pattern06_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028860, 3s-near: sf3 src/active06.c:481 Pattern06_0032 */
void Pattern06_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028892, 3s-near: sf3 src/active06.c:494 Pattern06_0033 */
void Pattern06_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060288C4, 3s-near: sf3 src/active06.c:507 Pattern06_0034 */
void Pattern06_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060288F6, 3s-near: sf3 src/active06.c:520 Pattern06_0035 */
void Pattern06_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028928, 3s-near: sf3 src/active06.c:533 Pattern06_0036 */
void Pattern06_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602896A, 3s-near: sf3 src/active06.c:546 Pattern06_0037 */
void Pattern06_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8058, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060289AC, 3s-near: sf3 src/active06.c:559 Pattern06_0038 */
void Pattern06_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8078, 0x8040, 9, 0x200, 0, 0x8078, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060289EE, 3s-near: sf3 src/active06.c:572 Pattern06_0039 */
void Pattern06_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8098, 0x8040, 9, 0x100, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028A30, 3s-near: sf3 src/active06.c:585 Pattern06_0040 */
void Pattern06_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8098, 0x8040, 9, 0x200, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028A96, 3s-near: sf3 src/active06.c:598 Pattern06_0041 */
void Pattern06_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xB, 0x20, 0xA, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028AF6, 3s-near: sf3 src/active06.c:620 Pattern06_0042 */
void Pattern06_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xB, 0x20, 0xA, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028B78, 3s-reloc: sf3 src/active06.c:642 Pattern06_0043 */
void Pattern06_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028BB8, 3s-reloc: sf3 src/active06.c:658 Pattern06_0044 */
void Pattern06_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028BD8, 3s-near: sf3 src/active06.c:671 Pattern06_0045 */
void Pattern06_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028BF8, 3s-near: sf3 src/active06.c:684 Pattern06_0046 */
void Pattern06_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028C18, 3s-near: sf3 src/active06.c:697 Pattern06_0047 */
void Pattern06_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028C94, 3s-near: sf3 src/active06.c:719 Pattern06_0048 */
void Pattern06_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028CE6, 3s-near: sf3 src/active06.c:738 Pattern06_0049 */
void Pattern06_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028D18, 3s-near: sf3 src/active06.c:751 Pattern06_0050 */
void Pattern06_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028D6A, 3s-near: sf3 src/active06.c:770 Pattern06_0051 */
void Pattern06_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028D8A, 3s-near: sf3 src/active06.c:783 Pattern06_0052 */
void Pattern06_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028DBE, 3s-near: sf3 src/active06.c:796 Pattern06_0053 */
void Pattern06_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028DE2, 3s-near: sf3 src/active06.c:812 Pattern06_0054 */
void Pattern06_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028E1A, 3s-near: sf3 src/active06.c:831 Pattern06_0055 */
void Pattern06_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x2F, 0x30, 0x35, 0x36, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028E54, 3s-near: sf3 src/active06.c:844 Pattern06_0056 */
void Pattern06_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 8, 0x42, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028ECC, 3s-near: sf3 src/active06.c:860 Pattern06_0057 */
void Pattern06_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 9, 0x42, 0, 0x8098, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 3:
        Wait(wk, 0xA);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

