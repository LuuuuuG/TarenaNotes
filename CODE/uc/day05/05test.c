//05test.c
#include<stdio.h>

int main(){
	int* pi = (int*)0xbf80d4bc;
	printf("*pi = %d\n",*pi);   //理论上是20 实际发生段错误
	return 0;
}
