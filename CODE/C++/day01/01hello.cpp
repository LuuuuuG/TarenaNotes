#include<iostream>
//#include<stdio.h>
#include<cstdio>//与上一行等价

 int main(void){
 /*将Hello,World!字符串字面值插入到std名字空间中的cout对象里
   然后再将std名字空间中的endl对象也插入到cout对象里
   std:标准名字空间
   cout:控制台输出设备对象
   endl:换行符对象*/
	std::cout << "Hello,World!"
	    << std::endl;//l-line 行尾
	printf("Hello,World2\n");
	return 0;
 }
