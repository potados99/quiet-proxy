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
#include "liquid.internal.h"

// test data
liquid_float_complex sumsqcf_test_x3[3] = {
  -0.143606511525f +  -0.137405158308f*_Complex_I,
  -0.155077565599f +  -0.128712786230f*_Complex_I,
   0.259257309730f +  -0.354313982924f*_Complex_I};
float sumsqcf_test_y3 = 0.272871791516851;

liquid_float_complex sumsqcf_test_x4[4] = {
  -0.027688113439f +   0.014257850202f*_Complex_I,
   0.135913101830f +  -0.193497844930f*_Complex_I,
  -0.184688262513f +  -0.018367564232f*_Complex_I,
   0.033677897260f +  -0.365996497668f*_Complex_I};
float sumsqcf_test_y4 = 0.226418463954813;

liquid_float_complex sumsqcf_test_x7[7] = {
  -0.052790293375f +   0.173778162166f*_Complex_I,
   0.026113336498f +  -0.228399854303f*_Complex_I,
   0.060259677552f +  -0.064704230326f*_Complex_I,
  -0.085637350173f +  -0.140391580928f*_Complex_I,
   0.137662823620f +  -0.049602389650f*_Complex_I,
   0.081078554377f +   0.103320097893f*_Complex_I,
  -0.140068020211f +  -0.028552894932f*_Complex_I};
float sumsqcf_test_y7 = 0.179790025178960;

liquid_float_complex sumsqcf_test_x8[8] = {
  -0.114842287937f +  -0.044108491804f*_Complex_I,
  -0.027032488500f +  -0.098073597323f*_Complex_I,
  -0.248865158871f +  -0.058431293594f*_Complex_I,
   0.152349654138f +   0.011146740847f*_Complex_I,
   0.100890388238f +   0.037191727983f*_Complex_I,
  -0.173317554621f +  -0.287191794305f*_Complex_I,
   0.159045702603f +  -0.097006888823f*_Complex_I,
  -0.048463564653f +  -0.123659611524f*_Complex_I};
float sumsqcf_test_y8 = 0.290592731534459;

liquid_float_complex sumsqcf_test_x15[15] = {
  -0.233166865552f +  -0.325575589001f*_Complex_I,
  -0.062157314569f +  -0.052675113778f*_Complex_I,
  -0.184924733094f +  -0.037448582846f*_Complex_I,
  -0.019336799407f +  -0.146627815330f*_Complex_I,
   0.014671587594f +  -0.040490423681f*_Complex_I,
  -0.070920638099f +   0.353056761369f*_Complex_I,
   0.342121380549f +   0.016365636789f*_Complex_I,
   0.407809024847f +  -0.067677610212f*_Complex_I,
   0.166345037028f +  -0.070618449000f*_Complex_I,
  -0.151572833379f +  -0.241061531174f*_Complex_I,
  -0.295395183108f +   0.107933512849f*_Complex_I,
   0.214887288420f +   0.158211288996f*_Complex_I,
   0.089528110626f +   0.534731503540f*_Complex_I,
  -0.387245894254f +   0.127860010582f*_Complex_I,
  -0.123711595377f +   0.212526707755f*_Complex_I};
float sumsqcf_test_y15 = 1.44880523546855;

liquid_float_complex sumsqcf_test_x16[16] = {
  -0.065168142317f +   0.069453199546f*_Complex_I,
   0.175268433034f +  -0.227486860237f*_Complex_I,
  -0.190532229460f +   0.079975095234f*_Complex_I,
   0.119309235855f +  -0.238114343006f*_Complex_I,
   0.125737810036f +   0.045214179459f*_Complex_I,
  -0.197170380197f +  -0.159688600627f*_Complex_I,
   0.075166226059f +   0.148949236785f*_Complex_I,
  -0.290229918639f +   0.019293769432f*_Complex_I,
  -0.145299853755f +  -0.083512058709f*_Complex_I,
  -0.256618190275f +  -0.450932031739f*_Complex_I,
  -0.169487127499f +   0.187004249967f*_Complex_I,
   0.203885942759f +   0.121347578873f*_Complex_I,
  -0.176280563451f +  -0.304717971490f*_Complex_I,
   0.240587060249f +  -0.055540407201f*_Complex_I,
   0.022889112723f +   0.027170265053f*_Complex_I,
   0.265769617236f +  -0.023686695049f*_Complex_I};
float sumsqcf_test_y16 = 1.07446555417927;

// helper function
void sumsqcf_runtest(liquid_float_complex * _x,
                     unsigned int    _n,
                     float           _y)
{
    float tol = 1e-6;   // error tolerance

    // run test
    float y = liquid_sumsqcf(_x, _n);

    CONTEND_DELTA( y, _y, tol );
}

// 
// AUTOTESTS : run test with pre-determined data sets
//
void autotest_sumsqcf_3()   {   sumsqcf_runtest( sumsqcf_test_x3,  3,  sumsqcf_test_y3  );  }
void autotest_sumsqcf_4()   {   sumsqcf_runtest( sumsqcf_test_x4,  4,  sumsqcf_test_y4  );  }
void autotest_sumsqcf_7()   {   sumsqcf_runtest( sumsqcf_test_x7,  7,  sumsqcf_test_y7  );  }
void autotest_sumsqcf_8()   {   sumsqcf_runtest( sumsqcf_test_x8,  8,  sumsqcf_test_y8  );  }
void autotest_sumsqcf_15()  {   sumsqcf_runtest( sumsqcf_test_x15, 15, sumsqcf_test_y15 );  }
void autotest_sumsqcf_16()  {   sumsqcf_runtest( sumsqcf_test_x16, 16, sumsqcf_test_y16 );  }
