//pthread_join函数等待线程结束并获取退出状态信息
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
//int sum;
void* fuck(void* shit){
//	char* pc = "Hello";
	int i = 0;
//	static int sum = 0;
	int sum = 0;
	for(i = 1;i <= 100;i++){
		sum += i;
	}
//	return &sum;
	return (void*)sum;
}

int main(){
	//1 创建子线程 
	pthread_t tid;
	int errno = pthread_create(&tid,NULL,fuck,NULL);
	if(0 != errno){
		printf("pthread_create: %s\n",strerror(errno)),exit(-1);
	}
	//设置子线程为分离状态的线程
	errno = pthread_detach(tid);
	if(0 != errno){
		printf("pthread_detach: %s\n",strerror(errno)),exit(-1);
	}

	//2 等待子线程结束,并获取推出状态信息,打印
//	char* ps = NULL;
//	errno = pthread_join(tid,(void**)&ps);//
	int res = 0;
	errno = pthread_join(tid,(void**)&res);//提升为一级指针再强转为二级指针
	if(0 != errno){
		printf("pthread_join: %s\n",strerror(errno)),exit(-1);
	}
//	printf("主线程中:*ps = %d\n",*(int*)ps); //5050
	printf("主线程中:res = %d\n",res); //5050
	return 0;
}
