//03lockB.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	//1 打开文件
	int fd = open("a.txt",O_RDWR);	
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开文件成功\n");
	//2 写锁
	struct flock lock;
	lock.l_type = F_WRLCK;//写锁
//	lock.l_type = F_RDLCK;//读锁
	lock.l_whence = SEEK_SET;
	lock.l_start = 2;
	lock.l_len = 15;
	lock.l_pid = -1;
	// 加锁
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res){
		printf("加锁失败\n");
	}
	else{
		printf("加锁成功\n");
	}
	//3 关闭文件a.txt
	res = close(fd);
	if(-1 == res){
		perror("close");
	}
	printf("成功关闭文件\n");
	return 0;
}	
