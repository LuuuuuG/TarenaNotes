#include<stdio.h>
int main(){
	int arr[3][2] = {{1,2},{3,4},{5,6}};	//二维数组声明
	int row = 0,col = 0;
	int num = 1;
	for(row = 0;row <= 2;row++){
		for(col = 0;col <= 1;col++){
			arr[row][col] = num;
			num++;
			printf("arr[%d][%d] = %d      ",row,col,arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}
