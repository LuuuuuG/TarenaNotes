//使用signal函数设置信号的处理方式
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
//自定义处理函数
void fa(int signo){
	printf("捕获到了信号%d\n",signo);
}
int main(){
	printf("pid = %d\n",getpid());
	//设置对信号2进行忽略处理
	if(SIG_ERR == signal(SIGINT/*2*/,SIG_IGN)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号2的忽略处理成功\n");
	//设置对信号3进行自定义处理
	if(SIG_ERR == signal(SIGQUIT/*3*/,fa)){
		perror("signal"),exit(-1);
	}
	printf("设置对信号3的自定义处理成功\n");
//	while(1);
	return 0;
}
