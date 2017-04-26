//main.c
#include "stack_list.h"
/*-------------------------------------*/

int main(){
	//1创建栈
	Stack* ps = stack_create();
	
	int i = 0;
	for(i = 1;i < 7;i++){
		stack_push(ps,i*10 + i);//入栈
		stack_travel(ps);	//遍历
	}
	printf("--------------------------------\n");
	printf("%s\n",stack_empty(ps)?"栈空":"栈不空");
	printf("%s\n",stack_full(ps)?"栈满":"栈不满");
	
	printf("栈顶元素是:%d\n",stack_peek(ps));//查看栈顶元素
	printf("栈中有效元素是:%d\n",stack_size(ps));
	
	printf("--------------------------------\n");
	printf("出栈的元素是:%d\n",stack_pop(ps));//66
	printf("栈顶的元素是:%d\n",stack_peek(ps));//55
	printf("栈中有效元素是:%d\n",stack_size(ps));//5
	stack_travel(ps);// 55 44 33 22 11
	
	printf("--------------------------------\n");
	stack_clear(ps);
	stack_travel(ps);//nothing

	//2销毁栈
	stack_destroy(ps);
	ps = NULL;

	return 0;
}


/*-------------------------------------*/
