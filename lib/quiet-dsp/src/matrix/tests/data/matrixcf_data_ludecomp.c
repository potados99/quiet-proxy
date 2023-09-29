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
// data for testing L/U decomposition
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_ludecomp_A [size: 8 x 8]
liquid_float_complex matrixcf_data_ludecomp_A[] = {
    0.455808967352f +   0.239869371057f*_Complex_I /* ( 0, 0) */,
    1.076113820076f +   0.303303003311f*_Complex_I /* ( 0, 1) */,
   -1.174549579620f +  -1.593330740929f*_Complex_I /* ( 0, 2) */,
    1.428434848785f +  -2.108702898026f*_Complex_I /* ( 0, 3) */,
    1.944794058800f +   1.039716124535f*_Complex_I /* ( 0, 4) */,
   -0.003220892511f +  -1.070197224617f*_Complex_I /* ( 0, 5) */,
    2.282850980759f +   0.567153334618f*_Complex_I /* ( 0, 6) */,
    0.677789986134f +  -0.110934779048f*_Complex_I /* ( 0, 7) */,
   -0.541479706764f +   0.508462309837f*_Complex_I /* ( 1, 0) */,
    0.659551382065f +   0.341979026794f*_Complex_I /* ( 1, 1) */,
    0.422295093536f +  -0.748002707958f*_Complex_I /* ( 1, 2) */,
    0.991572380066f +  -1.739566326141f*_Complex_I /* ( 1, 3) */,
   -0.973251938820f +  -0.314995020628f*_Complex_I /* ( 1, 4) */,
   -0.348222613335f +   1.216362476349f*_Complex_I /* ( 1, 5) */,
   -0.444941103458f +  -0.435953140259f*_Complex_I /* ( 1, 6) */,
    0.664277911186f +   0.398205667734f*_Complex_I /* ( 1, 7) */,
    1.578197240829f +  -0.245545297861f*_Complex_I /* ( 2, 0) */,
   -0.734657287598f +  -0.314642846584f*_Complex_I /* ( 2, 1) */,
   -0.185400843620f +   0.411517560482f*_Complex_I /* ( 2, 2) */,
   -0.141458645463f +   2.540255069733f*_Complex_I /* ( 2, 3) */,
   -1.887707233429f +   1.261052608490f*_Complex_I /* ( 2, 4) */,
    1.356706976891f +  -0.073478087783f*_Complex_I /* ( 2, 5) */,
    0.382849365473f +   1.176013708115f*_Complex_I /* ( 2, 6) */,
    0.088731415570f +  -0.000313452416f*_Complex_I /* ( 2, 7) */,
    0.694614350796f +   0.107012517750f*_Complex_I /* ( 3, 0) */,
   -0.541421890259f +  -1.525843501091f*_Complex_I /* ( 3, 1) */,
    1.210077285767f +  -0.249905958772f*_Complex_I /* ( 3, 2) */,
    0.051122765988f +   0.576834678650f*_Complex_I /* ( 3, 3) */,
    2.360952138901f +  -0.439353585243f*_Complex_I /* ( 3, 4) */,
    0.927220702171f +   0.293185442686f*_Complex_I /* ( 3, 5) */,
   -0.235832184553f +  -0.484229415655f*_Complex_I /* ( 3, 6) */,
   -1.589996099472f +   0.180045768619f*_Complex_I /* ( 3, 7) */,
    1.345695137978f +  -0.080361045897f*_Complex_I /* ( 4, 0) */,
   -0.245824366808f +  -1.841626405716f*_Complex_I /* ( 4, 1) */,
    0.978698849678f +   1.369340777397f*_Complex_I /* ( 4, 2) */,
   -1.106017351151f +  -1.615537166595f*_Complex_I /* ( 4, 3) */,
    0.627505123615f +   1.024900913239f*_Complex_I /* ( 4, 4) */,
    1.808397769928f +  -0.614134788513f*_Complex_I /* ( 4, 5) */,
   -0.322292149067f +  -0.765307128429f*_Complex_I /* ( 4, 6) */,
   -0.674273192883f +   0.044275555760f*_Complex_I /* ( 4, 7) */,
   -2.861634492874f +   2.582857608795f*_Complex_I /* ( 5, 0) */,
   -1.920535564423f +  -0.081001155078f*_Complex_I /* ( 5, 1) */,
   -1.339942932129f +  -0.246527969837f*_Complex_I /* ( 5, 2) */,
    0.540911912918f +   0.283990591764f*_Complex_I /* ( 5, 3) */,
   -0.800716042519f +   0.764756917953f*_Complex_I /* ( 5, 4) */,
    1.206449866295f +   0.518103539944f*_Complex_I /* ( 5, 5) */,
   -0.377558648586f +   0.065486297011f*_Complex_I /* ( 5, 6) */,
   -1.090067625046f +   0.741791069508f*_Complex_I /* ( 5, 7) */,
   -1.424072742462f +   0.091005645692f*_Complex_I /* ( 6, 0) */,
    0.340615779161f +   1.995890378952f*_Complex_I /* ( 6, 1) */,
   -0.395366579294f +   0.685165762901f*_Complex_I /* ( 6, 2) */,
    0.367168039083f +  -1.265154719353f*_Complex_I /* ( 6, 3) */,
    0.716018438339f +   1.003421306610f*_Complex_I /* ( 6, 4) */,
   -0.648339152336f +   2.441966056824f*_Complex_I /* ( 6, 5) */,
    0.788251757622f +   1.254729628563f*_Complex_I /* ( 6, 6) */,
   -0.776828289032f +  -0.615517139435f*_Complex_I /* ( 6, 7) */,
    1.112848401070f +  -0.297139286995f*_Complex_I /* ( 7, 0) */,
    0.366721868515f +   0.650049626827f*_Complex_I /* ( 7, 1) */,
    0.072020366788f +  -0.518339037895f*_Complex_I /* ( 7, 2) */,
    1.033115744591f +  -0.196805760264f*_Complex_I /* ( 7, 3) */,
   -1.083071947098f +  -1.565491795540f*_Complex_I /* ( 7, 4) */,
    1.409144878387f +   0.992799341679f*_Complex_I /* ( 7, 5) */,
    0.387732833624f +  -1.445696353912f*_Complex_I /* ( 7, 6) */,
   -0.528750956059f +  -1.205648779869f*_Complex_I /* ( 7, 7) */};

