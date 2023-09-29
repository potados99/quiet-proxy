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
// autotest fft data for 7-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x7[] = {
    0.325737557343f +   0.347762560645f*_Complex_I,
   -0.464568614672f +   1.344201995758f*_Complex_I,
   -1.458140194879f +   0.983317270098f*_Complex_I,
    1.679041515327f +   1.025013762005f*_Complex_I,
   -0.178483024495f +  -0.711524629930f*_Complex_I,
    0.986194459374f +  -1.709315563086f*_Complex_I,
    0.387998802736f +  -1.150726066104f*_Complex_I};

liquid_float_complex fft_test_y7[] = {
    1.277780500734f +   0.128729329387f*_Complex_I,
    4.360250363806f +   2.591163135631f*_Complex_I,
    1.609972293897f +   2.377175130550f*_Complex_I,
    0.436888889637f +  -3.701058823864f*_Complex_I,
   -0.903757801309f +   3.003131513942f*_Complex_I,
    1.797162255231f +  -0.068636624441f*_Complex_I,
   -6.298133600593f +  -1.896165736688f*_Complex_I};

