#include<stdio.h>
void print(int arr[5]){
	int num = 0;
	for(num = 0;num <= 4;num++){
		printf("%2d ",arr[num]);
	}
	printf("\n");
}

void negnum(int arr[5]){
	int num = 0;
	for(num = 0;num <= 4;num++){
		arr[num] =0 - arr[num];
	}
}

int main(){
	int arr[] = {1,2,3,4,5};
	print(arr);
	negnum(arr);
	print(arr);
	return 0;
}
