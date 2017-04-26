//01sbrk.c
//使用sbrk函数调整动态内存的大小
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

int main(){
	void* p1 = sbrk(4);
	//使用sbrk函数申请4个字节的动态内存
	if((void*) -1 == p1){
		perror("sbrk");
		exit(-1);
	}
	printf("p1 = %p\n",p1);  //0
	
	void* p2 = sbrk(4);
	if((void*) -1 == p2){
		perror("sbrk");
		exit(-1);
	}
	printf("p2 = %p\n",p2);  //4
	
	void* p3 = sbrk(4);
	if((void*)-1 == p3){
		perror("sbrk");
		exit(-1);
	}
	printf("p3 = %p\n",p3);  //8

	//获取当前动态内存的末尾地址
	void* p_end = sbrk(0);
	if((void*)-1 ==p_end){
		perror("sbrk");
		exit(-1);
	}
	printf("p_end = %p\n",p_end);  //12

	printf("-----------------------\n");
	//使用sbrk函数释放4个字节动态内存
	void* p4 = sbrk(-4);
	printf("p4 = %p\n",p4);	//p_end

	void* cur = sbrk(0);
	printf("cur = %p\n",cur); //p3
	
	printf("-----------------------\n");
	void* p5 = sbrk(-4);
	printf("p5 = %p\n",p5);//p3

	cur = sbrk(0);
	printf("cur = %p\n",cur);//p2
	
	printf("-----------------------\n");
	printf("当前进程的进程号是:%d\n",getpid());
	printf("当前进程中拥有4个字节的动态内存\n");
	getchar();

	sbrk(4093);
	printf("申请了4093个字节的动态内存,此时总量恰好超过了1个内存页大小\n");
	getchar();

	sbrk(-1);
	printf("释放了1个字节的动态内存,此时剩下的动态内存正好是一个内存页\n");
	getchar();

	sbrk(-4096);
	printf("所有动态内存释放完毕\n");
	getchar();
	return 0;
}




















