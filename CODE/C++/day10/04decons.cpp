/*************************************************************************
    > File Name: 04wth.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月24日 星期二 11时51分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A {
public:
	void fuck(void){
		throw 1;
	}
	~A (void){
		//throw 1.0;
		try{
			fuck();
		}
		catch(){}
	}

};

int main(){
	try{
		A a;
		a.fuck();
	}
	catch(int ex){
		cout << ex << endl;
	}
	catch(double ex){
		cout << ex << endl;
	}
	return 0;
}
