#include<iostream>
using namespace std;

int main(){
	bool b = true;
	cout << sizeof(b) << endl;
	cout << b << endl;
	cout << boolalpha << b << endl;//IO流
	b = !b;
	cout << b << endl;
	b = 19;
	cout << b << endl;

	b = 3.14;
	cout << b << endl;
	b = "Hello,World !";
	cout << b << endl;
	b = 0;
	cout << b << endl;
	b = 0.0;
	cout << b << endl;
	b = NULL;
	cout << b << endl;
	return 0;
}

