/*点菜程序：
	1表示龙虾	2表示小鸡炖蘑菇
	赵 1 无 2 有
	其他1 有 2 无
*/
#include<stdio.h>
int main(){
	int order = 0;
	printf("请点菜：");
	scanf("%d",&order);
#ifdef	ZHAO
	if (order == 1){
		printf("没有\n");
	}
	else{
		printf("真没有\n");
	}
#else
	if (order == 1){
	printf("有\n");
	}
	else{
	printf("没有\n");
	}
#endif
	return 0;
}
