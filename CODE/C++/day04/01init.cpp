#include<iostream>
using namespace std;

class Point{
public:
/*	Point(int x,int y,int z){
		m_x = x;
		m_y = y;
		m_z = z;
	}
*/
	//初始化表 函数定义的同时初始化
	Point(int x,int y,int z): m_x(x),m_y(y),m_z(z){}
	Point(int x,int y): m_x(x),m_y(y),m_z(0){}
	Point(int x): m_x(x),m_y(0),m_z(0){}
	Point(void): m_x(0),m_y(0),m_z(0){}


	void draw(){
		cout << "坐标点(" << m_x << ',' 
			<< m_y << ',' << m_z <<')'
			<< endl;
	}
private:
	int m_x;
	int m_y;
	int m_z;

};
class Integer{
public:
	Integer(int value): m_value(value){}
	void set(int value){
		m_value = value;
	}
	int get(){
		return m_value;
	}
private:
	int m_value;
};
class Pair{
public:
	Pair(void):m_first(0),m_second(0){
//		m_first (0); //error
//		m_first = 0; //error
	}
	Pair(int x,int y):m_first(x),m_second(y){}
	Integer m_first;
	Integer m_second;
};
class Message{
public:
	Message(string const& str):m_str(str),m_len(m_str.length()){}
	//error段错误 先声明的变量 先初始化
	size_t m_len;//交换变量声明语句顺序即可
	string m_str;
};

int main(){
	Point p1(1,2,3);
	Point p2(4,5);
	Point p3(6);
	Point p4;

	p1.draw();
	p2.draw();
	p3.draw();
	p4.draw();

	Pair pair;
	cout << pair.m_first.get() << ' ' 
	<< pair.m_second.get() << endl;

	Pair pair2(7,8);
	cout << pair2.m_first.get() << ' ' 
	<< pair2.m_second.get() << endl;
	 
	Message msg ("ABC");
	cout << msg.m_str << ' ' << msg.m_len << endl;
	
	return 0;
}
