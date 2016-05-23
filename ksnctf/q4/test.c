#include<stdio.h>

void printHack(){
	printf("You got FLAG!!\n");
}

int main(void){
	char str[256];
	fgets(str, sizeof str, stdin);
	printf(str);
	putchar('\n');
	return 0;
}
