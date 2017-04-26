#include<stdio.h>
#define n  5
void main(){
	int i,j,k;
	for(i = 0;i <= n;i++){
		for(j = 0;j < n+i-1;j++){
			if(j < n-i+1)
				printf(" ");
			
			else{
				if((j == n-i+1)|| j == n+i-1){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
		for(i = n;i >= 0;i--){
			for(k = i;k<= n;k++){
				printf(" ");
			}
			for(j = n + i - 1;j>=0;j--){
				if(j<n-i+1){
					printf(" ");
				}
				else{
					if((j == n-i+1)||(j == n+i-1)){
						printf("*");
					}
					else{
						printf(" ");
					}
				}
			}
			printf("\n");
	}
}
