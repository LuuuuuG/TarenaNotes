/*编写递归函数，计算从1开始到某个整数之间
  所有整数的和。
  */
#include<stdio.h>
int sum(int num){
	if(num == 1){
		return 1;
 	}
	 
	 return sum(num - 1) + num;	
}

int main(){
	int num = 0;
	printf("plz input a number:");
	scanf("%d",&num);
	printf("sum = %d\n",sum(num));
	return 0;
  }
