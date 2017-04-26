/*************************************************************************
    > File Name: 04copy.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月19日 星期四 15时14分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
public:
	A (int x = 0): m_x (x){}	
	int m_x;
};
class B : public A{
public:
	B (int x = 0,int y = 0):
		A (x),m_y(y){}
	//拷贝构造
//	B (B const& b): m_y (b.m_y){}     // 0 200
	B (B const& b): A(b),m_y (b.m_y){}// 100 200
	//拷贝赋值运算符
	B& operator= (B const& b){
		A::operator= (b);
		m_y = b.m_y;
		return *this;
	}
	int m_y;
};

int main(){
	B b1 (100,200);
	cout << b1.m_x << ' ' << b1.m_y << endl;
	B b2 = b1;//拷贝构造函数
	cout << b2.m_x << ' ' << b2.m_y << endl;
	B b3 (123,456);
	cout << b3.m_x << ' ' << b3.m_y << endl;
	b2 = b3;//拷贝赋值
	cout << b2.m_x << ' ' << b2.m_y << endl;

}
