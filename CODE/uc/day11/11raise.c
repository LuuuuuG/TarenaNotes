//使用raise函数发送信号
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fa(int signo){
	printf("捕获到了信号%d\n",signo);
}

int main(){
	//1 设置对信号2进行自定义处理
	signal(SIGINT,fa);
	//使用sleep函数进行延缓
	int res = sleep(5);
	if(0 == res){
		printf("sleep like a pig\n");
	}
	else{
		printf("fuck off,%ds left\n",res);
	}
	//2 使用raise函数发送信号2
	res = raise(SIGQUIT);
	if(0 != res){
		perror("raise"),exit(-1);
	}


	return 0;
}
