/*
 * pass15.c  Computer AI passive patterns for character 15 (Shin Gouki)
 *
 * Passive15 is the passive-mode entry for character number 15, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive15_Tbl; this file holds the 248 patterns
 * Passive15_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass15.h"



void Passive15(PLW* wk) {
    Passive15_Tbl[Pattern_Index[wk->wu.id]](wk);
}



void Passive15_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0001(PLW* wk) {
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



void Passive15_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8024, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8020, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
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



void Passive15_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
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



void Passive15_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xD, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
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
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8100, 6, 6, 0x7C);
        break;
    case 1:
        Command_Attack(wk, 8, 0x21, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 6, 0x7C);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 9, 0x20, 8, -1);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        Wait(wk, 3);
        break;
    case 6:
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 7:
        Wait(wk, 3);
        break;
    case 8:
        SA_Term(wk, -1, -1, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 4:
        Wait(wk, 4);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 6, 0x7C);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 6, 0x7C);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 10, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xD, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        J_Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;
    case 5:
        Wait(wk, 4);
        break;
    case 6:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 4:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    case 5:
        Wait(wk, 1);
        break;
    case 6:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 6:
        Wait(wk, 3);
        break;
    case 7:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8030, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 5:
        Pierce_On(wk);
        break;
    case 6:
        Wait(wk, 3);
        break;
    case 7:
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 8:
        Wait(wk, 3);
        break;
    case 9:
        SA_Term(wk, -1, -1, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x30, 0x31, 0x7F);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, 0x8060, 6, 6, 0x35);
        break;
    case 1:
        SA_Term(wk, -1, 0x30, 0x31, 0x7F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x30, 0x31, 0x7F);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 6, 0x35);
        break;
    case 1:
        SA_Term(wk, -1, 0x30, 0x31, 0x7F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        EM_Term(wk, 0x8040, 0x8038, 6, 6, 0x35);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8030, 6, 6, 0x35);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, 0x100, 2, 0x8060, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, 0x200, 2, 0x8060, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -1, 0x10, 2, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x31, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
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



void Passive15_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        J_Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;
    case 4:
        Wait(wk, 3);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8080, 0x20, 8, 0x200, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8050, 6, 6, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8040, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0060(PLW* wk) {
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



void Passive15_0061(PLW* wk) {
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



void Passive15_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 4, 6, 0x37);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    case 2:
        Next_Another_Menu(wk, 6, 0x39);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0xE0, 6, 0x45);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 0xB, 0x100, 0, 0x8080, -1, 0x200);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0x14, 0xF, 5, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0x14, 0xF, 5, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
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



void Passive15_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0xA, 7, 3, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 10, 7, 3, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x21, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 10, 7, 3, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x21, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0xF, 10, 5, 1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0xE0, 6, 0x45);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8020, 0xB, 0x100, 0, 0x8080, -1, 0x200);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 4, 6, 0x37);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    case 2:
        Next_Another_Menu(wk, 6, 0x46);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x300, 6, 0xE3);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    case 2:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x47);
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



void Passive15_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x80, 6, 0xE3);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    case 2:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x47);
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



void Passive15_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x200, 6, 0xE4);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 2:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x47);
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



void Passive15_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x100, 6, 0xE4);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 2:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x47);
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



void Passive15_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    case 2:
        Wait(wk, 1);
        break;
    case 3:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 1:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 1:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 1:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
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



void Passive15_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 3:
        Wait(wk, 3);
        break;
    case 4:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x15, 0x1D, 0x1E, 0x1F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 10, 0x102);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 10, 0x82);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 10, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 10, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
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



void Passive15_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x20, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0x8, -1, -1, 0x20, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0x8, -1, -1, 0x20, 0x1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x57, 0x57, 0x58, 0x59, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x5A, 0x5B, 0x5C, 0x5D, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x57, 0x57, 0x58, 0x59, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x5A, 0x5B, 0x5C, 0x5D, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x81, 0x81, 0x82, 0x82, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x84, 0x84, 0x85, 0x86, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x87, 0x87, 0x88, 0x89, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 10, 0x20, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xA, 0x20, 9, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xA, 0x20, 0xA, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x8C, 0x8C, 0x8D, 0x8E, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x90, 0xFF, 0xFF, 0xFF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 0xC, 0x2E, 8, -1, -1, 0x34, 0, -1, -1, -1);
        break;
    case 1:
        SA_Term(wk, 0x2F, -1, -1, 0xBF);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA_Full(wk, 6, 0x76);
        break;
    case 1:
        Only_Shot(wk, 0x10);
        break;
    case 2:
        Wait(wk, 1);
        break;
    case 3:
        Only_Shot(wk, 0x10);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        Lever_On(wk, 0, 0);
        break;
    case 6:
        Wait(wk, 1);
        break;
    case 7:
        Only_Shot(wk, 0x80);
        break;
    case 8:
        Wait(wk, 1);
        break;
    case 9:
        Only_Shot(wk, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 6, 0x76);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 0xA, -1, -1, 0x20, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x92, 0x92, 0x93, 0x94, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x81, 0x82, 0x81, 0x82, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 8, 0x49, 0xB, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 3:
        Wait(wk, 1);
        break;
    case 4:
        SA_Term(wk, 0x2F, 0x34, 0x34, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 0xB, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x34, 0x34, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Normal_Attack(wk, 0xD, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x34, 0x34, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x34, 0x34, 0x7F);
        break;
    case 6:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
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



void Passive15_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
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



void Passive15_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Wait_Get_Up(wk, 0x3, 0);
        break;
    case 2:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 3:
        Com_Random_Select(wk, 6, 113, 113, 114, 115, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0x3, 0);
        break;
    case 2:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 3:
        Com_Random_Select(wk, 6, 116, 116, 117, 118, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 132, 132, 133, 134, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 4:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 4:
        Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 5:
        Wait(wk, 1);
        break;
    case 6:
        SA_Term(wk, 0x2F, 0x34, 0x34, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
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



void Passive15_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, 0x102, 0, 32896, -1, 0x200);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 4:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 5:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
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



void Passive15_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
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



void Passive15_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 3:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, 0x102, 0, 32896, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
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



void Passive15_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 3:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 63, 64, 65, 66, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 3:
        Command_Attack(wk, 12, 31, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 3:
        Command_Attack(wk, 11, 31, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 47, 52, 52, 127);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 3:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, 0x102, 0, 32896, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
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



void Passive15_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 3:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, 0x102, 0, 32896, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
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



void Passive15_0184(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Command_Attack(wk, 11, 31, 10, -1);
        break;
    case 2:
        Wait(wk, 1);
        break;
    case 3:
        SA_Term(wk, 47, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 2:
        Command_Attack(wk, 11, 31, 10, -1);
        break;
    case 3:
        Wait(wk, 1);
        break;
    case 4:
        SA_Term(wk, 47, 52, 52, 127);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0186(PLW* wk) {
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



void Passive15_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 2:
        Command_Attack(wk, 12, 31, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 11, 0x102);
        break;
    case 2:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 3:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 32896, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 11, 0x102);
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 3:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0190(PLW* wk) {
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



void Passive15_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 11, 0x102, 0, 32896, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 11, 0x102);
        break;
    case 3:
        SA_Term(wk, 47, 52, 52, 127);
        break;
    case 4:
        Com_Random_Select(wk, 6, 119, 119, 120, 121, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 0xB, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 3);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0193(PLW* wk) {
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



void Passive15_0194(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0195(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0197(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7C);
        break;
    case 3:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 5:
        Pierce_On(wk);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 7:
        Wait(wk, 3);
        break;
    case 8:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 0x1, 1);
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 127);
        break;
    case 2:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 31, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0205(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 181, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, -1, 32928, 80, 0, 32896, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0209(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, -1, 32928, 80, 0, 32896, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 173, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, -1, 32928, 80, 0, 32896, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0211(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 47, 10, -1, 32928, 80, 0, 32896, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0212(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 50, -1, -1, 191);
        break;
    case 1:
        Com_Random_Select(wk, 6, 113, 113, 114, 115, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0213(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0214(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0215(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0216(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0217(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0218(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0219(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0220(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 0x8080, -1, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0221(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 768, 6, 225);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 10, -1);
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 3:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0222(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x80, 6, 0xE1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
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



void Passive15_0223(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 512, 6, 226);
        break;
    case 1:
        Command_Attack(wk, 8, 29, 8, -1);
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 3:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0224(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x100, 6, 0xE2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
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



void Passive15_0225(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 10, -1);
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0226(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 8, -1);
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0227(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 10, -1);
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0228(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 8, -1);
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0229(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 34, 8, -1);
        break;
    case 1:
        SA_Term(wk, 52, 52, 52, 71);
        break;
    case 2:
        EM_Term(wk, 32848, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0230(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 1:
        Check_SA_Full(wk, 6, 17);
        break;
    case 2:
        SA_Term(wk, 52, 52, 52, 127);
        break;
    case 3:
        Normal_Attack(wk, 12, 0x40);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        J_Command_Attack(wk, 8, 32, 8, -1);
        break;
    case 6:
        Wait(wk, 3);
        break;
    case 7:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0231(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Check_SA_Full(wk, 6, 0x11);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0xBF);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 6:
        Wait(wk, 3);
        break;
    case 7:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0232(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 3);
        break;
    case 1:
        Look(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0233(PLW* wk) {
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



void Passive15_0234(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 0x1, 1);
        break;
    case 1:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 2:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 31, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0235(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 6, 1);
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 127);
        break;
    case 2:
        J_Command_Attack(wk, 8, 30, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0236(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8098, -1, 6, 6, 1);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 4, 6, 235);
        break;
    case 2:
        Normal_Attack(wk, 12, 0x102);
        break;
    case 3:
        Command_Attack(wk, 12, 31, 10, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 47, 48, 49, 127);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0237(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 6, 1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 30, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0238(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0239(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0240(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x84, 0x85, 0x86, 0x87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0241(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0242(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
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



void Passive15_0243(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x26, 0x27, 0x28, 0x29, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0244(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, 0x3, 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0245(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, 0x3, 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0246(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, 0x3, 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0247(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, 0x3, 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, 0x102, 0, 32896, -1, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive15_0248(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
