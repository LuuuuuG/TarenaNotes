//变成实现单链表的基本操作
#include "list.h"

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
