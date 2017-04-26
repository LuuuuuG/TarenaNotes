//文本文件
#include<stdio.h>
#include<string.h>
int main(){
	char str[] = "1,2,3,4,5";	//字符串字面值初始化数组
	FILE *p_file = fopen("a.txt","wb");
	if (p_file) {
		fwrite(str,sizeof(char),strlen(str)/*数出字符个数*/,p_file);
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
