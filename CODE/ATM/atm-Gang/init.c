//
#include<stdlib.h>
#include"bank.h"

void init(){
    printf("  ********************************************************************\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                       银行账户管理系统                           *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                1 开户 2 销户 3 存款 4 取款                       *\n");
    printf("  *                                                                  *\n");
    printf("  *                5 查询 6 转帐 0 退出                              *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  *                                          __Design by LuGang__    *\n");
    printf("  *                                                                  *\n");
    printf("  *                                                                  *\n");
    printf("  ********************************************************************\n");

	    int choose = 0;
	    scanf("%d",&choose);
	    switch(choose)
	    {
			case 1:
				createUser();break;
			case 2:printf("正在销户\n");
				break;
			case 3:printf("正在存钱\n");
				break;
			case 4:printf("正在取钱\n");
				break;
			case 5:printf("正在查询\n");
				break;
			case 6:printf("正在转帐\n");
				break;
			case 0:printf("谢谢使用，下次再见\n");
				return;
			default:printf("输入错误\n");
		}
		printf("\n\n");


}
