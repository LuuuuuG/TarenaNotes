//枚举类型演示
#include<stdio.h>

int main(){
	enum /*season可以省略*/ {SPRING,SUMMER = 5,AUTUMN,WINTER};	//分别对应0123
	printf("spring is %d\n",SPRING);
	printf("summer is %d\n",SUMMER);
	printf("autumn is %d\n",AUTUMN);
	printf("winter is %d\n",WINTER);
	return 0;
}
