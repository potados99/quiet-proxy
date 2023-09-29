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
// autotest fft data definitions
//

#ifndef __LIQUID_FFT_DATA_H__
#define __LIQUID_FFT_DATA_H__

// autotest helper function
//  _x      :   fft input array
//  _test   :   expected fft output
//  _n      :   fft size
void fft_test(liquid_float_complex * _x,
              liquid_float_complex * _test,
              unsigned int    _n);

// 
// autotest datasets
//

//
extern liquid_float_complex fft_test_x2[];
extern liquid_float_complex fft_test_y2[];

extern liquid_float_complex fft_test_x3[];
extern liquid_float_complex fft_test_y3[];

extern liquid_float_complex fft_test_x4[];
extern liquid_float_complex fft_test_y4[];

extern liquid_float_complex fft_test_x5[];
extern liquid_float_complex fft_test_y5[];

extern liquid_float_complex fft_test_x6[];
extern liquid_float_complex fft_test_y6[];

extern liquid_float_complex fft_test_x7[];
extern liquid_float_complex fft_test_y7[];

extern liquid_float_complex fft_test_x8[];
extern liquid_float_complex fft_test_y8[];

extern liquid_float_complex fft_test_x9[];
extern liquid_float_complex fft_test_y9[];

//
extern liquid_float_complex fft_test_x10[];
extern liquid_float_complex fft_test_y10[];

extern liquid_float_complex fft_test_x16[];
extern liquid_float_complex fft_test_y16[];

extern liquid_float_complex fft_test_x17[];
extern liquid_float_complex fft_test_y17[];

extern liquid_float_complex fft_test_x20[];
extern liquid_float_complex fft_test_y20[];

extern liquid_float_complex fft_test_x21[];
extern liquid_float_complex fft_test_y21[];

extern liquid_float_complex fft_test_x22[];
extern liquid_float_complex fft_test_y22[];

extern liquid_float_complex fft_test_x24[];
extern liquid_float_complex fft_test_y24[];

extern liquid_float_complex fft_test_x26[];
extern liquid_float_complex fft_test_y26[];

extern liquid_float_complex fft_test_x30[];
extern liquid_float_complex fft_test_y30[];

extern liquid_float_complex fft_test_x32[];
extern liquid_float_complex fft_test_y32[];

extern liquid_float_complex fft_test_x35[];
extern liquid_float_complex fft_test_y35[];

extern liquid_float_complex fft_test_x36[];
extern liquid_float_complex fft_test_y36[];

extern liquid_float_complex fft_test_x43[];
extern liquid_float_complex fft_test_y43[];

extern liquid_float_complex fft_test_x48[];
extern liquid_float_complex fft_test_y48[];

extern liquid_float_complex fft_test_x63[];
extern liquid_float_complex fft_test_y63[];

extern liquid_float_complex fft_test_x64[];
extern liquid_float_complex fft_test_y64[];

extern liquid_float_complex fft_test_x79[];
extern liquid_float_complex fft_test_y79[];

extern liquid_float_complex fft_test_x92[];
extern liquid_float_complex fft_test_y92[];

extern liquid_float_complex fft_test_x96[];
extern liquid_float_complex fft_test_y96[];

//
extern liquid_float_complex fft_test_x120[];
extern liquid_float_complex fft_test_y120[];

extern liquid_float_complex fft_test_x130[];
extern liquid_float_complex fft_test_y130[];

extern liquid_float_complex fft_test_x157[];
extern liquid_float_complex fft_test_y157[];

extern liquid_float_complex fft_test_x192[];
extern liquid_float_complex fft_test_y192[];

extern liquid_float_complex fft_test_x317[];
extern liquid_float_complex fft_test_y317[];

extern liquid_float_complex fft_test_x509[];
extern liquid_float_complex fft_test_y509[];

// 8-point real even/odd dft data
extern float fftdata_r2r_x8[];
extern float fftdata_r2r_REDFT00_y8[];
extern float fftdata_r2r_REDFT10_y8[];
extern float fftdata_r2r_REDFT01_y8[];
extern float fftdata_r2r_REDFT11_y8[];
extern float fftdata_r2r_RODFT00_y8[];
extern float fftdata_r2r_RODFT10_y8[];
extern float fftdata_r2r_RODFT01_y8[];
extern float fftdata_r2r_RODFT11_y8[];

// 27-point real even/odd dft data
extern float fftdata_r2r_x27[];
extern float fftdata_r2r_REDFT00_y27[];
extern float fftdata_r2r_REDFT10_y27[];
extern float fftdata_r2r_REDFT01_y27[];
extern float fftdata_r2r_REDFT11_y27[];
extern float fftdata_r2r_RODFT00_y27[];
extern float fftdata_r2r_RODFT10_y27[];
extern float fftdata_r2r_RODFT01_y27[];
extern float fftdata_r2r_RODFT11_y27[];

// 32-point real even/odd dft data
extern float fftdata_r2r_x32[];
extern float fftdata_r2r_REDFT00_y32[];
extern float fftdata_r2r_REDFT10_y32[];
extern float fftdata_r2r_REDFT01_y32[];
extern float fftdata_r2r_REDFT11_y32[];
extern float fftdata_r2r_RODFT00_y32[];
extern float fftdata_r2r_RODFT10_y32[];
extern float fftdata_r2r_RODFT01_y32[];
extern float fftdata_r2r_RODFT11_y32[];

#endif // __LIQUID_FFT_DATA_H__
