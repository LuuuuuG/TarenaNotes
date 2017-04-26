//使用有名管道实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1 打开管道文件 使用open函数
	int fd = open("a.pipe",O_WRONLY);
	if(-1 == fd){
		perror("open"),exit(-1);
	}
	//2 分别写入1~100 之间的数据到管道文件中
	int i = 0;
	for(i = 1;i <= 100;i++){
		int res = write(fd,&i,sizeof(int));
		if(-1 == res){
			perror("write"),exit(-1);
		}
	}
	printf("写入数据成功\n");
	//3 关闭管道文件 使用close函数
	int res = close(fd);
	if(-1 == res){
		perror("close"),exit(-1);
	}


	return 0;
}
