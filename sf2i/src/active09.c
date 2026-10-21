/*
 * ACTIVE09.C  CPU active patterns for player 09 (Oro)
 *
 * Behaviour patterns for the computer-controlled player 09 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer09, which runs the pattern chosen in Pattern_Index
 * through Pattern09_Tbl. Each Pattern09_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 * ORO_JA_Term is used for this character's jump attacks.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active09.h"



/* 2i 0602B6E4, 3s-exact: sf3 src/active09.c:21 Computer09 */
void Computer09(PLW* wk) {
    Pattern09_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 0602B6FC, 3s-exact: sf3 src/active09.c:27 Pattern09_0000 */
void Pattern09_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x47, 0x47, 0x46, 0x46, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B734, 3s-exact: sf3 src/active09.c:40 Pattern09_0001 */
void Pattern09_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B758, 3s-exact: sf3 src/active09.c:56 Pattern09_0002 */
void Pattern09_0002(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, none, 5, 1, none);
        break;
    case 1:
        J_Command_Attack(wk, 8, 28, 8, none);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B7A6, 3s-reloc: sf3 src/active09.c:73 Pattern09_0003 */
void Pattern09_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, -1, 5, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B81A, 3s-reloc: sf3 src/active09.c:89 Pattern09_0004 */
void Pattern09_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 1, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B84C, 3s-near: sf3 src/active09.c:102 Pattern09_0005 */
void Pattern09_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B86E, 3s-near: sf3 src/active09.c:115 Pattern09_0006 */
void Pattern09_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B88C, 3s-near: sf3 src/active09.c:128 Pattern09_0007 */
void Pattern09_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B8E4, 3s-near: sf3 src/active09.c:147 Pattern09_0008 */
void Pattern09_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 0, (0x100), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B94A, 3s-reloc: sf3 src/active09.c:160 Pattern09_0009 */
void Pattern09_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, -1, 5, 1, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B998, 3s-reloc: sf3 src/active09.c:176 Pattern09_0010 */
void Pattern09_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, -1, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602B9DC, 3s-reloc: sf3 src/active09.c:192 Pattern09_0011 */
void Pattern09_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, -1, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BA48, 3s-exact: sf3 src/active09.c:208 Pattern09_0012 */
void Pattern09_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, -1, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BA8C, 3s-exact: sf3 src/active09.c:224 Pattern09_0013 */
void Pattern09_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, -1, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BAD0, 3s-exact: sf3 src/active09.c:240 Pattern09_0014 */
void Pattern09_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x100, 2, 0x8080, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BB14, 3s-reloc: sf3 src/active09.c:253 Pattern09_0015 */
void Pattern09_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BB60, 3s-exact: sf3 src/active09.c:266 Pattern09_0016 */
void Pattern09_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BB82, 3s-exact: sf3 src/active09.c:279 Pattern09_0017 */
void Pattern09_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x58, -1, 5, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BBCE, 3s-exact: sf3 src/active09.c:295 Pattern09_0018 */
void Pattern09_0018(PLW* wk) {
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



/* 2i 0602BBF6, 3s-exact: sf3 src/active09.c:311 Pattern09_0019 */
void Pattern09_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8068, -1, 0, 2, 5);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BC42, 3s-exact: sf3 src/active09.c:327 Pattern09_0020 */
void Pattern09_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Lever_On(wk, 1, 2);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x41, 0x42, 0x43, 0x44, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BC94, 3s-exact: sf3 src/active09.c:346 Pattern09_0021 */
void Pattern09_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80F0, -1, 5, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BCE0, 3s-reloc: sf3 src/active09.c:362 Pattern09_0022 */
void Pattern09_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8058, 8, 0x40, 0, 0x8070, -1, 0x80);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BD58, 3s-exact: sf3 src/active09.c:375 Pattern09_0023 */
void Pattern09_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BD78, 3s-exact: sf3 src/active09.c:388 Pattern09_0024 */
void Pattern09_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BD9A, 3s-exact: sf3 src/active09.c:401 Pattern09_0025 */
void Pattern09_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BDBC, 3s-exact: sf3 src/active09.c:414 Pattern09_0026 */
void Pattern09_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BDFA, 3s-reloc: sf3 src/active09.c:430 Pattern09_0027 */
void Pattern09_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BE44, 3s-exact: sf3 src/active09.c:443 Pattern09_0028 */
void Pattern09_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BE64, 3s-exact: sf3 src/active09.c:456 Pattern09_0029 */
void Pattern09_0029(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, none, 5, 1, none);
        break;
    case 1:
        Adjust_Attack(wk, 9, (0x80));
        break;
    case 2:
        Command_Attack(wk, 8, 30, 9, none);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BEC2, 3s-exact: sf3 src/active09.c:476 Pattern09_0030 */
void Pattern09_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8050, -1, 5, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BF16, 3s-reloc: sf3 src/active09.c:495 Pattern09_0031 */
void Pattern09_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x200, 0, 0x8098, -1, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BF8A, 3s-exact: sf3 src/active09.c:511 Pattern09_0032 */
void Pattern09_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BFB6, 3s-exact: sf3 src/active09.c:527 Pattern09_0033 */
void Pattern09_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602BFF6, 3s-exact: sf3 src/active09.c:543 Pattern09_0034 */
void Pattern09_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x80);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C020, 3s-reloc: sf3 src/active09.c:559 Pattern09_0035 */
void Pattern09_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, -1, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C090, 3s-exact: sf3 src/active09.c:575 Pattern09_0036 */
void Pattern09_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x80A0, -1, 5, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C0DC, 3s-near: sf3 src/active09.c:591 Pattern09_0037 */
void Pattern09_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C0FE, 3s-reloc: sf3 src/active09.c:604 Pattern09_0038 */
void Pattern09_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C164, 3s-exact: sf3 src/active09.c:623 Pattern09_0039 */
void Pattern09_0039(PLW* wk) {
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



/* 2i 0602C1AC, 3s-exact: sf3 src/active09.c:639 Pattern09_0040 */
void Pattern09_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C1EC, 3s-reloc: sf3 src/active09.c:655 Pattern09_0041 */
void Pattern09_0041(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, none, 5, 1, none);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 2:
        J_Command_Attack(wk, 8, 28, 10, none);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C268, 3s-exact: sf3 src/active09.c:675 Pattern09_0042 */
void Pattern09_0042(PLW* wk) {
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
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C2A8, 3s-exact: sf3 src/active09.c:697 Pattern09_0043 */
void Pattern09_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8058, 8, 0x40, 0, -1, 0x30, (0x401F));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C2EC, 3s-exact: sf3 src/active09.c:710 Pattern09_0044 */
void Pattern09_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8050, 8, 0x40, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C330, 3s-reloc: sf3 src/active09.c:723 Pattern09_0045 */
void Pattern09_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C396, 3s-exact: sf3 src/active09.c:736 Pattern09_0046 */
void Pattern09_0046(PLW* wk) {
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



/* 2i 0602C3E2, 3s-exact: sf3 src/active09.c:755 Pattern09_0047 */
void Pattern09_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, 0x8060, 0x30, 0, -1, 0x30, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C428, 3s-reloc: sf3 src/active09.c:768 Pattern09_0048 */
void Pattern09_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 0xA009, (0x200), 0, 0x8050, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C4C0, 3s-exact: sf3 src/active09.c:787 Pattern09_0049 */
void Pattern09_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8068, 0x8058, 9, 0x40, 0, 0x8050, -1, (0x200));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1D, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C528, 3s-exact: sf3 src/active09.c:806 Pattern09_0050 */
void Pattern09_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x200, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C55A, 3s-exact: sf3 src/active09.c:819 Pattern09_0051 */
void Pattern09_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C59C, 3s-reloc: sf3 src/active09.c:832 Pattern09_0052 */
void Pattern09_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C60C, 3s-near: sf3 src/active09.c:845 Pattern09_0053 */
void Pattern09_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C63E, 3s-near: sf3 src/active09.c:858 Pattern09_0054 */
void Pattern09_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C670, 3s-near: sf3 src/active09.c:871 Pattern09_0055 */
void Pattern09_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C6A2, 3s-near: sf3 src/active09.c:884 Pattern09_0056 */
void Pattern09_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C6D4, 3s-near: sf3 src/active09.c:897 Pattern09_0057 */
void Pattern09_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C706, 3s-near: sf3 src/active09.c:910 Pattern09_0058 */
void Pattern09_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C738, 3s-reloc: sf3 src/active09.c:923 Pattern09_0059 */
void Pattern09_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8070, -1, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C7A2, 3s-near: sf3 src/active09.c:939 Pattern09_0060 */
void Pattern09_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C7B6, 3s-near: sf3 src/active09.c:952 Pattern09_0061 */
void Pattern09_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C7CA, 3s-near: sf3 src/active09.c:965 Pattern09_0062 */
void Pattern09_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x36, -1, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C7FC, 3s-near: sf3 src/active09.c:978 Pattern09_0063 */
void Pattern09_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8070, 0x8040, 8, 0x100, 0, 0x8098, -1, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C840, 3s-near: sf3 src/active09.c:991 Pattern09_0064 */
void Pattern09_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8058, 9, 0x40, 0, 0x8050, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;
    case 3:
        Wait(wk, 5);
        break;
    case 4:
        SA_Term(wk, 0x35, 0x36, 0x3A, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C8EA, 3s-reloc: sf3 src/active09.c:1016 Pattern09_0065 */
void Pattern09_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C932, 3s-near: sf3 src/active09.c:1032 Pattern09_0066 */
void Pattern09_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602C9A4, 3s-reloc: sf3 src/active09.c:1048 Pattern09_0067 */
void Pattern09_0067(PLW* wk) {
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



/* 2i 0602C9EC, 3s-reloc: sf3 src/active09.c:1064 Pattern09_0068 */
void Pattern09_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CA34, 3s-reloc: sf3 src/active09.c:1080 Pattern09_0069 */
void Pattern09_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2f, 9, -1, -1, 0x8040, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CA7A, 3s-reloc: sf3 src/active09.c:1093 Pattern09_0070 */
void Pattern09_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CA98, 3s-reloc: sf3 src/active09.c:1106 Pattern09_0071 */
void Pattern09_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CAC2, 3s-reloc: sf3 src/active09.c:1122 Pattern09_0072 */
void Pattern09_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8060, 0x8010, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CB08, 3s-reloc: sf3 src/active09.c:1138 Pattern09_0073 */
void Pattern09_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8040, 0x8010, 5, 1, -1);
        break;
    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CB4E, 3s-reloc: sf3 src/active09.c:1154 Pattern09_0074 */
void Pattern09_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x8048, 0x8010, 5, 1, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CB94, 3s-reloc: sf3 src/active09.c:1170 Pattern09_0075 */
void Pattern09_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8038, 8, 0x40, 0, 0x8060, -1, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CC02, 3s-reloc: sf3 src/active09.c:1183 Pattern09_0076 */
void Pattern09_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 8, 0x100, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CC52, 3s-reloc: sf3 src/active09.c:1199 Pattern09_0077 */
void Pattern09_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 0xA009, (0x200), 0, 0x8060, -1, 0x40);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CCE8, 3s-near: sf3 src/active09.c:1218 Pattern09_0078 */
void Pattern09_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x4F);
        break;
    case 1:
        Pierce_On(wk);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x36, 0x37, 0x38, 0x39, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CD68, 3s-near: sf3 src/active09.c:1246 Pattern09_0079 */
void Pattern09_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, 0x3A, 0);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x36, 0x37, 0x38, 0x39, 1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CDB8, 3s-reloc: sf3 src/active09.c:1265 Pattern09_0080 */
void Pattern09_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CE0E, 3s-near: sf3 src/active09.c:1284 Pattern09_0081 */
void Pattern09_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8030, 0x2008, 0x100, 0, 0x8060, -1, 0x20);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602CE8C, 3s-near: sf3 src/active09.c:1300 Pattern09_0082 */
void Pattern09_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 2, 0);
        break;
    case 1:
        Provoke(wk, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
