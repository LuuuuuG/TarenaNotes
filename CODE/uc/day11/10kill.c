//使用kill函数发送信号
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fa(int signo){
	printf("捕获到了信号%d\n",signo);
}

int main(){
	//1 创建子进程 使用fork函数
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork"),exit(-1);
	}
	
	//2 子进程开始启动 设置对信号40进行自定义处理
	if(0 == pid){
		printf("子进程%d开始启动\n",getpid());
		//设置对信号40进行自定义处理
		signal(40,fa);
		while(1);
	}
	sleep(1);
	//3 父进程使用kill函数发送信号40给子进程
	if(0 == kill(pid,0)){
		printf("父进程开始发送信号40\n");
		kill(pid,40);
	}

	return 0;
}
