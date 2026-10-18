#ifndef EFFC2_H
#define EFFC2_H

#include "structs.h"

s32 c2_last_dir_select(PLW* wk, WORK* efw);
s32 bs2_sync_bomb(WORK* wk);
void bs2_status_disp(WORK* wk);
void clear_bs2_floor(WORK_Other* wk);
void init_bs2_floor(void);
s32 effect_C2_init(WORK* wk, u8 data);
void bs2_get_parts_break(WORK* wk);
void c2_last_char_and_mvxy(WORK_Other* ewk);
void c3_new_damage(WORK* wk);
s32 check_effc2_p2_rno(WORK* wk);
s32 check_parts_break_level(WORK* wk);
void copy_rno(WORK* wk);
void effC2_main_process_first(WORK_Other* ewk, PLW* twk);
void effC2_main_process_second(WORK_Other* ewk, PLW* twk);
void bs2_score_add_next(WORK* wk);
void set_1st_Bonus_Game_result();
void effc2_parts_work_chain_check(s16 flag);
void effect_C2_move(WORK_Other* ewk);
void setup_vital_bonus2();
void get_bs2_parts_data(WORK* wk);
void player_hosei_data();
void get_shizumi_guai(WORK* wk);
void send_to_shizumi_guai(WORK* wk);
void set_bs2_floor(WORK_Other* wk);
void set_c2_quake(WORK* wk);
void set_parts_priority(WORK* wk);
void setup_demojump(PLW* twk, s16 ix);
void setup_parts_break(WORK* wk);
void setup_parts_break2(WORK* wk);
void setup_prio_ix(WORK_Other* c2wk);

#endif
