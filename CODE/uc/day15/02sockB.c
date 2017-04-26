//基于socket的本地通信
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>

int main(){
	//1创建socket  
	int sockfd = socket(AF_UNIX,SOCK_DGRAM/*数据报通信方式*/,0);
	if(-1 == sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	
	//2准备通信地址 使用结构体
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path,"a.sock");
	
	//3 链接socket和通信地址 bind函数
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("connect"),exit(-1);
	}
	printf("链接socket和通信地址成功\n");
	
	//4 进行通信 使用read/write函数
	res = write(sockfd,"hello",6);
	if(-1 == res){
		perror("read"),exit(-1);
	}
	printf("成功发送数序到服务器,消息大小是：%d\n",res);
	
	//5 关闭socket 使用close函数
	res = close(sockfd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}
