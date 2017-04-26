//编写程序从键盘得到的两个整数，把他们之间
//所有偶数和与所有奇数和的差计算出来并打印
//如输入3、7 (4+6)-(3+5+7)=-5

#include <stdio.h>

int main(){
   
   int a,b,num,sum;
   int E = 0,O = 0;

   printf("请输入两个整数：");
   scanf("%d %d",&a,&b);
   
   if (a >= b){
   printf("请重新输入！\n");
   scanf("%d %d",&a,&b);
      } 
   
   for(num = a;num <= b;num++){
  
   if(num % 2 == 0){
    
      E = E + num;
      }
    else{

      O = O + num;
      }

   }
      
   sum = E - O;
   printf("所有偶数与奇数之差是：%d\n",sum);
   return 0;
}
