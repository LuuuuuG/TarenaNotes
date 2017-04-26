//使用vfork函数创建子进程
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){	
	//1 创建子进程 使用vfork函数
	pid_t pid = vfork();
	if(-1 == pid){
		perror("vfork");
		exit(-1);
	}
	//2 子进程开始执行
	if(0 == pid){
		printf("子进程%d开始执行\n",getpid());
		sleep(10);
		printf("子进程即将跳出去执行\n");
		//调用execl函数进行条转
		int res = execl("./process","process",NULL);
		if(-1 == res){
			perror("execl");
			_exit(-1);
		}

		printf("子进程结束\n");
	//	_exit(0);
	//	exit(0);	//会调用注册函数(如果存在)
	}
	//3 父进程开始执行
	printf("父进程%d开始执行\n",getpid());
	printf("父进程结束\n");

	return 0;
}
