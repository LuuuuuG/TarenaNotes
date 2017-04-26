//用指针做形参将数组的内容打印在屏幕上

#include<stdio.h>
void print(int *p_num){
	int num = 0;
	for (num = 0;num <= 4;num++){
	printf("%d ",*(p_num + num));
	}
}
/*
int main(){
	int num = 0;
	int arr[5] = {1,2,3,4,5};
	int *p_num = arr;
	print(p_num);
	printf("\n");
	return 0;
}

*/


void print(int arr[],int size){
	int num = 0;
	for (num = 0;num <= size - 1;num++){
	printf("%d ",arr[num]);
	}


}


int main(){
	int arr[5] = {1,2,3,4,5};
	
	print(arr,5);
	printf("\n");
	return 0;
}
