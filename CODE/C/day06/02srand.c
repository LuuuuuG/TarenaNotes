//srand
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int num = 0;
	srand(time(0));
	printf("num = %d\n",rand());
	printf("num = %d\n",rand());
	printf("num = %d\n",rand());

	return 0;
}
