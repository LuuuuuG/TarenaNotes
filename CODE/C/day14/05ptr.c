//二级指针形参演示
#include <stdio.h>
void setnull(int **pp_num){
	*pp_num = NULL;
}
int main(){
	int num = 0;
	int *p_num = &num;
	setnull(&p_num);
	printf("p_num is %p\n",p_num);
	return 0;
}
