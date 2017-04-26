#include <stdio.h>

int main(){
	unsigned char a = 0xa5;
	printf("a = %d\n",a);
	a = ~a;
	printf("先取反得 %d\n",a);
	a = a >> 6;
	printf("后移位得 %d\n",a);
	
	printf("----------------------\n");

	unsigned char b = 0xa5;
	printf("a = %d\n",b);
	b = b >> 6;
	printf("先移位得 %d\n",b);
	b = ~b;
	printf("后取反得 %d\n",b);

	return 0;
}
