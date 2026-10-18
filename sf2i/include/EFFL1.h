#ifndef EFFL1_H
#define EFFL1_H

#include "structs.h"

void effL1_f_col_adjust(WORK_Other_CONN* ewk, s16 n);
void effL1_f_stage_r_init(WORK_Other_CONN* ewk);
void effL1_f_grade_init(WORK_Other_CONN* ewk);
void effL1_f_kz_cont_init(WORK_Other_CONN* ewk);
void effL1_f_kz_spp_init(WORK_Other_CONN* ewk);
void effL1_f_mk_all_init(WORK_Other_CONN* ewk);
void effL1_f_mk_spp_init(WORK_Other_CONN* ewk);
void effL1_f_score_init(WORK_Other_CONN* ewk);
void effL1_f_stage_p_init(WORK_Other_CONN* ewk);
void effL1_k_grade_init(WORK_Other_CONN* ewk);
void effL1_k_graph_init(WORK_Other_CONN* ewk);
void effL1_suuchi_bunkai_sub(WORK_Other_CONN* ewk, u32 tsc);
void effL1_w_grade_init(WORK_Other_CONN* ewk);
void effL1_w_graph_init(WORK_Other_CONN* ewk);
void effL1_w_score_init(WORK_Other_CONN* ewk);
void effL1_w_win_init(WORK_Other_CONN* ewk);
s32 effect_L1_init(s16 flag);
void effect_L1_move(WORK_Other_CONN* ewk);
void effL1_trans(WORK* ewk);

#endif
