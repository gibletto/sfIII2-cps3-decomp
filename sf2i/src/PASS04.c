/*
 * PASS04.C  CPU passive patterns for character 4 (Dudley)
 *
 * Passive04 is the CPU passive (defensive) routine for character 4, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive04_Tbl.
 * The 142 Passive04_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS04.h"



/* 2i 06047E44, 3s-exact: sf3 src/PASS04.c:21 Passive04 */
void Passive04(PLW* wk) {
    Passive04_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06047E5C, 3s-exact: sf3 src/PASS04.c:27 Passive04_0000 */
void Passive04_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047E90, 3s-exact: sf3 src/PASS04.c:40 Passive04_0001 */
void Passive04_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x58);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047EF2, 3s-exact: sf3 src/PASS04.c:62 Passive04_0002 */
void Passive04_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047F24, 3s-exact: sf3 src/PASS04.c:75 Passive04_0003 */
void Passive04_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047F56, 3s-exact: sf3 src/PASS04.c:88 Passive04_0004 */
void Passive04_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047F98, 3s-reloc: sf3 src/PASS04.c:104 Passive04_0005 */
void Passive04_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06047FEE, 3s-exact: sf3 src/PASS04.c:117 Passive04_0006 */
void Passive04_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x58);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048050, 3s-exact: sf3 src/PASS04.c:139 Passive04_0007 */
void Passive04_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604809E, 3s-reloc: sf3 src/PASS04.c:155 Passive04_0008 */
void Passive04_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604810E, 3s-exact: sf3 src/PASS04.c:171 Passive04_0009 */
void Passive04_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048172, 3s-exact: sf3 src/PASS04.c:190 Passive04_0010 */
void Passive04_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8030, 0x8040, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060481B8, 3s-reloc: sf3 src/PASS04.c:206 Passive04_0011 */
void Passive04_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, (0x100), 0, 0x8090, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604821C, 3s-exact: sf3 src/PASS04.c:219 Passive04_0012 */
void Passive04_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, 0, 0, 2, 0);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604826C, 3s-exact: sf3 src/PASS04.c:235 Passive04_0013 */
void Passive04_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x58);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060482B8, 3s-reloc: sf3 src/PASS04.c:254 Passive04_0014 */
void Passive04_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048308, 3s-exact: sf3 src/PASS04.c:267 Passive04_0015 */
void Passive04_0015(PLW* wk) {
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



/* 2i 06048340, 3s-exact: sf3 src/PASS04.c:286 Passive04_0016 */
void Passive04_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Lever_Attack(wk, 0xD, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604837A, 3s-exact: sf3 src/PASS04.c:305 Passive04_0017 */
void Passive04_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
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



/* 2i 060483B2, 3s-reloc: sf3 src/PASS04.c:324 Passive04_0018 */
void Passive04_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048408, 3s-near: sf3 src/PASS04.c:343 Passive04_0019 */
void Passive04_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048428, 3s-exact: sf3 src/PASS04.c:356 Passive04_0020 */
void Passive04_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048448, 3s-exact: sf3 src/PASS04.c:369 Passive04_0021 */
void Passive04_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048496, 3s-reloc: sf3 src/PASS04.c:388 Passive04_0022 */
void Passive04_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, (0x200), 0, 0x8098, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048510, 3s-exact: sf3 src/PASS04.c:404 Passive04_0023 */
void Passive04_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, 0x8088, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048562, 3s-exact: sf3 src/PASS04.c:420 Passive04_0024 */
void Passive04_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xDF, 2);
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



/* 2i 0604859C, 3s-reloc: sf3 src/PASS04.c:439 Passive04_0025 */
void Passive04_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048638, 3s-exact: sf3 src/PASS04.c:461 Passive04_0026 */
void Passive04_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604867C, 3s-exact: sf3 src/PASS04.c:477 Passive04_0027 */
void Passive04_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060486BC, 3s-exact: sf3 src/PASS04.c:493 Passive04_0028 */
void Passive04_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060486DC, 3s-exact: sf3 src/PASS04.c:506 Passive04_0029 */
void Passive04_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x10);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048716, 3s-reloc: sf3 src/PASS04.c:525 Passive04_0030 */
void Passive04_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604875A, 3s-exact: sf3 src/PASS04.c:538 Passive04_0031 */
void Passive04_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604877C, 3s-near: sf3 src/PASS04.c:551 Passive04_0032 */
void Passive04_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060487AA, 3s-near: sf3 src/PASS04.c:567 Passive04_0033 */
void Passive04_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060487D8, 3s-near: sf3 src/PASS04.c:583 Passive04_0034 */
void Passive04_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060487F8, 3s-near: sf3 src/PASS04.c:596 Passive04_0035 */
void Passive04_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048818, 3s-near: sf3 src/PASS04.c:609 Passive04_0036 */
void Passive04_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604885C, 3s-near: sf3 src/PASS04.c:622 Passive04_0037 */
void Passive04_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060488B0, 3s-near: sf3 src/PASS04.c:641 Passive04_0038 */
void Passive04_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048904, 3s-near: sf3 src/PASS04.c:660 Passive04_0039 */
void Passive04_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8020, 0, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048962, 3s-reloc: sf3 src/PASS04.c:679 Passive04_0040 */
void Passive04_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060489CC, 3s-reloc: sf3 src/PASS04.c:707 Passive04_0041 */
void Passive04_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8018, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048A3A, 3s-reloc: sf3 src/PASS04.c:729 Passive04_0042 */
void Passive04_0042(PLW* wk) {
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



/* 2i 06048A94, 3s-near: sf3 src/PASS04.c:745 Passive04_0043 */
void Passive04_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048AE2, 3s-near: sf3 src/PASS04.c:761 Passive04_0044 */
void Passive04_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
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



/* 2i 06048B36, 3s-near: sf3 src/PASS04.c:780 Passive04_0045 */
void Passive04_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048B58, 3s-near: sf3 src/PASS04.c:793 Passive04_0046 */
void Passive04_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048B78, 3s-near: sf3 src/PASS04.c:806 Passive04_0047 */
void Passive04_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048BE0, 3s-near: sf3 src/PASS04.c:822 Passive04_0048 */
void Passive04_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048C0A, 3s-near: sf3 src/PASS04.c:838 Passive04_0049 */
void Passive04_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048C2A, 3s-near: sf3 src/PASS04.c:851 Passive04_0050 */
void Passive04_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048C4A, 3s-near: sf3 src/PASS04.c:864 Passive04_0051 */
void Passive04_0051(PLW* wk) {
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



/* 2i 06048C6E, 3s-near: sf3 src/PASS04.c:880 Passive04_0052 */
void Passive04_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048CB8, 3s-reloc: sf3 src/PASS04.c:896 Passive04_0053 */
void Passive04_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048CDA, 3s-reloc: sf3 src/PASS04.c:909 Passive04_0054 */
void Passive04_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048CFA, 3s-reloc: sf3 src/PASS04.c:922 Passive04_0055 */
void Passive04_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048D1A, 3s-near: sf3 src/PASS04.c:935 Passive04_0056 */
void Passive04_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 8, (0x200), 0, 0x8098, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048D5C, 3s-near: sf3 src/PASS04.c:948 Passive04_0057 */
void Passive04_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, (0x80), 0, 0x8088, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048DA0, 3s-near: sf3 src/PASS04.c:961 Passive04_0058 */
void Passive04_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048DE6, 3s-reloc: sf3 src/PASS04.c:974 Passive04_0059 */
void Passive04_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048E18, 3s-reloc: sf3 src/PASS04.c:987 Passive04_0060 */
void Passive04_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048E36, 3s-near: sf3 src/PASS04.c:1000 Passive04_0061 */
void Passive04_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048E56, 3s-near: sf3 src/PASS04.c:1013 Passive04_0062 */
void Passive04_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048E96, 3s-near: sf3 src/PASS04.c:1029 Passive04_0063 */
void Passive04_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048EF0, 3s-near: sf3 src/PASS04.c:1048 Passive04_0064 */
void Passive04_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048F3E, 3s-reloc: sf3 src/PASS04.c:1067 Passive04_0065 */
void Passive04_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xD, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048F6A, 3s-reloc: sf3 src/PASS04.c:1083 Passive04_0066 */
void Passive04_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048FAA, 3s-reloc: sf3 src/PASS04.c:1099 Passive04_0067 */
void Passive04_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06048FE8, 3s-near: sf3 src/PASS04.c:1112 Passive04_0068 */
void Passive04_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xDF, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049036, 3s-near: sf3 src/PASS04.c:1131 Passive04_0069 */
void Passive04_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 2:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049084, 3s-near: sf3 src/PASS04.c:1150 Passive04_0070 */
void Passive04_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049108, 3s-near: sf3 src/PASS04.c:1172 Passive04_0071 */
void Passive04_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8010, 0, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x36, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604916C, 3s-reloc: sf3 src/PASS04.c:1191 Passive04_0072 */
void Passive04_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 1:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060491AA, 3s-reloc: sf3 src/PASS04.c:1207 Passive04_0073 */
void Passive04_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xD, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060491EA, 3s-near: sf3 src/PASS04.c:1223 Passive04_0074 */
void Passive04_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049252, 3s-exact: sf3 src/PASS04.c:1242 Passive04_0075 */
void Passive04_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 5, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060492AC, 3s-exact: sf3 src/PASS04.c:1261 Passive04_0076 */
void Passive04_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1C);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060492F2, 3s-reloc: sf3 src/PASS04.c:1277 Passive04_0077 */
void Passive04_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049348, 3s-exact: sf3 src/PASS04.c:1293 Passive04_0078 */
void Passive04_0078(PLW* wk) {
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



/* 2i 06049374, 3s-exact: sf3 src/PASS04.c:1309 Passive04_0079 */
void Passive04_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060493B4, 3s-exact: sf3 src/PASS04.c:1325 Passive04_0080 */
void Passive04_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060493F4, 3s-reloc: sf3 src/PASS04.c:1341 Passive04_0081 */
void Passive04_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049450, 3s-exact: sf3 src/PASS04.c:1357 Passive04_0082 */
void Passive04_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 1:
        Lever_Attack(wk, 0xD, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049492, 3s-exact: sf3 src/PASS04.c:1373 Passive04_0083 */
void Passive04_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, 0, 0, 2, 0);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060494E2, 3s-reloc: sf3 src/PASS04.c:1389 Passive04_0084 */
void Passive04_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0, 0, 2, 0);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x608, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049558, 3s-exact: sf3 src/PASS04.c:1405 Passive04_0085 */
void Passive04_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, 0, 0, 2, 0);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x309, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060495A8, 3s-exact: sf3 src/PASS04.c:1421 Passive04_0086 */
void Passive04_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0, 0, 2, 0);
        break;
    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x308, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060495F8, 3s-exact: sf3 src/PASS04.c:1437 Passive04_0087 */
void Passive04_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x37, 0);
        break;
    case 1:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049636, 3s-reloc: sf3 src/PASS04.c:1453 Passive04_0088 */
void Passive04_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604967E, 3s-exact: sf3 src/PASS04.c:1466 Passive04_0089 */
void Passive04_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        SA_Term(wk, -1, 0x36, 0x37, 0);
        break;
    case 2:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060496CC, 3s-exact: sf3 src/PASS04.c:1485 Passive04_0090 */
void Passive04_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x608, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060496FE, 3s-exact: sf3 src/PASS04.c:1498 Passive04_0091 */
void Passive04_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049730, 3s-exact: sf3 src/PASS04.c:1511 Passive04_0092 */
void Passive04_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049762, 3s-reloc: sf3 src/PASS04.c:1524 Passive04_0093 */
void Passive04_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060497AE, 3s-exact: sf3 src/PASS04.c:1537 Passive04_0094 */
void Passive04_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, 0x8010, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049802, 3s-exact: sf3 src/PASS04.c:1559 Passive04_0095 */
void Passive04_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8040, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049848, 3s-reloc: sf3 src/PASS04.c:1575 Passive04_0096 */
void Passive04_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8040, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060498C4, 3s-exact: sf3 src/PASS04.c:1594 Passive04_0097 */
void Passive04_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060498F0, 3s-exact: sf3 src/PASS04.c:1610 Passive04_0098 */
void Passive04_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 8);
        break;
    case 1:
        EM_Term(wk, 0x8060, -1, 0, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604994A, 3s-reloc: sf3 src/PASS04.c:1629 Passive04_0099 */
void Passive04_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8028, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060499BC, 3s-reloc: sf3 src/PASS04.c:1645 Passive04_0100 */
void Passive04_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060499DA, 3s-near: sf3 src/PASS04.c:1658 Passive04_0101 */
void Passive04_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049A0C, 3s-near: sf3 src/PASS04.c:1674 Passive04_0102 */
void Passive04_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049A3E, 3s-near: sf3 src/PASS04.c:1693 Passive04_0103 */
void Passive04_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049A70, 3s-near: sf3 src/PASS04.c:1712 Passive04_0104 */
void Passive04_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 2, 0x11);
        break;
    case 1:
        Command_Attack(wk, 8, 0x21, 10, (0x380));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049AC8, 3s-near: sf3 src/PASS04.c:1728 Passive04_0105 */
void Passive04_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x65, 0x65, 0x66, 0x66, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049B0E, 3s-near: sf3 src/PASS04.c:1744 Passive04_0106 */
void Passive04_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x67, 0x67, 0x66, 0x66, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049B54, 3s-near: sf3 src/PASS04.c:1763 Passive04_0107 */
void Passive04_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x67, 0x67, 0x67, 0x68, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049BA2, 3s-reloc: sf3 src/PASS04.c:1782 Passive04_0108 */
void Passive04_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        EM_Term(wk, 0x8060, -1, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049C0E, 3s-near: sf3 src/PASS04.c:1801 Passive04_0109 */
void Passive04_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049C22, 3s-near: sf3 src/PASS04.c:1814 Passive04_0110 */
void Passive04_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049C7E, 3s-near: sf3 src/PASS04.c:1833 Passive04_0111 */
void Passive04_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049CF8, 3s-reloc: sf3 src/PASS04.c:1852 Passive04_0112 */
void Passive04_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049D6A, 3s-reloc: sf3 src/PASS04.c:1874 Passive04_0113 */
void Passive04_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        Check_EX(wk, 6, 0x6F);
        break;
    case 2:
        EM_Term(wk, 0x8068, -1, 0, 1, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049DD0, 3s-reloc: sf3 src/PASS04.c:1896 Passive04_0114 */
void Passive04_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x33);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049E1C, 3s-reloc: sf3 src/PASS04.c:1915 Passive04_0115 */
void Passive04_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xDF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049E6A, 3s-exact: sf3 src/PASS04.c:1928 Passive04_0116 */
void Passive04_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8010, 5, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x36, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049ECE, 3s-exact: sf3 src/PASS04.c:1947 Passive04_0117 */
void Passive04_0117(PLW* wk) {
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



/* 2i 06049EF6, 3s-exact: sf3 src/PASS04.c:1963 Passive04_0118 */
void Passive04_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8050, -1, 8, (0x200), 1, -1, 0x20, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049F38, 3s-reloc: sf3 src/PASS04.c:1976 Passive04_0119 */
void Passive04_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8050, 0x8050, 8, 0x40, 2, -1, 0x8050, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06049FC4, 3s-exact: sf3 src/PASS04.c:1992 Passive04_0120 */
void Passive04_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8050, 0x8050, 8, 0x40, 2, -1, 0x8050, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A022, 3s-exact: sf3 src/PASS04.c:2011 Passive04_0121 */
void Passive04_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
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



/* 2i 0604A05A, 3s-reloc: sf3 src/PASS04.c:2030 Passive04_0122 */
void Passive04_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A094, 3s-exact: sf3 src/PASS04.c:2043 Passive04_0123 */
void Passive04_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A0C6, 3s-exact: sf3 src/PASS04.c:2056 Passive04_0124 */
void Passive04_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x608, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A0F8, 3s-exact: sf3 src/PASS04.c:2069 Passive04_0125 */
void Passive04_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x309, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A12A, 3s-exact: sf3 src/PASS04.c:2082 Passive04_0126 */
void Passive04_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x308, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A15C, 3s-reloc: sf3 src/PASS04.c:2095 Passive04_0127 */
void Passive04_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A1C0, 3s-exact: sf3 src/PASS04.c:2111 Passive04_0128 */
void Passive04_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A204, 3s-exact: sf3 src/PASS04.c:2127 Passive04_0129 */
void Passive04_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A252, 3s-exact: sf3 src/PASS04.c:2143 Passive04_0130 */
void Passive04_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 0, 1, -1);
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



/* 2i 0604A29A, 3s-reloc: sf3 src/PASS04.c:2162 Passive04_0131 */
void Passive04_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A2FE, 3s-exact: sf3 src/PASS04.c:2181 Passive04_0132 */
void Passive04_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A34A, 3s-exact: sf3 src/PASS04.c:2197 Passive04_0133 */
void Passive04_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 0, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A3AE, 3s-reloc: sf3 src/PASS04.c:2216 Passive04_0134 */
void Passive04_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604A41E, 3s-reloc: sf3 src/PASS04.c:2232 Passive04_0135 */
void Passive04_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

