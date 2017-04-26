//变成实现单链表的基本操作
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义几个单链表数据类型
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


/*-------------------------------------------*/
int main(){
	//1 创建
	List* pl = list_create();
	printf("----------------------------------\n");
	printf("%s\n",list_empty(pl)?"链表空":"链表非空");
	printf("%s\n",list_full(pl)?"链表满":"链表非满");
	printf("链表中有效元素个数是%d\n",list_size(pl));
	printf("\n------------头插入--------------------\n");
	int i = 0;
	for(i = 1;i < 7;i++){
		list_push_head(pl,i*10+i);
		list_travel(pl);// 66 55 44 33 22 11
	}
	printf("单链表中有效元素的个数是:%d\n",list_size(pl));
	
	printf("\n------------尾插入----------------------\n");
	list_push_tail(pl,77);
	list_travel(pl);// 66 55 44 33 22 11 77
	printf("单链表中有效元素的个数是:%d\n",list_size(pl));
	
	printf("\n------------指定插入--------------------\n");
	list_push_pos(pl,88,-2);//插入88失败		
	list_travel(pl);		//66 55 44 33 22 11 77
	list_push_pos(pl,88,0);		
	list_travel(pl);		//88 66 55 44 33 22 11 77
	list_push_pos(pl,99,2);		
	list_travel(pl);		//88 66 99 55 44 33 22 11 77
	list_push_pos(pl,111,8);		
	list_travel(pl);		//88 66 99 55 44 33 22 11 111 77
	list_push_pos(pl,222,10);		
	list_travel(pl);		//88 66 99 55 44 33 22 11 111 77 222
	printf("单链表中有效元素的个数是:%d\n",list_size(pl));//11
	
	printf("\n------------查看,删除--------------------\n");
	printf("单链表中头节点的元素是%d\n",list_get_head(pl));//88
	printf("单链表中尾节点的元素是%d\n",list_get_tail(pl));//222
	printf("单链表中删除的头节点的元素是%d\n",list_pop_head(pl));//88
	printf("单链表中有效元素的个数是:%d\n",list_size(pl));//10
	list_travel(pl);//66 99 55 44 33 22 11 111 77 222
	
	printf("单链表中删除的尾节点的元素是%d\n",list_pop_tail(pl));//222
	printf("单链表中尾节点的元素是%d\n",list_get_tail(pl));//222
	printf("单链表中有效元素的个数是:%d\n",list_size(pl));//
	list_travel(pl);//66 99 55 44 33 22 11 111 77 
	
	printf("\n------------指定删除--------------------\n");
	printf("单链表中删除的尾节点的元素是%d\n",list_pop_pos(pl,-2));//-1
	printf("单链表中删除的尾节点的元素是%d\n",list_pop_pos(pl,0));//66
	printf("单链表中删除的尾节点的元素是%d\n",list_pop_pos(pl,2));//44
	printf("单链表中删除的尾节点的元素是%d\n",list_pop_pos(pl,6));//77
	printf("单链表中头节点的元素是%d\n",list_get_head(pl));//99
	printf("单链表中尾节点的元素是%d\n",list_get_tail(pl));//111
	printf("单链表中有效元素的个数是:%d\n",list_size(pl));//6
	list_travel(pl);//99 55 33 22 11 111
	
	printf("\n---------------clear-------------------\n");
	list_clear(pl);
	list_travel(pl);//啥也没有
	//2销毁
	list_destroy(pl);
	return 0;
}

/*-------------------------------------------*/

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

