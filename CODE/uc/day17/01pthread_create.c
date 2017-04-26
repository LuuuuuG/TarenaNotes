//创建新线程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
void* fuck(void* shit){
//	printf("子线程的编号是：%lu\n",pthread_self());
	pthread_t t1 = *(pthread_t*)shit;
	pthread_t t2 = pthread_self();
	int res = pthread_equal(t1,t2);
	if(0 != res){
		printf("两个线程的编号是相等的\n");
	}
	else{
		printf("两个线程的编号是不相等的\n");
	}

	int i = 0;
	for(i = 0;i < 10;i++){
		printf("WTF!!! + %d\n",i+1);
		sleep(1);
	}
	return NULL;
}

int main(){
	//准备变量，作为函数的实参
	//typedef unsigned long int pthread_t;
	//不同的操作系统中实现可能会不同
	pthread_t tid;
	//创建新线程
	//int errno = pthread_create(&tid,NULL,fuck,NULL);
	
	int errno = pthread_create(&tid,NULL,fuck,&tid);
	if(0 != errno){
		printf("thread_create: %s\n",strerror(errno));//模仿perror
		exit(-1);
	}
	sleep(3);
	printf("主线程中：tid = %lu,主线程自己的ID = %lu\n",tid,pthread_self());
	return 0;
}
