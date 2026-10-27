/*
 * CMD_WORK.C  command input work
 *
 * The per-character command table lists (initialised, section D) and the command input work
 * (section B): the lever history, the special move recognisers, the computer player's commands.
 * A <name>_tail table holds the bytes between <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

extern const s16 p3_cmd_30[];
extern const char lvr_chk_line_str0[];
extern const char lvr_chk_line_str1[];
extern const char lvr_chk_line_str2[];
extern const char player_cmd_line_str0[];
extern const char player_cmd_line_str1[];
extern const char player_cmd_line_str2[];
extern const char player_cmd_line_str3[];
extern const char player_cmd_line_str4[];
extern const char player_cmd_line_str5[];
extern const char player_cmd_line_str6[];
extern const s16 p3_cmd_31[];
extern const s16 p6_cmd_29[];
extern const s16 p6_cmd_30[];
extern const s16 p7_cmd_32[];
extern const s16 p7_cmd_31[];
extern const s16 dm_cmd_xx[];
extern const s16 p0_cmd_20[];
extern const s16 p0_cmd_21[];
extern const s16 p0_cmd_22[];
extern const s16 p0_cmd_24[];
extern const s16 p0_cmd_28[];
extern const s16 p0_cmd_29[];
extern const s16 p0_cmd_30[];
extern const s16 p0_cmd_31[];
extern const s16 p1_cmd_20[];
extern const s16 p1_cmd_21[];
extern const s16 p1_cmd_22[];
extern const s16 p1_cmd_28[];
extern const s16 p1_cmd_29[];
extern const s16 p1_cmd_30[];
extern const s16 p1_cmd_31[];
extern const s16 p1_cmd_32[];
extern const s16 p2_cmd_20[];
extern const s16 p2_cmd_21[];
extern const s16 p2_cmd_22[];
extern const s16 p2_cmd_28[];
extern const s16 p2_cmd_29[];
extern const s16 p2_cmd_30[];
extern const s16 p2_cmd_31[];
extern const s16 p2_cmd_46[];
extern const s16 p3_cmd_20[];
extern const s16 p3_cmd_21[];
extern const s16 p3_cmd_22[];
extern const s16 p3_cmd_28[];
extern const s16 p3_cmd_29[];
extern const s16 p3_cmd_32[];
extern const s16 p4_cmd_20[];
extern const s16 p4_cmd_21[];
extern const s16 p4_cmd_22[];
extern const s16 p4_cmd_28[];
extern const s16 p4_cmd_29[];
extern const s16 p4_cmd_30[];
extern const s16 p4_cmd_31[];
extern const s16 p4_cmd_32[];
extern const s16 p4_cmd_33[];
extern const s16 p5_cmd_20[];
extern const s16 p5_cmd_21[];
extern const s16 p5_cmd_22[];
extern const s16 p5_cmd_28[];
extern const s16 p5_cmd_29[];
extern const s16 p5_cmd_30[];
extern const s16 p5_cmd_31[];
extern const s16 p5_cmd_32[];
extern const s16 p6_cmd_20[];
extern const s16 p6_cmd_21[];
extern const s16 p6_cmd_22[];
extern const s16 p6_cmd_28[];
extern const s16 p6_cmd_32[];
extern const s16 p6_cmd_33[];
extern const s16 p7_cmd_20[];
extern const s16 p7_cmd_21[];
extern const s16 p7_cmd_28[];
extern const s16 p7_cmd_29[];
extern const s16 p7_cmd_30[];
extern const s16 p7_cmd_38[];
extern const s16 p7_cmd_46[];
extern const s16 p8_cmd_20[];
extern const s16 p8_cmd_21[];
extern const s16 p8_cmd_22[];
extern const s16 p8_cmd_28[];
extern const s16 p8_cmd_29[];
extern const s16 p8_cmd_30[];
extern const s16 p8_cmd_32[];
extern const s16 p9_cmd_20[];
extern const s16 p9_cmd_22[];
extern const s16 p9_cmd_24[];
extern const s16 p9_cmd_28[];
extern const s16 p9_cmd_29[];
extern const s16 p9_cmd_30[];
extern const s16 p9_cmd_31[];
extern const s16 p9_cmd_46[];
extern const s16 p9_cmd_47[];
extern const s16 pA_cmd_20[];
extern const s16 pA_cmd_21[];
extern const s16 pA_cmd_22[];
extern const s16 pA_cmd_28[];
extern const s16 pA_cmd_30[];
extern const s16 pA_cmd_31[];
extern const s16 pA_cmd_32[];
extern const s16 pB_cmd_20[];
extern const s16 pB_cmd_21[];
extern const s16 pB_cmd_22[];
extern const s16 pB_cmd_28[];
extern const s16 pB_cmd_29[];
extern const s16 pB_cmd_30[];
extern const s16 pB_cmd_46[];
extern const s16 pC_cmd_20[];
extern const s16 pC_cmd_21[];
extern const s16 pC_cmd_22[];
extern const s16 pC_cmd_28[];
extern const s16 pC_cmd_29[];
extern const s16 pC_cmd_30[];
extern const s16 pC_cmd_31[];
extern const s16 pC_cmd_32[];
extern const s16 pD_cmd_20[];
extern const s16 pD_cmd_21[];
extern const s16 pD_cmd_22[];
extern const s16 pD_cmd_28[];
extern const s16 pD_cmd_29[];
extern const s16 pD_cmd_30[];
extern const s16 pD_cmd_31[];
extern const s16 pE_cmd_20[];
extern const s16 pE_cmd_21[];
extern const s16 pE_cmd_22[];
extern const s16 pE_cmd_24[];
extern const s16 pE_cmd_28[];
extern const s16 pE_cmd_29[];
extern const s16 pE_cmd_30[];
extern const s16 pE_cmd_31[];
extern const s16 pE_cmd_32[];
extern const s16 pE_cmd_33[];
extern const s16 pE_cmd_34[];
extern const s16 pE_cmd_38[];
extern const s16 pE_cmd_39[];
extern const s16 pE_cmd_46[];
extern const s16 pE_cmd_47[];
extern const s16 pc_cmd_00[];
extern const s16 pc_cmd_01[];
extern const s16 pc_cmd_02[];
extern const s16 pc_cmd_03[];
extern const s16 pc_cmd_04[];
extern const s16 pc_cmd_05[];
extern const s16 pc_cmd_06[];
extern const s16 pc_cmd_07[];
extern const s16 pc_cmd_08[];
extern const s16 pc_cmd_09[];
extern const s16 pc_cmd_10[];
extern const s16 pc_cmd_11[];
extern const s16 pc_cmd_12[];
extern const s16 pc_cmd_13[];
extern const s16 pc_cmd_14[];
extern const s16 pc_cmd_15[];

extern const s16* pl_cmd_list[][56];
extern void* pl_CMD[];
extern const_s16_arr* player_cmd[];
extern TMLINE player_cmd_lines[];
extern u16 player_cmd_cells[][2];
extern s16 lvr_chk_tbl[][4];
extern TMLINE lvr_chk_lines[];

/* 02006470 */
const s16* pl_cmd_list[16][56] = {
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p0_cmd_20, p0_cmd_21, p0_cmd_22, dm_cmd_xx, p0_cmd_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p0_cmd_28, p0_cmd_29, p0_cmd_30, p0_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p1_cmd_20, p1_cmd_21, p1_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p1_cmd_28, p1_cmd_29, p1_cmd_30, p1_cmd_31, p1_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_20, p2_cmd_21, p2_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_28, p2_cmd_29, p2_cmd_30, p2_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_46, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p3_cmd_20, p3_cmd_21, p3_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p3_cmd_28, p3_cmd_29, p3_cmd_30, p3_cmd_31, p3_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p4_cmd_20, p4_cmd_21, p4_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p4_cmd_28, p4_cmd_29, p4_cmd_30, p4_cmd_31, p4_cmd_32, p4_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p5_cmd_20, p5_cmd_21, p5_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p5_cmd_28, p5_cmd_29, p5_cmd_30, p5_cmd_31, p5_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p6_cmd_20, p6_cmd_21, p6_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p6_cmd_28, p6_cmd_29, p6_cmd_30, p6_cmd_32, p6_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_20, p7_cmd_21, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_28, p7_cmd_29, p7_cmd_30, p7_cmd_31, p7_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_38, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_46, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p8_cmd_20, p8_cmd_21, p8_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p8_cmd_28, p8_cmd_29, p8_cmd_30, p8_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_20, p9_cmd_22, p9_cmd_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_28, p9_cmd_29, p9_cmd_30, p9_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_46, p9_cmd_47, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pA_cmd_20, pA_cmd_21, pA_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pA_cmd_28, pA_cmd_32, pA_cmd_31, pA_cmd_30, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_20, pB_cmd_21, pB_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_28, pB_cmd_29, pB_cmd_30, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_46, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pC_cmd_20, pC_cmd_21, pC_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pC_cmd_28, pC_cmd_29, pC_cmd_30, pC_cmd_31, pC_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pD_cmd_20, pD_cmd_21, pD_cmd_22, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pD_cmd_28, pD_cmd_29, pD_cmd_30, pD_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_20, pE_cmd_21, pE_cmd_22, dm_cmd_xx, pE_cmd_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_28, pE_cmd_29, pE_cmd_30, pE_cmd_31, pE_cmd_32, pE_cmd_33, pE_cmd_34, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_38, pE_cmd_39, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_46, pE_cmd_47, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
    { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07, pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_20, pE_cmd_21, pE_cmd_22, dm_cmd_xx, pE_cmd_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_28, pE_cmd_29, pE_cmd_30, pE_cmd_31, pE_cmd_32, pE_cmd_33, pE_cmd_34, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_38, pE_cmd_39, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_46, pE_cmd_47, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx },
};
/* 02007270 */
void* pl_CMD[16] = {
    (void *)pl_cmd_list[0],
    (void *)pl_cmd_list[1],
    (void *)pl_cmd_list[2],
    (void *)pl_cmd_list[3],
    (void *)pl_cmd_list[4],
    (void *)pl_cmd_list[5],
    (void *)pl_cmd_list[6],
    (void *)pl_cmd_list[7],
    (void *)pl_cmd_list[8],
    (void *)pl_cmd_list[9],
    (void *)pl_cmd_list[10],
    (void *)pl_cmd_list[11],
    (void *)pl_cmd_list[12],
    (void *)pl_cmd_list[13],
    (void *)pl_cmd_list[14],
    (void *)pl_cmd_list[15],
};
/* 020072B0 */
const_s16_arr* player_cmd[16] = {
    pl_cmd_list[0],
    pl_cmd_list[1],
    pl_cmd_list[2],
    pl_cmd_list[3],
    pl_cmd_list[4],
    pl_cmd_list[5],
    pl_cmd_list[6],
    pl_cmd_list[7],
    pl_cmd_list[8],
    pl_cmd_list[9],
    pl_cmd_list[10],
    pl_cmd_list[11],
    pl_cmd_list[12],
    pl_cmd_list[13],
    pl_cmd_list[14],
    pl_cmd_list[15],
};
/* provisional name */
/* Text lines of the key-assignment display, stored after player_cmd. Nothing in the program refers to
   them. */
/* 020072F0 */
TMLINE player_cmd_lines[12] = {
    { 1, 0xC, 0xE, 0, (u8 *)player_cmd_line_str0 },
    { 1, 0xD, 0xE, 0, (u8 *)player_cmd_line_str1 },
    { 1, 0xE, 0xE, 0, (u8 *)player_cmd_line_str2 },
    { 1, 0xF, 0xE, 0, (u8 *)player_cmd_line_str3 },
    { 1, 0x10, 0xE, 0, (u8 *)player_cmd_line_str4 },
    { 0xC, 0x11, 0xE, 0, (u8 *)player_cmd_line_str5 },
    { 0x17, 0xC, 0xE, 0, (u8 *)player_cmd_line_str0 },
    { 0x17, 0xD, 0xE, 0, (u8 *)player_cmd_line_str1 },
    { 0x17, 0xE, 0xE, 0, (u8 *)player_cmd_line_str2 },
    { 0x17, 0xF, 0xE, 0, (u8 *)player_cmd_line_str3 },
    { 0x17, 0x10, 0xE, 0, (u8 *)player_cmd_line_str4 },
    { 0x22, 0x11, 0xE, 0, (u8 *)player_cmd_line_str6 },
};
/* provisional name */
/* Stored after player_cmd_lines: (x, y) cell positions. Nothing in the program refers to it. */
/* 02007380 */
u16 player_cmd_cells[28][2] = {
    { 0xB, 3 }, { 0x1A, 3 }, { 0xB, 7 }, { 0x1A, 7 }, { 0xF, 3 }, { 0x1E, 3 }, { 0xF, 7 }, { 0x1E, 7 },
    { 0xD, 3 }, { 0x1C, 3 }, { 0xD, 7 }, { 0x1C, 7 }, { 0xB, 5 }, { 0x1A, 5 }, { 0xF, 5 }, { 0x1E, 5 },
    { 0xB, 9 }, { 0x1A, 9 }, { 0xD, 9 }, { 0x1C, 9 }, { 0xF, 9 }, { 0x1E, 9 }, { 0xB, 0xA }, { 0x1A, 0xA },
    { 0xD, 0xA }, { 0x1C, 0xA }, { 0xF, 0xA }, { 0x1E, 0xA },
};
/* 020073F0 */
s16 lvr_chk_tbl[2][4] = {
    { 5, 6, 9, 10 }, { 1, 2, 4, 8 },
};
/* provisional name */
/* Text lines of the lever-check display, stored after lvr_chk_tbl. Nothing in the program refers to them. */
/* 02007400 */
TMLINE lvr_chk_lines[6] = {
    { 6, 0x13, 6, 0, (u8 *)lvr_chk_line_str0 },
    { 6, 0x13, 6, 0, (u8 *)lvr_chk_line_str1 },
    { 6, 0x13, 6, 0, (u8 *)lvr_chk_line_str2 },
    { 0x1D, 0x13, 6, 0, (u8 *)lvr_chk_line_str0 },
    { 0x1D, 0x13, 6, 0, (u8 *)lvr_chk_line_str1 },
    { 0x1D, 0x13, 6, 0, (u8 *)lvr_chk_line_str2 },
};

T_PL_LVR t_pl_lvr[2];  /* 02020BF0 */
WAZA_WORK waza_work[2][56];  /* 02020C78 */
u8 waza_work_tail[2];  /* after waza_work; nothing refers to it by name or address */
u16 sw_work;  /* 020218BA */
s16* cmd_tbl_ptr;  /* 020218BC */
s16 waza_type[2];  /* 020218C0 */
T_PL_LVR* chk_pl;  /* 020218C4 */
WAZA_WORK* waza_ptr;  /* 020218C8 */
WORK_CP wcp[2];  /* 020218CC */
s16 cmd_id;  /* 020220D8 */
PLW* cmd_pl;  /* 020220DC */
u8 cmd_pl_tail[4];  /* after cmd_pl; nothing refers to it by name or address */
s16 eff_hit_flag[11];  /* 020220E4 */
