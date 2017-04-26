#include<stdio.h>
int main(){
 int sum = 0;
 int i=8;
 sum = ++i;
 printf("%d\n",sum);
 sum = --i;
 printf("%d\n",sum);
 sum = i++;
 printf("%d\n",sum);
 sum = i--;
 printf("%d\n",sum);

return 0;
}
