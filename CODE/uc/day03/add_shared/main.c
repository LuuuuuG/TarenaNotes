//main.c

#include "add.h"
//#include "../add.h"
//#include <add.h>  //查找失败

int main(){
	int sum = add_int(33,55);
	printf("33 + 55 = %d\n",sum);
	return 0;
}
