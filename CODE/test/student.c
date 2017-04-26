//学生信息管理系统。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node{
	int id;//记录学号
	char usr[10];//记录姓名
	int sex;//记录性别 1表示男 0表示女
	int Chinese;
	int Math;
	int English;//分别记录语数外成绩
	int total;
	struct node* next;
}Node;

typedef struct{
	Node* head;
	Node* tail;
	int cnt;
}List;

//0 创建单链表
List* list_create(void);

//1 初始化界面
void init(void);
//2 退出系统
void quit(void);

//3 增
Node* add(void);
//3.1 插入到单链表
void list_push_head(List* pl);
//4 删
int dele(List* pl);
//5 改
int rev(List* pl);
//6 查找
Node* seek(List* pl);
//7 打印
void show(Node* pn);
//8 遍历
void travel(List* pl);



/*---------------Main_beg--------------------*/
int main(){
	//展示初始化界面
	init();
	//创建单链表
	List* pl = list_create();
	int opt = 0;
	
	while(opt != 6){
		//选择操作
		scanf("%d",&opt);
		if(opt == 1){		//增*
			list_push_head(pl);
		}
		else if(opt == 2){
		//删
		}
		else if(opt == 3){
		//改
		}
		
		else if(opt == 4){		//查*/
			Node* pt = seek(pl);
			show(pt);
		}
		else if(opt == 5){		//展示所有学生信息
			travel(pl);
		}
	}//退出
	
	return 0;
}

/*--------------Main_end---------------------*/

//0 创建单链表
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

//1 初始化界面
void init(void){
	printf("\n************************************************************************************\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                       学 生 信 息 管 理 系 统                                    *\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                   1 增加 2 删除 3 修改 4 查看  5 退出                            *\n");
	printf("\n*                                                                                  *\n");
	printf("\n*                                                      __Design by LuGang__        *\n");
	printf("\n*                                                                                  *\n");
	printf("\n************************************************************************************\n");
}

//2 退出系统
void quit(void){
	exit(-1);
}


//3 增
Node* add(void){
	int id;//记录学号
	char usr[10];//记录姓名
	int sex;//记录性别 1表示男 0表示女
	int Chinese;
	int Math;
	int English;//分别记录语数外成绩
	int total;

	//创建新节点	//node_create
	Node* pn = (Node*)malloc(sizeof(Node));
	if(NULL == pn){
		printf("fail to create new node\n");
		return NULL;
	}
	printf("请输入学生学号:");
	scanf("%d",&id);
    scanf("%*[^\n]");    
    scanf("%*c");
	printf("请输入学生姓名:");
	fgets(usr,10,stdin);
    if(strlen(usr) == 9 && usr[8] != '\n'){ //确保有多余数据的时候，才清理
        scanf("%*[^\n]");    
        scanf("%*c");
    }   

	printf("请输入学生性别:");
	scanf("%d",&sex);
	printf("请输入学生语文成绩:");
	scanf("%d",&Chinese);
	printf("请输入学生数学成绩:");
	scanf("%d",&Math);
	printf("请输入学生英语成绩:");
	scanf("%d",&English);
	total = Chinese + Math + English;

	//初始化
	pn->id = id;
	pn->usr[10] = usr[10];
	pn->sex = sex;
	pn->Chinese = Chinese;
	pn->Math = Math;
	pn->English = English;
	pn->total = total;
	return pn;	
}

//3.2 判断是否空
bool list_empty(List* pl){
	return NULL == pl->head;
}
//3.1 插入到单链表
void list_push_head(List* pl){
	Node* pn = add();
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

//4 删
int dele(List* pl){
	seek(pl);

}

//5 改
int rev(List* pl){

}

//6 查找
Node* seek(List* pl){
	int choice = 0;
	char usr[10];
	int total;
	printf("按姓名查找 -- 1\n按总成绩查找 -- 2");
	scanf("%d",&choice);
	scanf("%*[^\n]");    
	scanf("%*c");
	Node* pt = pl->head;
	if(1 == choice){
			printf("请输入要查找的学生姓名:");
			fgets(usr,10,stdin);
		    if(strlen(usr) == 9 && usr[8] != '\n'){ 
			scanf("%*[^\n]");    
	        scanf("%*c");
		    }   
			if(pt->usr[10] != usr[10]){
				pt = pt->next;
			}
			else{
				return pt;
			}
	}
	else{	
			printf("请输入要查找的学生的总成绩:");
			scanf("%d",&total);
			if(total != pt->total){
				pt = pt->next;
			}
			else{
				return pt;
			}
	}
}

//7 打印
void show(Node* pn){
/*	int id;//记录学号
	char usr[10];//记录姓名
	int sex;//记录性别 1表示男 0表示女
	int Chinese;
	int Math;
	int English;//分别记录语数外成绩
	int total;*/
	printf("学生学号:%d\n",pn->id);
	printf("学生姓名:%s\n",pn->usr);
	printf("学生性别:%s\n",pn->sex?"男":"女");
	printf("学生语文成绩:%d\n",pn->Chinese);
	printf("学生数学成绩:%d\n",pn->Math);
	printf("学生英语成绩:%d\n",pn->English);
	printf("学生总成绩:%d\n",pn->total);
}

//8 遍历
void travel(List* pl){
	Node* pt = pl->head;
	while(NULL != pt){
		show(pt);
		pt = pt->next;
	}
	printf("\n");
}



















