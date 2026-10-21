/*
 * PASS05.C  CPU passive patterns for character 5 (Necro)
 *
 * Passive05 is the CPU passive (defensive) routine for character 5, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive05_Tbl.
 * The 102 Passive05_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS05.h"



/* 2i 0604A480, 3s-exact: sf3 src/PASS05.c:21 Passive05 */
void Passive05(PLW* wk) {
    Passive05_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0604A498, 3s-exact: sf3 src/PASS05.c:27 Passive05_0000 */
void Passive05_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A4CC, 3s-exact: sf3 src/PASS05.c:40 Passive05_0001 */
void Passive05_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A4EA, 3s-exact: sf3 src/PASS05.c:53 Passive05_0002 */
void Passive05_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A51C, 3s-exact: sf3 src/PASS05.c:66 Passive05_0003 */
void Passive05_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A54E, 3s-exact: sf3 src/PASS05.c:79 Passive05_0004 */
void Passive05_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A580, 3s-exact: sf3 src/PASS05.c:92 Passive05_0005 */
void Passive05_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A5B2, 3s-exact: sf3 src/PASS05.c:105 Passive05_0006 */
void Passive05_0006(PLW* wk) {
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



/* 2i 0604A5DA, 3s-reloc: sf3 src/PASS05.c:121 Passive05_0007 */
void Passive05_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x41D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A65E, 3s-exact: sf3 src/PASS05.c:137 Passive05_0008 */
void Passive05_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x41D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A6AC, 3s-exact: sf3 src/PASS05.c:153 Passive05_0009 */
void Passive05_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A710, 3s-reloc: sf3 src/PASS05.c:172 Passive05_0010 */
void Passive05_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8030, 0x8038, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A772, 3s-exact: sf3 src/PASS05.c:188 Passive05_0011 */
void Passive05_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8088, 0x8048, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A7B8, 3s-exact: sf3 src/PASS05.c:204 Passive05_0012 */
void Passive05_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, 0, 0, 2, 0);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A804, 3s-reloc: sf3 src/PASS05.c:220 Passive05_0013 */
void Passive05_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A870, 3s-reloc: sf3 src/PASS05.c:236 Passive05_0014 */
void Passive05_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A88E, 3s-reloc: sf3 src/PASS05.c:249 Passive05_0015 */
void Passive05_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A8AE, 3s-near: sf3 src/PASS05.c:262 Passive05_0016 */
void Passive05_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A8E8, 3s-reloc: sf3 src/PASS05.c:281 Passive05_0017 */
void Passive05_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A920, 3s-reloc: sf3 src/PASS05.c:300 Passive05_0018 */
void Passive05_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A98C, 3s-near: sf3 src/PASS05.c:319 Passive05_0019 */
void Passive05_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A9AC, 3s-exact: sf3 src/PASS05.c:332 Passive05_0020 */
void Passive05_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A9CC, 3s-exact: sf3 src/PASS05.c:345 Passive05_0021 */
void Passive05_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AA1A, 3s-reloc: sf3 src/PASS05.c:364 Passive05_0022 */
void Passive05_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x40, 8, 0x202, 0, 0x8098, -1, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AA8C, 3s-exact: sf3 src/PASS05.c:380 Passive05_0023 */
void Passive05_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 8, 0x40, 0, 0x8088, -1, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AADE, 3s-exact: sf3 src/PASS05.c:396 Passive05_0024 */
void Passive05_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AB18, 3s-reloc: sf3 src/PASS05.c:415 Passive05_0025 */
void Passive05_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AB94, 3s-exact: sf3 src/PASS05.c:431 Passive05_0026 */
void Passive05_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ABD8, 3s-exact: sf3 src/PASS05.c:447 Passive05_0027 */
void Passive05_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AC18, 3s-exact: sf3 src/PASS05.c:463 Passive05_0028 */
void Passive05_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 0, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AC66, 3s-reloc: sf3 src/PASS05.c:479 Passive05_0029 */
void Passive05_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ACAC, 3s-reloc: sf3 src/PASS05.c:492 Passive05_0030 */
void Passive05_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ACCC, 3s-reloc: sf3 src/PASS05.c:505 Passive05_0031 */
void Passive05_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ACEE, 3s-near: sf3 src/PASS05.c:518 Passive05_0032 */
void Passive05_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AD10, 3s-near: sf3 src/PASS05.c:531 Passive05_0033 */
void Passive05_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AD32, 3s-reloc: sf3 src/PASS05.c:544 Passive05_0034 */
void Passive05_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AD52, 3s-reloc: sf3 src/PASS05.c:557 Passive05_0035 */
void Passive05_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AD72, 3s-reloc: sf3 src/PASS05.c:570 Passive05_0036 */
void Passive05_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ADB0, 3s-near: sf3 src/PASS05.c:583 Passive05_0037 */
void Passive05_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ADF6, 3s-near: sf3 src/PASS05.c:599 Passive05_0038 */
void Passive05_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AE3C, 3s-exact: sf3 src/PASS05.c:615 Passive05_0039 */
void Passive05_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8035, 0x8008, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AE82, 3s-reloc: sf3 src/PASS05.c:631 Passive05_0040 */
void Passive05_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AEEA, 3s-exact: sf3 src/PASS05.c:647 Passive05_0041 */
void Passive05_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AF2A, 3s-exact: sf3 src/PASS05.c:663 Passive05_0042 */
void Passive05_0042(PLW* wk) {
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



/* 2i 0604AF52, 3s-reloc: sf3 src/PASS05.c:679 Passive05_0043 */
void Passive05_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 0, 6, 0x1F);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604AFC4, 3s-near: sf3 src/PASS05.c:695 Passive05_0044 */
void Passive05_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 3, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B018, 3s-reloc: sf3 src/PASS05.c:714 Passive05_0045 */
void Passive05_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B038, 3s-reloc: sf3 src/PASS05.c:727 Passive05_0046 */
void Passive05_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B058, 3s-reloc: sf3 src/PASS05.c:740 Passive05_0047 */
void Passive05_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B098, 3s-reloc: sf3 src/PASS05.c:756 Passive05_0048 */
void Passive05_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B0E2, 3s-exact: sf3 src/PASS05.c:769 Passive05_0049 */
void Passive05_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B102, 3s-exact: sf3 src/PASS05.c:782 Passive05_0050 */
void Passive05_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B122, 3s-exact: sf3 src/PASS05.c:795 Passive05_0051 */
void Passive05_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B146, 3s-exact: sf3 src/PASS05.c:811 Passive05_0052 */
void Passive05_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B166, 3s-exact: sf3 src/PASS05.c:824 Passive05_0053 */
void Passive05_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B198, 3s-reloc: sf3 src/PASS05.c:837 Passive05_0054 */
void Passive05_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x87, 0, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B1FE, 3s-exact: sf3 src/PASS05.c:853 Passive05_0055 */
void Passive05_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B230, 3s-exact: sf3 src/PASS05.c:866 Passive05_0056 */
void Passive05_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 0, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 10, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B27C, 3s-exact: sf3 src/PASS05.c:882 Passive05_0057 */
void Passive05_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 8, 0x202, 2, 0x8080, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B2BE, 3s-reloc: sf3 src/PASS05.c:895 Passive05_0058 */
void Passive05_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B308, 3s-exact: sf3 src/PASS05.c:908 Passive05_0059 */
void Passive05_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B362, 3s-exact: sf3 src/PASS05.c:927 Passive05_0060 */
void Passive05_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B380, 3s-exact: sf3 src/PASS05.c:940 Passive05_0061 */
void Passive05_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B3A0, 3s-reloc: sf3 src/PASS05.c:953 Passive05_0062 */
void Passive05_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B400, 3s-exact: sf3 src/PASS05.c:972 Passive05_0063 */
void Passive05_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B432, 3s-exact: sf3 src/PASS05.c:985 Passive05_0064 */
void Passive05_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B480, 3s-exact: sf3 src/PASS05.c:1004 Passive05_0065 */
void Passive05_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B4CE, 3s-reloc: sf3 src/PASS05.c:1023 Passive05_0066 */
void Passive05_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B52A, 3s-exact: sf3 src/PASS05.c:1039 Passive05_0067 */
void Passive05_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B54A, 3s-exact: sf3 src/PASS05.c:1052 Passive05_0068 */
void Passive05_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B56A, 3s-exact: sf3 src/PASS05.c:1065 Passive05_0069 */
void Passive05_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 2:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B5B8, 3s-reloc: sf3 src/PASS05.c:1084 Passive05_0070 */
void Passive05_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B63A, 3s-exact: sf3 src/PASS05.c:1109 Passive05_0071 */
void Passive05_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8058, 0x8008, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x36, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B69E, 3s-reloc: sf3 src/PASS05.c:1128 Passive05_0072 */
void Passive05_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8008, 5, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 2:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B71C, 3s-exact: sf3 src/PASS05.c:1147 Passive05_0073 */
void Passive05_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 5, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 2:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 10, 0x102);
        break;
    case 4:
        Normal_Attack(wk, 10, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B78E, 3s-reloc: sf3 src/PASS05.c:1172 Passive05_0074 */
void Passive05_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8010, 5, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B81C, 3s-exact: sf3 src/PASS05.c:1191 Passive05_0075 */
void Passive05_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 5, 6, 0x1F);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x41D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B880, 3s-exact: sf3 src/PASS05.c:1213 Passive05_0076 */
void Passive05_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1C);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B8C6, 3s-reloc: sf3 src/PASS05.c:1229 Passive05_0077 */
void Passive05_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B920, 3s-exact: sf3 src/PASS05.c:1245 Passive05_0078 */
void Passive05_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B94C, 3s-exact: sf3 src/PASS05.c:1261 Passive05_0079 */
void Passive05_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B96A, 3s-exact: sf3 src/PASS05.c:1274 Passive05_0080 */
void Passive05_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604B97E, 3s-reloc: sf3 src/PASS05.c:1284 Passive05_0081 */
void Passive05_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8058, 9, 0x40, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        Command_Attack(wk, 9, 0x1E, 10, -1);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BA30, 3s-exact: sf3 src/PASS05.c:1309 Passive05_0082 */
void Passive05_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 3:
        Command_Attack(wk, 9, 0x1c, 0xa, -1);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BAB4, 3s-exact: sf3 src/PASS05.c:1334 Passive05_0083 */
void Passive05_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BAD2, 3s-reloc: sf3 src/PASS05.c:1347 Passive05_0084 */
void Passive05_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 9, 0x102, 1, 0x8050, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BB48, 3s-exact: sf3 src/PASS05.c:1360 Passive05_0085 */
void Passive05_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, 0x8008, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xD, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BB8E, 3s-exact: sf3 src/PASS05.c:1376 Passive05_0086 */
void Passive05_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 6, 0x5A);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BBF0, 3s-exact: sf3 src/PASS05.c:1398 Passive05_0087 */
void Passive05_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BC10, 3s-reloc: sf3 src/PASS05.c:1411 Passive05_0088 */
void Passive05_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BC82, 3s-near: sf3 src/PASS05.c:1427 Passive05_0089 */
void Passive05_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0xE, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BCB4, 3s-near: sf3 src/PASS05.c:1440 Passive05_0090 */
void Passive05_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BCFC, 3s-near: sf3 src/PASS05.c:1456 Passive05_0091 */
void Passive05_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 5, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 2:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BD54, 3s-near: sf3 src/PASS05.c:1475 Passive05_0092 */
void Passive05_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x50, 8, 0x102, 2, 0x8080, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BDB6, 3s-exact: sf3 src/PASS05.c:1488 Passive05_0093 */
void Passive05_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8088, 9, 0x200, 0, 0x8060, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BDF8, 3s-exact: sf3 src/PASS05.c:1501 Passive05_0094 */
void Passive05_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BE3C, 3s-reloc: sf3 src/PASS05.c:1517 Passive05_0095 */
void Passive05_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BEB4, 3s-reloc: sf3 src/PASS05.c:1533 Passive05_0096 */
void Passive05_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BEFC, 3s-reloc: sf3 src/PASS05.c:1552 Passive05_0097 */
void Passive05_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604BF1C, 3s-reloc: sf3 src/PASS05.c:1565 Passive05_0098 */
void Passive05_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

