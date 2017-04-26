//文件操作代码框架

#include <stdio.h>

int main(){
	FILE *p_file = fopen("a.txt"/*文件路径*/,"w"/*操作方式*/);
	//文件指针打开文件
/*写法一
	if (p_file) {
		//文件打开成功
		fclose(p_file);		//打开的文件不关闭会造成内存泄露!!! 
		p_file = NULL;
	}
*/
//写法二：
	if (!p_file) {
		//文件打开失败
		return 0;
	}
	//打开成功
	fclose(p_file);
	p_file = NULL;
	return 0;
}
