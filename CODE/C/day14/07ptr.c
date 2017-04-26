//函数指针演示
#include <stdio.h>
int add(int num1,int num2){
	return num1 + num2;
}
int main(){
	int (*p_func)(int, int) = NULL; 	//函数指针初始化
	printf("add is %p\n",add);
	p_func = add;			//函数指针和函数捆绑
	printf("4+9 is %d\n",p_func(4,9));
	return 0;
}
