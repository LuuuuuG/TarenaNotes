//写处代码的输出
#include<iostream>
using namespace std;
namespace ns1{
	void fuck (int shit){
		cout << "ns1::fuck:" << shit << endl;
	}
}

namespace ns2{
	void fuck(double shit){
		cout << "ns2::fuck:" << shit << endl;
	}
}
//没有使用，这里暂时还无法判断是否重载
int main(void){
	using namespace ns1;
	using namespace ns2;
	//这行开始发生重载
	fuck(1); //ns1::fuck: 1
	fuck(1.2);//ns2::fuck: 1.2

	using ns1::fuck;//小作用域隐藏大作用域
	fuck(1);//ns1::fuck:1
	fuck(1.2);//ns1::fuck:1

	using ns2::fuck;//又开始发生重载
	fuck(1);//ns1::fuck:1
	fuck(1.2);//ns2::fuck:1.2
	return 0;
}

