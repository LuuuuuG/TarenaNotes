//07mutex.c
//使用互斥量 实现线程的同步问题
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//自定义数组作为共享资源
char* buf[5]; //指针数组
//自定义变量记录数组下标
int pos;
// 1)定义互斥量
pthread_mutex_t mutex;


void* fuck(void* shit){
	//3) 使用互斥量进行加锁
	pthread_mutex_lock(&mutex);
	//4) 访问共享资源
	buf[pos] = shit;
	sleep(1);
	pos++;
	//5）使用互斥量进行解锁
	pthread_mutex_unlock(&mutex);
}

int main(){
	//2)初始化互斥量
	pthread_mutex_init(&mutex,NULL);
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

	//6) 如果不再使用则 删除互斥量
	pthread_mutex_destroy(&mutex);
	return 0;
}
