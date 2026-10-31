/*
 * END_MAIN_C.C  Ending main control and the helpers the endings share
 *
 * Ending_main runs one of three ending scripts each frame: gill_ending for character 15, gouki_ending when
 * End_Gouki_Flag is set, normal_ending otherwise. Each clears the system, lets the character's ending script
 * (end_main_jp[]) set up and run its scenes, shows the continue-screen cards, handles the cut button, runs the
 * staff roll and finally the winner's name. The shared helpers used by the end_N modules follow:
 * common_end_init00/01 (scroll graphics allocation and BG work setup), plane position and family updates, block
 * attribute writes, the BGM fade and fade-complete checks, the cut button test and the ending BG dispatcher.
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
#include "SYS_sub.h"
#include "bg000.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "fifo.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "effe9.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "sc_trans.h"
#include "end_staff.h"
#include "end_main_c.h"

/* end_w.r_no_0 in normal_ending */
#define END_INIT        0       /* clear the system and start the character's ending */
#define END_COVER       1       /* after Cover_Timer, set up the screen and wipe in */
#define END_REVIVAL     2       /* finish the wipe */
#define END_PLAY        3       /* the ending, until it ends or is cut */
#define END_TO_STAFF    4       /* fade out to the staff roll */
#define END_STAFF_SETUP 5       /* after the fade, set up the staff roll screen */
#define END_FADE_IN     6       /* fade the staff roll in */
#define END_FADE_WAIT   7       /* until the fade is done */
#define END_STAFF       8       /* the staff roll */
#define END_FADE_OUT    9       /* fade out */
#define END_MUSIC       10      /* after the fade, fade the music (longer when the name entry was cut short) */
#define END_WAIT        11      /* wait end_w.timer, then finished */

/* end_w.r_no_0 in gouki_ending */
#define GOU_INIT        0       /* clear the system and start the ending */
#define GOU_COVER       1       /* after Cover_Timer, set up the screen and wipe in */
#define GOU_REVIVAL     2       /* finish the wipe */
#define GOU_PLAY        3       /* the ending, until it ends or is cut */
#define GOU_WIPE        4       /* save the screen and wipe */
#define GOU_SETUP       5       /* after the wipe, set up the staff roll screen */
#define GOU_COVER2      6       /* after Cover_Timer, wipe in */
#define GOU_REVIVAL2    7       /* finish the wipe */
#define GOU_STAFF       8       /* the staff roll */
#define GOU_MUSIC       9       /* fade the music */
#define GOU_WAIT        10      /* wait end_w.timer, then finished */

/* end_w.r_no_0 in gill_ending */
#define GILL_INIT       0       /* clear the system and set up the ending */
#define GILL_COVER      1       /* after Cover_Timer, wipe in */
#define GILL_REVIVAL    2       /* finish the wipe */
#define GILL_STAFF      3       /* the staff roll */
#define GILL_MUSIC      4       /* fade the music */
#define GILL_WAIT       5       /* wait end_w.timer, then finished */



extern s32 staff_r_no;
void Redisp_Continue_Count();
void bg_end_initialize(void);     /* bg_initialize's twin in bg000 that only the endings call */
void scrn_attr_set(u16 n, u16 attr, u16 bits);
void scrn_map_set(u16 n, u32 p);
void scrn_map_set_now(u16 n, u32 p);
extern s8 End_Gouki_Flag;
extern s8 end_scroll_dir;
extern const s8 end_type_tbl[16];
extern void end_BG000();
extern void end_BG010();
extern void end_BG020();
extern void end_BG030();
extern void end_BG040();
extern void end_BG050();
extern void end_BG060();
extern void end_BG070();
extern void end_BG080();
extern void end_BG090();
extern void end_BG100();
extern void end_BG110();
extern void end_BG120();
extern void end_BG130();
extern void end_BG140();
extern void end_BG150();



void Ending_init(void) {
    end_w.r_no_0 = END_INIT;
    end_w.r_no_1 = END1_INIT;
    end_w.r_no_2 = 0;
    end_w.type = 0;
    end_w.end_flag = 0;
    Game_timer = 0;
    ending_all_end = 0;
    end_fade_timer = 0;
    end_fade_flag = 0;
    end_no_cut = 0;
    staff_r_no = 0;
    end_staff_flag = 0;
    end_obj_sync = 0;
}



s32 Ending_main(s16 pl_num) {
    Game_timer++;
    if (pl_num == 15) {
        gill_ending(pl_num);
    } else if (End_Gouki_Flag) {
        gouki_ending(pl_num);
    } else {
        normal_ending(pl_num);
    }
    return ending_all_end;
}



void gill_ending(pl_num)
s16 pl_num;
{
    switch (end_w.r_no_0) {
    case GILL_INIT:
        end_w.r_no_0++;
        System_all_clear_Wait();
        bg_work_clear();
        bg_w.stage = 0;
        bg_w.area = 1;
        bg_end_initialize();
        Bg_Off_W(15);
        load_any_color(0x8D);
        load_any_color_fade(0x90, 15, 15, 15);
        load_any_color(0x8E);
        load_any_color_fade(0xB4, 0, 0, 0);
        bg_w.bgw[3].wxy[0].cal = bg_w.bgw[3].xy[0].cal = 0x2000000;
        bg_w.bgw[3].xy[1].cal = 0;
        bg_w.bgw[3].position_x = 512 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        end_fam_set(3);
        load_char_gfx(0xAC48, 1);
        Cover_Timer = 79;
        card_win_check(1);
        load_any_color(0x93);
        load_any_color(0x94);
        load_char_gfx(0x9C10, 1);
        load_char_gfx(0xAEC8, 1);
        effect_E9_init();
        effect_I6_init();
        gill_pos_limit();
        effect_I5_init();
        break;
    case GILL_COVER:
        if (--Cover_Timer) {
            break;
        }
        end_w.r_no_0++;
        Bg_On_W(3);
        end_bg_move();
        if (Gill_Pos_X > 0x200) {
            end_scroll_dir = 0;
            bg_w.bgw[1].wxy[0].disp.pos = bg_w.bgw[1].l_limit2;
        } else {
            end_scroll_dir = 1;
            bg_w.bgw[1].wxy[0].disp.pos = bg_w.bgw[1].r_limit2;
        }
        bg_w.bgw[1].xy[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
        bg_w.bgw[1].wxy[0].disp.low = bg_w.bgw[1].xy[0].disp.low = 0;
        tilemap_fill_all(0, 32);
        Redisp_Continue_Count(0);
        Redisp_Continue_Count(1);
        Switch_Screen_Init(0, 1);
        card_msg_disp();
        end_bg_move();
        break;
    case GILL_REVIVAL:
        if (Switch_Screen_Revival()) {
            end_w.r_no_0++;
            Ignore_Entry[LOSER] = 0;
            Forbid_Break = -1;
        }
        break;
    case GILL_STAFF:
        if (DEBUG_DISP) {
            tilemap_clear_rect(Game_setting.Screen_Mode * 7 + 5, 9, Game_setting.Screen_Mode * 7 + 42, 11);
        }
        end_staff_main();
        end_bg_move();
        card_msg_disp();
        if (end_w.end_flag != 0) {
            end_w.r_no_0++;
            end_no_cut = 1;
        }
        break;
    case GILL_MUSIC:
        end_w.r_no_0++;
        end_no_cut = 0;
        end_w.timer = 360;
        bgm_fade_out(91);
        if (name_wk[WINNER].timer > 0) {
            name_wk[WINNER].timer = 0;
            end_name_cut[WINNER] = 1;
        }
        break;
    case GILL_WAIT:
        end_w.timer--;
        if (end_w.timer < 0) {
            ending_all_end = 1;
            tilemap_clear_rect(Game_setting.Screen_Mode * 7 + 5, 9, Game_setting.Screen_Mode * 7 + 42, 11);
            Forbid_Break = 0;
        }
        break;
    }
}



void gill_pos_limit(void) {
    s16 l = 0x108;
    s16 r = 0x2F6;
    if (Gill_Pos_X < l) {
        Gill_Pos_X = l;
    }
    if (Gill_Pos_X > r) {
        Gill_Pos_X = r;
    }
}



#pragma inline(end_main_move)
void normal_ending(pl_num)
s16 pl_num;
{
    switch (end_w.r_no_0) {
    case END_INIT:
        end_w.r_no_0++;
        System_all_clear_Wait();
        load_any_color(0x8D);
        load_any_color(0x94);
        Cover_Timer = 29;
        end_main_jp[pl_num](pl_num);
        card_win_check(1);
        break;
    case END_COVER:
        if (--Cover_Timer) {
            break;
        }
        end_w.r_no_0++;
        end_color_load();
        tilemap_fill_all(0, 32);
        Redisp_Continue_Count(0);
        Redisp_Continue_Count(1);
        Switch_Screen_Init(0, 1);
        end_main_jp[pl_num](pl_num);
        card_msg_disp();
        load_any_color(0x93);
        load_char_gfx(0x9C10, 1);
        load_char_gfx(0xAEC8, 1);
        break;
    case END_REVIVAL:
        if (Switch_Screen_Revival()) {
            end_w.r_no_0++;
            Ignore_Entry[LOSER] = 0;
            Forbid_Break = -1;
        }
        break;
    case END_PLAY:
        end_main_move(pl_num);
        card_msg_disp();
        if (end_w.end_flag) {
            end_w.r_no_0++;
            end_no_cut = 1;
            Rewrite_End_Message(0);
        } else if (Cut_Cut_Cut_t()) {
            end_w.timer = 0;
            Rewrite_End_Message(0);
            end_main_move(pl_num);
            end_fade_flag = 0;
        }
        break;
    case END_TO_STAFF:
        if (end_no_cut == 0) {
            fadeout_to_staff_roll();
            end_w.r_no_0++;
        } else {
            end_w.r_no_0++;
        }
        break;
    case END_STAFF_SETUP:
        if (end_fade_complete()) {
            end_w.r_no_0++;
            end_w.r_no_2++;
            if (end_w.type == 12) {
                Bg_Off_W(1);
            }
            end_no_cut = 1;
        }
        break;
    case END_FADE_IN:
        end_w.r_no_0++;
        switch (end_type_tbl[end_w.type]) {
        case 0:
            Request_Fade(55, 0);
            break;
        case 1:
            Request_Fade(57, 0);
            break;
        case 2:
            Request_Fade(68, 0);
            break;
        }
        end_no_cut = 1;
        Forbid_Break = -1;
        break;
    case END_FADE_WAIT:
        if (end_fade_complete()) {
            end_w.r_no_0++;
            end_no_cut = 0;
        }
        break;
    case END_STAFF:
        Forbid_Break = 0;
        if (staff_credits(end_staff_flag)) {
            end_w.r_no_0++;
        }
        break;
    case END_FADE_OUT:
        switch (end_type_tbl[end_w.type]) {
        case 0:
            Request_Fade(60, 0);
            break;
        case 1:
            Request_Fade(59, 0);
            break;
        case 2:
            Request_Fade(67, 0);
            break;
        }
        end_w.r_no_0++;
        end_no_cut = 1;
        break;
    case END_MUSIC:
        if (end_fade_complete()) {
            end_w.r_no_0++;
            end_no_cut = 0;
            if (name_wk[WINNER].timer > 0) {
                name_wk[WINNER].timer = 0;
                end_name_cut[WINNER] = 1;
                end_w.timer = 180;
                bgm_fade_out(0xB6);
            } else {
                end_w.timer = 60;
                bgm_fade_out(0x222);
            }
        }
        break;
    case END_WAIT:
        end_w.timer--;
        if (end_w.timer < 0) {
            ending_all_end = 1;
        }
        Forbid_Break = 0;
        break;
    }
}



void gouki_ending(pl_num)
s16 pl_num;
{
    switch (end_w.r_no_0) {
    case GOU_INIT:
        end_w.r_no_0++;
        System_all_clear_Wait();
        load_any_color(0x8D);
        load_any_color(0x94);
        Cover_Timer = 29;
        end_main_jp[pl_num](pl_num);
        card_win_check(1);
        break;
    case GOU_COVER:
        if (--Cover_Timer) {
            break;
        }
        end_w.r_no_0++;
        end_color_load();
        tilemap_fill_all(0, 32);
        Redisp_Continue_Count(0);
        Redisp_Continue_Count(1);
        Switch_Screen_Init(0, 1);
        end_main_jp[pl_num](pl_num);
        card_msg_disp();
        load_any_color(0x93);
        load_char_gfx(0x9C10, 1);
        load_char_gfx(0xAEC8, 1);
        break;
    case GOU_REVIVAL:
        if (Switch_Screen_Revival()) {
            end_w.r_no_0++;
            Ignore_Entry[LOSER] = 0;
            Forbid_Break = -1;
        }
        break;
    case GOU_PLAY:
        end_main_move(pl_num);
        card_msg_disp();
        if (end_w.end_flag) {
            end_w.r_no_0++;
            end_no_cut = 1;
            Rewrite_End_Message(0);
        } else if (Cut_Cut_Cut_t()) {
            end_w.timer = 0;
            Rewrite_End_Message(0);
            end_main_move(pl_num);
            end_fade_flag = 0;
        }
        break;
    case GOU_WIPE:
        end_w.r_no_0++;
        end_no_cut = 1;
        sc_vram_to_ram();
        Switch_Screen_Init(3, 3);
        break;
    case GOU_SETUP:
        if (Switch_Screen()) {
            end_w.r_no_0++;
            Cover_Timer = 24;
            if (end_w.type == 12) {
                Bg_Off_W(1);
            }
            System_all_clear_Wait();
            Fade_Flag = 0;
            Fade_Mode = 0;
            bg_work_clear();
            bg_end_initialize();
            load_any_color(0x8E);
            load_char_gfx(0xAC48, 1);
            load_any_color(0x93);
            load_any_color(0x94);
            load_char_gfx(0x9C10, 1);
            load_char_gfx(0xAEC8, 1);
            effect_E9_init();
            effect_I6_init();
            end_obj_sync = 0;
            effect_J1_init();
            end_bg_move();
            bg_w.bgw[3].wxy[0].cal = bg_w.bgw[3].xy[0].cal = 0x2000000;
            bg_w.bgw[3].xy[1].cal = 0;
            bg_w.bgw[3].position_x = 512 - bg_w.pos_offset;
            bg_w.bgw[3].position_y = 0;
            end_fam_set(3);
        }
        break;
    case GOU_COVER2:
        Cover_Timer--;
        if (Cover_Timer < 0) {
            end_w.r_no_0++;
            Switch_Screen_Init(3, 3);
        }
        break;
    case GOU_REVIVAL2:
        if (Switch_Screen_Revival()) {
            end_w.r_no_0++;
            Forbid_Break = 0;
            end_no_cut = 0;
        }
        break;
    case GOU_STAFF:
        if (staff_credits(end_staff_flag)) {
            end_w.r_no_0++;
        }
        break;
    case GOU_MUSIC:
        end_w.r_no_0++;
        end_obj_sync = 1;
        Forbid_Break = 0;
        end_no_cut = 0;
        end_w.timer = 360;
        bgm_fade_out(91);
        if (name_wk[WINNER].timer > 0) {
            name_wk[WINNER].timer = 0;
            end_name_cut[WINNER] = 1;
        }
        break;
    case GOU_WAIT:
        end_w.timer--;
        if (end_w.timer < 0) {
            ending_all_end = 1;
        }
        Forbid_Break = 0;
        break;
    }
}



void end_main_move(s16 pl_num) {
    end_main_jp[pl_num](pl_num);
    end_fade_bgm();
}



void end_00000(void) {
    end_w.end_flag = 1;
    ending_all_end = 1;
}



/* provisional name */
void end_color_load(void) {
    switch (end_type_tbl[end_w.type]) {
    case 0:
        load_any_color(0x85);
        break;
    case 1:
        load_any_color(0x92);
        break;
    case 2:
        load_any_color(0x84);
        break;
    }
}



void fadeout_to_staff_roll(void) {
    switch (end_type_tbl[end_w.type]) {
    case 0:
        Request_Fade(56, 0);
        break;
    case 1:
        Request_Fade(58, 0);
        break;
    case 2:
        Request_Fade(66, 0);
        break;
    }
    end_no_cut = 1;
    Forbid_Break = -1;
}



void common_end_init00(s16 pl_num) {
    s16 i;
    s32 n;
    u32 blocks;
    const END_BG_GFX* gfx;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    end_cont_coin = Continue_Coin[WINNER];
    end_w.type = pl_num;
    bg_w.bg_index = end_bg_index_tbl[end_w.type];
    bg_w.scno = end_use_scr[end_w.type];
    n = ((end_bg_gfx_tbl[bg_w.bg_index].size << 4) + 0xFFF) / 0x1000;
    blocks = n;
    scr_cg_c_no = simmram_block_alloc_10(blocks, 1);
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    gfx = &end_bg_gfx_tbl[bg_w.bg_index];
    chr_dma_request(gfx->prep, 0, 0, 3);
    chr_dma_request(gfx->src, bg_w.scroll_cg_adr, gfx->size, 1);
    if (Game_setting.Screen_Mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    base_y_pos = 40;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].r_no_0 = 0;
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].xy[0].cal = 0;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].rewrite_flag = 0;
    }
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = (u16 *)simmram_slot_addr(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, (u32)bg_w.bgw[i].bg_address);
        scrn_map_set(i, (u32)bg_w.bgw[i].bg_address);
        sprite_list_setup(i, 1, end_map_tbl[i]);
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].fam_no = i;
    }
}



void common_end_init01(void) {
    s16 i;
    for (i = 0; i < bg_w.scno; i++) {
        scrn_attr_set(i, 0, 31);
        scrn_reg_w[i].ctrl &= 0xFE7F;
    }
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_w.bg_f_x = 9;
    bg_w.old_bg_f_x = 9;
    bg_w.bg_f_y = 9;
    bg_w.old_bg_f_y = 9;
    bg_w.dmm1 = 1;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    bg_sp_work = 0;
    bg_land_flag = 0;
    bg_etc_flag = 0;
    bg_stop2 = 0;
    bg_w.max_x = 6;
    bg_w.old_chase_flag = bg_w.chase_flag = 0;
    bg_zoom_x_pos = 0xC0;
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    bg_ofs_work[0] = bg_ofs_work[1] = bg_ofs_work[2] = 0;
    end_etc_flag = 0;
    end_reset_etc();
    bg_w.bgw[3].wxy[0].cal = bg_w.bgw[3].xy[0].cal = 0x2000000;
    bg_w.bgw[3].xy[1].cal = 0;
    bg_w.bgw[3].position_x = 512 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    end_fam_set(3);
    effect_E9_init();
    load_any_color(0x8E);
    load_char_gfx(0xAC48, 1);
    effect_F9_init(end_w.type);
}



void end_fam_set(s16 i) {
    BGW* bgw = &bg_w.bgw[i];
    s32 x, y, m;
    x = bgw->position_x;
    y = bgw->position_y;
    x = -x;
    m = 0x3FF;
    x &= m;
    y &= m;
    y = (0x300 - y) & m;
    Family_Set_R(i + 1, x, y);
}



void end_fam_set2(void) {
    s16 i;
    s32 pos_work_x;
    s32 pos_work_y;
    for (i = 0; i < bg_w.scno; i++) {
        pos_work_x = bg_w.bgw[i].position_x;
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_x = -pos_work_x & 0x3FF;
        pos_work_y = (0x300 - (pos_work_y & 0x3FF)) & 0x3FF;
        Family_Set_R(i + 1, pos_work_x, pos_work_y);
    }
}



void end_bg_pos_hosei(s16 bg_no) {
    s16 pos_work = bg_w.bgw[bg_no].abs_x & 0x3FF;
    pos_work -= bg_w.pos_offset;
    bg_w.bgw[bg_no].position_x = pos_work & 0x3FF;
    pos_work = bg_w.bgw[bg_no].abs_y & 0x3FF;
    bg_w.bgw[bg_no].position_y = pos_work;
}



void end_bg_pos_hosei2(void) {
    s16 bg_no;
    u16 pos_work;
    for (bg_no = 0; bg_no < bg_w.scno; bg_no++) {
        pos_work = bg_w.bgw[bg_no].abs_x & 0x3FF;
        pos_work -= bg_w.pos_offset;
        bg_w.bgw[bg_no].position_x = pos_work & 0x3FF;
        pos_work = bg_w.bgw[bg_no].abs_y & 0x3FF;
        bg_w.bgw[bg_no].position_y = pos_work;
    }
}



/* provisional name */
void end_scn_pos_set(u16 bg_no) {
    Scrn_Move_Set_R(bg_w.bgw[bg_no].fam_no, (bg_w.bgw[bg_no].xy[0].disp.pos & 0x3FF) - bg_w.pos_offset,
                    bg_w.bgw[bg_no].xy[1].disp.pos);
    bg_w.bgw[bg_no].wxy[0].cal = bg_w.bgw[bg_no].xy[0].cal;
}



void end_scn_pos_set2(void) {
    s16 bg_no;
    for (bg_no = 0; bg_no < bg_w.scno; bg_no++) {
        Scrn_Move_Set_R(bg_w.bgw[bg_no].fam_no,
                        (bg_w.bgw[bg_no].xy[0].disp.pos & 0x3FF) - bg_w.pos_offset,
                        bg_w.bgw[bg_no].xy[1].disp.pos);
        bg_w.bgw[bg_no].wxy[0].cal = bg_w.bgw[bg_no].xy[0].cal;
    }
}


/* provisional name */
void end_bg_block_attr_add(s16 bg, s32 ofs, s16 w, s32 cell, s16 h) {
    u16* adrs;
    adrs = bg_w.bgw[bg].bg_address;
    oh_opening_demo(adrs, ofs, w, cell, h, 0x220, bg_w.bgw[bg].r_limit);
}



void end_reset_etc(void) {
    s16 i;
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].abs_x = bg_w.bgw[i].xy[0].disp.pos = 0x200;
        bg_w.bgw[i].abs_y = bg_w.bgw[i].xy[1].disp.pos = 0;
    }
}



void end_X_com01(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_Off_W(1 << bgw_ptr->fam_no);
        break;
    case 1:
        break;
    }
}



void end_fade_bgm(void) {
    if (end_fade_flag != 0) {
        end_fade_timer--;
        if (end_fade_timer < 0) {
            end_fade_flag = 0;
            bgm_fade_out(0x111);
        }
    }
}



s16 end_fade_complete(void) {
    if (Check_Fade_Complete()) {
        Forbid_Break = -1;
        Text_Page_Y = 32;
        commit_name_entry_row_both_players(32);
        return 1;
    }
    return 0;
}



s32 Cut_Cut_Cut_t(void) {
    u16 sw_w;
    if (end_no_cut == 0) {
        if (WINNER) {
            sw_w = p2sw_0 & ~p2sw_1;
        } else {
            sw_w = p1sw_0 & ~p1sw_1;
        }
        if (sw_w & 0x7F0) {
            return 1;
        }
    }
    return 0;
}


/* provisional name */
void Cut_Cut_Cut_dummy(void) {}



void end_bg_move(void) {
    void (*end_bg_jp[17])() = {
        end_BG000, end_BG010, end_BG020, end_BG030, end_BG040, end_BG050, end_BG060, end_BG070,
        end_BG080, end_BG090, end_BG100, end_BG110, end_BG120, end_BG130, end_BG140, end_BG150,
        end_BG150
    };
    bg_w.bg2_sp_x = bg_w.bgw[1].wxy[0].disp.pos - bg_w.bgw[1].pos_x_work;
    bg_w.bg2_sp_x2 = bg_w.bgw[1].wxy[0].disp.pos - bg_w.bgw[1].pos_x_work;
    end_bg_jp[bg_w.bg_index]();
}
