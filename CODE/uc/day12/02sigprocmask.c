//使用sigprocmask函数设置信号的屏蔽
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fuck(int shit){
//	printf("捕获到了信号%d\n",shit);
}

int main(){
	printf("pid = %d\n",getpid());
	//1 设置对信号2、3、50进行自定义处理
	signal(2,fuck);
	signal(3,fuck);
	signal(50,fuck);
	//2 睡眠20秒 观察效果
	int res = sleep(20);
	if(0 == res){
		printf("妹妹睡了一觉\n");
	}
	else{
		printf("没有信号屏蔽,睡眠被打断,睡了%d秒\n",20-res);

	}

	//3 使用sigprocmask设置屏蔽信号2、3、50
	printf("---------信号屏蔽-------------\n");
	//准备信号集的变量
	sigset_t set,old;
	//清空两个信号集
	sigemptyset(&set);
	sigemptyset(&old);
	//添加信号2 3 50 到信号集set中
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,50);
	//设置信号的屏蔽
	res = sigprocmask(SIG_SETMASK,&set,&old);
	if(-1 == res){
		perror("sigprocmask"),exit(-1);
	}
	printf("设置信号的屏蔽成功,old = %d\n",old);
	//4睡眠20秒，观察效果
	res = sleep(30);
	if(0 == res){
		printf("sleep like a shit\n");
	}
	else{
		printf("you can't see me!\n");
	}
	//获取信号屏蔽期间来过的信号
	sigset_t pend;
	sigemptyset(&pend);//清空
	res = sigpending(&pend);
	if(-1 == res){
		perror("sigpending"),exit(-1);
	}
	//判断信号2是否来过
	if(1 == sigismember(&pend,2)){
		printf("信号2来过\n");
	}
	if(1 == sigismember(&pend,3)){
		printf("信号3来过\n");
	}
	
	if(1 == sigismember(&pend,50)){
		printf("信号50来过\n");
	}
	//恢复系统默认的屏蔽
	sigprocmask(SIG_SETMASK,&old,NULL);


	return 0;
}













