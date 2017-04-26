/*************************************************************************
    > File Name: 08zoo.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 16时28分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Animal {
public:
	virtual void eat (void) const = 0;
	virtual void run (void) const = 0;
	virtual void cry (void) const = 0;
};

class Cat:public Animal{
public:
	void eat (void) const{
		cout << "猫吃鱼" << endl;
	}
	void run (void) const {
		cout << "猫追逐" << endl;
	}
	void cry (void) const{
		cout << "猫喵喵" << endl;
	}
};

class Rabbit : public Animal{
public:
	void eat (void) const{
		cout << "兔子吃罗卜" << endl;
	}
	void run (void) const {
		cout << "兔子蹦跶" << endl;
	}
	void cry (void) const{
		cout << "兔子吱吱叫" << endl;
	}
};

void zoo (Animal const* animal){
	animal->eat();
	animal->run();
	animal->cry();
}
int main(){
	zoo (new Cat);
	zoo (new Rabbit);
	return 0;
}
