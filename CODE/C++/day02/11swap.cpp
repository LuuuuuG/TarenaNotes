//引用形参
#include<iostream>
#include<string>
using namespace std;
void swap1(int x,int y){
	int z = x;
	x = y;
	y = z;
}

void swap2(int* x,int* y){
	int z = *x;
	*x = *y;
	*y = z;
}

void swap3(int& x,int& y){
	int z = x;
	x = y;
	y = z;
}

void swap4(char const** x,char const** y){
	char const* z = *x;
	*x = *y;
	*y = z;
}
void swap5(char const*& x,char const*& y){
	char const* z = x;
	x = y;
	y = z;
}
//练习：编写swap4和swap5函数，分别用于交换两个字符串变量
int main(){
	int a = 100,b = 200;
	cout << a << ' ' << b << endl;

	swap1(a,b);//值传递
	cout << a << ' ' << b << endl;

	swap2(&a,&b);//地址传递
	cout << a << ' ' << b << endl;

	swap3(a,b);//通过引用交换参数
	cout << a << ' ' << b << endl;

	char const* c = "hello",*d = "world";
	cout << c << ' ' << d << endl;
	swap4(&c,&d);
	cout << c << ' ' << d << endl;
	swap5(c,d);
	cout << c << ' ' << d << endl;
	return 0;
} 
