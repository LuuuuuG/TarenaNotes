//C语言中的错误处理
#include<stdio.h>
#include<string.h>
#include<time.h>
//a生成1~10 之间随机数并返回,如果随机数是5则返回错误;
int fun1(void){
	int num = rand() % 10 + 1;
	if(num == 5){
		return -1;
	}
	else{
		return num;
	}
	//return 5 == num ? -1 : num;
}
//b 比较两个int类型参数的大小并返回最大值,如果相等则返回错误;
int fun2(int a,int b,int* max){
	if(a == b){
		return -1; //表示返回错误
	}
	*max = a > b ? a : b;
	return 0; //表示正常结束
}

//c 判断传入的字符串是否为"error" 如果是则返回错误,否则返回"ok"
char* fun3(const char* str){
	if(0 == strcmp("error",str)){
		return NULL;
	}
	else{
		return "ok";
	}
}

//d 打印传入的字符串即可;
void fun4(const char* str2){
	printf("%s\n",str2);
}



int main(){
	srand(time(0));
	fun1();
	printf("生成的随机数是:%d\n",fun1());
	
	int max = 0;
	if(0 == fun2(1,-2,&max)){
		printf("最大值是:%d\n",max);
	}
	char str[]="abcdef";
	printf("%s\n",fun3(str));
	char str2[]="hello world!";
	fun4(str2);
	return 0;
}
