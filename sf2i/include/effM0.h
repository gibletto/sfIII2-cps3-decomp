#ifndef EFFM0_H
#define EFFM0_H

#include "structs.h"

void animal_0005(WORK_Other* ewk);
void animal_0000(WORK_Other* ewk);
void animal_0001(WORK_Other* ewk);
void animal_0002(WORK_Other* ewk);
void animal_0004(WORK_Other* ewk);
void animal_control(WORK_Other* ewk);
void animal_init(WORK_Other* ewk);
void cat_run_set(WORK_Other* ewk);
void cat_run_set2(WORK_Other* ewk);
void don_run_set(WORK_Other* ewk);
void effect_M0_move(WORK_Other* ewk);
void cat_walk_set(WORK_Other* ewk);
void mouse_run_set(WORK_Other* ewk);
void mouse_stand_set(WORK_Other* ewk);

s32 effect_M0_init(u8 pl_rl, u8 animal_type);

#endif
