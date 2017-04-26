//作业
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>

void print(char* path){
	//1 打开目录
	DIR* dir = opendir(path);
	if(NULL == dir){
		//perror("opendir");
		//exit(-1);//结束整个程序
		return;//结束当前函数
	}
	printf("成功打开目录[%s]\n",path);
	//2 循环读取目录中的内容
	struct dirent* ent = readdir(dir);
	while(ent != NULL){
		//3 如果是文件则打印
		if(ent->d_type){
			printf("%s\n",ent->d_name);
		}

		//4 如果是目录则递归
		if(ent->d_type == 4 && strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0 ){
//			char str[20] = "../day02/";
//			print(strcat(str,ent->d_name));
			//方法二：
			char str[40] = {0};
			sprintf(str,"%s/%s",path,ent->d_name);
			print(str);

		}
		ent = readdir(dir);
	}
	//5 关闭目录
	int res = closedir(dir);
	if(-1 == res){
		perror("closedir");
		exit(-1);
	}
	printf("成功关闭目录\n");
}

int main(){
	print("../day03");
	return 0;
}


