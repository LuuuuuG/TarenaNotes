/*************************************************************************
    > File Name: 05overRide.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 14时50分03秒
 ************************************************************************/
//覆盖条件   ————待调试
//1. 必须是(非静态)成员函数。
//2. 必须是虚函数。
//3. 函数的签名(函数名+形参表+常属性)必须相同。
//4. 一般而言返回类型也应该相同,但是只有一个例外:类型协变。
#include<iostream>
using namespace std;
class A {
public:
	virtual void fuck (void){
		cout << "A::fuck" << endl;
	}
};

class B {
public:
	virtual void fuck (void){}
};

class C:public A{
public:
	virtual void fuck (int x){}//隐藏关系 
	//不覆盖
};
class D: public A{
public:
//	virtual int fuck (void){return 0;}//
	void fuck (void){ //覆盖关系
		cout << "D::fuck" << endl;
	}
};
class M {};
class N:public M {};
class X {
public:
	virtual M* fuck (){
		cout << "X::fuck" << endl;
		return NULL;
	}
};
class Y:public X{
public:
	 Y* fuck (){
		cout << "Y::fuck" << endl;
		return NULL;
	}
};
class P{
	public:
		void fuck(){
			cout << "P::fuck" << endl;
		}
};
class Q{
private:
	void fuck (){
		cout << "Q::fuck" << endl;
	}
};
int main(){
	D d;
	A& a = d;
	a.fuck();

	X* x = new Y;
	x->fuck();

	Q q;
	P& p = q;
	p.fuck();

	return 0;
}
