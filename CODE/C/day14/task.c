/*编写字符串拷贝函数(新字符串记录在动态分配内存里)
	函数把新字符串传递给调用函数并打印。*/
#include <stdio.h>
#include <stdlib.h>
	int num = 0;
char *print(char *p_num){
	char *p_copy = (char *)malloc(10*sizeof(char));
	if (p_copy){
		for(num = 0;num <= 9;num++){
			*(p_copy + num) = *(p_num + num);
		}
	}
	return p_copy;
}	

int main(){
	char str[10] = {0};
	printf("plz input a string:");
	fgets(str,10,stdin);
	char *p_num = print(str);
	if (p_num){
        for(num = 0;num <= 6;num++){
            printf("%c ",*(p_num + num));
        }   
        printf("\n");
        free(p_num);
        p_num = NULL;
    }
	return 0;
}
