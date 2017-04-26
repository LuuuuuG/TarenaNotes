//使用消息队列实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
int msqid;
//定义消息的数据类型
void fuck(int shit){
	printf("\n正在删除消息队列,请骚等...\n");
	int res = msgctl(msqid,IPC_RMID,NULL);
	sleep(3);
	printf("删除消息队列成功\n");
	exit(0);
}


typedef struct{
	long mtype;
	char buf[20];
}Msg;

int main(){
	//1 获取key值   ftok
	key_t key = ftok(".",150);
	if(-1 == key){
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	
	//2创建消息队列	msgget
	msqid = msgget(key,IPC_CREAT|IPC_EXCL|0664);
	if(-1 == msqid){
		perror("msgget"),exit(-1);
	}
	printf("msqid = %d\n",msqid);
	
	//3 发送消息	msgsnd
	Msg msg1 = {1,"hello"};
	Msg msg2 = {2,"world"};
	int res = msgsnd(msqid,&msg2,sizeof(msg2.buf),0);//发送消息2
	if(-1 == res){
		perror("msgsnd"),exit(-1);
	}
	printf("发送类型为2的消息成功\n");
	res = msgsnd(msqid,&msg1,sizeof(msg1.buf),0);//发送消息1
	if(-1 == res){
		perror("msgsnd"),exit(-1);
	}
	printf("发送类型为1的消息成功\n");
	
	//4 如果不再使用,则删除消息队列
	printf("删除消息队列请按ctrl+c...\n");
	signal(2,fuck);
	while(1);
	return 0;
}
