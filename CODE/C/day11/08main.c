//主函数参数演示

#include<stdio.h>
int main(int argc,char *argv[]){ // 1整数，2字符指针数组
	//第一个参数表示第二个参数里有多少个指针
	int num = 0;
	for(num = 0;num <= argc - 1;num++){
		printf("%s\n",argv[num]);

	}
	return 0;
}
