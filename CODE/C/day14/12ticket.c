//彩票3.0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *print(void){
	int *p_num = (int *)malloc(7 * sizeof(int));
	int num = 0;
//	srand(time(0));
	if (p_num) {
		for (num = 0;num <= 6;num++){
			*(p_num + num) = rand() % 36 + 1;
		}
	}
	return p_num;
}

int main(){
	int num = 0;
	srand(time(0));
	int *p_num = print();
	if (p_num){
		for(num = 0;num <= 6;num++){
			printf("%d ",*(p_num + num));
		}
		printf("\n");
		free(p_num);
		p_num = NULL;
		return 0;
	}
	return 0;
}
