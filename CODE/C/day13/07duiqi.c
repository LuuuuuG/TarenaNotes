#include<stdio.h>
typedef struct{
	int num;
	char ch;
}stru;

typedef struct{
	char ch;
	int num;
	char ch1;
}stru1;

int main(){	
	printf("sizeof(stru) is %d\n",sizeof(stru));
	printf("sizeof(stru1) is %d\n",sizeof(stru1));
	return 0;
}
