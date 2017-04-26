//基于socket的网络通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(){
	//1 创建socket socket
	int sockfd = socket(AF_INET,SOCK_DGRAM/*数据报*/,0);
	if(-1 == sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2 准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.3.168");
	//将字符串形式的ip地址转换成整数类型
	
	//3 绑定socket和通信地址 bind
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res ){
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");

	//4 进行通信 read/write
	char buf[100] = {0};
	res = read(sockfd,buf,sizeof(buf));
	if(-1 == res){
		perror("read"),exit(-1);
	}
	printf("客户端发来的消息是：%s,消息大小是:%d\n",buf,res);
	
	//5 关闭socket close
	res = close(sockfd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");

	return 0;
}
