//无类型指针演示
#include<stdio.h>
int main(){
	char ch = 'a';
	int num = 20;
	float fnum = 5.4f;
	void *p_v = NULL;
	p_v = &ch;
	printf("%c\n",*(char *)p_v);  //强制类型转换
	p_v = &num;
	printf("%d\n",*(int *)p_v);
	p_v = &fnum;
	printf("%g\n",*(float *)p_v);
	return 0;
}
