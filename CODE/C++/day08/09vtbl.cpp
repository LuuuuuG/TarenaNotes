/*************************************************************************
    > File Name: 09vtbl.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 17时23分56秒
 ************************************************************************/
//练习：设计一个实现验证虚函数表和虚函数表指针的存在性
#include<iostream>
using namespace std;
class A {
public:
	A (void) : m_ch ('A'){}
	virtual void fuck (void){
		cout << m_ch << "::fuck()" << endl;
	}
	virtual void shit (void){
		cout << m_ch << "::shit()" << endl;
	}
private:
	char m_ch;
};

int main(){
	cout << "&A::fuck = " << (void*)&A::fuck << endl;
	cout << "&A::shit = " << (void*)&A::shit << endl;
	return 0;
}

