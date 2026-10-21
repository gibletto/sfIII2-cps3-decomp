/*
 * PASS03.C  CPU passive patterns for character 3 (Yun)
 *
 * Passive03 is the CPU passive (defensive) routine for character 3, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive03_Tbl.
 * The 136 Passive03_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS03.h"



/* 2i 06045328, 3s-exact: sf3 src/PASS03.c:21 Passive03 */
void Passive03(PLW* wk) {
    Passive03_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06045340, 3s-exact: sf3 src/PASS03.c:27 Passive03_0000 */
void Passive03_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045374, 3s-exact: sf3 src/PASS03.c:40 Passive03_0001 */
void Passive03_0001(PLW* wk) {
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



/* 2i 0604539C, 3s-exact: sf3 src/PASS03.c:56 Passive03_0002 */
void Passive03_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 10, -1);
        break;
    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045406, 3s-reloc: sf3 src/PASS03.c:78 Passive03_0003 */
void Passive03_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604545C, 3s-exact: sf3 src/PASS03.c:91 Passive03_0004 */
void Passive03_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x53);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604549E, 3s-exact: sf3 src/PASS03.c:107 Passive03_0005 */
void Passive03_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060454BC, 3s-exact: sf3 src/PASS03.c:120 Passive03_0006 */
void Passive03_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x77, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045500, 3s-reloc: sf3 src/PASS03.c:136 Passive03_0007 */
void Passive03_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045560, 3s-exact: sf3 src/PASS03.c:152 Passive03_0008 */
void Passive03_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060455B2, 3s-exact: sf3 src/PASS03.c:171 Passive03_0009 */
void Passive03_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045600, 3s-exact: sf3 src/PASS03.c:187 Passive03_0010 */
void Passive03_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0, 0, 2, 0);
        break;
    case 1:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045650, 3s-exact: sf3 src/PASS03.c:203 Passive03_0011 */
void Passive03_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, 0x8200, 2, 0x8060, -1, 0x8200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045692, 3s-exact: sf3 src/PASS03.c:216 Passive03_0012 */
void Passive03_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, 0, 0, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060456DC, 3s-reloc: sf3 src/PASS03.c:232 Passive03_0013 */
void Passive03_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060457BA, 3s-exact: sf3 src/PASS03.c:263 Passive03_0014 */
void Passive03_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8050, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060457FE, 3s-exact: sf3 src/PASS03.c:279 Passive03_0015 */
void Passive03_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604581E, 3s-reloc: sf3 src/PASS03.c:292 Passive03_0016 */
void Passive03_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 5:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060458BC, 3s-exact: sf3 src/PASS03.c:320 Passive03_0017 */
void Passive03_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x81, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 6:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 7:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045956, 3s-reloc: sf3 src/PASS03.c:354 Passive03_0018 */
void Passive03_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x39, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060459E6, 3s-near: sf3 src/PASS03.c:379 Passive03_0019 */
void Passive03_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045A06, 3s-exact: sf3 src/PASS03.c:392 Passive03_0020 */
void Passive03_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045A26, 3s-exact: sf3 src/PASS03.c:405 Passive03_0021 */
void Passive03_0021(PLW* wk) {
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



/* 2i 06045A66, 3s-reloc: sf3 src/PASS03.c:421 Passive03_0022 */
void Passive03_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0xB, 0x80, 0, 0x8060, -1, 0x40);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045AFC, 3s-exact: sf3 src/PASS03.c:446 Passive03_0023 */
void Passive03_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, -1, 0xB, (0x8080), 0, 0x8060, -1, 0x40);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045B76, 3s-reloc: sf3 src/PASS03.c:468 Passive03_0024 */
void Passive03_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6C);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x81, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045BF0, 3s-exact: sf3 src/PASS03.c:493 Passive03_0025 */
void Passive03_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x81, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045C58, 3s-exact: sf3 src/PASS03.c:518 Passive03_0026 */
void Passive03_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045C9C, 3s-reloc: sf3 src/PASS03.c:534 Passive03_0027 */
void Passive03_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045CFC, 3s-exact: sf3 src/PASS03.c:547 Passive03_0028 */
void Passive03_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, 0x8200, 2, 0x8060, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045D3E, 3s-exact: sf3 src/PASS03.c:560 Passive03_0029 */
void Passive03_0029(PLW* wk) {
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



/* 2i 06045D76, 3s-exact: sf3 src/PASS03.c:579 Passive03_0030 */
void Passive03_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045DBA, 3s-reloc: sf3 src/PASS03.c:595 Passive03_0031 */
void Passive03_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045E04, 3s-exact: sf3 src/PASS03.c:608 Passive03_0032 */
void Passive03_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x22);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045E64, 3s-near: sf3 src/PASS03.c:630 Passive03_0033 */
void Passive03_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045E86, 3s-exact: sf3 src/PASS03.c:643 Passive03_0034 */
void Passive03_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045EC6, 3s-reloc: sf3 src/PASS03.c:659 Passive03_0035 */
void Passive03_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045F26, 3s-reloc: sf3 src/PASS03.c:678 Passive03_0036 */
void Passive03_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045F70, 3s-near: sf3 src/PASS03.c:697 Passive03_0037 */
void Passive03_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045FB6, 3s-near: sf3 src/PASS03.c:713 Passive03_0038 */
void Passive03_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046026, 3s-exact: sf3 src/PASS03.c:729 Passive03_0039 */
void Passive03_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 2, 0x42);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5A, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604606C, 3s-exact: sf3 src/PASS03.c:745 Passive03_0040 */
void Passive03_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, 0x8008, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x80));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060460CE, 3s-reloc: sf3 src/PASS03.c:767 Passive03_0041 */
void Passive03_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604614E, 3s-exact: sf3 src/PASS03.c:786 Passive03_0042 */
void Passive03_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046190, 3s-exact: sf3 src/PASS03.c:799 Passive03_0043 */
void Passive03_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060461DE, 3s-exact: sf3 src/PASS03.c:815 Passive03_0044 */
void Passive03_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x39, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1e, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604623C, 3s-exact: sf3 src/PASS03.c:834 Passive03_0045 */
void Passive03_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8020, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604628A, 3s-exact: sf3 src/PASS03.c:850 Passive03_0046 */
void Passive03_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060462AA, 3s-reloc: sf3 src/PASS03.c:863 Passive03_0047 */
void Passive03_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046326, 3s-reloc: sf3 src/PASS03.c:879 Passive03_0048 */
void Passive03_0048(PLW* wk) {
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



/* 2i 06046350, 3s-reloc: sf3 src/PASS03.c:895 Passive03_0049 */
void Passive03_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046370, 3s-reloc: sf3 src/PASS03.c:908 Passive03_0050 */
void Passive03_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046398, 3s-near: sf3 src/PASS03.c:924 Passive03_0051 */
void Passive03_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060463CA, 3s-near: sf3 src/PASS03.c:937 Passive03_0052 */
void Passive03_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046408, 3s-exact: sf3 src/PASS03.c:950 Passive03_0053 */
void Passive03_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604644A, 3s-exact: sf3 src/PASS03.c:963 Passive03_0054 */
void Passive03_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, 0x8200, 2, 0x8060, -1, 0x8200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604648C, 3s-exact: sf3 src/PASS03.c:976 Passive03_0055 */
void Passive03_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060464BE, 3s-exact: sf3 src/PASS03.c:989 Passive03_0056 */
void Passive03_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046500, 3s-exact: sf3 src/PASS03.c:1002 Passive03_0057 */
void Passive03_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x20, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046542, 3s-exact: sf3 src/PASS03.c:1015 Passive03_0058 */
void Passive03_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046562, 3s-exact: sf3 src/PASS03.c:1028 Passive03_0059 */
void Passive03_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604658E, 3s-exact: sf3 src/PASS03.c:1044 Passive03_0060 */
void Passive03_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060465AC, 3s-reloc: sf3 src/PASS03.c:1057 Passive03_0061 */
void Passive03_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2F, 0x30, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604661E, 3s-reloc: sf3 src/PASS03.c:1073 Passive03_0062 */
void Passive03_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604664C, 3s-exact: sf3 src/PASS03.c:1089 Passive03_0063 */
void Passive03_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604668C, 3s-reloc: sf3 src/PASS03.c:1105 Passive03_0064 */
void Passive03_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060466AE, 3s-reloc: sf3 src/PASS03.c:1118 Passive03_0065 */
void Passive03_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x80);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604671C, 3s-exact: sf3 src/PASS03.c:1137 Passive03_0066 */
void Passive03_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x40);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5A, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046762, 3s-exact: sf3 src/PASS03.c:1153 Passive03_0067 */
void Passive03_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046794, 3s-exact: sf3 src/PASS03.c:1166 Passive03_0068 */
void Passive03_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060467D6, 3s-exact: sf3 src/PASS03.c:1179 Passive03_0069 */
void Passive03_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046820, 3s-exact: sf3 src/PASS03.c:1195 Passive03_0070 */
void Passive03_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046872, 3s-exact: sf3 src/PASS03.c:1214 Passive03_0071 */
void Passive03_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060468C8, 3s-reloc: sf3 src/PASS03.c:1233 Passive03_0072 */
void Passive03_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046944, 3s-exact: sf3 src/PASS03.c:1252 Passive03_0073 */
void Passive03_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 0xB, (0x8200), 0, 0x8060, -1, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060469AE, 3s-reloc: sf3 src/PASS03.c:1271 Passive03_0074 */
void Passive03_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046A50, 3s-exact: sf3 src/PASS03.c:1296 Passive03_0075 */
void Passive03_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 2:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046AEC, 3s-reloc: sf3 src/PASS03.c:1327 Passive03_0076 */
void Passive03_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xB7, 2);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, 0x8200, 0, 0x8060, -1, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046BB6, 3s-exact: sf3 src/PASS03.c:1358 Passive03_0077 */
void Passive03_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0xB, 0x20, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046C06, 3s-reloc: sf3 src/PASS03.c:1374 Passive03_0078 */
void Passive03_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8050, -1, 8, (0x8200), 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046CAC, 3s-exact: sf3 src/PASS03.c:1396 Passive03_0079 */
void Passive03_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0xB, 0x20, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046D00, 3s-exact: sf3 src/PASS03.c:1412 Passive03_0080 */
void Passive03_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 0xB, 0x40, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046D50, 3s-reloc: sf3 src/PASS03.c:1428 Passive03_0081 */
void Passive03_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 0xB, 0x8100, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046DD4, 3s-exact: sf3 src/PASS03.c:1447 Passive03_0082 */
void Passive03_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8040, 0xB, 0x40, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046E28, 3s-reloc: sf3 src/PASS03.c:1463 Passive03_0083 */
void Passive03_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8040, 0xB, 0x40, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046ED0, 3s-exact: sf3 src/PASS03.c:1488 Passive03_0084 */
void Passive03_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, 0x8200, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046F58, 3s-exact: sf3 src/PASS03.c:1513 Passive03_0085 */
void Passive03_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 10);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06046F96, 3s-exact: sf3 src/PASS03.c:1529 Passive03_0086 */
void Passive03_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047024, 3s-reloc: sf3 src/PASS03.c:1557 Passive03_0087 */
void Passive03_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, -1, 0x2F, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060470FA, 3s-exact: sf3 src/PASS03.c:1588 Passive03_0088 */
void Passive03_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604718C, 3s-exact: sf3 src/PASS03.c:1616 Passive03_0089 */
void Passive03_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060471BE, 3s-exact: sf3 src/PASS03.c:1629 Passive03_0090 */
void Passive03_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060471F0, 3s-exact: sf3 src/PASS03.c:1642 Passive03_0091 */
void Passive03_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047222, 3s-exact: sf3 src/PASS03.c:1655 Passive03_0092 */
void Passive03_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8020, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047270, 3s-reloc: sf3 src/PASS03.c:1671 Passive03_0093 */
void Passive03_0093(PLW* wk) {
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



/* 2i 060472BE, 3s-exact: sf3 src/PASS03.c:1687 Passive03_0094 */
void Passive03_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060472F4, 3s-exact: sf3 src/PASS03.c:1700 Passive03_0095 */
void Passive03_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047338, 3s-exact: sf3 src/PASS03.c:1716 Passive03_0096 */
void Passive03_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604737C, 3s-near: sf3 src/PASS03.c:1732 Passive03_0097 */
void Passive03_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
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



/* 2i 060473F6, 3s-reloc: sf3 src/PASS03.c:1751 Passive03_0098 */
void Passive03_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 5:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047482, 3s-reloc: sf3 src/PASS03.c:1779 Passive03_0099 */
void Passive03_0099(PLW* wk) {
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



/* 2i 060474E4, 3s-reloc: sf3 src/PASS03.c:1801 Passive03_0100 */
void Passive03_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047534, 3s-reloc: sf3 src/PASS03.c:1820 Passive03_0101 */
void Passive03_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047578, 3s-reloc: sf3 src/PASS03.c:1836 Passive03_0102 */
void Passive03_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604760C, 3s-near: sf3 src/PASS03.c:1855 Passive03_0103 */
void Passive03_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
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



/* 2i 06047648, 3s-exact: sf3 src/PASS03.c:1874 Passive03_0104 */
void Passive03_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047668, 3s-reloc: sf3 src/PASS03.c:1887 Passive03_0105 */
void Passive03_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060476E8, 3s-near: sf3 src/PASS03.c:1909 Passive03_0106 */
void Passive03_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
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



/* 2i 06047724, 3s-exact: sf3 src/PASS03.c:1928 Passive03_0107 */
void Passive03_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047772, 3s-exact: sf3 src/PASS03.c:1944 Passive03_0108 */
void Passive03_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047792, 3s-reloc: sf3 src/PASS03.c:1957 Passive03_0109 */
void Passive03_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, -1, 0x30, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047804, 3s-exact: sf3 src/PASS03.c:1973 Passive03_0110 */
void Passive03_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 1:
        SA_Term(wk, 0x2E, 0x2F, -1, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047860, 3s-exact: sf3 src/PASS03.c:1992 Passive03_0111 */
void Passive03_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060478A4, 3s-reloc: sf3 src/PASS03.c:2008 Passive03_0112 */
void Passive03_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047926, 3s-reloc: sf3 src/PASS03.c:2027 Passive03_0113 */
void Passive03_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x20, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047974, 3s-reloc: sf3 src/PASS03.c:2043 Passive03_0114 */
void Passive03_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 1, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060479B6, 3s-near: sf3 src/PASS03.c:2056 Passive03_0115 */
void Passive03_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047A0C, 3s-reloc: sf3 src/PASS03.c:2075 Passive03_0116 */
void Passive03_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 0, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047A6E, 3s-exact: sf3 src/PASS03.c:2088 Passive03_0117 */
void Passive03_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x100, 1, -1, 0x20, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047AB0, 3s-exact: sf3 src/PASS03.c:2101 Passive03_0118 */
void Passive03_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x100, 0, -1, 0x20, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047AF2, 3s-exact: sf3 src/PASS03.c:2114 Passive03_0119 */
void Passive03_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047B12, 3s-exact: sf3 src/PASS03.c:2127 Passive03_0120 */
void Passive03_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047B32, 3s-reloc: sf3 src/PASS03.c:2140 Passive03_0121 */
void Passive03_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x7A, 0x7B, 0x7C, 0x7D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047B7E, 3s-exact: sf3 src/PASS03.c:2153 Passive03_0122 */
void Passive03_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047BB0, 3s-exact: sf3 src/PASS03.c:2166 Passive03_0123 */
void Passive03_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047BE2, 3s-exact: sf3 src/PASS03.c:2179 Passive03_0124 */
void Passive03_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047C14, 3s-exact: sf3 src/PASS03.c:2192 Passive03_0125 */
void Passive03_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xB, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047C46, 3s-exact: sf3 src/PASS03.c:2205 Passive03_0126 */
void Passive03_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047C64, 3s-reloc: sf3 src/PASS03.c:2218 Passive03_0127 */
void Passive03_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Normal_Attack(wk, 0xD, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047CA6, 3s-exact: sf3 src/PASS03.c:2234 Passive03_0128 */
void Passive03_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xB, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047CD8, 3s-exact: sf3 src/PASS03.c:2247 Passive03_0129 */
void Passive03_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xB, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047D0A, 3s-exact: sf3 src/PASS03.c:2260 Passive03_0130 */
void Passive03_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047D34, 3s-exact: sf3 src/PASS03.c:2276 Passive03_0131 */
void Passive03_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xB, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047D74, 3s-reloc: sf3 src/PASS03.c:2292 Passive03_0132 */
void Passive03_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 0xB, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047DD0, 3s-reloc: sf3 src/PASS03.c:2308 Passive03_0133 */
void Passive03_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xB, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047E10, 3s-reloc: sf3 src/PASS03.c:2324 Passive03_0134 */
void Passive03_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

