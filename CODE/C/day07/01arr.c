#include<stdio.h>

int main(){
	int arr[5] = {0};
	printf("arr is %p\n&arr[0] is %p\n",arr,&arr[0]);
	printf("sizeof(arr)is %d\n",sizeof(arr));
	return 0;
}
