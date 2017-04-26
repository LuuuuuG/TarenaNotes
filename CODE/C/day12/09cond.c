//条件编译演示2
#include<stdio.h>

int main(){
#if		defined(GONGCHANG)		//将宏名称转换成布尔值
	printf("80%%\n");
#elif	!defined(GONGCHANG) && !defined(JINGPIN)
	printf("100%%\n");
#else
	printf("120%%\n");
#endif
	return 0;
}
