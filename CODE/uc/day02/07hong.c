//预定义宏
#include <stdio.h>

int main(){
	printf("%s\n",__FILE__);
	printf("%d\n",__LINE__);
	printf("%s\n",__TIME__);
	printf("%s\n",__DATE__);

	return 0;
}
