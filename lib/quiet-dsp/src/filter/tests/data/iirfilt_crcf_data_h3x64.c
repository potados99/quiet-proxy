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
// iirfilt_crcf_data_h3x64.c: autotest iirfilt data
//



#include "liquid.h"
#include "autotest/autotest.h"

float iirfilt_crcf_data_h3x64_b[] = {
    0.067455273889,
    0.134910547778,
    0.067455273889};

float iirfilt_crcf_data_h3x64_a[] = {
    1.000000000000,
   -1.142980502540,
    0.412801598096};

liquid_float_complex iirfilt_crcf_data_h3x64_x[] = {
    0.157714921372f +   0.096933651372f*_Complex_I,
    0.112931825396f +   0.063629523666f*_Complex_I,
    0.036350589338f +   0.126527528681f*_Complex_I,
   -0.131639758916f +   0.002850582881f*_Complex_I,
    0.124813993717f +  -0.161564813627f*_Complex_I,
    0.055810697081f +  -0.079984015750f*_Complex_I,
   -0.113597866433f +   0.059629208365f*_Complex_I,
   -0.081276130300f +  -0.032884892886f*_Complex_I,
    0.189206432747f +   0.151230084280f*_Complex_I,
    0.046653973791f +   0.039106242827f*_Complex_I,
    0.062707370238f +   0.114770667926f*_Complex_I,
   -0.005370634420f +  -0.115131667770f*_Complex_I,
   -0.042638922558f +  -0.133249195976f*_Complex_I,
   -0.036786574989f +  -0.119823837652f*_Complex_I,
    0.086588872188f +   0.012335566540f*_Complex_I,
    0.162897246678f +   0.076457627729f*_Complex_I,
   -0.046976140791f +   0.024454556465f*_Complex_I,
    0.037224871206f +   0.005544202178f*_Complex_I,
   -0.106866213474f +  -0.004556655371f*_Complex_I,
    0.112442348190f +  -0.043675611175f*_Complex_I,
   -0.139836308260f +  -0.165558641382f*_Complex_I,
   -0.124475577909f +   0.044150412760f*_Complex_I,
   -0.112036331740f +   0.092938383030f*_Complex_I,
    0.004665562144f +   0.077748113050f*_Complex_I,
   -0.016082143750f +  -0.159087937039f*_Complex_I,
   -0.122649745886f +   0.169674782967f*_Complex_I,
   -0.059903644318f +  -0.028174007533f*_Complex_I,
   -0.135926561418f +   0.161939672399f*_Complex_I,
    0.058515792150f +  -0.092207684338f*_Complex_I,
   -0.001328847093f +  -0.044399214544f*_Complex_I,
    0.148659720963f +  -0.189463417484f*_Complex_I,
   -0.026581782415f +   0.095051513873f*_Complex_I,
    0.031890698003f +  -0.042421129272f*_Complex_I,
   -0.122306862234f +   0.005962301978f*_Complex_I,
   -0.061265177784f +   0.106033789898f*_Complex_I,
    0.261292757319f +  -0.214947283935f*_Complex_I,
    0.103799428426f +   0.080318756697f*_Complex_I,
   -0.049679368664f +   0.150833170036f*_Complex_I,
    0.042691894941f +   0.069350178325f*_Complex_I,
   -0.046630189152f +  -0.062689469185f*_Complex_I,
   -0.012129146913f +   0.031853481774f*_Complex_I,
    0.020440626886f +   0.011527708526f*_Complex_I,
    0.048482096955f +   0.129990980549f*_Complex_I,
    0.042635428860f +  -0.223911417035f*_Complex_I,
   -0.010964205149f +  -0.143631009428f*_Complex_I,
    0.065181991532f +  -0.058004538996f*_Complex_I,
   -0.000090077953f +  -0.081470015783f*_Complex_I,
    0.011047855650f +   0.146709286197f*_Complex_I,
   -0.114534249385f +   0.131496385737f*_Complex_I,
    0.071234677078f +   0.077433138944f*_Complex_I,
    0.200723551597f +   0.001379408486f*_Complex_I,
   -0.026760201597f +   0.140751935283f*_Complex_I,
    0.047450662078f +  -0.024838330640f*_Complex_I,
    0.013847228689f +  -0.209058524164f*_Complex_I,
    0.093422613814f +   0.012081621105f*_Complex_I,
    0.136809870406f +  -0.145382142602f*_Complex_I,
    0.009187149051f +   0.116724633427f*_Complex_I,
    0.136993412455f +   0.031913868005f*_Complex_I,
    0.000837449944f +  -0.080964662247f*_Complex_I,
   -0.060279791907f +  -0.040256932738f*_Complex_I,
    0.037791227194f +  -0.030926237571f*_Complex_I,
   -0.041416454010f +  -0.072873679453f*_Complex_I,
   -0.022768793380f +  -0.030601437534f*_Complex_I,
    0.108180951121f +   0.069467116791f*_Complex_I};

liquid_float_complex iirfilt_crcf_data_h3x64_y[] = {
    0.010638703218f +   0.006538686002f*_Complex_I,
    0.041055083998f +   0.024843109564f*_Complex_I,
    0.070859923453f +   0.049353938820f*_Complex_I,
    0.067686035774f +   0.067709646463f*_Complex_I,
    0.041224538648f +   0.055038544970f*_Complex_I,
    0.030901594293f +   0.007957479174f*_Complex_I,
    0.026588402992f +  -0.031291537326f*_Complex_I,
    0.000590470547f +  -0.038619471159f*_Complex_I,
   -0.016165649635f +  -0.021437053514f*_Complex_I,
    0.004469726906f +   0.012262241589f*_Complex_I,
    0.035069044446f +   0.046083751239f*_Complex_I,
    0.049482788267f +   0.057966414042f*_Complex_I,
    0.042710472013f +   0.030452084359f*_Complex_I,
    0.019794496184f +  -0.022948199659f*_Complex_I,
    0.002995531001f +  -0.063121775432f*_Complex_I,
    0.015441215948f +  -0.063934986641f*_Complex_I,
    0.041061093206f +  -0.034223045125f*_Complex_I,
    0.047719585714f +  -0.003893175152f*_Complex_I,
    0.032237020788f +   0.011767694149f*_Complex_I,
    0.012826028856f +   0.011870448387f*_Complex_I,
   -0.000119320177f +  -0.008657506452f*_Complex_I,
   -0.025108083598f +  -0.037099080266f*_Complex_I,
   -0.062432000766f +  -0.037771955955f*_Complex_I,
   -0.084190602890f +  -0.007096982968f*_Complex_I,
   -0.078469021221f +   0.013507514859f*_Complex_I,
   -0.065062852144f +   0.013595810519f*_Complex_I,
   -0.063645820627f +   0.020222934773f*_Complex_I,
   -0.071411851802f +   0.036070220963f*_Complex_I,
   -0.073780802600f +   0.046606489405f*_Complex_I,
   -0.056215295888f +   0.033869398399f*_Complex_I,
   -0.020000348431f +  -0.005517294981f*_Complex_I,
    0.018518800909f +  -0.042431351088f*_Complex_I,
    0.038015719300f +  -0.049039042613f*_Complex_I,
    0.030065702572f +  -0.037444083204f*_Complex_I,
    0.000189612796f +  -0.017459075006f*_Complex_I,
   -0.011084433416f +  -0.004290467457f*_Complex_I,
    0.025372744806f +  -0.014124980335f*_Complex_I,
    0.061854301275f +  -0.007862452949f*_Complex_I,
    0.063403692253f +   0.027289128630f*_Complex_I,
    0.046198628950f +   0.049738403126f*_Complex_I,
    0.022401700824f +   0.043954279075f*_Complex_I,
    0.003130865455f +   0.030553031785f*_Complex_I,
   -0.000459085357f +   0.029249594984f*_Complex_I,
    0.008978406999f +   0.024030129591f*_Complex_I,
    0.018734404042f +  -0.015736413767f*_Complex_I,
    0.023500424489f +  -0.066300146201f*_Complex_I,
    0.027175003553f +  -0.092293433110f*_Complex_I,
    0.026489439187f +  -0.083128349690f*_Complex_I,
    0.012817484482f +  -0.033748033571f*_Complex_I,
   -0.006186235518f +   0.028602009338f*_Complex_I,
    0.003062407634f +   0.066032501481f*_Complex_I,
    0.036133722347f +   0.078570737258f*_Complex_I,
    0.053166399461f +   0.079952991289f*_Complex_I,
    0.051382646333f +   0.050991991806f*_Complex_I,
    0.048152970882f +  -0.003786577505f*_Complex_I,
    0.056593380224f +  -0.047656514100f*_Complex_I,
    0.070186171051f +  -0.063832284508f*_Complex_I,
    0.076568506010f +  -0.045193020750f*_Complex_I,
    0.077701414291f +  -0.018586956449f*_Complex_I,
    0.062491319025f +  -0.014074548285f*_Complex_I,
    0.033824419480f +  -0.021392925087f*_Complex_I,
    0.011102622655f +  -0.030445232324f*_Complex_I,
   -0.005846867304f +  -0.039949067467f*_Complex_I,
   -0.009834168653f +  -0.037451411970f*_Complex_I};

