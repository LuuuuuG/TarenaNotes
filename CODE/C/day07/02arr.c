#include<stdio.h>

int main(){
	int size = 0;
	printf("请输入存储区个数：");
	scanf("%d",&size);
	int arr[size];	//变长数组声明。
	printf("sizeof(arr) is %d\n",sizeof(arr));
	return 0;
}
