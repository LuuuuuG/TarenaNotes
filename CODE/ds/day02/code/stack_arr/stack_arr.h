//stack_arr.h
#ifndef _STACK_ARR_H
#define _STACK_ARR_H


//使用顺序结构实现栈的基本操作
#include <stdio.h>
#include <stdlib.h>
//定义栈的数据类型
typedef struct{
//	int arr[5];
	int* arr;
	int len;//记录数组中可以存放的元素个数
	int pos;//记录数组下标
}Stack;

//1 实现栈的创建
Stack* stack_create(int len);
//2 实现栈的销毁
void stack_destroy(Stack* ps);

//3 判断栈是否为空
int stack_empty(Stack* ps);
//4 判断栈是否为满
int stack_full(Stack* ps);
//5 入栈
void stack_push(Stack* ps,int data);
//6 出栈
int stack_pop(Stack* ps);
//7 查看栈顶元素
int stack_peek(Stack* ps);
//8 计算栈中有效元素个数
int stack_size(Stack* ps);
//9 遍历栈中所有元素
void stack_travel(Stack* ps);
//10 清空栈
void stack_clear(Stack* ps);

#endif	//	_STACK_ARR_H
