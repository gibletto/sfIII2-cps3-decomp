/*
 * FOLLOW01.C  older follow-up table
 *
 * Follow01 runs the Follow01_xxxx entries of Follow01_Tbl, an older four-entry version of
 * the follow-up in FOLLOW02.C. Nothing calls it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "FOLLOW01.h"



/* provisional name */
/* 2i 06039508, 3s-exact: sf3 src/FOLLOW01.c:18 Follow01 */
void Follow01(PLW* wk) {
    Follow01_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* provisional name */
/* 2i 06039520, 3s-exact: sf3 src/FOLLOW01.c:25 Follow01_0000 */
void Follow01_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
/* 2i 06039560, 3s-exact: sf3 src/FOLLOW01.c:45 Follow01_0001 */
void Follow01_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 2, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
/* 2i 060395A0, 3s-reloc: sf3 src/FOLLOW01.c:62 Follow01_0002 */
void Follow01_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, (0x100));
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
/* 2i 060395FC, 3s-reloc: sf3 src/FOLLOW01.c:82 Follow01_0003 */
void Follow01_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 2, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
