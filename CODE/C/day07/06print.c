#include<stdio.h>
/*
int main(){

	int arr[5][5] = {0};
	int i = 0,j = 0;
	for(i = 0;i < 5;i++){
		for(j = 0;j < 5;j++){
			if(i == j){
				arr[i][j] = j + 1; 
				printf("%d",arr[i][j]);
			}
			else{
				arr[i][j] = 0;
				printf("%d",arr[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}*/

int main(){

	int arr[5][5] = {0};
	int i = 0,j = 0;
	for(i = 0;i < 5;i++){
		for(j = 0;j < 5;j++){
			if(i == j){
				arr[i][j] = j + 1; 
			}
		}
	}
	for(i = 0;i < 5;i++){
		for(j = 0;j < 5;j++){
			printf("%d",arr[i][j]);
			}
			printf("\n");
		}

	return 0;
}

