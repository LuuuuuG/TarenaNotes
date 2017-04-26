//使用malloc函数申请动态内存时的一般性原则

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	printf("当前进程的进程号是:%d\n",getpid());
	//十六进制的21000 本质上是33个内存页的大小
	//十六进制的1000 本质上是1个内存页的大小
	int* pi = (int*)malloc(sizeof(int));
	printf("pi = %p\n",pi);
	//故意越界试一下,但是不超过33个内存页的范围
//	*(pi + 1024*30) = 250;
//	printf("*(pi + 1024*30) = %d\n",*(pi + 1024*30));
	
	//故意越界试一下,并且超过33个内存页的范围
	*(pi + 1024*33) = 250;
	printf("*(pi + 1024*33) = %d\n",*(pi + 1024*33));
	
	while(1);
	return 0;
}
