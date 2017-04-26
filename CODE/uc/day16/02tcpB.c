//实现TCP一对多通信模型
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<signal.h>


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
    addr.sin_addr.s_addr = inet_addr("172.30.100.64");//pong 100.64
        
    //实现地址可以被立即重复使用的效果
    //解决地址被占用的问题
    int reuseaddr = 1;
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(int));

    //3 绑定socket和通信地址
    int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
    if(-1 == res){
        perror("bind"),exit(-1);
    }
    printf("绑定成功\n");

	
	
	
	//4 不断地和服务器进行通信
	while(1){
		char msg[233] = {0};
		printf("请输入要发送的内容：\n");
		scanf("%s",msg);
		//将用户输入的信息发送给服务器
		res = send(sockfd,msg,strlen(msg)+1/*有效字符+\0*/,0);
		if(-1 == res){
			perror("send"),exit(-1);
		}
		//接收服务器回发的消息并打印
		char buf[100] = {0};
		//当客户端发送的数据是“bye”时,客户端下线
		if(!strcmp(msg,"bye")){
			break;
		}
		res = recv(sockfd,buf,sizeof(buf),0);
		if(-1 == res){
			perror("recv"),exit(-1);
		}
		printf("服务器发来的消息是：%s\n",buf);
	}
	//5 关闭socket 
	res = close(sockfd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭客户端\n");
	return 0;
}
