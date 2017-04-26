//main.c
#include "stack_arr.h"

int main(void)
{
	//创建栈，调用stack_create函数
	Stack* ps = stack_create(5);

	printf("%s\n",stack_empty(ps)?"栈已经空了":"栈没有空"); // 栈已经空了
	printf("%s\n",stack_full(ps)?"栈已经满了":"栈没有满"); // 栈没有满
	printf("--------------------------\n");
	int i = 0;
	for(i = 1;i < 7;i++){
		stack_push(ps,i*10 + i);//入栈
		stack_travel(ps);//遍历
	}

	printf("---------------------------\n");
	
	printf("栈顶元素是%d\n",stack_peek(ps));	//查看栈顶元素
	printf("有效元素个数是:%d\n",stack_size(ps));
	
	printf("---------------------------\n");
	printf("出栈元素是%d\n",stack_pop(ps));
	printf("栈顶元素是%d\n",stack_peek(ps));	//查看栈顶元素
	printf("有效元素个数是:%d\n",stack_size(ps));
		stack_travel(ps);//遍历

	printf("---------------------------\n");
	//清空栈中元素
	stack_clear(ps);
	stack_travel(ps);//啥也没有了~

	//销毁栈，调用stack_destroy函数
	stack_destroy(ps);
	ps = NULL;
	return 0;
}

