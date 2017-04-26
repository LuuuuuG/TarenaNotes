#include<stdio.h>
int head(void){
	int heads = 0;
	int foots = 0;
	int rabbit = 0;	//记录rabbit
	printf("plz input the number of heads:");
	scanf("%d",&heads);
	printf("plz input the number of foots:");
	scanf("%d",&foots);
	for(rabbit = 0;rabbit <= heads;rabbit++){	//计算兔子的数量
		if(rabbit * 4 + (heads - rabbit) * 2 == foots){
			return rabbit;
		}
	}
}

int main(){
	int num = head();
	printf("There are %d rabbit\n",num);
	return 0;
}

int rabbit(void){
	int heads = 0,legs = 0,num = 0;
	printf("plz input the number of heads:");
	scanf("%d",&heads);
	printf("plz input the number of leds:");
	scanf("%d",&legs);
	for(num = 0;num <= heads;num++){
		if(4 * num + 2 * (heads - num) == legs){
			return num;
		}
	}
}/*
int main(){
	int num = rabbit();
	printf("There are %d rabbit\n",num);
	return 0;
}
*/
