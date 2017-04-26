//使用sigqueue函数发送信号和附加数据
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void fuck(int shit,siginfo_t* info,void* pv){
	printf("进程%d发来的信号是%d,发来的附加数据是%d\n",info->si_pid,shit,info->si_value);
}

int main(){	
	//1.创建子进程 使用fork函数
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork"),exit(-1);
	}
	//2 子进程启动 设置对信号40进行自定义处理
	if(0 == pid){
		printf("子进程%d开始启动\n",getpid());
		//准备结构体变量并初始化
		struct sigaction action = {};
		action.sa_sigaction = fuck;
		action.sa_flags = SA_SIGINFO;
		sigaction(40,&action,NULL);
		while(1);//子进程进入无限循环
	}
	//3 父进程启动 使用sigqueue函数发送信号40和1~100之间整数给子进程
	sleep(1);
	printf("父进程%d开始启动\n",getpid());
	int i = 0;
	for(i = 1;i <= 100;i++){
		//定义联合变量并初始化
		union sigval val;
		val.sival_int = i;
		int res = sigqueue(pid,40,val);
		if(-1 == res){
			perror("sigqueue"),exit(-1);
		}
		sleep(1);
	}


	return 0;
}
