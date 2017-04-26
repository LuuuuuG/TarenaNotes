/*************************************************************************
    > File Name: 08binary.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 17时02分36秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Student {
public:
	Student (char const* name = "",int age = 0):m_age (age){
			strcpy(m_name,name);
	}
	friend ostream& operator << (ostream& os,
			Student const& student){
		return os << student.m_name << ',' << student.m_age;
	}
private:
	char m_name[256];
	int m_age;
};

int main(){
	Student s1 ("张飞",22);
	ofstream ofs ("student.txt");
	ofs.write ((char*)&s1,sizeof (s1));
	ofs.close ();
	ifstream ifs ("student.txt");

	Student s2;
	ifs.read ((char*)&s2,sizeof(s2));
	cout << s2 << endl;
	return 0;
}
