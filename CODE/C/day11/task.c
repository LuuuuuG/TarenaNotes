#include <stdio.h>
#include <string.h>
/*
int main(){

	int a,b,c,d,e,sum;
	sscanf("50,60,70,80,90","%d,%d,%d,%d,%d",&a,&b,&c,&d,&e);
	sum = a + b + c + d + e;

	printf("%d\n",b);
	printf("sum = %d\n",sum);
	return 0;
}
*/

int main(){
	char grades[] = "10,20,30,40,50,60";
	char *p_grade = grades;
	int sum = 0;
	while(1){   //死循环
		sum += atoi(p_grade);
		p_grade = strstr(p_grade,","); //在字符串指针数组中找到逗号
		if(!p_grade){	//处理没找到逗号的情况
			break;
		}
		p_grade++;
	}
	printf("sum = %d\n",sum);
	return 0;
}


















