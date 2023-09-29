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
// qdetector_cccf.c
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "liquid.internal.h"

#define DEBUG_QDETECTOR              0
#define DEBUG_QDETECTOR_PRINT        0
#define DEBUG_QDETECTOR_FILENAME     "qdetector_cccf_debug.m"

// seek signal (initial detection)
void qdetector_cccf_execute_seek(qdetector_cccf _q,
                                 liquid_float_complex  _x);

// align signal in time, compute offset estimates
void qdetector_cccf_execute_align(qdetector_cccf _q,
                                  liquid_float_complex  _x);

enum state {
    QDETECTOR_STATE_SEEK,       // seek sequence
    QDETECTOR_STATE_ALIGN,      // align sequence
};

// main object definition
struct qdetector_cccf_s {
    unsigned int    s_len;          // template (time) length: k * (sequence_len + 2*m)
    liquid_float_complex * s;              // template (time), [size: s_len x 1]
    liquid_float_complex * S;              // template (freq), [size: nfft x 1]
    float           s2_sum;         // sum{ s^2 }

    liquid_float_complex * buf_time_0;     // time-domain buffer (FFT)
    liquid_float_complex * buf_freq_0;     // frequence-domain buffer (FFT)
    liquid_float_complex * buf_freq_1;     // frequence-domain buffer (IFFT)
    liquid_float_complex * buf_time_1;     // time-domain buffer (IFFT)
    unsigned int    nfft;           // fft size
    fftplan         fft;            // FFT object:  buf_time_0 > buf_freq_0
    fftplan         ifft;           // IFFT object: buf_freq_1 > buf_freq_1

    unsigned int    counter;        // sample counter for determining when to compute FFTs
    float           threshold;      // detection threshold
    int             range;          // carrier offset search range (subcarriers)
    unsigned int    num_transforms; // number of transforms taken (debugging)

    float           x2_sum_0;       // sum{ |x|^2 } of first half of buffer
    float           x2_sum_1;       // sum{ |x|^2 } of second half of buffer

    float           rxy;            // peak correlation output
    int             offset;         // FFT offset index for peak correlation (coarse carrier estimate)
    float           tau_hat;        // timing offset estimate
    float           gamma_hat;      // signal level estimate (channel gain)
    float           dphi_hat;       // carrier frequency offset estimate
    float           phi_hat;        // carrier phase offset estimate

    enum state      state;          // execution state
    int             frame_detected; // frame detected?
};

// create detector with generic sequence
//  _s      :   sample sequence
//  _s_len  :   length of sample sequence
qdetector_cccf qdetector_cccf_create(liquid_float_complex * _s,
                                     unsigned int    _s_len)
{
    // validate input
    if (_s_len == 0) {
        fprintf(stderr,"error: qdetector_cccf_create(), sequence length cannot be zero\n");
        exit(1);
    }
    
    // allocate memory for main object and set internal properties
    qdetector_cccf q = (qdetector_cccf) malloc(sizeof(struct qdetector_cccf_s));
    q->s_len = _s_len;

    // allocate memory and copy sequence
    q->s = (liquid_float_complex*) malloc(q->s_len * sizeof(liquid_float_complex));
    memmove(q->s, _s, q->s_len*sizeof(liquid_float_complex));
    q->s2_sum = liquid_sumsqcf(q->s, q->s_len); // compute sum{ s^2 }

    // prepare transforms
    q->nfft       = 1 << liquid_nextpow2( (unsigned int)( 2 * q->s_len ) ); // NOTE: must be even
    // printf("nfft: %d s_len: %d\n", q->nfft, q->s_len);
    q->buf_time_0 = (liquid_float_complex*) malloc(q->nfft * sizeof(liquid_float_complex));
    q->buf_freq_0 = (liquid_float_complex*) malloc(q->nfft * sizeof(liquid_float_complex));
    q->buf_freq_1 = (liquid_float_complex*) malloc(q->nfft * sizeof(liquid_float_complex));
    q->buf_time_1 = (liquid_float_complex*) malloc(q->nfft * sizeof(liquid_float_complex));

    q->fft  = fft_create_plan(q->nfft, q->buf_time_0, q->buf_freq_0, LIQUID_FFT_FORWARD,  0);
    q->ifft = fft_create_plan(q->nfft, q->buf_freq_1, q->buf_time_1, LIQUID_FFT_BACKWARD, 0);

    // create frequency-domain template by taking nfft-point transform on 's', storing in 'S'
    q->S = (liquid_float_complex*) malloc(q->nfft * sizeof(liquid_float_complex));
    memset(q->buf_time_0, 0x00, q->nfft*sizeof(liquid_float_complex));
    memmove(q->buf_time_0, q->s, q->s_len*sizeof(liquid_float_complex));
    fft_execute(q->fft);
    memmove(q->S, q->buf_freq_0, q->nfft*sizeof(liquid_float_complex));

    // reset state variables
    q->counter        = q->nfft/2;
    q->num_transforms = 0;
    q->x2_sum_0       = 0.0f;
    q->x2_sum_1       = 0.0f;
    q->state          = QDETECTOR_STATE_SEEK;
    q->frame_detected = 0;
    memset(q->buf_time_0, 0x00, q->nfft*sizeof(liquid_float_complex));
    
    // reset estimates
    q->rxy       = 0.0f;
    q->tau_hat   = 0.0f;
    q->gamma_hat = 0.0f;
    q->dphi_hat  = 0.0f;
    q->phi_hat   = 0.0f;

    qdetector_cccf_set_threshold(q,0.5f);
    qdetector_cccf_set_range    (q,0.3f); // set initial range for higher detection

    // return object
    return q;
}


// create detector from sequence of symbols using internal linear interpolator
//  _sequence       :   symbol sequence
//  _sequence_len   :   length of symbol sequence
//  _ftype          :   filter prototype (e.g. LIQUID_FIRFILT_RRC)
//  _k              :   samples/symbol
//  _m              :   filter delay
//  _beta           :   excess bandwidth factor
qdetector_cccf qdetector_cccf_create_linear(liquid_float_complex * _sequence,
                                            unsigned int    _sequence_len,
                                            int             _ftype,
                                            unsigned int    _k,
                                            unsigned int    _m,
                                            float           _beta)
{
    // validate input
    if (_sequence_len == 0) {
        fprintf(stderr,"error: qdetector_cccf_create_linear(), sequence length cannot be zero\n");
        exit(1);
    } else if (_k < 2 || _k > 80) {
        fprintf(stderr,"error: qdetector_cccf_create_linear(), samples per symbol must be in [2,80]\n");
        exit(1);
    } else if (_m < 1 || _m > 100) {
        fprintf(stderr,"error: qdetector_cccf_create_linear(), filter delay must be in [1,100]\n");
        exit(1);
    } else if (_beta < 0.0f || _beta > 1.0f) {
        fprintf(stderr,"error: qdetector_cccf_create_linear(), excess bandwidth factor must be in [0,1]\n");
        exit(1);
    }
    
    // create time-domain template
    unsigned int    s_len = _k * (_sequence_len + 2*_m);
    liquid_float_complex * s     = (liquid_float_complex*) malloc(s_len * sizeof(liquid_float_complex));
    firinterp_crcf interp = firinterp_crcf_create_prototype(_ftype, _k, _m, _beta, 0);
    unsigned int i;
    for (i=0; i<_sequence_len + 2*_m; i++)
        firinterp_crcf_execute(interp, i < _sequence_len ? _sequence[i] : 0, &s[_k*i]);
    firinterp_crcf_destroy(interp);

    for (i = 0; i < _sequence_len; i++) {
        // printf("% .2f, % .2fi\n", crealf(_sequence[i]), cimagf(_sequence[i]));
    }

    // create main object
    qdetector_cccf q = qdetector_cccf_create(s, s_len);

    // free allocated temporary array
    free(s);

    // return object
    return q;
}

// create detector from sequence of symbols using internal linear interpolator
//  _sequence       :   bit sequence
//  _sequence_len   :   length of bit sequence
//  _k              :   samples/symbol
//  _m              :   filter delay
//  _beta           :   excess bandwidth factor
qdetector_cccf qdetector_cccf_create_gmsk(unsigned char * _sequence,
                                          unsigned int    _sequence_len,
                                          unsigned int    _k,
                                          unsigned int    _m,
                                          float           _beta)
{
    // validate input
    if (_sequence_len == 0) {
        fprintf(stderr,"error: qdetector_cccf_create_gmsk(), sequence length cannot be zero\n");
        exit(1);
    } else if (_k < 2 || _k > 80) {
        fprintf(stderr,"error: qdetector_cccf_create_gmsk(), samples per symbol must be in [2,80]\n");
        exit(1);
    } else if (_m < 1 || _m > 100) {
        fprintf(stderr,"error: qdetector_cccf_create_gmsk(), filter delay must be in [1,100]\n");
        exit(1);
    } else if (_beta < 0.0f || _beta > 1.0f) {
        fprintf(stderr,"error: qdetector_cccf_create_gmsk(), excess bandwidth factor must be in [0,1]\n");
        exit(1);
    }
    
    // create time-domain template using GMSK modem
    unsigned int    s_len = _k * (_sequence_len + 2*_m);
    liquid_float_complex * s     = (liquid_float_complex*) malloc(s_len * sizeof(liquid_float_complex));
    gmskmod mod = gmskmod_create(_k, _m, _beta);
    unsigned int i;
    for (i=0; i<_sequence_len + 2*_m; i++)
        gmskmod_modulate(mod, i < _sequence_len ? _sequence[i] : 0, &s[_k*i]);
    gmskmod_destroy(mod);

    // create main object
    qdetector_cccf q = qdetector_cccf_create(s, s_len);

    // free allocated temporary array
    free(s);

    // return object
    return q;
}

void qdetector_cccf_destroy(qdetector_cccf _q)
{
    if (!_q) {
        return;
    }

    // free allocated arrays
    free(_q->s         );
    free(_q->S         );
    free(_q->buf_time_0);
    free(_q->buf_freq_0);
    free(_q->buf_freq_1);
    free(_q->buf_time_1);

    // destroy objects
    fft_destroy_plan(_q->fft);
    fft_destroy_plan(_q->ifft);

    // free main object memory
    free(_q);
}

void qdetector_cccf_print(qdetector_cccf _q)
{
    printf("qdetector_cccf:\n");
    printf("  template length (time):   %-u\n",   _q->s_len);
    printf("  FFT size              :   %-u\n",   _q->nfft);
    printf("  search range (bins)   :   %-d\n",   _q->range);
    printf("  detection threshold   :   %6.4f\n", _q->threshold);
    printf("  sum{ s^2 }            :   %.2f\n",  _q->s2_sum);
}

void qdetector_cccf_reset(qdetector_cccf _q)
{
    printf("qdetector reset\n");
    _q->counter        = _q->nfft / 2;
    _q->x2_sum_0       = 0.0f;
    _q->x2_sum_1       = 0.0f;
    _q->state          = QDETECTOR_STATE_SEEK;
    _q->frame_detected = 0;
    memset(_q->buf_time_0, 0x00, _q->nfft * sizeof(liquid_float_complex));
    memset(_q->buf_time_1, 0x00, _q->nfft * sizeof(liquid_float_complex));
}

void * qdetector_cccf_execute(qdetector_cccf _q,
                              liquid_float_complex  _x)
{
    switch (_q->state) {
    case QDETECTOR_STATE_SEEK:
        // seek signal
        qdetector_cccf_execute_seek(_q, _x);
        break;

    case QDETECTOR_STATE_ALIGN:
        // align signal
        qdetector_cccf_execute_align(_q, _x);
        break;
    }

    // check if frame was detected
    if (_q->frame_detected) {
        // clear flag
        _q->frame_detected = 0;

        // return pointer to internal buffer of saved samples
        return (void*)(_q->buf_time_1);
    }

    // frame not yet ready
    return NULL;
}

// set detection threshold (should be between 0 and 1, good starting point is 0.5)
void qdetector_cccf_set_threshold(qdetector_cccf _q,
                                  float          _threshold)
{
    if (_threshold <= 0.0f || _threshold > 2.0f) {
        fprintf(stderr,"warning: threshold (%12.4e) out of range; ignoring\n", _threshold);
        return;
    }

    // set internal threshold value
    _q->threshold = _threshold;
}

// set carrier offset search range
void qdetector_cccf_set_range(qdetector_cccf _q,
                              float          _dphi_max)
{
    if (_dphi_max < 0.0f || _dphi_max > 0.5f) {
        fprintf(stderr,"warning: carrier offset search range (%12.4e) out of range; ignoring\n", _dphi_max);
        return;
    }

    // set internal search range
    _q->range = (int)(_dphi_max * _q->nfft / (2*M_PI));
    _q->range = _q->range < 0 ? 0 : _q->range;
    //printf("range: %d / %u\n", _q->range, _q->nfft);
}

// get sequence length
unsigned int qdetector_cccf_get_seq_len(qdetector_cccf _q)
{
    return _q->s_len;
}

// pointer to sequence
const void * qdetector_cccf_get_sequence(qdetector_cccf _q)
{
    return (const void*) _q->s;
}

// buffer length
unsigned int qdetector_cccf_get_buf_len(qdetector_cccf _q)
{
    return _q->nfft;
}

// correlator output
float qdetector_cccf_get_rxy(qdetector_cccf _q)
{
    return _q->rxy;
}

// fractional timing offset estimate
float qdetector_cccf_get_tau(qdetector_cccf _q)
{
    return _q->tau_hat;
}

// channel gain
float qdetector_cccf_get_gamma(qdetector_cccf _q)
{
    return _q->gamma_hat;
}

// carrier frequency offset estimate
float qdetector_cccf_get_dphi(qdetector_cccf _q)
{
    return _q->dphi_hat;
}

// carrier phase offset estimate
float qdetector_cccf_get_phi(qdetector_cccf _q)
{
    return _q->phi_hat;
}


//
// internal methods
//

// seek signal (initial detection)
void qdetector_cccf_execute_seek(qdetector_cccf _q,
                                 liquid_float_complex  _x)
{
    // write sample to buffer and increment counter
    _q->buf_time_0[_q->counter++] = _x;

    // accumulate signal magnitude
    _q->x2_sum_1 += crealf(_x)*crealf(_x) + cimagf(_x)*cimagf(_x);

    if (_q->counter < _q->nfft)
        return;
    

    /*
    printf("qdetector buf 0:");
    for (unsigned int i = 0; i <_q->nfft/2; i++) {
        printf(" %.2f + %.2fi,", crealf(_q->buf_time_0[i + _q->nfft/2]), cimagf(_q->buf_time_0[i + _q->nfft/2]));
    }
    printf("\n");
    */
    // reset counter (last half of time buffer)
    _q->counter = _q->nfft/2;

    // run forward transform
    fft_execute(_q->fft);

    // compute scaling factor (TODO: use median rather than mean signal level)
    float g0;
    if (_q->x2_sum_0 == 0.f) {
        g0 = sqrtf(_q->x2_sum_1) * sqrtf((float)(_q->s_len) / (float)(_q->nfft / 2));
    } else {
        g0 = sqrtf(_q->x2_sum_0 + _q->x2_sum_1) * sqrtf((float)(_q->s_len) / (float)(_q->nfft));
    }
    if (g0 < 1e-10) {
        memmove(_q->buf_time_0,
                _q->buf_time_0 + _q->nfft / 2,
                (_q->nfft / 2) * sizeof(liquid_float_complex));

        // swap accumulated signal levels
        _q->x2_sum_0 = _q->x2_sum_1;
        _q->x2_sum_1 = 0.0f;
        return;
    }
    float g = 1.0f / ((float)(_q->nfft) * g0 * sqrtf(_q->s2_sum));

    // sweep over carrier frequency offset range
    int offset;
    unsigned int i;
    float        rxy_peak   = 0.0f;
    unsigned int rxy_index  = 0;
    int          rxy_offset = 0;
#if DEBUG_QDETECTOR
    // debug output
    char filename[64];
    sprintf(filename,"qdetector_out_%d.txt", _q->num_transforms);
    FILE * fid = fopen(filename, "w");
    fprintf(fid, "#\n#\n");
    fprintf(fid, "# name: nfft\n# type: scalar\n%u\n\n", _q->nfft);
    fprintf(fid, "# name: g\n# type: scalar\n%12.4e\n\n", g);
    fprintf(fid, "# name: pn_len\n# type: scalar\n%u\n\n", _q->s_len);
    fprintf(fid, "# name: g0\n# type: scalar\n%12.4e\n\n", g0);
    fprintf(fid, "# name: pn\n# type: complex matrix\n# rows: 1\n# columns: %u\n", _q->nfft);
    for (i=0; i<_q->s_len; i++)
        fprintf(fid, " (%12.4e,%12.4e)", crealf(_q->s[i]), cimagf(_q->s[i]));
    for (i=_q->s_len; i<_q->nfft; i++)
        fprintf(fid, " (0,0)");
    fprintf(fid, "\n\n");
    fprintf(fid, "# name: x\n# type: complex matrix\n# rows: 1\n# columns: %u\n", _q->nfft);
    for (i=0; i<_q->nfft; i++)
        fprintf(fid," (%12.4e,%12.4e)", crealf(_q->buf_time_0[i]), cimagf(_q->buf_time_0[i]));
    fprintf(fid, "\n\n");
    fprintf(fid, "# name: rxy\n# type: complex matrix\n# rows: %u\n# columns: %u\n", 2 * _q->range + 1, _q->nfft);
#endif

    // NOTE: this offset may be coarse as a fine carrier estimate is computed later
    for (offset=-_q->range; offset<=_q->range; offset++) {

        // cross-multiply, aligning appropriately
        for (i=0; i<_q->nfft; i++) {
            // shifted index
            unsigned int j = (i + _q->nfft - offset) % _q->nfft;

            _q->buf_freq_1[i] = _q->buf_freq_0[i] * conjf(_q->S[j]);
        }

        // run inverse transform
        fft_execute(_q->ifft);
        
        // scale output appropriately
        liquid_vectorcf_mulscalar(_q->buf_time_1, _q->nfft, g, _q->buf_time_1);

#if DEBUG_QDETECTOR
        // debug output
        for (i=0; i<_q->nfft; i++)
            fprintf(fid," (%12.4e, %12.4e)", crealf(_q->buf_time_1[i]), cimagf(_q->buf_time_1[i]));
        fprintf(fid, "\n");
#endif
        // search for peak
        // TODO: only search over range [-nfft/2, nfft/2)
        for (i=0; i<_q->nfft; i++) {
            float rxy_abs = cabsf(_q->buf_time_1[i]);
            if (rxy_abs > rxy_peak) {
                rxy_peak   = rxy_abs;
                rxy_index  = i;
                rxy_offset = offset;
            }
        }

        if (rxy_peak > _q->threshold && rxy_offset == offset) {
            i = rxy_index;
            unsigned int n = _q->nfft;
            printf("qdetector %.3f %.3f %.3f %.3f %.3f [%.3f] %.3f %.3f\n", cabsf(_q->buf_time_1[(i + n - 5) % n]), cabsf(_q->buf_time_1[(i + n - 4) % n]), cabsf(_q->buf_time_1[(i + n - 3) %n]), cabsf(_q->buf_time_1[(i + n - 2) % n]), cabsf(_q->buf_time_1[(i + n - 1) % n]), cabsf(_q->buf_time_1[i]), cabsf(_q->buf_time_1[(i + 1) % n]), cabsf(_q->buf_time_1[(i + 2) % n]));
        }
    }

#if DEBUG_QDETECTOR
    fprintf(fid, "\n");
    fprintf(fid, "# name: peak\n# type: scalar\n%12.4e\n\n", rxy_peak);
    fprintf(fid, "# name: peak_offset\n# type: scalar\n%u\n\n", rxy_offset + _q->range + 1);
    fclose(fid);
#endif

    // increment number of transforms (debugging)
    _q->num_transforms++;

    if (rxy_peak > _q->threshold && rxy_index < _q->nfft - _q->s_len) {
#if DEBUG_QDETECTOR_PRINT
        printf("*** frame detected! rxy = %12.8f, time index=%u, freq. offset=%d\n", rxy_peak, rxy_index, rxy_offset);
#endif
        // update state, reset counter, copy buffer appropriately
        _q->state = QDETECTOR_STATE_ALIGN;
        _q->offset = rxy_offset;
        _q->rxy    = rxy_peak; // note that this is a coarse estimate
        // TODO: check for edge case where rxy_index is zero (signal already aligned)

        // copy last part of fft input buffer to front
        memmove(_q->buf_time_0, _q->buf_time_0 + rxy_index, (_q->nfft - rxy_index)*sizeof(liquid_float_complex));
        _q->counter = _q->nfft - rxy_index - 1;

        return;
    }
#if DEBUG_QDETECTOR_PRINT
    printf(" no detect, rxy = %12.8f, time index=%u, freq. offset=%d\n", rxy_peak, rxy_index, rxy_offset);
#endif
    
    // copy last half of fft input buffer to front
    memmove(_q->buf_time_0, _q->buf_time_0 + _q->nfft/2, (_q->nfft/2)*sizeof(liquid_float_complex));

    // swap accumulated signal levels
    _q->x2_sum_0 = _q->x2_sum_1;
    _q->x2_sum_1 = 0.0f;
}

// align signal in time, compute offset estimates
void qdetector_cccf_execute_align(qdetector_cccf _q,
                                  liquid_float_complex  _x)
{
    // write sample to buffer and increment counter
    _q->buf_time_0[_q->counter++] = _x;

    if (_q->counter < _q->nfft)
        return;

    //printf("signal is aligned!\n");

    // estimate timing offset
    fft_execute(_q->fft);
    // cross-multiply frequency-domain components, aligning appropriately with
    // estimated FFT offset index due to carrier frequency offset in received signal
    unsigned int i;
    for (i=0; i<_q->nfft; i++) {
        // shifted index
        unsigned int j = (i + _q->nfft - _q->offset) % _q->nfft;
        _q->buf_freq_1[i] = _q->buf_freq_0[i] * conjf(_q->S[j]);
    }
    fft_execute(_q->ifft);
    // time aligned to index 0
    // NOTE: taking the sqrt removes bias in the timing estimate, but messes up gamma estimate
    float yneg = cabsf(_q->buf_time_1[_q->nfft - 1]);
    yneg       = sqrtf(yneg);
    float y0   = cabsf(_q->buf_time_1[0]);
    y0         = sqrtf(y0);
    float ypos = cabsf(_q->buf_time_1[1]);
    ypos       = sqrtf(ypos);
    // compute timing offset estimate from quadratic polynomial fit
    //  y = a x^2 + b x + c, [xneg = -1, x0 = 0, xpos = +1]
    float a     =  0.5f*(ypos + yneg) - y0;
    float b     =  0.5f*(ypos - yneg);
    float c     =  y0;
    _q->tau_hat = -b / (2.0f*a); //-0.5f*(ypos - yneg) / (ypos + yneg - 2*y0);
    float g_hat   = (a*_q->tau_hat*_q->tau_hat + b*_q->tau_hat + c);
    _q->gamma_hat = g_hat * g_hat / ((float)(_q->nfft) * _q->s2_sum); // g_hat^2 because of sqrt for yneg/y0/ypos
    // TODO: revise estimate of rxy here

    // copy buffer to preserve data integrity
    memmove(_q->buf_time_1, _q->buf_time_0, _q->nfft*sizeof(liquid_float_complex));

    // estimate carrier frequency offset
    for (i=0; i<_q->nfft; i++)
        _q->buf_time_0[i] *= i < _q->s_len ? conjf(_q->s[i]) : 0.0f;
    fft_execute(_q->fft);
#if DEBUG_QDETECTOR
    // debug output
    char filename[64];
    sprintf(filename,"qdetector_fft.m");
    FILE * fid = fopen(filename, "w");
    fprintf(fid,"nfft = %u;\n", _q->nfft);
    for (i=0; i<_q->nfft; i++)
        fprintf(fid,"V(%6u) = %12.4e + 1i*%12.4e;\n", i+1, crealf(_q->buf_freq_0[i]), cimagf(_q->buf_freq_0[i]));
    fprintf(fid,"V = fftshift(V) / max(abs(V));\n");
    fprintf(fid,"figure;\n");
    fprintf(fid,"f=[0:(nfft-1)] - nfft/2;\n");
    fprintf(fid,"plot(f,abs(V),'-x');\n");
    fprintf(fid,"grid on;\n");
    fprintf(fid,"axis([-10 10 0 1.2]);\n");
    fclose(fid);
    printf("debug: %s\n", filename);
#endif
    // search for peak (NOTE: should be at: _q->offset)
    // TODO: don't search for peak but just use internal offset
    float        v0 = 0.0f;
    unsigned int i0 = 0;
    for (i=0; i<_q->nfft; i++) {
        float v_abs = cabsf(_q->buf_freq_0[i]);
        if (v_abs > v0) {
            v0 = v_abs;
            i0 = i;
        }
    }
    // interpolate using quadratic polynomial for carrier frequency estimate
    unsigned int ineg = (i0 + _q->nfft - 1)%_q->nfft;
    unsigned int ipos = (i0            + 1)%_q->nfft;
    float        vneg = cabsf(_q->buf_freq_0[ineg]);
    float        vpos = cabsf(_q->buf_freq_0[ipos]);
    a            =  0.5f*(vpos + vneg) - v0;
    b            =  0.5f*(vpos - vneg);
    //c            =  v0;
    float idx    = -b / (2.0f*a); //-0.5f*(vpos - vneg) / (vpos + vneg - 2*v0);
    float index  = (float)i0 + idx;
    _q->dphi_hat = (i0 > _q->nfft/2 ? index-(float)_q->nfft : index) * 2*M_PI / (float)(_q->nfft);

    // estimate carrier phase offset
#if 0
    // METHOD 1: linear interpolation of phase in FFT output buffer
    float p0     = cargf(_q->buf_freq_0[ idx < 0 ? ineg : i0   ]);
    float p1     = cargf(_q->buf_freq_0[ idx < 0 ? i0   : ipos ]);
    float xp     = idx < 0 ? 1+idx : idx;
    _q->phi_hat  = (p1-p0)*xp + p0;
    //printf("v0 = %12.8f, v1 = %12.8f, xp = %12.8f\n", v0, v1, xp);
#else
    // METHOD 2: compute metric by de-rotating signal and measuring resulting phase
    // NOTE: this is possibly more accurate than the above method but might also
    //       be more computationally complex
    liquid_float_complex metric = 0;
    for (i=0; i<_q->s_len; i++)
        metric += _q->buf_time_0[i] * cexpf(-_Complex_I*(float)(_q->dphi_hat*i));
    //printf("metric : %12.8f <%12.8f>\n", cabsf(metric), cargf(metric));
    _q->phi_hat = cargf(metric);
#endif

#if DEBUG_QDETECTOR_PRINT
    printf("  y[    -1] : %12.8f\n", yneg);
    printf("  y[     0] : %12.8f\n", y0  );
    printf("  y[    +1] : %12.8f\n", ypos);
    printf("  tau-hat   : %12.8f\n", _q->tau_hat);
    //printf("  g-hat:    : %12.8f\n", g_hat);
    printf("  gamma-hat : %12.8f\n", _q->gamma_hat);
    printf("  v[%4u-1] : %12.8f\n", i0,vneg);
    printf("  v[%4u+0] : %12.8f\n", i0,v0  );
    printf("  v[%4u+1] : %12.8f\n", i0,vpos);
    printf("  dphi-hat  : %12.8f\n", _q->dphi_hat);
    printf("  phi-hat   : %12.8f\n", _q->phi_hat);
#endif

    // set flag
    _q->frame_detected = 1;

    // reset state
    // copy saved buffer state (last half of buf_time_1 to front half of buf_time_0)
    memmove(_q->buf_time_0, _q->buf_time_1 + _q->nfft/2, (_q->nfft/2)*sizeof(liquid_float_complex));
    _q->state = QDETECTOR_STATE_SEEK;
    _q->x2_sum_0 = liquid_sumsqcf(_q->buf_time_0, _q->nfft/2);
    _q->x2_sum_1 = 0;
    _q->counter = _q->nfft/2;
}

