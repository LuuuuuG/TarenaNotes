//作业使用on_exit函数释放申请的动态内存
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void show(int status,void* r){
	printf("status = %d\n",status);
	printf("开始释放动态内存...\n");
	sleep(3);
	int res = brk(r);
	if(-1 == res){
		perror("brk"),exit(-1);
	}
	printf("释放动态内存完毕\n");
}


int main(){
	//创建一个子进程
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork"),exit(-1);
	}
	if(0 == pid){
		//申请动态内存
		int* r = (int*)sbrk(sizeof(int));
		if((int*)-1 == r){
			perror("sbrk");
			exit(-1);
		}
		printf("请输入圆的半径：");
		scanf("%d",r);
		printf("圆周长为：%lg\n",2*3.14*(*r));
		//使用on_exit函数注册一个函数
		int res = on_exit(show,(void*)r);
		if(res){
			perror("on_exit"),exit(-1);
	}
		exit(100);
	}
	printf("父进程等待开始...\n");
	int status = 0;
	int res = waitpid(pid,&status,0);//等价 wait(&status);
	if(-1 == res){
		perror("waitpid"),exit(-1);
	}
	if(WIFEXITED(status)){
		printf("父进程等待结束,终止的子进程是:%d，退出状态信息是:%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}
