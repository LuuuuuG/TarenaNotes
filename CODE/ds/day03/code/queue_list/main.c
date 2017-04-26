//使用链式结构实现队列的基本操作

#include "queue_list.h"

/*--------------------Main_beg-------------------------*/
int main(){
	//1 创建队列
	Queue* pq = queue_create();
	printf("%s\n",queue_empty(pq)?"队列空":"队列非空");
	printf("%s\n",queue_full(pq)?"队列满":"队列非满");
	printf("队列中有效元素个数为 %d\n",queue_size(pq));
	printf("----------------入队-----------------------\n");
	int i = 0;
	for(i = 1;i < 7;i++){
		queue_push(pq,i*10+i);
		queue_travel(pq);
	}
	printf("队列中有效元素个数是：%d\n",queue_size(pq));

	printf("---------------出队------------------------\n");
	
	printf("队首元素是 %d\n",queue_front(pq)); //11
	printf("队尾元素是 %d\n",queue_back(pq));// 22
	
	printf("出队元素是 %d\n",queue_pop(pq)); //11
	printf("队首元素是 %d\n",queue_front(pq));//22
	printf("队中有效元素是 %d\n",queue_size(pq));//5
	queue_travel(pq);// 22 33 44 55 66
	printf("--------------清空-------------------------\n");
	queue_clear(pq);
	queue_travel(pq);//nothing
	//2 销毁队列
	queue_destroy(pq);
	pq = NULL;
	return 0;
}

/*--------------------Main_end--------------------------*/

