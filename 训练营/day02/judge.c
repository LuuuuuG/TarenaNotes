#include <stdio.h>

int main(){

 int a;
 printf("请输入一个数：\n");
 scanf("%d",&a);

if(a>0){
  printf("%d是一个正数\n",a);
}
else if(a<0){
  printf("%d是一个负数\n",a);
}
else{
 printf("是零\n");

}

}
