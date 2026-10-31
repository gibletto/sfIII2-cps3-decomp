/*
 * EFFE0.C  Effect E0 (140): the stage plates on the opponent select screen
 *
 * effect_E0_init makes eight plates, one per entry of the player's EM_Candidate list (pattern 16 +
 * stage, or 32 where Break_Com marks none). They slide in from both sides with a stagger
 * (effE0_delay_tbl), and Cut_Cut_Cut skips the slide (effE0_arrive). The plate the player's
 * VS_Index points at closes and reopens with the stage picture; when effE0_go is set all plates
 * slide out.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EffE0.h"

/* routine_no[0] */
#define R0_DELAY        0       /* wait the stagger */
#define R0_IN_L         1       /* slide in leftwards */
#define R0_IN_R         2       /* slide in rightwards */
#define R0_STOP         3       /* pause, then pick the plate */
#define R0_CLOSE        4       /* close the plate */
#define R0_OPEN         5       /* reopen with the stage */
#define R0_SHOW         6       /* show it for 40 frames */
#define R0_OUT          7       /* slide out once all are done */
#define R0_END          8       /* one more frame */
#define R0_KILL         9       /* (default) put the work back */

extern s8 effE0_go;                     /* provisional name */
extern const s16 effE0_x_tbl[8];        /* provisional name */
extern const s16 effE0_delay_tbl[8];    /* provisional name */



void effect_E0_move(WORK_Other* ewk) {
    if (Suicide) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = R0_END;
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_DELAY:
        if (Cut_Cut_Cut()) {
            effE0_arrive(ewk, 0);
        } else {
            if (--ewk->wu.dir_timer != 0) {
                return;
            }
            if (ewk->wu.mvxy.a[0].sp < 0) {
                ewk->wu.routine_no[0] = R0_IN_L;
            } else {
                ewk->wu.routine_no[0] = R0_IN_R;
            }
        }
        ewk->wu.disp_flag = 1;
        ewk->wu.dir_timer = 5;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case R0_IN_L:
        if (Cut_Cut_Cut()) {
            effE0_arrive(ewk, 1);
            break;
        }
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.vital_new >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = R0_STOP;
            ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }
        break;
    case R0_IN_R:
        if (Cut_Cut_Cut()) {
            effE0_arrive(ewk, 2);
            break;
        }
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.vital_new <= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }
        break;
    case R0_STOP:
        if (--ewk->wu.dir_timer == 0) {
            if (VS_Index[Player_id] != ewk->master_id) {
                ewk->wu.routine_no[0] = R0_OUT;
            } else {
                ewk->wu.routine_no[0]++;
            }
        }
        break;
    case R0_CLOSE:
        if ((ewk->wu.my_mr.size.x -= 6) > 0) {
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.my_mr.size.x = 0;
        ewk->wu.dir_step = EM_Candidate[Player_id][VS_Index[Player_id]];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case R0_OPEN:
        if ((ewk->wu.my_mr.size.x += 6) < 63) {
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.dir_timer = 40;
        ewk->wu.my_mr.size.x = 63;
        break;
    case R0_SHOW:
        if (--ewk->wu.dir_timer) {
            break;
        }
        ewk->wu.routine_no[0]++;
        effE0_go = 1;
        /* fall through */
    case R0_OUT:
        if (effE0_go != 0) {
            ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
            if (Ck_Range_Out_S(ewk, 2, 32)) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
                return;
            }
        }
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



/* the plate stops at its place at once */
/* provisional name */
void effE0_arrive(ewk, sw)
WORK_Other* ewk;
s16 sw;
{
    ewk->wu.routine_no[0] = R0_STOP;
    ewk->wu.dir_timer = 1;
    ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
    if (sw == 0) {
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    }
}



s32 effect_E0_init(s16 Type) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 work[8];
    s8* cand;
    const s16* delay;
    effE0_go = 0;
    cand = (s8*)EM_Candidate[Player_id];
    for (i = 0; i <= 7; i++) {
        if (Break_Com[Player_id][cand[i]]) {
            work[i] = cand[i] + 16;
        } else {
            work[i] = 32;
        }
    }
    i = 0;
    delay = effE0_delay_tbl;
    while (i <= 7) {
        ix = pull_effect_work(4);
        if (ix == -1) {
            return -1;
        }
        ewk = (WORK_Other*)((u32)frw + (ix << 11));
        ewk->wu.be_flag = 1;
        ewk->wu.id = 140;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.my_family = 3;
        ewk->wu.position_z = 7;
        ewk->wu.char_index = 5;
        ewk->wu.dir_step = work[i];
        ewk->wu.char_table[0] = sel_pl_char_table;
        ewk->master_id = i;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        ewk->wu.dir_timer = delay[i];
        if (work[i] == 32) {
        }
        ewk->wu.xyz[1].disp.pos = 35;
        ewk->wu.vital_new = effE0_x_tbl[i] + DE_X[10] + 0x2C0;
        if (i >= 4) {
            ewk->wu.xyz[0].disp.pos = 0x1C0;
            ewk->wu.mvxy.a[0].sp = 0x140000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        } else {
            ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x3C0;
            ewk->wu.mvxy.a[0].sp = -0x140000;
            ewk->wu.mvxy.d[0].sp = -0x8000;
        }
        i++;
    }
    return 0;
}
