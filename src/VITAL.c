/*
 * VITAL.C  Vitality bars and round timers
 *
 * Draws and runs the vitality bars and the timers. vital_cont_init resets both bars to full,
 * vital_cont_main and vital_control update them each frame and vital_parts_allwrite redraws all 20
 * cells from the yellow and red levels. count_cont_init/reset/main, counter_control and
 * counter_flash run the 99-count round timer, with a tick rate from the game-speed setting and
 * flashing below 30 and 10.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "PLS01.h"
#include "count.h"
#include "VITAL.h"
#include "cps3.h"

#define BAR_WORD(tbl, ix) (*(s16*)((u32)(tbl) + (ix) * 2))

s16 vital_col_ix;
s16 vital_dot_pos;
s16 vital_red_ofs;
s16 vital_yel_ofs;
u16 gauge_stop_flag[2];
VITAL_BAR vit_bar[2];



const u16* vital_npos_tbl[4] = {
    &vital_cell_1p_tbl[81],
    &vital_cell_1p_tbl[101],
    &vital_cell_1p_tbl[121],
    &vital_cell_1p_tbl[145],
};



const u16* vital_attr_tbl[3] = {
    &vital_cell_1p_tbl[169],
    &vital_cell_1p_tbl[172],
    &vital_cell_1p_tbl[175],
};



void vital_cont_init(void) {
    const u16* cell;
    vit_bar[0].cyerw = Game_setting.mode * 32 + 160;
    vit_bar[0].cred = Game_setting.mode * 32 + 160;
    vit_bar[0].ored = Game_setting.mode * 32 + 160;
    vit_bar[0].unused = 0;
    vit_bar[0].colnum = 0;
    vit_bar[0].cell = cell = vital_cell_tbl;
    vit_bar[0].attr = vital_attr_tbl[0];
    vit_bar[1].cyerw = Game_setting.mode * 32 + 160;
    vit_bar[1].cred = Game_setting.mode * 32 + 160;
    vit_bar[1].ored = Game_setting.mode * 32 + 160;
    vit_bar[1].unused = 0;
    vit_bar[1].colnum = 0;
    vit_bar[1].cell = cell;
    vit_bar[1].attr = vital_attr_tbl[1];
    if (Game_setting.mode == 0) {
        vit_bar[0].xpos = vital_npos_tbl[0];
        vit_bar[1].xpos = vital_npos_tbl[1];
        sc_ram_to_vram(4, 0, 0);
        sc_ram_to_vram(5, 0, 0);
    } else {
        vit_bar[0].xpos = vital_npos_tbl[2];
        vit_bar[1].xpos = vital_npos_tbl[3];
        sc_ram_to_vram(12, 0, 0);
        sc_ram_to_vram(13, 0, 0);
    }
    gauge_stop_flag[0] = 0;
    gauge_stop_flag[1] = 0;
}



void vital_cont_main(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    if (gauge_stop_flag[0] == 0) {
        vital_control(0);
    }
    if (gauge_stop_flag[1] == 0) {
        vital_control(1);
    }
}



s32 vital_control(s8 pl) {
    s8 i;
    if (plw[pl].wu.vital_new > Game_setting.mode * 32 + 0xA0) {
        return 0;
    }
    if (vit_bar[pl].cyerw == plw[pl].wu.vital_new) {
        if (vit_bar[pl].cred == plw[pl].wu.vital_new) {
            if (vit_bar[pl].ored != (plw[pl].wu.vital_new + 1)) {
                return 0;
            }
        }
    }
    if (vit_bar[pl].cred < plw[pl].wu.vital_new) {
        vit_bar[pl].cred = plw[pl].wu.vital_new;
    }
    vit_bar[pl].cyerw = plw[pl].wu.vital_new;
    (void)((WORK*)0)->id;
    if (plw[pl].wu.vital_new < 0) {
        vit_bar[pl].cyerw = 0;
    }
    vital_dot_pos = Game_setting.mode * 32 + 0xA0;
    vital_col_ix = 0;
    if (plw[pl].wu.vital_new <= Game_setting.mode * 32 + 0x9F) {
        vit_bar[pl].colnum = 1;
        if (plw[pl].wu.vital_new <= Game_setting.mode * 10 + 48) {
            vit_bar[pl].colnum = 2;
        }
    } else {
        vit_bar[pl].colnum = 0;
    }
    for (i = 0; i < Game_setting.mode * 4 + 20; i++) {
        vital_dot_pos -= 8;
        if (vital_dot_pos < vit_bar[pl].cred) {
            if (vit_bar[pl].cyerw > vital_dot_pos) {
                if (vital_dot_pos + 8 > vit_bar[pl].cred) {
                    vital_red_ofs = vital_dot_pos - vit_bar[pl].cred + 8;
                } else {
                    vital_red_ofs = 0;
                }
                if (vital_dot_pos + 8 > vit_bar[pl].cyerw) {
                    vital_yel_ofs = vit_bar[pl].cyerw - vital_dot_pos;
                } else {
                    vital_yel_ofs = 8;
                }
                tilemap_put_cell(BAR_WORD(vit_bar[pl].xpos, vital_col_ix), 2, BAR_WORD(vit_bar[pl].attr, vit_bar[pl].colnum),
                                 BAR_WORD(vit_bar[pl].cell, vital_yel_ofs * 9 + vital_red_ofs));
                vital_col_ix++;
                continue;
            } else {
                if (vit_bar[pl].cred >= vital_dot_pos + 8) {
                    vital_red_ofs = 0;
                } else {
                    vital_red_ofs = 8 - (vit_bar[pl].cred - vital_dot_pos);
                }
                vital_yel_ofs = 0;
                tilemap_put_cell(BAR_WORD(vit_bar[pl].xpos, vital_col_ix), 2, BAR_WORD(vit_bar[pl].attr, vit_bar[pl].colnum),
                                 BAR_WORD(vit_bar[pl].cell, vital_red_ofs));
            }
        } else {
            tilemap_put_cell(BAR_WORD(vit_bar[pl].xpos, vital_col_ix), 2, BAR_WORD(vit_bar[pl].attr, vit_bar[pl].colnum), 0xAC);
        }
        vital_col_ix++;
    }
    vit_bar[pl].ored = vit_bar[pl].cred;
    vit_bar[pl].cred--;
    if (vit_bar[pl].cred < plw[pl].wu.vital_new) {
        vit_bar[pl].cred = plw[pl].wu.vital_new;
    }
}



s32 vital_parts_allwrite(s8 pl) {
    const u16* tbl;
    s8 i;
    const s16* cols;
    const s16* attrs;
    if (vit_bar[1].cyerw < 0) {
        vit_bar[1].cyerw = 0;
    }
    if (pl == 0) {
        ToneDown(3);
        tbl = vital_cell_1p_tbl;
    } else {
        tbl = vital_cell_tbl;
    }
    if (Game_setting.mode == 0) {
        cols = (const s16*)vital_npos_tbl[1];
    } else {
        cols = (const s16*)vital_npos_tbl[3];
    }
    attrs = (const s16*)vital_attr_tbl[2 - pl];
    vital_dot_pos = Game_setting.mode * 32 + 160;
    vital_col_ix = 0;
    for (i = 0; i < Game_setting.mode * 4 + 20; i++) {
        vital_dot_pos -= 8;
        if (vital_dot_pos < vit_bar[1].cred) {
            if (vit_bar[1].cyerw > vital_dot_pos) {
                if (vital_dot_pos + 8 > vit_bar[1].cred) {
                    vital_red_ofs = vital_dot_pos - vit_bar[1].cred + 8;
                } else {
                    vital_red_ofs = 0;
                }
                if (vital_dot_pos + 8 > vit_bar[1].cyerw) {
                    vital_yel_ofs = vit_bar[1].cyerw - vital_dot_pos;
                } else {
                    vital_yel_ofs = 8;
                }
                tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], tbl[vital_yel_ofs * 9 + vital_red_ofs]);
                vital_col_ix++;
                continue;
            }
            if (vit_bar[1].cred >= vital_dot_pos + 8) {
                vital_red_ofs = 0;
            } else {
                vital_red_ofs = 8 - (vit_bar[1].cred - vital_dot_pos);
            }
            vital_yel_ofs = 0;
            tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], 0xAC);
            vital_col_ix++;
            continue;
        }
        tilemap_put_cell(cols[vital_col_ix], 2, attrs[vit_bar[1].colnum], 0xAC);
        vital_col_ix++;
    }
}
