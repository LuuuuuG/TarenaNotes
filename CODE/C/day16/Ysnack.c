/*
	Mr.Yang贪吃蛇
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define		SIZE	  40
enum {UP = 5,DOWN =2 ,LEFT = 1,RIGHT = 3};
typedef struct{
    int row,col;
}pt;

typedef struct{
    pt head,tail;
}snake;
//part.1 设置蛇初始的位置
void init_snake(snake *p_snake){
	p_snake->head.row = 20;	 
	p_snake->head.col = 20;	 
	p_snake->tail.row = 20;	 
	p_snake->tail.col = 21;
}

//part.2 设置苹果初始位置
void init_apple(pt *p_apple){
	p_apple->row = rand() % SIZE;
	p_apple->col = rand() % SIZE;
}

//part.3 移动蛇位置
void move_snake(snake *p_snake){
	pt tmp = {0};
	int direction = 0;
	printf("请选择移动方向:UP = 5,DOWN =2 ,LEFT = 1,RIGHT = 3");
	scanf("%d",&direction);
	tmp = p_snake->head;//tmp变量记录移动后蛇头移动后的位置
	switch(direction){
		case UP:	
			tmp.row--;
			break;
		case DOWN:
			tmp.row++;
			break;
		case LEFT:
			tmp.col--;
			break;
		case RIGHT:
			tmp.col++;
			break;
		default:
			break;			
	}
	//检查移动后的位置是否合理
	if (tmp.row < 0 || tmp.row >= SIZE - 1) {
		return ;
	}
	if (tmp.col < 0 || tmp.col >= SIZE - 1) {
		return ;
	}
	//检查是否头尾重叠
	if (tmp.row == p_snake->tail.row && tmp.col == p_snake->tail.col) {
		return ;
	}
	//上面三种情况没有发生,移动~
	p_snake->tail = p_snake->head;
	p_snake->head = tmp;
}

//part.4 判断蛇和苹果位置是否重叠
int overlap(const pt *p_apple,const snake *p_snake){
	 //不修改存储区,需要加const
	if((p_snake->head.row ==  p_apple->row) && (p_snake->head.col == p_apple->col)){
		return 1;
	}
	else{
		return 0;
	}
}

//part.5 显示所有内容
void show_map(const pt *p_apple,const snake *p_snake){
		//只显示,不修改,需要加const
	int row = 0,col = 0; 
	for(row = 0;row <= SIZE - 1;row++){
		for(col = 0;col <= SIZE - 1;col++) {
			if(row == p_snake->head.row && col == p_snake->head.col){
				printf("+");
			}
			else if(row == p_snake->tail.row && col == p_snake->tail.col){
				printf("-");
			}
			else if(row == p_apple->row && col == p_apple->col){
				printf("@");
			}
			else{
				printf(" ");
}
}
}
}


int main(){
	srand(time(0));
	snake snk = {0};
	pt apple = {0};	

	init_apple(&apple);
	init_snake(&snk);
	//确定苹果和蛇的位置不重叠
	while(1){
		if(overlap(&apple,&snk)){
			//位置重叠就重新设置苹果位置
			init_apple(&apple);
		}
		else{
			break;	
		}
	}
	//显示初始全部内容
	show_map(&apple,&snk);
	while(1){		
		move_snake(&snk);
		//检查蛇和苹果是否重叠,如果重叠,重蛇苹果位置。
		while(1){
			if(overlap(&apple,&snk)){
				init_apple(&apple);
			}
			else{
				break;
			}
		}
		show_map(&apple,&snk);
	}
 
	return 0;
}

