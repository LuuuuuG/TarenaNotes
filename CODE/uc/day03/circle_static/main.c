//main.c

#include"circle.h"
int main(){
	float radius = 0;
	printf("plz input the radius:");
	scanf("%g",&radius);
	circle_length(radius);
	circle_area(radius);
	return 0;
}



