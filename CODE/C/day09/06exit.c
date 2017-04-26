#include<stdio.h>
#include<stdlib.h>
void func(void){
	printf("2\n");
//	return ; //立刻结束函数的执行
	exit(0);
	printf("3\n");
}

int main(){
	printf("1\n");
	func();
	printf("4\n");
	return 0;
}
