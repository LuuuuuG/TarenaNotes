//03string.c
//常量字符串不同存放形式的比较
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char* pc = "hello";// 将字符串的首地址放在pc中
	//pc 指向只读常量区， pc本身在栈区
	char ps[6] = "hello";// 将字符串复制一份到连续存储空间
	//ps 指向栈区， ps本身也在栈区 代表第一个元素的地址；
	
	printf("pc = %p,&pc = %p\n",pc,&pc);
	printf("ps = %p,&ps = %p\n",ps,&ps);
	printf("----------------\n");
	//试图改变指针的指向
	pc = "1234";	//ok
//	ps = "1234";	//error  数组名是常量不可改变
	
	//试图改变指针指向的内容
//	strcpy(pc,"Good");	//error  pc指向只读常量区 内容不可更改
	strcpy(ps,"Good");	//ok
	printf("----------------\n");
	//pc 指向堆区 pc本身在栈区
	pc = (char*)malloc(sizeof(char)*10);
	//试图改变pc指针指向的内容
	strcpy(pc,"world");
	printf("pc = %s\n",pc);   //world

	//指定临时指针指向了动态内存
	char* pt = pc;
	//试图改变pc指针的指向
	pc = "world2";
	printf("%s\n",pc);	//world2
	//释放动态内存
	free(pt);
	pt = NULL;
	return 0;
}
