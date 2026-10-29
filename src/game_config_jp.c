/*
 * GAME_CONFIG_JP.C  Test-mode game configuration, Japanese page
 *
 * game_config_init_jp draws the GAME CONFIGURATION page shown when Country is 1 and
 * game_config_move_jp runs it: screen mode, difficulty, damage, timer speed, 1P/2P round counts,
 * event and bonus settings, with lever repeat and star gauges. game_config_apply copies the edited
 * settings back when the page is left.
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
void tilemap_rect_fill(u16 x, u16 y, u16 w, u16 h, u16 attr, u16 code);
void palette_write(s32 offset, const u16 *src, s32 count);
void tilemap_fill_all(u16 attr, u16 code);
void tilemap_print_script_seq();
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

extern const u16 gcfg_bonus_scr_jp_0[];
extern const u16 gcfg_bonus_scr_jp_1[];
extern const u16 gcfg_cursor_clr_scr_jp_0[];
extern const u16 gcfg_cursor_scr_jp_0[];
extern const u16 gcfg_event_scr_jp_0[];
extern const u16 gcfg_event_scr_jp_1[];
extern const u16 gcfg_exit_guide_scr_jp_0[];
extern const u16 gcfg_gauge_clr_scr_jp_0[];
extern const u16 gcfg_gauge_scr_jp_0[];
extern const u16 gcfg_gauge_scr_jp_1[];
extern const u16 gcfg_gauge_scr_jp_2[];
extern const u16 gcfg_gauge_scr_jp_3[];
extern const u16 gcfg_gauge_scr_jp_4[];
extern const u16 gcfg_gauge_scr_jp_5[];
extern const u16 gcfg_gauge_scr_jp_6[];
extern const u16 gcfg_gauge_scr_jp_7[];
extern const u16 gcfg_guide_scr_jp_0[];
extern const u16 gcfg_round_scr_jp_0[];
extern const u16 gcfg_round_scr_jp_1[];
extern const u16 gcfg_round_scr_jp_2[];
extern const u16 gcfg_round_scr_jp_3[];
extern const u16 gcfg_screen_scr_jp_0[];
extern const u16 gcfg_screen_scr_jp_1[];
extern const u16 gcfg_title_scr_jp_0[];
extern const u16 gcfg_title_old_scr_jp_0[];   /* provisional name */
extern const u32 config_jp_chr_f400[];      /* provisional name: data copied to SS_RAM + 0xF400 */

s8 Config_Item_jp;  
s8 Config_Exit_jp;  /* 02015A01 */
s8 Config_Move_jp;  /* 02015A02 */
s8 Config_Old_jp;  /* 02015A03 */
s8 Config_New_jp;  /* 02015A04 */
s8 Config_Org_jp;  /* 02015A05 */
s16 Config_Attr_jp;  /* 02015A06 */
s16 Config_Rep_Timer_jp[4];  /* 02015A08 */
s8 Config_Rep_Count_jp[4];  /* 02015A10 */
s16* Config_Code_Ptr_jp;  /* 02015A14, provisional name */
s16 Config_Code_No_jp;  /* 02015A18, provisional name */


/* 020007EC */
/* the menu button code (item, button): 13 steps unlock bit 1 of the bonus setting */
s16 gcfg_code_list_jp[13][2] = {
    { 3, 0x1000 }, { 3, 0x1000 }, { 3, 0x1000 }, { 5, 0x0100 }, { 5, 0x0100 }, { 0, 0x0200 }, { 0, 0x0200 },
    { 0, 0x0200 }, { 6, 0x1000 }, { 2, 0x0080 }, { 2, 0x0080 }, { 2, 0x0080 }, { 2, 0x0080 },
};
TMSCRIPT gcfg_title_scr_jp[1] = {
    { 1, 0, gcfg_title_scr_jp_0 },
};
TMSCRIPT gcfg_guide_scr_jp[1] = {
    { 1, 0, gcfg_guide_scr_jp_0 },
};
/* 020007F4 */
TMSCRIPT gcfg_exit_guide_scr_jp[1] = {
    { 1, 0, gcfg_exit_guide_scr_jp_0 },
};
/* 020007FC */
TMSCRIPT gcfg_screen_scr_jp[2] = {
    { 1, 0, gcfg_screen_scr_jp_0 },
    { 1, 0, gcfg_screen_scr_jp_1 },
};
/* 0200080C */
TMSCRIPT gcfg_round_scr_jp[4] = {
    { 1, 0, gcfg_round_scr_jp_0 },
    { 1, 0, gcfg_round_scr_jp_1 },
    { 1, 0, gcfg_round_scr_jp_2 },
    { 1, 0, gcfg_round_scr_jp_3 },
};
/* 0200082C */
TMSCRIPT gcfg_event_scr_jp[2] = {
    { 1, 0, gcfg_event_scr_jp_0 },
    { 1, 0, gcfg_event_scr_jp_1 },
};
/* 0200083C */
TMSCRIPT gcfg_bonus_scr_jp[2] = {
    { 1, 0, gcfg_bonus_scr_jp_0 },
    { 1, 0, gcfg_bonus_scr_jp_1 },
};
/* 0200084C */
TMSCRIPT gcfg_cursor_scr_jp[1] = {
    { 1, 0, gcfg_cursor_scr_jp_0 },
};
/* 02000854 */
TMSCRIPT gcfg_cursor_clr_scr_jp[1] = {
    { 1, 0, gcfg_cursor_clr_scr_jp_0 },
};
/* 0200085C */
TMSCRIPT gcfg_gauge_scr_jp[8] = {
    { 1, 0, gcfg_gauge_scr_jp_0 },
    { 1, 0, gcfg_gauge_scr_jp_1 },
    { 1, 0, gcfg_gauge_scr_jp_2 },
    { 1, 0, gcfg_gauge_scr_jp_3 },
    { 1, 0, gcfg_gauge_scr_jp_4 },
    { 1, 0, gcfg_gauge_scr_jp_5 },
    { 1, 0, gcfg_gauge_scr_jp_6 },
    { 1, 0, gcfg_gauge_scr_jp_7 },
};
/* 0200089C */
TMSCRIPT gcfg_gauge_clr_scr_jp[1] = {
    { 1, 0, gcfg_gauge_clr_scr_jp_0 },
};
/* Stored after gcfg_gauge_clr_scr_jp. Nothing in the program refers to it by name or address; if it is
   read, it is through an index past the end of gcfg_gauge_clr_scr_jp. */
TMSCRIPT gcfg_gauge_clr_scr_jp_tail[1] = {
    { 1, 0, gcfg_title_old_scr_jp_0 },
};
/* 020008A4 */


/* provisional name */
void game_config_init_jp(void) {
    Config_No_2++;
    Config_Exit_jp = 0;
    Config_Code_Ptr_jp = gcfg_code_list_jp[0];
    Config_Code_No_jp = 0;
    tilemap_fill_all(0, 32);
    palette_write(0, sys_palette, 0x100);
    init_render_lists();
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)jp_menu_font_cg, 0x200);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0xF400), (char*)config_jp_chr_f400, 4);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0xCD00), (char*)config_jp_chr_0, 4);
    tilemap_fill_all(0, 0x1200);
    tilemap_print_script_seq(0, 0, 0xFFFF, gcfg_title_scr_jp);
    Config_Attr_jp = 2;
    Config_Item_jp = 6;
    Config_New_jp = game_config_work.bonus & 1;
    Config_Old_jp = Game_setting.bonus & 1;
    Config_Attr_jp = (Config_New_jp != Config_Old_jp) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_bonus_scr_jp[Config_New_jp]);
    Config_Item_jp = 5;
    Config_New_jp = game_config_work.set5;
    Config_Attr_jp = (Config_New_jp != Game_setting.set5) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_event_scr_jp[Config_New_jp]);
    Config_Item_jp = 4;
    Config_New_jp = game_config_work.set4;
    Config_Attr_jp = (Config_New_jp != Game_setting.set4) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
    Config_Item_jp = 3;
    Config_New_jp = game_config_work.set3;
    Config_Attr_jp = (Config_New_jp != Game_setting.set3) ? 8 : 2;
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    Config_Item_jp = 2;
    Config_New_jp = game_config_work.set2;
    Config_Attr_jp = (Config_New_jp != Game_setting.set2) ? 8 : 2;
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    Config_Item_jp = 1;
    Config_New_jp = game_config_work.level;
    Config_Attr_jp = (Config_New_jp != Game_setting.level) ? 8 : 2;
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    Config_Item_jp = 0;
    Config_New_jp = game_config_work.mode;
    Config_Attr_jp = (Config_New_jp != Game_setting.mode) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_screen_scr_jp[Config_New_jp]);
    game_config_print_cursor_jp(gcfg_cursor_scr_jp);
}



/* provisional name */
void game_config_move_jp(void) {
    void (*Page_Tbl[8])() = { game_config_screen_item_jp, game_config_level_item_jp, game_config_damage_item_jp, game_config_timer_item_jp, game_config_1p_round_item_jp, game_config_event_item_jp, game_config_bonus_item_jp, game_config_exit_item_jp };
    void (*Page_Tbl_Old[6])() = { game_config_level_item_jp, game_config_damage_item_jp, game_config_timer_item_jp, game_config_1p_round_item_jp, game_config_event_item_jp, game_config_exit_item_jp };
    game_config_cursor_move_jp();
    Page_Tbl[Config_Item_jp]();
    game_config_print_cursor_jp(gcfg_cursor_scr_jp);
    if (Config_Item_jp == 7) {
        tilemap_print_script_seq(0, 0, 0xFFFF, gcfg_exit_guide_scr_jp);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, gcfg_guide_scr_jp);
    }
    game_config_code_check_jp();
}



/* provisional name */
void game_config_force_wide(void) {
    u16 sw1 = p1sw_0 & BUTTON_SHOTS;
    u16 sw2 = p2sw_0 & BUTTON_SHOTS;
    if (sw1 == 0x3F0 && sw2 == 0x3F0) {
        set_screen_mode(7);
        game_config_work.mode = 1;
        screen_flip_offsets_set();
    }
}



/* provisional name */
void game_config_screen_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.mode += Config_Move_jp;
        game_config_work.mode &= 1;
        if (game_config_work.mode) {
            set_screen_mode(7);
        } else {
            set_screen_mode(3);
        }
        screen_flip_offsets_set();
        tilemap_print_script_seq(24, 2, 0xFFFF, &gcfg_screen_scr_jp[game_config_work.mode]);
        if (game_config_work.mode != Game_setting.mode) {
            tilemap_rect_fill(24, 2, 8, 2, 8, 0xFFFF);
        } else {
            tilemap_rect_fill(24, 2, 8, 2, 2, 0xFFFF);
        }
    } else {
        game_config_work.mode &= 1;
    }
}



/* provisional name */
void game_config_level_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    game_config_work.level &= 7;
    if (Config_Move_jp) {
        Config_Old_jp = game_config_work.level;
        game_config_work.level += Config_Move_jp;
        game_config_work.level &= 7;
        Config_New_jp = game_config_work.level;
        Config_Attr_jp = Config_New_jp != Game_setting.level ? 8 : 2;
        game_config_print_gauge_jp(Config_New_jp, Config_Old_jp, Config_Attr_jp);
    }
}



/* provisional name */
void game_config_damage_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else {
        if (game_config_lever_repeat_jp(8, 3)) {
            Config_Move_jp = 1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = game_config_work.set2;
        game_config_work.set2 += Config_Move_jp;
        game_config_work.set2 &= 3;
        Config_New_jp = game_config_work.set2;
        Config_Attr_jp = Config_New_jp != Game_setting.set2 ? 8 : 2;
        game_config_print_gauge_jp(Config_New_jp, Config_Old_jp, Config_Attr_jp);
    }
}



/* provisional name */
void game_config_timer_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = game_config_work.set3;
        game_config_work.set3 += Config_Move_jp;
        game_config_work.set3 &= 3;
        Config_New_jp = game_config_work.set3;
        Config_Attr_jp = Config_New_jp != Game_setting.set3 ? 8 : 2;
        game_config_print_gauge_jp(Config_New_jp, Config_Old_jp, Config_Attr_jp);
    }
}



/* provisional name */
void game_config_1p_round_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.set4 += Config_Move_jp;
        game_config_work.set4 &= 3;
        Config_New_jp = game_config_work.set4;
        Config_Attr_jp = (Config_New_jp != Game_setting.set4) ? 8 : 2;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
    }
}




/* provisional name */
void game_config_event_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.set5 += Config_Move_jp;
        game_config_work.set5 &= 1;
        Config_New_jp = game_config_work.set5;
        Config_Attr_jp = (Config_New_jp != Game_setting.set5) ? 8 : 2;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_event_scr_jp[Config_New_jp]);
    }
}



/* provisional name */
void game_config_bonus_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & BUTTON_LP) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & BUTTON_MP) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.bonus ^= 1;
        game_config_work.bonus &= 3;
        Config_New_jp = game_config_work.bonus & 1;
        Config_Old_jp = Game_setting.bonus & 1;
        Config_Attr_jp = (Config_New_jp != Config_Old_jp) ? 8 : 2;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_bonus_scr_jp[Config_New_jp]);
    }
}



/* provisional name */
void game_config_exit_item_jp(void) {
    if ((~p1sw_1 & p1sw_0) & BUTTON_LP) {
        Config_Exit_jp = 1;
    }
}



/* provisional name */
void game_config_settings_commit(void) {
    Game_setting.mode = game_config_work.mode;
    Game_setting.level = game_config_work.level;
    Game_setting.set2 = game_config_work.set2;
    Game_setting.set3 = game_config_work.set3;
    Game_setting.set4 = game_config_work.set4;
    Game_setting.set5 = game_config_work.set5;
    Game_setting.set6 = game_config_work.set6;
    Game_setting.bonus = game_config_work.bonus;
}



/* provisional name */
s8 game_config_lever_repeat_jp(u16 sw, s16 ix) {
    if (~p1sw_1 & p1sw_0 & sw) {
        return 1;
    }
    if (p1sw_0 & sw) {
        Config_Rep_Timer_jp[ix]++;
        if (Config_Rep_Timer_jp[ix] > 10) {
            Config_Rep_Count_jp[ix]++;
            if (Config_Rep_Count_jp[ix] > 8) {
                Config_Rep_Count_jp[ix] = 0;
                return 1;
            }
        }
    } else {
        Config_Rep_Timer_jp[ix] = 0;
        Config_Rep_Count_jp[ix] = 0;
    }
    return 0;
}



/* provisional name */
void game_config_cursor_move_jp(void) {
    game_config_print_cursor_jp(gcfg_cursor_clr_scr_jp);
    if (game_config_lever_repeat_jp(1, 0)) {
        Config_Item_jp--;
        if (Config_Item_jp < 0) {
            Config_Item_jp = 7;
        }
    }
    if (game_config_lever_repeat_jp(2, 1)) {
        Config_Item_jp++;
        if (Config_Item_jp > 7) {
            Config_Item_jp = 0;
        }
    }
}



/* provisional name */
void game_config_apply(void) {
    if (game_config_work.set5) {
        event_off_flag = 0;
    } else {
        event_off_flag = 1;
    }
    if (game_config_work.mode) {
        set_screen_mode(7);
    } else {
        set_screen_mode(3);
    }
    screen_flip_offsets_set();
}

/* provisional name */
void game_config_print_value_jp(s16 attr, const TMSCRIPT* script) {
    s32 y;

    y = Config_Item_jp;
    y += y;
    y += 2;
    tilemap_print_script_seq(24, y, attr, script);
}



/* provisional name */
void game_config_print_gauge_jp(u32 newv, u32 oldv, s16 attr) {
    s32 y;
    u16 ix;

    y = Config_Item_jp;
    ix = newv;
    y += y;
    y += 2;
    newv += newv;
    newv += 26;
    if ((u16)oldv != 0xFFFF) {
        oldv += oldv;
        oldv += 26;
        tilemap_print_script_seq(oldv, y, 2, gcfg_gauge_clr_scr_jp);
    }
    tilemap_print_script_seq(newv, y, attr, &gcfg_gauge_scr_jp[ix]);
}

/* provisional name */
void game_config_print_cursor_jp(const TMSCRIPT* script) {
    s32 y;

    y = Config_Item_jp;
    y += y;
    y += 2;
    tilemap_print_script_seq(1, y, 0xFFFF, script);
}



/* provisional name: the menu button code; each press must match the next (item, button) step of
   gcfg_code_list_jp, and the 13th step sets bit 1 of the bonus setting */
void game_config_code_check_jp(void) {
    register s16 sw;
    if (game_config_work.bonus & 2) {
        return;
    }
    sw = ~p1sw_1 & p1sw_0 & 0x13C0;
    if (!sw) {
        return;
    }
    if (Config_Item_jp == Config_Code_Ptr_jp[0]) {
        if (sw == Config_Code_Ptr_jp[1]) {
            Config_Code_No_jp++;
            Config_Code_Ptr_jp += 2;
            if (Config_Code_No_jp >= 13) {
                game_config_work.bonus |= 2;
                sound_request(0x274);
            }
            return;
        }
    }
    Config_Code_No_jp = 0;
    Config_Code_Ptr_jp = gcfg_code_list_jp[0];
}
