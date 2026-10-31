/*
 * END_MAIN.C  Opening demo, ending plane positions and the combo demo players
 *
 * opening_demo_tick runs the opening each frame through opening_init2 (scroll graphics, BG work and planes),
 * opening_move (fifteen scenes, the first ones also moving the combo demo players) and opening_title_00 (the
 * title in one routine). The scenes keep their BG plane positions on screen through
 * op_scrn_pos_set2 (called with bsr from the scenes in range).
 *
 * Bg_Family_Set_op copies the scroll positions of BG planes 0-3 and 5 to their display positions and
 * families. combo_demo_move counts op_plmove_timer down, loads the next of the three demo setups
 * (combo_demo_load) when it reaches zero and moves the players while it is below zero; combo_demo_set_position
 * puts a player at the demo's start position. ending_effects_cleanup kills the effects the endings leave behind.
 *
 * bg_cell_write (u5 as u16), scfont_page0_fill (attr as u16) and Scrn_Move_Set are declared here with the
 * argument types the opening uses; end_3/5/11 use bg_sub.h's s32 u5.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "Com_Pl.h"
#include "aboutspr.h"
#include "bg000.h"
#include "fifo.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "EFFM7.h"
#include "EM_Cand.h"
#include "end_sub_8.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "effe9.h"
s32 Check_Fade_Complete(void);
s32 Request_Fade();
void scfont_page0_fill(u16 attr, u16 code);
void Disp_Copyright(void);
void scrn_pos_clear(void);
void bg_cell_write(s16 bg, s32 ofs, s32 cell, u32 src, u16 u5, s16 attr);
u32 simmram_small_page_alloc_40(s32 kind);
s32 chr_dma_request();
s32 simmram_block_alloc_10(s32 blocks, s32 kind);
s32 sprite_list_setup();
u32 simmram_big_page_alloc_40(s32 kind);
u32 simmram_slot_addr(s16 no);
u32 simmram_slot_to_offset(s16 handle);
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "sc_trans.h"
#include "end_staff.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"



extern const s32 combo_demo_pos_tbl[3][2];
extern const s16 combo_demo_timer_tbl[];
extern const s16 op_timer_tbl[14];
extern const PANEL* op_panel_p[4];
void scrn_attr_set(u16 n, u16 attr, u16 bits);
void scrn_map_set(u16 n, u32 p);
void scrn_map_set_now(u16 n, u32 p);

void suzi_line_fix_set2(void);
#include "end_main.h"
extern s8 effE1_end_flag;
extern const OP_CTR_SET op_ctr_set[2];
extern const OP_SCRN_POS op_scrn_pos_tbl[4];
void opening_pl_disp(void);
void opening_scrn_map_set(void);
void opening_scrn_pos_set();
void Scrn_Move_Set(s32 n, s16 x, s16 y);



/* provisional name */
void op_w_clear(void) {
    op_w.r_no_0 = 0;
    op_w.r_no_1 = 0;
    op_w.r_no_2 = 0;
    op_w.index = 0;
    op_w.mv_ctr = 0;
}



void op_work_clear(void) {
    s16 i;
    for (i = 0; i < 3; i++) {
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
    }
}



/* provisional name */
s16 opening_demo_tick(void) {
    void (*opening_demo_jp[3])() = { opening_init2, opening_move, opening_title_00 };
    Game_timer++;
    opening_demo_jp[op_w.r_no_0]();
    Bg_Family_Set_op();
    return op_end_flag;
}



void opening_init2(void) {
    Game_timer = 0;
    switch (op_w.r_no_1) {
    case 0:
        opning_init_00000();
        break;
    case 1:
        opning_init_01000();
        break;
    case 2:
        opning_init_02000();
        break;
    }
}



void opning_init_00000(void) {
    s16 i;
    op_w.r_no_1++;
    op_end_flag = 0;
    bg_vbl_trans_flag = 0;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    scr_cg_c_no = simmram_block_alloc_10(0x195, 1);
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    bg_w.scno = 1;
    chr_dma_request(0x01705800, 0, 0, 3);
    chr_dma_request(0x01705880, bg_w.scroll_cg_adr, 0x1948F, 1);
    if (Game_setting.Screen_Mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    for (i = 0; i < 6; i++) {
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].wxy[0].cal = 0x2000000;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0x2000000;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0x2000000;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].position_x = 0x200 - bg_w.pos_offset;
        bg_w.bgw[i].position_y = 0;
    }
    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].fam_no = i;
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, (u32)bg_w.bgw[i].bg_address);
        scrn_map_set(i, (u32)bg_w.bgw[i].bg_address);
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
        op_w.bgw[i].bg_no = i;
    }
    sprite_list_setup(0, 1, op_scr_record_data_0);
    sprite_list_setup(1, 1, op_scr_record_data_1);
    sprite_list_setup(2, 1, op_scr_record_data_2);
    sprite_list_setup(3, 1, op_scr_record_data_3);
    op_w.r_no_2 = 0;
    op_end_flag = 0;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_w.chase_flag = 0;
    Combo_Demo_Flag = 0x81;
}



void opning_init_01000(void) {
    s16 i;
    s16 j;
    const PANEL* p;
    const PANEL* q;
    op_w.r_no_1++;
    for (i = 0; i < 4; i++) {
        p = op_panel_p[i];
        for (j = 0; j < 16; j++) {
            q = p;
            q += j;
            bg_cell_write(i, q->ofs, q->cell, (u32)op_bg0_scrn_data, 0, 0x2C0);
        }
        Bg_On_R(1 << i);
        Bg_On_W(1 << i);
        scrn_attr_set(i, 0, 31);
        scrn_reg_w[i].ctrl &= 0xFE7F;
    }
    Bg_Off_R(0xFF);
    Bg_Off_W(0xFF);
    op_w.free_work = 8;
    BGM_Request(1);
    Scrn_Move_Set(0, 512 - bg_w.pos_offset, 512);
    bg_w.bgw[0].suzi_c_no = simmram_small_page_alloc_40(1);
    bg_w.bgw[0].suzi_adrs = (u16*)simmram_slot_addr(bg_w.bgw[0].suzi_c_no);
    scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
    bg_w.bgw[0].suzi_base_flag = 0;
    memset(bg_w.bgw[0].suzi_adrs, 0, 0x1000);
    bg_w.bgw[0].suzi_c_no2 = simmram_small_page_alloc_40(1);
    bg_w.bgw[0].suzi_adrs2 = (u16*)simmram_slot_addr(bg_w.bgw[0].suzi_c_no2);
    memset(bg_w.bgw[0].suzi_adrs2, 0, 0x1000);
    bg_w.bgw[0].zuubun = 16;
    bg_w.bgw[0].no_suzi_line = 0x200;
    bg_w.bgw[0].u_line = 0x200;
    bg_w.bgw[0].d_line = 96;
    bg_w.bgw[0].start_suzi = bg_w.bgw[0].suzi_adrs + 0x400;
    bg_w.bgw[0].start_suzi2 = bg_w.bgw[0].suzi_adrs2 + 0x400;
    base_y_pos = 40;
    load_char_gfx(0xA500, 1);
    load_char_gfx(0xAB48, 1);
}



void opning_init_02000(void) {
    op_w.free_work--;
    if (op_w.free_work < 0) {
        op_w.r_no_0++;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        wipe_pattern_set(0, 7, 0);
        scfont_page0_fill(0, 32);
    }
    Scrn_Move_Set(0, 512 - bg_w.pos_offset, 512);
    op_plmove_timer = combo_demo_timer_tbl[Get_Demo_Index];
    op_demo_index = 0;
    effect_F5_init(14);
}



void opening_move(void) {
    if (op_w.old_rno != op_w.r_no_1) {
        op_w.r_no_2 = 0;
        op_work_clear();
    }
    op_w.old_rno = op_w.r_no_1;
    switch (op_w.r_no_1) {
    case 0:
        combo_demo_move();
        op_00_move();
        break;
    case 1:
        combo_demo_move();
        op_01_move();
        break;
    case 2:
        combo_demo_move();
        opw_ptr = &op_w.bgw[0];
        op_02_move();
        break;
    case 3:
        op_03_move();
        combo_demo_move();
        break;
    case 4:
        combo_demo_move();
        op_04_move();
        break;
    case 5:
        combo_demo_move();
        op_05_move();
        break;
    case 6:
        op_06_move();
        break;
    case 7:
        opw_ptr = &op_w.bgw[0];
        op_07_move();
        break;
    case 8:
        opw_ptr = &op_w.bgw[0];
        op_08_move();
        break;
    case 9:
        opw_ptr = &op_w.bgw[0];
        op_09_move();
        break;
    case 10:
        opw_ptr = &op_w.bgw[0];
        op_10_move();
        break;
    case 11:
        opw_ptr = &op_w.bgw[0];
        op_11_move();
        break;
    case 12:
        opw_ptr = &op_w.bgw[0];
        op_12_move();
        break;
    case 13:
        opw_ptr = &op_w.bgw[0];
        op_13_move();
        break;
    case 14:
        opw_ptr = &op_w.bgw[0];
        op_14_move();
        break;
    }
}



void op_00_move(void) {
    if (op_w.r_no_2 != 0) {
        op_w.free_work--;
        if (op_w.free_work <= 0) {
            op_w.r_no_1++;
            wipe_pattern_set(0, 7, 0);
            scfont_page0_fill(0, 32);
            bg_cell_write(0, 0x1040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x1080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x2040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x2080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(1, 0x2040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(1, 0x2080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(2, 0x2040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(2, 0x2080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(2, 0x3040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(2, 0x3080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            op_w.r_no_2 = 0;
            return;
        }
    }
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        op_w.index = 0;
        op_w.free_work = op_timer_tbl[0];
        bg_w.bgw[0].wxy[0].cal = 0x2000000;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.bgw[1].wxy[0].cal = 0x2000000;
        bg_w.bgw[1].xy[1].cal = 0;
        bg_w.bgw[2].wxy[0].cal = 0x2000000;
        bg_w.bgw[2].xy[1].cal = 0;
        bg_w.bgw[1].speed_y = 0x20000;
        bg_w.bgw[2].speed_y = 0x10000;
        bg_cell_write(0, 0x3040, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x1040, 30, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x1080, 31, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x2040, 32, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x2080, 33, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x3040, 34, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x3080, 35, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(2, 0x2040, 26, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(2, 0x2080, 27, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(2, 0x3040, 28, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(2, 0x3080, 29, (u32)op_bg0_scrn_data, 0, 0x2C0);
        Bg_Off_R(17);
        Bg_On_W(6);
        break;
    case 1:
    case 2:
    case 3:
        op_w.r_no_2++;
        break;
    case 4:
        op_w.r_no_2++;
        ToneDown(0);
        /* fall through */
    case 5:
        if (op_w.free_work < 0x140) {
            op_w.r_no_2++;
            bg_w.bgw[1].xy[1].cal += bg_w.bgw[1].speed_y;
            bg_w.bgw[2].xy[1].cal += bg_w.bgw[2].speed_y;
        }
        break;
    case 6:
        bg_w.bgw[1].xy[1].cal += bg_w.bgw[1].speed_y;
        bg_w.bgw[2].xy[1].cal += bg_w.bgw[2].speed_y;
        if (op_w.free_work < 0xC6) {
            op_w.r_no_2++;
            op_obj_disp = 1;
            effect_48_init(0);
            Bg_On_W(1);
            Bg_Off_W(14);
        }
        break;
    case 7:
        if (!op_obj_disp) {
            op_w.r_no_2++;
            Bg_Off_W(1);
            Bg_On_W(14);
        }
        break;
    case 8:
        bg_w.bgw[1].xy[1].cal += bg_w.bgw[1].speed_y;
        bg_w.bgw[2].xy[1].cal += bg_w.bgw[2].speed_y;
        if (bg_w.bgw[1].xy[1].disp.pos >= 0x1E0) {
            op_w.r_no_2++;
        }
        break;
    case 9:;
    }
    op_scrn_pos_set2(0);
    op_scrn_pos_set2(1);
    op_scrn_pos_set2(2);
    op_scrn_pos_set2(5);
}



void op_01_move(void) {
    Combo_Demo_Flag = 1;
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        bg_w.bgw[0].wxy[0].cal = 0;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.bgw[1].wxy[0].cal = 0x2000000;
        bg_w.bgw[1].xy[1].cal = 0;
        bg_w.bgw[0].old_pos_x = 0;
        bg_cell_write(0, 0x20C0, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3000, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 36, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 37, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x30C0, 38, (u32)op_bg0_scrn_data, 0, 0x2C0);
        op_w.free_work = op_timer_tbl[1];
        op_scrn_pos_set2(1);
        bg_w.bgw[0].old_pos_x = 0;
        bg_w.bgw[0].suzi_base_flag = 0;
        Bg_On_R(17);
        Bg_Off_W(14);
        scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        suzi_line_clear(0);
        plw[0].wu.disp_flag = 1;
        plw[1].wu.disp_flag = 1;
        break;
    case 1:
    case 2:
    case 3:
        op_w.r_no_2++;
        suzi_line_fix_set2();
        op_w.free_work--;
        if (bg_w.bgw[0].suzi_base_flag) {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        } else {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs2);
        }
        bg_w.bgw[0].suzi_base_flag ^= 1;
        break;
    case 4:
        op_w.r_no_2++;
        ToneDown(0);
        /* fall through */
    case 5:
        suzi_line_fix_set2();
        op_w.free_work--;
        if (op_w.free_work <= 0) {
            op_w.r_no_2++;
            op_plmove_timer = combo_demo_timer_tbl[Get_Demo_Index + 1];
            wipe_pattern_set(0, 7, 0);
            scfont_page0_fill(0, 32);
        }
        if (bg_w.bgw[0].suzi_base_flag) {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        } else {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs2);
        }
        bg_w.bgw[0].suzi_base_flag ^= 1;
        break;
    case 6:
        op_w.r_no_1++;
        op_w.r_no_2 = 0;
        Bg_Off_W(16);
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        ending_effects_cleanup();
        Combo_Demo_Flag = 0x81;
        break;
    }
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    op_scrn_pos_set2(0);
}



void op_02_move(void) {
    s16 time;
    bg_w.bgw[0].xy[1].cal += 0x60000;
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        op_w.index = 0;
        Bg_On_W(1);
        Bg_Off_W(6);
        bg_w.bgw[0].wxy[0].cal = 0x2000000;
        bg_w.bgw[1].xy[1].cal = 0x2000000;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.bgw[1].xy[1].cal = 0;
        bg_cell_write(0, 64, 2, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 128, 3, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x1040, 2, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x1080, 3, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2040, 2, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 3, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 2, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 3, (u32)op_bg0_scrn_data, 0, 0x2C0);
        op_w.free_work = op_timer_tbl[2];
        bg_w.bgw[5].wxy[0].disp.pos = 0x200;
        bg_w.bgw[5].xy[1].disp.pos = 0;
        break;
    case 1:
    case 2:
    case 3:
        opw_ptr->r_no_0++;
        op_w.free_work--;
        break;
    case 4:
        opw_ptr->r_no_0++;
        ToneDown(0);
        /* fall through */
    case 5:
        op_w.free_work--;
        time = op_timer_tbl[2] - 60;
        if (op_w.free_work < time) {
            op_obj_disp = 1;
            effect_48_init(1);
            opw_ptr->r_no_0++;
            Bg_Off_W(15);
        }
        break;
    case 6:
        op_w.free_work--;
        if (!op_obj_disp) {
            opw_ptr->r_no_0++;
            Bg_On_W(15);
        }
        break;
    case 7:
        op_w.free_work--;
        if (op_w.free_work < 0) {
            op_w.r_no_1++;
            wipe_pattern_set(0, 7, 0);
            scfont_page0_fill(0, 32);
        }
        break;
    }
    op_scrn_pos_set2(0);
    op_scrn_pos_set2(5);
}



void op_03_move(void) {
    Combo_Demo_Flag = 1;
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        Bg_Off_W(14);
        Bg_On_R(17);
        bg_w.bgw[0].wxy[0].cal = 0x3000000;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.bgw[1].wxy[0].cal = 0x2000000;
        bg_w.bgw[1].xy[1].cal = 0;
        bg_cell_write(0, 0x2000, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x20C0, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3000, 39, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 40, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 41, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x30C0, 42, (u32)op_bg0_scrn_data, 0, 0x2C0);
        op_w.free_work = op_timer_tbl[3];
        op_scrn_pos_set2(1);
        bg_w.bgw[0].old_pos_x = 0;
        bg_w.bgw[0].suzi_base_flag = 0;
        scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        suzi_line_clear(0);
        break;
    case 1:
    case 2:
    case 3:
        op_w.r_no_2++;
        suzi_line_fix_set2();
        op_w.free_work--;
        if (bg_w.bgw[0].suzi_base_flag) {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        } else {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs2);
        }
        bg_w.bgw[0].suzi_base_flag ^= 1;
        plw[0].wu.disp_flag = 1;
        plw[1].wu.disp_flag = 1;
        break;
    case 4:
        op_w.r_no_2++;
        ToneDown(0);
        /* fall through */
    case 5:
        suzi_line_fix_set2();
        op_w.free_work--;
        if (op_w.free_work <= 0) {
            op_w.r_no_2++;
            op_plmove_timer = combo_demo_timer_tbl[Get_Demo_Index + 1];
            wipe_pattern_set(0, 7, 0);
            scfont_page0_fill(0, 32);
        }
        if (bg_w.bgw[0].suzi_base_flag) {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        } else {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs2);
        }
        bg_w.bgw[0].suzi_base_flag ^= 1;
        break;
    case 6:
        op_w.r_no_1++;
        op_w.r_no_2 = 0;
        Bg_Off_W(16);
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        ending_effects_cleanup();
        Combo_Demo_Flag = 0x81;
        break;
    }
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    op_scrn_pos_set2(0);
}



void op_04_move(void) {
    s16 time;
    bg_w.bgw[0].xy[1].cal += 0x80000;
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        op_w.index = 0;
        op_w.free_work = 0;
        Bg_On_W(1);
        Bg_Off_W(2);
        bg_cell_write(0, 64, 4, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 128, 5, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x1040, 6, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x1080, 7, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2040, 4, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 5, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 6, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 7, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_w.bgw[0].wxy[0].cal = 0x2000000;
        bg_w.bgw[0].xy[1].cal = 0;
        op_w.free_work = op_timer_tbl[4];
        bg_w.bgw[5].wxy[0].disp.pos = 0x200;
        bg_w.bgw[5].xy[1].disp.pos = 0;
        break;
    case 1:
    case 2:
    case 3:
        opw_ptr->r_no_0++;
        op_w.free_work--;
        break;
    case 4:
        opw_ptr->r_no_0++;
        ToneDown(0);
        /* fall through */
    case 5:
        op_w.free_work--;
        time = op_timer_tbl[4] - 44;
        if (op_w.free_work < time) {
            opw_ptr->r_no_0++;
            op_obj_disp = 1;
            effect_48_init(2);
            Bg_Off_W(15);
        }
        break;
    case 6:
        op_w.free_work--;
        if (!op_obj_disp) {
            opw_ptr->r_no_0++;
            Bg_On_W(15);
        }
        break;
    case 7:
        op_w.free_work--;
        if (op_w.free_work < 0) {
            op_w.r_no_1++;
            wipe_pattern_set(0, 7, 0);
            scfont_page0_fill(0, 32);
        }
        break;
    }
    op_scrn_pos_set2(0);
    op_scrn_pos_set2(5);
}



void op_05_move(void) {
    Combo_Demo_Flag = 1;
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        Bg_Off_W(14);
        Bg_On_R(16);
        bg_w.bgw[0].wxy[0].cal = 0x3000000;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.bgw[1].wxy[0].cal = 0x2000000;
        bg_w.bgw[1].xy[1].cal = 0;
        bg_cell_write(0, 0x2000, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x20C0, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3000, 43, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 44, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 45, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x30C0, 46, (u32)op_bg0_scrn_data, 0, 0x2C0);
        op_w.free_work = op_timer_tbl[5];
        op_scrn_pos_set2(1);
        bg_w.bgw[0].old_pos_x = 0;
        bg_w.bgw[0].suzi_base_flag = 0;
        scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        suzi_line_clear(0);
        break;
    case 1:
    case 2:
    case 3:
        op_w.r_no_2++;
        op_w.free_work--;
        if (bg_w.bgw[0].suzi_base_flag) {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        } else {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs2);
        }
        bg_w.bgw[0].suzi_base_flag ^= 1;
        plw[0].wu.disp_flag = 1;
        plw[1].wu.disp_flag = 1;
        break;
    case 4:
        op_w.r_no_2++;
        ToneDown(0);
        /* fall through */
    case 5:
        suzi_line_fix_set2();
        op_w.free_work--;
        if (op_w.free_work <= 0) {
            op_w.r_no_2++;
            wipe_pattern_set(0, 7, 0);
            scfont_page0_fill(0, 32);
        }
        if (bg_w.bgw[0].suzi_base_flag) {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs);
        } else {
            scrn_linescroll_set(0, bg_w.bgw[0].suzi_adrs2);
        }
        bg_w.bgw[0].suzi_base_flag ^= 1;
        break;
    case 6:
        op_w.r_no_1++;
        op_w.r_no_2 = 0;
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        ending_effects_cleanup();
        Bg_Off_W(16);
        Combo_Demo_Flag = 1;
        break;
    }
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    op_scrn_pos_set2(0);
}



void op_06_move(void) {
    s16 i;
    s32 wk;
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        bg_cell_write(0, 64, 10, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 128, 11, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x1040, 10, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x1080, 11, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2040, 10, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 11, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 10, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 11, (u32)op_bg0_scrn_data, 0, 0x2C0);
        Bg_On_W(1);
        Bg_Off_W(14);
        bg_w.bgw[0].wxy[0].cal = 0x2000000;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.bgw[1].wxy[0].cal = 0x2000000;
        bg_w.bgw[1].xy[1].cal = 0;
        bg_w.bgw[5].wxy[0].disp.pos = 0x200;
        bg_w.bgw[5].xy[1].disp.pos = 0;
        op_w.free_work = op_timer_tbl[12];
        op_scrn_pos_set2(0);
        op_scrn_pos_set2(1);
        op_scrn_pos_set2(5);
        break;
    case 1:
    case 2:
        op_w.r_no_2++;
        break;
    case 3:
        op_w.r_no_2++;
        ToneDown(0);
        /* fall through */
    case 4:
        bg_w.bgw[0].xy[1].cal += 0xA0000;
        op_w.free_work--;
        if (op_w.free_work <= 0) {
            Bg_Off_W(1);
            op_w.r_no_2++;
            op_obj_disp = 1;
            op_w.free_work = op_timer_tbl[6];
            effect_48_init(5);
        }
        break;
    case 5:
        bg_w.bgw[0].xy[1].cal += 0xA0000;
        if (!op_obj_disp) {
            op_w.r_no_2++;
            Bg_On_W(1);
        }
        break;
    case 6:
        bg_w.bgw[0].xy[1].cal += 0xA0000;
        op_w.free_work--;
        if (op_w.free_work <= 0) {
            op_w.r_no_2++;
            Bg_Off_W(1);
            op_obj_disp = 1;
            effect_48_init(3);
        }
        break;
    case 7:
        bg_w.bgw[0].xy[1].cal += 0x80000;
        if (!op_obj_disp) {
            op_w.r_no_2++;
            bg_w.bgw[0].wxy[0].cal = 0x2000000;
            bg_w.bgw[0].xy[1].cal = 0x3000000;
            bg_w.bgw[0].speed_y = 0x40000;
            bg_w.bgw[1].speed_y = 0x40000;
            bg_w.bgw[5].speed_y = 0x38000;
            bg_w.bgw[2].speed_y = 0x20000;
            bg_w.bgw[3].speed_y = 0x18000;
            effect_F5_init(15);
            for (i = 1; i < 4; i++) {
                bg_w.bgw[i].wxy[0].cal = 0x2000000;
                wk = 0x4000000 - bg_w.bgw[0].xy[1].cal;
                wk /= bg_w.bgw[0].speed_y;
                wk *= bg_w.bgw[i].speed_y;
                bg_w.bgw[i].xy[1].cal = -wk;
                op_scrn_pos_set2(i);
            }
            bg_w.bgw[5].wxy[0].cal = 0x2000000;
            wk = 0x4000000 - bg_w.bgw[0].xy[1].cal;
            wk /= bg_w.bgw[0].speed_y;
            wk *= bg_w.bgw[5].speed_y;
            bg_w.bgw[5].xy[1].cal = -wk;
            op_scrn_pos_set2(5);
            Bg_On_W(1);
            Bg_Off_W(2);
        }
        op_scrn_pos_set2(0);
        break;
    case 8:
        op_w.r_no_2++;
        bg_cell_write(0, 0x3040, 8, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 9, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x1040, 14, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x1080, 15, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x2040, 16, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x2080, 17, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x3040, 18, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 0x3080, 19, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 64, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(1, 128, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(2, 0x3040, 12, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(2, 0x3080, 13, (u32)op_bg0_scrn_data, 0, 0x2C0);
        Bg_On_W(15);
        /* fall through */
    case 9:
        for (i = 0; i < 4; i++) {
            bg_w.bgw[i].xy[1].cal += bg_w.bgw[i].speed_y;
            op_scrn_pos_set2(i);
        }
        bg_w.bgw[5].xy[1].cal += bg_w.bgw[5].speed_y;
        op_scrn_pos_set2(5);
        if (bg_w.bgw[0].xy[1].disp.pos > 0x380) {
            op_w.r_no_2++;
            bg_cell_write(0, 0x1040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x1080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x2040, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x2080, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        }
        break;
    case 10:
        for (i = 0; i < 4; i++) {
            bg_w.bgw[i].xy[1].cal += bg_w.bgw[i].speed_y;
            op_scrn_pos_set2(i);
        }
        bg_w.bgw[5].xy[1].cal += bg_w.bgw[5].speed_y;
        op_scrn_pos_set2(5);
        if (bg_w.bgw[2].xy[1].disp.pos > 28) {
            op_w.r_no_2++;
            op_w.mv_ctr = 64;
            op_w.free_work = op_timer_tbl[7];
            bg_cell_write(0, 64, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 128, 0, (u32)op_bg0_scrn_data, 0, 0x2C0);
        }
        break;
    case 11:
        op_w.free_work--;
        if (op_w.free_work < 0) {
            op_w.r_no_2++;
            op_w.free_work = op_timer_tbl[8];
            break;
        }
        for (i = 0; i < 4; i++) {
            bg_w.bgw[i].xy[1].cal += bg_w.bgw[i].speed_y;
            op_scrn_pos_set2(i);
        }
        bg_w.bgw[5].xy[1].cal += bg_w.bgw[5].speed_y;
        op_scrn_pos_set2(5);
        break;
    case 12:
        for (i = 0; i < 4; i++) {
            bg_w.bgw[i].xy[1].cal += bg_w.bgw[i].speed_y;
            op_scrn_pos_set2(i);
        }
        bg_w.bgw[5].xy[1].cal += bg_w.bgw[5].speed_y;
        op_scrn_pos_set2(5);
        op_w.free_work--;
        if (op_w.free_work < 0) {
            op_w.r_no_2++;
        }
        break;
    case 13:
        if (Request_Fade(48, 0)) {
            op_w.r_no_2++;
            bg_cell_write(0, 0x3040, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        }
        break;
    case 14:
        if (Check_Fade_Complete()) {
            op_w.r_no_2++;
        }
        break;
    case 22:
        op_w.r_no_1++;
        op_w.r_no_2 = 0;
        Bg_Off_W(14);
        break;
    default:
        op_w.r_no_2++;
        break;
    }
}



void op_07_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        if (Request_Fade(47, 0) == 0) {
            break;
        }
        Bg_On_W(1);
        bg_w.bgw[0].xy[1].cal = 0;
        bg_w.quake_x_index = 0;
        bg_w.quake_y_index = 0;
        opw_ptr->r_no_0++;
        break;
    case 1:
        if (Check_Fade_Complete()) {
            opw_ptr->r_no_0++;
        }
        break;
    case 2:
        opw_ptr->r_no_0++;
        op_w.free_work = 0;
        effect_F5_init(0);
        bg_w.bgw[0].wxy[0].cal = 0x2000000;
        bg_w.bgw[0].xy[1].cal = 0;
        bg_cell_write(0, 0x3040, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
        break;
    case 3:
        if (op_w.free_work) {
            op_w.r_no_1++;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_08_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        op_w.free_work = 0;
        effect_F6_init();
        Sound_SE(122);
        break;
    case 1:
        if (op_w.free_work) {
            op_w.r_no_1++;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_09_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        op_w.free_work = 0;
        effect_F5_init(0);
        effect_F5_init(1);
        effect_F5_init(6);
        effect_F5_init(7);
        break;
    case 1:
        if (op_w.free_work) {
            op_w.r_no_1++;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_10_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        effect_F5_init(10);
        effect_F5_init(11);
        effect_F5_init(12);
        effect_F5_init(13);
        effect_E1_init(0, 1, 0);
        op_w.free_work = op_timer_tbl[9];
        Sound_SE(123);
        break;
    case 1:
        op_w.free_work--;
        if (op_w.free_work < 0) {
            op_w.r_no_1++;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_11_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        effE1_end_flag = 0;
        effect_58_init(6, 50, 0xA1);
        effect_E1_init(1, 30, 0);
        effect_E1_init(2, 30, 0);
        break;
    case 1:
        if (effE1_end_flag) {
            op_w.r_no_1++;
            effE1_end_flag = 0;
            effect_F5_init(19);
            effect_F5_init(20);
            effect_F5_init(21);
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_12_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        if (Request_Fade(40, 0) == 0) {
            break;
        }
        effect_58_init(6, 4, 125);
        opw_ptr->r_no_0++;
        break;
    case 1:
        if (Check_Fade_Complete()) {
            if (Country != 1) {
                effect_F5_init(9);
            }
            op_w.r_no_1++;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_13_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        if (Request_Fade(41, 0) == 0) {
            break;
        }
        opw_ptr->r_no_0++;
        break;
    case 1:
        if (Check_Fade_Complete()) {
            op_w.r_no_1++;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



void op_14_move(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        Disp_Copyright();
        op_w.free_work = op_timer_tbl[11];
        opw_ptr->ctr = op_ctr_set[0].ctr;
        op_w.index = 4;
        break;
    case 1:
        op_w.free_work--;
        if (op_w.free_work < 0) {
            op_end_flag = 1;
            Bg_Off_W(0xFE);
            Combo_Demo_Flag = 0;
        }
        break;
    }
    op_scrn_pos_set2(0);
}



/* provisional name */
void op_bg_off(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        Bg_Off_W(1 << opw_ptr->bg_no);
        break;
    case 1:
        break;
    }
}



void opening_title_00(void) {
    s32 pos;
    Zoomf_Init();
    bg_vbl_trans_flag = 0;
    scr_cg_c_no = simmram_block_alloc_10(0x195, 1);
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    bg_w.scno = 1;
    chr_dma_request(0x01705800, 0, 0, 3);
    chr_dma_request(0x01705880, bg_w.scroll_cg_adr, 0x1948F, 1);
    if (Game_setting.Screen_Mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    bg_w.bgw[0].pos_x_work = bg_w.bgw[0].pos_y_work = 0;
    bg_w.bgw[0].rewrite_flag = 0;
    bg_w.bgw[0].fam_no = 0;
    bg_w.bgw[0].zuubun = 0;
    bg_w.bgw[0].wxy[0].cal = 0x2000000;
    bg_w.bgw[0].xy[1].cal = 0;
    bg_w.bgw[0].wxy[0].cal = 0x2000000;
    bg_w.bgw[0].wxy[1].cal = 0;
    bg_w.bgw[0].hos_xy[0].cal = 0x2000000;
    bg_w.bgw[0].hos_xy[1].cal = 0;
    bg_w.bgw[0].position_x = 0x200 - bg_w.pos_offset;
    bg_w.bgw[0].position_y = 0;
    bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
    bg_w.bgw[0].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
    scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
    sprite_list_setup(0, 1, op_scr_record_data_0);
    load_char_gfx(0xA500, 1);
    load_char_gfx(0xAB48, 1);
    effect_E1_init(1, 24, 1);
    effect_E1_init(0, 24, 1);
    effect_F5_init(16);
    effect_F5_init(17);
    effect_F5_init(18);
    if (Country != 1) {
        effect_F5_init(9);
    }
    Disp_Copyright();
    bg_cell_write(0, 0x3040, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
    bg_cell_write(0, 0x3080, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
    Bg_On_R(1);
    Bg_On_W(1);
    Bg_Off_R(0xFE);
    Bg_Off_W(0xFE);
    scrn_attr_set(0, 0, 31);
    scrn_reg_w[0].ctrl &= 0xFE7F;
    Scrn_Move_Set(0, 0x200 - bg_w.pos_offset, 0);
    Scrn_Move_Set(1, 0x200 - bg_w.pos_offset, 0);
    pos = (s16)-(0x200 - bg_w.pos_offset) & 0x3FF;
    Family_Set_W(1, pos, 0x300);
    op_end_flag = 1;
    Combo_Demo_Flag = 0;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_w.chase_flag = 0;
}



void opening_pl_disp(void) {
    plw[0].wu.position_x = plw[0].wu.xyz[0].disp.pos & 0x3FF;
    plw[1].wu.position_x = plw[1].wu.xyz[0].disp.pos & 0x3FF;
    plw[0].wu.position_y = plw[0].wu.xyz[1].disp.pos & 0x3FF;
    plw[1].wu.position_y = plw[1].wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request(&plw[0].wu);
    sort_push_request(&plw[1].wu);
}



void opening_scrn_map_set(void) {
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
}



void opening_scrn_pos_set(bg_no, ix)
s16 bg_no;
s16 ix;
{
    Scrn_Move_Set(bg_no, op_scrn_pos_tbl[ix].x - bg_w.pos_offset, op_scrn_pos_tbl[ix].y);
}



void op_scrn_pos_set2(bg_no)
s16 bg_no;
{
    s16 pos_x = bg_w.bgw[bg_no].wxy[0].disp.pos & 0x3FF;
    s16 pos_y = bg_w.bgw[bg_no].xy[1].disp.pos & 0x3FF;
    Scrn_Move_Set(bg_no, pos_x - bg_w.pos_offset, pos_y);
}



void Bg_Family_Set_op(void) {
    s32 pos_work_x;
    s32 pos_work_y;
    s16 i;
    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].xy[0].cal = bg_w.bgw[i].wxy[0].cal;
        bg_w.bgw[i].position_y = bg_w.bgw[i].xy[1].disp.pos & 0x3FF;
        bg_w.bgw[i].position_x = bg_w.bgw[i].wxy[0].disp.pos - bg_w.pos_offset;
        bg_w.bgw[i].position_x &= 0x3FF;
        pos_work_x = (s16)-bg_w.bgw[i].position_x & 0x3FF;
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_y = (768 - (pos_work_y & 0x3FF)) & 0x3FF;
        Family_Set_W(i + 1, pos_work_x, pos_work_y);
    }
    bg_w.bgw[5].position_y = bg_w.bgw[5].xy[1].disp.pos & 0x3FF;
    bg_w.bgw[5].position_x = bg_w.bgw[5].wxy[0].disp.pos - bg_w.pos_offset;
    bg_w.bgw[5].position_x &= 0x3FF;
    pos_work_x = (s16)-bg_w.bgw[5].position_x & 0x3FF;
    pos_work_y = bg_w.bgw[5].position_y;
    pos_work_y = (768 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(6, pos_work_x, pos_work_y);
}



void combo_demo_move(void) {
    op_plmove_timer--;
    if (op_plmove_timer == 0) {
        combo_demo_load(op_demo_index);
        op_demo_index++;
        if (op_demo_index >= 3) {
            op_demo_index = 0;
        }
        return;
    }
    if (op_plmove_timer < 0) {
        Player_control();
    }
}



void combo_demo_load(s16 n) {
    switch (n) {
    case 0:
        Combo_Demo_Init();
        load_char_eff_color(My_char[0], 0);
        load_char_eff_color(My_char[1], 1);
        break;
    case 1:
    case 2:
        Get_Demo_Index++;
        Combo_Demo_Init();
        load_char_eff_color(My_char[0], 0);
        load_char_eff_color(My_char[1], 1);
        break;
    case 8:
        load_char_eff_color(My_char[0], 0);
        break;
    case 9:
        load_char_eff_color(My_char[1], 1);
        break;
    }
}



void combo_demo_set_position(s16 id) {
    plw[id].wu.xyz[0].cal = combo_demo_pos_tbl[Get_Demo_Index][id];
    plw[id].wu.xyz[1].cal = 0;
}



/* provisional name */
void ending_effects_cleanup(void) {
    effect_work_kill(2, -1);
    effect_work_kill(0, 0);
    effect_work_kill(1, 1);
    effect_work_kill(3, 3);
    effect_work_kill(3, 0x91);
    effect_work_kill(3, 0x93);
    effect_work_kill(3, 0x94);
    effect_work_kill(3, 0xA5);
    effect_work_kill(3, 0xA6);
    effect_work_kill(3, 0xA9);
    effect_work_kill(3, 0xB4);
}
