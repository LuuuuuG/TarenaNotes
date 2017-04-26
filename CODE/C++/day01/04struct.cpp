#include<iostream>
using namespace std;
struct Dog{
	//成员变量————属性
	char name[64];
	int age;
	//成员函数————行为
	void who(void){
		cout << "我叫" << name <<",今年" << age << "岁。" <<endl;
	}
	void eat(char const* food){
		cout << "我吃" << food << "!" << endl;
	}
	void talk(void){
		cout << "汪汪~~~" << endl;
	}
};

int main(){
	Dog dog1={"王麻子",18},
		dog2={"狗蛋",20};
	dog1.who();
	dog1.eat("骨头");
	dog1.talk();
	dog2.who();
	dog2.eat("排骨");
	dog2.talk();
	return 0;
}



