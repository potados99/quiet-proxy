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
// autotest fft data for 22-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x22[] = {
    1.005393906711f +   1.012308570546f*_Complex_I,
    1.688071880070f +   1.150240841419f*_Complex_I,
    0.683345289428f +  -0.062623351865f*_Complex_I,
    0.155361503274f +  -0.795786088580f*_Complex_I,
   -1.820284248422f +   1.218801819999f*_Complex_I,
    0.628547514320f +  -0.973049954879f*_Complex_I,
    1.065280228237f +   0.036573157841f*_Complex_I,
   -2.060385212897f +   0.046192542979f*_Complex_I,
   -1.013657698873f +   0.781474907362f*_Complex_I,
    0.375646814842f +   1.554324770487f*_Complex_I,
    0.891369658302f +  -0.161096019710f*_Complex_I,
   -1.068796361214f +   0.437936260633f*_Complex_I,
    2.551818984217f +  -0.855823653619f*_Complex_I,
    1.902986665335f +   0.173617409071f*_Complex_I,
    0.782297326663f +   1.157416587734f*_Complex_I,
    1.408853663828f +  -0.360396487397f*_Complex_I,
   -1.133068299545f +   0.494376224047f*_Complex_I,
   -0.644483632405f +  -0.024946520734f*_Complex_I,
   -1.906331676937f +   0.114276645380f*_Complex_I,
   -0.607040125764f +   0.926527519920f*_Complex_I,
    0.405414441208f +   0.272172965895f*_Complex_I,
    0.522244149054f +   0.024648904750f*_Complex_I};

liquid_float_complex fft_test_y22[] = {
    3.812584769431f +   6.167167051279f*_Complex_I,
   -2.048551145080f +   1.920025824226f*_Complex_I,
    6.865239600362f +  -6.254294174522f*_Complex_I,
    6.680188302485f +   7.175301698042f*_Complex_I,
    0.336985685391f +  -2.472221525673f*_Complex_I,
    2.704578846644f +  -1.072297553521f*_Complex_I,
   -5.869735761695f +   0.406925054472f*_Complex_I,
    7.260505946731f +   4.415111182242f*_Complex_I,
    1.284910248555f +  -1.935024971881f*_Complex_I,
    1.066939615916f +  -8.084240769565f*_Complex_I,
   -5.103441669518f +   4.459170611366f*_Complex_I,
   -0.789428947455f +   1.848548655941f*_Complex_I,
   -2.925771543223f +  -0.333175332942f*_Complex_I,
    8.231473045218f +  -1.322435498403f*_Complex_I,
   -2.591866662060f +   5.216079561352f*_Complex_I,
   -0.164183264077f +  -4.464934113704f*_Complex_I,
  -10.152302601435f +   2.776060476179f*_Complex_I,
   -1.546651996340f +   8.030006620400f*_Complex_I,
    2.238990051464f +  -2.081025590453f*_Complex_I,
    2.420796442681f +  -1.572310054104f*_Complex_I,
   11.406980883199f +  10.003031983787f*_Complex_I,
   -0.999573899550f +  -0.554680582506f*_Complex_I};

