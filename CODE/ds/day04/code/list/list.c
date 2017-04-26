//变成实现单链表的基本操作
#include "list.h"
//定义几诶单的数据类型

//1 单链表的创建
List* list_create(void){
	//创建
	List* pl = (List*)malloc(sizeof(List));
	if(NULL == pl){
		printf("fail to create list");
		exit(-1);
	}
	//初始化
	pl->head = NULL;
	pl->tail = NULL;
	pl->cnt = 0;
	//返回
	return pl;
}
//2 单链表的销毁
void list_destroy(List* pl){
	free(pl);
	pl = NULL;
}
//3 判断是否空
bool list_empty(List* pl){
	return NULL == pl->head;
}
//4 判断是否满
bool list_full(List* pl){
	return false;
}
//5 计算有效元素个数
int list_size(List* pl){
	return pl->cnt;
}

//6.0 创建新节点 单独封装成一个函数
Node* node_create(int data){
	//创建新节点	//node_create
	Node* pn = (Node*)malloc(sizeof(Node));
	if(NULL == pn){
		printf("fail to create new node\n");
		return NULL;
	}
	//初始化
	pn->data = data;
	pn->next = NULL;
	return pn;
}

//6 插入新元素到单链表开头
void list_push_head(List* pl,int data){
	Node* pn = node_create(data);
	if(NULL == pn){
		printf("fail to create new node\n");
		return ;
	}
	//当单链表为空时
	if(list_empty(pl)){
		pl->tail = pn;
	}
	else{
		pn->next = pl->head;
	}
	pl->head = pn;
	pl->cnt++;
}
//6.1 插入新元素到单链表末尾
void list_push_tail(List* pl,int data){
	//创建新节点
	Node* pn = node_create(data);
	if(NULL == pn){
		printf("fail to create new node\n");
		return ;
	}
	//当单链表为空时
	if(list_empty(pl)){
		pl->head = pn;
	}
	else{
		pl->tail->next = pn;
	}
	pl->tail = pn;
	pl->cnt++;
	
}
//6.3 插入新元素到指定位置
void list_push_pos(List* pl,int data,int pos){
	//1判断坐标的合法性
	if(pos < 0 || pos > list_size(pl)){
		printf("坐标不合法，插入元素%d失败\n",data);
		return ;
		//pos = 0;	//默认插入到开头位置
		//pos = list_size(pl);	//默认插入到末尾位置
	}
	//2当pos = 0时，新元素插入到开头位置
	else if(0 == pos){
		list_push_head(pl,data);
	}
	//3当pos = cnt时，插入到末尾位置
	else if(pos == list_size(pl)){
		list_push_tail(pl,data);
	}
	//4当pos = pos时，采用归纳发插入到中间位置
	else{
		//创建新节点
		Node* pn = node_create(data);
		if(NULL == pn){
			printf("fail to create new node,program end\n");
			return ;
		}
		//使用循环将相对于pos=1时多出来的next执行完
		Node* pt = pl->head;
		int i = 0;
		for(i = 1;i < pos;i++){
			pt = pt->next;//指向下一个节点。
		}
		//编写pos = 1时的处理代码即可
		pn->next = pt->next;
		pt->next = pn;
		//节点个数加1.
		pl->cnt++;
	}
}
//7 遍历
void list_travel(List* pl){
	Node* pt = pl->head;
	printf("单链表中的元素有:");
	while(NULL != pt){
		printf("%d ",pt->data);
		pt = pt->next;
	}
	printf("\n");
}
//8 查看表头元素
int list_get_head(List* pl){
	if(list_empty(pl)){
		return -1;//表示查看失败
	}	
	return pl->head->data;
}
//9 查看表尾元素
int list_get_tail(List* pl){
	if(list_empty(pl)){
		return -1;//表示查看失败
	}	
	return pl->tail->data;
}
//10 删除头节点元素
int list_pop_head(List* pl){
	if(list_empty(pl)){
		return -1;//表示删除失败
	}
	//使用临时指针记录要删除节点的地址
	Node* pt =pl->head;
	//让head指针指向下一个节点
	pl->head = pl->head->next;
	//处理当单链表中只有一个节点的情况
	if(NULL == pl->head){
		pl->tail = NULL;
	}
	//使用临时变量记录要删除节点的元素值
	int temp = pt->data;
	//释放节点的动态内存
	free(pt);
	pt = NULL;
	//节点个数减1
	pl->cnt--;
	//返回删除节点中的元素值
	return temp;
}

//11 删除尾节点元素
int list_pop_tail(List* pl){
	//当单链表为空时
	if(list_empty(pl)){
		return -1;//删除节点失败
	}
	//当单链表中只有一个节点时
	else if (1 == list_size(pl)){
		/*int temp = pl->head->data;*/
		return pl->head->data;
		free(pl->head);
		pl->head = NULL;
		pl->tail = NULL;
		pl->cnt = 0;
		/*return temp;*/
	}
	//当单链表中至少有两个节点时
	Node* pt = pl->head;
	//用循环找到倒数第二个节点的地址
	while(pt->next->next != NULL){
		pt = pt->next;
	}
	int temp = pl->tail->data;
	pl->tail = pt;
	//释放尾节点，并置为空指针
	free(pt->next);
	pt->next = NULL;
	/*
	pt = pt->next;
	free(pt);
	pt = NULL;
	pl->tail->next = NULL;
	*/
	pl->cnt--;
	return temp;
}
//12 删除指定编号的元素
int list_pop_pos(List* pl,int pos){
	//1 判断坐标的合法性	
	if(pos < 0 || pos >= list_size(pl)){
		printf("坐标不合法，删除元素失败\n");
		return -1;
	}
	//2 当pos = 0时相当于删除头节点
	if(0 == pos){
		return list_pop_head(pl);
	}
	//3 当pos = list_szie(pl) - 1时，相当于删除尾节点
	else if(pos == list_size(pl) - 1){
		return list_pop_tail(pl);
	}
	//4 当pos = pos时，采用归纳发来删除指定节点。
	else{
		//1 使用临时指针替代head
		Node* pt = pl->head;
		//2 使用循环将pos = 1时多出来的next执行完
		int i = 0;
		for(i = 1;i < pos;i++){
			pt = pt->next;
		}
		//3编写pos = 1时的代码
		Node* pm = pt->next;
		pt->next = pm->next;
		//4 使用临时变量记录哟啊删除节点的元素值
		int temp = pm->data;
		//5 释放节点的动态内存
		free(pm);
		pm = NULL;
		pl->cnt--;
		return temp;
	}
}
//13 清空单链表
void list_clear(List* pl){
	while(-1 != list_pop_head(pl));
}

