//使用wait函数等待子进程结束并获取退出状态信息
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	//1 创建子进程,使用fork函数
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork");
		exit(-1);
	}
	
	//2 子进程开始执行,20秒后终止
	if(0 == pid){
		printf("子进程%d开始执行\n",getpid());
		sleep(20);
		printf("子进程结束\n");
		exit(100);
	//	exit(256);    //WEXITSTATUS(status) = 0;   status & 0377
	}
	//3 父进程开始等待,并获取子进程的退出状态信息
	printf("父进程开始等待...\n");
	int status = 0;
	int res = wait(&status);
	if(-1 == res){
		perror("wait"),exit(-1);
	}
	if(WIFEXITED(status)){
		printf("父进程等待结束,终止的子进程是%d,该子进程的退出状态信息是：%d\n",res,WEXITSTATUS(status));
	}

	return 0;

}
