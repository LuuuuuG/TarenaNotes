/*
用for循环打印（循环中尽量不出现数字）
54321
5432
543
54
5
*/

//多重循环的练习


#include <stdio.h>

int main(){
   int num = 0,num1 = 0;
   for (num = 1;num <= 5;num++){
       for (num1 = 5;num1 >= num;num1--){
	    printf("%d",num1);
	}
	printf("\n");
   } 
   
   return 0;
}

































