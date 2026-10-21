/*
 * PASS11.C  CPU passive patterns for character 11 (Ken)
 *
 * Passive11 is the CPU passive (defensive) routine for character 11, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive11_Tbl.
 * The 255 Passive11_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS11.h"



/* 2i 0605CFB8, 3s-exact: sf3 src/PASS11.c:21 Passive11 */
void Passive11(PLW* wk) {
    Passive11_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0605CFD0, 3s-exact: sf3 src/PASS11.c:27 Passive11_0000 */
void Passive11_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D004, 3s-exact: sf3 src/PASS11.c:40 Passive11_0001 */
void Passive11_0001(PLW* wk) {
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



/* 2i 0605D02C, 3s-near: sf3 src/PASS11.c:56 Passive11_0002 */
void Passive11_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0x36);
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



/* 2i 0605D064, 3s-exact: sf3 src/PASS11.c:75 Passive11_0003 */
void Passive11_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D0E2, 3s-exact: sf3 src/PASS11.c:100 Passive11_0004 */
void Passive11_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x31, -1, 0x47);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D144, 3s-reloc: sf3 src/PASS11.c:119 Passive11_0005 */
void Passive11_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D1F8, 3s-near: sf3 src/PASS11.c:141 Passive11_0006 */
void Passive11_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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



/* 2i 0605D24C, 3s-near: sf3 src/PASS11.c:160 Passive11_0007 */
void Passive11_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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



/* 2i 0605D2A0, 3s-near: sf3 src/PASS11.c:179 Passive11_0008 */
void Passive11_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D310, 3s-exact: sf3 src/PASS11.c:198 Passive11_0009 */
void Passive11_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8020, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D35E, 3s-exact: sf3 src/PASS11.c:214 Passive11_0010 */
void Passive11_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D3CC, 3s-exact: sf3 src/PASS11.c:236 Passive11_0011 */
void Passive11_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D3EA, 3s-exact: sf3 src/PASS11.c:249 Passive11_0012 */
void Passive11_0012(PLW* wk) {
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



/* 2i 0605D416, 3s-exact: sf3 src/PASS11.c:265 Passive11_0013 */
void Passive11_0013(PLW* wk) {
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



/* 2i 0605D442, 3s-exact: sf3 src/PASS11.c:281 Passive11_0014 */
void Passive11_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D48E, 3s-reloc: sf3 src/PASS11.c:297 Passive11_0015 */
void Passive11_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack_SP(wk, 8, 0x100, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D4E8, 3s-exact: sf3 src/PASS11.c:313 Passive11_0016 */
void Passive11_0016(PLW* wk) {
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



/* 2i 0605D514, 3s-exact: sf3 src/PASS11.c:329 Passive11_0017 */
void Passive11_0017(PLW* wk) {
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



/* 2i 0605D540, 3s-exact: sf3 src/PASS11.c:345 Passive11_0018 */
void Passive11_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D584, 3s-reloc: sf3 src/PASS11.c:361 Passive11_0019 */
void Passive11_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D60A, 3s-near: sf3 src/PASS11.c:380 Passive11_0020 */
void Passive11_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D638, 3s-near: sf3 src/PASS11.c:396 Passive11_0021 */
void Passive11_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D666, 3s-near: sf3 src/PASS11.c:412 Passive11_0022 */
void Passive11_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D694, 3s-reloc: sf3 src/PASS11.c:428 Passive11_0023 */
void Passive11_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D6EC, 3s-exact: sf3 src/PASS11.c:444 Passive11_0024 */
void Passive11_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D72C, 3s-exact: sf3 src/PASS11.c:460 Passive11_0025 */
void Passive11_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D76C, 3s-exact: sf3 src/PASS11.c:476 Passive11_0026 */
void Passive11_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D7BA, 3s-exact: sf3 src/PASS11.c:492 Passive11_0027 */
void Passive11_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D808, 3s-exact: sf3 src/PASS11.c:508 Passive11_0028 */
void Passive11_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D856, 3s-exact: sf3 src/PASS11.c:524 Passive11_0029 */
void Passive11_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 0xB, 0x1E, 10, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D8A8, 3s-near: sf3 src/PASS11.c:543 Passive11_0030 */
void Passive11_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D900, 3s-near: sf3 src/PASS11.c:562 Passive11_0031 */
void Passive11_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 9, 0, 0x100);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D946, 3s-exact: sf3 src/PASS11.c:584 Passive11_0032 */
void Passive11_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D99A, 3s-near: sf3 src/PASS11.c:606 Passive11_0033 */
void Passive11_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605D9E4, 3s-exact: sf3 src/PASS11.c:622 Passive11_0034 */
void Passive11_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DA3A, 3s-exact: sf3 src/PASS11.c:641 Passive11_0035 */
void Passive11_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DA88, 3s-exact: sf3 src/PASS11.c:657 Passive11_0036 */
void Passive11_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DAD6, 3s-exact: sf3 src/PASS11.c:673 Passive11_0037 */
void Passive11_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DB24, 3s-exact: sf3 src/PASS11.c:689 Passive11_0038 */
void Passive11_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DB72, 3s-exact: sf3 src/PASS11.c:705 Passive11_0039 */
void Passive11_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DBC0, 3s-reloc: sf3 src/PASS11.c:721 Passive11_0040 */
void Passive11_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DC32, 3s-exact: sf3 src/PASS11.c:737 Passive11_0041 */
void Passive11_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7f);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DC96, 3s-exact: sf3 src/PASS11.c:756 Passive11_0042 */
void Passive11_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DCB4, 3s-exact: sf3 src/PASS11.c:769 Passive11_0043 */
void Passive11_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DD00, 3s-reloc: sf3 src/PASS11.c:785 Passive11_0044 */
void Passive11_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x38, 8, (0x200), 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DD60, 3s-exact: sf3 src/PASS11.c:798 Passive11_0045 */
void Passive11_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DDAE, 3s-exact: sf3 src/PASS11.c:814 Passive11_0046 */
void Passive11_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DDFC, 3s-reloc: sf3 src/PASS11.c:830 Passive11_0047 */
void Passive11_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DE6A, 3s-exact: sf3 src/PASS11.c:846 Passive11_0048 */
void Passive11_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DEAE, 3s-exact: sf3 src/PASS11.c:862 Passive11_0049 */
void Passive11_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DECE, 3s-exact: sf3 src/PASS11.c:875 Passive11_0050 */
void Passive11_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DF0E, 3s-reloc: sf3 src/PASS11.c:891 Passive11_0051 */
void Passive11_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DF70, 3s-exact: sf3 src/PASS11.c:904 Passive11_0052 */
void Passive11_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605DFCA, 3s-exact: sf3 src/PASS11.c:920 Passive11_0053 */
void Passive11_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E032, 3s-reloc: sf3 src/PASS11.c:939 Passive11_0054 */
void Passive11_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
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



/* 2i 0605E092, 3s-near: sf3 src/PASS11.c:958 Passive11_0055 */
void Passive11_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E0C0, 3s-exact: sf3 src/PASS11.c:974 Passive11_0056 */
void Passive11_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E124, 3s-reloc: sf3 src/PASS11.c:996 Passive11_0057 */
void Passive11_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E198, 3s-near: sf3 src/PASS11.c:1012 Passive11_0058 */
void Passive11_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E1C6, 3s-near: sf3 src/PASS11.c:1028 Passive11_0059 */
void Passive11_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E1F4, 3s-near: sf3 src/PASS11.c:1044 Passive11_0060 */
void Passive11_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E222, 3s-exact: sf3 src/PASS11.c:1060 Passive11_0061 */
void Passive11_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E24C, 3s-reloc: sf3 src/PASS11.c:1076 Passive11_0062 */
void Passive11_0062(PLW* wk) {
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



/* 2i 0605E298, 3s-exact: sf3 src/PASS11.c:1092 Passive11_0063 */
void Passive11_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E2EA, 3s-exact: sf3 src/PASS11.c:1111 Passive11_0064 */
void Passive11_0064(PLW* wk) {
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



/* 2i 0605E316, 3s-reloc: sf3 src/PASS11.c:1127 Passive11_0065 */
void Passive11_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0xE0, 6, 0x42);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, (0x200));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E3C0, 3s-exact: sf3 src/PASS11.c:1149 Passive11_0066 */
void Passive11_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0x14, 0xF, 5, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E416, 3s-exact: sf3 src/PASS11.c:1168 Passive11_0067 */
void Passive11_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0x14, 0xF, 5, 1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E46C, 3s-exact: sf3 src/PASS11.c:1187 Passive11_0068 */
void Passive11_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E496, 3s-exact: sf3 src/PASS11.c:1203 Passive11_0069 */
void Passive11_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E4B6, 3s-reloc: sf3 src/PASS11.c:1216 Passive11_0070 */
void Passive11_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Search_Back_Term(wk, 0xE0, 6, 0x42);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 0xB, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E54A, 3s-exact: sf3 src/PASS11.c:1238 Passive11_0071 */
void Passive11_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E572, 3s-exact: sf3 src/PASS11.c:1254 Passive11_0072 */
void Passive11_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E5A4, 3s-exact: sf3 src/PASS11.c:1267 Passive11_0073 */
void Passive11_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E5C4, 3s-reloc: sf3 src/PASS11.c:1280 Passive11_0074 */
void Passive11_0074(PLW* wk) {
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



/* 2i 0605E646, 3s-reloc: sf3 src/PASS11.c:1296 Passive11_0075 */
void Passive11_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x8040, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E6A2, 3s-reloc: sf3 src/PASS11.c:1315 Passive11_0076 */
void Passive11_0076(PLW* wk) {
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



/* 2i 0605E6CE, 3s-reloc: sf3 src/PASS11.c:1331 Passive11_0077 */
void Passive11_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E73C, 3s-near: sf3 src/PASS11.c:1347 Passive11_0078 */
void Passive11_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0xE, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E76E, 3s-reloc: sf3 src/PASS11.c:1360 Passive11_0079 */
void Passive11_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x53, 0x2F, 0x24, 0x25);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E7C4, 3s-reloc: sf3 src/PASS11.c:1379 Passive11_0080 */
void Passive11_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E858, 3s-exact: sf3 src/PASS11.c:1398 Passive11_0081 */
void Passive11_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        EM_Term(wk, 0x8057, 0x8000, 4, 6, 0x94);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E8E4, 3s-reloc: sf3 src/PASS11.c:1420 Passive11_0082 */
void Passive11_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
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
        Com_Random_Select(wk, 2, 0x2D, 0x94, 0x94, 0xFF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E99C, 3s-near: sf3 src/PASS11.c:1445 Passive11_0083 */
void Passive11_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E9BE, 3s-near: sf3 src/PASS11.c:1458 Passive11_0084 */
void Passive11_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605E9E0, 3s-near: sf3 src/PASS11.c:1471 Passive11_0085 */
void Passive11_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EA02, 3s-reloc: sf3 src/PASS11.c:1484 Passive11_0086 */
void Passive11_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EA22, 3s-reloc: sf3 src/PASS11.c:1497 Passive11_0087 */
void Passive11_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EA78, 3s-exact: sf3 src/PASS11.c:1510 Passive11_0088 */
void Passive11_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EA96, 3s-exact: sf3 src/PASS11.c:1523 Passive11_0089 */
void Passive11_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EAE8, 3s-exact: sf3 src/PASS11.c:1542 Passive11_0090 */
void Passive11_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 10, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EB1A, 3s-near: sf3 src/PASS11.c:1555 Passive11_0091 */
void Passive11_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, 0x100);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EBA2, 3s-exact: sf3 src/PASS11.c:1577 Passive11_0092 */
void Passive11_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EC04, 3s-near: sf3 src/PASS11.c:1599 Passive11_0093 */
void Passive11_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x28, 7, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 9, 0, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EC58, 3s-reloc: sf3 src/PASS11.c:1618 Passive11_0094 */
void Passive11_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605ECCE, 3s-exact: sf3 src/PASS11.c:1637 Passive11_0095 */
void Passive11_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605ED0E, 3s-exact: sf3 src/PASS11.c:1653 Passive11_0096 */
void Passive11_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605ED4E, 3s-reloc: sf3 src/PASS11.c:1669 Passive11_0097 */
void Passive11_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7f);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EDDA, 3s-exact: sf3 src/PASS11.c:1688 Passive11_0098 */
void Passive11_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EE1E, 3s-exact: sf3 src/PASS11.c:1704 Passive11_0099 */
void Passive11_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EE3E, 3s-exact: sf3 src/PASS11.c:1717 Passive11_0100 */
void Passive11_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EE5E, 3s-reloc: sf3 src/PASS11.c:1730 Passive11_0101 */
void Passive11_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EEF0, 3s-exact: sf3 src/PASS11.c:1752 Passive11_0102 */
void Passive11_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, -1, -1, -1);
        break;
    case 1:
        EM_Term(wk, 0x8057, 0x8000, 4, 6, 0x94);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EF7A, 3s-reloc: sf3 src/PASS11.c:1774 Passive11_0103 */
void Passive11_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605EFE4, 3s-exact: sf3 src/PASS11.c:1790 Passive11_0104 */
void Passive11_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x77, 0x7F, 0x81, 0x87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F01E, 3s-exact: sf3 src/PASS11.c:1803 Passive11_0105 */
void Passive11_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F092, 3s-reloc: sf3 src/PASS11.c:1825 Passive11_0106 */
void Passive11_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 8, (0x100), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F104, 3s-exact: sf3 src/PASS11.c:1838 Passive11_0107 */
void Passive11_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F152, 3s-exact: sf3 src/PASS11.c:1854 Passive11_0108 */
void Passive11_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F1A0, 3s-exact: sf3 src/PASS11.c:1870 Passive11_0109 */
void Passive11_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F1EE, 3s-exact: sf3 src/PASS11.c:1886 Passive11_0110 */
void Passive11_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F252, 3s-exact: sf3 src/PASS11.c:1908 Passive11_0111 */
void Passive11_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F2B6, 3s-exact: sf3 src/PASS11.c:1930 Passive11_0112 */
void Passive11_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F2D6, 3s-reloc: sf3 src/PASS11.c:1943 Passive11_0113 */
void Passive11_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack_SP(wk, 8, 0x100, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F344, 3s-exact: sf3 src/PASS11.c:1959 Passive11_0114 */
void Passive11_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F3AC, 3s-reloc: sf3 src/PASS11.c:1978 Passive11_0115 */
void Passive11_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 10, -1);
        break;
    case 3:
        Wait(wk, 0xA);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F462, 3s-exact: sf3 src/PASS11.c:2003 Passive11_0116 */
void Passive11_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F480, 3s-exact: sf3 src/PASS11.c:2016 Passive11_0117 */
void Passive11_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F4C0, 3s-exact: sf3 src/PASS11.c:2032 Passive11_0118 */
void Passive11_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F500, 3s-reloc: sf3 src/PASS11.c:2048 Passive11_0119 */
void Passive11_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1e, 0xa, -1, -1, 0x30, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F568, 3s-exact: sf3 src/PASS11.c:2061 Passive11_0120 */
void Passive11_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F588, 3s-exact: sf3 src/PASS11.c:2074 Passive11_0121 */
void Passive11_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F5CC, 3s-exact: sf3 src/PASS11.c:2090 Passive11_0122 */
void Passive11_0122(PLW* wk) {
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



/* 2i 0605F5F8, 3s-reloc: sf3 src/PASS11.c:2106 Passive11_0123 */
void Passive11_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F658, 3s-exact: sf3 src/PASS11.c:2122 Passive11_0124 */
void Passive11_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F6A2, 3s-exact: sf3 src/PASS11.c:2141 Passive11_0125 */
void Passive11_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F6F0, 3s-reloc: sf3 src/PASS11.c:2160 Passive11_0126 */
void Passive11_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F788, 3s-exact: sf3 src/PASS11.c:2182 Passive11_0127 */
void Passive11_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, (0x380), -1, 0x30, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F7D0, 3s-exact: sf3 src/PASS11.c:2195 Passive11_0128 */
void Passive11_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F84E, 3s-reloc: sf3 src/PASS11.c:2217 Passive11_0129 */
void Passive11_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, -1, -1, 0x30, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F8BC, 3s-exact: sf3 src/PASS11.c:2230 Passive11_0130 */
void Passive11_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F93A, 3s-reloc: sf3 src/PASS11.c:2252 Passive11_0131 */
void Passive11_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605F9AC, 3s-exact: sf3 src/PASS11.c:2268 Passive11_0132 */
void Passive11_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FA14, 3s-reloc: sf3 src/PASS11.c:2287 Passive11_0133 */
void Passive11_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FAB8, 3s-exact: sf3 src/PASS11.c:2309 Passive11_0134 */
void Passive11_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FB20, 3s-exact: sf3 src/PASS11.c:2328 Passive11_0135 */
void Passive11_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, 0x380, -1, 0x30, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FB68, 3s-reloc: sf3 src/PASS11.c:2341 Passive11_0136 */
void Passive11_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1e, 0xa, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FBD8, 3s-exact: sf3 src/PASS11.c:2354 Passive11_0137 */
void Passive11_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FC26, 3s-exact: sf3 src/PASS11.c:2373 Passive11_0138 */
void Passive11_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FC6C, 3s-exact: sf3 src/PASS11.c:2386 Passive11_0139 */
void Passive11_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, 0x100, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FCAE, 3s-reloc: sf3 src/PASS11.c:2399 Passive11_0140 */
void Passive11_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FD34, 3s-exact: sf3 src/PASS11.c:2421 Passive11_0141 */
void Passive11_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Branch_Wait_Area(wk, 0x14, 0xF, 5, 1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FD8A, 3s-exact: sf3 src/PASS11.c:2440 Passive11_0142 */
void Passive11_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FDFE, 3s-exact: sf3 src/PASS11.c:2462 Passive11_0143 */
void Passive11_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FE6C, 3s-reloc: sf3 src/PASS11.c:2484 Passive11_0144 */
void Passive11_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FF24, 3s-exact: sf3 src/PASS11.c:2509 Passive11_0145 */
void Passive11_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7f);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FFA8, 3s-exact: sf3 src/PASS11.c:2534 Passive11_0146 */
void Passive11_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605FFFE, 3s-exact: sf3 src/PASS11.c:2553 Passive11_0147 */
void Passive11_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060030, 3s-exact: sf3 src/PASS11.c:2566 Passive11_0148 */
void Passive11_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060062, 3s-reloc: sf3 src/PASS11.c:2579 Passive11_0149 */
void Passive11_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 2, -1, -1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060600F4, 3s-exact: sf3 src/PASS11.c:2598 Passive11_0150 */
void Passive11_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060112, 3s-reloc: sf3 src/PASS11.c:2611 Passive11_0151 */
void Passive11_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060601BC, 3s-exact: sf3 src/PASS11.c:2639 Passive11_0152 */
void Passive11_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xA9, 0xA8, 0xB9, 0x86, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060206, 3s-exact: sf3 src/PASS11.c:2655 Passive11_0153 */
void Passive11_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0x56);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060232, 3s-exact: sf3 src/PASS11.c:2671 Passive11_0154 */
void Passive11_0154(PLW* wk) {
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



/* 2i 0606025E, 3s-reloc: sf3 src/PASS11.c:2687 Passive11_0155 */
void Passive11_0155(PLW* wk) {
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



/* 2i 060602B4, 3s-exact: sf3 src/PASS11.c:2703 Passive11_0156 */
void Passive11_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060302, 3s-exact: sf3 src/PASS11.c:2722 Passive11_0157 */
void Passive11_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0x9A);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    case 2:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060346, 3s-reloc: sf3 src/PASS11.c:2744 Passive11_0158 */
void Passive11_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 3:
        Com_Random_Select(wk, 6, 0xA5, 0xE9, 0xE7, 0xAD, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060603D6, 3s-exact: sf3 src/PASS11.c:2766 Passive11_0159 */
void Passive11_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606043A, 3s-reloc: sf3 src/PASS11.c:2788 Passive11_0160 */
void Passive11_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060604D8, 3s-exact: sf3 src/PASS11.c:2807 Passive11_0161 */
void Passive11_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        EM_Term(wk, -1, 0x8000, 4, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060562, 3s-exact: sf3 src/PASS11.c:2829 Passive11_0162 */
void Passive11_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060605A2, 3s-reloc: sf3 src/PASS11.c:2845 Passive11_0163 */
void Passive11_0163(PLW* wk) {
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



/* 2i 0606066A, 3s-exact: sf3 src/PASS11.c:2873 Passive11_0164 */
void Passive11_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060606BC, 3s-exact: sf3 src/PASS11.c:2889 Passive11_0165 */
void Passive11_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack_SP(wk, 8, 0x100, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060606DE, 3s-reloc: sf3 src/PASS11.c:2902 Passive11_0166 */
void Passive11_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060762, 3s-exact: sf3 src/PASS11.c:2918 Passive11_0167 */
void Passive11_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060607CA, 3s-exact: sf3 src/PASS11.c:2937 Passive11_0168 */
void Passive11_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060607EC, 3s-reloc: sf3 src/PASS11.c:2950 Passive11_0169 */
void Passive11_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606087A, 3s-exact: sf3 src/PASS11.c:2969 Passive11_0170 */
void Passive11_0170(PLW* wk) {
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



/* 2i 060608A6, 3s-exact: sf3 src/PASS11.c:2985 Passive11_0171 */
void Passive11_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060608F4, 3s-reloc: sf3 src/PASS11.c:3004 Passive11_0172 */
void Passive11_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x50, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x3F, 0x40, 0x41, 0x43, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606095C, 3s-exact: sf3 src/PASS11.c:3020 Passive11_0173 */
void Passive11_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0xA5);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x51, 0x1C, 0x4D, 0x25, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060609C6, 3s-reloc: sf3 src/PASS11.c:3042 Passive11_0174 */
void Passive11_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1D, 10, -1);
        break;
    case 4:
        Wait(wk, 10);
        break;
    case 5:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060A8A, 3s-exact: sf3 src/PASS11.c:3070 Passive11_0175 */
void Passive11_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060AD4, 3s-reloc: sf3 src/PASS11.c:3089 Passive11_0176 */
void Passive11_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0xA5, 0xE9, 0xE7, 0xAD, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060B60, 3s-exact: sf3 src/PASS11.c:3111 Passive11_0177 */
void Passive11_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060BDA, 3s-reloc: sf3 src/PASS11.c:3133 Passive11_0178 */
void Passive11_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060C9A, 3s-exact: sf3 src/PASS11.c:3158 Passive11_0179 */
void Passive11_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060CCC, 3s-near: sf3 src/PASS11.c:3171 Passive11_0180 */
void Passive11_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060D0E, 3s-exact: sf3 src/PASS11.c:3187 Passive11_0181 */
void Passive11_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060D40, 3s-reloc: sf3 src/PASS11.c:3200 Passive11_0182 */
void Passive11_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060D80, 3s-exact: sf3 src/PASS11.c:3213 Passive11_0183 */
void Passive11_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060DE8, 3s-reloc: sf3 src/PASS11.c:3232 Passive11_0184 */
void Passive11_0184(PLW* wk) {
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



/* 2i 06060EAA, 3s-exact: sf3 src/PASS11.c:3260 Passive11_0185 */
void Passive11_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060EEE, 3s-exact: sf3 src/PASS11.c:3276 Passive11_0186 */
void Passive11_0186(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060F40, 3s-reloc: sf3 src/PASS11.c:3292 Passive11_0187 */
void Passive11_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060FB0, 3s-exact: sf3 src/PASS11.c:3308 Passive11_0188 */
void Passive11_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06060FE2, 3s-exact: sf3 src/PASS11.c:3321 Passive11_0189 */
void Passive11_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606102E, 3s-exact: sf3 src/PASS11.c:3337 Passive11_0190 */
void Passive11_0190(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606107A, 3s-exact: sf3 src/PASS11.c:3353 Passive11_0191 */
void Passive11_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x3F, 0x40, 0x41, 0x43, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060610C2, 3s-reloc: sf3 src/PASS11.c:3369 Passive11_0192 */
void Passive11_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061128, 3s-exact: sf3 src/PASS11.c:3385 Passive11_0193 */
void Passive11_0193(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061172, 3s-exact: sf3 src/PASS11.c:3401 Passive11_0194 */
void Passive11_0194(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 1:
        Com_Random_Select(wk, 6, 1, 1, 0xC0, 0xC0, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060611B8, 3s-reloc: sf3 src/PASS11.c:3417 Passive11_0195 */
void Passive11_0195(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    case 1:
        Com_Random_Select(wk, 6, 1, 1, 0xC0, 0xC0, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061224, 3s-exact: sf3 src/PASS11.c:3433 Passive11_0196 */
void Passive11_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061270, 3s-exact: sf3 src/PASS11.c:3449 Passive11_0197 */
void Passive11_0197(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060612B4, 3s-exact: sf3 src/PASS11.c:3465 Passive11_0198 */
void Passive11_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060612D2, 3s-reloc: sf3 src/PASS11.c:3478 Passive11_0199 */
void Passive11_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061334, 3s-exact: sf3 src/PASS11.c:3494 Passive11_0200 */
void Passive11_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061374, 3s-exact: sf3 src/PASS11.c:3510 Passive11_0201 */
void Passive11_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060613D6, 3s-exact: sf3 src/PASS11.c:3532 Passive11_0202 */
void Passive11_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xc, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606144A, 3s-reloc: sf3 src/PASS11.c:3554 Passive11_0203 */
void Passive11_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x14, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xC6, 0xC4, 0xC5, 0x2F, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060614C0, 3s-reloc: sf3 src/PASS11.c:3570 Passive11_0204 */
void Passive11_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x2F);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x51, 0x1C, 0x4D, 0x25, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606152A, 3s-near: sf3 src/PASS11.c:3592 Passive11_0205 */
void Passive11_0205(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060615B4, 3s-reloc: sf3 src/PASS11.c:3614 Passive11_0206 */
void Passive11_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060615D4, 3s-near: sf3 src/PASS11.c:3627 Passive11_0207 */
void Passive11_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x53, 0x54, 0x13, 0x25, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061624, 3s-near: sf3 src/PASS11.c:3646 Passive11_0208 */
void Passive11_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x53, 0x54, 1, 0x25, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061674, 3s-reloc: sf3 src/PASS11.c:3665 Passive11_0209 */
void Passive11_0209(PLW* wk) {
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



/* 2i 060616DA, 3s-exact: sf3 src/PASS11.c:3681 Passive11_0210 */
void Passive11_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, 0x380);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061724, 3s-reloc: sf3 src/PASS11.c:3700 Passive11_0211 */
void Passive11_0211(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 0xC, 0x1C, 10, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060617E4, 3s-exact: sf3 src/PASS11.c:3728 Passive11_0212 */
void Passive11_0212(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8018, 6, 1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    case 3:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061858, 3s-exact: sf3 src/PASS11.c:3750 Passive11_0213 */
void Passive11_0213(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 1:
        Next_Another_Menu(wk, 6, 0x73);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061898, 3s-reloc: sf3 src/PASS11.c:3766 Passive11_0214 */
void Passive11_0214(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x40);
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
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061942, 3s-exact: sf3 src/PASS11.c:3791 Passive11_0215 */
void Passive11_0215(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606198A, 3s-reloc: sf3 src/PASS11.c:3807 Passive11_0216 */
void Passive11_0216(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061A20, 3s-exact: sf3 src/PASS11.c:3826 Passive11_0217 */
void Passive11_0217(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061A7A, 3s-reloc: sf3 src/PASS11.c:3842 Passive11_0218 */
void Passive11_0218(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x100);
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



/* 2i 06061B00, 3s-exact: sf3 src/PASS11.c:3861 Passive11_0219 */
void Passive11_0219(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061B8C, 3s-reloc: sf3 src/PASS11.c:3889 Passive11_0220 */
void Passive11_0220(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 3:
        Normal_Attack(wk, 9, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061C1A, 3s-near: sf3 src/PASS11.c:3911 Passive11_0221 */
void Passive11_0221(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061C84, 3s-near: sf3 src/PASS11.c:3933 Passive11_0222 */
void Passive11_0222(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061D0C, 3s-near: sf3 src/PASS11.c:3955 Passive11_0223 */
void Passive11_0223(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061D76, 3s-exact: sf3 src/PASS11.c:3977 Passive11_0224 */
void Passive11_0224(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8020, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7f);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061DDA, 3s-reloc: sf3 src/PASS11.c:3996 Passive11_0225 */
void Passive11_0225(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061E44, 3s-exact: sf3 src/PASS11.c:4012 Passive11_0226 */
void Passive11_0226(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061EA4, 3s-reloc: sf3 src/PASS11.c:4034 Passive11_0227 */
void Passive11_0227(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061F28, 3s-exact: sf3 src/PASS11.c:4053 Passive11_0228 */
void Passive11_0228(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061F82, 3s-exact: sf3 src/PASS11.c:4072 Passive11_0229 */
void Passive11_0229(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06061FDC, 3s-reloc: sf3 src/PASS11.c:4091 Passive11_0230 */
void Passive11_0230(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7f);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606206C, 3s-near: sf3 src/PASS11.c:4113 Passive11_0231 */
void Passive11_0231(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606209E, 3s-near: sf3 src/PASS11.c:4129 Passive11_0232 */
void Passive11_0232(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060620D0, 3s-near: sf3 src/PASS11.c:4142 Passive11_0233 */
void Passive11_0233(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06062102, 3s-near: sf3 src/PASS11.c:4155 Passive11_0234 */
void Passive11_0234(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, (0x380), -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0606216E, 3s-near: sf3 src/PASS11.c:4168 Passive11_0235 */
void Passive11_0235(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, 0x380, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060621B6, 3s-near: sf3 src/PASS11.c:4181 Passive11_0236 */
void Passive11_0236(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x88, 0x8A, 0xEA, 0xEB, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

