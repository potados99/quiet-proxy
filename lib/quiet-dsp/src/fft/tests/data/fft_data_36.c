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
// autotest fft data for 36-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x36[] = {
   -0.515260084522f +   1.287529717076f*_Complex_I,
    0.587117158481f +  -0.148572876243f*_Complex_I,
   -0.782947562463f +   1.641852621518f*_Complex_I,
   -0.526927266439f +   0.584647073200f*_Complex_I,
   -1.531349139822f +  -1.069623628897f*_Complex_I,
    1.018192400002f +  -0.793147230271f*_Complex_I,
   -1.074504882712f +  -0.091149144200f*_Complex_I,
   -0.401657438434f +   0.004317962559f*_Complex_I,
    1.259620132258f +  -0.104377362194f*_Complex_I,
   -0.102194404981f +  -0.973411762169f*_Complex_I,
   -0.895434561911f +  -1.050093649832f*_Complex_I,
    1.026577410282f +   1.080478300358f*_Complex_I,
    0.691470386469f +  -0.436083438367f*_Complex_I,
   -0.230801075525f +   1.635643257519f*_Complex_I,
   -0.121589188789f +   0.070584124184f*_Complex_I,
    0.332245123083f +   0.603463018191f*_Complex_I,
    0.098342650657f +   0.713292188052f*_Complex_I,
   -0.653525164870f +   0.226711651388f*_Complex_I,
   -0.486468735347f +   0.247902880597f*_Complex_I,
   -0.092383856045f +   0.443156295025f*_Complex_I,
   -1.207432550343f +  -0.503252568552f*_Complex_I,
    0.680629730441f +   0.210743200774f*_Complex_I,
   -1.655855919610f +   0.985314552623f*_Complex_I,
   -0.635578415199f +   1.126805769525f*_Complex_I,
    0.429626094959f +  -0.591166406548f*_Complex_I,
    0.843172830682f +  -0.010918445865f*_Complex_I,
   -0.130407009132f +   0.920489918178f*_Complex_I,
    0.879595565427f +   0.076478701355f*_Complex_I,
    0.407356105015f +   0.244802856694f*_Complex_I,
   -0.247029167369f +   1.416537545584f*_Complex_I,
    0.001447109646f +  -0.855321598060f*_Complex_I,
   -1.005160244372f +   0.880697474487f*_Complex_I,
   -1.506889600501f +  -0.376866773437f*_Complex_I,
    0.595335431863f +   0.874899791600f*_Complex_I,
   -1.720946712489f +  -0.251050064927f*_Complex_I,
   -0.304668621370f +  -0.437688673914f*_Complex_I};

liquid_float_complex fft_test_y36[] = {
   -6.978283472983f +   7.583625277009f*_Complex_I,
   -6.674217696450f +  -3.304059977181f*_Complex_I,
   -9.133615960691f +   4.553754806959f*_Complex_I,
    7.138280833022f +  -0.461421293427f*_Complex_I,
    6.376807409683f +  -0.306551799085f*_Complex_I,
    2.594166782732f +   4.623935739453f*_Complex_I,
    2.991096252215f +  -1.709441742997f*_Complex_I,
    7.042547687256f +  -5.210100129931f*_Complex_I,
   -3.291195373643f +  -2.837550873581f*_Complex_I,
    3.068320668506f +  -5.673130538045f*_Complex_I,
    1.959771299385f +  -2.235257672510f*_Complex_I,
  -10.609066858652f +   0.928096828820f*_Complex_I,
    3.208839022246f +   0.484194748895f*_Complex_I,
    2.548602732505f +   9.743720342785f*_Complex_I,
    6.240917395617f +   6.571681544646f*_Complex_I,
   -4.101181674885f +   4.039956075121f*_Complex_I,
   -9.685452992487f +   0.380605286598f*_Complex_I,
   -3.555255829985f +   3.488301753752f*_Complex_I,
  -10.504163464296f +  -6.018056829194f*_Complex_I,
   -2.111740241301f +   1.705549685664f*_Complex_I,
    2.140088966360f +   7.541207884663f*_Complex_I,
    0.985036473018f +  -0.558056384811f*_Complex_I,
   -1.305685512500f +   8.210384283174f*_Complex_I,
    4.783233947768f +  -2.666144508286f*_Complex_I,
    6.484426654393f +  -5.252223925558f*_Complex_I,
   -2.313461997972f +   5.743487698749f*_Complex_I,
   -1.086778704978f +   8.029162089587f*_Complex_I,
    6.916062245443f +   0.764580425536f*_Complex_I,
   -2.415195588075f +  -0.073706064002f*_Complex_I,
   -5.346986333451f +  -3.512605491284f*_Complex_I,
   -0.924055660625f +   2.282174534826f*_Complex_I,
   -0.470350054245f +   2.031728408857f*_Complex_I,
    2.141016439694f +  -1.773104703203f*_Complex_I,
   -1.014341113192f +   7.641158118573f*_Complex_I,
   -4.249655466965f +   2.206889911886f*_Complex_I,
    0.602106144731f +  -0.611713697716f*_Complex_I};

