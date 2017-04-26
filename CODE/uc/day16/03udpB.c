//基于UDP协议的通信模型
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	//1 创建socket
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	
	//2 准备通信地址,使用结构体类型
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.3.171");

	//3 进行通信 使用recv/send/...
//	int res = send(sockfd,"Hello",6,0);
	int res = sendto(sockfd,"&_&",6,0,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("sendto"),exit(-1);
	}
	printf("客户端发送数据成功,发送的数据大小是：%d\n",res);
	//接收服务器回发的消息
	char buf[233] = {0};
	res = recv(sockfd,buf,sizeof(buf),0);
	if(-1 == res){
		perror("recv"),exit(-1);
	}
	printf("服务器发来的消息是：%s,消息大小是：%d\n",buf,res);

	//4 关闭socket， close
	res = close(sockfd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");

	return 0;
}
