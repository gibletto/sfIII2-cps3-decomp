/*
 * EffD8.C  Effect D8: the player's face cursor on the character select screen
 *
 * effect_D8_entry (from the select screen, one per player) makes the cursor unless the player
 * already stands on face 14 (effD8_face_check). effect_D8_move waits for Appear_Cursor, follows
 * the player's Cursor_X / Cursor_Y over the ID_of_Face grid (effect_D8_init places it from
 * Face_Pos_Data), and when Sel_PL_Complete is set plays the chosen pattern, then marks the choice
 * done and starts the select timer. effD8_char_set picks the pattern for the face under the cursor,
 * effD8_same_face shows the second player's alternate pattern when both stand on the same face, and
 * effD8_colour_step (no caller) steps the cursor colour through old_rno[0..3].
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EffD8.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait for the cursor to appear */
#define R0_SELECT       1       /* follow the cursor */
#define R0_DECIDE       2       /* play the chosen pattern, then hide */
#define R0_END          3       /* one more frame */
#define R0_KILL         4       /* (default) put the work back */

extern const u8 effD8_char_tbl[3][2];   /* provisional name */

void effD8_char_set(WORK_Other* ewk);
void effD8_same_face(WORK_Other* ewk);
s32 effD8_face_check(s16 PL_id);



void effect_D8_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (Appear_Cursor == 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_SELECT:
        if (ewk->wu.dir_step != Cursor_X[ewk->master_id] || ewk->wu.dir_old != Cursor_Y[ewk->master_id]) {
            ewk->wu.dir_step = Cursor_X[ewk->master_id];
            ewk->wu.dir_old = Cursor_Y[ewk->master_id];
            effect_D8_init(ewk);
            effD8_char_set(ewk);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.cg_ix / ewk->wu.cgd_type) + 1, 0);
        }
        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 20;
            effD8_char_set(ewk);
            ewk->wu.char_index += 6;
            effD8_same_face(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        } else {
            effD8_same_face(ewk);
            char_move(&ewk->wu);
        }
        break;
    case R0_DECIDE:
        if (--ewk->wu.dir_timer) {
            char_move(&ewk->wu);
        } else {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            Sel_PL_Complete[ewk->master_id] = -0x8000;
            if (Select_Start[ewk->master_id] == 0) {
                Select_Timer = 32;
            }
            Unit_Of_Timer = 50;
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



/* provisional name */
s32 effect_D8_entry(s16 PL_id) {
    s16 ix;
    WORK_Other* ewk;
    if (effD8_face_check(PL_id)) {
        return 0;
    }
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8A;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 2;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.old_rno[0] = 0;
    ewk->wu.old_rno[1] = 1;
    ewk->wu.old_rno[2] = 2;
    ewk->wu.old_rno[3] = 15;
    ewk->wu.vital_old = 0;
    ewk->wu.vitality = 6;
    ewk->master_id = PL_id;
    ewk->wu.dir_step = Cursor_X[ewk->master_id];
    ewk->wu.dir_old = Cursor_Y[ewk->master_id];
    ewk->wu.position_z = 56;
    effD8_char_set(ewk);
    effect_D8_init(ewk);
    return 0;
}



/* the pattern for the face under the cursor */
/* provisional name */
void effD8_char_set(WORK_Other* ewk) {
    if (Cursor_X[ewk->master_id] == 6 && Cursor_Y[ewk->master_id] == 1) {
        ewk->wu.char_index = effD8_char_tbl[ewk->master_id][1];
    } else {
        ewk->wu.char_index = effD8_char_tbl[ewk->master_id][Cursor_X[ewk->master_id] & 1];
    }
}



/* the second player's alternate pattern on the first player's face */
/* provisional name */
void effD8_same_face(WORK_Other* ewk) {
    s16 face;
    s16 face2;
    if (ewk->master_id != 1) {
        return;
    }
    if (plw[0].wu.operator == 0) {
        return;
    }
    if (Cursor_Move[0] == 0 && Cursor_Move[1] == 0) {
        return;
    }
    if (Sel_PL_Complete[0] < 0) {
        return;
    }
    face = ID_of_Face[Cursor_Y[0]][Cursor_X[0]];
    face2 = ID_of_Face[Cursor_Y[1]][Cursor_X[1]];
    if (face == face2) {
        if (Cursor_X[ewk->master_id] == 6 && Cursor_Y[ewk->master_id] == 1) {
            ewk->wu.char_index = effD8_char_tbl[2][1];
        } else {
            ewk->wu.char_index = effD8_char_tbl[2][Cursor_X[ewk->master_id] & 1];
        }
        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.char_index += 6;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.cg_ix / ewk->wu.cgd_type) + 1, 0);
    } else if (ewk->wu.char_index == 67 || ewk->wu.char_index == 68) {
        effD8_char_set(ewk);
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.cg_ix / ewk->wu.cgd_type) + 1, 0);
    }
}



/* one argument, X from DE_X[10] */
void effect_D8_init(WORK_Other* ewk) {
    s16 xx = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    ewk->wu.xyz[0].disp.pos = Face_Pos_Data[xx][SEL_POS_X] + DE_X[10] + 0x1C1;
    ewk->wu.xyz[1].disp.pos = Face_Pos_Data[xx][SEL_POS_Y];
}



/* (no caller): steps the cursor colour */
/* provisional name */
void effD8_colour_step(WORK_Other* ewk, s16 num, s16 time) {
    if (--ewk->wu.vitality == 0) {
        if (++ewk->wu.vital_old >= num) {
            ewk->wu.vital_old = 0;
        }
        ewk->wu.vitality = time;
        ewk->wu.my_col_code = ewk->wu.old_rno[ewk->wu.vital_old] + 0x2040;
        effD8_char_set(ewk);
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.cg_ix / ewk->wu.cgd_type) + 1, 0);
    }
}



/* a player standing on face 14 gets no cursor and is moved to the corner */
/* provisional name */
s32 effD8_face_check(s16 PL_id) {
    if (Game_setting.Bonus_Game & 2) {
        return 0;
    }
    if (ID_of_Face[Cursor_Y[PL_id]][Cursor_X[PL_id]] != 14) {
        return 0;
    }
    if (Sel_PL_Complete[PL_id]) {
        return 1;
    }
    if (PL_id) {
        Cursor_X[PL_id] = 12;
    } else {
        Cursor_X[PL_id] = 0;
    }
    return Cursor_Y[PL_id] = 0;
}
