//add.c
#include"stu.h"
#include <stdio.h>
#include <stdlib.h>

void add(stu *p_head){
	stu* new = (stu*)malloc(sizeof(stu));
	printf("请输入新学员姓名,英语成绩,数学成绩，语文成绩\n");
	scanf("%s%lg%lg%lg",new->name,&new->English,&new->Math,&new->Chinese);
	new->sum = new->English + new->Math + new->Chinese;
	new->id = len(p_head);
	new->next = NULL;
	//末尾插入
	while(NULL != p_head->next){
		p_head = p_head->next;
	}
	p_head->next = new;
}
