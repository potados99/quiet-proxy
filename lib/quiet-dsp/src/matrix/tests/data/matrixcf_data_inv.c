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
// data for testing matrix inversion
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_inv_x [size: 5 x 5]
liquid_float_complex matrixcf_data_inv_x[] = {
   -0.911099433899f +  -0.436777323484f*_Complex_I /* ( 0, 0) */,
    0.598295390606f +  -0.283340752125f*_Complex_I /* ( 0, 1) */,
   -0.264758616686f +  -0.421906232834f*_Complex_I /* ( 0, 2) */,
   -0.066837862134f +  -0.934806823730f*_Complex_I /* ( 0, 3) */,
    0.393610686064f +  -1.011345505714f*_Complex_I /* ( 0, 4) */,
   -0.543692529202f +  -1.426580429077f*_Complex_I /* ( 1, 0) */,
   -1.006833553314f +   0.448534607887f*_Complex_I /* ( 1, 1) */,
    0.048818156123f +  -0.540948212147f*_Complex_I /* ( 1, 2) */,
    0.180871278048f +   0.331172674894f*_Complex_I /* ( 1, 3) */,
   -1.100448012352f +   1.841731786728f*_Complex_I /* ( 1, 4) */,
    2.341797351837f +  -1.200128436089f*_Complex_I /* ( 2, 0) */,
    0.239693909883f +   0.206349417567f*_Complex_I /* ( 2, 1) */,
   -0.815828502178f +  -0.349400132895f*_Complex_I /* ( 2, 2) */,
    1.213637232780f +   0.298941820860f*_Complex_I /* ( 2, 3) */,
   -1.522765398026f +   1.651986479759f*_Complex_I /* ( 2, 4) */,
    1.481738448143f +   0.055169839412f*_Complex_I /* ( 3, 0) */,
   -1.241538286209f +  -0.077680915594f*_Complex_I /* ( 3, 1) */,
    1.046607017517f +  -0.843883395195f*_Complex_I /* ( 3, 2) */,
   -1.564810752869f +   1.346152186394f*_Complex_I /* ( 3, 3) */,
    0.786287426949f +  -1.010108113289f*_Complex_I /* ( 3, 4) */,
    1.234361886978f +  -1.305809140205f*_Complex_I /* ( 4, 0) */,
    0.053748749197f +   0.403882414103f*_Complex_I /* ( 4, 1) */,
   -0.081336200237f +  -0.462558329105f*_Complex_I /* ( 4, 2) */,
   -1.370563983917f +  -0.284755766392f*_Complex_I /* ( 4, 3) */,
    0.200873896480f +  -0.036809749901f*_Complex_I /* ( 4, 4) */};

// matrixcf_data_inv_y [size: 5 x 5]
liquid_float_complex matrixcf_data_inv_y[] = {
   -0.127852678827f +  -0.009178191835f*_Complex_I /* ( 0, 0) */,
   -0.199905444866f +   0.033789259175f*_Complex_I /* ( 0, 1) */,
    0.168465876479f +  -0.059607902071f*_Complex_I /* ( 0, 2) */,
    0.087700609092f +  -0.030597427908f*_Complex_I /* ( 0, 3) */,
    0.084793376582f +   0.131223765916f*_Complex_I /* ( 0, 4) */,
    0.209779356201f +   0.642123753363f*_Complex_I /* ( 1, 0) */,
   -0.045651767577f +  -0.019599459364f*_Complex_I /* ( 1, 1) */,
    0.137284052424f +   0.504637287094f*_Complex_I /* ( 1, 2) */,
   -0.333643348460f +   0.455368743084f*_Complex_I /* ( 1, 3) */,
    0.244939020151f +  -0.609710193351f*_Complex_I /* ( 1, 4) */,
   -0.114524820581f +   0.963012925652f*_Complex_I /* ( 2, 0) */,
    0.303499486096f +   0.348121666797f*_Complex_I /* ( 2, 1) */,
   -0.327372880299f +   0.397314645420f*_Complex_I /* ( 2, 2) */,
   -0.231096370464f +   0.372958732742f*_Complex_I /* ( 2, 3) */,
    0.089363987094f +  -0.240520272187f*_Complex_I /* ( 2, 4) */,
    0.072169240922f +   0.159456098576f*_Complex_I /* ( 3, 0) */,
   -0.064066539188f +   0.069570707500f*_Complex_I /* ( 3, 1) */,
    0.090335627717f +  -0.121329478735f*_Complex_I /* ( 3, 2) */,
    0.053196220990f +  -0.158230982223f*_Complex_I /* ( 3, 3) */,
   -0.413653285108f +   0.167815066469f*_Complex_I /* ( 3, 4) */,
    0.089194647874f +  -0.035492413461f*_Complex_I /* ( 4, 0) */,
   -0.192303472410f +  -0.221655891788f*_Complex_I /* ( 4, 1) */,
    0.111730542618f +  -0.221903756183f*_Complex_I /* ( 4, 2) */,
    0.303835472120f +  -0.022543572811f*_Complex_I /* ( 4, 3) */,
   -0.167008031325f +   0.051911194273f*_Complex_I /* ( 4, 4) */};

