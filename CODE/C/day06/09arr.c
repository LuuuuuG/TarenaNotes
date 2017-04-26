//数组演示
#include <stdio.h>
int main(){
	int arr[5] = {1,2,3,4,5};		//声明数组并初始化，
									//5代表数组里的存储区个数
	int i = 0;
	//arr[2] = 10;
	//printf("arr[2] is %d\n",arr[2]);
/*	for (i = 0;i <= 4;i++){
		arr[i] = i + 1;
	}*/
	for (i = 4;i >=0;i--){
		printf("%d",arr[i]);
	}
	printf("\n");
	return 0;
}
