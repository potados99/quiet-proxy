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
// autotest fft data for 10-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x10[] = {
   -0.380648737020f +   1.003981780953f*_Complex_I,
    1.031511152163f +  -2.625896014009f*_Complex_I,
   -1.083239396623f +   1.646877001105f*_Complex_I,
    0.951587457487f +  -0.004983138281f*_Complex_I,
    0.407589360084f +   0.345698641918f*_Complex_I,
    0.549291472049f +   0.542579734652f*_Complex_I,
   -0.911825526748f +   1.282009726257f*_Complex_I,
   -0.617849040964f +   0.696673367751f*_Complex_I,
    1.097501043733f +   1.373947311009f*_Complex_I,
    0.848713422957f +  -0.738252787172f*_Complex_I};

liquid_float_complex fft_test_y10[] = {
    1.892631207117f +   3.522635624182f*_Complex_I,
   -1.167216826866f +  -3.158947047615f*_Complex_I,
   -0.019614668329f +   1.291770408491f*_Complex_I,
   -3.842057814631f +  -1.668342848977f*_Complex_I,
   -2.323082893679f +   1.200058008683f*_Complex_I,
   -3.633877720265f +   7.782393298301f*_Complex_I,
    0.649048218143f +   6.997144832999f*_Complex_I,
    1.025423884758f +   1.907666229150f*_Complex_I,
    0.644231811894f +  -5.278801296330f*_Complex_I,
    2.968027431661f +  -2.555759399357f*_Complex_I};

