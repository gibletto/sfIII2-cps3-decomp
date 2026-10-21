/*
 * n_input.c  Ranking name entry
 *
 * Name_Input is the per-player entry for entering initials after a ranked game: it works out
 * which ranking the player reached (ranking_state_check), sets up the name work and a time
 * limit, then runs the Name_Jmp_scs states (init, lever/button input, wait, finish).
 * Name_Input_comm and Name_Scs_Input_comm move the cursor through the character set and
 * commit letters, with a timeout that ends entry automatically. When the name is left blank or
 * matches an entry in slang_tbl (name_slang_check), define_name_input substitutes one of two
 * fixed names at random; ranking_name_entry then copies the letters into the ranking record.
 * The rest of the file draws the entered names and scores on the text layer and shows the
 * "thank you for playing" message.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "EFFB6.h"
#include "EFFB8.h"
#include "PLS02.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "n_input.h"



s16 Name_00[2];  /* 020280B8 */
NAME_WK name_wk[2];  /* 020280BC */
NAME_WK * name_ptr;  /* 02028128 */
SC_NAME_WK sc_name_wk[2][4];  /* 0202812C */
SC_NAME_WK * nsc_ptr;  /* 0202817C */
RANK_NAME_W rank_name_w[2];  /* 02028180 */
s16 Name_Input_f;  /* 02028188 */
s16 naming_cnt;  /* 2i: one counter (3s: one per player) */
s16 n_disp_flag;  /* 0202818E */


/* 02006820 */
/* The name entry states of the plain name entry; the game only runs Name_Jmp_scs. */
void (*Name_Jmp_Tbl[8])() = {
    Name_Input_init,
    Name_Input_comm,
    Name_Input_wait,
    Name_Input_comm,
    Name_Input_wait,
    Name_Input_comm,
    Name_Input_end,
    Name_Finish,
};
/* 02006840 */
void (*Name_Jmp_scs[8])() = {
    Name_Scs_Input_init,
    Name_Scs_Input_comm,
    Name_Input_wait,
    Name_Scs_Input_comm,
    Name_Input_wait,
    Name_Scs_Input_comm,
    Name_Scs_Input_end,
    Name_Scs_Finish,
};


/* 2i 060AAF50, 3s-near: sf3 src/n_input.c:86 Name_Input */
s32 Name_Input(s16 pl_id) {
    end_no_cut = 1;
    Name_Input_f = 0;
    name_ptr = &name_wk[pl_id];
    name_ptr->id = pl_id;
    start_cut_check(pl_id);
    switch (Name_00[pl_id]) {
    case 0:
        Name_00[pl_id]++;
        if (E_No0 != 8) {
            name_ptr->type = 0;
        } else {
            name_ptr->type = 1;
        }
        name_work_init(pl_id);
        ranking_state_check();
        all_name_display();
        break;
    default:
        if (E_No0 != 8) {
            if (name_ptr->type) {
                name_ptr->type = 0;
                break;
            }
            Name_Jmp_scs[name_ptr->r_no_0]();
        } else {
            Name_Jmp_Tbl[name_ptr->r_no_0]();
        }
        break;
    }
    return Name_Input_f;
}



/* provisional name */
/* 2i 060AB00C, 3s-reloc: sf3 src/n_input.c:111 Name_Input_init */
void Name_Input_init(void) {
    name_ptr->r_no_0++;
    load_any_color(4);
    if (end_name_cut[name_ptr->id] == 0) {
        name_ptr->timer = 1200;
    }
    name_ptr->index = 0;
    effect_B7_init(name_ptr->id);
    effect_B5_init(name_ptr->id);
}

/* provisional name */
/* 2i 060AB084, 3s-near: sf3 src/n_input.c:123 Name_Input_comm */
void Name_Input_comm(void) {
    s16 cmd;
    s16 i;
    name_ptr->timer--;
    if (name_ptr->timer < 0) {
        name_ptr->r_no_0 = 6;
        for (i = name_ptr->index; i < 4; i++) {
            name_ptr->code[i] = 0x2C;
        }
    } else {
        cmd = Name_Input_sub();
        switch (cmd) {
        case 1:
            name_ptr->r_no_0++;
            name_ptr->timer += 420;
            name_ptr->end_flag[name_ptr->index] = 1;
            name_ptr->index++;
            name_ptr->index &= 3;
            name_ptr->wait_cnt = 10;
            *(s16*)(name_ptr->code + name_ptr->index) = name_ptr->code[name_ptr->index - 1];
            break;
        case 2:
            name_ptr->timer += 420;
            name_ptr->index--;
            name_ptr->r_no_0 -= 2;
            if (name_ptr->index < 0) {
                name_ptr->index = 0;
                name_ptr->r_no_0 = 0;
            } else {
                name_ptr->code[name_ptr->index + 1] = 0x2F;
            }
            name_ptr->end_flag[name_ptr->index] = 0;
            break;
        case 3:
            name_ptr->r_no_0 = 6;
            for (i = name_ptr->index; i < 4; i++) {
                name_ptr->code[i] = 0x2C;
            }
            break;
        }
    }
}



/* 2i 060AB1CC, 3s-exact: sf3 src/n_input.c:169 Name_Input_wait */
void Name_Input_wait(void) {
    name_ptr->wait_cnt--;
    if (name_ptr->wait_cnt < 0) {
        name_ptr->r_no_0++;
    }
}



/* provisional name */
/* 2i 060AB1EC, 3s-reloc: sf3 src/n_input.c:179 Name_Input_end */
void Name_Input_end(void) {
    register s16 i;
    name_ptr->r_no_0++;
    if (name_ptr->index > 0) {
        if (name_slang_check() != 0) {
            define_name_input();
        }
    } else {
        define_name_input();
    }
    ranking_name_entry();
    i = 0;
    while (i < 4) {
        name_ptr->end_flag[i++] = 1;
    }
    name_ptr->index = 3;
}

/* provisional name */
/* 2i 060AB24C, 3s-exact: sf3 src/n_input.c:198 Name_Finish */
void Name_Finish(void)
{
    Sound_SE(0x62);
    end_no_cut = 0;
    Name_Input_f = 1;
}



/* provisional name */
/* 2i 060AB264, 3s-near: sf3 src/n_input.c:208 show_thank_you_for_playing */
void show_thank_you_for_playing(void) {
    tilemap_print_string_attr(20, 22, 40, thank_you_str);
    tilemap_print_string_attr(19, 23, 40, for_playing_str);
}



/* provisional name */
/* 2i 060AB280, 3s-reloc: sf3 src/n_input.c:216 Name_Scs_Input_init */
void Name_Scs_Input_init(void) {
    name_ptr->r_no_0++;
    if (end_name_cut[name_ptr->id] == 0) {
        name_ptr->timer = 1200;
    }
    name_ptr->index = 0;
    name_entry_commit_row(name_ptr->id, Text_Page_Y);
    Scs_char_move();
}



/* 2i 060AB2E0, 3s-near: sf3 src/n_input.c:228 Name_Scs_Input_comm */
void Name_Scs_Input_comm(void) {
    s16 work;
    s16 i;
    name_ptr->timer--;
    if (name_ptr->timer < 0) {
        name_ptr->r_no_0 = 6;
        for (i = name_ptr->index; i < 4; i++) {
            name_ptr->code[i] = 44;
        }
    } else {
        work = Name_Input_sub();
        switch (work) {
        case 1:
            name_ptr->r_no_0 += 1;
            name_ptr->timer += 420;
            name_ptr->end_flag[name_ptr->index] = 1;
            naming_set(name_ptr->id, name_ptr->index, name_ptr->code[name_ptr->index]);
            name_ptr->index += 1;
            name_ptr->index &= 3;
            name_ptr->wait_cnt = 10;
            if (name_ptr->index != 3) {
                *(s16*)(name_ptr->code + name_ptr->index) = name_ptr->code[name_ptr->index - 1];
            } else {
                name_ptr->code[name_ptr->index] = 46;
            }
            sc_name_wk[name_ptr->id][name_ptr->index].n_disp_flag = 0;
            sc_name_wk[name_ptr->id][name_ptr->index].f_cnt = 0;
            break;
        case 2:
            name_ptr->timer += 420;
            sc_name_wk[name_ptr->id][name_ptr->index].n_disp_flag = 0;
            sc_name_wk[name_ptr->id][name_ptr->index].f_cnt = 0;
            name_ptr->index--;
            name_ptr->r_no_0 -= 2;
            if (name_ptr->index < 0) {
                name_ptr->index = 0;
                name_ptr->r_no_0 = 0;
            } else {
                name_ptr->code[name_ptr->index + 1] = 47;
                naming_set(name_ptr->id, name_ptr->index, name_ptr->code[name_ptr->index]);
            }
            name_ptr->end_flag[name_ptr->index] = 0;
            break;
        case 3:
            name_ptr->r_no_0 = 6;
            naming_set(name_ptr->id, name_ptr->index, name_ptr->code[name_ptr->index]);
            for (i = name_ptr->index; i < 4; i++) {
                name_ptr->code[i] = 44;
            }
            break;
        }
    }
    Scs_char_move();
}



/* provisional name */
/* 2i 060AB56E, 3s-near: sf3 src/n_input.c:287 Name_Scs_Input_end */
void Name_Scs_Input_end(void) {
    s16 i;
    name_ptr->r_no_0++;
    naming_cnt = 120;
    n_disp_flag = 0;
    if (name_ptr->index != 0) {
        if (name_slang_check() != 0) {
            define_name_input();
        }
    } else {
        define_name_input();
    }
    for (i = 0; i < 4;) {
        name_ptr->end_flag[i++] = 1;
    }
    ranking_name_entry();
    name_ptr->index = 3;
    if (name_ptr->id) {
        effect_89_init(8, DE_X[0] + 40, Text_Page_Y, 3, 1);
    } else {
        effect_89_init(8, DE_X[6] + 13, Text_Page_Y, 3, 1);
    }
}



/* 2i 060AB60C, inferred: sf3 src/n_input.c:313 Name_Scs_Finish */
void Name_Scs_Finish(void) {
    naming_cnt--;
    if (naming_cnt < 0) {
        Name_Input_f = 1;
        end_no_cut = 0;
    }
    Scs_char_move();
}



/* 2i 060AB62A, 3s-near: sf3 src/n_input.c:324 Name_Input_sub */
s32 Name_Input_sub(void) {
    u16 sw_up_w;
    u16 sw_data;
    (&name_ptr->old_code[0])[name_ptr->index] = name_ptr->code[name_ptr->index];
    if (name_ptr->id) {
        sw_data = p2sw_0;
        sw_up_w = ~p2sw_1 & p2sw_0;
    } else {
        sw_data = p1sw_0;
        sw_up_w = ~p1sw_1 & p1sw_0;
    }
    if (sw_up_w & 0x3F0) {
        switch (name_ptr->code[name_ptr->index]) {
        case 45:
            return 2;
        case 46:
            return 3;
        default:
            return 1;
        }
    } else {
        if (sw_data & 0xC) {
            if (auto_n_check(4, 0, sw_data, sw_up_w)) {
                name_ptr->code[name_ptr->index]--;
                if (name_ptr->code[name_ptr->index] < 0) {
                    name_ptr->code[name_ptr->index] = 46;
                }
            }
            if (auto_n_check(8, 1, sw_data, sw_up_w)) {
                name_ptr->code[name_ptr->index]++;
                if (name_ptr->code[name_ptr->index] > 46) {
                    name_ptr->code[name_ptr->index] = 0;
                }
            }
        }
        return 0;
    }
}



/* 2i 060AB750, 3s-reloc: sf3 src/n_input.c:365 auto_n_check */
s32 auto_n_check(chk_lvr, index, sw_data, sw_up_w)
u16 chk_lvr;
s16 index;
u16 sw_data;
u16 sw_up_w;
{
    if (sw_up_w & chk_lvr) {
        name_ptr->count1[index] = 0;
        name_ptr->count2[index] = 0;
        return 1;
    }
    if (sw_data & chk_lvr) {
        if (name_ptr->count1[index] > 12) {
            name_ptr->count2[index]++;
            if (name_ptr->count2[index] > 4) {
                name_ptr->count2[index] = 0;
                return 1;
            }
        } else {
            name_ptr->count1[index]++;
            name_ptr->count2[index] = 0;
        }
    } else {
        name_ptr->count1[index] = 0;
        name_ptr->count2[index] = 0;
    }
    return 0;
}



/* 2i 060AB80A, 3s-reloc: sf3 src/n_input.c:396 name_slang_check */
s32 name_slang_check(void) {
    const s16* slang_ptr = &slang_tbl[0][0];
    s16 i;
    s16 j;
    s16 slang_cnt;
    for (i = 0; i < 17; i++) {
        slang_cnt = 0;
        for (j = 0; j < 3; j++) {
            if (*slang_ptr == name_ptr->code[j]) {
                slang_cnt++;
            }
            slang_ptr++;
        }
        if (slang_cnt == 3) {
            return 1;
        }
    }
    return 0;
}



/* 2i 060AB866, 3s-reloc: sf3 src/n_input.c:418 define_name_input */
void define_name_input(void) {
    s16 work = random_16_com();
    if (work & 1) {
        name_ptr->code[0] = 2;
        name_ptr->code[1] = 0;
        name_ptr->code[2] = 15;
    } else {
        name_ptr->code[0] = 2;
        name_ptr->code[1] = 14;
        name_ptr->code[2] = 12;
    }
}



void ranking_state_check(void) {
    name_ptr->rank = -1;
    name_ptr->rank_sub = -1;
    if (Rank_In[name_ptr->id][0] >= 0) {
        name_ptr->rank = Rank_In[name_ptr->id][0];
        name_ptr->status = 0;
        if (Rank_In[name_ptr->id][1] >= 0) {
            if (Rank_In[name_ptr->id][0] > Rank_In[name_ptr->id][1]) {
                name_ptr->rank_status = 6;
                name_ptr->rank_in = Rank_In[name_ptr->id][1];
                name_ptr->status_sub = 6;
                name_ptr->rank_sub = Rank_In[name_ptr->id][1];
            } else {
                name_ptr->rank_status = 0;
                name_ptr->rank_in = Rank_In[name_ptr->id][0];
            }
        } else {
            name_ptr->rank_status = 0;
            name_ptr->rank_in = Rank_In[name_ptr->id][0];
        }
    } else if (Rank_In[name_ptr->id][1] >= 0) {
        name_ptr->rank_status = 6;
        name_ptr->rank_in = Rank_In[name_ptr->id][1];
        name_ptr->status_sub = 6;
        name_ptr->rank_sub = Rank_In[name_ptr->id][1];
    }
}



/* 2i 060AB996, 3s-reloc: sf3 src/n_input.c:456 ranking_name_entry */
void ranking_name_entry(void) {
    RANK_NAME_W* ptr = &rank_name_w[name_ptr->id];
    ptr->code[0] = name_code_tbl[name_ptr->code[0]];
    ptr->code[1] = name_code_tbl[name_ptr->code[1]];
    ptr->code[2] = name_code_tbl[name_ptr->code[2]];
    ptr->code[3] = name_code_tbl[name_ptr->code[3]];
}



/* 2i 060AB9E8, 3s-near: sf3 src/n_input.c:466 name_work_init */
void name_work_init(pl_id)
s16 pl_id;
{
    s16 j;
    name_wk[pl_id].r_no_0 = 0;
    name_wk[pl_id].r_no_1 = 0;
    name_wk[pl_id].dmm = 0;
    name_wk[pl_id].end_flag[0] = 0;
    name_wk[pl_id].code[0] = 46;
    name_wk[pl_id].old_code[0] = 46;
    name_wk[pl_id].end_flag[3] = 0;
    name_wk[pl_id].old_code[3] = name_wk[pl_id].code[3] = 44;
    sc_name_wk[pl_id][0].c_cnt = 0;
    sc_name_wk[pl_id][0].type = 0;
    sc_name_wk[pl_id][0].r_no_0 = 0;
    sc_name_wk[pl_id][0].r_no_1 = 0;
    for (j = 1; j < 3; j++) {
        name_wk[pl_id].end_flag[j] = 0;
        name_wk[pl_id].code[j] = 0x2F;
        name_wk[pl_id].old_code[j] = 0x2F;
        sc_name_wk[pl_id][j].c_cnt = j;
        sc_name_wk[pl_id][j].type = j;
        sc_name_wk[pl_id][j].r_no_0 = 0;
        sc_name_wk[pl_id][j].r_no_1 = 0;
    }
}



/* provisional name */
/* 2i 060ABAC4, 3s-near: sf3 src/n_input.c:496 name_entry_commit_row */
void name_entry_commit_row(s16 pl_id, s16 pos_y) {
    s16 pos_x;
    if (!Game_setting.mode) {
    }
    if (pl_id) {
        pos_x = DE_X[0] + 37;
    } else {
        pos_x = DE_X[6] + 10;
    }
    switch (name_ptr->rank_in) {
    case 0:
        rank_mark_set(pl_id, 0);
        break;
    case 1:
        rank_mark_set(pl_id, 1);
        break;
    case 2:
        rank_mark_set(pl_id, 2);
        break;
    default:
        rank_mark_set(pl_id, 3);
        break;
    }
    tilemap_put_cell(pos_x - 1, pos_y, 42, name_ptr->rank_in + 1);
    tilemap_put_cell(pos_x, pos_y, 42, pl_id * 2 + 106);
    tilemap_put_cell(pos_x + 1, pos_y, 42, pl_id * 2 + 107);
    if (pl_id) {
        sc_ram_to_vram_opc(25, Game_setting.mode * 8, pos_y, 42);
    } else {
        sc_ram_to_vram_opc(24, Game_setting.mode * 4, pos_y, 42);
    }
}



/* 2i 060ABB7E, 3s-reloc: sf3 src/n_input.c:531 Scs_char_move */
void Scs_char_move(void) {
    s16 i;
    s8 ofs;
    ofs = 0;
    for (i = 0; i < 4; i++) {
        nsc_ptr = &sc_name_wk[name_ptr->id][ofs];
        Scs_move_sub();
        ofs++;
    }
}



/* 2i 060ABBEE, 3s-near: sf3 src/n_input.c:544 Scs_move_sub */
s32 Scs_move_sub(void) {
    switch (nsc_ptr->r_no_0) {
    case 0:
    case_0:
        if (name_ptr->end_flag[nsc_ptr->type]) {
            nsc_ptr->r_no_0++;
            naming_set(name_ptr->id, nsc_ptr->type, name_ptr->code[nsc_ptr->type]);
        } else {
            current_sc_move2();
        }
        break;
    case 1:
        if (name_ptr->r_no_0 == 7) {
            nsc_ptr->r_no_0 = 2;
        }
        if (name_ptr->end_flag[nsc_ptr->type] == 0) {
            nsc_ptr->r_no_0 = 1;
            goto case_0;
        }
        break;
    case 2:
        break;
    }
    if (name_ptr->old_code[nsc_ptr->type] != name_ptr->code[nsc_ptr->type]) {
        nsc_ptr->n_disp_flag = 0;
        nsc_ptr->f_cnt = 0;
        naming_set(name_ptr->id, nsc_ptr->type, name_ptr->code[nsc_ptr->type]);
    }
}



/* 2i 060ABCFE, 3s-near: sf3 src/n_input.c:576 current_sc_move2 */
void current_sc_move2(void) {
    if (name_ptr->index != nsc_ptr->c_cnt) {
        return;
    }
    switch (nsc_ptr->r_no_1) {
    case 0:
        nsc_ptr->r_no_1++;
        nsc_ptr->f_cnt = 0;
        nsc_ptr->n_disp_flag = 0;
        naming_set(name_ptr->id, nsc_ptr->type, name_ptr->code[nsc_ptr->type]);
        break;
    case 1:
        if (name_ptr->r_no_0 > 5) {
            nsc_ptr->r_no_0++;
        } else {
            nsc_ptr->f_cnt++;
            if (nsc_ptr->f_cnt > 16) {
                nsc_ptr->f_cnt = 0;
                nsc_ptr->n_disp_flag++;
                if (nsc_ptr->n_disp_flag > 2) {
                    nsc_ptr->n_disp_flag = 0;
                }
                if (nsc_ptr->n_disp_flag != 2) {
                    naming_set(name_ptr->id, nsc_ptr->type, name_ptr->code[nsc_ptr->type]);
                } else {
                    naming_set(name_ptr->id, nsc_ptr->type, 47);
                }
            }
        }
        break;
    }
}



/* 2i 060ABDDC, 3s-exact: sf3 src/n_input.c:611 all_name_display */
void all_name_display(void) {
    s16 i;
    for (i = 0; i < 3; i++) {
        naming_set(name_ptr->id, (s8)i, name_ptr->code[i]);
    }
    naming_set(name_ptr->id, 3, 44);
    name_ptr->dmm = 1;
}



/* 2i 060ABE5A, 3s-reloc: sf3 src/n_input.c:622 start_cut_check */
void start_cut_check(pl_id)
s16 pl_id;
{
    if (Naming_Cut[pl_id]) {
        if (name_ptr->r_no_0 < 6) {
            name_ptr->r_no_0 = 6;
        }
        pl_id = 0;
        do {
            if (name_ptr->end_flag[pl_id] == 0) {
                name_ptr->code[pl_id] = 44;
            }
        } while (++pl_id < 3);
    }
}
