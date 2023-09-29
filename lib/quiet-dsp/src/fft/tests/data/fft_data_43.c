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
// autotest fft data for 43-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x43[] = {
    0.086214736594f +  -0.374055466225f*_Complex_I,
   -0.398326405553f +   0.064437628903f*_Complex_I,
   -0.086828498048f +  -1.377541893939f*_Complex_I,
   -0.014057206023f +  -1.721581520365f*_Complex_I,
   -1.130661886812f +  -0.823144321334f*_Complex_I,
    0.265330564080f +  -2.139333421737f*_Complex_I,
    0.987278886883f +   0.510016610694f*_Complex_I,
    1.388439583820f +  -0.312226254937f*_Complex_I,
    1.314187441787f +   2.179164255828f*_Complex_I,
   -0.134438842798f +  -2.204082595282f*_Complex_I,
    0.245609009336f +   0.112479617279f*_Complex_I,
   -1.038607185161f +   0.772906423002f*_Complex_I,
    0.816938259734f +  -2.090685529624f*_Complex_I,
    0.975237183551f +  -0.563625353818f*_Complex_I,
   -0.941942184460f +   1.392834491457f*_Complex_I,
    1.369305972621f +   0.035788913101f*_Complex_I,
    0.274358812513f +   0.334025802789f*_Complex_I,
   -0.187955769606f +   0.806622195637f*_Complex_I,
   -0.435359111927f +   0.395863170294f*_Complex_I,
   -1.059982565487f +  -1.108626336147f*_Complex_I,
   -0.085915350568f +  -0.294840267490f*_Complex_I,
   -0.202754288995f +  -0.413065083074f*_Complex_I,
   -0.607968226502f +   1.253761902790f*_Complex_I,
    2.921829936105f +   1.400641655759f*_Complex_I,
    0.493898754300f +   2.597915340403f*_Complex_I,
   -0.939016287203f +   0.999025234458f*_Complex_I,
   -1.213828533796f +  -0.093371812474f*_Complex_I,
    0.049357784794f +  -1.117710210403f*_Complex_I,
    0.291427701377f +   0.619473850471f*_Complex_I,
   -0.297284045241f +   1.471963630624f*_Complex_I,
   -1.204828141785f +   0.357668469775f*_Complex_I,
    1.214147177406f +  -1.053652949447f*_Complex_I,
   -0.669099873019f +   0.645208133613f*_Complex_I,
   -0.669325749409f +   1.526826939113f*_Complex_I,
    1.388489801757f +  -0.663313867864f*_Complex_I,
    1.528893702905f +  -0.300643090523f*_Complex_I,
    0.969651597440f +   0.887262607328f*_Complex_I,
    0.961949407503f +  -1.302265834141f*_Complex_I,
    0.025366344758f +   1.938755581562f*_Complex_I,
    0.012954685257f +  -0.117840651513f*_Complex_I,
    0.422317736906f +   0.454593332125f*_Complex_I,
   -1.225108444904f +  -0.762684444639f*_Complex_I,
    0.510768457794f +   0.200474501150f*_Complex_I};

liquid_float_complex fft_test_y43[] = {
    5.970664941924f +   2.123419383178f*_Complex_I,
   -4.826258373494f + -10.530035821412f*_Complex_I,
   -6.840438649504f +   2.195697396144f*_Complex_I,
  -15.037444321130f +  -0.498694877295f*_Complex_I,
   -2.324178679783f +  -5.588631770237f*_Complex_I,
   -9.817989632278f +   8.215797271526f*_Complex_I,
   19.440508234356f +   0.725796090385f*_Complex_I,
   -0.273833848905f +   4.924507895251f*_Complex_I,
    5.898110303453f +  -7.584923619025f*_Complex_I,
   -1.491058783404f +   7.983518326557f*_Complex_I,
   -7.459786425320f +  -5.471409031844f*_Complex_I,
    9.458054840383f +  -1.411338639410f*_Complex_I,
   -7.652963176561f +  16.470882260110f*_Complex_I,
    4.933008347551f +   1.752692467372f*_Complex_I,
    3.158349989133f + -10.520004874496f*_Complex_I,
    3.461440707146f +  -1.053485004255f*_Complex_I,
    0.403169282390f +  15.216737475743f*_Complex_I,
   11.005277294499f +   0.924950795722f*_Complex_I,
   -2.459303339406f +  -4.952009870945f*_Complex_I,
  -11.998504221115f +  -4.269332241730f*_Complex_I,
  -10.575401537817f +   0.521491539120f*_Complex_I,
   -8.612771844559f +  -4.765648940500f*_Complex_I,
    7.802134874811f +   3.882271887067f*_Complex_I,
    2.664085789892f +  -5.430064274009f*_Complex_I,
    7.012256247961f +  -6.119235310609f*_Complex_I,
   -0.520208603756f +  -0.845655711277f*_Complex_I,
    0.308220700989f +   3.533138362895f*_Complex_I,
  -10.811305738786f +  -4.238039944052f*_Complex_I,
    6.001274292511f +  -2.592573440494f*_Complex_I,
    5.544361033380f + -11.920579663414f*_Complex_I,
   -2.095258565391f +   0.336151200781f*_Complex_I,
   -5.596706630782f +   7.291207810674f*_Complex_I,
    9.325757124002f +  -3.598787999557f*_Complex_I,
    1.133897756930f +  -1.612056679027f*_Complex_I,
   -2.012305507947f +   5.032886593926f*_Complex_I,
  -10.072407904704f +   5.354603355501f*_Complex_I,
    2.641399130952f +  -1.713592877295f*_Complex_I,
    1.128116547129f +   7.394974387525f*_Complex_I,
   12.210114373933f +  -3.041200993402f*_Complex_I,
   -0.850951175674f +   3.946134783722f*_Complex_I,
   -1.686631417770f +  -4.776809881210f*_Complex_I,
   -2.550902604765f +  -2.082230855079f*_Complex_I,
    9.773642843061f +  -9.294902010297f*_Complex_I};

