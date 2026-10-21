/*
 * EFF84.C  Effect 84: centre-screen message controller
 *
 * Effect 84 is created by the game manager (Game_Manage_2_2 / Game_Manage_12_0 in Manage.c) and
 * waits for request_message. When a message is requested it pauses the game, draws the message
 * picture for message_index with sc_picture_put and starts effect 89 over it; some kinds wait
 * until the combo score display (cmb_all_stock / cmb_calc_now) has finished. After the time from
 * Time_Data it clears the message area (eff84_message_clear), requests the dead voice, clears
 * request_message and resumes play. Messages are requested through request_center_message.
 * The effect dies when Suicide is set.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "sc_clear.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "PLSGAUGE.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF84.h"



void effect_84_move(WORK_Other* ewk) {
    if (Suicide) {
        push_effect_work(&ewk->wu);
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (request_message) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = Time_Data[request_message];
        }
        break;
    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (message_index) {
            case 0:
                Game_pause = -1;
                ewk->wu.routine_no[1]++;
                sc_picture_put(0, 0, 0);
                effect_89_init(0, DE_X[3] + 14, 9, 18, 8);
                break;
            case 1:
                Game_pause = -1;
                if (cmb_all_stock == 0) {
                    ewk->wu.routine_no[1]++;
                    sc_picture_put(1, 0, 0);
                    effect_89_init(1, DE_X[3] + 12, 9, 23, 4);
                }
                break;
            case 2:
                Game_pause = -1;
                ewk->wu.routine_no[1]++;
                sc_picture_put(2, 0, 0);
                effect_89_init(3, DE_X[3] + 12, 9, 23, 4);
                break;
            case 3:
                if (cmb_all_stock == 0 && cmb_calc_now[0] == 0 && cmb_calc_now[1] == 0) {
                    ewk->wu.routine_no[1]++;
                    sc_picture_put(3, 0, 0);
                    effect_89_init(3, DE_X[3] + 9, 8, 30, 6);
                }
                break;
            case 4:
            default:
                ewk->wu.routine_no[1]++;
                sc_picture_put(4, 0, 0);
                effect_89_init(1, DE_X[3] + 12, 9, 24, 4);
                break;
            }
            break;
        case 1:
            if ((ewk->wu.dir_timer -= 1) != 0) {
                break;
            } else {
                eff84_message_clear();
                dead_voice_request();
                request_message = 0;
                Game_pause = 0;
                ewk->wu.routine_no[0] = ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        break;
    case 2:
        break;
    }
}



/* provisional name */
void eff84_message_clear(void) {
    switch (message_index) {
    case 0:
        tilemap_clear_rect(DE_X[3] + 14, 9, DE_X[3] + 32, 17);
        break;
    case 1:
        tilemap_clear_rect(DE_X[3] + 12, 9, DE_X[3] + 35, 13);
        break;
    case 2:
        tilemap_clear_rect(DE_X[3] + 12, 9, DE_X[3] + 35, 13);
        break;
    case 3:
        tilemap_clear_rect(DE_X[3] + 8, 8, DE_X[3] + 40, 14);
        break;
    default:
        tilemap_clear_rect(DE_X[3] + 12, 9, DE_X[3] + 35, 13);
        break;
    }
}



s32 effect_84_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 84;
    return 0;
}
