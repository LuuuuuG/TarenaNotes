/*************************************************************************
    > File Name: 04calc.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 14时26分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Calculator{
public:
	virtual int calc (int x,int y) const {}//提供一个虚函数
};

class Adder:public Calculator {
public:
	//+
	int calc (int x,int y) const {
		return x + y;
	}
};

class Suber:public Calculator {
public:
	//-
	int calc (int x,int y) const {
		return x - y;
	}
};
//一个函数可以实现多个功能 ————面向抽象编程/接口化编程
int calc (int x,int y,Calculator const& obj){
	return obj.calc (x,y);
}	
int main(){
	Adder adder;
	Suber suber;
	cout << calc (123,456,adder) << endl;
	cout << calc (123,456,suber) << endl;
	return 0;
}
