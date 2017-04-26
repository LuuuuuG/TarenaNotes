#include<stdio.h>
void print(void){
	printf("1\n");
	print(); //调用自己
}

int main(){
	print();
	return 0;
}
