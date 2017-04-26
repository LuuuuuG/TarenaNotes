//获得字符串演示

#include<stdio.h>
#include<string.h>
int main(){
	char str[10] = {0};	
	printf("plz input a string:");
//	scanf("%s",str);
	
	fgets(str,10,stdin);
	if(strlen(str) == 9 && str[8] != '\n'){	//确保有多余数据的时候，才清理
		scanf("%*[^\n]");     
		scanf("%*c");
	}
	printf("%s\n",str);
	
	printf("plz input another string:");
	fgets(str,10,stdin);
	printf("%s\n",str);
	return 0;
}
