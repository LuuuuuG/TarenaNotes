//宏演示
#include <stdio.h>
#define		PI		3.14f
#define 	CIRCLE(r)	2 * PI * r
int main(){
	int radius = 0;
	printf("plz input radius:");
	scanf("%d",&radius);
	printf("%g\n",CIRCLE(radius));
	return 0;
}
