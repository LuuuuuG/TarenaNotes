//使用共享内存实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>
int shmid;//定义全局变量

void fuck(int shit){
	printf("\n正在删除共享内存,请骚等...\n");
	int res = shmctl(shmid,IPC_RMID,NULL);
	sleep(3);
	if(-1 == res){
		perror("shmctl"),exit(-1);
	}
	printf("删除共享内存成功\n");
	exit(0);//终止当前进程
}

int main(){
	//1获取key值 使用ftok函数
	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);// %x  -以十六进制打印 %#x 打印0x+十六进制
	//2创建共享内存 shmget
	shmid = shmget(key,4/*size*/,IPC_CREAT|IPC_EXCL|0664);
	if(-1 == shmid){
		perror("shmget"),exit(-1);
	}
	printf("shmid = %d\n",shmid);
	//3 挂接      shmat
	void* pv = shmat(shmid,NULL,0);
	if((void*)-1 == pv){
		perror("shmat"),exit(-1);
	}
	printf("挂接共享内存成功\n");
	//4使用
	//*(int*)pv = 200;
	int* pi = pv;
	*pi = 200;
	//5脱接		shmdt
	int res = shmdt(pv);
	if(-1 == res){
		perror("shmdt"),exit(-1);
	}
	printf("脱接共享内存成功\n");
	//6股不再使用 则删除
	printf("删除共享内存请按ctrl+c...\n");
	signal(SIGINT,fuck);
	while(1);	
	
	return 0;
}
