//show.c
#include "stu.h"
#include<stdio.h>

void show(stu* p_head){
	printf("ID\t姓名\t英语\t数学\t语文\t总成绩\n");
	while(p_head->next != NULL){
		p_head = p_head->next;
		printf("%d\t%s\t%lg\t%lg\t%lg\t%lg\n",p_head->id,p_head->name,p_head->English,p_head->Math,p_head->Chinese,p_head->sum);
	}

}
