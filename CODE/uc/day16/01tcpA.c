//服务器端
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
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");

	//4 监听
	res = listen(sockfd,233);
	if(-1 == res){
		perror("listen"),exit(-1);
	}
	printf("监听成功\n");

	//5 响应 accept
	//不断的通信
	//准备两个变量作为函数的实参
	while(1){
		struct sockaddr_in recv_addr;
		socklen_t len = sizeof(recv_addr);
		int fd = accept(sockfd,(struct sockaddr*)&recv_addr,&len);
		if(-1 == res){
			perror("accept"),exit(-1);
		}
		char* ip = inet_ntoa(recv_addr.sin_addr);
		printf("客户端%s连接成功！\n",ip);
		//6 通信 send/recv
		char buf[233] = {0};
		int res = recv(fd,buf,sizeof(buf),0);
		if(-1 == res){
			perror("recv"),exit(-1);
		}
		printf("客户端发来的消息是:%s,消息大小是：%d\n",buf,res);
		//想客户端回发消息
		res = send(fd,"\nI received!\n",12,0);
		printf("成功发送消息到客户端,发送的消息大小是:%d\n",res);
/*	//7 关闭 close
	res = close(fd);
	res = close(sockfd);
	printf("成功关闭socket\n");
*/	}
	return 0;
}
