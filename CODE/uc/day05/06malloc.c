//06malloc.c
//使用malloc函数申请动态内存是的注意事项
#include<stdio.h>
#include<stdlib.h>

int main(){

	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int));
	int* p4 = (int*)malloc(sizeof(int));
	int* p5 = (int*)malloc(sizeof(int));

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
	printf("p4 = %p\n",p4);
	printf("p5 = %p\n",p5);
	
	printf("-------------------\n");
	*p1 = 11;
//	*(p1+1) = 22;
//	*(p1+2) = 33;
//	*(p1+3) = 44;
	*(p1+4) = 55;

	printf("*p1 = %d\n",*p1);
	printf("*p2 = %d\n",*p2);
	
	free(p1);
	p1 = NULL;
	free(p2);
	p2 = NULL;
	return 0;
}
