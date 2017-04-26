   #include<stdio.h>
   #include<stdlib.h>
   #include<time.h>
  4 int main(){
  5     srand(time(0));
  6     int map[10][10] = {0};
  7     int i = 0,j = 0,m = 0,n = 0;
  8     int boom[i][j];
  9     int num = 0;
 10      for (;num < 10;){
 11             m = rand() % 10;
 12             n = rand() % 10;
 13         if(map[m][n] != -1){
 14             map[m][n] = -1;
 15             num++;
 16         }
 17         }
 18 
 19      for (i = 0;i < 10;i++){
 20         for(j = 0;j < 10;j++){
 21             if(map [i][j]){
 22                 printf("X");
 23             }
 24             else{
 25                 printf("o");
 26             }
 27 
 28         }
 29         printf("\n");
 30      }
 31 
 32 
 33     return 0;
 34 }
