#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	union{ //匿名联合
	  int i;
	  char c[4];
	};
	i = 0x12345678;
	printf("%#x %#x %#x %#x\n",c[0],c[1],c[2],c[3]);
	printf("%p %p\n",&i,c);
	return 0;
}
