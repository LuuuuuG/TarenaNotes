#include <stdio.h>
#define		SUB(a,b)	((a) - (b))
int main(){
	printf("result is %d\n",SUB(10,7));
	printf("result is %d\n",20 - SUB(10,7));
	printf("result is %d\n",SUB(20,10 - 7));
	return 0;
}


