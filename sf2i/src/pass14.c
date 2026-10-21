/*
 * pass14.c  Computer AI passive patterns for character 14 (Gouki)
 *
 * Passive14 is the passive-mode entry for character number 14, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive14_Tbl; this file holds the 253 patterns
 * Passive14_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass14.h"



/* 2i 0606A074, 3s-exact: sf3 src/pass14.c:21 Passive14 */
void Passive14(PLW* wk) {
    Passive14_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0606A08C, 3s-exact: sf3 src/pass14.c:27 Passive14_0000 */
void Passive14_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606A0C0, 3s-exact: sf3 src/pass14.c:40 Passive14_0001 */
void Passive14_0001(PLW* wk) {
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



/* 2i 0606A0E8, 3s-exact: sf3 src/pass14.c:56 Passive14_0002 */
void Passive14_0002(PLW* wk) {
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



/* 2i 0606A13A, 3s-exact: sf3 src/pass14.c:75 Passive14_0003 */
void Passive14_0003(PLW* wk) {
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



/* 2i 0606A18C, 3s-reloc: sf3 src/pass14.c:94 Passive14_0004 */
void Passive14_0004(PLW* wk) {
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



/* 2i 0606A212, 3s-near: sf3 src/pass14.c:113 Passive14_0005 */
void Passive14_0005(PLW* wk) {
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



/* 2i 0606A266, 3s-near: sf3 src/pass14.c:132 Passive14_0006 */
void Passive14_0006(PLW* wk) {
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



/* 2i 0606A2BA, 3s-reloc: sf3 src/pass14.c:151 Passive14_0007 */
void Passive14_0007(PLW* wk) {
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



/* 2i 0606A32C, 3s-exact: sf3 src/pass14.c:170 Passive14_0008 */
void Passive14_0008(PLW* wk) {
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



/* 2i 0606A36C, 3s-exact: sf3 src/pass14.c:186 Passive14_0009 */
void Passive14_0009(PLW* wk) {
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



/* 2i 0606A3D4, 3s-exact: sf3 src/pass14.c:208 Passive14_0010 */
void Passive14_0010(PLW* wk) {
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



/* 2i 0606A452, 3s-reloc: sf3 src/pass14.c:233 Passive14_0011 */
void Passive14_0011(PLW* wk) {
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



/* 2i 0606A514, 3s-exact: sf3 src/pass14.c:264 Passive14_0012 */
void Passive14_0012(PLW* wk) {
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



/* 2i 0606A56E, 3s-exact: sf3 src/pass14.c:283 Passive14_0013 */
void Passive14_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8100, 6, 6, 0x7C);
        break;
    case 1:
        Command_Attack(wk, 8, 0x21, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606A5BA, 3s-exact: sf3 src/pass14.c:299 Passive14_0014 */
void Passive14_0014(PLW* wk) {
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



/* 2i 0606A606, 3s-reloc: sf3 src/pass14.c:315 Passive14_0015 */
void Passive14_0015(PLW* wk) {
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



/* 2i 0606A682, 3s-reloc: sf3 src/pass14.c:334 Passive14_0016 */
void Passive14_0016(PLW* wk) {
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



/* 2i 0606A764, 3s-exact: sf3 src/pass14.c:371 Passive14_0017 */
void Passive14_0017(PLW* wk) {
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



/* 2i 0606A7EE, 3s-exact: sf3 src/pass14.c:399 Passive14_0018 */
void Passive14_0018(PLW* wk) {
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



/* 2i 0606A856, 3s-exact: sf3 src/pass14.c:421 Passive14_0019 */
void Passive14_0019(PLW* wk) {
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
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606A8C4, 3s-exact: sf3 src/pass14.c:443 Passive14_0020 */
void Passive14_0020(PLW* wk) {
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



/* 2i 0606A916, 3s-reloc: sf3 src/pass14.c:462 Passive14_0021 */
void Passive14_0021(PLW* wk) {
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



/* 2i 0606A99A, 3s-exact: sf3 src/pass14.c:481 Passive14_0022 */
void Passive14_0022(PLW* wk) {
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



/* 2i 0606A9E6, 3s-reloc: sf3 src/pass14.c:497 Passive14_0023 */
void Passive14_0023(PLW* wk) {
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



/* 2i 0606AA78, 3s-reloc: sf3 src/pass14.c:516 Passive14_0024 */
void Passive14_0024(PLW* wk) {
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



/* 2i 0606AB02, 3s-near: sf3 src/pass14.c:541 Passive14_0025 */
void Passive14_0025(PLW* wk) {
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



/* 2i 0606AB72, 3s-near: sf3 src/pass14.c:563 Passive14_0026 */
void Passive14_0026(PLW* wk) {
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



/* 2i 0606AC08, 3s-near: sf3 src/pass14.c:585 Passive14_0027 */
void Passive14_0027(PLW* wk) {
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



/* 2i 0606AC70, 3s-near: sf3 src/pass14.c:607 Passive14_0028 */
void Passive14_0028(PLW* wk) {
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
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
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



/* 2i 0606AD3A, 3s-near: sf3 src/pass14.c:638 Passive14_0029 */
void Passive14_0029(PLW* wk) {
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



/* 2i 0606AE0C, 3s-near: sf3 src/pass14.c:669 Passive14_0030 */
void Passive14_0030(PLW* wk) {
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



/* 2i 0606AEBE, 3s-near: sf3 src/pass14.c:703 Passive14_0031 */
void Passive14_0031(PLW* wk) {
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
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606AF6C, 3s-near: sf3 src/pass14.c:728 Passive14_0032 */
void Passive14_0032(PLW* wk) {
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



/* 2i 0606AFD4, 3s-near: sf3 src/pass14.c:750 Passive14_0033 */
void Passive14_0033(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B080, 3s-reloc: sf3 src/pass14.c:775 Passive14_0034 */
void Passive14_0034(PLW* wk) {
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



/* 2i 0606B140, 3s-reloc: sf3 src/pass14.c:803 Passive14_0035 */
void Passive14_0035(PLW* wk) {
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



/* 2i 0606B210, 3s-exact: sf3 src/pass14.c:843 Passive14_0036 */
void Passive14_0036(PLW* wk) {
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



/* 2i 0606B258, 3s-exact: sf3 src/pass14.c:859 Passive14_0037 */
void Passive14_0037(PLW* wk) {
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



/* 2i 0606B2BA, 3s-exact: sf3 src/pass14.c:878 Passive14_0038 */
void Passive14_0038(PLW* wk) {
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



/* 2i 0606B302, 3s-exact: sf3 src/pass14.c:894 Passive14_0039 */
void Passive14_0039(PLW* wk) {
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



/* 2i 0606B364, 3s-reloc: sf3 src/pass14.c:913 Passive14_0040 */
void Passive14_0040(PLW* wk) {
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



/* 2i 0606B3EA, 3s-exact: sf3 src/pass14.c:932 Passive14_0041 */
void Passive14_0041(PLW* wk) {
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



/* 2i 0606B452, 3s-exact: sf3 src/pass14.c:954 Passive14_0042 */
void Passive14_0042(PLW* wk) {
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



/* 2i 0606B494, 3s-reloc: sf3 src/pass14.c:970 Passive14_0043 */
void Passive14_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, 0x100, 2, 0x8060, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B4FA, 3s-exact: sf3 src/pass14.c:983 Passive14_0044 */
void Passive14_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, 0x200, 2, 0x8060, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B53C, 3s-reloc: sf3 src/pass14.c:996 Passive14_0045 */
void Passive14_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 10, -1, -1, 0x10, 2, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x31, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B5DC, 3s-exact: sf3 src/pass14.c:1018 Passive14_0046 */
void Passive14_0046(PLW* wk) {
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



/* 2i 0606B66E, 3s-reloc: sf3 src/pass14.c:1046 Passive14_0047 */
void Passive14_0047(PLW* wk) {
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
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
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



/* 2i 0606B726, 3s-exact: sf3 src/pass14.c:1074 Passive14_0048 */
void Passive14_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8080, 0x20, 8, 0x200, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B768, 3s-exact: sf3 src/pass14.c:1087 Passive14_0049 */
void Passive14_0049(PLW* wk) {
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



/* 2i 0606B7AC, 3s-reloc: sf3 src/pass14.c:1103 Passive14_0050 */
void Passive14_0050(PLW* wk) {
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



/* 2i 0606B826, 3s-exact: sf3 src/pass14.c:1119 Passive14_0051 */
void Passive14_0051(PLW* wk) {
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



/* 2i 0606B882, 3s-exact: sf3 src/pass14.c:1138 Passive14_0052 */
void Passive14_0052(PLW* wk) {
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



/* 2i 0606B8AE, 3s-exact: sf3 src/pass14.c:1154 Passive14_0053 */
void Passive14_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B8CC, 3s-exact: sf3 src/pass14.c:1167 Passive14_0054 */
void Passive14_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B8EC, 3s-reloc: sf3 src/pass14.c:1180 Passive14_0055 */
void Passive14_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606B934, 3s-exact: sf3 src/pass14.c:1193 Passive14_0056 */
void Passive14_0056(PLW* wk) {
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



/* 2i 0606B960, 3s-exact: sf3 src/pass14.c:1209 Passive14_0057 */
void Passive14_0057(PLW* wk) {
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



/* 2i 0606B98E, 3s-exact: sf3 src/pass14.c:1225 Passive14_0058 */
void Passive14_0058(PLW* wk) {
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



/* 2i 0606B9BA, 3s-exact: sf3 src/pass14.c:1241 Passive14_0059 */
void Passive14_0059(PLW* wk) {
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



/* 2i 0606B9E8, 3s-reloc: sf3 src/pass14.c:1257 Passive14_0060 */
void Passive14_0060(PLW* wk) {
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



/* 2i 0606BA30, 3s-exact: sf3 src/pass14.c:1273 Passive14_0061 */
void Passive14_0061(PLW* wk) {
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



/* 2i 0606BA5C, 3s-exact: sf3 src/pass14.c:1289 Passive14_0062 */
void Passive14_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
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



/* 2i 0606BAAA, 3s-exact: sf3 src/pass14.c:1308 Passive14_0063 */
void Passive14_0063(PLW* wk) {
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



/* 2i 0606BAE2, 3s-reloc: sf3 src/pass14.c:1327 Passive14_0064 */
void Passive14_0064(PLW* wk) {
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



/* 2i 0606BB30, 3s-exact: sf3 src/pass14.c:1343 Passive14_0065 */
void Passive14_0065(PLW* wk) {
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



/* 2i 0606BB5C, 3s-exact: sf3 src/pass14.c:1359 Passive14_0066 */
void Passive14_0066(PLW* wk) {
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



/* 2i 0606BBAA, 3s-exact: sf3 src/pass14.c:1378 Passive14_0067 */
void Passive14_0067(PLW* wk) {
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



/* 2i 0606BBD6, 3s-reloc: sf3 src/pass14.c:1394 Passive14_0068 */
void Passive14_0068(PLW* wk) {
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



/* 2i 0606BC6E, 3s-exact: sf3 src/pass14.c:1416 Passive14_0069 */
void Passive14_0069(PLW* wk) {
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



/* 2i 0606BCC4, 3s-reloc: sf3 src/pass14.c:1435 Passive14_0070 */
void Passive14_0070(PLW* wk) {
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



/* 2i 0606BD44, 3s-exact: sf3 src/pass14.c:1454 Passive14_0071 */
void Passive14_0071(PLW* wk) {
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



/* 2i 0606BD7C, 3s-exact: sf3 src/pass14.c:1473 Passive14_0072 */
void Passive14_0072(PLW* wk) {
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



/* 2i 0606BDB6, 3s-reloc: sf3 src/pass14.c:1492 Passive14_0073 */
void Passive14_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 10, 7, 3, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606BE30, 3s-exact: sf3 src/pass14.c:1511 Passive14_0074 */
void Passive14_0074(PLW* wk) {
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



/* 2i 0606BE86, 3s-exact: sf3 src/pass14.c:1530 Passive14_0075 */
void Passive14_0075(PLW* wk) {
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



/* 2i 0606BEDC, 3s-exact: sf3 src/pass14.c:1549 Passive14_0076 */
void Passive14_0076(PLW* wk) {
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



/* 2i 0606BF32, 3s-reloc: sf3 src/pass14.c:1568 Passive14_0077 */
void Passive14_0077(PLW* wk) {
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



/* 2i 0606BFC2, 3s-exact: sf3 src/pass14.c:1590 Passive14_0078 */
void Passive14_0078(PLW* wk) {
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



/* 2i 0606BFFA, 3s-exact: sf3 src/pass14.c:1609 Passive14_0079 */
void Passive14_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606C02C, 3s-reloc: sf3 src/pass14.c:1622 Passive14_0080 */
void Passive14_0080(PLW* wk) {
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



/* 2i 0606C098, 3s-exact: sf3 src/pass14.c:1640 Passive14_0081 */
void Passive14_0081(PLW* wk) {
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



/* 2i 0606C120, 3s-reloc: sf3 src/pass14.c:1665 Passive14_0082 */
void Passive14_0082(PLW* wk) {
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



/* 2i 0606C1D0, 3s-exact: sf3 src/pass14.c:1690 Passive14_0083 */
void Passive14_0083(PLW* wk) {
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



/* 2i 0606C258, 3s-reloc: sf3 src/pass14.c:1715 Passive14_0084 */
void Passive14_0084(PLW* wk) {
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



/* 2i 0606C306, 3s-exact: sf3 src/pass14.c:1740 Passive14_0085 */
void Passive14_0085(PLW* wk) {
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



/* 2i 0606C368, 3s-reloc: sf3 src/pass14.c:1762 Passive14_0086 */
void Passive14_0086(PLW* wk) {
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



/* 2i 0606C3C0, 3s-exact: sf3 src/pass14.c:1778 Passive14_0087 */
void Passive14_0087(PLW* wk) {
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



/* 2i 0606C400, 3s-exact: sf3 src/pass14.c:1794 Passive14_0088 */
void Passive14_0088(PLW* wk) {
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



/* 2i 0606C440, 3s-exact: sf3 src/pass14.c:1810 Passive14_0089 */
void Passive14_0089(PLW* wk) {
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



/* 2i 0606C480, 3s-reloc: sf3 src/pass14.c:1826 Passive14_0090 */
void Passive14_0090(PLW* wk) {
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



/* 2i 0606C4D8, 3s-exact: sf3 src/pass14.c:1842 Passive14_0091 */
void Passive14_0091(PLW* wk) {
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



/* 2i 0606C52E, 3s-exact: sf3 src/pass14.c:1861 Passive14_0092 */
void Passive14_0092(PLW* wk) {
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



/* 2i 0606C584, 3s-reloc: sf3 src/pass14.c:1880 Passive14_0093 */
void Passive14_0093(PLW* wk) {
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



/* 2i 0606C5F2, 3s-near: sf3 src/pass14.c:1899 Passive14_0094 */
void Passive14_0094(PLW* wk) {
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



/* 2i 0606C652, 3s-near: sf3 src/pass14.c:1921 Passive14_0095 */
void Passive14_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
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



/* 2i 0606C6EC, 3s-near: sf3 src/pass14.c:1946 Passive14_0096 */
void Passive14_0096(PLW* wk) {
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



/* 2i 0606C764, 3s-reloc: sf3 src/pass14.c:1971 Passive14_0097 */
void Passive14_0097(PLW* wk) {
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



/* 2i 0606C7AC, 3s-reloc: sf3 src/pass14.c:1987 Passive14_0098 */
void Passive14_0098(PLW* wk) {
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



/* 2i 0606C7FE, 3s-near: sf3 src/pass14.c:2003 Passive14_0099 */
void Passive14_0099(PLW* wk) {
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



/* 2i 0606C82A, 3s-near: sf3 src/pass14.c:2019 Passive14_0100 */
void Passive14_0100(PLW* wk) {
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



/* 2i 0606C856, 3s-near: sf3 src/pass14.c:2035 Passive14_0101 */
void Passive14_0101(PLW* wk) {
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



/* 2i 0606C89C, 3s-near: sf3 src/pass14.c:2054 Passive14_0102 */
void Passive14_0102(PLW* wk) {
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



/* 2i 0606C8FA, 3s-exact: sf3 src/pass14.c:2073 Passive14_0103 */
void Passive14_0103(PLW* wk) {
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



/* 2i 0606C944, 3s-reloc: sf3 src/pass14.c:2092 Passive14_0104 */
void Passive14_0104(PLW* wk) {
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



/* 2i 0606C9CC, 3s-exact: sf3 src/pass14.c:2117 Passive14_0105 */
void Passive14_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CA0E, 3s-exact: sf3 src/pass14.c:2133 Passive14_0106 */
void Passive14_0106(PLW* wk) {
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



/* 2i 0606CA50, 3s-exact: sf3 src/pass14.c:2149 Passive14_0107 */
void Passive14_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CA6E, 3s-exact: sf3 src/pass14.c:2162 Passive14_0108 */
void Passive14_0108(PLW* wk) {
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



/* 2i 0606CA9A, 3s-exact: sf3 src/pass14.c:2178 Passive14_0109 */
void Passive14_0109(PLW* wk) {
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



/* 2i 0606CAC6, 3s-reloc: sf3 src/pass14.c:2194 Passive14_0110 */
void Passive14_0110(PLW* wk) {
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



/* 2i 0606CB0A, 3s-exact: sf3 src/pass14.c:2210 Passive14_0111 */
void Passive14_0111(PLW* wk) {
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



/* 2i 0606CB36, 3s-exact: sf3 src/pass14.c:2226 Passive14_0112 */
void Passive14_0112(PLW* wk) {
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



/* 2i 0606CB84, 3s-exact: sf3 src/pass14.c:2245 Passive14_0113 */
void Passive14_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x20, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CBCE, 3s-reloc: sf3 src/pass14.c:2258 Passive14_0114 */
void Passive14_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CC38, 3s-exact: sf3 src/pass14.c:2271 Passive14_0115 */
void Passive14_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 2, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CC82, 3s-exact: sf3 src/pass14.c:2284 Passive14_0116 */
void Passive14_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x20, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CCCC, 3s-reloc: sf3 src/pass14.c:2297 Passive14_0117 */
void Passive14_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CD28, 3s-exact: sf3 src/pass14.c:2310 Passive14_0118 */
void Passive14_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 0, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CD72, 3s-exact: sf3 src/pass14.c:2323 Passive14_0119 */
void Passive14_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x20, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CDBC, 3s-exact: sf3 src/pass14.c:2336 Passive14_0120 */
void Passive14_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -1, 0x20, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CE06, 3s-reloc: sf3 src/pass14.c:2349 Passive14_0121 */
void Passive14_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x20, 1, 0x8080, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CE62, 3s-reloc: sf3 src/pass14.c:2362 Passive14_0122 */
void Passive14_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CE9C, 3s-reloc: sf3 src/pass14.c:2375 Passive14_0123 */
void Passive14_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CED6, 3s-reloc: sf3 src/pass14.c:2388 Passive14_0124 */
void Passive14_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606CF10, 3s-reloc: sf3 src/pass14.c:2401 Passive14_0125 */
void Passive14_0125(PLW* wk) {
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



/* 2i 0606CF64, 3s-reloc: sf3 src/pass14.c:2417 Passive14_0126 */
void Passive14_0126(PLW* wk) {
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



/* 2i 0606CFB8, 3s-reloc: sf3 src/pass14.c:2433 Passive14_0127 */
void Passive14_0127(PLW* wk) {
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



/* 2i 0606D000, 3s-reloc: sf3 src/pass14.c:2449 Passive14_0128 */
void Passive14_0128(PLW* wk) {
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



/* 2i 0606D048, 3s-near: sf3 src/pass14.c:2465 Passive14_0129 */
void Passive14_0129(PLW* wk) {
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



/* 2i 0606D094, 3s-near: sf3 src/pass14.c:2481 Passive14_0130 */
void Passive14_0130(PLW* wk) {
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



/* 2i 0606D0C2, 3s-reloc: sf3 src/pass14.c:2497 Passive14_0131 */
void Passive14_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x81, 0x81, 0x82, 0x82, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D0FA, 3s-reloc: sf3 src/pass14.c:2510 Passive14_0132 */
void Passive14_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D12C, 3s-reloc: sf3 src/pass14.c:2523 Passive14_0133 */
void Passive14_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D15E, 3s-reloc: sf3 src/pass14.c:2536 Passive14_0134 */
void Passive14_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D1B0, 3s-reloc: sf3 src/pass14.c:2549 Passive14_0135 */
void Passive14_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D1E2, 3s-reloc: sf3 src/pass14.c:2562 Passive14_0136 */
void Passive14_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D214, 3s-reloc: sf3 src/pass14.c:2575 Passive14_0137 */
void Passive14_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D246, 3s-reloc: sf3 src/pass14.c:2588 Passive14_0138 */
void Passive14_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x84, 0x84, 0x85, 0x86, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D280, 3s-reloc: sf3 src/pass14.c:2601 Passive14_0139 */
void Passive14_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x87, 0x87, 0x88, 0x89, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D2D8, 3s-near: sf3 src/pass14.c:2614 Passive14_0140 */
void Passive14_0140(PLW* wk) {
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



/* 2i 0606D320, 3s-near: sf3 src/pass14.c:2630 Passive14_0141 */
void Passive14_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 10, 0x20, 9, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D368, 3s-near: sf3 src/pass14.c:2646 Passive14_0142 */
void Passive14_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 10, 0x20, 10, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D3B0, 3s-reloc: sf3 src/pass14.c:2662 Passive14_0143 */
void Passive14_0143(PLW* wk) {
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



/* 2i 0606D41A, 3s-exact: sf3 src/pass14.c:2678 Passive14_0144 */
void Passive14_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D44C, 3s-exact: sf3 src/pass14.c:2691 Passive14_0145 */
void Passive14_0145(PLW* wk) {
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



/* 2i 0606D49E, 3s-reloc: sf3 src/pass14.c:2707 Passive14_0146 */
void Passive14_0146(PLW* wk) {
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



/* 2i 0606D520, 3s-reloc: sf3 src/pass14.c:2723 Passive14_0147 */
void Passive14_0147(PLW* wk) {
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



/* 2i 0606D5C2, 3s-exact: sf3 src/pass14.c:2763 Passive14_0148 */
void Passive14_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 6, 0x76);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 10, -1, -1, 0x20, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D618, 3s-exact: sf3 src/pass14.c:2779 Passive14_0149 */
void Passive14_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x92, 0x92, 0x93, 0x94, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D652, 3s-near: sf3 src/pass14.c:2792 Passive14_0150 */
void Passive14_0150(PLW* wk) {
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



/* 2i 0606D6CC, 3s-reloc: sf3 src/pass14.c:2808 Passive14_0151 */
void Passive14_0151(PLW* wk) {
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



/* 2i 0606D784, 3s-reloc: sf3 src/pass14.c:2833 Passive14_0152 */
void Passive14_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 0xb, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xb, 0x1f, 0xa, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2f, 0x34, 0x34, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D81E, 3s-reloc: sf3 src/pass14.c:2861 Passive14_0153 */
void Passive14_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606D840, 3s-reloc: sf3 src/pass14.c:2874 Passive14_0154 */
void Passive14_0154(PLW* wk) {
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



/* 2i 0606D8B8, 3s-near: sf3 src/pass14.c:2890 Passive14_0155 */
void Passive14_0155(PLW* wk) {
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



/* 2i 0606D92E, 3s-near: sf3 src/pass14.c:2912 Passive14_0156 */
void Passive14_0156(PLW* wk) {
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



/* 2i 0606D9EC, 3s-reloc: sf3 src/pass14.c:2940 Passive14_0157 */
void Passive14_0157(PLW* wk) {
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



/* 2i 0606DA62, 3s-near: sf3 src/pass14.c:2962 Passive14_0158 */
void Passive14_0158(PLW* wk) {
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



/* 2i 0606DB40, 3s-near: sf3 src/pass14.c:2993 Passive14_0159 */
void Passive14_0159(PLW* wk) {
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



/* 2i 0606DBD0, 3s-near: sf3 src/pass14.c:3012 Passive14_0160 */
void Passive14_0160(PLW* wk) {
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



/* 2i 0606DC5A, 3s-reloc: sf3 src/pass14.c:3037 Passive14_0161 */
void Passive14_0161(PLW* wk) {
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



/* 2i 0606DCEC, 3s-near: sf3 src/pass14.c:3056 Passive14_0162 */
void Passive14_0162(PLW* wk) {
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



/* 2i 0606DD76, 3s-reloc: sf3 src/pass14.c:3081 Passive14_0163 */
void Passive14_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606DDA8, 3s-reloc: sf3 src/pass14.c:3094 Passive14_0164 */
void Passive14_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 2:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606DE44, 3s-reloc: sf3 src/pass14.c:3116 Passive14_0165 */
void Passive14_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 3, 0);
        break;
    case 2:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606DEB0, 3s-reloc: sf3 src/pass14.c:3138 Passive14_0166 */
void Passive14_0166(PLW* wk) {
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



/* 2i 0606DF24, 3s-near: sf3 src/pass14.c:3154 Passive14_0167 */
void Passive14_0167(PLW* wk) {
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



/* 2i 0606DFB2, 3s-near: sf3 src/pass14.c:3179 Passive14_0168 */
void Passive14_0168(PLW* wk) {
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



/* 2i 0606E08E, 3s-near: sf3 src/pass14.c:3210 Passive14_0169 */
void Passive14_0169(PLW* wk) {
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
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E160, 3s-reloc: sf3 src/pass14.c:3235 Passive14_0170 */
void Passive14_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 9, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x102);
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



/* 2i 0606E1FC, 3s-near: sf3 src/pass14.c:3263 Passive14_0171 */
void Passive14_0171(PLW* wk) {
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
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E2C2, 3s-near: sf3 src/pass14.c:3288 Passive14_0172 */
void Passive14_0172(PLW* wk) {
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



/* 2i 0606E36C, 3s-near: sf3 src/pass14.c:3310 Passive14_0173 */
void Passive14_0173(PLW* wk) {
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



/* 2i 0606E40E, 3s-near: sf3 src/pass14.c:3338 Passive14_0174 */
void Passive14_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E4CA, 3s-near: sf3 src/pass14.c:3360 Passive14_0175 */
void Passive14_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 9, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E584, 3s-near: sf3 src/pass14.c:3385 Passive14_0176 */
void Passive14_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
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



/* 2i 0606E612, 3s-near: sf3 src/pass14.c:3407 Passive14_0177 */
void Passive14_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x3F, 0x40, 0x41, 0x42, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E64C, 3s-near: sf3 src/pass14.c:3420 Passive14_0178 */
void Passive14_0178(PLW* wk) {
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



/* 2i 0606E6EE, 3s-near: sf3 src/pass14.c:3442 Passive14_0179 */
void Passive14_0179(PLW* wk) {
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



/* 2i 0606E7BC, 3s-near: sf3 src/pass14.c:3470 Passive14_0180 */
void Passive14_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E84A, 3s-near: sf3 src/pass14.c:3492 Passive14_0181 */
void Passive14_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 9, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606E90C, 3s-near: sf3 src/pass14.c:3517 Passive14_0182 */
void Passive14_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
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



/* 2i 0606E99A, 3s-reloc: sf3 src/pass14.c:3539 Passive14_0183 */
void Passive14_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 9, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606EA50, 3s-reloc: sf3 src/pass14.c:3564 Passive14_0184 */
void Passive14_0184(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 2:
        Wait(wk, 1);
        break;
    case 3:
        SA_Term(wk, 0x2F, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606EAB8, 3s-reloc: sf3 src/pass14.c:3586 Passive14_0185 */
void Passive14_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
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



/* 2i 0606EB72, 3s-reloc: sf3 src/pass14.c:3611 Passive14_0186 */
void Passive14_0186(PLW* wk) {
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



/* 2i 0606EBBC, 3s-near: sf3 src/pass14.c:3627 Passive14_0187 */
void Passive14_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
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



/* 2i 0606EC5E, 3s-near: sf3 src/pass14.c:3646 Passive14_0188 */
void Passive14_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606ECE4, 3s-near: sf3 src/pass14.c:3668 Passive14_0189 */
void Passive14_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, 0x200, 0, 0x8080, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
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



/* 2i 0606ED94, 3s-near: sf3 src/pass14.c:3690 Passive14_0190 */
void Passive14_0190(PLW* wk) {
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



/* 2i 0606EDDE, 3s-near: sf3 src/pass14.c:3706 Passive14_0191 */
void Passive14_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 0xB, 0x102, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 3:
        SA_Term(wk, 0x2F, 0x34, 0x34, 0x7F);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606EE9C, 3s-near: sf3 src/pass14.c:3731 Passive14_0192 */
void Passive14_0192(PLW* wk) {
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



/* 2i 0606EF3C, 3s-reloc: sf3 src/pass14.c:3762 Passive14_0193 */
void Passive14_0193(PLW* wk) {
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



/* 2i 0606EFBC, 3s-near: sf3 src/pass14.c:3778 Passive14_0194 */
void Passive14_0194(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606EFF8, 3s-near: sf3 src/pass14.c:3791 Passive14_0195 */
void Passive14_0195(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F034, 3s-reloc: sf3 src/pass14.c:3804 Passive14_0196 */
void Passive14_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F090, 3s-reloc: sf3 src/pass14.c:3817 Passive14_0197 */
void Passive14_0197(PLW* wk) {
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



/* 2i 0606F158, 3s-reloc: sf3 src/pass14.c:3854 Passive14_0198 */
void Passive14_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F1A8, 3s-reloc: sf3 src/pass14.c:3867 Passive14_0199 */
void Passive14_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 1, 1);
        break;
    case 1:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
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



/* 2i 0606F20C, 3s-near: sf3 src/pass14.c:3889 Passive14_0200 */
void Passive14_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F276, 3s-near: sf3 src/pass14.c:3908 Passive14_0201 */
void Passive14_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F30C, 3s-near: sf3 src/pass14.c:3927 Passive14_0202 */
void Passive14_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F376, 3s-near: sf3 src/pass14.c:3946 Passive14_0203 */
void Passive14_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F3FC, 3s-near: sf3 src/pass14.c:3965 Passive14_0204 */
void Passive14_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F44C, 3s-near: sf3 src/pass14.c:3981 Passive14_0205 */
void Passive14_0205(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F49C, 3s-reloc: sf3 src/pass14.c:3997 Passive14_0206 */
void Passive14_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F4EC, 3s-reloc: sf3 src/pass14.c:4013 Passive14_0207 */
void Passive14_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F53C, 3s-reloc: sf3 src/pass14.c:4029 Passive14_0208 */
void Passive14_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB5, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 10, -1, 0x80A0, 0x50, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F5C2, 3s-reloc: sf3 src/pass14.c:4048 Passive14_0209 */
void Passive14_0209(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 10, -1, 0x80A0, 0x50, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F638, 3s-near: sf3 src/pass14.c:4067 Passive14_0210 */
void Passive14_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xAD, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 10, -1, 0x80A0, 0x50, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F6D4, 3s-reloc: sf3 src/pass14.c:4086 Passive14_0211 */
void Passive14_0211(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 10, -1, 0x80A0, 0x50, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F74A, 3s-reloc: sf3 src/pass14.c:4105 Passive14_0212 */
void Passive14_0212(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F7C0, 3s-near: sf3 src/pass14.c:4121 Passive14_0213 */
void Passive14_0213(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F814, 3s-near: sf3 src/pass14.c:4137 Passive14_0214 */
void Passive14_0214(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F868, 3s-near: sf3 src/pass14.c:4153 Passive14_0215 */
void Passive14_0215(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F8BC, 3s-near: sf3 src/pass14.c:4169 Passive14_0216 */
void Passive14_0216(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F910, 3s-near: sf3 src/pass14.c:4185 Passive14_0217 */
void Passive14_0217(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606F9B0, 3s-exact: sf3 src/pass14.c:4207 Passive14_0218 */
void Passive14_0218(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FA34, 3s-reloc: sf3 src/pass14.c:4229 Passive14_0219 */
void Passive14_0219(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FAD8, 3s-exact: sf3 src/pass14.c:4251 Passive14_0220 */
void Passive14_0220(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FB5C, 3s-reloc: sf3 src/pass14.c:4273 Passive14_0221 */
void Passive14_0221(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x300, 6, 0xE1);
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



/* 2i 0606FC04, 3s-reloc: sf3 src/pass14.c:4298 Passive14_0222 */
void Passive14_0222(PLW* wk) {
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



/* 2i 0606FCB4, 3s-exact: sf3 src/pass14.c:4323 Passive14_0223 */
void Passive14_0223(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x200, 6, 0xE2);
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



/* 2i 0606FD3C, 3s-reloc: sf3 src/pass14.c:4348 Passive14_0224 */
void Passive14_0224(PLW* wk) {
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



/* 2i 0606FDEC, 3s-exact: sf3 src/pass14.c:4373 Passive14_0225 */
void Passive14_0225(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FE64, 3s-exact: sf3 src/pass14.c:4395 Passive14_0226 */
void Passive14_0226(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FEDC, 3s-exact: sf3 src/pass14.c:4417 Passive14_0227 */
void Passive14_0227(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 1:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FF54, 3s-reloc: sf3 src/pass14.c:4439 Passive14_0228 */
void Passive14_0228(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 1:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606FFE8, 3s-exact: sf3 src/pass14.c:4461 Passive14_0229 */
void Passive14_0229(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 8, -1);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070060, 3s-exact: sf3 src/pass14.c:4483 Passive14_0230 */
void Passive14_0230(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
        break;
    case 1:
        Check_SA_Full(wk, 6, 0x11);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
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



/* 2i 0607010A, 3s-reloc: sf3 src/pass14.c:4517 Passive14_0231 */
void Passive14_0231(PLW* wk) {
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



/* 2i 060701EA, 3s-exact: sf3 src/pass14.c:4551 Passive14_0232 */
void Passive14_0232(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Look(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070214, 3s-exact: sf3 src/pass14.c:4567 Passive14_0233 */
void Passive14_0233(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607023E, 3s-reloc: sf3 src/pass14.c:4583 Passive14_0234 */
void Passive14_0234(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 1, 1);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 6, 1);
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



/* 2i 060702D8, 3s-exact: sf3 src/pass14.c:4605 Passive14_0235 */
void Passive14_0235(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 6, 1);
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



/* 2i 0607033A, 3s-reloc: sf3 src/pass14.c:4624 Passive14_0236 */
void Passive14_0236(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8098, -1, 6, 6, 1);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 4, 6, 0xEB);
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



/* 2i 06070404, 3s-exact: sf3 src/pass14.c:4652 Passive14_0237 */
void Passive14_0237(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 6, 1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070450, 3s-exact: sf3 src/pass14.c:4668 Passive14_0238 */
void Passive14_0238(PLW* wk) {
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



/* 2i 0607049A, 3s-reloc: sf3 src/pass14.c:4687 Passive14_0239 */
void Passive14_0239(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060704E4, 3s-exact: sf3 src/pass14.c:4700 Passive14_0240 */
void Passive14_0240(PLW* wk) {
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



/* 2i 0607052E, 3s-reloc: sf3 src/pass14.c:4716 Passive14_0241 */
void Passive14_0241(PLW* wk) {
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



/* 2i 060705E4, 3s-exact: sf3 src/pass14.c:4741 Passive14_0242 */
void Passive14_0242(PLW* wk) {
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



/* 2i 0607065E, 3s-exact: sf3 src/pass14.c:4763 Passive14_0243 */
void Passive14_0243(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x26, 0x27, 0x28, 0x29, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070698, 3s-reloc: sf3 src/pass14.c:4776 Passive14_0244 */
void Passive14_0244(PLW* wk) {
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
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070748, 3s-exact: sf3 src/pass14.c:4801 Passive14_0245 */
void Passive14_0245(PLW* wk) {
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
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060707CE, 3s-reloc: sf3 src/pass14.c:4826 Passive14_0246 */
void Passive14_0246(PLW* wk) {
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
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06070876, 3s-exact: sf3 src/pass14.c:4851 Passive14_0247 */
void Passive14_0247(PLW* wk) {
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
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060708FC, 3s-reloc: sf3 src/pass14.c:4876 Passive14_0248 */
void Passive14_0248(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

