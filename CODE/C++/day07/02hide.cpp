/*************************************************************************
    > File Name: 02hide.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月19日 星期四 11时08分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
private:

public:
	void abc (void){
		cout << "A::abc()" << endl;
	}
};
class B:public A {
public:
	int abc;
};
class C:public A {//隐藏
public:
	void abc (int x){
		cout << "C::abc()" << endl;
	}
};

class D:public A {//重载
public:
	using A::abc;
	void abc (int x){
		cout << "D::abc()" << endl;
	}
};

class E:public A {//隐藏
public:
	using A::abc;
	void abc (void){
		cout << "E::abc()" << endl;
	}
};

int main(){
	B b;
	b.abc = 100;
	b.A::abc (); 
	C c;
	c.A::abc();
	c.abc(10);
	D d;
	d.abc();
	d.abc(10);
	E e;
	e.abc();

	return 0;
}
