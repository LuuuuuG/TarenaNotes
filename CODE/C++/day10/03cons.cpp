/*************************************************************************
    > File Name: 03cons.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 11时21分21秒
 ************************************************************************/
#include<cstdlib>
#include<cstring>
#include<errno.h>
#include<iostream>
using namespace std;
class A {
public:
	A (void) {cout << "A构造" << endl;	}
	~A (void) {cout << "A析构" << endl;	}
};

class B {
public:
	B (void) {cout << "B构造" << endl;	}
	~B (void) {cout << "B析构" << endl;	}
};

class C {
public:
	C (void) {cout << "C构造" << endl;	}
	~C (void) {cout << "C析构" << endl;	}
};
class Object {
public:
	Object (void) : m_pa(new A),m_buf(malloc(0xFFFFFFFF)){
		if(! m_buf){
			delete m_pa;//手动释放资源
			throw errno;
		}
	}
	~Object (void){
		free(m_buf);
		delete m_pa;
	}
	void set(char const* text){
		strcpy((char*)m_buf,text);
	}
	char const* get(void) const{
		return (char const*) m_buf;
	}
private:
	A* m_pa;
	void* m_buf;
	auto_ptr<c> m_buf;
};

int main(){
	try{
		Object obj;
		obj.set("Hello,World~");
		cout << obj.get() << endl;
	}
	catch (int ex){
		cout << strerror(ex) << endl;
		return -1;
	}
	return 0;
}
/*
	在构造函数中抛出异常,那么对象的析构函数不会被执行,
	有关动态资源释放的操作必须在构造函数抛出异常之前手动完成。
*/
