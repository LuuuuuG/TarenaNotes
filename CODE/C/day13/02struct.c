//struct
#include<stdio.h>
typedef struct{
	int age;
	float height;
	char name[10];
}person;

int main(){
	person prn = {19,1.68,"abc"};
	person *p_person = &prn;	//声明结构体指针
	printf("%d\n",p_person->age);
	printf("%g\n",p_person->height);
	printf("%s\n",p_person->name);
	return 0;
}
