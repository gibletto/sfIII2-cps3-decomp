#ifndef EFFD5_H
#define EFFD5_H

#include "structs.h"

void cal_speeds(WORK_Other* ewk, PLW* , PLW* twk);
s32 effect_D5_init(WORK* wk);
void effD5_main_process(WORK_Other* ewk);
void setup_hana_extra(WORK* wk, s16 num, s16 acc);
void effect_D5_move(WORK_Other* ewk);
s32 effect_D6_init();
void effect_D6_move(WORK_Other* ewk);
s32 my_rose_live_check(PLW* wk);

#endif
