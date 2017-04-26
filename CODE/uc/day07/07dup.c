//使用dup函数实现文件描述符的复制
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
	//1打开/创建文件b.txt
	int fd = open("b.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1 == fd	){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件成功,fd = %d\n",fd);  //3
	//2复制文件描述符
	int fd2 = dup(fd);
	if (-1 == fd2){
		perror("dup");
	}
	printf("fd = %d,fd2 = %d\n",fd,fd2);	//3  4

	//分别使用两个文件描述符写入数据
	write(fd,"A",sizeof(char));
	write(fd2,"a",sizeof(char));
	

	//3关闭文件
	int res = close(fd);
	if(-1 == res){
		perror("close");
	}
	printf("成功关闭文件\n");
	
	//使用fd2写入数据1
	write(fd2,"1",sizeof(char));
	
	//关闭文件操作符fd2
	res = close(fd2);
	if(-1 == res){
		perror("close");
	}
	printf("成功关闭文件\n");
	return 0;
}
