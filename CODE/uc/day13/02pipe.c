//使用无名管道实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int pipefd[2];
	//1 创建无名管道 使用pipe函数
	int res = pipe(pipefd);
	if(-1 == res){
		perror("pipe"),exit(-1);
	}
	printf("创建无名管道成功\n");
	//2 创建子进程 使用fork函数
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork"),exit(-1);
	}
	//3 子进程开始执行 写入1~100
	if(0 == pid){
		printf("子进程%d开始执行\n",getpid());
		//关闭读端
		close(pipefd[0]);
		int i = 0;
		for(i = 1;i <= 100;i++){			
			write(pipefd[1],&i,sizeof(int));
		}
		//关闭写端
		close(pipefd[1]);
		printf("子进程结束\n");
		exit(0);
	}
	//4 父进程开始执行 读取管道中的数据并打印
	//关闭写端
	close(pipefd[1]);
	sleep(1);
	int i = 0;
	printf("父进程读取到的内容有：\n");
	for(i = 1;i <= 100;i++){
		int temp = 0;
		read(pipefd[0],&temp,sizeof(int));
		printf("%d ",temp);
	}
	printf("\n");
	close(pipefd[0]);
	return 0;
}
