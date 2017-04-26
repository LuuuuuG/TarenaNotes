#include <stdio.h>
#include "05add.h"
/*
int _Z3addii(int,int);
*/

int main(){
	int x = 123,y = 456;
//	printf("%d+%d=%d\n",x,y,_Z3addii(x,y));
	printf("%d+%d=%d\n",x,y,add(x,y));
	return 0;
}
