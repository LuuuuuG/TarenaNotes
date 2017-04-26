//stack_arr.c
#include "stack_arr.h"




//10 清空栈
void stack_clear(Stack* ps){
	ps->pos = 0;
}

//8 计算栈中有效元素个数
int stack_size(Stack* ps){
	return ps->pos;
}

//9 遍历栈中所有元素
void stack_travel(Stack* ps){
	int num = 0;
	printf("栈中元素有:");
	for(num = 0;num < ps->pos;num++){
		printf("%d ",ps->arr[num]);
	}
	printf("\n");

}

//7 查看栈顶元素
int stack_peek(Stack* ps){
	//判断栈是否为空
	if(stack_empty(ps)){
		return -1;//表示查看栈顶元素失败
		//暂时不考虑栈顶元素是-1的情况
		//UC课程阶段第三天讲到处理方案
	}
	return ps->arr[ps->pos - 1];
}

//5 入栈
void stack_push(Stack* ps,int data){
/*	int num = 0;
	for(num = 0;num <= ps->len;num++){
		*(ps->arr + num) = num + 1;
		ps->pos++;
	}
*/	if(stack_full(ps))
	{
		printf("栈满了，元素%d入栈失败",data);
		return;
		//exit(0);   整个程序结束
	}
	ps->arr[ps->pos++] = data;
}

//6 出栈
int stack_pop(Stack* ps){
	//判断栈是否为空
	if(stack_empty(ps)){
		return -1;//表示出栈失败
		//不考虑出栈元素是-1的情况
	}
	return ps->arr[--ps->pos];
}

//3 判断栈是否为空
int stack_empty(Stack* ps)
{
	return 0 == ps->pos;
}

//4 判断栈是否为满
int stack_full(Stack* ps)
{
	return ps->len == ps->pos;
}


//2 销毁
void stack_destroy(Stack* ps){
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
}
//1 创建
Stack* stack_create(int len){
	//1 创建栈 
//	Stack stack;	//局部变量	error
//	return &stack;	//永远不要返回局部变量的地址
//使用static关键字进行修饰   error~
	Stack* ps = (Stack*)malloc(sizeof(Stack));//动态内存分配
	if(NULL == ps){
		printf("创建栈失败，程序结束\n");
		exit(-1);//异常终止整个程序
	}
	
	//2 初始化栈中的所有成员
	ps->arr = (int*)malloc(sizeof(int)*len);
	if(NULL == ps->arr){
		printf("创建栈失败，程序结束\n");
		exit(-1);
	}
	ps->len = len;
	ps->pos = 0;
	//3  返回栈的首地址				
	return ps;
}

