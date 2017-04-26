//使用system函数执行具体的shell命令
#include<stdio.h>
#include<stdlib.h>

int main(){
	int res = system("pwd");
	if (-1 == res){
		perror("system");
		exit(-1);
	}
	printf("shell命令执行完毕\n");

	return 0;
}
