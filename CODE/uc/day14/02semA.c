//使用信号量集实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<signal.h>
int semid;

void fuck(int shit){
	printf("正在删除,请骚等...\n");
	sleep(3);
	int res = semctl(semid,0,IPC_RMID);
	printf("删除成功\n");
	exit(0);
}

int main(){
	//1 获取key值   ftok
	key_t key = ftok(".",200);
	if(-1 == key){
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2 创建    semget
	semid = semget(key,1,IPC_CREAT|IPC_EXCL|0664);
	if(-1 == semid){
		perror("semget"),exit(-1);
	}
	printf("semid = %d\n",semid);
	//3 初始化    semctl
	//int arr[1]; arr[0] = 5;
	int res = semctl(semid,0/*信号量集的下标*/,SETVAL,5);
	if(-1 == res){
		perror("semctl"),exit(-1);
	}
	printf("初始化信号量集成功\n");
	//4 如果不使用则删除  semctl
	printf("删除信号量集请按ctrl+c...\n");
	signal(2,fuck);
	while(1);
	return 0;
}
