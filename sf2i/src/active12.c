/*
 * ACTIVE12.C  CPU active patterns for player 12 (Sean)
 *
 * Behaviour patterns for the computer-controlled player 12 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer12, which runs the pattern chosen in Pattern_Index
 * through Pattern12_Tbl. Each Pattern12_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active12.h"


/* 2i 0602F708, 3s-reloc: sf3 src/active12.c:19 Computer12 */
void Computer12(PLW* wk) {
    Pattern12_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0602F720, 3s-reloc: sf3 src/active12.c:25 Pattern12_0000 */
void Pattern12_0000(PLW* wk) {
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


/* 2i 0602F748, 3s-reloc: sf3 src/active12.c:40 Pattern12_0001 */
void Pattern12_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F766, 3s-near: sf3 src/active12.c:53 Pattern12_0002 */
void Pattern12_0002(PLW* wk) {
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



/* 2i 0602F794, 3s-near: sf3 src/active12.c:69 Pattern12_0003 */
void Pattern12_0003(PLW* wk) {
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



/* 2i 0602F7C2, 3s-near: sf3 src/active12.c:85 Pattern12_0004 */
void Pattern12_0004(PLW* wk) {
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



/* 2i 0602F818, 3s-exact: sf3 src/active12.c:101 Pattern12_0005 */
void Pattern12_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F84A, 3s-exact: sf3 src/active12.c:114 Pattern12_0006 */
void Pattern12_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F87C, 3s-exact: sf3 src/active12.c:127 Pattern12_0007 */
void Pattern12_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F8AE, 3s-exact: sf3 src/active12.c:140 Pattern12_0008 */
void Pattern12_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F8E0, 3s-exact: sf3 src/active12.c:153 Pattern12_0009 */
void Pattern12_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F912, 3s-exact: sf3 src/active12.c:166 Pattern12_0010 */
void Pattern12_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F944, 3s-exact: sf3 src/active12.c:179 Pattern12_0011 */
void Pattern12_0011(PLW* wk) {
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



/* 2i 0602F97C, 3s-exact: sf3 src/active12.c:198 Pattern12_0012 */
void Pattern12_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F99C, 3s-exact: sf3 src/active12.c:211 Pattern12_0013 */
void Pattern12_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F9BC, 3s-reloc: sf3 src/active12.c:224 Pattern12_0014 */
void Pattern12_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602F9EE, 3s-exact: sf3 src/active12.c:237 Pattern12_0015 */
void Pattern12_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FA0E, 3s-exact: sf3 src/active12.c:250 Pattern12_0016 */
void Pattern12_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FA2E, 3s-exact: sf3 src/active12.c:263 Pattern12_0017 */
void Pattern12_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FA60, 3s-exact: sf3 src/active12.c:276 Pattern12_0018 */
void Pattern12_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FA92, 3s-exact: sf3 src/active12.c:289 Pattern12_0019 */
void Pattern12_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FAC4, 3s-reloc: sf3 src/active12.c:302 Pattern12_0020 */
void Pattern12_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FB02, 3s-exact: sf3 src/active12.c:315 Pattern12_0021 */
void Pattern12_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FB22, 3s-exact: sf3 src/active12.c:328 Pattern12_0022 */
void Pattern12_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FB42, 3s-exact: sf3 src/active12.c:341 Pattern12_0023 */
void Pattern12_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FB64, 3s-exact: sf3 src/active12.c:354 Pattern12_0024 */
void Pattern12_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FB96, 3s-exact: sf3 src/active12.c:367 Pattern12_0025 */
void Pattern12_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FBB4, 3s-reloc: sf3 src/active12.c:380 Pattern12_0026 */
void Pattern12_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FBF8, 3s-exact: sf3 src/active12.c:393 Pattern12_0027 */
void Pattern12_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FC18, 3s-exact: sf3 src/active12.c:406 Pattern12_0028 */
void Pattern12_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 2, 4, 0x20, 0xA, 4);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FC68, 3s-exact: sf3 src/active12.c:425 Pattern12_0029 */
void Pattern12_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Jump(wk, 0);
        break;
    case 2:
        Com_Random_Select(wk, 6, 2, 4, 0x0, 0xD, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FCB8, 3s-reloc: sf3 src/active12.c:444 Pattern12_0030 */
void Pattern12_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x11, 0, 0x10, 0x2F, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FD1A, 3s-exact: sf3 src/active12.c:460 Pattern12_0031 */
void Pattern12_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x11, 0, 0x24, 0x23, 3);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FD64, 3s-exact: sf3 src/active12.c:476 Pattern12_0032 */
void Pattern12_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FDA4, 3s-exact: sf3 src/active12.c:492 Pattern12_0033 */
void Pattern12_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FDFA, 3s-reloc: sf3 src/active12.c:511 Pattern12_0034 */
void Pattern12_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FE3A, 3s-exact: sf3 src/active12.c:524 Pattern12_0035 */
void Pattern12_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FE7A, 3s-exact: sf3 src/active12.c:540 Pattern12_0036 */
void Pattern12_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FEBA, 3s-reloc: sf3 src/active12.c:556 Pattern12_0037 */
void Pattern12_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FF1C, 3s-exact: sf3 src/active12.c:572 Pattern12_0038 */
void Pattern12_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0, 0xA, 0x13, 0x1F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FF84, 3s-exact: sf3 src/active12.c:594 Pattern12_0039 */
void Pattern12_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602FFE8, 3s-reloc: sf3 src/active12.c:616 Pattern12_0040 */
void Pattern12_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603005E, 3s-exact: sf3 src/active12.c:632 Pattern12_0041 */
void Pattern12_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, (0x100), 0, 0x8050, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060300C6, 3s-reloc: sf3 src/active12.c:651 Pattern12_0042 */
void Pattern12_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, -1, -1, -1);
        break;
    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030156, 3s-exact: sf3 src/active12.c:670 Pattern12_0043 */
void Pattern12_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060301BE, 3s-exact: sf3 src/active12.c:689 Pattern12_0044 */
void Pattern12_0044(PLW* wk) {
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



/* 2i 06030210, 3s-reloc: sf3 src/active12.c:705 Pattern12_0045 */
void Pattern12_0045(PLW* wk) {
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



/* 2i 060302A0, 3s-exact: sf3 src/active12.c:724 Pattern12_0046 */
void Pattern12_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, 0x40, 0, 0x8050, -1, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603032A, 3s-reloc: sf3 src/active12.c:749 Pattern12_0047 */
void Pattern12_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Command_Attack(wk, 0xc, 0, -1, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1d, 0xa, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060303AE, 3s-exact: sf3 src/active12.c:768 Pattern12_0048 */
void Pattern12_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060303E0, 3s-exact: sf3 src/active12.c:781 Pattern12_0049 */
void Pattern12_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8215, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030412, 3s-exact: sf3 src/active12.c:794 Pattern12_0050 */
void Pattern12_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030444, 3s-exact: sf3 src/active12.c:807 Pattern12_0051 */
void Pattern12_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030464, 3s-reloc: sf3 src/active12.c:820 Pattern12_0052 */
void Pattern12_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060304D2, 3s-exact: sf3 src/active12.c:839 Pattern12_0053 */
void Pattern12_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060304F2, 3s-exact: sf3 src/active12.c:852 Pattern12_0054 */
void Pattern12_0054(PLW* wk) {
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



/* 2i 06030516, 3s-exact: sf3 src/active12.c:866 Pattern12_0055 */
void Pattern12_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030560, 3s-reloc: sf3 src/active12.c:885 Pattern12_0056 */
void Pattern12_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030598, 3s-exact: sf3 src/active12.c:898 Pattern12_0057 */
void Pattern12_0057(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030636, 3s-reloc: sf3 src/active12.c:926 Pattern12_0058 */
void Pattern12_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060306A4, 3s-exact: sf3 src/active12.c:939 Pattern12_0059 */
void Pattern12_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060306C4, 3s-exact: sf3 src/active12.c:952 Pattern12_0060 */
void Pattern12_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060306E4, 3s-exact: sf3 src/active12.c:965 Pattern12_0061 */
void Pattern12_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030704, 3s-exact: sf3 src/active12.c:978 Pattern12_0062 */
void Pattern12_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030724, 3s-exact: sf3 src/active12.c:991 Pattern12_0063 */
void Pattern12_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030744, 3s-exact: sf3 src/active12.c:1004 Pattern12_0064 */
void Pattern12_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030764, 3s-reloc: sf3 src/active12.c:1017 Pattern12_0065 */
void Pattern12_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603079C, 3s-exact: sf3 src/active12.c:1030 Pattern12_0066 */
void Pattern12_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060307E0, 3s-exact: sf3 src/active12.c:1049 Pattern12_0067 */
void Pattern12_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030824, 3s-reloc: sf3 src/active12.c:1068 Pattern12_0068 */
void Pattern12_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030890, 3s-exact: sf3 src/active12.c:1090 Pattern12_0069 */
void Pattern12_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060308C2, 3s-exact: sf3 src/active12.c:1103 Pattern12_0070 */
void Pattern12_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060308F4, 3s-reloc: sf3 src/active12.c:1116 Pattern12_0071 */
void Pattern12_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x100, 0, 0x8050, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030988, 3s-exact: sf3 src/active12.c:1138 Pattern12_0072 */
void Pattern12_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 9, (0x100), 0, 0x8050, -1, (0x100));
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
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030A12, 3s-reloc: sf3 src/active12.c:1163 Pattern12_0073 */
void Pattern12_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x1C, 9, -1);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030A90, 3s-near: sf3 src/active12.c:1182 Pattern12_0074 */
void Pattern12_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x31, -1, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030AD8, 3s-near: sf3 src/active12.c:1201 Pattern12_0075 */
void Pattern12_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 2:
        SA_Term(wk, -1, 0x30, -1, 0);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030B32, 3s-near: sf3 src/active12.c:1221 Pattern12_0076 */
void Pattern12_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030B94, 3s-reloc: sf3 src/active12.c:1237 Pattern12_0077 */
void Pattern12_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 1:
        Keep_Away(wk, 0x7F, 0);
        break;
    case 2:
        Keep_Away(wk, 0xBF, 0);
        break;
    case 3:
        Keep_Away(wk, 0x37, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030BE2, 3s-reloc: sf3 src/active12.c:1259 Pattern12_0078 */
void Pattern12_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030C26, 3s-reloc: sf3 src/active12.c:1278 Pattern12_0079 */
void Pattern12_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x202));
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x202));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030C84, 3s-reloc: sf3 src/active12.c:1297 Pattern12_0080 */
void Pattern12_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0x8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030CCC, 3s-reloc: sf3 src/active12.c:1316 Pattern12_0081 */
void Pattern12_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030CFE, 3s-reloc: sf3 src/active12.c:1329 Pattern12_0082 */
void Pattern12_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030D30, 3s-reloc: sf3 src/active12.c:1342 Pattern12_0083 */
void Pattern12_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0xC, 1);
        break;
    case 1:
        Command_Attack(wk, 0xC, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030D70, 3s-reloc: sf3 src/active12.c:1358 Pattern12_0084 */
void Pattern12_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 1, -1);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
