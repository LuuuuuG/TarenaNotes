//变量演示
#include<stdio.h>
 int num;		//全局变量
void func(void){
// 	int num;	//局部变量
	printf("num = %d\n",num);
}


int main(){
	int num = 10;
	func();		//结果num = 0 (使用全局便来那个)
	printf("num = %d\n",num);//结果num = 10(优先使用局部变量)
	return 0;
}
