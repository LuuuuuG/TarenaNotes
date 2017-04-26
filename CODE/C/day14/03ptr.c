//二级指针演示
#include <stdio.h>
int main(){
	int num = 0;
	int *p_num = &num;
	int **pp_num = &p_num;	//声明二级指针
	**pp_num = 10;
	printf("num is %d\n",num);
	*pp_num = NULL;
	printf("p_num is %p\n",p_num);
	return 0;
}
