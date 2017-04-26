//客户端
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	//1 创建socket
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2 准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.3.168");//pong 100.64
	//3 绑定socket和通信地址
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("connect"),exit(-1);
	}
	printf("绑定成功\n");
	//6 通信 send/recv
	res = send(sockfd,"\n\n\n\t Hello\n\n\t World!\n\n\n",200,0);
//	res = send(sockfd,"bye",200,0);
	printf("成功发送消息到客户端,发送的消息大小是:%d\n",res);
	char buf[233] = {0};
	res = recv(sockfd,buf,sizeof(buf),0);
	printf("客户端接收结果:%s\n",buf);
	//7 关闭 close
	//res = close(fd);
	res = close(sockfd);
	printf("成功关闭socket\n");


	return 0;
}
