//宏操作符演示
#include<stdio.h>
#define		STR(n)		#n
#define		LOCAL(n)	l_##n
int main(){
	STR(2 + 3);		// int num = 0;
	int num = 0;
	int LOCAL(num) = 0;	//int l_num = 0;
	return 0;
}
