/*
 * PASS01.C  CPU passive patterns for character 1 (Alex)
 *
 * Passive01 is the CPU passive (defensive) routine for character 1, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive01_Tbl.
 * The 176 Passive01_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS01.h"



/* 2i 0603FFB0, 3s-exact: sf3 src/PASS01.c:21 Passive01 */
void Passive01(PLW* wk) {
    Passive01_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0603FFC8, 3s-exact: sf3 src/PASS01.c:27 Passive01_0000 */
void Passive01_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FFFC, 3s-exact: sf3 src/PASS01.c:40 Passive01_0001 */
void Passive01_0001(PLW* wk) {
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



/* 2i 06040024, 3s-exact: sf3 src/PASS01.c:56 Passive01_0002 */
void Passive01_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604008E, 3s-reloc: sf3 src/PASS01.c:78 Passive01_0003 */
void Passive01_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060400E4, 3s-exact: sf3 src/PASS01.c:91 Passive01_0004 */
void Passive01_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x53);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040126, 3s-exact: sf3 src/PASS01.c:107 Passive01_0005 */
void Passive01_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040144, 3s-exact: sf3 src/PASS01.c:120 Passive01_0006 */
void Passive01_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040188, 3s-reloc: sf3 src/PASS01.c:136 Passive01_0007 */
void Passive01_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060401E8, 3s-exact: sf3 src/PASS01.c:152 Passive01_0008 */
void Passive01_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604023A, 3s-exact: sf3 src/PASS01.c:171 Passive01_0009 */
void Passive01_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604026C, 3s-exact: sf3 src/PASS01.c:184 Passive01_0010 */
void Passive01_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604029E, 3s-exact: sf3 src/PASS01.c:197 Passive01_0011 */
void Passive01_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 2, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060402E0, 3s-reloc: sf3 src/PASS01.c:210 Passive01_0012 */
void Passive01_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040322, 3s-exact: sf3 src/PASS01.c:223 Passive01_0013 */
void Passive01_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040364, 3s-exact: sf3 src/PASS01.c:239 Passive01_0014 */
void Passive01_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060403A6, 3s-exact: sf3 src/PASS01.c:255 Passive01_0015 */
void Passive01_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060403C6, 3s-reloc: sf3 src/PASS01.c:268 Passive01_0016 */
void Passive01_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x8D, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 4:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040458, 3s-exact: sf3 src/PASS01.c:293 Passive01_0017 */
void Passive01_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060404A6, 3s-reloc: sf3 src/PASS01.c:315 Passive01_0018 */
void Passive01_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x8D, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 5:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040544, 3s-near: sf3 src/PASS01.c:343 Passive01_0019 */
void Passive01_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040564, 3s-exact: sf3 src/PASS01.c:356 Passive01_0020 */
void Passive01_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040584, 3s-exact: sf3 src/PASS01.c:369 Passive01_0021 */
void Passive01_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060405C4, 3s-reloc: sf3 src/PASS01.c:385 Passive01_0022 */
void Passive01_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8080, 0x8050, 0xB, 0x80, 0, 0x8060, -1, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604065C, 3s-exact: sf3 src/PASS01.c:410 Passive01_0023 */
void Passive01_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x20, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060406BC, 3s-reloc: sf3 src/PASS01.c:429 Passive01_0024 */
void Passive01_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x8D, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040738, 3s-exact: sf3 src/PASS01.c:454 Passive01_0025 */
void Passive01_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x8D, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 6:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060407B2, 3s-exact: sf3 src/PASS01.c:485 Passive01_0026 */
void Passive01_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060407F6, 3s-reloc: sf3 src/PASS01.c:501 Passive01_0027 */
void Passive01_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040860, 3s-exact: sf3 src/PASS01.c:517 Passive01_0028 */
void Passive01_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xA, 0x200, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040892, 3s-exact: sf3 src/PASS01.c:530 Passive01_0029 */
void Passive01_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060408CA, 3s-exact: sf3 src/PASS01.c:549 Passive01_0030 */
void Passive01_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040910, 3s-reloc: sf3 src/PASS01.c:565 Passive01_0031 */
void Passive01_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040958, 3s-exact: sf3 src/PASS01.c:578 Passive01_0032 */
void Passive01_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0x59);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060409A0, 3s-near: sf3 src/PASS01.c:594 Passive01_0033 */
void Passive01_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060409C2, 3s-near: sf3 src/PASS01.c:607 Passive01_0034 */
void Passive01_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040A02, 3s-near: sf3 src/PASS01.c:623 Passive01_0035 */
void Passive01_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040A60, 3s-reloc: sf3 src/PASS01.c:642 Passive01_0036 */
void Passive01_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xB, 0x1E, 0xA, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040AAE, 3s-near: sf3 src/PASS01.c:658 Passive01_0037 */
void Passive01_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040AF4, 3s-reloc: sf3 src/PASS01.c:674 Passive01_0038 */
void Passive01_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040B52, 3s-reloc: sf3 src/PASS01.c:693 Passive01_0039 */
void Passive01_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040BA0, 3s-reloc: sf3 src/PASS01.c:709 Passive01_0040 */
void Passive01_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040C26, 3s-near: sf3 src/PASS01.c:731 Passive01_0041 */
void Passive01_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8040, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040C6C, 3s-near: sf3 src/PASS01.c:750 Passive01_0042 */
void Passive01_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040C9E, 3s-near: sf3 src/PASS01.c:763 Passive01_0043 */
void Passive01_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8048, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040D10, 3s-near: sf3 src/PASS01.c:779 Passive01_0044 */
void Passive01_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1d, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040D6E, 3s-near: sf3 src/PASS01.c:798 Passive01_0045 */
void Passive01_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8028, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040DB6, 3s-near: sf3 src/PASS01.c:814 Passive01_0046 */
void Passive01_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040DD6, 3s-near: sf3 src/PASS01.c:827 Passive01_0047 */
void Passive01_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040E3C, 3s-reloc: sf3 src/PASS01.c:843 Passive01_0048 */
void Passive01_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040E66, 3s-reloc: sf3 src/PASS01.c:859 Passive01_0049 */
void Passive01_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040EAA, 3s-reloc: sf3 src/PASS01.c:875 Passive01_0050 */
void Passive01_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040EEE, 3s-near: sf3 src/PASS01.c:891 Passive01_0051 */
void Passive01_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040F50, 3s-reloc: sf3 src/PASS01.c:907 Passive01_0052 */
void Passive01_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040F70, 3s-reloc: sf3 src/PASS01.c:920 Passive01_0053 */
void Passive01_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040FA2, 3s-reloc: sf3 src/PASS01.c:933 Passive01_0054 */
void Passive01_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x68, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06040FD6, 3s-reloc: sf3 src/PASS01.c:946 Passive01_0055 */
void Passive01_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041008, 3s-near: sf3 src/PASS01.c:959 Passive01_0056 */
void Passive01_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x100, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041070, 3s-reloc: sf3 src/PASS01.c:972 Passive01_0057 */
void Passive01_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x20, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060410B2, 3s-reloc: sf3 src/PASS01.c:985 Passive01_0058 */
void Passive01_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060410D2, 3s-reloc: sf3 src/PASS01.c:998 Passive01_0059 */
void Passive01_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041104, 3s-reloc: sf3 src/PASS01.c:1011 Passive01_0060 */
void Passive01_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041122, 3s-reloc: sf3 src/PASS01.c:1024 Passive01_0061 */
void Passive01_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x59, 2);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0x59);
        break;
    case 3:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604119C, 3s-near: sf3 src/PASS01.c:1049 Passive01_0062 */
void Passive01_0062(PLW* wk) {
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



/* 2i 060411CA, 3s-near: sf3 src/PASS01.c:1068 Passive01_0063 */
void Passive01_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x21);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041206, 3s-near: sf3 src/PASS01.c:1087 Passive01_0064 */
void Passive01_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604125A, 3s-near: sf3 src/PASS01.c:1100 Passive01_0065 */
void Passive01_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060412C6, 3s-near: sf3 src/PASS01.c:1122 Passive01_0066 */
void Passive01_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041306, 3s-near: sf3 src/PASS01.c:1138 Passive01_0067 */
void Passive01_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041354, 3s-reloc: sf3 src/PASS01.c:1154 Passive01_0068 */
void Passive01_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 8, 0x100, 0, 0x8060, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041396, 3s-reloc: sf3 src/PASS01.c:1167 Passive01_0069 */
void Passive01_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xC, 0x42, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060413C8, 3s-reloc: sf3 src/PASS01.c:1180 Passive01_0070 */
void Passive01_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060413F6, 3s-near: sf3 src/PASS01.c:1196 Passive01_0071 */
void Passive01_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604144C, 3s-reloc: sf3 src/PASS01.c:1212 Passive01_0072 */
void Passive01_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060414AC, 3s-reloc: sf3 src/PASS01.c:1234 Passive01_0073 */
void Passive01_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060414FC, 3s-reloc: sf3 src/PASS01.c:1253 Passive01_0074 */
void Passive01_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0x59);
        break;
    case 1:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041576, 3s-near: sf3 src/PASS01.c:1272 Passive01_0075 */
void Passive01_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x59, 2);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0x59);
        break;
    case 3:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060415F0, 3s-near: sf3 src/PASS01.c:1297 Passive01_0076 */
void Passive01_0076(PLW* wk) {
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



/* 2i 06041660, 3s-reloc: sf3 src/PASS01.c:1316 Passive01_0077 */
void Passive01_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x40, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060416B0, 3s-reloc: sf3 src/PASS01.c:1332 Passive01_0078 */
void Passive01_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x80, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604170A, 3s-reloc: sf3 src/PASS01.c:1351 Passive01_0079 */
void Passive01_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x80A0, 0x8050, 0xB, 0x20, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604177C, 3s-reloc: sf3 src/PASS01.c:1367 Passive01_0080 */
void Passive01_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060417CC, 3s-reloc: sf3 src/PASS01.c:1383 Passive01_0081 */
void Passive01_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x80, 0, 0x8060, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041824, 3s-reloc: sf3 src/PASS01.c:1402 Passive01_0082 */
void Passive01_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x80A0, 0x8060, 0xB, 0x20, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041894, 3s-near: sf3 src/PASS01.c:1418 Passive01_0083 */
void Passive01_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x100), 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060418F8, 3s-near: sf3 src/PASS01.c:1440 Passive01_0084 */
void Passive01_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 0xC, 0xC, 0x42, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604194C, 3s-near: sf3 src/PASS01.c:1462 Passive01_0085 */
void Passive01_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xA);
        break;
    case 1:
        Com_Random_Select(wk, 6, 5, 9, 0x35, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060419B4, 3s-near: sf3 src/PASS01.c:1478 Passive01_0086 */
void Passive01_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x59, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x2E, -1, -1, 0x59);
        break;
    case 3:
        Approach_Walk(wk, 0x4f, 2);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041A32, 3s-reloc: sf3 src/PASS01.c:1503 Passive01_0087 */
void Passive01_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x59, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x2E, 0x2F, -1, 0x59);
        break;
    case 3:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041AB0, 3s-reloc: sf3 src/PASS01.c:1528 Passive01_0088 */
void Passive01_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041B16, 3s-reloc: sf3 src/PASS01.c:1547 Passive01_0089 */
void Passive01_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041B48, 3s-reloc: sf3 src/PASS01.c:1560 Passive01_0090 */
void Passive01_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041B7A, 3s-reloc: sf3 src/PASS01.c:1573 Passive01_0091 */
void Passive01_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041BDA, 3s-near: sf3 src/PASS01.c:1586 Passive01_0092 */
void Passive01_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041C2A, 3s-reloc: sf3 src/PASS01.c:1605 Passive01_0093 */
void Passive01_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041C54, 3s-reloc: sf3 src/PASS01.c:1621 Passive01_0094 */
void Passive01_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041C76, 3s-reloc: sf3 src/PASS01.c:1634 Passive01_0095 */
void Passive01_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041CDC, 3s-near: sf3 src/PASS01.c:1653 Passive01_0096 */
void Passive01_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8028, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041D22, 3s-near: sf3 src/PASS01.c:1672 Passive01_0097 */
void Passive01_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
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



/* 2i 06041D76, 3s-near: sf3 src/PASS01.c:1691 Passive01_0098 */
void Passive01_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041E1A, 3s-reloc: sf3 src/PASS01.c:1713 Passive01_0099 */
void Passive01_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041E7A, 3s-reloc: sf3 src/PASS01.c:1732 Passive01_0100 */
void Passive01_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
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



/* 2i 06041F10, 3s-reloc: sf3 src/PASS01.c:1754 Passive01_0101 */
void Passive01_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0x59);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041F68, 3s-reloc: sf3 src/PASS01.c:1773 Passive01_0102 */
void Passive01_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041FAE, 3s-reloc: sf3 src/PASS01.c:1789 Passive01_0103 */
void Passive01_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06041FCE, 3s-reloc: sf3 src/PASS01.c:1802 Passive01_0104 */
void Passive01_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042028, 3s-exact: sf3 src/PASS01.c:1815 Passive01_0105 */
void Passive01_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604205A, 3s-exact: sf3 src/PASS01.c:1828 Passive01_0106 */
void Passive01_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604208C, 3s-near: sf3 src/PASS01.c:1841 Passive01_0107 */
void Passive01_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Walk(wk, 1, 0x20, 0);
        break;
    case 2:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060420C8, 3s-exact: sf3 src/PASS01.c:1860 Passive01_0108 */
void Passive01_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060420E8, 3s-exact: sf3 src/PASS01.c:1873 Passive01_0109 */
void Passive01_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042142, 3s-near: sf3 src/PASS01.c:1895 Passive01_0110 */
void Passive01_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;
    case 1:
        Walk(wk, 1, 0x38, 0);
        break;
    case 2:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604217E, 3s-exact: sf3 src/PASS01.c:1914 Passive01_0111 */
void Passive01_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x42);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060421E0, 3s-exact: sf3 src/PASS01.c:1933 Passive01_0112 */
void Passive01_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042202, 3s-reloc: sf3 src/PASS01.c:1946 Passive01_0113 */
void Passive01_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042282, 3s-reloc: sf3 src/PASS01.c:1962 Passive01_0114 */
void Passive01_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060422D0, 3s-reloc: sf3 src/PASS01.c:1978 Passive01_0115 */
void Passive01_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x100, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042312, 3s-reloc: sf3 src/PASS01.c:1991 Passive01_0116 */
void Passive01_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x200), 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042354, 3s-near: sf3 src/PASS01.c:2004 Passive01_0117 */
void Passive01_0117(PLW* wk) {
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



/* 2i 060423A6, 3s-reloc: sf3 src/PASS01.c:2017 Passive01_0118 */
void Passive01_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060423C6, 3s-reloc: sf3 src/PASS01.c:2030 Passive01_0119 */
void Passive01_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1F, 1, -1);
        break;
    case 3:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042438, 3s-near: sf3 src/PASS01.c:2052 Passive01_0120 */
void Passive01_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 1, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604247A, 3s-near: sf3 src/PASS01.c:2065 Passive01_0121 */
void Passive01_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060424EC, 3s-near: sf3 src/PASS01.c:2078 Passive01_0122 */
void Passive01_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 1, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604252E, 3s-near: sf3 src/PASS01.c:2091 Passive01_0123 */
void Passive01_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 2, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042570, 3s-near: sf3 src/PASS01.c:2104 Passive01_0124 */
void Passive01_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 2, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060425B2, 3s-near: sf3 src/PASS01.c:2117 Passive01_0125 */
void Passive01_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 2, -1, 0x20, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042602, 3s-reloc: sf3 src/PASS01.c:2130 Passive01_0126 */
void Passive01_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042646, 3s-reloc: sf3 src/PASS01.c:2146 Passive01_0127 */
void Passive01_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042666, 3s-reloc: sf3 src/PASS01.c:2159 Passive01_0128 */
void Passive01_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060426A6, 3s-near: sf3 src/PASS01.c:2175 Passive01_0129 */
void Passive01_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060426D8, 3s-near: sf3 src/PASS01.c:2188 Passive01_0130 */
void Passive01_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042728, 3s-near: sf3 src/PASS01.c:2201 Passive01_0131 */
void Passive01_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604275A, 3s-near: sf3 src/PASS01.c:2214 Passive01_0132 */
void Passive01_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x81, 0x82, 0x82, 0x83);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042790, 3s-near: sf3 src/PASS01.c:2227 Passive01_0133 */
void Passive01_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x84);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060427D0, 3s-near: sf3 src/PASS01.c:2243 Passive01_0134 */
void Passive01_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042802, 3s-near: sf3 src/PASS01.c:2256 Passive01_0135 */
void Passive01_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042860, 3s-reloc: sf3 src/PASS01.c:2272 Passive01_0136 */
void Passive01_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060428A0, 3s-reloc: sf3 src/PASS01.c:2288 Passive01_0137 */
void Passive01_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060428EC, 3s-near: sf3 src/PASS01.c:2304 Passive01_0138 */
void Passive01_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x22);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604294C, 3s-near: sf3 src/PASS01.c:2320 Passive01_0139 */
void Passive01_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xA, 0x42, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604297E, 3s-near: sf3 src/PASS01.c:2333 Passive01_0140 */
void Passive01_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604299C, 3s-near: sf3 src/PASS01.c:2346 Passive01_0141 */
void Passive01_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060429E0, 3s-near: sf3 src/PASS01.c:2362 Passive01_0142 */
void Passive01_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060429FE, 3s-near: sf3 src/PASS01.c:2375 Passive01_0143 */
void Passive01_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042A6C, 3s-reloc: sf3 src/PASS01.c:2391 Passive01_0144 */
void Passive01_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0x59);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042ACA, 3s-reloc: sf3 src/PASS01.c:2410 Passive01_0145 */
void Passive01_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x30, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x73, 0x92, 0x93, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042B48, 3s-exact: sf3 src/PASS01.c:2429 Passive01_0146 */
void Passive01_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 3:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042BB6, 3s-reloc: sf3 src/PASS01.c:2454 Passive01_0147 */
void Passive01_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x85);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042BF6, 3s-exact: sf3 src/PASS01.c:2470 Passive01_0148 */
void Passive01_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042C1E, 3s-near: sf3 src/PASS01.c:2486 Passive01_0149 */
void Passive01_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, -1, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042C88, 3s-near: sf3 src/PASS01.c:2499 Passive01_0150 */
void Passive01_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, 0x8050, 8, 0x20, 2, -1, 0x8050, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042CDA, 3s-near: sf3 src/PASS01.c:2515 Passive01_0151 */
void Passive01_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042CFE, 3s-near: sf3 src/PASS01.c:2531 Passive01_0152 */
void Passive01_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042D68, 3s-exact: sf3 src/PASS01.c:2550 Passive01_0153 */
void Passive01_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042DAC, 3s-exact: sf3 src/PASS01.c:2566 Passive01_0154 */
void Passive01_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042DF4, 3s-exact: sf3 src/PASS01.c:2585 Passive01_0155 */
void Passive01_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 6);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042E36, 3s-reloc: sf3 src/PASS01.c:2601 Passive01_0156 */
void Passive01_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x9B);
        break;
    case 1:
        Wait(wk, 4);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

