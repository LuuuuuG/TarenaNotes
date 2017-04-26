#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//读数据
	int fd = open("task.txt",O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	
//	printf("打开文件成功\n");
	int i = 0;
	int res = read(fd,&i,sizeof(int));
	printf("%d\n",i);
	i++;
	// 写入数据
	int fd2 = open("task.txt",O_WRONLY|O_TRUNC);
	write(fd2,&i,sizeof(int));
//	printf("写入数据成功\n");

	//关闭文件
	res = close(fd);
	if (-1 == res) {
		perror("close");
		exit(-1);
	}
//	printf("成功关闭文件\n");
	return 0;
}
