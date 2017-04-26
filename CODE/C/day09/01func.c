#include<stdio.h>
void print(int num,int num1/*形参*/){ //每个形参的类型不能省略
	printf("%d %d\n",num,num1);
}
int main(){
	print(4,6/*实参*/);
	return 0;
}
