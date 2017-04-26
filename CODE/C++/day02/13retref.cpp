#include<iostream>
using namespace std;
int x = 0;
int& fuck(){
	return x;
}
int& shit(){
	int a =1000;
	return a;//返回局部变量的引用 函数结束后 内存变为自由内存
			 //内存可以被任意函数使用 这里被b继续使用
}
int& bitch(){
	int b = 2000;
	return b;
}
int main(){
	fuck() = 100;
	++fuck();
	fuck()++;
	cout << x << endl;//102
	int& r = shit();
	cout << r << endl; //1000
	bitch();
	cout << r << endl;//2000
	return 0;
}
