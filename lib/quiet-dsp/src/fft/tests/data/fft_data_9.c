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
// autotest fft data for 9-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x9[] = {
    0.318149471742f +  -0.872622265472f*_Complex_I,
    0.380460329361f +   0.204662364547f*_Complex_I,
   -0.569767779072f +  -0.271995206036f*_Complex_I,
    1.334787120105f +  -0.238015105170f*_Complex_I,
   -0.644864052383f +   0.948536285238f*_Complex_I,
   -0.489784794370f +   0.158143326416f*_Complex_I,
    1.783096398872f +  -2.166235062454f*_Complex_I,
   -0.138901921376f +  -0.646377338691f*_Complex_I,
   -0.257444231274f +   0.857372365765f*_Complex_I};

liquid_float_complex fft_test_y9[] = {
    1.715730541604f +  -2.026530635857f*_Complex_I,
    1.685963762512f +   0.399226582084f*_Complex_I,
   -4.115380429157f +   1.255898079784f*_Complex_I,
    4.091196716626f +  -4.693323087763f*_Complex_I,
   -1.668677608930f +  -1.439432143007f*_Complex_I,
   -2.523905986916f +  -0.920217192051f*_Complex_I,
    4.501171713926f +  -3.110763575667f*_Complex_I,
    1.269999384456f +   3.193455688437f*_Complex_I,
   -2.092752848444f +  -0.511914105207f*_Complex_I};

