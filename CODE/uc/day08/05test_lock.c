//使用wrtie函数向文件a.txt中写入“hello”
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1 打开文件a.txt 使用open
	int fd = open("a.txt",O_WRONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开文件成功\n");
	//2 准备一把锁信息
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 5;
	lock.l_pid = -1;
	
	//3 尝试进行加锁,使用fcntl函数
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res){
		printf("文件已被加锁,无法执行写操作\n");
	}
	else{
		// 写入数据hello 使用write函数
		 res = write(fd,"hello",5);
		if(-1 == res){
			perror("write");
			exit(-1);
		}
		printf("写入数据成功,写入数据大小是:%d\n",res);
	}
	//3 关闭文件a.txt 使用close函数
	res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
