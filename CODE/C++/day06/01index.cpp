#include<iostream>
using namespace std;
class Array{
private:
	int m_array[256];

public:
	int& operator[] (int i){
		return m_array[i];
	}
	int const& operator[] (int i) const {
//		return m_array[i];
		return const_cast<Array&>(*this)[i]; 
		//代码复用 调用上面函数的返回值
	}

};
 
int main(){
	Array a;
	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	cout << a[0] << endl; 
	cout << a[1] << endl; 
	cout << a[2] << endl; 
	
	Array const* cp = &a;
	cout << (*cp)[0] << endl;
	return 0;
}



