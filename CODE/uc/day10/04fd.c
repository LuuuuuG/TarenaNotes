#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
	//打开文件a.txt
	int fd = open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(-1 == fd){
		perror("fd");
		exit(-1);
	}
	printf("成功打开/创建文件\n");
	
	//创建子进程
	pid_t pid = fork();
	if(-1 == pid){
		perror("fork");
		exit(-1);
	}
	//向子进程中写入数据
	if(0 == pid){
		int res = write(fd,"world",5);
		if(-1 == res){
			perror("write");
			exit(-1);
		}
		printf("成功写入数据到子进程\n");
		res = close(fd);
		if(-1 == res){
			perror("close");
			exit(-1);
		}
		printf("成功关闭文件\n");
		exit(0);//终止子进程
	}
	
	sleep(1);
	//向a.txt中写入hello
	int res = write(fd,"hello",5);
	if(-1 == res){
		perror("write");
		exit(-1);
	}
	printf("成功写入数据到父进程\n");
	
	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");


	return 0;
}

