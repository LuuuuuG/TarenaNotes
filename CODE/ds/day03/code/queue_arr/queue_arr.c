//顺序结构实现队列的基本操作
#include "queue_arr.h"




//1 实现队列创建
Queue* queue_create(int len){
	//1st 创建队列
	Queue* pq = (Queue*)malloc(sizeof(Queue));//动态分配内存申请对列
	if(NULL == pq){
		printf("fail to creat queue\n");
		exit(-1);
	}
	//2ed 初始化队列中所有成员
	pq->arr = (int*)malloc(sizeof(int)*len);//动态分派内存申请数组
	if(NULL == pq->arr){
		printf("fail to creat queue\n");
		exit(-1);
	}
	pq->len = len;
	pq->front = 0;
	pq->cnt = 0;
	//3rd 返回队列首地址
	return pq;
}
//2 队列的销毁
void queue_destroy(Queue* pq){
	free(pq->arr);
	pq->arr = NULL;
	free(pq);
	pq = NULL;
}
//3 判断队列是否空
bool queue_empty(Queue* pq){
	return 0 == pq->cnt;
}
//4 判断队列是否满
bool queue_full(Queue* pq){
	return pq->len == pq->cnt;
}
//5 入队
void queue_push(Queue* pq,int data){
	if(queue_full(pq)){
		printf("queue is full,%d fail to push\n",data);
		return ; //结束当前函数
	}
	
		pq->arr[(pq->front + pq->cnt) % pq->len] = data;
		pq->cnt++;
	
}
//6 遍历
void queue_travel(Queue* pq){
	printf("队列中的元素有：");
	int i = 0;
	for(i = pq->front;i < pq->cnt + pq->front;i++){
		printf("%d ",pq->arr[i % pq->len]);  //避免i越界
	}
	printf("\n");
}
//7 计算有效元素个数
int queue_size(Queue* pq){
	return pq->cnt;
}
//8 查看队列中队首元素
int queue_front(Queue* pq){
	//判断队列是否为空
	if(queue_empty(pq)){
		return -1;//查看失败
	}
	return pq->arr[pq->front % pq->len];
}
//9 查看队列中队尾元素
int queue_back(Queue* pq){
	//判断队列是否为空
	if(queue_empty(pq)){
		return -1;//查看失败
	}
	return pq->arr[(pq->front + pq->cnt - 1) % pq->len];
}
//10 出队
int queue_pop(Queue* pq){
	if(queue_empty(pq)){
		return -1;//出队失败
	}
	int temp =  pq->arr[pq->front % pq->len];
	pq->front++;
	pq->cnt--;
	return temp;
}
//11 清空队列
void queue_clear(Queue* pq){
	pq->front = 0;
	pq->cnt = 0;
}
