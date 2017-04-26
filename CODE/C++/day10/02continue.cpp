/*************************************************************************
    > File Name: 02continue.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 10时35分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
};

class B {
public:
	B (void) {
		cout << "B构造" << endl;
	}
	~B (void) {
		cout << "B析构" << endl;
	}
};
void bitch(void){
	throw -1;
}
void shit (void){
	B* pb = new B;
	try{
		bitch();
	}
	catch (int ex){
		delete pb;
//		return;
		throw;//throw ex;
		//继续抛出异常
	}
	delete pb;
	//..
}
void fuck(void){
	A* pa = new A;
	try {
		shit();
	}
	catch (int ex){
		cout << "xsy233" << endl;
		delete pa;
//		return;
		throw;
	}
	delete pa;
	//..
}
int main(){
	try{
		fuck();
	}
	catch (int ex){
		cout << "异常：" << endl;
	}
	return 0;
}
