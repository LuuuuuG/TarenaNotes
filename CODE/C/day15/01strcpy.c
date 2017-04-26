//字符串拷贝作业

#include <stdio.h>
#include <stdlib.h>
char *mystrcpy(char *str){
	char *p_tmp = str,*p_dest = NULL;
	char *p_tmp1 = NULL;
	int cnt = 0;
	//计算字符串所占空间
	while (*p_tmp) {	//p_tmp指向'\0' 时 *p_tmp = 0
		cnt++;
		p_tmp++;	//指针后移
	}
	cnt++;
	p_dest = malloc(cnt *sizeof(char));
	if (p_dest){
		p_tmp = str;	//p_tmp指针和原有字符串第一个存储区捆绑
		p_tmp1 = p_dest;
		while(*p_tmp){
			*p_tmp1 = *p_tmp;
			p_tmp++;
			p_tmp1++;
		}
		*p_tmp1 = 0;	//在新字符串末尾加入"\0"
	}
	return p_dest;
}
int main(){
	char *str = mystrcpy("abcdef");
	if (str){
		printf("%s\n",str);
		free(str);
		str = NULL;
	}
	return 0;
}
