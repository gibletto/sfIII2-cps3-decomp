/*
 * GAME_CONFIG_EN.C  Test-mode game configuration, English page
 *
 * game_config_menu_en runs the GAME CONFIGURATION page shown outside Japan: the same items as the
 * Japanese page, printed with the system font, with lever repeat and star gauges.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "Com_Pl.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "CALDIR.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF00.h"
#include "EFF02.h"
#include "EFFK5.h"
void palette_write(s32 offset, const u16 *src, s32 count);
void palette_bank_set(s32 offset);
void tilemap_fill_all(u16 attr, u16 code);
void tilemap_print_string();
void tilemap_chunk_copy_16b(s16 *dst, char *src, s32 chunks);
#include "textsound_2.h"
#include "textsound_3.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "fifo.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg000.h"
#include "HITCHECK.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "cmd_main_2.h"
#include "CMD_MAIN.h"
#include "cps3.h"

extern const char str_NORMAL_2[];
extern const s8 str_WIDE[];
extern const s8 str_1_ROUND[];
extern const s8 str_3_ROUNDS[];
extern const s8 str_5_ROUNDS[];
extern const s8 str_7_ROUNDS[];
extern const s8 str_OFF[];
extern const s8 str_1_MATCH[];
extern const s8 str_OFF_2[];
extern const char str_ON[];

s8 Config_Item_en;  
s8 Config_Exit_en;  /* 02015A1D */
s8 Config_Move_en;  /* 02015A1E */
s8 Config_Old_en;  /* 02015A1F */
s8 Config_New_en;  /* 02015A20 */
s8 Config_Org_en;  /* 02015A21 */
s16 Config_Attr_en;  /* 02015A22 */
s16 Config_Rep_Timer_en[4];  /* 02015A24 */
s8 Config_Rep_Count_en[4];  /* 02015A2C */
s16* Config_Code_Ptr_en;  /* 02015A30, provisional name */
s16 Config_Code_No_en;  /* 02015A34, provisional name */


/* 020008AC */
/* the menu button code (item, button), as in game_config_jp.c */
s16 gcfg_code_list_en[13][2] = {
    { 3, 0x1000 }, { 3, 0x1000 }, { 3, 0x1000 }, { 5, 0x0100 }, { 5, 0x0100 }, { 0, 0x0200 }, { 0, 0x0200 },
    { 0, 0x0200 }, { 6, 0x1000 }, { 2, 0x0080 }, { 2, 0x0080 }, { 2, 0x0080 }, { 2, 0x0080 },
};
TM_STRING gcfg_screen_str_en[2] = {
    { 2, 0, 2, (void*)str_NORMAL_2 },
    { 2, 0, 2, str_WIDE },
};
/* 020008C4 */
TM_STRING gcfg_round_str_en[4] = {
    { 2, 0, 2, str_1_ROUND },
    { 2, 0, 2, str_3_ROUNDS },
    { 2, 0, 2, str_5_ROUNDS },
    { 2, 0, 2, str_7_ROUNDS },
};
/* 020008F4 */
TM_STRING gcfg_event_str_en[2] = {
    { 2, 0, 2, str_OFF },
    { 2, 0, 2, str_1_MATCH },
};
/* 0200090C */
TM_STRING gcfg_bonus_str_en[2] = {
    { 2, 0, 2, str_OFF_2 },
    { 2, 0, 2, (void*)str_ON },
};


/* provisional name */
s32 game_config_menu_en(void) {
    void (*tbl[2])(void) = { game_config_init_en, game_config_move_en };

    tbl[Config_No_2]();
    if (Config_Exit_en) {
        return 1;
    }
    return 0;
}


/* provisional name */
void game_config_init_en(void) {
    Config_No_2++;
    Config_Exit_en = 0;
    Config_Code_Ptr_en = gcfg_code_list_en[0];
    Config_Code_No_en = 0;
    init_render_lists();
    palette_bank_set(0);
    palette_write(0, sys_palette, 0x80);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)sys_font_cg, 0x8C);
    tilemap_fill_all(0, 32);
    tilemap_print_string(0, 0, 0xFFFF, config_title_str_tbl);
    Config_Item_en = 6;
    Config_New_en = game_config_work.bonus & 1;
    Config_Old_en = Game_setting.bonus & 1;
    Config_Attr_en = (Config_New_en != Config_Old_en) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_bonus_str_en[Config_New_en]);
    Config_Item_en = 5;
    Config_New_en = game_config_work.set5;
    Config_Attr_en = (Config_New_en != Game_setting.set5) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_event_str_en[Config_New_en]);
    Config_Item_en = 4;
    Config_New_en = game_config_work.set4;
    Config_Attr_en = (Config_New_en != Game_setting.set4) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_round_str_en[Config_New_en]);
    Config_Item_en = 3;
    Config_New_en = game_config_work.set3;
    Config_Attr_en = (Config_New_en != Game_setting.set3) ? 8 : 2;
    game_config_print_gauge_en(Config_New_en, 0xFFFF, Config_Attr_en);
    Config_Item_en = 2;
    Config_New_en = game_config_work.set2;
    Config_Attr_en = (Config_New_en != Game_setting.set2) ? 8 : 2;
    game_config_print_gauge_en(Config_New_en, 0xFFFF, Config_Attr_en);
    Config_Item_en = 1;
    Config_New_en = game_config_work.level;
    Config_Attr_en = (Config_New_en != Game_setting.level) ? 8 : 2;
    game_config_print_gauge_en(Config_New_en, 0xFFFF, Config_Attr_en);
    Config_Item_en = 0;
    Config_New_en = game_config_work.mode;
    Config_Attr_en = (Config_New_en != Game_setting.mode) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_screen_str_en[Config_New_en]);
    game_config_draw_cursor_en(62);
}


/* provisional name */
void game_config_move_en(void) {
    void (*Page_Tbl[8])() = { game_config_screen_item_en, game_config_level_item_en, game_config_damage_item_en, game_config_timer_item_en, game_config_1p_round_item_en, game_config_event_item_en, game_config_bonus_item_en, game_config_exit_item_en };
    void (*Page_Tbl_Old[6])() = { game_config_level_item_en, game_config_damage_item_en, game_config_timer_item_en, game_config_1p_round_item_en, game_config_event_item_en, game_config_exit_item_en };
    game_config_cursor_move_en();
    Page_Tbl[Config_Item_en]();
    game_config_draw_cursor_en(62);
    if (Config_Item_en == 7) {
        tilemap_print_string(0, 0, 0xFFFF, config_help_return_str_tbl);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, config_help_modify_str_tbl);
    }
    game_config_code_check_en();
}


/* provisional name */
void game_config_screen_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.mode += Config_Move_en;
        game_config_work.mode &= 1;
        Config_New_en = game_config_work.mode;
        if (game_config_work.mode) {
            set_screen_mode(7);
        } else {
            set_screen_mode(3);
        }
        screen_flip_offsets_set();
        Config_Attr_en = (Config_New_en != Game_setting.mode) ? 8 : 2;
        game_config_print_value_en(Config_Attr_en, &gcfg_screen_str_en[Config_New_en]);
    }
}


/* provisional name */
void game_config_level_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = game_config_work.level;
        game_config_work.level += Config_Move_en;
        if (game_config_work.level < 0) {
            game_config_work.level = 7;
        }
        if (game_config_work.level > 7) {
            game_config_work.level = 0;
        }
        Config_New_en = game_config_work.level;
        Config_Attr_en = Config_New_en != Game_setting.level ? 8 : 2;
        game_config_print_gauge_en(Config_New_en, Config_Old_en, Config_Attr_en);
    }
}


/* provisional name */
void game_config_damage_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = game_config_work.set2;
        game_config_work.set2 += Config_Move_en;
        game_config_work.set2 &= 3;
        Config_New_en = game_config_work.set2;
        Config_Attr_en = Config_New_en != Game_setting.set2 ? 8 : 2;
        game_config_print_gauge_en(Config_New_en, Config_Old_en, Config_Attr_en);
    }
}


/* provisional name */
void game_config_timer_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = game_config_work.set3;
        game_config_work.set3 += Config_Move_en;
        game_config_work.set3 &= 3;
        Config_New_en = game_config_work.set3;
        Config_Attr_en = Config_New_en != Game_setting.set3 ? 8 : 2;
        game_config_print_gauge_en(Config_New_en, Config_Old_en, Config_Attr_en);
    }
}


/* provisional name */
/* provisional name */
void game_config_1p_round_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.set4 += Config_Move_en;
        game_config_work.set4 &= 3;
        Config_New_en = game_config_work.set4;
        Config_Attr_en = (Config_New_en != Game_setting.set4) ? 8 : 2;
        game_config_print_value_en(Config_Attr_en, &gcfg_round_str_en[Config_New_en]);
    }
}


void game_config_event_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.set5 += Config_Move_en;
        game_config_work.set5 &= 1;
        Config_New_en = game_config_work.set5;
        Config_Attr_en = (Config_New_en != Game_setting.set5) ? 8 : 2;
        game_config_print_value_en(Config_Attr_en, &gcfg_event_str_en[Config_New_en]);
    }
}


/* provisional name */


void game_config_bonus_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.bonus ^= 1;
        game_config_work.bonus &= 3;
        Config_New_en = game_config_work.bonus & 1;
        Config_Old_en = Game_setting.bonus & 1;
        Config_Attr_en = (Config_New_en != Config_Old_en) ? 8 : 2;
        game_config_print_value_en(Config_Attr_en, &gcfg_bonus_str_en[Config_New_en]);
    }
}


/* provisional name */
void game_config_exit_item_en(void) {
    if ((~p1sw_1 & p1sw_0) & BUTTON_LP) {
        Config_Exit_en = 1;
    }
}


/* provisional name */
s8 game_config_lever_repeat_en(u16 sw, s16 ix) {
    if (~p1sw_1 & p1sw_0 & sw) {
        return 1;
    }
    if (p1sw_0 & sw) {
        Config_Rep_Timer_en[ix]++;
        if (Config_Rep_Timer_en[ix] > 10) {
            Config_Rep_Count_en[ix]++;
            if (Config_Rep_Count_en[ix] > 8) {
                Config_Rep_Count_en[ix] = 0;
                return 1;
            }
        }
    } else {
        Config_Rep_Timer_en[ix] = 0;
        Config_Rep_Count_en[ix] = 0;
    }
    return 0;
}


/* provisional name */
void game_config_cursor_move_en(void) {
    game_config_draw_cursor_en(32);
    if (game_config_lever_repeat_en(1, 0)) {
        Config_Item_en--;
        if (Config_Item_en < 0) {
            Config_Item_en = 7;
        }
    } else if (game_config_lever_repeat_en(2, 1)) {
        Config_Item_en++;
        if (Config_Item_en > 7) {
            Config_Item_en = 0;
        }
    }
}


/* provisional name */
void game_config_draw_cursor_en(s16 code) {
    s32 y;

    y = Config_Item_en;
    y += y;
    y += 4;
    tilemap_put_block(3, y, 2, code);
}

/* provisional name */
void game_config_print_gauge_en(u32 x, u32 old_x, s16 attr) {
    s32 y;
    u16 ix;

    y = Config_Item_en;
    y += y;
    ix = x;
    y += 4;
    x += 0x1F;
    if ((u16)old_x != 0xFFFF) {
        old_x += 0x1F;
        tilemap_put_block(old_x, y, 2, gcfg_gauge_clr_chr_en);
    }
    tilemap_put_block(x, y, attr, gcfg_gauge_chr_en[ix]);
}


/* provisional name */
void game_config_print_value_en(s16 attr, const TM_STRING* str) {
    s32 y;

    y = Config_Item_en;
    y += y;
    y += 4;
    tilemap_print_string(24, y, attr, str);
}


/* provisional name: the menu button code, as game_config_code_check_jp */
void game_config_code_check_en(void) {
    register s16 sw;
    if (game_config_work.bonus & 2) {
        return;
    }
    sw = ~p1sw_1 & p1sw_0 & 0x13C0;
    if (!sw) {
        return;
    }
    if (Config_Item_en == Config_Code_Ptr_en[0]) {
        if (sw == Config_Code_Ptr_en[1]) {
            Config_Code_No_en++;
            Config_Code_Ptr_en += 2;
            if (Config_Code_No_en >= 13) {
                game_config_work.bonus |= 2;
                sound_request(0x274);
            }
            return;
        }
    }
    Config_Code_No_en = 0;
    Config_Code_Ptr_en = gcfg_code_list_en[0];
}
