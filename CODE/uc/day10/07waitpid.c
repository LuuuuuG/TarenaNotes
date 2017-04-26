//使用waitpid函数等待子进程的状态发生改变
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	//1 创建两个子进程 使用fork函数
	pid_t pid1,pid2;
	pid1 = fork();
	if(-1 == pid1){
		perror("fork"),exit(-1);
	}

	if(pid1){
		pid2 = fork();
		if(-1 == pid2){
			perror("fork"),exit(-1);
		}
	}
//	printf("Are there 3P ???\n");
	//2 子进程一开始执行 10秒后终止
	if(0 == pid1){
		printf("子进程一%d开始\n",getpid());
		sleep(10);
		printf("子进程一结束\n");
		exit(100);
	}
	//3 子进程二开始执行 20秒后终止
	if(0 == pid2){
		printf("子进程二%d开始\n",getpid());
		sleep(20);
		printf("子进程二结束\n");
		exit(200);
	}
	//4 父进程等待子进程结束 并获取退出状态信息
	printf("父进程开始等待...\n");
	int status = 0;
	//表示等待任意一个子进程 等价与wait函数
//	int res = waitpid(-1,&status,0);
	//表示等待进程号为pid1的进程号，子进程一
//	int res = waitpid(pid1,&status,0);
	//表示等待进程号为pid2的进程号，子进程二
	int res = waitpid(pid2,&status,0);
	if(-1 == res){
		perror("waitpid"),exit(-1);
	}
	if(WIFEXITED(status)){
		printf("父进程等待结束,终止的子进程是:%d,退出状态信息是:%d\n",res,WEXITSTATUS(status));
	}

	return 0;
}
