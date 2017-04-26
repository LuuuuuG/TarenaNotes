//open函数和close函数的使用

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
	//1.打开/创建一个文件b.txt，使用open函数a
	//表示用可读可写方式打开/创建文件
	
	//如果文件不村在则创建,存在则打开
//	int fd = open("b.txt",O_RDWR|O_CREAT,0664);
	
	//如果文件不存在则创建,存在则清空	
//	int fd = open("b.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	
	//如果文件不存在则创建,存在则创建失败
	int fd = open("b.txt",O_RDWR|O_CREAT|O_EXCL,0664);
	
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件成功\n");

	printf("O_RDWR = %d,O_CREAT = %d,O_TRUNC = %d,O_EXCL = %d\n",O_RDWR,OCREAT,O_TRUNC,O_EXCL);

	//2.关闭b.txt ,使用close函数
	int res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");

	return 0;
}
