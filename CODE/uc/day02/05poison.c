// #pragma  GCC  poison的使用

#include <stdio.h>
//采用宏定义进行瞒天过海
#define GOTO goto
//设置goto为毒药
#pragma	GCC	poison	goto
int main(){
	ok:			//标识符
		sleep(1);	//睡一秒~~~
		printf("I am strong !\n");
	GOTO ok;
	return 0;
}
