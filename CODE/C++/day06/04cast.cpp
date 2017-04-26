#include <iostream>
using namespace std;
class Dog {
private:
	string m_name;
	friend class Cat;//友元类
public:
	Dog (string const& name): m_name(name){}
	Dog (Cat const& cat);
	//类型转换运算符函数
	operator Cat (void) const{
		return Cat (m_name);
	}
	void talk (void) const {
		cout << m_name << ":汪汪~~~" << endl;
	}
};
class Cat {
private:
	string m_name;
	friend class Dog;
public:
	Cat (string const& name): m_name(name){}
	void talk (void) const {
		cout << m_name << ":喵喵~~~" << endl;
	}
};
Dog::Dog (Cat const& cat):m_name(cat.m_name){}

Dog::operator Cat (void) const{
	return Cat (m_name);
}

int main(){
	Dog dog ("小白");
	dog.talk();
	Cat cat ("小花");
	cat.talk();
	Dog d = cat;
	d.talk();
	return 0;
}
