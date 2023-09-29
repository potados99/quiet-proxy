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
// References
//  [Ziemer:1998] Ziemer, Tranter, Fannin, "Signals & Systems,
//      Continuous and Discrete," 4th ed., Prentice Hall, Upper
//      Saddle River, NJ, 1998

#include "autotest/autotest.h"
#include "liquid.internal.h"

// 
// AUTOTEST : design 2nd-order butterworth filter (design comes
//            from [Ziemer:1998] Example 9-7, pp. 440--442)
//
void autotest_iirdes_butter_2()
{
    // initialize variables
    unsigned int order = 2; // filter order
    float fc = 0.25f;       // normalized cutoff frequency
    float f0 = 0.0f;        // center frequency (ignored for low-pass filter)
    float Ap = 1.0f;        // pass-band ripple (ignored for Butterworth)
    float As = 40.0f;       // stop-band attenuation (ignored for Butterworth)
    float tol = 1e-6f;      // error tolerance

    // initialize pre-determined coefficient array
    // for 2^nd-order low-pass Butterworth filter
    // with cutoff frequency 0.25
    float a_test[3] = {
        1.0f,
        0.0f,
        0.171572875253810f};
    float b_test[3] = {
        0.292893218813452f,
        0.585786437626905f,
        0.292893218813452f};

    // output coefficients
    float a[3];
    float b[3];

    // design butterworth filter
    liquid_iirdes(LIQUID_IIRDES_BUTTER,
                  LIQUID_IIRDES_LOWPASS,
                  LIQUID_IIRDES_TF,
                  order,
                  fc, f0,
                  Ap, As,
                  b, a);

    // Ensure data are equal to within tolerance
    unsigned int i;
    for (i=0; i<3; i++) {
        CONTEND_DELTA( b[i], b_test[i], tol );
        CONTEND_DELTA( a[i], a_test[i], tol );
    }
}

// 
// AUTOTEST : complex pair, n=6
//

void autotest_iirdes_cplxpair_n6()
{
    float tol = 1e-8f;

    //
    liquid_float_complex r[6] = {
       0.980066577841242f + 0.198669330795061f * _Complex_I,
       5.000000000000000f + 0.000000000000000f * _Complex_I,
      -0.416146836547142f + 0.909297426825682f * _Complex_I,
       0.980066577841242f - 0.198669330795061f * _Complex_I,
       0.300000000000000f + 0.000000000000000f * _Complex_I,
      -0.416146836547142f - 0.909297426825682f * _Complex_I
    };

    liquid_float_complex p[6];

    liquid_float_complex ptest[6] = {
      -0.416146836547142f - 0.909297426825682f * _Complex_I,
      -0.416146836547142f + 0.909297426825682f * _Complex_I,
       0.980066577841242f - 0.198669330795061f * _Complex_I,
       0.980066577841242f + 0.198669330795061f * _Complex_I,
       0.300000000000000f + 0.000000000000000f * _Complex_I,
       5.000000000000000f + 0.000000000000000f * _Complex_I
    };

    // compute complex pairs
    liquid_cplxpair(r,6,1e-6f,p);

    unsigned int i;

    if (liquid_autotest_verbose) {
        printf("complex set:\n");
        for (i=0; i<6; i++)
            printf("  r[%3u] : %12.8f + j*%12.8f\n", i, crealf(r[i]), cimagf(r[i]));

        printf("complex pairs:\n");
        for (i=0; i<6; i++)
            printf("  p[%3u] : %12.8f + j*%12.8f\n", i, crealf(p[i]), cimagf(p[i]));
    }

    // run test
    for (i=0; i<6; i++) {
        CONTEND_DELTA( crealf(p[i]), crealf(ptest[i]), tol );
        CONTEND_DELTA( cimagf(p[i]), cimagf(ptest[i]), tol );
    }
}


// 
// AUTOTEST : complex pair, n=20
//

void autotest_iirdes_cplxpair_n20()
{
    float tol = 1e-8f;

    //
    liquid_float_complex r[20] = {
      -0.340396183901119f + 1.109902927794652f * _Complex_I,
       1.148964416793990f + 0.000000000000000f * _Complex_I,
       0.190037889511651f + 0.597517076404221f * _Complex_I,
      -0.340396183901119f - 1.109902927794652f * _Complex_I,
       0.890883293686046f + 0.000000000000000f * _Complex_I,
      -0.248338528396292f - 0.199390430636670f * _Complex_I,
       0.190037889511651f - 0.597517076404221f * _Complex_I,
       0.003180396218998f + 0.000000000000000f * _Complex_I,
       0.261949046540733f - 0.739400953405199f * _Complex_I,
       0.261949046540733f + 0.739400953405199f * _Complex_I,
       0.309342570837113f + 0.000000000000000f * _Complex_I,
       0.035516103001236f + 0.000000000000000f * _Complex_I,
      -0.184159864176452f - 0.240335024546875f * _Complex_I,
      -0.485244526317243f + 0.452251520655749f * _Complex_I,
      -0.485244526317243f - 0.452251520655749f * _Complex_I,
      -0.581633365450190f + 0.000000000000000f * _Complex_I,
      -0.248338528396292f + 0.199390430636670f * _Complex_I,
      -0.184159864176452f + 0.240335024546875f * _Complex_I,
       1.013685316242435f + 0.000000000000000f * _Complex_I,
      -0.089598596934739f + 0.000000000000000f * _Complex_I
    };

    liquid_float_complex p[20];

    liquid_float_complex ptest[20] = {
      -0.485244526317243f - 0.452251520655749f * _Complex_I,
      -0.485244526317243f + 0.452251520655749f * _Complex_I,
      -0.340396183901119f - 1.109902927794652f * _Complex_I,
      -0.340396183901119f + 1.109902927794652f * _Complex_I,
      -0.248338528396292f - 0.199390430636670f * _Complex_I,
      -0.248338528396292f + 0.199390430636670f * _Complex_I,
      -0.184159864176452f - 0.240335024546875f * _Complex_I,
      -0.184159864176452f + 0.240335024546875f * _Complex_I,
       0.190037889511651f - 0.597517076404221f * _Complex_I,
       0.190037889511651f + 0.597517076404221f * _Complex_I,
       0.261949046540733f - 0.739400953405199f * _Complex_I,
       0.261949046540733f + 0.739400953405199f * _Complex_I,
      -0.581633365450190f + 0.000000000000000f * _Complex_I,
      -0.089598596934739f + 0.000000000000000f * _Complex_I,
       0.003180396218998f + 0.000000000000000f * _Complex_I,
       0.035516103001236f + 0.000000000000000f * _Complex_I,
       0.309342570837113f + 0.000000000000000f * _Complex_I,
       0.890883293686046f + 0.000000000000000f * _Complex_I,
       1.013685316242435f + 0.000000000000000f * _Complex_I,
       1.148964416793990f + 0.000000000000000f * _Complex_I
    };

    // compute complex pairs
    liquid_cplxpair(r,20,1e-6f,p);

    unsigned int i;

    if (liquid_autotest_verbose) {
        printf("complex set:\n");
        for (i=0; i<20; i++)
            printf("  r[%3u] : %12.8f + j*%12.8f\n", i, crealf(r[i]), cimagf(r[i]));

        printf("complex pairs:\n");
        for (i=0; i<20; i++)
            printf("  p[%3u] : %12.8f + j*%12.8f\n", i, crealf(p[i]), cimagf(p[i]));
    }

    // run test
    for (i=0; i<20; i++) {
        CONTEND_DELTA( crealf(p[i]), crealf(ptest[i]), tol );
        CONTEND_DELTA( cimagf(p[i]), cimagf(ptest[i]), tol );
    }
}

// 
// AUTOTEST : 
//
void autotest_iirdes_dzpk2sosf()
{
    unsigned int n=4;
    float fc = 0.25f;

    unsigned int i;
    unsigned int L = n % 2 ? (n+1)/2 : n/2;
    float *B = (float*) alloca((3*L)*sizeof(float));
    float *A = (float*) alloca((3*L)*sizeof(float));

    liquid_float_complex *za = (liquid_float_complex*) alloca((n)*sizeof(liquid_float_complex));    // analog zeros
    liquid_float_complex *pa = (liquid_float_complex*) alloca((n)*sizeof(liquid_float_complex));    // analog poles
    liquid_float_complex ka;       // analog gain
    butter_azpkf(n,za,pa,&ka);

    liquid_float_complex *zd = (liquid_float_complex*) alloca((n)*sizeof(liquid_float_complex));    // digital zeros
    liquid_float_complex *pd = (liquid_float_complex*) alloca((n)*sizeof(liquid_float_complex));    // digital poles
    liquid_float_complex kd;       // digital gain
    float m = 1 / tanf(M_PI * fc);
    bilinear_zpkf(za,  0,
                  pa,  n,
                  ka,  m,
                  zd, pd, &kd);

    if (liquid_autotest_verbose) {
        printf("poles (digital):\n");
        for (i=0; i<n; i++)
            printf("  pd[%3u] = %12.8f + j*%12.8f\n", i, crealf(pd[i]), cimagf(pd[i]));

        printf("zeros (digital):\n");
        for (i=0; i<n; i++)
            printf("  zd[%3u] = %12.8f + j*%12.8f\n", i, crealf(zd[i]), cimagf(zd[i]));
    }

    iirdes_dzpk2sosf(zd,pd,n,kd,B,A);

    if (liquid_autotest_verbose) {
        printf("B:\n");
        for (i=0; i<L; i++)
            printf("  %12.8f %12.8f %12.8f\n", B[3*i+0], B[3*i+1], B[3*i+2]);

        printf("A:\n");
        for (i=0; i<L; i++)
            printf("  %12.8f %12.8f %12.8f\n", A[3*i+0], A[3*i+1], A[3*i+2]);
    }
}

// 
// AUTOTEST : iirdes_isstable
//
void autotest_iirdes_isstable_n2_yes()
{
    // initialize pre-determined coefficient array
    // for 2^nd-order low-pass Butterworth filter
    // with cutoff frequency 0.25
    float a[3] = {
        1.0f,
        0.0f,
        0.171572875253810f};
    float b[3] = {
        0.292893218813452f,
        0.585786437626905f,
        0.292893218813452f};

    int stable = iirdes_isstable(b,a,3);
    CONTEND_EQUALITY( stable, 1 );
}


// 
// AUTOTEST : iirdes_isstable
//
void autotest_iirdes_isstable_n2_no()
{
    // initialize unstable filter
    float a[3] = {
        1.0f,
        0.0f,
        1.171572875253810f};
    float b[3] = {
        0.292893218813452f,
        0.585786437626905f,
        0.292893218813452f};

    int stable = iirdes_isstable(b,a,3);
    CONTEND_EQUALITY( stable, 0 );
}

