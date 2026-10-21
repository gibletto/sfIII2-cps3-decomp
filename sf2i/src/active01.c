/*
 * ACTIVE01.C  CPU active patterns for player 01 (Alex)
 *
 * Behaviour patterns for the computer-controlled player 01 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer01, which runs the pattern chosen in Pattern_Index
 * through Pattern01_Tbl. Each Pattern01_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active01.h"



/* 2i 06022B6C, 3s-exact: sf3 src/active01.c:20 Computer01 */
void Computer01(PLW* wk) {
    Pattern01_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06022B84, 3s-exact: sf3 src/active01.c:26 Pattern01_0000 */
void Pattern01_0000(PLW* wk) {
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



/* 2i 06022BAC, 3s-exact: sf3 src/active01.c:42 Pattern01_0001 */
void Pattern01_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022BD0, 3s-exact: sf3 src/active01.c:58 Pattern01_0002 */
void Pattern01_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x45, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022C10, 3s-exact: sf3 src/active01.c:74 Pattern01_0003 */
void Pattern01_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022C3C, 3s-reloc: sf3 src/active01.c:90 Pattern01_0004 */
void Pattern01_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022C9A, 3s-near: sf3 src/active01.c:103 Pattern01_0005 */
void Pattern01_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022CC8, 3s-near: sf3 src/active01.c:119 Pattern01_0006 */
void Pattern01_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022CE6, 3s-near: sf3 src/active01.c:132 Pattern01_0007 */
void Pattern01_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022D3E, 3s-reloc: sf3 src/active01.c:151 Pattern01_0008 */
void Pattern01_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022D88, 3s-exact: sf3 src/active01.c:164 Pattern01_0009 */
void Pattern01_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x10);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022DBE, 3s-exact: sf3 src/active01.c:183 Pattern01_0010 */
void Pattern01_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022DDE, 3s-exact: sf3 src/active01.c:196 Pattern01_0011 */
void Pattern01_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022DFE, 3s-exact: sf3 src/active01.c:209 Pattern01_0012 */
void Pattern01_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022E1E, 3s-exact: sf3 src/active01.c:222 Pattern01_0013 */
void Pattern01_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022E40, 3s-reloc: sf3 src/active01.c:235 Pattern01_0014 */
void Pattern01_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022EA2, 3s-exact: sf3 src/active01.c:248 Pattern01_0015 */
void Pattern01_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022EC4, 3s-exact: sf3 src/active01.c:261 Pattern01_0016 */
void Pattern01_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022EE6, 3s-exact: sf3 src/active01.c:274 Pattern01_0017 */
void Pattern01_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022F18, 3s-exact: sf3 src/active01.c:287 Pattern01_0018 */
void Pattern01_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022F4A, 3s-reloc: sf3 src/active01.c:300 Pattern01_0019 */
void Pattern01_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022F94, 3s-exact: sf3 src/active01.c:313 Pattern01_0020 */
void Pattern01_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 1:
        Jump_Attack(wk, 8, 0xA, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022FDC, 3s-exact: sf3 src/active01.c:329 Pattern01_0021 */
void Pattern01_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8060, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602301E, 3s-exact: sf3 src/active01.c:342 Pattern01_0022 */
void Pattern01_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xF, 0x40, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023050, 3s-exact: sf3 src/active01.c:355 Pattern01_0023 */
void Pattern01_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023070, 3s-reloc: sf3 src/active01.c:368 Pattern01_0024 */
void Pattern01_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060230B8, 3s-exact: sf3 src/active01.c:381 Pattern01_0025 */
void Pattern01_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060230DA, 3s-exact: sf3 src/active01.c:394 Pattern01_0026 */
void Pattern01_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023118, 3s-exact: sf3 src/active01.c:410 Pattern01_0027 */
void Pattern01_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023136, 3s-exact: sf3 src/active01.c:423 Pattern01_0028 */
void Pattern01_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023156, 3s-reloc: sf3 src/active01.c:436 Pattern01_0029 */
void Pattern01_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x100);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060231C4, 3s-exact: sf3 src/active01.c:455 Pattern01_0030 */
void Pattern01_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060231F0, 3s-exact: sf3 src/active01.c:471 Pattern01_0031 */
void Pattern01_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023240, 3s-exact: sf3 src/active01.c:487 Pattern01_0032 */
void Pattern01_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023280, 3s-reloc: sf3 src/active01.c:503 Pattern01_0033 */
void Pattern01_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060232E4, 3s-exact: sf3 src/active01.c:519 Pattern01_0034 */
void Pattern01_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x82);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x82);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023322, 3s-exact: sf3 src/active01.c:538 Pattern01_0035 */
void Pattern01_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023342, 3s-exact: sf3 src/active01.c:551 Pattern01_0036 */
void Pattern01_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023362, 3s-exact: sf3 src/active01.c:564 Pattern01_0037 */
void Pattern01_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060233A4, 3s-reloc: sf3 src/active01.c:580 Pattern01_0038 */
void Pattern01_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060233FC, 3s-exact: sf3 src/active01.c:599 Pattern01_0039 */
void Pattern01_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023444, 3s-exact: sf3 src/active01.c:615 Pattern01_0040 */
void Pattern01_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023484, 3s-reloc: sf3 src/active01.c:631 Pattern01_0041 */
void Pattern01_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060234E0, 3s-reloc: sf3 src/active01.c:647 Pattern01_0042 */
void Pattern01_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602351C, 3s-near: sf3 src/active01.c:666 Pattern01_0043 */
void Pattern01_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 8, 0x100, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023560, 3s-near: sf3 src/active01.c:694 Pattern01_0044 */
void Pattern01_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8040, 8, 0x20, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060235A4, 3s-near: sf3 src/active01.c:719 Pattern01_0045 */
void Pattern01_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x100, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602360C, 3s-near: sf3 src/active01.c:744 Pattern01_0046 */
void Pattern01_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602363E, 3s-near: sf3 src/active01.c:757 Pattern01_0047 */
void Pattern01_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023670, 3s-near: sf3 src/active01.c:770 Pattern01_0048 */
void Pattern01_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x31, 0x32, 0x33);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060236A6, 3s-near: sf3 src/active01.c:783 Pattern01_0049 */
void Pattern01_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060236D8, 3s-near: sf3 src/active01.c:796 Pattern01_0050 */
void Pattern01_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602370A, 3s-near: sf3 src/active01.c:809 Pattern01_0051 */
void Pattern01_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602373C, 3s-reloc: sf3 src/active01.c:822 Pattern01_0052 */
void Pattern01_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x45, 2);
        break;
    case 1:
        SA_Term(wk, 0x2E, -1, -1, 0x45);
        break;
    case 2:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060237A8, 3s-reloc: sf3 src/active01.c:844 Pattern01_0053 */
void Pattern01_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x45, 2);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0x45);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602383C, 3s-near: sf3 src/active01.c:866 Pattern01_0054 */
void Pattern01_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xC3, 2);
        break;
    case 2:
        Jump_Attack(wk, 8, 0xC, 0x42, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023892, 3s-near: sf3 src/active01.c:885 Pattern01_0055 */
void Pattern01_0055(PLW* wk) {
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



/* 2i 060238BA, 3s-near: sf3 src/active01.c:901 Pattern01_0056 */
void Pattern01_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060238EC, 3s-near: sf3 src/active01.c:914 Pattern01_0057 */
void Pattern01_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602391E, 3s-near: sf3 src/active01.c:927 Pattern01_0058 */
void Pattern01_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023972, 3s-near: sf3 src/active01.c:940 Pattern01_0059 */
void Pattern01_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060239A4, 3s-near: sf3 src/active01.c:953 Pattern01_0060 */
void Pattern01_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060239D6, 3s-near: sf3 src/active01.c:966 Pattern01_0061 */
void Pattern01_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

