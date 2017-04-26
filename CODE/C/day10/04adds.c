//地址数据演示

#include<stdio.h>

int main(){
	
	int arr[5] = {1,2,3,4,5};
	int *p_num = arr;
	printf("sizeof(arr) is %d\n",sizeof(arr));
	printf("sizeof(p_num) is %d\n",sizeof(p_num));
	
	return 0;

}
