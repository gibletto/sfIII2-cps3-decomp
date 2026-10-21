/*
 * TEXTSOUND_2.C  Text layer printing, sprite DMA copies and the sound driver interface (part 2)
 *
 * Sound driver interface: sound_driver_init, sound_request / sound_seq_start start a sound or music
 * sequence on the BGM or sound-effect voices, and the sound_reg_* and voice_* routines trigger, set
 * levels, read status, mute and fade. sound_driver_tick, called from the vertical blank interrupt,
 * runs the master fade and then processes all 16 BGM and 16 effect voices through sound_voice.c.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice.h"
#include "sound_voice_2.h"
#include "textsound_2.h"
#include "cps3.h"



u32 * snd_seq_data;  /* 0207318C */
SNDRAMP se_ramp_req;  /* 02073190 */
u16 snd_reg_save;  /* 02073198 */
u16 snd_seq_max;  /* 0207319A */
u8 bgm_status_save[16];  /* 0207319C */
u8 sound_sample_submit_work7;  /* 020731AC */
u8 sound_sample_submit_work7_tail[1];  /* after sound_sample_submit_work7; nothing refers to it by name or address */
u8 bgm_master_vol_init;  /* 020731AE */



/* provisional name */
/* 2i 060F9B78, 3s-near: sf3 src/textsound_2.c:64 sound_driver_version */
s32 sound_driver_version(void)
{
  return (s32)((s16)(328));
}

/* provisional name */
/* 2i 060F9B7E, 3s-reloc: sf3 src/textsound_2.c:70 sound_sample_bank_set */
void sound_sample_bank_set(u16 bank)
{
    snd_wave_bias = bank;
}



/* provisional name */
/* 2i 060F9B84, 3s-near: sf3 src/textsound_2.c:78 sound_init */
void sound_init(u8* data, SNDSAMPLE* bank_a, u8** bank_b, u8 stereo, u8 volume, u8 flag) {
    u16 init[21] = {
        3, 1, 3, 1, 3, 1, 3, 0, 2, 1, 3, 0, 2, 0, 2, 0, 2, 2, 6, 6, 2
    };
    u16* p;
    s32 n;
    volatile u16* reg;
    SNDVOICE* v;
    snd_attack_ptr = snd_attack_rate_tbl;
    snd_decay_ptr = snd_decay_rate_tbl;
    snd_lfo_rate_ptr = snd_lfo_rate_tbl;
    snd_pitch_lfo_ptr = snd_pitch_lfo_tbl;
    snd_vol_lfo_ptr = snd_vol_lfo_tbl;
    snd_sample_tbl = bank_a;
    snd_bank_tbl = bank_b;
    snd_stereo = flag;
    for (p = init; p < &init[21]; p++) {
        *(u16*)(EXT_SW + 0x202) = *p;
        n = 0x100;
        while (n--) {
        }
    }
    (void)&((TEXT_CELL*)n)->code;
    reg = (volatile u16*)SOUND_REG;
    for (n = 0x100; n != 0; reg++) {
        *reg = 0;
        n--;
    }
    ((u16 (*)[2])&snd_ctrl)[0][0] = (volume << 8) | (stereo & 1) | 0x22;
    *(u32*)(SOUND_REG + 0x210) = ((u32 (*)[1])&snd_ctrl)[0][0];
    *(u16*)(SOUND_REG + 0x200) = 0;
    snd_seq_data = (u32*)data;
    snd_seq_max = *data++;
    snd_seq_max <<= 8;
    snd_seq_max += *data++;
    bgm_master_vol = *data++;
    bgm_master_vol_init = bgm_master_vol;
    snd_master_vol = *data;
    sound_sample_submit_work7 = 1;
    voice_reset:;
    voice_state_init_pair_work = 0;
    sound_sample_submit_work4 = 0;
    snd_fade_level = 0;
    snd_fade_speed = 0;
    for (n = 0; n < 16; n++) {
        bgm_voice[n].status = 0xC0;
        bgm_status_save[n] = 0xC0;
    }
    for (v = se_voice; v < &se_voice[16];) {
        (v++)->status = 0xC0;
        (v++)->status = 0xC0;
    }
}






/* provisional name */
/* 2i 060F9D18, 3s-exact: sf3 src/textsound_2.c:144 sound_request */
s32 sound_request(s32 code) {
    return sound_seq_start(code, -1);
}



/* provisional name */
/* 2i 060F9D1C, 3s-near: sf3 src/textsound_2.c:151 sound_seq_start */
s32 sound_seq_start(u16 code, s16 ramp) {
    u8* seq;
    u8* p;
    u8* track;
    u8* bank;
    u8** bank_table;
    SNDPATCH* initial_patch;
    SNDVOICE* v;
    SNDVOICE* mv;
    SNDVOICE* vp;
    u32 ofs;
    s32 ticks;
    s32 n;
    u16 off;
    u8 hdr;
    u8 ch;
    u8 i;
    for (;;) {
        if (code < snd_seq_max) {
            break;
        }
        code -= snd_seq_max;
    }
    ofs = snd_seq_data[code + 1];
    if (ofs == 0) {
        return;
    }
    seq = (u8*)((u32)snd_seq_data + ofs);
    p = seq;
    hdr = *p++;
    if (!hdr) {
        bgm_stop();
        if (0) {
            return;
        }
        i = 0;
        mv = bgm_voice;
        vp = &bgm_voice[0];
        for (; i < 16; ) {
            off = *p++ << 8;
            off += *p++;
            if (off) {
                track = seq + off;
                v = vp;
                v->origin = track;
                n = midi_vlq_decode_while(track, &ticks);
                ticks <<= 8;
                v->event_ticks = ticks;
                v->cursor = &track[n];
                v->status = 0x20;
                bank_table = snd_bank_tbl;
                v->patch = (SNDPATCH*)(*bank_table + *(u16*)*bank_table);
                v->sample = &snd_sample_tbl[v->patch->sample_index];
                v->note_ticks = 0;
                v->decoded_pitch = 0;
                v->target_pitch = 0;
                v->current_pitch = 0;
                v->pitch_lfo = 0;
                v->volume_lfo = 0;
                v->pitch_lfo_depth = 0;
                v->volume_lfo_depth = 0;
                v->lfo_rate = 0;
                v->envelope_level = 0;
                v->saved_portamento_step = 0;
                v->portamento_step = 0;
                v->program_index = 0;
                v->attack_peak = 0;
                v->attack_rate = 0;
                v->sustain_level = 0;
                v->decay_rate = 0;
                v->release_rate = 0;
                v->forced_release_rate = 0;
                v->loop_count[0] = 0;
                v->loop_count[1] = 0;
                v->loop_count[2] = 0;
                v->loop_count[3] = 0;
                v->loop_latch = 0;
                v->envelope_phase = 0;
                v->lfo_phase_flags = 0;
                v->priority_flags = hdr;
                v->volume = 0;
                v->velocity = 0;
                v->expression = 0x40;
                v->volume_offset = 0;
                v->transpose = 0;
                v->coarse_pitch_bend = 0;
                v->fine_pitch_control = 0x40;
                v->key_on_pending = 0;
                v->duration_enabled = 0;
                v->note_event_pending = 0;
                v->tie = 0;
                v->release_pending = 0;
                v->restart_pending = 0;
                v->pan_override = 0x40;
                v->control_70 = 0;
            } else {
                mv->status = 0xC0;
            }
            i++, vp++, mv = mv + 1;
            off = *p++ << 8;
            off += *p++;
            if (off) {
                track = seq + off;
                (v = vp)->origin = track;
                n = midi_vlq_decode_while(track, &ticks);
                ticks <<= 8;
                v->event_ticks = ticks;
                v->cursor = &track[n];
                v->status = 0x20;
                bank_table = snd_bank_tbl;
                v->patch = (SNDPATCH*)(*bank_table + *(u16*)*bank_table);
                v->sample = &snd_sample_tbl[v->patch->sample_index];
                v->note_ticks = 0;
                v->decoded_pitch = 0;
                v->target_pitch = 0;
                v->current_pitch = 0;
                v->pitch_lfo = 0;
                v->volume_lfo = 0;
                v->pitch_lfo_depth = 0;
                v->volume_lfo_depth = 0;
                v->lfo_rate = 0;
                v->envelope_level = 0;
                v->saved_portamento_step = 0;
                v->portamento_step = 0;
                v->program_index = 0;
                v->attack_peak = 0;
                v->attack_rate = 0;
                v->sustain_level = 0;
                v->decay_rate = 0;
                v->release_rate = 0;
                v->forced_release_rate = 0;
                v->loop_count[0] = 0;
                v->loop_count[1] = 0;
                v->loop_count[2] = 0;
                v->loop_count[3] = 0;
                v->loop_latch = 0;
                v->envelope_phase = 0;
                v->lfo_phase_flags = 0;
                v->priority_flags = hdr;
                v->volume = 0;
                v->velocity = 0;
                v->expression = 0x40;
                v->volume_offset = 0;
                v->transpose = 0;
                v->coarse_pitch_bend = 0;
                v->fine_pitch_control = 0x40;
                v->key_on_pending = 0;
                v->duration_enabled = 0;
                v->note_event_pending = 0;
                v->tie = 0;
                v->release_pending = 0;
                v->restart_pending = 0;
                v->pan_override = 0x40;
                v->control_70 = 0;
            } else {
                mv->status = 0xC0;
            }
            i++, vp++, mv = mv + 1;
            off = *p++ << 8;
            off += *p++;
            if (off) {
                track = seq + off;
                v = vp;
                vp->origin = track;
                n = midi_vlq_decode_while(track, &ticks);
                ticks <<= 8;
                v->event_ticks = ticks;
                v->cursor = &track[n];
                v->status = 0x20;
                bank_table = snd_bank_tbl;
                v->patch = (SNDPATCH*)(*bank_table + *(u16*)*bank_table);
                v->sample = &snd_sample_tbl[v->patch->sample_index];
                v->note_ticks = 0;
                v->decoded_pitch = 0;
                v->target_pitch = 0;
                v->current_pitch = 0;
                v->pitch_lfo = 0;
                v->volume_lfo = 0;
                v->pitch_lfo_depth = 0;
                v->volume_lfo_depth = 0;
                v->lfo_rate = 0;
                v->envelope_level = 0;
                v->saved_portamento_step = 0;
                v->portamento_step = 0;
                v->program_index = 0;
                v->attack_peak = 0;
                v->attack_rate = 0;
                v->sustain_level = 0;
                v->decay_rate = 0;
                v->release_rate = 0;
                v->forced_release_rate = 0;
                v->loop_count[0] = 0;
                v->loop_count[1] = 0;
                v->loop_count[2] = 0;
                v->loop_count[3] = 0;
                v->loop_latch = 0;
                v->envelope_phase = 0;
                v->lfo_phase_flags = 0;
                v->priority_flags = hdr;
                v->volume = 0;
                v->velocity = 0;
                v->expression = 0x40;
                v->volume_offset = 0;
                v->transpose = 0;
                v->coarse_pitch_bend = 0;
                v->fine_pitch_control = 0x40;
                v->key_on_pending = 0;
                v->duration_enabled = 0;
                v->note_event_pending = 0;
                v->tie = 0;
                v->release_pending = 0;
                v->restart_pending = 0;
                v->pan_override = 0x40;
                v->control_70 = 0;
            } else {
                mv->status = 0xC0;
            }
            i++, vp++, mv = mv + 1;
            off = *p++ << 8;
            off += *p++;
            if (off) {
                track = seq + off;
                v = vp;
                vp->origin = track;
                n = midi_vlq_decode_while(track, &ticks);
                ticks <<= 8;
                v->event_ticks = ticks;
                v->cursor = &track[n];
                v->status = 0x20;
                bank_table = snd_bank_tbl;
                v->patch = (SNDPATCH*)(*bank_table + *(u16*)*bank_table);
                v->sample = &snd_sample_tbl[v->patch->sample_index];
                v->note_ticks = 0;
                v->decoded_pitch = 0;
                v->target_pitch = 0;
                v->current_pitch = 0;
                v->pitch_lfo = 0;
                v->volume_lfo = 0;
                v->pitch_lfo_depth = 0;
                v->volume_lfo_depth = 0;
                v->lfo_rate = 0;
                v->envelope_level = 0;
                v->saved_portamento_step = 0;
                v->portamento_step = 0;
                v->program_index = 0;
                v->attack_peak = 0;
                v->attack_rate = 0;
                v->sustain_level = 0;
                v->decay_rate = 0;
                v->release_rate = 0;
                v->forced_release_rate = 0;
                v->loop_count[0] = 0;
                v->loop_count[1] = 0;
                v->loop_count[2] = 0;
                v->loop_count[3] = 0;
                v->loop_latch = 0;
                v->envelope_phase = 0;
                v->lfo_phase_flags = 0;
                v->priority_flags = hdr;
                v->volume = 0;
                v->velocity = 0;
                v->expression = 0x40;
                v->volume_offset = 0;
                v->transpose = 0;
                v->coarse_pitch_bend = 0;
                v->fine_pitch_control = 0x40;
                v->key_on_pending = 0;
                v->duration_enabled = 0;
                v->note_event_pending = 0;
                v->tie = 0;
                v->release_pending = 0;
                v->restart_pending = 0;
                v->pan_override = 0x40;
                v->control_70 = 0;
            } else {
                mv->status = 0xC0;
            }
            i++, vp++, mv = mv + 1;
        }
        if (!(sound_sample_submit_work7 & 8)) {
            snd_fade_level = 0x8000;
        }
        bgm_tick_step = 0;
        if (0) {
            sound_sample_submit_work7 |= 8;
        }
        sound_sample_submit_work7 |= 2;
        return;
    } else if (!(hdr & 0x80)) {
        for (i = 0; i < 16; i++) {
            off = *p++ << 8;
            off = off + *p++;
            if (off) {
                if (((hdr >= se_voice[i].priority_flags) & 0x7F) || (se_voice[i].status & 0x80)) {
                    track = seq + off;
                    n = midi_vlq_decode_while(track, &ticks);
                    ticks <<= 8;
                    se_voice[i].event_ticks = ticks;
                    se_voice[i].cursor = &track[n];
                    se_voice[i].status = 0;
                    bank_table = snd_bank_tbl;
                    bank = *bank_table;
                    (void)&((TEXT_CELL*)bank_table)->code;
                    se_voice[i].patch = (SNDPATCH*)(bank + *(u16*)bank);
                    se_voice[i].sample = &snd_sample_tbl[se_voice[i].patch->sample_index];
                    se_voice[i].decoded_pitch = 0;
                    se_voice[i].target_pitch = 0;
                    se_voice[i].current_pitch = 0;
                    se_voice[i].pitch_lfo = 0;
                    se_voice[i].volume_lfo = 0;
                    se_voice[i].pitch_lfo_depth = 0;
                    se_voice[i].volume_lfo_depth = 0;
                    se_voice[i].lfo_rate = 0;
                    se_voice[i].envelope_level = 0;
                    se_voice[i].saved_portamento_step = 0;
                    se_voice[i].portamento_step = 0;
                    se_voice[i].program_index = 0;
                    se_voice[i].attack_peak = 0;
                    se_voice[i].attack_rate = 0;
                    se_voice[i].sustain_level = 0;
                    se_voice[i].decay_rate = 0;
                    se_voice[i].release_rate = 0;
                    se_voice[i].forced_release_rate = 0;
                    se_voice[i].loop_count[0] = 0;
                    se_voice[i].loop_count[1] = 0;
                    se_voice[i].loop_count[2] = 0;
                    se_voice[i].loop_count[3] = 0;
                    se_voice[i].loop_latch = 0;
                    se_voice[i].envelope_phase = 0;
                    se_voice[i].pan_override = 0x40;
                    se_voice[i].lfo_phase_flags = 0;
                    se_voice[i].priority_flags = hdr;
                    se_voice[i].volume = 0;
                    bgm_voice[i].velocity = 0x7F;
                    se_voice[i].expression = 0x7F;
                    se_voice[i].volume_offset = 0;
                    se_voice[i].transpose = 0;
                    se_voice[i].coarse_pitch_bend = 0;
                    se_voice[i].fine_pitch_control = 0x40;
                    se_voice[i].key_on_pending = 0;
                    se_voice[i].duration_enabled = 0;
                    se_voice[i].note_event_pending = 0;
                    se_voice[i].tie = 0;
                    se_voice[i].release_pending = 0;
                    se_voice[i].pan_override = 0x40;
                    se_voice[i].control_70 = 0;
                    if (ramp != -1) {
                        se_pan_ramp[i].current = se_ramp_req.current;
                        se_pan_ramp[i].target = se_ramp_req.target;
                        se_pan_ramp[i].step = se_ramp_req.step;
                        se_pan_ramp[i].mode = se_ramp_req.mode;
                    } else {
                        se_pan_ramp[i].current = 0;
                        se_pan_ramp[i].target = 0;
                        se_pan_ramp[i].step = 0;
                        se_pan_ramp[i].mode = -1;
                    }
                    se_tick_step[i] = 0;
                }
            }
        }
        (void)&((WORK*)se_tick_step)->id;
        return;
    }
    if (ch = hdr & 15, (*p & 0x7F) < (se_voice[ch].priority_flags & 0x7F) && !(se_voice[ch].status & 0x80)) {
        return;
    }
    se_voice[ch].cursor = p;
    (void)&((WORK*)seq)->id;
    bank_table = snd_bank_tbl;
    se_voice[ch].patch = (SNDPATCH*)(*bank_table + *(u16*)*bank_table);
    (void)&((WORK*)hdr)->id;
    se_voice[ch].sample = &snd_sample_tbl[se_voice[ch].patch->sample_index];
    se_voice[ch].envelope_level = 0;
    se_voice[ch].program_index = 0;
    se_voice[ch].attack_peak = 0;
    se_voice[ch].attack_rate = 0;
    se_voice[ch].sustain_level = 0;
    se_voice[ch].decay_rate = 0;
    se_voice[ch].release_rate = 0;
    se_voice[ch].forced_release_rate = 0;
    se_voice[ch].volume = 0;
    se_voice[ch].velocity = 0x7F;
    se_voice[ch].expression = 0x7F;
    se_voice[ch].volume_offset = 0;
    se_voice[ch].transpose = 0;
    se_voice[ch].coarse_pitch_bend = 0;
    se_voice[ch].fine_pitch_control = 0x40;
    se_voice[ch].priority_flags = *p | 0x80;
    se_voice[ch].pan_override = 0x40;
    if (ramp != -1) {
        se_pan_ramp[ch].current = se_ramp_req.current;
        se_pan_ramp[ch].target = se_ramp_req.target;
        se_pan_ramp[ch].step = se_ramp_req.step;
        se_pan_ramp[ch].mode = se_ramp_req.mode;
    } else {
        se_pan_ramp[ch].current = 0;
        se_pan_ramp[ch].target = 0;
        se_pan_ramp[ch].step = 0;
        se_pan_ramp[ch].mode = -1;
    }
    se_voice[ch].status = 0;
}



/* provisional name */
/* 2i 060FA9BA, 3s-near: sf3 src/textsound_2.c:561 sound_request_pan */
void sound_request_pan(u16 code, s16 vol_l, s16 vol_r, s16 time, s16 ramp) {
    se_ramp_req.current = vol_l << 8;
    se_ramp_req.target = vol_r << 8;
    se_ramp_req.step = (se_ramp_req.target - se_ramp_req.current) / time;
    se_ramp_req.mode = ramp;
    sound_seq_start(code, ramp);
}



/* provisional name */
/* 2i 060FA9EC, 3s-reloc: sf3 src/textsound_2.c:582 bgm_stop */
void bgm_stop(void) {
    u8 i;
    if (!(sound_sample_submit_work7 & 2)) {
        return;
    }
    for (i = 0; i < 16; i++) {
        bgm_voice[i].status = 192;
    }
    sound_sample_submit_work7 = 1;
    snd_reg_save = 0;
}



/* provisional name */
/* 2i 060FAA40, 3s-reloc: sf3 src/textsound_2.c:597 bgm_pause */
void bgm_pause(void) {
    u8 i;
    if (!(sound_sample_submit_work7 & 2) || (sound_sample_submit_work7 & 4)) {
        return;
    }
    snd_reg_save = *(u16*)(SOUND_REG + 0x200);
    for (i = 0; i < 16; i++) {
        bgm_status_save[i] = bgm_voice[i].status;
        bgm_voice[i].status = 192;
    }
    sound_sample_submit_work7 |= 4;
}


/* provisional name */
/* 2i 060FAA96, 3s-reloc: sf3 src/textsound_2.c:612 bgm_resume */
void bgm_resume(void) {
    u8* save;
    SNDVOICE* v;
    u8 i;
    if (!(sound_sample_submit_work7 & 2) || !(sound_sample_submit_work7 & 4)) {
        return;
    }
    for (i = 0, save = bgm_status_save, v = bgm_voice; i < 16; i++) {
        v->status = *save;
        save++;
        v++;
    }
    sound_sample_submit_work7 &= ~4;
    *(u16*)(SOUND_REG + 0x200) |= snd_reg_save;
}

/* provisional name */
/* 2i 060FAAE0, 3s-reloc: sf3 src/textsound_2.c:629 sound_fade_in_submit */
u32 sound_fade_in_submit(u16 code_no, u16 speed)
{
    snd_fade_level = 0;
    snd_fade_speed = speed & 0x7FFF;
    sound_sample_submit_work7 |= 8;
    return sound_seq_start(code_no, -1);
}



/* provisional name */
/* 2i 060FAB04, 3s-reloc: sf3 src/textsound_2.c:640 bgm_fade_out */
void bgm_fade_out(cmd)
u16 cmd;
{
    if (sound_sample_submit_work7 & 2) {
        snd_fade_speed = cmd & 0x7FFF;
        sound_sample_submit_work7 &= 0xF7;
        sound_sample_submit_work7 |= 16;
    }
}



/* provisional name */
/* 2i 060FAB28, 3s-reloc: sf3 src/textsound_2.c:653 sound_reg_level_set */
void sound_reg_level_set(s16 level, s8 flag) {
    voice_state_init_pair_work = level;
    sound_sample_submit_work4 = flag;
}



/* provisional name */
/* 2i 060FAB32, 3s-reloc: sf3 src/textsound_2.c:661 sound_status_read */
u8 sound_status_read(void) {
    return sound_sample_submit_work7;
}



/* provisional name */
/* 2i 060FAB60, inferred: sf3 src/textsound_2.c:668 sound_driver_init */
void sound_driver_init(void) {
    u8 i;
    for (i = 0; i < 16; i++) {
        bgm_voice[i].status = 192;
        se_voice[i].status = 192;
    }
    sound_sample_submit_work7 = 1;
    *(u16*)(SOUND_REG + 0x200) = 0;
    snd_reg_save = 0;
}



/* provisional name */
/* 2i 060FABB0, inferred: sf3 src/textsound_2.c:683 se_voice_stop */
void se_voice_stop(u8 ch) {
    se_voice[ch].status = 192;
}



/* provisional name */
/* 2i 060FABC6, inferred: sf3 src/textsound_2.c:691 se_voice_stop_all */
void se_voice_stop_all(void) {
    u8 i;
    for (i = 0; i < 16; i++) {
        se_voice[i].status = 192;
    }
}



/* provisional name */
/* 2i 060FABE4, 3s-near: sf3 src/textsound_2.c:702 sound_driver_tick */
void sound_driver_tick(void) {
    u32 i;
    if ((sound_sample_submit_work7 & 8) && !(sound_sample_submit_work7 & 4)) {
        snd_fade_level += snd_fade_speed;
        if (snd_fade_level >= 0x8000) {
            snd_fade_level = 0x8000;
            sound_sample_submit_work7 &= ~8;
        }
    }
    if ((sound_sample_submit_work7 & 0x10) && !(sound_sample_submit_work7 & 4)) {
        if (snd_fade_speed >= snd_fade_level) {
            bgm_stop();
            snd_fade_level = 0;
            sound_sample_submit_work7 &= ~0x10;
        } else {
            snd_fade_level -= snd_fade_speed;
        }
    }
    for (i = 0; i < 16; i++) {
        voice_process_primary(&bgm_voice[i], 1, i);
    }
    for (i = 0; i < 16; i++) {
        if (se_voice[i].priority_flags & 0x80) {
            voice_process_null(&se_voice[i], i);
        } else {
            voice_process_primary(&se_voice[i], 0, i);
        }
    }
    for (i = 0; i < 16; i++) {
        voice_process_secondary(&bgm_voice[i], i, 1);
    }
    for (i = 0; i < 16; i++) {
        if (!(se_voice[i].priority_flags & 0x80)) {
            voice_process_secondary(&se_voice[i], i, 0);
        }
    }
}
