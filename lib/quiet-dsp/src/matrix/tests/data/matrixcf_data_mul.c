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
// data for testing matrix multiplication
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_mul_x [size: 5 x 4]
liquid_float_complex matrixcf_data_mul_x[] = {
    1.131277322769f +  -2.908640623093f*_Complex_I /* ( 0, 0) */,
    0.847201466560f +  -1.637244105339f*_Complex_I /* ( 0, 1) */,
   -2.173580169678f +   0.096817605197f*_Complex_I /* ( 0, 2) */,
    0.792498826981f +  -0.358158409595f*_Complex_I /* ( 0, 3) */,
   -0.243082717061f +   0.824095964432f*_Complex_I /* ( 1, 0) */,
   -1.889652967453f +   0.283876717091f*_Complex_I /* ( 1, 1) */,
    0.044418141246f +  -0.882465064526f*_Complex_I /* ( 1, 2) */,
    0.515216410160f +  -0.366532146931f*_Complex_I /* ( 1, 3) */,
    0.579283773899f +   1.173513293266f*_Complex_I /* ( 2, 0) */,
    0.059265002608f +  -0.497733235359f*_Complex_I /* ( 2, 1) */,
   -0.877321839333f +   0.404732406139f*_Complex_I /* ( 2, 2) */,
   -0.794282734394f +   0.456011295319f*_Complex_I /* ( 2, 3) */,
   -1.174414634705f +  -1.358565688133f*_Complex_I /* ( 3, 0) */,
   -0.418152034283f +   1.380919337273f*_Complex_I /* ( 3, 1) */,
   -0.747197151184f +   1.584241986275f*_Complex_I /* ( 3, 2) */,
   -0.522293865681f +  -0.573823392391f*_Complex_I /* ( 3, 3) */,
   -1.866284489632f +  -0.199214607477f*_Complex_I /* ( 4, 0) */,
   -0.453905433416f +   0.452787637711f*_Complex_I /* ( 4, 1) */,
    1.989426016808f +  -1.771166682243f*_Complex_I /* ( 4, 2) */,
    2.234328985214f +   0.855401337147f*_Complex_I /* ( 4, 3) */};

// matrixcf_data_mul_y [size: 4 x 3]
liquid_float_complex matrixcf_data_mul_y[] = {
    0.122429788113f +  -1.041572093964f*_Complex_I /* ( 0, 0) */,
   -1.123313307762f +  -1.396123170853f*_Complex_I /* ( 0, 1) */,
   -0.318034142256f +  -0.537796914577f*_Complex_I /* ( 0, 2) */,
    0.096901215613f +  -0.035752061754f*_Complex_I /* ( 1, 0) */,
    0.423960685730f +  -0.379842221737f*_Complex_I /* ( 1, 1) */,
   -0.184147700667f +   0.022100308910f*_Complex_I /* ( 1, 2) */,
    0.189968794584f +   0.919595599174f*_Complex_I /* ( 2, 0) */,
    0.621766507626f +  -0.634516119957f*_Complex_I /* ( 2, 1) */,
    0.605251312256f +   1.410223841667f*_Complex_I /* ( 2, 2) */,
    0.427330523729f +   0.042397715151f*_Complex_I /* ( 3, 0) */,
    0.204851210117f +   0.611065924168f*_Complex_I /* ( 3, 1) */,
    0.562124013901f +   0.047597970814f*_Complex_I /* ( 3, 2) */};

// matrixcf_data_mul_z [size: 5 x 3]
liquid_float_complex matrixcf_data_mul_z[] = {
   -3.015598273252f +  -3.823225604286f*_Complex_I /* ( 0, 0) */,
   -6.503138041472f +   2.522251659946f*_Complex_I /* ( 0, 1) */,
   -3.033435877267f +  -2.533375977709f*_Complex_I /* ( 0, 2) */,
    1.711291176504f +   0.187568584413f*_Complex_I /* ( 1, 0) */,
    0.527484730969f +  -0.085346610822f*_Complex_I /* ( 1, 1) */,
    2.440625470928f +  -0.878385559540f*_Complex_I /* ( 1, 2) */,
    0.383559143593f +  -1.078745633782f*_Complex_I /* ( 2, 0) */,
    0.093675017974f +  -1.944126015771f*_Complex_I /* ( 2, 1) */,
   -1.122987739839f +  -1.365514815630f*_Complex_I /* ( 2, 2) */,
   -3.347645581625f +   0.552152171890f*_Complex_I /* ( 3, 0) */,
    0.554058303745f +   4.932442551750f*_Complex_I /* ( 3, 1) */,
   -3.263304464031f +   0.357861697730f*_Complex_I /* ( 3, 2) */,
    2.461434774758f +   3.932854324787f*_Complex_I /* ( 4, 0) */,
    1.845966920717f +   2.370697350446f*_Complex_I /* ( 4, 1) */,
    5.477082880684f +   3.294354034834f*_Complex_I /* ( 4, 2) */};

