//指针和数组的关系
#include<stdio.h>

int main(){
	int arr[5] = {1,2,3,4,5};
	int *p_num = arr ; //用数组名称对指针初始化。
	int num = 0;
	for(num = 0;num <= 4;num++){
	//	printf("%d ",arr[num]);   // ok
	//	printf("%d ",*(arr + num));  //bad
	//	printf("%d ",p_num[num]);  // not good
		printf("%d ",*(p_num + num));  //best
	}
	printf("\n");
	return 0;
}
