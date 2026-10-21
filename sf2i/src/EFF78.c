/*
 * EFF78.C  Effect 78: crows (bg000)
 *
 * 3s: effect_78_entry creates the two crows on BG2. effect_78_move animates them; when the
 * screen quakes (crow_fuss_check) they take off away from the players and fly to a new perch
 * (crow_fuss_move) before returning to their idle animation.
 * 2i has no crows: effect_78_move is empty and effect_78_entry only claims a work with id 78.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EFF78.h"



/* 2i 060D4304, inferred: sf3 src/EFF78.c:24 effect_78_move; 2i: empty */
void effect_78_move(WORK_Other* ewk) {
}



/* 2i 060D4308, inferred: sf3 src/EFF78.c effect_78_entry; 2i: a work with id 78 and nothing else */
s32 effect_78_entry(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 78;
    return 0;
}
