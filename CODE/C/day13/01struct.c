//结构体演示
#include<stdio.h>
/*	struct person{
		int age;	//三个子存储区 只表示类型~
		float height;	//不分配内存~
		char name[10];	//可以写在头文件里~
	};
typedef	struct person	people;//起别名 people;
效果等同与下*/
typedef struct /*person省略*/{
	int age;
	float height;		//结构体声明语句与起别名语句合并
	char name[10];
}people;

int main(){
	people prn1 = {20,1.73f,"abc"}, prn2 = 0;
	printf("plz input age:");
	scanf("%d",&(prn1.age));
	printf("plz input height:");
	scanf("%g",&(prn1.height));
	scanf("%*[^\n]");	//清理
	scanf("%*c");		//缓存
	printf("plz input name:");
	fgets(prn1.name,10,stdin);
	printf("age is %d\n",prn1.age);
	printf("height is %g\n",prn1.height);
	printf("name is %s\n",prn1.name);

	prn2 = prn1;
	printf("age is %d\n",prn2.age);
	printf("height is %g\n",prn2.height);
	printf("name is %s\n",prn2.name);
	return 0;
}
