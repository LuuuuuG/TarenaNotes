//动态分配内存演示

#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p_num = (int *)malloc(5 * sizeof(int)); //分配5个int类型的内存
	//malloc分配的是无类型指针，需要强制类型转换
	int num = 0;
	if (p_num){			//分配内存成功
		  for (num = 0;num <= 4;num++){
				*(p_num + num) = num + 1;
		  }
		  for (num = 0;num <= 4;num++){
				printf("%d ",*(p_num + num));
		  }
		  printf("\n");
		free(p_num);	//释放内存
		p_num = NULL;
	}
	return 0;
}
