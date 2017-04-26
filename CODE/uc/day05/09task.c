/*
	【练习】
		使用C语言中的错误表现形式编写以下两个功能函数:
		a.实现计算参数指定的文件的大小,并通过返回值返回,
		  如果参数指定的文件打开失败,则返回错误;
		    ftell()	fseek()
		b.实现比较两个参数字符串的大小,并返回最大值,如果相等则返回错误
			string_copmpare()

*/

#include <stdio.h>
#include <string.h>


int file_size(const char* f1){
	FILE* p_file = fopen(f1,"rb");
	if(p_file){
		fseek(p_file,0,SEEK_END);
		return ftell(p_file);
	}
	else{
		return -1;
	}
}

const char* string_compare(const char* s1,const char* s2){
	int res = strcmp(s1,s2);
	if(0 == res){
		return NULL;
	}
	else if(res > 0){
		return s1;
	}
	else{
		return s2;
	}
	//三目运算 
}	



int main(){
	int size = file_size("a.out");
	printf("文件的大小为:%d\n",size);


	char* s1 = "hello";
	char* s2 = "world";

	printf("最大字符串是:%s\n",string_compare(s1,s2));
	return 0;
}


