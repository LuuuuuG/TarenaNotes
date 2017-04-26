//字符串演示
#include <stdio.h>

int main(){
	
	printf("%p\n","abc");      // 字符a的地址
	printf("%p\n","ab""c");      // 并列写在一起会被写成一个。
	printf("%p\n","abc" + 3);  // \0 地地址
	printf("%d\n",*("abc" + 3)); // 寻址 结果为0
//	*"abc" = 'x';       // 将a换为x 出现错误！
	char str[] = "xyz";
	printf("sizeof(str) is %d\n",sizeof(str));
	str[0] = 'a';
	printf("%s\n",str);
	return 0;
}
