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
// autotest fft data for 8-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x8[] = {
    1.143832659273f +   0.058730029889f*_Complex_I,
   -0.094390429919f +   0.229144161540f*_Complex_I,
   -0.231936945111f +   0.250418514706f*_Complex_I,
    0.180568135767f +  -0.869698396678f*_Complex_I,
   -0.345282052584f +   1.176003338020f*_Complex_I,
    0.544428216952f +  -0.610473584454f*_Complex_I,
    0.928035714223f +   0.647778401795f*_Complex_I,
    0.441211141066f +  -1.176622015089f*_Complex_I};

liquid_float_complex fft_test_y8[] = {
    2.566466439667f +  -0.294719550271f*_Complex_I,
    1.635071437815f +   1.055386414782f*_Complex_I,
    1.767442826430f +   0.508277941207f*_Complex_I,
    2.964612333261f +  -2.017902163711f*_Complex_I,
    0.422832311935f +   4.560580119089f*_Complex_I,
    0.548438211721f +  -0.969987712376f*_Complex_I,
   -1.562539151277f +   0.164794961607f*_Complex_I,
    0.808336864628f +  -2.536589771219f*_Complex_I};

