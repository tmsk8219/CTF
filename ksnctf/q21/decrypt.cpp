//  g++ -O2 -o encrypt.exe encrypt.cpp mt19937ar.cpp

#include <stdio.h>
#include <stdlib.h>
#include "mt19937ar.h"

typedef unsigned long dword;

void decrypt(const char *plain, const char *crypt, const char *key);
int min(int a, int b) { return a<b ? a : b; }

int main()
{
    decrypt("encrypt_dec.cpp", "encrypt.enc", "encrypt.key");
    decrypt("flag_dec.jpg", "flag.enc", "flag.key");
}

void decrypt(const char *plain, const char *crypt, const char *key)
{
    FILE *fp = fopen(plain, "wb");
    if (fp==NULL)
    {
        printf("Failed to open %s\n", plain);
        exit(-1);
    }
    FILE *fc = fopen(crypt, "rb");
    if (fc==NULL)
    {
        printf("Failed to open %s\n", crypt);
        exit(-1);
    }
    FILE *fk = fopen(key, "rb");
    if (fk==NULL)
    {
        printf("Failed to open %s\n", key);
        exit(-1);
    }
    
    dword length;
    fread(&length, 4, 1, fc);
    
    for (int i=0; i<length; i+=4)
    {
        dword c;
        fread(&c, 4, 1, fc);
        dword k;
        fread(&k, 4, 1, fk);
        dword p = c^k;
        
        fwrite(&p, 4, 1, fp);
    }
    
    fclose(fp);
    fclose(fc);
    fclose(fk);
}
