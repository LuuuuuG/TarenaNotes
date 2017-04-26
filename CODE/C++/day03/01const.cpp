#include<iostream>
using namespace std;
int main(){
	int const& r = 100;
	cout << &r << ' ' << r << endl;
	const_cast<int&>(r) = 200;//去常类型转换
	cout << &r << ' ' << r << endl;//200
	int const volatile a = 300; //a为常变量
	//cv限定int volatile 防止编译器优化
	int* p = const_cast<int*> (&a);//去常转换
	*p = 400;
	cout << p << ' ' <<  *p << endl;//400
	cout << (void*)&a << ' ' << a << endl;//应该打印出400 实际打印出300
	//加(void*)防止转换成布尔类型
//	cout << &a << ' ' << 300 << endl;//编译器的常量优化,字面值替换常变量

	return 0;
}
