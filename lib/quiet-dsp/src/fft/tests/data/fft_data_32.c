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
// autotest fft data for 32-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x32[] = {
    0.010014623512f +   0.557635892111f*_Complex_I,
   -0.206536736342f +  -0.166543150147f*_Complex_I,
    0.538145349965f +  -1.725439447290f*_Complex_I,
    0.302742823470f +  -1.371600938217f*_Complex_I,
    1.002711341702f +   0.326114543577f*_Complex_I,
    0.141075699526f +   0.155158151624f*_Complex_I,
   -0.607068327122f +   1.319516119806f*_Complex_I,
    0.368752062157f +  -0.923715410356f*_Complex_I,
    2.103742061281f +  -0.015112313666f*_Complex_I,
    0.161141569742f +   0.602136525051f*_Complex_I,
   -0.450622712484f +   1.781653187693f*_Complex_I,
   -0.135385448029f +   0.118136375039f*_Complex_I,
   -0.881476360789f +   0.743248990846f*_Complex_I,
   -0.470865375669f +   0.297577338949f*_Complex_I,
    1.578293870903f +   0.150586285410f*_Complex_I,
   -0.582548890310f +  -0.090131349592f*_Complex_I,
   -0.728216825909f +  -0.280660553441f*_Complex_I,
   -0.405960077281f +  -0.823236356122f*_Complex_I,
   -0.689782453002f +  -0.111721138015f*_Complex_I,
   -0.483036608523f +  -2.255409787531f*_Complex_I,
   -1.773638052539f +   0.276871847058f*_Complex_I,
    1.768143481866f +   0.929411559777f*_Complex_I,
    1.598162436054f +   0.336924712326f*_Complex_I,
    0.025313208364f +   0.101634388542f*_Complex_I,
    1.295932058649f +  -0.792267243573f*_Complex_I,
    0.197302929571f +  -1.198246830820f*_Complex_I,
   -0.674567746661f +   0.782836390216f*_Complex_I,
   -1.155843266715f +  -2.060346979162f*_Complex_I,
   -1.174296668808f +  -1.018450093532f*_Complex_I,
   -2.374237969002f +   0.374087797223f*_Complex_I,
    0.773269391236f +  -0.854101525457f*_Complex_I,
   -0.320046719055f +  -0.112754382318f*_Complex_I};

liquid_float_complex fft_test_y32[] = {
   -1.249387330241f +  -4.946207393990f*_Complex_I,
    6.246388763884f +  -6.773507691880f*_Complex_I,
   -8.084921469264f + -10.845914953315f*_Complex_I,
    4.357263742580f +  -0.359518611967f*_Complex_I,
    0.869129033150f +   4.810140005791f*_Complex_I,
   -4.320755060606f +  -2.990777115902f*_Complex_I,
   -6.040916675986f +  11.391912365593f*_Complex_I,
    1.334419178501f +   8.684519829396f*_Complex_I,
    4.553475487339f +  -2.672989876360f*_Complex_I,
    5.980003650433f +   0.810448601904f*_Complex_I,
   -6.393705093395f +   4.226375095002f*_Complex_I,
   -2.975901497257f +   6.587514214591f*_Complex_I,
   -1.005810190439f +  -6.128898292417f*_Complex_I,
    0.016624592858f +  -1.973370861210f*_Complex_I,
    0.024605667140f +  -7.634608092684f*_Complex_I,
    2.682037461215f +  -1.379684965569f*_Complex_I,
    5.090591302217f +   7.901478702130f*_Complex_I,
    4.974928932755f +  -2.673377557945f*_Complex_I,
    2.018958625049f +   1.429758433848f*_Complex_I,
   -3.215930811783f +  -5.513827987988f*_Complex_I,
    9.696021083826f +   2.712450847683f*_Complex_I,
   -6.175824724853f +   6.515234684364f*_Complex_I,
  -10.139408716624f +   3.456026873018f*_Complex_I,
    3.811736373367f +   3.481961808174f*_Complex_I,
   -8.975590750922f +  -1.092757154258f*_Complex_I,
    1.006822057237f +  -4.766098514087f*_Complex_I,
   -0.499087378413f +   4.387815733060f*_Complex_I,
   -0.223489533627f +   2.032893439147f*_Complex_I,
   12.473346705334f +  -4.826450587127f*_Complex_I,
    4.394902822920f +  12.095339998118f*_Complex_I,
   -3.828535537115f +   2.263473712749f*_Complex_I,
   -6.081522756885f +  -0.365006140312f*_Complex_I};

