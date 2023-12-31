//
// msresamp_crcf_example.c
//
// Demonstration of the multi-stage arbitrary resampler
//

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <getopt.h>

#include "liquid.h"

#define OUTPUT_FILENAME "msresamp_crcf_example.m"

// print usage/help message
void usage()
{
    printf("Usage: %s [OPTION]\n", __FILE__);
    printf("  h     : print help\n");
    printf("  r     : resampling rate (output/input), default: 0.23175\n");
    printf("  s     : stop-band attenuation [dB],     default: 60\n");
    printf("  n     : number of input samples,        default: 400\n");
    printf("  f     : input signal frequency,         default: 0.017\n");
}

int main(int argc, char*argv[])
{
    // options
    float r=0.23175f;       // resampling rate (output/input)
    float As=60.0f;         // resampling filter stop-band attenuation [dB]
    unsigned int n=400;     // number of input samples
    float fc=0.017f;        // complex sinusoid frequency

    int dopt;
    while ((dopt = getopt(argc,argv,"hr:s:n:f:")) != EOF) {
        switch (dopt) {
        case 'h': usage();                return 0;
        case 'r': r       = atof(optarg); break;
        case 's': As      = atof(optarg); break;
        case 'n': n       = atoi(optarg); break;
        case 'f': fc      = atof(optarg); break;
        default:
            exit(1);
        }
    }

    // validate input
    if (n == 0) {
        fprintf(stderr,"error: %s, number of input samples must be greater than zero\n", argv[0]);
        exit(1);
    } else if (r <= 0.0f) {
        fprintf(stderr,"error: %s, resampling rate must be greater than zero\n", argv[0]);
        exit(1);
    } else if ( fabsf(log2f(r)) > 10 ) {
        fprintf(stderr,"error: %s, resampling rate unreasonable\n", argv[0]);
        exit(1);
    }

    unsigned int i;

    // create multi-stage arbitrary resampler object
    msresamp_crcf q = msresamp_crcf_create(r,As);
    msresamp_crcf_print(q);
    float delay = msresamp_crcf_get_delay(q);

    // number of input samples (zero-padded)
    unsigned int nx = n + (int)ceilf(delay) + 10;

    // output buffer with extra padding for good measure
    unsigned int ny_alloc = (unsigned int) (2*(float)nx * r);  // allocation for output

    // allocate memory for arrays
    liquid_float_complex x[nx];
    liquid_float_complex y[ny_alloc];

    // generate input signal
    float wsum = 0.0f;
    for (i=0; i<nx; i++) {
        // compute window
        float w = i < n ? kaiser(i, n, 10.0f, 0.0f) : 0.0f;

        // apply window to complex sinusoid
        x[i] = cexpf(_Complex_I*2*M_PI*fc*i) * w;

        // accumulate window
        wsum += w;
    }

    // run resampler
    unsigned int ny;
    msresamp_crcf_execute(q, x, nx, y, &ny);

    // clean up allocated objects
    msresamp_crcf_destroy(q);
    
    
    // 
    // analyze resulting signal
    //

    // check that the actual resampling rate is close to the target
    float r_actual = (float)ny / (float)nx;
    float fy = fc / r;      // expected output frequency

    // run FFT and ensure that carrier has moved and that image
    // frequencies and distortion have been adequately suppressed
    unsigned int nfft = 1 << liquid_nextpow2(ny);
    liquid_float_complex yfft[nfft];   // fft input
    liquid_float_complex Yfft[nfft];   // fft output
    for (i=0; i<nfft; i++)
        yfft[i] = i < ny ? y[i] : 0.0f;
    fft_run(nfft, yfft, Yfft, LIQUID_FFT_FORWARD, 0);
    fft_shift(Yfft, nfft);  // run FFT shift

    // find peak frequency
    float Ypeak = 0.0f;
    float fpeak = 0.0f;
    float max_sidelobe = -1e9f;     // maximum side-lobe [dB]
    float main_lobe_width = 0.07f;  // TODO: figure this out from Kaiser's equations
    for (i=0; i<nfft; i++) {
        // normalized output frequency
        float f = (float)i/(float)nfft - 0.5f;

        // scale FFT output appropriately
        float Ymag = 20*log10f( cabsf(Yfft[i] / (r * wsum)) );

        // find frequency location of maximum magnitude
        if (Ymag > Ypeak || i==0) {
            Ypeak = Ymag;
            fpeak = f;
        }

        // find peak side-lobe value, ignoring frequencies
        // within a certain range of signal frequency
        if ( fabsf(f-fy) > main_lobe_width )
            max_sidelobe = Ymag > max_sidelobe ? Ymag : max_sidelobe;
    }

    // print results and check frequency location
    printf("output results:\n");
    printf("  output delay              :   %12.8f samples\n", delay);
    printf("  desired resampling rate   :   %12.8f\n", r);
    printf("  measured resampling rate  :   %12.8f    (%u/%u)\n", r_actual, ny, nx);
    printf("  peak spectrum             :   %12.8f dB (expected 0.0 dB)\n", Ypeak);
    printf("  peak frequency            :   %12.8f    (expected %-12.8f)\n", fpeak, fy);
    printf("  max sidelobe              :   %12.8f dB (expected at least %.2f dB)\n", max_sidelobe, -As);


    // 
    // export results
    //
    FILE * fid = fopen(OUTPUT_FILENAME,"w");
    fprintf(fid,"%% %s: auto-generated file\n",OUTPUT_FILENAME);
    fprintf(fid,"clear all;\n");
    fprintf(fid,"close all;\n");
    fprintf(fid,"delay=%f;\n", delay);
    fprintf(fid,"r=%12.8f;\n", r);

    fprintf(fid,"nx = %u;\n", nx);
    fprintf(fid,"x = zeros(1,nx);\n");
    for (i=0; i<nx; i++)
        fprintf(fid,"x(%3u) = %12.4e + j*%12.4e;\n", i+1, crealf(x[i]), cimagf(x[i]));

    fprintf(fid,"ny = %u;\n", ny);
    fprintf(fid,"y = zeros(1,ny);\n");
    for (i=0; i<ny; i++)
        fprintf(fid,"y(%3u) = %12.4e + j*%12.4e;\n", i+1, crealf(y[i]), cimagf(y[i]));

    // time-domain results
    fprintf(fid,"\n");
    fprintf(fid,"%% plot time-domain result\n");
    fprintf(fid,"tx=[0:(length(x)-1)];\n");
    fprintf(fid,"ty=[0:(length(y)-1)]/r-delay;\n");
    fprintf(fid,"tmin = min(tx(1),  ty(1)  );\n");
    fprintf(fid,"tmax = max(tx(end),ty(end));\n");
    fprintf(fid,"figure;\n");
    fprintf(fid,"subplot(2,1,1);\n");
    fprintf(fid,"  plot(tx,real(x),'-s','Color',[0.5 0.5 0.5],'MarkerSize',1,...\n");
    fprintf(fid,"       ty,real(y),'-s','Color',[0.5 0 0],    'MarkerSize',1);\n");
    fprintf(fid,"  legend('original','resampled','location','northeast');");
    fprintf(fid,"  axis([tmin tmax -1.2 1.2]);\n");
    fprintf(fid,"  grid on;\n");
    fprintf(fid,"  xlabel('time');\n");
    fprintf(fid,"  ylabel('real');\n");
    fprintf(fid,"subplot(2,1,2);\n");
    fprintf(fid,"  plot(tx,imag(x),'-s','Color',[0.5 0.5 0.5],'MarkerSize',1,...\n");
    fprintf(fid,"       ty,imag(y),'-s','Color',[0 0.5 0],    'MarkerSize',1);\n");
    fprintf(fid,"  legend('original','resampled','location','northeast');");
    fprintf(fid,"  axis([tmin tmax -1.2 1.2]);\n");
    fprintf(fid,"  grid on;\n");
    fprintf(fid,"  xlabel('time');\n");
    fprintf(fid,"  ylabel('imag');\n");

    // frequency-domain results
    fprintf(fid,"\n\n");
    fprintf(fid,"%% plot frequency-domain result\n");
    fprintf(fid,"nfft=2^nextpow2(max(nx,ny));\n");
    fprintf(fid,"%% estimate PSD, normalize by array length\n");
    fprintf(fid,"X=20*log10(abs(fftshift(fft(x,nfft)/length(x))));\n");
    fprintf(fid,"Y=20*log10(abs(fftshift(fft(y,nfft)/length(y))));\n");
    fprintf(fid,"G=max(X);\n");
    fprintf(fid,"X=X-G;\n");
    fprintf(fid,"Y=Y-G;\n");
    fprintf(fid,"f=[0:(nfft-1)]/nfft-0.5;\n");
    fprintf(fid,"figure;\n");
    fprintf(fid,"if r>1, fx = f/r; fy = f;   %% interpolated\n");
    fprintf(fid,"else,   fx = f;   fy = f*r; %% decimated\n");
    fprintf(fid,"end;\n");
    fprintf(fid,"plot(fx,X,'LineWidth',1,  'Color',[0.5 0.5 0.5],...\n");
    fprintf(fid,"     fy,Y,'LineWidth',1.5,'Color',[0.1 0.3 0.5]);\n");
    fprintf(fid,"grid on;\n");
    fprintf(fid,"xlabel('normalized frequency');\n");
    fprintf(fid,"ylabel('PSD [dB]');\n");
    fprintf(fid,"legend('original','resampled','location','northeast');");
    fprintf(fid,"axis([-0.5 0.5 -120 20]);\n");

    fclose(fid);
    printf("results written to %s\n",OUTPUT_FILENAME);

    printf("done.\n");
    return 0;
}
