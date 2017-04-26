//使用alarm函数发送信号
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fa(int signo){
	printf("捕获到了信号%d\n",signo);
	//设置1秒后的闹钟
	alarm(1);//每隔1秒响一次
}

int main(){
	// 设置对信号SIGALRM进行自定义处理
	signal(SIGALRM,fa);
	//设置5秒后响的闹钟
	int res = alarm(5);
	
	printf("res = %d\n",res); //0
	sleep(2);
	//设置10秒后的闹钟
	res = alarm(10);
	printf("res = %d\n",res); //3
	
//	res = alarm(0);  
//	printf("res = %d\n",res);	//10
	while(1);
	return 0;
}
