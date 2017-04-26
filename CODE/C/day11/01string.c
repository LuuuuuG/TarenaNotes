//字符串函数演示
#include<stdio.h>
#include<string.h>
int main(){
	char str[10] = "xyz";
	int len = strlen(str);	 	//strlen 统计有效字符个数
	printf("lenth is %d\n",len);
	printf("sizeof(str) is %d\n",sizeof(str));//sizeof统计数组所有字符个数
	
	printf("%s\n",strcat(str,"abc"));	//前一个参数必须是字符串数组。
	printf("%s\n",str);			//效果与上相同。
	
	printf("比较结果是%d\n",strcmp("abc","abd"));

	printf("%s\n",strcpy(str,"123456")); //字符串复制到字符数组里
	printf("%s\n",str);		//效果同上 ，与用字符串初始化数组效果相同。

	memset(str,'h',10); 	//设置数组为10个 h
	printf("%s\n sizeof(str)",str,sizeof(str));
	
	printf("%s\n",strstr("abcdefghijklmn","def"));	//效果从def一直打印到末尾

	return 0;

}	

