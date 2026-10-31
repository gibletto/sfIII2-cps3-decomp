/*
 * EFFI8.C  Effect I8: the balls of the blocking bonus stage
 *
 * Effect I8 is a ball in the bonus stage where balls are thrown at the player to be parried; it
 * is created through effect_I8_init by setup_effI8 (below, called from BBBSCOM.c) with timing and aim data. effect_I8_move lobs it in
 * from the screen edge to the thrower (cal_speeds_to_me_effI8), who catches it in a set attack
 * frame (effI8_hit_box) and throws it at the player (cal_speeds_to_em_effI8, aimed at a height
 * per character from bbbs_emtall), counting down Bonus_Game_Work. effI8_main_process bounces it
 * with a bounce sound and handles hits: a parry adds to Bonus_Game_result with bonus score, a
 * normal hit or guard knocks it away, and a ball that hits the player scores and adds to
 * Bonus_Game_ex_result. The bounce step is 32; a parry scores 6 and 5.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "PLS02.h"
#include "effd6_code.h"
#include "EFFD7.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFF03.h"
#include "HITCHECK.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS01.h"
#include "CHARID.h"
#include "EFFI8.h"

/* routine_no[0] */
#define R0_INIT         0       /* set up and lob to the thrower */
#define R0_MOVE         1       /* fly, bounce and take hits */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1] */
#define R1_FLY          0       /* fly and bounce */
#define R1_HIT          1       /* react to a hit */
#define R1_STRUCK       2       /* struck the player: vanish soon */

/* routine_no[2] */
#define R2_FLY          0       /* fly until the thrower catches it */
#define R2_HELD         1       /* held until it is thrown */

/* Sean's attack routine 31 (pl12_exatt_table: Att_PL12_BONUS_STAGE), the ball thrower of the bonus stage */
#define SEAN_BONUS_STAGE 31



void effect_I8_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 11;
        set_char_base_data(&ewk->wu);
        ewk->wu.my_col_code = ewk->wu.dm_vital;
        *ewk->wu.char_table = plef_char_table;
        ball_init_position_effD7(ewk, (PLW*)ewk->my_master);
        ewk->wu.type = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        ewk->wu.shell_ix[1] = 0;
        ewk->wu.shell_ix[2] = 8;
        ewk->wu.shell_ix[3] = 32;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        cal_speeds_to_me_effI8(ewk, (PLW*)ewk->my_master);
        set_char_move_init(&ewk->wu, 0, 0x75);
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1 || Suicide != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        if (sa_stop_check()) {
        } else {
            if (ewk->wu.hit_stop < 0) {
                ewk->wu.hit_stop = -ewk->wu.hit_stop;
            }
            if (EXE_flag == 0 && Game_pause == 0) {
                effI8_main_process(ewk);
            }
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            if (ewk->wu.type) {
                hit_push_request(&ewk->wu);
            }
        }
        sort_push_request(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effI8_main_process(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = R1_HIT;
    }
    if (ewk->wu.shell_ix[1]) {
        ewk->wu.kage_flag = ewk->wu.shell_ix[1] = 0;
    }
    switch (ewk->wu.routine_no[1]) {
    case R1_FLY:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        switch (ewk->wu.routine_no[2]) {
        case R2_FLY:
            char_move(&ewk->wu);
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
            if (ewk->wu.xyz[1].disp.pos < ewk->wu.shell_ix[2]) {
                ewk->wu.xyz[1].disp.pos = ewk->wu.shell_ix[2];
                ewk->wu.shell_ix[2] -= ewk->wu.shell_ix[3];
                if (ewk->wu.char_index != 0x8A) {
                    set_char_move_init(&ewk->wu, 0, 0x8A);
                }
                sound_effect_request[0x157](ewk, 0x157);
                ewk->wu.mvxy.a[0].sp = (ewk->wu.mvxy.a[0].sp * 80) / 100;
                ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
                ewk->wu.mvxy.a[1].sp = (ewk->wu.mvxy.a[1].sp * 3) / 5;
                ewk->wu.shell_ix[1] = 1;
                ewk->wu.hit_stop = 1;
                if (screen_range_check_effD7(&ewk->wu)) {
                    ewk->wu.disp_flag = 0;
                    ewk->wu.type = 0;
                    ewk->wu.routine_no[0] = R0_END;
                    break;
                }
            }
            if (ewk->wu.kage_flag != 0 && ewk->refrected == 0) {
                if (mwk->wu.routine_no[1] == PLAYER_ATTACK && mwk->wu.routine_no[2] == SEAN_BONUS_STAGE && mwk->wu.cg_type == 0x28) {
                    if (hit_check_subroutine(&ewk->wu, (WORK*)ewk->my_master, effI8_hit_box[0], effI8_hit_box[1])) {
                        mwk->wu.cmwk[7] = 1;
                        ewk->wu.type = 0;
                        ewk->wu.routine_no[2] = R2_HELD;
                    }
                }
            }
            break;
        case R2_HELD:
            ewk->wu.disp_flag = 0;
            if (mwk->wu.routine_no[1] != PLAYER_ATTACK) {
                ewk->wu.routine_no[2] = R2_FLY;
                ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos;
                ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos + 136;
                ewk->wu.disp_flag = 1;
                ewk->wu.type = 1;
                ewk->wu.mvxy.a[0].sp = 0x18000;
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.a[1].sp = 0x20000;
                ewk->wu.mvxy.d[1].sp = -0x6800;
            } else if (mwk->wu.cmwk[6]) {
                ewk->wu.routine_no[2] = R2_FLY;
                mwk->wu.cmwk[6] = 0;
                if (mwk->wu.rl_flag) {
                    ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos + 10;
                } else {
                    ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos - 10;
                }
                ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos + 136;
                Bonus_Game_Work--;
                ewk->wu.disp_flag = 1;
                ewk->wu.type = 1;
                set_char_move_init(&ewk->wu, 0, 0x89);
                cal_speeds_to_em_effI8(ewk, (PLW*)ewk->wu.target_adrs);
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
            }
            break;
        }
        break;
    case R1_HIT:
        if (ewk->wu.hf.hit.player) {
            if (ewk->wu.hf.hit.player & 0x33) {
                ewk->wu.routine_no[1] = R1_FLY;
                if (ewk->wu.hf.hit.player & 0x30) {
                    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                    ewk->wu.mvxy.a[0].sp /= 3;
                    ewk->wu.mvxy.a[1].sp = 0x10000;
                    ewk->wu.mvxy.d[1].sp = -0x6000;
                } else {
                    ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                    ewk->wu.mvxy.a[0].sp /= 2;
                    ewk->wu.mvxy.a[1].sp = 0;
                    ewk->wu.mvxy.d[1].sp = -0x6000;
                }
            } else if (ewk->wu.hf.hit.player & 0xC0) {
                ewk->wu.routine_no[1] = R1_FLY;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->wu.mvxy.a[0].sp = 0x30000;
                ewk->wu.mvxy.a[1].sp = 0x44000;
                ewk->wu.mvxy.d[1].sp = -0x5000;
                ewk->wu.hit_stop = 4;
                Bonus_Game_result++;
                if (ewk->wu.hf.hit.player & 0x80) {
                    Additinal_Score_DM((WORK_Other*)ewk->wu.target_adrs, 6);
                } else {
                    Additinal_Score_DM((WORK_Other*)ewk->wu.target_adrs, 5);
                }
                set_char_move_init(&ewk->wu, 0, 0x8B);
            }
        } else if (ewk->wu.hf.hit.effect && ((WORK*)ewk->wu.hit_adrs)->id == 0x89) {
            sound_effect_request[0x157](ewk, 0x157);
            ewk->wu.routine_no[1] = R1_FLY;
            ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
            ewk->wu.mvxy.a[0].sp = (ewk->wu.mvxy.a[0].sp * 3) / 4;
            ewk->wu.hit_stop = 2;
        } else {
            if (ewk->wu.dmg_work_id != 1) {
                sound_effect_request[0x10B](ewk, 0x10B);
            }
            ewk->wu.routine_no[1] = R1_STRUCK;
            ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.type = 0;
            ewk->wu.kage_flag = 0;
            ewk->wu.dir_timer = 8;
            ewk->wu.hit_stop = 2;
            Additinal_Score_DM((WORK_Other*)ewk->wu.target_adrs, 6);
            Bonus_Game_ex_result++;
        }
        ewk->wu.hit_work_id = ewk->wu.dmg_work_id = 0;
        ewk->wu.hf.hit_flag = 0;
        ewk->refrected = 1;
        break;
    case R1_STRUCK:
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
        }
        break;
    }
}



void cal_speeds_to_me_effI8(WORK_Other* ewk, PLW* mwk) {
    s16 tx = mwk->wu.xyz[0].disp.pos;
    s16 ty = cal_move_quantity3(&mwk->wu, ewk->wu.dir_timer) + 128;
    cal_speeds_effD7(ewk, ewk->wu.dir_timer, tx, ty, 5);
}



void cal_speeds_to_em_effI8(WORK_Other* ewk, PLW* twk) {
    s16 tx = twk->wu.position_x;
    s16 ty;
    if (twk->wu.rl_flag) {
        tx -= ewk->wu.next_x;
    } else {
        tx += ewk->wu.next_x;
    }
    ty = bbbs_emtall[twk->player_number];
    cal_speeds_effD7(ewk, ewk->wu.dir_step, tx, ty, ewk->wu.dir_old);
}



s32 effect_I8_init(wk, top, sptr)
PLW* wk;
s16 top;
const s16* sptr;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xBC;
    ewk->wu.work_id = 2;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.dm_vital = wk->wu.my_col_code;
    ewk->wu.dir_timer = top;
    ewk->wu.dir_step = sptr[1];
    ewk->wu.dir_old = sptr[2];
    ewk->wu.next_x = sptr[3];
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = wk->wu.target_adrs;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = 0x1C;
    return 0;
}



void setup_effI8(PLW* wk, const BBBSTable* dadr) {
    s16 i;
    s16 ttime = 0;
    for (i = 0; i < dadr->kosuu; i++) {
        ttime += dadr->bbdat[i][0];
        effect_I8_init(wk, ttime, &dadr->bbdat[i][0]);
    }
}
