/*
 * ACTIVE11.C  CPU active patterns for player 11 (Ken)
 *
 * Behaviour patterns for the computer-controlled player 11 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer11, which runs the pattern chosen in Pattern_Index
 * through Pattern11_Tbl. Each Pattern11_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active11.h"


/* 2i 0602E284, 3s-exact: sf3 src/active11.c:19 Computer11 */
void Computer11(PLW* wk) {
    Pattern11_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0602E29C, 3s-exact: sf3 src/active11.c:25 Pattern11_0000 */
void Pattern11_0000(PLW* wk) {
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


/* 2i 0602E2C4, 3s-exact: sf3 src/active11.c:40 Pattern11_0001 */
void Pattern11_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E2E2, 3s-near: sf3 src/active11.c:53 Pattern11_0002 */
void Pattern11_0002(PLW* wk) {
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



/* 2i 0602E310, 3s-near: sf3 src/active11.c:69 Pattern11_0003 */
void Pattern11_0003(PLW* wk) {
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



/* 2i 0602E33E, 3s-near: sf3 src/active11.c:85 Pattern11_0004 */
void Pattern11_0004(PLW* wk) {
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



/* 2i 0602E394, 3s-exact: sf3 src/active11.c:101 Pattern11_0005 */
void Pattern11_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E3C6, 3s-exact: sf3 src/active11.c:114 Pattern11_0006 */
void Pattern11_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E3F8, 3s-exact: sf3 src/active11.c:127 Pattern11_0007 */
void Pattern11_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E42A, 3s-exact: sf3 src/active11.c:140 Pattern11_0008 */
void Pattern11_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E45C, 3s-exact: sf3 src/active11.c:153 Pattern11_0009 */
void Pattern11_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E48E, 3s-exact: sf3 src/active11.c:166 Pattern11_0010 */
void Pattern11_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E4C0, 3s-exact: sf3 src/active11.c:179 Pattern11_0011 */
void Pattern11_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E4E0, 3s-exact: sf3 src/active11.c:192 Pattern11_0012 */
void Pattern11_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x20));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E500, 3s-exact: sf3 src/active11.c:205 Pattern11_0013 */
void Pattern11_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x40));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E520, 3s-reloc: sf3 src/active11.c:218 Pattern11_0014 */
void Pattern11_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E552, 3s-exact: sf3 src/active11.c:231 Pattern11_0015 */
void Pattern11_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E572, 3s-exact: sf3 src/active11.c:244 Pattern11_0016 */
void Pattern11_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E592, 3s-exact: sf3 src/active11.c:257 Pattern11_0017 */
void Pattern11_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E5C4, 3s-exact: sf3 src/active11.c:270 Pattern11_0018 */
void Pattern11_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0x9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E5F6, 3s-exact: sf3 src/active11.c:283 Pattern11_0019 */
void Pattern11_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E628, 3s-reloc: sf3 src/active11.c:296 Pattern11_0020 */
void Pattern11_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack_SP(wk, 8, (0x100), 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E660, 3s-exact: sf3 src/active11.c:309 Pattern11_0021 */
void Pattern11_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E680, 3s-exact: sf3 src/active11.c:322 Pattern11_0022 */
void Pattern11_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E6A0, 3s-exact: sf3 src/active11.c:335 Pattern11_0023 */
void Pattern11_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E6C2, 3s-exact: sf3 src/active11.c:348 Pattern11_0024 */
void Pattern11_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E6F4, 3s-exact: sf3 src/active11.c:361 Pattern11_0025 */
void Pattern11_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E712, 3s-reloc: sf3 src/active11.c:374 Pattern11_0026 */
void Pattern11_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    case 1:
        ETC_Term(wk, 4, 2, 0x13);
        break;
    case 2:
        Next_Another_Menu(wk, 2, 0x37);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E774, 3s-exact: sf3 src/active11.c:393 Pattern11_0027 */
void Pattern11_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    case 1:
        ETC_Term(wk, 4, 2, 0x13);
        break;
    case 2:
        Next_Another_Menu(wk, 2, 0x37);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E7AE, 3s-near: sf3 src/active11.c:412 Pattern11_0028 */
void Pattern11_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 2, 2, 4, 0x20, 0xA, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E7FE, 3s-near: sf3 src/active11.c:431 Pattern11_0029 */
void Pattern11_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 2, 2, 4, 0, 0xD, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E870, 3s-near: sf3 src/active11.c:450 Pattern11_0030 */
void Pattern11_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x11, 0, 0x10, 0x2F, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E8B8, 3s-exact: sf3 src/active11.c:466 Pattern11_0031 */
void Pattern11_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x11, 0, 0x24, 0x23, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E902, 3s-exact: sf3 src/active11.c:482 Pattern11_0032 */
void Pattern11_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E942, 3s-reloc: sf3 src/active11.c:498 Pattern11_0033 */
void Pattern11_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E9BC, 3s-exact: sf3 src/active11.c:517 Pattern11_0034 */
void Pattern11_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602E9DC, 3s-exact: sf3 src/active11.c:530 Pattern11_0035 */
void Pattern11_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EA1C, 3s-exact: sf3 src/active11.c:546 Pattern11_0036 */
void Pattern11_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EA5C, 3s-reloc: sf3 src/active11.c:562 Pattern11_0037 */
void Pattern11_0037(PLW* wk) {
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



/* 2i 0602EABE, 3s-exact: sf3 src/active11.c:578 Pattern11_0038 */
void Pattern11_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0, 0xA, 0x13, 0x1F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EB36, 3s-exact: sf3 src/active11.c:600 Pattern11_0039 */
void Pattern11_0039(PLW* wk) {
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



/* 2i 0602EB9A, 3s-reloc: sf3 src/active11.c:622 Pattern11_0040 */
void Pattern11_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EC12, 3s-exact: sf3 src/active11.c:638 Pattern11_0041 */
void Pattern11_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
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



/* 2i 0602EC7A, 3s-reloc: sf3 src/active11.c:657 Pattern11_0042 */
void Pattern11_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, 0x100, 0, -1, -1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ED0A, 3s-exact: sf3 src/active11.c:676 Pattern11_0043 */
void Pattern11_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602ED72, 3s-exact: sf3 src/active11.c:695 Pattern11_0044 */
void Pattern11_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x200), 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EDC4, 3s-reloc: sf3 src/active11.c:711 Pattern11_0045 */
void Pattern11_0045(PLW* wk) {
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



/* 2i 0602EE54, 3s-exact: sf3 src/active11.c:730 Pattern11_0046 */
void Pattern11_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
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



/* 2i 0602EEDE, 3s-reloc: sf3 src/active11.c:755 Pattern11_0047 */
void Pattern11_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EF62, 3s-exact: sf3 src/active11.c:774 Pattern11_0048 */
void Pattern11_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EF94, 3s-exact: sf3 src/active11.c:787 Pattern11_0049 */
void Pattern11_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8115, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EFC6, 3s-exact: sf3 src/active11.c:800 Pattern11_0050 */
void Pattern11_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602EFF8, 3s-exact: sf3 src/active11.c:813 Pattern11_0051 */
void Pattern11_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F018, 3s-reloc: sf3 src/active11.c:826 Pattern11_0052 */
void Pattern11_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F086, 3s-exact: sf3 src/active11.c:845 Pattern11_0053 */
void Pattern11_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F0A6, 3s-exact: sf3 src/active11.c:858 Pattern11_0054 */
void Pattern11_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F0CA, 3s-exact: sf3 src/active11.c:872 Pattern11_0055 */
void Pattern11_0055(PLW* wk) {
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



/* 2i 0602F114, 3s-reloc: sf3 src/active11.c:891 Pattern11_0056 */
void Pattern11_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F14C, 3s-exact: sf3 src/active11.c:904 Pattern11_0057 */
void Pattern11_0057(PLW* wk) {
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
        Com_Random_Select(wk, 2, 0x2D, 0x13, 0x13, 0xFF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F1D6, 3s-exact: sf3 src/active11.c:929 Pattern11_0058 */
void Pattern11_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F21A, 3s-reloc: sf3 src/active11.c:942 Pattern11_0059 */
void Pattern11_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F264, 3s-exact: sf3 src/active11.c:955 Pattern11_0060 */
void Pattern11_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F284, 3s-exact: sf3 src/active11.c:968 Pattern11_0061 */
void Pattern11_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F2A4, 3s-exact: sf3 src/active11.c:981 Pattern11_0062 */
void Pattern11_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0x11);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F2E6, 3s-exact: sf3 src/active11.c:997 Pattern11_0063 */
void Pattern11_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0x12);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F328, 3s-reloc: sf3 src/active11.c:1013 Pattern11_0064 */
void Pattern11_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0x13);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F382, 3s-exact: sf3 src/active11.c:1029 Pattern11_0065 */
void Pattern11_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
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



/* 2i 0602F3E2, 3s-reloc: sf3 src/active11.c:1051 Pattern11_0066 */
void Pattern11_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 4:
        Com_Random_Select(wk, 2, 0, 0xA, 0x13, 0x1F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F486, 3s-exact: sf3 src/active11.c:1076 Pattern11_0067 */
void Pattern11_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F4EC, 3s-exact: sf3 src/active11.c:1098 Pattern11_0068 */
void Pattern11_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F546, 3s-exact: sf3 src/active11.c:1117 Pattern11_0069 */
void Pattern11_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F588, 3s-exact: sf3 src/active11.c:1133 Pattern11_0070 */
void Pattern11_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F5CA, 3s-exact: sf3 src/active11.c:1149 Pattern11_0071 */
void Pattern11_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F60C, 3s-reloc: sf3 src/active11.c:1165 Pattern11_0072 */
void Pattern11_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, (0x380), -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F66E, 3s-reloc: sf3 src/active11.c:1178 Pattern11_0073 */
void Pattern11_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, 0x380, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F6B6, 3s-reloc: sf3 src/active11.c:1191 Pattern11_0074 */
void Pattern11_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0xA, 0x48, 0x48, 0x49, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
