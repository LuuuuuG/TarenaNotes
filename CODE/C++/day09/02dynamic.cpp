/*************************************************************************
    > File Name: 02dynamic.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月23日 星期一 11时47分29秒
 ************************************************************************/
//静态类型转换/动态类型转换
#include<iostream>
using namespace std;
class A {virtual void fuck (void){}};
class B : public A {
};
class C : public B {
};
class D {
};


int main(){
	B b;
	A* pa = &b;
	B* pb = static_cast<B*>(pa);//B是A的后代类,编译成功,安全
	C* pc = static_cast<C*>(pa);//C是A的后代类,编译成功,危险
//	D* pd = static_cast<D*>(pa);//编译失败 安全
	cout << "pb = " << pb << endl; 
	cout << "pc = " << pc << endl; 
//	cout << "pd = " << pd << endl; 

	
	pb = dynamic_cast<B*>(pa);//pa指向B对象,成功,安全
	pc = dynamic_cast<C*>(pa);//pa指向非C对象,失败,安全
	D* pd = dynamic_cast<D*>(pa);//pa指向非D对象,失败,安全
	cout << "pb = " << pb << endl; 
	cout << "pc = " << pc << endl; 
	cout << "pd = " << pd << endl; 
	
	pb = reinterpret_cast<B*>(pa);//重解释
	pc = reinterpret_cast<C*>(pa);
	pd = reinterpret_cast<D*>(pa);
	cout << "pb = " << pb << endl; 
	cout << "pc = " << pc << endl; 
	cout << "pd = " << pd << endl; 
	return 0;
}
/*
	静态类型转换只看类型不看对象
	动态类型转换即看类型也看对象
	重解释在编译期、运行时均不检查
*/
