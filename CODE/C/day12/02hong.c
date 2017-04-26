#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define     SIZE      
int main(){
	int arr[SIZE] = {0},num = 0;	 //用宏来表示数组个数为定长数组
	srand(time(0));
	for(num = 0;num <= SIZE - 1;num++){
		arr[num] = rand() % MAX	+ 1;
	}
	for(num = 0;num <= SIZE - 1;num++){
		printf("%d ",arr[num]);
	}
	printf("\n");
	return 0;
}
