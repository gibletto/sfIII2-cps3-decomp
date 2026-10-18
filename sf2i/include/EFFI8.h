#ifndef EFFI8_H
#define EFFI8_H

#include "structs.h"

s32 check_ball_mizushibuki();
void cal_speeds_to_me_effI8(WORK_Other* ewk, PLW* mwk);
void effI8_main_process(WORK_Other* ewk);
void cal_speeds_to_em_effI8(WORK_Other* ewk, PLW* twk);
void effect_I8_move(WORK_Other* ewk);
s32 effect_I8_init();
void bbbs_ball_set(PLW* wk, const BBBSTable* dadr);

#endif
