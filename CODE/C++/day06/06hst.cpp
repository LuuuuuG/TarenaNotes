#include<iostream>
using namespace std;
//		人类
//		/  \
//	  学生  教师
class Human {
public:
	Human (string const& name,int age):
		m_name(name),m_age(age){}
	void who (void) const{
		cout << "我是:" << m_name
			<< ",今年" << m_age << "岁。"
			<< endl;
	}
	void eat (string const& food) const {
		cout << "我吃" << food << "。"
			<< endl;
	}
	void sleep(int hours) const {
		cout << "我睡觉" << hours << "小时。"
			<< endl;
	}
private:
	string m_name;
	int m_age;
};

class Student : public Human {
public:
	Student(string const& name,int age,int no):Human(name,age)
									   ,m_no(no){}
	void learn(string const& course) const{
		cout << "我的学号是" << m_no
			<< ",我在学" << course << "~"
			<< endl;
	}
private:
	int m_no;
};

class Teacher : public Human{
public:
	Teacher (string const& name,int age,int salary):
		Human(name,age),m_salary(salary){}
		
	void teach (string const& course) const{
		cout << "我的工资" << m_salary 
			<< ",我教" << course << "."
			<< endl;
	}
private:
	int m_salary;

};

int main(void){
	Student s("张飞",10,1001);
	s.who ();
	s.eat("面条");
	s.sleep(1);
	s.learn("C++");
	Teacher t ("杨健",40,20000);
	t.who();
	t.eat("米饭");
	t.sleep(2);
	t.teach("标C");
	return 0;
}
