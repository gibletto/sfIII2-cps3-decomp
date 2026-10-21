/*
 * ACTIVE05.C  CPU active patterns for player 05 (Necro)
 *
 * Behaviour patterns for the computer-controlled player 05 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer05, which runs the pattern chosen in Pattern_Index
 * through Pattern05_Tbl. Each Pattern05_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active05.h"



/* 2i 060271F0, 3s-exact: sf3 src/active05.c:20 Computer05 */
void Computer05(PLW* wk) {
    Pattern05_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06027208, 3s-exact: sf3 src/active05.c:26 Pattern05_0000 */
void Pattern05_0000(PLW* wk) {
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



/* 2i 06027230, 3s-exact: sf3 src/active05.c:42 Pattern05_0001 */
void Pattern05_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027270, 3s-exact: sf3 src/active05.c:61 Pattern05_0002 */
void Pattern05_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x41D, 0x8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060272A2, 3s-exact: sf3 src/active05.c:74 Pattern05_0003 */
void Pattern05_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060272CE, 3s-reloc: sf3 src/active05.c:90 Pattern05_0004 */
void Pattern05_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 1, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602732A, 3s-near: sf3 src/active05.c:103 Pattern05_0005 */
void Pattern05_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602734C, 3s-near: sf3 src/active05.c:116 Pattern05_0006 */
void Pattern05_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602736A, 3s-near: sf3 src/active05.c:129 Pattern05_0007 */
void Pattern05_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xB, -1);
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



/* 2i 060273B2, 3s-reloc: sf3 src/active05.c:148 Pattern05_0008 */
void Pattern05_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 0, (0x100), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060273F6, 3s-near: sf3 src/active05.c:161 Pattern05_0009 */
void Pattern05_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602744E, 3s-reloc: sf3 src/active05.c:174 Pattern05_0010 */
void Pattern05_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602746E, 3s-reloc: sf3 src/active05.c:187 Pattern05_0011 */
void Pattern05_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602748E, 3s-reloc: sf3 src/active05.c:200 Pattern05_0012 */
void Pattern05_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060274AE, 3s-reloc: sf3 src/active05.c:213 Pattern05_0013 */
void Pattern05_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060274CE, 3s-reloc: sf3 src/active05.c:226 Pattern05_0014 */
void Pattern05_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x100, 2, 0x8080, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027512, 3s-near: sf3 src/active05.c:239 Pattern05_0015 */
void Pattern05_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027558, 3s-near: sf3 src/active05.c:252 Pattern05_0016 */
void Pattern05_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602757A, 3s-near: sf3 src/active05.c:265 Pattern05_0017 */
void Pattern05_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060275AC, 3s-near: sf3 src/active05.c:278 Pattern05_0018 */
void Pattern05_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
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



/* 2i 060275DE, 3s-near: sf3 src/active05.c:297 Pattern05_0019 */
void Pattern05_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x88, -1, 0, 2, 5);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027624, 3s-reloc: sf3 src/active05.c:313 Pattern05_0020 */
void Pattern05_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602767E, 3s-reloc: sf3 src/active05.c:326 Pattern05_0021 */
void Pattern05_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060276B0, 3s-reloc: sf3 src/active05.c:339 Pattern05_0022 */
void Pattern05_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 8, 0x40, 0, 0x8070, -1, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060276F2, 3s-reloc: sf3 src/active05.c:352 Pattern05_0023 */
void Pattern05_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027712, 3s-reloc: sf3 src/active05.c:365 Pattern05_0024 */
void Pattern05_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027734, 3s-near: sf3 src/active05.c:378 Pattern05_0025 */
void Pattern05_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602777C, 3s-reloc: sf3 src/active05.c:391 Pattern05_0026 */
void Pattern05_0026(PLW* wk) {
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



/* 2i 060277C4, 3s-reloc: sf3 src/active05.c:410 Pattern05_0027 */
void Pattern05_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060277E2, 3s-reloc: sf3 src/active05.c:423 Pattern05_0028 */
void Pattern05_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027802, 3s-reloc: sf3 src/active05.c:436 Pattern05_0029 */
void Pattern05_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x41D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027842, 3s-near: sf3 src/active05.c:452 Pattern05_0030 */
void Pattern05_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060278AA, 3s-near: sf3 src/active05.c:468 Pattern05_0031 */
void Pattern05_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80B0, 0x8050, 8, 0x102, 0, 0x8098, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060278FC, 3s-near: sf3 src/active05.c:484 Pattern05_0032 */
void Pattern05_0032(PLW* wk) {
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



/* 2i 06027928, 3s-near: sf3 src/active05.c:500 Pattern05_0033 */
void Pattern05_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027994, 3s-reloc: sf3 src/active05.c:516 Pattern05_0034 */
void Pattern05_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x80);
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



/* 2i 060279C8, 3s-reloc: sf3 src/active05.c:535 Pattern05_0035 */
void Pattern05_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060279E8, 3s-reloc: sf3 src/active05.c:548 Pattern05_0036 */
void Pattern05_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027A08, 3s-near: sf3 src/active05.c:561 Pattern05_0037 */
void Pattern05_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027A2A, 3s-near: sf3 src/active05.c:574 Pattern05_0038 */
void Pattern05_0038(PLW* wk) {
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
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 4:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027AB8, 3s-near: sf3 src/active05.c:599 Pattern05_0039 */
void Pattern05_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027B00, 3s-near: sf3 src/active05.c:615 Pattern05_0040 */
void Pattern05_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027B40, 3s-near: sf3 src/active05.c:631 Pattern05_0041 */
void Pattern05_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027BA0, 3s-reloc: sf3 src/active05.c:647 Pattern05_0042 */
void Pattern05_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027BE0, 3s-reloc: sf3 src/active05.c:669 Pattern05_0043 */
void Pattern05_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 8, 0x40, 0, -1, 0x30, (0x401F));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027C24, 3s-reloc: sf3 src/active05.c:682 Pattern05_0044 */
void Pattern05_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 8, 0x40, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027C68, 3s-near: sf3 src/active05.c:695 Pattern05_0045 */
void Pattern05_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027CCA, 3s-near: sf3 src/active05.c:717 Pattern05_0046 */
void Pattern05_0046(PLW* wk) {
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



/* 2i 06027D16, 3s-near: sf3 src/active05.c:736 Pattern05_0047 */
void Pattern05_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, 0x8060, 0x30, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027D5C, 3s-near: sf3 src/active05.c:749 Pattern05_0048 */
void Pattern05_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027D70, 3s-near: sf3 src/active05.c:759 Pattern05_0049 */
void Pattern05_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027D84, 3s-near: sf3 src/active05.c:769 Pattern05_0050 */
void Pattern05_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x200, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027DD0, 3s-near: sf3 src/active05.c:782 Pattern05_0051 */
void Pattern05_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027E12, 3s-near: sf3 src/active05.c:795 Pattern05_0052 */
void Pattern05_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027E58, 3s-near: sf3 src/active05.c:808 Pattern05_0053 */
void Pattern05_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8414, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027E8A, 3s-near: sf3 src/active05.c:821 Pattern05_0054 */
void Pattern05_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027EBC, 3s-reloc: sf3 src/active05.c:834 Pattern05_0055 */
void Pattern05_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027EEE, 3s-reloc: sf3 src/active05.c:847 Pattern05_0056 */
void Pattern05_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8414, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027F20, 3s-reloc: sf3 src/active05.c:860 Pattern05_0057 */
void Pattern05_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027F52, 3s-reloc: sf3 src/active05.c:873 Pattern05_0058 */
void Pattern05_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027F84, 3s-reloc: sf3 src/active05.c:886 Pattern05_0059 */
void Pattern05_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8414, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027FB6, 3s-reloc: sf3 src/active05.c:899 Pattern05_0060 */
void Pattern05_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06027FE8, 3s-reloc: sf3 src/active05.c:912 Pattern05_0061 */
void Pattern05_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602803A, 3s-reloc: sf3 src/active05.c:925 Pattern05_0062 */
void Pattern05_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602806C, 3s-reloc: sf3 src/active05.c:938 Pattern05_0063 */
void Pattern05_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x100, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060280B0, 3s-reloc: sf3 src/active05.c:951 Pattern05_0064 */
void Pattern05_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x50, 8, 0x202, 2, 0x8080, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060280F2, 3s-reloc: sf3 src/active05.c:964 Pattern05_0065 */
void Pattern05_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x50, 8, 0x102, 2, 0x8080, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028162, 3s-near: sf3 src/active05.c:977 Pattern05_0066 */
void Pattern05_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
