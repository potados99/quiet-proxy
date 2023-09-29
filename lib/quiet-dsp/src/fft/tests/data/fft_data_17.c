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
// autotest fft data for 17-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x17[] = {
   -0.655587921776f +  -0.863886550358f*_Complex_I,
   -1.070139919529f +  -2.370656605854f*_Complex_I,
    1.167384281127f +   0.116747569575f*_Complex_I,
    1.105640858428f +  -1.226141009276f*_Complex_I,
   -0.349562744440f +  -0.005953723423f*_Complex_I,
    0.655312446998f +   1.594642817084f*_Complex_I,
   -0.230495501721f +  -0.272806523691f*_Complex_I,
    0.731764183318f +  -0.732380509571f*_Complex_I,
   -0.953609619255f +   1.102615917395f*_Complex_I,
   -0.496898865182f +  -1.822920499315f*_Complex_I,
   -2.052948327746f +  -0.382334768518f*_Complex_I,
    1.062783811112f +   0.673250838256f*_Complex_I,
   -0.142175503751f +   0.542432325176f*_Complex_I,
    1.108087524611f +  -0.029888173999f*_Complex_I,
   -0.164259605567f +  -1.184782100304f*_Complex_I,
   -0.236452649938f +  -0.998080495482f*_Complex_I,
   -0.197908967423f +  -0.229518503722f*_Complex_I};

liquid_float_complex fft_test_y17[] = {
   -0.719066520735f +  -6.089659996026f*_Complex_I,
    1.821427336790f +  -5.621144218242f*_Complex_I,
   -6.173678834923f +  -4.525807530343f*_Complex_I,
   -1.549626337288f +   0.314087328771f*_Complex_I,
   -5.136370472539f +   4.327372264632f*_Complex_I,
   -0.105170126419f +  -2.207231016009f*_Complex_I,
   -5.750228396460f +   3.094152945701f*_Complex_I,
    0.618725077794f +   3.278602823446f*_Complex_I,
   -0.888646366224f +  -3.887677672776f*_Complex_I,
    3.905822192802f +   7.933139073811f*_Complex_I,
   -1.522365359136f +   0.172605279098f*_Complex_I,
    8.552784050577f +  -3.105361200836f*_Complex_I,
   -1.598265822441f +  -5.532288727983f*_Complex_I,
    1.151099028128f +  -2.046469788513f*_Complex_I,
    0.253410312032f +   6.386316111258f*_Complex_I,
   -4.676752932337f +  -4.421634395132f*_Complex_I,
    0.671908500186f +  -2.755072636947f*_Complex_I};

