#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int map[10][10] = {0},row = 0,col = 0,cnt = 0,num = 0,newrow = 0,newcol = 0;
	int delta[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	srand(time(0));
	//crease mine 
	do{		
		row = rand() % 10;
		col = rand() % 10;
		if (map[row][col] != -1){
			map[row][col] = -1;
			cnt++;
		}
	}while(cnt < 10);

	//print numbers next mine in map
	for (row = 0;row <= 9;row++){
		for(col = 0;col <= 9;col++){
			if(map[row][col] != -1){
				continue;
			}
			for (num = 0;num <= 7;num++){
				newrow = row + delta[num][0];
				newcol = col + delta[num][1];
				if (newrow < 0|| newrow > 9){
					continue;
				}
				if (newcol < 0|| newcol > 9){
					continue;
				}
				if (map[newrow][newcol] == -1){
					continue;
				}
				map[newrow][newcol]++;
			}

		}

	}
	
	//print map
	for(row = 0;row <= 9;row++){
		for(col = 0;col <= 9;col++){
			if(!map[row][col]){
				printf("O ");
			}
			else if(map[row][col] > 0){
				printf("%d ",map[row][col]);
			}
			else{
				printf("X ");
			}

		}
		printf("\n");
	}
	return 0;
}
