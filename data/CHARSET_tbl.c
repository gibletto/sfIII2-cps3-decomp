/*
 * CHARSET_TBL.C  tables read by CHARMOVE.c and EFFE5.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 jphos_table[];
extern void (*const comm_jmp_tbl[])();
extern void (*const comm_if_jmp_tbl[])();
extern const u16 acatkoa_table[];
extern void comm_a123();
extern void comm_a456();
extern void comm_abbak();
extern void comm_addr();
extern void comm_asxy();
extern void comm_atmf();
extern void comm_back();
extern void comm_bgrlf();
extern void comm_cafr();
extern void comm_care();
extern void comm_ccch();
extern void comm_ccfl();
extern void comm_chkwf();
extern void comm_djmp();
extern void comm_dspf();
extern void comm_dummy();
extern void comm_emhp();
extern void comm_end();
extern void comm_epcy();
extern void comm_exbgc();
extern void comm_exbgs();
extern void comm_exec();
extern void comm_flip();
extern void comm_for();
extern void comm_for2();
extern void comm_gets();
extern void comm_hclr();
extern void comm_hjmp();
extern void comm_if_l();
extern void comm_if_s();
extern void comm_iflb();
extern void comm_iflg();
extern void comm_ifrlf();
extern void comm_ifs2();
extern void comm_ifs3();
extern void comm_imgc();
extern void comm_imgs();
extern void comm_ixbw();
extern void comm_ixfw();
extern void comm_jmp();
extern void comm_jpss();
extern void comm_jsr();
extern void comm_kage();
extern void comm_mdat();
extern void comm_mpcy();
extern void comm_mpos();
extern void comm_mvix();
extern void comm_mxyt();
extern void comm_myhp();
extern void comm_nex();
extern void comm_nex2();
extern void comm_ngda();
extern void comm_ngem();
extern void comm_ngme();
extern void comm_pa_x();
extern void comm_pa_y();
extern void comm_paxy();
extern void comm_pjmp();
extern void comm_ps_x();
extern void comm_ps_y();
extern void comm_psxy();
extern void comm_quax();
extern void comm_quay();
extern void comm_rapk();
extern void comm_rapk2();
extern void comm_rapp();
extern void comm_rapp2();
extern void comm_ret();
extern void comm_retmj();
extern void comm_rja();
extern void comm_rja2();
extern void comm_rja3();
extern void comm_rja4();
extern void comm_rja5();
extern void comm_rja6();
extern void comm_rja7();
extern void comm_rljmp();
extern void comm_rmja();
extern void comm_rngc();
extern void comm_roa();
extern void comm_rv_x();
extern void comm_rv_y();
extern void comm_rvxy();
extern void comm_s123();
extern void comm_s456();
extern void comm_s_chg();
extern void comm_sajp();
extern void comm_schx();
extern void comm_schy();
extern void comm_scmd();
extern void comm_setr();
extern void comm_smhf();
extern void comm_sps();
extern void comm_srlf();
extern void comm_sse();
extern void comm_sstx();
extern void comm_ssty();
extern void comm_stop();
extern void comm_uja();
extern void comm_uja2();
extern void comm_uja3();
extern void comm_uja4();
extern void comm_uja5();
extern void comm_uja6();
extern void comm_uja7();
extern void comm_umja();
extern void comm_wadd();
extern void comm_wadd2();
extern void comm_wca();
extern void comm_wceq();
extern void comm_wceq2();
extern void comm_wcgt();
extern void comm_wcgt2();
extern void comm_wclt();
extern void comm_wclt2();
extern void comm_wcne();
extern void comm_wcne2();
extern void comm_wset();
extern void comm_wswk();
extern void comm_ydat();

const s16 jphos_table[16] = {
    0, -16, -12, -8, -4, 4, 8, 12,
    16, 20, 24, 28, 32, 36, 40, 44,
};

void (*const comm_jmp_tbl[119])() = {
    (void (*)())comm_dummy,
    (void (*)())comm_roa,
    (void (*)())comm_end,
    (void (*)())comm_jmp,
    (void (*)())comm_jpss,
    (void (*)())comm_jsr,
    (void (*)())comm_ret,
    (void (*)())comm_sps,
    (void (*)())comm_setr,
    (void (*)())comm_addr,
    (void (*)())comm_if_l,
    (void (*)())comm_djmp,
    (void (*)())comm_for,
    (void (*)())comm_nex,
    (void (*)())comm_for2,
    (void (*)())comm_nex2,
    (void (*)())comm_rja,
    (void (*)())comm_uja,
    (void (*)())comm_rja2,
    (void (*)())comm_uja2,
    (void (*)())comm_rja3,
    (void (*)())comm_uja3,
    (void (*)())comm_rja4,
    (void (*)())comm_uja4,
    (void (*)())comm_rja5,
    (void (*)())comm_uja5,
    (void (*)())comm_rja6,
    (void (*)())comm_uja6,
    (void (*)())comm_rja7,
    (void (*)())comm_uja7,
    (void (*)())comm_rmja,
    (void (*)())comm_umja,
    (void (*)())comm_mdat,
    (void (*)())comm_ydat,
    (void (*)())comm_mpos,
    (void (*)())comm_cafr,
    (void (*)())comm_care,
    (void (*)())comm_psxy,
    (void (*)())comm_ps_x,
    (void (*)())comm_ps_y,
    (void (*)())comm_paxy,
    (void (*)())comm_pa_x,
    (void (*)())comm_pa_y,
    (void (*)())comm_exec,
    (void (*)())comm_rngc,
    (void (*)())comm_mxyt,
    (void (*)())comm_pjmp,
    (void (*)())comm_hjmp,
    (void (*)())comm_hclr,
    (void (*)())comm_ixfw,
    (void (*)())comm_ixbw,
    (void (*)())comm_quax,
    (void (*)())comm_quay,
    (void (*)())comm_if_s,
    (void (*)())comm_rapp,
    (void (*)())comm_rapk,
    (void (*)())comm_gets,
    (void (*)())comm_s123,
    (void (*)())comm_s456,
    (void (*)())comm_a123,
    (void (*)())comm_a456,
    (void (*)())comm_stop,
    (void (*)())comm_smhf,
    (void (*)())comm_ngme,
    (void (*)())comm_ngem,
    (void (*)())comm_iflb,
    (void (*)())comm_asxy,
    (void (*)())comm_schx,
    (void (*)())comm_schy,
    (void (*)())comm_back,
    (void (*)())comm_mvix,
    (void (*)())comm_sajp,
    (void (*)())comm_ccch,
    (void (*)())comm_wset,
    (void (*)())comm_wswk,
    (void (*)())comm_wadd,
    (void (*)())comm_wceq,
    (void (*)())comm_wcne,
    (void (*)())comm_wcgt,
    (void (*)())comm_wclt,
    (void (*)())comm_wadd2,
    (void (*)())comm_wceq2,
    (void (*)())comm_wcne2,
    (void (*)())comm_wcgt2,
    (void (*)())comm_wclt2,
    (void (*)())comm_rapp2,
    (void (*)())comm_rapk2,
    (void (*)())comm_iflg,
    (void (*)())comm_mpcy,
    (void (*)())comm_epcy,
    (void (*)())comm_imgs,
    (void (*)())comm_imgc,
    (void (*)())comm_rvxy,
    (void (*)())comm_rv_x,
    (void (*)())comm_rv_y,
    (void (*)())comm_ccfl,
    (void (*)())comm_myhp,
    (void (*)())comm_emhp,
    (void (*)())comm_exbgs,
    (void (*)())comm_exbgc,
    (void (*)())comm_atmf,
    (void (*)())comm_chkwf,
    (void (*)())comm_retmj,
    (void (*)())comm_sstx,
    (void (*)())comm_ssty,
    (void (*)())comm_ngda,
    (void (*)())comm_flip,
    (void (*)())comm_kage,
    (void (*)())comm_dspf,
    (void (*)())comm_ifrlf,
    (void (*)())comm_srlf,
    (void (*)())comm_bgrlf,
    (void (*)())comm_scmd,
    (void (*)())comm_rljmp,
    (void (*)())comm_ifs2,
    (void (*)())comm_abbak,
    (void (*)())comm_sse,
    (void (*)())comm_s_chg,
    (void (*)())comm_ifs3,
};

void (*const comm_if_jmp_tbl[16])() = {
    (void (*)())comm_dummy,
    (void (*)())comm_ret,
    (void (*)())comm_uja,
    (void (*)())comm_uja2,
    (void (*)())comm_uja3,
    (void (*)())comm_uja4,
    (void (*)())comm_uja5,
    (void (*)())comm_uja6,
    (void (*)())comm_uja7,
    (void (*)())comm_umja,
    (void (*)())comm_back,
    (void (*)())comm_nex,
    (void (*)())comm_nex2,
    (void (*)())comm_wca,
    (void (*)())comm_retmj,
    (void (*)())comm_abbak,
};

const u16 acatkoa_table[66] = {
    4, 4, 8, 8, 8, 8, 8, 8,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x800, 0xFFFF,
};
