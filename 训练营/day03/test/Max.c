//输入4个整数，打印最大值。

#include <stdio.h>

 int main(){
  int a,b,c,d;
  int temp;
  printf("请输入4个数(用逗号隔开):\n");
   scanf("%d,%d,%d,%d",&a,&b,&c,&d);

  if(a<b){
   temp=a;
   a=b;
   b=temp;
}
 if(a<c){
  temp=a;
  a=c;
  c=temp;
}
 if(a<d){
  temp=a;
  a=d;
  d=temp;
} 
  printf("最大数是：%d\n",a); 

 return 0;
}
