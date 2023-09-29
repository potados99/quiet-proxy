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
// data for testing multiply/transpose
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_transmul_x [size: 5 x 4]
liquid_float_complex matrixcf_data_transmul_x[] = {
    0.897770464420f +  -1.137341141701f*_Complex_I /* ( 0, 0) */,
    0.816529691219f +  -0.575469911098f*_Complex_I /* ( 0, 1) */,
    2.407611131668f +   0.901603281498f*_Complex_I /* ( 0, 2) */,
   -1.024818181992f +  -1.785745739937f*_Complex_I /* ( 0, 3) */,
    1.494256496429f +  -0.826167643070f*_Complex_I /* ( 1, 0) */,
   -0.908512234688f +   0.119766108692f*_Complex_I /* ( 1, 1) */,
   -0.215938329697f +  -2.537411689758f*_Complex_I /* ( 1, 2) */,
   -1.348789930344f +  -0.935531198978f*_Complex_I /* ( 1, 3) */,
   -0.398543357849f +   0.101190350950f*_Complex_I /* ( 2, 0) */,
   -0.083604514599f +   1.493514776230f*_Complex_I /* ( 2, 1) */,
    0.477280050516f +  -0.074863225222f*_Complex_I /* ( 2, 2) */,
   -0.283995777369f +   0.336168438196f*_Complex_I /* ( 2, 3) */,
   -0.030109925196f +  -1.602186083794f*_Complex_I /* ( 3, 0) */,
    2.220442056656f +  -0.208865001798f*_Complex_I /* ( 3, 1) */,
    1.889614224434f +  -0.896111547947f*_Complex_I /* ( 3, 2) */,
   -0.317830920219f +   0.215485602617f*_Complex_I /* ( 3, 3) */,
   -0.945744097233f +  -0.822628259659f*_Complex_I /* ( 4, 0) */,
   -0.238264903426f +   0.054408840835f*_Complex_I /* ( 4, 1) */,
    0.532425582409f +   0.438958346844f*_Complex_I /* ( 4, 2) */,
    0.089408367872f +  -1.864659070969f*_Complex_I /* ( 4, 3) */};

// matrixcf_data_transmul_xxT [size: 5 x 5]
liquid_float_complex matrixcf_data_transmul_xxT[] = {
   13.946043026996f +   0.000000000000f*_Complex_I /* ( 0, 0) */,
    1.715635857916f +   6.831514803023f*_Complex_I /* ( 0, 1) */,
   -0.628286275869f +   0.653261344190f*_Complex_I /* ( 0, 2) */,
    7.410888277177f +   5.014956782605f*_Complex_I /* ( 0, 3) */,
    4.776506544166f +  -0.740548606324f*_Complex_I /* ( 0, 4) */,
    1.715635857916f +  -6.831514803023f*_Complex_I /* ( 1, 0) */,
   12.934634198959f +   0.000000000000f*_Complex_I /* ( 1, 1) */,
   -0.268847669275f +   1.016808442009f*_Complex_I /* ( 1, 2) */,
    1.329226044140f +  -1.905118394989f*_Complex_I /* ( 1, 3) */,
   -0.115507997317f +  -1.823416830395f*_Complex_I /* ( 1, 4) */,
   -0.628286275869f +  -0.653261344190f*_Complex_I /* ( 2, 0) */,
   -0.268847669275f +  -1.016808442009f*_Complex_I /* ( 2, 1) */,
    2.833715966403f +   0.000000000000f*_Complex_I /* ( 2, 2) */,
    0.483955462699f +   2.897799335427f*_Complex_I /* ( 2, 3) */,
   -0.036118440085f +  -1.523720724413f*_Complex_I /* ( 2, 4) */,
    7.410888277177f +  -5.014956782605f*_Complex_I /* ( 3, 0) */,
    1.329226044140f +   1.905118394989f*_Complex_I /* ( 3, 1) */,
    0.483955462699f +  -2.897799335427f*_Complex_I /* ( 3, 2) */,
   12.063002732969f +   0.000000000000f*_Complex_I /* ( 3, 3) */,
    0.988561701830f +  -0.460512464248f*_Complex_I /* ( 3, 4) */,
    4.776506544166f +   0.740548606324f*_Complex_I /* ( 4, 0) */,
   -0.115507997317f +   1.823416830395f*_Complex_I /* ( 4, 1) */,
   -0.036118440085f +   1.523720724413f*_Complex_I /* ( 4, 2) */,
    0.988561701830f +   0.460512464248f*_Complex_I /* ( 4, 3) */,
    5.591988375464f +   0.000000000000f*_Complex_I /* ( 4, 4) */};

// matrixcf_data_transmul_xxH [size: 5 x 5]
liquid_float_complex matrixcf_data_transmul_xxH[] = {
    2.693069394806f +   5.019630491560f*_Complex_I /* ( 0, 0) */,
    1.208446246635f +  -4.757020341403f*_Complex_I /* ( 0, 1) */,
    2.656451825557f +   2.224444954914f*_Complex_I /* ( 0, 2) */,
    5.911512147844f +  -2.959566260460f*_Complex_I /* ( 0, 3) */,
   -4.483236639053f +   3.806796594938f*_Complex_I /* ( 0, 4) */,
    1.208446246635f +  -4.757020341403f*_Complex_I /* ( 1, 0) */,
   -3.086513006704f +   0.932888319797f*_Complex_I /* ( 1, 1) */,
   -0.210317709361f +  -2.269045302266f*_Complex_I /* ( 1, 2) */,
   -5.412513485879f +  -6.508039464439f*_Complex_I /* ( 1, 3) */,
   -2.749055759920f +   0.459776624619f*_Complex_I /* ( 1, 4) */,
    2.656451825557f +   2.224444954914f*_Complex_I /* ( 2, 0) */,
   -0.210317709361f +  -2.269045302266f*_Complex_I /* ( 2, 1) */,
   -1.885163224141f +  -0.592788922020f*_Complex_I /* ( 2, 2) */,
    1.153042421508f +   3.232018360881f*_Complex_I /* ( 2, 3) */,
    1.287247559495f +   0.601010412549f*_Complex_I /* ( 2, 4) */,
    5.911512147844f +  -2.959566260460f*_Complex_I /* ( 3, 0) */,
   -5.412513485879f +  -6.508039464439f*_Complex_I /* ( 3, 1) */,
    1.153042421508f +   3.232018360881f*_Complex_I /* ( 3, 2) */,
    5.142853158215f +  -4.354648092153f*_Complex_I /* ( 3, 3) */,
   -0.034391537899f +   2.674865932467f*_Complex_I /* ( 3, 4) */,
   -4.483236639053f +   3.806796594938f*_Complex_I /* ( 4, 0) */,
   -2.749055759920f +   0.459776624619f*_Complex_I /* ( 4, 1) */,
    1.287247559495f +   0.601010412549f*_Complex_I /* ( 4, 2) */,
   -0.034391537899f +   2.674865932467f*_Complex_I /* ( 4, 3) */,
   -3.106642538055f +   1.664057265760f*_Complex_I /* ( 4, 4) */};

// matrixcf_data_transmul_xTx [size: 4 x 4]
liquid_float_complex matrixcf_data_transmul_xTx[] = {
    9.323024431917f +   0.000000000000f*_Complex_I /* ( 0, 0) */,
    0.563876592623f +   2.570030362211f*_Complex_I /* ( 0, 1) */,
    3.226123027525f +   2.636644463529f*_Complex_I /* ( 0, 2) */,
    1.129305368076f +  -4.064920271606f*_Complex_I /* ( 0, 3) */,
    0.563876592623f +  -2.570030362211f*_Complex_I /* ( 1, 0) */,
    9.108918860377f +   0.000000000000f*_Complex_I /* ( 1, 1) */,
    5.467585123601f +   2.017612849734f*_Complex_I /* ( 1, 2) */,
    0.956522192172f +   0.211168853425f*_Complex_I /* ( 1, 3) */,
    3.226123027525f +  -2.636644463529f*_Complex_I /* ( 2, 0) */,
    5.467585123601f +  -2.017612849734f*_Complex_I /* ( 2, 1) */,
   18.177787287820f +   0.000000000000f*_Complex_I /* ( 2, 2) */,
   -3.137608134941f +  -7.366300567700f*_Complex_I /* ( 2, 3) */,
    1.129305368076f +   4.064920271606f*_Complex_I /* ( 3, 0) */,
    0.956522192172f +  -0.211168853425f*_Complex_I /* ( 3, 1) */,
   -3.137608134941f +   7.366300567700f*_Complex_I /* ( 3, 2) */,
   10.759653720678f +   0.000000000000f*_Complex_I /* ( 3, 3) */};

// matrixcf_data_transmul_xHx [size: 4 x 4]
liquid_float_complex matrixcf_data_transmul_xHx[] = {
   -1.137085237839f +  -2.939337742229f*_Complex_I /* ( 0, 0) */,
   -1.429264118470f +  -4.526184217761f*_Complex_I /* ( 0, 1) */,
   -1.049795781222f +  -9.317515018345f*_Complex_I /* ( 0, 2) */,
   -6.923890470327f +   1.308742276041f*_Complex_I /* ( 0, 3) */,
   -1.429264118470f +  -4.526184217761f*_Complex_I /* ( 1, 0) */,
    3.863557186128f +  -2.360596346275f*_Complex_I /* ( 1, 1) */,
    6.914587648894f +  -0.110888488534f*_Complex_I /* ( 1, 2) */,
   -1.585896210450f +   0.361787209777f*_Complex_I /* ( 1, 3) */,
   -1.049795781222f +  -9.317515018345f*_Complex_I /* ( 2, 0) */,
    6.914587648894f +  -0.110888488534f*_Complex_I /* ( 2, 1) */,
    1.672484488523f +   2.446622681596f*_Complex_I /* ( 2, 2) */,
   -2.591648390404f +  -1.678750072577f*_Complex_I /* ( 2, 3) */,
   -6.923890470327f +   1.308742276041f*_Complex_I /* ( 3, 0) */,
   -1.585896210450f +   0.361787209777f*_Complex_I /* ( 3, 1) */,
   -2.591648390404f +  -1.678750072577f*_Complex_I /* ( 3, 2) */,
   -4.641352652692f +   5.522450469852f*_Complex_I /* ( 3, 3) */};

