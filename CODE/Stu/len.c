//len.c
#include "stu.h"
#include <stdio.h>
int len(stu* p_head){
	int size = 0;
	while(p_head->next!=NULL){
		p_head = p_head->next;
		size++;
	}
	return size;
}
