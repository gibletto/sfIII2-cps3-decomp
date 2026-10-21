/*
 * EFF79.C  Effect 79: super art selection plates (2nd Impact only)
 *
 * 2nd Impact rewrote the 3rd Strike plates. effect_79_init (Setup_ID, Basic_Sub_Ex, Check_Auto_Cut) makes one plate per
 * player and art; Setup_Pos_79 slides it in from the screen edge (routine 1) to its slot in
 * eff79_plate_pos, and routine_no[7] keeps the state it takes after the delay. When Moving_Plate
 * asks, Setup_Move_79 sends the plates to their new slots (Move_79 with EFF79_Move_X / EFF79_Move_Y,
 * Check_Priority and eff79_char_move for the depth and the turning pattern). Select_End_Sub_79 sends
 * the chosen plate to its flash (routine 4) and the others out of the screen (routine 3).
 * The effect 80 and 81 marks follow the plate.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "Eff51.h"
#include "Eff80.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Eff79.h"

s32 effect_81_init(WORK_Other* oya, s16 PL_id, s16 Master_Player, s16 Priority, s16 Kind);

extern s16 Flash_Complete[2];

/* 2nd Impact table (CTBL 06179EA4): x, y of each plate slot by player; provisional name */
extern const s16 eff79_plate_pos[2][6];



void effect_79_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.disp_flag = 1;
        ewk->wu.routine_no[0] = ewk->wu.routine_no[7];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dm_vital + 1, 0);
        effect_80_init(ewk, ewk->master_id, ewk->master_player, ewk->master_priority & 0x7FFF, ewk->wu.routine_no[7]);
        effect_81_init(ewk, ewk->master_id, ewk->master_player, ewk->master_priority & 0x7FFF, ewk->wu.routine_no[7]);
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.dir_step <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.dir_step;
                ewk->wu.mvxy.a[0].sp = -0x17FFF7;
                Move_Super_Arts[ewk->master_id]--;
                Select_Arts[ewk->master_id]--;
                if (Flash_Complete[ewk->master_id] == -1 || plw[ewk->master_id].wu.operator == 0) {
                    ewk->wu.routine_no[0] = 8;
                }
                if (ewk->wu.vitality != 0) {
                    ewk->wu.routine_no[0] = 6;
                }
            }
        } else if (ewk->wu.dir_step >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.dir_step;
            ewk->wu.mvxy.a[0].sp = 0x17FFF7;
            Move_Super_Arts[ewk->master_id]--;
            Select_Arts[ewk->master_id]--;
            if (Flash_Complete[ewk->master_id] == -1 || plw[ewk->master_id].wu.operator == 0) {
                ewk->wu.routine_no[0] = 8;
            }
            if (ewk->wu.vitality != 0) {
                ewk->wu.routine_no[0] = 6;
            }
        }
        break;
    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (Moving_Plate[ewk->master_id]) {
            case 1:
                switch (ewk->wu.hit_quake) {
                case 0:
                    ewk->wu.dmcal_m = 1;
                    Setup_Move_79(ewk, 1, 1, 0xDB6D, 0x20000);
                    break;
                case 1:
                    ewk->wu.dmcal_m = 2;
                    Setup_Move_79(ewk, 2, 1, -0xDB6D, 0x20000);
                    break;
                default:
                    ewk->wu.dmcal_m = 0;
                    Setup_Move_79(ewk, 0, 2, 0, -0x40000);
                    break;
                }
                break;
            case 2:
                switch (ewk->wu.hit_quake) {
                case 0:
                    ewk->wu.dmcal_m = 2;
                    Setup_Move_79(ewk, 0, 1, 0, 0x40000);
                    break;
                case 1:
                    ewk->wu.dmcal_m = 0;
                    Setup_Move_79(ewk, 2, 2, -0xDB6D, -0x20000);
                    break;
                default:
                    ewk->wu.dmcal_m = 1;
                    Setup_Move_79(ewk, 1, 2, 0xDB6D, -0x20000);
                    break;
                }
                break;
            default:
                if (Select_End_Sub_79(ewk)) {
                    if (ewk->master_id) {
                        ewk->wu.mvxy.a[0].sp = 0x17FFF7;
                    } else {
                        ewk->wu.mvxy.a[0].sp = -0x17FFF7;
                    }
                }
                break;
            }
            break;
        case 1:
            Move_79(ewk);
            break;
        }
        break;
    case 3:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        if (Ck_Range_Out_S(ewk, 2, 0x80)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 8;
        }
        break;
    case 4:
        if (Flash_Violent(ewk, 1)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 10;
            Sel_Arts_Complete[ewk->master_id] |= 0x8000;
        }
        if (ewk->wu.vitality) {
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dm_vital + 1, 0);
        }
        break;
    case 5:
        if (--ewk->wu.dir_timer) {
            break;
        }
        ewk->wu.routine_no[0] = 3;
        break;
    case 6:
        break;
    case 7:
        if (Suicide) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 8;
            return;
        }
        break;
    case 8:
        ewk->wu.routine_no[0]++;
        return;
    default:
        ewk->wu.disp_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    PP_Priority[ewk->master_id][ewk->master_player] = ewk->wu.dmcal_m;
    sort_push_request4(&ewk->wu);
}



void Move_79(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[2]++;
        }
        break;
    case 1:
        EFF79_Move_X(ewk);
        Check_Priority(ewk);
        if (EFF79_Move_Y(ewk)) {
            ewk->wu.routine_no[2]++;
            ewk->wu.hit_quake = ewk->wu.dmcal_m;
            Moving_Plate_Counter[ewk->master_id]--;
            ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.dmcal_m] + 35;
        }
        break;
    default:
        if (Moving_Plate_Counter[ewk->master_id] == 0) {
            ewk->wu.routine_no[1] = 0;
            Moving_Plate[ewk->master_id] = 0;
        }
        break;
    }
    eff79_char_move(ewk);
}



void Check_Priority(WORK_Other* ewk) {
    if (ewk->wu.routine_no[3] == 1 && ewk->wu.cg_type == 4) {
        ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.dmcal_m] + 34;
    }
}



/* provisional name */
void eff79_char_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[3]) {
    case 0:
        break;
    case 1:
        if (ewk->wu.cg_type != 8) {
            char_move(&ewk->wu);
        }
        break;
    case 2:
        if (ewk->wu.cg_type != 0) {
            char_move(&ewk->wu);
        }
        break;
    }
}



void Setup_Move_79(ewk, move_type, _p1, X_Value, Y_Value)
WORK_Other* ewk;
s16 move_type;
s32 _p1;
s32 X_Value;
s32 Y_Value;
{
    s16 ofs;
    if (ewk->master_id == 0) {
        ofs = DE_X[6];
    } else {
        ofs = DE_X[5] - DE_X[6];
        X_Value = -X_Value;
    }
    ewk->wu.mvxy.a[0].sp = X_Value;
    ewk->wu.routine_no[1] = 1;
    ewk->wu.routine_no[2] = 0;
    ewk->wu.routine_no[3] = move_type;
    ewk->wu.routine_no[4] = 0;
    ewk->wu.dir_timer = 1;
    ewk->wu.dir_step = ofs + eff79_plate_pos[ewk->master_id][ewk->wu.dmcal_m * 2];
    ewk->wu.direction = eff79_plate_pos[ewk->master_id][ewk->wu.dmcal_m * 2 + 1];
    ewk->wu.mvxy.a[1].sp = Y_Value;
    ewk->wu.mvxy.d[1].sp = 0;
    if (Moving_Plate[ewk->master_id] == 1 && move_type == 1) {
        ewk->wu.xyz[2].disp.pos -= 7;
    }
}



void EFF79_Move_X(WORK_Other* ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    if (0 > ewk->wu.mvxy.a[0].sp) {
        if (ewk->wu.dir_step >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = ewk->wu.dir_step;
        }
    } else if (ewk->wu.dir_step <= ewk->wu.xyz[0].disp.pos) {
        ewk->wu.xyz[0].disp.pos = ewk->wu.dir_step;
    }
}



s32 EFF79_Move_Y(WORK_Other* ewk) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
    if (0 > ewk->wu.mvxy.a[1].sp) {
        if (ewk->wu.direction >= ewk->wu.xyz[1].disp.pos) {
            ewk->wu.xyz[1].disp.pos = ewk->wu.direction;
            return 1;
        }
    } else if (ewk->wu.direction <= ewk->wu.xyz[1].disp.pos) {
        ewk->wu.xyz[1].disp.pos = ewk->wu.direction;
        return 1;
    }
    return 0;
}



/* provisional name: no caller */
void eff79_set_position(WORK_Other* ewk, s16 flag) {
    if (flag) {
        ewk->wu.xyz[0].disp.pos = eff79_plate_pos[ewk->master_id][0] + DE_X[5];
    } else {
        ewk->wu.xyz[0].disp.pos = eff79_plate_pos[ewk->master_id][0];
    }
    ewk->wu.xyz[1].disp.pos = 16;
    ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.dmcal_m] + 35;
}



s32 Select_End_Sub_79(WORK_Other* ewk) {
    if (Sel_Arts_Complete[ewk->master_id] == 0) {
        return 0;
    }
    if (Super_Arts[ewk->master_id] == ewk->master_player) {
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[2] = 1;
        ewk->wu.routine_no[3] = 8;
        ewk->wu.routine_no[4] = 32;
        ewk->wu.vitality = 0;
        ewk->wu.vital_new = 0;
        ewk->wu.vital_old = 0;
        ewk->wu.dm_vital = 8;
    } else {
        ewk->wu.routine_no[0]++;
    }
    return 1;
}



s32 effect_79_init(s16 pl_id, s16 plate_id, s16 pos_id, s16 time, s16 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->master_player = plate_id;
    ewk->master_priority = pos_id;
    ewk->wu.hit_quake = pos_id;
    ewk->wu.dmcal_m = pos_id;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 79;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ((WORK*)3)->id;
    ewk->wu.dir_timer = time;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = pl_id;
    ewk->wu.char_index = plate_id + pl_id * 3 + 16;
    ewk->wu.vitality = type;
    if (pos_id == 1 || type) {
        ewk->wu.dm_vital = 8;
    } else {
        ewk->wu.dm_vital = 0;
    }
    Setup_Pos_79(ewk);
    return 0;
}



void Setup_Pos_79(WORK_Other* ewk) {
    s16 pos;
    ewk->wu.routine_no[7] = 1;
    if (ewk->wu.vitality != 0) {
        pos = 2;
        ewk->wu.xyz[1].disp.pos = 40;
        ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[1] + 35;
    } else {
        pos = ewk->master_priority;
        ewk->wu.xyz[1].disp.pos = eff79_plate_pos[ewk->master_id][pos * 2 + 1];
        ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[pos] + 35;
    }
    if (ewk->master_id) {
        ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x400;
        ewk->wu.mvxy.a[0].sp = -0x14FFFA;
        ewk->wu.mvxy.d[0].sp = -0x8000;
        ewk->wu.dir_step = eff79_plate_pos[ewk->master_id][pos * 2] + DE_X[5] - DE_X[6];
    } else {
        ewk->wu.xyz[0].disp.pos = 0x1A0;
        ewk->wu.mvxy.a[0].sp = 0x14FFFA;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        ewk->wu.dir_step = eff79_plate_pos[ewk->master_id][pos * 2] + DE_X[6];
    }
    if (ewk->wu.vitality == 2) {
        ewk->wu.routine_no[7] = 6;
        ewk->wu.xyz[0].disp.pos = ewk->wu.dir_step;
    }
    if (ewk->wu.vitality == 3) {
        ewk->wu.routine_no[7] = 7;
        ewk->wu.xyz[0].disp.pos = ewk->wu.dir_step;
    }
}
