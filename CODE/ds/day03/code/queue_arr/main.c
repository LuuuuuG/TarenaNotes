//顺序结构实现队列的基本操作
#include "queue_arr.h"


/*---------------Main_beg--------------------*/

int main(){
	//1 创建队列
	Queue* pq = queue_create(5);
	//3 判断队列是否空
	printf("%s\n",queue_empty(pq) ? "队列空":"队列非空");
	//4 判断队列是否满
	printf("%s\n",queue_full(pq)  ? "队列满":"队列非满");

	//计算有效元素个数
	printf("队列中有效元素个数为%d\n",queue_size(pq));
	
	printf("-------------入队---------------------\n");
	//5 入队
	int i = 0;
	for(i = 1;i < 7;i++){
		queue_push(pq,i*10+i);
		queue_travel(pq); //11 22 33 44 55
		}
	printf("队列中有效元素个数为%d\n",queue_size(pq)); //5
	
	printf("-------------------------------------\n");
	//查看队首元素
	printf("队首元素是%d\n",queue_front(pq));//11
	//查看队尾元素
	printf("队尾元素是%d\n",queue_back(pq));//55
		
	printf("--------------出队----------------------\n");
	//10 出队
	printf("出队的元素是: %d\n",queue_pop(pq));
	printf("队列的有效元素个数为 %d\n",queue_size(pq));
	printf("队首的元素为 %d\n",queue_front(pq));
	queue_travel(pq);  //
	
	printf("-------------清空-----------------------\n");
	queue_clear(pq);
	queue_travel(pq);  //
	//2 销毁队列
	queue_destroy(pq);
	pq = NULL;
	
	return 0;
}

/*---------------Main_end--------------------*/
