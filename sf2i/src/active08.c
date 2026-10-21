/*
 * ACTIVE08.C  CPU active patterns for player 08 (Elena)
 *
 * Behaviour patterns for the computer-controlled player 08 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer08, which runs the pattern chosen in Pattern_Index
 * through Pattern08_Tbl. Each Pattern08_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active08.h"



/* 2i 0602A42C, 3s-exact: sf3 src/active08.c:20 Computer08 */
void Computer08(PLW* wk) {
    Pattern08_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0602A444, 3s-exact: sf3 src/active08.c:26 Pattern08_0000 */
void Pattern08_0000(PLW* wk) {
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



/* 2i 0602A46C, 3s-exact: sf3 src/active08.c:42 Pattern08_0001 */
void Pattern08_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A4AA, 3s-exact: sf3 src/active08.c:61 Pattern08_0002 */
void Pattern08_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A4D4, 3s-reloc: sf3 src/active08.c:77 Pattern08_0003 */
void Pattern08_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A528, 3s-exact: sf3 src/active08.c:93 Pattern08_0004 */
void Pattern08_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0x1E, 9, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A58E, 3s-near: sf3 src/active08.c:115 Pattern08_0005 */
void Pattern08_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A5DE, 3s-reloc: sf3 src/active08.c:134 Pattern08_0006 */
void Pattern08_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A620, 3s-near: sf3 src/active08.c:147 Pattern08_0007 */
void Pattern08_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    case 1:
        Lever_Off(wk);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A668, 3s-reloc: sf3 src/active08.c:166 Pattern08_0008 */
void Pattern08_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x100, 0, 0x8068, -1, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A6D0, 3s-near: sf3 src/active08.c:185 Pattern08_0009 */
void Pattern08_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 9, 0x1E, 0xA, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A764, 3s-near: sf3 src/active08.c:207 Pattern08_0010 */
void Pattern08_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A784, 3s-near: sf3 src/active08.c:220 Pattern08_0011 */
void Pattern08_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        J_Command_Attack(wk, 9, 0x1E, 0xA, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A7E4, 3s-near: sf3 src/active08.c:242 Pattern08_0012 */
void Pattern08_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A804, 3s-reloc: sf3 src/active08.c:255 Pattern08_0013 */
void Pattern08_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A862, 3s-reloc: sf3 src/active08.c:274 Pattern08_0014 */
void Pattern08_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x100, 2, -1, 0x8010, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A8B4, 3s-reloc: sf3 src/active08.c:290 Pattern08_0015 */
void Pattern08_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A8D6, 3s-reloc: sf3 src/active08.c:303 Pattern08_0016 */
void Pattern08_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A8F8, 3s-reloc: sf3 src/active08.c:316 Pattern08_0017 */
void Pattern08_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A954, 3s-near: sf3 src/active08.c:329 Pattern08_0018 */
void Pattern08_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;
    case 3:
        Lever_Off(wk);
        break;
    case 4:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A9B8, 3s-near: sf3 src/active08.c:354 Pattern08_0019 */
void Pattern08_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x70, -1, 0, 2, 5);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A9FE, 3s-near: sf3 src/active08.c:370 Pattern08_0020 */
void Pattern08_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0x1D, 0xA, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AA70, 3s-reloc: sf3 src/active08.c:386 Pattern08_0021 */
void Pattern08_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AAA2, 3s-reloc: sf3 src/active08.c:399 Pattern08_0022 */
void Pattern08_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8040, 9, 0x40, 0, 0x8070, -1, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AAFC, 3s-reloc: sf3 src/active08.c:415 Pattern08_0023 */
void Pattern08_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AB1C, 3s-reloc: sf3 src/active08.c:428 Pattern08_0024 */
void Pattern08_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AB3E, 3s-reloc: sf3 src/active08.c:441 Pattern08_0025 */
void Pattern08_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AB84, 3s-reloc: sf3 src/active08.c:454 Pattern08_0026 */
void Pattern08_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Lever_Off(wk);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ABCC, 3s-reloc: sf3 src/active08.c:473 Pattern08_0027 */
void Pattern08_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ABEA, 3s-reloc: sf3 src/active08.c:486 Pattern08_0028 */
void Pattern08_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AC0A, 3s-near: sf3 src/active08.c:499 Pattern08_0029 */
void Pattern08_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AC98, 3s-near: sf3 src/active08.c:521 Pattern08_0030 */
void Pattern08_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ACF2, 3s-near: sf3 src/active08.c:543 Pattern08_0031 */
void Pattern08_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8040, 8, (0x100), 0, 0x8098, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AD44, 3s-near: sf3 src/active08.c:559 Pattern08_0032 */
void Pattern08_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ADA4, 3s-near: sf3 src/active08.c:578 Pattern08_0033 */
void Pattern08_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 9, 0, 0x20);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ADD4, 3s-near: sf3 src/active08.c:594 Pattern08_0034 */
void Pattern08_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 0xb, 0x40);
        break;
    case 2:
        Normal_Attack(wk, 0xb, (0x202));
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 5:
        Lever_Off(wk);
        break;
    case 6:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AE52, 3s-near: sf3 src/active08.c:625 Pattern08_0035 */
void Pattern08_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AE98, 3s-reloc: sf3 src/active08.c:638 Pattern08_0036 */
void Pattern08_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AEB8, 3s-near: sf3 src/active08.c:651 Pattern08_0037 */
void Pattern08_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AEDA, 3s-reloc: sf3 src/active08.c:664 Pattern08_0038 */
void Pattern08_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x100);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    case 4:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AF3C, 3s-reloc: sf3 src/active08.c:689 Pattern08_0039 */
void Pattern08_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AFB0, 3s-reloc: sf3 src/active08.c:705 Pattern08_0040 */
void Pattern08_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602AFF0, 3s-reloc: sf3 src/active08.c:721 Pattern08_0041 */
void Pattern08_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B040, 3s-reloc: sf3 src/active08.c:740 Pattern08_0042 */
void Pattern08_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x100, 0, 0x8090, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B084, 3s-reloc: sf3 src/active08.c:753 Pattern08_0043 */
void Pattern08_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8040, 8, 0x40, 0, -1, 0x8020, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B0F0, 3s-reloc: sf3 src/active08.c:766 Pattern08_0044 */
void Pattern08_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8040, 8, 0x40, 0, 0x8090, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B142, 3s-near: sf3 src/active08.c:782 Pattern08_0045 */
void Pattern08_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8040, 0xB, (0x200), 0, 0x8090, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B1C0, 3s-reloc: sf3 src/active08.c:801 Pattern08_0046 */
void Pattern08_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;
    case 1:
        Walk(wk, 1, 0x13, 0);
        break;
    case 2:
        Walk(wk, 0, 0x10, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B20C, 3s-reloc: sf3 src/active08.c:820 Pattern08_0047 */
void Pattern08_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 0);
        break;
    case 1:
        Walk(wk, 0, 0x14, 0);
        break;
    case 2:
        Walk(wk, 1, 0x18, 0);
        break;
    case 3:
        Wait(wk, 0x14);
        break;
    case 4:
        Walk(wk, 0, 0x14, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B270, 3s-reloc: sf3 src/active08.c:845 Pattern08_0048 */
void Pattern08_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B28E, 3s-reloc: sf3 src/active08.c:858 Pattern08_0049 */
void Pattern08_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B2C0, 3s-reloc: sf3 src/active08.c:871 Pattern08_0050 */
void Pattern08_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8068, 0x8048, 8, 0x200, 2, -1, 0x8010, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B318, 3s-reloc: sf3 src/active08.c:884 Pattern08_0051 */
void Pattern08_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8068, 0x8048, 8, 0x40, 0, -1, 0x8010, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B35C, 3s-reloc: sf3 src/active08.c:897 Pattern08_0052 */
void Pattern08_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8068, 0x8048, 8, 0x40, 0, -1, 0x8010, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B3A0, 3s-reloc: sf3 src/active08.c:910 Pattern08_0053 */
void Pattern08_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B414, 3s-near: sf3 src/active08.c:929 Pattern08_0054 */
void Pattern08_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B446, 3s-near: sf3 src/active08.c:942 Pattern08_0055 */
void Pattern08_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1d, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B4B6, 3s-near: sf3 src/active08.c:970 Pattern08_0056 */
void Pattern08_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 5:
        SA_Term(wk, -1, -1, 0x3b, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B53E, 3s-near: sf3 src/active08.c:998 Pattern08_0057 */
void Pattern08_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B570, 3s-near: sf3 src/active08.c:1011 Pattern08_0058 */
void Pattern08_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B5A2, 3s-near: sf3 src/active08.c:1024 Pattern08_0059 */
void Pattern08_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B5D4, 3s-near: sf3 src/active08.c:1037 Pattern08_0060 */
void Pattern08_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B5E8, 3s-near: sf3 src/active08.c:1047 Pattern08_0061 */
void Pattern08_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x3B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B65A, 3s-reloc: sf3 src/active08.c:1063 Pattern08_0062 */
void Pattern08_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B68C, 3s-reloc: sf3 src/active08.c:1076 Pattern08_0063 */
void Pattern08_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B6A0, 3s-near: sf3 src/active08.c:1086 Pattern08_0064 */
void Pattern08_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

