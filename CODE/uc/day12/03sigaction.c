//使用sigaction设置对信号的处理方式
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fuck(int shit){
	printf("正在处理信号%d，骚等...\n",shit);
	sleep(5);
	printf("处理信号完毕\n");
}

int main(){
	printf("pid = %d\n",getpid());
	//准备结构体变量并初始化
	struct sigaction action = {};
	
	action.sa_handler = fuck;//自定义函数
	
	//清空信号集
	sigemptyset(&action.sa_mask);
	
	//添加信号3到信号集中
	sigaddset(&action.sa_mask,3);

	//解除对触发信号处理函数信号的屏蔽
	action.sa_flags = SA_NODEFER;//解除的是信号2
	

	//设置对信号2进行自定义处理
	int res = sigaction(SIGINT/*2*/,&action,NULL);
	if(-1 == res){
		perror("sigaction"),exit(-1);
	}
	printf("设置信号的处理方式成功\n");

	while(1);
	return 0;
}
