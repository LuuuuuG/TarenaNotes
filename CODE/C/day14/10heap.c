//动态内存分配 演示
#include <stdio.h>
#include <stdlib.h>
int *read(void){
	int *p_num = (int *)malloc(sizeof(int));
	if (p_num) {
		printf("plz input a number:");
		scanf("%d",p_num);
	}
	return p_num;   //如果分配不成功 返回值为NULL
}

int main(){
	int *p_num = read();
	if (p_num) {	//只处理分配成功的情况
		printf("%d\n",*p_num);
		free(p_num);	//释放内存
		p_num = NULL;	//指针恢复成空指针
	}
	return 0;
}
