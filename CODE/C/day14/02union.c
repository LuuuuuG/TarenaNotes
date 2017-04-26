//联合演示
 #include <stdio.h>
typedef union {		//关键字不同
	char ch;		//其他类似与结构体
	int num;	
}un;				

 int main(){
	un un1;
	un1.num = 0;
	un1.ch = 'a'; 	//修改ch子存储区 上一个num存储区也受影响
	printf("un1.num is %d\n",un1.num);
	return 0;
 }
