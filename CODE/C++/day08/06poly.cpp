/*************************************************************************
    > File Name: 06poly.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 15时19分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
public:
	A (){
		this->fuck();
	}
	virtual void fuck(void){
		cout << "A::fuck" << endl;
	}
	void shit(void) const{
		this->fuck();
	}
};
class B : public A{
public:
	void fuck(void) const{
		cout << "B::fuck" << endl;
	}
};
int main(){
	B b;
/*
	A a = b; //对象截切
	a.fuck();
	A* p = &b;//指针访问子对象
	p->fuck();
	A& r = b;
	r.fuck();//引用访问子类对象
	b.shit();
*/
	return 0;
}

