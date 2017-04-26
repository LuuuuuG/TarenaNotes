//使用dup2函数实现文件描述符的复制
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
	//1打开/创建b.txt
	int fd = open("b.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件b.txt成功\n");
	
	//2打开/创建d.txt
	int fd2 = creat("d.txt",0664);
	if(-1 == fd2){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件d.txt成功\n");
	printf("fd = %d,fd2 = %d\n",fd,fd2);  // 3 4

	//3复制文件描述符 使用dup2函数
	int fd3 = dup2(fd,fd2); 
	if(-1 == fd3){
		perror("dup2");
		exit(-1);
	}
	printf("fd = %d,fd2 = %d,fd3 = %d\n",fd,fd2,fd3);

	//写入数据到各个文件描述符中  都写入到了b.txt 并且数据挨着
	write(fd,"A",sizeof(char));
	write(fd2,"a",sizeof(char));
	write(fd3,"1",sizeof(char));

	//4关闭文件 使用close函数
	int res = close(fd);
	if (-1 == res) {
		perror("close");
		exit(-1);
	}
	res = close(fd2);
	if (-1 == res) {
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");

	return 0;
}
