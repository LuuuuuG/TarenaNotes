#include<iostream>
using namespace std;
class A{
public:
	A (int var = 0) : m_var (var){}
	static void set(int arg){
		s_var  = arg;
	}
	static void get(int arg){
		return s_var;

	}

	int m_var;
	static int s_var;//声名静态成员变量
};
int A::s_var;//定义静态成员变量
int main(){
	
	cout << &A::s_var << endl;
	A a;
	cout << sizeof(a) << endl; //4
	cout << &a << endl;
	cout << &a.m_var << endl;
	A a2;
	cout << sizeof(a2) << endl; //4
	cout << &a2 << endl;
	cout << &a2.m_var << endl;


	return 0;
}
