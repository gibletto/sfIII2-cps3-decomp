/*
 * ACTIVE04.C  CPU active patterns for player 04 (Dudley)
 *
 * Behaviour patterns for the computer-controlled player 04 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer04, which runs the pattern chosen in Pattern_Index
 * through Pattern04_Tbl. Each Pattern04_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active04.h"



/* 2i 060260EC, 3s-reloc: sf3 src/active04.c:20 Computer04 */
void Computer04(PLW* wk) {
    Pattern04_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06026104, 3s-reloc: sf3 src/active04.c:26 Pattern04_0000 */
void Pattern04_0000(PLW* wk) {
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



/* 2i 0602612C, 3s-reloc: sf3 src/active04.c:42 Pattern04_0001 */
void Pattern04_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026164, 3s-reloc: sf3 src/active04.c:61 Pattern04_0002 */
void Pattern04_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026196, 3s-reloc: sf3 src/active04.c:74 Pattern04_0003 */
void Pattern04_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060261BA, 3s-reloc: sf3 src/active04.c:90 Pattern04_0004 */
void Pattern04_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060261EC, 3s-near: sf3 src/active04.c:103 Pattern04_0005 */
void Pattern04_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602621A, 3s-near: sf3 src/active04.c:119 Pattern04_0006 */
void Pattern04_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026238, 3s-near: sf3 src/active04.c:132 Pattern04_0007 */
void Pattern04_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 0x14);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
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



/* 2i 0602629A, 3s-near: sf3 src/active04.c:151 Pattern04_0008 */
void Pattern04_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602631A, 3s-near: sf3 src/active04.c:164 Pattern04_0009 */
void Pattern04_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602634C, 3s-reloc: sf3 src/active04.c:177 Pattern04_0010 */
void Pattern04_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602636C, 3s-reloc: sf3 src/active04.c:190 Pattern04_0011 */
void Pattern04_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602638C, 3s-reloc: sf3 src/active04.c:203 Pattern04_0012 */
void Pattern04_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060263AC, 3s-reloc: sf3 src/active04.c:216 Pattern04_0013 */
void Pattern04_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060263CC, 3s-near: sf3 src/active04.c:229 Pattern04_0014 */
void Pattern04_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x100, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026430, 3s-near: sf3 src/active04.c:242 Pattern04_0015 */
void Pattern04_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026452, 3s-near: sf3 src/active04.c:255 Pattern04_0016 */
void Pattern04_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026474, 3s-near: sf3 src/active04.c:268 Pattern04_0017 */
void Pattern04_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060264A6, 3s-near: sf3 src/active04.c:281 Pattern04_0018 */
void Pattern04_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 0x31);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Jump(wk, 1);
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



/* 2i 06026524, 3s-near: sf3 src/active04.c:306 Pattern04_0019 */
void Pattern04_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x88, -1, 0, 2, 5);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602656A, 3s-near: sf3 src/active04.c:322 Pattern04_0020 */
void Pattern04_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060265B2, 3s-near: sf3 src/active04.c:338 Pattern04_0021 */
void Pattern04_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060265E4, 3s-near: sf3 src/active04.c:351 Pattern04_0022 */
void Pattern04_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x40, 0, 0x8070, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026650, 3s-near: sf3 src/active04.c:364 Pattern04_0023 */
void Pattern04_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026670, 3s-near: sf3 src/active04.c:377 Pattern04_0024 */
void Pattern04_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026692, 3s-near: sf3 src/active04.c:390 Pattern04_0025 */
void Pattern04_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060266B4, 3s-near: sf3 src/active04.c:403 Pattern04_0026 */
void Pattern04_0026(PLW* wk) {
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



/* 2i 060266FC, 3s-near: sf3 src/active04.c:422 Pattern04_0027 */
void Pattern04_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602671A, 3s-near: sf3 src/active04.c:435 Pattern04_0028 */
void Pattern04_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xDF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026760, 3s-near: sf3 src/active04.c:448 Pattern04_0029 */
void Pattern04_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x82);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060267A0, 3s-reloc: sf3 src/active04.c:464 Pattern04_0030 */
void Pattern04_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060267D8, 3s-reloc: sf3 src/active04.c:483 Pattern04_0031 */
void Pattern04_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x200, 0, 0x8098, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602682A, 3s-near: sf3 src/active04.c:499 Pattern04_0032 */
void Pattern04_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026884, 3s-near: sf3 src/active04.c:515 Pattern04_0033 */
void Pattern04_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060268D2, 3s-reloc: sf3 src/active04.c:534 Pattern04_0034 */
void Pattern04_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
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



/* 2i 06026906, 3s-reloc: sf3 src/active04.c:553 Pattern04_0035 */
void Pattern04_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026926, 3s-near: sf3 src/active04.c:566 Pattern04_0036 */
void Pattern04_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026968, 3s-near: sf3 src/active04.c:579 Pattern04_0037 */
void Pattern04_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026996, 3s-near: sf3 src/active04.c:595 Pattern04_0038 */
void Pattern04_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xA, 0x82);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060269F8, 3s-near: sf3 src/active04.c:620 Pattern04_0039 */
void Pattern04_0039(PLW* wk) {
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



/* 2i 06026A6C, 3s-near: sf3 src/active04.c:636 Pattern04_0040 */
void Pattern04_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 9, 0, 0x100);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026ABC, 3s-near: sf3 src/active04.c:655 Pattern04_0041 */
void Pattern04_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026B0A, 3s-near: sf3 src/active04.c:674 Pattern04_0042 */
void Pattern04_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026B7A, 3s-near: sf3 src/active04.c:699 Pattern04_0043 */
void Pattern04_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, -1, 0x30, (0x4020));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026BBE, 3s-near: sf3 src/active04.c:712 Pattern04_0044 */
void Pattern04_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026C02, 3s-near: sf3 src/active04.c:725 Pattern04_0045 */
void Pattern04_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026C46, 3s-near: sf3 src/active04.c:738 Pattern04_0046 */
void Pattern04_0046(PLW* wk) {
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



/* 2i 06026CB0, 3s-near: sf3 src/active04.c:757 Pattern04_0047 */
void Pattern04_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, -1, 0x8060, 0x30, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026CF6, 3s-reloc: sf3 src/active04.c:770 Pattern04_0048 */
void Pattern04_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xD, 0, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026D24, 3s-reloc: sf3 src/active04.c:786 Pattern04_0049 */
void Pattern04_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026D56, 3s-reloc: sf3 src/active04.c:799 Pattern04_0050 */
void Pattern04_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x200, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026D88, 3s-near: sf3 src/active04.c:812 Pattern04_0051 */
void Pattern04_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026DEC, 3s-reloc: sf3 src/active04.c:825 Pattern04_0052 */
void Pattern04_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026E32, 3s-reloc: sf3 src/active04.c:838 Pattern04_0053 */
void Pattern04_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026E64, 3s-reloc: sf3 src/active04.c:851 Pattern04_0054 */
void Pattern04_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8215, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026E96, 3s-reloc: sf3 src/active04.c:864 Pattern04_0055 */
void Pattern04_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026EC8, 3s-reloc: sf3 src/active04.c:877 Pattern04_0056 */
void Pattern04_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026EFA, 3s-reloc: sf3 src/active04.c:890 Pattern04_0057 */
void Pattern04_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026F2C, 3s-reloc: sf3 src/active04.c:903 Pattern04_0058 */
void Pattern04_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        Lever_Attack(wk, 0xD, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026FA0, 3s-exact: sf3 src/active04.c:922 Pattern04_0059 */
void Pattern04_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06026FE8, 3s-reloc: sf3 src/active04.c:938 Pattern04_0060 */
void Pattern04_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        {
            s16 zero = 0;
            EM_Term(wk, 0x8070, zero, zero, 2, zero);
        }
        break;
    case 1:
        Command_Attack(wk, 13, 32, 0x609, -1);
        break;
    case 2:
        Approach_Walk(wk, 71, 2);
        break;
    case 3:
        Normal_Attack(wk, 13, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027058, 3s-near: sf3 src/active04.c:963 Pattern04_0061 */
void Pattern04_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 1, 0x40, 0x41, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060270BA, 3s-near: sf3 src/active04.c:976 Pattern04_0062 */
void Pattern04_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x40, 0x41, 0x42, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060270F2, 3s-near: sf3 src/active04.c:989 Pattern04_0063 */
void Pattern04_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, (0x100), 0, 0x8098, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027136, 3s-near: sf3 src/active04.c:1002 Pattern04_0064 */
void Pattern04_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027168, 3s-near: sf3 src/active04.c:1015 Pattern04_0065 */
void Pattern04_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602719A, 3s-near: sf3 src/active04.c:1028 Pattern04_0066 */
void Pattern04_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

