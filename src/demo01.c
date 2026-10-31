/*
 * DEMO01.C  Attract mode: title
 *
 * Title and Title_At_a_Dash run the title sequence and opening.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Game_Main.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "Entry.h"
#include "entry_2.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
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
#include "cmb_win.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "eeprom.h"
#include "sc_trans.h"
#include "bg000.h"
#include "EM_Cand.h"
#include "Grade.h"
#include "lose_pl.h"
#include "PLS02.h"
#include "SLOWF.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "demo01.h"

/* D_No1 in Title */
#define TT_INIT         0       /* set up */
#define TT_COLOR        1       /* load the characters' colours */
#define TT_DEMO         2       /* the opening demo */
#define TT_HOLD         3       /* wait D_Timer, then wipe */
#define TT_WIPE         4       /* until the wipe is done */

/* D_No1 in Title_At_a_Dash */
#define TD_INIT         0       /* set up */
#define TD_DEMO         1       /* the opening demo, then wait D_Timer */



/* Uses palettes 130, 2 and 1. */
s32 Title(void) {
    switch (D_No1) {
    case TT_INIT:
        D_No1++;
        D_Timer = 10;
        wipe_pattern_set(0, 7, 0);
        tilemap_fill_all(0, 32);
        load_any_color(130);
        load_any_color(2);
        load_any_color(1);
        Text_Page_Y = 32;
        Scrn_Move_Set(4, 0, 0x100);
        E_No1 = 1;
        op_w.r_no_0 = 0;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        op_w.index = 0;
        op_work_clear();
        Get_Demo_Index = 0;
        break;
    case TT_COLOR:
        D_No1++;
        load_char_eff_color(My_char[0], 0);
        load_char_eff_color(My_char[1], 1);
        break;
    case TT_DEMO:
        set_EXE_flag();
        if (opening_demo_tick()) {
            D_No1++;
            D_Timer = 40;
        }
        break;
    case TT_HOLD:
        if (--D_Timer == 0) {
            D_No1++;
            sc_vram_to_ram();
            Switch_Screen_Init(0, 1);
        }
        break;
    case TT_WIPE:
        if (Switch_Screen()) {
            D_No1++;
            Cover_Timer = 22;
            Scrn_Move_Set(4, 0, 0);
        }
        break;
    default:
        return 1;
    }
    return 0;
}



/* Uses palettes 130 and 2. */
s32 Title_At_a_Dash(void) {
    switch (D_No1) {
    case TD_INIT:
        D_No1++;
        Scrn_Move_Set(4, 0, 0);
        System_all_clear_Wait();
        load_any_color(130);
        load_any_color(2);
        op_w.r_no_0 = 2;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        op_w.index = 0;
        op_work_clear();
        break;
    case TD_DEMO:
        if (opening_demo_tick()) {
            D_No1++;
            D_Timer = 20;
            credit_display_render(1);
            Disp_Start_Message();
        }
        break;
    default:
        if (--D_Timer == 0) {
            ToneDown(0);
            return 1;
        }
        break;
    }
    return 0;
}
