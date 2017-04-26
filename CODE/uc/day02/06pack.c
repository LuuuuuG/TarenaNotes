//#pragma pack(整数n)
#include<stdio.h>
//按照2的倍数进行对齐和补齐
//#pragma pack(2) //8
//#pragma pack(1) //6
//#pragma pack(3) //error 默认按照4进行对齐和补齐
//#pragma pack(4) //默认情况
//#pragma pack(8) //超过按照4计算

int main(){
	struct S{
		char c1;
		int i;
		char c2;
	};
	printf("sizeof(struct S) = %d\n",sizeof(struct S));
	return 0;
}
