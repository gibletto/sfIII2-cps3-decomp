/*
 * ACTIVE07.C  CPU active patterns for player 07 (Ibuki)
 *
 * Behaviour patterns for the computer-controlled player 07 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer07, which runs the pattern chosen in Pattern_Index
 * through Pattern07_Tbl. Each Pattern07_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active07.h"



/* 2i 06028F74, 3s-exact: sf3 src/active07.c:20 Computer07 */
void Computer07(PLW* wk) {
    Pattern07_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06028F8C, 3s-exact: sf3 src/active07.c:26 Pattern07_0000 */
void Pattern07_0000(PLW* wk) {
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



/* 2i 06028FB4, 3s-exact: sf3 src/active07.c:42 Pattern07_0001 */
void Pattern07_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06028FFA, 3s-reloc: sf3 src/active07.c:61 Pattern07_0002 */
void Pattern07_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0x1C, 8, -1);
        break;
    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029080, 3s-exact: sf3 src/active07.c:80 Pattern07_0003 */
void Pattern07_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x200);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060290CE, 3s-exact: sf3 src/active07.c:102 Pattern07_0004 */
void Pattern07_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029116, 3s-reloc: sf3 src/active07.c:118 Pattern07_0005 */
void Pattern07_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    case 1:
        Lever_Attack(wk, 0xB, 0, 0x200);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029180, 3s-reloc: sf3 src/active07.c:137 Pattern07_0006 */
void Pattern07_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602919E, 3s-near: sf3 src/active07.c:150 Pattern07_0007 */
void Pattern07_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    case 2:
        Lever_Off(wk);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060291F6, 3s-reloc: sf3 src/active07.c:169 Pattern07_0008 */
void Pattern07_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x40, 0, 0x8070, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029298, 3s-exact: sf3 src/active07.c:191 Pattern07_0009 */
void Pattern07_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060292E0, 3s-exact: sf3 src/active07.c:207 Pattern07_0010 */
void Pattern07_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x40, 0, 0x8070, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029340, 3s-reloc: sf3 src/active07.c:226 Pattern07_0011 */
void Pattern07_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    case 1:
        Lever_Attack(wk, 0xB, 0, 0x102);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060293A8, 3s-exact: sf3 src/active07.c:245 Pattern07_0012 */
void Pattern07_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060293D6, 3s-exact: sf3 src/active07.c:261 Pattern07_0013 */
void Pattern07_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0x1E, 9, -1);
        break;
    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602943C, 3s-reloc: sf3 src/active07.c:283 Pattern07_0014 */
void Pattern07_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, (0x100), 2, 0x8080, -1, (0x100));
        break;
    case 1:
        Lever_Attack(wk, 9, 0, (0x100));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060294D8, 3s-exact: sf3 src/active07.c:302 Pattern07_0015 */
void Pattern07_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060294FA, 3s-exact: sf3 src/active07.c:315 Pattern07_0016 */
void Pattern07_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602951C, 3s-exact: sf3 src/active07.c:328 Pattern07_0017 */
void Pattern07_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602954E, 3s-exact: sf3 src/active07.c:341 Pattern07_0018 */
void Pattern07_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 1, -1);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Lever_Off(wk);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602958E, 3s-reloc: sf3 src/active07.c:363 Pattern07_0019 */
void Pattern07_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8064, 0x8040, 8, (0x80), 0, 0x8070, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029626, 3s-exact: sf3 src/active07.c:385 Pattern07_0020 */
void Pattern07_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602966E, 3s-reloc: sf3 src/active07.c:401 Pattern07_0021 */
void Pattern07_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8064, 0x8040, 8, 0x20, 0, 0x8070, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x200);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602970A, 3s-exact: sf3 src/active07.c:423 Pattern07_0022 */
void Pattern07_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, 0x8070, -1, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029764, 3s-exact: sf3 src/active07.c:439 Pattern07_0023 */
void Pattern07_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC7, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029784, 3s-exact: sf3 src/active07.c:452 Pattern07_0024 */
void Pattern07_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060297A6, 3s-reloc: sf3 src/active07.c:465 Pattern07_0025 */
void Pattern07_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060297F0, 3s-exact: sf3 src/active07.c:478 Pattern07_0026 */
void Pattern07_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 2:
        Lever_Off(wk);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602984E, 3s-exact: sf3 src/active07.c:500 Pattern07_0027 */
void Pattern07_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1d, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 4:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 5:
        Command_Attack(wk, 8, 1, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060298CE, 3s-exact: sf3 src/active07.c:528 Pattern07_0028 */
void Pattern07_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060298EE, 3s-reloc: sf3 src/active07.c:541 Pattern07_0029 */
void Pattern07_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029954, 3s-exact: sf3 src/active07.c:557 Pattern07_0030 */
void Pattern07_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029986, 3s-exact: sf3 src/active07.c:576 Pattern07_0031 */
void Pattern07_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x100, 0, 0x8098, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060299D8, 3s-reloc: sf3 src/active07.c:592 Pattern07_0032 */
void Pattern07_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Lever_Attack(wk, 0xB, 0, 0x80);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029A5A, 3s-exact: sf3 src/active07.c:614 Pattern07_0033 */
void Pattern07_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029A9A, 3s-exact: sf3 src/active07.c:630 Pattern07_0034 */
void Pattern07_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x100);
        break;
    case 3:
        Lever_Off(wk);
        break;
    case 4:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029AFA, 3s-reloc: sf3 src/active07.c:655 Pattern07_0035 */
void Pattern07_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029B3C, 3s-exact: sf3 src/active07.c:668 Pattern07_0036 */
void Pattern07_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029B5C, 3s-near: sf3 src/active07.c:681 Pattern07_0037 */
void Pattern07_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029BAE, 3s-reloc: sf3 src/active07.c:700 Pattern07_0038 */
void Pattern07_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 4:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029C40, 3s-exact: sf3 src/active07.c:725 Pattern07_0039 */
void Pattern07_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029C88, 3s-exact: sf3 src/active07.c:741 Pattern07_0040 */
void Pattern07_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029CC8, 3s-reloc: sf3 src/active07.c:757 Pattern07_0041 */
void Pattern07_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029D2C, 3s-exact: sf3 src/active07.c:776 Pattern07_0042 */
void Pattern07_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029D7E, 3s-exact: sf3 src/active07.c:798 Pattern07_0043 */
void Pattern07_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, -1, 0x30, (0x4020));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029DC2, 3s-exact: sf3 src/active07.c:811 Pattern07_0044 */
void Pattern07_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029E06, 3s-reloc: sf3 src/active07.c:824 Pattern07_0045 */
void Pattern07_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029E6A, 3s-exact: sf3 src/active07.c:837 Pattern07_0046 */
void Pattern07_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029E7E, 3s-exact: sf3 src/active07.c:847 Pattern07_0047 */
void Pattern07_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, 0x8060, 0x38, 0x0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029EC6, 3s-reloc: sf3 src/active07.c:860 Pattern07_0048 */
void Pattern07_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x80);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x38, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029F58, 3s-exact: sf3 src/active07.c:879 Pattern07_0049 */
void Pattern07_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8038, 8, (0x100), 0, 0x8058, -1, (0x100));
        break;
    case 1:
        Lever_Attack(wk, 9, 0, (0x80));
        break;
    case 2:
        Lever_Attack(wk, 9, 0, (0x80));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029FC2, 3s-exact: sf3 src/active07.c:901 Pattern07_0050 */
void Pattern07_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x200, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06029FF4, 3s-reloc: sf3 src/active07.c:914 Pattern07_0051 */
void Pattern07_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8038, 8, 0x20, 0, 0x8058, -1, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A078, 3s-exact: sf3 src/active07.c:930 Pattern07_0052 */
void Pattern07_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x8126, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A0BE, 3s-exact: sf3 src/active07.c:943 Pattern07_0053 */
void Pattern07_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        {
            s16 menu = 58;
            Branch_Unit_Area(wk, 2, 56, menu, menu, menu);
        }
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A0F6, 3s-exact: sf3 src/active07.c:959 Pattern07_0054 */
void Pattern07_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A128, 3s-exact: sf3 src/active07.c:972 Pattern07_0055 */
void Pattern07_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A15A, 3s-exact: sf3 src/active07.c:985 Pattern07_0056 */
void Pattern07_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 9, -1, -1, 0x40, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A1A0, 3s-exact: sf3 src/active07.c:998 Pattern07_0057 */
void Pattern07_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 9, -1, -1, 0x40, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A1E6, 3s-exact: sf3 src/active07.c:1011 Pattern07_0058 */
void Pattern07_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 0xa, -1, -1, 0x30, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A22C, 3s-reloc: sf3 src/active07.c:1024 Pattern07_0059 */
void Pattern07_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A2B0, 3s-exact: sf3 src/active07.c:1046 Pattern07_0060 */
void Pattern07_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;
    case 1:
        Walk(wk, 1, 0x14, 0);
        break;
    case 2:
        Walk(wk, 0, 0x10, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A2FC, 3s-reloc: sf3 src/active07.c:1065 Pattern07_0061 */
void Pattern07_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x14, 0);
        break;
    case 1:
        Walk(wk, 0, 0x10, 0);
        break;
    case 2:
        Walk(wk, 1, 0x18, 0);
        break;
    case 3:
        Walk(wk, 0, 0x10, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A368, 3s-reloc: sf3 src/active07.c:1087 Pattern07_0062 */
void Pattern07_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x10, 0);
        break;
    case 1:
        Walk(wk, 1, 0x18, 0);
        break;
    case 2:
        Wait(wk, 0x10);
        break;
    case 3:
        Walk(wk, 0, 0x10, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602A3C2, 3s-reloc: sf3 src/active07.c:1109 Pattern07_0063 */
void Pattern07_0063(PLW* wk) {
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

