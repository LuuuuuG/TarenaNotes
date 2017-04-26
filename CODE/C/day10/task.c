/*
	编写函数把一个数组里的所有存储区内容前后颠倒。
		如数组里原有内容是 1 2 3 4 5 
		颠倒后的内容为 5 4 3 2 1 
	要求用返回值表示处理后的数组，用指针编写程序。
*/

#include <stdio.h>
/*int reverse(int *p_num){
	int num = 0;
	for (num = 4;num >= 0;num-- ){
		printf("%d ",*(p_num + num));
	}
}
int main(){
	int arr[] = {1,2,3,4,5};
	reverse(arr);
	printf("\n");
	return 0;
}
*/

int reverse(int *p_num){
	int num = 0;
	int arr[5] = {0}; 
	for (num = 0;num <= 4;num++){
		 arr[4 - num] = *(p_num + num);
	}
	for(num = 0;num <= 4;num++){
		printf("%d ",arr[num]);
	}
}
int main(){
	int arr[] = {1,2,3,4,5};
	reverse(arr);
	printf("\n");

	return 0;
}
