//this 隐藏参数
#include <iostream>
using namespace std;
class A {
public:
	A (void){
		cout << "构造函数：" << this << endl;
	}
	void fuck(void){
		cout << "fuck:" << this << endl;
	}
};

class B {
public:
	int data;
	B inc (void){//自拷贝
		++data;
		return *this;
	}
	B& dec (void){//自引用  
		--data;
		void print(B&);   //??为什么要先声明？
		print(*this);
		return *this;//返回的是引用
	}
	B (int data){
		this -> data = data;
	}

};

void print (B& b){
	cout << "print:" << b.data << endl;
}
int main(){
	A a;
	cout << "main:" << &a << endl;
	a.fuck();
//	fuck(&a);
	B b(100);
	cout << b.data << endl;//100

	B b2 = b.inc();
	cout << b2.data << endl;//101

	b.dec().dec().dec(); 
	cout << b.data << endl; //98

	b.inc().inc().inc();
	cout << b.data << endl;//99
	return 0;
}
