//观察一下小端系统和大端系统的区别
#include<stdio.h>

int main(){
	union Un{
		int x;
		char buf[4];
	};
	union Un un;
	un.x = 0x12345678;//十六进制4字节
	int i = 0;
	for(i = 0;i < 4;i++){
		printf("buf[%d] = %#x[%p]\n",i,un.buf[i],&un.buf[i]);
	}
	return 0;
}
