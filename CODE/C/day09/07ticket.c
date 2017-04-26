#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ticket(int arr[7]){
	srand(time(0));
	int num = 0;
	for(num = 0;num <= 6;num++){
		arr[num] = rand() % 36 + 1;
	}
	for(num = 0;num <= 6;num++){
		printf("%d ",arr[num]);
	}
}

int main(){
	int arr[7] = {0};
	ticket(arr);
	printf("\n");
	return 0;
}

/*  Mr.Yang
void ticket(int arr[],int size){
	int num = 0;
	for(num = 0;num <= size - 1;num++){
		arr[num] = rand() % 36 + 1;
	}

}

int main(){
	srand(time(0));
	int arr[7] = {0},num = 0;
	ticket(arr,7);
	for (num = 0;num <= 6;num++){
		printf("%d ",arr[num]);
	}
	printf("\n");
	return 0;
}*/
