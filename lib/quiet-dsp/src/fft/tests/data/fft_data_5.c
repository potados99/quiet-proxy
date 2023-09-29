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
// autotest fft data for 5-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x5[] = {
    1.043452789296f +  -0.216675780077f*_Complex_I,
   -0.039259154719f +  -0.756503590362f*_Complex_I,
   -1.378329383804f +  -1.629692578129f*_Complex_I,
    0.695728357044f +  -2.639675956000f*_Complex_I,
   -0.019932891052f +   0.123958045411f*_Complex_I};

liquid_float_complex fft_test_y5[] = {
    0.301659716765f +  -5.118589859158f*_Complex_I,
    1.333681830770f +   4.279329517647f*_Complex_I,
   -0.597668794979f +  -2.985429553632f*_Complex_I,
    2.358478480201f +   0.936943320049f*_Complex_I,
    1.821112713724f +   1.804367674708f*_Complex_I};

