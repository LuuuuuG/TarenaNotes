/*
用for循环打印（循环中尽量不出现数字）
54321
5432
543
54
5
*/

//Mr.Gang
#include <stdio.h>

int main(){
   int i,num=54321;
   for(i = 1;i <= 5;i++ ){
   printf("%d\n",num);    
   num= num/10;	
 }
      return 0;
}



//Mr.Yang

//循环变量不一定连续变化
//方法一
#include <stdio.h>

int main(){
   int num = 0,max = 54321,min = 5,ten = 10;
   for (num = max;num >= min;num = num/ten){

   printf("%d\n",num);
   }
   return 0;
}


//多重循环
//方法二

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





