//用函数求最大公约数
#include <stdio.h>
int max_com(void){
	int a = 0,b = 0; // a > b
	int tmp = 0;
	printf("plz input two numbers:");
	scanf("%d%d",&a,&b);
	while(b % a){
		tmp = a;
		a = b % a;
		b = tmp;
	}
	return a;
}

int main(){
	int num = max_com();
	printf("max common number is %d\n",num);
	return 0;
}
