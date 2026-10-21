/*
 * PLS03.C  Special move, super art and normal attack command checks
 *
 * check_full_gauge_attack, check_super_arts_attack and execute_super_arts test the super art commands against
 * the gauge; check_special_attack the
 * special move commands (the EX version only with the EX gauge); check_leap_attack the command
 * leap attacks; hissatsu_setup_union sets up the chosen move. Then the normal attack checks:
 * check_nm_attack picks the attack by the jump/crouch status (a jump status change re-picks it),
 * the parry, taunt, throw escape and lever-up checks, waza_select and decode_wst_data for the
 * CPU's choices, and the cancel checks (renda, meoshi).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Grade.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "ta_sub.h"
#include "PLPAT.h"
#include "PLS03.h"
#include "PLS03ATT.h"

#pragma inline(shot_data_refresh)

void hissatsu_setup_union(PLW* wk, s16 rno) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = rno;
    wk->wu.routine_no[3] = 0;
    wk->cancel_timer = 0;
    wk->wu.cg_type = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.paring_attack_flag = 0;
}



/* the 0x100 test comes before the ground/air split */
s32 check_full_gauge_attack(PLW* wk, s8 always) {
    u16* conpane;
    s16 j;
    u16 cusw;
    u16 exsw;
    if (wk->sa->mp != 1) {
        return 0;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 0x40;
    }
    if (always && !(wk->cp->btix[wk->sa->exsa_g_ix] & 0x100)) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos <= 0) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }
        if (wk->sa->exsa_g_ix == 0) {
            return 0;
        }
        if (wk->sa->exsa_g_ix > 0x1C) {
            return 0;
        }
        conpane = (u16*)wk->cp;
        if (wk->cp->waza_flag[wk->sa->exsa_g_ix] == -1) {
            return 0;
        }
        if ((wk->cp->btix[wk->sa->exsa_g_ix] & 0xFF) != 0x80) {
            if (wk->cp->waza_flag[wk->sa->exsa_g_ix] != 0) {
                cusw = conpane[wk->cp->btix[wk->sa->exsa_g_ix] & 0xFF];
                for (j = 3; j >= 0; j--) {
                    if ((j == 3) && !(wk->cp->btix[wk->sa->exsa_g_ix] & 0x600)) {
                        continue;
                    }
                    exsw = cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_g_ix][j]];
                    if ((u16)(exsw & cusw) != cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_g_ix][j] & 0xF]) {
                        continue;
                    }
                    setup_comm_back(&wk->wu);
                    wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->exsa_g_ix - 20][j].as;
                    wk->wu.cg_cancel = 0;
                    wk->sa->mp = -1;
                    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exsa_g_ix][j]);
                    waza_compel_all_init2(wk);
                    return 1;
                }
            }
        }
        return 0;
    }
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->exsa_a_ix == 0) {
        return 0;
    }
    if ((wk->sa->exsa_a_ix) < 0x1C) {
        return 0;
    }
    conpane = (u16*)wk->cp;
    if (wk->cp->waza_flag[wk->sa->exsa_a_ix] == -1) {
        return 0;
    }
    if ((wk->cp->btix[wk->sa->exsa_a_ix] & 0xFF) != 0x80) {
        if (wk->cp->waza_flag[wk->sa->exsa_a_ix] != 0) {
            cusw = conpane[wk->cp->btix[wk->sa->exsa_a_ix] & 0xFF];
            for (j = 3; j >= 0; j--) {
                if ((j == 3) && !(wk->cp->btix[wk->sa->exsa_a_ix] & 0x600)) {
                    continue;
                }
                exsw = cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_a_ix][j]];
                if ((u16)(exsw & cusw) != cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_a_ix][j] & 0xF]) {
                    continue;
                }
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_air[wk->player_number][wk->sa->exsa_a_ix - 38][j].as;
                wk->wu.cg_cancel = 0;
                wk->sa->mp = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exsa_a_ix][j]);
                waza_compel_all_init2(wk);
                return 1;
            }
        }
    }
    return 0;
}



s32 check_super_arts_attack(PLW* wk) {
    u16* conpane;
    s16 j;
    u16 cusw;
    u16 exsw;
    if (wk->sa->ok != 1) {
        return 0;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 1;
    }
    if (wk->wu.xyz[1].disp.pos <= 0) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }
        if (wk->sa->nmsa_g_ix == 0) {
            return 0;
        }
        if (wk->sa->nmsa_g_ix > 0x1C) {
            return 0;
        }
        conpane = (u16*)wk->cp;
        if (wk->cp->waza_flag[wk->sa->nmsa_g_ix] == -1) {
            return 0;
        }
        if ((wk->cp->btix[wk->sa->nmsa_g_ix] & 0xFF) != 0x80) {
            if (wk->cp->waza_flag[wk->sa->nmsa_g_ix] != 0) {
                cusw = conpane[wk->cp->btix[wk->sa->nmsa_g_ix] & 0xFF];
                for (j = 3; j >= 0; j--) {
                    if ((j == 3) && !(wk->cp->btix[wk->sa->nmsa_g_ix] & 0x600)) {
                        continue;
                    }
                    exsw = cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_g_ix][j]];
                    if ((u16)(exsw & cusw) != cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_g_ix][j] & 0xF]) {
                        continue;
                    }
                    setup_comm_back(&wk->wu);
                    wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->nmsa_g_ix - 20][j].as;
                    wk->wu.cg_cancel = 0;
                    wk->sa->ok = -1;
                    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_g_ix][j]);
                    waza_compel_all_init2(wk);
                    return 1;
                }
            }
        }
        return 0;
    }
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->nmsa_a_ix == 0) {
        return 0;
    }
    if ((wk->sa->nmsa_a_ix) < 0x1C) {
        return 0;
    }
    conpane = (u16*)wk->cp;
    if (wk->cp->waza_flag[wk->sa->nmsa_a_ix] == -1) {
        return 0;
    }
    if ((wk->cp->btix[wk->sa->nmsa_a_ix] & 0xFF) != 0x80) {
        if (wk->cp->waza_flag[wk->sa->nmsa_a_ix] != 0) {
            cusw = conpane[wk->cp->btix[wk->sa->nmsa_a_ix] & 0xFF];
            for (j = 3; j >= 0; j--) {
                if ((j == 3) && !(wk->cp->btix[wk->sa->nmsa_a_ix] & 0x600)) {
                    continue;
                }
                exsw = cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_a_ix][j]];
                if ((u16)(exsw & cusw) != cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_a_ix][j] & 0xF]) {
                    continue;
                }
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_air[wk->player_number][wk->sa->nmsa_a_ix - 38][j].as;
                wk->wu.cg_cancel = 0;
                wk->sa->ok = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_a_ix][j]);
                waza_compel_all_init2(wk);
                return 1;
            }
        }
    }
    return 0;
}



s32 execute_super_arts(PLW* wk) {
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 1;
    }
    if ((wk->sa->gauge_type != 3) && pcon_dp_flag) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        goto air;
    }
    if (wk->spmv_ng_flag & 0x40000000) {
        return 0;
    }
    if (wk->sa->ok != 1) {
        return 0;
    }
    if (wk->sa->nmsa_g_ix > 28) {
        return 0;
    }
    setup_comm_back(&wk->wu);
    wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->nmsa_g_ix - 20][0].as;
    wk->wu.cg_cancel = 0;
    wk->sa->ok = -1;
    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_g_ix][0]);
    waza_compel_all_init2(wk);
    return 1;
air:
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->ok != 1) {
        return 0;
    }
    if (wk->sa->nmsa_a_ix < 28) {
        return 0;
    }
    setup_comm_back(&wk->wu);
    wk->as = &asstbl_sa_air[wk->player_number][wk->sa->nmsa_a_ix - 38][0].as;
    wk->wu.cg_cancel = 0;
    wk->sa->ok = -1;
    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_a_ix][0]);
    waza_compel_all_init2(wk);
    return 1;
}



/* the EX test before the command match */
s32 check_special_attack(PLW* wk) {
    s16 i;
    s16 j;
    u16 cusw;
    u16 exsw;
    u16* conpane;
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 2;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        goto air;
    }
    if (wk->spmv_ng_flag & 0x10000000) {
        return 0;
    }
    conpane = (u16*)wk->cp;
    for (i = 28; i < 38; i++) {
        if (wk->cp->waza_flag[i] == -1) {
            continue;
        }
        if (wk->cp->btix[i] & 0x800) {
            if (shell_live_check(wk, i)) {
                continue;
            }
        }
        if ((wk->cp->btix[i] & 0xFF) != 0x80) {
            if (wk->cp->waza_flag[i]) {
                cusw = conpane[wk->cp->btix[i] & 0xFF];
                for (j = 3; j >= 0; j--) {
                    if (j == 3) {
                        if (wk->sa->mp == -1) {
                            continue;
                        }
                        if (wk->sa->ok == -1) {
                            continue;
                        }
                        if (wk->sa->ex != 1) {
                            continue;
                        }
                        if (!(wk->cp->btix[i] & 0x600)) {
                            continue;
                        }
                    }
                    exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];
                    if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                        continue;
                    }
                    if ((j == 3) && (wk->cp->btix[i] & 0x400)) {
                        wk->sa->ex = -1;
                    }
                    setup_comm_back(&wk->wu);
                    wk->as = &asstbl_sa_ground[wk->player_number][i - 20][j].as;
                    wk->wu.cg_cancel &= 0x40;
                    hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                    waza_flag_clear_only_1(wk->wu.id, i);
                    return 1;
                }
            }
        }
    }
    return 0;
air:
    if (wk->spmv_ng_flag & 0x20000000) {
        return 0;
    }
    if ((wk->wu.mvxy.a[1].sp > 0) && (wk->wu.xyz[1].disp.pos < 32)) {
        return 0;
    }
    conpane = (u16*)wk->cp;
    for (i = 46; i < 56; i++) {
        if (wk->cp->waza_flag[i] == -1) {
            continue;
        }
        if ((wk->cp->btix[i] & 0xFF) != 0x80) {
            if (wk->cp->waza_flag[i]) {
                cusw = conpane[wk->cp->btix[i] & 0xFF];
                for (j = 3; j >= 0; j--) {
                    if (j == 3) {
                        if (wk->sa->mp == -1) {
                            continue;
                        }
                        if (wk->sa->ok == -1) {
                            continue;
                        }
                        if (wk->sa->ex != 1) {
                            continue;
                        }
                        if (!(wk->cp->btix[i] & 0x600)) {
                            continue;
                        }
                    }
                    exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];
                    if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                        continue;
                    }
                    if ((j == 3) && (wk->cp->btix[i] & 0x400)) {
                        wk->sa->ex = -1;
                    }
                    setup_comm_back(&wk->wu);
                    wk->as = &asstbl_sa_air[wk->player_number][i - 38][j].as;
                    wk->wu.cg_cancel &= 0x40;
                    hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                    waza_flag_clear_only_1(wk->wu.id, i);
                    return 1;
                }
            }
        }
    }
    return 0;
}



/* waza 14/15 by command (one button test) */
s32 check_leap_attack(PLW* wk) {
    s16 i;
    s16 j;
    u16 cusw;
    u16 exsw;
    u16* conpane;
    if (pcon_dp_flag) {
        return 0;
    }
    conpane = (u16*)wk->cp;
    for (i = 14; i < 16; i++) {
        if (wk->cp->waza_flag[i] == -1) {
            continue;
        }
        if ((wk->cp->btix[i] & 0xFF) != 0x80) {
            if (wk->cp->waza_flag[i]) {
                cusw = conpane[wk->cp->btix[i] & 0xFF];
                for (j = 3; j >= 0; j--) {
                    if (j == 3) {
                        if (wk->sa->ex != 1) {
                            continue;
                        }
                    }
                    exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];
                    if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                        continue;
                    }
                    if (j == 3) {
                        wk->sa->ex = -1;
                    }
                    setup_comm_back(&wk->wu);
                    wk->as = &asstbl_lv_D010[wk->player_number][i - 14][j].as;
                    hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                    return 1;
                }
            }
        }
    }
    return 0;
}



s32 check_leap_dummy(void) {
    return 0;
}



s32 check_nm_attack(PLW* wk) {
    s16 kos;
    s16 koa;
    wk->permited_koa |= 4;
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
again:
    switch (wk->wu.pat_status) {
    case 20:
        koa = waza_select(wk, kos, 3);
        wk->as = &asstbl_lv_3010[wk->player_number][kos][koa].as;
        break;
    case 14:
        koa = waza_select(wk, kos, 6);
        wk->as = &asstbl_lv_6010[wk->player_number][kos][koa].as;
        break;
    case 26:
        koa = waza_select(wk, kos, 9);
        wk->as = &asstbl_lv_9010[wk->player_number][kos][koa].as;
        break;
    case 22:
        koa = waza_select(wk, kos, 2);
        wk->as = &asstbl_lv_2010[wk->player_number][kos][koa].as;
        break;
    case 16:
        koa = waza_select(wk, kos, 5);
        wk->as = &asstbl_lv_5010[wk->player_number][kos][koa].as;
        break;
    case 28:
        koa = waza_select(wk, kos, 8);
        wk->as = &asstbl_lv_8010[wk->player_number][kos][koa].as;
        break;
    case 24:
        koa = waza_select(wk, kos, 4);
        wk->as = &asstbl_lv_4010[wk->player_number][kos][koa].as;
        break;
    case 18:
        koa = waza_select(wk, kos, 7);
        wk->as = &asstbl_lv_7010[wk->player_number][kos][koa].as;
        break;
    case 30:
        koa = waza_select(wk, kos, 10);
        wk->as = &asstbl_lv_10010[wk->player_number][kos][koa].as;
        break;
    default:
        if (check_jump_pat_status(wk)) {
            goto again;
        }
        if (wk->wu.xyz[1].disp.pos > 0) {
            return 0;
        }
        if (wk->cp->sw_lvbt & 2) {
            koa = waza_select(wk, kos, 1);
            wk->as = &asstbl_lv_1010[wk->player_number][kos][koa].as;
        } else {
            koa = waza_select(wk, kos, 0);
            wk->as = &asstbl_lv_0010[wk->player_number][kos][koa].as;
        }
        break;
    }
    setup_comm_back(&wk->wu);
    wk->current_attack = shot_data_refresh(kos);
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.cg_cancel &= 0xF8;
    return 1;
}



s32 check_jump_pat_status(PLW* wk) {
    if (!(wk->cp->sw_lvbt & 1)) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos <= 0) {
        wk->wu.xyz[1].disp.pos = 0;
        wk->wu.pat_status = jump_pat_status_data[wk->wu.rl_flag != wk->wu.rl_waza][wk->cp->lever_dir];
        return 1;
    }
    return 0;
}



s32 check_paring_attack(PLW* wk) {
    s16 kos;
    if (wk->spmv_ng_flag & 0x1000) {
        return 0;
    }
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    setup_comm_back((WORK*)wk);
    wk->as = &asstbl_paring_att[wk->player_number][kos].as;
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 1;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



s32 check_dm_shot_attack(PLW* wk) {
    s16 kos;
    if (wk->spmv_ng_flag & 0x2000) {
        return 0;
    }
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    setup_comm_back((WORK*)wk);
    wk->as = &asstbl_dm_att[wk->player_number][kos].as;
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



s32 check_chouhatsu(PLW* wk) {
    wk->permited_koa |= 0x80;
    if (wk->wu.xyz[1].disp.pos > 0) {
        return 0;
    }
    if (wk->cp->sw_lvbt & 0xF) {
        return 0;
    }
    if (wk->cp->ca36 == 0) {
        return 0;
    }
    wk->as = &asstbl_lv_E010[wk->player_number][0].as;
    setup_comm_back(&wk->wu);
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



s32 check_nagenuke_cmd(PLW* wk) {
    if (wk->cat_break_reserve) {
        return 1;
    }
    if (wk->cp->sw_lvbt & 3) {
        return 0;
    }
    if (wk->cp->sw_lvbt & 0xC) {
        if (wk->cp->sw_now & 0x660) {
            return 1;
        }
    }
    return 0;
}



s32 check_lever_up_attack(PLW* wk) {
    s16 kos;
    wk->permited_koa |= 8;
    if (wk->spmv_ng_flag & 0x4000) {
        return 0;
    }
    if (!(wk->cp->sw_new & 1)) {
        return 0;
    }
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    setup_comm_back((WORK*)wk);
    wk->as = &asstbl_lever_up_att[wk->player_number][kos].as;
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



/* an empty check */
s32 check_catch_attack(PLW* wk) {
    return 0;
}



void set_attack_routine_number(PLW* wk) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = wk->as->r_no;
    wk->wu.routine_no[3] = 0;
    wk->wu.cg_type = 0;
}



s32 get_nearing_range(pnum, kos)
s16 pnum;
s16 kos;
{
    u16 nrange;
    const u16* asstbl;
    u16 lwork;
    nrange = 0;
    if ((kos = shot_data_convert(kos)) < 0) {
        return 0;
    }
    asstbl = asstbl_lv_0000[pnum][kos];
    if ((lwork = asstbl[0] & 0x7FF)) {
        nrange = lwork;
    } else if ((lwork = asstbl[1] & 0x7FF)) {
        nrange = lwork;
    }
    return nrange;
}



s32 waza_select(wk, kos, sf)
PLW* wk;
s16 kos;
s16 sf;
{
    const u16* wst;
    switch (sf) {
    case 0:
        wst = asstbl_lv_0000[wk->player_number][kos];
        break;
    case 1:
        wst = asstbl_lv_1000[wk->player_number][kos];
        break;
    case 2:
        wst = asstbl_lv_2000[wk->player_number][kos];
        break;
    case 3:
        wst = asstbl_lv_3000[wk->player_number][kos];
        break;
    case 4:
        wst = asstbl_lv_4000[wk->player_number][kos];
        break;
    case 5:
        wst = asstbl_lv_5000[wk->player_number][kos];
        break;
    case 6:
        wst = asstbl_lv_6000[wk->player_number][kos];
        break;
    case 7:
        wst = asstbl_lv_7000[wk->player_number][kos];
        break;
    case 8:
        wst = asstbl_lv_8000[wk->player_number][kos];
        break;
    case 9:
        wst = asstbl_lv_9000[wk->player_number][kos];
        break;
    case 10:
        wst = asstbl_lv_10000[wk->player_number][kos];
        break;
    default:
        return 0;
    }
    if (decode_wst_data(wk, wst[0], wst[1])) {
        return 2;
    }
    if (decode_wst_data(wk, wst[1], wst[1])) {
        return 1;
    }
    return 0;
}



s32 decode_wst_data(wk, cmd, cmd_ex)
PLW* wk;
u16 cmd;
s16 cmd_ex;
{
    u16 lever;
    u16 rnum;
    if (cmd == 0) {
        return 0;
    }
    rnum = 0;
    lever = cmd & 0xF;
    switch (cmd & 0xF000) {
    case 0x4000:
        rnum = wk->cp->sw_new & lever;
        break;
    case 0x8000:
        rnum = (lever == (wk->cp->sw_new & 0xF));
        break;
    case 0x3000:
        rnum = cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex);
        break;
    case 0x7000:
        if (wk->cp->sw_new & lever) {
            if (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex)) {
                rnum = 1;
            }
        }
        break;
    case 0xB000:
        if ((lever == (wk->cp->sw_new & 0xF))) {
            if ((cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
                rnum = 1;
            }
        }
        break;
    case 0x2000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0x1000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0xA000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (lever == (wk->cp->sw_new & 0xF))) {
            if (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex)) {
                rnum = 1;
            }
        }
        break;
    case 0x9000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (lever == (wk->cp->sw_new & 0xF))) {
            if (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex)) {
                rnum = 1;
            }
        }
        break;
    case 0x6000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }
        break;
    case 0x5000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }
        break;
    default:
        if (get_em_body_range(&wk->wu) >= cmd) {
            rnum = 1;
        }
        break;
    }
    return rnum;
}



/* the nearest of two body boxes and the push box */
s32 get_em_body_range(WORK* wk) {
    WORK* em = (WORK*)wk->target_adrs;
    s16 r1;
    s16 r2;
    s16 r3;
    if (em->rl_flag) {
        r1 = em->xyz[0].disp.pos - em->h_bod->body_dm[1][0];
        r2 = em->xyz[0].disp.pos - em->h_bod->body_dm[2][0];
        r3 = em->xyz[0].disp.pos - em->h_hos->hos_box[0];
        if (em->rl_waza == 0) {
            r1 -= em->h_bod->body_dm[1][1];
            r2 -= em->h_bod->body_dm[2][1];
            r3 -= em->h_hos->hos_box[1];
        }
    } else {
        r1 = em->xyz[0].disp.pos + em->h_bod->body_dm[1][0];
        r2 = em->xyz[0].disp.pos + em->h_bod->body_dm[2][0];
        r3 = em->xyz[0].disp.pos + em->h_hos->hos_box[0];
        if (em->rl_waza) {
            r1 += em->h_bod->body_dm[1][1];
            r2 += em->h_bod->body_dm[2][1];
            r3 += em->h_hos->hos_box[1];
        }
    }
    r1 -= wk->xyz[0].disp.pos;
    r2 -= wk->xyz[0].disp.pos;
    r3 -= wk->xyz[0].disp.pos;
    if (r1 < 0) {
        r1 = -r1;
    }
    if (r2 < 0) {
        r2 = -r2;
    }
    if (r3 < 0) {
        r3 = -r3;
    }
    if (r1 > r2) {
        r1 = r2;
    }
    if (r1 > r3) {
        r1 = r3;
    }
    return r1;
}



s32 cmd_ex_check(px, cx)
s16 px;
s16 cx;
{
    if (cx) {
        if (cx < 0) {
            if (px + cx <= 0) {
                return 1;
            }
        } else if (px - cx >= 0) {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}



s32 shot_data_convert(sw)
s32 sw;
{
    s16 i;
    s16 rnum = -1;
    for (i = 0; i < 6; i++) {
        if ((u16)sw & shot_prio[i][0]) {
            rnum = shot_prio[i][1];
            sw *= 1;
        }
    }
    return rnum;
}



/* the attack for button strength sw (shot_refresh) */
s16 shot_data_refresh(s16 sw) {
    return shot_refresh[sw];
}



/* provisional name: the throw button strength from ca14/ca25/ca36; nothing calls it */
s32 get_catch_kos(PLW* wk) {
    s16 kos;
    if (wk->cp->calf == 0) {
        return -1;
    }
    kos = wk->cp->ca14 + wk->cp->ca25 * 2 + wk->cp->ca36 * 4;
    if (kos == 0) {
        return -1;
    }
    return catch_kos_table[kos] + ((wk->cp->sw_lvbt & 2) != 0) * 3;
}



s16 renbanshot_conpaneshot(dadr, pow)
const s16* dadr;
s16 pow;
{
    return rc_shot_conv[dadr[pow] & 0xF];
}



s32 datacmd_conpanecmd(dat)
s16 dat;
{
    s16 r;
    r = (dat & 0x700) >> 1 | dat & 0x7F;
    return r;
}



s32 check_renda_cancel(PLW* wk) {
    if (wk->wu.rl_flag != wk->wu.rl_waza) {
        return 0;
    }
    wk->permited_koa |= 32;
    if (wk->wu.pat_status == renda_status_table[(wk->cp->sw_new & 3)]) {
        if (wk->current_attack == (wk->cp->sw_now & 0x770)) {
            setup_comm_back((WORK*)wk);
            wk->wu.cg_ix = wk->wu.cg_eftype * wk->wu.cgd_type - (wk->wu.cgd_type * 2);
            wk->wu.cg_next_ix = 0;
            wk->wu.cg_ctr = 1;
            wk->wu.meoshi_hit_flag = 0;
            wk->wu.att_hit_ok = 0;
            wk->wu.hf.hit_flag = 0;
            wk->caution_flag = 1;
            wk->cancel_timer = 5;
            wk->wu.cg_cancel &= 0xE0;
            return 1;
        }
    }
    return 0;
}



s32 check_sp_waza_flag(PLW* wk) {
    s16 i;
    s16 rnum = 0;
    for (i = 20; i < 38; i++) {
        if (wk->cp->waza_flag[i]) {
            rnum = 1;
        }
    }
    return rnum;
}



s32 check_meoshi_cancel(PLW* wk) {
    s16 i;
    s16 tdat;
    s16 wdat;
    s32 t0;
    wk->permited_koa |= 0x10;
    if (wk->wu.meoshi_hit_flag == 0) {
        return 0;
    }
    t0 = (s16)(wk->wu.cg_meoshi & 0x8F) & 0x8F;
    if ((s16)t0 != 0) {
        wdat = cnmc_conv_data[wk->cp->sw_new & 0xF];
        t0 &= 0xF;
        if (wk->wu.cg_meoshi & 0x80) {
            for (i = 0; i < 6; i++) {
                if (cnmc_Z_lever_data[t0][i] == -1) {
                    return 0;
                }
                if (cnmc_Z_lever_data[t0][i] == wdat) {
                    goto matched;
                }
            }
        } else {
            for (i = 0; i < 8; i++) {
                if (cnmc_z_lever_data[(s16)t0][i] == -1) {
                    return 0;
                }
                if (cnmc_z_lever_data[(s16)t0][i] == wdat) {
                    goto matched;
                }
            }
        }
        return 0;
    }
matched:
    if ((tdat = wk->wu.cg_meoshi & 0x770) == 0) {
        if (!(wk->wu.cg_meoshi & 0x800)) {
            return 0;
        }
        goto cancel;
    }
    wdat = wk->cp->sw_new & 0x770;
    if (wdat & ~tdat) {
        return 0;
    }
    if (shot_data_convert(wk->cp->sw_now) < 0) {
        goto off;
    }
    if (wk->wu.cg_meoshi & 0x800) {
        goto cancel;
    }
    goto end;
off:
    if (!(wk->wu.cg_cancel & 0x80)) {
        return 0;
    }
    wdat = wk->cp->sw_off & 0x770;
    if (wdat & ~tdat) {
        return 0;
    }
    if (shot_data_convert(wk->cp->sw_off) < 0) {
        return 0;
    }
    if (!(wk->wu.cg_meoshi & 0x800)) {
        return 0;
    }
cancel:
    if (wk->wu.cg_meoshi & 0x1000) {
        if (char_move_cmms3(wk) == 0) {
            return 0;
        }
    } else {
        char_move_cmms2((WORK*)wk);
    }
    wk->wu.hf.hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.cg_cancel &= 0x60;
    return 1;
end:
    return check_nm_attack(wk);
}

s32 get_meoshi_lever(lever)
s16 lever;
{
    return gml_real_lever_data[lever & 0xF];
}

s32 get_meoshi_shot(shot)
s16 shot;
{
    return ((shot & 0x700) >> 1) + (shot & 0x70);
}
