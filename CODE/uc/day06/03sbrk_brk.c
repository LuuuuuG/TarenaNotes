//练习
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	int* p1 = sbrk(4);
	if((int*)-1 == p1){
		perror("sbrk");
		exit(-1);
	}
	*p1 = 66;

	double* p2 = sbrk(8);
	if((double*)-1 == p2){
		perror("sbrk");
		exit(-1);
	}
	*p2 = 3.14;

	char* p3 = sbrk(sizeof(char)*10);
	if((char*)-1 == p3){
		perror("sbrk");
		exit(-1);
	}
	//p3 = "hello";   //改变指向
	strcpy(p3,"hello");  //改变内容

	printf("%d %lg %s\n",*p1,*p2,p3);

	int res = brk(p1);
	if(-1 == res){
		perror("brk");
		exit(-1);
	}


	return 0;
}
