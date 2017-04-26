//输入4个整数，打印最大值。


/*
#include <stdio.h>

 int main(){
  int a,b,c,d;
  int m,n,max;
  printf("请输入4个数(用逗号隔开):\n");
   scanf("%d,%d,%d,%d",&a,&b,&c,&d);
 
 if(a>b){
  m=a;
}else{
 
  m=b;
}


 if(c>d){
  n=c;
}else{
  n=d;
}


if(m>n){
 max=m;
}else{
 max=n;
}

  printf("4个数的最大值是%d\n",max);

}
*/



//方法二

 #include <stdio.h>
 
int main(){

 int num=0,max=1 << 31;        // max=1 << 31 计算机中最小的数
 printf("请输入一个数字：\n");
 scanf("%d",&num);
  if(max<num){
   max=num;
}
 printf("请输入一个数字：\n");
 scanf("%d",&num);
  if(max<num){
   max=num;
}
 
 printf("请输入一个数字：\n");
 scanf("%d",&num);
  if(max<num){
   max=num;
}
  
 printf("请输入一个数字：\n");
 scanf("%d",&num);
  if(max<num){
   max=num;
}
  printf("最大数是：%d\n",max);
	 return 0;
}



































