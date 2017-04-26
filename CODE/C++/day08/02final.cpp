/*************************************************************************
    > File Name: 02final.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 11时07分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
private:
	A (int x= 0):m_x(x){}
	//构造函数设置为私有
	//禁止派生子类 
	//但是也不能生成对象了。。
public:
	int m_x;
	friend class AA;
};
/*
class B : public A{
public:
	B (int x,int y) : A (x),m_y(y){}
	int m_y;
};
*/
//使用A的友元构造对象
//虚继承实现断子绝孙效果
class AA: virtual public A {
public:
	AA (int x = 0):A (x){}
};

int main(){
//	B b(123,456);
//	cout << b.m_x << ' ' << b.m_y << endl;
//	A a (123);//无法构造对象
	AA a(123);
	cout << a.m_x << endl;
	return 0;
}
