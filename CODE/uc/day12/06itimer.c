//计时器的使用
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<signal.h>
void fuck(int shit){
	printf("捕获到了信号%d\n",shit);

}

int main(){
	//1 设置对信号SIGALRM进行自定义处理
	signal(SIGALRM,fuck);
	//2 使用setitimer启动计时器
	//准备结构体变量 并初始化
	struct itimerval timer;
	//设置间隔时间
	timer.it_interval.tv_sec = 1;
	timer.it_interval.tv_usec = 300000;
	//设置启动时间
	timer.it_value.tv_sec = 5;
	timer.it_value.tv_usec = 0;

	//2.使用setitimer启动计时器
	int res = setitimer(ITIMER_REAL,&timer,NULL);
	if(-1 == res){
		perror("setitimer"),exit(-1);
	}
	printf("设置计时器成功\n");
	
	getchar();
	//3 关闭计时器
	printf("关闭计时器\n");
	timer.it_value.tv_sec = 0;//启动时间设置为0
	res = setitimer(ITIMER_REAL,&timer,NULL);
	if(-1 == res){
		perror("setitimer"),exit(-1);
	}
	while(1);

	return 0;
}
