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
// autotest fft data for 157-point transform
//



#include "liquid.h"
#include "autotest/autotest.h"

liquid_float_complex fft_test_x157[] = {
    0.257182749425f +   0.221924222343f*_Complex_I,
    1.678933476985f +   1.690438801569f*_Complex_I,
   -0.370453539748f +  -0.279443271284f*_Complex_I,
   -0.425568170028f +  -0.346884537719f*_Complex_I,
    0.025131704106f +   0.368626953376f*_Complex_I,
   -0.013250700538f +   0.876875327290f*_Complex_I,
    0.935964221688f +  -0.003996500003f*_Complex_I,
    0.697482794970f +   0.169890786221f*_Complex_I,
   -0.672758751419f +  -0.529033743727f*_Complex_I,
   -0.103638614252f +   0.221443696028f*_Complex_I,
   -0.365208618659f +  -0.660189374984f*_Complex_I,
    0.148416173585f +  -0.919145673704f*_Complex_I,
   -0.015366679279f +  -0.943544155661f*_Complex_I,
    1.622323455798f +   0.481254671673f*_Complex_I,
   -0.438594792675f +   0.487727000762f*_Complex_I,
    1.590594341984f +  -0.549613288902f*_Complex_I,
   -0.917184623744f +  -2.221026339765f*_Complex_I,
   -1.617744928538f +   1.593484682047f*_Complex_I,
   -0.989508283152f +  -0.094108203222f*_Complex_I,
    0.852090994091f +  -2.231080010685f*_Complex_I,
   -0.400903430450f +  -0.366248303051f*_Complex_I,
   -0.125211983197f +  -1.455734382818f*_Complex_I,
    1.947225389836f +   0.980175860892f*_Complex_I,
   -1.398014729095f +   0.014318572276f*_Complex_I,
   -0.771114386583f +   0.544211573481f*_Complex_I,
    0.126434853618f +  -0.465319924891f*_Complex_I,
    0.952552119580f +   2.799409645314f*_Complex_I,
    0.745539772546f +   0.038782344125f*_Complex_I,
    0.629464449611f +  -1.544746925900f*_Complex_I,
   -1.430974620188f +  -1.148543279148f*_Complex_I,
   -0.550191215098f +  -1.044145048363f*_Complex_I,
   -0.616171694097f +  -1.252745889547f*_Complex_I,
    0.988808988108f +  -1.602725943935f*_Complex_I,
   -0.607710796313f +   0.518971475013f*_Complex_I,
    0.771090806997f +  -0.385515422626f*_Complex_I,
    0.825512088357f +   0.474459769075f*_Complex_I,
   -0.291745809631f +  -0.149808656805f*_Complex_I,
   -1.958415654055f +   0.651147959844f*_Complex_I,
   -0.778182389479f +  -0.780881485990f*_Complex_I,
   -2.015821535479f +  -0.050499463828f*_Complex_I,
    0.887353255055f +  -1.214230826942f*_Complex_I,
   -0.096317891587f +   0.761206139060f*_Complex_I,
   -1.062009284735f +  -0.271266211836f*_Complex_I,
    1.423990266183f +   1.335814455222f*_Complex_I,
   -0.847479948365f +   2.671530186606f*_Complex_I,
   -1.345728311726f +  -0.634481496676f*_Complex_I,
   -0.797816703427f +   0.502757855534f*_Complex_I,
   -0.464673266498f +   0.116721201943f*_Complex_I,
    0.203062847770f +   0.561494795746f*_Complex_I,
    0.033909266352f +  -0.261380019453f*_Complex_I,
   -0.658056423237f +   1.281296865326f*_Complex_I,
    0.941736081602f +   1.987602839317f*_Complex_I,
   -0.423846356775f +  -1.241587960307f*_Complex_I,
   -0.393324168712f +   0.737043249313f*_Complex_I,
   -1.944403782443f +  -0.943905358441f*_Complex_I,
   -0.528242253913f +   1.908236422266f*_Complex_I,
    1.452295322067f +  -0.869099055081f*_Complex_I,
   -1.120053624869f +   0.850800785935f*_Complex_I,
    0.365006117743f +  -0.347073388222f*_Complex_I,
   -1.980724188697f +   1.747266666168f*_Complex_I,
    1.558965406397f +   0.725116188824f*_Complex_I,
   -1.050340476177f +   0.477386287145f*_Complex_I,
    0.078299549695f +  -1.166209184146f*_Complex_I,
    0.666177598254f +  -1.881539760701f*_Complex_I,
   -0.553008717374f +   0.112063233224f*_Complex_I,
   -1.542438669400f +  -0.905459946121f*_Complex_I,
   -0.540183077595f +  -0.653405677927f*_Complex_I,
    0.093096056538f +   1.658838310544f*_Complex_I,
   -0.070743442866f +  -0.474238998458f*_Complex_I,
   -1.057268947675f +   0.965366634327f*_Complex_I,
   -0.084404481306f +   0.516458044167f*_Complex_I,
    0.415540467796f +  -0.571894574983f*_Complex_I,
   -0.495234089660f +   0.103235766156f*_Complex_I,
    0.464768365021f +   0.651070663181f*_Complex_I,
   -1.478301866530f +  -1.246265840883f*_Complex_I,
   -0.810080291321f +  -0.090687751615f*_Complex_I,
    1.597727768491f +  -1.303542260713f*_Complex_I,
    0.899193648643f +   0.101515082173f*_Complex_I,
   -1.275261212066f +  -1.670150745367f*_Complex_I,
   -0.067477528818f +   0.082676448878f*_Complex_I,
   -0.593487795772f +   1.015383261914f*_Complex_I,
   -0.195143706875f +   0.197795648282f*_Complex_I,
    1.470101318427f +  -1.090920995443f*_Complex_I,
    3.099635934834f +   0.418783664178f*_Complex_I,
    0.517928899798f +  -0.515604023095f*_Complex_I,
   -0.699637334030f +   0.411968031541f*_Complex_I,
    0.238527504044f +  -1.024932943805f*_Complex_I,
    1.067350706566f +  -1.185403362126f*_Complex_I,
    1.013271318338f +   0.881471326676f*_Complex_I,
    0.004430604182f +  -0.799775043761f*_Complex_I,
    0.351524389294f +   0.780435439706f*_Complex_I,
    0.106334238498f +   0.458736063427f*_Complex_I,
   -0.008723581305f +   2.334855897709f*_Complex_I,
   -0.486030470423f +  -0.237085023857f*_Complex_I,
   -0.752315645429f +   0.905584767839f*_Complex_I,
   -0.578103821311f +   1.125629982729f*_Complex_I,
   -0.948197773007f +  -0.457632138151f*_Complex_I,
    0.742229639059f +   0.271160961106f*_Complex_I,
   -0.773931821655f +  -0.314444247010f*_Complex_I,
   -1.490298210738f +   0.035980837847f*_Complex_I,
    0.199618338445f +   0.632691460449f*_Complex_I,
   -0.234261424994f +  -1.443456519632f*_Complex_I,
    0.463236279099f +   0.303140551137f*_Complex_I,
    0.292524617190f +  -0.043026971072f*_Complex_I,
    0.046692677937f +   1.116783220186f*_Complex_I,
   -1.861132210698f +   0.261380583838f*_Complex_I,
   -0.341148975896f +  -0.470343064889f*_Complex_I,
   -0.671470989909f +   0.007947245970f*_Complex_I,
   -0.534160841208f +  -0.124549058301f*_Complex_I,
    0.487094311512f +  -0.314353890072f*_Complex_I,
   -0.403442115448f +  -0.857412221358f*_Complex_I,
    1.085529198882f +  -0.386892824664f*_Complex_I,
    0.591555113309f +   0.384947041491f*_Complex_I,
   -0.516471791207f +  -0.646903850947f*_Complex_I,
   -0.216099520865f +   0.030923700983f*_Complex_I,
   -2.362722198570f +   2.187609191074f*_Complex_I,
   -2.996234948353f +   1.169329942024f*_Complex_I,
    0.398987017180f +   1.432369958192f*_Complex_I,
   -0.321543239403f +  -1.079202616493f*_Complex_I,
    0.155932087142f +   0.283226593654f*_Complex_I,
   -0.149566717019f +   2.000037448099f*_Complex_I,
   -0.505275327391f +  -0.592114971901f*_Complex_I,
    0.712863240336f +  -0.919212613392f*_Complex_I,
    2.561694455976f +  -0.315857229465f*_Complex_I,
   -0.401098664528f +  -1.414850199386f*_Complex_I,
    1.068811040362f +  -0.520713203914f*_Complex_I,
   -0.928756706401f +  -1.036472849545f*_Complex_I,
    0.731918541008f +   2.246056257734f*_Complex_I,
   -1.087622423230f +  -1.271134991425f*_Complex_I,
    0.747682565630f +   1.167376255945f*_Complex_I,
    0.823139516666f +   0.417274248065f*_Complex_I,
    0.488604293527f +  -0.768657162242f*_Complex_I,
   -1.566207330521f +  -0.520510590335f*_Complex_I,
    0.286432330277f +  -0.603250643993f*_Complex_I,
    0.685025047143f +  -0.939995698866f*_Complex_I,
    0.955471389243f +  -0.323428744209f*_Complex_I,
   -1.169027438782f +  -0.175653814544f*_Complex_I,
   -0.284005159687f +   0.460772145706f*_Complex_I,
   -0.310159212214f +  -1.720418494846f*_Complex_I,
    0.305232638909f +  -0.090314073904f*_Complex_I,
    0.190795117789f +  -0.467619419555f*_Complex_I,
   -0.905744042954f +  -1.143116395802f*_Complex_I,
    0.392128587570f +   2.286798561832f*_Complex_I,
   -1.315880319405f +  -1.432434182558f*_Complex_I,
    1.007683317172f +  -0.154461360928f*_Complex_I,
    0.474642520199f +   0.729416858430f*_Complex_I,
   -0.679375823140f +  -2.856682284668f*_Complex_I,
   -0.687426016158f +  -1.023213289303f*_Complex_I,
   -0.022785229613f +   0.698739170753f*_Complex_I,
   -0.643221050022f +   1.444057111513f*_Complex_I,
    0.149585673645f +  -0.602773170360f*_Complex_I,
    0.389853409146f +  -0.949003645210f*_Complex_I,
   -1.115251553217f +  -0.405311422912f*_Complex_I,
    0.228569355271f +  -0.486849085232f*_Complex_I,
   -0.140823347089f +  -0.328067722810f*_Complex_I,
    1.388787822068f +  -2.267147899079f*_Complex_I,
    0.939124099904f +  -0.563609820499f*_Complex_I};

liquid_float_complex fft_test_y157[] = {
  -13.721520175468f +  -9.568907767571f*_Complex_I,
    8.721468524756f + -10.198063416643f*_Complex_I,
   15.060716782723f + -14.846901712846f*_Complex_I,
  -11.623905596583f +  16.650835292293f*_Complex_I,
   19.695072317931f + -11.298461808236f*_Complex_I,
    1.838122765692f +   7.179001252206f*_Complex_I,
    8.145195639028f + -10.634659386087f*_Complex_I,
   13.033783220459f +  19.061682407788f*_Complex_I,
   -3.959970595745f +  -7.333783752376f*_Complex_I,
   17.086993536942f +  -6.079044767515f*_Complex_I,
   10.491053572778f +  -4.514192461667f*_Complex_I,
    6.064025221921f +  10.332579887094f*_Complex_I,
   -3.762638600928f +  10.624543304629f*_Complex_I,
   -1.847856432273f +  -8.006182372781f*_Complex_I,
   41.710087074031f +   2.242012124979f*_Complex_I,
    8.362552928082f +  -0.431571425998f*_Complex_I,
   -2.684280607792f + -19.646530227003f*_Complex_I,
   -5.355855356382f +  -4.457469415514f*_Complex_I,
   -7.411106913072f +  24.950544746191f*_Complex_I,
   16.058416814462f +   7.398904353701f*_Complex_I,
    4.287192732400f + -11.227843680234f*_Complex_I,
   -1.117925486982f +  24.330611594547f*_Complex_I,
    3.444591991920f +  32.326680862100f*_Complex_I,
   17.351475510592f +  -7.023399927552f*_Complex_I,
   -0.243462815765f +   5.525094059061f*_Complex_I,
    1.824464191173f + -10.437625350692f*_Complex_I,
    0.863195259259f +   8.286510583962f*_Complex_I,
   -2.958971801726f + -14.975362935027f*_Complex_I,
    9.706578069666f +   2.274491450388f*_Complex_I,
   18.904225667531f +   9.156322125243f*_Complex_I,
    1.847919083204f +  22.188095024380f*_Complex_I,
   -4.136288117963f + -22.092021747680f*_Complex_I,
    4.703234992916f +   0.532501901615f*_Complex_I,
   -3.030532632664f + -11.313921121067f*_Complex_I,
    1.091146775351f +   7.577427645200f*_Complex_I,
    3.975634530789f +  10.604839429746f*_Complex_I,
   12.752600166339f +   7.600696307234f*_Complex_I,
   15.977675567158f +  16.362460714763f*_Complex_I,
   -0.020172843559f +   3.858168994446f*_Complex_I,
  -14.397449821557f +  12.915383581435f*_Complex_I,
   15.101543348628f + -23.907576345828f*_Complex_I,
   -1.954273280892f +  13.597214533352f*_Complex_I,
   -8.025138226552f +   3.693906127107f*_Complex_I,
  -10.663001711599f +  11.720999651550f*_Complex_I,
   -1.917368345264f + -19.036649221044f*_Complex_I,
    4.152821868650f +  -8.488773546805f*_Complex_I,
  -24.343188706355f + -10.538612575861f*_Complex_I,
   12.414685926300f +  16.068084980361f*_Complex_I,
    2.673733474235f +  -8.293379374130f*_Complex_I,
    9.339757855123f +   0.779105093141f*_Complex_I,
   34.385020257627f +  -8.910778839680f*_Complex_I,
   13.686080719584f +  -2.468581114278f*_Complex_I,
   -0.105352104096f +  -7.123485160682f*_Complex_I,
  -26.981218401390f +  13.727259016390f*_Complex_I,
   -6.504207057579f +   3.268522185903f*_Complex_I,
    7.577558748754f +   2.965812787302f*_Complex_I,
  -22.926267985360f +   4.630017422388f*_Complex_I,
   -8.347022143339f +   1.975527870103f*_Complex_I,
    3.060029390078f + -21.656262254959f*_Complex_I,
    9.637126253972f +  -7.538708825218f*_Complex_I,
  -13.130853679756f + -18.805264312027f*_Complex_I,
  -16.821204438708f +   4.950740394033f*_Complex_I,
   22.988677066759f +  -1.571260161915f*_Complex_I,
    1.406205876954f +  12.062599478139f*_Complex_I,
  -28.514716646160f +   7.993271146497f*_Complex_I,
   -0.907689305572f +   0.456303536916f*_Complex_I,
   -3.571030267866f +  -4.518597998420f*_Complex_I,
  -11.957457146313f + -19.766437913007f*_Complex_I,
   -5.413654003898f +  -1.754632161022f*_Complex_I,
   -9.175989023330f +  -7.046783981905f*_Complex_I,
   -4.258428526498f + -16.319730685668f*_Complex_I,
   -8.132160224937f +  -1.537755723079f*_Complex_I,
   15.156793468505f +  10.343087291076f*_Complex_I,
   25.761505476002f +   3.887909686471f*_Complex_I,
   21.853951697775f + -12.770771455381f*_Complex_I,
  -14.242421455518f +   2.407693112009f*_Complex_I,
  -13.467445303389f + -29.036488998230f*_Complex_I,
   -9.305071893547f +   2.506212475888f*_Complex_I,
   22.323867850705f +  -4.075769716056f*_Complex_I,
   -5.679643000649f +  -3.670620943265f*_Complex_I,
  -13.769169134408f +  13.834529429033f*_Complex_I,
  -12.414956903750f + -16.194735699494f*_Complex_I,
   -2.005403979995f + -11.362528318332f*_Complex_I,
    7.730155179299f +   9.255875770335f*_Complex_I,
   15.051941677947f +  -3.828126836044f*_Complex_I,
  -21.086873877673f +  12.717384691065f*_Complex_I,
   22.428970474249f +  14.741806815196f*_Complex_I,
    2.480130753861f + -23.039122194478f*_Complex_I,
  -10.903771391849f + -13.412743738585f*_Complex_I,
    6.147006915635f +  13.690721935985f*_Complex_I,
  -20.616357511746f + -17.845769868478f*_Complex_I,
   -8.402987902554f +   3.410410123270f*_Complex_I,
   10.582061652995f +   4.348210154826f*_Complex_I,
   15.024788596168f +  -5.782083339001f*_Complex_I,
    8.689851678442f +  35.535383742654f*_Complex_I,
   -4.132601952228f +  -0.321739745032f*_Complex_I,
  -19.197163106392f +   3.413027621621f*_Complex_I,
   -5.794327856223f +  -7.331102283615f*_Complex_I,
   -6.543417534351f +  -1.677934031582f*_Complex_I,
    7.329352169488f +  -4.324029036611f*_Complex_I,
  -25.477673544286f + -10.789721951286f*_Complex_I,
   -0.912644707297f +  -9.637940446228f*_Complex_I,
    4.037691841333f +   3.096945310047f*_Complex_I,
   -5.847674330905f +  13.938407689472f*_Complex_I,
   10.812159378022f +   2.497873869651f*_Complex_I,
    5.034733833406f +  20.614345199846f*_Complex_I,
    9.197163204775f +   3.499527690970f*_Complex_I,
  -11.061382406800f +   3.269075618163f*_Complex_I,
   -2.869327440190f + -17.824719429904f*_Complex_I,
  -16.473833296088f +  -7.487202778068f*_Complex_I,
    6.310496423938f +   5.004751989728f*_Complex_I,
   -6.079010956757f +  18.024756582815f*_Complex_I,
   -4.356220575254f +  -2.205381751597f*_Complex_I,
   -8.493558121870f +  -3.869308590719f*_Complex_I,
    7.159973070917f +   6.849733506562f*_Complex_I,
   17.405411913875f +  -3.643915205170f*_Complex_I,
    1.342183355448f +   0.252403128806f*_Complex_I,
    2.470554720768f +   3.325864954849f*_Complex_I,
    3.304540368971f +  -7.701906570289f*_Complex_I,
  -41.203455184368f +  12.817592975767f*_Complex_I,
  -20.058954711820f +  19.878752053751f*_Complex_I,
    9.046175416813f +  11.732938261288f*_Complex_I,
   -0.786044861883f +  17.615815760165f*_Complex_I,
   -3.027566374297f +  11.824558467687f*_Complex_I,
   -3.793394817088f +   4.309384254386f*_Complex_I,
  -15.395453276032f +  -6.476272377854f*_Complex_I,
    2.993318695808f +  20.818567190739f*_Complex_I,
  -21.109827170023f + -18.433989642597f*_Complex_I,
   -7.427193578999f +  -4.496310454720f*_Complex_I,
   13.462176439125f + -14.456554646582f*_Complex_I,
    2.860309865551f +   0.813195406900f*_Complex_I,
  -16.705039250487f +   5.416257334069f*_Complex_I,
   12.149530796231f +   5.677739145239f*_Complex_I,
   10.883522142352f +  -2.048976821145f*_Complex_I,
   33.919769198703f +  14.546697989253f*_Complex_I,
   -0.080428049883f +  -5.729314964055f*_Complex_I,
   -1.382967825489f +  -0.843240827862f*_Complex_I,
  -14.258739687335f +  -4.164415134916f*_Complex_I,
  -11.232537602109f +  13.450368521399f*_Complex_I,
    6.475674985073f +  -6.229640995099f*_Complex_I,
    9.211806090883f +  -7.267971548561f*_Complex_I,
  -14.365301190661f +   8.987964911736f*_Complex_I,
  -11.266093935597f + -15.954781116216f*_Complex_I,
  -18.499836430748f +  -8.923649916614f*_Complex_I,
   31.090884321227f +   2.260100309627f*_Complex_I,
   -7.383545212516f +  10.553116472713f*_Complex_I,
    1.165337529929f +  -1.083672004639f*_Complex_I,
    1.026784219611f + -16.203749347621f*_Complex_I,
   -0.529416311921f +  -8.707703034115f*_Complex_I,
   -9.657893357311f +  12.096083541637f*_Complex_I,
  -15.285477594802f +   4.224467463110f*_Complex_I,
   16.595393096965f +   1.232758856522f*_Complex_I,
   10.380238903621f +  -5.473695910884f*_Complex_I,
   -5.199124871644f +  14.427071924858f*_Complex_I,
  -10.919624558299f +  16.105413828801f*_Complex_I,
   15.081167155045f +  -6.737986374676f*_Complex_I,
    5.602666437487f + -19.846630500695f*_Complex_I};

