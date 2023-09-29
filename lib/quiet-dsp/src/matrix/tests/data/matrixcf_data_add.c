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
// data for testing matrix addition
//



#include "liquid.h"
#include "autotest/autotest.h"

// matrixcf_data_add_x [size: 5 x 4]
liquid_float_complex matrixcf_data_add_x[] = {
    1.366575479507f +  -1.463535666466f*_Complex_I /* ( 0, 0) */,
    1.982354640961f +   0.090445250273f*_Complex_I /* ( 0, 1) */,
    0.913504719734f +  -0.689249753952f*_Complex_I /* ( 0, 2) */,
    0.671039104462f +  -0.184951126575f*_Complex_I /* ( 0, 3) */,
    0.264611721039f +   0.204716682434f*_Complex_I /* ( 1, 0) */,
    0.995791137218f +  -0.192152589560f*_Complex_I /* ( 1, 1) */,
   -1.983934879303f +  -0.306251227856f*_Complex_I /* ( 1, 2) */,
   -0.375840932131f +  -0.751154422760f*_Complex_I /* ( 1, 3) */,
    0.245937779546f +  -0.470900952816f*_Complex_I /* ( 2, 0) */,
   -0.343152791262f +   1.205224752426f*_Complex_I /* ( 2, 1) */,
   -0.143777698278f +  -0.457689523697f*_Complex_I /* ( 2, 2) */,
   -1.387172579765f +   0.225333094597f*_Complex_I /* ( 2, 3) */,
    0.781192481518f +  -1.102205991745f*_Complex_I /* ( 3, 0) */,
    1.444583415985f +   0.660028517246f*_Complex_I /* ( 3, 1) */,
    0.043851174414f +   0.049496211112f*_Complex_I /* ( 3, 2) */,
    0.399744838476f +  -1.435891628265f*_Complex_I /* ( 3, 3) */,
   -0.488068610430f +  -0.211131110787f*_Complex_I /* ( 4, 0) */,
    0.573721885681f +   0.016210200265f*_Complex_I /* ( 4, 1) */,
   -1.381630182266f +  -0.026558181271f*_Complex_I /* ( 4, 2) */,
   -0.176615595818f +  -0.414863616228f*_Complex_I /* ( 4, 3) */};

// matrixcf_data_add_y [size: 5 x 4]
liquid_float_complex matrixcf_data_add_y[] = {
   -0.345586329699f +   0.240964725614f*_Complex_I /* ( 0, 0) */,
   -0.025732314214f +   1.212726473808f*_Complex_I /* ( 0, 1) */,
    0.907316803932f +   1.614625453949f*_Complex_I /* ( 0, 2) */,
   -1.277831077576f +  -0.193561494350f*_Complex_I /* ( 0, 3) */,
   -0.566267848015f +  -0.477513909340f*_Complex_I /* ( 1, 0) */,
   -0.220387980342f +   0.152425482869f*_Complex_I /* ( 1, 1) */,
    1.062286615372f +  -1.132043361664f*_Complex_I /* ( 1, 2) */,
    0.560977220535f +  -0.981467425823f*_Complex_I /* ( 1, 3) */,
    0.025816366076f +  -0.697246491909f*_Complex_I /* ( 2, 0) */,
    0.658244788647f +  -1.403432965279f*_Complex_I /* ( 2, 1) */,
   -1.326129436493f +  -0.529069602489f*_Complex_I /* ( 2, 2) */,
   -1.535833358765f +  -1.406206607819f*_Complex_I /* ( 2, 3) */,
    0.101660177112f +  -1.552777647972f*_Complex_I /* ( 3, 0) */,
    1.834807038307f +   0.647780478001f*_Complex_I /* ( 3, 1) */,
   -0.620168924332f +  -0.103246472776f*_Complex_I /* ( 3, 2) */,
   -0.063054643571f +  -0.756766498089f*_Complex_I /* ( 3, 3) */,
    0.280569136143f +   0.560459613800f*_Complex_I /* ( 4, 0) */,
   -0.069713011384f +  -0.971132814884f*_Complex_I /* ( 4, 1) */,
    0.225165605545f +  -1.117488980293f*_Complex_I /* ( 4, 2) */,
   -0.290932357311f +   0.302335798740f*_Complex_I /* ( 4, 3) */};

// matrixcf_data_add_z [size: 5 x 4]
liquid_float_complex matrixcf_data_add_z[] = {
    1.020989149809f +  -1.222570940852f*_Complex_I /* ( 0, 0) */,
    1.956622326747f +   1.303171724081f*_Complex_I /* ( 0, 1) */,
    1.820821523666f +   0.925375699997f*_Complex_I /* ( 0, 2) */,
   -0.606791973114f +  -0.378512620926f*_Complex_I /* ( 0, 3) */,
   -0.301656126976f +  -0.272797226906f*_Complex_I /* ( 1, 0) */,
    0.775403156877f +  -0.039727106690f*_Complex_I /* ( 1, 1) */,
   -0.921648263931f +  -1.438294589520f*_Complex_I /* ( 1, 2) */,
    0.185136288404f +  -1.732621848583f*_Complex_I /* ( 1, 3) */,
    0.271754145622f +  -1.168147444725f*_Complex_I /* ( 2, 0) */,
    0.315091997385f +  -0.198208212852f*_Complex_I /* ( 2, 1) */,
   -1.469907134771f +  -0.986759126186f*_Complex_I /* ( 2, 2) */,
   -2.923005938530f +  -1.180873513222f*_Complex_I /* ( 2, 3) */,
    0.882852658629f +  -2.654983639717f*_Complex_I /* ( 3, 0) */,
    3.279390454292f +   1.307808995247f*_Complex_I /* ( 3, 1) */,
   -0.576317749918f +  -0.053750261664f*_Complex_I /* ( 3, 2) */,
    0.336690194905f +  -2.192658126354f*_Complex_I /* ( 3, 3) */,
   -0.207499474287f +   0.349328503013f*_Complex_I /* ( 4, 0) */,
    0.504008874297f +  -0.954922614619f*_Complex_I /* ( 4, 1) */,
   -1.156464576721f +  -1.144047161564f*_Complex_I /* ( 4, 2) */,
   -0.467547953129f +  -0.112527817488f*_Complex_I /* ( 4, 3) */};

