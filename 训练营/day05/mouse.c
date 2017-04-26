/*
打地鼠游戏
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i,j;  //i,j记录老鼠的位置  
  int p,q;  //p,q记录锤子的位置
  int hit = 0,nohit = 0; 
  int m,n;  //m,n用来画地图
  int times; //打击次数
  int t;//记录游戏次数
  srand(time(0));   //随机生成老鼠的位置

  i = rand () %3 + 1;
  j = rand () %3 + 1;

  printf("请输入打击次数：");
  scanf("%d",&times);

  for(t = 1;t <= times;t++){
  printf("请输入锤子所在的位置：");
  scanf("%d %d",&p,&q);  //用户输入锤子的位置

         //          画图
  for(m = 1; m <=3;m++){
     for(n = 1;n <= 3 ;n++){
 	if(i == p && j == q){
	printf("O");      //砸中用O表示
	}
	else if(m == i && n == j){
	printf("X");      //老鼠的位置用X表示
	}     

	else if(m == p && n == q){
	printf("O");      //锤子用O表示
	}  
	else {
	printf("*");      //地图其他位置用*显示
	}   

    }
    printf("\n"); 
 }



  if(i == p && j == q){   //显示结果并记录
  printf("打中了\n");
  hit = hit +1;
  }
  else{
  printf("没打中\n");
  nohit = nohit +1;
  }
  
  printf("打中%d,错过%d\n",hit,nohit);

}


  return 0;
}







