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
// bsequence.c
//
// generic binary sequence
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "liquid.internal.h"

// 
struct bsequence_s {
    unsigned int * s;           // sequence array, memory pointer
    unsigned int num_bits;      // number of bits in sequence
    unsigned int num_bits_msb;  // number of bits in most-significant block
    unsigned int bit_mask_msb;  // bit mask for most-significant block
    unsigned int s_len;         // length of array, number of allocated blocks
};

// Create a binary sequence of a specific length
bsequence bsequence_create(unsigned int _num_bits)
{
    bsequence bs;

    // allocate memory for binary sequence
    bs = (bsequence) malloc( sizeof(struct bsequence_s) );

    // initialize variables
    bs->s_len = 0;
    bs->s = NULL;
    bs->num_bits = _num_bits;
    
    // initialize array length
    div_t d = div( (int)bs->num_bits, (int)(sizeof(unsigned int)*8) );
    bs->s_len = d.quot;
    bs->s_len += (d.rem > 0) ? 1 : 0;

    // number of bits in MSB block
    bs->num_bits_msb = (d.rem == 0) ? 8*sizeof(unsigned int) : (unsigned int) d.rem;

    // bit mask for MSB block
    unsigned int i;
    bs->bit_mask_msb = 0;
    for (i=0; i<bs->num_bits_msb; i++) {
        bs->bit_mask_msb <<= 1;
        bs->bit_mask_msb |=  1;
    }

    // initialze array with zeros
    bs->s = (unsigned int*) malloc( bs->s_len * sizeof(unsigned int) );
    bsequence_reset(bs);

    return bs;
}

// Free memory in a binary sequence
void bsequence_destroy(bsequence _bs)
{
    free( _bs->s );
    free( _bs );
}

void bsequence_reset(bsequence _bs)
{
    memset( _bs->s, 0x00, (_bs->s_len)*sizeof(unsigned int) );
}

// initialize sequence on external array
void bsequence_init(bsequence _bs,
                    unsigned char * _v)
{
    // push single bit at a time
    unsigned int i;
    unsigned int k=0;
    unsigned char byte = 0x00;
    unsigned char mask = 0x80;
    for (i=0; i<_bs->num_bits; i++) {
        if ( (i%8)==0 ) {
            byte = _v[k++];
            mask = 0x80;
        }

        bsequence_push(_bs, byte & mask ? 1 : 0);
        mask >>= 1;
    }
}

// Print sequence to the screen
void bsequence_print(bsequence _bs)
{
    unsigned int i, j;
    unsigned int chunk;
    unsigned int p = 8*sizeof(unsigned int);

    printf("bsequence[%6u]:     ", _bs->num_bits);
    for (i=0; i<_bs->s_len; i++) {
        // strip chunk from sequence, starting with most-significant bits
        chunk = _bs->s[i];

        for (j=0; j<p; j++) {
            if (i==0 && j<p-_bs->num_bits_msb)
                printf(".");    // print '.' for each bit in byte not included in first byte
            else
                printf("%c", (chunk >> (p-j-1)) & 0x01 ? '1' : '0');
            
            if ( ((j+1)%8)==0 )
                printf(" ");
        }
    }
    printf("\n");
}

// push bits in from the right
void bsequence_push(bsequence _bs,
                    unsigned int _bit)
{
    unsigned int overflow;
    unsigned int i;
    unsigned int p = 8*sizeof(unsigned int);

    // shift first block
    _bs->s[0] <<= 1;
    _bs->s[0] &= _bs->bit_mask_msb;

    for (i=1; i<_bs->s_len; i++) {
        // overflow for i-th block is its MSB
        overflow = (_bs->s[i] >> (p-1)) & 1;

        // shift block 1 bit
        _bs->s[i] <<= 1;

        // apply overflow to (i-1)-th block's LSB
        _bs->s[i-1] |= overflow;
    }

    // apply input bit to LSB of last block
    _bs->s[_bs->s_len-1] |= ( _bit & 1 );
}

// circular shift (left)
void bsequence_circshift(bsequence _bs)
{
    // extract most-significant (left-most) bit
    unsigned int msb_mask = 1 << (_bs->num_bits_msb-1);
    unsigned int b = (_bs->s[0] & msb_mask) >> (_bs->num_bits_msb-1);

    // push bit into sequence
    bsequence_push(_bs, b);
}

// Correlate two binary sequences together
signed int bsequence_correlate(bsequence _bs1,
                               bsequence _bs2)
{
    signed int rxy = 0;
    unsigned int i;
    
    if ( _bs1->s_len != _bs2->s_len ) {
        printf("error: bsequence_correlate(), binary sequences must be the same length!\n");
        exit(-1);
    }
    
    unsigned int chunk;

    for (i=0; i<_bs1->s_len; i++) {
        //
        chunk = _bs1->s[i] ^ _bs2->s[i];
        chunk = ~chunk;

        rxy += liquid_count_ones(chunk);
    }

    // compensate for most-significant block and return
    rxy -= 8*sizeof(unsigned int) - _bs1->num_bits_msb;
    return rxy;
}

// compute the binary addition of two bit sequences
void bsequence_add(bsequence _bs1,
                   bsequence _bs2,
                   bsequence _bs3)
{
    // test lengths of all sequences
    if ( _bs1->s_len != _bs2->s_len ||
         _bs1->s_len != _bs3->s_len ||
         _bs2->s_len != _bs3->s_len )
    {
        fprintf(stderr,"error: bsequence_add(), binary sequences must be same length!\n");
        exit(-1);
    }

    // b3 = b1 + b2
    unsigned int i;
    for (i=0; i<_bs1->s_len; i++)
        _bs3->s[i] = _bs1->s[i] ^ _bs2->s[i];

    // no need to mask most-significant byte
}

// compute the binary multiplication of two bit sequences
void bsequence_mul(bsequence _bs1,
                   bsequence _bs2,
                   bsequence _bs3)
{
    // test lengths of all sequences
    if ( _bs1->s_len != _bs2->s_len ||
         _bs1->s_len != _bs3->s_len ||
         _bs2->s_len != _bs3->s_len )
    {
        fprintf(stderr,"error: bsequence_mul(), binary sequences must be same length!\n");
        exit(-1);
    }

    // b3 = b1 * b2
    unsigned int i;
    for (i=0; i<_bs1->s_len; i++)
        _bs3->s[i] = _bs1->s[i] & _bs2->s[i];

    // no need to mask most-significant byte
}

// accumulate the 1's in a binary sequence
unsigned int bsequence_accumulate(bsequence _bs)
{
    unsigned int i;
    unsigned int r=0;

    for (i=0; i<_bs->s_len; i++)
        r += liquid_count_ones(_bs->s[i]);

    return r;
}

// return the number of ones in a sequence
unsigned int bsequence_get_length(bsequence _bs)
{
    return _bs->num_bits;
}

// return the i-th bit of the sequence
unsigned int bsequence_index(bsequence _bs,
                             unsigned int _i)
{
    if (_i >= _bs->num_bits) {
        fprintf(stderr,"error: bsequence_index(), invalid index %u\n", _i);
        exit(-1);
    }
    div_t d = div( (int)_i, (int)(8*sizeof(unsigned int)) );

    // compute byte index
    unsigned int k = _bs->s_len - d.quot - 1;

    // return particular bit at byte index
    return (_bs->s[k] >> d.rem ) & 1;
}

// intialize two sequences to complementary codes.  sequences must
// be of length at least 8 and a power of 2 (e.g. 8, 16, 32, 64,...)
void bsequence_create_ccodes(bsequence _qa, bsequence _qb)
{
    // make sure sequences are the same length
    if (_qa->num_bits != _qb->num_bits) {
        printf("error: bsequence_create_ccodes(), sequence lengths must match\n");
        exit(1);
    } else if (_qa->num_bits < 8) {
        printf("error: bsequence_create_ccodes(), sequence too short\n");
        exit(1);
    } else if ( (_qa->num_bits)%8 != 0 ) {
        printf("error: bsequence_create_ccodes(), sequence must be multiple of 8\n");
        exit(1);
    }

    // generate two temporary arrays
    unsigned int num_bytes = _qa->num_bits / 8;
    unsigned char *a = (unsigned char*) alloca(num_bytes*sizeof(unsigned char));
    unsigned char *b = (unsigned char*) alloca(num_bytes*sizeof(unsigned char));

    memset(a, 0x00, num_bytes);
    memset(b, 0x00, num_bytes);

    // initialize
    a[num_bytes-1] = 0xb8;  // 1011 1000
    b[num_bytes-1] = 0xb7;  // 1011 0111

    unsigned int i;
    unsigned int n=1;
    unsigned int i_n1;
    unsigned int i_n0;
    while (n < num_bytes) {

        i_n1 = num_bytes - n;
        i_n0 = num_bytes - 2*n;

        // a -> [a  b]
        // b -> [a ~b]
        memmove(&a[i_n0], &a[i_n1], n*sizeof(unsigned char));
        memmove(&b[i_n0], &a[i_n1], n*sizeof(unsigned char));

        memmove(&a[i_n1], &b[i_n1], n*sizeof(unsigned char));
        memmove(&b[i_n1], &b[i_n1], n*sizeof(unsigned char));

        // complement lower half
        for (i=0; i<n; i++)
            b[num_bytes-i-1] ^= 0xff;

        n += n;
    }

    // initialize on generated sequences
    bsequence_init(_qa, a);
    bsequence_init(_qb, b);
}

