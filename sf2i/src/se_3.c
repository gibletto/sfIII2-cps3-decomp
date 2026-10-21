/*
 * SE_3.C  Screen wipe patterns and sound request routines (part 3)
 *
 * The sound routines start stage BGM (Stage_BGM, bgm_fade_in_stage), initialise sound
 * (sound_system_init) and play effects for objects: the Se_ table handlers (Se_Myself, Se_Let,
 * Se_Let_SP, ...) and Se_Shock play a code in the character's own sound bank, panned by screen
 * position (Get_Position), with voice replacement from Check_Voice_SE. Call_Se plays a fixed code;
 * Finish_SE plays the winner's finishing voice.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "se_3.h"
#include "cps3.h"



/* 2i 06082848, 3s-near: sf3 src/se_3.c:28 Stage_BGM; 2i: the stage's own BGM (no round add, no gSeqStatus) */
void Stage_BGM(Stage_Number, Round_Number)
u16 Stage_Number;
s32 Round_Number;
{
    s32 code;
    if ((Demo_Sound != 0 || Demo_Flag != 0) && PB_Music_Off == 0) {
        code = stage_bgm_tbl[Stage_Number];
        sound_request(code);
    }
}



/* provisional name */
/* 2i 06082870, 3s-reloc: sf3 src/se_3.c:47 bgm_fade_in_stage */
void bgm_fade_in_stage(s16 x) {
    if (PB_Music_Off) {
        return;
    }
    sound_fade_in_submit(stage_bgm_tbl[bg_w.stage], 0x8000 / x);
}

/* 2i 060828A4, 3s-reloc: sf3 src/se_3.c:54 Sound_SE */
void Sound_SE(Code)
    s16 Code;
{
    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        sound_request(Code);
    }
}


/* provisional name */
/* 2i 060828CE, 3s-reloc: sf3 src/se_3.c:64 sound_bgm_fade_out */
void sound_bgm_fade_out(s16 speed) {
    bgm_fade_out(speed);
}

/* provisional name */
/* 2i 060828DA, 3s-reloc: sf3 src/se_3.c:69 bgm_request */
void bgm_request(bgm_code)
s16 bgm_code;
{
    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (PB_Music_Off) {
        return;
    }
    sound_reg_level_set(0, 0);
    sound_request(bgm_code);
}



/* provisional name */
/* 2i 06082912, 3s-reloc: sf3 src/se_3.c:85 voice_all_off */
void voice_all_off(void) { bgm_stop(); }



/* provisional name */
/* 2i 06082918, 3s-reloc: sf3 src/se_3.c:90 sound_system_init */
void sound_system_init(void) {
    s16 i;
    sound_request_pan(0x78, 0x40, 0x40, 0, 2);
    for (i = 0; i < 14; i++) {
        se_voice_stop(init_fade_voice_tbl[i]);
    }
}



/* 2i 0608295C, 3s-exact: sf3 src/se_3.c:100 Se_Dummy */
void Se_Dummy(WORK_Other* ewk, u16 Code) {
}



/* 2i 06082960, 3s-near: sf3 src/se_3.c:105 Se_Shock; 2i: no Check_Bonus_SE, voice banks 0x200 per player */
void Se_Shock(WORK_Other* ewk, u16 se) {
    s16 pos;
    PLW* em;
    s32 uid;
    s16 xx;
    s32 zz;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        if (ewk->wu.work_id == 1) {
            em = (PLW*)ewk->wu.target_adrs;
            uid = ewk->wu.id;
        } else {
            em = (PLW*)((PLW*)ewk->my_master)->wu.target_adrs;
            uid = ewk->master_id;
        }
        if (em->wu.work_id == 1 && em->wu.vital_new < 0) {
            xx = 0;
            zz = 0x27;
            for (; xx < 7; xx++) {
                if (se == SE_Shock_Data[xx]) {
                    zz = 0;
                    break;
                }
            }
            se += zz;
        }
        if (se) {
            se += uid * 0x200;
        }
        pos = Get_Position((PLW*)ewk);
        sound_request_pan(se, pos, pos, 0, 2);
    }
}



/* 2i 06082A36, 3s-near: sf3 src/se_3.c:143 Se_Myself; 2i: voice banks 0x200 per player */
void Se_Myself(WORK_Other* ewk, u16 Code) {
    s32 se;
    s16 pos;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        se = Check_Voice_SE(Code);
        if ((u16)se) {
            se += ewk->wu.id * 0x200;
        }
        pos = Get_Position((PLW*)ewk);
        sound_request_pan(se, pos, pos, 0, 2);
    }
}



/* 2i 06082AB4, 3s-near: sf3 src/se_3.c:159 Se_Myself_Die; 2i: plays the code itself (no Check_Voice_SE) */
void Se_Myself_Die(WORK_Other* ewk, u16 se) {
    s16 pos;

    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Combo_Demo_Flag & 0x80) {
        return;
    }
    if (ewk->wu.vital_new < 0) {
        return;
    }
    if (se) {
        se += ewk->wu.id * 0x200;
    }
    pos = Get_Position((PLW*)ewk);
    sound_request_pan(se, pos, pos, 0, 2);
}




/* 2i 06082B0C, 3s-near: sf3 src/se_3.c:182 Se_Let; 2i: no Check_Bonus_SE */
void Se_Let(WORK_Other* ewk, u16 Code) {
    s32 se;
    s32 uid;
    s16 pos;

    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Combo_Demo_Flag & 0x80) {
        return;
    }
    se = Check_Voice_SE(Code);
    if (ewk->wu.work_id == 1) {
        uid = ewk->wu.id;
    } else {
        uid = ewk->master_id;
    }
    if ((u16)se) {
        se += uid * 0x200;
    }
    pos = Get_Position((PLW*)ewk);
    sound_request_pan(se, pos, pos, 0, 2);
}



/* 2i 06082B8C, 3s-near: sf3 src/se_3.c:210 Se_Let_SP; 2i: voice banks 0x200 per player */
void Se_Let_SP(WORK_Other* ewk, u16 Code) {
    s32 uid;
    PLW* em;
    s16 pos;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        em = (PLW*)ewk->wu.target_adrs;
        if (ewk->wu.work_id == 1) {
            uid = ewk->wu.id;
        } else {
            uid = ewk->master_id;
        }
        if (em->wu.work_id == 1 && em->wu.vital_new < 0) {
            if (Code == 0x14B) {
                Code = 0x158;
            }
            if (Code == 0x13A) {
                Code = 0x15A;
            }
        }
        if (Code) {
            Code += uid * 0x200;
        }
        pos = Get_Position((PLW*)ewk);
        sound_request_pan(Code, pos, pos, 0, 2);
    }
}



/* 2i 06082C0E, 3s-reloc: sf3 src/se_3.c:240 Call_Se */
void Call_Se(WORK_Other* ewk, u16 Code) {
    s16 code = Code;
    s16 pos;
    PLW* wk;
    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        pos = Get_Position(wk);
        sound_request_pan(code, pos, pos, 0, 2);
    }
}

/* Sound handler: plays Code (with the character's voice replacement) at the
   object's screen position, but stays silent while the object is dropping
   at a height of 64 or less. */
/* 2i 06082C70, 3s-near: sf3 src/se_3.c:253 Se_Term */
s32 Se_Term(WORK_Other* ewk, u16 Code) {
    s32 se;
    s16 pos;

    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Combo_Demo_Flag & 0x80) {
        return;
    }
    if (ewk->wu.mvxy.a[1].sp < 0 && ewk->wu.xyz[1].disp.pos <= 64) {
        return 0;
    }
    se = Check_Voice_SE(Code);
    if ((u16)se) {
        se += ewk->wu.id * 0x200;
    }
    pos = Get_Position((PLW*)ewk);
    sound_request_pan(se, pos, pos, 0, 2);
}



/* 2i 06082CE6, 3s-near: sf3 src/se_3.c:276 Finish_SE */
void Finish_SE(void) {
    s32 se;
    s16 pos;
    PLW* wk;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        se = Check_Finish_SE();
        if ((s16)se != -1) {
            wk = &plw[Winner_id];
            if ((s16)se) {
                se += wk->wu.id * 0x200;
            }
            pos = Get_Position(wk);
            sound_request_pan(se, pos, pos, 0, 2);
        }
    }
}



/* 2i 06082D54, 3s-reloc: sf3 src/se_3.c:296 Check_Finish_SE */
s32 Check_Finish_SE(void) {
    s16 xx;
    for (xx = 0; xx < 7; xx++) {
        if (Finish_SE_Data[0][xx] == Last_Called_SE) {
        } else {
            continue;
        }
        return Finish_SE_Data[1][xx];
    }
    return -1;
}



/* 2i 06082DA6, 3s-reloc: sf3 src/se_3.c:310 Get_Position */
s32 Get_Position(PLW* wk) {
    u16 xx;
    u16 yy;
    xx = get_center_position();
    xx -= 0xF8;
    xx = wk->wu.position_x - xx;
    xx /= 4;
    if (xx < 0x80) {
        return xx;
    }
    yy = get_center_position();
    if (yy > wk->wu.xyz[0].disp.pos) {
        return 1;
    }
    return 0x7E;
}



/* provisional name */
/* 2i 06082DF8, 3s-reloc: sf3 src/se_3.c:330 Check_Voice_SE */
s32 Check_Voice_SE(code)
s16 code;
{
    if (code < 0x140 || Voice_Type == 0) {
        return code;
    }
    return Voice_SE_Data[code - 0x140];
}

