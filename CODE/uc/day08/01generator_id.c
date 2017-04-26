#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//打开文件
	int fd = open("task.txt",O_RDWR);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开文件成功\n");
	// 写入数据
	int i = 100000;
	int res = write(fd,&i,sizeof(int));
	if(-1 == res){
		perror("write");
		exit(-1);
	}
	printf("写入数据成功,写入数据:%d\n",i);

	//关闭文件
	res = close(fd);
	if (-1 == res) {
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
