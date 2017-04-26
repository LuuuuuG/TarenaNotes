#include<stdio.h>
int main(){
	int arr[3][2] = {0};
	printf("arr is %p\n&arr[0][0]is %p\n",arr,&arr[0][0]);
	printf("sizeof(arr) is %d\n",sizeof(arr));
	printf("arr[1] is %p\n&arr[1][0]is %p\n",arr[1],&arr[1][0]);
	printf("sizeof(arr[1]) is %d\n",sizeof(arr[1]));
	return 0;
}
