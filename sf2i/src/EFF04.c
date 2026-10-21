/*
 * EFF04.C  Effect 04: nine-piece zoom display controller
 *
 * effect_04_init starts a controller that waits a given time and then creates the nine
 * effect 17 pieces (EFF18). When the pieces report they are in place it steps an extra
 * colour through eff04_col_tbl, holds, and waits for the pieces to close before ending.
 * Any Break_Into request ends it at once.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFF18.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EFF04.h"



/* 2i 060C2380, 3s-near: sf3 src/EFF04.c:22 effect_04_move */
void effect_04_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[0] = 5;
            break;
        }
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] > 0) {
            break;
        }
        load_char_gfx(0xB2B8, 1);
        ewk->wu.routine_no[0]++;
        effect_17_init(&ewk->wu);
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[0] = 5;
            break;
        }
        if (ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[1] = 6;
            ewk->wu.old_rno[3] = 0;
            ewk->wu.extra_col = 0;
            ewk->wu.old_rno[2] = 0;
        }
        break;
    case 2:
        if (Break_Into) {
            ewk->wu.routine_no[0] = 5;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.old_rno[1] = 6;
        ewk->wu.old_rno[3]++;
        if (ewk->wu.old_rno[3] < 6) {
            ewk->wu.extra_col = eff04_col_tbl[ewk->wu.old_rno[3]];
            ewk->wu.extra_col = ewk->wu.extra_col | 0x2000;
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.old_rno[1] = 8;
        break;
    case 3:
        if (Break_Into) {
            ewk->wu.routine_no[0] = 5;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[2] = 0;
        }
        break;
    case 4:
        if (Break_Into) {
            ewk->wu.routine_no[0] = 5;
            break;
        }
        if (ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 5:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060C24FC, 3s-reloc: sf3 src/EFF04.c:99 effect_04_init */
s32 effect_04_init(s16 timer) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 4;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.old_rno[2] = 0;
    ewk->wu.old_rno[5] = timer;
    return 0;
}
