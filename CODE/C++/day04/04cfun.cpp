#include <iostream>
using namespace std;
class Student{
public:
	Student (string const& name,int age): m_name(name),
	m_age(age),m_times(0){}
	void print() const {//常函数,修饰this指针
//	void print(Student const* this){
//		cout << m_name << ',' << this->m_age++ << endl;
		if(++m_times > 3)
//	  =	if(++const_cast<Student*>(this)->m_times > 3)	
			cout << "打印次数超限！" << endl;
		else
			cout << m_name << ',' << this->m_age << endl;
	}
private:
	string m_name;
	int m_age;
	mutable unsigned int m_times;
};

int main(){
	Student s1("张飞",29);
	s1.print();
	s1.print();
	s1.print();
	s1.print();
	s1.print();
	return 0;
}
