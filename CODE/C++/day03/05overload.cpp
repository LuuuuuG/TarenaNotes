//构造函数重载
#include<iostream>
using namespace std;
class Point {
public:
	Point (int x,int y,int z){//三维点
		m_x = x;
		m_y = y;
		m_z = z;
	}
	Point (int x,int y){//二维点
		m_x = x	;
		m_y = y;
		m_z = 0;
	}
	//类型转换构造函数
	Point (int x){//一维点
		m_x = x;
		m_y = 0;
		m_z = 0;
	}
	//缺省构造函数
	Point (void){//原点
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	//拷贝构造函数  
	Point (Point const& that){ //形参必须用引用
		cout << "拷贝构造函数" << endl;
		m_x = that.m_x;
		m_y = that.m_y;
		m_z = that.m_z;
	}

	void draw(){
		cout << "绘制点(" << m_x << ',' << m_y
			<< ',' << m_z << ')' << endl;
	}
private:
	int m_x;
	int m_y;
	int m_z;
};

class A{ //类中没有构造函数
//编译器会自动提供一个缺省构造函数
public:
	int m_var;
	Point m_pt;
};

void fuck (Point point){
	point.draw();
}

Point shit (void){
	return 900;
//	return Point (900);
}

int main(){
	Point p1(100,200,300);
	p1.draw();
	Point p2(400,500);
	p2.draw();
	Point p3(600);
	p3.draw();
	Point p4;
	p4.draw();
	A a;
	cout << a.m_var << endl;
	a.m_pt.draw();

	p1 = 700;
//= p1 = (Point)700;
//  p1 = Point (700);
	p1.draw();

	fuck (800);

	p1 = shit();
	p1.draw();

	Point p5 (p1); //拷贝构造
	p5.draw();

	Point p6 = p5; //拷贝构造
	p6.draw();
}
