//实现学生
#include<iostream>
using namespace std;
#include "student.h"

Student::Student(string const& name,int age):m_name(name),m_age(age){}
	void Student::who(){
		cout << "我是" << m_name << ",今年" << m_age << "岁。" << endl;
	}
	void Student::eat (string const& food){
		cout << "我吃" << food << "." << endl;
	}
	void Student::learn(string const& course){
		cout << "我学" << course << endl;
	}

