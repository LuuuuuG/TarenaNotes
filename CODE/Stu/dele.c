//dele.c
#include "stu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int deleId(stu* p_head){
	stu* p1 = p_head;
	int id = 0;
	printf("请输入要删除的ID:");
	scanf("%d",&id);
	while(p_head->next != NULL){
		p1 = p_head;
		p_head = p_head->next;
		if(p_head->id == id){
			p1->next = p_head->next;
			free(p_head);
			p_head = NULL;
			return 1;
		}
	}
	return -1;
}


int deleName(stu* p_head){
	char name[20] = {};
	stu* p1 = p_head;
	printf("请输入要删除的学员姓名:");
	scanf("%s",name);
	int size = 0;//用来保存同名同姓的个数
	while(p1->next != NULL){
		p1 = p1->next;
		if(strcmp(p1->name,name) == 0){ //比较字符串
			printf("%d\t%s\t%lg\t%lg\t%lg\t%lg\t",p1->id,p1->name,p1->English,p1->Math,p1->Chinese,p1->sum);
			size++;
		}
	}
	if(size == 0){
		return -1;
	}
	else{
		printf("同名同姓的学员共有%d个\n",size);
		deleId(p_head);//p1已经挪到了链表尾了
	}
}

int deleDele(stu* p_head){
	stu* p1 = p_head;//临时指针用来释放节点
	while(p_head->next != NULL){ //从头开始删除节点
		p1 = p_head->next;//
		p_head = p1->next;
		free(p1);
		p1 = NULL;
	}
	if(p_head->next == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int deleFile(/*stu* p_head*/){
	system("rm ./stu.bin");
	//只清空不删除文件用fopen函数,只给写权限,写入一个空字符串
	return 1;
}



void dele(stu* p_head){
    printf("  ************************************************************************************\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                       学 生 信 息 管 理 系 统                                    *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                   1 学号 2 姓名 3 全删 0 取消                                    *\n");
    printf("  *                                                                                  *\n");
    printf("  *                            4 清空记录                                            *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                      __Design by LuGang__        *\n");
    printf("  *                                                                                  *\n");
    printf("  *                                                                                  *\n");
    printf("  ************************************************************************************\n");
	int val = 0;
	scanf("%d",&val);
	switch(val){
		case 1:
			if(deleId(p_head) == -1){
				printf("删除失败\n");
			}
			else{
				printf("删除成功\n");
			}
			break;
		case 2:
			if(deleName(p_head) == -1){
				printf("删除失败\n");
			}
			else{
				printf("删除成功\n");
			}
			break;
		case 3:
			if(deleDele(p_head) == -1){
				printf("删除失败\n");
			}
			else{
				printf("删除成功\n");
			}
			break;
		case 4:
			if(deleFile(p_head) == -1){
				printf("删除失败\n");
			}
			else{
				printf("删除成功\n");
			}
			break;
		case 0:
			return ;
		default:
			printf("此功能未上线\n");
	}
	

}
