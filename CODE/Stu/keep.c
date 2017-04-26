//keep.c
#include "stu.h"
#include <stdio.h>

void keep (stu* p_head){
	FILE* p_file = fopen("./stu.bin","w");
	if(p_file == NULL) return;
	
	while(p_head->next != NULL){
		p_head = p_head->next;
		fwrite(p_head,sizeof(stu),1,p_file);
	}
	fclose(p_file);
	p_file = NULL;
}
