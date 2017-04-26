//sort.c
#include "stu.h"
#include <stdio.h>
int sortName(stu* p_head){
//how can this program enable ???

	stu* p1 = p_head;//冒泡排序
	while(p_head->next != NULL){
		p_head = p_head->next;
		p1 = p_head;
		while(p1->next != NULL){
			p1 = p1->next;
			if(strcmp(p_head->name,p1->name) > 0){
				
				//交换节点位置
				stu p = *p_head;
				*p_head = *p1;
				*p1 = p;
			
				//交换next指向位置
				stu* p2 = p_head->next;
				p_head->next = p1->next;
				p1->next = p2;
			}
		}
	}
}



void sort(stu* p_head){
	//界面
	//switch
	//调用函数
	if(sortName(/*stu* */p_head)){
		printf("排序成功\n");
	}
	else{
		printf("排序失败\n");
	}
}
