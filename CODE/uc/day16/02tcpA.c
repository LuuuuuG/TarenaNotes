//基于tcp通信模型一对多的服务器端
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<string.h>
//定义全局变量来记录用于响应的socket描述符
int sockfd;

void fuck(int shit){
	printf("正在关闭服务器,请骚等...\n");
	sleep(3);
	//关闭socket 使用close
	int res = close(sockfd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("关闭服务器成功\n");
	exit(0);//终止进程
}

int main(){
	//1 创建socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd){
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	
	//2 准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.3.168");//pong 100.64
	
	//实现地址可以被立即重复使用的效果
	//解决地址被占用的问题
	int reuseaddr = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(int));

	//3 绑定socket和通信地址
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res){
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");

	//4 监听 使用listen
	res = listen(sockfd,233);
	if(-1 == res){
		perror("listen"),exit(-1);
	}
	printf("监听成功\n");


	//设置对信号2 SIGINT自定义处理
	if(SIG_ERR == signal(SIGINT,fuck)){
		perror("signal"),exit(-1);
	}
	printf("关闭服务器请按ctrl+c...\n");

	//5 不断响应 accept
	//准备两个变量作为函数的实参
	while(1){
		//准备两个变量作为accept函数的实参
		struct sockaddr_in recv_addr;
		socklen_t len = sizeof(recv_addr);
		int fd = accept(sockfd,(struct sockaddr*)&recv_addr,&len);
		if(-1 == fd){
			perror("accept"),exit(-1);
		}
		char* ip = inet_ntoa(recv_addr.sin_addr);//将结构体类型的i被地址转换为字符串
		printf("客户端%s连接成功...\n",ip);
		
		//创建子进程实现和该客户端通信
		pid_t pid = fork();
		if(-1 == pid){
			perror("fork"),exit(-1);
		}
		if(0 == pid){
			//使用signal函数设置对信号2进行默认处理
			if(SIG_ERR == signal(SIGINT,SIG_DFL)){
				perror("fork"),exit(-1);
			}
			//关闭响应的sockfd
			res = close(sockfd);
			if(-1 == res){
				perror("close"),exit(-1);
			}
			while(1){
				char arr[10] = {0};
				strcmp("","");
				//6 针对每个客户端进行不断滴通信 send/recv
				char buf[233] = {0};
				int res = recv(fd,buf,sizeof(buf),0);
				if(-1 == res){
					perror("recv"),exit(-1);
				}
				printf("客户端发来的消息是:%s,消息大小是：%d\n",buf,res);
				if(!strcmp(buf,"bye")){
					printf("客户端%s已经下线！\n",ip);
					break;//跳出无限循环
				}
				//向客户端回发消息
				res = send(fd,"服务器发来的消息是：I received!\n",100,0);
				printf("成功发送消息到客户端,发送的消息大小是:%d\n",res);
			}
			//执行break之后跳到了这里
			res = close(fd);
			if(-1 == res){
				perror("close"),exit(-1);
			}
			//终止当前子进程
			exit(0);
		}
		//在父进程中关闭用于通信的socket
		//关闭用于通信的socket
		res = close(fd);
		if(-1 == res){
			perror("close"),exit(-1);
		}
	}	
	//7 关闭 close
	
	return 0;
}
