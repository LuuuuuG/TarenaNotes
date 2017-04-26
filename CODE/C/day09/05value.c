#include<stdio.h>

double add(double num,double num1){
	return num + num1;
}
int main(){
	int num = add(3,8);
	printf("sum = %d\n",num);
	return 0;
}


