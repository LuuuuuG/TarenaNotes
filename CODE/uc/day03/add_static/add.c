//add.c
#include "add.h"
//#include "../add.h"  //优先从上一级目录找头文件

int add_int(int a,int b){
	printf("静态库的使用测试\n");
	printf("test\n");
	return a + b;
}
