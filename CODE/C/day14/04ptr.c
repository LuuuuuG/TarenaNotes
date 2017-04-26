//二级指针代表指针数组
#include <stdio.h>

int main(int argc,char **argv){
	int num = 0;
	for (num = 0;num <= argc - 1;num++){
		printf("%s\n",*(argv + num));
	}
	return 0;
}
