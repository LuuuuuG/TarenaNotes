#include <cstdlib>
#include<iostream>
using namespace std;
class A {
public:
	A (int arg = 0):m_var(arg) {
		cout << "A构造：" << this << endl;
	}
	~A (void) {
		cout << "A析构：" << this << endl;
	}
	static void* operator new (size_t size){
		void* p = malloc(size);
		cout << "new:" << size << ' ' 
		<< p << endl;
		return p;
	}
	static void operator delete (void* p){
		cout << "delete:" << p << endl;
		free(p);
	}
private:
	int m_var;
};

int main(){
	A* pa = new A (100);
	delete pa;

	return 0;
}
