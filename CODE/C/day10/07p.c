//指针返回值演示
#include<stdio.h>
int *read(void){
//	static int num;   //静态局部变量不可以初始化。。
	printf("plz input a number:");
	scanf("%d",&num);
	return &num;

}

int main(){
	int *p_num = read();
	printf("%d\n",*p_num);
	return 0;
}

