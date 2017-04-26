/*
	贪吃蛇游戏
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define		SIZE	40

enum {DOWN,LEFT,UP,RIGHT};

typedef struct{
	int row,col;
}pt;

//蛇前进方向
void slip(){


}

int main(){
	srand(time(0));
	pt pt_s_h = {20,20}/*初始化蛇头*/,
	   pt_s_b = {20,21}/*初始化蛇尾*/,
	   pt_apple = {20,10}/*苹果*/;

	int num = 0,row = 0,col = 0;
	
	while(1){
		
	
	}
	
	
	
	for(row= 0;row <= SIZE - 1;row++){
		for(col = 0;col <= SIZE - 1;col++){
				if(row == pt_s_h.row && col == pt_s_h.col){
					printf("+");
				}
				if(row == pt_s_b.row && col == pt_s_b.col){
					printf("-");
				}
				if(row == pt_apple.row && col == pt_apple.col){
					printf("@");
				}
				
		}
	}
                                                            
	return 0;
}









                                                                                                










