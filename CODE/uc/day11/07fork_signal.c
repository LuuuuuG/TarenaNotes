#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fa(int signo){
	printf("捕获到了信号%d\n",signo);
}

int main(){
	printf("pid = %d\n",getpid());
	//设置对信号2进行自定义处理
	if(SIG_ERR == signal(SIGINT,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号2的自定义处理成功\n");
	//设置对信号3进行忽略处理
	if(SIG_ERR == signal(SIGQUIT,SIG_IGN)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号3的忽略处理成功\n");
	
	//创建子进程
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork"),exit(-1);
	}
	if(0 == pid){
		printf("子进程%d开始执行\n",getpid());
		while(1);
	}
	printf("父进程结束\n");
	return 0;
}
