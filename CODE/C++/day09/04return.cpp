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
int fuck(void){
	A a;
	FILE* fp = fopen("none","r");
	if(!fp){
		perror ("fopen");
		return -1;
	}
	fclose(fp);
	return 0;
}
int shit(void){
	A a;
	if(-1 == fuck())
		return -1;
	return 0;
}
int bitch(void){
	A a;
	if(-1 == shit())
		return -1;
	return 0;
}
int main(){
	A a;
	if (-1 == bitch()){
		cout << "失败!" << endl;
		return -1;
	}
	cout << "成功！" << endl;

	return 0;
}
