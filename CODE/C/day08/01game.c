#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*int main(){
	srand(time(0));
	int map[10][10] = {0};
	int i = 0,j = 0,m = 0,n = 0;
	int boom[i][j];
	int num = 0;
	 for (;num < 10;){
			m = rand() % 10;
			n = rand() % 10;
		if(map[m][n] != -1){
			map[m][n] = -1; 
			num++;
		}
		}

	 for (i = 0;i < 10;i++){
		for(j = 0;j < 10;j++){
			if(map [i][j]){
				printf("X");
			}
			else{
				printf("o");
			}
			
		}
		printf("\n");
	 }


	return 0;
}*/

int main(){
	int map[10][10] = {0};    //初始化  此时地图上全是空位置0
	int row = 0,col = 0;
	int cnt = 0;	//用来计算地雷的个数
	int num = 0;
	int newrow = 0,newcol = 0;
	srand(time(0));
	do{						
		row = rand() % 10;		
		col = rand() % 10; 
		if(map[row][col] !=1){		//用 -1 表示地雷的位置
			map[row][col] = 1;		//地图上不是-1的地方变成-1
			cnt++;
		}
	}while(cnt < 10);



	do{
		for (row = 0;row < 10;row++){
			for (col = 0;col < 10;col++){
			
				map[newrow][newcol] = map[row][col + 1] + 1;  //up 
				map[newrow][newcol] = map[row][col - 1] + 1;  //down
				map[newrow][newcol] = map[row - 1][col] + 1; //left
				map[newrow][newcol] = map[row + 1][col] + 1; //right
				map[newrow][newcol] = map[row + 1][col + 1] - 1; 	 
				map[newrow][newcol] = map[row + 1][col - 1] + 1; 
				map[newrow][newcol] = map[row - 1][col - 1] + 1; 
				map[newrow][newcol] = map[row - 1][col + 1] + 1; 
			if(newrow < 0 || newrow > 9){
				continue;
			}
			if(newcol < 0|| newcol > 9){
				continue;
			}
			if (map[newrow][newcol] == 1){
				continue;
			}
			}
			}
	}while(map[row][col] == 1);
		
	
	for(row = 0;row < 10;row++){
		for(col = 0;col < 10;col++){
			if(map[row][col] == 1){
				printf("X");
			}
			else if(map[row][col] == 0){
				printf("o");
			}
			else{
				printf("%d",map[newrow][newcol] - 1);
			}
		}
		printf("\n");
	}

	return 0;
}
