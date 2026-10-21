/*
 * PASS02.C  CPU passive patterns for character 2 (Ryu)
 *
 * Passive02 is the CPU passive (defensive) routine for character 2, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive02_Tbl.
 * The 133 Passive02_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS02.h"



/* 2i 06042EB4, 3s-exact: sf3 src/PASS02.c:21 Passive02 */
void Passive02(PLW* wk) {
    Passive02_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06042ECC, 3s-exact: sf3 src/PASS02.c:27 Passive02_0000 */
void Passive02_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042F00, 3s-exact: sf3 src/PASS02.c:40 Passive02_0001 */
void Passive02_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042F58, 3s-exact: sf3 src/PASS02.c:59 Passive02_0002 */
void Passive02_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042F8A, 3s-exact: sf3 src/PASS02.c:72 Passive02_0003 */
void Passive02_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042FD6, 3s-exact: sf3 src/PASS02.c:88 Passive02_0004 */
void Passive02_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06042FF4, 3s-reloc: sf3 src/PASS02.c:101 Passive02_0005 */
void Passive02_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043056, 3s-exact: sf3 src/PASS02.c:114 Passive02_0006 */
void Passive02_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043088, 3s-exact: sf3 src/PASS02.c:127 Passive02_0007 */
void Passive02_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060430D6, 3s-reloc: sf3 src/PASS02.c:143 Passive02_0008 */
void Passive02_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043140, 3s-exact: sf3 src/PASS02.c:159 Passive02_0009 */
void Passive02_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, -1, 0, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x36, -1, 0x47);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060431A4, 3s-exact: sf3 src/PASS02.c:178 Passive02_0010 */
void Passive02_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8058, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060431EA, 3s-reloc: sf3 src/PASS02.c:194 Passive02_0011 */
void Passive02_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x100, 0, 0x8090, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604325C, 3s-reloc: sf3 src/PASS02.c:207 Passive02_0012 */
void Passive02_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x6F);
        break;
    case 1:
        Next_Another_Menu(wk, 6, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043288, 3s-reloc: sf3 src/PASS02.c:223 Passive02_0013 */
void Passive02_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060432CA, 3s-reloc: sf3 src/PASS02.c:239 Passive02_0014 */
void Passive02_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060432E8, 3s-reloc: sf3 src/PASS02.c:252 Passive02_0015 */
void Passive02_0015(PLW* wk) {
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



/* 2i 06043320, 3s-near: sf3 src/PASS02.c:271 Passive02_0016 */
void Passive02_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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



/* 2i 0604335A, 3s-near: sf3 src/PASS02.c:290 Passive02_0017 */
void Passive02_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060433BE, 3s-near: sf3 src/PASS02.c:309 Passive02_0018 */
void Passive02_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1C);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043420, 3s-near: sf3 src/PASS02.c:331 Passive02_0019 */
void Passive02_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043440, 3s-near: sf3 src/PASS02.c:344 Passive02_0020 */
void Passive02_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043460, 3s-reloc: sf3 src/PASS02.c:357 Passive02_0021 */
void Passive02_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060434D2, 3s-reloc: sf3 src/PASS02.c:376 Passive02_0022 */
void Passive02_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x200, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043524, 3s-reloc: sf3 src/PASS02.c:392 Passive02_0023 */
void Passive02_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x40, 0, 0x8088, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043576, 3s-near: sf3 src/PASS02.c:408 Passive02_0024 */
void Passive02_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
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



/* 2i 060435F4, 3s-near: sf3 src/PASS02.c:427 Passive02_0025 */
void Passive02_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 2:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043652, 3s-near: sf3 src/PASS02.c:446 Passive02_0026 */
void Passive02_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043696, 3s-near: sf3 src/PASS02.c:462 Passive02_0027 */
void Passive02_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060436F8, 3s-reloc: sf3 src/PASS02.c:478 Passive02_0028 */
void Passive02_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043718, 3s-reloc: sf3 src/PASS02.c:491 Passive02_0029 */
void Passive02_0029(PLW* wk) {
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



/* 2i 06043750, 3s-reloc: sf3 src/PASS02.c:510 Passive02_0030 */
void Passive02_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043770, 3s-reloc: sf3 src/PASS02.c:523 Passive02_0031 */
void Passive02_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043792, 3s-near: sf3 src/PASS02.c:536 Passive02_0032 */
void Passive02_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060437B4, 3s-near: sf3 src/PASS02.c:549 Passive02_0033 */
void Passive02_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060437F0, 3s-near: sf3 src/PASS02.c:562 Passive02_0034 */
void Passive02_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043810, 3s-near: sf3 src/PASS02.c:575 Passive02_0035 */
void Passive02_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043830, 3s-near: sf3 src/PASS02.c:588 Passive02_0036 */
void Passive02_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604384E, 3s-near: sf3 src/PASS02.c:601 Passive02_0037 */
void Passive02_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043894, 3s-near: sf3 src/PASS02.c:617 Passive02_0038 */
void Passive02_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8008, 0, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043900, 3s-near: sf3 src/PASS02.c:633 Passive02_0039 */
void Passive02_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604394E, 3s-near: sf3 src/PASS02.c:649 Passive02_0040 */
void Passive02_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 0, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604399C, 3s-reloc: sf3 src/PASS02.c:668 Passive02_0041 */
void Passive02_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 0, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043A18, 3s-near: sf3 src/PASS02.c:687 Passive02_0042 */
void Passive02_0042(PLW* wk) {
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



/* 2i 06043A40, 3s-near: sf3 src/PASS02.c:703 Passive02_0043 */
void Passive02_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 0, 6, 0x1F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043A9A, 3s-near: sf3 src/PASS02.c:722 Passive02_0044 */
void Passive02_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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



/* 2i 06043AEE, 3s-near: sf3 src/PASS02.c:741 Passive02_0045 */
void Passive02_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x70);
        break;
    case 1:
        Next_Another_Menu(wk, 6, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043B1A, 3s-near: sf3 src/PASS02.c:757 Passive02_0046 */
void Passive02_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043B3A, 3s-near: sf3 src/PASS02.c:770 Passive02_0047 */
void Passive02_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043BB0, 3s-reloc: sf3 src/PASS02.c:786 Passive02_0048 */
void Passive02_0048(PLW* wk) {
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



/* 2i 06043BDA, 3s-near: sf3 src/PASS02.c:802 Passive02_0049 */
void Passive02_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1F);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043C1E, 3s-near: sf3 src/PASS02.c:818 Passive02_0050 */
void Passive02_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043C62, 3s-near: sf3 src/PASS02.c:834 Passive02_0051 */
void Passive02_0051(PLW* wk) {
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



/* 2i 06043CAA, 3s-near: sf3 src/PASS02.c:850 Passive02_0052 */
void Passive02_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043CCA, 3s-near: sf3 src/PASS02.c:863 Passive02_0053 */
void Passive02_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043CFC, 3s-near: sf3 src/PASS02.c:876 Passive02_0054 */
void Passive02_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043D2E, 3s-reloc: sf3 src/PASS02.c:889 Passive02_0055 */
void Passive02_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043D60, 3s-reloc: sf3 src/PASS02.c:902 Passive02_0056 */
void Passive02_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 8, 0x200, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043DC4, 3s-near: sf3 src/PASS02.c:915 Passive02_0057 */
void Passive02_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x80, 0, 0x8088, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043E08, 3s-near: sf3 src/PASS02.c:928 Passive02_0058 */
void Passive02_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043E28, 3s-reloc: sf3 src/PASS02.c:941 Passive02_0059 */
void Passive02_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1F);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043E74, 3s-reloc: sf3 src/PASS02.c:957 Passive02_0060 */
void Passive02_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043E92, 3s-reloc: sf3 src/PASS02.c:970 Passive02_0061 */
void Passive02_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043EE0, 3s-near: sf3 src/PASS02.c:983 Passive02_0062 */
void Passive02_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043F20, 3s-near: sf3 src/PASS02.c:999 Passive02_0063 */
void Passive02_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, -1, 0x47);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x19, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043F68, 3s-reloc: sf3 src/PASS02.c:1015 Passive02_0064 */
void Passive02_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06043FFC, 3s-near: sf3 src/PASS02.c:1037 Passive02_0065 */
void Passive02_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604404A, 3s-near: sf3 src/PASS02.c:1056 Passive02_0066 */
void Passive02_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, -1, 0x47);
        break;
    case 2:
        SA_Term(wk, -1, -1, 0x19, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060440A0, 3s-near: sf3 src/PASS02.c:1075 Passive02_0067 */
void Passive02_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060440C0, 3s-near: sf3 src/PASS02.c:1088 Passive02_0068 */
void Passive02_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        Next_Be_Passive(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044110, 3s-reloc: sf3 src/PASS02.c:1104 Passive02_0069 */
void Passive02_0069(PLW* wk) {
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



/* 2i 0604415E, 3s-near: sf3 src/PASS02.c:1123 Passive02_0070 */
void Passive02_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x40, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Wait(wk, 10);
        break;
    case 3:
        SA_Term(wk, 0x35, 0x36, -1, 0x47);
        break;
    case 4:
        SA_Term(wk, -1, -1, 0x19, 0x3C);
        break;
    case 5:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 6:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044204, 3s-near: sf3 src/PASS02.c:1154 Passive02_0071 */
void Passive02_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 0, 1, -1);
        break;
    case 2:
        ETC_Term(wk, 8, 6, 7);
        break;
    case 3:
        Check_SA(wk, 6, 7);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        Command_Attack(wk, 8, 0x8016, 10, -1);
        break;
    case 6:
        Wait(wk, 1);
        break;
    case 7:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060442AA, 3s-reloc: sf3 src/PASS02.c:1188 Passive02_0072 */
void Passive02_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060442F2, 3s-near: sf3 src/PASS02.c:1204 Passive02_0073 */
void Passive02_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 1:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604438C, 3s-reloc: sf3 src/PASS02.c:1226 Passive02_0074 */
void Passive02_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, -1, 0x47);
        break;
    case 1:
        SA_Term(wk, -1, -1, 0x19, 0x3C);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060443EA, 3s-reloc: sf3 src/PASS02.c:1245 Passive02_0075 */
void Passive02_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 5, 6, 0x1F);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044444, 3s-reloc: sf3 src/PASS02.c:1264 Passive02_0076 */
void Passive02_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 6, 0x1C);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060444AE, 3s-reloc: sf3 src/PASS02.c:1280 Passive02_0077 */
void Passive02_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060444DA, 3s-reloc: sf3 src/PASS02.c:1296 Passive02_0078 */
void Passive02_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Check_EX(wk, 6, 0x70);
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1F, 8, (0x380));
        break;
    case 5:
        Check_BOSS_EX(wk, 1, -1);
        break;
    case 6:
        EM_Term(wk, 0x80A8, -1, 0, 1, -1);
        break;
    case 7:
        Wait(wk, 2);
        break;
    case 8:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060445D4, 3s-reloc: sf3 src/PASS02.c:1333 Passive02_0079 */
void Passive02_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060445F2, 3s-near: sf3 src/PASS02.c:1346 Passive02_0080 */
void Passive02_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060446B4, 3s-near: sf3 src/PASS02.c:1371 Passive02_0081 */
void Passive02_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 10, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, -1, 0x47);
        break;
    case 5:
        SA_Term(wk, -1, -1, 0x19, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044754, 3s-near: sf3 src/PASS02.c:1399 Passive02_0082 */
void Passive02_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1d, 0xa, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044812, 3s-near: sf3 src/PASS02.c:1427 Passive02_0083 */
void Passive02_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 4, 6, 0x2A);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604483E, 3s-near: sf3 src/PASS02.c:1443 Passive02_0084 */
void Passive02_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 9, 0x80, 1, 0x8050, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044880, 3s-near: sf3 src/PASS02.c:1456 Passive02_0085 */
void Passive02_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604491E, 3s-reloc: sf3 src/PASS02.c:1478 Passive02_0086 */
void Passive02_0086(PLW* wk) {
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



/* 2i 0604494A, 3s-near: sf3 src/PASS02.c:1494 Passive02_0087 */
void Passive02_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, (0x380), 0x8060, 0x48, 0, 0x380, 0x30, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044992, 3s-near: sf3 src/PASS02.c:1507 Passive02_0088 */
void Passive02_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044A5A, 3s-near: sf3 src/PASS02.c:1535 Passive02_0089 */
void Passive02_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x20, 0x3B, 0x36, 0x5A);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044AB0, 3s-near: sf3 src/PASS02.c:1554 Passive02_0090 */
void Passive02_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044B10, 3s-reloc: sf3 src/PASS02.c:1567 Passive02_0091 */
void Passive02_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8010, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044B80, 3s-reloc: sf3 src/PASS02.c:1589 Passive02_0092 */
void Passive02_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 0, 1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x60, 0x61, 0x62, 99, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044BD4, 3s-reloc: sf3 src/PASS02.c:1605 Passive02_0093 */
void Passive02_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044C68, 3s-exact: sf3 src/PASS02.c:1627 Passive02_0094 */
void Passive02_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 3, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044C9A, 3s-exact: sf3 src/PASS02.c:1640 Passive02_0095 */
void Passive02_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0xD, 0x3B);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044CCC, 3s-exact: sf3 src/PASS02.c:1653 Passive02_0096 */
void Passive02_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0xF, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044CFE, 3s-reloc: sf3 src/PASS02.c:1666 Passive02_0097 */
void Passive02_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0xF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044D58, 3s-exact: sf3 src/PASS02.c:1679 Passive02_0098 */
void Passive02_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 3, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044D8A, 3s-exact: sf3 src/PASS02.c:1692 Passive02_0099 */
void Passive02_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x11, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044DBC, 3s-exact: sf3 src/PASS02.c:1705 Passive02_0100 */
void Passive02_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8060, 0, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044E00, 3s-reloc: sf3 src/PASS02.c:1721 Passive02_0101 */
void Passive02_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044E6C, 3s-exact: sf3 src/PASS02.c:1737 Passive02_0102 */
void Passive02_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 0, 1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, (0x100), 0, 0x8090, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044ECC, 3s-exact: sf3 src/PASS02.c:1753 Passive02_0103 */
void Passive02_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, 0x8040, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044F1A, 3s-reloc: sf3 src/PASS02.c:1769 Passive02_0104 */
void Passive02_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, 0x8040, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044F8C, 3s-exact: sf3 src/PASS02.c:1785 Passive02_0105 */
void Passive02_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, 0x8040, 0, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x36, -1, 0x47);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06044FF0, 3s-exact: sf3 src/PASS02.c:1804 Passive02_0106 */
void Passive02_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 9);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0xB, 2, 0xC, 0x5A, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604505A, 3s-exact: sf3 src/PASS02.c:1826 Passive02_0107 */
void Passive02_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 7, 0x67, 8, 0x68, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045094, 3s-exact: sf3 src/PASS02.c:1839 Passive02_0108 */
void Passive02_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 9, 0x69, 9, 0x69, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060450CE, 3s-exact: sf3 src/PASS02.c:1852 Passive02_0109 */
void Passive02_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xc, 0, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045124, 3s-exact: sf3 src/PASS02.c:1871 Passive02_0110 */
void Passive02_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x6A);
        break;
    case 1:
        Next_Another_Menu(wk, 6, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045150, 3s-reloc: sf3 src/PASS02.c:1887 Passive02_0111 */
void Passive02_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8078, 0x8030, 0, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060451CA, 3s-exact: sf3 src/PASS02.c:1903 Passive02_0112 */
void Passive02_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8010, 0, 6, 0x1F);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06045216, 3s-exact: sf3 src/PASS02.c:1919 Passive02_0113 */
void Passive02_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS_EX(wk, 6, 0x72);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x4C, 0x37, 0x37, 0x30, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604525E, 3s-reloc: sf3 src/PASS02.c:1935 Passive02_0114 */
void Passive02_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8030, 0x8010, 5, 6, 1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x35, 0x36, -1, 0);
        break;
    case 4:
        SA_Term(wk, -1, -1, 0x19, 0x3C);
        break;
    case 5:
        Command_Attack(wk, 0xC, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

