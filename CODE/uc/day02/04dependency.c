// *pragma GCC dependency 的使用
#include<stdio.h>
//当前文件依赖于02lin.c
#pragma  GCC dependency  "01line.c"
int main(){
	printf("指定的文件有没有发生改动呢？？\n");
	return 0;
}
