//stack_list.h
#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

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

#endif  //_STACK_LIST_H_
