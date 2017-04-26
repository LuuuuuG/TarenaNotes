/*
用递归实现斐波那契数列
  1 1 2 3 5 8 13 21 ...
  0 1 2 3 4 5  6  7 ...
*/
#include <stdio.h>
int fei(int num){
	if(num <= 1){
		return 1;
	}
	return fei(num - 1) + fei(num - 2);
}

int main(){
	int num = 0;
	printf("plz input the code:");
	scanf("%d",&num);
	printf("the number is %d\n",fei(num));
	return 0;
}
