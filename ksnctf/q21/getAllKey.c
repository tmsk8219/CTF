#include <stdio.h>
#include <stdlib.h>
#include "mt19937ar.h"

// typedef unsigned long dword;


/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
#define KEY_SIZE 19639          /* flag.keyのサイズ */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */
int min(int a, int b) { return a<b ? a : b; }
void initialize();
unsigned long genrand_int32(void);
unsigned long untempering(unsigned long y);
unsigned long decodeXorRight(unsigned long y, int t);
unsigned long decodeXorLeft(unsigned long y, int t, unsigned long mask);

void initialize()
{
	FILE *fk = fopen("encrypt.key", "rb");
    // unsigned long state[N];

	for(int i = 0; i < N; i++){
		fread(&mt[i], 4, 1, fk);
		mt[i] = untempering(mt[i]);
	}

	fclose(fk);
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        //if (mti == N+1)   /* if init_genrand() has not been called, */
        //    init_genrand(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }
  
    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

// void submain(){
//     FILE *fp = fopen("random", "rb");

//     mti = 0;

//     for(int i = 0; i < N; i++){
//         fread(&mt[i], 4, 1, fp);
//         mt[i] = untempering(mt[i]);
//     }
//     fclose(fp);

    
//     for(int i = 0; i < N*2; i++){
//         printf("%d: %08lx\n", i, genrand_int32());
//     }
// }

unsigned long untempering(unsigned long y){
    unsigned long x;

    x = decodeXorRight(y, 18);
    x = decodeXorLeft(x, 15, 0xefc60000UL);
    x = decodeXorLeft(x, 7, 0x9d2c5680UL);
    x = decodeXorRight(x, 11);

    return x;
}

unsigned long decodeXorRight(unsigned long y, int t){
    int i = 1;
    unsigned long x = y;
    while(i * t < 32){
        unsigned long z = x >> t;
        x = y ^ z;
        i++;
    }
    return x;
}

unsigned long decodeXorLeft(unsigned long y, int t, unsigned long mask){
    int i = 1;
    unsigned long x = y;
    while(i * t < 32){
        unsigned long z = x << t;
        x = y ^ (z & mask);
        i++;
    }
    return x;
}

void checkEncryptKey(unsigned long *k){
    FILE *fp = fopen("encrypt.key", "rb");

    for(int i = 0; i < 650; i++){
        unsigned long e;
        fread(&e, 4, 1, fp);
        // if(e != k[i]){
            printf("%d: %08lx, %08lx\n", i, e, k[i]);
        // }
    }

    fclose(fp);
}



int main(){

    //submain();
    mti = 0;

    FILE *fpk = fopen("flag.key", "wb");
    unsigned long k[KEY_SIZE];
	initialize();

    /* encrypt.cppの暗号化のために650個の乱数を生成 */
    for(int i = 0; i < 650; i++){
        genrand_int32();
    }

    /* flag.cppの暗号化のための乱数を出力する */
	for(int i = 0; i < KEY_SIZE; i++){
        // printf("%d: %08lx\n", i, genrand_int32());
        k[i] = genrand_int32();
        //printf("%d: %08lx\n", i, k[i]);
        fwrite(&k[i], 4, 1, fpk);

	}

    // checkEncryptKey(k);

    fclose(fpk);

	return 0;
}