#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
/*
	printf("%d\n",(time_t*)time(0));
	printf("%s\n",__TIME__);
*/
	time_t now;
	struct tm* timenow;
	time(&now);
	timenow = localtime(&now);
	printf("%s\n",asctime(timenow));
	
	return 0;
}
