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
// autotest fft data for 20-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x20[] = {
   -0.138174469322f +  -0.274748504122f*_Complex_I,
   -1.227476709426f +   0.905279873773f*_Complex_I,
   -0.940584818722f +  -0.463678927507f*_Complex_I,
   -0.327372793730f +   0.441537277752f*_Complex_I,
    0.086812488375f +   1.122322318862f*_Complex_I,
   -0.100645730164f +  -0.142102548176f*_Complex_I,
   -0.339607323410f +  -0.632982556339f*_Complex_I,
   -1.122342071583f +  -0.361529677196f*_Complex_I,
   -0.394764118785f +   1.317868322379f*_Complex_I,
    0.885025645922f +   0.277662260330f*_Complex_I,
   -0.937809434341f +  -0.464711897028f*_Complex_I,
   -0.316998490158f +   0.688777215432f*_Complex_I,
    0.649526607014f +   0.181558179235f*_Complex_I,
    0.780299241568f +  -0.070192359053f*_Complex_I,
    1.932600474030f +  -0.136400805574f*_Complex_I,
   -0.216121187682f +  -0.461249755715f*_Complex_I,
    0.926223942818f +  -0.028529590209f*_Complex_I,
    1.602135289481f +   1.434596371731f*_Complex_I,
    1.623836928491f +  -1.265873017618f*_Complex_I,
    1.568843067308f +  -0.364404259258f*_Complex_I};

liquid_float_complex fft_test_y20[] = {
    3.993406537683f +   1.703197921701f*_Complex_I,
    3.008874212687f +   7.663142996950f*_Complex_I,
   -1.159042365700f +   3.282695683450f*_Complex_I,
    0.903124379379f +   1.428002755716f*_Complex_I,
   -1.572075523393f +   4.283883169775f*_Complex_I,
    2.253301421641f +   2.928788716985f*_Complex_I,
    3.534976344610f +   2.383761115026f*_Complex_I,
    1.326813143543f +   3.111834244207f*_Complex_I,
   -3.988701280111f +  -0.677308408606f*_Complex_I,
   -1.984004176890f +  -4.401380983625f*_Complex_I,
    0.942714014611f +  -2.993550877540f*_Complex_I,
    2.448617718798f +  -1.195359461640f*_Complex_I,
   -3.328697057289f +  -4.221639306000f*_Complex_I,
    4.287827550431f +   1.139111429335f*_Complex_I,
   -4.013398939947f +  -0.677595378939f*_Complex_I,
   -2.670924173537f +   7.635447143438f*_Complex_I,
   -2.067686784436f +  -7.802196902076f*_Complex_I,
   -1.972088145081f +  -6.957222482710f*_Complex_I,
   -3.101333982661f +  -2.675851028288f*_Complex_I,
    0.394807719219f +  -9.452730429599f*_Complex_I};

