/*
 * PLCNTSET_2.C  Player control fight phases, settlement and push-back (part 2)
 *
 * Player_control is the per-frame player control of a fight, called from Game_Main. It runs the
 * player_main_process phase (plcnt_init, plcnt_move, plcnt_die), body touch and push-back
 * (check_body_touch, check_damage_hosei), quake and hit requests for both players and the
 * after-image table.
 * plcnt_init runs the start-of-round (appear) phase: init_app_10000 sets up both players at the
 * start of a match (pli_0000 clears the works, loads the combo demo players if needed and calls
 * setup_base_and_other_data), stores the parry counters, loads the extra colours some characters
 * need and waits until both players are ready (pli_1000) before starting the fight. init_app_20000
 * and init_app_30000 are the lighter resets used by the other appear types.
 * plcnt_move is the fight phase: it moves both players (move_player_work, calling Player_move in
 * the right order with the scroll limits around the screen centre), checks time over and KO
 * (time_over_check, will_die, settle_check) and enters the settle phase with setup_settle_rno.
 * plcnt_die runs the settle types (settle_type_00000 - 60000) that play the KO, double KO or
 * time-over finish and set Next_Step. check_damage_hosei passes the push-back left over by one
 * player on to the other. check_sa_resurrection / check_sa_type_rebirth handle rebirth-type super
 * arts. set_quake and add_next_position are shared with the bonus control and effects.
 * 2nd Impact has no grade calls, no pli_3000 extra graphics, no settle_type_70000 and no
 * check_work_position / set_rl_waza / set_scrrrl step in the player moves.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SLOWF.h"
#include "Manage.h"
#include "manage_2.h"
#include "PLMAIN.h"
#include "PLS02.h"
#include "effd2.h"
#include "effd3.h"
#include "Grade.h"
#include "ta_sub.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "PLS01.h"
#include "PLPNM.h"
#include "PLPDM.h"
#include "EM_Cand.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFC9.h"
#include "effM5.h"
#include "PLCNTSET.h"
#include "EFF33.h"
#include "plcntset_2.h"
#include "fighter.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "HITCHECK.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "spgauge.h"
#include "sc_sub.h"
#include "sc_sub_2.h"
#include "EFFM7.h"



static void move_player_work(void);


void Player_control(void) {
    s16 i;
    pl_eff_disp_stop = 0;
    if ((pcon_rno[0] + pcon_rno[1]) == 0) {
        goto run;
    }
    if (!Game_pause && !EXE_flag) {
run:
        pcon_timer++;
        pcon_timer &= 0x7FFF;
        player_main_process[pcon_rno[0]]();
        check_body_touch();
        check_damage_hosei();
        set_quake(&plw[0]);
        set_quake(&plw[1]);
        if (plw[0].zuru_flag == 0 && plw[0].zettai_muteki_flag == 0) {
            hit_push_request(&plw[0].wu);
        }
        if (plw[1].zuru_flag == 0 && plw[1].zettai_muteki_flag == 0) {
            hit_push_request(&plw[1].wu);
        }
        add_next_position(&plw[0]);
        add_next_position(&plw[1]);
        check_cg_zoom();
    }
    for (i = 47; i > 0; i--) {
        zanzou_table[0][i] = zanzou_table[0][i - 1];
        zanzou_table[1][i] = zanzou_table[1][i - 1];
    }
    zanzou_table[0]->pos_x = plw[0].wu.position_x;
    zanzou_table[0]->pos_y = plw[0].wu.position_y;
    zanzou_table[0]->pos_z = plw[0].wu.position_z;
    zanzou_table[0]->cg_num = plw[0].wu.cg_number;
    zanzou_table[0]->renew = plw[0].wu.renew_attack;
    zanzou_table[0]->hit_ix = plw[0].wu.cg_hit_ix;
    zanzou_table[0]->flip = plw[0].wu.rl_flag;
    zanzou_table[0]->cg_flp = plw[0].wu.cg_flip;
    zanzou_table[0]->kowaza = plw[0].wu.kind_of_waza;
    zanzou_table[1]->pos_x = plw[1].wu.position_x;
    zanzou_table[1]->pos_y = plw[1].wu.position_y;
    zanzou_table[1]->pos_z = plw[1].wu.position_z;
    zanzou_table[1]->cg_num = plw[1].wu.cg_number;
    zanzou_table[1]->renew = plw[1].wu.renew_attack;
    zanzou_table[1]->hit_ix = plw[1].wu.cg_hit_ix;
    zanzou_table[1]->flip = plw[1].wu.rl_flag;
    zanzou_table[1]->cg_flp = plw[1].wu.cg_flip;
    zanzou_table[1]->kowaza = plw[1].wu.kind_of_waza;
    if (pl_eff_disp_stop == 0) {
        sort_push_request((WORK*)&plw[0]);
        sort_push_request((WORK*)&plw[1]);
    }
    if (Combo_Demo_Flag == 0) {
        spgauge_cont_main();
        stngauge_cont_main();
    }
}



void plcnt_init(void) {
    appear_initalize[appear_type]();
    move_player_work();
}



void init_app_10000(void) {
    switch (pcon_rno[1]) {
    case 0:
        pli_0000();
        if (plw[0].wu.operator) {
            paring_ctr_vs[0][0] = paring_ctr_ori[0];
        } else {
            paring_ctr_vs[0][0] = 0;
        }
        if (plw[1].wu.operator) {
            paring_ctr_vs[0][1] = paring_ctr_ori[1];
        } else {
            paring_ctr_vs[0][1] = 0;
        }
        round_slow_flag = 0;
        dead_voice_flag = 0;
        pcon_dp_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        if (plw[0].player_number == 9 || plw[1].player_number == 9) {
            load_any_color(0x8B);
        }
        if (plw[0].player_number == 8 || plw[1].player_number == 8) {
            load_any_color(0x9B);
        }
        if (plw[0].player_number == 13 || plw[1].player_number == 13) {
            load_any_color(0x9F);
        }
        break;
    case 1:
        pli_1000();
        break;
    }
}



void init_app_20000(void) {
    s16 i;
    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1]++;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        pcon_dp_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        reset_char_disp_work(&plw[0].wu);
        reset_char_disp_work(&plw[1].wu);
        for (i = 0; i < 8; i++) {
            plw[0].wu.routine_no[i] = plw[1].wu.routine_no[i] = 0;
        }
        setup_any_data();
        plw[0].do_not_move = plw[1].do_not_move = 0;
        break;
    case 1:
        pli_1000();
        break;
    }
}



void init_app_30000(void) {
    s16 i;
    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1]++;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        for (i = 1; i < 8; i++) {
            plw[0].wu.routine_no[i] = plw[1].wu.routine_no[i] = 0;
        }
        plw[0].wu.routine_no[0] = plw[1].wu.routine_no[0] = 1;
        another_bg[0] = another_bg[1] = 0;
        plw[0].do_not_move = plw[1].do_not_move = 0;
        break;
    case 1:
        if (plw[0].wu.routine_no[0] != 3 || plw[1].wu.routine_no[0] != 3) {
            return;
        }
        pcon_rno[0] = 2;
        pcon_rno[1] = 3;
        pcon_rno[2] = 1;
        setup_EJG_index();
        effect_C9_init(&plw[0], 0);
        effect_C9_init(&plw[0], 1);
        effect_C9_init(&plw[0], 2);
        load_any_color(0x88);
        load_any_color(0x8A);
        load_char_gfx(0xAEA8, 1);
        if (bg_w.stage == 8 && Round_num == 0) {
            break;
        }
        if (plw[0].player_number == PL_HUGO) {
            effect_33_init((WORK*)&plw[0], 0);
        }
        if (plw[1].player_number == PL_HUGO) {
            effect_33_init((WORK*)&plw[1], 0);
        }
        break;
    }
}



void pli_0000(void) {
    pcon_rno[1]++;
    round_slow_flag = 0;
    work_init_zero((s32*)&plw[0], sizeof(PLW));
    work_init_zero((s32*)&plw[1], sizeof(PLW));
    if (Combo_Demo_Flag) {
        Setup_Combo_Demo_PL();
    }
    setup_base_and_other_data();
}



void pli_1000(void) {
    if ((plw[0].wu.routine_no[0] == 3) && (plw[1].wu.routine_no[0] == 3)) {
        if (Allow_a_battle_f) {
            pcon_rno[0] = 1;
            pcon_rno[1] = 0;
            plw[0].wu.routine_no[0] = 4;
            plw[1].wu.routine_no[0] = 4;
            ca_check_flag = 1;
        }
    }
}



void plcnt_move(void) {
    if (time_over_check() != 0) {
        return;
    }
    if (((u8)No_Death)) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }
    move_player_work();
    if (aiuchi_flag) {
        subtract_dm_vital_aiuchi(&plw[0]);
        subtract_dm_vital_aiuchi(&plw[1]);
        if ((plw[0].dead_flag != 0) && (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 2;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 4;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        } else if ((plw[0].dead_flag != 0) || (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 4;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 8;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        }
    }
    settle_check();
    if (pcon_rno[0] == 2) {
        if (Round_Result & 0x980) {
            if ((Round_Result & 0x800) && gouki_wins) {
                effect_D3_init(1);
            } else {
                effect_D3_init(0);
            }
        }
        if ((plw[0].kezurijini_flag == 1) || (plw[1].kezurijini_flag == 1)) {
            Round_Result |= 0x200;
        }
    }
}



void plcnt_die(void) {
    plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    settle_process[pcon_rno[1]]();
    move_player_work();
    if (pcon_rno[1] == 3) {
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 0;
    }
}



void settle_type_00000(void) {
    switch (pcon_rno[2]) {
    case 0:
        plw[Winner_id].wu.dir_timer = 60;
        pcon_rno[2]++;
    case 1:
        if (nekorobi_check(Loser_id)) {
            pcon_rno[2]++;
            plw[Winner_id].wkey_flag = 1;
        }
        if (--plw[Winner_id].wu.dir_timer != 0) {
            break;
        } else {
            plw[Winner_id].wkey_flag = 1;
            break;
        }
    case 2:
        if (footwork_check(Winner_id)) {
            if (Special_Settle) {
                pcon_rno[1] = 5;
                pcon_rno[2] = 0;
                break;
            }
            pcon_rno[2]++;
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Winner_id].wu.routine_no[3] = 0;
            plw[Loser_id].wu.routine_no[1] = 0;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[Loser_id].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
            complete_victory_pause();
            if (plw[Loser_id].wu.operator == 0 && plw[Loser_id].player_number == PL_GILL) {
                Gill_Pos_X = plw[Loser_id].wu.xyz[0].disp.pos;
            }
        }
        break;
    case 3:
        if (plw[Winner_id].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }
        break;
    }
}



void settle_type_10000(void) {
    switch (pcon_rno[2]) {
    case 0:
        if (nekorobi_check(0) && nekorobi_check(1)) {
            pcon_rno[2]++;
        }
        break;
    case 1:
        complete_victory_pause();
        pcon_rno[2]++;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        if (bg_w.stage == 8 && bg_w.area == 0) {
            plw[0].wu.routine_no[1] = 0;
            plw[0].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = 0;
            plw[1].wu.routine_no[1] = 0;
            plw[1].wu.routine_no[2] = 41;
            plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
        }
        if (plw[0].wu.operator == 0 && plw[0].player_number == PL_GILL) {
            Gill_Pos_X = plw[0].wu.xyz[0].disp.pos;
        }
        if (plw[1].wu.operator == 0 && plw[1].player_number == PL_GILL) {
            Gill_Pos_X = plw[1].wu.xyz[0].disp.pos;
        }
        break;
    }
}



void settle_type_20000(void) {
    switch (pcon_rno[2]) {
    case 0:
        plw[0].wkey_flag = plw[1].wkey_flag = 1;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        pcon_rno[2]++;
    case 1:
        if (footwork_check(0)) {
            if (footwork_check(1)) {
                pcon_rno[2]++;
                if (!plw[0].wu.operator && plw[0].player_number == PL_GILL) {
                    Gill_Pos_X = plw[0].wu.xyz[0].disp.pos;
                }
                if (!plw[1].wu.operator && plw[1].player_number == PL_GILL) {
                    Gill_Pos_X = plw[1].wu.xyz[0].disp.pos;
                }
            }
        }
        break;
    case 2:
        complete_victory_pause();
        if (plw[0].wu.vital_new == plw[1].wu.vital_new) {
            pcon_rno[2] = 4;
        } else {
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            pcon_rno[2]++;
        }
        break;
    case 3:
        if (plw[0].wu.routine_no[3] != 9) {
            break;
        }
        if (plw[1].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }
        break;
    }
}



void settle_type_30000(void) {
    switch (pcon_rno[2]) {
    case 0:
        break;
    case 1:
        if (Event_Judge_Gals != -1) {
            break;
        }
        if (Complete_Judgement) {
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            complete_victory_pause();
            pcon_rno[2]++;
            if (plw[Loser_id].wu.operator == 0 && plw[Loser_id].player_number == PL_GILL) {
                Gill_Pos_X = plw[Loser_id].wu.xyz[0].disp.pos;
            }
        }
        break;
    case 2:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }
        break;
    }
}



void settle_type_40000(void) {
    switch (pcon_rno[2]) {
    case 0:
        plw[Winner_id].wkey_flag = 1;
        pcon_rno[2]++;
    case 1:
        if (nekorobi_check(Loser_id) != 0) {
            pcon_rno[2]++;
        case 2:
            if (footwork_check(Winner_id)) {
                pcon_rno[2]++;
                plw[Winner_id].wu.routine_no[2] = 40;
                plw[Winner_id].wu.routine_no[3] = 0;
                plw[Loser_id].wu.routine_no[1] = 0;
                plw[Loser_id].wu.routine_no[2] = 41;
                plw[Loser_id].wu.routine_no[3] = 0;
                plw[Winner_id].wu.cg_type = 0;
                plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
                plw[Winner_id].wu.dir_timer = 60;
                if (plw[Loser_id].wu.operator == 0 && plw[Loser_id].player_number == PL_GILL) {
                    Gill_Pos_X = plw[Loser_id].wu.xyz[0].disp.pos;
                }
                set_conclusion_slow();
                return;
            }
        }
        break;
    case 3:
        if (--plw[Winner_id].wu.dir_timer <= 0) {
            if (Special_Settle) {
                pcon_rno[2] = 10;
                break;
            } else {
                complete_victory_pause();
                pcon_rno[2]++;
                break;
            }
        }
        break;
    case 4:
        if (plw[Winner_id].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }
        break;
    case 10:
        complete_victory_pause();
        pcon_rno[2]++;
        break;
    case 11:
        if (Special_Settle & 0x80) {
            pcon_rno[1] = 6;
            pcon_rno[2] = 0;
        }
        break;
    }
}



/* provisional name */
void settle_type_50000(void) {
    switch (pcon_rno[2]) {
    case 0:
        complete_victory_pause();
        pcon_rno[2]++;
        break;
    case 1:
        if (Special_Settle & 0x80) {
            pcon_rno[2]++;
            plw[Loser_id].wu.routine_no[1] = 0;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[Loser_id].wu.routine_no[3] = 0;
            plw[Winner_id].do_not_move = 1;
            bg_stop = 1;
        }
        break;
    case 2:
        if (plw[Loser_id].wu.routine_no[3] >= 2) {
            pcon_rno[2]++;
            Next_Step = 1;
        }
        break;
    }
}



/* provisional name */
void settle_type_60000(void) {
    switch (pcon_rno[2]) {
    case 0:
        pcon_rno[2]++;
        plw[Loser_id].wu.routine_no[1] = 0;
        plw[Loser_id].wu.routine_no[2] = 41;
        plw[Loser_id].wu.routine_no[3] = 0;
        plw[Winner_id].do_not_move = 1;
        break;
    case 1:
        if (plw[Loser_id].wu.routine_no[3] >= 2) {
            pcon_rno[2]++;
            Next_Step = 1;
            bg_stop = 0;
        }
        break;
    }
}



static void move_P1_move_P2();
static void move_P2_move_P1();

static void move_player_work(void) {
    s16 center;
    s16 scr_r;
    s16 scr_l;
    center = get_center_position();
    if (Game_setting.mode) {
        scr_r = center + 248;
        scr_l = center - 248;
    } else {
        scr_r = center + 192;
        scr_l = center - 192;
    }
    Timer_Freeze = 0;
    switch (plw[0].tsukami_f + (plw[1].tsukami_f * 2)) {
    case 1:
        move_P1_move_P2(scr_r, scr_l);
        break;
    case 2:
        move_P2_move_P1(scr_r, scr_l);
        break;
    default:
        switch (plw[0].wu.operator + (plw[1].wu.operator * 2)) {
        case 1:
            move_P1_move_P2(scr_r, scr_l);
            break;
        case 2:
            move_P2_move_P1(scr_r, scr_l);
            break;
        default:
            switch ((plw[0].wu.routine_no[1] == 4) + ((plw[1].wu.routine_no[1] == 4) * 2)) {
            case 1:
                move_P1_move_P2(scr_r, scr_l);
                break;
            case 2:
                move_P2_move_P1(scr_r, scr_l);
                break;
            default:
                if (Game_timer & 1) {
                    move_P1_move_P2(scr_r, scr_l);
                } else {
                    move_P2_move_P1(scr_r, scr_l);
                }
                break;
            }
            break;
        }
        break;
    }
}



static void move_P1_move_P2(scr_r, scr_l)
s16 scr_r;
s16 scr_l;
{
    if (plw[0].do_not_move == 0) {
        Player_move(&plw[0], sw_to_lvbt(p1sw_0));
    }
    if (bg_stop == 0 && bg_app == 0) {
        if (set_field_hosei_flag(&plw[0], scr_r, 1)) {
            set_field_hosei_flag(&plw[0], scr_l, 0);
        }
    }
    if (plw[1].do_not_move == 0) {
        Player_move(&plw[1], sw_to_lvbt(p2sw_0));
    }
    if (bg_stop == 0 && bg_app == 0) {
        if (set_field_hosei_flag(&plw[1], scr_r, 1)) {
            set_field_hosei_flag(&plw[1], scr_l, 0);
        }
    }
}



static void move_P2_move_P1(scr_r, scr_l)
s16 scr_r;
s16 scr_l;
{
    if (plw[1].do_not_move == 0) {
        Player_move(&plw[1], sw_to_lvbt(p2sw_0));
    }
    if (bg_stop == 0 && bg_app == 0) {
        if (set_field_hosei_flag(&plw[1], scr_r, 1)) {
            set_field_hosei_flag(&plw[1], scr_l, 0);
        }
    }
    if (plw[0].do_not_move == 0) {
        Player_move(&plw[0], sw_to_lvbt(p1sw_0));
    }
    if (bg_stop == 0 && bg_app == 0) {
        if (set_field_hosei_flag(&plw[0], scr_r, 1)) {
            set_field_hosei_flag(&plw[0], scr_l, 0);
        }
    }
}



/* 2nd Impact push-back rules (3rd Strike check_damage_hosei_nage / _dageki are not in 2nd Impact) */
void check_damage_hosei(void) {
    plw[0].muriyari_ugoku = plw[0].hosei_amari;
    plw[1].muriyari_ugoku = plw[1].hosei_amari;
    switch ((plw[0].hosei_amari != 0) + ((plw[1].hosei_amari != 0) * 2)) {
    case 1:
        if (plw[0].tsukami_f && plw[0].kind_of_catch == 1) {
            goto p1_push;
        }
        if (plw[0].tsukamare_f | plw[0].dm_hos_flag) {
p1_push:
            plw[1].wu.xyz[0].disp.pos += plw[0].hosei_amari;
            plw[1].muriyari_ugoku += plw[0].hosei_amari;
        }
        break;
    case 2:
        if (plw[1].tsukami_f && plw[1].kind_of_catch == 1) {
            goto p2_push;
        }
        if (plw[1].tsukamare_f | plw[1].dm_hos_flag) {
p2_push:
            plw[0].wu.xyz[0].disp.pos += plw[1].hosei_amari;
            plw[0].muriyari_ugoku += plw[1].hosei_amari;
        }
        break;
    case 3:
        if (plw[0].hos_fi_flag == plw[1].hos_fi_flag) {
            if (plw[0].tsukamare_f) {
                goto p1_push;
            }
            if (plw[1].tsukamare_f) {
                goto p2_push;
            }
        }
        break;
    }
    plw[0].hosei_amari = plw[1].hosei_amari = 0;
}



s32 time_over_check(void) {
    if ((will_die() != 0) && (round_timer.size.full == 0)) {
        Winner_id = 0;
        Loser_id = 1;
        if (plw[0].wu.vital_new < plw[1].wu.vital_new) {
            Winner_id = 1;
            Loser_id = 0;
        }
        setup_gouki_wins();
        Conclusion_Flag = 1;
        Conclusion_Type = 2;
        setup_settle_rno(2);
        if (Demo_Flag) {
            request_center_message(2);
        }
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
        Round_Result |= 1;
        return 1;
    }
    return 0;
}



s32 will_die(void) {
    if (plw[0].wu.dm_vital > plw[0].wu.vital_new) {
        return 0;
    }
    if (plw[1].wu.dm_vital > plw[1].wu.vital_new) {
        return 0;
    }
    return 1;
}



/* provisional name */
void setup_settle_rno(kos)
s16 kos;
{
    pcon_rno[0] = 2;
    pcon_rno[1] = kos;
    pcon_rno[2] = 0;
    ca_check_flag = 0;
    pcon_dp_flag = 1;
}



void settle_check(void) {
retry:
    switch ((plw[0].dead_flag) + (plw[1].dead_flag * 2)) {
    case 1:
        Winner_id = 1;
        Loser_id = 0;
        goto settle;
    case 2:
        Winner_id = 0;
        Loser_id = 1;
    settle:
        if (check_sa_resurrection(&plw[Loser_id])) {
            break;
        }
        setup_gouki_wins();
        Round_Result |= plw[Loser_id].wu.dm_koa;
        if ((Round_Result & 0x800) && gouki_wins) {
            Shin_Gouki_BGM = 1;
            Control_Music_Fade(150);
            setup_settle_rno(4);
        } else {
            setup_settle_rno(0);
            Conclusion_Flag = 1;
            Conclusion_Type = 0;
            if (Demo_Flag) {
                request_center_message(0);
            }
        }
        break;
    case 3:
        if (check_sa_resurrection(&plw[0]) || check_sa_resurrection(&plw[1])) {
            goto retry;
        }
        Conclusion_Flag = 1;
        Conclusion_Type = 1;
        setup_settle_rno(1);
        if (Demo_Flag) {
            request_center_message(1);
        }
        break;
    default:
        break;
    }
}



/* provisional name */
s32 check_sa_resurrection(PLW* wk) {
    if (check_sa_type_rebirth(wk) == 0) {
        return 0;
    }
    wk->kezurijini_flag = 0;
    wk->dead_flag = 0;
    return 1;
}



s32 check_sa_type_rebirth(PLW* wk) {
    if (wk->sa->gauge_type != 3) {
        return 0;
    }
    if (wk->sa->ok != 1) {
        return 0;
    }
    return 1;
}



s32 nekorobi_check(char pl) {
    s16 result;
    result = 0;
    if (plw[pl].wu.routine_no[1] == 1) {
        if (plw[pl].wu.routine_no[2] == 0) {
            if (plw[pl].wu.routine_no[3] > 2) {
                result = 1;
            }
        }
    }
    return result;
}



s32 footwork_check(char pl)
{
    s16 result;
    result = 0;
    if (plw[pl].wu.routine_no[1] == 0) {
        if (plw[pl].wu.routine_no[2] == 1) {
            result = 1;
        }
    }
    return result;
}



/* provisional name */
void reset_char_disp_work(WORK* wk) {
    s16 i;
    for (i = 0; i < 4; i++) {
        wk->spr.gfx_blk10[i] = wk->spr.gfx_blk40[i] = 0;
    }
    wk->old_cgnum = 0;
    wk->spr.gfx_ofs = 0;
    wk->spr.gfx_cells = 0;
}



void set_quake(PLW* wk) {
    if (wk->wu.hit_quake) {
        wk->wu.hit_quake--;
        wk->wu.next_x = quake_table[wk->wu.hit_quake];
        if (wk->wu.rl_flag) {
            wk->wu.next_x = -wk->wu.next_x;
        }
    } else {
        wk->wu.next_x = 0;
    }
    wk->wu.next_y = 0;
}



void add_next_position(PLW* wk) {
    wk->wu.position_x = wk->wu.xyz[0].disp.pos + wk->wu.next_x;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos + wk->wu.next_y;
    wk->wu.position_z = wk->wu.next_z;
}



/* provisional name */
void setup_gouki_wins(void)
{
    gouki_wins = 0;
    if (plw[Winner_id].player_number == PL_GOUKI1 || plw[Winner_id].player_number == PL_GOUKI2) {
        gouki_wins = 1;
    }
}
