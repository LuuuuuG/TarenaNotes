//把调用函数中两个变量的内容交换

#include<stdio.h>
/*
void point(*p_num,int size){
	int num = 0;
	for(num = size - 1;num >= 0;num--){
		printf("%d ",*(p_num - num));
	}

}


int main(){
	int arr[] = {1,2};
	
	print(arr,2);

	return 0;
}*/

void swap(int *p_num1,int*p_num2){
	int tmp = *p_num1;
	*p_num1 = *p_num2;
	*p_num2 = tmp;

}

int main(){
	int num1 = 3,num2 = 7;
	swap(&num1,&num2);
	printf("num1 = %d num2 = %d\n",num1,num2);
	return 0;
}
