/*
身份证前17个号码和下面17个数字对应相乘
(7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2)

把所有乘积求和，用求和结果除11取余，用余数到下面11个数字里挑选
(1,0,x,9,8,7,6,5,4,3,2)
挑选的结果就是第18位的数字

*/
#include<stdio.h>
/*
int main(){
	int arr[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int i = 0,num = 0,sum = 0,last_num = 0;
	for(i = 0;i < 17;i++){
		printf("输入你身份证的第%d位：",i);
		scanf("%d",&num);
		sum = sum + arr[i] * num;
	}

		last_num = sum % 11; 
	int arr2[11] = {1,0,999,9,8,7,6,5,4,3,2};
		if( arr2[last_num] == 2){
			printf("最后一位是x\n");    
		}   
		else{
			printf("最后一位是%d\n",arr2[last_num]);    
		}
	
	return 0;
}
*/

int main(){
	int card[17] = {0},arr[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char arr1[11] = {'1','0','x','9','8','7','6','5','4','3','2'};
	int num = 0,sum = 0;
	for (num = 0;num <= 16;num++){
		 printf("输入你身份证的第%d位：",num+1);
		 scanf("%d",&card[num]);
	}
	for (num = 0;num <= 16;num++){
		sum += card[num] * arr[num];
	}
		printf("最后一位是%c\n",arr1[sum % 11]);
	
	return 0;
}
