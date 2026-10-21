/*
 * PASS12.C  CPU passive patterns for character 12 (Sean)
 *
 * Passive12 is the CPU passive (defensive) routine for character 12, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive12_Tbl.
 * The 231 Passive12_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS12.h"



/* 2i 06062210, 3s-reloc: sf3 src/PASS12.c:21 Passive12 */
void Passive12(PLW* wk) {
    Passive12_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06062228, 3s-reloc: sf3 src/PASS12.c:27 Passive12_0000 */
void Passive12_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606225C, 3s-reloc: sf3 src/PASS12.c:40 Passive12_0001 */
void Passive12_0001(PLW* wk) {
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



/* 2i 06062284, 3s-near: sf3 src/PASS12.c:56 Passive12_0002 */
void Passive12_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060622CC, 3s-near: sf3 src/PASS12.c:72 Passive12_0003 */
void Passive12_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062318, 3s-reloc: sf3 src/PASS12.c:88 Passive12_0004 */
void Passive12_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x31, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606237A, 3s-near: sf3 src/PASS12.c:107 Passive12_0005 */
void Passive12_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060623D4, 3s-near: sf3 src/PASS12.c:126 Passive12_0006 */
void Passive12_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606246A, 3s-near: sf3 src/PASS12.c:145 Passive12_0007 */
void Passive12_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060624BE, 3s-near: sf3 src/PASS12.c:164 Passive12_0008 */
void Passive12_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062512, 3s-near: sf3 src/PASS12.c:183 Passive12_0009 */
void Passive12_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062584, 3s-near: sf3 src/PASS12.c:199 Passive12_0010 */
void Passive12_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060625F2, 3s-near: sf3 src/PASS12.c:221 Passive12_0011 */
void Passive12_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062610, 3s-near: sf3 src/PASS12.c:234 Passive12_0012 */
void Passive12_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606263C, 3s-near: sf3 src/PASS12.c:250 Passive12_0013 */
void Passive12_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606268C, 3s-reloc: sf3 src/PASS12.c:266 Passive12_0014 */
void Passive12_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060626B8, 3s-reloc: sf3 src/PASS12.c:282 Passive12_0015 */
void Passive12_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060626E4, 3s-reloc: sf3 src/PASS12.c:298 Passive12_0016 */
void Passive12_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062710, 3s-reloc: sf3 src/PASS12.c:314 Passive12_0017 */
void Passive12_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606273C, 3s-near: sf3 src/PASS12.c:330 Passive12_0018 */
void Passive12_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060627A2, 3s-near: sf3 src/PASS12.c:346 Passive12_0019 */
void Passive12_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060627E2, 3s-near: sf3 src/PASS12.c:362 Passive12_0020 */
void Passive12_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062810, 3s-near: sf3 src/PASS12.c:378 Passive12_0021 */
void Passive12_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606283E, 3s-near: sf3 src/PASS12.c:394 Passive12_0022 */
void Passive12_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606288C, 3s-reloc: sf3 src/PASS12.c:410 Passive12_0023 */
void Passive12_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060628CC, 3s-reloc: sf3 src/PASS12.c:426 Passive12_0024 */
void Passive12_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606290C, 3s-near: sf3 src/PASS12.c:442 Passive12_0025 */
void Passive12_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606294C, 3s-reloc: sf3 src/PASS12.c:458 Passive12_0026 */
void Passive12_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606297E, 3s-reloc: sf3 src/PASS12.c:471 Passive12_0027 */
void Passive12_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060629B0, 3s-reloc: sf3 src/PASS12.c:484 Passive12_0028 */
void Passive12_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060629E2, 3s-reloc: sf3 src/PASS12.c:497 Passive12_0029 */
void Passive12_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 0xB, 0x20, 10, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062A34, 3s-reloc: sf3 src/PASS12.c:516 Passive12_0030 */
void Passive12_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062A84, 3s-exact: sf3 src/PASS12.c:535 Passive12_0031 */
void Passive12_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 9, 0, (0x100));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062ACA, 3s-exact: sf3 src/PASS12.c:557 Passive12_0032 */
void Passive12_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062B1E, 3s-reloc: sf3 src/PASS12.c:579 Passive12_0033 */
void Passive12_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062B68, 3s-exact: sf3 src/PASS12.c:595 Passive12_0034 */
void Passive12_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062BBE, 3s-exact: sf3 src/PASS12.c:614 Passive12_0035 */
void Passive12_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062BF0, 3s-exact: sf3 src/PASS12.c:627 Passive12_0036 */
void Passive12_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062C22, 3s-near: sf3 src/PASS12.c:640 Passive12_0037 */
void Passive12_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062C74, 3s-exact: sf3 src/PASS12.c:653 Passive12_0038 */
void Passive12_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062CC2, 3s-exact: sf3 src/PASS12.c:669 Passive12_0039 */
void Passive12_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062D10, 3s-exact: sf3 src/PASS12.c:685 Passive12_0040 */
void Passive12_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062D5E, 3s-exact: sf3 src/PASS12.c:701 Passive12_0041 */
void Passive12_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062DC2, 3s-exact: sf3 src/PASS12.c:720 Passive12_0042 */
void Passive12_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062DE0, 3s-exact: sf3 src/PASS12.c:733 Passive12_0043 */
void Passive12_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062E26, 3s-reloc: sf3 src/PASS12.c:746 Passive12_0044 */
void Passive12_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, (0x200), 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062E88, 3s-exact: sf3 src/PASS12.c:759 Passive12_0045 */
void Passive12_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062EBA, 3s-exact: sf3 src/PASS12.c:772 Passive12_0046 */
void Passive12_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062EEC, 3s-exact: sf3 src/PASS12.c:785 Passive12_0047 */
void Passive12_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062F1E, 3s-exact: sf3 src/PASS12.c:798 Passive12_0048 */
void Passive12_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062F3E, 3s-near: sf3 src/PASS12.c:811 Passive12_0049 */
void Passive12_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062F7C, 3s-exact: sf3 src/PASS12.c:824 Passive12_0050 */
void Passive12_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062FBC, 3s-exact: sf3 src/PASS12.c:840 Passive12_0051 */
void Passive12_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063000, 3s-reloc: sf3 src/PASS12.c:859 Passive12_0052 */
void Passive12_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606307C, 3s-exact: sf3 src/PASS12.c:875 Passive12_0053 */
void Passive12_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060630E4, 3s-exact: sf3 src/PASS12.c:894 Passive12_0054 */
void Passive12_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606311C, 3s-reloc: sf3 src/PASS12.c:913 Passive12_0055 */
void Passive12_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063174, 3s-reloc: sf3 src/PASS12.c:929 Passive12_0056 */
void Passive12_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060631D8, 3s-reloc: sf3 src/PASS12.c:951 Passive12_0057 */
void Passive12_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x22);
        break;
    case 2:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606323C, 3s-near: sf3 src/PASS12.c:973 Passive12_0058 */
void Passive12_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606326A, 3s-near: sf3 src/PASS12.c:989 Passive12_0059 */
void Passive12_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063298, 3s-near: sf3 src/PASS12.c:1005 Passive12_0060 */
void Passive12_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060632E4, 3s-near: sf3 src/PASS12.c:1021 Passive12_0061 */
void Passive12_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x37, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606330E, 3s-near: sf3 src/PASS12.c:1037 Passive12_0062 */
void Passive12_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606333A, 3s-near: sf3 src/PASS12.c:1053 Passive12_0063 */
void Passive12_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 5:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 6:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606340E, 3s-near: sf3 src/PASS12.c:1084 Passive12_0064 */
void Passive12_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606343A, 3s-near: sf3 src/PASS12.c:1100 Passive12_0065 */
void Passive12_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060634A2, 3s-near: sf3 src/PASS12.c:1119 Passive12_0066 */
void Passive12_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063512, 3s-near: sf3 src/PASS12.c:1135 Passive12_0067 */
void Passive12_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063552, 3s-near: sf3 src/PASS12.c:1151 Passive12_0068 */
void Passive12_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606357C, 3s-near: sf3 src/PASS12.c:1167 Passive12_0069 */
void Passive12_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606359C, 3s-near: sf3 src/PASS12.c:1180 Passive12_0070 */
void Passive12_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 0xB, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063632, 3s-near: sf3 src/PASS12.c:1199 Passive12_0071 */
void Passive12_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606365A, 3s-near: sf3 src/PASS12.c:1215 Passive12_0072 */
void Passive12_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063684, 3s-near: sf3 src/PASS12.c:1231 Passive12_0073 */
void Passive12_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060636A4, 3s-near: sf3 src/PASS12.c:1244 Passive12_0074 */
void Passive12_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063714, 3s-near: sf3 src/PASS12.c:1260 Passive12_0075 */
void Passive12_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063772, 3s-near: sf3 src/PASS12.c:1279 Passive12_0076 */
void Passive12_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606379E, 3s-near: sf3 src/PASS12.c:1295 Passive12_0077 */
void Passive12_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060637BE, 3s-near: sf3 src/PASS12.c:1308 Passive12_0078 */
void Passive12_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0xE, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063814, 3s-reloc: sf3 src/PASS12.c:1321 Passive12_0079 */
void Passive12_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x53, 0x2F, 0x24, 0x25);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606386A, 3s-near: sf3 src/PASS12.c:1340 Passive12_0080 */
void Passive12_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060638D2, 3s-near: sf3 src/PASS12.c:1359 Passive12_0081 */
void Passive12_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606396C, 3s-near: sf3 src/PASS12.c:1378 Passive12_0082 */
void Passive12_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063A3C, 3s-near: sf3 src/PASS12.c:1406 Passive12_0083 */
void Passive12_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063A5E, 3s-near: sf3 src/PASS12.c:1419 Passive12_0084 */
void Passive12_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063A80, 3s-near: sf3 src/PASS12.c:1432 Passive12_0085 */
void Passive12_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063AA2, 3s-near: sf3 src/PASS12.c:1445 Passive12_0086 */
void Passive12_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063AC2, 3s-near: sf3 src/PASS12.c:1458 Passive12_0087 */
void Passive12_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063AF4, 3s-near: sf3 src/PASS12.c:1471 Passive12_0088 */
void Passive12_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063B30, 3s-reloc: sf3 src/PASS12.c:1484 Passive12_0089 */
void Passive12_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063B82, 3s-reloc: sf3 src/PASS12.c:1503 Passive12_0090 */
void Passive12_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x32, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063BE6, 3s-reloc: sf3 src/PASS12.c:1525 Passive12_0091 */
void Passive12_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, (0x100));
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x32, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063C68, 3s-reloc: sf3 src/PASS12.c:1547 Passive12_0092 */
void Passive12_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, (0x100));
        break;
    case 2:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063CCE, 3s-near: sf3 src/PASS12.c:1569 Passive12_0093 */
void Passive12_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x28, 7, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 9, 0, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063D4C, 3s-reloc: sf3 src/PASS12.c:1588 Passive12_0094 */
void Passive12_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063D9A, 3s-reloc: sf3 src/PASS12.c:1607 Passive12_0095 */
void Passive12_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063DDA, 3s-near: sf3 src/PASS12.c:1623 Passive12_0096 */
void Passive12_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063E1A, 3s-near: sf3 src/PASS12.c:1639 Passive12_0097 */
void Passive12_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063E84, 3s-reloc: sf3 src/PASS12.c:1655 Passive12_0098 */
void Passive12_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063EA4, 3s-reloc: sf3 src/PASS12.c:1668 Passive12_0099 */
void Passive12_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063EC4, 3s-near: sf3 src/PASS12.c:1681 Passive12_0100 */
void Passive12_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063EE4, 3s-reloc: sf3 src/PASS12.c:1694 Passive12_0101 */
void Passive12_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 1:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063F58, 3s-near: sf3 src/PASS12.c:1713 Passive12_0102 */
void Passive12_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06063FC6, 3s-near: sf3 src/PASS12.c:1732 Passive12_0103 */
void Passive12_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064006, 3s-near: sf3 src/PASS12.c:1748 Passive12_0104 */
void Passive12_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x202));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606406C, 3s-near: sf3 src/PASS12.c:1764 Passive12_0105 */
void Passive12_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060640E0, 3s-near: sf3 src/PASS12.c:1786 Passive12_0106 */
void Passive12_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064124, 3s-near: sf3 src/PASS12.c:1799 Passive12_0107 */
void Passive12_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606419E, 3s-near: sf3 src/PASS12.c:1815 Passive12_0108 */
void Passive12_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060641EC, 3s-near: sf3 src/PASS12.c:1831 Passive12_0109 */
void Passive12_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606423A, 3s-reloc: sf3 src/PASS12.c:1847 Passive12_0110 */
void Passive12_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606429E, 3s-reloc: sf3 src/PASS12.c:1869 Passive12_0111 */
void Passive12_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064322, 3s-near: sf3 src/PASS12.c:1891 Passive12_0112 */
void Passive12_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064342, 3s-near: sf3 src/PASS12.c:1904 Passive12_0113 */
void Passive12_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064362, 3s-near: sf3 src/PASS12.c:1917 Passive12_0114 */
void Passive12_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060643BE, 3s-near: sf3 src/PASS12.c:1936 Passive12_0115 */
void Passive12_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606446E, 3s-reloc: sf3 src/PASS12.c:1961 Passive12_0116 */
void Passive12_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606448C, 3s-reloc: sf3 src/PASS12.c:1974 Passive12_0117 */
void Passive12_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060644CC, 3s-reloc: sf3 src/PASS12.c:1990 Passive12_0118 */
void Passive12_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064540, 3s-exact: sf3 src/PASS12.c:2006 Passive12_0119 */
void Passive12_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064596, 3s-exact: sf3 src/PASS12.c:2025 Passive12_0120 */
void Passive12_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060645EA, 3s-exact: sf3 src/PASS12.c:2047 Passive12_0121 */
void Passive12_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606460A, 3s-reloc: sf3 src/PASS12.c:2060 Passive12_0122 */
void Passive12_0122(PLW* wk) {
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



/* 2i 06064656, 3s-exact: sf3 src/PASS12.c:2076 Passive12_0123 */
void Passive12_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606469C, 3s-exact: sf3 src/PASS12.c:2095 Passive12_0124 */
void Passive12_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060646E6, 3s-reloc: sf3 src/PASS12.c:2114 Passive12_0125 */
void Passive12_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064752, 3s-exact: sf3 src/PASS12.c:2133 Passive12_0126 */
void Passive12_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 2:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060647AE, 3s-reloc: sf3 src/PASS12.c:2155 Passive12_0127 */
void Passive12_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606485A, 3s-exact: sf3 src/PASS12.c:2180 Passive12_0128 */
void Passive12_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060648D8, 3s-reloc: sf3 src/PASS12.c:2202 Passive12_0129 */
void Passive12_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606498A, 3s-exact: sf3 src/PASS12.c:2230 Passive12_0130 */
void Passive12_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064A08, 3s-reloc: sf3 src/PASS12.c:2252 Passive12_0131 */
void Passive12_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064A80, 3s-exact: sf3 src/PASS12.c:2268 Passive12_0132 */
void Passive12_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064AE8, 3s-reloc: sf3 src/PASS12.c:2287 Passive12_0133 */
void Passive12_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064B8A, 3s-exact: sf3 src/PASS12.c:2309 Passive12_0134 */
void Passive12_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064BF2, 3s-exact: sf3 src/PASS12.c:2328 Passive12_0135 */
void Passive12_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064C40, 3s-reloc: sf3 src/PASS12.c:2344 Passive12_0136 */
void Passive12_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064CC0, 3s-exact: sf3 src/PASS12.c:2363 Passive12_0137 */
void Passive12_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064D0E, 3s-exact: sf3 src/PASS12.c:2382 Passive12_0138 */
void Passive12_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x42);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064D5C, 3s-reloc: sf3 src/PASS12.c:2401 Passive12_0139 */
void Passive12_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064DE4, 3s-exact: sf3 src/PASS12.c:2423 Passive12_0140 */
void Passive12_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064E48, 3s-reloc: sf3 src/PASS12.c:2445 Passive12_0141 */
void Passive12_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064EA8, 3s-exact: sf3 src/PASS12.c:2461 Passive12_0142 */
void Passive12_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064F1C, 3s-reloc: sf3 src/PASS12.c:2483 Passive12_0143 */
void Passive12_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06064FB0, 3s-exact: sf3 src/PASS12.c:2505 Passive12_0144 */
void Passive12_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1c, 0x400a, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065034, 3s-reloc: sf3 src/PASS12.c:2530 Passive12_0145 */
void Passive12_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060650DA, 3s-exact: sf3 src/PASS12.c:2555 Passive12_0146 */
void Passive12_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xc, 0, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065130, 3s-reloc: sf3 src/PASS12.c:2574 Passive12_0147 */
void Passive12_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060651CC, 3s-exact: sf3 src/PASS12.c:2602 Passive12_0148 */
void Passive12_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065220, 3s-reloc: sf3 src/PASS12.c:2624 Passive12_0149 */
void Passive12_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060652A4, 3s-exact: sf3 src/PASS12.c:2649 Passive12_0150 */
void Passive12_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 3:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065312, 3s-reloc: sf3 src/PASS12.c:2674 Passive12_0151 */
void Passive12_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 4:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 5:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060653AE, 3s-exact: sf3 src/PASS12.c:2702 Passive12_0152 */
void Passive12_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xA9, 0xA8, 0xB9, 0x86, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060653F8, 3s-exact: sf3 src/PASS12.c:2718 Passive12_0153 */
void Passive12_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606544E, 3s-reloc: sf3 src/PASS12.c:2737 Passive12_0154 */
void Passive12_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060654A8, 3s-exact: sf3 src/PASS12.c:2753 Passive12_0155 */
void Passive12_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060654D4, 3s-exact: sf3 src/PASS12.c:2769 Passive12_0156 */
void Passive12_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065522, 3s-reloc: sf3 src/PASS12.c:2788 Passive12_0157 */
void Passive12_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 4:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060655EC, 3s-reloc: sf3 src/PASS12.c:2816 Passive12_0158 */
void Passive12_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 4:
        SA_Term(wk, 0x30, -1, 0x32, 0);
        break;
    case 5:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060656B0, 3s-exact: sf3 src/PASS12.c:2844 Passive12_0159 */
void Passive12_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065714, 3s-exact: sf3 src/PASS12.c:2866 Passive12_0160 */
void Passive12_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606577C, 3s-reloc: sf3 src/PASS12.c:2885 Passive12_0161 */
void Passive12_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606581C, 3s-exact: sf3 src/PASS12.c:2904 Passive12_0162 */
void Passive12_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606585C, 3s-reloc: sf3 src/PASS12.c:2920 Passive12_0163 */
void Passive12_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065920, 3s-exact: sf3 src/PASS12.c:2948 Passive12_0164 */
void Passive12_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065972, 3s-reloc: sf3 src/PASS12.c:2964 Passive12_0165 */
void Passive12_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x202));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065A08, 3s-exact: sf3 src/PASS12.c:2983 Passive12_0166 */
void Passive12_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065A5A, 3s-exact: sf3 src/PASS12.c:2999 Passive12_0167 */
void Passive12_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x202));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065AC2, 3s-reloc: sf3 src/PASS12.c:3018 Passive12_0168 */
void Passive12_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065B0C, 3s-exact: sf3 src/PASS12.c:3031 Passive12_0169 */
void Passive12_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065B4C, 3s-exact: sf3 src/PASS12.c:3047 Passive12_0170 */
void Passive12_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065B78, 3s-exact: sf3 src/PASS12.c:3063 Passive12_0171 */
void Passive12_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065BC6, 3s-reloc: sf3 src/PASS12.c:3082 Passive12_0172 */
void Passive12_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x50, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x3F, 0x40, 0x41, 0x43, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065C2E, 3s-reloc: sf3 src/PASS12.c:3098 Passive12_0173 */
void Passive12_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065CF8, 3s-exact: sf3 src/PASS12.c:3126 Passive12_0174 */
void Passive12_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1c, 0x400a, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065D8A, 3s-reloc: sf3 src/PASS12.c:3154 Passive12_0175 */
void Passive12_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065E00, 3s-exact: sf3 src/PASS12.c:3173 Passive12_0176 */
void Passive12_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065E72, 3s-reloc: sf3 src/PASS12.c:3198 Passive12_0177 */
void Passive12_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065EF0, 3s-exact: sf3 src/PASS12.c:3217 Passive12_0178 */
void Passive12_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065F7A, 3s-exact: sf3 src/PASS12.c:3242 Passive12_0179 */
void Passive12_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06065FA8, 3s-reloc: sf3 src/PASS12.c:3258 Passive12_0180 */
void Passive12_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066018, 3s-exact: sf3 src/PASS12.c:3274 Passive12_0181 */
void Passive12_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066068, 3s-exact: sf3 src/PASS12.c:3293 Passive12_0182 */
void Passive12_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066088, 3s-reloc: sf3 src/PASS12.c:3306 Passive12_0183 */
void Passive12_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606611C, 3s-exact: sf3 src/PASS12.c:3325 Passive12_0184 */
void Passive12_0184(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060661BA, 3s-exact: sf3 src/PASS12.c:3353 Passive12_0185 */
void Passive12_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060661DA, 3s-reloc: sf3 src/PASS12.c:3366 Passive12_0186 */
void Passive12_0186(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066258, 3s-exact: sf3 src/PASS12.c:3382 Passive12_0187 */
void Passive12_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060662AA, 3s-exact: sf3 src/PASS12.c:3398 Passive12_0188 */
void Passive12_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060662FC, 3s-reloc: sf3 src/PASS12.c:3414 Passive12_0189 */
void Passive12_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066360, 3s-exact: sf3 src/PASS12.c:3430 Passive12_0190 */
void Passive12_0190(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060663AC, 3s-exact: sf3 src/PASS12.c:3446 Passive12_0191 */
void Passive12_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x3F, 0x40, 0x41, 0x43, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060663F4, 3s-reloc: sf3 src/PASS12.c:3462 Passive12_0192 */
void Passive12_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066464, 3s-exact: sf3 src/PASS12.c:3478 Passive12_0193 */
void Passive12_0193(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060664AE, 3s-exact: sf3 src/PASS12.c:3494 Passive12_0194 */
void Passive12_0194(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    case 1:
        Com_Random_Select(wk, 6, 1, 1, 0xC0, 0xC0, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060664F4, 3s-exact: sf3 src/PASS12.c:3510 Passive12_0195 */
void Passive12_0195(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 1:
        Com_Random_Select(wk, 6, 1, 1, 0xC0, 0xC0, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606653A, 3s-reloc: sf3 src/PASS12.c:3526 Passive12_0196 */
void Passive12_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060665A8, 3s-exact: sf3 src/PASS12.c:3542 Passive12_0197 */
void Passive12_0197(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060665EC, 3s-exact: sf3 src/PASS12.c:3558 Passive12_0198 */
void Passive12_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606660A, 3s-exact: sf3 src/PASS12.c:3571 Passive12_0199 */
void Passive12_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606664A, 3s-reloc: sf3 src/PASS12.c:3587 Passive12_0200 */
void Passive12_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060666AE, 3s-exact: sf3 src/PASS12.c:3603 Passive12_0201 */
void Passive12_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066710, 3s-exact: sf3 src/PASS12.c:3625 Passive12_0202 */
void Passive12_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066766, 3s-reloc: sf3 src/PASS12.c:3644 Passive12_0203 */
void Passive12_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x14, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xC6, 0xC4, 0xC5, 0x2F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060667D0, 3s-reloc: sf3 src/PASS12.c:3660 Passive12_0204 */
void Passive12_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x2F);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x51, 0x1C, 0x4D, 0x25, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606683A, 3s-near: sf3 src/PASS12.c:3682 Passive12_0205 */
void Passive12_0205(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060668CA, 3s-exact: sf3 src/PASS12.c:3704 Passive12_0206 */
void Passive12_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060668EA, 3s-near: sf3 src/PASS12.c:3717 Passive12_0207 */
void Passive12_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x53, 0x54, 0x13, 0x25, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606693A, 3s-exact: sf3 src/PASS12.c:3736 Passive12_0208 */
void Passive12_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x53, 0x54, 1, 0x25, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606698A, 3s-reloc: sf3 src/PASS12.c:3755 Passive12_0209 */
void Passive12_0209(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060669CC, 3s-exact: sf3 src/PASS12.c:3768 Passive12_0210 */
void Passive12_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066A16, 3s-reloc: sf3 src/PASS12.c:3787 Passive12_0211 */
void Passive12_0211(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 12, 0x1D, 10, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066AD4, 3s-exact: sf3 src/PASS12.c:3815 Passive12_0212 */
void Passive12_0212(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066B48, 3s-reloc: sf3 src/PASS12.c:3837 Passive12_0213 */
void Passive12_0213(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066C04, 3s-exact: sf3 src/PASS12.c:3862 Passive12_0214 */
void Passive12_0214(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066C44, 3s-exact: sf3 src/PASS12.c:3878 Passive12_0215 */
void Passive12_0215(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0x1E, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066C72, 3s-exact: sf3 src/PASS12.c:3894 Passive12_0216 */
void Passive12_0216(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Lever_Attack(wk, 8, 0x1E, 0xA);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066CA0, 3s-reloc: sf3 src/PASS12.c:3910 Passive12_0217 */
void Passive12_0217(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 5:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066D4C, 3s-exact: sf3 src/PASS12.c:3938 Passive12_0218 */
void Passive12_0218(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066D7E, 3s-exact: sf3 src/PASS12.c:3951 Passive12_0219 */
void Passive12_0219(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x400B, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066DB0, 3s-exact: sf3 src/PASS12.c:3964 Passive12_0220 */
void Passive12_0220(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066DE2, 3s-reloc: sf3 src/PASS12.c:3977 Passive12_0221 */
void Passive12_0221(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xA, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066E42, 3s-reloc: sf3 src/PASS12.c:3990 Passive12_0222 */
void Passive12_0222(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066E9C, 3s-reloc: sf3 src/PASS12.c:4012 Passive12_0223 */
void Passive12_0223(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

