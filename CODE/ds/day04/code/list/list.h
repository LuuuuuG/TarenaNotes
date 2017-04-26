//变成实现单链表的基本操作
#ifndef _LIST_H_
#define _LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//定义几诶单的数据类型
typedef struct node{
	int data;
	struct node* next;
}Node;

typedef struct{
	Node* head;
	Node* tail;
	int cnt;
}List;
//1 单链表的创建
List* list_create(void);
//2 单链表的销毁
void list_destroy(List* pl);
//3 判断是否空
bool list_empty(List* pl);
//4 判断是否满
bool list_full(List* pl);
//5 计算有效元素个数
int list_size(List* pl);
//6.0 创建新节点
Node* node_create(int data);
//6 插入新元素到单链表开头
void list_push_head(List* pl,int data);
//6.1 插入新元素到单链表末尾
void list_push_tail(List* pl,int data);
//6.3 插入新元素到指定位置
void list_push_pos(List* pl,int data,int pos);
//7 遍历
void list_travel(List* pl);
//8 查看表头元素
int list_get_head(List* pl);
//9 查看表尾元素
int list_get_tail(List* pl);
//10 删除头节点元素
int list_pop_head(List* pl);
//11 删除尾节点元素
int list_pop_tail(List* pl);
//12 删除指定编号的元素
int list_pop_pos(List* pl,int pos);
//13 清空单链表
void list_clear(List* pl);
#endif //_LIST_H_
