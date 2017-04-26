//04map.c
//建立/接触虚拟地址到真实无力内存的映射
#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>

int main(){
	//1.使用mmap函数建立映射
	void* pv = mmap(NULL/*由系统内核指定*/,
	4,/*映射区域大小*/
	PROT_READ|PROT_WRITE,//可读可写的权限
	MAP_PRIVATE|MAP_ANONYMOUS,//映射无力内存
	0,
	0);
	if(MAP_FAILED == pv){
		perror("mmap");
		exit(-1);
	}
	printf("建立映射成功\n");
	//2.使用映射区域存放数据100
	*(int*)pv = 100;
	printf("映射区的数据是:%d\n",*(int*)pv);
	//3.使用munmap函数接触映射
	int res = munmap(pv,4);
	if(-1 == res){
		perror("munmap");
		exit(-1);
	}
	printf("映射成功\n");


	return 0;
}
