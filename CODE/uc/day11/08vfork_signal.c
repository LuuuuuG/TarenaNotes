//使用signal函数设置对信号的处理方式
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fa(int signo){
	printf("捕获到了信号%d\n",signo);
}

int main(){
	//1 设置对信号2进行自定义处理
	signal(2,fa);
	//2 设置对信号3进行忽略处理
	signal(3,SIG_IGN);
	//3 使用vfork函数创建子进程
	pid_t pid = vfork();
	if(-1 == pid){
		perror("vfork"),exit(-1);
	}
	//4 子进程开始执行,打印进程号,并调用execl函数
	if(0 == pid){
		printf("子进程%d开始执行\n",getpid());
		//调用execl函数进行条转
		execl("./proc","proc",NULL);
	}
	//5 父进程结束
	printf("父进程%d结束\n",getpid());
	return 0;
}
