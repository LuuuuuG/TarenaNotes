//07read.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1.打开文件c.txt
	int fd = open("c.txt",O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开文件成功\n");
	//2.读取数据到缓存区
//	char* pt = (char*)malloc(sizeof(char)*10);  
//	char* pt = sbrk(sizeof(char)*10);
	char pt[20] = {0};

	int res = read(fd,pt,sizeof(pt));
	if(-1 == res){
		printf("读取失败\n");
		exit(-1);
	}
	
	printf("c.txt的内容是:%s,数据大小是:%d\n",pt,res);
	//3.关闭文件c.txt
	res = close(fd);
	if(-1 == res){
		perror("colse");
		exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
