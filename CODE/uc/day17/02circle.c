//在线程处理函数中计算原型的周长和面积
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void* fuck(void* shit){
	int r = *(int*)shit;
	printf("圆周长：%lg\n",2*3.14*r);
	printf("圆面积：%lg\n",3.14*r*r);
}

int main(){
	int* radius = (int*)sbrk(4);
	if((int*)-1 == radius){
		perror("sbrk"),exit(-1);
	}
	printf("请输入半径：");
	scanf("%d",radius);
	//创建子线程
	pthread_t tid;
	int errno = pthread_create(&tid,NULL,fuck,(void*)radius);
	if(errno){
		printf("thread_create: %s\n",strerror(errno));
		exit(-1);
	}
//	sleep(2);
	//等待子线程结束
	errno = pthread_join(tid,NULL);
	if(0 != errno){
		printf("pthread_join: %s\n",strerror(errno));
		exit(-1);
	}

	brk(radius);//释放申请的内存
	return 0;
}
