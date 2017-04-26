//const关键字演示
#include<stdio.h>

int main(){	
	int num = 0;
	const int *p_num = &num;
//	*p_num = 10;    //不能通过指针对捆绑存储区赋值；
	p_num = NULL;	//可以对指针本身的存储区赋值

	int const p_num1 = &num;
	*p_num1 = 10;   //可以对对指针捆绑存储区做赋值
//	p_num1 = NULL;  //不能对指针本身做赋值。
	return 0;
}
