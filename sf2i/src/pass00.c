/*
 * pass00.c  Computer AI passive patterns for character 0 (Gill)
 *
 * Passive00 is the passive-mode entry for character number 0, called from Com_Passive in
 * Com_Pl.c (after the damage, caught and flip checks) through Passive_Jmp_Tbl. It runs the
 * pattern chosen in Pattern_Index through Passive00_Tbl; this file holds the 149 patterns
 * Passive00_0000 onward. Each pattern is a short script: a switch on the pattern step
 * (CP_Index) that issues one AI command per step from Com_Sub - Normal_Attack, Command_Attack,
 * Approach_Walk, Wait_Get_Up, Com_Random_Select and the like - and ends with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "pass00.h"



/* 2i 0603D0B4, 3s-exact: sf3 src/pass00.c:21 Passive00 */
void Passive00(PLW* wk) {
    Passive00_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0603D0CC, 3s-exact: sf3 src/pass00.c:27 Passive00_0000 */
void Passive00_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D100, 3s-exact: sf3 src/pass00.c:40 Passive00_0001 */
void Passive00_0001(PLW* wk) {
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



/* 2i 0603D128, 3s-exact: sf3 src/pass00.c:56 Passive00_0002 */
void Passive00_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;
    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D192, 3s-reloc: sf3 src/pass00.c:78 Passive00_0003 */
void Passive00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D1E8, 3s-exact: sf3 src/pass00.c:91 Passive00_0004 */
void Passive00_0004(PLW* wk) {
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



/* 2i 0603D22A, 3s-exact: sf3 src/pass00.c:107 Passive00_0005 */
void Passive00_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D248, 3s-exact: sf3 src/pass00.c:120 Passive00_0006 */
void Passive00_0006(PLW* wk) {
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



/* 2i 0603D28C, 3s-exact: sf3 src/pass00.c:136 Passive00_0007 */
void Passive00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D2BE, 3s-reloc: sf3 src/pass00.c:149 Passive00_0008 */
void Passive00_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D32E, 3s-near: sf3 src/pass00.c:168 Passive00_0009 (2i steps differ) */
void Passive00_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x8A);
        break;
    case 1:
        EM_Term(wk, -1, 0x38, 7, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D38C, 3s-reloc: sf3 src/pass00.c:184 Passive00_0010 */
void Passive00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D3BE, 3s-reloc: sf3 src/pass00.c:197 Passive00_0011 */
void Passive00_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D414, 3s-reloc: sf3 src/pass00.c:210 Passive00_0012 */
void Passive00_0012(PLW* wk) {
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



/* 2i 0603D45E, 3s-reloc: sf3 src/pass00.c:226 Passive00_0013 */
void Passive00_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D4B4, 3s-reloc: sf3 src/pass00.c:248 Passive00_0014 */
void Passive00_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D4D4, 3s-reloc: sf3 src/pass00.c:261 Passive00_0015 */
void Passive00_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D510, 3s-reloc: sf3 src/pass00.c:274 Passive00_0016 */
void Passive00_0016(PLW* wk) {
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
        Normal_Attack(wk, 0xB, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D554, 3s-reloc: sf3 src/pass00.c:296 Passive00_0017 */
void Passive00_0017(PLW* wk) {
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



/* 2i 0603D5BA, 3s-reloc: sf3 src/pass00.c:321 Passive00_0018 */
void Passive00_0018(PLW* wk) {
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
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D61A, 3s-near: sf3 src/pass00.c:343 Passive00_0019 (2i steps differ) */
void Passive00_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D63A, 3s-reloc: sf3 src/pass00.c:356 Passive00_0020 */
void Passive00_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D65A, 3s-reloc: sf3 src/pass00.c:369 Passive00_0021 */
void Passive00_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D6AC, 3s-reloc: sf3 src/pass00.c:391 Passive00_0022 */
void Passive00_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Check_BOSS(wk, 6, 0x17);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, 0x40, 0, 0x8070, -1, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D746, 3s-near: sf3 src/pass00.c:416 Passive00_0023 (2i steps differ) */
void Passive00_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, 0x10, 0, 0x8070, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D7B4, 3s-reloc: sf3 src/pass00.c:438 Passive00_0024 */
void Passive00_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D7E0, 3s-reloc: sf3 src/pass00.c:454 Passive00_0025 */
void Passive00_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D864, 3s-reloc: sf3 src/pass00.c:476 Passive00_0026 */
void Passive00_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D884, 3s-reloc: sf3 src/pass00.c:489 Passive00_0027 */
void Passive00_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8060, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D8D8, 3s-near: sf3 src/pass00.c:508 Passive00_0028 (2i steps differ) */
void Passive00_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D90A, 3s-reloc: sf3 src/pass00.c:521 Passive00_0029 */
void Passive00_0029(PLW* wk) {
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



/* 2i 0603D942, 3s-reloc: sf3 src/pass00.c:540 Passive00_0030 */
void Passive00_0030(PLW* wk) {
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



/* 2i 0603D988, 3s-reloc: sf3 src/pass00.c:556 Passive00_0031 */
void Passive00_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603D9AA, 3s-reloc: sf3 src/pass00.c:569 Passive00_0032 */
void Passive00_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DA06, 3s-near: sf3 src/pass00.c:585 Passive00_0033 (2i steps differ) */
void Passive00_0033(PLW* wk) {
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



/* 2i 0603DA34, 3s-reloc: sf3 src/pass00.c:601 Passive00_0034 */
void Passive00_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DA54, 3s-reloc: sf3 src/pass00.c:614 Passive00_0035 */
void Passive00_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DA9A, 3s-near: sf3 src/pass00.c:633 Passive00_0036 (2i steps differ) */
void Passive00_0036(PLW* wk) {
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
        Check_BOSS(wk, 6, 0x88);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DB34, 3s-near: sf3 src/pass00.c:658 Passive00_0037 (2i steps differ) */
void Passive00_0037(PLW* wk) {
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



/* 2i 0603DB88, 3s-near: sf3 src/pass00.c:677 Passive00_0038 (2i steps differ) */
void Passive00_0038(PLW* wk) {
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



/* 2i 0603DC00, 3s-reloc: sf3 src/pass00.c:693 Passive00_0039 */
void Passive00_0039(PLW* wk) {
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



/* 2i 0603DC52, 3s-reloc: sf3 src/pass00.c:712 Passive00_0040 */
void Passive00_0040(PLW* wk) {
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
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DCB8, 3s-reloc: sf3 src/pass00.c:737 Passive00_0041 */
void Passive00_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DD30, 3s-reloc: sf3 src/pass00.c:756 Passive00_0042 */
void Passive00_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 0, 0x8070, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DD72, 3s-reloc: sf3 src/pass00.c:769 Passive00_0043 */
void Passive00_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x1B);
        break;
    case 1:
        EM_Term(wk, 0x8080, 0x8050, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DDC6, 3s-reloc: sf3 src/pass00.c:788 Passive00_0044 */
void Passive00_0044(PLW* wk) {
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



/* 2i 0603DE40, 3s-reloc: sf3 src/pass00.c:804 Passive00_0045 */
void Passive00_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x1B);
        break;
    case 1:
        EM_Term(wk, -1, 0x8070, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DE9E, 3s-reloc: sf3 src/pass00.c:823 Passive00_0046 */
void Passive00_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DEBE, 3s-reloc: sf3 src/pass00.c:836 Passive00_0047 */
void Passive00_0047(PLW* wk) {
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



/* 2i 0603DEE8, 3s-reloc: sf3 src/pass00.c:852 Passive00_0048 */
void Passive00_0048(PLW* wk) {
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



/* 2i 0603DF5A, 3s-reloc: sf3 src/pass00.c:871 Passive00_0049 */
void Passive00_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603DF7A, 3s-reloc: sf3 src/pass00.c:884 Passive00_0050 */
void Passive00_0050(PLW* wk) {
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



/* 2i 0603DFA6, 3s-near: sf3 src/pass00.c:900 Passive00_0051 (2i steps differ) */
void Passive00_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x2F);
        break;
    case 1:
        J_Command_Attack(wk, 0xB, 0xE, 0xA, -1);
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



/* 2i 0603DFFE, 3s-reloc: sf3 src/pass00.c:919 Passive00_0052 */
void Passive00_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E01E, 3s-reloc: sf3 src/pass00.c:932 Passive00_0053 */
void Passive00_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E06E, 3s-reloc: sf3 src/pass00.c:945 Passive00_0054 */
void Passive00_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
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



/* 2i 0603E09E, 3s-reloc: sf3 src/pass00.c:964 Passive00_0055 */
void Passive00_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E0C0, 3s-reloc: sf3 src/pass00.c:977 Passive00_0056 */
void Passive00_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8058, 8, 0x80, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E102, 3s-reloc: sf3 src/pass00.c:990 Passive00_0057 */
void Passive00_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8058, 8, 0x10, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E16C, 3s-reloc: sf3 src/pass00.c:1003 Passive00_0058 */
void Passive00_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E18C, 3s-reloc: sf3 src/pass00.c:1016 Passive00_0059 */
void Passive00_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x34);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E1BA, 3s-reloc: sf3 src/pass00.c:1032 Passive00_0060 */
void Passive00_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E1D8, 3s-near: sf3 src/pass00.c:1045 Passive00_0061 (2i steps differ) */
void Passive00_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x88);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E218, 3s-near: sf3 src/pass00.c:1061 Passive00_0062 (2i steps differ) */
void Passive00_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E23A, 3s-reloc: sf3 src/pass00.c:1074 Passive00_0063 */
void Passive00_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E296, 3s-reloc: sf3 src/pass00.c:1087 Passive00_0064 */
void Passive00_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E2B8, 3s-near: sf3 src/pass00.c:1100 Passive00_0065 (2i steps differ) */
void Passive00_0065(PLW* wk) {
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



/* 2i 0603E2E6, 3s-near: sf3 src/pass00.c:1116 Passive00_0066 (2i steps differ) */
void Passive00_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 6, 6);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E328, 3s-reloc: sf3 src/pass00.c:1132 Passive00_0067 */
void Passive00_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E35A, 3s-reloc: sf3 src/pass00.c:1145 Passive00_0068 */
void Passive00_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5a, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E398, 3s-reloc: sf3 src/pass00.c:1158 Passive00_0069 */
void Passive00_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E3EA, 3s-near: sf3 src/pass00.c:1177 Passive00_0070 (2i steps differ) */
void Passive00_0070(PLW* wk) {
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



/* 2i 0603E43C, 3s-near: sf3 src/pass00.c:1193 Passive00_0071 (2i steps differ) */
void Passive00_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        Check_BOSS(wk, 6, 0x2F);
        break;
    case 2:
        J_Command_Attack(wk, 0xB, 0xE, 0xA, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E4A2, 3s-reloc: sf3 src/pass00.c:1215 Passive00_0072 */
void Passive00_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E4EC, 3s-reloc: sf3 src/pass00.c:1234 Passive00_0073 */
void Passive00_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 8, 0x200, 0, 0x8070, -1, 0x20);
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



/* 2i 0603E56E, 3s-reloc: sf3 src/pass00.c:1253 Passive00_0074 */
void Passive00_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E5B4, 3s-near: sf3 src/pass00.c:1272 Passive00_0075 (2i steps differ) */
void Passive00_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 2:
        Check_BOSS(wk, 6, 0xE);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E630, 3s-near: sf3 src/pass00.c:1291 Passive00_0076 (2i steps differ) */
void Passive00_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB1, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8040, 8, (0x200), 0, 0x8070, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 3:
        Check_BOSS(wk, 6, 0xE);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E6C4, 3s-near: sf3 src/pass00.c:1316 Passive00_0077 (2i steps differ) */
void Passive00_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, 0x40, 0, 0x8070, -1, 0x100);
        break;
    case 1:
        Check_BOSS(wk, 6, 0xE);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E74C, 3s-exact: sf3 src/pass00.c:1332 Passive00_0078 */
void Passive00_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, 0x200, 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E7B8, 3s-exact: sf3 src/pass00.c:1354 Passive00_0079 */
void Passive00_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, 0x40, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E80A, 3s-reloc: sf3 src/pass00.c:1370 Passive00_0080 */
void Passive00_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x40, 0, 0x8070, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E882, 3s-exact: sf3 src/pass00.c:1389 Passive00_0081 */
void Passive00_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x200, 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E8DC, 3s-reloc: sf3 src/pass00.c:1408 Passive00_0082 */
void Passive00_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, 0x40, 0, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E950, 3s-near: sf3 src/pass00.c:1424 Passive00_0083 (2i steps differ) */
void Passive00_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x200), 0, 0x8070, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 3:
        Check_BOSS(wk, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603E9D4, 3s-near: sf3 src/pass00.c:1446 Passive00_0084 (2i steps differ) */
void Passive00_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8060, 0xB, (0x200), 0, 0x8070, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Check_BOSS(wk, 6, 0x88);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603EA7E, 3s-reloc: sf3 src/pass00.c:1468 Passive00_0085 */
void Passive00_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 8);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603EABC, 3s-reloc: sf3 src/pass00.c:1484 Passive00_0086 */
void Passive00_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x49);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603EB44, 3s-reloc: sf3 src/pass00.c:1512 Passive00_0087 */
void Passive00_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x49);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 10, -1);
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



/* 2i 0603EBE4, 3s-near: sf3 src/pass00.c:1543 Passive00_0088 (2i steps differ) */
void Passive00_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xB1, 2);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, (0x200), 0, 0x8070, -1, (0x100));
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        Check_BOSS(wk, 6, 0xE);
        break;
    case 5:
        J_Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 6:
        ETC_Term(wk, 2, 6, 1);
        break;
    case 7:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603ECCC, 3s-reloc: sf3 src/pass00.c:1574 Passive00_0089 */
void Passive00_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603ECFE, 3s-reloc: sf3 src/pass00.c:1587 Passive00_0090 */
void Passive00_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603ED30, 3s-reloc: sf3 src/pass00.c:1600 Passive00_0091 */
void Passive00_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603ED94, 3s-exact: sf3 src/pass00.c:1613 Passive00_0092 */
void Passive00_0092(PLW* wk) {
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



/* 2i 0603EDE2, 3s-exact: sf3 src/pass00.c:1629 Passive00_0093 */
void Passive00_0093(PLW* wk) {
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



/* 2i 0603EE06, 3s-exact: sf3 src/pass00.c:1645 Passive00_0094 */
void Passive00_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603EE40, 3s-reloc: sf3 src/pass00.c:1658 Passive00_0095 */
void Passive00_0095(PLW* wk) {
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



/* 2i 0603EEB4, 3s-exact: sf3 src/pass00.c:1674 Passive00_0096 */
void Passive00_0096(PLW* wk) {
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



/* 2i 0603EEF8, 3s-near: sf3 src/pass00.c:1690 Passive00_0097 (2i steps differ) */
void Passive00_0097(PLW* wk) {
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



/* 2i 0603EF4C, 3s-reloc: sf3 src/pass00.c:1709 Passive00_0098 */
void Passive00_0098(PLW* wk) {
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
        Check_BOSS(wk, 6, 0xe);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1f, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603EFF8, 3s-near: sf3 src/pass00.c:1737 Passive00_0099 (2i steps differ) */
void Passive00_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 2:
        Check_BOSS(wk, 6, 0xE);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F050, 3s-reloc: sf3 src/pass00.c:1756 Passive00_0100 */
void Passive00_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Check_BOSS(wk, 6, 0x88);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F0C0, 3s-reloc: sf3 src/pass00.c:1775 Passive00_0101 */
void Passive00_0101(PLW* wk) {
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



/* 2i 0603F108, 3s-reloc: sf3 src/pass00.c:1791 Passive00_0102 */
void Passive00_0102(PLW* wk) {
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



/* 2i 0603F156, 3s-near: sf3 src/pass00.c:1807 Passive00_0103 (2i steps differ) */
void Passive00_0103(PLW* wk) {
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



/* 2i 0603F192, 3s-reloc: sf3 src/pass00.c:1826 Passive00_0104 */
void Passive00_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F1B2, 3s-reloc: sf3 src/pass00.c:1839 Passive00_0105 */
void Passive00_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F20C, 3s-near: sf3 src/pass00.c:1861 Passive00_0106 (2i steps differ) */
void Passive00_0106(PLW* wk) {
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



/* 2i 0603F248, 3s-reloc: sf3 src/pass00.c:1880 Passive00_0107 */
void Passive00_0107(PLW* wk) {
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



/* 2i 0603F29E, 3s-reloc: sf3 src/pass00.c:1902 Passive00_0108 */
void Passive00_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBB, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F2EE, 3s-reloc: sf3 src/pass00.c:1915 Passive00_0109 */
void Passive00_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8070, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F35A, 3s-near: sf3 src/pass00.c:1937 Passive00_0110 (2i steps differ) */
void Passive00_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x89);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F39A, 3s-reloc: sf3 src/pass00.c:1950 Passive00_0111 */
void Passive00_0111(PLW* wk) {
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



/* 2i 0603F41C, 3s-near: sf3 src/pass00.c:1969 Passive00_0112 (2i steps differ) */
void Passive00_0112(PLW* wk) {
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
        Check_BOSS(wk, 6, 0x88);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F496, 3s-reloc: sf3 src/pass00.c:1991 Passive00_0113 */
void Passive00_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x70);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        EM_Term(wk, -1, 0x8058, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F53E, 3s-near: sf3 src/pass00.c:2019 Passive00_0114 (2i steps differ) */
void Passive00_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x30, 7, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;
    case 3:
        Check_BOSS(wk, 6, 0xE);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F5AC, 3s-near: sf3 src/pass00.c:2041 Passive00_0115 (2i steps differ) */
void Passive00_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x70);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;
    case 5:
        ETC_Term(wk, 2, 6, 1);
        break;
    case 6:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F63C, 3s-reloc: sf3 src/pass00.c:2069 Passive00_0116 */
void Passive00_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x200, 1, -1, 0x10, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F6A6, 3s-exact: sf3 src/pass00.c:2082 Passive00_0117 */
void Passive00_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x100, 1, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F6E8, 3s-exact: sf3 src/pass00.c:2095 Passive00_0118 */
void Passive00_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x20, 1, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F72A, 3s-exact: sf3 src/pass00.c:2108 Passive00_0119 */
void Passive00_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x200, 0, -1, 0x10, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F76C, 3s-reloc: sf3 src/pass00.c:2121 Passive00_0120 */
void Passive00_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x100, 0, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F7C0, 3s-reloc: sf3 src/pass00.c:2134 Passive00_0121 */
void Passive00_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x20, 0, -1, 0x10, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F802, 3s-reloc: sf3 src/pass00.c:2147 Passive00_0122 */
void Passive00_0122(PLW* wk) {
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



/* 2i 0603F846, 3s-reloc: sf3 src/pass00.c:2163 Passive00_0123 */
void Passive00_0123(PLW* wk) {
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



/* 2i 0603F8AA, 3s-near: sf3 src/pass00.c:2188 Passive00_0124 (2i steps differ) */
void Passive00_0124(PLW* wk) {
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
        Check_BOSS(wk, 6, 0xE);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F93A, 3s-exact: sf3 src/pass00.c:2213 Passive00_0125 */
void Passive00_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x48, 6, 0x22);
        break;
    case 1:
        Walk(wk, 1, 0x18, 0);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F976, 3s-exact: sf3 src/pass00.c:2232 Passive00_0126 */
void Passive00_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603F996, 3s-exact: sf3 src/pass00.c:2245 Passive00_0127 */
void Passive00_0127(PLW* wk) {
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



/* 2i 0603F9D2, 3s-reloc: sf3 src/pass00.c:2264 Passive00_0128 */
void Passive00_0128(PLW* wk) {
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



/* 2i 0603FA3A, 3s-reloc: sf3 src/pass00.c:2283 Passive00_0129 */
void Passive00_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x40, 6, 0x40);
        break;
    case 1:
        Walk(wk, 1, 0x10, 0);
        break;
    case 2:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FA78, 3s-near: sf3 src/pass00.c:2302 Passive00_0130 (2i steps differ) */
void Passive00_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 3);
        break;
    case 1:
        Search_Back_Term(wk, 0x50, 6, 0x6E);
        break;
    case 2:
        Walk(wk, 1, 0x18, 0);
        break;
    case 3:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FAFA, 3s-reloc: sf3 src/pass00.c:2324 Passive00_0131 */
void Passive00_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FB5C, 3s-near: sf3 src/pass00.c:2343 Passive00_0132 (2i steps differ) */
void Passive00_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x39, 0x39, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FBA4, 3s-reloc: sf3 src/pass00.c:2359 Passive00_0133 */
void Passive00_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FBC2, 3s-reloc: sf3 src/pass00.c:2372 Passive00_0134 */
void Passive00_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FBE2, 3s-reloc: sf3 src/pass00.c:2385 Passive00_0135 */
void Passive00_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FC00, 3s-reloc: sf3 src/pass00.c:2398 Passive00_0136 */
void Passive00_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FC22, 3s-reloc: sf3 src/pass00.c:2411 Passive00_0137 */
void Passive00_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FC6E, 3s-reloc: sf3 src/pass00.c:2424 Passive00_0138 */
void Passive00_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 5);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FC9A, 3s-reloc: sf3 src/pass00.c:2440 Passive00_0139 */
void Passive00_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FCC2, 3s-near: sf3 src/pass00.c:2456 Passive00_0140 (2i steps differ) */
void Passive00_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, -1, 8, 0x20, 1, -1, 0x20, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FD04, 3s-near: sf3 src/pass00.c:2469 Passive00_0141 (2i steps differ) */
void Passive00_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, 0x8040, 8, 0x20, 2, -1, 0x8050, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FD84, 3s-near: sf3 src/pass00.c:2485 Passive00_0142 (2i steps differ) */
void Passive00_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8090, 0x8040, 9, 0x20, 2, -1, -1, -1);
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



/* 2i 0603FDEC, 3s-exact: sf3 src/pass00.c:2504 Passive00_0143 */
void Passive00_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xA);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FE0A, 3s-exact: sf3 src/pass00.c:2517 Passive00_0144 */
void Passive00_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FE4E, 3s-reloc: sf3 src/pass00.c:2533 Passive00_0145 */
void Passive00_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 6, 1, -1);
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



/* 2i 0603FEBC, 3s-exact: sf3 src/pass00.c:2552 Passive00_0146 */
void Passive00_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603FF00, 3s-exact: sf3 src/pass00.c:2568 Passive00_0147 */
void Passive00_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 6, 1, -1);
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



/* 2i 0603FF48, 3s-near: sf3 src/pass00.c:2587 Passive00_0148 (2i steps differ) */
void Passive00_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 0xB, 0x200, 1, 0x8070, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
