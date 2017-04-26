#include<stdio.h>
void print(int arr[],int size){ //声明一个size变量
	int num = 0;
	for (num = 0;num <= size - 1;num++){
		printf("%d ",arr[num]);
	}
	printf("\n");
}
void clear(int arr[],int size){//将数组内容清零
	int num = 0;
	for (num = 0;num <= size -1;num++){
		arr[num] = 0;
	}
}

int main(){
	int arr[] = {1,2,3,4,5};//提供形参
	print(arr,5);
	clear(arr,5);
	print(arr,5);
	return 0;
}
