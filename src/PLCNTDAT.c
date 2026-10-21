/*
 * PLCNTDAT.C  Player base data, stun and super-art setup, round resets
 *
 * setup_base_and_other_data sets both players' base data (set_base_data), super-art and stun work
 * pointers and other data, and creates their E5 effects; setup_any_data reloads them with
 * set_base_data_tiny. set_player_shadow sets the shadow. set_kizetsu_status loads a character's stun
 * limit and recovery; clear_kizetsu_point and clear_super_arts_point reset the stun and super-art
 * values. reset_piyori_and_fight, reset_fight_status, reset_round_and_screen and erase_extra_plef_work
 * reset the round. check_combo_end is used by the combo counter (cmb_cont). debug_player_change
 * (nothing calls it) steps a player's character, super art or colour from the debug
 * switches and resets the fight.
 * The debug character step wraps at 16.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "VITAL.h"
#include "count.h"
#include "spgauge.h"
#include "EFF02.h"
#include "EFF00.h"
#include "EFFK5.h"
#include "effM5.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "EFFE5.h"
#include "EFFJ7.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "CHARID.h"
#include "plcntdat_2.h"
#include "PLCNTDAT.h"
#include "fighter.h"




/* provisional name */
s32 debug_player_change(void) {
    s16 chg = 0;
    if (exsw_1 & 0x80) {
        if (plw[0].cp->sw_now & 0x10) {
            chg = 1;
            My_char[0] = (My_char[0] + 1) & 15;
        }
        if (plw[0].cp->sw_now & 0x20) {
            chg = 2;
            Super_Arts[0]++;
            if (Super_Arts[0] > 2) {
                Super_Arts[0] = 0;
            }
        }
        if (plw[0].cp->sw_now & 0x40) {
            chg = 1;
            Player_Color[0]++;
            if (Player_Color[0] > 6) {
                Player_Color[0] = 0;
            }
        }
        if (plw[1].cp->sw_now & 0x10) {
            chg = 1;
            My_char[1] = (My_char[1] + 1) & 15;
        }
        if (plw[1].cp->sw_now & 0x20) {
            chg = 2;
            Super_Arts[1]++;
            if (Super_Arts[1] > 2) {
                Super_Arts[1] = 0;
            }
        }
        if (plw[1].cp->sw_now & 0x40) {
            chg = 1;
            Player_Color[1]++;
            if (Player_Color[1] > 6) {
                Player_Color[1] = 0;
            }
        }
    }
    if (chg) {
        if (chg == 1) {
            set_kizetsu_status(0);
            set_kizetsu_status(1);
        }
        reset_fight_status();
        erase_extra_plef_work();
    }
    return chg;
}



/* provisional name */
void reset_piyori_and_fight(void)
{
  set_kizetsu_status(0);
  set_kizetsu_status(1);
  reset_fight_status();
  return;
}



/* provisional name */
void reset_fight_status(void) {
    s16 rno = 0;
    appear_type = pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = rno;
    count_cont_reset();
    set_super_arts_status(0);
    set_super_arts_status(1);
    Sa_frame_Clear();
    spgauge_cont_init();
}



/* provisional name */
void reset_round_and_screen(void) {
    System_all_clear_Wait();
    scfont_page0_fill(0, 32);
    load_any_color(2);
    count_cont_reset();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    appear_type = 0;
    G_No2 = 0;
    Round_num = 0;
}



/* provisional name */
void erase_extra_plef_work(void) {
    effect_work_list_release(0, 0);
    effect_work_list_release(1, 1);
    effect_work_list_release(3, 0x91);
    effect_work_list_release(4, 0x81);
    effect_work_list_release(4, 0x25);
    effect_work_list_release(4, 0xAC);
}



void setup_base_and_other_data(void) {
    set_base_data(&plw[0], 0);
    set_base_data(&plw[1], 1);
    plw[0].sa = &super_arts[0];
    plw[1].sa = &super_arts[1];
    plw[0].py = &piyori_type[0];
    plw[1].py = &piyori_type[1];
    setup_other_data(&plw[0]);
    setup_other_data(&plw[1]);
    effect_E5_init(&plw[0]);
    effect_E5_init(&plw[1]);
    if (plw[0].wu.my_priority == plw[1].wu.my_priority) {
        plw[0].the_same_players = plw[1].the_same_players = 1;
    }
}



void setup_any_data(void) {
    set_base_data_tiny(&plw[0]);
    set_base_data_tiny(&plw[1]);
    setup_other_data(&plw[0]);
    setup_other_data(&plw[1]);
    effect_E5_init(&plw[0]);
    effect_E5_init(&plw[1]);
    if (plw[0].wu.my_priority == plw[1].wu.my_priority) {
        plw[0].the_same_players = plw[1].the_same_players = 1;
    }
}



void set_base_data(PLW* wk, s16 ix) {
    wk->wu.be_flag = 1;
    wk->wu.disp_flag = 0;
    wk->wu.blink_timing = ix;
    wk->wu.id = ix;
    wk->wu.work_id = 1;
    wk->wu.operator = Operator_Status[ix];
    wk->wu.charset_id = plid_data[My_char[ix]];
    wk->wkey_flag = wk->dead_flag = 0;
    set_char_base_data(&wk->wu);
    wk->wu.target_adrs = (u32*)&plw[(ix + 1) & 1];
    wk->player_number = My_char[ix];
    cmd_init(wk);
    wk->cb = &combo_type[ix];
    wk->rp = &remake_power[ix];
    if (ix) {
        wk->wu.my_col_code |= 0x10;
    }
    wk->spmv_ng_flag = spmv_ng_table[wk->player_number];
    wk->wu.weight_level = weight_lv_table[wk->player_number];
    set_player_shadow(wk);
}




void set_base_data_tiny(PLW* wk) {
    wk->wu.be_flag = 1;
    wk->wu.disp_flag = 0;
    wk->wkey_flag = wk->dead_flag = 0;
    cmd_init(wk);
    set_player_shadow(wk);
}



void set_player_shadow(PLW* wk) {
    wk->wu.kage_flag = 1;
    wk->wu.kage_prio = 68;
    wk->wu.kage_hx = kage_base[wk->player_number][0];
    wk->wu.kage_char = kage_base[wk->player_number][1];
}



void setup_other_data(PLW* wk) {
    load_player_color(wk->player_number, wk->wu.id, Player_Color[wk->wu.id]);
    effect_01_init((WORK*)wk, 0);
    effect_01_init((WORK*)wk, 1);
    effect_01_init((WORK*)wk, 2);
    effect_01_init((WORK*)wk, 3);
}



/* provisional name */
void set_kizetsu_status(ix)
s16 ix;
{
    s16 plnum = My_char[ix];
    piyori_type[ix].flag = 0;
    piyori_type[ix].time = 0;
    piyori_type[ix].now.timer = 0;
    piyori_type[ix].store = 0;
    piyori_type[ix].genkai = pl_piyo_tbl[plnum];
    piyori_type[ix].recover = pl_nr_piyo_tbl[plnum];
}



void clear_kizetsu_point(PLW* wk) {
    wk->py->flag = 0;
    wk->py->time = 0;
    wk->py->now.timer = 0;
    wk->py->store = 0;
    wk->py->recover = pl_nr_piyo_tbl[wk->player_number];
}

void set_super_arts_status(s16 pl)
{
    u8 *data;

    data = super_arts_data[My_char[pl]][Super_Arts[pl]];
    super_arts[pl].kind_of_arts = Super_Arts[pl];
    super_arts[pl].nmsa_g_ix = data[0];
    super_arts[pl].exsa_g_ix = data[1];
    super_arts[pl].nmsa_a_ix = data[2];
    super_arts[pl].exsa_a_ix = data[3];
    super_arts[pl].gauge_type = data[5];
    super_arts[pl].gauge_len = *(s16 *)&data[6];
    super_arts[pl].store_max = *(s16 *)&data[8];
    super_arts[pl].dtm = *(s32 *)&data[12];
    super_arts[pl].store = 0;
    super_arts[pl].gauge.s.h = 0;
    super_arts[pl].gauge.s.l = -1;
    super_arts[pl].sa_rno = 0;
    super_arts[pl].ok = 0;
}



void clear_super_arts_point(PLW* wk) {
    wk->sa->gauge.s.h = 0;
    wk->sa->gauge.s.l = -1;
    wk->sa->mp_rno = 0;
    wk->sa->sa_rno = 0;
    wk->sa->ex_rno = 0;
    wk->sa->mp = 0;
    wk->sa->ok = 0;
    wk->sa->ex = 0;
}



s32 check_combo_end(ix)
s16 ix;
{
    s16 rnum;
    if (plw[ix].py->flag) {
        return 1;
    }
    if (plw[ix].tsukamare_f) {
        return 1;
    }
    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 0;
    }
    if (plw[ix].wu.cg_ja.boix == 0 && plw[ix].wu.cg_ja.cuix == 0 && plw[ix].wu.pat_status == 38) {
        return 0;
    }
    if (plw[ix].zuru_flag) {
        return 0;
    }
    if (plw[ix].wu.routine_no[1] != 1 && plw[ix].wu.routine_no[1] != 3) {
        return 0;
    }
    if (plw[ix].old_gdflag != plw[ix].guard_flag) {
        if (plw[ix].guard_flag == 0) {
            rnum = 0;
        } else {
            rnum = 1;
        }
    } else if (plw[ix].guard_flag == 0) {
        rnum = 0;
    } else {
        rnum = 1;
    }
    return rnum;
}

