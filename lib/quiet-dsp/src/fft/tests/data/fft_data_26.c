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
// autotest fft data for 26-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x26[] = {
   -1.513790990128f +   0.450104660529f*_Complex_I,
   -0.609587704775f +   0.200963343771f*_Complex_I,
    1.150854971928f +  -0.979670346844f*_Complex_I,
    0.676761753784f +  -0.390760850862f*_Complex_I,
    0.025326431025f +   0.226613394038f*_Complex_I,
   -0.877894422758f +   0.377687762743f*_Complex_I,
    0.016945667503f +  -0.414424826825f*_Complex_I,
    0.671396901344f +   1.014597796222f*_Complex_I,
    1.620562100771f +  -0.445584464270f*_Complex_I,
   -0.621912682345f +   0.523347355420f*_Complex_I,
   -1.722706628967f +  -1.473722873869f*_Complex_I,
    1.604125850850f +  -0.595523792175f*_Complex_I,
    2.695969244871f +  -0.740444785313f*_Complex_I,
   -1.837539349404f +  -0.402987576873f*_Complex_I,
    0.643703593669f +  -0.530984627964f*_Complex_I,
    0.745985203740f +  -1.158124796569f*_Complex_I,
    0.492860315079f +   0.183477887101f*_Complex_I,
   -0.715219690752f +  -0.979086251385f*_Complex_I,
    0.179883358483f +   0.236135674483f*_Complex_I,
    0.196402574786f +  -1.059380996958f*_Complex_I,
    0.069933652344f +   0.829344522775f*_Complex_I,
    0.325146685501f +  -1.266467132602f*_Complex_I,
   -1.839777223485f +  -0.327473446299f*_Complex_I,
    1.778506841624f +  -1.571433253340f*_Complex_I,
    1.002599293378f +   0.297630901673f*_Complex_I,
   -1.821267785996f +   1.027493831629f*_Complex_I};

liquid_float_complex fft_test_y26[] = {
    2.337267962069f +  -6.968672891765f*_Complex_I,
   -1.374144569280f +   2.440460452235f*_Complex_I,
    0.293963382503f +  -1.014603415840f*_Complex_I,
   -5.808647515741f +   2.932080281412f*_Complex_I,
   -3.954391977726f +   4.050421232706f*_Complex_I,
  -10.434029005073f +  -2.430379478773f*_Complex_I,
  -14.396971442054f +   7.561455425624f*_Complex_I,
    4.801073402095f +  -7.297832464880f*_Complex_I,
   -6.451827528493f +  -1.778154888801f*_Complex_I,
    7.694740702469f +  -3.586296872724f*_Complex_I,
    0.830361317715f +  -4.000025563805f*_Complex_I,
    2.193823341792f +   2.627715132519f*_Complex_I,
    5.557050661872f +   3.023112572307f*_Complex_I,
    3.307459610871f +   1.590676230192f*_Complex_I,
  -12.118932653799f +  -2.054113664628f*_Complex_I,
    5.893155083845f +  -6.130479717222f*_Complex_I,
    1.236890091413f +  -1.250300895885f*_Complex_I,
    6.703265906214f +   0.834044438577f*_Complex_I,
   -7.565202099594f +   2.208332250508f*_Complex_I,
    3.230245599909f +   6.555949348851f*_Complex_I,
   -7.293883944894f +  -3.228615872305f*_Complex_I,
   -4.814526866453f +   4.783901741180f*_Complex_I,
   -0.579907911716f +   5.262229129419f*_Complex_I,
   -0.768605942699f +   3.726121287503f*_Complex_I,
   -1.461710271209f +  -1.198541330006f*_Complex_I,
   -6.415081077369f +   5.044238707360f*_Complex_I};

