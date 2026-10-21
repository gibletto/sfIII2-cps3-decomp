/*
 * SHELL14.C  CPU anti-projectile patterns, table 14
 *
 * Behaviour patterns used by the computer-controlled player when the opponent fires a
 * projectile (VS Shell mode). Com_VS_Shell in Com_Pl calls Shell14 for players 14 and 15;
 * it runs the pattern in Pattern_Index through Shell14_Tbl. Each Shell14_nnnn routine is
 * a script stepped by CP_Index: SHELL_Term waits for the projectile, then the player jumps or
 * jump-attacks over it, follows up with normal or command attacks and ends with End_Pattern.
 * The last entry, the empty Shell14_0013, is placed at the head of aboutspr.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "SHELL14.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "cps3.h"



/* 2i 06079678, 3s-exact: sf3 src/SHELL14.c:37 Shell14 */
void Shell14(PLW* wk) {
    Shell14_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06079690, 3s-exact: sf3 src/SHELL14.c:43 Shell14_0000 */
void Shell14_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060796A4, 3s-exact: sf3 src/SHELL14.c:53 Shell14_0001 */
void Shell14_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 1, 2, 1, -1, -1);
        break;
    case 1:
        Jump(wk, 2);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060796E4, 3s-exact: sf3 src/SHELL14.c:69 Shell14_0002 */
void Shell14_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump(wk, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06079724, 3s-reloc: sf3 src/SHELL14.c:85 Shell14_0003 */
void Shell14_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 9, (0x100), 0, 0x8050, -1, (0x100));
        break;
    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;
    case 3:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060797B4, 3s-exact: sf3 src/SHELL14.c:107 Shell14_0004 */
void Shell14_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 0xB, 0x100, 0, 0x8050, -1, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06079822, 3s-reloc: sf3 src/SHELL14.c:126 Shell14_0005 */
void Shell14_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 0xB, (0x100), 0, 0x8050, -1, (0x200));
        break;
    case 2:
        Normal_Attack(wk, 8, (0x102));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060798B6, 3s-exact: sf3 src/SHELL14.c:145 Shell14_0006 */
void Shell14_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 1, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x200, 2, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 0607990E, 3s-exact: sf3 src/SHELL14.c:161 Shell14_0007 */
void Shell14_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06079940, 3s-reloc: sf3 src/SHELL14.c:174 Shell14_0008 */
void Shell14_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;
    case 1:
        Jump_Attack_Term(wk, 0x8058, 0x8030, 0xB, 0x20, 0, 0x8050, -1, 0x100);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060799D4, 3s-near: sf3 src/SHELL14.c:193 Shell14_0009 */
void Shell14_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 2, 2, 1, -1, -1);
        break;
    case 1:
        Next_Be_Flip(wk, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06079A14, 3s-near: sf3 src/SHELL14.c:212 Shell14_0010 */
void Shell14_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06079A28, 3s-near: sf3 src/SHELL14.c:222 Shell14_0011 */
void Shell14_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06079A6E, 3s-near: sf3 src/SHELL14.c:235 Shell14_0012 */
void Shell14_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, (0x380), -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

