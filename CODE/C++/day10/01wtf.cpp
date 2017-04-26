/*************************************************************************
    > File Name: 01wtf.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 09时56分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
//void fuck (int arg) throw(int,double,char const*,string){//抛出特定异常
//	void fuck (int arg) throw(){//不抛出任何异常
	void fuck (int arg){//可以抛出任何异常
	switch(arg){
		case 1:
			throw 123;
		case 2:
			throw 4.5;
		case 3:
		//	throw "出错啦！";
			throw string("出错啦！");
	}
	cout << "成功返回。" << endl;
}
class Base{
public:
	virtual void fuck(void) throw (int,double){}
};

class Derived:public Base{
public:
	~Derived(void) throw (){} //该析构啥都不做,只是让覆盖生效???
//	void fuck(void) throw (double,int){}//覆盖
//	void fuck(void) throw (double){}
//	void fuck(void) throw (double,int,string){}//error超出覆盖范围
//	void fuck(void) throw (string){}  //error 
//	void fuck(void) {} //error
	void fuck(void) throw (){}
};
/*
	如果基类中的虚函数带有异常说明,那么该函数在子类中的覆盖版本
		不能说明比基类版本抛出更多的异常。
 */

int main(){
	int var;
	cin >> var;
	try{
		fuck(var);
	}
	catch (int ex){
		cout << "整形异常:" << ex << endl;
	}
	catch (double ex){
		cout << "双精度异常:" << ex << endl;
	}/*
	catch (char const* ex){
		cout << "字符串异常:" << ex << endl;
	}*/
	catch (string& ex){
		cout << "字符串异常:" << ex << endl;
	}
	return 0;
}
