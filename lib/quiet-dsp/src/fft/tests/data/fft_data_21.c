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
// autotest fft data for 21-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x21[] = {
   -0.292459060095f +  -0.918931582987f*_Complex_I,
   -1.517033866291f +  -0.323416256164f*_Complex_I,
   -1.482752904272f +   0.244611310478f*_Complex_I,
    0.319915998225f +  -0.315947516079f*_Complex_I,
   -0.304653265396f +   1.887596128705f*_Complex_I,
    0.411043591735f +  -0.374178478358f*_Complex_I,
    0.462233294747f +   0.181705549666f*_Complex_I,
   -0.053584030277f +  -1.645170622140f*_Complex_I,
   -0.503521485275f +   0.734911625473f*_Complex_I,
   -0.425967471739f +   0.316306288806f*_Complex_I,
    0.824866046500f +  -0.830071277629f*_Complex_I,
    1.806337286696f +  -0.766132673126f*_Complex_I,
    0.620721751355f +   0.965491952308f*_Complex_I,
   -2.440640280723f +  -0.836336433610f*_Complex_I,
   -0.620347474921f +  -1.385103078296f*_Complex_I,
   -0.195316065403f +   0.051333260777f*_Complex_I,
   -0.448853815719f +   1.473820485114f*_Complex_I,
    0.468718174491f +  -0.133593056210f*_Complex_I,
   -0.912579674279f +   0.093239456860f*_Complex_I,
   -0.060107647935f +  -1.182219308121f*_Complex_I,
   -1.630393758159f +  -1.763218511036f*_Complex_I};

liquid_float_complex fft_test_y21[] = {
   -5.974374656733f +  -4.525302735571f*_Complex_I,
   -3.602445825195f +  -3.324518378407f*_Complex_I,
    1.072414517043f +  -2.680697729601f*_Complex_I,
   -2.544321267300f +  -3.718686381182f*_Complex_I,
    7.073007677928f +  -0.865187973747f*_Complex_I,
   -4.293690988707f +   8.225140969655f*_Complex_I,
    6.571053045547f +  -6.857090522238f*_Complex_I,
    4.072721192387f +   4.943421889232f*_Complex_I,
    0.156147391740f +  -4.066681194313f*_Complex_I,
   -0.307481517626f +  -5.479113972476f*_Complex_I,
   -3.514186056563f +   2.187768615743f*_Complex_I,
    6.761786041122f +   2.434424093260f*_Complex_I,
    6.161936098710f +   2.932845658178f*_Complex_I,
   -0.983132976608f +   2.475188613552f*_Complex_I,
    0.631299782782f +   0.701473074392f*_Complex_I,
   -0.667672994573f +  -2.853889888582f*_Complex_I,
   -1.447661658880f +   2.115483689466f*_Complex_I,
    4.415160634353f +   1.955631737971f*_Complex_I,
  -10.003872665072f +  -7.143199142087f*_Complex_I,
   -2.863331203221f +  -6.794540372208f*_Complex_I,
   -6.854994833120f +   1.039966706231f*_Complex_I};

