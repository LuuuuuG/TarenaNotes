//init.c
#include"stu.h"
#include<stdio.h>
#include<stdlib.h>

void init(stu* p_head){
	//system("clear");//清屏幕
    printf("  **************************************************************************\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                       学 生 信 息 管 理 系 统                          *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                   1 增加 2 删除 3 排序 4 修改  5 查找                  *\n");
    printf("  *                                                                        *\n");
    printf("  *                   6 打印 7 保存 8 人数 0 退出                          *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  *                                             __Design by LuGang__       *\n");
    printf("  *                                                                        *\n");
    printf("  *                                                                        *\n");
    printf("  **************************************************************************\n");
	int val = 0;
	scanf("%d",&val);
	switch(val){//int,char,bool,枚举//整数类型
		case 1:
		system("clear");//清屏幕
			add(p_head);
			break;
		case 2:
		system("clear");//清屏幕
			dele(p_head);
			break;
		case 3:
		system("clear");//清屏幕
			//sort(p_head);
			break;
		case 4:
		system("clear");//清屏幕
			//rev(p_head);
			break;
		case 5:
		system("clear");//清屏幕
			//seek(p_head);
			break;
		case 6:
		system("clear");//清屏幕
			show(p_head);
			break;
		case 7:
		system("clear");//清屏幕
			keep(p_head);
			break;
		case 8:
		system("clear");//清屏幕
			printf("已记录学员人数%d名\n",len(p_head));
			break;
		case 0:
			//quit((p_head);
			break;
		default:
			printf("sorry,此功能正在研发中,请稍后!\n");
	}
}

