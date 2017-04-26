/*************************************************************************
    > File Name: 03subclass.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月19日 星期四 14时08分35秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
private:

public:
	A (int x=123): m_x(x){
		cout << "A构造：" << this << endl;
	}
	~A(void){
		cout << "A析构：" << this << endl;
	}
	
	int m_x;
};
//隐式构造基类子对象
class B:public A{
public:
	B(int y):m_y(y){
		cout << "B构造：" << this << endl;
	}
	~B(void){
		cout << "B析构：" << this << endl;
	}
	int m_y;
};
//显式构造基类子对象
class C:public A{
public:
	C (int x,int z):A (x),m_z(z){
		cout << "C构造：" << this << endl;
	}
	~C(void){
		cout << "C析构：" << this << endl;
	}
//	A(x); //只是定义一个匿名对象 寿命很短只有一行 0.0？
//	A a (x) //有名变量
	int m_z;
};

class D : public B{
public:
	D(int x,int y,int z):B(y),
		m_c(x,z){
		cout << "D构造：" << this << endl;
	}
	~D(void){
		cout << "D析构：" << this << endl;
	}
	C m_c;
	//调用顺序
};//D->B->A		先调基类子对象
//  \->C->A		载调成员子对象

int main(){
/*	B b (456);
	cout << b.m_x << endl;
	cout << b.m_y << endl;
	C c(111,222);
	cout << c.m_x << endl;
	cout << c.m_z << endl;
*//*
	cout << "-----------------" << endl;
	D d(333,444,555);
	cout << sizeof (d) << endl;
	cout << "-----------------" << endl;
*//*
	B* pb = new B (456);
	delete pb;//析构B->A
*/
	A* pa = new B (456);//向上造型
//	delete pa;//只会执行A的析构函数
	delete static_cast<B*> (pa);//向下造型回去再析构
	return 0;
}//右括号负责调用析构函数
