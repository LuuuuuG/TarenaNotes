#include <stdio.h>
int main(){
	int num = 0,num1 = 0;
	FILE *p_file = fopen("b.txt","r");
	if (p_file) {
		for (num = 0;num <= 4;num++) {
			fscanf(p_file,"%d ",&num1);	//将文件里的数据读到num1里
			printf("%d ",num1);
		}
		printf("\n");
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
