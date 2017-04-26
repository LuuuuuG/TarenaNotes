//08semaphore.c
//使用信号量 实现线程的同步问题
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

//自定义数组作为共享资源
char* buf[5]; //指针数组
//自定义变量记录数组下标
int pos;
// 1)定义信号量
sem_t sem;


void* fuck(void* shit){
	//3) 获取信号量 信号量-1
	sem_wait(&sem);
	//4) 访问共享资源
	buf[pos] = shit;
	sleep(1);
	pos++;
	//5）释放信号量 信号量+1
	sem_post(&sem);
}

int main(){
	//2)初始化信号量
	sem_init(&sem,0,1/*信号量初始值*/);
	//1 创建子线程
	pthread_t tid1;
	pthread_create(&tid1,NULL,fuck,"zhangfei");
	pthread_t tid2;
	pthread_create(&tid2,NULL,fuck,"guanyu");
	//2 等待子线程
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	//3 打印字符指针数组中的所有字符串内容
	int i = 0;
	for(i = 0;i < pos;i++){
		printf("%s ",buf[i]);
	}
	printf("\n");

	//6) 如果不再使用则 删除信号
	sem_destroy(&sem);
	return 0;
}
