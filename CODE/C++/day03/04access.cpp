#include<iostream>
using namespace std;
class Student {
private://不写默认私有
	string m_name;
	int m_age;		//此处为函数声明 不能初始化
public://公有
	//构造函数
	Student (string const& name = " ",int age = 0){//设置缺省值
		m_name = name;
		m_age = age;
	}
	void setName (string const& name){
		if(name != "SB")
			m_name = name;
	}
	void setAge(int age){
		if(age > 0)
			m_age = age;
	}
	void who (){
		cout << "我叫" << m_name << ",今年" << m_age << "岁." << endl;
	}
	void learn(string const& course){
		cout << "我在学习" << course << "。" << endl;
	}
};

int main(){
	Student s1;
//	Student s1(); //会被编译器误解为函数声明
	s1.setName("张飞");
	s1.setAge(25);
	s1.who();
	s1.learn("C++");

	s1.setName("SB");
	s1.setAge(-10);
	s1.who();
	s1.learn("C++");
	
//	int i = 10;//初始化
	int i (10); //初始化表达式
	i = 20;//赋值运算表达式
	
	Student s2 ("赵云",22);
//  s2.Student ("赵云",22);
	s2.who(); //因为没有初始化,age 随机

	int* pi = new int (30);
	cout << *pi << endl;
	delete pi;
	Student* ps = new Student ("关羽",40);
//	Student* ps = (Studnet*)malloc(
//		sizeof(Student));
//	ps->Student ("关羽",40);
	ps->who();
	delete ps;
	ps = new Student;//ok
	ps->who();
	delete ps;
	ps = new Student();//ok
	ps->who();
	delete ps;
	return 0;
}
