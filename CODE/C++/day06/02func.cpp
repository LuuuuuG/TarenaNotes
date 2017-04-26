//函数操作符
#include<iostream>
using namespace std;
class Square{
public:
	int operator() (int x) const {
		return x*x;
	}
	double operator() (double x,double y) const {
		return x*x + y*y;
	}

};
int main(){
	Square square;
	cout << square (10) << endl;
	cout << square (0.3,0.4) << endl;
	return 0;
}
