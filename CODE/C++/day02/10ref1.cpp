#include<iostream>
using namespace std;

int main(){
	int a = 10;
	int& b = a;
	++b;
	cout << a << endl;//11
	cout << &b << '\n' << &a << endl;
	int& c = b;
	cout << &c << endl;
//	int& d; //引用必须初始化
//	int& d = NULL;//引用不能为空
	int d = 233;
	b = d; //等价与a = d，而不是使b成为d的引用
			//引用的目标不能更换
	cout << &b <<' '<< &d << endl;
	return 0;
}
