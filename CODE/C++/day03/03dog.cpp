#include<iostream>
using namespace std;
struct Dog{
	//成员变量描述属性
	char breed[256];  //犬种
	char name[256];
	int age;		  //犬龄
	float weight;	  //体重
	char color[256];  //毛色

	//成员函数描述行为
	//进食
	void eat(string const& food){
		cout << "啃了" << food << endl;
	}
	//睡眠
	void sleep(int duration){
		cout << "睡了" << duration << "小时" << endl;
	}
	//玩耍
	void play(void){
		cout << "愉快地玩耍" << endl;
	}
	//描述
	void who(){
		cout << name << ",一条" << age << "岁大," << weight 
			<< "公斤重的" << color << "色" << breed << endl;
	}
};

int main(){
	Dog dog = {"单身狗","徐少远",19,80,"黄"};//创建一个对象
	dog.who();
	dog.eat("狗屎");
	dog.sleep(1);
	dog.play();
	return 0;
}
