//函数演示
#include<stdio.h>

void print(void){
	int num = 0;
	printf("1\n");
}
void func(void){
	int num;
	printf("num is %d\n",num);
	num = 10;
}
void func1(void){	//排除偶然两次调用func函数的因素
	int num = 10;
	int num1 = 11;
	int num2 = num + num1;

}
int main(){
	int num = 0;
//	print();	
	func();
	func1();
	func();
	return 0;
}
