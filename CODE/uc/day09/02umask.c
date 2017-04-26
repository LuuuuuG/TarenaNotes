//使用umask函数设置文件创建时屏蔽的权限
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	//使用umask函数设置新的权限屏蔽字
	mode_t old = umask(0055);
	printf("old = %d\n",old);  //2
	//1 创建文件b.txt 使用open函数
	int fd = open("b.txt",O_RDWR|O_CREAT|O_EXCL,0777); //最终为0775
	if(-1 == fd){						//0002为系统默认屏蔽的权限
		perror("open");
		exit(-1);
	}
	printf("创建文件成功\n");
	//调用umaks函数回复系统默认的权限屏蔽
	umask(old);
	//2 关闭文件b.txt 使用close函数
	int res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
