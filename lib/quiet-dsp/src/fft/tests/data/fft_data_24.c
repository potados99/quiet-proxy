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
// autotest fft data for 24-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x24[] = {
   -1.420307293620f +   0.936847943063f*_Complex_I,
   -0.496969771953f +   0.590714565032f*_Complex_I,
   -1.354677361467f +  -2.010032405560f*_Complex_I,
   -0.345483299359f +   0.404926987051f*_Complex_I,
    0.689486222452f +  -0.768259750193f*_Complex_I,
   -1.549641684121f +  -0.858118594125f*_Complex_I,
    0.420175234777f +  -0.280408837681f*_Complex_I,
   -2.217262854791f +  -0.375004631542f*_Complex_I,
   -1.198653374297f +   0.900261122326f*_Complex_I,
    0.329725819477f +   0.014746627154f*_Complex_I,
    0.045545673584f +  -0.712071131515f*_Complex_I,
   -0.495265874931f +  -0.922857927267f*_Complex_I,
    0.628733326629f +   0.643883091672f*_Complex_I,
    0.331696680042f +  -1.105791987558f*_Complex_I,
    0.515399107713f +  -0.438177945625f*_Complex_I,
    0.183533661425f +  -0.031372217136f*_Complex_I,
   -0.276753781687f +   0.187288341292f*_Complex_I,
    0.177067067896f +  -0.017072068523f*_Complex_I,
   -0.269294774259f +   0.299567125253f*_Complex_I,
    0.691280106543f +  -0.285429769347f*_Complex_I,
   -0.478959763653f +   0.592471601549f*_Complex_I,
    0.731469600041f +  -1.116061252131f*_Complex_I,
    0.506952261982f +  -1.310440154883f*_Complex_I,
   -0.131823537621f +   1.440176198054f*_Complex_I};

liquid_float_complex fft_test_y24[] = {
   -4.984028609200f +  -4.220215070640f*_Complex_I,
   -4.250507506099f +   6.724208699822f*_Complex_I,
    0.057360770043f +   0.512716211712f*_Complex_I,
   -3.908279516708f +   6.693724296623f*_Complex_I,
   -1.890450979255f +   6.088953815148f*_Complex_I,
   -1.373512942118f +   4.739496879303f*_Complex_I,
   -4.642576156472f +   5.105686189601f*_Complex_I,
   -2.584328440882f +   1.728098263528f*_Complex_I,
    0.744531943959f +   0.135606499920f*_Complex_I,
   -0.971959807211f +  -7.134164325953f*_Complex_I,
    0.738417588646f +  -0.940988007706f*_Complex_I,
   -0.528146358843f +  -0.272559882858f*_Complex_I,
    0.599319565507f +   0.302073070033f*_Complex_I,
   -3.856916042162f + -10.635041786616f*_Complex_I,
   -5.293262572847f +  -3.982011344991f*_Complex_I,
   -4.348687900619f +   2.460786763911f*_Complex_I,
    5.015153490569f +   6.700996972453f*_Complex_I,
    0.389766514080f +  -0.278393532462f*_Complex_I,
    0.801466543459f +   8.782425209839f*_Complex_I,
    3.623555226700f +  -0.026142755609f*_Complex_I,
   -3.328686450422f +   0.591920646925f*_Complex_I,
   -5.710969715584f +   4.204863120029f*_Complex_I,
    2.683867262111f +  -0.108391775481f*_Complex_I,
   -1.068500953539f +  -4.689297523031f*_Complex_I};

