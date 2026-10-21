/*
 * ACTIVE03.C  CPU active patterns for player 03 (Yun)
 *
 * Behaviour patterns for the computer-controlled player 03 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer03, which runs the pattern chosen in Pattern_Index
 * through Pattern03_Tbl. Each Pattern03_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active03.h"



/* 2i 06024D2C, 3s-reloc: sf3 src/active03.c:20 Computer03 */
void Computer03(PLW* wk) {
    Pattern03_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06024D44, 3s-reloc: sf3 src/active03.c:26 Pattern03_0000 */
void Pattern03_0000(PLW* wk) {
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



/* 2i 06024D6C, 3s-reloc: sf3 src/active03.c:42 Pattern03_0001 */
void Pattern03_0001(PLW* wk) {
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



/* 2i 06024D90, 3s-reloc: sf3 src/active03.c:58 Pattern03_0002 */
void Pattern03_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024DC6, 3s-reloc: sf3 src/active03.c:71 Pattern03_0003 */
void Pattern03_0003(PLW* wk) {
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



/* 2i 06024DF2, 3s-reloc: sf3 src/active03.c:87 Pattern03_0004 */
void Pattern03_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024E24, 3s-near: sf3 src/active03.c:100 Pattern03_0005 */
void Pattern03_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024E46, 3s-near: sf3 src/active03.c:113 Pattern03_0006 */
void Pattern03_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024E64, 3s-near: sf3 src/active03.c:126 Pattern03_0007 */
void Pattern03_0007(PLW* wk) {
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



/* 2i 06024EBC, 3s-near: sf3 src/active03.c:145 Pattern03_0008 */
void Pattern03_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024F22, 3s-near: sf3 src/active03.c:161 Pattern03_0009 */
void Pattern03_0009(PLW* wk) {
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



/* 2i 06024F58, 3s-reloc: sf3 src/active03.c:180 Pattern03_0010 */
void Pattern03_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024F78, 3s-reloc: sf3 src/active03.c:193 Pattern03_0011 */
void Pattern03_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024FA4, 3s-reloc: sf3 src/active03.c:209 Pattern03_0012 */
void Pattern03_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024FC4, 3s-near: sf3 src/active03.c:222 Pattern03_0013 */
void Pattern03_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025010, 3s-near: sf3 src/active03.c:235 Pattern03_0014 */
void Pattern03_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x20, 2, 0x8060, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025052, 3s-near: sf3 src/active03.c:248 Pattern03_0015 */
void Pattern03_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025074, 3s-reloc: sf3 src/active03.c:261 Pattern03_0016 */
void Pattern03_0016(PLW* wk) {
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



/* 2i 060250A4, 3s-reloc: sf3 src/active03.c:277 Pattern03_0017 */
void Pattern03_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060250D6, 3s-reloc: sf3 src/active03.c:290 Pattern03_0018 */
void Pattern03_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x8200, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025108, 3s-reloc: sf3 src/active03.c:303 Pattern03_0019 */
void Pattern03_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602513A, 3s-near: sf3 src/active03.c:316 Pattern03_0020 */
void Pattern03_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060251A6, 3s-near: sf3 src/active03.c:332 Pattern03_0021 */
void Pattern03_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060251E8, 3s-near: sf3 src/active03.c:345 Pattern03_0022 */
void Pattern03_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8050, -1, 8, 0x8080, 0, 0x8060, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602522A, 3s-near: sf3 src/active03.c:358 Pattern03_0023 */
void Pattern03_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602524A, 3s-near: sf3 src/active03.c:371 Pattern03_0024 */
void Pattern03_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x20, 2, 0x8060, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060252BE, 3s-near: sf3 src/active03.c:384 Pattern03_0025 */
void Pattern03_0025(PLW* wk) {
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



/* 2i 060252EE, 3s-near: sf3 src/active03.c:400 Pattern03_0026 */
void Pattern03_0026(PLW* wk) {
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



/* 2i 0602532C, 3s-near: sf3 src/active03.c:416 Pattern03_0027 */
void Pattern03_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602534A, 3s-near: sf3 src/active03.c:429 Pattern03_0028 */
void Pattern03_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602536A, 3s-near: sf3 src/active03.c:442 Pattern03_0029 */
void Pattern03_0029(PLW* wk) {
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



/* 2i 060253EA, 3s-near: sf3 src/active03.c:464 Pattern03_0030 */
void Pattern03_0030(PLW* wk) {
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
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025446, 3s-near: sf3 src/active03.c:486 Pattern03_0031 */
void Pattern03_0031(PLW* wk) {
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



/* 2i 06025488, 3s-near: sf3 src/active03.c:502 Pattern03_0032 */
void Pattern03_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060254EA, 3s-near: sf3 src/active03.c:518 Pattern03_0033 */
void Pattern03_0033(PLW* wk) {
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



/* 2i 06025518, 3s-reloc: sf3 src/active03.c:534 Pattern03_0034 */
void Pattern03_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x82);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025558, 3s-reloc: sf3 src/active03.c:550 Pattern03_0035 */
void Pattern03_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025578, 3s-reloc: sf3 src/active03.c:563 Pattern03_0036 */
void Pattern03_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025598, 3s-near: sf3 src/active03.c:576 Pattern03_0037 */
void Pattern03_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060255F6, 3s-reloc: sf3 src/active03.c:592 Pattern03_0038 */
void Pattern03_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 2:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025648, 3s-reloc: sf3 src/active03.c:611 Pattern03_0039 */
void Pattern03_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025694, 3s-reloc: sf3 src/active03.c:627 Pattern03_0040 */
void Pattern03_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060256F0, 3s-exact: sf3 src/active03.c:643 Pattern03_0041 */
void Pattern03_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x42);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025730, 3s-exact: sf3 src/active03.c:659 Pattern03_0042 */
void Pattern03_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
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



/* 2i 06025776, 3s-exact: sf3 src/active03.c:678 Pattern03_0043 */
void Pattern03_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 8, 8, 0x8200, 0, -1, 0x8060, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060257B8, 3s-reloc: sf3 src/active03.c:691 Pattern03_0044 */
void Pattern03_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 0, 0x8060, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602581A, 3s-exact: sf3 src/active03.c:704 Pattern03_0045 */
void Pattern03_0045(PLW* wk) {
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



/* 2i 06025866, 3s-exact: sf3 src/active03.c:723 Pattern03_0046 */
void Pattern03_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025898, 3s-exact: sf3 src/active03.c:736 Pattern03_0047 */
void Pattern03_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060258CA, 3s-reloc: sf3 src/active03.c:749 Pattern03_0048 */
void Pattern03_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025922, 3s-exact: sf3 src/active03.c:762 Pattern03_0049 */
void Pattern03_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025954, 3s-exact: sf3 src/active03.c:775 Pattern03_0050 */
void Pattern03_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025986, 3s-exact: sf3 src/active03.c:788 Pattern03_0051 */
void Pattern03_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060259B8, 3s-exact: sf3 src/active03.c:801 Pattern03_0052 */
void Pattern03_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025A00, 3s-exact: sf3 src/active03.c:817 Pattern03_0053 */
void Pattern03_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025A48, 3s-exact: sf3 src/active03.c:833 Pattern03_0054 */
void Pattern03_0054(PLW* wk) {
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



/* 2i 06025AA4, 3s-exact: sf3 src/active03.c:852 Pattern03_0055 */
void Pattern03_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025AE6, 3s-reloc: sf3 src/active03.c:865 Pattern03_0056 */
void Pattern03_0056(PLW* wk) {
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



/* 2i 06025B66, 3s-exact: sf3 src/active03.c:881 Pattern03_0057 */
void Pattern03_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x12);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 1, 0x8060, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025BB8, 3s-reloc: sf3 src/active03.c:897 Pattern03_0058 */
void Pattern03_0058(PLW* wk) {
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



/* 2i 06025C70, 3s-exact: sf3 src/active03.c:922 Pattern03_0059 */
void Pattern03_0059(PLW* wk) {
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



/* 2i 06025CEE, 3s-reloc: sf3 src/active03.c:947 Pattern03_0060 */
void Pattern03_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, (0x100), 0, -1, -1, -1);
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



/* 2i 06025DA2, 3s-exact: sf3 src/active03.c:972 Pattern03_0061 */
void Pattern03_0061(PLW* wk) {
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



/* 2i 06025E18, 3s-reloc: sf3 src/active03.c:995 Pattern03_0062 */
void Pattern03_0062(PLW* wk) {
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



/* 2i 06025EA0, 3s-exact: sf3 src/active03.c:1011 Pattern03_0063 */
void Pattern03_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025EE2, 3s-exact: sf3 src/active03.c:1027 Pattern03_0064 */
void Pattern03_0064(PLW* wk) {
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



/* 2i 06025F44, 3s-reloc: sf3 src/active03.c:1049 Pattern03_0065 */
void Pattern03_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025FA0, 3s-exact: sf3 src/active03.c:1065 Pattern03_0066 */
void Pattern03_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x2D, 0x19, 0x10, 0x17, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06025FDA, 3s-exact: sf3 src/active03.c:1078 Pattern03_0067 */
void Pattern03_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x44, 0x45, 0x46, 0x47);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026010, 3s-exact: sf3 src/active03.c:1091 Pattern03_0068 */
void Pattern03_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026042, 3s-exact: sf3 src/active03.c:1104 Pattern03_0069 */
void Pattern03_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026074, 3s-exact: sf3 src/active03.c:1117 Pattern03_0070 */
void Pattern03_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060260A6, 3s-reloc: sf3 src/active03.c:1130 Pattern03_0071 */
void Pattern03_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xB, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
