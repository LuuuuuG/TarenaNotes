//stack_list.c

#include "stack_list.h"

//9出栈
int stack_pop(Stack* ps){
	if(stack_empty(ps)){
		return -1;//表示出栈失败
	}
	Node* pt = ps->top;
	ps->top = ps->top->next;
	int temp = pt->data;
	free(pt);
	pt = NULL;
	ps->cnt--;
	return temp;
}
//10 清空栈中内容
void stack_clear(Stack* ps){
	while(-1 != stack_pop(ps)){
		
	}
}

//5判断栈是否空
bool stack_empty(Stack* ps){
	return NULL == ps->top;
}
//6判断栈是否满
bool stack_full(Stack* ps){
	return false;
}
//7查看栈顶元素
int stack_peek(Stack* ps){
	//return stack_empty(ps) ? -1:ps->top->data;
	if(stack_empty(ps)){
		return -1;
	}
	return ps->top->data;
}


//8计算栈中有效元素的个数		/*HARD*/
int stack_size(Stack* ps){
/*	Node* pt = ps->top;//定义临时指针代替top
	int cnt = 0;
	while(pt != NULL){
		cnt++;
		pt = pt->next;
	}
	return cnt;
*/
	return ps->cnt;
}


//3实现入栈操作
void stack_push(Stack* ps,int data){
	//创建新节点
	Node* pn = (Node*)malloc(sizeof(Node));
	if(NULL == pn){
		printf("fail to creat new node!");
		exit(-1);
	}
	pn->data = data;
	pn->next = NULL;
	//将新节点插入到合适的位置
	pn->next = ps->top;
	ps->top = pn;
	//有效元素个数加1
	ps->cnt++;
}

//4实现遍历
void stack_travel(Stack* ps){
	printf("栈中元素有：");
	Node* pt = ps->top;//指定临时指针代替top进行遍历
	while(pt != NULL){
		printf("%d ",pt->data);
		//指向下一个节点
		pt = pt->next;
	}
	printf("\n");
}


//1实现栈的创建 
Stack* stack_create(void){
	//1创建栈
	Stack* ps = (Stack*)malloc(sizeof(Stack));
	if(NULL == ps){
		printf("fail to create stack!\n");
		exit(-1);
	}
	//2初始化栈中成员
	ps->top = NULL;
	ps->cnt = 0;
	//3返回栈的首地址
	return ps;
}
//2实现栈的销毁
void stack_destroy(Stack* ps){
	free(ps);
	ps = NULL;
}





