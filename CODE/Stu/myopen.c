//myopen.c
#include "stu.h"
#include <stdio.h>
#include <stdlib.h>
//三大标准
	//输入 stdin
	//输出 stdout
	//错误 stderror
void myopen(stu* p_head){
	FILE *p_file = fopen("./stu.bin","r");
	if(p_file){
		while(1){
			stu* new = (stu*)malloc(sizeof(stu));
			if(!fread(new,sizeof(stu),1,p_file)){ //读完释放多声请的内存
				free(new);	
				new = NULL;
				break;
			}
			else{
				new->next = NULL;
				/*
				//末尾插入
				while(p_head->next != NULL){
					p_head = p_head->next;
				}//遍历到尾节点
				p_head->next = new;
				*/
				//头插入
				new->next = p_head->next;
				p_head->next = new;
			}
		}
		fclose(p_file);
		p_file = NULL;
	}
}
