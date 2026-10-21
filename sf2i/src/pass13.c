/*
 * pass13.c  Computer AI passive patterns for character 13 (Urien)
 *
 * Passive13 is the passive-mode entry for character number 13, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive13_Tbl; this file holds the 164 patterns
 * Passive13_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass13.h"



/* 2i 06066EE4, 3s-exact: sf3 src/pass13.c:21 Passive13 */
void Passive13(PLW* wk) {
    Passive13_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06066EFC, 3s-exact: sf3 src/pass13.c:27 Passive13_0000 */
void Passive13_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06066F30, 3s-exact: sf3 src/pass13.c:40 Passive13_0001 */
void Passive13_0001(PLW* wk) {
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



/* 2i 06066F58, 3s-exact: sf3 src/pass13.c:56 Passive13_0002 */
void Passive13_0002(PLW* wk) {
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



/* 2i 06066FC2, 3s-reloc: sf3 src/pass13.c:78 Passive13_0003 */
void Passive13_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067018, 3s-exact: sf3 src/pass13.c:91 Passive13_0004 */
void Passive13_0004(PLW* wk) {
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



/* 2i 0606705A, 3s-exact: sf3 src/pass13.c:107 Passive13_0005 */
void Passive13_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067078, 3s-exact: sf3 src/pass13.c:120 Passive13_0006 */
void Passive13_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060670BC, 3s-exact: sf3 src/pass13.c:136 Passive13_0007 */
void Passive13_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060670EE, 3s-reloc: sf3 src/pass13.c:149 Passive13_0008 */
void Passive13_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 1, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 8, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606715E, 3s-exact: sf3 src/pass13.c:168 Passive13_0009 */
void Passive13_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x38, 7, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060671BC, 3s-exact: sf3 src/pass13.c:187 Passive13_0010 */
void Passive13_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060671EE, 3s-reloc: sf3 src/pass13.c:200 Passive13_0011 */
void Passive13_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067244, 3s-exact: sf3 src/pass13.c:213 Passive13_0012 */
void Passive13_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0, 0, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606728E, 3s-exact: sf3 src/pass13.c:229 Passive13_0013 */
void Passive13_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x22);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060672D8, 3s-exact: sf3 src/pass13.c:248 Passive13_0014 */
void Passive13_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060672F8, 3s-reloc: sf3 src/pass13.c:261 Passive13_0015 */
void Passive13_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067338, 3s-exact: sf3 src/pass13.c:274 Passive13_0016 */
void Passive13_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606737C, 3s-exact: sf3 src/pass13.c:296 Passive13_0017 */
void Passive13_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060673E2, 3s-reloc: sf3 src/pass13.c:321 Passive13_0018 */
void Passive13_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067442, 3s-near: sf3 src/pass13.c:343 Passive13_0019 */
void Passive13_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067462, 3s-exact: sf3 src/pass13.c:356 Passive13_0020 */
void Passive13_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067482, 3s-exact: sf3 src/pass13.c:369 Passive13_0021 */
void Passive13_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060674C2, 3s-reloc: sf3 src/pass13.c:385 Passive13_0022 */
void Passive13_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA00B, 0x40, 0, 0x8070, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067552, 3s-exact: sf3 src/pass13.c:407 Passive13_0023 */
void Passive13_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA00B, (0x200), 0, 0x8070, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060675BA, 3s-exact: sf3 src/pass13.c:429 Passive13_0024 */
void Passive13_0024(PLW* wk) {
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



/* 2i 060675E6, 3s-near: sf3 src/pass13.c:445 Passive13_0025 */
void Passive13_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
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



/* 2i 0606766C, 3s-reloc: sf3 src/pass13.c:467 Passive13_0026 */
void Passive13_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606768C, 3s-reloc: sf3 src/pass13.c:480 Passive13_0027 */
void Passive13_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060676BE, 3s-near: sf3 src/pass13.c:493 Passive13_0028 */
void Passive13_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060676F0, 3s-near: sf3 src/pass13.c:506 Passive13_0029 */
void Passive13_0029(PLW* wk) {
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



/* 2i 06067728, 3s-near: sf3 src/pass13.c:525 Passive13_0030 */
void Passive13_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606776E, 3s-reloc: sf3 src/pass13.c:541 Passive13_0031 */
void Passive13_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067790, 3s-near: sf3 src/pass13.c:554 Passive13_0032 */
void Passive13_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060677E2, 3s-near: sf3 src/pass13.c:570 Passive13_0033 */
void Passive13_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067810, 3s-near: sf3 src/pass13.c:586 Passive13_0034 */
void Passive13_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067830, 3s-reloc: sf3 src/pass13.c:599 Passive13_0035 */
void Passive13_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
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



/* 2i 06067876, 3s-near: sf3 src/pass13.c:618 Passive13_0036 */
void Passive13_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Next_Another_Menu(wk, 6, 0x8B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060678F4, 3s-near: sf3 src/pass13.c:640 Passive13_0037 */
void Passive13_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8002, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067948, 3s-near: sf3 src/pass13.c:659 Passive13_0038 */
void Passive13_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8002, 6, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606798E, 3s-near: sf3 src/pass13.c:675 Passive13_0039 */
void Passive13_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067A0E, 3s-near: sf3 src/pass13.c:694 Passive13_0040 */
void Passive13_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, 0x8080, 0x8050, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067A74, 3s-near: sf3 src/pass13.c:719 Passive13_0041 */
void Passive13_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x80));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067AF0, 3s-near: sf3 src/pass13.c:738 Passive13_0042 */
void Passive13_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA008, 0x40, 0, 0x8070, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067B32, 3s-near: sf3 src/pass13.c:751 Passive13_0043 */
void Passive13_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8050, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067B78, 3s-near: sf3 src/pass13.c:767 Passive13_0044 */
void Passive13_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067BC6, 3s-near: sf3 src/pass13.c:783 Passive13_0045 */
void Passive13_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8070, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067C3E, 3s-reloc: sf3 src/pass13.c:799 Passive13_0046 */
void Passive13_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067C5E, 3s-near: sf3 src/pass13.c:812 Passive13_0047 */
void Passive13_0047(PLW* wk) {
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



/* 2i 06067C88, 3s-near: sf3 src/pass13.c:828 Passive13_0048 */
void Passive13_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8040, 6, 1, -1);
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



/* 2i 06067CD2, 3s-near: sf3 src/pass13.c:847 Passive13_0049 */
void Passive13_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067D1C, 3s-reloc: sf3 src/pass13.c:860 Passive13_0050 */
void Passive13_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067D48, 3s-reloc: sf3 src/pass13.c:876 Passive13_0051 */
void Passive13_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
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



/* 2i 06067D92, 3s-near: sf3 src/pass13.c:895 Passive13_0052 */
void Passive13_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067DB2, 3s-near: sf3 src/pass13.c:908 Passive13_0053 */
void Passive13_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067DE4, 3s-near: sf3 src/pass13.c:921 Passive13_0054 */
void Passive13_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067E3E, 3s-reloc: sf3 src/pass13.c:937 Passive13_0055 */
void Passive13_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0x1F, 8, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067E8C, 3s-reloc: sf3 src/pass13.c:956 Passive13_0056 */
void Passive13_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA008, 0x40, 0, 0x8070, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067ECE, 3s-reloc: sf3 src/pass13.c:969 Passive13_0057 */
void Passive13_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA008, 0x40, 0, 0x8070, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067F10, 3s-near: sf3 src/pass13.c:982 Passive13_0058 */
void Passive13_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067F5A, 3s-near: sf3 src/pass13.c:995 Passive13_0059 */
void Passive13_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x34);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067F88, 3s-near: sf3 src/pass13.c:1011 Passive13_0060 */
void Passive13_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067FA6, 3s-near: sf3 src/pass13.c:1024 Passive13_0061 */
void Passive13_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067FD8, 3s-near: sf3 src/pass13.c:1037 Passive13_0062 */
void Passive13_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06067FFA, 3s-near: sf3 src/pass13.c:1053 Passive13_0063 */
void Passive13_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606802C, 3s-near: sf3 src/pass13.c:1066 Passive13_0064 */
void Passive13_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068074, 3s-near: sf3 src/pass13.c:1079 Passive13_0065 */
void Passive13_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060680A2, 3s-near: sf3 src/pass13.c:1095 Passive13_0066 */
void Passive13_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 6, 6);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060680E4, 3s-near: sf3 src/pass13.c:1111 Passive13_0067 */
void Passive13_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068116, 3s-near: sf3 src/pass13.c:1124 Passive13_0068 */
void Passive13_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5A, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068154, 3s-near: sf3 src/pass13.c:1137 Passive13_0069 */
void Passive13_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060681A6, 3s-near: sf3 src/pass13.c:1156 Passive13_0070 */
void Passive13_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060681F8, 3s-near: sf3 src/pass13.c:1172 Passive13_0071 */
void Passive13_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068250, 3s-near: sf3 src/pass13.c:1194 Passive13_0072 */
void Passive13_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606829A, 3s-near: sf3 src/pass13.c:1213 Passive13_0073 */
void Passive13_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xA008, (0x200), 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606831A, 3s-exact: sf3 src/pass13.c:1232 Passive13_0074 */
void Passive13_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068360, 3s-reloc: sf3 src/pass13.c:1251 Passive13_0075 */
void Passive13_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060683CC, 3s-exact: sf3 src/pass13.c:1270 Passive13_0076 */
void Passive13_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB1, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA008, (0x200), 0, 0x8070, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068450, 3s-reloc: sf3 src/pass13.c:1295 Passive13_0077 */
void Passive13_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA00B, 0x40, 0, 0x8070, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060684D0, 3s-exact: sf3 src/pass13.c:1311 Passive13_0078 */
void Passive13_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA00B, (0x200), 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606853C, 3s-exact: sf3 src/pass13.c:1333 Passive13_0079 */
void Passive13_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA00B, 0x40, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606858E, 3s-reloc: sf3 src/pass13.c:1349 Passive13_0080 */
void Passive13_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8050, 0xA00B, 0x40, 0, 0x8070, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606860A, 3s-exact: sf3 src/pass13.c:1368 Passive13_0081 */
void Passive13_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xA00B, (0x200), 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068664, 3s-reloc: sf3 src/pass13.c:1387 Passive13_0082 */
void Passive13_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xA00B, 0x40, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060686DC, 3s-exact: sf3 src/pass13.c:1403 Passive13_0083 */
void Passive13_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xA00B, 0x200, 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068750, 3s-reloc: sf3 src/pass13.c:1425 Passive13_0084 */
void Passive13_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xA00B, (0x200), 0, 0x8070, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060687EC, 3s-exact: sf3 src/pass13.c:1447 Passive13_0085 */
void Passive13_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 8);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606882A, 3s-exact: sf3 src/pass13.c:1463 Passive13_0086 */
void Passive13_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060688A2, 3s-exact: sf3 src/pass13.c:1488 Passive13_0087 */
void Passive13_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 0xB, 0x1F, 9, -1);
        break;
    case 4:
        ETC_Term(wk, 2, 6, 1);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068932, 3s-reloc: sf3 src/pass13.c:1516 Passive13_0088 */
void Passive13_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xB1, 2);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x8040, 0xA00B, (0x200), 0, 0x8070, -1, (0x100));
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 9, -1);
        break;
    case 5:
        ETC_Term(wk, 2, 6, 1);
        break;
    case 6:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068A08, 3s-exact: sf3 src/pass13.c:1547 Passive13_0089 */
void Passive13_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068A3A, 3s-exact: sf3 src/pass13.c:1560 Passive13_0090 */
void Passive13_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068A6C, 3s-reloc: sf3 src/pass13.c:1573 Passive13_0091 */
void Passive13_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068AD0, 3s-exact: sf3 src/pass13.c:1586 Passive13_0092 */
void Passive13_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068B1E, 3s-exact: sf3 src/pass13.c:1602 Passive13_0093 */
void Passive13_0093(PLW* wk) {
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



/* 2i 06068B42, 3s-exact: sf3 src/pass13.c:1618 Passive13_0094 */
void Passive13_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068B7C, 3s-reloc: sf3 src/pass13.c:1631 Passive13_0095 */
void Passive13_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5A, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068BF0, 3s-exact: sf3 src/pass13.c:1647 Passive13_0096 */
void Passive13_0096(PLW* wk) {
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



/* 2i 06068C34, 3s-near: sf3 src/pass13.c:1663 Passive13_0097 */
void Passive13_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8002, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068C88, 3s-reloc: sf3 src/pass13.c:1682 Passive13_0098 */
void Passive13_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068D26, 3s-exact: sf3 src/pass13.c:1707 Passive13_0099 */
void Passive13_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068D70, 3s-exact: sf3 src/pass13.c:1726 Passive13_0100 */
void Passive13_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068DB0, 3s-exact: sf3 src/pass13.c:1742 Passive13_0101 */
void Passive13_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068DF8, 3s-exact: sf3 src/pass13.c:1758 Passive13_0102 */
void Passive13_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5A, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068E46, 3s-near: sf3 src/pass13.c:1774 Passive13_0103 */
void Passive13_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
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



/* 2i 06068E82, 3s-exact: sf3 src/pass13.c:1793 Passive13_0104 */
void Passive13_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0xD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068EA2, 3s-reloc: sf3 src/pass13.c:1806 Passive13_0105 */
void Passive13_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
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



/* 2i 06068F28, 3s-near: sf3 src/pass13.c:1828 Passive13_0106 */
void Passive13_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
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



/* 2i 06068F64, 3s-exact: sf3 src/pass13.c:1847 Passive13_0107 */
void Passive13_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068FBA, 3s-exact: sf3 src/pass13.c:1869 Passive13_0108 */
void Passive13_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBB, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06068FDA, 3s-reloc: sf3 src/pass13.c:1882 Passive13_0109 */
void Passive13_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8070, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 0xB, 0x1F, 9, 0x70);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069070, 3s-exact: sf3 src/pass13.c:1904 Passive13_0110 */
void Passive13_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060690CE, 3s-exact: sf3 src/pass13.c:1923 Passive13_0111 */
void Passive13_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069120, 3s-exact: sf3 src/pass13.c:1942 Passive13_0112 */
void Passive13_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606918A, 3s-reloc: sf3 src/pass13.c:1964 Passive13_0113 */
void Passive13_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8058, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 0xB, 0x1F, 9, -1);
        break;
    case 4:
        Lever_On(wk, 1, 2);
        break;
    case 5:
        Wait(wk, 5);
        break;
    case 6:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069264, 3s-exact: sf3 src/pass13.c:1995 Passive13_0114 */
void Passive13_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x30, 7, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 0xB, 0x1F, 9, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060692CE, 3s-exact: sf3 src/pass13.c:2017 Passive13_0115 */
void Passive13_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 0xB, 0x1F, 9, -1);
        break;
    case 4:
        ETC_Term(wk, 2, 6, 1);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606935A, 3s-reloc: sf3 src/pass13.c:2045 Passive13_0116 */
void Passive13_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 0xA008, (0x200), 1, -1, 0x10, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060693BE, 3s-exact: sf3 src/pass13.c:2058 Passive13_0117 */
void Passive13_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 0xA008, (0x100), 1, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069400, 3s-exact: sf3 src/pass13.c:2071 Passive13_0118 */
void Passive13_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 0xA008, 0x20, 1, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069442, 3s-exact: sf3 src/pass13.c:2084 Passive13_0119 */
void Passive13_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 0xA008, (0x200), 0, -1, 0x10, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069484, 3s-reloc: sf3 src/pass13.c:2097 Passive13_0120 */
void Passive13_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 0xA008, (0x100), 0, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060694DA, 3s-exact: sf3 src/pass13.c:2110 Passive13_0121 */
void Passive13_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 0xA008, 0x20, 0, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606951C, 3s-exact: sf3 src/pass13.c:2123 Passive13_0122 */
void Passive13_0122(PLW* wk) {
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



/* 2i 06069560, 3s-reloc: sf3 src/pass13.c:2139 Passive13_0123 */
void Passive13_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060695E2, 3s-exact: sf3 src/pass13.c:2164 Passive13_0124 */
void Passive13_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069644, 3s-exact: sf3 src/pass13.c:2189 Passive13_0125 */
void Passive13_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x48, 6, 0x22);
        break;
    case 1:
        Walk(wk, 1, 0x18, 0);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069680, 3s-reloc: sf3 src/pass13.c:2208 Passive13_0126 */
void Passive13_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060696C4, 3s-exact: sf3 src/pass13.c:2221 Passive13_0127 */
void Passive13_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x48, 6, 0x7E);
        break;
    case 1:
        Walk(wk, 1, 0x18, 0);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069700, 3s-exact: sf3 src/pass13.c:2240 Passive13_0128 */
void Passive13_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x8050, 6, 1, -1);
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



/* 2i 0606974A, 3s-exact: sf3 src/pass13.c:2259 Passive13_0129 */
void Passive13_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606976C, 3s-exact: sf3 src/pass13.c:2272 Passive13_0130 */
void Passive13_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 6, 0x6e);
        break;
    case 1:
        Walk(wk, 1, 0x18, 0);
        break;
    case 2:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060697DE, 3s-reloc: sf3 src/pass13.c:2294 Passive13_0131 */
void Passive13_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069832, 3s-exact: sf3 src/pass13.c:2310 Passive13_0132 */
void Passive13_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x3A, 0x3D, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606987C, 3s-exact: sf3 src/pass13.c:2326 Passive13_0133 */
void Passive13_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, 0x3C, -1);
        break;
    case 1:
        Check_Store_Lever(wk, 0x1C, 6, 0x86);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060698D4, 3s-reloc: sf3 src/pass13.c:2345 Passive13_0134 */
void Passive13_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606993C, 3s-exact: sf3 src/pass13.c:2361 Passive13_0135 */
void Passive13_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606995A, 3s-exact: sf3 src/pass13.c:2374 Passive13_0136 */
void Passive13_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 7, 6, 0x85);
        break;
    case 1:
        Check_SA(wk, 2, 0x35);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x89, 0x89, 0x8A, 0x8B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060699AE, 3s-reloc: sf3 src/pass13.c:2393 Passive13_0137 */
void Passive13_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 9, -1);
        break;
    case 1:
        Check_SA(wk, 2, 0x35);
        break;
    case 2:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069A3C, 3s-exact: sf3 src/pass13.c:2415 Passive13_0138 */
void Passive13_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 10, -1);
        break;
    case 1:
        Check_SA(wk, 2, 0x35);
        break;
    case 2:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069AA2, 3s-exact: sf3 src/pass13.c:2437 Passive13_0139 */
void Passive13_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 10, -1);
        break;
    case 1:
        Check_SA(wk, 2, 0x34);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069B16, 3s-reloc: sf3 src/pass13.c:2459 Passive13_0140 */
void Passive13_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x8D, 0x8D, 0x8E, 0x8F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069B66, 3s-exact: sf3 src/pass13.c:2472 Passive13_0141 */
void Passive13_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069B98, 3s-exact: sf3 src/pass13.c:2485 Passive13_0142 */
void Passive13_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069BCA, 3s-exact: sf3 src/pass13.c:2498 Passive13_0143 */
void Passive13_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069BFC, 3s-exact: sf3 src/pass13.c:2511 Passive13_0144 */
void Passive13_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x91, 0x91, 0x92, 0x93);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069C32, 3s-reloc: sf3 src/pass13.c:2524 Passive13_0145 */
void Passive13_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069C82, 3s-exact: sf3 src/pass13.c:2537 Passive13_0146 */
void Passive13_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069CB4, 3s-exact: sf3 src/pass13.c:2550 Passive13_0147 */
void Passive13_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069CE6, 3s-exact: sf3 src/pass13.c:2563 Passive13_0148 */
void Passive13_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069D04, 3s-exact: sf3 src/pass13.c:2576 Passive13_0149 */
void Passive13_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8040, -1, 0xA008, (0x100), 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069D46, 3s-reloc: sf3 src/pass13.c:2589 Passive13_0150 */
void Passive13_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069D8C, 3s-exact: sf3 src/pass13.c:2602 Passive13_0151 */
void Passive13_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_Store_Lever(wk, 0x1F, 6, 0x96);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069DCE, 3s-exact: sf3 src/pass13.c:2618 Passive13_0152 */
void Passive13_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 8, 6, 0x22);
        break;
    case 1:
        Check_SA(wk, 6, 0x22);
        break;
    case 2:
        SA_Term(wk, -1, 0x3A, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069E26, 3s-reloc: sf3 src/pass13.c:2637 Passive13_0153 */
void Passive13_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8040, -1, 0xA008, (0x200), 2, -1, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069EBC, 3s-exact: sf3 src/pass13.c:2656 Passive13_0154 */
void Passive13_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1E, 9, -1);
        break;
    case 3:
        Check_SA(wk, 6, 0x22);
        break;
    case 4:
        SA_Term(wk, 0x39, 0x3A, 0x3D, -1);
        break;
    case 5:
        Command_Attack(wk, 0xC, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069F4C, 3s-exact: sf3 src/pass13.c:2684 Passive13_0155 */
void Passive13_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06069F92, 3s-reloc: sf3 src/pass13.c:2700 Passive13_0156 */
void Passive13_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xD, 0x10);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x59, 0x8C, 0x9E, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606A018, 3s-reloc: sf3 src/pass13.c:2719 Passive13_0157 */
void Passive13_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606A03A, 3s-reloc: sf3 src/pass13.c:2732 Passive13_0158 */
void Passive13_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

