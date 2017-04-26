#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1 打开文件
	int fd = open("a.pipe",O_RDONLY);
	if(-1 == fd){
		perror("open"),exit(-1);
	}
	//2 读取数据
	int* shit = (int*)malloc(sizeof(int)*100);
	int i = 0;
	for(i = 0;i < 100;i++){
		int res = read(fd,shit+i,sizeof(int));
		if(-1 == res){
			perror("read"),exit(-1);
		}
		printf("%.2d ",*(shit+i));
	}
	printf("\n");
	//3 关闭文件
	int res = close(fd);
	if(-1 == res){
		perror("close"),exit(-1);
	}


	return 0;
}
