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
// data for testing linear solver
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_linsolve_A [size: 5 x 5]
liquid_float_complex matrixcf_data_linsolve_A[] = {
   -0.482884645462f +  -0.221723198891f*_Complex_I /* ( 0, 0) */,
   -0.387645065784f +   0.086682170630f*_Complex_I /* ( 0, 1) */,
    1.580931067467f +   0.883717715740f*_Complex_I /* ( 0, 2) */,
    1.570333838463f +   1.783135294914f*_Complex_I /* ( 0, 3) */,
   -1.081483244896f +  -0.691094517708f*_Complex_I /* ( 0, 4) */,
    0.248138338327f +  -0.250954031944f*_Complex_I /* ( 1, 0) */,
    0.790891706944f +  -0.313775628805f*_Complex_I /* ( 1, 1) */,
   -0.146090522408f +  -1.320674061775f*_Complex_I /* ( 1, 2) */,
    0.672296106815f +   1.346951484680f*_Complex_I /* ( 1, 3) */,
   -0.352442741394f +   0.056975554675f*_Complex_I /* ( 1, 4) */,
    0.707973957062f +  -0.069402769208f*_Complex_I /* ( 2, 0) */,
   -0.894841134548f +  -1.854133605957f*_Complex_I /* ( 2, 1) */,
    0.397095054388f +  -0.924011290073f*_Complex_I /* ( 2, 2) */,
    0.054669041187f +   0.017023870721f*_Complex_I /* ( 2, 3) */,
    0.515784740448f +  -0.455956429243f*_Complex_I /* ( 2, 4) */,
    0.570774257183f +   0.538610219955f*_Complex_I /* ( 3, 0) */,
   -0.389531791210f +   0.200702637434f*_Complex_I /* ( 3, 1) */,
    0.159817531705f +   1.283960223198f*_Complex_I /* ( 3, 2) */,
    1.571215510368f +   0.574963092804f*_Complex_I /* ( 3, 3) */,
   -2.452192783356f +  -0.583715677261f*_Complex_I /* ( 3, 4) */,
   -0.603657603264f +   0.617622077465f*_Complex_I /* ( 4, 0) */,
    0.935181498528f +   0.949800848961f*_Complex_I /* ( 4, 1) */,
    0.043205004185f +   1.351160168648f*_Complex_I /* ( 4, 2) */,
    0.674502849579f +   0.340750336647f*_Complex_I /* ( 4, 3) */,
   -0.241452947259f +   1.540177464485f*_Complex_I /* ( 4, 4) */};

// matrixcf_data_linsolve_x [size: 5 x 1]
liquid_float_complex matrixcf_data_linsolve_x[] = {
   -0.686784207821f +   0.516409814358f*_Complex_I /* ( 0, 0) */,
    0.725918948650f +  -0.725804686546f*_Complex_I /* ( 1, 0) */,
    0.048043362796f +   1.415739893913f*_Complex_I /* ( 2, 0) */,
    1.184294700623f +  -1.108955144882f*_Complex_I /* ( 3, 0) */,
    1.000079274178f +   0.117630988359f*_Complex_I /* ( 4, 0) */};

// matrixcf_data_linsolve_b [size: 5 x 1]
liquid_float_complex matrixcf_data_linsolve_b[] = {
    1.889372086452f +   2.079795053851f*_Complex_I /* ( 0, 0) */,
    4.099006087145f +   0.093571115573f*_Complex_I /* ( 1, 0) */,
   -0.465385431770f +  -0.201195243205f*_Complex_I /* ( 2, 0) */,
   -2.502649126311f +  -1.292489487343f*_Complex_I /* ( 3, 0) */,
    0.307098947642f +   0.568345470088f*_Complex_I /* ( 4, 0) */};

