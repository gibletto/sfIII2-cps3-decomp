/*
 * PASS09.C  CPU passive patterns for character 9 (Oro)
 *
 * Passive09 is the CPU passive (defensive) routine for character 9, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive09_Tbl.
 * The 132 Passive09_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS09.h"



/* 2i 06057D78, 3s-exact: sf3 src/PASS09.c:21 Passive09 */
void Passive09(PLW* wk) {
    Passive09_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06057D90, 3s-exact: sf3 src/PASS09.c:27 Passive09_0000 */
void Passive09_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057DC4, 3s-exact: sf3 src/PASS09.c:40 Passive09_0001 */
void Passive09_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, 0x8050, 0x8028, 3, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1C, 6, 0x3C);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057E30, 3s-exact: sf3 src/PASS09.c:62 Passive09_0002 */
void Passive09_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80F0, -1, 5, 6, 0x2A);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057E7C, 3s-exact: sf3 src/PASS09.c:78 Passive09_0003 */
void Passive09_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_Store_Lever(wk, 0x1E, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057EBE, 3s-reloc: sf3 src/PASS09.c:94 Passive09_0004 */
void Passive09_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 6);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057F36, 3s-exact: sf3 src/PASS09.c:110 Passive09_0005 */
void Passive09_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_Store_Lever(wk, 0x1E, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057F78, 3s-exact: sf3 src/PASS09.c:126 Passive09_0006 */
void Passive09_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057F96, 3s-reloc: sf3 src/PASS09.c:139 Passive09_0007 */
void Passive09_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, 0x8050, 0x8028, 3, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1C, 6, 0x3C);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058028, 3s-exact: sf3 src/PASS09.c:161 Passive09_0008 */
void Passive09_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, 0x8050, 0x8028, 3, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1C, 6, 0x3C);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058094, 3s-exact: sf3 src/PASS09.c:183 Passive09_0009 */
void Passive09_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, 0x8050, 0x8028, 3, 1, -1);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1C, 6, 0x3C);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058100, 3s-exact: sf3 src/PASS09.c:205 Passive09_0010 */
void Passive09_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, 0x8040, 0, 6, 0x3C);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058146, 3s-exact: sf3 src/PASS09.c:221 Passive09_0011 */
void Passive09_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x20, 2, 0x8090, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605818A, 3s-reloc: sf3 src/PASS09.c:234 Passive09_0012 */
void Passive09_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8098, 0x8040, 3, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060581FE, 3s-exact: sf3 src/PASS09.c:250 Passive09_0013 */
void Passive09_0013(PLW* wk) {
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



/* 2i 06058240, 3s-exact: sf3 src/PASS09.c:266 Passive09_0014 */
void Passive09_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605825E, 3s-exact: sf3 src/PASS09.c:279 Passive09_0015 */
void Passive09_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6C);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060582A8, 3s-near: sf3 src/PASS09.c:301 Passive09_0016 */
void Passive09_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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



/* 2i 06058308, 3s-near: sf3 src/PASS09.c:320 Passive09_0017 */
void Passive09_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
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



/* 2i 06058340, 3s-near: sf3 src/PASS09.c:339 Passive09_0018 */
void Passive09_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1C);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060583A2, 3s-near: sf3 src/PASS09.c:361 Passive09_0019 */
void Passive09_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060583C2, 3s-near: sf3 src/PASS09.c:374 Passive09_0020 */
void Passive09_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058404, 3s-exact: sf3 src/PASS09.c:387 Passive09_0021 */
void Passive09_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2f, 9, -1, -1, 0x8040, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605844A, 3s-exact: sf3 src/PASS09.c:400 Passive09_0022 */
void Passive09_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, (0x100), 0, 0x8098, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605849C, 3s-reloc: sf3 src/PASS09.c:416 Passive09_0023 */
void Passive09_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8068, 0x8058, 8, 0x40, 0, 0x8088, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058518, 3s-exact: sf3 src/PASS09.c:432 Passive09_0024 */
void Passive09_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058566, 3s-exact: sf3 src/PASS09.c:451 Passive09_0025 */
void Passive09_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 2:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060585C4, 3s-reloc: sf3 src/PASS09.c:470 Passive09_0026 */
void Passive09_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058624, 3s-exact: sf3 src/PASS09.c:486 Passive09_0027 */
void Passive09_0027(PLW* wk) {
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



/* 2i 06058664, 3s-exact: sf3 src/PASS09.c:502 Passive09_0028 */
void Passive09_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058684, 3s-exact: sf3 src/PASS09.c:515 Passive09_0029 */
void Passive09_0029(PLW* wk) {
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



/* 2i 060586BC, 3s-exact: sf3 src/PASS09.c:534 Passive09_0030 */
void Passive09_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060586DC, 3s-exact: sf3 src/PASS09.c:547 Passive09_0031 */
void Passive09_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060586FE, 3s-near: sf3 src/PASS09.c:560 Passive09_0032 */
void Passive09_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605873C, 3s-near: sf3 src/PASS09.c:573 Passive09_0033 */
void Passive09_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605875E, 3s-near: sf3 src/PASS09.c:586 Passive09_0034 */
void Passive09_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6C);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605878C, 3s-near: sf3 src/PASS09.c:602 Passive09_0035 */
void Passive09_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060587AC, 3s-near: sf3 src/PASS09.c:615 Passive09_0036 */
void Passive09_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060587CA, 3s-near: sf3 src/PASS09.c:628 Passive09_0037 */
void Passive09_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058838, 3s-near: sf3 src/PASS09.c:644 Passive09_0038 */
void Passive09_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605887E, 3s-exact: sf3 src/PASS09.c:660 Passive09_0039 */
void Passive09_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060588D8, 3s-reloc: sf3 src/PASS09.c:679 Passive09_0040 */
void Passive09_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605896A, 3s-reloc: sf3 src/PASS09.c:701 Passive09_0041 */
void Passive09_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6D);
        break;
    case 1:
        Lever_On(wk, -1, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8010, 6, 6, 0x1F);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 4:
        Check_Store_Lever(wk, 0x1C, 1, -1);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060589F2, 3s-reloc: sf3 src/PASS09.c:729 Passive09_0042 */
void Passive09_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058A10, 3s-reloc: sf3 src/PASS09.c:742 Passive09_0043 */
void Passive09_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_On(wk, -1, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8050, 6, 6, 0x1F);
        break;
    case 3:
        Check_Store_Lever(wk, 0x1C, 1, -1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058A88, 3s-near: sf3 src/PASS09.c:767 Passive09_0044 */
void Passive09_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 3, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058ADC, 3s-near: sf3 src/PASS09.c:786 Passive09_0045 */
void Passive09_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 6, 0x1F);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058B28, 3s-near: sf3 src/PASS09.c:802 Passive09_0046 */
void Passive09_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, 0x8038, 0, 6, 0x3C);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058BAA, 3s-near: sf3 src/PASS09.c:818 Passive09_0047 */
void Passive09_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8038, 8, 0x200, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058BEE, 3s-near: sf3 src/PASS09.c:831 Passive09_0048 */
void Passive09_0048(PLW* wk) {
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



/* 2i 06058C18, 3s-near: sf3 src/PASS09.c:847 Passive09_0049 */
void Passive09_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6D);
        break;
    case 1:
        EM_Term(wk, 0x8050, -1, 3, 6, 0x1F);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058C9C, 3s-near: sf3 src/PASS09.c:866 Passive09_0050 */
void Passive09_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 3, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058CE0, 3s-near: sf3 src/PASS09.c:882 Passive09_0051 */
void Passive09_0051(PLW* wk) {
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



/* 2i 06058D04, 3s-reloc: sf3 src/PASS09.c:898 Passive09_0052 */
void Passive09_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058D24, 3s-reloc: sf3 src/PASS09.c:911 Passive09_0053 */
void Passive09_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x58, -1, 5, 6, 0x2A);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058D70, 3s-reloc: sf3 src/PASS09.c:927 Passive09_0054 */
void Passive09_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058DBE, 3s-reloc: sf3 src/PASS09.c:940 Passive09_0055 */
void Passive09_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 5, 6, 0x2A);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058E0A, 3s-near: sf3 src/PASS09.c:956 Passive09_0056 */
void Passive09_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8050, 0x8040, 8, (0x200), 0, 0x8098, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058E4E, 3s-near: sf3 src/PASS09.c:969 Passive09_0057 */
void Passive09_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8058, 8, 0x80, 0, 0x8088, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058E92, 3s-near: sf3 src/PASS09.c:982 Passive09_0058 */
void Passive09_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058EE6, 3s-near: sf3 src/PASS09.c:995 Passive09_0059 */
void Passive09_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, 0x8050, -1, 3, 6, 0x1F);
        break;
    case 2:
        Check_Store_Lever(wk, 0x1C, 1, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058F50, 3s-near: sf3 src/PASS09.c:1017 Passive09_0060 */
void Passive09_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058F6E, 3s-near: sf3 src/PASS09.c:1030 Passive09_0061 */
void Passive09_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06058F8E, 3s-near: sf3 src/PASS09.c:1043 Passive09_0062 */
void Passive09_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x100);
        break;
    case 1:
        ETC_Term(wk, 1, 6, 0x6E);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605900E, 3s-near: sf3 src/PASS09.c:1062 Passive09_0063 */
void Passive09_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x60, 0x61, 0x62, 0x63, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605905E, 3s-reloc: sf3 src/PASS09.c:1081 Passive09_0064 */
void Passive09_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        ETC_Term(wk, 1, 6, 0x6E);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060590A0, 3s-reloc: sf3 src/PASS09.c:1103 Passive09_0065 */
void Passive09_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x100);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059110, 3s-near: sf3 src/PASS09.c:1122 Passive09_0066 */
void Passive09_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, -1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059150, 3s-near: sf3 src/PASS09.c:1144 Passive09_0067 */
void Passive09_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059170, 3s-near: sf3 src/PASS09.c:1157 Passive09_0068 */
void Passive09_0068(PLW* wk) {
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



/* 2i 060591BC, 3s-near: sf3 src/PASS09.c:1176 Passive09_0069 */
void Passive09_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    case 2:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059226, 3s-near: sf3 src/PASS09.c:1198 Passive09_0070 */
void Passive09_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x60, 0x61, 0x62, 0x63, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059284, 3s-near: sf3 src/PASS09.c:1214 Passive09_0071 */
void Passive09_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x3A, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060592CC, 3s-near: sf3 src/PASS09.c:1230 Passive09_0072 */
void Passive09_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 1:
        EM_Term(wk, 0x8070, 0x8010, 3, 6, 0x1C);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605932A, 3s-near: sf3 src/PASS09.c:1249 Passive09_0073 */
void Passive09_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605939A, 3s-near: sf3 src/PASS09.c:1268 Passive09_0074 */
void Passive09_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x60, 0x61, 0x62, 0x63, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060593EA, 3s-near: sf3 src/PASS09.c:1281 Passive09_0075 */
void Passive09_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6C);
        break;
    case 1:
        Lever_On(wk, -1, 2);
        break;
    case 2:
        EM_Term(wk, 0x8040, -1, 3, 6, 0x1F);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605948C, 3s-reloc: sf3 src/PASS09.c:1306 Passive09_0076 */
void Passive09_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6E);
        break;
    case 1:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1C);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060594E2, 3s-reloc: sf3 src/PASS09.c:1325 Passive09_0077 */
void Passive09_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x40, 2);
        break;
    case 1:
        EM_Term(wk, 0x8048, 0x8010, 3, 6, 0x1C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x100));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605954C, 3s-reloc: sf3 src/PASS09.c:1347 Passive09_0078 */
void Passive09_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x200, 2, 0x8090, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060595C8, 3s-reloc: sf3 src/PASS09.c:1360 Passive09_0079 */
void Passive09_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060595E6, 3s-near: sf3 src/PASS09.c:1373 Passive09_0080 */
void Passive09_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 0xA009, (0x200), 0, 0x8050, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605964E, 3s-near: sf3 src/PASS09.c:1392 Passive09_0081 */
void Passive09_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8058, 9, 0x40, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060596E4, 3s-exact: sf3 src/PASS09.c:1411 Passive09_0082 */
void Passive09_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059752, 3s-exact: sf3 src/PASS09.c:1433 Passive09_0083 */
void Passive09_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059770, 3s-reloc: sf3 src/PASS09.c:1446 Passive09_0084 */
void Passive09_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 9, 0x80, 1, 0x8050, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060597E4, 3s-near: sf3 src/PASS09.c:1459 Passive09_0085 */
void Passive09_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059844, 3s-reloc: sf3 src/PASS09.c:1481 Passive09_0086 */
void Passive09_0086(PLW* wk) {
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



/* 2i 06059870, 3s-reloc: sf3 src/PASS09.c:1497 Passive09_0087 */
void Passive09_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8040, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060598F4, 3s-exact: sf3 src/PASS09.c:1513 Passive09_0088 */
void Passive09_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xA009, (0x100), 0, 0x8050, -1, (0x100));
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
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059992, 3s-reloc: sf3 src/PASS09.c:1541 Passive09_0089 */
void Passive09_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x20, 0x3B, 0x36, 0x5A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059A1C, 3s-exact: sf3 src/PASS09.c:1560 Passive09_0090 */
void Passive09_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059A4E, 3s-exact: sf3 src/PASS09.c:1573 Passive09_0091 */
void Passive09_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8010, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059ABE, 3s-exact: sf3 src/PASS09.c:1595 Passive09_0092 */
void Passive09_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x60, 0x61, 0x62, 99, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059AF8, 3s-reloc: sf3 src/PASS09.c:1608 Passive09_0093 */
void Passive09_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8058, 9, 0x40, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059B8C, 3s-near: sf3 src/PASS09.c:1630 Passive09_0094 */
void Passive09_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x36, -1, 0x36);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059BBE, 3s-near: sf3 src/PASS09.c:1643 Passive09_0095 */
void Passive09_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x36, -1, 0x37);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059BF0, 3s-near: sf3 src/PASS09.c:1656 Passive09_0096 */
void Passive09_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x36, -1, 0x38);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059C22, 3s-near: sf3 src/PASS09.c:1669 Passive09_0097 */
void Passive09_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x36, -1, 0x39);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059C7C, 3s-exact: sf3 src/PASS09.c:1682 Passive09_0098 */
void Passive09_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 5, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x100);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059CD6, 3s-exact: sf3 src/PASS09.c:1701 Passive09_0099 */
void Passive09_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 1, 6, 0x6D);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        Com_Random_Select(wk, 6, 5, 5, 100, 0x5A, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059D2E, 3s-reloc: sf3 src/PASS09.c:1720 Passive09_0100 */
void Passive09_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059D88, 3s-exact: sf3 src/PASS09.c:1733 Passive09_0101 */
void Passive09_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2f, 9, -1, -1, 0x8040, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059DCE, 3s-exact: sf3 src/PASS09.c:1746 Passive09_0102 */
void Passive09_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059E26, 3s-reloc: sf3 src/PASS09.c:1768 Passive09_0103 */
void Passive09_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059EA2, 3s-exact: sf3 src/PASS09.c:1790 Passive09_0104 */
void Passive09_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059EEE, 3s-exact: sf3 src/PASS09.c:1809 Passive09_0105 */
void Passive09_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059F3A, 3s-exact: sf3 src/PASS09.c:1828 Passive09_0106 */
void Passive09_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059F98, 3s-reloc: sf3 src/PASS09.c:1847 Passive09_0107 */
void Passive09_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8070, 6, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06059FFE, 3s-exact: sf3 src/PASS09.c:1863 Passive09_0108 */
void Passive09_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8038, 0x8008, 5, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A044, 3s-exact: sf3 src/PASS09.c:1879 Passive09_0109 */
void Passive09_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, 0x8008, 5, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A08A, 3s-exact: sf3 src/PASS09.c:1895 Passive09_0110 */
void Passive09_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, 0x8008, 5, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A0D0, 3s-reloc: sf3 src/PASS09.c:1911 Passive09_0111 */
void Passive09_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

