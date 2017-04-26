#include<iostream>
using namespace std;

int main(){
	enum Fuck {A,B,C,D,E};
	Fuck x;
	x = A;
	cout << x << endl;//0
	//整型=>枚举 必须显示转换
	x = (Fuck)0;//类型转换法1
	int e = 4;
	x = Fuck(e); //类型转换法2
	e = E;//枚举=>整型
	e = x;
	return 0;
}
