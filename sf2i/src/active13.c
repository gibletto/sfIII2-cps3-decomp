/*
 * ACTIVE13.C  CPU active patterns for player 13 (Urien)
 *
 * Behaviour patterns for the computer-controlled player 13 in active (attacking) mode.
 * Com_Active in Com_Pl calls Computer13, which runs the pattern chosen in Pattern_Index
 * through Pattern13_Tbl. Each Pattern13_nnnn routine is a short script stepped by
 * CP_Index: walks and approaches, waits, range and area checks, normal, lever, command and jump
 * attacks, random branches to other patterns, and End_Pattern to finish.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "active13.h"


/* 2i 06030DBC, 3s-reloc: sf3 src/active13.c:19 Computer13 */
void Computer13(PLW* wk) {
    Pattern13_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06030DD4, 3s-reloc: sf3 src/active13.c:25 Pattern13_0000 */
void Pattern13_0000(PLW* wk) {
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


/* 2i 06030DFC, 3s-reloc: sf3 src/active13.c:40 Pattern13_0001 */
void Pattern13_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030E28, 3s-reloc: sf3 src/active13.c:56 Pattern13_0002 */
void Pattern13_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030E5A, 3s-reloc: sf3 src/active13.c:69 Pattern13_0003 */
void Pattern13_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xD, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030E86, 3s-reloc: sf3 src/active13.c:85 Pattern13_0004 */
void Pattern13_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030EB8, 3s-near: sf3 src/active13.c:98 Pattern13_0005 */
void Pattern13_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030EE6, 3s-near: sf3 src/active13.c:114 Pattern13_0006 */
void Pattern13_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x3C);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030F04, 3s-near: sf3 src/active13.c:127 Pattern13_0007 */
void Pattern13_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030F56, 3s-reloc: sf3 src/active13.c:140 Pattern13_0008 */
void Pattern13_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, (0x80));
        break;
    case 1:
        Normal_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030F82, 3s-reloc: sf3 src/active13.c:156 Pattern13_0009 */
void Pattern13_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Lever_On(wk, 1, 2);
        break;
    case 3:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030FC4, 3s-reloc: sf3 src/active13.c:178 Pattern13_0010 */
void Pattern13_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06030FE4, 3s-reloc: sf3 src/active13.c:191 Pattern13_0011 */
void Pattern13_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
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



/* 2i 06031044, 3s-reloc: sf3 src/active13.c:210 Pattern13_0012 */
void Pattern13_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031064, 3s-reloc: sf3 src/active13.c:223 Pattern13_0013 */
void Pattern13_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031084, 3s-reloc: sf3 src/active13.c:236 Pattern13_0014 */
void Pattern13_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 2, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060310C6, 3s-reloc: sf3 src/active13.c:249 Pattern13_0015 */
void Pattern13_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060310E8, 3s-reloc: sf3 src/active13.c:262 Pattern13_0016 */
void Pattern13_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031118, 3s-reloc: sf3 src/active13.c:278 Pattern13_0017 */
void Pattern13_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603116E, 3s-reloc: sf3 src/active13.c:291 Pattern13_0018 */
void Pattern13_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060311A0, 3s-reloc: sf3 src/active13.c:304 Pattern13_0019 */
void Pattern13_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060311D2, 3s-reloc: sf3 src/active13.c:317 Pattern13_0020 */
void Pattern13_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 8, 0x10, 0, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031214, 3s-reloc: sf3 src/active13.c:330 Pattern13_0021 */
void Pattern13_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, (0x200), 0, 0x8070, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603127C, 3s-near: sf3 src/active13.c:343 Pattern13_0022 */
void Pattern13_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Search_Back_Term(wk, 0x60, 2, 0x12);
        break;
    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060312DE, 3s-near: sf3 src/active13.c:365 Pattern13_0023 */
void Pattern13_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060312FE, 3s-near: sf3 src/active13.c:378 Pattern13_0024 */
void Pattern13_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031320, 3s-near: sf3 src/active13.c:391 Pattern13_0025 */
void Pattern13_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;
    case 1:
        Walk(wk, 1, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031350, 3s-reloc: sf3 src/active13.c:407 Pattern13_0026 */
void Pattern13_0026(PLW* wk) {
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



/* 2i 0603138E, 3s-reloc: sf3 src/active13.c:423 Pattern13_0027 */
void Pattern13_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x10, 0, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060313D0, 3s-reloc: sf3 src/active13.c:436 Pattern13_0028 */
void Pattern13_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060313F0, 3s-reloc: sf3 src/active13.c:449 Pattern13_0029 */
void Pattern13_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, (0x80));
        break;
    case 1:
        Adjust_Attack(wk, 0xC, (0x80));
        break;
    case 2:
        Adjust_Attack(wk, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031464, 3s-reloc: sf3 src/active13.c:468 Pattern13_0030 */
void Pattern13_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x10);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x20);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060314A8, 3s-reloc: sf3 src/active13.c:487 Pattern13_0031 */
void Pattern13_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060314E8, 3s-near: sf3 src/active13.c:503 Pattern13_0032 */
void Pattern13_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Lever_On(wk, 1, 2);
        break;
    case 2:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031562, 3s-near: sf3 src/active13.c:525 Pattern13_0033 */
void Pattern13_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031590, 3s-near: sf3 src/active13.c:541 Pattern13_0034 */
void Pattern13_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060315C2, 3s-near: sf3 src/active13.c:554 Pattern13_0035 */
void Pattern13_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060315E2, 3s-near: sf3 src/active13.c:567 Pattern13_0036 */
void Pattern13_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031602, 3s-near: sf3 src/active13.c:580 Pattern13_0037 */
void Pattern13_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Lever_On(wk, 1, 2);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;
    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031680, 3s-reloc: sf3 src/active13.c:602 Pattern13_0038 */
void Pattern13_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0);
        break;
    case 1:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xA, (0x102));
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060316DC, 3s-reloc: sf3 src/active13.c:624 Pattern13_0039 */
void Pattern13_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, (0x100));
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603171C, 3s-near: sf3 src/active13.c:640 Pattern13_0040 */
void Pattern13_0040(PLW* wk) {
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



/* 2i 06031786, 3s-near: sf3 src/active13.c:656 Pattern13_0041 */
void Pattern13_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    case 1:
        Normal_Attack(wk, 8, (0x202));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060317C6, 3s-near: sf3 src/active13.c:672 Pattern13_0042 */
void Pattern13_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031816, 3s-near: sf3 src/active13.c:694 Pattern13_0043 */
void Pattern13_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031878, 3s-near: sf3 src/active13.c:707 Pattern13_0044 */
void Pattern13_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060318BA, 3s-near: sf3 src/active13.c:720 Pattern13_0045 */
void Pattern13_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8040, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060318FC, 3s-near: sf3 src/active13.c:733 Pattern13_0046 */
void Pattern13_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0603192E, 3s-near: sf3 src/active13.c:746 Pattern13_0047 */
void Pattern13_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031960, 3s-near: sf3 src/active13.c:759 Pattern13_0048 */
void Pattern13_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060319B2, 3s-near: sf3 src/active13.c:772 Pattern13_0049 */
void Pattern13_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060319E4, 3s-near: sf3 src/active13.c:785 Pattern13_0050 */
void Pattern13_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0x9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031A16, 3s-near: sf3 src/active13.c:798 Pattern13_0051 */
void Pattern13_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031A48, 3s-near: sf3 src/active13.c:811 Pattern13_0052 */
void Pattern13_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031A86, 3s-near: sf3 src/active13.c:824 Pattern13_0053 */
void Pattern13_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031AC0, 3s-near: sf3 src/active13.c:837 Pattern13_0054 */
void Pattern13_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x32, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031AFA, 3s-near: sf3 src/active13.c:850 Pattern13_0055 */
void Pattern13_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;
    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031B28, 3s-near: sf3 src/active13.c:866 Pattern13_0056 */
void Pattern13_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8048, 8, (0x200), 1, 0x8070, -1, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031B9A, 3s-reloc: sf3 src/active13.c:882 Pattern13_0057 */
void Pattern13_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031BCC, 3s-reloc: sf3 src/active13.c:895 Pattern13_0058 */
void Pattern13_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031BFE, 3s-near: sf3 src/active13.c:908 Pattern13_0059 */
void Pattern13_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031C30, 3s-near: sf3 src/active13.c:921 Pattern13_0060 */
void Pattern13_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031C8C, 3s-near: sf3 src/active13.c:934 Pattern13_0061 */
void Pattern13_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031CBE, 3s-near: sf3 src/active13.c:947 Pattern13_0062 */
void Pattern13_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031CF0, 3s-near: sf3 src/active13.c:960 Pattern13_0063 */
void Pattern13_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 7, 2, 0x44);
        break;
    case 1:
        Check_SA(wk, 2, 0x44);
        break;
    case 2:
        Branch_Unit_Area(wk, 2, 0x40, 0x40, 0x41, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031D44, 3s-near: sf3 src/active13.c:979 Pattern13_0064 */
void Pattern13_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 9, -1);
        break;
    case 1:
        Check_SA(wk, 2, 0x35);
        break;
    case 2:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031DAA, 3s-near: sf3 src/active13.c:1001 Pattern13_0065 */
void Pattern13_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    case 1:
        Check_SA(wk, 2, 0x35);
        break;
    case 2:
        Command_Attack(wk, 8, 0x8016, 8, -1);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031E10, 3s-near: sf3 src/active13.c:1023 Pattern13_0066 */
void Pattern13_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;
    case 1:
        Check_SA(wk, 2, 0x34);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    case 3:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031EA4, 3s-near: sf3 src/active13.c:1045 Pattern13_0067 */
void Pattern13_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;
    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031EEC, 3s-near: sf3 src/active13.c:1061 Pattern13_0068 */
void Pattern13_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, 0x3C, -1);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031F34, 3s-near: sf3 src/active13.c:1077 Pattern13_0069 */
void Pattern13_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8060, 0x8040, 8, 0x40, 0, 0x8070, 8, (0x200));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06031F78, 3s-near: sf3 src/active13.c:1090 Pattern13_0070 */
void Pattern13_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
