/*
 * ACTIVE00.C  Computer player patterns: end of Passive20 and the Pattern00 active set
 *
 * Step-by-step CPU pattern routines. Each pattern is a switch on CP_Index[id][0]; every case
 * calls one Com_Sub step (Walk, Normal_Attack, Jump_Attack_Term, Command_Attack, Look, ...)
 * and the last case calls End_Pattern.
 * Passive20_0123..0175 are the tail of character 20's passive (reaction) patterns, reached
 * through Passive20_Tbl.
 * Computer00 is character 0's entry in the Char_Jmp_Tbl of Com_Pl; it runs the pattern
 * selected by Pattern_Index[id] from Pattern00_Tbl (Pattern00_0000..0067).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "ACTIVE00.h"



/* 2i 06021C38, 3s-reloc: sf3 src/ACTIVE00.c:22 Computer00 */
void Computer00(PLW* wk) {
    Pattern00_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06021C50, 3s-reloc: sf3 src/ACTIVE00.c:28 Pattern00_0000 */
void Pattern00_0000(PLW* wk) {
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



/* 2i 06021C78, 3s-reloc: sf3 src/ACTIVE00.c:44 Pattern00_0001 */
void Pattern00_0001(PLW* wk) {
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



/* 2i 06021CA4, 3s-reloc: sf3 src/ACTIVE00.c:60 Pattern00_0002 */
void Pattern00_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021CD6, 3s-reloc: sf3 src/ACTIVE00.c:73 Pattern00_0003 */
void Pattern00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021D02, 3s-reloc: sf3 src/ACTIVE00.c:89 Pattern00_0004 */
void Pattern00_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021D34, 3s-near: sf3 src/ACTIVE00.c:102 Pattern00_0005 */
void Pattern00_0005(PLW* wk) {
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



/* 2i 06021D62, 3s-near: sf3 src/ACTIVE00.c:118 Pattern00_0006 */
void Pattern00_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021D80, 3s-near: sf3 src/ACTIVE00.c:131 Pattern00_0007 */
void Pattern00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 2, 0x3E);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021DE2, 3s-reloc: sf3 src/ACTIVE00.c:144 Pattern00_0008 */
void Pattern00_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x80);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021E0E, 3s-reloc: sf3 src/ACTIVE00.c:160 Pattern00_0009 */
void Pattern00_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump(wk, 1);
        break;
    case 2:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021E44, 3s-near: sf3 src/ACTIVE00.c:179 Pattern00_0010 */
void Pattern00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021E64, 3s-reloc: sf3 src/ACTIVE00.c:192 Pattern00_0011 */
void Pattern00_0011(PLW* wk) {
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



/* 2i 06021E90, 3s-near: sf3 src/ACTIVE00.c:208 Pattern00_0012 */
void Pattern00_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021ED4, 3s-reloc: sf3 src/ACTIVE00.c:221 Pattern00_0013 */
void Pattern00_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021EF4, 3s-reloc: sf3 src/ACTIVE00.c:234 Pattern00_0014 */
void Pattern00_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 2, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021F36, 3s-reloc: sf3 src/ACTIVE00.c:247 Pattern00_0015 */
void Pattern00_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021F58, 3s-near: sf3 src/ACTIVE00.c:260 Pattern00_0016 */
void Pattern00_0016(PLW* wk) {
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



/* 2i 06021F88, 3s-near: sf3 src/ACTIVE00.c:276 Pattern00_0017 */
void Pattern00_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06021FBA, 3s-near: sf3 src/ACTIVE00.c:289 Pattern00_0018 */
void Pattern00_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022012, 3s-near: sf3 src/ACTIVE00.c:302 Pattern00_0019 */
void Pattern00_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 2, 0x3C);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022052, 3s-near: sf3 src/ACTIVE00.c:318 Pattern00_0020 */
void Pattern00_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 8, 0x10, 0, 8, 8, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022094, 3s-near: sf3 src/ACTIVE00.c:331 Pattern00_0021 */
void Pattern00_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, 0x8070, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022100, 3s-near: sf3 src/ACTIVE00.c:344 Pattern00_0022 */
void Pattern00_0022(PLW* wk) {
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



/* 2i 06022162, 3s-near: sf3 src/ACTIVE00.c:366 Pattern00_0023 */
void Pattern00_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022182, 3s-near: sf3 src/ACTIVE00.c:379 Pattern00_0024 */
void Pattern00_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060221A4, 3s-near: sf3 src/ACTIVE00.c:392 Pattern00_0025 */
void Pattern00_0025(PLW* wk) {
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



/* 2i 060221F8, 3s-reloc: sf3 src/ACTIVE00.c:408 Pattern00_0026 */
void Pattern00_0026(PLW* wk) {
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



/* 2i 06022236, 3s-reloc: sf3 src/ACTIVE00.c:424 Pattern00_0027 */
void Pattern00_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8050, 0xB, 0x20, 0, 0x8070, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022278, 3s-near: sf3 src/ACTIVE00.c:437 Pattern00_0028 */
void Pattern00_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022298, 3s-near: sf3 src/ACTIVE00.c:450 Pattern00_0029 */
void Pattern00_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x80);
        break;
    case 1:
        Adjust_Attack(wk, 0xC, 0x80);
        break;
    case 2:
        Adjust_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022304, 3s-reloc: sf3 src/ACTIVE00.c:469 Pattern00_0030 */
void Pattern00_0030(PLW* wk) {
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



/* 2i 06022348, 3s-reloc: sf3 src/ACTIVE00.c:488 Pattern00_0031 */
void Pattern00_0031(PLW* wk) {
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



/* 2i 06022388, 3s-near: sf3 src/ACTIVE00.c:504 Pattern00_0032 */
void Pattern00_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060223B6, 3s-near: sf3 src/ACTIVE00.c:520 Pattern00_0033 */
void Pattern00_0033(PLW* wk) {
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



/* 2i 06022400, 3s-near: sf3 src/ACTIVE00.c:536 Pattern00_0034 */
void Pattern00_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x3D);
        break;
    case 1:
        Adjust_Attack(wk, 9, 0x80);
        break;
    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602244E, 3s-near: sf3 src/ACTIVE00.c:555 Pattern00_0035 */
void Pattern00_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602246E, 3s-near: sf3 src/ACTIVE00.c:568 Pattern00_0036 */
void Pattern00_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602248E, 3s-near: sf3 src/ACTIVE00.c:581 Pattern00_0037 */
void Pattern00_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;
    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060224BC, 3s-near: sf3 src/ACTIVE00.c:597 Pattern00_0038 */
void Pattern00_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;
    case 1:
        Normal_Attack(wk, 0xA, 0x102);
        break;
    case 2:
        Check_BOSS(wk, 6, 0x3E);
        break;
    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022538, 3s-near: sf3 src/ACTIVE00.c:616 Pattern00_0039 */
void Pattern00_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022578, 3s-near: sf3 src/ACTIVE00.c:632 Pattern00_0040 */
void Pattern00_0040(PLW* wk) {
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



/* 2i 060225C0, 3s-near: sf3 src/ACTIVE00.c:648 Pattern00_0041 */
void Pattern00_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 2, 0x3E);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602262A, 3s-near: sf3 src/ACTIVE00.c:664 Pattern00_0042 */
void Pattern00_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602266A, 3s-near: sf3 src/ACTIVE00.c:683 Pattern00_0043 */
void Pattern00_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x200, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060226AC, 3s-near: sf3 src/ACTIVE00.c:696 Pattern00_0044 */
void Pattern00_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x8040, 8, 0x40, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060226EE, 3s-near: sf3 src/ACTIVE00.c:709 Pattern00_0045 */
void Pattern00_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x8040, 8, (0x200), 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022748, 3s-near: sf3 src/ACTIVE00.c:722 Pattern00_0046 */
void Pattern00_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602277A, 3s-near: sf3 src/ACTIVE00.c:735 Pattern00_0047 */
void Pattern00_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060227AC, 3s-near: sf3 src/ACTIVE00.c:748 Pattern00_0048 */
void Pattern00_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060227DE, 3s-near: sf3 src/ACTIVE00.c:761 Pattern00_0049 */
void Pattern00_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022810, 3s-near: sf3 src/ACTIVE00.c:774 Pattern00_0050 */
void Pattern00_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0602285E, 3s-reloc: sf3 src/ACTIVE00.c:787 Pattern00_0051 */
void Pattern00_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022890, 3s-near: sf3 src/ACTIVE00.c:800 Pattern00_0052 */
void Pattern00_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x31, 0x32, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060228CE, 3s-near: sf3 src/ACTIVE00.c:819 Pattern00_0053 */
void Pattern00_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022908, 3s-near: sf3 src/ACTIVE00.c:832 Pattern00_0054 */
void Pattern00_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x32, 0x32, 0x33, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022942, 3s-near: sf3 src/ACTIVE00.c:845 Pattern00_0055 */
void Pattern00_0055(PLW* wk) {
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



/* 2i 06022984, 3s-near: sf3 src/ACTIVE00.c:861 Pattern00_0056 */
void Pattern00_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x8048, 8, 0x200, 1, 0x8070, -1, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060229D6, 3s-near: sf3 src/ACTIVE00.c:877 Pattern00_0057 */
void Pattern00_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 2, 0x34);
        break;
    case 1:
        Command_Attack(wk, 8, 0x8018, 0xA, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022A16, 3s-near: sf3 src/ACTIVE00.c:893 Pattern00_0058 */
void Pattern00_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;
    case 1:
        Look(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022A3E, 3s-near: sf3 src/ACTIVE00.c:909 Pattern00_0059 */
void Pattern00_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022AA6, 3s-reloc: sf3 src/ACTIVE00.c:922 Pattern00_0060 */
void Pattern00_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022AC8, 3s-reloc: sf3 src/ACTIVE00.c:935 Pattern00_0061 */
void Pattern00_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022AF4, 3s-reloc: sf3 src/ACTIVE00.c:951 Pattern00_0062 */
void Pattern00_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022B14, 3s-near: sf3 src/ACTIVE00.c:964 Pattern00_0063 */
void Pattern00_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x20);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06022B36, 3s-near: sf3 src/ACTIVE00.c:977 Pattern00_0064 */
void Pattern00_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xA);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

