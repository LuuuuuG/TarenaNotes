/*************************************************************************
    > File Name: 07hmwork.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月19日 星期四 17时04分51秒
 ************************************************************************/
//	 A
//	/ \
// B   C
//  \ /
//   D

#include<iostream>
using namespace std;
class A {
protected:
	int m_data;
public:
	A (int data): m_data(data){
		cout << "A构造：" << this << endl;
	}

};

class B : virtual public A{
public:
	B (int data): A (data){
		cout << "B构造：" << this << endl;
	}
	void set (int data){
		cout << "set:" << &m_data << endl;
		m_data = data;
	}
};

class C: virtual public A{
public:
	C (int data): A (data){
		cout << "C构造：" << this << endl;
	}
	int get (void) const{
		cout << "get:" << &m_data << endl;
		return m_data;
	}
};

class D : public B,public C {
public:
	D (int data): B (data),C(data),A(data){
		cout << "D构造：" << this << endl;
	}
};

int main(){
	D d (100);
	cout << d.get() << endl;//100
	d.set(200);
	cout << d.get() << endl;//100 ??? 
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
}

