#include<iostream>
using namespace std;

int x=5678;
/*匿名名字空间
namespace{
	int x =5678;
}
*/
namespace icbc{
  int balance = 0;
  int x=1234;
  void save(int money){
	balance += money;
  }
  void draw(int money){
	balance -= money;
  }
  void query(){
	std::cout << balance << std::endl;
  }
  void foo(){
	std::cout << x <<std::endl;//x=1234
	std::cout << ::x <<std::endl;//x=5678
  }
}

namespace abc{
int balance = 0;
  void save(int money){
	balance += money;
  }
  void draw(int money){
	balance -= money;
  }
 void query();//函数声明
/*  void query(){
	std::cout << balance << std::endl;
  }  
*/
}


namespace tarena{
	namespace cpp{
		namespace uc{
			namespace chatroom{
				int data=100;
			}
		}
	}
}	
int main(){
	using namespace icbc;
/*
	icbc::query();
	icbc::save(10000);
	icbc::query();
	icbc::draw(5000);
	icbc::query();
*/
	query();
	save(10000);
	query();
	draw(5000);
	query();
	int x = 999;//小作用域隐藏大作用域
	std::cout<<x<<std::endl;
	std::cout<<icbc::x<<std::endl;
	std::cout<<::x<<std::endl;
//	using namespace abc;
//  query(); //歧义错误
	using abc::query;//名字空间声明 局部优先与全局
//	using icbc::query; //歧义错误
	query();
	abc::save(50000);
	query();
	abc::draw(40000);
	query();
	foo();
	std::cout
		<< tarena::cpp::uc::chatroom::data
		<<std::endl;
	namespace tc = tarena::cpp::uc::chatroom;
	std::cout << tc::data << std::endl;
	cout << "省略std前缀，灰常简洁！" << endl;
	return 0;
}

  void abc::query(){
	std::cout << balance << std::endl;

  }  
