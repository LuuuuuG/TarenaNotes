//使用pthread_cancel函数来取消线程
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
void* fuck(void* shit){
	//设置该线程不可以被取消
	int errno = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	if(0 != errno){
		printf("pthread_setcancelstate: %s\n",strerror(errno));
		exit(-1);
	}
	while(1){
		printf("WTF!!!\n");
		sleep(1);
	}
}
void* fuck2(void* shit2){
	printf("正在发送取消请求，请骚等...\n");
	sleep(3);
	//调用pthread_cancel函数发送取消请求
	int errno = pthread_cancel(*(pthread_t*)shit2);
	if(0 != errno){
		printf("pthread_cancel: %s\n",strerror(errno));
		exit(-1);
	}
	printf("发送取消请求成功\n");
}

int main(){
	//1 创建子线程
	pthread_t tid1;
	int errno = pthread_create(&tid1,NULL,fuck,NULL);
	if(0 != errno){
		printf("pthread_create: %s\n",strerror(errno));
		exit(-1);
	}
	//再创建一个线程
	pthread_t tid2;
	errno = pthread_create(&tid2,NULL,fuck2,(void*)&tid1);
	if(0 != errno){
		printf("pthread_create: %s\n",strerror(errno));
		exit(-1);
	}
	
	//2 等待子线程结束 使用pthread_join函数
	errno = pthread_join(tid1,NULL);	
	if(0 != errno){
		printf("pthread_join: %s\n",strerror(errno));
		exit(-1);
	}
	// 等待子线程2结束
	errno = pthread_join(tid2,NULL);
	if(0 != errno){
		printf("pthread_join： %s\n",strerror(errno));
		exit(-1);
	}
	return 0;
}
