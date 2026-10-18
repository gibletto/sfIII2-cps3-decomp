#ifndef EFFK5_H
#define EFFK5_H

#include "structs.h"

u32 decode_mvsw();
s32 effect_K5_init(PLW* wk);
void K5_decode_new_hit_index();
void K5_init_data_copy(MVJ* mvj, K5Data* dad, s16 num);
void effect_K5_move(WORK_Other* ewk);
void K5_main_process(WORK* ewk, WORK* mwk, MVJ* mvj);
void K5_init_data(WORK* mwk, MVJ* mvj, u16* ixtbl);
void K5_init_data_copy2(K5Data* dad, MVJ* mvj, s16 num);
s32 get_cal_work(WORK* wk);
void get_master_table_address(WORK* ewk, WORK* mwk);
void get_table_adrs_K5(WORK* wk);
void init_K5_work(WORK* ewk, WORK* mwk, MVJ* mvj);
void k5_add_sub(MVJ* mvj);

#endif
