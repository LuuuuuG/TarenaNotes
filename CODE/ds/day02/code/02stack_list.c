//使用链式结构实现栈的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义节点的数据类型
typedef struct node{
	int data;//记录数据元素本身
	struct node* next;//记录下一个节点地址
}Node;


//定义栈的数据类型
typedef struct{
	Node* top;//记录第一个节点的地址
	int cnt;//记录有效元素的个数
}Stack;

//1实现栈的创建 
Stack* stack_create(void);
//2实现栈的销毁
void stack_destroy(Stack* ps);
//3实现入栈操作
void stack_push(Stack* ps,int data);
//4实现遍历
void stack_travel(Stack* ps);
//5判断栈是否空
bool stack_empty(Stack* ps);    //布尔类型
//6判断栈是否满
bool stack_full(Stack* ps);
//7查看栈顶元素
int stack_peek(Stack* ps);
//8计算栈中有效元素的个数
int stack_size(Stack* ps);
//9出栈
int stack_pop(Stack* ps);
//10 清空栈中内容
void stack_clear(Stack* ps);

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
	//不断执行出栈操作	
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






