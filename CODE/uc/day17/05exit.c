//练习
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
void* fuck(void* shit){
	static int i = 0;
	for(i = 1;i <= 20;i++){
		if(10 == i){
			pthread_exit((void*)&i);
		}
		printf("i = %d\n",i);
		sleep(1);
	}
}

int main(){	
	//1 创建子线程
	pthread_t tid;
	int errno = pthread_create(&tid,NULL,fuck,NULL);
	if(0 != errno){
		printf("pthread_create: %s\n",strerror(errno));
		exit(-1);
	}
	//2 等待子线程结束 并获取退出状态信息，打印
	int* ps = NULL;
	errno = pthread_join(tid,(void**)&ps);
	if(0 != errno){
		printf("pthread_join: %s\n",strerror(errno)),exit(-1);
	}
	printf("主线程中：*ps = %d\n",*ps);

	return 0;
}
