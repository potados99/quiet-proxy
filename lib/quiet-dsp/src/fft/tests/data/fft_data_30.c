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
// autotest fft data for 30-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x30[] = {
    1.383958311928f +   1.009063372834f*_Complex_I,
    0.656943839727f +  -0.201492142788f*_Complex_I,
   -1.263185461543f +  -0.762235271683f*_Complex_I,
   -0.279286295800f +   0.737833309276f*_Complex_I,
    0.061984731638f +   0.232640465778f*_Complex_I,
    0.078974781535f +   0.151163978562f*_Complex_I,
   -0.067264854607f +  -1.701011326832f*_Complex_I,
   -2.367250035232f +  -0.675654408115f*_Complex_I,
    0.901831068347f +  -2.291740807507f*_Complex_I,
   -0.685180193104f +   0.640309251420f*_Complex_I,
   -0.865870302577f +  -0.234993063029f*_Complex_I,
    0.394411867502f +  -1.629554965527f*_Complex_I,
   -0.163205564173f +   0.199656642882f*_Complex_I,
    0.561129126184f +   2.875025531619f*_Complex_I,
   -1.191762025326f +   0.544473782291f*_Complex_I,
    0.808768695645f +   1.055445062240f*_Complex_I,
   -0.145391531392f +  -0.095884441741f*_Complex_I,
    1.006538762836f +  -0.724775764669f*_Complex_I,
    2.116364610835f +  -2.412759658708f*_Complex_I,
    0.210526780948f +   1.338479312378f*_Complex_I,
    0.722177277886f +   1.447742766425f*_Complex_I,
    0.148533332865f +   0.262381546261f*_Complex_I,
   -1.337190861421f +   1.251733062365f*_Complex_I,
   -0.346555962201f +  -0.012481387193f*_Complex_I,
    1.400932749094f +  -0.360556660035f*_Complex_I,
    0.479524006659f +  -0.777208683834f*_Complex_I,
   -0.525976158853f +  -0.155146817266f*_Complex_I,
   -1.237887495307f +   0.159614688084f*_Complex_I,
    0.526429110861f +  -1.368405705104f*_Complex_I,
   -0.688995272873f +   0.833548127008f*_Complex_I};

liquid_float_complex fft_test_y30[] = {
    0.294027040082f +  -0.664790204608f*_Complex_I,
   -7.251086654153f +   1.930700457878f*_Complex_I,
    4.192769230897f +   1.789725983362f*_Complex_I,
   11.197367573831f +   3.254783235859f*_Complex_I,
  -10.053118996304f +  -1.739286933243f*_Complex_I,
   10.012405959748f +  -4.383419562391f*_Complex_I,
   -1.293134786584f +   8.917417869363f*_Complex_I,
    3.828158834339f +   7.240756714477f*_Complex_I,
    2.213781017086f +  -3.491740260928f*_Complex_I,
  -11.803330439118f +   1.771364969478f*_Complex_I,
    9.272563287802f +   0.848929030951f*_Complex_I,
   -0.497098653141f +  -0.996109950789f*_Complex_I,
   -3.419412966566f +  -7.252273855897f*_Complex_I,
   -3.013334143526f +  -1.690385014079f*_Complex_I,
    8.340586193744f +   1.433397080247f*_Complex_I,
    2.813635161314f +  -8.730057114052f*_Complex_I,
    0.460908379865f +   1.518681481090f*_Complex_I,
   -5.717851959043f +  -2.820174393000f*_Complex_I,
    8.168927986272f +  11.157813415293f*_Complex_I,
    2.879730739941f +   1.551007915618f*_Complex_I,
    0.710609564242f +  -1.414210144075f*_Complex_I,
    5.664928404839f +  12.624792285877f*_Complex_I,
   -4.559435692794f +   5.128817112052f*_Complex_I,
    3.020061485600f +   2.317084746039f*_Complex_I,
    9.287256582183f +   1.097899941841f*_Complex_I,
    4.921470505274f +  -5.250097784974f*_Complex_I,
    5.775306053035f +   5.396588308077f*_Complex_I,
   -8.507611683876f +   0.041180219148f*_Complex_I,
    3.499272220645f +   8.240657702592f*_Complex_I,
    1.080399112219f +  -7.557152066173f*_Complex_I};

