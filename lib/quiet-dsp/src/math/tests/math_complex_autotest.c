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

#include "autotest/autotest.h"
#include "liquid.internal.h"

// 
// AUTOTEST: cexpf
//
void autotest_cexpf()
{
    float tol = 1e-3f;

    unsigned int n = 32;
    liquid_float_complex z[32] = {
        2.721502e+00f+_Complex_I* -8.449366e-01f,   2.264794e+00f+_Complex_I*  2.387520e+00f,
        3.293179e+00f+_Complex_I* -2.419589e+00f,  -1.318218e+00f+_Complex_I*  2.145837e+00f,
       -1.777802e+00f+_Complex_I*  4.317598e-01f,  -1.808236e-01f+_Complex_I*  1.030967e+00f,
       -1.081724e+00f+_Complex_I*  1.072073e-01f,   3.617838e+00f+_Complex_I*  3.329561e+00f,
        1.085694e+00f+_Complex_I*  1.738376e+00f,  -2.867179e+00f+_Complex_I*  8.557510e-01f,
       -3.869596e+00f+_Complex_I* -2.056906e+00f,  -2.902147e+00f+_Complex_I*  2.433414e+00f,
       -2.746567e+00f+_Complex_I* -7.924449e-01f,  -2.961677e+00f+_Complex_I* -3.129529e+00f,
        3.991396e+00f+_Complex_I* -2.253945e+00f,   1.034594e-01f+_Complex_I*  2.712898e+00f,
        9.011188e-01f+_Complex_I* -1.631747e+00f,   1.100418e+00f+_Complex_I*  1.942973e-01f,
       -5.133605e-02f+_Complex_I*  3.782200e+00f,  -1.659866e+00f+_Complex_I*  2.170862e+00f,
        2.139597e-01f+_Complex_I*  2.159311e+00f,  -7.981710e-01f+_Complex_I*  3.132236e+00f,
       -1.733482e+00f+_Complex_I* -1.180333e+00f,   2.461796e+00f+_Complex_I*  3.352212e+00f,
       -3.441958e+00f+_Complex_I*  3.594616e+00f,   2.079630e-01f+_Complex_I* -3.311553e+00f,
       -2.462289e+00f+_Complex_I*  1.305815e+00f,   3.121861e+00f+_Complex_I* -1.208857e+00f,
       -3.486629e+00f+_Complex_I* -3.839816e+00f,  -3.383861e-01f+_Complex_I* -3.495233e+00f,
       -2.093760e+00f+_Complex_I*  3.765073e+00f,   3.217665e+00f+_Complex_I*  2.807358e+00f };

    liquid_float_complex test[32] = {
        1.009152e+01f+_Complex_I* -1.137087e+01f,  -7.018747e+00f+_Complex_I*  6.592232e+00f,
       -2.020926e+01f+_Complex_I* -1.779666e+01f,  -1.455457e-01f+_Complex_I*  2.245718e-01f,
        1.534993e-01f+_Complex_I*  7.072523e-02f,   4.289666e-01f+_Complex_I*  7.159020e-01f,
        3.370642e-01f+_Complex_I*  3.627482e-02f,  -3.660068e+01f+_Complex_I* -6.961947e+00f,
       -4.939656e-01f+_Complex_I*  2.920008e+00f,   3.727975e-02f+_Complex_I*  4.293222e-02f,
       -9.748754e-03f+_Complex_I* -1.844954e-02f,  -4.170312e-02f+_Complex_I*  3.571317e-02f,
        4.503850e-02f+_Complex_I* -4.567777e-02f,  -5.172835e-02f+_Complex_I* -6.240385e-04f,
       -3.416917e+01f+_Complex_I* -4.198295e+01f,  -1.008646e+00f+_Complex_I*  4.609940e-01f,
       -1.499894e-01f+_Complex_I* -2.457784e+00f,   2.948871e+00f+_Complex_I*  5.802783e-01f,
       -7.616135e-01f+_Complex_I* -5.677744e-01f,  -1.073852e-01f+_Complex_I*  1.569425e-01f,
       -6.875640e-01f+_Complex_I*  1.030203e+00f,  -4.501318e-01f+_Complex_I*  4.212064e-03f,
        6.724286e-02f+_Complex_I* -1.633708e-01f,  -1.146673e+01f+_Complex_I* -2.451473e+00f,
       -2.877386e-02f+_Complex_I* -1.400682e-02f,  -1.213428e+00f+_Complex_I*  2.082440e-01f,
        2.232348e-02f+_Complex_I*  8.226451e-02f,   8.033771e+00f+_Complex_I* -2.121861e+01f,
       -2.344211e-02f+_Complex_I*  1.967391e-02f,  -6.688032e-01f+_Complex_I*  2.468952e-01f,
       -1.000387e-01f+_Complex_I* -7.194542e-02f,  -2.358796e+01f+_Complex_I*  8.191224e+00f };

    unsigned int i;
    for (i=0; i<n; i++) {
        liquid_float_complex t = liquid_cexpf(z[i]);

        CONTEND_DELTA(crealf(t), crealf(test[i]), tol);
        CONTEND_DELTA(cimagf(t), cimagf(test[i]), tol);
    }
}


// 
// AUTOTEST: clogf
//
void autotest_clogf()
{
    float tol = 1e-3f;

    unsigned int n = 32;
    liquid_float_complex z[32] = {
        2.7215e+00f+_Complex_I* -8.4494e-01f,   2.2648e+00f+_Complex_I*  2.3875e+00f,
        3.2932e+00f+_Complex_I* -2.4196e+00f,  -1.3182e+00f+_Complex_I*  2.1458e+00f,
       -1.7778e+00f+_Complex_I*  4.3176e-01f,  -1.8082e-01f+_Complex_I*  1.0310e+00f,
       -1.0817e+00f+_Complex_I*  1.0721e-01f,   3.6178e+00f+_Complex_I*  3.3296e+00f,
        1.0857e+00f+_Complex_I*  1.7384e+00f,  -2.8672e+00f+_Complex_I*  8.5575e-01f,
       -3.8696e+00f+_Complex_I* -2.0569e+00f,  -2.9021e+00f+_Complex_I*  2.4334e+00f,
       -2.7466e+00f+_Complex_I* -7.9244e-01f,  -2.9617e+00f+_Complex_I* -3.1295e+00f,
        3.9914e+00f+_Complex_I* -2.2539e+00f,   1.0346e-01f+_Complex_I*  2.7129e+00f,
        9.0112e-01f+_Complex_I* -1.6317e+00f,   1.1004e+00f+_Complex_I*  1.9430e-01f,
       -5.1336e-02f+_Complex_I*  3.7822e+00f,  -1.6599e+00f+_Complex_I*  2.1709e+00f,
        2.1396e-01f+_Complex_I*  2.1593e+00f,  -7.9817e-01f+_Complex_I*  3.1322e+00f,
       -1.7335e+00f+_Complex_I* -1.1803e+00f,   2.4618e+00f+_Complex_I*  3.3522e+00f,
       -3.4420e+00f+_Complex_I*  3.5946e+00f,   2.0796e-01f+_Complex_I* -3.3116e+00f,
       -2.4623e+00f+_Complex_I*  1.3058e+00f,   3.1219e+00f+_Complex_I* -1.2089e+00f,
       -3.4866e+00f+_Complex_I* -3.8398e+00f,  -3.3839e-01f+_Complex_I* -3.4952e+00f,
       -2.0938e+00f+_Complex_I*  3.7651e+00f,   3.2177e+00f+_Complex_I*  2.8074e+00f};

    liquid_float_complex test[32] = {
        1.0472e+00f+_Complex_I* -3.0103e-01f,   1.1911e+00f+_Complex_I*  8.1177e-01f,
        1.4077e+00f+_Complex_I* -6.3365e-01f,   9.2362e-01f+_Complex_I*  2.1217e+00f,
        6.0403e-01f+_Complex_I*  2.9033e+00f,   4.5647e-02f+_Complex_I*  1.7444e+00f,
        8.3443e-02f+_Complex_I*  3.0428e+00f,   1.5927e+00f+_Complex_I*  7.4393e-01f,
        7.1762e-01f+_Complex_I*  1.0125e+00f,   1.0960e+00f+_Complex_I*  2.8515e+00f,
        1.4776e+00f+_Complex_I* -2.6530e+00f,   1.3317e+00f+_Complex_I*  2.4438e+00f,
        1.0503e+00f+_Complex_I* -2.8607e+00f,   1.4607e+00f+_Complex_I* -2.3286e+00f,
        1.5225e+00f+_Complex_I* -5.1406e-01f,   9.9874e-01f+_Complex_I*  1.5327e+00f,
        6.2274e-01f+_Complex_I* -1.0662e+00f,   1.1104e-01f+_Complex_I*  1.7477e-01f,
        1.3304e+00f+_Complex_I*  1.5844e+00f,   1.0053e+00f+_Complex_I*  2.2236e+00f,
        7.7467e-01f+_Complex_I*  1.4720e+00f,   1.1732e+00f+_Complex_I*  1.8203e+00f,
        7.4059e-01f+_Complex_I* -2.5438e+00f,   1.4253e+00f+_Complex_I*  9.3737e-01f,
        1.6048e+00f+_Complex_I*  2.3345e+00f,   1.1994e+00f+_Complex_I* -1.5081e+00f,
        1.0250e+00f+_Complex_I*  2.6540e+00f,   1.2083e+00f+_Complex_I* -3.6944e-01f,
        1.6461e+00f+_Complex_I* -2.3080e+00f,   1.2561e+00f+_Complex_I* -1.6673e+00f,
        1.4605e+00f+_Complex_I*  2.0783e+00f,   1.4517e+00f+_Complex_I*  7.1740e-01f};

    unsigned int i;
    for (i=0; i<n; i++) {
        liquid_float_complex t = liquid_clogf(z[i]);

        CONTEND_DELTA(crealf(t), crealf(test[i]), tol);
        CONTEND_DELTA(cimagf(t), cimagf(test[i]), tol);
    }
}

// 
// AUTOTEST: csqrtf
//
void autotest_csqrtf()
{
    float tol = 1e-3f;

    unsigned int n = 32;
    liquid_float_complex z[32] = {
        1.3608e+00f+_Complex_I* -4.2247e-01f,   1.1324e+00f+_Complex_I*  1.1938e+00f,
        1.6466e+00f+_Complex_I* -1.2098e+00f,  -6.5911e-01f+_Complex_I*  1.0729e+00f,
       -8.8890e-01f+_Complex_I*  2.1588e-01f,  -9.0412e-02f+_Complex_I*  5.1548e-01f,
       -5.4086e-01f+_Complex_I*  5.3604e-02f,   1.8089e+00f+_Complex_I*  1.6648e+00f,
        5.4285e-01f+_Complex_I*  8.6919e-01f,  -1.4336e+00f+_Complex_I*  4.2788e-01f,
       -1.9348e+00f+_Complex_I* -1.0285e+00f,  -1.4511e+00f+_Complex_I*  1.2167e+00f,
       -1.3733e+00f+_Complex_I* -3.9622e-01f,  -1.4808e+00f+_Complex_I* -1.5648e+00f,
        1.9957e+00f+_Complex_I* -1.1270e+00f,   5.1730e-02f+_Complex_I*  1.3564e+00f,
        4.5056e-01f+_Complex_I* -8.1587e-01f,   5.5021e-01f+_Complex_I*  9.7149e-02f,
       -2.5668e-02f+_Complex_I*  1.8911e+00f,  -8.2993e-01f+_Complex_I*  1.0854e+00f,
        1.0698e-01f+_Complex_I*  1.0797e+00f,  -3.9909e-01f+_Complex_I*  1.5661e+00f,
       -8.6674e-01f+_Complex_I* -5.9017e-01f,   1.2309e+00f+_Complex_I*  1.6761e+00f,
       -1.7210e+00f+_Complex_I*  1.7973e+00f,   1.0398e-01f+_Complex_I* -1.6558e+00f,
       -1.2311e+00f+_Complex_I*  6.5291e-01f,   1.5609e+00f+_Complex_I* -6.0443e-01f,
       -1.7433e+00f+_Complex_I* -1.9199e+00f,  -1.6919e-01f+_Complex_I* -1.7476e+00f,
       -1.0469e+00f+_Complex_I*  1.8825e+00f,   1.6088e+00f+_Complex_I*  1.4037e+00f};

    liquid_float_complex test[32] = {
        1.1802e+00f+_Complex_I* -1.7899e-01f,   1.1785e+00f+_Complex_I*  5.0647e-01f,
        1.3583e+00f+_Complex_I* -4.4534e-01f,   5.4776e-01f+_Complex_I*  9.7936e-01f,
        1.1366e-01f+_Complex_I*  9.4964e-01f,   4.6526e-01f+_Complex_I*  5.5397e-01f,
        3.6399e-02f+_Complex_I*  7.3633e-01f,   1.4607e+00f+_Complex_I*  5.6986e-01f,
        8.8533e-01f+_Complex_I*  4.9088e-01f,   1.7676e-01f+_Complex_I*  1.2103e+00f,
        3.5802e-01f+_Complex_I* -1.4363e+00f,   4.7042e-01f+_Complex_I*  1.2932e+00f,
        1.6736e-01f+_Complex_I* -1.1838e+00f,   5.8032e-01f+_Complex_I* -1.3482e+00f,
        1.4642e+00f+_Complex_I* -3.8485e-01f,   8.3939e-01f+_Complex_I*  8.0799e-01f,
        8.3144e-01f+_Complex_I* -4.9064e-01f,   7.4462e-01f+_Complex_I*  6.5233e-02f,
        9.6582e-01f+_Complex_I*  9.7902e-01f,   5.1789e-01f+_Complex_I*  1.0479e+00f,
        7.7199e-01f+_Complex_I*  6.9927e-01f,   7.8009e-01f+_Complex_I*  1.0038e+00f,
        3.0154e-01f+_Complex_I* -9.7860e-01f,   1.2866e+00f+_Complex_I*  6.5140e-01f,
        6.1944e-01f+_Complex_I*  1.4508e+00f,   9.3889e-01f+_Complex_I* -8.8178e-01f,
        2.8497e-01f+_Complex_I*  1.1456e+00f,   1.2718e+00f+_Complex_I* -2.3763e-01f,
        6.5191e-01f+_Complex_I* -1.4725e+00f,   8.9067e-01f+_Complex_I* -9.8107e-01f,
        7.4403e-01f+_Complex_I*  1.2651e+00f,   1.3682e+00f+_Complex_I*  5.1297e-01f};

    unsigned int i;
    for (i=0; i<n; i++) {
        liquid_float_complex t = liquid_csqrtf(z[i]);

        CONTEND_DELTA(crealf(t), crealf(test[i]), tol);
        CONTEND_DELTA(cimagf(t), cimagf(test[i]), tol);
    }
}

// 
// AUTOTEST: casinf
//
void autotest_casinf()
{
    float tol = 1e-3f;

    unsigned int n = 32;

    liquid_float_complex z[32] = {
        1.3608e+00f+_Complex_I* -4.2247e-01f,   1.1324e+00f+_Complex_I*  1.1938e+00f,
        1.6466e+00f+_Complex_I* -1.2098e+00f,  -6.5911e-01f+_Complex_I*  1.0729e+00f,
       -8.8890e-01f+_Complex_I*  2.1588e-01f,  -9.0412e-02f+_Complex_I*  5.1548e-01f,
       -5.4086e-01f+_Complex_I*  5.3604e-02f,   1.8089e+00f+_Complex_I*  1.6648e+00f,
        5.4285e-01f+_Complex_I*  8.6919e-01f,  -1.4336e+00f+_Complex_I*  4.2788e-01f,
       -1.9348e+00f+_Complex_I* -1.0285e+00f,  -1.4511e+00f+_Complex_I*  1.2167e+00f,
       -1.3733e+00f+_Complex_I* -3.9622e-01f,  -1.4808e+00f+_Complex_I* -1.5648e+00f,
        1.9957e+00f+_Complex_I* -1.1270e+00f,   5.1730e-02f+_Complex_I*  1.3564e+00f,
        4.5056e-01f+_Complex_I* -8.1587e-01f,   5.5021e-01f+_Complex_I*  9.7149e-02f,
       -2.5668e-02f+_Complex_I*  1.8911e+00f,  -8.2993e-01f+_Complex_I*  1.0854e+00f,
        1.0698e-01f+_Complex_I*  1.0797e+00f,  -3.9909e-01f+_Complex_I*  1.5661e+00f,
       -8.6674e-01f+_Complex_I* -5.9017e-01f,   1.2309e+00f+_Complex_I*  1.6761e+00f,
       -1.7210e+00f+_Complex_I*  1.7973e+00f,   1.0398e-01f+_Complex_I* -1.6558e+00f,
       -1.2311e+00f+_Complex_I*  6.5291e-01f,   1.5609e+00f+_Complex_I* -6.0443e-01f,
       -1.7433e+00f+_Complex_I* -1.9199e+00f,  -1.6919e-01f+_Complex_I* -1.7476e+00f,
       -1.0469e+00f+_Complex_I*  1.8825e+00f,   1.6088e+00f+_Complex_I*  1.4037e+00f };

    liquid_float_complex test[32] = {
        1.1716e+00f+_Complex_I* -9.4147e-01f,   6.7048e-01f+_Complex_I*  1.2078e+00f,
        8.7747e-01f+_Complex_I* -1.3947e+00f,  -4.3898e-01f+_Complex_I*  1.0065e+00f,
       -9.7768e-01f+_Complex_I*  3.7722e-01f,  -8.0395e-02f+_Complex_I*  4.9650e-01f,
       -5.7016e-01f+_Complex_I*  6.3633e-02f,   7.8546e-01f+_Complex_I*  1.5918e+00f,
        4.0539e-01f+_Complex_I*  8.4256e-01f,  -1.1968e+00f+_Complex_I*  9.9741e-01f,
       -1.0352e+00f+_Complex_I* -1.4505e+00f,  -8.0295e-01f+_Complex_I*  1.3267e+00f,
       -1.1968e+00f+_Complex_I* -9.3995e-01f,  -7.0503e-01f+_Complex_I* -1.4678e+00f,
        1.0130e+00f+_Complex_I* -1.4999e+00f,   3.0692e-02f+_Complex_I*  1.1128e+00f,
        3.4725e-01f+_Complex_I* -7.8464e-01f,   5.7823e-01f+_Complex_I*  1.1575e-01f,
       -1.1998e-02f+_Complex_I*  1.3939e+00f,  -5.4040e-01f+_Complex_I*  1.0574e+00f,
        7.2656e-02f+_Complex_I*  9.3853e-01f,  -2.1290e-01f+_Complex_I*  1.2502e+00f,
       -7.4285e-01f+_Complex_I* -7.3366e-01f,   5.8143e-01f+_Complex_I*  1.4462e+00f,
       -7.2379e-01f+_Complex_I*  1.6089e+00f,   5.3725e-02f+_Complex_I* -1.2794e+00f,
       -9.5454e-01f+_Complex_I*  9.7013e-01f,   1.1275e+00f+_Complex_I* -1.1433e+00f,
       -7.0078e-01f+_Complex_I* -1.6516e+00f,  -8.3905e-02f+_Complex_I* -1.3278e+00f,
       -4.6555e-01f+_Complex_I*  1.4904e+00f,   7.9838e-01f+_Complex_I*  1.4487e+00f };

    unsigned int i;
    for (i=0; i<n; i++) {
        liquid_float_complex t = liquid_casinf(z[i]);

        CONTEND_DELTA(crealf(t), crealf(test[i]), tol);
        CONTEND_DELTA(cimagf(t), cimagf(test[i]), tol);
    }
}

// 
// AUTOTEST: cacosf
//
void autotest_cacosf()
{
    float tol = 1e-3f;

    unsigned int n = 32;

    liquid_float_complex z[32] = {
        1.3608e+00f+_Complex_I* -4.2247e-01f,   1.1324e+00f+_Complex_I*  1.1938e+00f,
        1.6466e+00f+_Complex_I* -1.2098e+00f,  -6.5911e-01f+_Complex_I*  1.0729e+00f,
       -8.8890e-01f+_Complex_I*  2.1588e-01f,  -9.0412e-02f+_Complex_I*  5.1548e-01f,
       -5.4086e-01f+_Complex_I*  5.3604e-02f,   1.8089e+00f+_Complex_I*  1.6648e+00f,
        5.4285e-01f+_Complex_I*  8.6919e-01f,  -1.4336e+00f+_Complex_I*  4.2788e-01f,
       -1.9348e+00f+_Complex_I* -1.0285e+00f,  -1.4511e+00f+_Complex_I*  1.2167e+00f,
       -1.3733e+00f+_Complex_I* -3.9622e-01f,  -1.4808e+00f+_Complex_I* -1.5648e+00f,
        1.9957e+00f+_Complex_I* -1.1270e+00f,   5.1730e-02f+_Complex_I*  1.3564e+00f,
        4.5056e-01f+_Complex_I* -8.1587e-01f,   5.5021e-01f+_Complex_I*  9.7149e-02f,
       -2.5668e-02f+_Complex_I*  1.8911e+00f,  -8.2993e-01f+_Complex_I*  1.0854e+00f,
        1.0698e-01f+_Complex_I*  1.0797e+00f,  -3.9909e-01f+_Complex_I*  1.5661e+00f,
       -8.6674e-01f+_Complex_I* -5.9017e-01f,   1.2309e+00f+_Complex_I*  1.6761e+00f,
       -1.7210e+00f+_Complex_I*  1.7973e+00f,   1.0398e-01f+_Complex_I* -1.6558e+00f,
       -1.2311e+00f+_Complex_I*  6.5291e-01f,   1.5609e+00f+_Complex_I* -6.0443e-01f,
       -1.7433e+00f+_Complex_I* -1.9199e+00f,  -1.6919e-01f+_Complex_I* -1.7476e+00f,
       -1.0469e+00f+_Complex_I*  1.8825e+00f,   1.6088e+00f+_Complex_I*  1.4037e+00f,
      };

    liquid_float_complex test[32] = {
        3.9923e-01f+_Complex_I*  9.4147e-01f,   9.0032e-01f+_Complex_I* -1.2078e+00f,
        6.9333e-01f+_Complex_I*  1.3947e+00f,   2.0098e+00f+_Complex_I* -1.0065e+00f,
        2.5485e+00f+_Complex_I* -3.7722e-01f,   1.6512e+00f+_Complex_I* -4.9650e-01f,
        2.1410e+00f+_Complex_I* -6.3633e-02f,   7.8534e-01f+_Complex_I* -1.5918e+00f,
        1.1654e+00f+_Complex_I* -8.4256e-01f,   2.7676e+00f+_Complex_I* -9.9741e-01f,
        2.6060e+00f+_Complex_I*  1.4505e+00f,   2.3737e+00f+_Complex_I* -1.3267e+00f,
        2.7676e+00f+_Complex_I*  9.3995e-01f,   2.2758e+00f+_Complex_I*  1.4678e+00f,
        5.5780e-01f+_Complex_I*  1.4999e+00f,   1.5401e+00f+_Complex_I* -1.1128e+00f,
        1.2235e+00f+_Complex_I*  7.8464e-01f,   9.9257e-01f+_Complex_I* -1.1575e-01f,
        1.5828e+00f+_Complex_I* -1.3939e+00f,   2.1112e+00f+_Complex_I* -1.0574e+00f,
        1.4981e+00f+_Complex_I* -9.3853e-01f,   1.7837e+00f+_Complex_I* -1.2502e+00f,
        2.3137e+00f+_Complex_I*  7.3366e-01f,   9.8936e-01f+_Complex_I* -1.4462e+00f,
        2.2946e+00f+_Complex_I* -1.6089e+00f,   1.5171e+00f+_Complex_I*  1.2794e+00f,
        2.5253e+00f+_Complex_I* -9.7013e-01f,   4.4330e-01f+_Complex_I*  1.1433e+00f,
        2.2716e+00f+_Complex_I*  1.6516e+00f,   1.6547e+00f+_Complex_I*  1.3278e+00f,
        2.0363e+00f+_Complex_I* -1.4904e+00f,   7.7241e-01f+_Complex_I* -1.4487e+00f};

    unsigned int i;
    for (i=0; i<n; i++) {
        liquid_float_complex t = liquid_cacosf(z[i]);

        CONTEND_DELTA(crealf(t), crealf(test[i]), tol);
        CONTEND_DELTA(cimagf(t), cimagf(test[i]), tol);
    }
}

// 
// AUTOTEST: catanf
//
void autotest_catanf()
{
    float tol = 1e-3f;

    unsigned int n = 32;

    liquid_float_complex z[32] = {
        1.3608e+00f+_Complex_I* -4.2247e-01f,   1.1324e+00f+_Complex_I*  1.1938e+00f,
        1.6466e+00f+_Complex_I* -1.2098e+00f,  -6.5911e-01f+_Complex_I*  1.0729e+00f,
       -8.8890e-01f+_Complex_I*  2.1588e-01f,  -9.0412e-02f+_Complex_I*  5.1548e-01f,
       -5.4086e-01f+_Complex_I*  5.3604e-02f,   1.8089e+00f+_Complex_I*  1.6648e+00f,
        5.4285e-01f+_Complex_I*  8.6919e-01f,  -1.4336e+00f+_Complex_I*  4.2788e-01f,
       -1.9348e+00f+_Complex_I* -1.0285e+00f,  -1.4511e+00f+_Complex_I*  1.2167e+00f,
       -1.3733e+00f+_Complex_I* -3.9622e-01f,  -1.4808e+00f+_Complex_I* -1.5648e+00f,
        1.9957e+00f+_Complex_I* -1.1270e+00f,   5.1730e-02f+_Complex_I*  1.3564e+00f,
        4.5056e-01f+_Complex_I* -8.1587e-01f,   5.5021e-01f+_Complex_I*  9.7149e-02f,
       -2.5668e-02f+_Complex_I*  1.8911e+00f,  -8.2993e-01f+_Complex_I*  1.0854e+00f,
        1.0698e-01f+_Complex_I*  1.0797e+00f,  -3.9909e-01f+_Complex_I*  1.5661e+00f,
       -8.6674e-01f+_Complex_I* -5.9017e-01f,   1.2309e+00f+_Complex_I*  1.6761e+00f,
       -1.7210e+00f+_Complex_I*  1.7973e+00f,   1.0398e-01f+_Complex_I* -1.6558e+00f,
       -1.2311e+00f+_Complex_I*  6.5291e-01f,   1.5609e+00f+_Complex_I* -6.0443e-01f,
       -1.7433e+00f+_Complex_I* -1.9199e+00f,  -1.6919e-01f+_Complex_I* -1.7476e+00f,
       -1.0469e+00f+_Complex_I*  1.8825e+00f,   1.6088e+00f+_Complex_I*  1.4037e+00f };

    liquid_float_complex test[32] = {
        9.6632e-01f+_Complex_I* -1.4321e-01f,   1.1084e+00f+_Complex_I*  3.8248e-01f,
        1.1690e+00f+_Complex_I* -2.5348e-01f,  -9.9442e-01f+_Complex_I*  5.9395e-01f,
       -7.3961e-01f+_Complex_I*  1.1977e-01f,  -1.2203e-01f+_Complex_I*  5.6250e-01f,
       -4.9673e-01f+_Complex_I*  4.1475e-02f,   1.2597e+00f+_Complex_I*  2.5677e-01f,
        8.0849e-01f+_Complex_I*  6.2435e-01f,  -9.8924e-01f+_Complex_I*  1.3534e-01f,
       -1.1736e+00f+_Complex_I* -1.8533e-01f,  -1.1493e+00f+_Complex_I*  2.9550e-01f,
       -9.6685e-01f+_Complex_I* -1.3328e-01f,  -1.2294e+00f+_Complex_I* -3.1261e-01f,
        1.1940e+00f+_Complex_I* -1.8871e-01f,   1.5097e+00f+_Complex_I*  9.3927e-01f,
        7.1303e-01f+_Complex_I* -6.7324e-01f,   5.0608e-01f+_Complex_I*  7.4585e-02f,
       -1.5608e+00f+_Complex_I*  5.8828e-01f,  -1.0261e+00f+_Complex_I*  4.9481e-01f,
        1.1311e+00f+_Complex_I*  1.3740e+00f,  -1.3409e+00f+_Complex_I*  6.6079e-01f,
       -8.1408e-01f+_Complex_I* -3.1801e-01f,   1.2521e+00f+_Complex_I*  3.7037e-01f,
       -1.2781e+00f+_Complex_I*  2.7452e-01f,   1.5117e+00f+_Complex_I* -6.9351e-01f,
       -9.6809e-01f+_Complex_I*  2.3851e-01f,   1.0471e+00f+_Complex_I* -1.6469e-01f,
       -1.2973e+00f+_Complex_I* -2.7269e-01f,  -1.4903e+00f+_Complex_I* -6.3926e-01f,
       -1.3098e+00f+_Complex_I*  4.0318e-01f,   1.2032e+00f+_Complex_I*  2.7803e-01f };

    unsigned int i;
    for (i=0; i<n; i++) {
        liquid_float_complex t = liquid_catanf(z[i]);

        CONTEND_DELTA(crealf(t), crealf(test[i]), tol);
        CONTEND_DELTA(cimagf(t), cimagf(test[i]), tol);
    }
}
