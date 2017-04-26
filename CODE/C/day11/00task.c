// task of pointers
#include<stdio.h>
int *reverse(int *p_num,int size){
	int tmp = 0;
	int *p_start = p_num;			//数组第一个存储区
	int *p_end = p_num + size - 1;	//数组最后一个存储区

	while (p_start < p_end){		
		tmp = *p_start;	         	//交换头尾指针内容
		*p_start = *p_end;
		*p_end = tmp;
		p_start++;
		p_end--;
	}
	return p_num;
}

int main(){
	int num = 0;
	int arr[] = {1,2,3,4,5};
	int *p_num = reverse(arr,5);
	for(num = 0;num <= 4;num++){
		printf("%d ",*(p_num + num));
	}
	printf("\n");
	return 0;
}
