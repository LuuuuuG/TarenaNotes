#ifndef _QUEUE_ARR_H
#define _QUEUE_ARR_H

//顺序结构实现队列的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义队列数据类型
typedef struct{
	int* arr;//记录数组首地址
	int len;//记录数组中最多存储的个数
	int front;//记录队列中队首元素的下标
	int cnt;//记录队列中有效元素个数
}Queue;

//1 实现队列创建
Queue* queue_create(int len);
//2 队列的销毁
void queue_destroy(Queue* pq);
//3 判断队列是否空
bool queue_empty(Queue* pq);
//4 判断队列是否满
bool queue_full(Queue* pq);
//5 入队
void queue_push(Queue* pq,int data);
//6 遍历
void queue_travel(Queue* pq);
//7 计算有效元素个数
int queue_size(Queue* pq);
//8 查看队列中队首元素
int queue_front(Queue* pq);
//9 查看队列中队尾元素
int queue_back(Queue* pq);
//10 出队
int queue_pop(Queue* pq);
//11 清空队列
void queue_clear(Queue* pq);

#endif //_QUEUE_ARR_H

