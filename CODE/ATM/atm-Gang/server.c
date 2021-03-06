#include"bank.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<signal.h>
#include<sys/wait.h>

static int msgid1;
static int msgid2;

//创建消息队列
void init(void){
	 printf("服务器正在初始化，请稍后...\n");
	 sleep(2);
	 //创建第一个消息队列
	 msgid1 = msgget(key1,IPC_CREAT|IPC_EXCL|0666);
	 if(-1 == msgid1)
	 {
		perror("创建消息队列一失败");	
		exit(-1);			
	 }
	 printf("消息队列一创建成功\n");
	 //创建第二个消息队列
	 msgid2 = msgget(key2,IPC_CREAT|IPC_EXCL|0666);
	 if(-1 == msgid2)
	 {
			perror("创建消息队列二失败");
			exit(-1);
	 }
	 printf("消息队列二创建成功\n");
	 printf("服务器初始化成功\n");
}

//工作
void start(void)
{
	pid_t pid_open = vfork();
	if(-1 == pid_open)
	{
		perror("创建子进程失败");
		exit(-1);
	}
	if(0 == pid_open)
	{
		//实现开户的功能
		execl("./open","open",NULL);
	}
	//父进程等待子进程结束
	waitpid(pid_open,NULL,0);
}

int main(void)
{
	 //程序退出时，自动执行
	 atexit(destroy);
	 printf("关闭服务器请按CTRL+C\n");
	 signal(SIGINT,sig_exit);
	 //初始化服务器
	 init();
	 //调用start方法
	 start();
	 //关闭服务器
	 //destroy();
	 return 0;
}

























