//编写程序产生一张彩票，彩票里的数字个数由用户指定。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(0));
	int size = 0;
	int i = 0;
	int tmp = 0,cnt = 0;
	printf("Input the size of CaiPiao:");
	scanf("%d",&size);
	int arr[size];
/*	for(i = 0;i <= size;i++){
		arr[i] = rand() % 36 + 1;
		printf("%d ",arr[i]);
	}*/
	do{
		tmp = rand() % 36 + 1;
		for(i = 0;i <= cnt - 1;i++){
			if(arr[i] == tmp){
				break;
			}
		}
		if(i == cnt){
			arr[cnt] = tmp;
			cnt++;
		}
	}while(cnt < size);
	for(i = 0;i < size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
