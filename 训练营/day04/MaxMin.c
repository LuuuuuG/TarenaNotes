//盘输入4个数字，用for循环打印出最大值和最小值

#include <stdio.h>

int main(){
   int i,num;
   int max=-1000,min =1000;

   for(i = 1;i <= 4;i++){

   printf("请输入一个数字：");
   scanf("%d",&num);

   if (num >= max ){
     max=num;
   } 
   if (num <= min){
     min=num;
   }   
}

   printf("最大值是:%d\n",max);
   printf("最小值是:%d\n",min);

   return 0;
}
