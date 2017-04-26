#include <stdio.h>

int main(){
	int i = 0,j = 0;
	for (i = 0;i <= 5;i++){   //i表示两元
		for(j = 0;j <= 2;j++){ //j表示五元
				if(2*i +5*j <= 10){
					printf("一元%d张 两元%d张 五元%d张\n",10 - 2*i - 5*j,i,j);
				}
			}
		}
	return 0;
}


