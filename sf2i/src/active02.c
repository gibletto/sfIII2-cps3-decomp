/*
 * ACTIVE02.C  CPU active patterns for player 02 (Ryu)
 *
 * Behaviour patterns for the computer-controlled player 02 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer02, which runs the pattern chosen in Pattern_Index
 * through Pattern02_Tbl. Each Pattern02_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active02.h"



/* 2i 06023A18, 3s-exact: sf3 src/active02.c:20 Computer02 */
void Computer02(PLW* wk) {
    Pattern02_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06023A30, 3s-exact: sf3 src/active02.c:26 Pattern02_0000 */
void Pattern02_0000(PLW* wk) {
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



/* 2i 06023A58, 3s-exact: sf3 src/active02.c:42 Pattern02_0001 */
void Pattern02_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023A98, 3s-exact: sf3 src/active02.c:61 Pattern02_0002 */
void Pattern02_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023ACA, 3s-exact: sf3 src/active02.c:74 Pattern02_0003 */
void Pattern02_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023AF6, 3s-reloc: sf3 src/active02.c:90 Pattern02_0004 */
void Pattern02_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 1, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023B4E, 3s-near: sf3 src/active02.c:103 Pattern02_0005 */
void Pattern02_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023B70, 3s-near: sf3 src/active02.c:116 Pattern02_0006 */
void Pattern02_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023B8E, 3s-near: sf3 src/active02.c:129 Pattern02_0007 */
void Pattern02_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 1:
        Lever_Off(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023BCA, 3s-reloc: sf3 src/active02.c:145 Pattern02_0008 */
void Pattern02_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 0, (0x100), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023C0E, 3s-reloc: sf3 src/active02.c:158 Pattern02_0009 */
void Pattern02_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023C68, 3s-exact: sf3 src/active02.c:171 Pattern02_0010 */
void Pattern02_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023C88, 3s-exact: sf3 src/active02.c:184 Pattern02_0011 */
void Pattern02_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023CA8, 3s-exact: sf3 src/active02.c:197 Pattern02_0012 */
void Pattern02_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023CC8, 3s-exact: sf3 src/active02.c:210 Pattern02_0013 */
void Pattern02_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023CE8, 3s-exact: sf3 src/active02.c:223 Pattern02_0014 */
void Pattern02_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, (0x100), 2, 0x8080, -1, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023D2C, 3s-reloc: sf3 src/active02.c:236 Pattern02_0015 */
void Pattern02_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023D70, 3s-exact: sf3 src/active02.c:249 Pattern02_0016 */
void Pattern02_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023D92, 3s-exact: sf3 src/active02.c:262 Pattern02_0017 */
void Pattern02_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023DC4, 3s-exact: sf3 src/active02.c:275 Pattern02_0018 */
void Pattern02_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;
    case 1:
        Lever_Off(wk);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023DF6, 3s-exact: sf3 src/active02.c:294 Pattern02_0019 */
void Pattern02_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x88, -1, 0, 2, 5);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023E42, 3s-reloc: sf3 src/active02.c:310 Pattern02_0020 */
void Pattern02_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x41, 0x42, 0x43, 0x44, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023EA2, 3s-exact: sf3 src/active02.c:323 Pattern02_0021 */
void Pattern02_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023ED4, 3s-exact: sf3 src/active02.c:336 Pattern02_0022 */
void Pattern02_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x40, 0, 0x8070, -1, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023F18, 3s-exact: sf3 src/active02.c:349 Pattern02_0023 */
void Pattern02_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023F38, 3s-exact: sf3 src/active02.c:362 Pattern02_0024 */
void Pattern02_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023F5A, 3s-reloc: sf3 src/active02.c:375 Pattern02_0025 */
void Pattern02_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023FA4, 3s-exact: sf3 src/active02.c:388 Pattern02_0026 */
void Pattern02_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Lever_Off(wk);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06023FEC, 3s-exact: sf3 src/active02.c:407 Pattern02_0027 */
void Pattern02_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602400A, 3s-exact: sf3 src/active02.c:420 Pattern02_0028 */
void Pattern02_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602402A, 3s-exact: sf3 src/active02.c:433 Pattern02_0029 */
void Pattern02_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602406A, 3s-reloc: sf3 src/active02.c:449 Pattern02_0030 */
void Pattern02_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060240BC, 3s-exact: sf3 src/active02.c:465 Pattern02_0031 */
void Pattern02_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, (0x100), 0, 0x8098, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602410E, 3s-exact: sf3 src/active02.c:481 Pattern02_0032 */
void Pattern02_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602413A, 3s-exact: sf3 src/active02.c:497 Pattern02_0033 */
void Pattern02_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602417A, 3s-reloc: sf3 src/active02.c:513 Pattern02_0034 */
void Pattern02_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x80);
        break;
    case 1:
        Lever_Off(wk);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060241D6, 3s-exact: sf3 src/active02.c:532 Pattern02_0035 */
void Pattern02_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060241F6, 3s-exact: sf3 src/active02.c:545 Pattern02_0036 */
void Pattern02_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024216, 3s-near: sf3 src/active02.c:558 Pattern02_0037 */
void Pattern02_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024238, 3s-exact: sf3 src/active02.c:571 Pattern02_0038 */
void Pattern02_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024286, 3s-reloc: sf3 src/active02.c:590 Pattern02_0039 */
void Pattern02_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060242F4, 3s-exact: sf3 src/active02.c:606 Pattern02_0040 */
void Pattern02_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024334, 3s-exact: sf3 src/active02.c:622 Pattern02_0041 */
void Pattern02_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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



/* 2i 06024382, 3s-reloc: sf3 src/active02.c:641 Pattern02_0042 */
void Pattern02_0042(PLW* wk) {
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
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060243DE, 3s-exact: sf3 src/active02.c:663 Pattern02_0043 */
void Pattern02_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x40, 0, -1, 0x30, (0x401E));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024422, 3s-exact: sf3 src/active02.c:676 Pattern02_0044 */
void Pattern02_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, -1, 0x30, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024466, 3s-exact: sf3 src/active02.c:689 Pattern02_0045 */
void Pattern02_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060244AA, 3s-reloc: sf3 src/active02.c:702 Pattern02_0046 */
void Pattern02_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;
    case 1:
        Walk(wk, 1, 0x13, 0);
        break;
    case 2:
        Walk(wk, 0, 0x10, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024514, 3s-exact: sf3 src/active02.c:721 Pattern02_0047 */
void Pattern02_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, -1, 0x8060, 0x30, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602455A, 3s-reloc: sf3 src/active02.c:734 Pattern02_0048 */
void Pattern02_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x50, -1, 5, 2, 0);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8080, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1d, 10, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x47);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024634, 3s-exact: sf3 src/active02.c:762 Pattern02_0049 */
void Pattern02_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8060, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x47);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060246BC, 3s-exact: sf3 src/active02.c:787 Pattern02_0050 */
void Pattern02_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, (0x200), 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060246EE, 3s-reloc: sf3 src/active02.c:800 Pattern02_0051 */
void Pattern02_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024760, 3s-exact: sf3 src/active02.c:813 Pattern02_0052 */
void Pattern02_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060247A6, 3s-exact: sf3 src/active02.c:826 Pattern02_0053 */
void Pattern02_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060247D8, 3s-exact: sf3 src/active02.c:839 Pattern02_0054 */
void Pattern02_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602480A, 3s-exact: sf3 src/active02.c:852 Pattern02_0055 */
void Pattern02_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Setup_DENJIN_LEVEL(wk);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024828, 3s-exact: sf3 src/active02.c:865 Pattern02_0056 */
void Pattern02_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602485A, 3s-exact: sf3 src/active02.c:878 Pattern02_0057 */
void Pattern02_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;
    case 1:
        Push_Shot(wk, 5);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024898, 3s-exact: sf3 src/active02.c:894 Pattern02_0058 */
void Pattern02_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;
    case 1:
        Push_Shot(wk, 0xB);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060248D6, 3s-exact: sf3 src/active02.c:910 Pattern02_0059 */
void Pattern02_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;
    case 1:
        Push_Shot(wk, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024914, 3s-reloc: sf3 src/active02.c:926 Pattern02_0060 */
void Pattern02_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    case 1:
        Push_Shot(wk, 0xFF);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024978, 3s-exact: sf3 src/active02.c:942 Pattern02_0061 */
void Pattern02_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
    }
}



/* 2i 0602498C, 3s-exact: sf3 src/active02.c:951 Pattern02_0062 */
void Pattern02_0062(PLW* wk) {
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



/* 2i 060249D4, 3s-exact: sf3 src/active02.c:967 Pattern02_0063 */
void Pattern02_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, (0x100), 0, 0x8098, -1, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024A18, 3s-reloc: sf3 src/active02.c:980 Pattern02_0064 */
void Pattern02_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8080, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
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



/* 2i 06024AC6, 3s-exact: sf3 src/active02.c:1005 Pattern02_0065 */
void Pattern02_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024B0E, 3s-reloc: sf3 src/active02.c:1021 Pattern02_0066 */
void Pattern02_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024B80, 3s-reloc: sf3 src/active02.c:1037 Pattern02_0067 */
void Pattern02_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024BC8, 3s-reloc: sf3 src/active02.c:1053 Pattern02_0068 */
void Pattern02_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024C10, 3s-near: sf3 src/active02.c:1069 Pattern02_0069 */
void Pattern02_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024C52, 3s-reloc: sf3 src/active02.c:1085 Pattern02_0070 */
void Pattern02_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x14);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Next_Another_Menu(wk, 2, 0x14);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024C8A, 3s-reloc: sf3 src/active02.c:1104 Pattern02_0071 */
void Pattern02_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 2, 0x17);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06024CB6, 3s-reloc: sf3 src/active02.c:1120 Pattern02_0072 */
void Pattern02_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, 0x8060, 0x48, 0, -1, 0x30, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
