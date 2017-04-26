#include <iostream>
using namespace std;

class Integer{
public:
	Integer (int i = 0) : m_i (i){}
	int& value(){
		return m_i;
	}
	int const& value() const{ //常函数 返回常引用
	//第二个const修饰隐藏的this 		
		return m_i;
	}

private:
	int m_i;
};

int main(){
	Integer i (100);
	cout << i.value() << endl;
//	i.value() = 200;
	cout << i.value() << endl;
	Integer const& cr = i;//非常-> 常
	cout << cr.value() << endl;
	return 0;
}

