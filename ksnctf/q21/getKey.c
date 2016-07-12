// encrypt.cppとencrypt.encのxorを取ることによって、暗号化に使われていたkeyを求める
// ただし、encrypt.encの先頭4byteにはファイルには平文のサイズが格納されているため、4byteずらす。

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long dword;
int min(int a, int b) { return a<b ? a : b; }

int main(void){

	char plain[] = "encrypt.cpp";
	char crypt[] = "encrypt.enc";
	char key[] = "encrypt.key";

	// 平文を開く
    FILE *fp = fopen(plain, "rb");
    if (fp==NULL)
    {
        printf("Failed to open %s\n", plain);
        exit(-1);
    }

    // 暗号文を開く
    FILE *fc = fopen(crypt, "rb");
    if (fc==NULL)
    {
        printf("Failed to open %s\n", crypt);
        exit(-1);
    }

    // 鍵を開く
    FILE *fk = fopen(key, "wb");
    if (fk==NULL)
    {
        printf("Failed to open %s\n", key);
        exit(-1);
    }
    
    unsigned long length;
    fread(&length, 4, 1, fc);    
    for(int i = 0; i < length; i += 4){
        unsigned long p;
        fread(&p, 4, 1, fp);
        unsigned long c;
        fread(&c, 4, 1, fc);
        unsigned long k;
        k = p ^ c;
        fwrite(&k, 4, 1, fk);
    }
    
    fclose(fp);
    fclose(fc);
    fclose(fk);
}