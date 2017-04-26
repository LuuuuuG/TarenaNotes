//从键盘得到三个整数，从大到小输出
#include<stdio.h>

int main(){
	int num1 = 0,num2 = 0,num3 = 0,tmp = 0;
	int *p_num1 = &num1,*p_num2 = &num2,*p_num3 = &num3,*p_tmp = &tmp; 
	//声明三个指针变量分别和三个数字捆绑。
	printf("plz input three numbers:");
	scanf("%d%d%d",p_num1,p_num2,p_num3);
	if(*p_num1 < *p_num2){
		*p_tmp = *p_num1;
		*p_num1 = *p_num2;
		*p_num2 = *p_tmp;
	}
	if(*p_num1 < *p_num3){
		*p_tmp = *p_num1;
		*p_num1 = *p_num3;
		*p_num3 = *p_tmp;
	}
	if(*p_num2 < *p_num3){
		*p_tmp = *p_num2;
		*p_num2 = *p_num3;
		*p_num3 = *p_tmp;
	}
	printf("Numbers from bigger to smaller: %d %d %d\n",*p_num1,*p_num2,*p_num3);
	printf("num1,num2,num3 = %d %d %d\n",num1,num2,num3);
	return 0;
}
