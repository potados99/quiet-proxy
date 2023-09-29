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
// firfilt_crcf_data_h4x8.c: autotest firfilt data
//



#include "liquid.h"
#include "autotest/autotest.h"

float firfilt_crcf_data_h4x8_h[] = {
    0.081125556518,
   -0.048097526791,
    0.083945750272,
    0.016820374297};

liquid_float_complex firfilt_crcf_data_h4x8_x[] = {
    0.212556497097f +  -0.062593316778f*_Complex_I,
    0.074632428892f +  -0.155168218555f*_Complex_I,
   -0.139928836211f +  -0.151937330426f*_Complex_I,
    0.057785165005f +   0.027214057011f*_Complex_I,
    0.047104310251f +  -0.016114794312f*_Complex_I,
    0.140236563713f +   0.296500956218f*_Complex_I,
   -0.134588116658f +  -0.011633439603f*_Complex_I,
    0.035369414992f +  -0.047878728319f*_Complex_I};

liquid_float_complex firfilt_crcf_data_h4x8_y[] = {
    0.017243764119f +  -0.005077917658f*_Complex_I,
   -0.004168844485f +  -0.009577524353f*_Complex_I,
    0.002901774665f +  -0.010117235877f*_Complex_I,
    0.021258439696f +  -0.004562990201f*_Complex_I,
   -0.009449045890f +  -0.017980731205f*_Complex_I,
    0.011608332082f +   0.024557748499f*_Complex_I,
   -0.012737392976f +  -0.016099749821f*_Complex_I,
    0.021907294708f +   0.021294289547f*_Complex_I};

