#include<stdio.h>
int print(int heads,int legs){
	int rabbits = 0;
	for(rabbits = 0;rabbits <= heads;rabbits++){
		if(rabbits * 4 + (heads - rabbits) * 2 == legs){
			return rabbits;
		}
	}
}

int main(){
	int heads = 0,legs = 0,num;
	printf("plz input numbers of heads and legs:");
	scanf("%d%d",&heads,&legs);
	num = print(heads,legs);
    printf("There are %d rabbits and %d checken\n",num,heads - num);
	return 0;
}
