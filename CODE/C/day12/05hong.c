#include <stdio.h>
#define 	SQU(num)		((num) * (num))

int main(){
	int num = 5;
	printf("10^2 = %d\n",SQU(10));
	printf(" (++num) * (++num) =  %d\n",SQU(++num));
	return 0;

}
