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
// autotest fft data for 35-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x35[] = {
    0.621203985274f +  -1.170486588571f*_Complex_I,
    0.001346936460f +   0.911992162865f*_Complex_I,
    0.852266167932f +  -0.485602417107f*_Complex_I,
   -1.440614617555f +  -0.143907395580f*_Complex_I,
   -0.886824740774f +  -0.735649970983f*_Complex_I,
    0.822316647558f +  -2.190416870881f*_Complex_I,
   -0.848542045588f +   0.265512380995f*_Complex_I,
    0.224076450439f +  -2.302360677412f*_Complex_I,
   -0.510056035858f +  -1.331941821231f*_Complex_I,
    1.682894720322f +   1.515017086970f*_Complex_I,
   -0.293255187957f +   0.559255597549f*_Complex_I,
    1.692889886331f +  -1.640844999342f*_Complex_I,
   -1.032973350809f +   0.405524091118f*_Complex_I,
    0.177413388869f +  -1.166118195604f*_Complex_I,
   -0.077664879368f +  -1.471655833896f*_Complex_I,
   -0.713927870525f +   1.118966977478f*_Complex_I,
    3.112942596938f +   0.183067680138f*_Complex_I,
   -2.132342418783f +   0.888305824658f*_Complex_I,
    0.570015793758f +  -1.075297345387f*_Complex_I,
    0.029232277101f +  -0.052772048068f*_Complex_I,
    0.021810229730f +   1.026136624357f*_Complex_I,
    0.183820954153f +   0.359011138378f*_Complex_I,
   -0.646415125847f +   0.878859460005f*_Complex_I,
    0.379503797426f +   0.690555809274f*_Complex_I,
   -1.205501520591f +  -1.281704908973f*_Complex_I,
   -0.671296057445f +  -1.202380495393f*_Complex_I,
    1.000730854392f +   1.337218974137f*_Complex_I,
   -0.507823699969f +   0.667041823900f*_Complex_I,
    0.786493220706f +   0.711624105805f*_Complex_I,
   -0.147343975279f +  -0.421666316903f*_Complex_I,
    1.000992786069f +   0.072055493934f*_Complex_I,
   -0.638324259500f +   0.503386775311f*_Complex_I,
    1.518863022405f +  -0.447779056699f*_Complex_I,
   -0.690987494413f +   0.744128091375f*_Complex_I,
    0.074647158829f +  -1.048901976585f*_Complex_I};

liquid_float_complex fft_test_y35[] = {
    2.309567594431f +  -5.331826820366f*_Complex_I,
   -7.442846930878f +  -4.725553620071f*_Complex_I,
   -2.183297818919f +   6.404493143269f*_Complex_I,
   -2.751014847029f +   2.658941664250f*_Complex_I,
    8.330534466967f +   0.919074147759f*_Complex_I,
    6.588325473188f +  -2.237962814214f*_Complex_I,
   -7.983324045653f +  -4.751388462518f*_Complex_I,
    9.842334426677f +  -4.886656356639f*_Complex_I,
    2.723677138226f +  -1.864201873505f*_Complex_I,
    3.314550864796f +  -2.486087207928f*_Complex_I,
   -9.968089532702f + -11.225031015883f*_Complex_I,
    3.348282695100f +   3.685146610266f*_Complex_I,
    3.650591794608f +   7.864477419325f*_Complex_I,
   12.324040428213f +  -2.521426915911f*_Complex_I,
   -1.118920460046f +  -5.025187742730f*_Complex_I,
   14.513400880941f +  11.251977643133f*_Complex_I,
   -2.482556277234f +  -3.095357211645f*_Complex_I,
   -7.549326283090f +   3.844289159351f*_Complex_I,
   -6.554611159279f +  -1.426517057076f*_Complex_I,
    6.564157092619f +   4.071022052298f*_Complex_I,
    5.022588868136f + -15.817689097768f*_Complex_I,
   -5.251727726400f +   2.789037545358f*_Complex_I,
   -2.128113345135f + -15.921584799030f*_Complex_I,
   -6.717549051974f +   1.209151038219f*_Complex_I,
    3.222807461576f +   5.205190352829f*_Complex_I,
   -2.420694516532f +  -6.628232249491f*_Complex_I,
   -0.210938110900f +   1.317502940068f*_Complex_I,
   -4.284810675111f +   4.379050426632f*_Complex_I,
   -1.842031171135f +   3.520287066742f*_Complex_I,
    5.259391106033f +  -9.692983760094f*_Complex_I,
   -3.879590649031f +   2.871689364722f*_Complex_I,
   -1.641216184114f +   4.267406466810f*_Complex_I,
    1.294145378923f +  -2.702480168973f*_Complex_I,
    1.886124883788f +  -3.741139781213f*_Complex_I,
    7.958277715545f +  -3.144460685955f*_Complex_I};

