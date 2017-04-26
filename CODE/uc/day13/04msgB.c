#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
typedef struct{
	long mtype;
	char buf[20];
}Msg;

int main(){
	//1 获取key值 ftok
	key_t key = ftok(".",150);
	if(-1 == key){
		perror("ftok"),exit(-1);
	}
	printf("ket = %#x\n",key);
	
	//2 获取消息队列
	int msqid = msgget(key,0);
	if(-1 == msqid){
		perror("msqid"),exit(-1);
	}
	printf("msqid = %d\n",msqid);
	
	//3 读取
	Msg msg = {};
	int res = msgrcv(msqid,&msg,sizeof(msg.buf),-2,0);
	printf("%ld,%s\n",msg.mtype,msg.buf);
	printf("读取数据成功\n");
	

	return 0;
}
