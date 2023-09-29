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
// firfilt_crcf_data_h13x32.c: autotest firfilt data
//



#include "liquid.h"
#include "autotest/autotest.h"

float firfilt_crcf_data_h13x32_h[] = {
    0.005113901796,
    0.005286268339,
   -0.119811540901,
   -0.004501609093,
   -0.065007372397,
    0.048866593324,
    0.013172470077,
   -0.002661385800,
    0.103490232103,
   -0.080549511664,
    0.044381828692,
    0.059428974785,
    0.036011050317};

liquid_float_complex firfilt_crcf_data_h13x32_x[] = {
   -0.150478051517f +   0.011369787230f*_Complex_I,
   -0.011682362019f +  -0.131898855698f*_Complex_I,
    0.002241423344f +   0.056583759593f*_Complex_I,
   -0.059449335305f +   0.187622651747f*_Complex_I,
   -0.180436000741f +   0.005303426369f*_Complex_I,
    0.011260126047f +   0.058406411239f*_Complex_I,
    0.104607282644f +   0.079267822272f*_Complex_I,
    0.085374933204f +   0.051946754389f*_Complex_I,
   -0.022910313299f +   0.030414137098f*_Complex_I,
    0.088237668857f +  -0.149226301695f*_Complex_I,
   -0.077336181799f +   0.011213633150f*_Complex_I,
   -0.041671694767f +  -0.010591371244f*_Complex_I,
   -0.072827057153f +   0.029626684791f*_Complex_I,
   -0.031258311706f +  -0.032641520688f*_Complex_I,
   -0.008154356734f +   0.089595819254f*_Complex_I,
    0.008874945980f +   0.055052307581f*_Complex_I,
    0.021540988384f +   0.002343360972f*_Complex_I,
    0.031406241630f +  -0.041565525378f*_Complex_I,
   -0.186621079183f +  -0.055706611874f*_Complex_I,
   -0.204887932486f +   0.107546397697f*_Complex_I,
   -0.001299342939f +  -0.091725815207f*_Complex_I,
    0.098883395599f +  -0.042781095000f*_Complex_I,
   -0.148848628287f +   0.075959712533f*_Complex_I,
    0.168232372928f +   0.044377154144f*_Complex_I,
    0.162761143249f +  -0.111406681457f*_Complex_I,
   -0.069728838323f +   0.030195226651f*_Complex_I,
   -0.015037533839f +   0.032270195219f*_Complex_I,
    0.047319395233f +  -0.049920188058f*_Complex_I,
   -0.275633692987f +  -0.077201329969f*_Complex_I,
    0.260550021883f +  -0.026872750426f*_Complex_I,
    0.154250187563f +  -0.051859524539f*_Complex_I,
    0.085702710731f +  -0.034956856551f*_Complex_I};

liquid_float_complex firfilt_crcf_data_h13x32_y[] = {
   -0.000769529978f +   0.000058143975f*_Complex_I,
   -0.000855209812f +  -0.000614414049f*_Complex_I,
    0.017978713542f +  -0.001770120683f*_Complex_I,
    0.001784905863f +   0.017010423559f*_Complex_I,
    0.008329226648f +  -0.005905805446f*_Complex_I,
   -0.000377533572f +  -0.013277356194f*_Complex_I,
    0.019781654463f +  -0.010739936790f*_Complex_I,
    0.004673510867f +  -0.017536447645f*_Complex_I,
   -0.018937503016f +   0.001766778181f*_Complex_I,
   -0.009796095237f +  -0.022965903194f*_Complex_I,
   -0.011542534189f +   0.009647205778f*_Complex_I,
   -0.026694559597f +   0.028680204257f*_Complex_I,
   -0.004613286077f +  -0.018608161470f*_Complex_I,
    0.011559988327f +   0.025425767569f*_Complex_I,
    0.015974924004f +   0.005946996608f*_Complex_I,
   -0.007726490650f +   0.012377335870f*_Complex_I,
   -0.007714581040f +  -0.006039979551f*_Complex_I,
    0.018766419009f +  -0.012572800123f*_Complex_I,
   -0.012542031545f +   0.012437887461f*_Complex_I,
    0.000458385988f +   0.000571447349f*_Complex_I,
    0.016943660061f +   0.007409564688f*_Complex_I,
    0.024399758745f +  -0.020976831445f*_Complex_I,
    0.007946403220f +   0.025133322345f*_Complex_I,
   -0.012852674380f +  -0.005689128468f*_Complex_I,
    0.003313037804f +   0.000263249514f*_Complex_I,
   -0.027377402722f +  -0.004127607511f*_Complex_I,
   -0.026320368186f +   0.009134835527f*_Complex_I,
   -0.012297987932f +   0.013200852928f*_Complex_I,
    0.007101262388f +  -0.017149417134f*_Complex_I,
    0.000657385901f +   0.001192381502f*_Complex_I,
   -0.008080139857f +   0.018480645475f*_Complex_I,
   -0.007551765865f +   0.003627711775f*_Complex_I};

