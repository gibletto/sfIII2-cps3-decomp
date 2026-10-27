/*
 * ACTIVE15.C  CPU active patterns for player 15 (Shin Gouki)
 *
 * Behaviour patterns for the computer-controlled player 15 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer15, which runs the pattern chosen in Pattern_Index
 * through Pattern15_Tbl. Each Pattern15_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 * The set closely follows player 14's.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active15.h"


void Computer15(PLW* wk) {
    Pattern15_Tbl[Pattern_Index[wk->wu.id]](wk);
}



void Pattern15_0000(PLW* wk) {
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


void Pattern15_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0x8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 32, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x30, 0, 0x8080, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 5);
        break;
    case 6:
        SA_Term(wk, 0x2F, -1, 0x31, 0x7F);
        break;
    case 7:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x20));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x30, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xb, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xb, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xb, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xb, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 8, -1, -1, 0x30, 0, 0x8080, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 3);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 0xB, 0x2F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 8, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 11, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 31, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 8, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 8, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 3);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    case 3:
        Wait(wk, 1);
        break;
    case 4:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x37, 0x37, 0x36, 0x35);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8016, 0xA, -1, 0x8050, 0x8040, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA_Full(wk, 6, 0x7c);
        break;
    case 1:
        EM_Term(wk, 0x80d0, -1, 5, 2, 0);
        break;
    case 2:
        Only_Shot(wk, 0x10);
        break;
    case 3:
        Wait(wk, 1);
        break;
    case 4:
        Only_Shot(wk, 0x10);
        break;
    case 5:
        Wait(wk, 1);
        break;
    case 6:
        Lever_On(wk, 0, 0);
        break;
    case 7:
        Wait(wk, 1);
        break;
    case 8:
        Only_Shot(wk, (0x80));
        break;
    case 9:
        Wait(wk, 1);
        break;
    case 10:
        Only_Shot(wk, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x84, 0x84, 0x85, 0x86, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 4:
        Command_Attack(wk, 12, 31, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 4:
        Command_Attack(wk, 12, 31, 10, -1);
        break;
    case 5:
        Wait(wk, 1);
        break;
    case 6:
        SA_Term(wk, 47, 48, 49, 127);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 4:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 9, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 4:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 4:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 3:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 5:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    case 6:
        Wait(wk, 1);
        break;
    case 7:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Lever_Attack(wk, 9, 0, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 4:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 5:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 6:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    case 7:
        Wait(wk, 1);
        break;
    case 8:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        SA_Term(wk, 0x32, -1, -1, 0xbf);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 0xB, 0x2F, 0xA, -1, -1, 0x40, 0, -1, -1, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 127, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
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



void Pattern15_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 4:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 5:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 4:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 6:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 7:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
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



void Pattern15_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 5:
        Lever_On(wk, 1, 2);
        break;
    case 6:
        Wait(wk, 2);
        break;
    case 7:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 2:
        Approach_Walk(wk, 16, 2);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 2:
        Approach_Walk(wk, 16, 2);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        J_Command_Attack(wk, 8, 32, 8, (-1));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 4:
        Approach_Walk(wk, 16, 2);
        break;
    case 5:
        Lever_Attack(wk, 8, 0, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 4:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 5:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7f);
        break;
    case 6:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 7:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 2:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 2:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 2:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 2:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, (-1));
        break;
    case 1:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, (-1));
        break;
    case 1:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, (-1));
        break;
    case 1:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, (-1));
        break;
    case 1:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, (-1), 32928, 80, 0, 32896, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, (-1), 32928, 80, 0, 32896, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, (-1), 32928, 80, 0, 32896, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, (-1), 32928, 80, 0, 32896, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 34, 8, (-1));
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 768, 2, 118);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 10, (-1));
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 3:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x80, 2, 0x76);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 3:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 512, 2, 119);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 3:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 256, 2, 119);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, (-1));
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 3:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 114, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 114, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 114, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 114, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x21, 0x3F, 0x40, 0x41, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x23, 0x24, 0x25, 0x3D, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x22, 0x43, 0x3C, 0x3E, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    case 2:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 114, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    case 2:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x71, 0x72, 0x71, 0x72, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x1A, 0x1C, 0x1D, 0x1E, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 120, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 134, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 119, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 132, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x84, 0x85, 0x86, 0x87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xc, 0x102);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 8, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x2f, -1, 0x31, 0x7f);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 1:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 8, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x2f, -1, 0x31, 0x7f);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xc, 0x102);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 9, -1);
        break;
    case 4:
        Wait(wk, 3);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1e, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 11, 32, 9, (-1));
        break;
    case 4:
        Wait(wk, 3);
        break;
    case 5:
        J_Command_Attack(wk, 8, 30, 9, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x26, 0x27, 0x28, 0x29, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 3:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 3:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 3:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Pattern15_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 3:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
