/*
 * ACTIVE14.C  CPU active patterns for player 14 (Gouki)
 *
 * Behaviour patterns for the computer-controlled player 14 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer14, which runs the pattern chosen in Pattern_Index
 * through Pattern14_Tbl. Each Pattern14_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 * SA_Term and Check_SA time the super arts.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active14.h"


/* 2i 06031FC0, 3s-exact: sf3 src/active14.c:20 Computer14 */
void Computer14(PLW* wk) {
    Pattern14_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06031FD8, 3s-exact: sf3 src/active14.c:26 Pattern14_0000 */
void Pattern14_0000(PLW* wk) {
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


/* 2i 06032000, 3s-exact: sf3 src/active14.c:41 Pattern14_0001 */
void Pattern14_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603201E, 3s-exact: sf3 src/active14.c:54 Pattern14_0002 */
void Pattern14_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603203E, 3s-exact: sf3 src/active14.c:67 Pattern14_0003 */
void Pattern14_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603205E, 3s-exact: sf3 src/active14.c:80 Pattern14_0004 */
void Pattern14_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603207E, 3s-reloc: sf3 src/active14.c:93 Pattern14_0005 */
void Pattern14_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x80));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060320C0, 3s-exact: sf3 src/active14.c:106 Pattern14_0006 */
void Pattern14_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060320E0, 3s-exact: sf3 src/active14.c:119 Pattern14_0007 */
void Pattern14_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032100, 3s-exact: sf3 src/active14.c:132 Pattern14_0008 */
void Pattern14_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032120, 3s-exact: sf3 src/active14.c:145 Pattern14_0009 */
void Pattern14_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032140, 3s-exact: sf3 src/active14.c:158 Pattern14_0010 */
void Pattern14_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032160, 3s-exact: sf3 src/active14.c:171 Pattern14_0011 */
void Pattern14_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032180, 3s-reloc: sf3 src/active14.c:184 Pattern14_0012 */
void Pattern14_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060321B4, 3s-exact: sf3 src/active14.c:197 Pattern14_0013 */
void Pattern14_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060321D4, 3s-exact: sf3 src/active14.c:210 Pattern14_0014 */
void Pattern14_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032206, 3s-exact: sf3 src/active14.c:223 Pattern14_0015 */
void Pattern14_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032238, 3s-exact: sf3 src/active14.c:236 Pattern14_0016 */
void Pattern14_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603226A, 3s-reloc: sf3 src/active14.c:249 Pattern14_0017 */
void Pattern14_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060322C8, 3s-exact: sf3 src/active14.c:265 Pattern14_0018 */
void Pattern14_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060322FA, 3s-exact: sf3 src/active14.c:278 Pattern14_0019 */
void Pattern14_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603232C, 3s-exact: sf3 src/active14.c:291 Pattern14_0020 */
void Pattern14_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603235E, 3s-exact: sf3 src/active14.c:304 Pattern14_0021 */
void Pattern14_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032390, 3s-near: sf3 src/active14.c:317 Pattern14_0022 */
void Pattern14_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060323D8, 3s-near: sf3 src/active14.c:333 Pattern14_0023 */
void Pattern14_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032420, 3s-exact: sf3 src/active14.c:349 Pattern14_0024 */
void Pattern14_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032440, 3s-reloc: sf3 src/active14.c:362 Pattern14_0025 */
void Pattern14_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032472, 3s-exact: sf3 src/active14.c:375 Pattern14_0026 */
void Pattern14_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x30, 0, 0x8080, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 4:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 5);
        break;
    case 6:
        SA_Term(wk, 0x2F, -1, 0x31, 0x7F);
        break;
    case 7:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032534, 3s-reloc: sf3 src/active14.c:409 Pattern14_0027 */
void Pattern14_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603258C, 3s-exact: sf3 src/active14.c:422 Pattern14_0028 */
void Pattern14_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x30, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060325F8, 3s-reloc: sf3 src/active14.c:441 Pattern14_0029 */
void Pattern14_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603269C, 3s-exact: sf3 src/active14.c:463 Pattern14_0030 */
void Pattern14_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032734, 3s-reloc: sf3 src/active14.c:491 Pattern14_0031 */
void Pattern14_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 0x2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xb, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060327D8, 3s-reloc: sf3 src/active14.c:513 Pattern14_0032 */
void Pattern14_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 0xB, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060328A0, 3s-exact: sf3 src/active14.c:541 Pattern14_0033 */
void Pattern14_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 8, -1, -1, 0x30, 0, 0x8080, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 3);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032948, 3s-reloc: sf3 src/active14.c:572 Pattern14_0034 */
void Pattern14_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 0xB, 0x2F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060329EA, 3s-exact: sf3 src/active14.c:594 Pattern14_0035 */
void Pattern14_0035(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, none, 97, 8, (0x102), 0, 0x8080, none, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 11, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 31, 10, none);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032A60, 3s-reloc: sf3 src/active14.c:617 Pattern14_0036 */
void Pattern14_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 8, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 3:
        Command_Attack(wk, 0xc, 0x1f, 0xa, -1);
        break;
    case 4:
        Wait(wk, 1);
        break;
    case 5:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032B22, 3s-reloc: sf3 src/active14.c:645 Pattern14_0037 */
void Pattern14_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 8, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 0xb, (0x102));
        break;
    case 3:
        Pierce_On(wk);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 5:
        Wait(wk, 3);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032BF4, 3s-exact: sf3 src/active14.c:676 Pattern14_0038 */
void Pattern14_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032C36, 3s-exact: sf3 src/active14.c:692 Pattern14_0039 */
void Pattern14_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032C78, 3s-exact: sf3 src/active14.c:708 Pattern14_0040 */
void Pattern14_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032CBA, 3s-exact: sf3 src/active14.c:724 Pattern14_0041 */
void Pattern14_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032D12, 3s-reloc: sf3 src/active14.c:743 Pattern14_0042 */
void Pattern14_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;
    case 2:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    case 3:
        Wait(wk, 1);
        break;
    case 4:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032D96, 3s-exact: sf3 src/active14.c:768 Pattern14_0043 */
void Pattern14_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;
    case 1:
        Normal_Attack(wk, 0xB, (0x102));
        break;
    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032DE6, 3s-exact: sf3 src/active14.c:787 Pattern14_0044 */
void Pattern14_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032E20, 3s-reloc: sf3 src/active14.c:800 Pattern14_0045 */
void Pattern14_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032E7C, 3s-exact: sf3 src/active14.c:813 Pattern14_0046 */
void Pattern14_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032EB6, 3s-exact: sf3 src/active14.c:826 Pattern14_0047 */
void Pattern14_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032EE8, 3s-exact: sf3 src/active14.c:839 Pattern14_0048 */
void Pattern14_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032F1A, 3s-exact: sf3 src/active14.c:852 Pattern14_0049 */
void Pattern14_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032F4C, 3s-exact: sf3 src/active14.c:865 Pattern14_0050 */
void Pattern14_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x37, 0x37, 0x36, 0x35);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032F82, 3s-reloc: sf3 src/active14.c:878 Pattern14_0051 */
void Pattern14_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8016, 0xA, -1, 0x8050, 0x8040, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06032FFC, 3s-reloc: sf3 src/active14.c:891 Pattern14_0052 */
void Pattern14_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA_Full(wk, 6, 0x7c);
        break;
    case 1:
        EM_Term(wk, 0x80d0, -1, 5, 2, 0);
        break;
    case 2:
        Only_Shot(wk, 0x10);
        break;
    case 3:
        Wait(wk, 1);
        break;
    case 4:
        Only_Shot(wk, 0x10);
        break;
    case 5:
        Wait(wk, 1);
        break;
    case 6:
        Lever_On(wk, 0, 0);
        break;
    case 7:
        Wait(wk, 1);
        break;
    case 8:
        Only_Shot(wk, (0x80));
        break;
    case 9:
        Wait(wk, 1);
        break;
    case 10:
        Only_Shot(wk, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060330B6, 3s-exact: sf3 src/active14.c:934 Pattern14_0053 */
void Pattern14_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060330FC, 3s-exact: sf3 src/active14.c:947 Pattern14_0054 */
void Pattern14_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033142, 3s-reloc: sf3 src/active14.c:960 Pattern14_0055 */
void Pattern14_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 1, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060331AC, 3s-exact: sf3 src/active14.c:973 Pattern14_0056 */
void Pattern14_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 2:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603320A, 3s-reloc: sf3 src/active14.c:992 Pattern14_0057 */
void Pattern14_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0x84, 0x84, 0x85, 0x86, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033284, 3s-near: sf3 src/active14.c:1008 Pattern14_0058 */
void Pattern14_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 4:
        Command_Attack(wk, 0xC, 0x1F, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033312, 3s-near: sf3 src/active14.c:1033 Pattern14_0059 */
void Pattern14_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        Normal_Attack(wk, 0xC, (0x102));
        break;
    case 4:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;
    case 5:
        Wait(wk, 1);
        break;
    case 6:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060333EE, 3s-near: sf3 src/active14.c:1064 Pattern14_0060 */
void Pattern14_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060334C0, 3s-reloc: sf3 src/active14.c:1089 Pattern14_0061 */
void Pattern14_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 9, (0x102), 0, 0x8080, -1, (0x200));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 4:
        SA_Term(wk, 0x32, -1, -1, 0xBF);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603355C, 3s-near: sf3 src/active14.c:1117 Pattern14_0062 */
void Pattern14_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8038, 9, (0x200), 0, 0x8080, -1, (0x200));
        break;
    case 2:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 3:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033622, 3s-near: sf3 src/active14.c:1142 Pattern14_0063 */
void Pattern14_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 3:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 4:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 5:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    case 6:
        Wait(wk, 1);
        break;
    case 7:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033716, 3s-near: sf3 src/active14.c:1176 Pattern14_0064 */
void Pattern14_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x34, 0, 0x8080, -1, 0x200);
        break;
    case 2:
        Lever_Attack(wk, 9, 0, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 4:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 5:
        Normal_Attack(wk, 0xc, 0x102);
        break;
    case 6:
        Command_Attack(wk, 0xc, 0x1f, 10, -1);
        break;
    case 7:
        Wait(wk, 1);
        break;
    case 8:
        SA_Term(wk, 0x2f, 0x30, 0x31, 0x7f);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603381C, 3s-near: sf3 src/active14.c:1213 Pattern14_0065 */
void Pattern14_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2e, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 4:
        SA_Term(wk, 0x32, -1, -1, 0xbf);
        break;
    case 5:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060338BE, 3s-near: sf3 src/active14.c:1241 Pattern14_0066 */
void Pattern14_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x34, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033974, 3s-exact: sf3 src/active14.c:1263 Pattern14_0067 */
void Pattern14_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 2:
        Jump_Command_Attack_Term(wk, 0xB, 0x2F, 0xA, -1, -1, 0x40, 0, -1, -1, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060339EA, 3s-reloc: sf3 src/active14.c:1285 Pattern14_0068 */
void Pattern14_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033A48, 3s-exact: sf3 src/active14.c:1298 Pattern14_0069 */
void Pattern14_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033A92, 3s-exact: sf3 src/active14.c:1314 Pattern14_0070 */
void Pattern14_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033ADC, 3s-exact: sf3 src/active14.c:1330 Pattern14_0071 */
void Pattern14_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033B26, 3s-reloc: sf3 src/active14.c:1346 Pattern14_0072 */
void Pattern14_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033B84, 3s-exact: sf3 src/active14.c:1359 Pattern14_0073 */
void Pattern14_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033BC0, 3s-exact: sf3 src/active14.c:1372 Pattern14_0074 */
void Pattern14_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033BFC, 3s-exact: sf3 src/active14.c:1385 Pattern14_0075 */
void Pattern14_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033C1C, 3s-reloc: sf3 src/active14.c:1398 Pattern14_0076 */
void Pattern14_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033C94, 3s-exact: sf3 src/active14.c:1417 Pattern14_0077 */
void Pattern14_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033CD8, 3s-reloc: sf3 src/active14.c:1436 Pattern14_0078 */
void Pattern14_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033D48, 3s-exact: sf3 src/active14.c:1458 Pattern14_0079 */
void Pattern14_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033DAA, 3s-exact: sf3 src/active14.c:1483 Pattern14_0080 */
void Pattern14_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033DD6, 3s-reloc: sf3 src/active14.c:1499 Pattern14_0081 */
void Pattern14_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033E34, 3s-exact: sf3 src/active14.c:1518 Pattern14_0082 */
void Pattern14_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x82));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033E60, 3s-reloc: sf3 src/active14.c:1534 Pattern14_0083 */
void Pattern14_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 4:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 5:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033EE8, 3s-near: sf3 src/active14.c:1562 Pattern14_0084 */
void Pattern14_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 4:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 6:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 7:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033F78, 3s-near: sf3 src/active14.c:1596 Pattern14_0085 */
void Pattern14_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06033FEA, 3s-near: sf3 src/active14.c:1618 Pattern14_0086 */
void Pattern14_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, (0x82));
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034044, 3s-near: sf3 src/active14.c:1640 Pattern14_0087 */
void Pattern14_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0xE, 10, -1);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 2:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 3:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 4:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 5:
        Lever_On(wk, 1, 2);
        break;
    case 6:
        Wait(wk, 2);
        break;
    case 7:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060340F2, 3s-near: sf3 src/active14.c:1674 Pattern14_0088 */
void Pattern14_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 2:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034150, 3s-near: sf3 src/active14.c:1696 Pattern14_0089 */
void Pattern14_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x80));
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;
    case 2:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 3:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060341D4, 3s-near: sf3 src/active14.c:1718 Pattern14_0090 */
void Pattern14_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 3:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7f);
        break;
    case 4:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 5:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034256, 3s-near: sf3 src/active14.c:1746 Pattern14_0091 */
void Pattern14_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x80);
        break;
    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;
    case 4:
        Normal_Attack(wk, 9, 0x82);
        break;
    case 5:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7f);
        break;
    case 6:
        Approach_Walk(wk, 0x10, 2);
        break;
    case 7:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603431A, 3s-exact: sf3 src/active14.c:1780 Pattern14_0092 */
void Pattern14_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034384, 3s-near: sf3 src/active14.c:1799 Pattern14_0093 */
void Pattern14_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603441C, 3s-exact: sf3 src/active14.c:1818 Pattern14_0094 */
void Pattern14_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034486, 3s-reloc: sf3 src/active14.c:1837 Pattern14_0095 */
void Pattern14_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603450C, 3s-exact: sf3 src/active14.c:1856 Pattern14_0096 */
void Pattern14_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603455C, 3s-exact: sf3 src/active14.c:1872 Pattern14_0097 */
void Pattern14_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060345AC, 3s-exact: sf3 src/active14.c:1888 Pattern14_0098 */
void Pattern14_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060345FC, 3s-exact: sf3 src/active14.c:1904 Pattern14_0099 */
void Pattern14_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603464C, 3s-reloc: sf3 src/active14.c:1920 Pattern14_0100 */
void Pattern14_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, 0x80A0, 0x50, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060346D2, 3s-exact: sf3 src/active14.c:1939 Pattern14_0101 */
void Pattern14_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, 0x80A0, 0x50, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034748, 3s-reloc: sf3 src/active14.c:1958 Pattern14_0102 */
void Pattern14_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, 0x80A0, 0x50, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060347E0, 3s-exact: sf3 src/active14.c:1977 Pattern14_0103 */
void Pattern14_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;
    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, 0x80A0, 0x50, 0, 0x8080, -1, (0x200));
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034856, 3s-exact: sf3 src/active14.c:1996 Pattern14_0104 */
void Pattern14_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034890, 3s-reloc: sf3 src/active14.c:2009 Pattern14_0105 */
void Pattern14_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060348EA, 3s-exact: sf3 src/active14.c:2022 Pattern14_0106 */
void Pattern14_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034924, 3s-exact: sf3 src/active14.c:2035 Pattern14_0107 */
void Pattern14_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603495E, 3s-reloc: sf3 src/active14.c:2048 Pattern14_0108 */
void Pattern14_0108(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 76, 77, 78, 79, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034A02, 3s-exact: sf3 src/active14.c:2071 Pattern14_0109 */
void Pattern14_0109(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 80, 81, 82, 83, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034A86, 3s-reloc: sf3 src/active14.c:2094 Pattern14_0110 */
void Pattern14_0110(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 84, 85, 86, 87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034B28, 3s-exact: sf3 src/active14.c:2117 Pattern14_0111 */
void Pattern14_0111(PLW* wk) {
    s16 none = -1;
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, none, none);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, none, 73, 9, (0x102), 0, 0x8080, none, 64);
        break;
    case 3:
        Com_Random_Select(wk, 2, 88, 89, 90, 91, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034BAC, 3s-exact: sf3 src/active14.c:2140 Pattern14_0112 */
void Pattern14_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034BDE, 3s-reloc: sf3 src/active14.c:2153 Pattern14_0113 */
void Pattern14_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 8, -1);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034C74, 3s-reloc: sf3 src/active14.c:2175 Pattern14_0114 */
void Pattern14_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x300, 2, 0x76);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 3:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034D20, 3s-exact: sf3 src/active14.c:2200 Pattern14_0115 */
void Pattern14_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x80, 2, 0x76);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 3:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034DAA, 3s-reloc: sf3 src/active14.c:2225 Pattern14_0116 */
void Pattern14_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x200, 2, 0x77);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 0x8, -1);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 3:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034E54, 3s-exact: sf3 src/active14.c:2250 Pattern14_0117 */
void Pattern14_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x100, 2, 0x77);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;
    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 3:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034EDC, 3s-reloc: sf3 src/active14.c:2275 Pattern14_0118 */
void Pattern14_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034F76, 3s-exact: sf3 src/active14.c:2297 Pattern14_0119 */
void Pattern14_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x8, -1);
        break;
    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;
    case 2:
        EM_Term(wk, 0x8050, -1, 5, 6, 1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06034FEE, 3s-reloc: sf3 src/active14.c:2319 Pattern14_0120 */
void Pattern14_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035040, 3s-exact: sf3 src/active14.c:2335 Pattern14_0121 */
void Pattern14_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035088, 3s-exact: sf3 src/active14.c:2351 Pattern14_0122 */
void Pattern14_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060350D0, 3s-exact: sf3 src/active14.c:2367 Pattern14_0123 */
void Pattern14_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035118, 3s-exact: sf3 src/active14.c:2383 Pattern14_0124 */
void Pattern14_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;
    case 1:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035160, 3s-exact: sf3 src/active14.c:2399 Pattern14_0125 */
void Pattern14_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x21, 0x3F, 0x40, 0x41, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603519A, 3s-exact: sf3 src/active14.c:2412 Pattern14_0126 */
void Pattern14_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x23, 0x24, 0x25, 0x3D, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060351D4, 3s-exact: sf3 src/active14.c:2425 Pattern14_0127 */
void Pattern14_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x22, 0x43, 0x3C, 0x3E, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603520E, 3s-reloc: sf3 src/active14.c:2438 Pattern14_0128 */
void Pattern14_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035274, 3s-exact: sf3 src/active14.c:2457 Pattern14_0129 */
void Pattern14_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;
    case 1:
        Look(wk, 2);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060352C8, 3s-exact: sf3 src/active14.c:2476 Pattern14_0130 */
void Pattern14_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x71, 0x72, 0x71, 0x72, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035302, 3s-reloc: sf3 src/active14.c:2489 Pattern14_0131 */
void Pattern14_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x1A, 0x1C, 0x1D, 0x1E, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035354, 3s-exact: sf3 src/active14.c:2502 Pattern14_0132 */
void Pattern14_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 120, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035380, 3s-exact: sf3 src/active14.c:2518 Pattern14_0133 */
void Pattern14_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x86, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060353AC, 3s-exact: sf3 src/active14.c:2534 Pattern14_0134 */
void Pattern14_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x77, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060353D8, 3s-exact: sf3 src/active14.c:2550 Pattern14_0135 */
void Pattern14_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x84, 2);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035404, 3s-reloc: sf3 src/active14.c:2566 Pattern14_0136 */
void Pattern14_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x84, 0x85, 0x86, 0x87, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035464, 3s-exact: sf3 src/active14.c:2579 Pattern14_0137 */
void Pattern14_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xc, 0x102);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 8, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x2f, -1, 0x31, 0x7f);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060354EC, 3s-reloc: sf3 src/active14.c:2610 Pattern14_0138 */
void Pattern14_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x102));
        break;
    case 1:
        Normal_Attack(wk, 0xc, (0x102));
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 8, -1);
        break;
    case 4:
        Wait(wk, 5);
        break;
    case 5:
        SA_Term(wk, 0x2f, -1, 0x31, 0x7f);
        break;
    case 6:
        J_Command_Attack(wk, 8, 0x1e, 10, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035596, 3s-reloc: sf3 src/active14.c:2641 Pattern14_0139 */
void Pattern14_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Normal_Attack(wk, 0xc, 0x102);
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 9, -1);
        break;
    case 4:
        Wait(wk, 3);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1e, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603562C, 3s-exact: sf3 src/active14.c:2669 Pattern14_0140 */
void Pattern14_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 1:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 2:
        Pierce_On(wk);
        break;
    case 3:
        J_Command_Attack(wk, 0xb, 0x20, 9, -1);
        break;
    case 4:
        Wait(wk, 3);
        break;
    case 5:
        J_Command_Attack(wk, 8, 0x1e, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603569C, 3s-exact: sf3 src/active14.c:2697 Pattern14_0141 */
void Pattern14_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060356D8, 3s-reloc: sf3 src/active14.c:2710 Pattern14_0142 */
void Pattern14_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603577E, 3s-exact: sf3 src/active14.c:2732 Pattern14_0143 */
void Pattern14_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 2:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060357EA, 3s-reloc: sf3 src/active14.c:2751 Pattern14_0144 */
void Pattern14_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x26, 0x27, 0x28, 0x29, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035844, 3s-exact: sf3 src/active14.c:2764 Pattern14_0145 */
void Pattern14_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x102, 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060358BC, 3s-reloc: sf3 src/active14.c:2786 Pattern14_0146 */
void Pattern14_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06035954, 3s-exact: sf3 src/active14.c:2808 Pattern14_0147 */
void Pattern14_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060359CC, 3s-reloc: sf3 src/active14.c:2830 Pattern14_0148 */
void Pattern14_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;
    case 1:
        Turn_Over_On(wk);
        break;
    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, (0x102), 0, 0x8080, -1, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
