//08free.c
//使用free函数释放动态内存的一般性原则
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	
	printf("当前进程的进程号是:%d\n",getpid());
	void* p1 = malloc(4096*2);
	printf("申请了2个内存页大小的动态内存\n");	//34
	getchar(); //scanf("%c",&c); 读取一个字符

	void* p2 = malloc(4096*30);
	printf("又申请了30个内存页大小的动态内存\n"); //34
	getchar();

	void* p3 = malloc(4096*3);
	printf("又申请了3个内存页大小的动态内存\n");	//67
	getchar();

	free(p3);
	p3 = NULL;
	printf("释放了3个内存页大小的动态内存\n");	//64
	getchar();

	free(p2);
	p2 = NULL;		
	printf("又释放了30个内存页大小的动态内存\n"); //34
	getchar();

	free(p1);
	p1 = NULL;
	printf("所有动态内存释放完毕\n");	//33
	getchar();

	return 0;
}



