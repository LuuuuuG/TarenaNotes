#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int mouse_row = 0,mouse_col = 0;//老鼠的行列号
	int ham_row = 0,ham_col = 0;//锤子的行列号
	int hits = 0,missed = 0;//错过的次数
	int times = 0;//游戏次数
	int num = 0;  //循环变量
    int row = 0,col = 0;//地图的循环变量
	srand(time(0));
	
	printf("请输入游戏次数：");
	scanf("%d",&times);
	printf("***\n***\n***\n");//打印地图
	
	for (num = 1;num <= times;num++){
		mouse_row = rand() % 3 + 1;
		mouse_col = rand() % 3 + 1;

		printf("请输入锤子的位置：");
		scanf("%d%d",&ham_row,&ham_col);
		//行输入1~3以外的数字的处理
		if(ham_row < 0){          
	          ham_row = 0 - ham_row;
		}
		if(ham_row < 1 || ham_row >3){
		  ham_row = ham_row % 3 + 1;
		}
		//列输入1~3以外的数字的处理
		if(ham_col < 0){
	      	  ham_col = 0 - ham_col;
		}
		if(ham_col <1 || ham_col >3){
	          ham_col = ham_col % 3 + 1;
		}
		//记录是否命中
		if(mouse_row == ham_row && mouse_col == ham_col){
			hits++; 
		}
		else{
			missed++;
		}
		//画地图
		for(row = 1;row <= 3;row++){
			for(col = 1;col <=3;col++){
				if(ham_row == row && ham_col == col){
					printf("O");//打印锤子
				}
				else if(mouse_row == row && mouse_col == col){
					printf("X");//打印老鼠
				}
				else{
					printf("*");//打印其他空位置
				}

			}
			printf("\n");
		}

		if(mouse_row == ham_row && mouse_col == ham_col){
			printf("打中了\n");

		}
		else{
			printf("没打中\n");
		}
 		printf("打中%d,错过%d\n",hits,missed);
	}

  return 0;

}



















