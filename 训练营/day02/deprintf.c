#include <stdio.h>

int main(){
 
  int num;
  int a,b,c;
 printf("请输入一个三位数：\n");
 scanf("%d",&num);


 a = num/100;
 num = num % 100;
 b = num/10;
 num = num %10;
 c = num;

 num = c*100 + b*10 + a;
printf("倒序输出：%d\n",num);

return 0;
}
