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



/* 2i 0607096C, 3s-exact: sf3 src/pass15.c:21 Passive15 */
void Passive15(PLW* wk) {
    Passive15_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06070984, 3s-exact: sf3 src/pass15.c:27 Passive15_0000 */
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



/* 2i 060709B8, 3s-exact: sf3 src/pass15.c:40 Passive15_0001 */
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



/* 2i 060709E0, 3s-exact: sf3 src/pass15.c:56 Passive15_0002 */
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



/* 2i 06070A32, 3s-exact: sf3 src/pass15.c:75 Passive15_0003 */
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



/* 2i 06070A84, 3s-reloc: sf3 src/pass15.c:94 Passive15_0004 */
void Passive15_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8020, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070B0A, 3s-exact: sf3 src/pass15.c:113 Passive15_0005 */
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



/* 2i 06070B5E, 3s-exact: sf3 src/pass15.c:132 Passive15_0006 */
void Passive15_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070BB2, 3s-reloc: sf3 src/pass15.c:151 Passive15_0007 */
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



/* 2i 06070C24, 3s-exact: sf3 src/pass15.c:170 Passive15_0008 */
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



/* 2i 06070C64, 3s-exact: sf3 src/pass15.c:186 Passive15_0009 */
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



/* 2i 06070CCC, 3s-exact: sf3 src/pass15.c:208 Passive15_0010 */
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



/* 2i 06070D4A, 3s-reloc: sf3 src/pass15.c:233 Passive15_0011 */
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



/* 2i 06070E0C, 3s-exact: sf3 src/pass15.c:264 Passive15_0012 */
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



/* 2i 06070E66, 3s-exact: sf3 src/pass15.c:283 Passive15_0013 */
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



/* 2i 06070EB2, 3s-exact: sf3 src/pass15.c:299 Passive15_0014 */
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



/* 2i 06070EFE, 3s-reloc: sf3 src/pass15.c:315 Passive15_0015 */
void Passive15_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 6, 0x7C);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070F7A, 3s-reloc: sf3 src/pass15.c:334 Passive15_0016 */
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



/* 2i 0607105C, 3s-exact: sf3 src/pass15.c:371 Passive15_0017 */
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



/* 2i 060710E6, 3s-exact: sf3 src/pass15.c:399 Passive15_0018 */
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



/* 2i 0607114E, 3s-exact: sf3 src/pass15.c:421 Passive15_0019 */
void Passive15_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xc, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1e, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060711BC, 3s-exact: sf3 src/pass15.c:443 Passive15_0020 */
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



/* 2i 0607120E, 3s-reloc: sf3 src/pass15.c:462 Passive15_0021 */
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



/* 2i 06071292, 3s-exact: sf3 src/pass15.c:481 Passive15_0022 */
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



/* 2i 060712DE, 3s-reloc: sf3 src/pass15.c:497 Passive15_0023 */
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



/* 2i 06071370, 3s-exact: sf3 src/pass15.c:516 Passive15_0024 */
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



/* 2i 060713FA, 3s-exact: sf3 src/pass15.c:541 Passive15_0025 */
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



/* 2i 0607146A, 3s-reloc: sf3 src/pass15.c:563 Passive15_0026 */
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
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071500, 3s-exact: sf3 src/pass15.c:585 Passive15_0027 */
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



/* 2i 06071568, 3s-reloc: sf3 src/pass15.c:607 Passive15_0028 */
void Passive15_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 2:
        EM_Term(wk, -1, 0x8008, 6, 6, 0x7c);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 4:
        J_Command_Attack(wk, 0xc, 0x1e, 0xa, -1);
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



/* 2i 06071632, 3s-reloc: sf3 src/pass15.c:638 Passive15_0029 */
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
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06071704, 3s-exact: sf3 src/pass15.c:669 Passive15_0030 */
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
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 060717B6, 3s-reloc: sf3 src/pass15.c:703 Passive15_0031 */
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
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071864, 3s-exact: sf3 src/pass15.c:728 Passive15_0032 */
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
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060718CC, 3s-reloc: sf3 src/pass15.c:750 Passive15_0033 */
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



/* 2i 06071978, 3s-reloc: sf3 src/pass15.c:775 Passive15_0034 */
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



/* 2i 06071A38, 3s-reloc: sf3 src/pass15.c:803 Passive15_0035 */
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



/* 2i 06071B08, 3s-exact: sf3 src/pass15.c:843 Passive15_0036 */
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



/* 2i 06071B50, 3s-exact: sf3 src/pass15.c:859 Passive15_0037 */
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



/* 2i 06071BB2, 3s-exact: sf3 src/pass15.c:878 Passive15_0038 */
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



/* 2i 06071BFA, 3s-exact: sf3 src/pass15.c:894 Passive15_0039 */
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



/* 2i 06071C5C, 3s-reloc: sf3 src/pass15.c:913 Passive15_0040 */
void Passive15_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;
    case 1:
        EM_Term(wk, 0x8040, 0x8038, 6, 6, 0x35);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071CE2, 3s-exact: sf3 src/pass15.c:932 Passive15_0041 */
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
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071D4A, 3s-exact: sf3 src/pass15.c:954 Passive15_0042 */
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



/* 2i 06071D8C, 3s-reloc: sf3 src/pass15.c:970 Passive15_0043 */
void Passive15_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, (0x100), 2, 0x8060, -1, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071DF2, 3s-exact: sf3 src/pass15.c:983 Passive15_0044 */
void Passive15_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, (0x200), 2, 0x8060, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071E34, 3s-reloc: sf3 src/pass15.c:996 Passive15_0045 */
void Passive15_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2f, 0xa, -1, -1, 0x10, 2, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x31, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1e, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06071ED4, 3s-exact: sf3 src/pass15.c:1018 Passive15_0046 */
void Passive15_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7f, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1f, 0xa, -1);
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



/* 2i 06071F66, 3s-reloc: sf3 src/pass15.c:1046 Passive15_0047 */
void Passive15_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 0607201E, 3s-exact: sf3 src/pass15.c:1074 Passive15_0048 */
void Passive15_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8080, 0x20, 8, (0x200), 1, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072060, 3s-exact: sf3 src/pass15.c:1087 Passive15_0049 */
void Passive15_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8050, 6, 6, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060720A4, 3s-reloc: sf3 src/pass15.c:1103 Passive15_0050 */
void Passive15_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607211E, 3s-exact: sf3 src/pass15.c:1119 Passive15_0051 */
void Passive15_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8040, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607217A, 3s-exact: sf3 src/pass15.c:1138 Passive15_0052 */
void Passive15_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060721A6, 3s-exact: sf3 src/pass15.c:1154 Passive15_0053 */
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



/* 2i 060721C4, 3s-exact: sf3 src/pass15.c:1167 Passive15_0054 */
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



/* 2i 060721E4, 3s-reloc: sf3 src/pass15.c:1180 Passive15_0055 */
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



/* 2i 0607222C, 3s-exact: sf3 src/pass15.c:1193 Passive15_0056 */
void Passive15_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072258, 3s-exact: sf3 src/pass15.c:1209 Passive15_0057 */
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



/* 2i 06072286, 3s-exact: sf3 src/pass15.c:1225 Passive15_0058 */
void Passive15_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060722B2, 3s-exact: sf3 src/pass15.c:1241 Passive15_0059 */
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



/* 2i 060722E0, 3s-reloc: sf3 src/pass15.c:1257 Passive15_0060 */
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



/* 2i 06072328, 3s-exact: sf3 src/pass15.c:1273 Passive15_0061 */
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



/* 2i 06072354, 3s-exact: sf3 src/pass15.c:1289 Passive15_0062 */
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



/* 2i 060723A2, 3s-exact: sf3 src/pass15.c:1308 Passive15_0063 */
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



/* 2i 060723DA, 3s-reloc: sf3 src/pass15.c:1327 Passive15_0064 */
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



/* 2i 06072428, 3s-exact: sf3 src/pass15.c:1343 Passive15_0065 */
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



/* 2i 06072454, 3s-exact: sf3 src/pass15.c:1359 Passive15_0066 */
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



/* 2i 060724A2, 3s-exact: sf3 src/pass15.c:1378 Passive15_0067 */
void Passive15_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060724CE, 3s-reloc: sf3 src/pass15.c:1394 Passive15_0068 */
void Passive15_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0xE0, 6, 0x45);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 0xB, (0x100), 0, 0x8080, -1, (0x200));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072566, 3s-exact: sf3 src/pass15.c:1416 Passive15_0069 */
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



/* 2i 060725BC, 3s-reloc: sf3 src/pass15.c:1435 Passive15_0070 */
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



/* 2i 0607263C, 3s-exact: sf3 src/pass15.c:1454 Passive15_0071 */
void Passive15_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072674, 3s-exact: sf3 src/pass15.c:1473 Passive15_0072 */
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



/* 2i 060726AE, 3s-reloc: sf3 src/pass15.c:1492 Passive15_0073 */
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



/* 2i 06072728, 3s-exact: sf3 src/pass15.c:1511 Passive15_0074 */
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



/* 2i 0607277E, 3s-exact: sf3 src/pass15.c:1530 Passive15_0075 */
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



/* 2i 060727D4, 3s-exact: sf3 src/pass15.c:1549 Passive15_0076 */
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



/* 2i 0607282A, 3s-reloc: sf3 src/pass15.c:1568 Passive15_0077 */
void Passive15_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0xE0, 6, 0x45);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8020, 0xB, (0x100), 0, 0x8080, -1, (0x200));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060728BA, 3s-exact: sf3 src/pass15.c:1590 Passive15_0078 */
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



/* 2i 060728F2, 3s-exact: sf3 src/pass15.c:1609 Passive15_0079 */
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



/* 2i 06072924, 3s-reloc: sf3 src/pass15.c:1622 Passive15_0080 */
void Passive15_0080(PLW* wk) {
    s16 m = -1;

    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, m, m);
        break;
    case 1:
        Command_Attack(wk, 8, 0, m, m);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072990, 3s-exact: sf3 src/pass15.c:1640 Passive15_0081 */
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



/* 2i 06072A18, 3s-reloc: sf3 src/pass15.c:1665 Passive15_0082 */
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



/* 2i 06072AC8, 3s-exact: sf3 src/pass15.c:1690 Passive15_0083 */
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



/* 2i 06072B50, 3s-reloc: sf3 src/pass15.c:1715 Passive15_0084 */
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



/* 2i 06072BFE, 3s-exact: sf3 src/pass15.c:1740 Passive15_0085 */
void Passive15_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x102));
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



/* 2i 06072C60, 3s-reloc: sf3 src/pass15.c:1762 Passive15_0086 */
void Passive15_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072CB8, 3s-exact: sf3 src/pass15.c:1778 Passive15_0087 */
void Passive15_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072CF8, 3s-exact: sf3 src/pass15.c:1794 Passive15_0088 */
void Passive15_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072D38, 3s-exact: sf3 src/pass15.c:1810 Passive15_0089 */
void Passive15_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072D78, 3s-reloc: sf3 src/pass15.c:1826 Passive15_0090 */
void Passive15_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072DD0, 3s-exact: sf3 src/pass15.c:1842 Passive15_0091 */
void Passive15_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06072E26, 3s-exact: sf3 src/pass15.c:1861 Passive15_0092 */
void Passive15_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06072E7C, 3s-reloc: sf3 src/pass15.c:1880 Passive15_0093 */
void Passive15_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06072EEA, 3s-near: sf3 src/pass15.c:1899 Passive15_0094 */
void Passive15_0094(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06072F4A, 3s-near: sf3 src/pass15.c:1921 Passive15_0095 */
void Passive15_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06072FE4, 3s-near: sf3 src/pass15.c:1946 Passive15_0096 */
void Passive15_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 0607305C, 3s-reloc: sf3 src/pass15.c:1971 Passive15_0097 */
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



/* 2i 060730A4, 3s-reloc: sf3 src/pass15.c:1987 Passive15_0098 */
void Passive15_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060730F6, 3s-near: sf3 src/pass15.c:2003 Passive15_0099 */
void Passive15_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06073122, 3s-near: sf3 src/pass15.c:2019 Passive15_0100 */
void Passive15_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607314E, 3s-near: sf3 src/pass15.c:2035 Passive15_0101 */
void Passive15_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 10, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06073194, 3s-near: sf3 src/pass15.c:2054 Passive15_0102 */
void Passive15_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 10, (0x82));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060731F2, 3s-exact: sf3 src/pass15.c:2073 Passive15_0103 */
void Passive15_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 10, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607323C, 3s-reloc: sf3 src/pass15.c:2092 Passive15_0104 */
void Passive15_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 10, (0x102));
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



/* 2i 060732C4, 3s-exact: sf3 src/pass15.c:2117 Passive15_0105 */
void Passive15_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1f, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06073306, 3s-exact: sf3 src/pass15.c:2133 Passive15_0106 */
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



/* 2i 06073348, 3s-exact: sf3 src/pass15.c:2149 Passive15_0107 */
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



/* 2i 06073366, 3s-exact: sf3 src/pass15.c:2162 Passive15_0108 */
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



/* 2i 06073392, 3s-exact: sf3 src/pass15.c:2178 Passive15_0109 */
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



/* 2i 060733BE, 3s-reloc: sf3 src/pass15.c:2194 Passive15_0110 */
void Passive15_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06073402, 3s-exact: sf3 src/pass15.c:2210 Passive15_0111 */
void Passive15_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607342E, 3s-exact: sf3 src/pass15.c:2226 Passive15_0112 */
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



/* 2i 0607347C, 3s-exact: sf3 src/pass15.c:2245 Passive15_0113 */
void Passive15_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x20, 2, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060734C6, 3s-reloc: sf3 src/pass15.c:2258 Passive15_0114 */
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



/* 2i 06073530, 3s-exact: sf3 src/pass15.c:2271 Passive15_0115 */
void Passive15_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 2, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607357A, 3s-exact: sf3 src/pass15.c:2284 Passive15_0116 */
void Passive15_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0x8, -1, -1, 0x20, 0, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060735C4, 3s-reloc: sf3 src/pass15.c:2297 Passive15_0117 */
void Passive15_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 0, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06073620, 3s-exact: sf3 src/pass15.c:2310 Passive15_0118 */
void Passive15_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 0, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607366A, 3s-exact: sf3 src/pass15.c:2323 Passive15_0119 */
void Passive15_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0x8, -1, -1, 0x20, 0x1, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060736B4, 3s-exact: sf3 src/pass15.c:2336 Passive15_0120 */
void Passive15_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 1, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060736FE, 3s-reloc: sf3 src/pass15.c:2349 Passive15_0121 */
void Passive15_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 1, 0x8080, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607375A, 3s-exact: sf3 src/pass15.c:2362 Passive15_0122 */
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



/* 2i 06073794, 3s-exact: sf3 src/pass15.c:2375 Passive15_0123 */
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



/* 2i 060737CE, 3s-exact: sf3 src/pass15.c:2388 Passive15_0124 */
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



/* 2i 06073808, 3s-exact: sf3 src/pass15.c:2401 Passive15_0125 */
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



/* 2i 0607385C, 3s-exact: sf3 src/pass15.c:2417 Passive15_0126 */
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



/* 2i 060738B0, 3s-exact: sf3 src/pass15.c:2433 Passive15_0127 */
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



/* 2i 060738F8, 3s-exact: sf3 src/pass15.c:2449 Passive15_0128 */
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



/* 2i 06073940, 3s-reloc: sf3 src/pass15.c:2465 Passive15_0129 */
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



/* 2i 0607398C, 3s-exact: sf3 src/pass15.c:2481 Passive15_0130 */
void Passive15_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060739BA, 3s-exact: sf3 src/pass15.c:2497 Passive15_0131 */
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



/* 2i 060739F2, 3s-exact: sf3 src/pass15.c:2510 Passive15_0132 */
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



/* 2i 06073A24, 3s-exact: sf3 src/pass15.c:2523 Passive15_0133 */
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



/* 2i 06073A56, 3s-reloc: sf3 src/pass15.c:2536 Passive15_0134 */
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



/* 2i 06073AA8, 3s-exact: sf3 src/pass15.c:2549 Passive15_0135 */
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



/* 2i 06073ADA, 3s-exact: sf3 src/pass15.c:2562 Passive15_0136 */
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



/* 2i 06073B0C, 3s-exact: sf3 src/pass15.c:2575 Passive15_0137 */
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



/* 2i 06073B3E, 3s-exact: sf3 src/pass15.c:2588 Passive15_0138 */
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



/* 2i 06073B78, 3s-reloc: sf3 src/pass15.c:2601 Passive15_0139 */
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



/* 2i 06073BD0, 3s-exact: sf3 src/pass15.c:2614 Passive15_0140 */
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



/* 2i 06073C18, 3s-exact: sf3 src/pass15.c:2630 Passive15_0141 */
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



/* 2i 06073C60, 3s-exact: sf3 src/pass15.c:2646 Passive15_0142 */
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



/* 2i 06073CA8, 3s-reloc: sf3 src/pass15.c:2662 Passive15_0143 */
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



/* 2i 06073D12, 3s-exact: sf3 src/pass15.c:2678 Passive15_0144 */
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



/* 2i 06073D44, 3s-exact: sf3 src/pass15.c:2691 Passive15_0145 */
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



/* 2i 06073D96, 3s-reloc: sf3 src/pass15.c:2707 Passive15_0146 */
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



/* 2i 06073E18, 3s-reloc: sf3 src/pass15.c:2723 Passive15_0147 */
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
        Only_Shot(wk, (0x80));
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



/* 2i 06073EBA, 3s-exact: sf3 src/pass15.c:2763 Passive15_0148 */
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



/* 2i 06073F10, 3s-exact: sf3 src/pass15.c:2779 Passive15_0149 */
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



/* 2i 06073F4A, 3s-near: sf3 src/pass15.c:2792 Passive15_0150 */
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



/* 2i 06073FC4, 3s-reloc: sf3 src/pass15.c:2808 Passive15_0151 */
void Passive15_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 8, 0x49, 0xB, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 0607407C, 3s-reloc: sf3 src/pass15.c:2833 Passive15_0152 */
void Passive15_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 0xB, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06074116, 3s-reloc: sf3 src/pass15.c:2861 Passive15_0153 */
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



/* 2i 06074138, 3s-reloc: sf3 src/pass15.c:2874 Passive15_0154 */
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



/* 2i 060741B0, 3s-near: sf3 src/pass15.c:2890 Passive15_0155 */
void Passive15_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06074226, 3s-near: sf3 src/pass15.c:2912 Passive15_0156 */
void Passive15_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 060742E4, 3s-reloc: sf3 src/pass15.c:2940 Passive15_0157 */
void Passive15_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607435A, 3s-near: sf3 src/pass15.c:2962 Passive15_0158 */
void Passive15_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06074438, 3s-near: sf3 src/pass15.c:2993 Passive15_0159 */
void Passive15_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060744C8, 3s-near: sf3 src/pass15.c:3012 Passive15_0160 */
void Passive15_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06074552, 3s-reloc: sf3 src/pass15.c:3037 Passive15_0161 */
void Passive15_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060745E4, 3s-near: sf3 src/pass15.c:3056 Passive15_0162 */
void Passive15_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 0607466E, 3s-reloc: sf3 src/pass15.c:3081 Passive15_0163 */
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



/* 2i 060746A0, 3s-reloc: sf3 src/pass15.c:3094 Passive15_0164 */
void Passive15_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, (-1));
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), 0);
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



/* 2i 0607473C, 3s-reloc: sf3 src/pass15.c:3116 Passive15_0165 */
void Passive15_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), 0);
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



/* 2i 060747A8, 3s-reloc: sf3 src/pass15.c:3138 Passive15_0166 */
void Passive15_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, (-1));
        break;
    case 1:
        Com_Random_Select(wk, 6, 132, 132, 133, 134, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607481C, 3s-near: sf3 src/pass15.c:3154 Passive15_0167 */
void Passive15_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 4:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060748AA, 3s-near: sf3 src/pass15.c:3179 Passive15_0168 */
void Passive15_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06074986, 3s-near: sf3 src/pass15.c:3210 Passive15_0169 */
void Passive15_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
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



/* 2i 06074A58, 3s-reloc: sf3 src/pass15.c:3235 Passive15_0170 */
void Passive15_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, (0x102), 0, 32896, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x102));
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



/* 2i 06074AF4, 3s-near: sf3 src/pass15.c:3263 Passive15_0171 */
void Passive15_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 191, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
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



/* 2i 06074BBA, 3s-near: sf3 src/pass15.c:3288 Passive15_0172 */
void Passive15_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06074C64, 3s-near: sf3 src/pass15.c:3310 Passive15_0173 */
void Passive15_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06074D06, 3s-near: sf3 src/pass15.c:3338 Passive15_0174 */
void Passive15_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
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



/* 2i 06074DC2, 3s-near: sf3 src/pass15.c:3360 Passive15_0175 */
void Passive15_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, (0x102), 0, 32896, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
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



/* 2i 06074E7C, 3s-near: sf3 src/pass15.c:3385 Passive15_0176 */
void Passive15_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
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



/* 2i 06074F0A, 3s-near: sf3 src/pass15.c:3407 Passive15_0177 */
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



/* 2i 06074F44, 3s-near: sf3 src/pass15.c:3420 Passive15_0178 */
void Passive15_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 3:
        Command_Attack(wk, 12, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06074FE6, 3s-near: sf3 src/pass15.c:3442 Passive15_0179 */
void Passive15_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 3:
        Command_Attack(wk, 11, 31, 10, (-1));
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



/* 2i 060750B4, 3s-near: sf3 src/pass15.c:3470 Passive15_0180 */
void Passive15_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
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



/* 2i 06075142, 3s-near: sf3 src/pass15.c:3492 Passive15_0181 */
void Passive15_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, (0x102), 0, 32896, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
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



/* 2i 06075204, 3s-near: sf3 src/pass15.c:3517 Passive15_0182 */
void Passive15_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
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



/* 2i 06075292, 3s-reloc: sf3 src/pass15.c:3539 Passive15_0183 */
void Passive15_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 9, (0x102), 0, 32896, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
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



/* 2i 06075348, 3s-reloc: sf3 src/pass15.c:3564 Passive15_0184 */
void Passive15_0184(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Command_Attack(wk, 11, 31, 10, none);
        break;
    case 2:
        Wait(wk, 1);
        break;
    case 3:
        SA_Term(wk, 47, none, none, none);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060753B0, 3s-reloc: sf3 src/pass15.c:3587 Passive15_0185 */
void Passive15_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 2:
        Command_Attack(wk, 11, 31, 10, (-1));
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



/* 2i 0607546A, 3s-reloc: sf3 src/pass15.c:3612 Passive15_0186 */
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



/* 2i 060754B4, 3s-near: sf3 src/pass15.c:3628 Passive15_0187 */
void Passive15_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 2:
        Command_Attack(wk, 12, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06075556, 3s-near: sf3 src/pass15.c:3647 Passive15_0188 */
void Passive15_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 11, (0x102));
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



/* 2i 060755DC, 3s-near: sf3 src/pass15.c:3669 Passive15_0189 */
void Passive15_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 32896, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 11, (0x102));
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



/* 2i 0607568C, 3s-near: sf3 src/pass15.c:3691 Passive15_0190 */
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



/* 2i 060756D6, 3s-near: sf3 src/pass15.c:3707 Passive15_0191 */
void Passive15_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 97, 11, (0x102), 0, 32896, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 11, (0x102));
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



/* 2i 06075794, 3s-near: sf3 src/pass15.c:3732 Passive15_0192 */
void Passive15_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 0xB, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
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



/* 2i 06075834, 3s-reloc: sf3 src/pass15.c:3763 Passive15_0193 */
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



/* 2i 060758B4, 3s-near: sf3 src/pass15.c:3779 Passive15_0194 */
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



/* 2i 060758F0, 3s-near: sf3 src/pass15.c:3792 Passive15_0195 */
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



/* 2i 0607592C, 3s-reloc: sf3 src/pass15.c:3805 Passive15_0196 */
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



/* 2i 06075988, 3s-reloc: sf3 src/pass15.c:3818 Passive15_0197 */
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



/* 2i 06075A50, 3s-reloc: sf3 src/pass15.c:3855 Passive15_0198 */
void Passive15_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06075AA0, 3s-reloc: sf3 src/pass15.c:3868 Passive15_0199 */
void Passive15_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, (0x1), 1);
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 127);
        break;
    case 2:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06075B04, 3s-near: sf3 src/pass15.c:3890 Passive15_0200 */
void Passive15_0200(PLW* wk) {
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



/* 2i 06075B6E, 3s-near: sf3 src/pass15.c:3909 Passive15_0201 */
void Passive15_0201(PLW* wk) {
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



/* 2i 06075C04, 3s-near: sf3 src/pass15.c:3928 Passive15_0202 */
void Passive15_0202(PLW* wk) {
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



/* 2i 06075C6E, 3s-near: sf3 src/pass15.c:3947 Passive15_0203 */
void Passive15_0203(PLW* wk) {
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



/* 2i 06075CF4, 3s-near: sf3 src/pass15.c:3966 Passive15_0204 */
void Passive15_0204(PLW* wk) {
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



/* 2i 06075D44, 3s-near: sf3 src/pass15.c:3982 Passive15_0205 */
void Passive15_0205(PLW* wk) {
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



/* 2i 06075D94, 3s-reloc: sf3 src/pass15.c:3998 Passive15_0206 */
void Passive15_0206(PLW* wk) {
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



/* 2i 06075DE4, 3s-reloc: sf3 src/pass15.c:4014 Passive15_0207 */
void Passive15_0207(PLW* wk) {
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



/* 2i 06075E34, 3s-reloc: sf3 src/pass15.c:4030 Passive15_0208 */
void Passive15_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 181, 3);
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



/* 2i 06075EBA, 3s-reloc: sf3 src/pass15.c:4049 Passive15_0209 */
void Passive15_0209(PLW* wk) {
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



/* 2i 06075F30, 3s-near: sf3 src/pass15.c:4068 Passive15_0210 */
void Passive15_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 173, 3);
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



/* 2i 06075FCC, 3s-reloc: sf3 src/pass15.c:4087 Passive15_0211 */
void Passive15_0211(PLW* wk) {
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



/* 2i 06076042, 3s-reloc: sf3 src/pass15.c:4106 Passive15_0212 */
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



/* 2i 060760B8, 3s-near: sf3 src/pass15.c:4122 Passive15_0213 */
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



/* 2i 0607610C, 3s-near: sf3 src/pass15.c:4138 Passive15_0214 */
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



/* 2i 06076160, 3s-near: sf3 src/pass15.c:4154 Passive15_0215 */
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



/* 2i 060761B4, 3s-near: sf3 src/pass15.c:4170 Passive15_0216 */
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



/* 2i 06076208, 3s-near: sf3 src/pass15.c:4186 Passive15_0217 */
void Passive15_0217(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060762A8, 3s-exact: sf3 src/pass15.c:4209 Passive15_0218 */
void Passive15_0218(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607632C, 3s-reloc: sf3 src/pass15.c:4232 Passive15_0219 */
void Passive15_0219(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060763D0, 3s-exact: sf3 src/pass15.c:4255 Passive15_0220 */
void Passive15_0220(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076454, 3s-reloc: sf3 src/pass15.c:4278 Passive15_0221 */
void Passive15_0221(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 768, 6, 225);
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



/* 2i 060764FC, 3s-reloc: sf3 src/pass15.c:4303 Passive15_0222 */
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



/* 2i 060765AC, 3s-exact: sf3 src/pass15.c:4328 Passive15_0223 */
void Passive15_0223(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 512, 6, 226);
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



/* 2i 06076634, 3s-reloc: sf3 src/pass15.c:4353 Passive15_0224 */
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



/* 2i 060766E4, 3s-exact: sf3 src/pass15.c:4378 Passive15_0225 */
void Passive15_0225(PLW* wk) {
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



/* 2i 0607675C, 3s-exact: sf3 src/pass15.c:4400 Passive15_0226 */
void Passive15_0226(PLW* wk) {
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



/* 2i 060767D4, 3s-exact: sf3 src/pass15.c:4422 Passive15_0227 */
void Passive15_0227(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 10, (-1));
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 71);
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



/* 2i 0607684C, 3s-reloc: sf3 src/pass15.c:4444 Passive15_0228 */
void Passive15_0228(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 28, 8, (-1));
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 71);
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



/* 2i 060768E0, 3s-exact: sf3 src/pass15.c:4466 Passive15_0229 */
void Passive15_0229(PLW* wk) {
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



/* 2i 06076958, 3s-exact: sf3 src/pass15.c:4488 Passive15_0230 */
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
        Normal_Attack(wk, 12, (0x40));
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        J_Command_Attack(wk, 8, 32, 8, (-1));
        break;
    case 6:
        Wait(wk, 3);
        break;
    case 7:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076A02, 3s-reloc: sf3 src/pass15.c:4522 Passive15_0231 */
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



/* 2i 06076AE2, 3s-exact: sf3 src/pass15.c:4556 Passive15_0232 */
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



/* 2i 06076B0C, 3s-exact: sf3 src/pass15.c:4572 Passive15_0233 */
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



/* 2i 06076B36, 3s-reloc: sf3 src/pass15.c:4588 Passive15_0234 */
void Passive15_0234(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, (0x1), 1);
        break;
    case 1:
        EM_Term(wk, -1, 32776, 6, 6, 1);
        break;
    case 2:
        Normal_Attack(wk, 12, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 31, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076BD0, 3s-exact: sf3 src/pass15.c:4610 Passive15_0235 */
void Passive15_0235(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 6, 1);
        break;
    case 1:
        SA_Term(wk, 47, 48, 49, 127);
        break;
    case 2:
        J_Command_Attack(wk, 8, 30, 8, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076C32, 3s-reloc: sf3 src/pass15.c:4629 Passive15_0236 */
void Passive15_0236(PLW* wk) {
    s16 next = 6;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8098, -1, next, next, 1);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 4, next, 235);
        break;
    case 2:
        Normal_Attack(wk, 12, (0x102));
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



/* 2i 06076CFC, 3s-exact: sf3 src/pass15.c:4658 Passive15_0237 */
void Passive15_0237(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 32896, -1, 6, 6, 1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 30, 10, (-1));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076D48, 3s-exact: sf3 src/pass15.c:4674 Passive15_0238 */
void Passive15_0238(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076D92, 3s-reloc: sf3 src/pass15.c:4693 Passive15_0239 */
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



/* 2i 06076DDC, 3s-exact: sf3 src/pass15.c:4706 Passive15_0240 */
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



/* 2i 06076E26, 3s-reloc: sf3 src/pass15.c:4722 Passive15_0241 */
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
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 4:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076EDC, 3s-exact: sf3 src/pass15.c:4747 Passive15_0242 */
void Passive15_0242(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06076F56, 3s-exact: sf3 src/pass15.c:4769 Passive15_0243 */
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



/* 2i 06076F90, 3s-reloc: sf3 src/pass15.c:4782 Passive15_0244 */
void Passive15_0244(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 4:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06077040, 3s-exact: sf3 src/pass15.c:4807 Passive15_0245 */
void Passive15_0245(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 4:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060770C6, 3s-reloc: sf3 src/pass15.c:4832 Passive15_0246 */
void Passive15_0246(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 4:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607716E, 3s-exact: sf3 src/pass15.c:4857 Passive15_0247 */
void Passive15_0247(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 87, 3);
        break;
    case 1:
        Wait_Get_Up(wk, (0x3), 0);
        break;
    case 2:
        Turn_Over_On(wk);
        break;
    case 3:
        Jump_Attack_Term(wk, -1, 73, 9, (0x102), 0, 32896, -1, (0x40));
        break;
    case 4:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060771F4, 3s-reloc: sf3 src/pass15.c:4882 Passive15_0248 */
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
