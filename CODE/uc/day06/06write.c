//06write.c
//使用write函数将指定的数据写入到文件中
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){
	//1.打开/创建文件c.txt 使用open函数
//	int fd = open("c.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	int fd = creat("c.txt",0664);//同上等价
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件成功\n");
	//2.写入数据“hello”到文件 使用write函数
	int res = write(fd,"hello"/*首地址*/,6);
	if(-1 == res){
		perror("write");
		exit(-1);
	}
	printf("成功写入数据到文件中,写入数据大小是%d\n",res);
	//3.关闭文件c.txt 使用close函数
	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
