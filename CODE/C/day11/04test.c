#include<stdio.h>
#include<string.h>
/*
int main(){
	char str[5] = {0};
	int a,b,c,d,e;
	printf("plz input five scores:");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	sprintf(str,"%d,%d,%d,%d,%d",a,b,c,d,e);
	printf("%s\n",str);

	return 0;
}
*/

int main(){
	char tmp[10] = {0},grades[30] = {0};
	int num = 0,grade = 0;
	for (num = 1;num <= 5;num++){
		printf("plz input a grade:");
		scanf("%d",&grade);
		sprintf(tmp,"%d,",grade);	//将输入的一个成绩打印入tmp数组中
		strcat(grades,tmp);			//将tmp中的字符合并入grade数组中
	}
	grades[strlen(grades) - 1] = 0;// 将最后一个逗号赋值为0
	printf("%s\n",grades);
	return 0;
}









