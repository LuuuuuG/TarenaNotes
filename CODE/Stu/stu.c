//声明头节点
//调用open
//init();
#include "stu.h"
#include <stdio.h>
int main(){
	stu head = {};
	head.next = NULL;
	myopen(&head);//打开保存的学员信息
	while(1){
		init (&head);
	}



	return 0;
}
