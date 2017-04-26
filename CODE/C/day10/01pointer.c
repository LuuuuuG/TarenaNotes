//指针演示
#include <stdio.h>
int main(){
	int num = 0;
	int *p_num = &num,*p_num1 = NULL;   //所有指针必须初始化，避免野指针！
	*p_num = 10;         // *用来找到num的存储区
	printf("num is %d\n",num);
	return 0;
}
