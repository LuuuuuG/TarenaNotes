//回调函数演示
#include <stdio.h>
/*void print(int *p_num,int size){
	int num = 0;
	for (num = 0;num <= size - 1;num++){
		printf("%d ",*(p_num + num));
	}
}*/

void print_cb(int *p_num){
	printf("%d ",*p_num);
}
void neg_cb(int *p_num){
	*p_num = 0 - *p_num;
}

void for_each(int *p_num,int size,void (*p_func)(int*)){	//处理数组每一个存储区   
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		p_func(p_num + num);	//函数名称换为函数指针名称
	}
}
int main(){
	int arr[] = {1,2,3,4,5};
	for_each(arr,5,print_cb);	//函数指针和print_cb函数捆绑
	printf("\n");
	for_each(arr,5,neg_cb);
	for_each(arr,5,print_cb);	//函数指针和print_cb函数捆绑
	printf("\n");
	return 0;
}
