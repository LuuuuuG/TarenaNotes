//使用access函数判断文件是否存在以及拥有相应权限
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	//判断文件是否存在
	if(0 == access("a.txt",F_OK)){
		printf("该文件存在\n");
	}
	//判断文件是否可读
	if(0 == access("a.txt",R_OK)){
		printf("该文件可读\n");
	}
	//判断文件是否可写
	if(0 == access("a.txt",W_OK)){
		printf("该文件可写\n");
	}
	//判断文件是否可执行
	if(0 == access("a.txt",X_OK)){
		printf("该文件可执行\n");
	}

	return 0;
}
