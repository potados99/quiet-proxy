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
// autotest fft data for 6-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x6[] = {
   -0.946868805918f +   0.048419613876f*_Complex_I,
   -1.426556442325f +   1.356194807524f*_Complex_I,
    0.262357323076f +   1.594616904796f*_Complex_I,
   -1.032912520662f +   0.046391595464f*_Complex_I,
   -0.271359734201f +  -2.390517158747f*_Complex_I,
   -0.288151144041f +   0.071324517238f*_Complex_I};

liquid_float_complex fft_test_y6[] = {
   -3.703491324072f +   0.726430280150f*_Complex_I,
    3.797148775593f +   1.637413185851f*_Complex_I,
   -3.456423352393f +   1.227102112087f*_Complex_I,
    1.791748889984f +  -2.221391560299f*_Complex_I,
    1.220570696725f +  -1.669098764217f*_Complex_I,
   -5.330766521347f +   0.590062429687f*_Complex_I};

