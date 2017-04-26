//scanf

#include <stdio.h>
int main(){
	int num = 0,num1 = 0;
	printf("input a number:");
	scanf("%d",&num);
	scanf("%*[^\n]");   // 丢掉前面第一次
	scanf("%*c");       //输入的内容！！！
	printf("num is %d\n",num);
	printf("input a number:");
	scanf("%d",&num1);
	printf("num is %d\n",num1);
	return 0;
}

