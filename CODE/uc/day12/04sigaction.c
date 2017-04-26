//使用sigaction函数设置信号的处理防护死
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fuck(int shit,siginfo_t *info,void* pv){
	printf("进程%d发送来了信号%d\n",info->si_pid,shit);
}

int main(){
	printf("pid = %d\n",getpid());
	//准备结构体变量并进行初始化
	struct sigaction action = {};
	//使用第二个函数指针来设置信号的处理方式
	action.sa_sigaction = fuck;
	action.sa_flags = SA_SIGINFO;

	//设置对信号2进行自定义处理
	int res = sigaction(SIGINT,&action,NULL);
	if(-1 == res){
		perror("sigaction");
		exit(-1);
	}
	printf("设置对信号的处理方式成功\n");
	while(1);
	return 0;
}
