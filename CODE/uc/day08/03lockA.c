//使用fcntl函数给文件进行加锁

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	printf("当前进程的进程号是:%d\n",getpid());
	
	//1 打开文件a.txt
	int fd = open("a.txt",O_RDWR);
	if(-1 == fd){
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2 准备一把锁 并进行初始化
	struct flock lock;
//	lock.l_type = F_RDLCK;//读锁
	lock.l_type = F_WRLCK;//写锁
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;//不偏移
	lock.l_len = 10;
	lock.l_pid = -1;//暂时不使用
	//3 使用fcntl函数进行加锁
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res){
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功,开始使用文件...\n");
	//4 模拟占用文件20秒
	sleep(20);	//睡20秒
	printf("使用文件结束,即将关闭文件\n");
	//5 关闭文件a.txt
	res = close(fd);
	if(-1 == res){
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
