/*
 * ACTIVE13.C  CPU active patterns for player 13 (Urien)
 *
 * Behaviour patterns for the computer-controlled player 13 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer13, which runs the pattern chosen in Pattern_Index
 * through Pattern13_Tbl. Each Pattern13_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active13.h"


void Computer13(PLW* wk) {
    Pattern13_Tbl[Pattern_Index[wk->wu.id]](wk);
}



void Pattern13_0000(PLW* wk) {
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


void Pattern13_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xD, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0005(PLW* wk) {
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



void Pattern13_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Lever_On(wk, 1, 2);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 2, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 8, 0x10, 0, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, 0x8070, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Search_Back_Term(wk, 0x60, 2, 0x12);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x10, 0, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x80);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Lever_On(wk, 1, 2);
        break;
    case 2:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Lever_On(wk, 1, 2);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0);
        break;
    case 1:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0x9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x32, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0055(PLW* wk) {
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



void Pattern13_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8048, 8, 0x200, 1, 0x8070, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 7, 2, 0x44);
        break;
    case 1:
        Check_SA(wk, 2, 0x44);
        break;
    case 2:
        Branch_Unit_Area(wk, 2, 0x40, 0x40, 0x41, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0064(PLW* wk) {
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



void Pattern13_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
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



void Pattern13_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
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



void Pattern13_0067(PLW* wk) {
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



void Pattern13_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, 0x3C, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, 0x8070, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern13_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
