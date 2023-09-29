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

#include "autotest/autotest.h"
#include "liquid.h"

void autotest_fft_shift_4()
{
    liquid_float_complex x[] = {
        0.f + 0.f*_Complex_I,
        1.f + 1.f*_Complex_I,
        2.f + 2.f*_Complex_I,
        3.f + 3.f*_Complex_I
    };

    liquid_float_complex test[] = {
        2.f + 2.f*_Complex_I,
        3.f + 3.f*_Complex_I,
        0.f + 0.f*_Complex_I,
        1.f + 1.f*_Complex_I
    };

    fft_shift(x,4);

    CONTEND_SAME_DATA(x,test,4*sizeof(liquid_float_complex));
}

void autotest_fft_shift_8()
{
    liquid_float_complex x[] = {
        0.f + 0.f*_Complex_I,
        1.f + 1.f*_Complex_I,
        2.f + 2.f*_Complex_I,
        3.f + 3.f*_Complex_I,
        4.f + 4.f*_Complex_I,
        5.f + 5.f*_Complex_I,
        6.f + 6.f*_Complex_I,
        7.f + 7.f*_Complex_I
    };

    liquid_float_complex test[] = {
        4.f + 4.f*_Complex_I,
        5.f + 5.f*_Complex_I,
        6.f + 6.f*_Complex_I,
        7.f + 7.f*_Complex_I,
        0.f + 0.f*_Complex_I,
        1.f + 1.f*_Complex_I,
        2.f + 2.f*_Complex_I,
        3.f + 3.f*_Complex_I
    };

    fft_shift(x,8);

    CONTEND_SAME_DATA(x,test,8*sizeof(liquid_float_complex));
}

