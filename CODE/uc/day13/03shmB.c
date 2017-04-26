//打印共享内存中的数据

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<signal.h>

int main(){
	//1 获取key值 ftok
	key_t key = ftok(".",100);
	if(-1 == key){
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2 获取共享内存	shmget
	int shmid = shmget(key,0,0);
	if(-1 ==  shmid){
		perror("shmget"),exit(-1);
	}
	printf("shmid = %d\n",shmid);
	//  挂接			shmat
	void* pv = shmat(shmid,NULL,0);
	
	printf("挂接成功\n");
	//3 使用共享内存	
	printf("共享内存中的内容是:%d\n",*(int*)pv);
	//4 脱接			shmdt
	int res = shmdt(pv);
	if(-1 == res){
		perror("shmdt"),exit(-1);
	}
	printf("脱接共享内存成功\n");


	return 0;
}
