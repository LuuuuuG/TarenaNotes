/*
编写程序 从键盘得到一个非负整数
，统计出它里面包含的所有个位数的数量

	千位 1233 / 1000 = 1 
*/
#include<stdio.h>
/*
int main(){
	int num = 0;
	int i = 0,j = 0,cnt = 0;
	int same = 0;
	int arr[] = {0};
	printf("Input a number:");
	scanf("%d",&num);
	//i用来计算输入的数有多少位
	do{
		cnt = cnt / 10;
		
		i++;

	}while(cnt >= 10);
	arr[0] = num % (10^i);
	//将输入的数按位放入数组中。
	for(j = i;j >= 1 ;j--){
		arr[j] = num / (10^i);
		num = num % (10^i);
		
	} 
	//统计与个位数相同的
	for(j = i;j >= 0;j--){
		if(arr[j] == arr[0]){
			same++;
			printf("包含个位数%d个\n",same);
		}
		else{
			printf("包含个位数0个\n");
			break;		
		}
	}

	return 0;
}

*/


int main(){
	int arr[10] = {0},num = 0;
	printf("请输入一个数字：");
	scanf("%d",&num);
	do{
		arr[num %10]++;
		num /= 10;		//丢掉最右边的数
	}while(num);

	for(num = 0;num <= 9;num++){
		if(arr[num]){
			printf("数字%d出现的次数是%d\n",num,arr[num]);
		}
	}
	return 0;
}



















