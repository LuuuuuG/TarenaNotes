//使用exit函数实现进程的终止
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void show(void){
	printf("You Can You Up!!!\n");
}

int main(){
	//使用atexit函数注册一个函数
	int res = atexit(show);
	if(res){
		perror("atexit"),exit(-1);
	}
	printf("main函数开始\n");
//	_exit(0);//立即终止进程
	exit(0);//程序正常终止
	printf("main函数结束\n");
	
	return 0;
}
