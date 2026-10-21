/*
 * ACTIVE10.C  CPU active patterns for player 10 (Yang)
 *
 * Behaviour patterns for the computer-controlled player 10 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer10, which runs the pattern chosen in Pattern_Index
 * through Pattern10_Tbl. Each Pattern10_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active10.h"


/* 2i 0602CEDC, 3s-reloc: sf3 src/active10.c:19 Computer10 */
void Computer10(PLW* wk) {
    Pattern10_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0602CEF4, 3s-reloc: sf3 src/active10.c:25 Pattern10_0000 */
void Pattern10_0000(PLW* wk) {
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


/* 2i 0602CF1C, 3s-reloc: sf3 src/active10.c:40 Pattern10_0001 */
void Pattern10_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CF40, 3s-reloc: sf3 src/active10.c:54 Pattern10_0002 */
void Pattern10_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CF76, 3s-reloc: sf3 src/active10.c:67 Pattern10_0003 */
void Pattern10_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CFA2, 3s-near: sf3 src/active10.c:83 Pattern10_0004 */
void Pattern10_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CFD4, 3s-near: sf3 src/active10.c:96 Pattern10_0005 */
void Pattern10_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CFF6, 3s-near: sf3 src/active10.c:109 Pattern10_0006 */
void Pattern10_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D014, 3s-near: sf3 src/active10.c:122 Pattern10_0007 */
void Pattern10_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 1);
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



/* 2i 0602D06C, 3s-near: sf3 src/active10.c:141 Pattern10_0008 */
void Pattern10_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D0D2, 3s-near: sf3 src/active10.c:157 Pattern10_0009 */
void Pattern10_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0x10);
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



/* 2i 0602D108, 3s-reloc: sf3 src/active10.c:176 Pattern10_0010 */
void Pattern10_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D128, 3s-reloc: sf3 src/active10.c:189 Pattern10_0011 */
void Pattern10_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D154, 3s-reloc: sf3 src/active10.c:205 Pattern10_0012 */
void Pattern10_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D174, 3s-near: sf3 src/active10.c:218 Pattern10_0013 */
void Pattern10_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D1C0, 3s-near: sf3 src/active10.c:231 Pattern10_0014 */
void Pattern10_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x20, 2, 0x8060, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D202, 3s-near: sf3 src/active10.c:244 Pattern10_0015 */
void Pattern10_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D224, 3s-reloc: sf3 src/active10.c:257 Pattern10_0016 */
void Pattern10_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D254, 3s-near: sf3 src/active10.c:273 Pattern10_0017 */
void Pattern10_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 8, -1);
        break;
    case 2:
        Wait(wk, 0xe);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 8, -1);
        break;
    case 4:
        Wait(wk, 0xe);
        break;
    case 5:
        Command_Attack(wk, 0xe, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D2C6, 3s-reloc: sf3 src/active10.c:301 Pattern10_0018 */
void Pattern10_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, (0x8200), 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D2F8, 3s-near: sf3 src/active10.c:314 Pattern10_0019 */
void Pattern10_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 9, -1);
        break;
    case 2:
        Wait(wk, 0xe);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 9, -1);
        break;
    case 4:
        Wait(wk, 0xe);
        break;
    case 5:
        Command_Attack(wk, 0xe, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D36A, 3s-near: sf3 src/active10.c:342 Pattern10_0020 */
void Pattern10_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D3DE, 3s-exact: sf3 src/active10.c:358 Pattern10_0021 */
void Pattern10_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D420, 3s-exact: sf3 src/active10.c:371 Pattern10_0022 */
void Pattern10_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8050, -1, 8, (0x8080), 0, 0x8060, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D462, 3s-exact: sf3 src/active10.c:384 Pattern10_0023 */
void Pattern10_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D482, 3s-reloc: sf3 src/active10.c:397 Pattern10_0024 */
void Pattern10_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x20, 2, 0x8060, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D4F6, 3s-exact: sf3 src/active10.c:410 Pattern10_0025 */
void Pattern10_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D526, 3s-exact: sf3 src/active10.c:426 Pattern10_0026 */
void Pattern10_0026(PLW* wk) {
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



/* 2i 0602D564, 3s-exact: sf3 src/active10.c:442 Pattern10_0027 */
void Pattern10_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D582, 3s-exact: sf3 src/active10.c:455 Pattern10_0028 */
void Pattern10_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D5A2, 3s-reloc: sf3 src/active10.c:468 Pattern10_0029 */
void Pattern10_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, (0x80));
        break;
    case 1:
        Adjust_Attack(wk, 0xC, (0x80));
        break;
    case 2:
        Adjust_Attack(wk, 0xC, (0x102));
        break;
    case 3:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D622, 3s-near: sf3 src/active10.c:490 Pattern10_0030 */
void Pattern10_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D67E, 3s-exact: sf3 src/active10.c:512 Pattern10_0031 */
void Pattern10_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 0x33);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D6C0, 3s-near: sf3 src/active10.c:528 Pattern10_0032 */
void Pattern10_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D722, 3s-near: sf3 src/active10.c:544 Pattern10_0033 */
void Pattern10_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D750, 3s-near: sf3 src/active10.c:560 Pattern10_0034 */
void Pattern10_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, (0x82));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D790, 3s-near: sf3 src/active10.c:576 Pattern10_0035 */
void Pattern10_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D7B0, 3s-near: sf3 src/active10.c:589 Pattern10_0036 */
void Pattern10_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D7D0, 3s-near: sf3 src/active10.c:602 Pattern10_0037 */
void Pattern10_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D82E, 3s-exact: sf3 src/active10.c:618 Pattern10_0038 */
void Pattern10_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, (0x102));
        break;
    case 2:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D880, 3s-near: sf3 src/active10.c:637 Pattern10_0039 */
void Pattern10_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D8CC, 3s-near: sf3 src/active10.c:653 Pattern10_0040 */
void Pattern10_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D928, 3s-near: sf3 src/active10.c:669 Pattern10_0041 */
void Pattern10_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x42);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xe, 0x1F, 8, -1);
        break;
    case 3:
        Wait(wk, 0xe);
        break;
    case 4:
        Command_Attack(wk, 0xe, 0x1F, 8, -1);
        break;
    case 5:
        Wait(wk, 0xe);
        break;
    case 6:
        Command_Attack(wk, 0xe, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D9AC, 3s-exact: sf3 src/active10.c:700 Pattern10_0042 */
void Pattern10_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602D9F2, 3s-reloc: sf3 src/active10.c:719 Pattern10_0043 */
void Pattern10_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 8, 8, 0x8200, 0, -1, 0x8060, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DA4E, 3s-exact: sf3 src/active10.c:732 Pattern10_0044 */
void Pattern10_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 0, 0x8060, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DA90, 3s-exact: sf3 src/active10.c:745 Pattern10_0045 */
void Pattern10_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x14, 0);
        break;
    case 1:
        Walk(wk, 1, 0x16, 0);
        break;
    case 2:
        Walk(wk, 0, 0x18, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DADC, 3s-exact: sf3 src/active10.c:764 Pattern10_0046 */
void Pattern10_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DB0E, 3s-reloc: sf3 src/active10.c:777 Pattern10_0047 */
void Pattern10_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DB66, 3s-exact: sf3 src/active10.c:790 Pattern10_0048 */
void Pattern10_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DB98, 3s-near: sf3 src/active10.c:803 Pattern10_0049 */
void Pattern10_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DBCA, 3s-near: sf3 src/active10.c:816 Pattern10_0050 */
void Pattern10_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DBFC, 3s-near: sf3 src/active10.c:829 Pattern10_0051 */
void Pattern10_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DC2E, 3s-near: sf3 src/active10.c:842 Pattern10_0052 */
void Pattern10_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DC76, 3s-near: sf3 src/active10.c:858 Pattern10_0053 */
void Pattern10_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0x8040);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0x8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DCBE, 3s-exact: sf3 src/active10.c:874 Pattern10_0054 */
void Pattern10_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 48, 0);
        break;
    case 1:
        {
            s16 range = 8;
            Hi_Jump_Attack_Term(wk, 0x8050, range, range, (0x8200), 0, 0x8060, range, 0x20);
        }
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DD1A, 3s-reloc: sf3 src/active10.c:893 Pattern10_0055 */
void Pattern10_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DD90, 3s-exact: sf3 src/active10.c:906 Pattern10_0056 */
void Pattern10_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x31, 4, 5, 1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DDE0, 3s-exact: sf3 src/active10.c:922 Pattern10_0057 */
void Pattern10_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x12);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 1, 0x8060, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DE32, 3s-reloc: sf3 src/active10.c:938 Pattern10_0058 */
void Pattern10_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0x11);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 1, 0x8060, 8, 0x100);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 4:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DEE8, 3s-exact: sf3 src/active10.c:963 Pattern10_0059 */
void Pattern10_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0x11);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 4:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602DF66, 3s-reloc: sf3 src/active10.c:988 Pattern10_0060 */
void Pattern10_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x100, 0, -1, -1, -1);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 4:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E010, 3s-exact: sf3 src/active10.c:1013 Pattern10_0061 */
void Pattern10_0061(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 11, none);
        break;
    case 3:
        Hi_Jump_Attack_Term(wk, 0x8060, none, 8, (0x8200), 0, 0x8060, none, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E086, 3s-reloc: sf3 src/active10.c:1036 Pattern10_0062 */
void Pattern10_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 0, 0x8060, 8, 0x100);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E114, 3s-near: sf3 src/active10.c:1052 Pattern10_0063 */
void Pattern10_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E156, 3s-exact: sf3 src/active10.c:1068 Pattern10_0064 */
void Pattern10_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E1B8, 3s-near: sf3 src/active10.c:1090 Pattern10_0065 */
void Pattern10_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E212, 3s-reloc: sf3 src/active10.c:1106 Pattern10_0066 */
void Pattern10_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x2D, 0x19, 0x10, 0x17, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E24C, 3s-reloc: sf3 src/active10.c:1119 Pattern10_0067 */
void Pattern10_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
