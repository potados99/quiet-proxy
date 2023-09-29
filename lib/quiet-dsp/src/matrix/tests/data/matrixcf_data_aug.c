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
// data for testing matrix augmentation
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_aug_x [size: 5 x 4]
liquid_float_complex matrixcf_data_aug_x[] = {
   -1.383545994759f +   0.803655147552f*_Complex_I /* ( 0, 0) */,
   -0.918114125729f +  -1.194809913635f*_Complex_I /* ( 0, 1) */,
    0.090901032090f +   0.484884619713f*_Complex_I /* ( 0, 2) */,
    0.109402157366f +   1.450437188148f*_Complex_I /* ( 0, 3) */,
   -2.269510746002f +  -0.606436431408f*_Complex_I /* ( 1, 0) */,
   -0.195189133286f +   0.416639328003f*_Complex_I /* ( 1, 1) */,
    1.940145850182f +   0.895506143570f*_Complex_I /* ( 1, 2) */,
   -0.784153759480f +  -0.345893263817f*_Complex_I /* ( 1, 3) */,
    0.652509629726f +   0.994532823563f*_Complex_I /* ( 2, 0) */,
   -2.253150939941f +   0.327611356974f*_Complex_I /* ( 2, 1) */,
    1.012208938599f +  -0.677044689655f*_Complex_I /* ( 2, 2) */,
   -0.700399398804f +  -0.330108255148f*_Complex_I /* ( 2, 3) */,
   -1.175772666931f +   0.248428389430f*_Complex_I /* ( 3, 0) */,
    0.412228941917f +  -2.519471645355f*_Complex_I /* ( 3, 1) */,
   -1.667356371880f +  -1.187105178833f*_Complex_I /* ( 3, 2) */,
    1.243350982666f +  -0.736937880516f*_Complex_I /* ( 3, 3) */,
    0.033468723297f +   0.131351217628f*_Complex_I /* ( 4, 0) */,
   -0.617851972580f +   1.434038400650f*_Complex_I /* ( 4, 1) */,
   -1.009798288345f +   0.758803665638f*_Complex_I /* ( 4, 2) */,
    1.450994849205f +  -0.595933079720f*_Complex_I /* ( 4, 3) */};

// matrixcf_data_aug_y [size: 5 x 3]
liquid_float_complex matrixcf_data_aug_y[] = {
    0.301848381758f +   0.353115469217f*_Complex_I /* ( 0, 0) */,
    0.703616917133f +   0.044240720570f*_Complex_I /* ( 0, 1) */,
    0.268176555634f +   1.071476221085f*_Complex_I /* ( 0, 2) */,
   -0.717849135399f +  -0.764326214790f*_Complex_I /* ( 1, 0) */,
   -0.108926303685f +  -0.315297245979f*_Complex_I /* ( 1, 1) */,
    0.357895255089f +  -1.419853448868f*_Complex_I /* ( 1, 2) */,
   -0.831380963326f +   1.003911018372f*_Complex_I /* ( 2, 0) */,
   -0.361211270094f +  -0.926369905472f*_Complex_I /* ( 2, 1) */,
    2.307183980942f +  -0.432167291641f*_Complex_I /* ( 2, 2) */,
   -0.694230437279f +  -1.021739125252f*_Complex_I /* ( 3, 0) */,
    0.412434548140f +  -1.840429663658f*_Complex_I /* ( 3, 1) */,
    0.342358648777f +  -1.084336757660f*_Complex_I /* ( 3, 2) */,
   -0.314995974302f +  -0.811702668667f*_Complex_I /* ( 4, 0) */,
    0.912520587444f +  -2.686280250549f*_Complex_I /* ( 4, 1) */,
    0.204153224826f +  -0.616621196270f*_Complex_I /* ( 4, 2) */};

// matrixcf_data_aug_z [size: 5 x 7]
liquid_float_complex matrixcf_data_aug_z[] = {
   -1.383545994759f +   0.803655147552f*_Complex_I /* ( 0, 0) */,
   -0.918114125729f +  -1.194809913635f*_Complex_I /* ( 0, 1) */,
    0.090901032090f +   0.484884619713f*_Complex_I /* ( 0, 2) */,
    0.109402157366f +   1.450437188148f*_Complex_I /* ( 0, 3) */,
    0.301848381758f +   0.353115469217f*_Complex_I /* ( 0, 4) */,
    0.703616917133f +   0.044240720570f*_Complex_I /* ( 0, 5) */,
    0.268176555634f +   1.071476221085f*_Complex_I /* ( 0, 6) */,
   -2.269510746002f +  -0.606436431408f*_Complex_I /* ( 1, 0) */,
   -0.195189133286f +   0.416639328003f*_Complex_I /* ( 1, 1) */,
    1.940145850182f +   0.895506143570f*_Complex_I /* ( 1, 2) */,
   -0.784153759480f +  -0.345893263817f*_Complex_I /* ( 1, 3) */,
   -0.717849135399f +  -0.764326214790f*_Complex_I /* ( 1, 4) */,
   -0.108926303685f +  -0.315297245979f*_Complex_I /* ( 1, 5) */,
    0.357895255089f +  -1.419853448868f*_Complex_I /* ( 1, 6) */,
    0.652509629726f +   0.994532823563f*_Complex_I /* ( 2, 0) */,
   -2.253150939941f +   0.327611356974f*_Complex_I /* ( 2, 1) */,
    1.012208938599f +  -0.677044689655f*_Complex_I /* ( 2, 2) */,
   -0.700399398804f +  -0.330108255148f*_Complex_I /* ( 2, 3) */,
   -0.831380963326f +   1.003911018372f*_Complex_I /* ( 2, 4) */,
   -0.361211270094f +  -0.926369905472f*_Complex_I /* ( 2, 5) */,
    2.307183980942f +  -0.432167291641f*_Complex_I /* ( 2, 6) */,
   -1.175772666931f +   0.248428389430f*_Complex_I /* ( 3, 0) */,
    0.412228941917f +  -2.519471645355f*_Complex_I /* ( 3, 1) */,
   -1.667356371880f +  -1.187105178833f*_Complex_I /* ( 3, 2) */,
    1.243350982666f +  -0.736937880516f*_Complex_I /* ( 3, 3) */,
   -0.694230437279f +  -1.021739125252f*_Complex_I /* ( 3, 4) */,
    0.412434548140f +  -1.840429663658f*_Complex_I /* ( 3, 5) */,
    0.342358648777f +  -1.084336757660f*_Complex_I /* ( 3, 6) */,
    0.033468723297f +   0.131351217628f*_Complex_I /* ( 4, 0) */,
   -0.617851972580f +   1.434038400650f*_Complex_I /* ( 4, 1) */,
   -1.009798288345f +   0.758803665638f*_Complex_I /* ( 4, 2) */,
    1.450994849205f +  -0.595933079720f*_Complex_I /* ( 4, 3) */,
   -0.314995974302f +  -0.811702668667f*_Complex_I /* ( 4, 4) */,
    0.912520587444f +  -2.686280250549f*_Complex_I /* ( 4, 5) */,
    0.204153224826f +  -0.616621196270f*_Complex_I /* ( 4, 6) */};

