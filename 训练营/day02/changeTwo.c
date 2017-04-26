// 不加参数，交换两变量的值
#include<stdio.h>

 int main(){
  int a,b;
  printf("请输入两个数：\n");
  scanf("%d%d",&a,&b);
  
  a=a+b;   
  b=a-b;  
  a=a-b;

  printf("a=%d\n",a);
  printf("b=%d\n",b);
   return 0;
}
