/*
 * FOLLOW02.C  follow-up table
 *
 * Follow02 is the follow-up routine used for every character by Com_Follow; it runs the
 * Follow02_xxxx entries of Follow02_Tbl.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "FOLLOW02.h"



/* 2i 0603964C, 3s-exact: sf3 src/FOLLOW02.c:17 Follow02 */
void Follow02(PLW* wk) {
    Follow02_Tbl[Pattern_Index[wk->wu.id]](wk);
}



/* 2i 06039664, 3s-exact: sf3 src/FOLLOW02.c:23 Follow02_0000 */
void Follow02_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060396A4, 3s-exact: sf3 src/FOLLOW02.c:42 Follow02_0001 */
void Follow02_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 060396D2, 3s-exact: sf3 src/FOLLOW02.c:58 Follow02_0002 */
void Follow02_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* 2i 06039712, 3s-reloc: sf3 src/FOLLOW02.c:77 Follow02_0003 */
void Follow02_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 1:
        Command_Attack(wk, 8, 0x1C, 8);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}
