//pthread_join函数等待线程结束并获取退出状态信息
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void* fuck(void* shit){
	char* pc = "Hello";
	return pc;
}

int main(){
	//1 创建子线程 
	pthread_t tid;
	int errno = pthread_create(&tid,NULL,fuck,NULL);
	if(0 != errno){
		printf("pthread_create: %s\n",strerror(errno)),exit(-1);
	}
	//2 等待子线程结束,并获取推出状态信息,打印
	char* ps = NULL;
	errno = pthread_join(tid,(void**)&ps);
	if(0 != errno){
		printf("pthread_join: %s\n",strerror(errno)),exit(-1);
	}
	printf("主线程中:ps = %s\n",ps); //"Hello"
	return 0;
}
