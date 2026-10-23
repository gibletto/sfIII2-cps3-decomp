/*
 * BG_WORK.C  background work
 *
 * The stage map tables (initialised, section D) and the backgrounds' work RAM (section B). A
 * <name>_tail table holds the bytes between <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

extern const HUD_CELL bg_rewrite_cells0[];
extern const HUD_CELL bg_rewrite_cells1[];
extern const HUD_CELL bg_rewrite_cells2[];
extern const HUD_CELL bg_rewrite_cells3[];
extern const HUD_CELL bg_rewrite_cells4[];
extern const HUD_CELL bg_rewrite_cells5[];
extern const HUD_CELL bg_rewrite_cells6[];
extern const HUD_CELL bg_rewrite_cells7[];
extern const HUD_CELL bg_rewrite_cells8[];
extern const HUD_CELL bg_rewrite_cells9[];
extern const TILEREQ bg_etc_cells0[];
extern const TILEREQ bg_etc_cells1[];
extern const TILEREQ bg_etc_cells2[];
extern const TILEREQ bg_etc_cells3[];
extern const TILEREQ bg_etc_cells4[];
extern const s16 bg_scr_record_data[];
extern const s16 ake_scr_record_data[];
extern const PANEL end_1100_bg0_cell_tbl[];

/* 020074D4 */
u32 bg_map_tbl[18][4] = {
    { (u32)bg_scr_record_data, (u32)&bg_scr_record_data[16], (u32)&bg_scr_record_data[32], 0 },
    { (u32)&ake_scr_record_data[48], (u32)&ake_scr_record_data[64], 0, 0 },
    { (u32)&ake_scr_record_data[80], (u32)&ake_scr_record_data[93], 0, 0 },
    { (u32)&ake_scr_record_data[109], (u32)&ake_scr_record_data[125], (u32)&ake_scr_record_data[141], 0 },
    { (u32)&ake_scr_record_data[180], (u32)&ake_scr_record_data[196], 0, 0 },
    { (u32)bg_scr_record_data, (u32)&bg_scr_record_data[16], (u32)&ake_scr_record_data[212], 0 },
    { (u32)&ake_scr_record_data[219], (u32)&bg_scr_record_data[16], 0, 0 },
    { (u32)&ake_scr_record_data[232], (u32)&bg_scr_record_data[16], (u32)&ake_scr_record_data[248], 0 },
    { (u32)&ake_scr_record_data[264], (u32)&ake_scr_record_data[286], 0, 0 },
    { (u32)bg_scr_record_data, (u32)&ake_scr_record_data[293], 0, 0 },
    { (u32)&ake_scr_record_data[321], (u32)&bg_scr_record_data[16], (u32)&ake_scr_record_data[331], 0 },
    { (u32)&ake_scr_record_data[154], (u32)&ake_scr_record_data[167], 0, 0 },
    { (u32)&ake_scr_record_data[341], (u32)&ake_scr_record_data[357], (u32)&bg_scr_record_data[32], 0 },
    { (u32)&ake_scr_record_data[373], (u32)&bg_scr_record_data[16], (u32)&bg_scr_record_data[32], 0 },
    { (u32)&ake_scr_record_data[389], (u32)&ake_scr_record_data[405], 0, 0 },
    { (u32)&ake_scr_record_data[418], (u32)&bg_scr_record_data[16], 0, 0 },
    { (u32)&ake_scr_record_data[219], (u32)&bg_scr_record_data[16], 0, 0 },
    { (u32)&ake_scr_record_data[437], 0, 0, 0 },
};
/* 020075F4 */
u32 bg_map_tbl2[5][4] = {
    { (u32)bg_scr_record_data, (u32)&bg_scr_record_data[16], (u32)&bg_scr_record_data[32], (u32)&bg_scr_record_data[48] },
    { (u32)bg_scr_record_data, 0, 0, 0 },
    { (u32)bg_scr_record_data, 0, 0, 0 },
    { (u32)bg_scr_record_data, 0, 0, 0 },
    { (u32)bg_scr_record_data, 0, 0, 0 },
};
/* 02007644 */
HUD_CELL* bg_rewrite_cell_tbl[5][4] = {
    { (HUD_CELL *)end_1100_bg0_cell_tbl, (HUD_CELL *)bg_rewrite_cells0, (HUD_CELL *)bg_rewrite_cells2, (HUD_CELL *)bg_rewrite_cells3 },
    { (HUD_CELL *)bg_rewrite_cells4, (HUD_CELL *)bg_rewrite_cells5, (HUD_CELL *)bg_rewrite_cells6, (HUD_CELL *)bg_rewrite_cells7 },
    { (HUD_CELL *)bg_rewrite_cells9, (HUD_CELL *)bg_rewrite_cells5, (HUD_CELL *)bg_rewrite_cells6, (HUD_CELL *)bg_rewrite_cells7 },
    { (HUD_CELL *)bg_rewrite_cells8, 0, 0, 0 },
    { (HUD_CELL *)end_1100_bg0_cell_tbl, (HUD_CELL *)bg_rewrite_cells1, (HUD_CELL *)bg_rewrite_cells2, (HUD_CELL *)bg_rewrite_cells3 },
};
/* 02007694 */
TILEREQ* bg_etc_cell_tbl[5][4] = {
    { (TILEREQ *)bg_etc_cells0, 0, 0, 0 },
    { (TILEREQ *)bg_etc_cells1, 0, 0, 0 },
    { (TILEREQ *)bg_etc_cells2, 0, 0, 0 },
    { (TILEREQ *)bg_etc_cells3, 0, 0, 0 },
    { (TILEREQ *)bg_etc_cells4, 0, 0, 0 },
};

s16 stage8_base_y;  /* 020225A8, provisional name */
BGW* bgw_ptr;  /* 020225AC */
SUZI_CALC suzi_calc_w[2];  /* 020225B0 */
Ideal_W ideal_w;  /* 020225C0 */
u16 suzi_line_buf[2048];  /* 020225C8 */
MVXY bg_mvxy;  /* 020235C8 */
s16 bg_stop;  /* 020235E0 */
s16 base_y_pos;  /* 020235E2 */
u8 base_y_pos_tail[12];  /* after base_y_pos; nothing refers to it by name or address */
s16 mark_gfx_ofs[128];  /* 020235F0, provisional name */
s16 mark_gfx_cells[128];  /* 020236F0, provisional name */
s16 mark_gfx_colcd[128];  /* 020237F0, provisional name */
s16 bg_ofs_work[3];  /* 020238F0 */
s16 bg_zoom_x_pos;  /* 020238F6 */
s16 bg_sp_work;  /* 020238F8 */
u8 bg_sp_work_tail[6];  /* after bg_sp_work; nothing refers to it by name or address */
s16 bg_land_flag;  /* 02023900 */
s8 demo_car_flag[2];  /* 02023902 */
s16 bg_etc_flag;  /* 02023904 */
s16 bg_stop2;  /* 02023906 */
s16 chase_x;  /* 02023908 */
s16 chase_y;  /* 0202390A */
s16 chase_time_x;  /* 0202390C */
s16 chase_time_y;  /* 0202390E */
u8 chase_time_y_tail[4];  /* after chase_time_y; nothing refers to it by name or address */
s8 akebono_flag;  /* 02023914 */
s8 seraph_flag;  /* 02023915 */
s8 aku_flag;  /* 02023916 */
s8 bg_select_no;  /* 02023917 */
s8 sa_pa_flag;  /* 02023918 */
s8 bg_app;  /* 02023919 */
s8 bg_vbl_trans_flag;  /* 0202391A */
s16 ls_rate0;  /* 0202391C */
s16 ls_cnt1;  /* 0202391E */
s16 ls_cnt2;  /* 02023920 */
BG_ADRS eff_bg_adrs[3];  /* 02023924 */
u8 eff_bg_adrs_tail[60];  /* after eff_bg_adrs; nothing refers to it by name or address */
s8 bg_demo_cnt;  /* 02023978 */
u8 bg_demo_cnt_tail[3];  /* after bg_demo_cnt; nothing refers to it by name or address */
s8 bg060_cnt;  /* 0202397C */
s8 bg060_timer;  /* 0202397D */
s8 bg060_end;  /* 0202397E */
s8 bg060_mode;  /* 0202397F */
s16 bg080_quake_sw;  /* 02023980 */
u8 bg080_quake_sw_tail[2];  /* after bg080_quake_sw; nothing refers to it by name or address */
s16 bg1403_wait;  /* 02023984 */
