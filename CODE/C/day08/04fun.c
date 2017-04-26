#include<stdio.h>
int read(void){ //被调用函数
	int num = 0;
	printf("plz input a number:");
	scanf("%d",&num);
	return num;
}
int main(){
	int num = read();	 //调用read函数
	printf("num is %d\n",num);
	return 0;
}
