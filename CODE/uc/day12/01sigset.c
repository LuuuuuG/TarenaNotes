//信号集的使用
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

int main(){
	sigset_t set;
	printf("sizeof(sigset_t) = %d\n",sizeof(sigset_t));
	printf("set = %d\n",set);  //随机数
	
	//清空信号集
	if(-1 == sigemptyset(&set)){
		perror("sigemptyset"),exit(-1);
	}
	printf("set = %d\n",set);
	
	//增加信号2到信号集中 打印
	if(-1 == sigaddset(&set,2)){
		perror("sigaddset"),exit(-1);
	}
	printf("set = %d\n",set);//2
	//增加信号3到信号集中
	if(-1 == sigaddset(&set,3)){
		perror("sigaddset"),exit(-1);//6 = 2 + 4
	}
	printf("set = %d\n",set);
	//怎家信号7到信号集中
	if(-1 == sigaddset(&set,7)){
		perror("sigaddset"),exit(-1);
	}
	printf("set = %d\n",set);// 70 = 64 + 2 + 4
	
	printf("------------------\n");

	//删除信号3 打印
	if(-1 == sigdelset(&set,3)){
		perror("sigdelset"),exit(-1);
	}
	printf("set = %d\n",set);// 66
	
	//判断信号2是否存在
	if(1 == sigismember(&set,2)){
		printf("信号2存在\n");
	}
	//判断信号3是否存在
	if(1 == sigismember(&set,3)){
		printf("信号3存在\n");
	}
	//判断信号7是否存在
	if(1 == sigismember(&set,7)){
		printf("信号7存在\n");
	}

	//填满信号集 打印
	if(-1 == sigfillset(&set)){
		perror("sigfillset"),exit(-1);
	}
	printf("set = %d\n",set);
	return 0;
}
