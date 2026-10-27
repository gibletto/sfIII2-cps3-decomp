/*
 * SOUND_VOICE.C  Sound driver voice sequencer
 *
 * The per-voice core of the sound driver, called every tick from the driver tick in textsound.c for
 * each of the 16 BGM voices and 16 sound-effect voices. voice_process_primary reads the voice's
 * event stream: note events look up the instrument patch for the note in the current bank, set the
 * sample and pitch and compute the attack, decay and release rates (sound_envelope_rate); control
 * events change program, volume, pan, tempo, loops and ties. voice_process_secondary counts down the
 * event and note times, runs the envelope and pan automation, works out pitch (sound_note_to_pitch)
 * and volume (sound_voice_volume_compute) and writes the result to that voice's sound chip
 * registers, handling key-on/key-off. A BGM voice only reaches the hardware while no sound effect
 * holds the same channel. midi_vlq_decode_* decode variable-length delta times from the sequence
 * data.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice_2.h"
#include "sound_voice.h"
#include "seqop.h"
#include "cps3.h"
/* provisional name */
u32 sound_envelope_rate(u16 level, u8 index, const u16* table) {
    u32 rate;

    table += index;
    rate = (u32)(level * (*table + 1)) >> 16;
    if (rate) {
        return rate;
    }
    return 1;
}



/* provisional name */
void voice_process_null(void)
{
  return;
}



/* provisional name */
void voice_process_primary(SNDVOICE* voice, s8 is_bgm, u8 voice_index) {
    u8* argument;
    u8 event;
    u8 loop_index;
    u8 skip_index;
    s32 note;
    u32 event_mask;
    s16 note_resolved;
    s32 consumed;
    s32 ticks;
    s32 relative;
    SNDPATCH* patch;
    SNDVOICE* paired_bgm_voice;
    SNDRAMP* automation;
    u16* sfx_ticks;
    u16* bgm_ticks;
    if (voice->status & 0x60) {
        return;
    }
    sfx_ticks = &se_tick_step[voice_index];
    paired_bgm_voice = &bgm_voice[voice_index];
    automation = &se_pan_ramp[voice_index];
    bgm_ticks = &bgm_tick_step;
    (void)&((WORK*)bgm_ticks)->id;
    event_mask = 0x80;
    (void)&((WORK*)1)->id;
    (void)&((WORK*)0)->id;
next_event:
    argument = voice->cursor;
    event = *argument++;
    if (event >= SEQ_CONTROL) {
control_event:;
        switch (event) {
        case SEQ_NOP:
            break;
        case SEQ_TEMPO:
            if (is_bgm) {
                *bgm_ticks = *argument++ << 8;
                *bgm_ticks += *argument++;
            } else {
                *sfx_ticks = *argument++ << 8;
                *sfx_ticks += *argument++;
            }
            break;
        case SEQ_BANK:
            voice->instrument_bank = *argument++ & 0x0f;
            break;
        case SEQ_BEND:
            voice->coarse_pitch_bend = *argument++;
            break;
        case SEQ_FINE:
            voice->fine_pitch_control = *argument++;
            break;
        case SEQ_PROG:
            voice->program_index = *argument++ & 0x7f;
            break;
        case SEQ_PLFO:
            event = *argument++;
            voice->pitch_lfo_depth = snd_pitch_lfo_ptr[event];
            break;
        case SEQ_VOL:
            voice->volume = *argument++;
            break;
        case SEQ_PAN:
            voice->pan_override = *argument++;
            break;
        case SEQ_EXPR:
            voice->expression = *argument++;
            break;
        case SEQ_PORTA:
            voice->saved_portamento_step = voice->portamento_step;
            event = *argument++;
            if (event) {
                voice->portamento_step = (event + 1) * 2;
                voice->saved_portamento_step = voice->portamento_step;
            } else {
                voice->status &= ~0x02;
                voice->portamento_step = 0;
            }
            break;
        case SEQ_REPEAT:
            if (!voice->loop_latch) {
                argument = voice->origin;
                voice->loop_latch = 1;
            }
            break;
        case SEQ_END_REPEAT:
            if (voice->loop_latch) {
                voice->status |= 0x40;
                return;
            }
            break;
        case SEQ_JUMP2:
            if (voice->loop_latch) {
                relative = (s8)*argument++ * 0x100;
                relative += (s8)*argument++;
                argument += relative;
                voice->loop_latch = 1;
            } else {
                argument += 2;
            }
            break;
        case SEQ_JUMP1:
            if (!voice->loop_latch) {
                relative = (s8)argument[0] * 0x100 + argument[1] + 2;
                argument += relative;
                voice->loop_latch = 1;
            } else {
                argument += 2;
            }
            break;
        case SEQ_JUMP:
            relative = (s8)*argument++;
            relative <<= 8;
            relative |= *argument++;
            argument += relative;
            break;
        case SEQ_JUMP_TRACK:
            argument = bgm_voice[*argument].origin;
            break;
        case SEQ_LOOP_START:
        case SEQ_LOOP_START + 1:
        case SEQ_LOOP_START + 2:
        case SEQ_LOOP_START + 3:
            voice->loop_cursor[event - SEQ_LOOP_START] = argument;
            break;
        case SEQ_LOOP:
        case SEQ_LOOP + 1:
        case SEQ_LOOP + 2:
        case SEQ_LOOP + 3:
            loop_index = event - SEQ_LOOP;
            if (voice->loop_count[loop_index]) {
                voice->loop_count[loop_index]--;
                if (voice->loop_count[loop_index]) {
                    argument = voice->loop_cursor[loop_index];
                } else {
                    argument++;
                }
            } else {
                voice->loop_count[loop_index] = *argument;
                argument = voice->loop_cursor[loop_index];
            }
            break;
        case SEQ_LOOP_EXIT:
        case SEQ_LOOP_EXIT + 1:
        case SEQ_LOOP_EXIT + 2:
        case SEQ_LOOP_EXIT + 3:
            skip_index = event - SEQ_LOOP_EXIT;
            if (voice->loop_count[skip_index] == 1) {
                voice->loop_count[skip_index] = 0;
                relative = (argument[0] << 8) + argument[1];
                argument += 2;
                argument += relative;
            } else {
                argument += 2;
            }
            break;
        case SEQ_KEY:
            voice->transpose = (s8)*argument++;
            break;
        case SEQ_KEY_ADD:
            voice->transpose += (s8)*argument++;
            break;
        case SEQ_TUNE:
            voice->volume_offset = (s8)*argument++;
            break;
        case SEQ_TUNE_ADD:
            voice->volume_offset += (s8)*argument++;
            break;
        case SEQ_LFO_SYNC:
            if (*argument++) {
                voice->status |= 0x01;
            } else {
                voice->status &= ~0x01;
            }
            break;
        case SEQ_LFO_RATE:
            event = *argument++;
            voice->lfo_rate = snd_lfo_rate_ptr[event];
            break;
        case SEQ_VLFO:
            event = *argument++;
            voice->volume_lfo_depth = snd_vol_lfo_ptr[event];
            break;
        case SEQ_PRIO:
            voice->priority_flags = *argument++;
            break;
        case SEQ_E4:
        case SEQ_E5:
            argument += 2;
            break;
        case SEQ_E6:
            argument++;
            break;
        case SEQ_END:
            voice->status |= 0x40;
            if (!is_bgm) {
                if (!(paired_bgm_voice->status & event_mask)) {
                    paired_bgm_voice->restart_pending = 1;
                    if (!(paired_bgm_voice->patch->sample_index & 0x8000)) {
                        paired_bgm_voice->envelope_level = 0;
                        paired_bgm_voice->envelope_phase = 0;
                    }
                }
            }
            automation->mode = -1;
            return;
        default:
            break;
        }
    } else {
        u8** bank;
        u16* entry;
        note_resolved = 1;
        voice->velocity = (event & 0x3f) << 1;
        note = *argument & 0x7f;
        voice->control_70 = note;
        bank = snd_bank_tbl;
        bank = bank + voice->instrument_bank;
        if (*bank != 0) {
            entry = (u16*)*bank;
            entry = entry + voice->program_index;
            if (*entry) {
                patch = (SNDPATCH*)(*entry + *bank);
                for (;;) {
                    if (patch->note_ceiling == -1) {
                        patch = 0;
                        break;
                    } else if ((s16)note <= patch->note_ceiling) {
                        break;
                    }
                    patch++;
                    note *= 1;
                    note *= 1;
                    note *= 1;
                }
                if (patch) {
                    voice->patch = patch;
                    voice->sample = snd_sample_tbl;
                    voice->sample += voice->patch->sample_index & 0x7FFF;
                    voice->decoded_pitch = (s16)(((note - voice->sample->base_pitch + voice->transpose + 7) << 8) + event_mask + voice->patch->pitch_bias);
                    voice->attack_peak = voice->velocity << 8;
                    voice->sustain_level = ((u16)(voice->patch->velocity_scale + 1) * voice->attack_peak) >> 7;
                    voice->attack_rate = sound_envelope_rate(voice->attack_peak, voice->patch->attack_curve, snd_attack_ptr);
                    voice->attack_rate = (voice->attack_rate * (u16)(voice->velocity + 1)) >> 7;
                    voice->decay_rate = sound_envelope_rate(voice->attack_peak, voice->patch->decay_curve, snd_decay_ptr);
                    voice->release_rate = sound_envelope_rate(voice->sustain_level, voice->patch->release_curve, snd_decay_ptr);
                    voice->note_event_pending = 1;
            } else {
                    note_resolved = 0;
                }
            } else {
                note_resolved = 0;
            }
        } else {
            note_resolved = 0;
        }
        if (note_resolved) {
            if (voice->tie) {
                voice->key_on_pending = 0;
            } else {
                voice->key_on_pending = 1;
            }
            for (;;) {
            for (;;) {
            for (;;) {
            if (*argument++ & event_mask) {
                voice->duration_enabled = 0;
                voice->tie = 1;
            } else {
                voice->duration_enabled = 1;
                voice->tie = 0;
            }
            break;
            }
            break;
            }
            break;
            }
        } else {
            voice->note_event_pending = 0;
            argument++;
            voice->duration_enabled = 0;
            voice->key_on_pending = 0;
            voice->tie = 0;
        }
        consumed = midi_vlq_decode_leading(argument, &ticks);
        ticks <<= 8;
        voice->note_ticks = ticks;
        argument += consumed;
    }
    consumed = midi_vlq_decode_while(argument, &ticks);
    ticks <<= 8;
    voice->event_ticks = voice->event_ticks + ticks;
    argument += consumed;
    voice->cursor = argument;
    if (ticks <= 0) {
        goto next_event;
    }
    voice->status |= 0x20;
    return;
}



