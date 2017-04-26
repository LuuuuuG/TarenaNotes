#include<stdio.h>
#define 	ABS(n)		n >= 0 ? n : 0 - n
#define 	NEG(n)		n = 0 - n
void neg(int *p_num){			//利用指针形参跨函数使用存储区
	*p_num = 0 - *p_num;
}

int abs(int num){
	if(num >= 0){
		return num;
	}
	else{
		return 0 - num;
	}
}
int main(){
	int num = 0;
	printf("plz input a num:");
	scanf("%d",&num);
	printf("abs(num) is %d\n",abs(num));
	printf("ABS(num) is %d\n\n",ABS(num));
	neg(&num);
	printf("NEG(num) is %d\n",num);
	NEG(num);
	printf("NEG(num) is %d\n",num);
	return 0;
}
