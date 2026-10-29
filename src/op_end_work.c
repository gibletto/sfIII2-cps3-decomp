/*
 * OP_END_WORK.C  opening and ending work
 *
 * The ending's routine and panel tables (initialised, section D) and the opening's and the
 * ending's work RAM (section B). A <name>_tail table holds the bytes between <name> and the
 * next named variable.
 */

#include "types.h"
#include "structs.h"


extern const PANEL end_400_panel0[];
extern const PANEL end_400_panel1[];
extern const PANEL end_800_panel0[];
extern const PANEL end_800_panel1[];
extern const PANEL op_panel0[];
extern const PANEL op_panel1[];
extern const PANEL op_panel2[];
extern const s16 end_map_data_0[];
extern const s16 end_map_data_1[];
extern const s16 end_map_data_2[];
extern const s16 end_map_data_3[];
extern const s32 end_1100_cell0[];
extern const s32 end_1100_cell1[];
extern const s32 end_1100_cell2[];
extern const s32 end_1100_cell3[];
extern const s32 end_1100_cell4[];
extern const s32 end_1100_cell5[];
extern const s32 end_1100_cell6[];
extern const s32 end_1100_cell7[];
extern const PANEL end_10_panel_tbl_0[];
extern const PANEL end_10_panel_tbl_1[];
extern void end_00000();
extern void end_01000();
extern void end_02000();
extern void end_03000();
extern void end_04000();
extern void end_05000();
extern void end_06000();
extern void end_07000();
extern void end_08000();
extern void end_09000();
extern void end_10000();
extern void end_1000_0000();
extern void end_1000_1000();
extern void end_1000_2000();
extern void end_1000_3000();
extern void end_1000_4000();
extern void end_1000_5000();
extern void end_1000_6000();
extern void end_11000();
extern void end_12000();
extern void end_13000();

/* 02007724 */
const PANEL* op_panel_p[4] = {
    op_panel0,
    op_panel0,
    op_panel1,
    op_panel2,
};
/* the code declares end_main_jp[24]; end_map_tbl starts after its first 16 entries */
/* 02007734 */
void (*end_main_jp[16])(s16) = {
    (void (*)(s16))end_00000, (void (*)(s16))end_01000, (void (*)(s16))end_02000, (void (*)(s16))end_03000,
    (void (*)(s16))end_04000, (void (*)(s16))end_05000, (void (*)(s16))end_06000, (void (*)(s16))end_07000,
    (void (*)(s16))end_08000, (void (*)(s16))end_09000, (void (*)(s16))end_03000, (void (*)(s16))end_10000,
    (void (*)(s16))end_11000, (void (*)(s16))end_12000, (void (*)(s16))end_13000, (void (*)(s16))end_13000,
};
/* 02007774 */
u32 end_map_tbl[4] = {
    (u32)end_map_data_0, (u32)end_map_data_1, (u32)end_map_data_2, (u32)end_map_data_3,
};
/* 02007784 */
const PANEL* end_4_panel_p[2] = {
    end_400_panel0,
    end_400_panel1,
};
/* 0200778C */
const PANEL* end_8_panel_p[2] = {
    end_800_panel0,
    end_800_panel1,
};
/* 02007794 */
const PANEL* end_10_panel_p[2] = {
    end_10_panel_tbl_0, end_10_panel_tbl_1,
};
/* 0200779C */
void (*end_10_jp[7])() = {
    end_1000_0000, end_1000_1000, end_1000_2000, end_1000_3000, end_1000_4000, end_1000_5000, end_1000_6000,
};
/* 020077B8 */
const s32* end_11_cell_ptr0[9] = {
    end_1100_cell0,
    end_1100_cell1,
    end_1100_cell2,
    end_1100_cell3,
    end_1100_cell3,
    end_1100_cell4,
    end_1100_cell3,
    end_1100_cell5,
    end_1100_cell0,
};
/* 020077DC */
const s32* end_11_cell_ptr1[9] = {
    end_1100_cell6,
    end_1100_cell7,
    end_1100_cell7,
    end_1100_cell7,
    end_1100_cell6,
    end_1100_cell6,
    end_1100_cell7,
    end_1100_cell6,
    end_1100_cell6,
};
/* 02007800 */
/* Stored after end_11_cell_ptr1. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_11_cell_ptr1. */
u32 end_11_cell_ptr1_tail[11] = {
    (u32)end_1100_cell6, 0, 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000,
    0x70000, 0x80000, 0x90000,
};


OP_W op_w;  /* 02023A88 */
s16 op_end_flag;  /* 02023AA4 */
s16 op_obj_disp;  /* 02023AA6 */
s8 effE1_end_flag;  /* 02023AA8, provisional name */
OPBW* opw_ptr;  /* 02023AAC */
u8 opw_ptr_tail[2];  /* after opw_ptr; nothing refers to it by name or address */
s16 op_plmove_timer;  /* 02023AB2 */
s16 op_demo_index;  /* 02023AB4 */
u8 op_demo_index_tail[2];  /* after op_demo_index; nothing refers to it by name or address */
END_W end_w;  /* 02023AB8 */
s16 ls_rate1;  /* 02023AC4 */
s8 end_etc_flag;  /* 02023AC6 */
s8 ending_all_end;  /* 02023AC7 */
s8 end_fade_flag;  /* 02023AC8 */
s8 end_no_cut;  /* 02023AC9 */
s16 end_fade_timer;  /* 02023ACA */
s16 end_cnt;  /* 02023ACC */
s8 end_name_cut[2];  /* 02023ACE */
s8 end_staff_flag;  /* 02023AD0 */
u8 end_cont_coin;  /* 02023AD1 */
s8 end_scroll_dir;  /* 02023AD2 */
s8 end_staff_done;  /* 02023AD3 */
s8 end_obj_sync;  /* 02023AD4 */
s16 staff_roll_timer;  /* 02023AD6 */
s32 staff_r_no;  /* 02023AD8 */
s32 end_2_bg0_step;  /* 02023ADC */
s32 end_2_bg1_step;  /* 02023AE0 */
s32 end_2_timer;  /* 02023AE4 */
s16 end_cnt2;  /* 02023AE8 */
