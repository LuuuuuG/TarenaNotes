/*************************************************************************
    > File Name: 06name.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月19日 星期四 16时49分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
public:
	int abc;
	void foo (void){
		cout << "A::foo()" << endl;
	}
};

class B {
public:
	typedef int abc;
	void foo (int x ){
		cout << "B::foo()" << endl;
	}
};

class C : public A,public B{
public:	
	using A::foo;
	using B::foo;
	
};

int main(){
	C c;
	c.A::abc = 10;
	C::B::abc i = 10;
	//通过作用域限定解决名字冲突
//	c.A::foo();
//	c.B::foo(123);
	c.foo();
	c.foo(123);
	return 0;
}
