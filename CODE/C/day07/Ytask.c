/*
编写程序产生一张彩票，彩票里包含7个1~36之间的随机数（数字可以重复）
 首先得到一张彩票，然后把彩票里的数字打印在屏幕上。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(0));
	int arr[7] = {0};
	int tmp = 0,num = 0;
	int i = 0,cnt = 0;
/*	for(i = 1;i <=7;i++){
		arr[i] = rand() % 36 +1;
	}
*/
	do{
		tmp = rand() % 36 +1;
		for(num = 0;num <= cnt - 1;num++){
			if(arr[num] == tmp){	//生成数字跟前面数字已有一样
				break;				//结束循环
			}
		}
		if (num == cnt){			//循环如果正常结束
			arr[cnt] = tmp;			//说明生成数字可以使用~
			cnt++;
		}
	}while(cnt <7);
	for(i = 0;i < 7;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
