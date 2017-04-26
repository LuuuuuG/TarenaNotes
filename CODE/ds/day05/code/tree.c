#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data,new_data;
	struct node* left;//记录左子节点
	struct node* right;//记录右子节点
}Node;
//定义二叉树的数据类型
typedef struct{
	Node* root;//记录根节点
	int cnt;//记录有效元素个数
}Binary_tree;

//1 有序二叉树的创建
Binary_tree* binary_tree_create(void);
//2 有序二叉树的销毁
void binary_tree_destroy(Binary_tree* pbt);
//3 插入
void binary_tree_insert(Binary_tree* pbt,int data);
//3.1 插入元素的递归函数
void insert(Node** pRoot,Node* pn);
/*二级指针的主要用途为用作形参接收一级指针实参的地址*/

//4 遍历
void binary_tree_travel(Binary_tree* pbt);
//4.1 遍历的递归函数
void travel(Node* root);

//5 查找指定元素
Node** binary_tree_find(Binary_tree* pbt,int data);
//5.1 查找的递归函数
Node** find(Node** pRoot,int data);

//6 删除
int binary_tree_delete(Binary_tree* pbt,int data);

//7 修改
void binary_tree_modify(Binary_tree* pbt,int data,int new_data);

//8 判空
bool binary_tree_empty(Binary_tree* pbt);

//9 判满
bool binary_tree_full(Binary_tree* pbt);

//10 查看根节点
int binary_tree_root(Binary_tree* pbt);

//11 计算有效元素
int binary_tree_size(Binary_tree* pbt);

//12 清空
void binary_tree_clear(Binary_tree* pbt);
//12.1 清空递归
void clear(Node** pRoot);

/*------------Main_bgn-----------------*/
int main(){
	//1 创建
	Binary_tree* pbt = binary_tree_create();
	printf("--------------插入---------------\n");
	
	binary_tree_insert(pbt,50);
	binary_tree_travel(pbt);//50

	binary_tree_insert(pbt,70);
	binary_tree_travel(pbt);//50 70

	binary_tree_insert(pbt,20);
	binary_tree_travel(pbt);//20 50 70

	binary_tree_insert(pbt,60);
	binary_tree_travel(pbt);//20 50 60 70
	printf("-------------删除-------------\n");
	
	binary_tree_delete(pbt,50);
	binary_tree_travel(pbt);//20 60 70


	printf("-------------判空/满----------------\n");
	printf("%s\n",binary_tree_empty(pbt)?"空":"非空");//非空
	printf("%s\n",binary_tree_full(pbt)?"满":"非满");//非满
	printf("有序二叉树中有效元素个数是:%d\n",binary_tree_size(pbt));//3
	printf("有序二叉树中根节点元素是:%d\n",binary_tree_root(pbt));//60

	printf("--------------修改------------\n");
	
	binary_tree_modify(pbt,20,200);
	binary_tree_travel(pbt);//60 70 200

	printf("--------------清空---------------\n");
	binary_tree_clear(pbt);
	binary_tree_travel(pbt);//啥都没有

	//2 销毁
	binary_tree_destroy(pbt);
	pbt = NULL;
	return 0;
}
/*------------Main_end-----------------*/


//1 有序二叉树的创建
Binary_tree* binary_tree_create(void){
	//创建
	Binary_tree* pbt = (Binary_tree*)malloc(sizeof(Binary_tree));
	if(NULL == pbt){
		printf("fail to create pbt\n");
		exit(-1);
	}
	//初始化
	pbt->cnt = 0;
	pbt->root = NULL;
	//返回首地址
	return pbt;
}

//2 有序二叉树的销毁
void binary_tree_destroy(Binary_tree* pbt){
	free(pbt);
	pbt = NULL;
}

//3 插入
void binary_tree_insert(Binary_tree* pbt,int data){
	//创建新节点，并初始化
	Node* pn = (Node*)malloc(sizeof(Node));
	if (NULL == pn){
		printf("fail to create new node\n");
		return ;//结束当前函数
	}
	pn->data = data;
	pn->left = NULL;
	pn->right = NULL;
	//插入新节点到合适位置,调用递归函数
	insert(&pbt->root/*一级指针取地址*/,pn);
	//节点元素个数加1
	pbt->cnt++;
}

//3.1 插入元素的递归函数
void insert(Node** pRoot,Node* pn){
	//如果有序二叉树为空，直接插入
	if(NULL == *pRoot){
		*pRoot = pn; //将新节点的地址作为root的地址
		return;//结束当前函数
	}
	//不空,和根节点元素比较,小了插左,大了插右
	if((*pRoot)->data > pn->data){
		insert(&(*pRoot)->left,pn);  // 优先运算: -> * &
	}
	else{
		insert(&(*pRoot)->right,pn);
	}
	
}

//4 遍历
void binary_tree_travel(Binary_tree* pbt){
	//采用中序遍历,采用递归函数
	travel(pbt->root);
	
	printf("\n");
}

//4.1 遍历的递归函数
void travel(Node* root){
	if(root != NULL){
		//遍历左子树,递归
		travel(root->left);
		//遍历根节点
		printf("%d ",root->data);
		//遍历右子树,递归
		travel(root->right);
	}
}

//5 查找指定元素
Node** binary_tree_find(Binary_tree* pbt,int data){
	//调用递归函数进行查找
	return find(&pbt->root,data);
}
//5.1 查找的递归函数
//实际返回的是指向目标元素所在节点的指针的地址
Node** find(Node** pRoot,int data){
	//1)如果空
	if(NULL == *pRoot){
		return pRoot;//代表查找失败
	}
	//2)如果目标元素等于根节点元素
	if(data == (*pRoot)->data){
		return pRoot;//代表查找成功
	}
	//3)如果目标元素小于 根节点元素
	else if(data < (*pRoot)->data){
		return find(&(*pRoot)->left,data);
	}
	//4)    	    大于 根节点元素
	else{
		return find(&(*pRoot)->right,data);
	}

}

//6 删除
int binary_tree_delete(Binary_tree* pbt,int data){
	//1)查找目标元素所在的地址
	Node** ppt = binary_tree_find(pbt,data);
		if(NULL == *ppt){
			return -1;//表示查找失败
		}
	
	//2)将该节点的左子树合并到右子树中
	if((*ppt)->left != NULL){
		insert(&(*ppt)->right,(*ppt)->left);
	}
	//3)使用临时指针记录要删除的节点地址
	Node* pt = *ppt;
	//4)将原来指向要删除节点地址的指针指向右子节点
	*ppt = (*ppt)->right;
	//5)删除目标元素所在的节点
	free(pt);
	//6)节点元素的个数减1
	pbt->cnt--;
	//7)返回删除成功
	return 0;
}


//7 修改
void binary_tree_modify(Binary_tree* pbt,int data,int new_data){
	//1)判断二叉树是否为空
	if(binary_tree_empty(pbt)){
		printf("修改失败\n");
	}
	//2)删除data
	int res = binary_tree_delete(pbt,data);
	if(-1 == res){
		printf("目标元素不存在，修改失败\n");
		return;//结束当前函数
	}
	//3)插入new_data
	binary_tree_insert(pbt,new_data);
}

//8 判空
bool binary_tree_empty(Binary_tree* pbt){
	return 0 == pbt->cnt;
	// NULL == pbt->root;
	
}

//9 判满
bool binary_tree_full(Binary_tree* pbt){
	return false;
}
//10 查看根节点
int binary_tree_root(Binary_tree* pbt){
	//判断有序二叉树是否为空
	if(binary_tree_empty(pbt)){
		return -1;
	}
	return pbt->root->data;
}

//11 计算有效元素
int binary_tree_size(Binary_tree* pbt){
	return pbt->cnt;
}

//12 清空
void binary_tree_clear(Binary_tree* pbt){
	//1)调用递归函数实现真正的清空
	clear(&pbt->root);
	//2)节点个数变成0
	pbt->cnt = 0;
}


//12.1 清空递归
void clear(Node** pRoot){
	if(*pRoot != NULL){
		//1)清空左子树--递归
		clear(&(*pRoot)->left);
		//2)清空右子树--递归
		clear(&(*pRoot)->right);
		//3)清空根节点
		free(*pRoot);
		*pRoot = NULL;
	}
}


