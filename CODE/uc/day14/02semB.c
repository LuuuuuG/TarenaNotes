#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<signal.h>
/*
typedef struct{
	unsigned short sem_num;
	short sem_op;
	short sem_flg;
}Sem;
*/

int main(){
	//1 获取key值
	key_t key = ftok(".",200);
	if(-1 == key){
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2 获取
	int semid = semget(key,0,0);
	if(-1 == semid){
		perror("semget"),exit(-1);
	}
	printf("semid = %d\n",semid);
	//3 操作 控制进程个数   semop
	int i = 0;
	for(i = 0;i < 10;i++){
		//创建子进程 
		pid_t pid = fork();
		if(-1 == pid){
			perror("fork"),exit(-1);
		}
		//子进程模拟抢占资源的过程
		if(0 == pid){
			//准备结构体变量并初始化
			struct sembuf buf = {};
			buf.sem_num = 0;//信号量集的下标
			buf.sem_op = -1;//信号量数值减1
			buf.sem_flg = 0;//操作的标志
			
			//信号量的数值减1 使用semop函数
			int res = semop(semid,&buf,1/*结构体变量的个数*/);
			if(-1 == res){
				perror("semop"),exit(-1);
			}
			printf("进程%d申请共享资源成功\n",getpid());
		
			//模拟占用资源20秒
			sleep(20);
			
			//模拟释放共享资源
			buf.sem_op = 1;
			res = semop(semid,&buf,1);
			if(-1 == res){
				perror("semop"),exit(-1);
			}
			printf("进程%d释放资源\n",getpid());
			exit(0);//终止子进程
			
		}
	}
	return 0;
}
