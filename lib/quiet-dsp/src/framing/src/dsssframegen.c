/*
 * Copyright (c) 2007 - 2015 Joseph Gaeddert
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//
// dsssdsssframegen.c
//
// dsss flexible frame generator
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

#include "liquid.internal.h"

// reconfigure internal properties
void                 dsssframegen_reconfigure(dsssframegen _q);
void                 dsssframegen_reconfigure_header(dsssframegen _q);
liquid_float_complex dsssframegen_generate_symbol(dsssframegen _q);
liquid_float_complex dsssframegen_generate_preamble(dsssframegen _q);
liquid_float_complex dsssframegen_generate_header(dsssframegen _q);
liquid_float_complex dsssframegen_generate_payload(dsssframegen _q);
liquid_float_complex dsssframegen_generate_tail(dsssframegen _q);

// default dsssframegen properties
static dsssframegenprops_s dsssframegenprops_default = {
    LIQUID_CRC_16,   // check
    LIQUID_FEC_NONE, // fec0
    LIQUID_FEC_NONE, // fec1
};

static dsssframegenprops_s dsssframegenprops_header_default = {
    DSSSFRAME_H_CRC,
    DSSSFRAME_H_FEC0,
    DSSSFRAME_H_FEC1,
};

enum state {
    STATE_PREAMBLE = 0, // write preamble p/n sequence
    STATE_HEADER,       // write header symbols
    STATE_PAYLOAD,      // write payload symbols
    STATE_TAIL,         // tail symbols
};

struct dsssframegen_s {
    // interpolator
    unsigned int         k;             // interp samples/symbol (fixed at 2)
    unsigned int         m;             // interp filter delay (symbols)
    float                beta;          // excess bandwidth factor
    firinterp_crcf       interp;        // interpolator object
    liquid_float_complex buf_interp[2]; // output interpolator buffer [size: k x 1]

    dsssframegenprops_s props;        // payload properties
    dsssframegenprops_s header_props; // header properties

    // preamble
    liquid_float_complex * preamble_pn; // p/n sequence
    synth_crcf             header_synth;
    synth_crcf             payload_synth;

    // header
    unsigned char *        header;          // header data
    unsigned int           header_user_len; // header user section length
    unsigned int           header_dec_len;  // header length (decoded)
    qpacketmodem           header_encoder;  // header encoder/modulator
    unsigned int           header_mod_len;  // header length
    liquid_float_complex * header_mod;

    // payload
    unsigned int           payload_dec_len; // length of decoded
    qpacketmodem           payload_encoder;
    unsigned int           payload_mod_len;
    liquid_float_complex * payload_mod;

    // counters/states
    unsigned int         symbol_counter; // output symbol number
    unsigned int         sample_counter; // output sample number
    unsigned int         bit_counter;    // output bit number
    int                  bit_high;       // current bit is 1
    liquid_float_complex sym;
    int                  frame_assembled; // frame assembled flag
    int                  frame_complete;  // frame completed flag
    enum state           state;           // write state
};

dsssframegen dsssframegen_create(dsssframegenprops_s * _fgprops)
{
    dsssframegen q = (dsssframegen)calloc(1, sizeof(struct dsssframegen_s));
    unsigned int i;

    // create pulse-shaping filter
    q->k      = 2;
    q->m      = 7;
    q->beta   = 0.25f;
    q->interp = firinterp_crcf_create_prototype(LIQUID_FIRFILT_ARKAISER, q->k, q->m, q->beta, 0);

    // generate pn sequence
    q->preamble_pn = (liquid_float_complex *)malloc(64 * sizeof(liquid_float_complex));
    msequence ms   = msequence_create(7, 0x0089, 1);
    for (i = 0; i < 64; i++) {
        q->preamble_pn[i] = (msequence_advance(ms) ? (float)M_SQRT1_2 : (float)-M_SQRT1_2);
        q->preamble_pn[i] += (msequence_advance(ms) ? (float)M_SQRT1_2 : (float)-M_SQRT1_2) * _Complex_I;
    }
    msequence_destroy(ms);

    liquid_float_complex * pn = (liquid_float_complex *)malloc(64 * sizeof(liquid_float_complex));
    ms                        = msequence_create(7, 0x00cb, 0x53);
    for (i = 0; i < 64; i++) {
        pn[i] = (msequence_advance(ms) ? (float)M_SQRT1_2 : (float)-M_SQRT1_2);
        pn[i] += (msequence_advance(ms) ? (float)M_SQRT1_2 : (float)-M_SQRT1_2) * _Complex_I;
    }
    q->header_synth  = synth_crcf_create(pn, 64);
    q->payload_synth = synth_crcf_create(pn, 64);
    free(pn);
    msequence_destroy(ms);

    dsssframegen_reset(q);

    q->header          = NULL;
    q->header_user_len = DSSSFRAME_H_USER_DEFAULT;
    q->header_dec_len  = DSSSFRAME_H_DEC + q->header_user_len;
    q->header_mod      = NULL;
    q->header_encoder  = qpacketmodem_create();

    q->payload_encoder = qpacketmodem_create();
    q->payload_dec_len = 0;
    q->payload_mod_len = 0;
    q->payload_mod     = NULL;

    dsssframegen_setprops(q, _fgprops);
    dsssframegen_set_header_props(q, NULL);
    dsssframegen_set_header_len(q, q->header_user_len);

    return q;
}

void dsssframegen_destroy(dsssframegen _q)
{
    if (!_q) {
        return;
    }

    firinterp_crcf_destroy(_q->interp);
    qpacketmodem_destroy(_q->header_encoder);
    qpacketmodem_destroy(_q->payload_encoder);
    synth_crcf_destroy(_q->header_synth);
    synth_crcf_destroy(_q->payload_synth);

    free(_q->preamble_pn);
    free(_q->header);
    free(_q->header_mod);
    free(_q->payload_mod);

    free(_q);
}

void dsssframegen_reset(dsssframegen _q)
{
    // reset internal counters and state
    _q->symbol_counter  = 0;
    _q->bit_counter     = 0;
    _q->sample_counter  = 0;
    _q->frame_assembled = 0;
    _q->frame_complete  = 0;
    _q->state           = STATE_PREAMBLE;
}

int dsssframegen_is_assembled(dsssframegen _q)
{
    return _q->frame_assembled;
}

void dsssframegen_getprops(dsssframegen _q, dsssframegenprops_s * _props)
{
    memmove(_props, &_q->props, sizeof(dsssframegenprops_s));
}

int dsssframegen_setprops(dsssframegen _q, dsssframegenprops_s * _props)
{
    if (_q->frame_assembled) {
        fprintf(
            stderr,
            "warning: dsssframegen_setprops(), frame is already assembled; must reset() first\n");
        return -1;
    }

    if (_props == NULL) {
        dsssframegen_setprops(_q, &dsssframegenprops_default);
        return 0;
    }

    if (_props->check == LIQUID_CRC_UNKNOWN || _props->check >= LIQUID_CRC_NUM_SCHEMES) {
        fprintf(stderr, "error: dsssframegen_setprops(), invalid/unsupported CRC scheme\n");
        exit(1);
    } else if (_props->fec0 == LIQUID_FEC_UNKNOWN || _props->fec1 == LIQUID_FEC_UNKNOWN) {
        fprintf(stderr, "error: dsssframegen_setprops(), invalid/unsupported FEC scheme\n");
        exit(1);
    }

    // copy properties to internal structure
    memmove(&_q->props, _props, sizeof(dsssframegenprops_s));

    // reconfigure payload buffers (reallocate as necessary)
    dsssframegen_reconfigure(_q);

    return 0;
}

void dsssframegen_set_header_len(dsssframegen _q, unsigned int _len)
{
    if (_q->frame_assembled) {
        fprintf(stderr,
                "warning: dsssframegen_set_header_len(), frame is already assembled; must reset() "
                "first\n");
        return;
    }

    _q->header_user_len = _len;
    _q->header_dec_len  = DSSSFRAME_H_DEC + _q->header_user_len;
    _q->header = (unsigned char *)realloc(_q->header, _q->header_dec_len * sizeof(unsigned char));

    dsssframegen_reconfigure_header(_q);
}

int dsssframegen_set_header_props(dsssframegen _q, dsssframegenprops_s * _props)
{
    if (_q->frame_assembled) {
        fprintf(stderr,
                "warning: dsssframegen_set_header_props(), frmae is already assembled; must "
                "reset() first\n");
        return -1;
    }

    if (_props == NULL) {
        _props = &dsssframegenprops_header_default;
    }

    if (_props->check == LIQUID_CRC_UNKNOWN || _props->check >= LIQUID_CRC_NUM_SCHEMES) {
        fprintf(stderr, "error: dsssframegen_set_header_props(), invalid/unsupported CRC scheme\n");
        exit(1);
    } else if (_props->fec0 == LIQUID_FEC_UNKNOWN || _props->fec1 == LIQUID_FEC_UNKNOWN) {
        fprintf(stderr, "error: dsssframegen_set_header_props(), invalid/unsupported FEC scheme\n");
        exit(1);
    }

    memmove(&_q->header_props, _props, sizeof(dsssframegenprops_s));

    dsssframegen_reconfigure_header(_q);

    return 0;
}

unsigned int dsssframegen_getframelen(dsssframegen _q)
{
    if (!_q->frame_assembled) {
        fprintf(stderr, "warning: dsssframegen_getframelen(), frame not assembled\n");
        return 0;
    }

    unsigned int num_frame_symbols
        = 64 + // preamble
          _q->header_mod_len * synth_crcf_get_length(_q->header_synth)
          + _q->payload_mod_len * synth_crcf_get_length(_q->payload_synth) + 2 * _q->m; // tail

    return num_frame_symbols * _q->k;
}

void dsssframegen_assemble(dsssframegen          _q,
                           const unsigned char * _header,
                           const unsigned char * _payload,
                           unsigned int          _payload_dec_len)
{
    dsssframegen_reset(_q);

    _q->payload_dec_len = _payload_dec_len;

    if (_header == NULL) {
        memset(_q->header, 0x00, _q->header_user_len * sizeof(unsigned char));
    } else {
        memmove(_q->header, _header, _q->header_user_len * sizeof(unsigned char));
    }

    unsigned int n = _q->header_user_len;

    _q->header[n + 0] = DSSSFRAME_PROTOCOL;
    _q->header[n + 1] = (_q->payload_dec_len >> 8) & 0xff;
    _q->header[n + 2] = (_q->payload_dec_len) & 0xff;
    _q->header[n + 3] = (_q->props.check & 0x07) << 5;
    _q->header[n + 3] |= (_q->props.fec0) & 0x1f;
    _q->header[n + 4] = (_q->props.fec1) & 0x1f;

    qpacketmodem_encode(_q->header_encoder, _q->header, _q->header_mod);

    _q->payload_dec_len = _payload_dec_len;
    dsssframegen_reconfigure(_q);

    qpacketmodem_encode(_q->payload_encoder, _payload, _q->payload_mod);

    _q->frame_assembled = 1;
}

int dsssframegen_write_samples(dsssframegen           _q,
                               liquid_float_complex * _buffer,
                               unsigned int           _buffer_len)
{
    unsigned int i;
    for (i = 0; i < _buffer_len; ++i) {
        if (_q->sample_counter == 0) {
            liquid_float_complex sym = dsssframegen_generate_symbol(_q);

            firinterp_crcf_execute(_q->interp, sym, _q->buf_interp);
        }

        _buffer[i] = _q->buf_interp[_q->sample_counter];

        // apply ramping window to first 'm' symbols
        if (_q->symbol_counter < _q->m && _q->state == STATE_PREAMBLE) {
            _buffer[i]
                *= hamming(_q->symbol_counter * _q->k + _q->sample_counter, 2 * _q->m * _q->k);
        }

        _q->sample_counter = (_q->sample_counter + 1) % _q->k;
    }

    return _q->frame_complete;
}

void dsssframegen_reconfigure(dsssframegen _q)
{
    qpacketmodem_configure(_q->payload_encoder,
                           _q->payload_dec_len,
                           (crc_scheme)_q->props.check,
                           (fec_scheme)_q->props.fec0,
                           (fec_scheme)_q->props.fec1,
                           LIQUID_MODEM_BPSK);
    _q->payload_mod_len = qpacketmodem_get_frame_len(_q->payload_encoder);
    _q->payload_mod     = (liquid_float_complex *)realloc(
        _q->payload_mod, _q->payload_mod_len * sizeof(liquid_float_complex));
}

void dsssframegen_reconfigure_header(dsssframegen _q)
{
    qpacketmodem_configure(_q->header_encoder,
                           _q->header_dec_len,
                           (crc_scheme)_q->header_props.check,
                           (fec_scheme)_q->header_props.fec0,
                           (fec_scheme)_q->header_props.fec1,
                           LIQUID_MODEM_BPSK);
    _q->header_mod_len = qpacketmodem_get_frame_len(_q->header_encoder);
    _q->header_mod     = (liquid_float_complex *)realloc(
        _q->header_mod, _q->header_mod_len * sizeof(liquid_float_complex));
}

liquid_float_complex dsssframegen_generate_symbol(dsssframegen _q)
{
    if (!_q->frame_assembled) {
        return 0.f;
    }

    switch (_q->state) {
    case STATE_PREAMBLE: return dsssframegen_generate_preamble(_q); break;
    case STATE_HEADER: return dsssframegen_generate_header(_q); break;
    case STATE_PAYLOAD: return dsssframegen_generate_payload(_q); break;
    case STATE_TAIL: return dsssframegen_generate_tail(_q); break;
    default:
        fprintf(
            stderr, "error: dsssframegen_generate_symbol(), unknown/unsupported internal state\n");
        exit(1);
    }

    return 0.f;
}

liquid_float_complex dsssframegen_generate_preamble(dsssframegen _q)
{
    liquid_float_complex symbol = _q->preamble_pn[_q->symbol_counter];
    ++_q->symbol_counter;

    if (_q->symbol_counter == 64) {
        _q->symbol_counter = 0;
        _q->state          = STATE_HEADER;
    }

    return symbol;
}

liquid_float_complex dsssframegen_generate_header(dsssframegen _q)
{
    if (_q->symbol_counter == 0) {
        _q->sym = _q->header_mod[_q->bit_counter];
    }

    liquid_float_complex symbol;
    synth_crcf_mix_up(_q->header_synth, _q->sym, &symbol);
    synth_crcf_step(_q->header_synth);

    ++_q->symbol_counter;
    if (_q->symbol_counter == synth_crcf_get_length(_q->header_synth)) {
        _q->symbol_counter = 0;
        ++_q->bit_counter;
        if (_q->bit_counter == _q->header_mod_len) {
            _q->bit_counter = 0;
            _q->state       = STATE_PAYLOAD;
        }
    }

    return symbol;
}

liquid_float_complex dsssframegen_generate_payload(dsssframegen _q)
{
    if (_q->symbol_counter == 0) {
        _q->sym = _q->payload_mod[_q->bit_counter];
    }

    liquid_float_complex symbol;
    synth_crcf_mix_up(_q->payload_synth, _q->sym, &symbol);
    synth_crcf_step(_q->payload_synth);

    ++_q->symbol_counter;
    if (_q->symbol_counter == synth_crcf_get_length(_q->payload_synth)) {
        _q->symbol_counter = 0;
        ++_q->bit_counter;
        if (_q->bit_counter == _q->payload_mod_len) {
            _q->bit_counter = 0;
            _q->state       = STATE_TAIL;
        }
    }

    return symbol;
}

liquid_float_complex dsssframegen_generate_tail(dsssframegen _q)
{
    ++_q->symbol_counter;

    if (_q->symbol_counter == 2 * _q->m) {
        _q->symbol_counter  = 0;
        _q->frame_complete  = 1;
        _q->frame_assembled = 0;
    }
    return 0.f;
}
