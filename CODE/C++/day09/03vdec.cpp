/*************************************************************************
    > File Name: 03vdec.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月23日 星期一 14时19分26秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
/*
class A {
public:
	A (void) : m_buf (new char[1024]){
		cout << "分配内存：" << (void*)m_buf << endl;
	}
	virtual ~A (void){//虚析构
		delete[] m_buf;
		cout << "释放内存：" << (void*)m_buf << endl;
	}
private:
	char* m_buf;
};
*/
//基类不分配资源也需要添加一个空虚析构函数
class A {
public:
	virtual ~A(void){} //空虚析构
private:
	char* m_buf[1024];
};

class B:public A {
public:
	B (void) : m_fp (fopen("aaa","w+")){
		cout << "打开文件：" << m_fp << endl;
	}
	~B (void){
		cout << "关闭文件：" << m_fp << endl;
		fclose (m_fp);
	}
private:
	FILE* m_fp;
};

int main(){
//	B* pb = new B;  OK
//	delete pb; // B::~B()->A::~A()
	

//	A* pa = new B;
//	delete pa; //不会调用子类析构函数
//	delete static_cast<B*>(pa);//向下造型
	
	A* pa = new B; //B::B()->A::~A()
	delete pa;
	return 0;
}
