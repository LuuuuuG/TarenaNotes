/*************************************************************************
    > File Name: 03shape.cpp
    > Author: Mr.Gang
    > mail: 776881718@qq.com
    > Created Time: 2016年05月20日 星期五 11时40分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Shape {
public:
	Shape (int x,int y): m_x (x),m_y (y){}
	//虚函数
	virtual void draw () const{  
		cout << "图形(" << m_x << ','
			<< m_y << ')' << endl;
	}
protected:
	int m_x,m_y;
};
class Rect: public Shape{
public:
	Rect (int x,int y,int w,int h):
		Shape (x,y),m_w(w),m_h(h){}
	//虚函数 覆盖了基类中的draw函数
	void draw () const {
		cout << "矩形(" << m_x << ','
			<< m_y <<','<< m_w <<','<< m_h << ')' << endl;
	}
private:
	int m_w;
	int m_h;
};
class Circle : public Shape{
public:
	Circle (int x,int y,int r):
		Shape(x,y),m_r(r){}
	//虚函数 覆盖了基类中的draw函数
	void draw() const{
		cout << "圆形(" << m_x << ','
			<< m_y << ',' << m_r << ')' << endl;
	}
private:
	int m_r;
};
void render(Shape* shapes[]){
	for(size_t i = 0; shapes[i]; ++i)
		shapes[i]->draw();
		//不是根据指针本身的类型选择函数,
		//而是根据指针所指向的具体子类对象
		//的类型选择所要调用的函数————多态
}
int main(){
	Circle circle (1,2,3);
	circle.draw();
	Rect rect (4,5,6,7);
	rect.draw();
	Shape* shapes[1024] = {};
	shapes[0] = new Circle(1,2,3);
	shapes[1] = new Circle(4,5,6);
	shapes[2] = new Rect(7,8,9,10);
	shapes[3] = new Rect(11,12,13,14);
	shapes[4] = new Circle(15,16,17);
	render (shapes);
	return 0;
}
