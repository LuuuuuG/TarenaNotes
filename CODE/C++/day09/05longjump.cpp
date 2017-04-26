/*************************************************************************
    > File Name: 04return.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月23日 星期一 15时05分24秒
 ************************************************************************/
#include<cstdio>
#include<csetjmp>
#include<iostream>
using namespace std;
jmp_buf g_env;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void){
		cout << "A析构" << endl;
	}
};
void fuck(void){
	A a;
	FILE* fp = fopen("none","r");
	if(!fp){
		perror ("fopen");
		longjmp(g_env,100);
	}
	fclose(fp);
}
void shit(void){
	A a;
	fuck();
}
void bitch(void){
	A a;
	shit();
}
int main(){
	A a;
	if(100 == setjmp (g_env)){
		cout << "失败!" << endl;
		return -1;
	}
	bitch();
	cout << "成功！" << endl;
	return 0;
}
