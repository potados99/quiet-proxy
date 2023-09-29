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

#include <stdlib.h>

#include "autotest/autotest.h"
#include "liquid.internal.h"

// 
// AUTOTEST: compare structured result to oridinal computation
//

// 
// AUTOTEST: dot product with floating-point data
//
void autotest_dotprod_cccf_rand16()
{
    liquid_float_complex h[16] = {
      0.17702709f +   1.38978455f*_Complex_I,  0.91294148f +   0.39217381f*_Complex_I,
     -0.80607338f +   0.76477512f*_Complex_I,  0.05099755f +  -0.87350051f*_Complex_I,
      0.44513826f +  -0.49490569f*_Complex_I,  0.14754967f +   2.04349962f*_Complex_I,
      1.07246623f +   1.08146290f*_Complex_I, -1.14028088f +   1.83380899f*_Complex_I,
      0.38105361f +  -0.45591846f*_Complex_I,  0.32605401f +   0.34440081f*_Complex_I,
     -0.05477144f +   0.60832595f*_Complex_I,  1.81667523f +  -1.12238075f*_Complex_I,
     -0.87190497f +   1.10743858f*_Complex_I,  1.30921403f +   1.24438643f*_Complex_I,
      0.55524695f +  -1.94931519f*_Complex_I, -0.87191170f +   0.91693119f*_Complex_I,
    };

    liquid_float_complex x[16] = {
     -2.19591953f +  -0.93229692f*_Complex_I,  0.17150376f +   0.56165114f*_Complex_I,
      1.58354529f +  -0.50696037f*_Complex_I,  1.40929619f +   0.87868803f*_Complex_I,
     -0.75505072f +  -0.30867372f*_Complex_I, -0.09821367f +  -0.73949106f*_Complex_I,
      0.03785571f +   0.72763665f*_Complex_I, -1.20262636f +  -0.88838102f*_Complex_I,
      0.23323685f +   0.12456235f*_Complex_I,  0.34593736f +   0.02529594f*_Complex_I,
      0.33669564f +   0.39064649f*_Complex_I, -2.45003867f +  -0.54862205f*_Complex_I,
     -2.64870707f +   2.33444473f*_Complex_I, -0.92284477f +  -2.45121397f*_Complex_I,
      0.24852918f +  -0.62409860f*_Complex_I, -0.87039907f +   0.90921212f*_Complex_I,
    };

    liquid_float_complex y;
    liquid_float_complex test = -0.604285042605890f - 12.390925785344704f * _Complex_I;

    float tol = 1e-3f;

    dotprod_cccf_run(h,x,16,&y);
    CONTEND_DELTA( crealf(y), crealf(test), tol);
    CONTEND_DELTA( cimagf(y), cimagf(test), tol);

    dotprod_cccf_run4(h,x,16,&y);
    CONTEND_DELTA( crealf(y), crealf(test), tol);
    CONTEND_DELTA( cimagf(y), cimagf(test), tol);

    // test object
    dotprod_cccf q = dotprod_cccf_create(h,16);
    dotprod_cccf_execute(q,x,&y);
    CONTEND_DELTA( crealf(y), crealf(test), tol);
    CONTEND_DELTA( cimagf(y), cimagf(test), tol);
    dotprod_cccf_destroy(q);
}

// 
// AUTOTEST: structured dot product, odd lengths
//
void autotest_dotprod_cccf_struct_lengths()
{
    float tol = 2e-6;
    liquid_float_complex y;

    liquid_float_complex h[35] = {
      1.11555653f +   2.30658043f*_Complex_I, -0.36133676f +  -0.10917327f*_Complex_I,
      0.17714505f +  -2.14631440f*_Complex_I,  2.20424609f +   0.59063608f*_Complex_I,
     -0.44699194f +   0.23369318f*_Complex_I,  0.60613931f +   0.21868288f*_Complex_I,
     -1.18746289f +  -0.52159563f*_Complex_I, -0.46277775f +   0.75010157f*_Complex_I,
      0.93796307f +   0.28608151f*_Complex_I, -2.18699829f +   0.38029319f*_Complex_I,
      0.16145611f +   0.18343353f*_Complex_I, -0.62653631f +  -1.79037656f*_Complex_I,
     -0.67042462f +   0.11044084f*_Complex_I,  0.70333438f +   1.78729174f*_Complex_I,
     -0.32923580f +   0.78514690f*_Complex_I,  0.27534332f +  -0.56377431f*_Complex_I,
      0.41492559f +   1.37176526f*_Complex_I,  3.25368958f +   2.70495218f*_Complex_I,
      1.63002035f +  -0.14193750f*_Complex_I,  2.22057186f +   0.55056461f*_Complex_I,
      1.40896777f +   0.80722903f*_Complex_I, -0.22334033f +  -0.14227395f*_Complex_I,
     -1.48631186f +   0.53610531f*_Complex_I, -1.91632185f +   0.88755083f*_Complex_I,
     -0.52054895f +  -0.35572001f*_Complex_I, -1.56515607f +  -0.41448794f*_Complex_I,
     -0.91107117f +   0.17059659f*_Complex_I, -0.77007659f +   2.73381816f*_Complex_I,
     -0.46645585f +   0.38994666f*_Complex_I,  0.80317663f +  -0.41756968f*_Complex_I,
      0.26992512f +   0.41828145f*_Complex_I, -0.72456446f +   1.25002030f*_Complex_I,
      1.19573306f +   0.98449546f*_Complex_I,  1.42491943f +  -0.55426305f*_Complex_I,
      1.08243614f +   0.35774368f*_Complex_I, };

    liquid_float_complex x[35] = {
     -0.82466736f +  -1.39329228f*_Complex_I, -1.46176052f +  -1.96218827f*_Complex_I,
     -1.28388174f +  -0.07152934f*_Complex_I, -0.51910014f +  -0.37915971f*_Complex_I,
     -0.65964708f +  -0.98417534f*_Complex_I, -1.40213479f +  -0.82198463f*_Complex_I,
      0.86051446f +   0.97926463f*_Complex_I,  0.26257342f +   0.76586696f*_Complex_I,
      0.72174183f +  -1.89884636f*_Complex_I, -0.26018863f +   1.06920599f*_Complex_I,
      0.57949117f +  -0.77431546f*_Complex_I,  0.84635184f +  -0.81123009f*_Complex_I,
     -1.12637629f +  -0.42027412f*_Complex_I, -1.04214881f +   0.90519721f*_Complex_I,
      0.54458433f +  -1.03487314f*_Complex_I, -0.17847893f +   2.20358978f*_Complex_I,
      0.19642532f +  -0.07449796f*_Complex_I, -1.84958229f +   0.13218920f*_Complex_I,
     -1.49042886f +   0.81610408f*_Complex_I, -0.27466940f +  -1.48438409f*_Complex_I,
      0.29239375f +   0.72443343f*_Complex_I, -1.20243456f +  -2.77032750f*_Complex_I,
     -0.41784260f +   0.77455254f*_Complex_I,  0.37737465f +  -0.52426993f*_Complex_I,
     -1.25500377f +   1.76270122f*_Complex_I,  1.55976056f +  -1.18189171f*_Complex_I,
     -0.05111343f +  -1.18849396f*_Complex_I, -1.92966664f +   0.66504899f*_Complex_I,
     -2.82387897f +   1.41128242f*_Complex_I, -1.48171326f +  -0.03347470f*_Complex_I,
      0.38047273f +  -1.40969799f*_Complex_I,  1.71995272f +   0.00298203f*_Complex_I,
      0.56040910f +  -0.12713027f*_Complex_I, -0.46653022f +  -0.65450499f*_Complex_I,
      0.15515755f +   1.58944030f*_Complex_I, };

    liquid_float_complex v32 = -11.5100903519506f - 15.3575526884014f*_Complex_I;
    liquid_float_complex v33 = -10.7148314918614f - 14.9578463360225f*_Complex_I;
    liquid_float_complex v34 = -11.7423673921916f - 15.6318827515320f*_Complex_I;
    liquid_float_complex v35 = -12.1430314741466f - 13.8559085000689f*_Complex_I;

    // 
    dotprod_cccf dp;

    // n = 32
    dp = dotprod_cccf_create(h,32);
    dotprod_cccf_execute(dp, x, &y);
    CONTEND_DELTA(cabsf(y), cabsf(v32), tol);
    dotprod_cccf_destroy(dp);
    if (liquid_autotest_verbose) {
        printf("  dotprod-cccf-32 : %12.8f + j%12.8f (expected %12.8f + j%12.8f)\n",
                crealf(y), cimagf(y), crealf(v32), cimagf(v32));
    }

    // n = 33
    dp = dotprod_cccf_create(h,33);
    dotprod_cccf_execute(dp, x, &y);
    CONTEND_DELTA(cabsf(y), cabsf(v33), tol);
    dotprod_cccf_destroy(dp);
    if (liquid_autotest_verbose) {
        printf("  dotprod-cccf-33 : %12.8f + j%12.8f (expected %12.8f + j%12.8f)\n",
                crealf(y), cimagf(y), crealf(v33), cimagf(v33));
    }

    // n = 34
    dp = dotprod_cccf_create(h,34);
    dotprod_cccf_execute(dp, x, &y);
    CONTEND_DELTA(cabsf(y), cabsf(v34), tol);
    dotprod_cccf_destroy(dp);
    if (liquid_autotest_verbose) {
        printf("  dotprod-cccf-34 : %12.8f + j%12.8f (expected %12.8f + j%12.8f)\n",
                crealf(y), cimagf(y), crealf(v34), cimagf(v34));
    }

    // n = 35
    dp = dotprod_cccf_create(h,35);
    dotprod_cccf_execute(dp, x, &y);
    CONTEND_DELTA(cabsf(y), cabsf(v35), tol);
    dotprod_cccf_destroy(dp);
    if (liquid_autotest_verbose) {
        printf("  dotprod-cccf-35 : %12.8f + j%12.8f (expected %12.8f + j%12.8f)\n",
                crealf(y), cimagf(y), crealf(v35), cimagf(v35));
    }
}



// helper function (compare structured object to ordinal computation)
void runtest_dotprod_cccf(unsigned int _n)
{
    float tol = 1e-3;
    liquid_float_complex *h = (liquid_float_complex*) alloca((_n)*sizeof(liquid_float_complex));
    liquid_float_complex *x = (liquid_float_complex*) alloca((_n)*sizeof(liquid_float_complex));

    // generate random coefficients
    unsigned int i;
    for (i=0; i<_n; i++) {
        h[i] = randnf() + randnf() * _Complex_I;
        x[i] = randnf() + randnf() * _Complex_I;
    }
    
    // compute expected value (ordinal computation)
    liquid_float_complex y_test=0;
    for (i=0; i<_n; i++)
        y_test += h[i] * x[i];

    // create and run dot product object
    liquid_float_complex y;
    dotprod_cccf dp;
    dp = dotprod_cccf_create(h,_n);
    dotprod_cccf_execute(dp, x, &y);
    dotprod_cccf_destroy(dp);

    // print results
    if (liquid_autotest_verbose) {
        printf("  dotprod-cccf-%-4u : %12.8f + j%12.8f (expected %12.8f + j%12.8f)\n",
                _n, crealf(y), cimagf(y), crealf(y_test), cimagf(y_test));
    }

    // validate result
    CONTEND_DELTA(crealf(y), crealf(y_test), tol);
    CONTEND_DELTA(cimagf(y), cimagf(y_test), tol);
}

// compare structured object to ordinal computation
void autotest_dotprod_cccf_struct_vs_ordinal()
{
    // run many, many tests
    unsigned int i;
    for (i=1; i<=512; i++)
        runtest_dotprod_cccf(i);
}

