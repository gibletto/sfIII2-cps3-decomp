/*
 * PASS08.C  CPU passive patterns for character 8 (Elena)
 *
 * Passive08 is the CPU passive (defensive) routine for character 8, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive08_Tbl.
 * The 214 Passive08_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS08.h"



/* 2i 060534B4, 3s-exact: sf3 src/PASS08.c:21 Passive08 */
void Passive08(PLW* wk) {
    Passive08_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 060534CC, 3s-exact: sf3 src/PASS08.c:27 Passive08_0000 */
void Passive08_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053500, 3s-exact: sf3 src/PASS08.c:40 Passive08_0001 */
void Passive08_0001(PLW* wk) {
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



/* 2i 06053528, 3s-exact: sf3 src/PASS08.c:56 Passive08_0002 */
void Passive08_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;
    case 2:
        J_Command_Attack(wk, 9, 0x1E, 8, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053588, 3s-reloc: sf3 src/PASS08.c:78 Passive08_0003 */
void Passive08_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053600, 3s-reloc: sf3 src/PASS08.c:94 Passive08_0004 */
void Passive08_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        SA_Term(wk, -1, 0x3A, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053662, 3s-reloc: sf3 src/PASS08.c:113 Passive08_0005 */
void Passive08_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 1, -1);
        break;
    case 1:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605368E, 3s-near: sf3 src/PASS08.c:129 Passive08_0006 */
void Passive08_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060536E2, 3s-near: sf3 src/PASS08.c:148 Passive08_0007 */
void Passive08_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
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



/* 2i 06053736, 3s-near: sf3 src/PASS08.c:167 Passive08_0008 */
void Passive08_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053778, 3s-near: sf3 src/PASS08.c:183 Passive08_0009 */
void Passive08_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060537FC, 3s-exact: sf3 src/PASS08.c:199 Passive08_0010 */
void Passive08_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1e, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605386A, 3s-exact: sf3 src/PASS08.c:221 Passive08_0011 */
void Passive08_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053888, 3s-exact: sf3 src/PASS08.c:234 Passive08_0012 */
void Passive08_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060538B6, 3s-reloc: sf3 src/PASS08.c:250 Passive08_0013 */
void Passive08_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605390C, 3s-exact: sf3 src/PASS08.c:266 Passive08_0014 */
void Passive08_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053944, 3s-exact: sf3 src/PASS08.c:285 Passive08_0015 */
void Passive08_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605397C, 3s-exact: sf3 src/PASS08.c:304 Passive08_0016 */
void Passive08_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060539A8, 3s-reloc: sf3 src/PASS08.c:320 Passive08_0017 */
void Passive08_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060539EC, 3s-reloc: sf3 src/PASS08.c:336 Passive08_0018 */
void Passive08_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8048, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053A30, 3s-reloc: sf3 src/PASS08.c:352 Passive08_0019 */
void Passive08_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053A70, 3s-near: sf3 src/PASS08.c:368 Passive08_0020 */
void Passive08_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053A9E, 3s-reloc: sf3 src/PASS08.c:384 Passive08_0021 */
void Passive08_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053AF0, 3s-exact: sf3 src/PASS08.c:400 Passive08_0022 */
void Passive08_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053B12, 3s-exact: sf3 src/PASS08.c:413 Passive08_0023 */
void Passive08_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053B68, 3s-exact: sf3 src/PASS08.c:432 Passive08_0024 */
void Passive08_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053BA8, 3s-reloc: sf3 src/PASS08.c:448 Passive08_0025 */
void Passive08_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053C00, 3s-exact: sf3 src/PASS08.c:464 Passive08_0026 */
void Passive08_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053C32, 3s-exact: sf3 src/PASS08.c:477 Passive08_0027 */
void Passive08_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053C64, 3s-exact: sf3 src/PASS08.c:490 Passive08_0028 */
void Passive08_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053C96, 3s-exact: sf3 src/PASS08.c:503 Passive08_0029 */
void Passive08_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053CE8, 3s-reloc: sf3 src/PASS08.c:522 Passive08_0030 */
void Passive08_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053D4C, 3s-exact: sf3 src/PASS08.c:541 Passive08_0031 */
void Passive08_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 9, 0, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053D92, 3s-exact: sf3 src/PASS08.c:563 Passive08_0032 */
void Passive08_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xB, 0, 0x20);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053DCE, 3s-reloc: sf3 src/PASS08.c:582 Passive08_0033 */
void Passive08_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053E18, 3s-exact: sf3 src/PASS08.c:598 Passive08_0034 */
void Passive08_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053E6E, 3s-exact: sf3 src/PASS08.c:617 Passive08_0035 */
void Passive08_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053EA0, 3s-exact: sf3 src/PASS08.c:630 Passive08_0036 */
void Passive08_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053ED2, 3s-exact: sf3 src/PASS08.c:643 Passive08_0037 */
void Passive08_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053F04, 3s-exact: sf3 src/PASS08.c:656 Passive08_0038 */
void Passive08_0038(PLW* wk) {
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



/* 2i 06053F52, 3s-exact: sf3 src/PASS08.c:672 Passive08_0039 */
void Passive08_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053FA0, 3s-exact: sf3 src/PASS08.c:688 Passive08_0040 */
void Passive08_0040(PLW* wk) {
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



/* 2i 06053FEE, 3s-reloc: sf3 src/PASS08.c:704 Passive08_0041 */
void Passive08_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x39, -1, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605406E, 3s-exact: sf3 src/PASS08.c:723 Passive08_0042 */
void Passive08_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605408C, 3s-exact: sf3 src/PASS08.c:736 Passive08_0043 */
void Passive08_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x40, 8, 0x80, 0, 0x8040, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060540CE, 3s-exact: sf3 src/PASS08.c:749 Passive08_0044 */
void Passive08_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x40, 8, 0x200, 0, 0x8040, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054110, 3s-exact: sf3 src/PASS08.c:762 Passive08_0045 */
void Passive08_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054142, 3s-reloc: sf3 src/PASS08.c:775 Passive08_0046 */
void Passive08_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054196, 3s-exact: sf3 src/PASS08.c:788 Passive08_0047 */
void Passive08_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060541C8, 3s-exact: sf3 src/PASS08.c:801 Passive08_0048 */
void Passive08_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060541E8, 3s-exact: sf3 src/PASS08.c:814 Passive08_0049 */
void Passive08_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605420C, 3s-exact: sf3 src/PASS08.c:830 Passive08_0050 */
void Passive08_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605424C, 3s-reloc: sf3 src/PASS08.c:846 Passive08_0051 */
void Passive08_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060542AA, 3s-exact: sf3 src/PASS08.c:865 Passive08_0052 */
void Passive08_0052(PLW* wk) {
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



/* 2i 06054304, 3s-reloc: sf3 src/PASS08.c:881 Passive08_0053 */
void Passive08_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054390, 3s-exact: sf3 src/PASS08.c:900 Passive08_0054 */
void Passive08_0054(PLW* wk) {
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



/* 2i 060543C8, 3s-exact: sf3 src/PASS08.c:919 Passive08_0055 */
void Passive08_0055(PLW* wk) {
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



/* 2i 060543F6, 3s-reloc: sf3 src/PASS08.c:935 Passive08_0056 */
void Passive08_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0xBC);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, (0x380));
        break;
    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 6:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060544C2, 3s-reloc: sf3 src/PASS08.c:966 Passive08_0057 */
void Passive08_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x22);
        break;
    case 2:
        SA_Term(wk, 0x39, -1, 0x3B, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054526, 3s-reloc: sf3 src/PASS08.c:988 Passive08_0058 */
void Passive08_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054544, 3s-near: sf3 src/PASS08.c:1001 Passive08_0059 */
void Passive08_0059(PLW* wk) {
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



/* 2i 06054572, 3s-near: sf3 src/PASS08.c:1017 Passive08_0060 */
void Passive08_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x3A);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060545B2, 3s-near: sf3 src/PASS08.c:1033 Passive08_0061 */
void Passive08_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060545E8, 3s-near: sf3 src/PASS08.c:1052 Passive08_0062 */
void Passive08_0062(PLW* wk) {
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



/* 2i 0605464A, 3s-reloc: sf3 src/PASS08.c:1068 Passive08_0063 */
void Passive08_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054696, 3s-reloc: sf3 src/PASS08.c:1084 Passive08_0064 */
void Passive08_0064(PLW* wk) {
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



/* 2i 060546C2, 3s-reloc: sf3 src/PASS08.c:1100 Passive08_0065 */
void Passive08_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054758, 3s-near: sf3 src/PASS08.c:1119 Passive08_0066 */
void Passive08_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Walk(wk, 0, 0x10, 0);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 4:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 6:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 7:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060547FA, 3s-reloc: sf3 src/PASS08.c:1153 Passive08_0067 */
void Passive08_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605483A, 3s-reloc: sf3 src/PASS08.c:1169 Passive08_0068 */
void Passive08_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x7B, 2);
        break;
    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054870, 3s-reloc: sf3 src/PASS08.c:1188 Passive08_0069 */
void Passive08_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054890, 3s-reloc: sf3 src/PASS08.c:1201 Passive08_0070 */
void Passive08_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 0xB, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054922, 3s-exact: sf3 src/PASS08.c:1220 Passive08_0071 */
void Passive08_0071(PLW* wk) {
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



/* 2i 0605494A, 3s-exact: sf3 src/PASS08.c:1236 Passive08_0072 */
void Passive08_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 2:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054980, 3s-exact: sf3 src/PASS08.c:1255 Passive08_0073 */
void Passive08_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060549A0, 3s-reloc: sf3 src/PASS08.c:1268 Passive08_0074 */
void Passive08_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054A16, 3s-exact: sf3 src/PASS08.c:1284 Passive08_0075 */
void Passive08_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 0, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xb, (0x82));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1c, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054A74, 3s-exact: sf3 src/PASS08.c:1303 Passive08_0076 */
void Passive08_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054AA0, 3s-exact: sf3 src/PASS08.c:1319 Passive08_0077 */
void Passive08_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054AC0, 3s-reloc: sf3 src/PASS08.c:1332 Passive08_0078 */
void Passive08_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Branch_Unit_Area(wk, 6, 0x55, 0x2F, 0x1B, 0x25);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054B40, 3s-exact: sf3 src/PASS08.c:1351 Passive08_0079 */
void Passive08_0079(PLW* wk) {
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



/* 2i 06054B96, 3s-reloc: sf3 src/PASS08.c:1370 Passive08_0080 */
void Passive08_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054C28, 3s-exact: sf3 src/PASS08.c:1389 Passive08_0081 */
void Passive08_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054C98, 3s-reloc: sf3 src/PASS08.c:1408 Passive08_0082 */
void Passive08_0082(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054D62, 3s-exact: sf3 src/PASS08.c:1436 Passive08_0083 */
void Passive08_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054D84, 3s-exact: sf3 src/PASS08.c:1449 Passive08_0084 */
void Passive08_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054DA6, 3s-exact: sf3 src/PASS08.c:1462 Passive08_0085 */
void Passive08_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054DC8, 3s-exact: sf3 src/PASS08.c:1475 Passive08_0086 */
void Passive08_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054DE8, 3s-exact: sf3 src/PASS08.c:1488 Passive08_0087 */
void Passive08_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054E1A, 3s-reloc: sf3 src/PASS08.c:1501 Passive08_0088 */
void Passive08_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054E5C, 3s-exact: sf3 src/PASS08.c:1514 Passive08_0089 */
void Passive08_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xc, 0, -1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1c, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054EAE, 3s-exact: sf3 src/PASS08.c:1533 Passive08_0090 */
void Passive08_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054F12, 3s-reloc: sf3 src/PASS08.c:1555 Passive08_0091 */
void Passive08_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06054F94, 3s-exact: sf3 src/PASS08.c:1577 Passive08_0092 */
void Passive08_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055010, 3s-reloc: sf3 src/PASS08.c:1602 Passive08_0093 */
void Passive08_0093(PLW* wk) {
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



/* 2i 0605508C, 3s-exact: sf3 src/PASS08.c:1621 Passive08_0094 */
void Passive08_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
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



/* 2i 060550DA, 3s-exact: sf3 src/PASS08.c:1640 Passive08_0095 */
void Passive08_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605511A, 3s-exact: sf3 src/PASS08.c:1656 Passive08_0096 */
void Passive08_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605515A, 3s-reloc: sf3 src/PASS08.c:1672 Passive08_0097 */
void Passive08_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060551C4, 3s-exact: sf3 src/PASS08.c:1688 Passive08_0098 */
void Passive08_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060551E4, 3s-exact: sf3 src/PASS08.c:1701 Passive08_0099 */
void Passive08_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055204, 3s-exact: sf3 src/PASS08.c:1714 Passive08_0100 */
void Passive08_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055224, 3s-reloc: sf3 src/PASS08.c:1727 Passive08_0101 */
void Passive08_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055298, 3s-exact: sf3 src/PASS08.c:1746 Passive08_0102 */
void Passive08_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, -1, -1, -1);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055306, 3s-exact: sf3 src/PASS08.c:1765 Passive08_0103 */
void Passive08_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055346, 3s-reloc: sf3 src/PASS08.c:1781 Passive08_0104 */
void Passive08_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060553A8, 3s-exact: sf3 src/PASS08.c:1797 Passive08_0105 */
void Passive08_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3f, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1c, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605541C, 3s-exact: sf3 src/PASS08.c:1819 Passive08_0106 */
void Passive08_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055460, 3s-reloc: sf3 src/PASS08.c:1832 Passive08_0107 */
void Passive08_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060554DE, 3s-exact: sf3 src/PASS08.c:1848 Passive08_0108 */
void Passive08_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605552C, 3s-exact: sf3 src/PASS08.c:1864 Passive08_0109 */
void Passive08_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 0, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605557A, 3s-exact: sf3 src/PASS08.c:1880 Passive08_0110 */
void Passive08_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060555DE, 3s-exact: sf3 src/PASS08.c:1902 Passive08_0111 */
void Passive08_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055642, 3s-exact: sf3 src/PASS08.c:1924 Passive08_0112 */
void Passive08_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055662, 3s-reloc: sf3 src/PASS08.c:1937 Passive08_0113 */
void Passive08_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060556A6, 3s-exact: sf3 src/PASS08.c:1950 Passive08_0114 */
void Passive08_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055702, 3s-reloc: sf3 src/PASS08.c:1969 Passive08_0115 */
void Passive08_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;
    case 3:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060557A4, 3s-exact: sf3 src/PASS08.c:1991 Passive08_0116 */
void Passive08_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060557C2, 3s-exact: sf3 src/PASS08.c:2004 Passive08_0117 */
void Passive08_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055802, 3s-exact: sf3 src/PASS08.c:2020 Passive08_0118 */
void Passive08_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055842, 3s-reloc: sf3 src/PASS08.c:2036 Passive08_0119 */
void Passive08_0119(PLW* wk) {
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



/* 2i 0605589C, 3s-exact: sf3 src/PASS08.c:2052 Passive08_0120 */
void Passive08_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060558E0, 3s-exact: sf3 src/PASS08.c:2071 Passive08_0121 */
void Passive08_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055900, 3s-exact: sf3 src/PASS08.c:2084 Passive08_0122 */
void Passive08_0122(PLW* wk) {
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



/* 2i 0605592C, 3s-reloc: sf3 src/PASS08.c:2100 Passive08_0123 */
void Passive08_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055988, 3s-exact: sf3 src/PASS08.c:2119 Passive08_0124 */
void Passive08_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060559D2, 3s-exact: sf3 src/PASS08.c:2138 Passive08_0125 */
void Passive08_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055A20, 3s-reloc: sf3 src/PASS08.c:2157 Passive08_0126 */
void Passive08_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x82));
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055A96, 3s-exact: sf3 src/PASS08.c:2179 Passive08_0127 */
void Passive08_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055B1A, 3s-reloc: sf3 src/PASS08.c:2204 Passive08_0128 */
void Passive08_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055BBC, 3s-exact: sf3 src/PASS08.c:2226 Passive08_0129 */
void Passive08_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055C48, 3s-reloc: sf3 src/PASS08.c:2254 Passive08_0130 */
void Passive08_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055CF2, 3s-exact: sf3 src/PASS08.c:2276 Passive08_0131 */
void Passive08_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055D3A, 3s-reloc: sf3 src/PASS08.c:2292 Passive08_0132 */
void Passive08_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055DCA, 3s-exact: sf3 src/PASS08.c:2311 Passive08_0133 */
void Passive08_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055E48, 3s-reloc: sf3 src/PASS08.c:2333 Passive08_0134 */
void Passive08_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055EE8, 3s-exact: sf3 src/PASS08.c:2355 Passive08_0135 */
void Passive08_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8050, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055F36, 3s-exact: sf3 src/PASS08.c:2371 Passive08_0136 */
void Passive08_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055F88, 3s-reloc: sf3 src/PASS08.c:2390 Passive08_0137 */
void Passive08_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06055FFC, 3s-exact: sf3 src/PASS08.c:2409 Passive08_0138 */
void Passive08_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605604A, 3s-exact: sf3 src/PASS08.c:2428 Passive08_0139 */
void Passive08_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060560AE, 3s-exact: sf3 src/PASS08.c:2450 Passive08_0140 */
void Passive08_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056112, 3s-exact: sf3 src/PASS08.c:2472 Passive08_0141 */
void Passive08_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 6:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060561A2, 3s-reloc: sf3 src/PASS08.c:2503 Passive08_0142 */
void Passive08_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 8, -1);
        break;
    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 6:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056272, 3s-exact: sf3 src/PASS08.c:2534 Passive08_0143 */
void Passive08_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    case 4:
        Pierce_On(wk);
        break;
    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 6:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605630A, 3s-exact: sf3 src/PASS08.c:2565 Passive08_0144 */
void Passive08_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605638E, 3s-reloc: sf3 src/PASS08.c:2590 Passive08_0145 */
void Passive08_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605644C, 3s-exact: sf3 src/PASS08.c:2615 Passive08_0146 */
void Passive08_0146(PLW* wk) {
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



/* 2i 060564A2, 3s-near: sf3 src/PASS08.c:2634 Passive08_0147 */
void Passive08_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060564DE, 3s-near: sf3 src/PASS08.c:2650 Passive08_0148 */
void Passive08_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xE, 0x1F, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 0xE, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056526, 3s-near: sf3 src/PASS08.c:2666 Passive08_0149 */
void Passive08_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xE, 0x1F, 9, -1);
        break;
    case 1:
        Command_Attack(wk, 0xE, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605656E, 3s-near: sf3 src/PASS08.c:2682 Passive08_0150 */
void Passive08_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x95);
        break;
    case 1:
        Command_Attack(wk, 0xE, 0x1F, 0xA, 0x380);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060565DA, 3s-exact: sf3 src/PASS08.c:2701 Passive08_0151 */
void Passive08_0151(PLW* wk) {
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
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056658, 3s-reloc: sf3 src/PASS08.c:2729 Passive08_0152 */
void Passive08_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060566DE, 3s-exact: sf3 src/PASS08.c:2751 Passive08_0153 */
void Passive08_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056734, 3s-exact: sf3 src/PASS08.c:2770 Passive08_0154 */
void Passive08_0154(PLW* wk) {
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



/* 2i 06056760, 3s-reloc: sf3 src/PASS08.c:2786 Passive08_0155 */
void Passive08_0155(PLW* wk) {
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



/* 2i 060567B4, 3s-exact: sf3 src/PASS08.c:2802 Passive08_0156 */
void Passive08_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056802, 3s-reloc: sf3 src/PASS08.c:2821 Passive08_0157 */
void Passive08_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 4:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060568D8, 3s-exact: sf3 src/PASS08.c:2849 Passive08_0158 */
void Passive08_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, -1, -1, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 4:
        SA_Term(wk, 0x39, 0x3A, -1, 0);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056972, 3s-reloc: sf3 src/PASS08.c:2877 Passive08_0159 */
void Passive08_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    case 5:
        Pierce_On(wk);
        break;
    case 6:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 7:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056A4A, 3s-exact: sf3 src/PASS08.c:2911 Passive08_0160 */
void Passive08_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056AB2, 3s-reloc: sf3 src/PASS08.c:2930 Passive08_0161 */
void Passive08_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056B54, 3s-exact: sf3 src/PASS08.c:2949 Passive08_0162 */
void Passive08_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056BC0, 3s-reloc: sf3 src/PASS08.c:2971 Passive08_0163 */
void Passive08_0163(PLW* wk) {
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
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056C70, 3s-exact: sf3 src/PASS08.c:2996 Passive08_0164 */
void Passive08_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056CDC, 3s-reloc: sf3 src/PASS08.c:3018 Passive08_0165 */
void Passive08_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056D6C, 3s-exact: sf3 src/PASS08.c:3037 Passive08_0166 */
void Passive08_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056DC8, 3s-reloc: sf3 src/PASS08.c:3056 Passive08_0167 */
void Passive08_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x202));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056E6A, 3s-exact: sf3 src/PASS08.c:3078 Passive08_0168 */
void Passive08_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056E8C, 3s-exact: sf3 src/PASS08.c:3091 Passive08_0169 */
void Passive08_0169(PLW* wk) {
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



/* 2i 06056EB6, 3s-exact: sf3 src/PASS08.c:3107 Passive08_0170 */
void Passive08_0170(PLW* wk) {
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



/* 2i 06056EE2, 3s-exact: sf3 src/PASS08.c:3123 Passive08_0171 */
void Passive08_0171(PLW* wk) {
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



/* 2i 06056F0E, 3s-reloc: sf3 src/PASS08.c:3139 Passive08_0172 */
void Passive08_0172(PLW* wk) {
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



/* 2i 06056F5E, 3s-exact: sf3 src/PASS08.c:3155 Passive08_0173 */
void Passive08_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, -1, 0x3B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06056F90, 3s-reloc: sf3 src/PASS08.c:3168 Passive08_0174 */
void Passive08_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3f, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 0xc, 0x1e, 9, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x39, 0x3a, 0x3b, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057050, 3s-exact: sf3 src/PASS08.c:3196 Passive08_0175 */
void Passive08_0175(PLW* wk) {
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



/* 2i 0605709A, 3s-exact: sf3 src/PASS08.c:3215 Passive08_0176 */
void Passive08_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605710C, 3s-reloc: sf3 src/PASS08.c:3240 Passive08_0177 */
void Passive08_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x100));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057188, 3s-exact: sf3 src/PASS08.c:3259 Passive08_0178 */
void Passive08_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;
    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057206, 3s-reloc: sf3 src/PASS08.c:3281 Passive08_0179 */
void Passive08_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057264, 3s-exact: sf3 src/PASS08.c:3297 Passive08_0180 */
void Passive08_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060572D2, 3s-exact: sf3 src/PASS08.c:3319 Passive08_0181 */
void Passive08_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057322, 3s-reloc: sf3 src/PASS08.c:3338 Passive08_0182 */
void Passive08_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057360, 3s-exact: sf3 src/PASS08.c:3351 Passive08_0183 */
void Passive08_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060573C8, 3s-reloc: sf3 src/PASS08.c:3370 Passive08_0184 */
void Passive08_0184(PLW* wk) {
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
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605748A, 3s-exact: sf3 src/PASS08.c:3398 Passive08_0185 */
void Passive08_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060574AA, 3s-exact: sf3 src/PASS08.c:3411 Passive08_0186 */
void Passive08_0186(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057512, 3s-reloc: sf3 src/PASS08.c:3433 Passive08_0187 */
void Passive08_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1d, 9, -1);
        break;
    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605759E, 3s-exact: sf3 src/PASS08.c:3455 Passive08_0188 */
void Passive08_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057606, 3s-exact: sf3 src/PASS08.c:3477 Passive08_0189 */
void Passive08_0189(PLW* wk) {
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



/* 2i 06057652, 3s-exact: sf3 src/PASS08.c:3493 Passive08_0190 */
void Passive08_0190(PLW* wk) {
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



/* 2i 0605769E, 3s-exact: sf3 src/PASS08.c:3509 Passive08_0191 */
void Passive08_0191(PLW* wk) {
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



/* 2i 060576E6, 3s-reloc: sf3 src/PASS08.c:3525 Passive08_0192 */
void Passive08_0192(PLW* wk) {
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



/* 2i 06057758, 3s-exact: sf3 src/PASS08.c:3541 Passive08_0193 */
void Passive08_0193(PLW* wk) {
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



/* 2i 060577A2, 3s-exact: sf3 src/PASS08.c:3557 Passive08_0194 */
void Passive08_0194(PLW* wk) {
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



/* 2i 060577E8, 3s-reloc: sf3 src/PASS08.c:3573 Passive08_0195 */
void Passive08_0195(PLW* wk) {
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



/* 2i 06057854, 3s-exact: sf3 src/PASS08.c:3589 Passive08_0196 */
void Passive08_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060578A0, 3s-exact: sf3 src/PASS08.c:3605 Passive08_0197 */
void Passive08_0197(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060578E4, 3s-exact: sf3 src/PASS08.c:3621 Passive08_0198 */
void Passive08_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605792A, 3s-reloc: sf3 src/PASS08.c:3637 Passive08_0199 */
void Passive08_0199(PLW* wk) {
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



/* 2i 0605798A, 3s-exact: sf3 src/PASS08.c:3653 Passive08_0200 */
void Passive08_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057A02, 3s-exact: sf3 src/PASS08.c:3678 Passive08_0201 */
void Passive08_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    case 2:
        Wait(wk, 5);
        break;
    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057A64, 3s-exact: sf3 src/PASS08.c:3700 Passive08_0202 */
void Passive08_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057ABA, 3s-exact: sf3 src/PASS08.c:3719 Passive08_0203 */
void Passive08_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057AF8, 3s-exact: sf3 src/PASS08.c:3735 Passive08_0204 */
void Passive08_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 6);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057B36, 3s-exact: sf3 src/PASS08.c:3751 Passive08_0205 */
void Passive08_0205(PLW* wk) {
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



/* 2i 06057B5E, 3s-reloc: sf3 src/PASS08.c:3767 Passive08_0206 */
void Passive08_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, 0x200, 1, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057BCE, 3s-exact: sf3 src/PASS08.c:3780 Passive08_0207 */
void Passive08_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8050, 8, 0x100, 2, -1, 0x8050, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057C28, 3s-exact: sf3 src/PASS08.c:3796 Passive08_0208 */
void Passive08_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8050, 8, 0x200, 2, -1, 0x8050, 0x200);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xAF, 0xB0, 0x78, 0x7B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057C8C, 3s-near: sf3 src/PASS08.c:3812 Passive08_0209 */
void Passive08_0209(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8050, 8, 0x40, 2, -1, 0x8050, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06057D0A, 3s-reloc: sf3 src/PASS08.c:3828 Passive08_0210 */
void Passive08_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8050, 8, 0x100, 2, -1, 0x8050, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

