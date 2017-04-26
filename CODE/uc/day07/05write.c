//write.c,将[1~10^6]之间的每一个整数写入到文件num2.dat中；
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main(){
	int fd = open("num2.dat",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	printf("打开/创建文件成功\n");
	int i = 0;
	for(i = 0;i < 1000000;i++){
	    write(fd,&i,sizeof(int));
	}
	printf("成功写入数据\n");

	int res = close(fd);
	if(-1 == res){
		perror("close");
		exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}


