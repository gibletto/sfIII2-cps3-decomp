/*
 * PASS06.C  CPU passive patterns for character 6 (Hugo)
 *
 * Passive06 is the CPU passive (defensive) routine for character 6, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive06_Tbl.
 * The 147 Passive06_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS06.h"



void Passive06(PLW* wk) {
    Passive06_Tbl[Pattern_Index[wk->wu.id]](wk);
}



void Passive06_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0001(PLW* wk) {
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



void Passive06_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x70, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x68, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x70, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x68, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 1, -1, 3, 0x78);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1E, 10, 0x70);
        break;
    case 3:
        SA_Term(wk, -1, 2, 3, 0x78);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8004, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8004, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8080, 6, 1, -1);
        break;
    case 2:
        Check_EX(wk, 6, 0x18);
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 1, -1, 3, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80C0, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x38, 8, 0x200, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 2, -1, -1);
        break;
    case 1:
        Next_Another_Menu(wk, 6, 0x2F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xB, 0x20, 10, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xB, 0x20, 10, -1);
        break;
    case 3:
        SA_Term(wk, -1, 2, -1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Check_EX(wk, 6, 0x65);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        Command_Attack(wk, 0xB, 0x20, 10, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 2, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x2D);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x3C, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 8, 0x100, 0, 0x8058, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8078, 0x8040, 8, 0x200, 0, 0x8078, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8098, 0x8040, 8, 0x100, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8098, 0x8040, 8, 0x200, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8058, -1, 0x200);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8100, -1, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 6, 1, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
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



void Passive06_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
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



void Passive06_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Check_EX(wk, 6, 0x4E);
        break;
    case 3:
        Wait(wk, 10);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 6:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x65, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0084(PLW* wk) {
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



void Passive06_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x9F, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xFF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x9F, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x9F, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x65, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xFF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x3C, 0x3D, 0x3F, 0x65, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x65, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x3C, 0x3D, 0x3F, 0x65, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        Check_EX(wk, 6, 0x36);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0xF);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Provoke(wk, -1);
        break;
    case 3:
        Next_Another_Menu(wk, 6, 0xF);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 3, -1);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 4, 6, 0x36);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    case 2:
        Next_Another_Menu(wk, 6, 0x37);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x65, 0x5B, 0x5A, 0x58, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 8, 0x100, 1, 0x8058, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8098, 0x40, 8, 0x40, 2, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 1, -1, -1);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Check_EX(wk, 6, 0x6F);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;
    case 1:
        Check_EX(wk, 6, 0x79);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Command_Attack(wk, 0xB, 0x1E, 10, 0x70);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80C0, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80E0, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80C0, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x16, 0x13, 0x2C, 8, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 3, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    case 1:
        SA_Term(wk, 1, -1, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 8, 0x42, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 9, 0x42, 0, 0x8098, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 3:
        Wait(wk, 9);
        break;
    case 4:
        EM_Term(wk, 0x8070, -1, 4, 6, 0x89);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 9, 0x42, 0, 0x8098, -1, 0x200);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 4:
        Wait(wk, 9);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x8A, 0x16, 0x86, 0x87, 5);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 1, -1, 3, -1);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xB, 0x20, 0xA, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8058, 9, 0x42, 0, 0x8098, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 3:
        Wait(wk, 9);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x89, 0x86, 0x16, 0x87, 5);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



void Passive06_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 4, 6, 0x89);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

