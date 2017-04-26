//递归函数演示
#include<stdio.h>
void print(int num){
	if (num == 1){
		printf("1 ");
		return ;
	}
	print(num - 1);	//假设递归函数已经完成，打印从1开始到num - 1
	printf("%d ",num);//打印num
}

int main(){
	int num = 0;
	printf("plz intput a number:");
	scanf("%d",&num);
	print(num);
	printf("\n");
	return 0;
}
