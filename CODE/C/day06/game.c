/*
编写猜数游戏，计算机里产生一个1到100之间的随机数，
然后让用户猜，每次猜完都要给出提示
直到猜对程序为止。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int num = 0,guess = 0;
	srand(time(0));
	num = rand() %100 + 1;
	for (;;){
	printf("Input a number:");
	scanf("%d",&guess);
		if(guess == num){
			printf("Congratulation!\n");
			continue;
		}
		else if(guess < num){
			printf("Smaller!\n");
		}
		else{
			printf("Bigger!\n");
		}
	}
	return 0;
}
