/*
 * pass10.c  Computer AI passive patterns for character 10 (Yang)
 *
 * Passive10 is the passive-mode entry for character number 10, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive10_Tbl; this file holds the 138 patterns
 * Passive10_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass10.h"



/* 2i 0605A114, 3s-exact: sf3 src/pass10.c:21 Passive10 */
void Passive10(PLW* wk) {
    Passive10_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0605A12C, 3s-exact: sf3 src/pass10.c:27 Passive10_0000 */
void Passive10_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A160, 3s-exact: sf3 src/pass10.c:40 Passive10_0001 */
void Passive10_0001(PLW* wk) {
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



/* 2i 0605A188, 3s-exact: sf3 src/pass10.c:56 Passive10_0002 */
void Passive10_0002(PLW* wk) {
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
        EM_Term(wk, 0x7fff, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A1F2, 3s-near: sf3 src/pass10.c:78 Passive10_0003 */
void Passive10_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A248, 3s-exact: sf3 src/pass10.c:91 Passive10_0004 */
void Passive10_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x53);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xb, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A28A, 3s-exact: sf3 src/pass10.c:107 Passive10_0005 */
void Passive10_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A2A8, 3s-exact: sf3 src/pass10.c:120 Passive10_0006 */
void Passive10_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7f, 2);
        break;
    case 1:
        EM_Term(wk, 0x7fff, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A2EC, 3s-near: sf3 src/pass10.c:136 Passive10_0007 */
void Passive10_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A34C, 3s-near: sf3 src/pass10.c:152 Passive10_0008 */
void Passive10_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xc, 0, 0xb, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A39E, 3s-exact: sf3 src/pass10.c:171 Passive10_0009 */
void Passive10_0009(PLW* wk) {
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



/* 2i 0605A3EC, 3s-exact: sf3 src/pass10.c:187 Passive10_0010 */
void Passive10_0010(PLW* wk) {
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



/* 2i 0605A43C, 3s-exact: sf3 src/pass10.c:203 Passive10_0011 */
void Passive10_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A47E, 3s-exact: sf3 src/pass10.c:216 Passive10_0012 */
void Passive10_0012(PLW* wk) {
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



/* 2i 0605A4C8, 3s-reloc: sf3 src/pass10.c:232 Passive10_0013 */
void Passive10_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        SA_Term(wk, 0x2e, 0x2f, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 0xb, 0x10);
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



/* 2i 0605A5A6, 3s-exact: sf3 src/pass10.c:263 Passive10_0014 */
void Passive10_0014(PLW* wk) {
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



/* 2i 0605A5EA, 3s-exact: sf3 src/pass10.c:279 Passive10_0015 */
void Passive10_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A60A, 3s-near: sf3 src/pass10.c:292 Passive10_0016 */
void Passive10_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A6A8, 3s-near: sf3 src/pass10.c:320 Passive10_0017 */
void Passive10_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6c);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x89, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 0xb, (0x80));
        break;
    case 5:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 6:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 7:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A742, 3s-reloc: sf3 src/pass10.c:354 Passive10_0018 */
void Passive10_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A7D2, 3s-near: sf3 src/pass10.c:379 Passive10_0019 */
void Passive10_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A7F2, 3s-exact: sf3 src/pass10.c:392 Passive10_0020 */
void Passive10_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A812, 3s-exact: sf3 src/pass10.c:405 Passive10_0021 */
void Passive10_0021(PLW* wk) {
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



/* 2i 0605A852, 3s-near: sf3 src/pass10.c:421 Passive10_0022 */
void Passive10_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0xb, (0x80), 0, 0x8060, -1, 0x40);
        break;
    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A8E8, 3s-near: sf3 src/pass10.c:446 Passive10_0023 */
void Passive10_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, -1, 0xb, (0x8080), 0, 0x8060, -1, 0x40);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A962, 3s-reloc: sf3 src/pass10.c:468 Passive10_0024 */
void Passive10_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6c);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x89, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605A9DC, 3s-exact: sf3 src/pass10.c:493 Passive10_0025 */
void Passive10_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Keep_Away(wk, 0x89, 0);
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



/* 2i 0605AA44, 3s-exact: sf3 src/pass10.c:518 Passive10_0026 */
void Passive10_0026(PLW* wk) {
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



/* 2i 0605AA88, 3s-reloc: sf3 src/pass10.c:534 Passive10_0027 */
void Passive10_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AAE8, 3s-exact: sf3 src/pass10.c:547 Passive10_0028 */
void Passive10_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AB2A, 3s-exact: sf3 src/pass10.c:560 Passive10_0029 */
void Passive10_0029(PLW* wk) {
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



/* 2i 0605AB62, 3s-exact: sf3 src/pass10.c:579 Passive10_0030 */
void Passive10_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605ABA6, 3s-reloc: sf3 src/pass10.c:595 Passive10_0031 */
void Passive10_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605ABF0, 3s-near: sf3 src/pass10.c:608 Passive10_0032 */
void Passive10_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, -1, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xb, 0x22);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AC50, 3s-near: sf3 src/pass10.c:630 Passive10_0033 */
void Passive10_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AC72, 3s-near: sf3 src/pass10.c:643 Passive10_0034 */
void Passive10_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xc, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605ACB2, 3s-near: sf3 src/pass10.c:659 Passive10_0035 */
void Passive10_0035(PLW* wk) {
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



/* 2i 0605AD16, 3s-reloc: sf3 src/pass10.c:678 Passive10_0036 */
void Passive10_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AD60, 3s-near: sf3 src/pass10.c:697 Passive10_0037 */
void Passive10_0037(PLW* wk) {
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



/* 2i 0605ADA6, 3s-near: sf3 src/pass10.c:713 Passive10_0038 */
void Passive10_0038(PLW* wk) {
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



/* 2i 0605AE16, 3s-exact: sf3 src/pass10.c:729 Passive10_0039 */
void Passive10_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 2, 0x42);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5a, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AE5C, 3s-exact: sf3 src/pass10.c:745 Passive10_0040 */
void Passive10_0040(PLW* wk) {
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



/* 2i 0605AEBE, 3s-near: sf3 src/pass10.c:767 Passive10_0041 */
void Passive10_0041(PLW* wk) {
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



/* 2i 0605AF3E, 3s-exact: sf3 src/pass10.c:786 Passive10_0042 */
void Passive10_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AF80, 3s-near: sf3 src/pass10.c:799 Passive10_0043 */
void Passive10_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605AFCE, 3s-exact: sf3 src/pass10.c:815 Passive10_0044 */
void Passive10_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B02C, 3s-exact: sf3 src/pass10.c:834 Passive10_0045 */
void Passive10_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8020, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B07A, 3s-exact: sf3 src/pass10.c:850 Passive10_0046 */
void Passive10_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B09A, 3s-near: sf3 src/pass10.c:863 Passive10_0047 */
void Passive10_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, (0x82));
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B116, 3s-reloc: sf3 src/pass10.c:879 Passive10_0048 */
void Passive10_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B140, 3s-reloc: sf3 src/pass10.c:895 Passive10_0049 */
void Passive10_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B160, 3s-reloc: sf3 src/pass10.c:908 Passive10_0050 */
void Passive10_0050(PLW* wk) {
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



/* 2i 0605B188, 3s-near: sf3 src/pass10.c:924 Passive10_0051 */
void Passive10_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B1BA, 3s-near: sf3 src/pass10.c:937 Passive10_0052 */
void Passive10_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B1F8, 3s-exact: sf3 src/pass10.c:950 Passive10_0053 */
void Passive10_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B23A, 3s-exact: sf3 src/pass10.c:963 Passive10_0054 */
void Passive10_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 2, 0x8060, -1, (0x8200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B27C, 3s-near: sf3 src/pass10.c:976 Passive10_0055 */
void Passive10_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B2AE, 3s-exact: sf3 src/pass10.c:989 Passive10_0056 */
void Passive10_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B2F0, 3s-exact: sf3 src/pass10.c:1002 Passive10_0057 */
void Passive10_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x20, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B332, 3s-exact: sf3 src/pass10.c:1015 Passive10_0058 */
void Passive10_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B352, 3s-exact: sf3 src/pass10.c:1028 Passive10_0059 */
void Passive10_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B37E, 3s-exact: sf3 src/pass10.c:1044 Passive10_0060 */
void Passive10_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B39C, 3s-reloc: sf3 src/pass10.c:1057 Passive10_0061 */
void Passive10_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0x30, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B40E, 3s-near: sf3 src/pass10.c:1073 Passive10_0062 */
void Passive10_0062(PLW* wk) {
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



/* 2i 0605B43C, 3s-near: sf3 src/pass10.c:1089 Passive10_0063 */
void Passive10_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xc, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B47C, 3s-near: sf3 src/pass10.c:1105 Passive10_0064 */
void Passive10_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B49E, 3s-near: sf3 src/pass10.c:1118 Passive10_0065 */
void Passive10_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xc, (0x80));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B50C, 3s-exact: sf3 src/pass10.c:1137 Passive10_0066 */
void Passive10_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x40);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5a, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B552, 3s-near: sf3 src/pass10.c:1153 Passive10_0067 */
void Passive10_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B584, 3s-exact: sf3 src/pass10.c:1166 Passive10_0068 */
void Passive10_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B5C6, 3s-exact: sf3 src/pass10.c:1179 Passive10_0069 */
void Passive10_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xc, 0, 0xb, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B610, 3s-exact: sf3 src/pass10.c:1195 Passive10_0070 */
void Passive10_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xb, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B662, 3s-exact: sf3 src/pass10.c:1214 Passive10_0071 */
void Passive10_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1c, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B6B8, 3s-near: sf3 src/pass10.c:1233 Passive10_0072 */
void Passive10_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xc, 0, 0xb, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B734, 3s-near: sf3 src/pass10.c:1252 Passive10_0073 */
void Passive10_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 0xb, (0x8200), 0, 0x8060, -1, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B79E, 3s-reloc: sf3 src/pass10.c:1271 Passive10_0074 */
void Passive10_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0x30, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B840, 3s-exact: sf3 src/pass10.c:1296 Passive10_0075 */
void Passive10_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, -1, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 2:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B8DC, 3s-reloc: sf3 src/pass10.c:1327 Passive10_0076 */
void Passive10_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2f, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 0, 0x8060, -1, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B9A6, 3s-exact: sf3 src/pass10.c:1358 Passive10_0077 */
void Passive10_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0xb, 0x20, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605B9F6, 3s-near: sf3 src/pass10.c:1374 Passive10_0078 */
void Passive10_0078(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BA9C, 3s-exact: sf3 src/pass10.c:1396 Passive10_0079 */
void Passive10_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0xb, 0x20, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BAF0, 3s-exact: sf3 src/pass10.c:1412 Passive10_0080 */
void Passive10_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 0xb, 0x40, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BB40, 3s-reloc: sf3 src/pass10.c:1428 Passive10_0081 */
void Passive10_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 0xb, (0x8100), 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BBC4, 3s-exact: sf3 src/pass10.c:1447 Passive10_0082 */
void Passive10_0082(PLW* wk) {
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



/* 2i 0605BC18, 3s-near: sf3 src/pass10.c:1463 Passive10_0083 */
void Passive10_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8040, 0xb, 0x40, 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BCC0, 3s-exact: sf3 src/pass10.c:1488 Passive10_0084 */
void Passive10_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BD48, 3s-exact: sf3 src/pass10.c:1513 Passive10_0085 */
void Passive10_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xa);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BD86, 3s-exact: sf3 src/pass10.c:1529 Passive10_0086 */
void Passive10_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x2e, 0x2f, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 0xb, 0x12);
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



/* 2i 0605BE14, 3s-reloc: sf3 src/pass10.c:1557 Passive10_0087 */
void Passive10_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BEEA, 3s-exact: sf3 src/pass10.c:1588 Passive10_0088 */
void Passive10_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x30, 0);
        break;
    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BF7C, 3s-near: sf3 src/pass10.c:1616 Passive10_0089 */
void Passive10_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BFAE, 3s-near: sf3 src/pass10.c:1629 Passive10_0090 */
void Passive10_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605BFE0, 3s-near: sf3 src/pass10.c:1642 Passive10_0091 */
void Passive10_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C012, 3s-exact: sf3 src/pass10.c:1655 Passive10_0092 */
void Passive10_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8020, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C060, 3s-reloc: sf3 src/pass10.c:1671 Passive10_0093 */
void Passive10_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C0AE, 3s-exact: sf3 src/pass10.c:1687 Passive10_0094 */
void Passive10_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C0E4, 3s-exact: sf3 src/pass10.c:1700 Passive10_0095 */
void Passive10_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C128, 3s-exact: sf3 src/pass10.c:1716 Passive10_0096 */
void Passive10_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C16C, 3s-near: sf3 src/pass10.c:1732 Passive10_0097 */
void Passive10_0097(PLW* wk) {
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



/* 2i 0605C1E6, 3s-near: sf3 src/pass10.c:1751 Passive10_0098 */
void Passive10_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C272, 3s-reloc: sf3 src/pass10.c:1779 Passive10_0099 */
void Passive10_0099(PLW* wk) {
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



/* 2i 0605C2D4, 3s-near: sf3 src/pass10.c:1801 Passive10_0100 */
void Passive10_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C324, 3s-reloc: sf3 src/pass10.c:1820 Passive10_0101 */
void Passive10_0101(PLW* wk) {
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



/* 2i 0605C368, 3s-near: sf3 src/pass10.c:1836 Passive10_0102 */
void Passive10_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C400, 3s-near: sf3 src/pass10.c:1855 Passive10_0103 */
void Passive10_0103(PLW* wk) {
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



/* 2i 0605C43C, 3s-exact: sf3 src/pass10.c:1874 Passive10_0104 */
void Passive10_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0xa, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C45C, 3s-reloc: sf3 src/pass10.c:1887 Passive10_0105 */
void Passive10_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xa, -1);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C4DC, 3s-near: sf3 src/pass10.c:1909 Passive10_0106 */
void Passive10_0106(PLW* wk) {
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



/* 2i 0605C518, 3s-exact: sf3 src/pass10.c:1928 Passive10_0107 */
void Passive10_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C566, 3s-exact: sf3 src/pass10.c:1944 Passive10_0108 */
void Passive10_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C586, 3s-reloc: sf3 src/pass10.c:1957 Passive10_0109 */
void Passive10_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, -1, 0x30, 0);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C5F8, 3s-exact: sf3 src/pass10.c:1973 Passive10_0110 */
void Passive10_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xc, 0x20);
        break;
    case 1:
        SA_Term(wk, 0x2e, 0x2f, -1, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C654, 3s-exact: sf3 src/pass10.c:1992 Passive10_0111 */
void Passive10_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C698, 3s-near: sf3 src/pass10.c:2008 Passive10_0112 */
void Passive10_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C71A, 3s-near: sf3 src/pass10.c:2027 Passive10_0113 */
void Passive10_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x20, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C768, 3s-reloc: sf3 src/pass10.c:2043 Passive10_0114 */
void Passive10_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, (0x200), 1, -1, 0x20, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C7AA, 3s-near: sf3 src/pass10.c:2056 Passive10_0115 */
void Passive10_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xb, (0x82));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C800, 3s-reloc: sf3 src/pass10.c:2075 Passive10_0116 */
void Passive10_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, (0x200), 0, -1, 0x20, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C862, 3s-exact: sf3 src/pass10.c:2088 Passive10_0117 */
void Passive10_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, (0x100), 1, -1, 0x20, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C8A4, 3s-exact: sf3 src/pass10.c:2101 Passive10_0118 */
void Passive10_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, (0x100), 0, -1, 0x20, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C8E6, 3s-exact: sf3 src/pass10.c:2114 Passive10_0119 */
void Passive10_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C906, 3s-near: sf3 src/pass10.c:2127 Passive10_0120 */
void Passive10_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C976, 3s-near: sf3 src/pass10.c:2146 Passive10_0121 */
void Passive10_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 3:
        Wait(wk, 0xe);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605C9E4, 3s-near: sf3 src/pass10.c:2171 Passive10_0122 */
void Passive10_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xE, 0x1F, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CA4C, 3s-exact: sf3 src/pass10.c:2193 Passive10_0123 */
void Passive10_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CA6A, 3s-reloc: sf3 src/pass10.c:2206 Passive10_0124 */
void Passive10_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xd, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CAA2, 3s-near: sf3 src/pass10.c:2219 Passive10_0125 */
void Passive10_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 3:
        Wait(wk, 0xe);
        break;
    case 4:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CB04, 3s-near: sf3 src/pass10.c:2244 Passive10_0126 */
void Passive10_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CB56, 3s-near: sf3 src/pass10.c:2266 Passive10_0127 */
void Passive10_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xB, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CBA8, 3s-near: sf3 src/pass10.c:2279 Passive10_0128 */
void Passive10_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 2:
        Wait(wk, 0xe);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 4:
        Wait(wk, 0xe);
        break;
    case 5:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 6:
        Wait(wk, 0xe);
        break;
    case 7:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 8:
        Wait(wk, 0xe);
        break;
    case 9:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CC48, 3s-near: sf3 src/pass10.c:2319 Passive10_0129 */
void Passive10_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 2:
        Wait(wk, 0xe);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    case 4:
        Wait(wk, 0xe);
        break;
    case 5:
        Command_Attack(wk, 0xe, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CCBA, 3s-reloc: sf3 src/pass10.c:2347 Passive10_0130 */
void Passive10_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x2f, 0x30, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, 0x8060, -1, 8, (0x8200), 0, 0x8060, -1, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 0xb, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CD8A, 3s-near: sf3 src/pass10.c:2378 Passive10_0131 */
void Passive10_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xB, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CE08, 3s-near: sf3 src/pass10.c:2397 Passive10_0132 */
void Passive10_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 2:
        Wait(wk, 0xe);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 4:
        Wait(wk, 0xe);
        break;
    case 5:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 6:
        Wait(wk, 0xe);
        break;
    case 7:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 8:
        Wait(wk, 0xe);
        break;
    case 9:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CEA8, 3s-reloc: sf3 src/pass10.c:2437 Passive10_0133 */
void Passive10_0133(PLW* wk) {
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



/* 2i 0605CEE8, 3s-near: sf3 src/pass10.c:2453 Passive10_0134 */
void Passive10_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 2:
        Wait(wk, 0xe);
        break;
    case 3:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 4:
        Wait(wk, 0xe);
        break;
    case 5:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 6:
        Wait(wk, 0xe);
        break;
    case 7:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    case 8:
        Wait(wk, 0xe);
        break;
    case 9:
        Command_Attack(wk, 0xe, 0x1F, 0xb, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605CF88, 3s-reloc: sf3 src/pass10.c:2493 Passive10_0135 */
void Passive10_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

