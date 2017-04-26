// #warning #error 的使用
#include<stdio.h>
#define VERSION 2
#if(VERSION > 3)
	#warning "版本过高"
#elif(VERSION < 3)
	#error "版本过低"
#endif
int main(){

	printf("警告才能看到这句话呦~\n");
	return 0;
}
