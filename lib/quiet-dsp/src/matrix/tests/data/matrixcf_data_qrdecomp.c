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
// data for testing Q/R decomposition
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_qrdecomp_A [size: 4 x 4]
liquid_float_complex matrixcf_data_qrdecomp_A[] = {
    2.114020000000f +  -0.576040000000f*_Complex_I /* ( 0, 0) */,
    0.417500000000f +   1.008330000000f*_Complex_I /* ( 0, 1) */,
   -0.962640000000f +  -3.621960000000f*_Complex_I /* ( 0, 2) */,
   -0.206790000000f +  -1.026680000000f*_Complex_I /* ( 0, 3) */,
    0.008540000000f +   1.616260000000f*_Complex_I /* ( 1, 0) */,
    0.846950000000f +  -0.327360000000f*_Complex_I /* ( 1, 1) */,
   -1.018620000000f +  -1.107860000000f*_Complex_I /* ( 1, 2) */,
   -1.788770000000f +   1.844560000000f*_Complex_I /* ( 1, 3) */,
   -2.979010000000f +  -1.303840000000f*_Complex_I /* ( 2, 0) */,
    0.522890000000f +   1.891100000000f*_Complex_I /* ( 2, 1) */,
    1.325760000000f +  -0.367370000000f*_Complex_I /* ( 2, 2) */,
    0.047170000000f +   0.206280000000f*_Complex_I /* ( 2, 3) */,
    0.289700000000f +   0.642470000000f*_Complex_I /* ( 3, 0) */,
   -0.559160000000f +   0.683020000000f*_Complex_I /* ( 3, 1) */,
    1.406150000000f +   0.623980000000f*_Complex_I /* ( 3, 2) */,
   -0.127670000000f +  -0.539970000000f*_Complex_I /* ( 3, 3) */};

// matrixcf_data_qrdecomp_Q [size: 4 x 4]
liquid_float_complex matrixcf_data_qrdecomp_Q[] = {
    0.491706158979f +  -0.133982845866f*_Complex_I /* ( 0, 0) */,
    0.429660711419f +   0.559833033911f*_Complex_I /* ( 0, 1) */,
   -0.309333641162f +  -0.278321211351f*_Complex_I /* ( 0, 2) */,
    0.215207397547f +  -0.150957196713f*_Complex_I /* ( 0, 3) */,
    0.001986343837f +   0.375930689639f*_Complex_I /* ( 1, 0) */,
    0.242768204454f +   0.009257007128f*_Complex_I /* ( 1, 1) */,
   -0.422306122793f +  -0.032511505165f*_Complex_I /* ( 1, 2) */,
   -0.503566009661f +   0.605534385769f*_Complex_I /* ( 1, 3) */,
   -0.692896739226f +  -0.303263998601f*_Complex_I /* ( 2, 0) */,
    0.054111560749f +   0.468071856237f*_Complex_I /* ( 2, 1) */,
   -0.082147488614f +   0.069653107384f*_Complex_I /* ( 2, 2) */,
    0.279669645547f +   0.340721083028f*_Complex_I /* ( 2, 3) */,
    0.067382179098f +   0.149433995875f*_Complex_I /* ( 3, 0) */,
   -0.270466351267f +   0.384428384950f*_Complex_I /* ( 3, 1) */,
   -0.285071449427f +   0.744704670261f*_Complex_I /* ( 3, 2) */,
   -0.173581995183f +  -0.293616086507f*_Complex_I /* ( 3, 3) */};

// matrixcf_data_qrdecomp_R [size: 4 x 4]
liquid_float_complex matrixcf_data_qrdecomp_R[] = {
    4.299356356224f +   0.000000000000f*_Complex_I /* ( 0, 0) */,
   -0.922616273377f +  -0.789487259898f*_Complex_I /* ( 0, 1) */,
   -1.025768821795f +  -1.040664085433f*_Complex_I /* ( 0, 2) */,
    0.541217397816f +  -0.002345615451f*_Complex_I /* ( 0, 3) */,
    0.000000000000f +   0.000000000000f*_Complex_I /* ( 1, 0) */,
    2.273733268802f +   0.000000000000f*_Complex_I /* ( 1, 1) */,
   -2.939502710322f +  -2.626579524510f*_Complex_I /* ( 1, 2) */,
   -1.154743344912f +   0.323209860623f*_Complex_I /* ( 1, 3) */,
    0.000000000000f +   0.000000000000f*_Complex_I /* ( 2, 0) */,
    0.000000000000f +   0.000000000000f*_Complex_I /* ( 2, 1) */,
    1.701364174878f +   0.000000000000f*_Complex_I /* ( 2, 2) */,
    0.689923063328f +  -0.348316412767f*_Complex_I /* ( 2, 3) */,
    0.000000000000f +   0.000000000000f*_Complex_I /* ( 3, 0) */,
    0.000000000000f +   0.000000000000f*_Complex_I /* ( 3, 1) */,
    0.000000000000f +   0.000000000000f*_Complex_I /* ( 3, 2) */,
    2.392371328442f +   0.000000000000f*_Complex_I /* ( 3, 3) */};

