/*
 * EFFF6.C  Opening demo moving sprites (effect F6)
 *
 * Sprites of the attract-mode opening that slide into place. Like EFF36, each object is
 * active between a start and an end value of the opening timeline op_w.index.
 * effect_F6_init(typenum) reads colour, position, priority, animation and timing from
 * efff6_data_tbl00 and direction, target point, zoom and speeds from efff6_etc_data.
 * efff6_move_common moves the sprite along X, Y or a diagonal until it reaches its target;
 * efff6_move01 adds a short colour ramp (type 0x1B). Created from end_main.c and LOSE_PL.
 * 2i: a counter, not sprites: effect_F6_init starts effect F7 with it as the master, and
 * effect_F6_move counts routine_no[0] up every old_rno[1] frames, setting effF6_end_flag at 23.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "efff6.h"
#include "efff7.h"

extern s16 effF6_end_flag;   /* provisional name */



/* 2i 060E60D0, inferred: sf3 src/efff6.c:26 effect_F6_move; 2i: a step counter (3s: the opening sprites) */
void effect_F6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[3] = 0;
        /* fall through */
    case 1:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[2] = ewk->wu.old_rno[1];
            if (ewk->wu.routine_no[0] == 23) {
                effF6_end_flag = 1;
                ewk->wu.routine_no[1]++;
                ewk->wu.old_rno[3] = 1;
            }
        }
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    case 3:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060E615A (no table row; the census calls 3s effect_F6_init absent): sf3 src/efff6.c effect_F6_init; 2i: the counter and effect F7 */
s32 effect_F6_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 0x9C;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[2] = ewk->wu.old_rno[1] = 2;
    effect_F7_init(ewk);
    return 0;
}
