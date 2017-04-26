//Mr.Yang
//盘输入4个数字，用for循环打印出最大值和最小值

#include <stdio.h>
/*
int main(){
   int num = 0,num1 = 0;
   int max = 1 << 31;     //用于记录最大数
   int min = ~(1 << 31);  //用于记录最小数
   int sum = 0;

   for (num = 1;num <= 4;num++){
    
     printf("请输入一个数字：");
     scanf("%d",&num1);
     sum= sum + num1; 
   
    if (num1 >= max){
       max = num1;
    }
    if (num1 <= min){
       min = num1;
    }
}
  printf("最大值是：%d\n",max);
  printf("最小值是：%d\n",min);
  printf("它们的和是：%d\n",sum);
  return 0;
}

*/


int main(){
    
   int max = 0, min = 0, num = 0,result = 0;
   printf("请输入两个整数：");
   scanf("%d %d",&max,&min);

   if(max < min){
    max = max + min;
    min = max - min;
    max = max - min; 
   }
 
   for (num = min;num <= max;num++){

	if(num % 2 == 0){
  	   result = result + num;  
        }
	else{
       	   result = result - num;
	}
  }
   printf("结果是：%d\n",result);
   return 0;
}

































