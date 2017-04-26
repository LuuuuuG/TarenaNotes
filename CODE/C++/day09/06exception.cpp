/*************************************************************************
    > File Name: 04return.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月23日 星期一 15时05分24秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
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
	cout << "调用fopen前" << endl;
	FILE* fp = fopen("none","r");
	if(!fp){
		perror ("fopen");
		throw 100;
	}
	cout << "fopen 成功" << endl;
	fclose(fp);
}
void shit(void){
	A a;
	cout << "调用fuck前" << endl;
	fuck();
	cout << "调用fuck后" << endl;
}
void bitch(void){
	A a;
	cout << "调用shit前" << endl;
	shit();
	cout << "调用shit后" << endl;
}
int main(){
	try{
		A a;
		cout << "调用bitch前" << endl;
		bitch();
		cout << "调用bitch后" << endl;
	}
	catch (int ex){
			cout << "失败!" << endl;
			return -1;
	}
	cout << "成功！" << endl;

	return 0;
}
