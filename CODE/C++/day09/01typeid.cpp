/*************************************************************************
    > File Name: 01typeid.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月23日 星期一 10时15分12秒
 ************************************************************************/

#include<iostream>
#include<typeinfo>
using namespace std;
/*
class  {
public:

private:

};
*/
int main(){
	cout << typeid (void).name() << endl;
	cout << typeid (void*).name() << endl;
	cout << typeid (void**).name() << endl;
	cout << typeid (char).name() << endl;
	cout << typeid (unsigned char).name() << endl;
	cout << typeid (short).name() << endl;
	cout << typeid (unsigned short).name() << endl;
	cout << typeid (int).name() << endl;
	cout << typeid (unsigned int).name() << endl;
	cout << typeid (long).name() << endl;
	cout << typeid (unsigned long).name() << endl;
	string sa[10];
	cout << typeid (sa).name() << endl;
	char ca[10];
	cout << typeid (ca).name() << endl;

	char* pa[10];//字符指针数组
	cout << typeid (pa).name() << endl;

	char (*ap)[10];//字符数组指针
	cout << typeid (ap).name() << endl;

	const char* cp;//  \_ 
	char const* cc;//  / 等效
	cout << typeid (cp).name() << endl;
	cout << typeid (cc).name() << endl;

	char* const pc = NULL; 
	cout << typeid (pc).name() << endl;
	char const* const ccc =NULL;
	cout << typeid(ccc).name() << endl;

	void (*p1) (void);
	void (*p2)(int*(*)(short*));
	long* (*(*p3)(int*(*)(short*)))(char*);
	//p3是一个指向以函数指针为参数同时返回函数指针的函数的指针
	cout << typeid (p1).name() << endl;//PFvvE
	cout << typeid (p2).name() << endl;//PFvPFPiPsEE
	cout << typeid (p3).name() << endl;//PFPFPlPcEPFPiPsEE


	//只有基类中函数(纯)虚函数的继承关系 叫做多态继承
	class A {};
	class B : public A {//B从A普通继承
		virtual void fuck (void){}
	};
	class C: public B {};//C从B多态继承
	
	B b;
	A& ra = b;
	//普通继承,取静态类型————A
	cout << typeid(ra).name()<< endl;
	C c;
	B& rb = c;
	//多态继承,取动态类型————C
	cout << typeid(rb).name()<< endl;

	A* p4 = &c;
	cout << typeid (*p4).name() << endl;
	return 0;
}
