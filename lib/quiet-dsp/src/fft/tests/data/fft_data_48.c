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
// autotest fft data for 48-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x48[] = {
   -1.408383409504f +   0.661990153106f*_Complex_I,
   -0.257850483647f +  -2.392863066952f*_Complex_I,
   -0.321563284081f +   1.408168751420f*_Complex_I,
   -1.963488918325f +  -0.315363008755f*_Complex_I,
    0.872572043811f +  -1.774358495756f*_Complex_I,
   -1.036243090405f +   0.085162186806f*_Complex_I,
   -0.810463329242f +   0.370726012575f*_Complex_I,
    0.814727688017f +  -0.148930236445f*_Complex_I,
   -0.482188504339f +  -0.888806074906f*_Complex_I,
    0.751010250272f +   0.610241893778f*_Complex_I,
    1.562853718365f +   0.338170177897f*_Complex_I,
    0.836367957185f +  -1.685869538958f*_Complex_I,
   -0.678836393610f +  -1.105381292997f*_Complex_I,
    1.313536222418f +  -1.604103598331f*_Complex_I,
    0.652309130012f +  -1.915192986159f*_Complex_I,
   -0.398123599463f +   1.372136473305f*_Complex_I,
    2.555137160099f +   0.715094591241f*_Complex_I,
    1.803926723963f +  -0.470162240275f*_Complex_I,
   -1.033969686967f +  -1.754083599107f*_Complex_I,
    0.345505105620f +   1.869665415226f*_Complex_I,
    0.917886037796f +   1.488788889124f*_Complex_I,
   -0.149819207787f +   0.641387132093f*_Complex_I,
    0.239135545455f +   0.491166352445f*_Complex_I,
    0.571741246274f +   0.056534896965f*_Complex_I,
   -0.131630105163f +  -1.508920032468f*_Complex_I,
    1.209119501276f +  -0.078706912158f*_Complex_I,
   -0.955610498388f +   1.044137820022f*_Complex_I,
    0.106457806412f +  -0.585542024212f*_Complex_I,
   -1.229933443664f +  -0.322249167809f*_Complex_I,
    0.278186189361f +   1.807684972303f*_Complex_I,
   -1.729784506112f +  -0.939519586014f*_Complex_I,
    0.927483189137f +   0.431322133098f*_Complex_I,
    0.141968377392f +  -0.120521833531f*_Complex_I,
    0.747436107175f +  -1.117297332586f*_Complex_I,
    0.321427506892f +   0.604553538042f*_Complex_I,
   -1.310259971951f +   0.301350874871f*_Complex_I,
    0.000616127451f +   1.395956853708f*_Complex_I,
    0.789283665376f +  -0.378417239374f*_Complex_I,
    1.626071060809f +  -0.838198796474f*_Complex_I,
   -0.502170615893f +  -0.371786828507f*_Complex_I,
    0.941560993676f +   0.083132997096f*_Complex_I,
    0.217335920952f +  -0.775367298569f*_Complex_I,
   -1.386726382455f +   1.228033537755f*_Complex_I,
    0.135305964480f +   1.010214926902f*_Complex_I,
   -0.769134001940f +  -1.642182708631f*_Complex_I,
    0.451443995268f +  -1.443277308466f*_Complex_I,
    0.315403114502f +   0.409584212993f*_Complex_I,
    0.777007938735f +   0.033642728423f*_Complex_I};

liquid_float_complex fft_test_y48[] = {
    5.666636855245f +  -5.718253686246f*_Complex_I,
   -9.318440723038f + -11.045628239935f*_Complex_I,
  -10.484391800934f +  10.258547835119f*_Complex_I,
    5.692975013010f +  -0.079178697546f*_Complex_I,
   -0.031494239726f +  -3.429117974659f*_Complex_I,
   -1.633492827483f +   6.955978741593f*_Complex_I,
    9.741303637543f +   2.061588265899f*_Complex_I,
    1.051018454307f +  11.180284489721f*_Complex_I,
   -8.006452512021f +   0.459314562290f*_Complex_I,
   -7.397134103296f +   6.198088361763f*_Complex_I,
    4.688329496623f +   1.626283668222f*_Complex_I,
   -8.380975402709f +  -3.715659857481f*_Complex_I,
   -4.832542130429f +  -9.241813561210f*_Complex_I,
   -5.444148048877f +  -5.774968307876f*_Complex_I,
   -2.557281197147f +  -8.013068178874f*_Complex_I,
   -2.508606838763f +   3.393130955025f*_Complex_I,
  -13.856615792482f +  -8.279988253172f*_Complex_I,
   -0.275213201833f +   9.234040467214f*_Complex_I,
  -10.548623142987f +   1.461152259705f*_Complex_I,
   -5.454201445127f +   5.015988800202f*_Complex_I,
    3.151148175752f +  16.404964892896f*_Complex_I,
   -2.628471739476f +  12.549705973202f*_Complex_I,
   -5.309278338161f +  -1.496205611507f*_Complex_I,
    8.327510797620f +   9.076602173656f*_Complex_I,
   -7.249202313653f +   0.578432313391f*_Complex_I,
    0.278119672993f +   6.335493150399f*_Complex_I,
   -4.400202487177f +   4.358641062270f*_Complex_I,
    1.825561215029f + -10.742991731336f*_Complex_I,
    2.059618967411f +   5.230483842207f*_Complex_I,
   -0.589368957248f +  -0.568413649725f*_Complex_I,
    5.846114680415f +   3.953722464016f*_Complex_I,
   -4.790203069855f +   5.357335572595f*_Complex_I,
  -16.219316666593f +   5.416145069047f*_Complex_I,
    4.053779640014f +  14.490156426037f*_Complex_I,
   10.343285976607f + -19.941466772140f*_Complex_I,
   -0.179745539698f +  -6.776924924303f*_Complex_I,
    9.333647116859f +   2.311810446775f*_Complex_I,
   -0.778589953827f +  -7.796695480692f*_Complex_I,
   -5.728518422011f +  -0.187241621271f*_Complex_I,
   15.554791252022f +   3.837751365144f*_Complex_I,
   -3.410115684107f +  -2.362837725953f*_Complex_I,
  -14.699080682437f +   4.704009521181f*_Complex_I,
    4.974381394298f +  -3.870880098021f*_Complex_I,
    4.347015481178f +   1.639590273798f*_Complex_I,
    6.775882853829f +  -8.045391749167f*_Complex_I,
   -6.905056488040f +  -1.077414483536f*_Complex_I,
   -6.906638779165f +  -3.861138554296f*_Complex_I,
   -0.790121808651f +  -0.288436445313f*_Complex_I};

