#include <stdio.h>

#include <stdlib.h>

#include <time.h>


#define   SIZE   4

enum {UP,RIGHT,DOWN,LEFT};



void init_map(int map[][SIZE],int size){

	int row = 0,col = 0;

	for (row = 0;row <= size - 1;row++){

		for (col = 0;col <= SIZE -1;col++){

			map[row][col] = 0;

		}

	}

}



void show_map(int map[][SIZE],int size){

	int row = 0,col = 0;

	for (row = 0;row <= size - 1;row++){

		for(col = 0;col <=SIZE - 1;col++){

			printf("%6d",map[row][col]);
		
		}

		printf("\n");
 	
	}

}




void add_num(int map[][SIZE],int size){

	int row = 0,col = 0,cnt = 0,pos = 0,sn = 0;



	for (row = 0;row <= size - 1;row++){

		for(col = 0;col <=SIZE - 1;col++){

			if (!map[row][col]){

				cnt++;

			}

		}

	}





	pos = rand ()% cnt;

	sn = 0;



	for (row = 0;row <= size - 1;row++){

		for (col = 0;col <= SIZE - 1;col++){

			if (!map[row][col]){

				if (sn == pos){





 				map[row][col] = 2;

				return ;

			}

			else {

				sn++;

			}

		}

	}

}

}










void slip(int map[][SIZE],int size){

	int direction = 0,

	num = 0,

	row = 0,

	col = 0;







	int start_points[][4][2] = {

		{{0,0},{0,1},{0,2},{0,3}},

	{{0,size - 1},{1,size - 1},{2,size - 1},{3,size - 1}},

	{{3,0},{3,1},{3,2},{3,3}},

	{{0,0},{1,0},{2,0},{3,0}}};





	static const int directions[][2] = {{1,0},

		{0,-1},{-1,0},{0,1}};



 		printf("请选择一个方向：%d代表上，%d代表右，%d代表下，%d代表左",UP,RIGHT,DOWN,LEFT);

		scanf("%d",&direction);

		for(num = 0;num <= 3;num++){







		row = start_points[direction][num][0];

		col = start_points[direction][num][1];

		do {



			if (row < 0 || row >= size
				|| col < 0 || col >= SIZE){






				break;

			}

			if (map[row][col]){







				int oldrow = row;

				int oldcol = col;





				int tmprow = oldrow - directions[direction][0];

				int tmpcol = oldcol - directions[direction][1];

				while (tmprow >= 0 && tmprow <= size - 1
						&& tmpcol >= 0 && tmpcol <= SIZE -1){




					if (!map[tmprow][tmpcol]){





						map[tmprow][tmpcol] = map[oldrow][oldcol];

						map[oldrow][oldcol] = 0;
	
					}

					else{











						if (map[tmprow][tmpcol] == map[oldrow][oldcol]){

							map[tmprow][tmpcol] <<= 1;



					

							map[tmprow][tmpcol] |= 1;

							map[oldrow][oldcol] = 0;

						}



						break;

					}



					oldrow = tmprow;

					oldcol = tmpcol;

					tmprow = oldrow - directions[direction][0];

					tmpcol = oldcol - directions[direction][1];

				}

			}



			row += directions[direction][0];

			col += directions[direction][1];

		} while(1);

	}





	for (row = 0;row <= size -1;row++){

		for(col = 0;col <= SIZE - 1;col++){

			if (map[row][col] & 1){

				map[row][col] ^= 1;

			}

		}

	}

}













int full(int map[][SIZE],int size){

	int row = 0,col = 0;

	for (row = 0;row <= size - 1;row++){

		for(col = 0;col <= SIZE - 1;col++){

			if (!map[row][col]){

				return 0;

			}

		}

	}

	return 1;

}

int main()

{

	int map[SIZE][SIZE] = {},choice = 1;

	srand(time(0));

	do{

		init_map(map,SIZE);

		add_num(map,SIZE);

		show_map(map,SIZE);

		do{

			slip(map,SIZE);

			if(full(map,SIZE)){



				show_map(map,SIZE);

				printf("游戏结束\n");

				break;

			}

			else{





				add_num(map,SIZE);

				show_map(map,SIZE);

			}

		}while(1);

		printf("是否需要开始下一盘？0表示不，1表示是");

		scanf("%d",&choice);

	}while (choice);

	return 0;

}















































































































			



















































































































































































































































