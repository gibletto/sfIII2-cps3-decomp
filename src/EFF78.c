/*
 * EFF78.C  Effect 78: an empty effect
 *
 * effect_78_move is empty and effect_78_entry only claims a work with id 78.
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



/* empty */
void effect_78_move(WORK_Other* ewk) {
}



/* a work with id 78 and nothing else */
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
