//环境表基本操作函数的使用
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	//使用getenv函数来获得环境变量SHELL的数值
	char* pc = getenv("SHELL");
	if(NULL == pc){
		printf("该环境变量不存在\n");
		return -1;
	}
	printf("SHELL = %s\n",pc);// /bin/bash
	
	printf("--------------------\n");
	
	//使用setenv函数修改SHELL的值,不修改
	int res = setenv("SHELL","abcd",0);
	if(-1 == res){
		perror("srtenv");
		exit(-1);
	}
	printf("SHELL = %s\n",getenv("SHELL"));// /bin/bash
	
	//使用setenv函数修改SHELL的值为abcd,要求修改
	printf("--------------------\n");
	res = setenv("SHELL","abcd",1);
	if(-1 == res){
		perror("setenv");
		exit(-1);
	}
	printf("SHELL = %s\n",getenv("SHELL"));// /bin/bash

	//使用setenv函数增加MARK=xiaomage
	printf("--------------------\n");
	res = setenv("MARK","xiaomage",1);
	if(-1 == res){
		perror("setenv");
		exit(-1);
	}
	printf("MARK = %s\n",getenv("MARK"));
	printf("--------------------\n");
	
	//使用unsetenv函数删除环境变量MARK
	res = unsetenv("MARK");
	if(-1 == res){
		perror("unsetenv");
		exit(-1);
	}
	printf("MARK = %s\n",getenv("MARK"));
	printf("--------------------\n");
	
	//使用putenv函数修改环境变量SHELL的数值
	res = putenv("SHELL=/bin/bash");
	if(0 != res){
		perror("putenv");
		exit(-1);
	}
		//  /bin/bash
	printf("SHELL = %s\n",getenv("SHELL"));
	
	//使用putenv函数增加环境变量WUHUSHANGJIANG
	res = putenv("WUHUSHANGJIANG=zhangfei");
	if(0 != res){
		perror("putenv");
		exit(-1);
	}	//zhangfei
	printf("WUHUSHANGJIANG = %s\n",getenv("WUHUSHANGJIANG"));
	printf("--------------------\n");

	//使用clearenv 清空整个环境表
	res = clearenv();
	if(0 != res){
		perror("clearenv");
		exit(-1);
	}
	printf("整个环境表清空完毕\n");
	
	if(NULL == getenv("PATH")){
		printf("环境变量PATH已经被删除了\n");
	}
	extern char** environ;
	if(NULL == environ){
		printf("整个环境表空了\n");
	}
	return 0;
}
