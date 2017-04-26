
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//test画图 只显示老鼠的位置~

int main(){
  int i,j;  //i,j记录老鼠的位置
  
  int m,n;  //m,n用来画地图
  srand(time(0));   //随机生成老鼠的位置
  i = rand () %3 + 1;
  j = rand () %3 + 1;

  printf("老鼠的位置是：%d %d\n",i,j);



  return 0;
}
