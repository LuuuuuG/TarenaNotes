//star.c
#include"star.h"
int i = 0,j = 0;
void print1(void){
	printf("  *   \n");
	printf(" * *  \n");
	printf("*   *  \n");
	printf(" * *  \n");
	printf("  *   \n");


}

void print2(void){

	for(i = 0;i < 3;i++){
		for(j = 1;j <= 5;j++){
			if(j >= (3 - i )&& j <= (3 + i)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf(" *** \n");
	printf("  *  \n");
}
