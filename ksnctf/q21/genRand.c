#include <stdio.h>
#include <stdlib.h>
#include "mt19937ar.h"

typedef unsigned long dword;

void initialize(const char *seed)
{
    const int N = 1024;
    
    FILE *f = fopen(seed, "rb");
    if (f==NULL)
    {
        printf("Failed to open %s\n", seed);
        exit(-1);
    }
    
    dword buf[N];
    fread(buf, sizeof (dword), N, f);
    
    fclose(f);
    
    init_by_array(buf, N);
}

int main(void){

    FILE *fw = fopen("random", "wb");

	initialize("seed");

    for(int i = 0; i < 1024; i++){
        dword r = genrand_int32();
        fwrite(&r, sizeof(unsigned long), 1, fw);
    	// printf(fw, "%lx\n", genrand_int32());
    }

    fclose(fw);

	return 0;
}