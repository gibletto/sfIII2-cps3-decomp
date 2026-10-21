/*
 * PASS07.C  CPU passive patterns for character 7 (Ibuki)
 *
 * Passive07 is the CPU passive (defensive) routine for character 7, called through
 * Com_Passive's table by character number. It runs the current pattern chosen by Pattern_Index
 * from Passive07_Tbl.
 * The 214 Passive07_xxxx routines are the pattern steps: each is a switch on CP_Index that calls
 * the Com_Sub building blocks (guards, waits for get-up, normal and command attacks, lever
 * releases, reaction terms such as EM_Term) one step at a time and finishes with End_Pattern.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "PASS07.h"



/* 2i 0604EC80, 3s-exact: sf3 src/PASS07.c:21 Passive07 */
void Passive07(PLW* wk) {
    Passive07_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0604EC98, 3s-exact: sf3 src/PASS07.c:27 Passive07_0000 */
void Passive07_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ECCC, 3s-exact: sf3 src/PASS07.c:40 Passive07_0001 */
void Passive07_0001(PLW* wk) {
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



/* 2i 0604ECF4, 3s-exact: sf3 src/PASS07.c:56 Passive07_0002 */
void Passive07_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604ED12, 3s-exact: sf3 src/PASS07.c:69 Passive07_0003 */
void Passive07_0003(PLW* wk) {
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



/* 2i 0604ED5E, 3s-reloc: sf3 src/PASS07.c:85 Passive07_0004 */
void Passive07_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, 0x28, 7, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604EDD6, 3s-reloc: sf3 src/PASS07.c:101 Passive07_0005 */
void Passive07_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Jump(wk, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604EE02, 3s-near: sf3 src/PASS07.c:117 Passive07_0006 */
void Passive07_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604EE64, 3s-near: sf3 src/PASS07.c:139 Passive07_0007 */
void Passive07_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604EEEE, 3s-reloc: sf3 src/PASS07.c:161 Passive07_0008 */
void Passive07_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x80);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604EF4A, 3s-reloc: sf3 src/PASS07.c:183 Passive07_0009 */
void Passive07_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604EFC0, 3s-exact: sf3 src/PASS07.c:199 Passive07_0010 */
void Passive07_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 4:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    case 5:
        Command_Attack(wk, 8, 0x20, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F04A, 3s-exact: sf3 src/PASS07.c:227 Passive07_0011 */
void Passive07_0011(PLW* wk) {
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



/* 2i 0604F08E, 3s-reloc: sf3 src/PASS07.c:243 Passive07_0012 */
void Passive07_0012(PLW* wk) {
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



/* 2i 0604F0FE, 3s-exact: sf3 src/PASS07.c:259 Passive07_0013 */
void Passive07_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F12A, 3s-exact: sf3 src/PASS07.c:275 Passive07_0014 */
void Passive07_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F156, 3s-exact: sf3 src/PASS07.c:291 Passive07_0015 */
void Passive07_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
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



/* 2i 0604F18E, 3s-reloc: sf3 src/PASS07.c:310 Passive07_0016 */
void Passive07_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F1DC, 3s-reloc: sf3 src/PASS07.c:326 Passive07_0017 */
void Passive07_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F208, 3s-reloc: sf3 src/PASS07.c:342 Passive07_0018 */
void Passive07_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F23A, 3s-reloc: sf3 src/PASS07.c:355 Passive07_0019 */
void Passive07_0019(PLW* wk) {
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



/* 2i 0604F27A, 3s-near: sf3 src/PASS07.c:371 Passive07_0020 */
void Passive07_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F2A8, 3s-reloc: sf3 src/PASS07.c:387 Passive07_0021 */
void Passive07_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F2F4, 3s-exact: sf3 src/PASS07.c:403 Passive07_0022 */
void Passive07_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F322, 3s-exact: sf3 src/PASS07.c:419 Passive07_0023 */
void Passive07_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F362, 3s-exact: sf3 src/PASS07.c:435 Passive07_0024 */
void Passive07_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x80);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F3C0, 3s-reloc: sf3 src/PASS07.c:457 Passive07_0025 */
void Passive07_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 0xa, -1, -1, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F428, 3s-exact: sf3 src/PASS07.c:470 Passive07_0026 */
void Passive07_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 10, -1, -1, 0x40, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F46E, 3s-exact: sf3 src/PASS07.c:483 Passive07_0027 */
void Passive07_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x2E);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 10, -1, -1, 0x40, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F4C6, 3s-exact: sf3 src/PASS07.c:499 Passive07_0028 */
void Passive07_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F4DA, 3s-exact: sf3 src/PASS07.c:509 Passive07_0029 */
void Passive07_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F52C, 3s-reloc: sf3 src/PASS07.c:528 Passive07_0030 */
void Passive07_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Lever_Attack(wk, 8, 0x1E, 10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F584, 3s-exact: sf3 src/PASS07.c:547 Passive07_0031 */
void Passive07_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Lever_Attack(wk, 9, 0, 0x200);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F5CA, 3s-exact: sf3 src/PASS07.c:569 Passive07_0032 */
void Passive07_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xB, 0, 0x100);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F606, 3s-reloc: sf3 src/PASS07.c:588 Passive07_0033 */
void Passive07_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F650, 3s-exact: sf3 src/PASS07.c:604 Passive07_0034 */
void Passive07_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F6A6, 3s-exact: sf3 src/PASS07.c:623 Passive07_0035 */
void Passive07_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F6D8, 3s-exact: sf3 src/PASS07.c:636 Passive07_0036 */
void Passive07_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F70A, 3s-exact: sf3 src/PASS07.c:649 Passive07_0037 */
void Passive07_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F73C, 3s-exact: sf3 src/PASS07.c:662 Passive07_0038 */
void Passive07_0038(PLW* wk) {
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



/* 2i 0604F78A, 3s-exact: sf3 src/PASS07.c:678 Passive07_0039 */
void Passive07_0039(PLW* wk) {
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



/* 2i 0604F7D8, 3s-exact: sf3 src/PASS07.c:694 Passive07_0040 */
void Passive07_0040(PLW* wk) {
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



/* 2i 0604F826, 3s-reloc: sf3 src/PASS07.c:710 Passive07_0041 */
void Passive07_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, -1, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F8A6, 3s-exact: sf3 src/PASS07.c:729 Passive07_0042 */
void Passive07_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F8C4, 3s-exact: sf3 src/PASS07.c:742 Passive07_0043 */
void Passive07_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x40, 8, 0x100, 0, 0x8040, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F906, 3s-exact: sf3 src/PASS07.c:755 Passive07_0044 */
void Passive07_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x200, 0, 0x8040, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F948, 3s-exact: sf3 src/PASS07.c:768 Passive07_0045 */
void Passive07_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F97A, 3s-reloc: sf3 src/PASS07.c:781 Passive07_0046 */
void Passive07_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604F9CE, 3s-exact: sf3 src/PASS07.c:794 Passive07_0047 */
void Passive07_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FA00, 3s-exact: sf3 src/PASS07.c:807 Passive07_0048 */
void Passive07_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
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



/* 2i 0604FA48, 3s-exact: sf3 src/PASS07.c:826 Passive07_0049 */
void Passive07_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, -1, 6, 1, -1);
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



/* 2i 0604FA90, 3s-exact: sf3 src/PASS07.c:845 Passive07_0050 */
void Passive07_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FAD0, 3s-reloc: sf3 src/PASS07.c:861 Passive07_0051 */
void Passive07_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FB32, 3s-exact: sf3 src/PASS07.c:880 Passive07_0052 */
void Passive07_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FB9A, 3s-reloc: sf3 src/PASS07.c:899 Passive07_0053 */
void Passive07_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FC2C, 3s-exact: sf3 src/PASS07.c:918 Passive07_0054 */
void Passive07_0054(PLW* wk) {
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



/* 2i 0604FC64, 3s-exact: sf3 src/PASS07.c:937 Passive07_0055 */
void Passive07_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Wait(wk, 4);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FC9C, 3s-reloc: sf3 src/PASS07.c:956 Passive07_0056 */
void Passive07_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, -1, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FD28, 3s-reloc: sf3 src/PASS07.c:978 Passive07_0057 */
void Passive07_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x22);
        break;
    case 2:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FD8C, 3s-near: sf3 src/PASS07.c:1000 Passive07_0058 */
void Passive07_0058(PLW* wk) {
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



/* 2i 0604FDBA, 3s-reloc: sf3 src/PASS07.c:1016 Passive07_0059 */
void Passive07_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, 0x70, -1, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FE02, 3s-reloc: sf3 src/PASS07.c:1029 Passive07_0060 */
void Passive07_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, 0x70, -1, 0x40, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FE4A, 3s-reloc: sf3 src/PASS07.c:1042 Passive07_0061 */
void Passive07_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;
    case 1:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FE80, 3s-reloc: sf3 src/PASS07.c:1061 Passive07_0062 */
void Passive07_0062(PLW* wk) {
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



/* 2i 0604FED6, 3s-near: sf3 src/PASS07.c:1077 Passive07_0063 */
void Passive07_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 5:
        Normal_Attack(wk, 8, (0x202));
        break;
    case 6:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0604FF76, 3s-reloc: sf3 src/PASS07.c:1108 Passive07_0064 */
void Passive07_0064(PLW* wk) {
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



/* 2i 0604FFD0, 3s-reloc: sf3 src/PASS07.c:1124 Passive07_0065 */
void Passive07_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050038, 3s-reloc: sf3 src/PASS07.c:1143 Passive07_0066 */
void Passive07_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050078, 3s-near: sf3 src/PASS07.c:1159 Passive07_0067 */
void Passive07_0067(PLW* wk) {
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



/* 2i 060500D8, 3s-reloc: sf3 src/PASS07.c:1175 Passive07_0068 */
void Passive07_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 10, 0x380);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605010A, 3s-reloc: sf3 src/PASS07.c:1188 Passive07_0069 */
void Passive07_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605012A, 3s-near: sf3 src/PASS07.c:1201 Passive07_0070 */
void Passive07_0070(PLW* wk) {
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



/* 2i 06050192, 3s-near: sf3 src/PASS07.c:1220 Passive07_0071 */
void Passive07_0071(PLW* wk) {
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



/* 2i 060501E8, 3s-reloc: sf3 src/PASS07.c:1236 Passive07_0072 */
void Passive07_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050212, 3s-reloc: sf3 src/PASS07.c:1252 Passive07_0073 */
void Passive07_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050232, 3s-reloc: sf3 src/PASS07.c:1265 Passive07_0074 */
void Passive07_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 6, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050276, 3s-reloc: sf3 src/PASS07.c:1281 Passive07_0075 */
void Passive07_0075(PLW* wk) {
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



/* 2i 060502FC, 3s-reloc: sf3 src/PASS07.c:1300 Passive07_0076 */
void Passive07_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050328, 3s-reloc: sf3 src/PASS07.c:1316 Passive07_0077 */
void Passive07_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050348, 3s-reloc: sf3 src/PASS07.c:1329 Passive07_0078 */
void Passive07_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Branch_Unit_Area(wk, 6, 0x55, 0x2F, 0x1B, 0x25);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050388, 3s-near: sf3 src/PASS07.c:1345 Passive07_0079 */
void Passive07_0079(PLW* wk) {
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



/* 2i 06050400, 3s-near: sf3 src/PASS07.c:1364 Passive07_0080 */
void Passive07_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050468, 3s-near: sf3 src/PASS07.c:1383 Passive07_0081 */
void Passive07_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050500, 3s-near: sf3 src/PASS07.c:1402 Passive07_0082 */
void Passive07_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x102);
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



/* 2i 0605059E, 3s-near: sf3 src/PASS07.c:1430 Passive07_0083 */
void Passive07_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060505C0, 3s-near: sf3 src/PASS07.c:1443 Passive07_0084 */
void Passive07_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050610, 3s-near: sf3 src/PASS07.c:1456 Passive07_0085 */
void Passive07_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050632, 3s-near: sf3 src/PASS07.c:1469 Passive07_0086 */
void Passive07_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 199, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050652, 3s-near: sf3 src/PASS07.c:1482 Passive07_0087 */
void Passive07_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050684, 3s-reloc: sf3 src/PASS07.c:1495 Passive07_0088 */
void Passive07_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060506A2, 3s-near: sf3 src/PASS07.c:1508 Passive07_0089 */
void Passive07_0089(PLW* wk) {
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



/* 2i 06050714, 3s-near: sf3 src/PASS07.c:1527 Passive07_0090 */
void Passive07_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050778, 3s-near: sf3 src/PASS07.c:1549 Passive07_0091 */
void Passive07_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050804, 3s-near: sf3 src/PASS07.c:1574 Passive07_0092 */
void Passive07_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Lever_Attack(wk, 0xC, 0, 0x100);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
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



/* 2i 06050880, 3s-reloc: sf3 src/PASS07.c:1599 Passive07_0093 */
void Passive07_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8080, 0x28, 7, 1, -1);
        break;
    case 1:
        Lever_Attack(wk, 9, 0, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060508FC, 3s-near: sf3 src/PASS07.c:1618 Passive07_0094 */
void Passive07_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
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



/* 2i 0605094A, 3s-near: sf3 src/PASS07.c:1637 Passive07_0095 */
void Passive07_0095(PLW* wk) {
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



/* 2i 0605098A, 3s-near: sf3 src/PASS07.c:1653 Passive07_0096 */
void Passive07_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060509CA, 3s-near: sf3 src/PASS07.c:1669 Passive07_0097 */
void Passive07_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050A34, 3s-reloc: sf3 src/PASS07.c:1685 Passive07_0098 */
void Passive07_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050A54, 3s-reloc: sf3 src/PASS07.c:1698 Passive07_0099 */
void Passive07_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050A74, 3s-reloc: sf3 src/PASS07.c:1711 Passive07_0100 */
void Passive07_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    case 1:
        Wait(wk, 0x10);
        break;
    case 2:
        Walk(wk, 0, 0x18, -1);
        break;
    case 3:
        Walk(wk, 1, 0x18, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050ACC, 3s-reloc: sf3 src/PASS07.c:1733 Passive07_0101 */
void Passive07_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x102);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050B42, 3s-reloc: sf3 src/PASS07.c:1752 Passive07_0102 */
void Passive07_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, -1, -1, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050BB0, 3s-reloc: sf3 src/PASS07.c:1771 Passive07_0103 */
void Passive07_0103(PLW* wk) {
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



/* 2i 06050BF0, 3s-reloc: sf3 src/PASS07.c:1787 Passive07_0104 */
void Passive07_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050C50, 3s-reloc: sf3 src/PASS07.c:1803 Passive07_0105 */
void Passive07_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3b, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8030, 6, 1, -1);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1c, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050CC4, 3s-reloc: sf3 src/PASS07.c:1825 Passive07_0106 */
void Passive07_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050D08, 3s-reloc: sf3 src/PASS07.c:1838 Passive07_0107 */
void Passive07_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050D86, 3s-reloc: sf3 src/PASS07.c:1854 Passive07_0108 */
void Passive07_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x8038, 6, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050DD4, 3s-reloc: sf3 src/PASS07.c:1870 Passive07_0109 */
void Passive07_0109(PLW* wk) {
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



/* 2i 06050E22, 3s-reloc: sf3 src/PASS07.c:1886 Passive07_0110 */
void Passive07_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050E86, 3s-reloc: sf3 src/PASS07.c:1908 Passive07_0111 */
void Passive07_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050EEA, 3s-reloc: sf3 src/PASS07.c:1930 Passive07_0112 */
void Passive07_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050F0A, 3s-reloc: sf3 src/PASS07.c:1943 Passive07_0113 */
void Passive07_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06050F84, 3s-exact: sf3 src/PASS07.c:1962 Passive07_0114 */
void Passive07_0114(PLW* wk) {
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



/* 2i 06050FE0, 3s-reloc: sf3 src/PASS07.c:1981 Passive07_0115 */
void Passive07_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605106C, 3s-exact: sf3 src/PASS07.c:2000 Passive07_0116 */
void Passive07_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605108A, 3s-exact: sf3 src/PASS07.c:2013 Passive07_0117 */
void Passive07_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060510CA, 3s-exact: sf3 src/PASS07.c:2029 Passive07_0118 */
void Passive07_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605110A, 3s-exact: sf3 src/PASS07.c:2045 Passive07_0119 */
void Passive07_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605112C, 3s-reloc: sf3 src/PASS07.c:2058 Passive07_0120 */
void Passive07_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051192, 3s-exact: sf3 src/PASS07.c:2077 Passive07_0121 */
void Passive07_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060511B2, 3s-exact: sf3 src/PASS07.c:2090 Passive07_0122 */
void Passive07_0122(PLW* wk) {
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



/* 2i 060511DE, 3s-exact: sf3 src/PASS07.c:2106 Passive07_0123 */
void Passive07_0123(PLW* wk) {
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



/* 2i 06051224, 3s-reloc: sf3 src/PASS07.c:2125 Passive07_0124 */
void Passive07_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051286, 3s-exact: sf3 src/PASS07.c:2144 Passive07_0125 */
void Passive07_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        SA_Term(wk, 0x35, -1, 0x37, 0);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060512D4, 3s-reloc: sf3 src/PASS07.c:2163 Passive07_0126 */
void Passive07_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605134C, 3s-exact: sf3 src/PASS07.c:2185 Passive07_0127 */
void Passive07_0127(PLW* wk) {
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
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060513D0, 3s-reloc: sf3 src/PASS07.c:2210 Passive07_0128 */
void Passive07_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051472, 3s-exact: sf3 src/PASS07.c:2232 Passive07_0129 */
void Passive07_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 5:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060514FE, 3s-reloc: sf3 src/PASS07.c:2260 Passive07_0130 */
void Passive07_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060515A0, 3s-exact: sf3 src/PASS07.c:2282 Passive07_0131 */
void Passive07_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060515E8, 3s-reloc: sf3 src/PASS07.c:2298 Passive07_0132 */
void Passive07_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051674, 3s-exact: sf3 src/PASS07.c:2317 Passive07_0133 */
void Passive07_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060516F2, 3s-reloc: sf3 src/PASS07.c:2339 Passive07_0134 */
void Passive07_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051784, 3s-exact: sf3 src/PASS07.c:2358 Passive07_0135 */
void Passive07_0135(PLW* wk) {
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



/* 2i 060517D2, 3s-exact: sf3 src/PASS07.c:2374 Passive07_0136 */
void Passive07_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
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



/* 2i 06051824, 3s-reloc: sf3 src/PASS07.c:2393 Passive07_0137 */
void Passive07_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060518A0, 3s-exact: sf3 src/PASS07.c:2412 Passive07_0138 */
void Passive07_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605190C, 3s-reloc: sf3 src/PASS07.c:2437 Passive07_0139 */
void Passive07_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051990, 3s-exact: sf3 src/PASS07.c:2459 Passive07_0140 */
void Passive07_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060519F4, 3s-exact: sf3 src/PASS07.c:2481 Passive07_0141 */
void Passive07_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051A34, 3s-exact: sf3 src/PASS07.c:2497 Passive07_0142 */
void Passive07_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8040, 6, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1E, 8, -1);
        break;
    case 3:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051AA8, 3s-exact: sf3 src/PASS07.c:2519 Passive07_0143 */
void Passive07_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051B16, 3s-reloc: sf3 src/PASS07.c:2541 Passive07_0144 */
void Passive07_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8008, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 4:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051BCC, 3s-exact: sf3 src/PASS07.c:2566 Passive07_0145 */
void Passive07_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
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
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051C50, 3s-exact: sf3 src/PASS07.c:2591 Passive07_0146 */
void Passive07_0146(PLW* wk) {
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



/* 2i 06051CA6, 3s-reloc: sf3 src/PASS07.c:2610 Passive07_0147 */
void Passive07_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 5:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051D4A, 3s-exact: sf3 src/PASS07.c:2638 Passive07_0148 */
void Passive07_0148(PLW* wk) {
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
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051D9E, 3s-reloc: sf3 src/PASS07.c:2660 Passive07_0149 */
void Passive07_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 4:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051E22, 3s-exact: sf3 src/PASS07.c:2685 Passive07_0150 */
void Passive07_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051E76, 3s-reloc: sf3 src/PASS07.c:2707 Passive07_0151 */
void Passive07_0151(PLW* wk) {
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
        SA_Term(wk, 0x35, 0x36, -1, 0);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051F14, 3s-exact: sf3 src/PASS07.c:2735 Passive07_0152 */
void Passive07_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;
    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051F80, 3s-exact: sf3 src/PASS07.c:2757 Passive07_0153 */
void Passive07_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06051FD6, 3s-reloc: sf3 src/PASS07.c:2776 Passive07_0154 */
void Passive07_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052030, 3s-exact: sf3 src/PASS07.c:2792 Passive07_0155 */
void Passive07_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 2, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605205C, 3s-exact: sf3 src/PASS07.c:2808 Passive07_0156 */
void Passive07_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060520AA, 3s-reloc: sf3 src/PASS07.c:2827 Passive07_0157 */
void Passive07_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 2:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, -1, 0);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052174, 3s-reloc: sf3 src/PASS07.c:2855 Passive07_0158 */
void Passive07_0158(PLW* wk) {
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
        SA_Term(wk, 0x35, 0x36, -1, 0);
        break;
    case 5:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052238, 3s-exact: sf3 src/PASS07.c:2883 Passive07_0159 */
void Passive07_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605229C, 3s-exact: sf3 src/PASS07.c:2905 Passive07_0160 */
void Passive07_0160(PLW* wk) {
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



/* 2i 06052304, 3s-reloc: sf3 src/PASS07.c:2924 Passive07_0161 */
void Passive07_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, 0x8050, -1, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605239C, 3s-reloc: sf3 src/PASS07.c:2943 Passive07_0162 */
void Passive07_0162(PLW* wk) {
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
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 5:
        Normal_Attack(wk, 9, (0x202));
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    case 7:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052496, 3s-exact: sf3 src/PASS07.c:2977 Passive07_0163 */
void Passive07_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605251E, 3s-reloc: sf3 src/PASS07.c:3002 Passive07_0164 */
void Passive07_0164(PLW* wk) {
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



/* 2i 0605259A, 3s-exact: sf3 src/PASS07.c:3018 Passive07_0165 */
void Passive07_0165(PLW* wk) {
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



/* 2i 06052602, 3s-reloc: sf3 src/PASS07.c:3037 Passive07_0166 */
void Passive07_0166(PLW* wk) {
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



/* 2i 06052678, 3s-exact: sf3 src/PASS07.c:3053 Passive07_0167 */
void Passive07_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x200, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 3:
        Search_Back_Term(wk, 0x30, 1, -1);
        break;
    case 4:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605270A, 3s-exact: sf3 src/PASS07.c:3078 Passive07_0168 */
void Passive07_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605272C, 3s-exact: sf3 src/PASS07.c:3091 Passive07_0169 */
void Passive07_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605274C, 3s-reloc: sf3 src/PASS07.c:3104 Passive07_0170 */
void Passive07_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060527A6, 3s-exact: sf3 src/PASS07.c:3120 Passive07_0171 */
void Passive07_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060527D2, 3s-exact: sf3 src/PASS07.c:3136 Passive07_0172 */
void Passive07_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 0);
        break;
    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060527FE, 3s-reloc: sf3 src/PASS07.c:3152 Passive07_0173 */
void Passive07_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052894, 3s-exact: sf3 src/PASS07.c:3174 Passive07_0174 */
void Passive07_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    case 1:
        EM_Term(wk, -1, 0x8010, 6, 1, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 3:
        J_Command_Attack(wk, 0xc, 0x1c, 0xa, -1);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052918, 3s-exact: sf3 src/PASS07.c:3199 Passive07_0175 */
void Passive07_0175(PLW* wk) {
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



/* 2i 06052962, 3s-reloc: sf3 src/PASS07.c:3218 Passive07_0176 */
void Passive07_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x100));
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



/* 2i 060529F4, 3s-exact: sf3 src/PASS07.c:3243 Passive07_0177 */
void Passive07_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x100);
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



/* 2i 06052A56, 3s-reloc: sf3 src/PASS07.c:3262 Passive07_0178 */
void Passive07_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 0xC, 0x20, 0xA, -1);
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



/* 2i 06052B04, 3s-exact: sf3 src/PASS07.c:3287 Passive07_0179 */
void Passive07_0179(PLW* wk) {
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



/* 2i 06052B32, 3s-exact: sf3 src/PASS07.c:3303 Passive07_0180 */
void Passive07_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052B74, 3s-reloc: sf3 src/PASS07.c:3319 Passive07_0181 */
void Passive07_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052BE4, 3s-exact: sf3 src/PASS07.c:3338 Passive07_0182 */
void Passive07_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052C04, 3s-exact: sf3 src/PASS07.c:3351 Passive07_0183 */
void Passive07_0183(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052C6C, 3s-reloc: sf3 src/PASS07.c:3370 Passive07_0184 */
void Passive07_0184(PLW* wk) {
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
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052D30, 3s-exact: sf3 src/PASS07.c:3398 Passive07_0185 */
void Passive07_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052D50, 3s-exact: sf3 src/PASS07.c:3411 Passive07_0186 */
void Passive07_0186(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052D82, 3s-exact: sf3 src/PASS07.c:3424 Passive07_0187 */
void Passive07_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052DB4, 3s-reloc: sf3 src/PASS07.c:3437 Passive07_0188 */
void Passive07_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052E00, 3s-exact: sf3 src/PASS07.c:3450 Passive07_0189 */
void Passive07_0189(PLW* wk) {
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



/* 2i 06052E4C, 3s-exact: sf3 src/PASS07.c:3466 Passive07_0190 */
void Passive07_0190(PLW* wk) {
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



/* 2i 06052E98, 3s-exact: sf3 src/PASS07.c:3482 Passive07_0191 */
void Passive07_0191(PLW* wk) {
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



/* 2i 06052EE0, 3s-reloc: sf3 src/PASS07.c:3498 Passive07_0192 */
void Passive07_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xC7, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06052F44, 3s-exact: sf3 src/PASS07.c:3514 Passive07_0193 */
void Passive07_0193(PLW* wk) {
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



/* 2i 06052F8E, 3s-exact: sf3 src/PASS07.c:3530 Passive07_0194 */
void Passive07_0194(PLW* wk) {
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



/* 2i 06052FD4, 3s-reloc: sf3 src/PASS07.c:3546 Passive07_0195 */
void Passive07_0195(PLW* wk) {
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



/* 2i 06053040, 3s-exact: sf3 src/PASS07.c:3562 Passive07_0196 */
void Passive07_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8090, 0x28, 7, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605308C, 3s-exact: sf3 src/PASS07.c:3578 Passive07_0197 */
void Passive07_0197(PLW* wk) {
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



/* 2i 060530D0, 3s-exact: sf3 src/PASS07.c:3594 Passive07_0198 */
void Passive07_0198(PLW* wk) {
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



/* 2i 06053116, 3s-reloc: sf3 src/PASS07.c:3610 Passive07_0199 */
void Passive07_0199(PLW* wk) {
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



/* 2i 06053178, 3s-exact: sf3 src/PASS07.c:3626 Passive07_0200 */
void Passive07_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060531B8, 3s-exact: sf3 src/PASS07.c:3642 Passive07_0201 */
void Passive07_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605320E, 3s-exact: sf3 src/PASS07.c:3661 Passive07_0202 */
void Passive07_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053264, 3s-reloc: sf3 src/PASS07.c:3680 Passive07_0203 */
void Passive07_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605329A, 3s-exact: sf3 src/PASS07.c:3693 Passive07_0204 */
void Passive07_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, 0, 4, 2, 0);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060532E6, 3s-exact: sf3 src/PASS07.c:3709 Passive07_0205 */
void Passive07_0205(PLW* wk) {
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



/* 2i 0605330E, 3s-exact: sf3 src/PASS07.c:3725 Passive07_0206 */
void Passive07_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, -1, 8, 0x200, 1, -1, 0x20, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06053350, 3s-reloc: sf3 src/PASS07.c:3738 Passive07_0207 */
void Passive07_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8050, 8, 0x40, 2, -1, 0x8050, 0x40);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060533D6, 3s-reloc: sf3 src/PASS07.c:3754 Passive07_0208 */
void Passive07_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8050, 8, 0x40, 2, -1, 0x8050, 0x40);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xAF, 0xB0, 0x7C, 0x7B, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0605343A, 3s-reloc: sf3 src/PASS07.c:3770 Passive07_0209 */
void Passive07_0209(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8050, 8, 0x40, 2, -1, 0x8050, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

