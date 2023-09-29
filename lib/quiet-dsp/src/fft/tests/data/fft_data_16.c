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
// autotest fft data for 16-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x16[] = {
   -1.772146047027f +   0.295934658602f*_Complex_I,
   -1.433777343858f +  -0.874041962217f*_Complex_I,
   -0.388629405392f +   0.611030474954f*_Complex_I,
   -0.492539890742f +   1.007726724574f*_Complex_I,
    0.494699992643f +  -1.725668238103f*_Complex_I,
    0.572982289851f +   0.061642401846f*_Complex_I,
   -0.574974496567f +   0.909843544187f*_Complex_I,
    0.733687565510f +   0.447433079732f*_Complex_I,
    0.308242485351f +  -1.532252262483f*_Complex_I,
    1.207949830231f +  -0.953543898451f*_Complex_I,
    0.640048909719f +  -1.022371047059f*_Complex_I,
   -0.241879356643f +  -0.462432765300f*_Complex_I,
   -0.435900183311f +   0.856847254979f*_Complex_I,
    0.577243720893f +   0.220786650383f*_Complex_I,
    1.263302572543f +   1.444493924498f*_Complex_I,
    1.911070541506f +  -1.906912076526f*_Complex_I};

liquid_float_complex fft_test_y16[] = {
    2.369381184706f +  -2.621483536381f*_Complex_I,
   -2.618054253504f +   4.676728363894f*_Complex_I,
   -2.946376269367f +   0.522273546089f*_Complex_I,
    2.120729100677f +   4.308004588255f*_Complex_I,
   -2.975823103566f +  -3.062195121072f*_Complex_I,
   -3.932696300262f +   3.143967424649f*_Complex_I,
   -0.247865075327f +   5.467645213372f*_Complex_I,
    3.887448941709f +   5.439788616063f*_Complex_I,
   -3.300093528791f +   2.297200155534f*_Complex_I,
   -4.008939493163f +   4.239020717646f*_Complex_I,
   -5.630386554230f +  -0.383449644305f*_Complex_I,
   -0.707551950987f +   2.197968388714f*_Complex_I,
   -1.713879561730f +  -5.034075846097f*_Complex_I,
   -8.091926054909f +  -8.469369525668f*_Complex_I,
    2.733814414891f +  -7.076455598181f*_Complex_I,
   -3.292118248586f +  -0.910613204873f*_Complex_I};

