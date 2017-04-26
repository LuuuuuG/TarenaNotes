//字符指针数组演示

#include<stdio.h>

int main(){
	char *strs[5] = {"abc","def","hij","klm","xyz"};
	int num = 0;
	for(num = 0;num <= 4;num++){
		printf("%s\n",strs[num]);
	}
	return 0;
}
