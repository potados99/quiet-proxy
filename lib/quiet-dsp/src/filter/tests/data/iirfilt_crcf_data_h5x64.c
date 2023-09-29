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
// iirfilt_crcf_data_h5x64.c: autotest iirfilt data
//



#include "liquid.h"
#include "autotest/autotest.h"

float iirfilt_crcf_data_h5x64_b[] = {
    0.004824343358,
    0.019297373431,
    0.028946060146,
    0.019297373431,
    0.004824343358};

float iirfilt_crcf_data_h5x64_a[] = {
    1.000000000000,
   -2.369513007182,
    2.313988414416,
   -1.054665405879,
    0.187379492368};

liquid_float_complex iirfilt_crcf_data_h5x64_x[] = {
    0.034816486087f +  -0.057435933225f*_Complex_I,
   -0.138922686034f +   0.002487157060f*_Complex_I,
    0.002168200782f +   0.075752631688f*_Complex_I,
    0.110645778286f +   0.097973148283f*_Complex_I,
   -0.062999498912f +   0.034473236147f*_Complex_I,
    0.030513585484f +   0.108486942526f*_Complex_I,
    0.130905798224f +  -0.206952317034f*_Complex_I,
    0.104557822758f +  -0.049326363722f*_Complex_I,
    0.175995475228f +  -0.040903480637f*_Complex_I,
    0.263382017202f +   0.007386489593f*_Complex_I,
    0.075401623113f +   0.034346157974f*_Complex_I,
   -0.004787311774f +   0.050323428781f*_Complex_I,
    0.039595621673f +  -0.013034423002f*_Complex_I,
    0.289435339135f +   0.004887226549f*_Complex_I,
    0.000109192613f +  -0.098143317718f*_Complex_I,
    0.218628727322f +   0.045783638022f*_Complex_I,
    0.011357280346f +   0.060469524704f*_Complex_I,
   -0.005462153874f +   0.011440185961f*_Complex_I,
    0.086903581383f +   0.054667638583f*_Complex_I,
    0.009197661173f +  -0.006158688411f*_Complex_I,
    0.082244960567f +  -0.138538495472f*_Complex_I,
    0.078074527675f +  -0.110054617600f*_Complex_I,
   -0.071517687777f +  -0.053281282254f*_Complex_I,
    0.050695873651f +   0.049035186418f*_Complex_I,
   -0.064011859850f +   0.057026886508f*_Complex_I,
    0.002187309591f +   0.247199024244f*_Complex_I,
    0.177910643270f +   0.036260952778f*_Complex_I,
   -0.133404966159f +   0.007272659425f*_Complex_I,
    0.104545832232f +   0.100374198245f*_Complex_I,
    0.152937259249f +  -0.006345268825f*_Complex_I,
   -0.089893987831f +  -0.066730853350f*_Complex_I,
   -0.031614665144f +  -0.108199665873f*_Complex_I,
   -0.019945023665f +  -0.036637064501f*_Complex_I,
    0.035423077805f +  -0.084251698103f*_Complex_I,
   -0.045559909198f +  -0.065683835690f*_Complex_I,
    0.082043588708f +  -0.073113783286f*_Complex_I,
    0.146363247845f +  -0.313133192986f*_Complex_I,
    0.163657926540f +   0.035668446628f*_Complex_I,
   -0.133126328934f +  -0.033221937410f*_Complex_I,
   -0.041582597083f +   0.060780541288f*_Complex_I,
   -0.102136662865f +   0.064174466409f*_Complex_I,
    0.129371455827f +  -0.122309646349f*_Complex_I,
    0.081072163867f +   0.121012321373f*_Complex_I,
    0.035429837296f +   0.040975877524f*_Complex_I,
    0.047403447509f +   0.014166128441f*_Complex_I,
    0.081667476778f +   0.117576764934f*_Complex_I,
    0.142529344063f +  -0.015788307193f*_Complex_I,
    0.107269994778f +   0.039678416397f*_Complex_I,
   -0.189638285144f +  -0.025105560583f*_Complex_I,
    0.127449393546f +  -0.026105377201f*_Complex_I,
    0.051057729361f +  -0.029706326528f*_Complex_I,
    0.095342091161f +  -0.221870514334f*_Complex_I,
    0.033077914989f +  -0.078421433242f*_Complex_I,
    0.139326073519f +   0.176520418207f*_Complex_I,
    0.180222947875f +  -0.140485235948f*_Complex_I,
   -0.092080231794f +   0.044423535254f*_Complex_I,
   -0.116184788790f +  -0.081712392283f*_Complex_I,
   -0.015159814021f +  -0.253655296232f*_Complex_I,
   -0.165572835614f +   0.032968825997f*_Complex_I,
   -0.018186027637f +   0.146030996176f*_Complex_I,
   -0.081743534837f +   0.046764387177f*_Complex_I,
   -0.163907916201f +   0.000894565796f*_Complex_I,
    0.066507006426f +   0.153027239112f*_Complex_I,
   -0.093381553000f +   0.004333390574f*_Complex_I};

liquid_float_complex iirfilt_crcf_data_h5x64_y[] = {
    0.000167966683f +  -0.000277090663f*_Complex_I,
    0.000399655237f +  -0.001752933682f*_Complex_I,
   -0.001104267382f +  -0.004761506250f*_Complex_I,
   -0.006137988749f +  -0.006620307024f*_Complex_I,
   -0.012217626919f +  -0.002445090386f*_Complex_I,
   -0.014480238497f +   0.010330691717f*_Complex_I,
   -0.010763861323f +   0.028395668560f*_Complex_I,
   -0.000501503170f +   0.042087127701f*_Complex_I,
    0.017677520131f +   0.040492499282f*_Complex_I,
    0.044775392784f +   0.020918790830f*_Complex_I,
    0.079868253591f +  -0.007890790986f*_Complex_I,
    0.117333468546f +  -0.032191317082f*_Complex_I,
    0.145332483454f +  -0.041696063730f*_Complex_I,
    0.153450768495f +  -0.034623789141f*_Complex_I,
    0.143091173002f +  -0.017649460381f*_Complex_I,
    0.125440207813f +  -0.001185301267f*_Complex_I,
    0.110781054574f +   0.007694330137f*_Complex_I,
    0.102309442381f +   0.009525121208f*_Complex_I,
    0.096424656974f +   0.009467240886f*_Complex_I,
    0.087905819414f +   0.011472932774f*_Complex_I,
    0.075351746332f +   0.015189934128f*_Complex_I,
    0.061539619627f +   0.015371965161f*_Complex_I,
    0.050238103007f +   0.005354811389f*_Complex_I,
    0.042392909138f +  -0.015692162843f*_Complex_I,
    0.035487235197f +  -0.039320795693f*_Complex_I,
    0.026683183579f +  -0.051939223046f*_Complex_I,
    0.016086735480f +  -0.042351028087f*_Complex_I,
    0.007718993110f +  -0.009467148500f*_Complex_I,
    0.005371191435f +   0.034876269506f*_Complex_I,
    0.009169183447f +   0.073622002790f*_Complex_I,
    0.018251989832f +   0.094472386300f*_Complex_I,
    0.030162933688f +   0.092028482193f*_Complex_I,
    0.038047814129f +   0.066731638129f*_Complex_I,
    0.035763727219f +   0.025446392854f*_Complex_I,
    0.023934856252f +  -0.020176728351f*_Complex_I,
    0.008437472733f +  -0.058844376262f*_Complex_I,
   -0.003244989715f +  -0.085035950076f*_Complex_I,
   -0.003390870214f +  -0.101037326348f*_Complex_I,
    0.012003956420f +  -0.111181202859f*_Complex_I,
    0.036474465180f +  -0.114015132267f*_Complex_I,
    0.054397129333f +  -0.103816397690f*_Complex_I,
    0.053458816959f +  -0.078552582252f*_Complex_I,
    0.035502609681f +  -0.044222383504f*_Complex_I,
    0.014265637465f +  -0.010619069148f*_Complex_I,
    0.003101144454f +   0.016085677224f*_Complex_I,
    0.006286890891f +   0.034538795527f*_Complex_I,
    0.020824414839f +   0.045682197348f*_Complex_I,
    0.042111099700f +   0.051038175528f*_Complex_I,
    0.064730289486f +   0.051165119231f*_Complex_I,
    0.079924238054f +   0.045642918872f*_Complex_I,
    0.080081550492f +   0.034340023196f*_Complex_I,
    0.067180942535f +   0.017458189468f*_Complex_I,
    0.051064446907f +  -0.005688909571f*_Complex_I,
    0.040695417558f +  -0.033996511064f*_Complex_I,
    0.040715290376f +  -0.059379363759f*_Complex_I,
    0.051739083738f +  -0.071274663107f*_Complex_I,
    0.067460869459f +  -0.066847437344f*_Complex_I,
    0.074610717895f +  -0.053096308826f*_Complex_I,
    0.062263741557f +  -0.042094216632f*_Complex_I,
    0.029932249437f +  -0.041388946019f*_Complex_I,
   -0.013495205238f +  -0.045430267433f*_Complex_I,
   -0.055715901366f +  -0.041773963667f*_Complex_I,
   -0.087248260391f +  -0.024536503294f*_Complex_I,
   -0.103228307102f +   0.002973369704f*_Complex_I};

