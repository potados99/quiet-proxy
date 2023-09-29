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
// iirfilt_crcf_data_h7x64.c: autotest iirfilt data
//



#include "liquid.h"
#include "autotest/autotest.h"

float iirfilt_crcf_data_h7x64_b[] = {
    0.000340537653,
    0.002043225916,
    0.005108064791,
    0.006810753054,
    0.005108064791,
    0.002043225916,
    0.000340537653};

float iirfilt_crcf_data_h7x64_a[] = {
    1.000000000000,
   -3.579434798331,
    5.658667165934,
   -4.965415228779,
    2.529494905841,
   -0.705274114510,
    0.083756479619};

liquid_float_complex iirfilt_crcf_data_h7x64_x[] = {
    0.004233635522f +   0.032166672422f*_Complex_I,
   -0.157552590267f +   0.250368602921f*_Complex_I,
    0.054267060665f +  -0.005044027264f*_Complex_I,
    0.051025281222f +   0.067245838231f*_Complex_I,
   -0.027078112717f +  -0.126549310903f*_Complex_I,
    0.035527067912f +   0.084082095013f*_Complex_I,
   -0.045166037588f +   0.117512061237f*_Complex_I,
   -0.170543036494f +  -0.210138171552f*_Complex_I,
    0.122017191616f +   0.083315021977f*_Complex_I,
    0.087665380573f +  -0.113419352152f*_Complex_I,
   -0.020592340496f +   0.051461184327f*_Complex_I,
    0.005438907415f +  -0.034203108407f*_Complex_I,
   -0.004238610906f +  -0.010875374856f*_Complex_I,
    0.014448167389f +   0.140297619530f*_Complex_I,
    0.023037852846f +   0.147634578106f*_Complex_I,
    0.039831512515f +   0.117367316573f*_Complex_I,
   -0.049079756276f +  -0.134214287084f*_Complex_I,
   -0.081369646592f +  -0.123999271543f*_Complex_I,
   -0.060778482772f +  -0.005943225227f*_Complex_I,
    0.060096536726f +   0.110619062414f*_Complex_I,
   -0.029590602066f +   0.069542558264f*_Complex_I,
    0.276694153680f +   0.033847635389f*_Complex_I,
   -0.069801585631f +  -0.024433292968f*_Complex_I,
    0.103527771239f +   0.043047059964f*_Complex_I,
    0.052392266919f +   0.106611921459f*_Complex_I,
    0.047921013690f +   0.144591771640f*_Complex_I,
   -0.100885260679f +   0.085422512163f*_Complex_I,
    0.023817071089f +   0.007631681829f*_Complex_I,
   -0.103520290629f +   0.065084699549f*_Complex_I,
    0.141218652175f +   0.181817618913f*_Complex_I,
    0.091918916526f +   0.090132723783f*_Complex_I,
    0.073412476081f +  -0.185654057154f*_Complex_I,
    0.064690355167f +  -0.154617720920f*_Complex_I,
   -0.141562424619f +  -0.078498890176f*_Complex_I,
   -0.089061791163f +  -0.089972135569f*_Complex_I,
    0.061285035005f +  -0.042181313189f*_Complex_I,
    0.011648008082f +   0.030075451872f*_Complex_I,
   -0.050030705016f +   0.044231269056f*_Complex_I,
    0.055904020426f +  -0.100086776348f*_Complex_I,
    0.067035512200f +   0.110427319881f*_Complex_I,
    0.112195729535f +  -0.159140605014f*_Complex_I,
   -0.008321783937f +  -0.074224475191f*_Complex_I,
    0.124554695470f +  -0.000035276105f*_Complex_I,
    0.178233609860f +  -0.241786527172f*_Complex_I,
    0.013428861272f +   0.019929110617f*_Complex_I,
    0.106814998943f +   0.061446999514f*_Complex_I,
   -0.087662510082f +  -0.142756477357f*_Complex_I,
    0.005116389200f +   0.004875226134f*_Complex_I,
   -0.082163710392f +  -0.003854447463f*_Complex_I,
    0.055960629067f +   0.147529880141f*_Complex_I,
    0.104198321794f +   0.047973142904f*_Complex_I,
   -0.092852806707f +  -0.088517198490f*_Complex_I,
    0.008453380604f +   0.016712253059f*_Complex_I,
   -0.168237622832f +   0.182661482388f*_Complex_I,
   -0.003676740087f +   0.067558336540f*_Complex_I,
    0.083397702670f +   0.084971378309f*_Complex_I,
    0.105858021404f +   0.040735314366f*_Complex_I,
   -0.117228290082f +  -0.024601874801f*_Complex_I,
   -0.158931397897f +  -0.101660731802f*_Complex_I,
   -0.079872460607f +  -0.030609694665f*_Complex_I,
   -0.070191072161f +   0.183132157615f*_Complex_I,
   -0.187191287439f +  -0.013144361324f*_Complex_I,
   -0.097352654114f +  -0.073775329625f*_Complex_I,
   -0.160782253378f +   0.108482062513f*_Complex_I};

liquid_float_complex iirfilt_crcf_data_h7x64_y[] = {
    0.000001441712f +   0.000010953963f*_Complex_I,
   -0.000039841800f +   0.000190192712f*_Complex_I,
   -0.000432579170f +   0.001292948964f*_Complex_I,
   -0.001963477446f +   0.005116752194f*_Complex_I,
   -0.005460987213f +   0.013853437396f*_Complex_I,
   -0.010691848048f +   0.028003970363f*_Complex_I,
   -0.015829219307f +   0.044636043744f*_Complex_I,
   -0.018444702482f +   0.058202478955f*_Complex_I,
   -0.017385042715f +   0.063522217409f*_Complex_I,
   -0.013852978602f +   0.058220061227f*_Complex_I,
   -0.010372120290f +   0.043135943082f*_Complex_I,
   -0.008386259332f +   0.021557712213f*_Complex_I,
   -0.007057894617f +  -0.001756678543f*_Complex_I,
   -0.004462600311f +  -0.021708921739f*_Complex_I,
    0.000413860784f +  -0.033985730231f*_Complex_I,
    0.006867599715f +  -0.035636537512f*_Complex_I,
    0.013151792937f +  -0.025207996188f*_Complex_I,
    0.017581663360f +  -0.003488920494f*_Complex_I,
    0.018987594562f +   0.024903700370f*_Complex_I,
    0.016476110032f +   0.051134067764f*_Complex_I,
    0.009459018773f +   0.065241189212f*_Complex_I,
   -0.001441469538f +   0.061675106678f*_Complex_I,
   -0.013298737003f +   0.042982674038f*_Complex_I,
   -0.020975009992f +   0.018439112600f*_Complex_I,
   -0.019171489571f +  -0.001220893708f*_Complex_I,
   -0.005478667970f +  -0.008887635676f*_Complex_I,
    0.017790116314f +  -0.002906881750f*_Complex_I,
    0.044167796652f +   0.014155489246f*_Complex_I,
    0.065318293362f +   0.037562815973f*_Complex_I,
    0.073959143834f +   0.061781091547f*_Complex_I,
    0.066724360261f +   0.081615483562f*_Complex_I,
    0.046102292983f +   0.093697367755f*_Complex_I,
    0.020214021152f +   0.097173425139f*_Complex_I,
   -0.000316969804f +   0.092297203234f*_Complex_I,
   -0.007456572181f +   0.078335403968f*_Complex_I,
   -0.000109513959f +   0.053648935265f*_Complex_I,
    0.015245116502f +   0.018291043433f*_Complex_I,
    0.028507759029f +  -0.023453077073f*_Complex_I,
    0.031847159216f +  -0.063005523552f*_Complex_I,
    0.023465571027f +  -0.090337797990f*_Complex_I,
    0.007593101686f +  -0.098277994324f*_Complex_I,
   -0.008080860379f +  -0.085900545160f*_Complex_I,
   -0.015861382531f +  -0.059241419647f*_Complex_I,
   -0.011151330660f +  -0.029092859925f*_Complex_I,
    0.006066947770f +  -0.006896796239f*_Complex_I,
    0.031921995818f +  -0.000519982404f*_Complex_I,
    0.060475303064f +  -0.011467885217f*_Complex_I,
    0.085275600399f +  -0.034448894253f*_Complex_I,
    0.100389600600f +  -0.059802028892f*_Complex_I,
    0.101457128362f +  -0.077810326455f*_Complex_I,
    0.087090251053f +  -0.082216982388f*_Complex_I,
    0.060162530535f +  -0.071286280151f*_Complex_I,
    0.027739822472f +  -0.047336780803f*_Complex_I,
   -0.001368012589f +  -0.016047415915f*_Complex_I,
   -0.020598333225f +   0.014978961236f*_Complex_I,
   -0.028528780470f +   0.039136270897f*_Complex_I,
   -0.028450797573f +   0.053688158765f*_Complex_I,
   -0.024993006862f +   0.060174099568f*_Complex_I,
   -0.020853885213f +   0.062097322569f*_Complex_I,
   -0.016606097058f +   0.061833377745f*_Complex_I,
   -0.013052589087f +   0.058990818175f*_Complex_I,
   -0.012808887831f +   0.051482609352f*_Complex_I,
   -0.019272140076f +   0.038484586328f*_Complex_I,
   -0.034383553960f +   0.022386350903f*_Complex_I};

