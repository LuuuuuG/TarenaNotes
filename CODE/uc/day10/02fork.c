//使用fork函数创建子进程
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	printf("main start\n");
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork"),exit(-1);
	}

	//printf("main end%d\n",pid);
	if(0 == pid){
		printf("pid =  %d, ppid = %d\n",getpid(),getppid());
		sleep(3);
		printf("pid =  %d, ppid = %d\n",getpid(),getppid());

	}
	else{
		sleep(1);
		printf("我是父进程,我的进程号是:%d，我的子进程是:%d\n",getpid(),pid);
	}
	
	return 0;
}
