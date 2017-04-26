//编写程序从键盘得到多个整数（数量不超过5个，反序打印，然后打印求和结果）
#include <stdio.h>
/*int main(){
	int a,b,c,d,e;
	int i = 0;
	int sum = 0;
	printf("Input five numbers:");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int arr[5] = {a,b,c,d,e};
	for(i = 4;i >= 0;i--){
		printf("%d ",arr[i]);
		sum = sum + arr[i];
	}
		printf("sum = %d\n",sum);
	
	return 0;
}
*/


int main(){
	int arr[5] = {0},qty = 0,num = 0,pos = 4;
	int sum = 0;
	printf("Input counts of numbers:");
	scanf("%d",&qty);
	for (num = 1;num <= qty;num++){
		printf("Input a number:");
		scanf("%d",&arr[pos]);
		printf("%d",arr[num]);
		sum += arr[num];
		pos--;
	}
	printf("\n");
/*	for(num = pos + 1;num <= 4;num++){
	}
*/
	printf("Sun = %d\n",sum);
	return 0;
}



