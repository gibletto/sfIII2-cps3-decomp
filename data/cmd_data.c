/*
 * CMD_DATA.C  command input records
 *
 * The fighters' command records (format in CMD_DATA.H): pc_cmd_00 - 15 are shared by every
 * fighter (dashes, high jump, parries, button mashing, down-down inputs), the pN_cmd_ records
 * are each fighter's special moves and super arts, and dm_cmd_xx fills the unused slots. They
 * are reached through pl_cmd_list in CMD_WORK.C (56 slots per fighter), which pl_CMD hands to
 * the command input check in CMD_MAIN_2.C and player_cmd to the computer player in COM_PL.C
 * and COM_SUB.C. CMD_MAIN_2.C also reads pl_cmd_num (where each fighter's slot groups end),
 * lever_gacha_tbl (the number of bits set in a nibble, for mashing) and ukemi_time_tbl
 * (recovery-roll input timing). p11_cmd_31 is the tail of pE_cmd_33's record.
 * player_cmd_line_str0 - 6 and lvr_chk_line_str0 - 2 are the text of the key-assignment and
 * lever-check displays, listed in player_cmd_lines and lvr_chk_lines of CMD_WORK.C, which
 * nothing reads.
 */

/*
 * Record format (CMD_DATA.H names every field and flag): a 12-word header, then 4-word steps,
 * then CMD_END.  Ryu's Hadoken, 236+P:
 *
 *   CMD_RESET, CMD_LV_UP, 0,          reset: once entered, the command waits 12 frames for the
 *                                     move to start; dead, dead2: holding up (a jump) drops it
 *   CMD_WAZA(RYU_HADOKEN),            rno[4]: the attack routine each strength starts
 *   CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL,   btix: the button is a new press, there is an EX
 *                                     version, and not while the fireball is out
 *   CMD_EX_PUNCHES,                   exdt[4]: LP, MP, HP, and two punches for the EX version
 *   CMD_LEVER(0, CMD_LV_DOWN),        steps: down,
 *   CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),   down-forward within 10 frames,
 *   CMD_LEVER(10, CMD_LV_FORWARD),    forward within 10 frames
 *   CMD_END,
 */

#include "types.h"
#include "structs.h"
#include "cmd_data.h"

#pragma section TBL

extern const s16 lever_gacha_tbl[];
extern const s16 pl_cmd_num[][7];
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
extern const s16 p3_cmd_30[];
extern const s16 p3_cmd_31[];
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
extern const s16 p6_cmd_29[];
extern const s16 p6_cmd_30[];
extern const s16 p6_cmd_32[];
extern const s16 p6_cmd_33[];
extern const s16 p7_cmd_20[];
extern const s16 p7_cmd_21[];
extern const s16 p7_cmd_38[];
extern const s16 p7_cmd_28[];
extern const s16 p7_cmd_29[];
extern const s16 p7_cmd_30[];
extern const s16 p7_cmd_31[];
extern const s16 p7_cmd_32[];
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
extern const s16 pA_cmd_32[];
extern const s16 pA_cmd_31[];
extern const s16 pA_cmd_30[];
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
extern const s16 p11_cmd_31[];
extern const s16 pE_cmd_34[];
extern const s16 pE_cmd_38[];
extern const s16 pE_cmd_39[];
extern const s16 pE_cmd_46[];
extern const s16 pE_cmd_47[];
extern const s16 ukemi_time_tbl[];
extern const char player_cmd_line_str0[];
extern const char player_cmd_line_str1[];
extern const char player_cmd_line_str2[];
extern const char player_cmd_line_str3[];
extern const char player_cmd_line_str4[];
extern const char player_cmd_line_str5[];
extern const char player_cmd_line_str6[];
extern const char lvr_chk_line_str0[];
extern const char lvr_chk_line_str1[];
extern const char lvr_chk_line_str2[];

const s16 lever_gacha_tbl[16] = {
    0, 1, 1, 2, 1, 2, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4,
};

const s16 pl_cmd_num[16][7] = {
    { 16, 23, 25, 32, 38, 42, 46 },  /* Gill */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Alex */
    { 16, 23, 24, 32, 38, 42, 47 },  /* Ryu */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Yun */
    { 16, 23, 24, 34, 38, 42, 46 },  /* Dudley */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Necro */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Hugo */
    { 16, 22, 24, 33, 39, 42, 47 },  /* Ibuki */
    { 16, 23, 24, 32, 38, 42, 46 },  /* Elena */
    { 16, 23, 24, 32, 38, 42, 48 },  /* Oro */
    { 16, 23, 24, 32, 38, 42, 46 },  /* Yang */
    { 16, 23, 24, 31, 38, 42, 47 },  /* Ken */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Sean */
    { 16, 23, 24, 32, 38, 42, 46 },  /* Urien */
    { 16, 23, 25, 35, 40, 42, 48 },  /* Gouki */
    { 16, 23, 25, 35, 40, 42, 48 },  /* Shin Gouki */
};

/* The comment on each record names the move from the published move lists, checked against its
   motion, buttons, slot group and the plNN_exatt_table routine its rno starts; (?) marks a guess.
   A super art's number (SA I - III) is the one whose super_arts_data entry (PLCNT_tbl.c) names the
   record's slot; the slot order is not the super art order. The input after the name is in numpad
   notation (2 down, 6 forward, [4]6 charge back then forward), as the record's steps accept it. */
const s16 pc_cmd_00[29] = {  /* forward dash */
    8, CMD_LV_BACK, CMD_LV_DOWN, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER, 1, 1, CMD_LV_FORWARD),
    CMD_LEVER_ANY(6, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_SET, 6, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_STEP(CK_LEVER_REPEAT, 6, 6, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_END,
};

const s16 pc_cmd_01[29] = {  /* back dash */
    8, CMD_LV_FORWARD, CMD_LV_DOWN, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_LEVER_ANY(1, CMD_LV_BACK),
    CMD_LEVER_ANY(6, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_SET, 6, 0, CMD_EXACT(CMD_LV_BACK)),
    CMD_STEP(CK_LEVER_REPEAT, 6, 6, CMD_EXACT(CMD_LV_BACK)),
    CMD_END,
};

const s16 pc_cmd_02[21] = {  /* high jump */
    8, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER_NEW, 1, 0, CMD_LV_DOWN),
    CMD_STEP(CK_LEVER_NEW, 8, 0, CMD_LV_UP),
    CMD_END,
};

const s16 pc_cmd_03[17] = {  /* parry (forward) */
    10, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pc_cmd_04[17] = {  /* low parry (down) */
    10, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_DOWN),
    CMD_END,
};

const s16 pc_cmd_05[17] = {  /* air parry (forward) */
    8, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pc_cmd_06[17] = {  /* air parry (down) */
    8, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_DOWN),
    CMD_END,
};

const s16 pc_cmd_07[17] = {  /* red parry window (down) (?) */
    2, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY_STRICT, 8, 0, CMD_LV_DOWN),
    CMD_END,
};

const s16 pc_cmd_08[17] = {  /* punch mashing */
    7, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_RENDA3, 48, 48, CMD_SW_LP),
    CMD_END,
};

const s16 pc_cmd_09[17] = {  /* punch mashing, longer window */
    11, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_RENDA3, 72, 72, CMD_SW_LP),
    CMD_END,
};

const s16 pc_cmd_10[17] = {  /* kick mashing */
    7, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_RENDA3, 48, 48, CMD_SW_LK),
    CMD_END,
};

const s16 pc_cmd_11[17] = {  /* kick mashing, longer window */
    11, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_RENDA3, 72, 72, CMD_SW_LK),
    CMD_END,
};

const s16 pc_cmd_12[17] = {  /* parry (forward), short hold */
    6, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pc_cmd_13[25] = {  /* down, down */
    4, CMD_LV_UP, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};

const s16 pc_cmd_14[25] = {  /* down, down + punch */
    CMD_RESET, CMD_LV_UP, 0, 10, 10, 10, 10, CMD_BT_NOW, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};

const s16 pc_cmd_15[25] = {  /* down, down + kick */
    CMD_RESET, CMD_LV_UP, 0, 10, 10, 10, 10, CMD_BT_NOW, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};

const s16 dm_cmd_xx[25] = {  /* unused slot (a dummy fireball motion) */
    CMD_RESET, 0, 0, 0, 0, 0, 0, CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Gill's attack routines (routine_no[2]; 16 and up index pl00_exatt_table) */
#define GILL_PYROKINESIS          16  /* Att_HADOUKEN */
#define GILL_MOONSAULT_KNEE_DROP  17  /* Att_MOONSALT_KNEE_DROP */
#define GILL_CYBER_LARIAT         18  /* Att_SLIDE_and_JUMP */
#define GILL_PSYCHO_HEADBUTT      19  /* Att_SENPUUKYAKU */
#define GILL_METEOR_STRIKE        20  /* Att_HADOUKEN */
#define GILL_RESURRECTION         21  /* Att_RESURRECTION */

const s16 p0_cmd_20[13] = {  /* Gill: super art slot, disabled */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_RESURRECTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled; check_init reads the rest of the step from the next record */
};

const s16 p0_cmd_21[13] = {  /* Gill: super art slot, disabled */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_RESURRECTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled; check_init reads the rest of the step from the next record */
};

const s16 p0_cmd_22[13] = {  /* Gill: super art slot, disabled */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_RESURRECTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled; check_init reads the rest of the step from the next record */
};

const s16 p0_cmd_24[33] = {  /* Gill: Meteor Strike, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_METEOR_STRIKE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p0_cmd_28[25] = {  /* Gill: Cyber Lariat, 623+P */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_CYBER_LARIAT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p0_cmd_29[25] = {  /* Gill: Moonsault Knee Drop, 63214+K */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_MOONSAULT_KNEE_DROP), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p0_cmd_30[25] = {  /* Gill: Pyrokinesis, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GILL_PYROKINESIS), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p0_cmd_31[25] = {  /* Gill: Psycho Headbutt, 214+P */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_PSYCHO_HEADBUTT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Alex's attack routines (routine_no[2]; 16 and up index pl01_exatt_table) */
#define ALEX_FLASH_CHOP         16  /* Att_CHOUCHUURENGEKI */
#define ALEX_AIR_KNEE_SMASH     17  /* Att_SHOURYUUKEN */
#define ALEX_POWER_BOMB         18  /* Att_HADOUKEN */
#define ALEX_HYPER_BOMB         19  /* Att_HADOUKEN2 */
#define ALEX_BOOMERANG_RAID     20  /* Att_CHOUCHUURENGEKI */
#define ALEX_STUN_GUN_HEADBUTT  21  /* Att_SENPUUKYAKU2 */
#define ALEX_AIR_STAMPEDE       22  /* Att_SENPUUKYAKU */
#define ALEX_AIR_STAMPEDE_EX    25  /* Att_HOMING_JUMP */
#define ALEX_SLASH_ELBOW        26  /* Att_SLIDE_and_JUMP */

const s16 p1_cmd_20[17] = {  /* Alex: SA I Hyper Bomb, 360+P */
    CMD_RESET, 0, 0, CMD_WAZA(ALEX_HYPER_BOMB), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};

const s16 p1_cmd_21[33] = {  /* Alex: SA II Boomerang Raid, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ALEX_BOOMERANG_RAID), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p1_cmd_22[33] = {  /* Alex: SA III Stun Gun Headbutt, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ALEX_STUN_GUN_HEADBUTT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p1_cmd_28[25] = {  /* Alex: Air Knee Smash, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_AIR_KNEE_SMASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p1_cmd_29[25] = {  /* Alex: Power Bomb, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_POWER_BOMB), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p1_cmd_30[25] = {  /* Alex: Flash Chop, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_FLASH_CHOP), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p1_cmd_31[21] = {  /* Alex: Air Stampede, [2]8+K */
    CMD_RESET, 0, 0, CMD_WAZA_EX(ALEX_AIR_STAMPEDE, ALEX_AIR_STAMPEDE_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};

const s16 p1_cmd_32[21] = {  /* Alex: Slash Elbow, [4]6+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_SLASH_ELBOW), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Ryu's attack routines (routine_no[2]; 16 and up index pl02_exatt_table) */
#define RYU_HADOKEN                   16  /* Att_HADOUKEN */
#define RYU_SHORYUKEN                 17  /* Att_SHOURYUUKEN */
#define RYU_TATSUMAKI_SENPUKYAKU      18  /* Att_SENPUUKYAKU */
#define RYU_SHINKUU_HADOKEN           19  /* Att_HADOUKEN */
#define RYU_SHIN_SHORYUKEN            20  /* Att_SHINSHOURYUUKEN */
#define RYU_DENJIN_HADOKEN            21  /* Att_DENJINHADOUKEN */
#define RYU_AIR_TATSUMAKI_SENPUKYAKU  22  /* Att_KUUCHUUNICHIRINSHOU */
#define RYU_JOUDAN_SOKUTOU_GERI       23  /* Att_SLIDE_and_JUMP */

const s16 p2_cmd_20[33] = {  /* Ryu: SA I Shinkuu Hadoken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(RYU_SHINKUU_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p2_cmd_21[33] = {  /* Ryu: SA III Denjin Hadoken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(RYU_DENJIN_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p2_cmd_22[33] = {  /* Ryu: SA II Shin Shoryuken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(RYU_SHIN_SHORYUKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p2_cmd_28[25] = {  /* Ryu: Shoryuken, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_SHORYUKEN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p2_cmd_29[25] = {  /* Ryu: Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_HADOKEN), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p2_cmd_30[25] = {  /* Ryu: Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 p2_cmd_31[29] = {  /* Ryu: Joudan Sokutou Geri, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_JOUDAN_SOKUTOU_GERI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p2_cmd_46[25] = {  /* Ryu: air Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_AIR_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Yun's attack routines (routine_no[2]; 16 and up index pl03_exatt_table) */
#define YUN_KOBOKUSHI       16  /* Att_HADOUKEN */
#define YUN_SENKYUUTAI      17  /* Att_TENSHINSENKYUUTAI */
#define YUN_ZESSHOU_HOHOU   18  /* Att_SENPUUKYAKU */
#define YUN_GENEI_JIN       19  /* Att_HADOUKEN */
#define YUN_SOURAI_RENGEKI  20  /* Att_SLIDE_and_JUMP */
#define YUN_YOU_HOU         21  /* Att_SLIDE_and_JUMP */
#define YUN_ZENPOU_TENSHIN  22  /* Att_HADOUKEN */
#define YUN_TETSUZAN_KOU    24  /* Att_SLIDE_and_JUMP */

const s16 p3_cmd_20[33] = {  /* Yun: SA III Genei Jin, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YUN_GENEI_JIN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p3_cmd_21[33] = {  /* Yun: SA II Sourai Rengeki, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YUN_SOURAI_RENGEKI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p3_cmd_22[33] = {  /* Yun: SA I You Hou, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YUN_YOU_HOU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p3_cmd_28[25] = {  /* Yun: Zenpou Tenshin, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_ZENPOU_TENSHIN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p3_cmd_29[25] = {  /* Yun: Tetsuzan Kou, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_TETSUZAN_KOU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

/* provisional name */
const s16 p3_cmd_30[25] = {  /* Yun: Kobokushi (two punches: the feint), 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_KOBOKUSHI), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* provisional name */
const s16 p3_cmd_31[25] = {  /* Yun: Senkyuutai, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_SENKYUUTAI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p3_cmd_32[25] = {  /* Yun: Zesshou Hohou, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_ZESSHOU_HOHOU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Dudley's attack routines (routine_no[2]; 16 and up index pl04_exatt_table) */
#define DUDLEY_JET_UPPER                16  /* Att_SENPUUKYAKU */
#define DUDLEY_MACHINE_GUN_BLOW         17  /* Att_SENPUUKYAKU */
#define DUDLEY_CROSS_COUNTER            18  /* Att_HADOUKEN */
#define DUDLEY_ROCKET_UPPERCUT          19  /* Att_SHOURYUUREPPA */
#define DUDLEY_ROLLING_THUNDER          20  /* Att_HADOUKEN2 */
#define DUDLEY_CORKSCREW_BLOW           21  /* Att_CHOUCHUURENGEKI */
#define DUDLEY_DUCKING                  22  /* Att_CHOUCHUURENGEKI */
#define DUDLEY_THUNDERBOLT              23  /* Att_SLIDE_and_JUMP */
#define DUDLEY_PUNCH_AND_CROSS_COUNTER  25  /* Att_HADOUKEN */
#define DUDLEY_THUNDERBOLT_EX           28  /* Att_HOMING_JUMP */

const s16 p4_cmd_20[33] = {  /* Dudley: SA I Rocket Uppercut, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(DUDLEY_ROCKET_UPPERCUT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_21[33] = {  /* Dudley: SA II Rolling Thunder, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(DUDLEY_ROLLING_THUNDER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_22[33] = {  /* Dudley: SA III Corkscrew Blow, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(DUDLEY_CORKSCREW_BLOW), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_28[25] = {  /* Dudley: Jet Upper, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_JET_UPPER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_29[33] = {  /* Dudley: Punch and Cross Counter, 6321456+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_PUNCH_AND_CROSS_COUNTER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_NEUTRAL),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_30[25] = {  /* Dudley: Cross Counter, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_CROSS_COUNTER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p4_cmd_31[25] = {  /* Dudley: Machine Gun Blow, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_MACHINE_GUN_BLOW), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_32[25] = {  /* Dudley: Ducking, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_DUCKING), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p4_cmd_33[25] = {  /* Dudley: Thunderbolt, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(DUDLEY_THUNDERBOLT, DUDLEY_THUNDERBOLT_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Necro's attack routines (routine_no[2]; 16 and up index pl05_exatt_table) */
#define NECRO_TORNADO_HOOK     16  /* Att_CHOUCHUURENGEKI */
#define NECRO_DENJI_BLAST      17  /* Att_HADOUKEN */
#define NECRO_MAGNETIC_STORM   18  /* Att_HADOUKEN */
#define NECRO_SNAKE_FANG       19  /* Att_HADOUKEN */
#define NECRO_ELECTRIC_SNAKE   20  /* Att_HADOUKEN */
#define NECRO_FLYING_VIPER     21  /* Att_SENPUUKYAKU */
#define NECRO_SLAM_DANCE       22  /* Att_HADOUKEN */
#define NECRO_RISING_COBRA     24  /* Att_HADOUKEN */
#define NECRO_FLYING_VIPER_EX  25  /* Att_JINNCHUUWATARI */
#define NECRO_RISING_COBRA_EX  26  /* Att_SLIDE_and_JUMP */

const s16 p5_cmd_20[33] = {  /* Necro: SA I Magnetic Storm, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_MAGNETIC_STORM), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p5_cmd_21[33] = {  /* Necro: SA III Electric Snake, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_ELECTRIC_SNAKE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p5_cmd_22[33] = {  /* Necro: SA II Slam Dance, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_SLAM_DANCE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p5_cmd_28[29] = {  /* Necro: Snake Fang, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(NECRO_SNAKE_FANG), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p5_cmd_29[25] = {  /* Necro: Denji Blast, 623+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_DENJI_BLAST), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p5_cmd_30[29] = {  /* Necro: Tornado Hook, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(NECRO_TORNADO_HOOK), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p5_cmd_31[25] = {  /* Necro: Flying Viper, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(NECRO_FLYING_VIPER, NECRO_FLYING_VIPER_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 p5_cmd_32[25] = {  /* Necro: Rising Cobra, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(NECRO_RISING_COBRA, NECRO_RISING_COBRA_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Hugo's attack routines (routine_no[2]; 16 and up index pl06_exatt_table) */
#define HUGO_GIANT_PALM_BOMBER      16  /* Att_HADOUKEN2 */
#define HUGO_MOONSAULT_PRESS        17  /* Att_HADOUKEN2 */
#define HUGO_MONSTER_LARIAT         18  /* Att_CHOUCHUURENGEKI */
#define HUGO_ULTRA_THROW            19  /* Att_HADOUKEN2 */
#define HUGO_SHOOTDOWN_BACKBREAKER  20  /* Att_SHOURYUUKEN */
#define HUGO_HAMMER_FRENZY          21  /* Att_SLIDE_and_JUMP */
#define HUGO_GIGAS_BREAKER          22  /* Att_HADOUKEN2 */
#define HUGO_MEGATON_PRESS          23  /* Att_SHOURYUUKEN */
#define HUGO_MONSTER_LARIAT_EX      25  /* Att_TENSHINSENKYUUTAI */

const s16 p6_cmd_20[21] = {  /* Hugo: SA I Gigas Breaker, 720+P */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_GIGAS_BREAKER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};

const s16 p6_cmd_21[33] = {  /* Hugo: SA II Megaton Press, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_MEGATON_PRESS), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p6_cmd_22[33] = {  /* Hugo: SA III Hammer Frenzy, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_HAMMER_FRENZY), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p6_cmd_28[17] = {  /* Hugo: Moonsault Press, 360+P */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_MOONSAULT_PRESS), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};

/* provisional name */
const s16 p6_cmd_29[25] = {  /* Hugo: Shootdown Backbreaker, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(HUGO_SHOOTDOWN_BACKBREAKER), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

/* provisional name */
const s16 p6_cmd_30[25] = {  /* Hugo: Giant Palm Bomber, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(HUGO_GIANT_PALM_BOMBER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 p6_cmd_32[25] = {  /* Hugo: Monster Lariat, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(HUGO_MONSTER_LARIAT, HUGO_MONSTER_LARIAT_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p6_cmd_33[25] = {  /* Hugo: Ultra Throw, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(HUGO_ULTRA_THROW), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

/* Ibuki's attack routines (routine_no[2]; 16 and up index pl07_exatt_table) */
#define IBUKI_KAZEKIRI       16  /* Att_SHOURYUUKEN */
#define IBUKI_KUBI_ORI       17  /* Att_PL07_AT1 */
#define IBUKI_RAIDA          18  /* Att_CHOUCHUURENGEKI */
#define IBUKI_HASHIN_SHO     19  /* Att_CHOUCHUURENGEKI */
#define IBUKI_TSUMUJI        20  /* Att_CHOUCHUURENGEKI */
#define IBUKI_YOROI_DOSHI    21  /* Att_PL07_SA2 */
#define IBUKI_HIEN           22  /* Att_PL07_AT2 */
#define IBUKI_KUNAI          23  /* Att_PL07_AT3 */
#define IBUKI_KASUMI_SUZAKU  24  /* Att_PL07_SA3 */
#define IBUKI_HIEN_EX        26  /* Att_HOMING_JUMP */

const s16 p7_cmd_20[33] = {  /* Ibuki: SA III Hashin Sho, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(IBUKI_HASHIN_SHO), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p7_cmd_21[33] = {  /* Ibuki: SA II Yoroi Doshi, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(IBUKI_YOROI_DOSHI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p7_cmd_38[33] = {  /* Ibuki: SA I Kasumi Suzaku (air), 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(IBUKI_KASUMI_SUZAKU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p7_cmd_28[25] = {  /* Ibuki: Kazekiri, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_KAZEKIRI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p7_cmd_29[25] = {  /* Ibuki: Raida, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_RAIDA), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p7_cmd_30[25] = {  /* Ibuki: Hien, 421+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(IBUKI_HIEN, IBUKI_HIEN_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_END,
};

/* provisional name */
const s16 p7_cmd_31[25] = {  /* Ibuki: Kubi Ori, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_KUBI_ORI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* provisional name */
const s16 p7_cmd_32[25] = {  /* Ibuki: Tsumuji, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_TSUMUJI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 p7_cmd_46[25] = {  /* Ibuki: Kunai (air), 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_KUNAI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Elena's attack routines (routine_no[2]; 16 and up index pl08_exatt_table) */
#define ELENA_SCRATCH_WHEEL  16  /* Att_SHOURYUUKEN */
#define ELENA_RHINO_HORN     17  /* Att_SENPUUKYAKU */
#define ELENA_MALLET_SMASH   18  /* Att_SENPUUKYAKU */
#define ELENA_SPINNING_BEAT  19  /* Att_SHOURYUUREPPA */
#define ELENA_BRAVE_DANCE    20  /* Att_SHOURYUUREPPA */
#define ELENA_HEALING        21  /* Att_PL08_HEALING */
#define ELENA_SPIN_SCYTHE    23  /* Att_SLIDE_and_JUMP */

const s16 p8_cmd_20[33] = {  /* Elena: SA I Spinning Beat, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(ELENA_SPINNING_BEAT), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p8_cmd_21[33] = {  /* Elena: SA II Brave Dance, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(ELENA_BRAVE_DANCE), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p8_cmd_22[33] = {  /* Elena: SA III Healing, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ELENA_HEALING), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p8_cmd_28[25] = {  /* Elena: Scratch Wheel, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_SCRATCH_WHEEL), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p8_cmd_29[25] = {  /* Elena: Rhino Horn, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_RHINO_HORN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p8_cmd_30[25] = {  /* Elena: Mallet Smash, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_MALLET_SMASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p8_cmd_32[25] = {  /* Elena: Spin Scythe, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_SPIN_SCYTHE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Oro's attack routines (routine_no[2]; 16 and up index pl09_exatt_table) */
#define ORO_NICHIRIN_SHOU       16  /* Att_HADOUKEN */
#define ORO_ONI_YANMA           17  /* Att_SHOURYUUKEN */
#define ORO_AIR_NICHIRIN_SHOU   18  /* Att_KUUCHUUNICHIRINSHOU */
#define ORO_NIOU_RIKI           19  /* Att_HADOUKEN */
#define ORO_TENGU_STONE         20  /* Att_HADOUKEN */
#define ORO_YAGYOU_DAMA         21  /* Att_HADOUKEN */
#define ORO_KISHIN_RIKI         22  /* Att_HADOUKEN */
#define ORO_AIR_JINCHUU_WATARI  23  /* Att_KUUCHUUJINNCHUUWATARI */
#define ORO_JINCHUU_WATARI      24  /* Att_JINNCHUUWATARI */
#define ORO_JINCHUU_WATARI_EX   25  /* Att_JINNCHUUWATARI_EX */

const s16 p9_cmd_20[33] = {  /* Oro: SA III Tengu Stone, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_TENGU_STONE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p9_cmd_22[33] = {  /* Oro: SA II Yagyou Dama, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_YAGYOU_DAMA), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p9_cmd_24[33] = {  /* Oro: SA I Kishin Riki, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_KISHIN_RIKI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 p9_cmd_28[21] = {  /* Oro: Oni Yanma, [2]8+P */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_ONI_YANMA), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};

const s16 p9_cmd_29[25] = {  /* Oro: Niou Riki, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_NIOU_RIKI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 p9_cmd_30[21] = {  /* Oro: Nichirin Shou, [4]6+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_NICHIRIN_SHOU), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p9_cmd_31[25] = {  /* Oro: Jinchuu Watari, 236+K */
    CMD_RESET, 0, 0, CMD_WAZA_EX(ORO_JINCHUU_WATARI, ORO_JINCHUU_WATARI_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p9_cmd_46[26] = {  /* Oro: air Nichirin Shou, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_AIR_NICHIRIN_SHOU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled: placed ahead of the steps below */
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 p9_cmd_47[25] = {  /* Oro: air Jinchuu Watari, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_AIR_JINCHUU_WATARI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Yang's attack routines (routine_no[2]; 16 and up index pl10_exatt_table) */
#define YANG_BYAKKO_SOUSHOUDA    16  /* Att_HADOUKEN */
#define YANG_SENKYUUTAI          17  /* Att_TENSHINSENKYUUTAI */
#define YANG_TOUROU_ZAN          18  /* Att_SLIDE_and_JUMP */
#define YANG_SEI_EI_ENBU         19  /* Att_HADOUKEN */
#define YANG_RAISHIN_MAHHAKEN    20  /* Att_SLIDE_and_JUMP */
#define YANG_TENSHIN_SENKYUUTAI  21  /* Att_TENSHINSENKYUUTAI */
#define YANG_ZENPOU_TENSHIN      22  /* Att_HADOUKEN */

const s16 pA_cmd_20[33] = {  /* Yang: SA III Sei-ei Enbu, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YANG_SEI_EI_ENBU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pA_cmd_21[33] = {  /* Yang: SA I Raishin Mahhaken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YANG_RAISHIN_MAHHAKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pA_cmd_22[33] = {  /* Yang: SA II Tenshin Senkyuutai, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(YANG_TENSHIN_SENKYUUTAI), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pA_cmd_28[25] = {  /* Yang: Zenpou Tenshin, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_ZENPOU_TENSHIN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

const s16 pA_cmd_32[25] = {  /* Yang: Byakko Soushouda, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_BYAKKO_SOUSHOUDA), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 pA_cmd_31[25] = {  /* Yang: Senkyuutai, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_SENKYUUTAI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pA_cmd_30[25] = {  /* Yang: Tourou Zan, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_TOUROU_ZAN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Ken's attack routines (routine_no[2]; 16 and up index pl11_exatt_table) */
#define KEN_HADOKEN                   16  /* Att_HADOUKEN */
#define KEN_SHORYUKEN                 17  /* Att_SHOURYUUKEN */
#define KEN_TATSUMAKI_SENPUKYAKU      18  /* Att_SENPUUKYAKU */
#define KEN_SHORYU_REPPA              19  /* Att_SHOURYUUREPPA */
#define KEN_SHINRYUKEN                20  /* Att_SHOURYUUREPPA */
#define KEN_SHIPPU_JINRAIKYAKU        21  /* Att_SLIDE_and_JUMP */
#define KEN_AIR_TATSUMAKI_SENPUKYAKU  22  /* Att_KUUCHUUNICHIRINSHOU */

const s16 pB_cmd_20[33] = {  /* Ken: SA I Shoryu Reppa, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(KEN_SHORYU_REPPA), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pB_cmd_21[33] = {  /* Ken: SA II Shinryuken, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(KEN_SHINRYUKEN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pB_cmd_22[33] = {  /* Ken: SA III Shippu Jinraikyaku, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(KEN_SHIPPU_JINRAIKYAKU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pB_cmd_28[25] = {  /* Ken: Shoryuken, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_SHORYUKEN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pB_cmd_29[25] = {  /* Ken: Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_HADOKEN), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pB_cmd_30[25] = {  /* Ken: Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 pB_cmd_46[25] = {  /* Ken: air Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_AIR_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Sean's attack routines (routine_no[2]; 16 and up index pl12_exatt_table) */
#define SEAN_HADOU_BURST      16  /* Att_HADOUKEN */
#define SEAN_SHORYU_CANNON    17  /* Att_SHOURYUUREPPA */
#define SEAN_HYPER_TORNADO    18  /* Att_SLIDE_and_JUMP */
#define SEAN_RYUUBI_KYAKU     19  /* Att_ABISEGERI */
#define SEAN_ZENPOU_TENSHIN   20  /* Att_CHOUCHUURENGEKI */
#define SEAN_TORNADO          21  /* Att_SHOURYUUKEN */
#define SEAN_SEAN_TACKLE      22  /* Att_CHOUCHUURENGEKI */
#define SEAN_DRAGON_SMASH     24  /* Att_SENPUUKYAKU */
#define SEAN_RYUUBI_KYAKU_EX  25  /* Att_HOMING_JUMP */

const s16 pC_cmd_20[33] = {  /* Sean: SA I Hadou Burst, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(SEAN_HADOU_BURST), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pC_cmd_21[33] = {  /* Sean: SA II Shoryu Cannon, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(SEAN_SHORYU_CANNON), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pC_cmd_22[33] = {  /* Sean: SA III Hyper Tornado, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(SEAN_HYPER_TORNADO), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pC_cmd_28[25] = {  /* Sean: Sean Tackle, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_SEAN_TACKLE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pC_cmd_29[25] = {  /* Sean: Dragon Smash, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_DRAGON_SMASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pC_cmd_30[25] = {  /* Sean: Ryuubi Kyaku, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(SEAN_RYUUBI_KYAKU, SEAN_RYUUBI_KYAKU_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pC_cmd_31[25] = {  /* Sean: Zenpou Tenshin (forward roll), 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_ZENPOU_TENSHIN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 pC_cmd_32[25] = {  /* Sean: Tornado, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_TORNADO), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Urien's attack routines (routine_no[2]; 16 and up index pl13_exatt_table) */
#define URIEN_METALLIC_SPHERE        16  /* Att_HADOUKEN */
#define URIEN_VIOLENCE_KNEE_DROP_EX  17  /* Att_MOONSALT_KNEE_DROP2 */
#define URIEN_DANGEROUS_HEADBUTT     19  /* Att_SENPUUKYAKU */
#define URIEN_TYRANT_SLAUGHTER       20  /* Att_CHOUCHUURENGEKI */
#define URIEN_TEMPORAL_THUNDER       21  /* Att_CHOUCHUURENGEKI */
#define URIEN_AEGIS_REFLECTOR        22  /* Att_HADOUKEN */
#define URIEN_CHARIOT_TACKLE         23  /* Att_CHOUCHUURENGEKI */
#define URIEN_VIOLENCE_KNEE_DROP     24  /* Att_SLIDE_and_JUMP */

const s16 pD_cmd_20[33] = {  /* Urien: SA I Tyrant Slaughter, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_TYRANT_SLAUGHTER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pD_cmd_21[33] = {  /* Urien: SA II Temporal Thunder, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_TEMPORAL_THUNDER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pD_cmd_22[33] = {  /* Urien: SA III Aegis Reflector, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_AEGIS_REFLECTOR), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pD_cmd_28[21] = {  /* Urien: Chariot Tackle, [4]6+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(URIEN_CHARIOT_TACKLE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pD_cmd_29[21] = {  /* Urien: Violence Knee Drop, [2]8+K */
    CMD_RESET, 0, 0, CMD_WAZA_EX(URIEN_VIOLENCE_KNEE_DROP, URIEN_VIOLENCE_KNEE_DROP_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};

const s16 pD_cmd_30[25] = {  /* Urien: Metallic Sphere, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(URIEN_METALLIC_SPHERE), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pD_cmd_31[21] = {  /* Urien: Dangerous Headbutt, [2]8+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_DANGEROUS_HEADBUTT), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};

/* Gouki's attack routines (routine_no[2]; 16 and up index pl14_exatt_table) */
#define GOUKI_GOU_HADOKEN                16  /* Att_HADOUKEN */
#define GOUKI_GOU_SHORYUKEN              17  /* Att_SHOURYUUKEN */
#define GOUKI_TATSUMAKI_ZANKUUKYAKU      18  /* Att_SENPUUKYAKU */
#define GOUKI_MESSATSU_GOU_SENPUU        19  /* Att_KUUCHUUJINNCHUUWATARI */
#define GOUKI_MESSATSU_GOU_SHORYU        20  /* Att_SHOURYUUREPPA */
#define GOUKI_ZENPOU_TENSHIN             21  /* Att_SLIDE_and_JUMP */
#define GOUKI_AIR_TATSUMAKI_ZANKUUKYAKU  22  /* Att_KUUCHUUNICHIRINSHOU */
#define GOUKI_ZANKU_HADOKEN              25  /* Att_PL14_AT2 */

const s16 pE_cmd_20[33] = {  /* Gouki: SA I Messatsu Gou Hadou, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_GOU_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_21[33] = {  /* Gouki: SA II Messatsu Gou Shoryu, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_MESSATSU_GOU_SHORYU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_22[33] = {  /* Gouki: SA III Messatsu Gou Rasen, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_GOU_SHORYUKEN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_24[29] = {  /* Gouki: Shun Goku Satsu */
    CMD_RESET, 0, 0, 24, 24, 24, 24, CMD_BT_NOW | CMD_BT_ALWAYS,
    CMD_EX_ONLY(CMD_EX_HP), CMD_EX_ONLY(CMD_EX_HP), CMD_EX_ONLY(CMD_EX_HP), CMD_EX_ONLY(CMD_EX_HP),
    CMD_STEP(CK_PRESS, 0, 0, CMD_SW_LP),
    CMD_STEP(CK_PRESS, 10, 0, CMD_SW_LP),
    CMD_STEP(CK_LEVER_PRESS, 16, 0, CMD_LV_FORWARD),
    CMD_STEP(CK_PRESS, 10, 0, CMD_SW_LK),
    CMD_END,
};

const s16 pE_cmd_28[25] = {  /* Gouki: Ashura Senkuu (forward) */
    CMD_RESET, CMD_LV_UP, 0, 23, 23, 23, 23, CMD_BT_CHG,
    CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_KK), CMD_EX_ONLY(CMD_EX_KK),
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_29[25] = {  /* Gouki: Ashura Senkuu (back) */
    CMD_RESET, CMD_LV_UP, 0, 23, 23, 23, 23, CMD_BT_CHG,
    CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_KK), CMD_EX_ONLY(CMD_EX_KK),
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_END,
};

const s16 pE_cmd_30[25] = {  /* Gouki: Gou Shoryuken, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_GOU_SHORYUKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_31[25] = {  /* Gouki: Gou Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_GOU_HADOKEN), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_32[25] = {  /* Gouki: Tatsumaki Zankuukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_TATSUMAKI_ZANKUUKYAKU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* pE_cmd_33's record runs on into p11_cmd_31, which slot 31 of fighter 0x11 points into, four words
   after the record's start: p11_cmd_31 holds the last three rno words, the button words and the steps */
const s16 pE_cmd_33[4] = {  /* Gouki: Shakunetsu Hadoken, 63214+P; the record runs on into p11_cmd_31 */
    CMD_RESET, CMD_LV_UP, 0, GOUKI_GOU_HADOKEN,
};

const s16 p11_cmd_31[29] = {  /* the rest of pE_cmd_33 */
    GOUKI_GOU_HADOKEN, GOUKI_GOU_HADOKEN, GOUKI_GOU_HADOKEN, CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 pE_cmd_34[33] = {  /* Gouki: Zenpou Tenshin, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_ZENPOU_TENSHIN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_38[33] = {  /* Gouki: SA I Tenma Gou Zankuu (air), 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_ZANKU_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_39[33] = {  /* Gouki: SA III Messatsu Gou Senpuu (air), 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_MESSATSU_GOU_SENPUU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_46[25] = {  /* Gouki: Zanku Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_ZANKU_HADOKEN), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

const s16 pE_cmd_47[25] = {  /* Gouki: air Tatsumaki Zankuukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_AIR_TATSUMAKI_ZANKUUKYAKU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 ukemi_time_tbl[18] = {
    0, 0, 1, 1, 2, 2, 3, 3,
    4, 4, 5, 5, 6, 6, 7, 7,
    7, -1,
};

/* provisional name */
const char player_cmd_line_str0[20] = "UP    =    SHOT1 =\n";

/* provisional name */
const char player_cmd_line_str1[20] = "DOWN  =    SHOT2 =\n";

/* provisional name */
const char player_cmd_line_str2[20] = "LEFT  =    SHOT3 =\n";

/* provisional name */
const char player_cmd_line_str3[20] = "RIGHT =    SHOT4 =\n";

/* provisional name */
const char player_cmd_line_str4[20] = "DIR        SHOT5 =\n";

/* provisional name */
const char player_cmd_line_str5[12] = "SHOT6 =\n\0\xFF\xFF\xFF";

/* provisional name */
const char player_cmd_line_str6[8] = "SHOT6 =";

/* provisional name */
const char lvr_chk_line_str0[4] = "S \0\xFF";

/* provisional name */
const char lvr_chk_line_str1[4] = "M \0\xFF";

/* provisional name */
const char lvr_chk_line_str2[4] = "L \0\xFF";
