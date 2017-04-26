//static 变量演示

#include<stdio.h>
void func(void){
	static int num = 3;
	printf("num is %d\n",num);
	num = 10;
}
void func1(void){   //排除第二次打印是10的偶然因素
	int num = 10;
	int num1 = 11;
	int num2 = num + num1;
}
int main(){
	func();
	func1();
	func();
	return 0;
}
