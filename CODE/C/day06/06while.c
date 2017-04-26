//Game: guess number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*int main(){
	int num = 0,guess = 0;
	srand(time(0));
	num = rand() % 100 + 1;
	printf("Input a number:");
	scanf("%d",&guess);

	while (guess < num){
		printf("Smaller\n");
		printf("Input a number:");
		scanf("%d",&guess);
	}

	while (guess > num){
		printf("bigger\n");
		printf("Input a number:");
		scanf("%d",&guess);
	}
	
	while (guess == num){
		printf("congratulation!\n");
	}
	return 0;
}*/

int main(){
	int num = 0,guess = 0;
	srand(time(0));
	num = rand() % 100 + 1;
	while(guess != num){
		printf("Input a number:");
		scanf("%d",&guess);
		
		if (guess < num){
			printf("Smaller\n");
		}
		else if (guess > num){
			printf("Bigger\n");
		}
		else{
			printf("Congratulation\n");
		}
	}

	return 0;
}

