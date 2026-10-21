#ifndef END_MAIN_H
#define END_MAIN_H

#include "structs.h"

void Ending_init(void);
s32 Ending_main(s16 pl_num);
void op_111_move(void);
void op_112_move(void);
void op_113_move(void);
void op_115_move(void);
void op_116_move(void);
void op_117_move(void);
void op_bg_off(void);
void op_bg0_0002(s16 r_index);
void op_bg0_0004(s16 r_index);
void op_bg0_0005(s16 r_index);
void op_bg0_0006(s16 r_index);
void op_bg0_0007(s16 r_index);
void op_bg0_0008(s16 r_index);
void op_bg0_0009(s16 r_index);
void op_bg0_0010(s16 r_index);
void op_bg0_0011(s16 r_index);
void op_bg0_0012(s16 r_index);
void op_bg0_0013(s16 r_index);
void op_bg0_0015(s16 r_index);
void op_bg0_0016(s16 r_index);
void opening_title_00();
void end_scn_pos_set(u16 bg_no);
void end_bg_block_attr_set(s16 bg, s32 ofs, s16 w, s32 cell, s16 h);
void end_bg_block_attr_add(s16 bg, u16 ofs, s16 w, s32 cell, s16 h);
void op_118_move(void);
void common_end_init00(s16 pl_num);
void common_end_init01(void);
void op_107_move(void);
void op_109_move(void);
void op_110_move(void);
void op_114_move(void);
void op_bg0_0000(s16 r_index);
void op_bg0_0001(s16 r_index);
void op_bg0_0003(s16 r_index);
void op_bg1_0000();
void op_bg1_0001();
void op_bg1_0002(s16 r_index);
void op_bg1_0003(s16 r_index);
void end_X_com01(void);
void end_bg_pos_hosei(s16 bg_no);
void end_bg_pos_hosei2(void);
void end_fade_bgm(void);
s16 end_fade_complete(void);
void end_fam_set(s16 i);
void end_fam_set2(void);
void end_main_move(s16 pl_num);
void end_reset_etc();
void end_scn_pos_set2(void);
void ending_effects_cleanup(void);
void fadeout_to_staff_roll(void);
void normal_ending();
s32 Cut_Cut_Cut_t(void);
void op_bg0_move();
void op_bg_move();
void op_bg1_move();
void op_bg2_move();
void opening_bgw_commit_pos();
void opening_title_01();
void opening_title(void);
void op_108_move(void);
void op_bg0_0014(s16 r_index);
void end_00000(void);
void update_all_disp_pos_ending(void);

void scrn_map_set(u16 n, u32 p);
void scrn_map_set_now(u16 n, u32 p);

#endif
