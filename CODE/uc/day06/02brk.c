//使用brk函数调整动态内存的大小
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
	//使用sbrk函数获取一个有效的地址
	void* pv = sbrk(0);
	if((void*)-1 == pv){
		perror("sbrk");
		exit(-1);
	}
	printf("pv = %p\n",pv);
	//使用brk函数申请4个字节的动态内存
	int res = brk(pv+4);
	if(-1 == res){
		perror("brk");
		exit(-1);
	}
	//使用sbrk函数获取当前动态内存的末尾地址
	void* cur = sbrk(0);
	printf("cur = %p\n",cur); //pv + 4
	
	//使用brk函数申请4个字节的动态内存
	res = brk(pv+8);
	if(-1 == res){
		perror("brk");
		exit(-1);
	}
	cur = sbrk(0);
	printf("cur = %p\n",cur); //pv + 8
	
	//释放所有的动态内存
	brk(pv);
	cur = sbrk(0);
	printf("cur = %p\n",cur);  //pv
	
	return 0;
}
