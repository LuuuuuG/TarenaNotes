/*
用for循环实现

1x9=9
2x8=16
3x7=21
4x6=24
5x5=25

*/


#include <stdio.h>

/*int main(){
   
   int i,j;
   for (i = 1,j = 9; i <= 5,j >= 5; i++,j--){

   printf("%d x %d = %d\n",i,j,i*j);

   }

   return 0;
}

*/

//Mr.Yang

int main(){
   int num = 0;
   for(num= 1;num <= 5;num++){
	printf("%d x %d = %d\n",num,10-num,num*(10-num));
	}

   return 0;
}
