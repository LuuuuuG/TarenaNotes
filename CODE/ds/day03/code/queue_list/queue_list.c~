//使用链式结构实现队列的基本操作

#include "queue_list.h"


//1 实现队列的创建
Queue* queue_create(void){
	//1st 创建队列
	Queue* pq = (Queue*)malloc(sizeof(Queue));
	if (NULL == pq){
		printf("fail to create queue\n");
		exit(-1);
	}
	//2en 初始化队列中的成员
	pq->head = NULL;
	pq->tail = NULL;
	//3rd 返回队列的首地址
	return pq;
}
//2 实现队列的销毁
void queue_destroy(Queue* pq){
	free(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//3 判断队列是否为空
bool queue_empty(Queue* pq){
	return NULL == pq->head;
}
//4 判断队列是否为满
bool queue_full(Queue* pq){
	return false;
}
//5 计算队列中有效元素个数
int queue_size(Queue* pq){
	Node* pt = pq->head;
	int cnt = 0;
	while(pt != NULL){
		cnt++;
		pt = pt->next;
	}
	return cnt;
}
//6 入队
int queue_push(Queue* pq,int data){
	//创建新节点
	Node* pn = (Node*)malloc(sizeof(Node));
	if(NULL == pn){
		printf("fail to create new node\n");
		return ;
	}
	pn->data = data;
	pn->next = NULL;
	//当队列为空，head指向新节点
	if(queue_empty(pq)){
		pq->head = pn;
	}
	//队列不为空时 将新节点放在最后一个节点后面
	else{/*
	Node* pt = pq->head;
	while(pt->next != NULL){
		pt = pt->next;
	}
	pt->next = pn;
	*/
	pq->tail->next = pn;
	}
	//提高空间复杂度，降低时间复杂度
	pq->tail = pn;
}
//7 遍历
void queue_travel(Queue* pq){
	printf("队列中有效元素有:");
	Node* pt = pq->head;
	while(pt != NULL){
		printf("%d ",pt->data);
		pt = pt->next;
	}
	printf("\n");
}
//8 出队
int queue_pop(Queue* pq){
	if(queue_empty(pq)){
		return -1;//表示出队失败
	}
	Node* pt = pq->head;
	//使用临时指针记录要删除节点的地址
	pq->head = pq->head->next;
	//当队列中只有一个节点时，
	if(NULL == pq->head){
		pq->tail = NULL;//将tail指针置为空指针
	}
	int temp = pt->data;//使用临时变量记录要删除的节点元素值
	free(pt);//释放节点元素值
	pt = NULL;
	return temp;
}
//9 查看队首元素
int queue_front(Queue* pq){
	if(queue_empty(pq)){
		return -1;
	}
	return pq->head->data;
}
//10 查看队尾元素
int queue_back(Queue* pq){
	if(queue_empty(pq)){
		return -1;
	}
	return pq->tail->data;
}
//11 清空队列所有元素
int queue_clear(Queue* pq){
	while(-1 != queue_pop(pq)){
		//不断执行出队操作
	}
}













