#include <stdio.h>
#include "12get.h"
extern int num;		//一个文件想使用另外一个源文件的全局变量,需要再次声明。
int main(){
	print();
	printf("num is %d\n",num);
	return 0;
}
