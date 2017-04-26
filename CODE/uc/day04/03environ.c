//遍历环境表
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//声明外部的全局变量
	extern char** environ;
	//指定零食变量代替environ进行遍历
	char** ppv = environ;
	while(*ppv != NULL){
		//打印字符串内容
		printf("%s\n",*ppv);
		//指向下一个字符串
		ppv++;
	}
	
	printf("------------------------------\n");
	/*练习:找到SHELL的环境变量，将环境变量SHELL的变量值取出来放到自定义数组buf中,打印buf中的内容
	*/
	ppv = environ;
	char buf[10] = {};
	while(NULL != *ppv){
		if(!strncmp("SHELL",*ppv,5)){
			strcpy(buf,*ppv+6);
			break;//跳出循环
		}
		ppv++;
	}
	printf("%s\n",buf);
	return 0;
}
