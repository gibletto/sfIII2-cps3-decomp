#ifndef GRADE_H
#define GRADE_H

#include "structs.h"

void grade_final_grade_bonus(void);
s32 grade_scale_to_percent(s16 value);
void grade_makeup_round_para_dko(void);
void grade_makeup_round_parameter(s16 ix);
void grade_makeup_bonus_parameter(s16 PL_id);
void grade_makeup_final_parameter();
void makeup_spp_frdat();
void grade_makeup_stage_para_com();
void grade_makeup_judgement_gals(void);
void check_guard_miss();
void renew_judge_final_work();
s32 get_offence_total();
s32 get_defence_total();
s32 get_ex_point_total();
s32 get_grade_ix();
s32 get_tech_pts_total();
void grade_add_att_renew(WORK_Other* wk);
void grade_add_blocking(PLW* wk);
void grade_add_clean_hits(WORK_Other* wk);
void grade_add_command_waza(s16 ix);
void grade_add_em_stun(s16 ix);
void grade_add_grap_def(s16 ix);
void grade_add_guard_success(s16 ix);
void grade_add_leap_attack(s16 ix);
void grade_add_nml_nage(WORK* wk);
void grade_add_onaji_waza(s16 ix);
void grade_add_personal_action(s16 ix);
void grade_add_quick_stand(s16 ix);
void grade_add_reversal();
void grade_add_super_arts(s16 ix, s16 num);
void grade_add_target_combo(s16 ix);
void grade_check_tairyokusa(void);
s32 grade_check_work_1st_init();
void grade_check_work_stage_init(s16 ix);
s32 grade_get_cm_point_percentage();
void grade_get_first_attack();
s32 grade_get_my_grade(s16 ix);
s32 grade_get_my_point_percentage();
void grade_max_combo_check();
void grade_set_round_result(s16 ix);
void backup_RO_PT(void);
void grade_store_vitality();
u32 rannyuu_Q_check(s16 pl);
void grade_makeup_stage_parameter(s16 ix);
void grade_check_work_round_init();
void makeup_final_grade();

#endif
